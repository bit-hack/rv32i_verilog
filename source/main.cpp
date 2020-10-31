#include <cstdio>

#include "../obj_dir/Vrv32i_cpu_t.h"

#include "memory.h"
#include "elf.h"

#if 0
#define DEBUG(...) printf(__VA_ARGS__);
#else
#define DEBUG(...)
#endif


static const char *reg_name(uint32_t reg) {
  const char *name[] = {
  "zero", "ra",  "sp",   "gp",  "tp",   "t0",  "t1",   "t2",
  "s0",   "s1",  "a0",   "a1",  "a2",   "a3",  "a4",   "a5",
  "a6",   "a7",  "s2",   "s3",  "s4",   "s5",  "s6",   "s7",
  "s8",   "s9",  "s10",  "s11", "t3",   "t4",  "t5",   "t6" };
  return name[reg & 31];
}

void print_signature(elf_t &elf, memory_t &mem) {

  DEBUG("---- ---- ---- ---- ---- ---- ----\n");

  uint32_t start = 0, end = 0;
  // use the entire .data section as a fallback
  elf.get_data_section_range(start, end);
  // try and access the exact signature range
  if (const ELF::Elf32_Sym *sym = elf.get_symbol("begin_signature")) {
    start = sym->st_value;
  }
  if (const ELF::Elf32_Sym *sym = elf.get_symbol("end_signature")) {
    end = sym->st_value;
  }
  // dump it word by word
  for (uint32_t i = start; i < end; i += 4) {
    uint32_t value = mem.read_w(i);
    printf("%08x\n", value);
  }
}

void dump_text(elf_t &elf, memory_t &mem) {
  uint32_t start = 0;
  uint32_t end = 0;
  if (!elf.get_section_range(".text", start, end)) {
    return;
  }
  for (uint32_t i = start, x = 0; i < end; ++i, ++x) {
    uint8_t v = mem.read_b(i);
    printf("%s%02x", (x % 4 == 0) ? "\n": " ", v);
  }
}

struct rv32i_cpu_t {

  rv32i_cpu_t(memory_t &memory)
    : active(false)
    , mem(memory)
  {
  }

  void set_pc(uint32_t addr) {
    rtl.rv32i_cpu_t__DOT__pc = addr;
    rtl.eval();
  }

  uint32_t get_pc() const {
    return rtl.rv32i_cpu_t__DOT__pc;
  }

  uint32_t get_phi() const {
    return rtl.rv32i_cpu_t__DOT__phi;
  }

  uint32_t get_reg(uint32_t index) const {
    return rtl.rv32i_cpu_t__DOT__X[index & 31];
  }

  void reset() {
    active = true;
    rtl.hold = 0;
    rtl.reset = 1;
    for (int i = 0; i < 4; ++i) {
      rtl.clk ^= 1;
      rtl.eval();
    }
    rtl.reset = 0;
    rtl.eval();
  }

  void step() {
    static const uint32_t ecall_inst = 0x00000073;
    while (active) {

      // update logic
      rtl.eval();

      // update memory on the negative clock edge
      if (rtl.clk == 0) {
        const uint32_t addr = rtl.out_mem_addr;
        const uint32_t read = mem.read_w(addr & ~3u);
        const uint32_t out = rtl.out_data;
        const uint32_t mask = rtl.out_write_mask;

        rtl.in_data = read;
        rtl.eval();

        if (mask) {
          const uint32_t write =
            ((mask & 1) ? (out & 0x000000ff) : (read & 0x000000ff)) |
            ((mask & 2) ? (out & 0x0000ff00) : (read & 0x0000ff00)) |
            ((mask & 4) ? (out & 0x00ff0000) : (read & 0x00ff0000)) |
            ((mask & 8) ? (out & 0xff000000) : (read & 0xff000000));

          mem.write(addr & ~3u, (const uint8_t*)&write, 4);
        }
      }

      // check if we just fetched and ecall instruction
      if (rtl.rv32i_cpu_t__DOT__inst == ecall_inst) {
        active = false;
      }

      // toggle the clock
      rtl.clk ^= 1;
      // exit on next instruction fetch
      if (rtl.clk && get_phi() == 0) {
        break;
      }
    }
  }

  bool is_active() const {
    return active;
  }

protected:

  uint32_t width_to_size(uint32_t in) const {
    switch (in) {
    case 1: return 1;
    case 3: return 2;
    case 7: return 4;
    default: assert(!"unreachable"); return 0;
    }
  }

  bool active;
  memory_t &mem;
  Vrv32i_cpu_t rtl;
};

int main(int argc, char **args) {

  elf_t elf;
  memory_t mem;
  rv32i_cpu_t cpu{mem};

  if (argc <= 1) {
    return 1;
  }

  if (!elf.load(args[1])) {
    return 1;
  }
  elf.upload(mem);
  // dump_text(elf, mem);

  cpu.reset();

  cpu.set_pc(elf.get_entry_point());

  while (cpu.is_active()) {
    DEBUG("0x%08x\n", cpu.get_pc());
    cpu.step();
  }

  print_signature(elf, mem);
  return 0;
}
