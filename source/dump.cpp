#include <cstdio>

#include "memory.h"
#include "elf.h"

int main(int argc, char **args) {

  elf_t elf;
  memory_t mem;

  if (argc <= 2) {
    return 1;
  }

  if (!elf.load(args[1])) {
    return 1;
  }
  elf.upload(mem);

  FILE *out = fopen(args[2], "w");
  if (!out) {
    return 1;
  }

  const uint32_t base = 0xf0000000;
  for (int i = 0; i < 1024; i += 4) {
    const uint32_t val = mem.read_w(base + i);
    fprintf(out, "%08x\n", val);
  }

  fclose(out);
  return 0;
}
