#pragma once
#include <cstdint>


static const uint32_t program[] = {
   /*10074:*/	0x00002537, //          	lui	a0,0x2
   /*10078:*/	0x80050513, //          	addi	a0,a0,-2048 # 1800 <userstart-0xe874>
// /*1007c:*/	0x30052073, //          	csrs	mstatus,a0
   /*1007c:*/	0x00000000, //
   /*10080:*/	0x00001117, //          	auipc	sp,0x1
   /*10084:*/	0x58010113, //          	addi	sp,sp,1408 # 11600 <__DATA_BEGIN__>
   /*10088:*/	0x0000d0b7, //          	lui	ra,0xd
   /*1008c:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*10090:*/	0xfff00f93, //          	li	t6,-1
   /*10094:*/	0x00000813, //          	li	a6,0
   /*10098:*/	0x010f8663, //          	beq	t6,a6,100a4 <userstart+0x30>
   /*1009c:*/	0x000120b7, //          	lui	ra,0x12
   /*100a0:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*100a4:*/	0x00112023, //          	sw	ra,0(sp)
   /*100a8:*/	0x0000d0b7, //          	lui	ra,0xd
   /*100ac:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*100b0:*/	0x00100f13, //          	li	t5,1
   /*100b4:*/	0x80100793, //          	li	a5,-2047
   /*100b8:*/	0x00ff0663, //          	beq	t5,a5,100c4 <userstart+0x50>
   /*100bc:*/	0x000120b7, //          	lui	ra,0x12
   /*100c0:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*100c4:*/	0x00112223, //          	sw	ra,4(sp)
   /*100c8:*/	0x0080006f, //          	j	100d0 <userstart+0x5c>
   /*100cc:*/	0x0200006f, //          	j	100ec <userstart+0x78>
   /*100d0:*/	0x0000d0b7, //          	lui	ra,0xd
   /*100d4:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*100d8:*/	0x00000e93, //          	li	t4,0
   /*100dc:*/	0xfff00713, //          	li	a4,-1
   /*100e0:*/	0xfeee86e3, //          	beq	t4,a4,100cc <userstart+0x58>
   /*100e4:*/	0x000120b7, //          	lui	ra,0x12
   /*100e8:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*100ec:*/	0x00112423, //          	sw	ra,8(sp)
   /*100f0:*/	0x0000d0b7, //          	lui	ra,0xd
   /*100f4:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*100f8:*/	0x7ff00e13, //          	li	t3,2047
   /*100fc:*/	0xfffff6b7, //          	lui	a3,0xfffff
   /*10100:*/	0xdcc68693, //          	addi	a3,a3,-564 # ffffedcc <__global_pointer$+0xfffecfcc>
   /*10104:*/	0x00de0663, //          	beq	t3,a3,10110 <userstart+0x9c>
   /*10108:*/	0x000120b7, //          	lui	ra,0x12
   /*1010c:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*10110:*/	0x00112623, //          	sw	ra,12(sp)
   /*10114:*/	0x0000d0b7, //          	lui	ra,0xd
   /*10118:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*1011c:*/	0x00000d93, //          	li	s11,0
   /*10120:*/	0x80000637, //          	lui	a2,0x80000
   /*10124:*/	0x00cd8663, //          	beq	s11,a2,10130 <userstart+0xbc>
   /*10128:*/	0x000120b7, //          	lui	ra,0x12
   /*1012c:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*10130:*/	0x00112823, //          	sw	ra,16(sp)
   /*10134:*/	0x00001117, //          	auipc	sp,0x1
   /*10138:*/	0x4e010113, //          	addi	sp,sp,1248 # 11614 <test_2_res>
   /*1013c:*/	0x0000d0b7, //          	lui	ra,0xd
   /*10140:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*10144:*/	0x00001d37, //          	lui	s10,0x1
   /*10148:*/	0x800d0d13, //          	addi	s10,s10,-2048 # 800 <userstart-0xf874>
   /*1014c:*/	0x000015b7, //          	lui	a1,0x1
   /*10150:*/	0x23458593, //          	addi	a1,a1,564 # 1234 <userstart-0xee40>
   /*10154:*/	0x00bd0663, //          	beq	s10,a1,10160 <userstart+0xec>
   /*10158:*/	0x000120b7, //          	lui	ra,0x12
   /*1015c:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*10160:*/	0x00112023, //          	sw	ra,0(sp)
   /*10164:*/	0x0000d0b7, //          	lui	ra,0xd
   /*10168:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*1016c:*/	0x07654cb7, //          	lui	s9,0x7654
   /*10170:*/	0x321c8c93, //          	addi	s9,s9,801 # 7654321 <__global_pointer$+0x7642521>
   /*10174:*/	0xfff00513, //          	li	a0,-1
   /*10178:*/	0x00ac8663, //          	beq	s9,a0,10184 <userstart+0x110>
   /*1017c:*/	0x000120b7, //          	lui	ra,0x12
   /*10180:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*10184:*/	0x00112223, //          	sw	ra,4(sp)
   /*10188:*/	0x0080006f, //          	j	10190 <userstart+0x11c>
   /*1018c:*/	0x0240006f, //          	j	101b0 <userstart+0x13c>
   /*10190:*/	0x0000d0b7, //          	lui	ra,0xd
   /*10194:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*10198:*/	0x80000c37, //          	lui	s8,0x80000
   /*1019c:*/	0xfffc0c13, //          	addi	s8,s8,-1 # 7fffffff <__global_pointer$+0x7ffee1ff>
   /*101a0:*/	0x00100493, //          	li	s1,1
   /*101a4:*/	0xfe9c04e3, //          	beq	s8,s1,1018c <userstart+0x118>
   /*101a8:*/	0x000120b7, //          	lui	ra,0x12
   /*101ac:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*101b0:*/	0x00112423, //          	sw	ra,8(sp)
   /*101b4:*/	0x0000d0b7, //          	lui	ra,0xd
   /*101b8:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*101bc:*/	0x00100b93, //          	li	s7,1
   /*101c0:*/	0x80000437, //          	lui	s0,0x80000
   /*101c4:*/	0xfff40413, //          	addi	s0,s0,-1 # 7fffffff <__global_pointer$+0x7ffee1ff>
   /*101c8:*/	0x008b8663, //          	beq	s7,s0,101d4 <userstart+0x160>
   /*101cc:*/	0x000120b7, //          	lui	ra,0x12
   /*101d0:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*101d4:*/	0x00112623, //          	sw	ra,12(sp)
   /*101d8:*/	0x0000d0b7, //          	lui	ra,0xd
   /*101dc:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*101e0:*/	0xfff00b13, //          	li	s6,-1
   /*101e4:*/	0x076543b7, //          	lui	t2,0x7654
   /*101e8:*/	0x32138393, //          	addi	t2,t2,801 # 7654321 <__global_pointer$+0x7642521>
   /*101ec:*/	0x007b0663, //          	beq	s6,t2,101f8 <userstart+0x184>
   /*101f0:*/	0x000120b7, //          	lui	ra,0x12
   /*101f4:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*101f8:*/	0x00112823, //          	sw	ra,16(sp)
   /*101fc:*/	0x00001397, //          	auipc	t2,0x1
   /*10200:*/	0x42c38393, //          	addi	t2,t2,1068 # 11628 <test_3_res>
   /*10204:*/	0x0000d0b7, //          	lui	ra,0xd
   /*10208:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*1020c:*/	0x00001ab7, //          	lui	s5,0x1
   /*10210:*/	0x234a8a93, //          	addi	s5,s5,564 # 1234 <userstart-0xee40>
   /*10214:*/	0x00001337, //          	lui	t1,0x1
   /*10218:*/	0x80030313, //          	addi	t1,t1,-2048 # 800 <userstart-0xf874>
   /*1021c:*/	0x006a8663, //          	beq	s5,t1,10228 <userstart+0x1b4>
   /*10220:*/	0x000120b7, //          	lui	ra,0x12
   /*10224:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*10228:*/	0x0013a023, //          	sw	ra,0(t2)
   /*1022c:*/	0x0000d0b7, //          	lui	ra,0xd
   /*10230:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*10234:*/	0x80000a37, //          	lui	s4,0x80000
   /*10238:*/	0x00000293, //          	li	t0,0
   /*1023c:*/	0x005a0663, //          	beq	s4,t0,10248 <userstart+0x1d4>
   /*10240:*/	0x000120b7, //          	lui	ra,0x12
   /*10244:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*10248:*/	0x0013a223, //          	sw	ra,4(t2)
   /*1024c:*/	0x0080006f, //          	j	10254 <userstart+0x1e0>
   /*10250:*/	0x0240006f, //          	j	10274 <userstart+0x200>
   /*10254:*/	0x0000d0b7, //          	lui	ra,0xd
   /*10258:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*1025c:*/	0xfffff9b7, //          	lui	s3,0xfffff
   /*10260:*/	0xdcc98993, //          	addi	s3,s3,-564 # ffffedcc <__global_pointer$+0xfffecfcc>
   /*10264:*/	0x7ff00213, //          	li	tp,2047
   /*10268:*/	0xfe4984e3, //          	beq	s3,tp,10250 <userstart+0x1dc>
   /*1026c:*/	0x000120b7, //          	lui	ra,0x12
   /*10270:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*10274:*/	0x0013a423, //          	sw	ra,8(t2)
   /*10278:*/	0x0000d0b7, //          	lui	ra,0xd
   /*1027c:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*10280:*/	0xfff00913, //          	li	s2,-1
   /*10284:*/	0xfff00193, //          	li	gp,-1
   /*10288:*/	0x00390663, //          	beq	s2,gp,10294 <userstart+0x220>
   /*1028c:*/	0x000120b7, //          	lui	ra,0x12
   /*10290:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*10294:*/	0x0013a623, //          	sw	ra,12(t2)
   /*10298:*/	0x0000d0b7, //          	lui	ra,0xd
   /*1029c:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*102a0:*/	0x80100893, //          	li	a7,-2047
   /*102a4:*/	0x00100113, //          	li	sp,1
   /*102a8:*/	0x00288663, //          	beq	a7,sp,102b4 <userstart+0x240>
   /*102ac:*/	0x000120b7, //          	lui	ra,0x12
   /*102b0:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*102b4:*/	0x0013a823, //          	sw	ra,16(t2)
   /*102b8:*/	0x00001197, //          	auipc	gp,0x1
   /*102bc:*/	0x38418193, //          	addi	gp,gp,900 # 1163c <test_4_res>
   /*102c0:*/	0x0000d137, //          	lui	sp,0xd
   /*102c4:*/	0xccc10113, //          	addi	sp,sp,-820 # cccc <userstart-0x33a8>
   /*102c8:*/	0x00000813, //          	li	a6,0
   /*102cc:*/	0x00000093, //          	li	ra,0
   /*102d0:*/	0x00180663, //          	beq	a6,ra,102dc <userstart+0x268>
   /*102d4:*/	0x00012137, //          	lui	sp,0x12
   /*102d8:*/	0x3ab10113, //          	addi	sp,sp,939 # 123ab <__global_pointer$+0x5ab>
   /*102dc:*/	0x0021a023, //          	sw	sp,0(gp) # 11e00 <__global_pointer$>
   /*102e0:*/	0x0000d0b7, //          	lui	ra,0xd
   /*102e4:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*102e8:*/	0xfff00793, //          	li	a5,-1
   /*102ec:*/	0x00000013, //          	nop
   /*102f0:*/	0x00078663, //          	beqz	a5,102fc <userstart+0x288>
   /*102f4:*/	0x000120b7, //          	lui	ra,0x12
   /*102f8:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*102fc:*/	0x0011a223, //          	sw	ra,4(gp) # 11e04 <__global_pointer$+0x4>
   /*10300:*/	0x0080006f, //          	j	10308 <userstart+0x294>
   /*10304:*/	0x0200006f, //          	j	10324 <userstart+0x2b0>
   /*10308:*/	0x0000d0b7, //          	lui	ra,0xd
   /*1030c:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*10310:*/	0x00100713, //          	li	a4,1
   /*10314:*/	0x80100f93, //          	li	t6,-2047
   /*10318:*/	0xfff706e3, //          	beq	a4,t6,10304 <userstart+0x290>
   /*1031c:*/	0x000120b7, //          	lui	ra,0x12
   /*10320:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*10324:*/	0x0011a423, //          	sw	ra,8(gp) # 11e08 <__global_pointer$+0x8>
   /*10328:*/	0x0000d0b7, //          	lui	ra,0xd
   /*1032c:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*10330:*/	0x00000693, //          	li	a3,0
   /*10334:*/	0xfff00f13, //          	li	t5,-1
   /*10338:*/	0x01e68663, //          	beq	a3,t5,10344 <userstart+0x2d0>
   /*1033c:*/	0x000120b7, //          	lui	ra,0x12
   /*10340:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*10344:*/	0x0011a623, //          	sw	ra,12(gp) # 11e0c <__global_pointer$+0xc>
   /*10348:*/	0x0000d0b7, //          	lui	ra,0xd
   /*1034c:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*10350:*/	0x7ff00613, //          	li	a2,2047
   /*10354:*/	0xfffffeb7, //          	lui	t4,0xfffff
   /*10358:*/	0xdcce8e93, //          	addi	t4,t4,-564 # ffffedcc <__global_pointer$+0xfffecfcc>
   /*1035c:*/	0x01d60663, //          	beq	a2,t4,10368 <userstart+0x2f4>
   /*10360:*/	0x000120b7, //          	lui	ra,0x12
   /*10364:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*10368:*/	0x0011a823, //          	sw	ra,16(gp) # 11e10 <__global_pointer$+0x10>
   /*1036c:*/	0x00001117, //          	auipc	sp,0x1
   /*10370:*/	0x2e410113, //          	addi	sp,sp,740 # 11650 <test_5_res>
   /*10374:*/	0x0000d0b7, //          	lui	ra,0xd
   /*10378:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*1037c:*/	0x00000593, //          	li	a1,0
   /*10380:*/	0x80000e37, //          	lui	t3,0x80000
   /*10384:*/	0x01c58663, //          	beq	a1,t3,10390 <userstart+0x31c>
   /*10388:*/	0x000120b7, //          	lui	ra,0x12
   /*1038c:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*10390:*/	0x00112023, //          	sw	ra,0(sp)
   /*10394:*/	0x0000d0b7, //          	lui	ra,0xd
   /*10398:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*1039c:*/	0x00001537, //          	lui	a0,0x1
   /*103a0:*/	0x80050513, //          	addi	a0,a0,-2048 # 800 <userstart-0xf874>
   /*103a4:*/	0x00001db7, //          	lui	s11,0x1
   /*103a8:*/	0x234d8d93, //          	addi	s11,s11,564 # 1234 <userstart-0xee40>
   /*103ac:*/	0x01b50663, //          	beq	a0,s11,103b8 <userstart+0x344>
   /*103b0:*/	0x000120b7, //          	lui	ra,0x12
   /*103b4:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*103b8:*/	0x00112223, //          	sw	ra,4(sp)
   /*103bc:*/	0x0080006f, //          	j	103c4 <userstart+0x350>
   /*103c0:*/	0x0240006f, //          	j	103e4 <userstart+0x370>
   /*103c4:*/	0x0000d0b7, //          	lui	ra,0xd
   /*103c8:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*103cc:*/	0x076544b7, //          	lui	s1,0x7654
   /*103d0:*/	0x32148493, //          	addi	s1,s1,801 # 7654321 <__global_pointer$+0x7642521>
   /*103d4:*/	0xfff00d13, //          	li	s10,-1
   /*103d8:*/	0xffa484e3, //          	beq	s1,s10,103c0 <userstart+0x34c>
   /*103dc:*/	0x000120b7, //          	lui	ra,0x12
   /*103e0:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*103e4:*/	0x00112423, //          	sw	ra,8(sp)
   /*103e8:*/	0x0000d0b7, //          	lui	ra,0xd
   /*103ec:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*103f0:*/	0x80000437, //          	lui	s0,0x80000
   /*103f4:*/	0xfff40413, //          	addi	s0,s0,-1 # 7fffffff <__global_pointer$+0x7ffee1ff>
   /*103f8:*/	0x00100c93, //          	li	s9,1
   /*103fc:*/	0x01940663, //          	beq	s0,s9,10408 <userstart+0x394>
   /*10400:*/	0x000120b7, //          	lui	ra,0x12
   /*10404:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*10408:*/	0x00112623, //          	sw	ra,12(sp)
   /*1040c:*/	0x0000d0b7, //          	lui	ra,0xd
   /*10410:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*10414:*/	0x00100393, //          	li	t2,1
   /*10418:*/	0x80000c37, //          	lui	s8,0x80000
   /*1041c:*/	0xfffc0c13, //          	addi	s8,s8,-1 # 7fffffff <__global_pointer$+0x7ffee1ff>
   /*10420:*/	0x01838663, //          	beq	t2,s8,1042c <userstart+0x3b8>
   /*10424:*/	0x000120b7, //          	lui	ra,0x12
   /*10428:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*1042c:*/	0x00112823, //          	sw	ra,16(sp)
   /*10430:*/	0x00001397, //          	auipc	t2,0x1
   /*10434:*/	0x23438393, //          	addi	t2,t2,564 # 11664 <test_6_res>
   /*10438:*/	0x0000d0b7, //          	lui	ra,0xd
   /*1043c:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*10440:*/	0xfff00313, //          	li	t1,-1
   /*10444:*/	0x07654bb7, //          	lui	s7,0x7654
   /*10448:*/	0x321b8b93, //          	addi	s7,s7,801 # 7654321 <__global_pointer$+0x7642521>
   /*1044c:*/	0x01730663, //          	beq	t1,s7,10458 <userstart+0x3e4>
   /*10450:*/	0x000120b7, //          	lui	ra,0x12
   /*10454:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*10458:*/	0x0013a023, //          	sw	ra,0(t2)
   /*1045c:*/	0x0000d0b7, //          	lui	ra,0xd
   /*10460:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*10464:*/	0x000012b7, //          	lui	t0,0x1
   /*10468:*/	0x23428293, //          	addi	t0,t0,564 # 1234 <userstart-0xee40>
   /*1046c:*/	0x00001b37, //          	lui	s6,0x1
   /*10470:*/	0x800b0b13, //          	addi	s6,s6,-2048 # 800 <userstart-0xf874>
   /*10474:*/	0x01628663, //          	beq	t0,s6,10480 <userstart+0x40c>
   /*10478:*/	0x000120b7, //          	lui	ra,0x12
   /*1047c:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*10480:*/	0x0013a223, //          	sw	ra,4(t2)
   /*10484:*/	0x0080006f, //          	j	1048c <userstart+0x418>
   /*10488:*/	0x0200006f, //          	j	104a8 <userstart+0x434>
   /*1048c:*/	0x0000d0b7, //          	lui	ra,0xd
   /*10490:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*10494:*/	0x80000237, //          	lui	tp,0x80000
   /*10498:*/	0x00000a93, //          	li	s5,0
   /*1049c:*/	0xff5206e3, //          	beq	tp,s5,10488 <userstart+0x414>
   /*104a0:*/	0x000120b7, //          	lui	ra,0x12
   /*104a4:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*104a8:*/	0x0013a423, //          	sw	ra,8(t2)
   /*104ac:*/	0x0000d0b7, //          	lui	ra,0xd
   /*104b0:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*104b4:*/	0xfffff1b7, //          	lui	gp,0xfffff
   /*104b8:*/	0xdcc18193, //          	addi	gp,gp,-564 # ffffedcc <__global_pointer$+0xfffecfcc>
   /*104bc:*/	0x7ff00a13, //          	li	s4,2047
   /*104c0:*/	0x01418663, //          	beq	gp,s4,104cc <userstart+0x458>
   /*104c4:*/	0x000120b7, //          	lui	ra,0x12
   /*104c8:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*104cc:*/	0x0013a623, //          	sw	ra,12(t2)
   /*104d0:*/	0x0000d0b7, //          	lui	ra,0xd
   /*104d4:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*104d8:*/	0xfff00113, //          	li	sp,-1
   /*104dc:*/	0xfff00993, //          	li	s3,-1
   /*104e0:*/	0x01310663, //          	beq	sp,s3,104ec <userstart+0x478>
   /*104e4:*/	0x000120b7, //          	lui	ra,0x12
   /*104e8:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*104ec:*/	0x0013a823, //          	sw	ra,16(t2)
   /*104f0:*/	0x00001197, //          	auipc	gp,0x1
   /*104f4:*/	0x18818193, //          	addi	gp,gp,392 # 11678 <test_7_res>
   /*104f8:*/	0x0000d137, //          	lui	sp,0xd
   /*104fc:*/	0xccc10113, //          	addi	sp,sp,-820 # cccc <userstart-0x33a8>
   /*10500:*/	0x80100093, //          	li	ra,-2047
   /*10504:*/	0x00100913, //          	li	s2,1
   /*10508:*/	0x01208663, //          	beq	ra,s2,10514 <userstart+0x4a0>
   /*1050c:*/	0x00012137, //          	lui	sp,0x12
   /*10510:*/	0x3ab10113, //          	addi	sp,sp,939 # 123ab <__global_pointer$+0x5ab>
   /*10514:*/	0x0021a023, //          	sw	sp,0(gp) # 11e00 <__global_pointer$>
   /*10518:*/	0x0000d0b7, //          	lui	ra,0xd
   /*1051c:*/	0xccc08093, //          	addi	ra,ra,-820 # cccc <userstart-0x33a8>
   /*10520:*/	0x00000013, //          	nop
   /*10524:*/	0x00000893, //          	li	a7,0
   /*10528:*/	0x01100663, //          	beq	zero,a7,10534 <userstart+0x4c0>
   /*1052c:*/	0x000120b7, //          	lui	ra,0x12
   /*10530:*/	0x3ab08093, //          	addi	ra,ra,939 # 123ab <__global_pointer$+0x5ab>
   /*10534:*/	0x0011a223, //          	sw	ra,4(gp) # 11e04 <__global_pointer$+0x4>
   /*10538:*/	0x00100513, //          	li	a0,1
   /*1053c:*/	0x00000073, //          	ecall
};
