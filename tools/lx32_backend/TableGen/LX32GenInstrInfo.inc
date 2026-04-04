/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Target Instruction Enum Values and Descriptors                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_INSTRINFO_ENUM
#undef GET_INSTRINFO_ENUM

namespace llvm::LX32 {

  enum {
    PHI                                   = 0, // Target.td:1301
    INLINEASM                             = 1, // Target.td:1307
    INLINEASM_BR                          = 2, // Target.td:1313
    CFI_INSTRUCTION                       = 3, // Target.td:1322
    EH_LABEL                              = 4, // Target.td:1331
    GC_LABEL                              = 5, // Target.td:1340
    ANNOTATION_LABEL                      = 6, // Target.td:1349
    KILL                                  = 7, // Target.td:1357
    EXTRACT_SUBREG                        = 8, // Target.td:1364
    INSERT_SUBREG                         = 9, // Target.td:1370
    IMPLICIT_DEF                          = 10, // Target.td:1377
    INIT_UNDEF                            = 11, // Target.td:1386
    SUBREG_TO_REG                         = 12, // Target.td:1393
    COPY_TO_REGCLASS                      = 13, // Target.td:1399
    DBG_VALUE                             = 14, // Target.td:1406
    DBG_VALUE_LIST                        = 15, // Target.td:1413
    DBG_INSTR_REF                         = 16, // Target.td:1420
    DBG_PHI                               = 17, // Target.td:1427
    DBG_LABEL                             = 18, // Target.td:1434
    REG_SEQUENCE                          = 19, // Target.td:1441
    COPY                                  = 20, // Target.td:1448
    COPY_LANEMASK                         = 21, // Target.td:1456
    BUNDLE                                = 22, // Target.td:1463
    LIFETIME_START                        = 23, // Target.td:1469
    LIFETIME_END                          = 24, // Target.td:1476
    PSEUDO_PROBE                          = 25, // Target.td:1483
    ARITH_FENCE                           = 26, // Target.td:1490
    STACKMAP                              = 27, // Target.td:1499
    FENTRY_CALL                           = 28, // Target.td:1634
    PATCHPOINT                            = 29, // Target.td:1507
    LOAD_STACK_GUARD                      = 30, // Target.td:1525
    PREALLOCATED_SETUP                    = 31, // Target.td:1533
    PREALLOCATED_ARG                      = 32, // Target.td:1539
    STATEPOINT                            = 33, // Target.td:1516
    LOCAL_ESCAPE                          = 34, // Target.td:1545
    FAULTING_OP                           = 35, // Target.td:1554
    PATCHABLE_OP                          = 36, // Target.td:1574
    PATCHABLE_FUNCTION_ENTER              = 37, // Target.td:1582
    PATCHABLE_RET                         = 38, // Target.td:1589
    PATCHABLE_FUNCTION_EXIT               = 39, // Target.td:1598
    PATCHABLE_TAIL_CALL                   = 40, // Target.td:1606
    PATCHABLE_EVENT_CALL                  = 41, // Target.td:1614
    PATCHABLE_TYPED_EVENT_CALL            = 42, // Target.td:1624
    ICALL_BRANCH_FUNNEL                   = 43, // Target.td:1644
    FAKE_USE                              = 44, // Target.td:1564
    MEMBARRIER                            = 45, // Target.td:1650
    JUMP_TABLE_DEBUG_INFO                 = 46, // Target.td:1658
    RELOC_NONE                            = 47, // Target.td:1666
    CONVERGENCECTRL_ENTRY                 = 48, // Target.td:1677
    CONVERGENCECTRL_ANCHOR                = 49, // Target.td:1673
    CONVERGENCECTRL_LOOP                  = 50, // Target.td:1681
    CONVERGENCECTRL_GLUE                  = 51, // Target.td:1685
    G_ASSERT_SEXT                         = 52, // GenericOpcodes.td:1865
    G_ASSERT_ZEXT                         = 53, // GenericOpcodes.td:1857
    G_ASSERT_ALIGN                        = 54, // GenericOpcodes.td:1872
    G_ADD                                 = 55, // GenericOpcodes.td:300
    G_SUB                                 = 56, // GenericOpcodes.td:308
    G_MUL                                 = 57, // GenericOpcodes.td:316
    G_SDIV                                = 58, // GenericOpcodes.td:324
    G_UDIV                                = 59, // GenericOpcodes.td:332
    G_SREM                                = 60, // GenericOpcodes.td:340
    G_UREM                                = 61, // GenericOpcodes.td:348
    G_SDIVREM                             = 62, // GenericOpcodes.td:356
    G_UDIVREM                             = 63, // GenericOpcodes.td:364
    G_AND                                 = 64, // GenericOpcodes.td:372
    G_OR                                  = 65, // GenericOpcodes.td:380
    G_XOR                                 = 66, // GenericOpcodes.td:388
    G_ABDS                                = 67, // GenericOpcodes.td:417
    G_ABDU                                = 68, // GenericOpcodes.td:425
    G_UAVGFLOOR                           = 69, // GenericOpcodes.td:433
    G_UAVGCEIL                            = 70, // GenericOpcodes.td:440
    G_SAVGFLOOR                           = 71, // GenericOpcodes.td:447
    G_SAVGCEIL                            = 72, // GenericOpcodes.td:454
    G_IMPLICIT_DEF                        = 73, // GenericOpcodes.td:110
    G_PHI                                 = 74, // GenericOpcodes.td:116
    G_FRAME_INDEX                         = 75, // GenericOpcodes.td:122
    G_GLOBAL_VALUE                        = 76, // GenericOpcodes.td:128
    G_PTRAUTH_GLOBAL_VALUE                = 77, // GenericOpcodes.td:134
    G_CONSTANT_POOL                       = 78, // GenericOpcodes.td:140
    G_EXTRACT                             = 79, // GenericOpcodes.td:1472
    G_UNMERGE_VALUES                      = 80, // GenericOpcodes.td:1484
    G_INSERT                              = 81, // GenericOpcodes.td:1492
    G_MERGE_VALUES                        = 82, // GenericOpcodes.td:1502
    G_BUILD_VECTOR                        = 83, // GenericOpcodes.td:1521
    G_BUILD_VECTOR_TRUNC                  = 84, // GenericOpcodes.td:1530
    G_CONCAT_VECTORS                      = 85, // GenericOpcodes.td:1537
    G_PTRTOINT                            = 86, // GenericOpcodes.td:152
    G_INTTOPTR                            = 87, // GenericOpcodes.td:146
    G_BITCAST                             = 88, // GenericOpcodes.td:158
    G_FREEZE                              = 89, // GenericOpcodes.td:277
    G_CONSTANT_FOLD_BARRIER               = 90, // GenericOpcodes.td:1879
    G_INTRINSIC_FPTRUNC_ROUND             = 91, // GenericOpcodes.td:1263
    G_INTRINSIC_TRUNC                     = 92, // GenericOpcodes.td:1269
    G_INTRINSIC_ROUND                     = 93, // GenericOpcodes.td:1275
    G_INTRINSIC_LRINT                     = 94, // GenericOpcodes.td:1281
    G_INTRINSIC_LLRINT                    = 95, // GenericOpcodes.td:1287
    G_INTRINSIC_ROUNDEVEN                 = 96, // GenericOpcodes.td:1293
    G_READCYCLECOUNTER                    = 97, // GenericOpcodes.td:1299
    G_READSTEADYCOUNTER                   = 98, // GenericOpcodes.td:1305
    G_LOAD                                = 99, // GenericOpcodes.td:1332
    G_SEXTLOAD                            = 100, // GenericOpcodes.td:1340
    G_ZEXTLOAD                            = 101, // GenericOpcodes.td:1348
    G_INDEXED_LOAD                        = 102, // GenericOpcodes.td:1358
    G_INDEXED_SEXTLOAD                    = 103, // GenericOpcodes.td:1366
    G_INDEXED_ZEXTLOAD                    = 104, // GenericOpcodes.td:1374
    G_STORE                               = 105, // GenericOpcodes.td:1382
    G_INDEXED_STORE                       = 106, // GenericOpcodes.td:1390
    G_ATOMIC_CMPXCHG_WITH_SUCCESS         = 107, // GenericOpcodes.td:1400
    G_ATOMIC_CMPXCHG                      = 108, // GenericOpcodes.td:1410
    G_ATOMICRMW_XCHG                      = 109, // GenericOpcodes.td:1428
    G_ATOMICRMW_ADD                       = 110, // GenericOpcodes.td:1429
    G_ATOMICRMW_SUB                       = 111, // GenericOpcodes.td:1430
    G_ATOMICRMW_AND                       = 112, // GenericOpcodes.td:1431
    G_ATOMICRMW_NAND                      = 113, // GenericOpcodes.td:1432
    G_ATOMICRMW_OR                        = 114, // GenericOpcodes.td:1433
    G_ATOMICRMW_XOR                       = 115, // GenericOpcodes.td:1434
    G_ATOMICRMW_MAX                       = 116, // GenericOpcodes.td:1435
    G_ATOMICRMW_MIN                       = 117, // GenericOpcodes.td:1436
    G_ATOMICRMW_UMAX                      = 118, // GenericOpcodes.td:1437
    G_ATOMICRMW_UMIN                      = 119, // GenericOpcodes.td:1438
    G_ATOMICRMW_FADD                      = 120, // GenericOpcodes.td:1439
    G_ATOMICRMW_FSUB                      = 121, // GenericOpcodes.td:1440
    G_ATOMICRMW_FMAX                      = 122, // GenericOpcodes.td:1441
    G_ATOMICRMW_FMIN                      = 123, // GenericOpcodes.td:1442
    G_ATOMICRMW_FMAXIMUM                  = 124, // GenericOpcodes.td:1443
    G_ATOMICRMW_FMINIMUM                  = 125, // GenericOpcodes.td:1444
    G_ATOMICRMW_UINC_WRAP                 = 126, // GenericOpcodes.td:1445
    G_ATOMICRMW_UDEC_WRAP                 = 127, // GenericOpcodes.td:1446
    G_ATOMICRMW_USUB_COND                 = 128, // GenericOpcodes.td:1447
    G_ATOMICRMW_USUB_SAT                  = 129, // GenericOpcodes.td:1448
    G_FENCE                               = 130, // GenericOpcodes.td:1450
    G_PREFETCH                            = 131, // GenericOpcodes.td:1457
    G_BRCOND                              = 132, // GenericOpcodes.td:1592
    G_BRINDIRECT                          = 133, // GenericOpcodes.td:1601
    G_INVOKE_REGION_START                 = 134, // GenericOpcodes.td:1624
    G_INTRINSIC                           = 135, // GenericOpcodes.td:1544
    G_INTRINSIC_W_SIDE_EFFECTS            = 136, // GenericOpcodes.td:1551
    G_INTRINSIC_CONVERGENT                = 137, // GenericOpcodes.td:1560
    G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS = 138, // GenericOpcodes.td:1568
    G_ANYEXT                              = 139, // GenericOpcodes.td:44
    G_TRUNC                               = 140, // GenericOpcodes.td:83
    G_TRUNC_SSAT_S                        = 141, // GenericOpcodes.td:90
    G_TRUNC_SSAT_U                        = 142, // GenericOpcodes.td:97
    G_TRUNC_USAT_U                        = 143, // GenericOpcodes.td:104
    G_CONSTANT                            = 144, // GenericOpcodes.td:165
    G_FCONSTANT                           = 145, // GenericOpcodes.td:172
    G_VASTART                             = 146, // GenericOpcodes.td:178
    G_VAARG                               = 147, // GenericOpcodes.td:185
    G_SEXT                                = 148, // GenericOpcodes.td:52
    G_SEXT_INREG                          = 149, // GenericOpcodes.td:66
    G_ZEXT                                = 150, // GenericOpcodes.td:74
    G_SHL                                 = 151, // GenericOpcodes.td:396
    G_LSHR                                = 152, // GenericOpcodes.td:403
    G_ASHR                                = 153, // GenericOpcodes.td:410
    G_FSHL                                = 154, // GenericOpcodes.td:462
    G_FSHR                                = 155, // GenericOpcodes.td:470
    G_ROTR                                = 156, // GenericOpcodes.td:477
    G_ROTL                                = 157, // GenericOpcodes.td:484
    G_ICMP                                = 158, // GenericOpcodes.td:491
    G_FCMP                                = 159, // GenericOpcodes.td:498
    G_SCMP                                = 160, // GenericOpcodes.td:505
    G_UCMP                                = 161, // GenericOpcodes.td:512
    G_SELECT                              = 162, // GenericOpcodes.td:519
    G_UADDO                               = 163, // GenericOpcodes.td:584
    G_UADDE                               = 164, // GenericOpcodes.td:592
    G_USUBO                               = 165, // GenericOpcodes.td:614
    G_USUBE                               = 166, // GenericOpcodes.td:620
    G_SADDO                               = 167, // GenericOpcodes.td:599
    G_SADDE                               = 168, // GenericOpcodes.td:607
    G_SSUBO                               = 169, // GenericOpcodes.td:627
    G_SSUBE                               = 170, // GenericOpcodes.td:634
    G_UMULO                               = 171, // GenericOpcodes.td:641
    G_SMULO                               = 172, // GenericOpcodes.td:649
    G_UMULH                               = 173, // GenericOpcodes.td:658
    G_SMULH                               = 174, // GenericOpcodes.td:667
    G_UADDSAT                             = 175, // GenericOpcodes.td:679
    G_SADDSAT                             = 176, // GenericOpcodes.td:687
    G_USUBSAT                             = 177, // GenericOpcodes.td:695
    G_SSUBSAT                             = 178, // GenericOpcodes.td:703
    G_USHLSAT                             = 179, // GenericOpcodes.td:711
    G_SSHLSAT                             = 180, // GenericOpcodes.td:719
    G_SMULFIX                             = 181, // GenericOpcodes.td:731
    G_UMULFIX                             = 182, // GenericOpcodes.td:738
    G_SMULFIXSAT                          = 183, // GenericOpcodes.td:748
    G_UMULFIXSAT                          = 184, // GenericOpcodes.td:755
    G_SDIVFIX                             = 185, // GenericOpcodes.td:766
    G_UDIVFIX                             = 186, // GenericOpcodes.td:773
    G_SDIVFIXSAT                          = 187, // GenericOpcodes.td:783
    G_UDIVFIXSAT                          = 188, // GenericOpcodes.td:790
    G_FADD                                = 189, // GenericOpcodes.td:963
    G_FSUB                                = 190, // GenericOpcodes.td:971
    G_FMUL                                = 191, // GenericOpcodes.td:979
    G_FMA                                 = 192, // GenericOpcodes.td:988
    G_FMAD                                = 193, // GenericOpcodes.td:997
    G_FDIV                                = 194, // GenericOpcodes.td:1005
    G_FREM                                = 195, // GenericOpcodes.td:1012
    G_FMODF                               = 196, // GenericOpcodes.td:1019
    G_FPOW                                = 197, // GenericOpcodes.td:1026
    G_FPOWI                               = 198, // GenericOpcodes.td:1033
    G_FEXP                                = 199, // GenericOpcodes.td:1040
    G_FEXP2                               = 200, // GenericOpcodes.td:1047
    G_FEXP10                              = 201, // GenericOpcodes.td:1054
    G_FLOG                                = 202, // GenericOpcodes.td:1061
    G_FLOG2                               = 203, // GenericOpcodes.td:1068
    G_FLOG10                              = 204, // GenericOpcodes.td:1075
    G_FLDEXP                              = 205, // GenericOpcodes.td:1082
    G_FFREXP                              = 206, // GenericOpcodes.td:1089
    G_FNEG                                = 207, // GenericOpcodes.td:801
    G_FPEXT                               = 208, // GenericOpcodes.td:807
    G_FPTRUNC                             = 209, // GenericOpcodes.td:813
    G_FPTOSI                              = 210, // GenericOpcodes.td:819
    G_FPTOUI                              = 211, // GenericOpcodes.td:825
    G_SITOFP                              = 212, // GenericOpcodes.td:831
    G_UITOFP                              = 213, // GenericOpcodes.td:837
    G_FPTOSI_SAT                          = 214, // GenericOpcodes.td:843
    G_FPTOUI_SAT                          = 215, // GenericOpcodes.td:849
    G_FABS                                = 216, // GenericOpcodes.td:855
    G_FCOPYSIGN                           = 217, // GenericOpcodes.td:861
    G_IS_FPCLASS                          = 218, // GenericOpcodes.td:874
    G_FCANONICALIZE                       = 219, // GenericOpcodes.td:867
    G_FMINNUM                             = 220, // GenericOpcodes.td:887
    G_FMAXNUM                             = 221, // GenericOpcodes.td:894
    G_FMINNUM_IEEE                        = 222, // GenericOpcodes.td:912
    G_FMAXNUM_IEEE                        = 223, // GenericOpcodes.td:919
    G_FMINIMUM                            = 224, // GenericOpcodes.td:929
    G_FMAXIMUM                            = 225, // GenericOpcodes.td:936
    G_FMINIMUMNUM                         = 226, // GenericOpcodes.td:944
    G_FMAXIMUMNUM                         = 227, // GenericOpcodes.td:951
    G_GET_FPENV                           = 228, // GenericOpcodes.td:1219
    G_SET_FPENV                           = 229, // GenericOpcodes.td:1226
    G_RESET_FPENV                         = 230, // GenericOpcodes.td:1233
    G_GET_FPMODE                          = 231, // GenericOpcodes.td:1240
    G_SET_FPMODE                          = 232, // GenericOpcodes.td:1247
    G_RESET_FPMODE                        = 233, // GenericOpcodes.td:1254
    G_GET_ROUNDING                        = 234, // GenericOpcodes.td:1311
    G_SET_ROUNDING                        = 235, // GenericOpcodes.td:1317
    G_PTR_ADD                             = 236, // GenericOpcodes.td:526
    G_PTRMASK                             = 237, // GenericOpcodes.td:534
    G_SMIN                                = 238, // GenericOpcodes.td:541
    G_SMAX                                = 239, // GenericOpcodes.td:549
    G_UMIN                                = 240, // GenericOpcodes.td:557
    G_UMAX                                = 241, // GenericOpcodes.td:565
    G_ABS                                 = 242, // GenericOpcodes.td:573
    G_LROUND                              = 243, // GenericOpcodes.td:283
    G_LLROUND                             = 244, // GenericOpcodes.td:289
    G_BR                                  = 245, // GenericOpcodes.td:1582
    G_BRJT                                = 246, // GenericOpcodes.td:1612
    G_VSCALE                              = 247, // GenericOpcodes.td:1512
    G_INSERT_SUBVECTOR                    = 248, // GenericOpcodes.td:1656
    G_EXTRACT_SUBVECTOR                   = 249, // GenericOpcodes.td:1663
    G_INSERT_VECTOR_ELT                   = 250, // GenericOpcodes.td:1670
    G_EXTRACT_VECTOR_ELT                  = 251, // GenericOpcodes.td:1677
    G_SHUFFLE_VECTOR                      = 252, // GenericOpcodes.td:1687
    G_SPLAT_VECTOR                        = 253, // GenericOpcodes.td:1694
    G_STEP_VECTOR                         = 254, // GenericOpcodes.td:1701
    G_VECTOR_COMPRESS                     = 255, // GenericOpcodes.td:1708
    G_CTTZ                                = 256, // GenericOpcodes.td:205
    G_CTTZ_ZERO_UNDEF                     = 257, // GenericOpcodes.td:211
    G_CTLZ                                = 258, // GenericOpcodes.td:193
    G_CTLZ_ZERO_UNDEF                     = 259, // GenericOpcodes.td:199
    G_CTLS                                = 260, // GenericOpcodes.td:217
    G_CTPOP                               = 261, // GenericOpcodes.td:223
    G_BSWAP                               = 262, // GenericOpcodes.td:229
    G_BITREVERSE                          = 263, // GenericOpcodes.td:235
    G_FCEIL                               = 264, // GenericOpcodes.td:1096
    G_FCOS                                = 265, // GenericOpcodes.td:1103
    G_FSIN                                = 266, // GenericOpcodes.td:1110
    G_FSINCOS                             = 267, // GenericOpcodes.td:1117
    G_FTAN                                = 268, // GenericOpcodes.td:1124
    G_FACOS                               = 269, // GenericOpcodes.td:1131
    G_FASIN                               = 270, // GenericOpcodes.td:1138
    G_FATAN                               = 271, // GenericOpcodes.td:1145
    G_FATAN2                              = 272, // GenericOpcodes.td:1152
    G_FCOSH                               = 273, // GenericOpcodes.td:1159
    G_FSINH                               = 274, // GenericOpcodes.td:1166
    G_FTANH                               = 275, // GenericOpcodes.td:1173
    G_FSQRT                               = 276, // GenericOpcodes.td:1183
    G_FFLOOR                              = 277, // GenericOpcodes.td:1190
    G_FRINT                               = 278, // GenericOpcodes.td:1197
    G_FNEARBYINT                          = 279, // GenericOpcodes.td:1204
    G_ADDRSPACE_CAST                      = 280, // GenericOpcodes.td:241
    G_BLOCK_ADDR                          = 281, // GenericOpcodes.td:247
    G_JUMP_TABLE                          = 282, // GenericOpcodes.td:253
    G_DYN_STACKALLOC                      = 283, // GenericOpcodes.td:259
    G_STACKSAVE                           = 284, // GenericOpcodes.td:265
    G_STACKRESTORE                        = 285, // GenericOpcodes.td:271
    G_STRICT_FADD                         = 286, // GenericOpcodes.td:1758
    G_STRICT_FSUB                         = 287, // GenericOpcodes.td:1759
    G_STRICT_FMUL                         = 288, // GenericOpcodes.td:1760
    G_STRICT_FDIV                         = 289, // GenericOpcodes.td:1761
    G_STRICT_FREM                         = 290, // GenericOpcodes.td:1762
    G_STRICT_FMA                          = 291, // GenericOpcodes.td:1763
    G_STRICT_FSQRT                        = 292, // GenericOpcodes.td:1764
    G_STRICT_FLDEXP                       = 293, // GenericOpcodes.td:1765
    G_READ_REGISTER                       = 294, // GenericOpcodes.td:1631
    G_WRITE_REGISTER                      = 295, // GenericOpcodes.td:1641
    G_MEMCPY                              = 296, // GenericOpcodes.td:1771
    G_MEMCPY_INLINE                       = 297, // GenericOpcodes.td:1779
    G_MEMMOVE                             = 298, // GenericOpcodes.td:1787
    G_MEMSET                              = 299, // GenericOpcodes.td:1795
    G_BZERO                               = 300, // GenericOpcodes.td:1802
    G_TRAP                                = 301, // GenericOpcodes.td:1812
    G_DEBUGTRAP                           = 302, // GenericOpcodes.td:1819
    G_UBSANTRAP                           = 303, // GenericOpcodes.td:1825
    G_VECREDUCE_SEQ_FADD                  = 304, // GenericOpcodes.td:1724
    G_VECREDUCE_SEQ_FMUL                  = 305, // GenericOpcodes.td:1730
    G_VECREDUCE_FADD                      = 306, // GenericOpcodes.td:1736
    G_VECREDUCE_FMUL                      = 307, // GenericOpcodes.td:1737
    G_VECREDUCE_FMAX                      = 308, // GenericOpcodes.td:1739
    G_VECREDUCE_FMIN                      = 309, // GenericOpcodes.td:1740
    G_VECREDUCE_FMAXIMUM                  = 310, // GenericOpcodes.td:1741
    G_VECREDUCE_FMINIMUM                  = 311, // GenericOpcodes.td:1742
    G_VECREDUCE_ADD                       = 312, // GenericOpcodes.td:1744
    G_VECREDUCE_MUL                       = 313, // GenericOpcodes.td:1745
    G_VECREDUCE_AND                       = 314, // GenericOpcodes.td:1746
    G_VECREDUCE_OR                        = 315, // GenericOpcodes.td:1747
    G_VECREDUCE_XOR                       = 316, // GenericOpcodes.td:1748
    G_VECREDUCE_SMAX                      = 317, // GenericOpcodes.td:1749
    G_VECREDUCE_SMIN                      = 318, // GenericOpcodes.td:1750
    G_VECREDUCE_UMAX                      = 319, // GenericOpcodes.td:1751
    G_VECREDUCE_UMIN                      = 320, // GenericOpcodes.td:1752
    G_SBFX                                = 321, // GenericOpcodes.td:1837
    G_UBFX                                = 322, // GenericOpcodes.td:1845
    ADJCALLSTACKDOWN                      = 323, // LX32InstrInfo.td:514
    ADJCALLSTACKUP                        = 324, // LX32InstrInfo.td:523
    LX32_LOAD_STACK_GUARD                 = 325, // LX32InstrInfo.td:496
    LX32_PREALLOCATED_ARG                 = 326, // LX32InstrInfo.td:503
    PseudoCALL                            = 327, // LX32InstrInfo.td:460
    PseudoLA                              = 328, // LX32InstrInfo.td:466
    PseudoNOP                             = 329, // LX32InstrInfo.td:469
    PseudoRET                             = 330, // LX32InstrInfo.td:453
    ADD                                   = 331, // LX32InstrInfo.td:158
    ADDI                                  = 332, // LX32InstrInfo.td:194
    AND                                   = 333, // LX32InstrInfo.td:167
    ANDI                                  = 334, // LX32InstrInfo.td:199
    AUIPC                                 = 335, // LX32InstrInfo.td:385
    BEQ                                   = 336, // LX32InstrInfo.td:328
    BGE                                   = 337, // LX32InstrInfo.td:331
    BGEU                                  = 338, // LX32InstrInfo.td:333
    BLT                                   = 339, // LX32InstrInfo.td:330
    BLTU                                  = 340, // LX32InstrInfo.td:332
    BNE                                   = 341, // LX32InstrInfo.td:329
    JAL                                   = 342, // LX32InstrInfo.td:360
    JALR                                  = 343, // LX32InstrInfo.td:363
    LB                                    = 344, // LX32InstrInfo.td:258
    LBU                                   = 345, // LX32InstrInfo.td:261
    LH                                    = 346, // LX32InstrInfo.td:252
    LHU                                   = 347, // LX32InstrInfo.td:255
    LUI                                   = 348, // LX32InstrInfo.td:383
    LW                                    = 349, // LX32InstrInfo.td:249
    OR                                    = 350, // LX32InstrInfo.td:166
    ORI                                   = 351, // LX32InstrInfo.td:198
    SB                                    = 352, // LX32InstrInfo.td:300
    SH                                    = 353, // LX32InstrInfo.td:296
    SLL                                   = 354, // LX32InstrInfo.td:160
    SLLI                                  = 355, // LX32InstrInfo.td:207
    SLT                                   = 356, // LX32InstrInfo.td:161
    SLTI                                  = 357, // LX32InstrInfo.td:195
    SLTIU                                 = 358, // LX32InstrInfo.td:196
    SLTU                                  = 359, // LX32InstrInfo.td:162
    SRA                                   = 360, // LX32InstrInfo.td:165
    SRAI                                  = 361, // LX32InstrInfo.td:219
    SRL                                   = 362, // LX32InstrInfo.td:164
    SRLI                                  = 363, // LX32InstrInfo.td:213
    SUB                                   = 364, // LX32InstrInfo.td:159
    SW                                    = 365, // LX32InstrInfo.td:292
    XOR                                   = 366, // LX32InstrInfo.td:163
    XORI                                  = 367, // LX32InstrInfo.td:197
    INSTRUCTION_LIST_END = 368
  };

} // namespace llvm::LX32

#endif // GET_INSTRINFO_ENUM

#ifdef GET_INSTRINFO_SCHED_ENUM
#undef GET_INSTRINFO_SCHED_ENUM

namespace llvm::LX32::Sched {

  enum {
    NoInstrModel	= 0,
    SCHED_LIST_END = 1
  };

} // namespace llvm::LX32::Sched

#endif // GET_INSTRINFO_SCHED_ENUM

#if defined(GET_INSTRINFO_MC_DESC) || defined(GET_INSTRINFO_CTOR_DTOR)

namespace llvm {

struct LX32InstrTable {
  MCInstrDesc Insts[368];
  static_assert(alignof(MCInstrDesc) >= alignof(MCPhysReg), "Unwanted padding between Insts and ImplicitOps");
  MCPhysReg ImplicitOps[1];
  char Padding[sizeof(MCOperandInfo) - sizeof ImplicitOps % sizeof(MCOperandInfo)];
  static_assert(alignof(MCInstrDesc) >= alignof(MCOperandInfo), "Unwanted padding between Insts and OperandInfo");
  MCOperandInfo OperandInfo[158];
};
} // namespace llvm

#endif // defined(GET_INSTRINFO_MC_DESC) || defined(GET_INSTRINFO_CTOR_DTOR)

#ifdef GET_INSTRINFO_MC_DESC
#undef GET_INSTRINFO_MC_DESC

namespace llvm {

static_assert((sizeof LX32InstrTable::ImplicitOps + sizeof LX32InstrTable::Padding) % sizeof(MCOperandInfo) == 0);
static constexpr unsigned LX32OpInfoBase = (sizeof LX32InstrTable::ImplicitOps + sizeof LX32InstrTable::Padding) / sizeof(MCOperandInfo);

extern const LX32InstrTable LX32Descs = {
  {
    { 367,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0, 0x0ULL },  // XORI
    { 366,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 152,	0,	0, 0x0ULL },  // XOR
    { 365,	3,	0,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0|(1ULL<<MCID::MayStore), 0x0ULL },  // SW
    { 364,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 152,	0,	0, 0x0ULL },  // SUB
    { 363,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0, 0x0ULL },  // SRLI
    { 362,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 152,	0,	0, 0x0ULL },  // SRL
    { 361,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0, 0x0ULL },  // SRAI
    { 360,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 152,	0,	0, 0x0ULL },  // SRA
    { 359,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 152,	0,	0, 0x0ULL },  // SLTU
    { 358,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0, 0x0ULL },  // SLTIU
    { 357,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0, 0x0ULL },  // SLTI
    { 356,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 152,	0,	0, 0x0ULL },  // SLT
    { 355,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0, 0x0ULL },  // SLLI
    { 354,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 152,	0,	0, 0x0ULL },  // SLL
    { 353,	3,	0,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0|(1ULL<<MCID::MayStore), 0x0ULL },  // SH
    { 352,	3,	0,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0|(1ULL<<MCID::MayStore), 0x0ULL },  // SB
    { 351,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0, 0x0ULL },  // ORI
    { 350,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 152,	0,	0, 0x0ULL },  // OR
    { 349,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0|(1ULL<<MCID::MayLoad), 0x0ULL },  // LW
    { 348,	2,	1,	4,	0,	0,	0,	LX32OpInfoBase + 34,	0,	0, 0x0ULL },  // LUI
    { 347,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0|(1ULL<<MCID::MayLoad), 0x0ULL },  // LHU
    { 346,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0|(1ULL<<MCID::MayLoad), 0x0ULL },  // LH
    { 345,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0|(1ULL<<MCID::MayLoad), 0x0ULL },  // LBU
    { 344,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0|(1ULL<<MCID::MayLoad), 0x0ULL },  // LB
    { 343,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator), 0x0ULL },  // JALR
    { 342,	2,	1,	4,	0,	0,	0,	LX32OpInfoBase + 34,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator), 0x0ULL },  // JAL
    { 341,	3,	0,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator), 0x0ULL },  // BNE
    { 340,	3,	0,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator), 0x0ULL },  // BLTU
    { 339,	3,	0,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator), 0x0ULL },  // BLT
    { 338,	3,	0,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator), 0x0ULL },  // BGEU
    { 337,	3,	0,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator), 0x0ULL },  // BGE
    { 336,	3,	0,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator), 0x0ULL },  // BEQ
    { 335,	2,	1,	4,	0,	0,	0,	LX32OpInfoBase + 34,	0,	0, 0x0ULL },  // AUIPC
    { 334,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0, 0x0ULL },  // ANDI
    { 333,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 152,	0,	0, 0x0ULL },  // AND
    { 332,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 155,	0,	0, 0x0ULL },  // ADDI
    { 331,	3,	1,	4,	0,	0,	0,	LX32OpInfoBase + 152,	0,	0, 0x0ULL },  // ADD
    { 330,	0,	0,	4,	0,	1,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Return)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator), 0x0ULL },  // PseudoRET
    { 329,	0,	0,	4,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo), 0x0ULL },  // PseudoNOP
    { 328,	2,	1,	4,	0,	0,	0,	LX32OpInfoBase + 34,	0,	0|(1ULL<<MCID::Pseudo), 0x0ULL },  // PseudoLA
    { 327,	1,	0,	4,	0,	0,	1,	LX32OpInfoBase + 151,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // PseudoCALL
    { 326,	1,	0,	4,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // LX32_PREALLOCATED_ARG
    { 325,	1,	1,	4,	0,	0,	0,	LX32OpInfoBase + 28,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad), 0x0ULL },  // LX32_LOAD_STACK_GUARD
    { 324,	2,	0,	4,	0,	0,	0,	LX32OpInfoBase + 20,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // ADJCALLSTACKUP
    { 323,	2,	0,	4,	0,	0,	0,	LX32OpInfoBase + 20,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // ADJCALLSTACKDOWN
    { 322,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 147,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_UBFX
    { 321,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 147,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SBFX
    { 320,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_UMIN
    { 319,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_UMAX
    { 318,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_SMIN
    { 317,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_SMAX
    { 316,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_XOR
    { 315,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_OR
    { 314,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_AND
    { 313,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_MUL
    { 312,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_ADD
    { 311,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_FMINIMUM
    { 310,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_FMAXIMUM
    { 309,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_FMIN
    { 308,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_FMAX
    { 307,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_FMUL
    { 306,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_FADD
    { 305,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 130,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_SEQ_FMUL
    { 304,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 130,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECREDUCE_SEQ_FADD
    { 303,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_UBSANTRAP
    { 302,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_DEBUGTRAP
    { 301,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_TRAP
    { 300,	3,	0,	0,	0,	0,	0,	LX32OpInfoBase + 57,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_BZERO
    { 299,	4,	0,	0,	0,	0,	0,	LX32OpInfoBase + 143,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_MEMSET
    { 298,	4,	0,	0,	0,	0,	0,	LX32OpInfoBase + 143,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_MEMMOVE
    { 297,	3,	0,	0,	0,	0,	0,	LX32OpInfoBase + 130,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_MEMCPY_INLINE
    { 296,	4,	0,	0,	0,	0,	0,	LX32OpInfoBase + 143,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_MEMCPY
    { 295,	2,	0,	0,	0,	0,	0,	LX32OpInfoBase + 141,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::Convergent), 0x0ULL },  // G_WRITE_REGISTER
    { 294,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 50,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::Convergent), 0x0ULL },  // G_READ_REGISTER
    { 293,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 100,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayRaiseFPException)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_STRICT_FLDEXP
    { 292,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayRaiseFPException)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_STRICT_FSQRT
    { 291,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 45,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayRaiseFPException)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_STRICT_FMA
    { 290,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayRaiseFPException)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_STRICT_FREM
    { 289,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayRaiseFPException)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_STRICT_FDIV
    { 288,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayRaiseFPException)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_STRICT_FMUL
    { 287,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayRaiseFPException)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_STRICT_FSUB
    { 286,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayRaiseFPException)|(1ULL<<MCID::Commutable)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_STRICT_FADD
    { 285,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 49,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_STACKRESTORE
    { 284,	1,	1,	0,	0,	0,	0,	LX32OpInfoBase + 49,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_STACKSAVE
    { 283,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 68,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_DYN_STACKALLOC
    { 282,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 50,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_JUMP_TABLE
    { 281,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 50,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_BLOCK_ADDR
    { 280,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_ADDRSPACE_CAST
    { 279,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FNEARBYINT
    { 278,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FRINT
    { 277,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FFLOOR
    { 276,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FSQRT
    { 275,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FTANH
    { 274,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FSINH
    { 273,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FCOSH
    { 272,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FATAN2
    { 271,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FATAN
    { 270,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FASIN
    { 269,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FACOS
    { 268,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FTAN
    { 267,	3,	2,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FSINCOS
    { 266,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FSIN
    { 265,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FCOS
    { 264,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FCEIL
    { 263,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_BITREVERSE
    { 262,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_BSWAP
    { 261,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_CTPOP
    { 260,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_CTLS
    { 259,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_CTLZ_ZERO_UNDEF
    { 258,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_CTLZ
    { 257,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_CTTZ_ZERO_UNDEF
    { 256,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_CTTZ
    { 255,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 137,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VECTOR_COMPRESS
    { 254,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 50,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_STEP_VECTOR
    { 253,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SPLAT_VECTOR
    { 252,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 133,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SHUFFLE_VECTOR
    { 251,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 130,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_EXTRACT_VECTOR_ELT
    { 250,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 126,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_INSERT_VECTOR_ELT
    { 249,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 57,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_EXTRACT_SUBVECTOR
    { 248,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 62,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_INSERT_SUBVECTOR
    { 247,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 50,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_VSCALE
    { 246,	3,	0,	0,	0,	0,	0,	LX32OpInfoBase + 123,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Branch)|(1ULL<<MCID::IndirectBranch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator), 0x0ULL },  // G_BRJT
    { 245,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 0,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator), 0x0ULL },  // G_BR
    { 244,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_LLROUND
    { 243,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_LROUND
    { 242,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_ABS
    { 241,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_UMAX
    { 240,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_UMIN
    { 239,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_SMAX
    { 238,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_SMIN
    { 237,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 100,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_PTRMASK
    { 236,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 100,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_PTR_ADD
    { 235,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 49,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_SET_ROUNDING
    { 234,	1,	1,	0,	0,	0,	0,	LX32OpInfoBase + 49,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_GET_ROUNDING
    { 233,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_RESET_FPMODE
    { 232,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 49,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_SET_FPMODE
    { 231,	1,	1,	0,	0,	0,	0,	LX32OpInfoBase + 49,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_GET_FPMODE
    { 230,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_RESET_FPENV
    { 229,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 49,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_SET_FPENV
    { 228,	1,	1,	0,	0,	0,	0,	LX32OpInfoBase + 49,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_GET_FPENV
    { 227,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_FMAXIMUMNUM
    { 226,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_FMINIMUMNUM
    { 225,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_FMAXIMUM
    { 224,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_FMINIMUM
    { 223,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_FMAXNUM_IEEE
    { 222,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_FMINNUM_IEEE
    { 221,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_FMAXNUM
    { 220,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_FMINNUM
    { 219,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FCANONICALIZE
    { 218,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 97,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_IS_FPCLASS
    { 217,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 100,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FCOPYSIGN
    { 216,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FABS
    { 215,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FPTOUI_SAT
    { 214,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FPTOSI_SAT
    { 213,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_UITOFP
    { 212,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SITOFP
    { 211,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FPTOUI
    { 210,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FPTOSI
    { 209,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FPTRUNC
    { 208,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FPEXT
    { 207,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FNEG
    { 206,	3,	2,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FFREXP
    { 205,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 100,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FLDEXP
    { 204,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FLOG10
    { 203,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FLOG2
    { 202,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FLOG
    { 201,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FEXP10
    { 200,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FEXP2
    { 199,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FEXP
    { 198,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 100,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FPOWI
    { 197,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FPOW
    { 196,	3,	2,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FMODF
    { 195,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FREM
    { 194,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FDIV
    { 193,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 45,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FMAD
    { 192,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 45,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FMA
    { 191,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_FMUL
    { 190,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FSUB
    { 189,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_FADD
    { 188,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 119,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_UDIVFIXSAT
    { 187,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 119,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SDIVFIXSAT
    { 186,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 119,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_UDIVFIX
    { 185,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 119,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SDIVFIX
    { 184,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 119,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_UMULFIXSAT
    { 183,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 119,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_SMULFIXSAT
    { 182,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 119,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_UMULFIX
    { 181,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 119,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_SMULFIX
    { 180,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 100,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SSHLSAT
    { 179,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 100,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_USHLSAT
    { 178,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SSUBSAT
    { 177,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_USUBSAT
    { 176,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_SADDSAT
    { 175,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_UADDSAT
    { 174,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_SMULH
    { 173,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_UMULH
    { 172,	4,	2,	0,	0,	0,	0,	LX32OpInfoBase + 86,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_SMULO
    { 171,	4,	2,	0,	0,	0,	0,	LX32OpInfoBase + 86,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_UMULO
    { 170,	5,	2,	0,	0,	0,	0,	LX32OpInfoBase + 114,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SSUBE
    { 169,	4,	2,	0,	0,	0,	0,	LX32OpInfoBase + 86,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SSUBO
    { 168,	5,	2,	0,	0,	0,	0,	LX32OpInfoBase + 114,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SADDE
    { 167,	4,	2,	0,	0,	0,	0,	LX32OpInfoBase + 86,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_SADDO
    { 166,	5,	2,	0,	0,	0,	0,	LX32OpInfoBase + 114,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_USUBE
    { 165,	4,	2,	0,	0,	0,	0,	LX32OpInfoBase + 86,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_USUBO
    { 164,	5,	2,	0,	0,	0,	0,	LX32OpInfoBase + 114,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_UADDE
    { 163,	4,	2,	0,	0,	0,	0,	LX32OpInfoBase + 86,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_UADDO
    { 162,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 86,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SELECT
    { 161,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 111,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_UCMP
    { 160,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 111,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SCMP
    { 159,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 107,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FCMP
    { 158,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 107,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_ICMP
    { 157,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 100,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_ROTL
    { 156,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 100,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_ROTR
    { 155,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 103,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FSHR
    { 154,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 103,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FSHL
    { 153,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 100,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_ASHR
    { 152,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 100,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_LSHR
    { 151,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 100,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SHL
    { 150,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_ZEXT
    { 149,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 39,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SEXT_INREG
    { 148,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SEXT
    { 147,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 97,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_VAARG
    { 146,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 49,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_VASTART
    { 145,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 50,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FCONSTANT
    { 144,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 50,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_CONSTANT
    { 143,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_TRUNC_USAT_U
    { 142,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_TRUNC_SSAT_U
    { 141,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_TRUNC_SSAT_S
    { 140,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_TRUNC
    { 139,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_ANYEXT
    { 138,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 0,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects)|(1ULL<<MCID::Convergent), 0x0ULL },  // G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS
    { 137,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 0,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::Convergent), 0x0ULL },  // G_INTRINSIC_CONVERGENT
    { 136,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 0,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_INTRINSIC_W_SIDE_EFFECTS
    { 135,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 0,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic), 0x0ULL },  // G_INTRINSIC
    { 134,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Terminator), 0x0ULL },  // G_INVOKE_REGION_START
    { 133,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 49,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Branch)|(1ULL<<MCID::IndirectBranch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator), 0x0ULL },  // G_BRINDIRECT
    { 132,	2,	0,	0,	0,	0,	0,	LX32OpInfoBase + 50,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator), 0x0ULL },  // G_BRCOND
    { 131,	4,	0,	0,	0,	0,	0,	LX32OpInfoBase + 93,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_PREFETCH
    { 130,	2,	0,	0,	0,	0,	0,	LX32OpInfoBase + 20,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_FENCE
    { 129,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_USUB_SAT
    { 128,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_USUB_COND
    { 127,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_UDEC_WRAP
    { 126,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_UINC_WRAP
    { 125,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_FMINIMUM
    { 124,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_FMAXIMUM
    { 123,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_FMIN
    { 122,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_FMAX
    { 121,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_FSUB
    { 120,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_FADD
    { 119,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_UMIN
    { 118,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_UMAX
    { 117,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_MIN
    { 116,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_MAX
    { 115,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_XOR
    { 114,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_OR
    { 113,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_NAND
    { 112,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_AND
    { 111,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_SUB
    { 110,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_ADD
    { 109,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 90,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMICRMW_XCHG
    { 108,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 86,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMIC_CMPXCHG
    { 107,	5,	2,	0,	0,	0,	0,	LX32OpInfoBase + 81,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_ATOMIC_CMPXCHG_WITH_SUCCESS
    { 106,	5,	1,	0,	0,	0,	0,	LX32OpInfoBase + 76,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_INDEXED_STORE
    { 105,	2,	0,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayStore), 0x0ULL },  // G_STORE
    { 104,	5,	2,	0,	0,	0,	0,	LX32OpInfoBase + 71,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad), 0x0ULL },  // G_INDEXED_ZEXTLOAD
    { 103,	5,	2,	0,	0,	0,	0,	LX32OpInfoBase + 71,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad), 0x0ULL },  // G_INDEXED_SEXTLOAD
    { 102,	5,	2,	0,	0,	0,	0,	LX32OpInfoBase + 71,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad), 0x0ULL },  // G_INDEXED_LOAD
    { 101,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad), 0x0ULL },  // G_ZEXTLOAD
    { 100,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad), 0x0ULL },  // G_SEXTLOAD
    { 99,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad), 0x0ULL },  // G_LOAD
    { 98,	1,	1,	0,	0,	0,	0,	LX32OpInfoBase + 49,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_READSTEADYCOUNTER
    { 97,	1,	1,	0,	0,	0,	0,	LX32OpInfoBase + 49,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // G_READCYCLECOUNTER
    { 96,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_INTRINSIC_ROUNDEVEN
    { 95,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_INTRINSIC_LLRINT
    { 94,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_INTRINSIC_LRINT
    { 93,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_INTRINSIC_ROUND
    { 92,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_INTRINSIC_TRUNC
    { 91,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 68,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_INTRINSIC_FPTRUNC_ROUND
    { 90,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_CONSTANT_FOLD_BARRIER
    { 89,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 66,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FREEZE
    { 88,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_BITCAST
    { 87,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_INTTOPTR
    { 86,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_PTRTOINT
    { 85,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic), 0x0ULL },  // G_CONCAT_VECTORS
    { 84,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic), 0x0ULL },  // G_BUILD_VECTOR_TRUNC
    { 83,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic), 0x0ULL },  // G_BUILD_VECTOR
    { 82,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic), 0x0ULL },  // G_MERGE_VALUES
    { 81,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 62,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_INSERT
    { 80,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 60,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic), 0x0ULL },  // G_UNMERGE_VALUES
    { 79,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 57,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_EXTRACT
    { 78,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 50,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_CONSTANT_POOL
    { 77,	5,	1,	0,	0,	0,	0,	LX32OpInfoBase + 52,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_PTRAUTH_GLOBAL_VALUE
    { 76,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 50,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_GLOBAL_VALUE
    { 75,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 50,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_FRAME_INDEX
    { 74,	1,	1,	0,	0,	0,	0,	LX32OpInfoBase + 49,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic), 0x0ULL },  // G_PHI
    { 73,	1,	1,	0,	0,	0,	0,	LX32OpInfoBase + 49,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_IMPLICIT_DEF
    { 72,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SAVGCEIL
    { 71,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SAVGFLOOR
    { 70,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_UAVGCEIL
    { 69,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_UAVGFLOOR
    { 68,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_ABDU
    { 67,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_ABDS
    { 66,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_XOR
    { 65,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_OR
    { 64,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_AND
    { 63,	4,	2,	0,	0,	0,	0,	LX32OpInfoBase + 45,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_UDIVREM
    { 62,	4,	2,	0,	0,	0,	0,	LX32OpInfoBase + 45,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SDIVREM
    { 61,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_UREM
    { 60,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SREM
    { 59,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_UDIV
    { 58,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SDIV
    { 57,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_MUL
    { 56,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_SUB
    { 55,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 42,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Commutable), 0x0ULL },  // G_ADD
    { 54,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 39,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_ASSERT_ALIGN
    { 53,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 39,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_ASSERT_ZEXT
    { 52,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 39,	0,	0|(1ULL<<MCID::PreISelOpcode)|(1ULL<<MCID::Pseudo), 0x0ULL },  // G_ASSERT_SEXT
    { 51,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Convergent), 0x0ULL },  // CONVERGENCECTRL_GLUE
    { 50,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 9,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Convergent), 0x0ULL },  // CONVERGENCECTRL_LOOP
    { 49,	1,	1,	0,	0,	0,	0,	LX32OpInfoBase + 0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Convergent), 0x0ULL },  // CONVERGENCECTRL_ANCHOR
    { 48,	1,	1,	0,	0,	0,	0,	LX32OpInfoBase + 0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Convergent), 0x0ULL },  // CONVERGENCECTRL_ENTRY
    { 47,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // RELOC_NONE
    { 46,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta), 0x0ULL },  // JUMP_TABLE_DEBUG_INFO
    { 45,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // MEMBARRIER
    { 44,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Variadic), 0x0ULL },  // FAKE_USE
    { 43,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // ICALL_BRANCH_FUNNEL
    { 42,	3,	0,	0,	0,	0,	0,	LX32OpInfoBase + 36,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // anonymous_14635
    { 41,	2,	0,	0,	0,	0,	0,	LX32OpInfoBase + 34,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // anonymous_14634
    { 40,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Return)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // PATCHABLE_TAIL_CALL
    { 39,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // PATCHABLE_FUNCTION_EXIT
    { 38,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Return)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // PATCHABLE_RET
    { 37,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // PATCHABLE_FUNCTION_ENTER
    { 36,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // PATCHABLE_OP
    { 35,	1,	1,	0,	0,	0,	0,	LX32OpInfoBase + 0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Branch)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // FAULTING_OP
    { 34,	2,	0,	0,	0,	0,	0,	LX32OpInfoBase + 32,	0,	0|(1ULL<<MCID::Pseudo), 0x0ULL },  // LOCAL_ESCAPE
    { 33,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // STATEPOINT
    { 32,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 29,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // anonymous_14633
    { 31,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // PREALLOCATED_SETUP
    { 30,	1,	1,	0,	0,	0,	0,	LX32OpInfoBase + 28,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::Rematerializable), 0x0ULL },  // anonymous_14344
    { 29,	6,	1,	0,	0,	0,	0,	LX32OpInfoBase + 22,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // PATCHPOINT
    { 28,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // FENTRY_CALL
    { 27,	2,	0,	0,	0,	0,	0,	LX32OpInfoBase + 20,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // STACKMAP
    { 26,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 18,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta), 0x0ULL },  // ARITH_FENCE
    { 25,	4,	0,	0,	0,	0,	0,	LX32OpInfoBase + 14,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // PSEUDO_PROBE
    { 24,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta), 0x0ULL },  // LIFETIME_END
    { 23,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta), 0x0ULL },  // LIFETIME_START
    { 22,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic), 0x0ULL },  // BUNDLE
    { 21,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 11,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::CheapAsAMove), 0x0ULL },  // COPY_LANEMASK
    { 20,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 9,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::CheapAsAMove), 0x0ULL },  // COPY
    { 19,	2,	1,	0,	0,	0,	0,	LX32OpInfoBase + 9,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::CheapAsAMove), 0x0ULL },  // REG_SEQUENCE
    { 18,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta), 0x0ULL },  // DBG_LABEL
    { 17,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Variadic), 0x0ULL },  // DBG_PHI
    { 16,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Variadic), 0x0ULL },  // DBG_INSTR_REF
    { 15,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Variadic), 0x0ULL },  // DBG_VALUE_LIST
    { 14,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Variadic), 0x0ULL },  // DBG_VALUE
    { 13,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 2,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::CheapAsAMove), 0x0ULL },  // COPY_TO_REGCLASS
    { 12,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 2,	0,	0|(1ULL<<MCID::Pseudo), 0x0ULL },  // SUBREG_TO_REG
    { 11,	1,	1,	0,	0,	0,	0,	LX32OpInfoBase + 0,	0,	0|(1ULL<<MCID::Pseudo), 0x0ULL },  // INIT_UNDEF
    { 10,	1,	1,	0,	0,	0,	0,	LX32OpInfoBase + 0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove), 0x0ULL },  // IMPLICIT_DEF
    { 9,	4,	1,	0,	0,	0,	0,	LX32OpInfoBase + 5,	0,	0|(1ULL<<MCID::Pseudo), 0x0ULL },  // INSERT_SUBREG
    { 8,	3,	1,	0,	0,	0,	0,	LX32OpInfoBase + 2,	0,	0|(1ULL<<MCID::Pseudo), 0x0ULL },  // EXTRACT_SUBREG
    { 7,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::Variadic), 0x0ULL },  // KILL
    { 6,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::NotDuplicable), 0x0ULL },  // ANNOTATION_LABEL
    { 5,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::NotDuplicable), 0x0ULL },  // GC_LABEL
    { 4,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::NotDuplicable), 0x0ULL },  // EH_LABEL
    { 3,	1,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Meta)|(1ULL<<MCID::NotDuplicable), 0x0ULL },  // CFI_INSTRUCTION
    { 2,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL },  // INLINEASM_BR
    { 1,	0,	0,	0,	0,	0,	0,	LX32OpInfoBase + 1,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic), 0x0ULL },  // INLINEASM
    { 0,	1,	1,	0,	0,	0,	0,	LX32OpInfoBase + 0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic), 0x0ULL },  // PHI
  }, {
    /* 0 */
    /* 0 */ LX32::X1,
  }, {
    0
  }, {
    /* 0 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 1 */
    /* 1 */ { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 2 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 5 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, MCOI_TIED_TO(0) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 9 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 11 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 14 */ { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 18 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, MCOI_TIED_TO(0) },
    /* 20 */ { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 22 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 28 */ { LX32::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 29 */ { LX32::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 32 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 34 */ { LX32::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 36 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { LX32::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 39 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_IMM_0, 0 },
    /* 42 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 45 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 49 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 50 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 52 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 57 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_IMM_0, 0 },
    /* 60 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 },
    /* 62 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_IMM_0, 0 },
    /* 66 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 68 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 71 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_2, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 76 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_2, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 81 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_2, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 86 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 90 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 93 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 },
    /* 97 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 100 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 },
    /* 103 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 },
    /* 107 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 },
    /* 111 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 },
    /* 114 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 },
    /* 119 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_IMM_0, 0 },
    /* 123 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 },
    /* 126 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_2, 0 },
    /* 130 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_2, 0 },
    /* 133 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
    /* 137 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 141 */ { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 },
    /* 143 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_2, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_IMM_0, 0 },
    /* 147 */ { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_0, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 }, { -1, 0, MCOI::OPERAND_GENERIC_1, 0 },
    /* 151 */ { LX32::GPRNOX0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 152 */ { LX32::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { LX32::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { LX32::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 },
    /* 155 */ { LX32::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { LX32::GPRRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 },
  }
};


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverlength-strings"
#endif
extern const char LX32InstrNameData[] = {
  /* 0 */ "G_FLOG10\000"
  /* 9 */ "G_FEXP10\000"
  /* 18 */ "G_FLOG2\000"
  /* 26 */ "G_FATAN2\000"
  /* 35 */ "G_FEXP2\000"
  /* 43 */ "PseudoLA\000"
  /* 52 */ "G_FMA\000"
  /* 58 */ "G_STRICT_FMA\000"
  /* 71 */ "SRA\000"
  /* 75 */ "LB\000"
  /* 78 */ "SB\000"
  /* 81 */ "G_FSUB\000"
  /* 88 */ "G_STRICT_FSUB\000"
  /* 102 */ "G_ATOMICRMW_FSUB\000"
  /* 119 */ "G_SUB\000"
  /* 125 */ "G_ATOMICRMW_SUB\000"
  /* 141 */ "G_INTRINSIC\000"
  /* 153 */ "G_FPTRUNC\000"
  /* 163 */ "G_INTRINSIC_TRUNC\000"
  /* 181 */ "G_TRUNC\000"
  /* 189 */ "G_BUILD_VECTOR_TRUNC\000"
  /* 210 */ "G_DYN_STACKALLOC\000"
  /* 227 */ "AUIPC\000"
  /* 233 */ "G_FMAD\000"
  /* 240 */ "G_INDEXED_SEXTLOAD\000"
  /* 259 */ "G_SEXTLOAD\000"
  /* 270 */ "G_INDEXED_ZEXTLOAD\000"
  /* 289 */ "G_ZEXTLOAD\000"
  /* 300 */ "G_INDEXED_LOAD\000"
  /* 315 */ "G_LOAD\000"
  /* 322 */ "G_VECREDUCE_FADD\000"
  /* 339 */ "G_FADD\000"
  /* 346 */ "G_VECREDUCE_SEQ_FADD\000"
  /* 367 */ "G_STRICT_FADD\000"
  /* 381 */ "G_ATOMICRMW_FADD\000"
  /* 398 */ "G_VECREDUCE_ADD\000"
  /* 414 */ "G_ADD\000"
  /* 420 */ "G_PTR_ADD\000"
  /* 430 */ "G_ATOMICRMW_ADD\000"
  /* 446 */ "G_ATOMICRMW_NAND\000"
  /* 463 */ "G_VECREDUCE_AND\000"
  /* 479 */ "G_AND\000"
  /* 485 */ "G_ATOMICRMW_AND\000"
  /* 501 */ "LIFETIME_END\000"
  /* 514 */ "G_BRCOND\000"
  /* 523 */ "G_ATOMICRMW_USUB_COND\000"
  /* 545 */ "G_LLROUND\000"
  /* 555 */ "G_LROUND\000"
  /* 564 */ "G_INTRINSIC_ROUND\000"
  /* 582 */ "G_INTRINSIC_FPTRUNC_ROUND\000"
  /* 608 */ "LX32_LOAD_STACK_GUARD\000"
  /* 630 */ "PSEUDO_PROBE\000"
  /* 643 */ "G_SSUBE\000"
  /* 651 */ "G_USUBE\000"
  /* 659 */ "G_FENCE\000"
  /* 667 */ "ARITH_FENCE\000"
  /* 679 */ "REG_SEQUENCE\000"
  /* 692 */ "G_SADDE\000"
  /* 700 */ "G_UADDE\000"
  /* 708 */ "G_GET_FPMODE\000"
  /* 721 */ "G_RESET_FPMODE\000"
  /* 736 */ "G_SET_FPMODE\000"
  /* 749 */ "G_FMINNUM_IEEE\000"
  /* 764 */ "G_FMAXNUM_IEEE\000"
  /* 779 */ "BGE\000"
  /* 783 */ "G_VSCALE\000"
  /* 792 */ "G_JUMP_TABLE\000"
  /* 805 */ "BUNDLE\000"
  /* 812 */ "BNE\000"
  /* 816 */ "G_MEMCPY_INLINE\000"
  /* 832 */ "RELOC_NONE\000"
  /* 843 */ "LOCAL_ESCAPE\000"
  /* 856 */ "G_STACKRESTORE\000"
  /* 871 */ "G_INDEXED_STORE\000"
  /* 887 */ "G_STORE\000"
  /* 895 */ "G_BITREVERSE\000"
  /* 908 */ "FAKE_USE\000"
  /* 917 */ "DBG_VALUE\000"
  /* 927 */ "G_GLOBAL_VALUE\000"
  /* 942 */ "G_PTRAUTH_GLOBAL_VALUE\000"
  /* 965 */ "CONVERGENCECTRL_GLUE\000"
  /* 986 */ "G_STACKSAVE\000"
  /* 998 */ "G_MEMMOVE\000"
  /* 1008 */ "G_FREEZE\000"
  /* 1017 */ "G_FCANONICALIZE\000"
  /* 1033 */ "G_FMODF\000"
  /* 1041 */ "G_CTLZ_ZERO_UNDEF\000"
  /* 1059 */ "G_CTTZ_ZERO_UNDEF\000"
  /* 1077 */ "INIT_UNDEF\000"
  /* 1088 */ "G_IMPLICIT_DEF\000"
  /* 1103 */ "DBG_INSTR_REF\000"
  /* 1117 */ "G_FNEG\000"
  /* 1124 */ "EXTRACT_SUBREG\000"
  /* 1139 */ "INSERT_SUBREG\000"
  /* 1153 */ "G_SEXT_INREG\000"
  /* 1166 */ "SUBREG_TO_REG\000"
  /* 1180 */ "G_ATOMIC_CMPXCHG\000"
  /* 1197 */ "G_ATOMICRMW_XCHG\000"
  /* 1214 */ "G_GET_ROUNDING\000"
  /* 1229 */ "G_SET_ROUNDING\000"
  /* 1244 */ "G_FLOG\000"
  /* 1251 */ "G_VAARG\000"
  /* 1259 */ "LX32_PREALLOCATED_ARG\000"
  /* 1281 */ "G_PREFETCH\000"
  /* 1292 */ "G_SMULH\000"
  /* 1300 */ "G_UMULH\000"
  /* 1308 */ "G_FTANH\000"
  /* 1316 */ "G_FSINH\000"
  /* 1324 */ "G_FCOSH\000"
  /* 1332 */ "SRAI\000"
  /* 1337 */ "ADDI\000"
  /* 1342 */ "ANDI\000"
  /* 1347 */ "DBG_PHI\000"
  /* 1355 */ "SLLI\000"
  /* 1360 */ "SRLI\000"
  /* 1365 */ "XORI\000"
  /* 1370 */ "G_FPTOSI\000"
  /* 1379 */ "SLTI\000"
  /* 1384 */ "LUI\000"
  /* 1388 */ "G_FPTOUI\000"
  /* 1397 */ "G_FPOWI\000"
  /* 1405 */ "COPY_LANEMASK\000"
  /* 1419 */ "G_PTRMASK\000"
  /* 1429 */ "JAL\000"
  /* 1433 */ "GC_LABEL\000"
  /* 1442 */ "DBG_LABEL\000"
  /* 1452 */ "EH_LABEL\000"
  /* 1461 */ "ANNOTATION_LABEL\000"
  /* 1478 */ "ICALL_BRANCH_FUNNEL\000"
  /* 1498 */ "G_FSHL\000"
  /* 1505 */ "G_SHL\000"
  /* 1511 */ "G_FCEIL\000"
  /* 1519 */ "G_SAVGCEIL\000"
  /* 1530 */ "G_UAVGCEIL\000"
  /* 1541 */ "PATCHABLE_TAIL_CALL\000"
  /* 1561 */ "PATCHABLE_TYPED_EVENT_CALL\000"
  /* 1588 */ "PATCHABLE_EVENT_CALL\000"
  /* 1609 */ "FENTRY_CALL\000"
  /* 1621 */ "PseudoCALL\000"
  /* 1632 */ "KILL\000"
  /* 1637 */ "SLL\000"
  /* 1641 */ "G_CONSTANT_POOL\000"
  /* 1657 */ "SRL\000"
  /* 1661 */ "G_ROTL\000"
  /* 1668 */ "G_VECREDUCE_FMUL\000"
  /* 1685 */ "G_FMUL\000"
  /* 1692 */ "G_VECREDUCE_SEQ_FMUL\000"
  /* 1713 */ "G_STRICT_FMUL\000"
  /* 1727 */ "G_VECREDUCE_MUL\000"
  /* 1743 */ "G_MUL\000"
  /* 1749 */ "G_FREM\000"
  /* 1756 */ "G_STRICT_FREM\000"
  /* 1770 */ "G_SREM\000"
  /* 1777 */ "G_UREM\000"
  /* 1784 */ "G_SDIVREM\000"
  /* 1794 */ "G_UDIVREM\000"
  /* 1804 */ "INLINEASM\000"
  /* 1814 */ "G_VECREDUCE_FMINIMUM\000"
  /* 1835 */ "G_FMINIMUM\000"
  /* 1846 */ "G_ATOMICRMW_FMINIMUM\000"
  /* 1867 */ "G_VECREDUCE_FMAXIMUM\000"
  /* 1888 */ "G_FMAXIMUM\000"
  /* 1899 */ "G_ATOMICRMW_FMAXIMUM\000"
  /* 1920 */ "G_FMINIMUMNUM\000"
  /* 1934 */ "G_FMAXIMUMNUM\000"
  /* 1948 */ "G_FMINNUM\000"
  /* 1958 */ "G_FMAXNUM\000"
  /* 1968 */ "G_FATAN\000"
  /* 1976 */ "G_FTAN\000"
  /* 1983 */ "G_INTRINSIC_ROUNDEVEN\000"
  /* 2005 */ "G_ASSERT_ALIGN\000"
  /* 2020 */ "G_FCOPYSIGN\000"
  /* 2032 */ "G_VECREDUCE_FMIN\000"
  /* 2049 */ "G_ATOMICRMW_FMIN\000"
  /* 2066 */ "G_VECREDUCE_SMIN\000"
  /* 2083 */ "G_SMIN\000"
  /* 2090 */ "G_VECREDUCE_UMIN\000"
  /* 2107 */ "G_UMIN\000"
  /* 2114 */ "G_ATOMICRMW_UMIN\000"
  /* 2131 */ "G_ATOMICRMW_MIN\000"
  /* 2147 */ "G_FASIN\000"
  /* 2155 */ "G_FSIN\000"
  /* 2162 */ "CFI_INSTRUCTION\000"
  /* 2178 */ "ADJCALLSTACKDOWN\000"
  /* 2195 */ "G_SSUBO\000"
  /* 2203 */ "G_USUBO\000"
  /* 2211 */ "G_SADDO\000"
  /* 2219 */ "G_UADDO\000"
  /* 2227 */ "JUMP_TABLE_DEBUG_INFO\000"
  /* 2249 */ "G_SMULO\000"
  /* 2257 */ "G_UMULO\000"
  /* 2265 */ "G_BZERO\000"
  /* 2273 */ "STACKMAP\000"
  /* 2282 */ "G_DEBUGTRAP\000"
  /* 2294 */ "G_UBSANTRAP\000"
  /* 2306 */ "G_TRAP\000"
  /* 2313 */ "G_ATOMICRMW_UDEC_WRAP\000"
  /* 2335 */ "G_ATOMICRMW_UINC_WRAP\000"
  /* 2357 */ "G_BSWAP\000"
  /* 2365 */ "G_SITOFP\000"
  /* 2374 */ "G_UITOFP\000"
  /* 2383 */ "G_FCMP\000"
  /* 2390 */ "G_ICMP\000"
  /* 2397 */ "G_SCMP\000"
  /* 2404 */ "G_UCMP\000"
  /* 2411 */ "PseudoNOP\000"
  /* 2421 */ "CONVERGENCECTRL_LOOP\000"
  /* 2442 */ "G_CTPOP\000"
  /* 2450 */ "PATCHABLE_OP\000"
  /* 2463 */ "FAULTING_OP\000"
  /* 2475 */ "ADJCALLSTACKUP\000"
  /* 2490 */ "PREALLOCATED_SETUP\000"
  /* 2509 */ "G_FLDEXP\000"
  /* 2518 */ "G_STRICT_FLDEXP\000"
  /* 2534 */ "G_FEXP\000"
  /* 2541 */ "G_FFREXP\000"
  /* 2550 */ "BEQ\000"
  /* 2554 */ "G_BR\000"
  /* 2559 */ "INLINEASM_BR\000"
  /* 2572 */ "G_BLOCK_ADDR\000"
  /* 2585 */ "MEMBARRIER\000"
  /* 2596 */ "G_CONSTANT_FOLD_BARRIER\000"
  /* 2620 */ "PATCHABLE_FUNCTION_ENTER\000"
  /* 2645 */ "G_READCYCLECOUNTER\000"
  /* 2664 */ "G_READSTEADYCOUNTER\000"
  /* 2684 */ "G_READ_REGISTER\000"
  /* 2700 */ "G_WRITE_REGISTER\000"
  /* 2717 */ "G_ASHR\000"
  /* 2724 */ "G_FSHR\000"
  /* 2731 */ "G_LSHR\000"
  /* 2738 */ "JALR\000"
  /* 2743 */ "CONVERGENCECTRL_ANCHOR\000"
  /* 2766 */ "G_FFLOOR\000"
  /* 2775 */ "G_SAVGFLOOR\000"
  /* 2787 */ "G_UAVGFLOOR\000"
  /* 2799 */ "G_EXTRACT_SUBVECTOR\000"
  /* 2819 */ "G_INSERT_SUBVECTOR\000"
  /* 2838 */ "G_BUILD_VECTOR\000"
  /* 2853 */ "G_SHUFFLE_VECTOR\000"
  /* 2870 */ "G_STEP_VECTOR\000"
  /* 2884 */ "G_SPLAT_VECTOR\000"
  /* 2899 */ "G_VECREDUCE_XOR\000"
  /* 2915 */ "G_XOR\000"
  /* 2921 */ "G_ATOMICRMW_XOR\000"
  /* 2937 */ "G_VECREDUCE_OR\000"
  /* 2952 */ "G_OR\000"
  /* 2957 */ "G_ATOMICRMW_OR\000"
  /* 2972 */ "G_ROTR\000"
  /* 2979 */ "G_INTTOPTR\000"
  /* 2990 */ "G_FABS\000"
  /* 2997 */ "G_ABS\000"
  /* 3003 */ "G_ABDS\000"
  /* 3010 */ "G_UNMERGE_VALUES\000"
  /* 3027 */ "G_MERGE_VALUES\000"
  /* 3042 */ "G_CTLS\000"
  /* 3049 */ "G_FACOS\000"
  /* 3057 */ "G_FCOS\000"
  /* 3064 */ "G_FSINCOS\000"
  /* 3074 */ "G_CONCAT_VECTORS\000"
  /* 3091 */ "COPY_TO_REGCLASS\000"
  /* 3108 */ "G_IS_FPCLASS\000"
  /* 3121 */ "G_ATOMIC_CMPXCHG_WITH_SUCCESS\000"
  /* 3151 */ "G_VECTOR_COMPRESS\000"
  /* 3169 */ "G_INTRINSIC_W_SIDE_EFFECTS\000"
  /* 3196 */ "G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS\000"
  /* 3234 */ "G_TRUNC_SSAT_S\000"
  /* 3249 */ "G_SSUBSAT\000"
  /* 3259 */ "G_USUBSAT\000"
  /* 3269 */ "G_SADDSAT\000"
  /* 3279 */ "G_UADDSAT\000"
  /* 3289 */ "G_SSHLSAT\000"
  /* 3299 */ "G_USHLSAT\000"
  /* 3309 */ "G_SMULFIXSAT\000"
  /* 3322 */ "G_UMULFIXSAT\000"
  /* 3335 */ "G_SDIVFIXSAT\000"
  /* 3348 */ "G_UDIVFIXSAT\000"
  /* 3361 */ "G_ATOMICRMW_USUB_SAT\000"
  /* 3382 */ "G_FPTOSI_SAT\000"
  /* 3395 */ "G_FPTOUI_SAT\000"
  /* 3408 */ "G_EXTRACT\000"
  /* 3418 */ "G_SELECT\000"
  /* 3427 */ "G_BRINDIRECT\000"
  /* 3440 */ "PATCHABLE_RET\000"
  /* 3454 */ "PseudoRET\000"
  /* 3464 */ "G_MEMSET\000"
  /* 3473 */ "PATCHABLE_FUNCTION_EXIT\000"
  /* 3497 */ "G_BRJT\000"
  /* 3504 */ "BLT\000"
  /* 3508 */ "G_EXTRACT_VECTOR_ELT\000"
  /* 3529 */ "G_INSERT_VECTOR_ELT\000"
  /* 3549 */ "SLT\000"
  /* 3553 */ "G_FCONSTANT\000"
  /* 3565 */ "G_CONSTANT\000"
  /* 3576 */ "G_INTRINSIC_CONVERGENT\000"
  /* 3599 */ "STATEPOINT\000"
  /* 3610 */ "PATCHPOINT\000"
  /* 3621 */ "G_PTRTOINT\000"
  /* 3632 */ "G_FRINT\000"
  /* 3640 */ "G_INTRINSIC_LLRINT\000"
  /* 3659 */ "G_INTRINSIC_LRINT\000"
  /* 3677 */ "G_FNEARBYINT\000"
  /* 3690 */ "G_VASTART\000"
  /* 3700 */ "LIFETIME_START\000"
  /* 3715 */ "G_INVOKE_REGION_START\000"
  /* 3737 */ "G_INSERT\000"
  /* 3746 */ "G_FSQRT\000"
  /* 3754 */ "G_STRICT_FSQRT\000"
  /* 3769 */ "G_BITCAST\000"
  /* 3779 */ "G_ADDRSPACE_CAST\000"
  /* 3796 */ "DBG_VALUE_LIST\000"
  /* 3811 */ "G_FPEXT\000"
  /* 3819 */ "G_SEXT\000"
  /* 3826 */ "G_ASSERT_SEXT\000"
  /* 3840 */ "G_ANYEXT\000"
  /* 3849 */ "G_ZEXT\000"
  /* 3856 */ "G_ASSERT_ZEXT\000"
  /* 3870 */ "LBU\000"
  /* 3874 */ "G_ABDU\000"
  /* 3881 */ "BGEU\000"
  /* 3886 */ "LHU\000"
  /* 3890 */ "SLTIU\000"
  /* 3896 */ "BLTU\000"
  /* 3901 */ "SLTU\000"
  /* 3906 */ "G_TRUNC_SSAT_U\000"
  /* 3921 */ "G_TRUNC_USAT_U\000"
  /* 3936 */ "G_FDIV\000"
  /* 3943 */ "G_STRICT_FDIV\000"
  /* 3957 */ "G_SDIV\000"
  /* 3964 */ "G_UDIV\000"
  /* 3971 */ "G_GET_FPENV\000"
  /* 3983 */ "G_RESET_FPENV\000"
  /* 3997 */ "G_SET_FPENV\000"
  /* 4009 */ "LW\000"
  /* 4012 */ "G_FPOW\000"
  /* 4019 */ "SW\000"
  /* 4022 */ "G_VECREDUCE_FMAX\000"
  /* 4039 */ "G_ATOMICRMW_FMAX\000"
  /* 4056 */ "G_VECREDUCE_SMAX\000"
  /* 4073 */ "G_SMAX\000"
  /* 4080 */ "G_VECREDUCE_UMAX\000"
  /* 4097 */ "G_UMAX\000"
  /* 4104 */ "G_ATOMICRMW_UMAX\000"
  /* 4121 */ "G_ATOMICRMW_MAX\000"
  /* 4137 */ "G_FRAME_INDEX\000"
  /* 4151 */ "G_SBFX\000"
  /* 4158 */ "G_UBFX\000"
  /* 4165 */ "G_SMULFIX\000"
  /* 4175 */ "G_UMULFIX\000"
  /* 4185 */ "G_SDIVFIX\000"
  /* 4195 */ "G_UDIVFIX\000"
  /* 4205 */ "G_MEMCPY\000"
  /* 4214 */ "COPY\000"
  /* 4219 */ "CONVERGENCECTRL_ENTRY\000"
  /* 4241 */ "G_CTLZ\000"
  /* 4248 */ "G_CTTZ\000"
};
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif

extern const unsigned LX32InstrNameIndices[] = {
    1351U, 1804U, 2559U, 2162U, 1452U, 1433U, 1461U, 1632U, 
    1124U, 1139U, 1090U, 1077U, 1166U, 3091U, 917U, 3796U, 
    1103U, 1347U, 1442U, 679U, 4214U, 1405U, 805U, 3700U, 
    501U, 630U, 667U, 2273U, 1609U, 3610U, 613U, 2490U, 
    1264U, 3599U, 843U, 2463U, 2450U, 2620U, 3440U, 3473U, 
    1541U, 1588U, 1561U, 1478U, 908U, 2585U, 2227U, 832U, 
    4219U, 2743U, 2421U, 965U, 3826U, 3856U, 2005U, 414U, 
    119U, 1743U, 3957U, 3964U, 1770U, 1777U, 1784U, 1794U, 
    479U, 2952U, 2915U, 3003U, 3874U, 2787U, 1530U, 2775U, 
    1519U, 1088U, 1349U, 4137U, 927U, 942U, 1641U, 3408U, 
    3010U, 3737U, 3027U, 2838U, 189U, 3074U, 3621U, 2979U, 
    3769U, 1008U, 2596U, 582U, 163U, 564U, 3659U, 3640U, 
    1983U, 2645U, 2664U, 315U, 259U, 289U, 300U, 240U, 
    270U, 887U, 871U, 3121U, 1180U, 1197U, 430U, 125U, 
    485U, 446U, 2957U, 2921U, 4121U, 2131U, 4104U, 2114U, 
    381U, 102U, 4039U, 2049U, 1899U, 1846U, 2335U, 2313U, 
    523U, 3361U, 659U, 1281U, 514U, 3427U, 3715U, 141U, 
    3169U, 3576U, 3196U, 3840U, 181U, 3234U, 3906U, 3921U, 
    3565U, 3553U, 3690U, 1251U, 3819U, 1153U, 3849U, 1505U, 
    2731U, 2717U, 1498U, 2724U, 2972U, 1661U, 2390U, 2383U, 
    2397U, 2404U, 3418U, 2219U, 700U, 2203U, 651U, 2211U, 
    692U, 2195U, 643U, 2257U, 2249U, 1300U, 1292U, 3279U, 
    3269U, 3259U, 3249U, 3299U, 3289U, 4165U, 4175U, 3309U, 
    3322U, 4185U, 4195U, 3335U, 3348U, 339U, 81U, 1685U, 
    52U, 233U, 3936U, 1749U, 1033U, 4012U, 1397U, 2534U, 
    35U, 9U, 1244U, 18U, 0U, 2509U, 2541U, 1117U, 
    3811U, 153U, 1370U, 1388U, 2365U, 2374U, 3382U, 3395U, 
    2990U, 2020U, 3108U, 1017U, 1948U, 1958U, 749U, 764U, 
    1835U, 1888U, 1920U, 1934U, 3971U, 3997U, 3983U, 708U, 
    736U, 721U, 1214U, 1229U, 420U, 1419U, 2083U, 4073U, 
    2107U, 4097U, 2997U, 555U, 545U, 2554U, 3497U, 783U, 
    2819U, 2799U, 3529U, 3508U, 2853U, 2884U, 2870U, 3151U, 
    4248U, 1059U, 4241U, 1041U, 3042U, 2442U, 2357U, 895U, 
    1511U, 3057U, 2155U, 3064U, 1976U, 3049U, 2147U, 1968U, 
    26U, 1324U, 1316U, 1308U, 3746U, 2766U, 3632U, 3677U, 
    3779U, 2572U, 792U, 210U, 986U, 856U, 367U, 88U, 
    1713U, 3943U, 1756U, 58U, 3754U, 2518U, 2684U, 2700U, 
    4205U, 816U, 998U, 3464U, 2265U, 2306U, 2282U, 2294U, 
    346U, 1692U, 322U, 1668U, 4022U, 2032U, 1867U, 1814U, 
    398U, 1727U, 463U, 2937U, 2899U, 4056U, 2066U, 4080U, 
    2090U, 4151U, 4158U, 2178U, 2475U, 608U, 1259U, 1621U, 
    43U, 2411U, 3454U, 335U, 1337U, 459U, 1342U, 227U, 
    2550U, 779U, 3881U, 3504U, 3896U, 812U, 1429U, 2738U, 
    75U, 3870U, 1297U, 3886U, 1384U, 4009U, 2763U, 1366U, 
    78U, 1329U, 1637U, 1355U, 3549U, 1379U, 3890U, 3901U, 
    71U, 1332U, 1657U, 1360U, 84U, 4019U, 2911U, 1365U, 
};

static inline void InitLX32MCInstrInfo(MCInstrInfo *II) {
  II->InitMCInstrInfo(LX32Descs.Insts, LX32InstrNameIndices, LX32InstrNameData, nullptr, nullptr, 368, nullptr, 0);
}


} // namespace llvm

#endif // GET_INSTRINFO_MC_DESC

#ifdef GET_INSTRINFO_HEADER
#undef GET_INSTRINFO_HEADER

namespace llvm {

struct LX32GenInstrInfo : public TargetInstrInfo {
  explicit LX32GenInstrInfo(const TargetSubtargetInfo &STI, const TargetRegisterInfo &TRI, unsigned CFSetupOpcode = ~0u, unsigned CFDestroyOpcode = ~0u, unsigned CatchRetOpcode = ~0u, unsigned ReturnOpcode = ~0u);
  ~LX32GenInstrInfo() override = default;
};

} // namespace llvm

namespace llvm::LX32 {


} // namespace llvm::LX32

#endif // GET_INSTRINFO_HEADER

#ifdef GET_INSTRINFO_HELPER_DECLS
#undef GET_INSTRINFO_HELPER_DECLS


#endif // GET_INSTRINFO_HELPER_DECLS

#ifdef GET_INSTRINFO_HELPERS
#undef GET_INSTRINFO_HELPERS


#endif // GET_INSTRINFO_HELPERS

#ifdef GET_INSTRINFO_CTOR_DTOR
#undef GET_INSTRINFO_CTOR_DTOR

namespace llvm {

extern const LX32InstrTable LX32Descs;
extern const unsigned LX32InstrNameIndices[];
extern const char LX32InstrNameData[];
LX32GenInstrInfo::LX32GenInstrInfo(const TargetSubtargetInfo &STI, const TargetRegisterInfo &TRI, unsigned CFSetupOpcode, unsigned CFDestroyOpcode, unsigned CatchRetOpcode, unsigned ReturnOpcode)
  : TargetInstrInfo(TRI, CFSetupOpcode, CFDestroyOpcode, CatchRetOpcode, ReturnOpcode) {
  InitMCInstrInfo(LX32Descs.Insts, LX32InstrNameIndices, LX32InstrNameData, nullptr, nullptr, 368);
}

} // namespace llvm

#endif // GET_INSTRINFO_CTOR_DTOR

#ifdef GET_INSTRINFO_MC_HELPER_DECLS
#undef GET_INSTRINFO_MC_HELPER_DECLS

namespace llvm {

class MCInst;
class FeatureBitset;

namespace LX32_MC {

void verifyInstructionPredicates(unsigned Opcode, const FeatureBitset &Features);

} // namespace LX32_MC

} // namespace llvm

#endif // GET_INSTRINFO_MC_HELPER_DECLS

#ifdef GET_INSTRINFO_MC_HELPERS
#undef GET_INSTRINFO_MC_HELPERS

namespace llvm::LX32_MC {


} // namespace llvm::LX32_MC

#endif // GET_INSTRINFO_MC_HELPERS

#if (defined(ENABLE_INSTR_PREDICATE_VERIFIER) && !defined(NDEBUG)) ||\
    defined(GET_AVAILABLE_OPCODE_CHECKER)
#define GET_COMPUTE_FEATURES
#endif
#ifdef GET_COMPUTE_FEATURES
#undef GET_COMPUTE_FEATURES

namespace llvm::LX32_MC {

// Bits for subtarget features that participate in instruction matching.
enum SubtargetFeatureBits : uint8_t {
};

inline FeatureBitset computeAvailableFeatures(const FeatureBitset &FB) {
  FeatureBitset Features;
  return Features;
}

inline FeatureBitset computeRequiredFeatures(unsigned Opcode) {
  enum : uint8_t {
    CEFBS_None,
  };

  static constexpr FeatureBitset FeatureBitsets[] = {
    {}, // CEFBS_None
  };
  static constexpr uint8_t RequiredFeaturesRefs[] = {
    CEFBS_None, // PHI
    CEFBS_None, // INLINEASM
    CEFBS_None, // INLINEASM_BR
    CEFBS_None, // CFI_INSTRUCTION
    CEFBS_None, // EH_LABEL
    CEFBS_None, // GC_LABEL
    CEFBS_None, // ANNOTATION_LABEL
    CEFBS_None, // KILL
    CEFBS_None, // EXTRACT_SUBREG
    CEFBS_None, // INSERT_SUBREG
    CEFBS_None, // IMPLICIT_DEF
    CEFBS_None, // INIT_UNDEF
    CEFBS_None, // SUBREG_TO_REG
    CEFBS_None, // COPY_TO_REGCLASS
    CEFBS_None, // DBG_VALUE
    CEFBS_None, // DBG_VALUE_LIST
    CEFBS_None, // DBG_INSTR_REF
    CEFBS_None, // DBG_PHI
    CEFBS_None, // DBG_LABEL
    CEFBS_None, // REG_SEQUENCE
    CEFBS_None, // COPY
    CEFBS_None, // COPY_LANEMASK
    CEFBS_None, // BUNDLE
    CEFBS_None, // LIFETIME_START
    CEFBS_None, // LIFETIME_END
    CEFBS_None, // PSEUDO_PROBE
    CEFBS_None, // ARITH_FENCE
    CEFBS_None, // STACKMAP
    CEFBS_None, // FENTRY_CALL
    CEFBS_None, // PATCHPOINT
    CEFBS_None, // LOAD_STACK_GUARD
    CEFBS_None, // PREALLOCATED_SETUP
    CEFBS_None, // PREALLOCATED_ARG
    CEFBS_None, // STATEPOINT
    CEFBS_None, // LOCAL_ESCAPE
    CEFBS_None, // FAULTING_OP
    CEFBS_None, // PATCHABLE_OP
    CEFBS_None, // PATCHABLE_FUNCTION_ENTER
    CEFBS_None, // PATCHABLE_RET
    CEFBS_None, // PATCHABLE_FUNCTION_EXIT
    CEFBS_None, // PATCHABLE_TAIL_CALL
    CEFBS_None, // PATCHABLE_EVENT_CALL
    CEFBS_None, // PATCHABLE_TYPED_EVENT_CALL
    CEFBS_None, // ICALL_BRANCH_FUNNEL
    CEFBS_None, // FAKE_USE
    CEFBS_None, // MEMBARRIER
    CEFBS_None, // JUMP_TABLE_DEBUG_INFO
    CEFBS_None, // RELOC_NONE
    CEFBS_None, // CONVERGENCECTRL_ENTRY
    CEFBS_None, // CONVERGENCECTRL_ANCHOR
    CEFBS_None, // CONVERGENCECTRL_LOOP
    CEFBS_None, // CONVERGENCECTRL_GLUE
    CEFBS_None, // G_ASSERT_SEXT
    CEFBS_None, // G_ASSERT_ZEXT
    CEFBS_None, // G_ASSERT_ALIGN
    CEFBS_None, // G_ADD
    CEFBS_None, // G_SUB
    CEFBS_None, // G_MUL
    CEFBS_None, // G_SDIV
    CEFBS_None, // G_UDIV
    CEFBS_None, // G_SREM
    CEFBS_None, // G_UREM
    CEFBS_None, // G_SDIVREM
    CEFBS_None, // G_UDIVREM
    CEFBS_None, // G_AND
    CEFBS_None, // G_OR
    CEFBS_None, // G_XOR
    CEFBS_None, // G_ABDS
    CEFBS_None, // G_ABDU
    CEFBS_None, // G_UAVGFLOOR
    CEFBS_None, // G_UAVGCEIL
    CEFBS_None, // G_SAVGFLOOR
    CEFBS_None, // G_SAVGCEIL
    CEFBS_None, // G_IMPLICIT_DEF
    CEFBS_None, // G_PHI
    CEFBS_None, // G_FRAME_INDEX
    CEFBS_None, // G_GLOBAL_VALUE
    CEFBS_None, // G_PTRAUTH_GLOBAL_VALUE
    CEFBS_None, // G_CONSTANT_POOL
    CEFBS_None, // G_EXTRACT
    CEFBS_None, // G_UNMERGE_VALUES
    CEFBS_None, // G_INSERT
    CEFBS_None, // G_MERGE_VALUES
    CEFBS_None, // G_BUILD_VECTOR
    CEFBS_None, // G_BUILD_VECTOR_TRUNC
    CEFBS_None, // G_CONCAT_VECTORS
    CEFBS_None, // G_PTRTOINT
    CEFBS_None, // G_INTTOPTR
    CEFBS_None, // G_BITCAST
    CEFBS_None, // G_FREEZE
    CEFBS_None, // G_CONSTANT_FOLD_BARRIER
    CEFBS_None, // G_INTRINSIC_FPTRUNC_ROUND
    CEFBS_None, // G_INTRINSIC_TRUNC
    CEFBS_None, // G_INTRINSIC_ROUND
    CEFBS_None, // G_INTRINSIC_LRINT
    CEFBS_None, // G_INTRINSIC_LLRINT
    CEFBS_None, // G_INTRINSIC_ROUNDEVEN
    CEFBS_None, // G_READCYCLECOUNTER
    CEFBS_None, // G_READSTEADYCOUNTER
    CEFBS_None, // G_LOAD
    CEFBS_None, // G_SEXTLOAD
    CEFBS_None, // G_ZEXTLOAD
    CEFBS_None, // G_INDEXED_LOAD
    CEFBS_None, // G_INDEXED_SEXTLOAD
    CEFBS_None, // G_INDEXED_ZEXTLOAD
    CEFBS_None, // G_STORE
    CEFBS_None, // G_INDEXED_STORE
    CEFBS_None, // G_ATOMIC_CMPXCHG_WITH_SUCCESS
    CEFBS_None, // G_ATOMIC_CMPXCHG
    CEFBS_None, // G_ATOMICRMW_XCHG
    CEFBS_None, // G_ATOMICRMW_ADD
    CEFBS_None, // G_ATOMICRMW_SUB
    CEFBS_None, // G_ATOMICRMW_AND
    CEFBS_None, // G_ATOMICRMW_NAND
    CEFBS_None, // G_ATOMICRMW_OR
    CEFBS_None, // G_ATOMICRMW_XOR
    CEFBS_None, // G_ATOMICRMW_MAX
    CEFBS_None, // G_ATOMICRMW_MIN
    CEFBS_None, // G_ATOMICRMW_UMAX
    CEFBS_None, // G_ATOMICRMW_UMIN
    CEFBS_None, // G_ATOMICRMW_FADD
    CEFBS_None, // G_ATOMICRMW_FSUB
    CEFBS_None, // G_ATOMICRMW_FMAX
    CEFBS_None, // G_ATOMICRMW_FMIN
    CEFBS_None, // G_ATOMICRMW_FMAXIMUM
    CEFBS_None, // G_ATOMICRMW_FMINIMUM
    CEFBS_None, // G_ATOMICRMW_UINC_WRAP
    CEFBS_None, // G_ATOMICRMW_UDEC_WRAP
    CEFBS_None, // G_ATOMICRMW_USUB_COND
    CEFBS_None, // G_ATOMICRMW_USUB_SAT
    CEFBS_None, // G_FENCE
    CEFBS_None, // G_PREFETCH
    CEFBS_None, // G_BRCOND
    CEFBS_None, // G_BRINDIRECT
    CEFBS_None, // G_INVOKE_REGION_START
    CEFBS_None, // G_INTRINSIC
    CEFBS_None, // G_INTRINSIC_W_SIDE_EFFECTS
    CEFBS_None, // G_INTRINSIC_CONVERGENT
    CEFBS_None, // G_INTRINSIC_CONVERGENT_W_SIDE_EFFECTS
    CEFBS_None, // G_ANYEXT
    CEFBS_None, // G_TRUNC
    CEFBS_None, // G_TRUNC_SSAT_S
    CEFBS_None, // G_TRUNC_SSAT_U
    CEFBS_None, // G_TRUNC_USAT_U
    CEFBS_None, // G_CONSTANT
    CEFBS_None, // G_FCONSTANT
    CEFBS_None, // G_VASTART
    CEFBS_None, // G_VAARG
    CEFBS_None, // G_SEXT
    CEFBS_None, // G_SEXT_INREG
    CEFBS_None, // G_ZEXT
    CEFBS_None, // G_SHL
    CEFBS_None, // G_LSHR
    CEFBS_None, // G_ASHR
    CEFBS_None, // G_FSHL
    CEFBS_None, // G_FSHR
    CEFBS_None, // G_ROTR
    CEFBS_None, // G_ROTL
    CEFBS_None, // G_ICMP
    CEFBS_None, // G_FCMP
    CEFBS_None, // G_SCMP
    CEFBS_None, // G_UCMP
    CEFBS_None, // G_SELECT
    CEFBS_None, // G_UADDO
    CEFBS_None, // G_UADDE
    CEFBS_None, // G_USUBO
    CEFBS_None, // G_USUBE
    CEFBS_None, // G_SADDO
    CEFBS_None, // G_SADDE
    CEFBS_None, // G_SSUBO
    CEFBS_None, // G_SSUBE
    CEFBS_None, // G_UMULO
    CEFBS_None, // G_SMULO
    CEFBS_None, // G_UMULH
    CEFBS_None, // G_SMULH
    CEFBS_None, // G_UADDSAT
    CEFBS_None, // G_SADDSAT
    CEFBS_None, // G_USUBSAT
    CEFBS_None, // G_SSUBSAT
    CEFBS_None, // G_USHLSAT
    CEFBS_None, // G_SSHLSAT
    CEFBS_None, // G_SMULFIX
    CEFBS_None, // G_UMULFIX
    CEFBS_None, // G_SMULFIXSAT
    CEFBS_None, // G_UMULFIXSAT
    CEFBS_None, // G_SDIVFIX
    CEFBS_None, // G_UDIVFIX
    CEFBS_None, // G_SDIVFIXSAT
    CEFBS_None, // G_UDIVFIXSAT
    CEFBS_None, // G_FADD
    CEFBS_None, // G_FSUB
    CEFBS_None, // G_FMUL
    CEFBS_None, // G_FMA
    CEFBS_None, // G_FMAD
    CEFBS_None, // G_FDIV
    CEFBS_None, // G_FREM
    CEFBS_None, // G_FMODF
    CEFBS_None, // G_FPOW
    CEFBS_None, // G_FPOWI
    CEFBS_None, // G_FEXP
    CEFBS_None, // G_FEXP2
    CEFBS_None, // G_FEXP10
    CEFBS_None, // G_FLOG
    CEFBS_None, // G_FLOG2
    CEFBS_None, // G_FLOG10
    CEFBS_None, // G_FLDEXP
    CEFBS_None, // G_FFREXP
    CEFBS_None, // G_FNEG
    CEFBS_None, // G_FPEXT
    CEFBS_None, // G_FPTRUNC
    CEFBS_None, // G_FPTOSI
    CEFBS_None, // G_FPTOUI
    CEFBS_None, // G_SITOFP
    CEFBS_None, // G_UITOFP
    CEFBS_None, // G_FPTOSI_SAT
    CEFBS_None, // G_FPTOUI_SAT
    CEFBS_None, // G_FABS
    CEFBS_None, // G_FCOPYSIGN
    CEFBS_None, // G_IS_FPCLASS
    CEFBS_None, // G_FCANONICALIZE
    CEFBS_None, // G_FMINNUM
    CEFBS_None, // G_FMAXNUM
    CEFBS_None, // G_FMINNUM_IEEE
    CEFBS_None, // G_FMAXNUM_IEEE
    CEFBS_None, // G_FMINIMUM
    CEFBS_None, // G_FMAXIMUM
    CEFBS_None, // G_FMINIMUMNUM
    CEFBS_None, // G_FMAXIMUMNUM
    CEFBS_None, // G_GET_FPENV
    CEFBS_None, // G_SET_FPENV
    CEFBS_None, // G_RESET_FPENV
    CEFBS_None, // G_GET_FPMODE
    CEFBS_None, // G_SET_FPMODE
    CEFBS_None, // G_RESET_FPMODE
    CEFBS_None, // G_GET_ROUNDING
    CEFBS_None, // G_SET_ROUNDING
    CEFBS_None, // G_PTR_ADD
    CEFBS_None, // G_PTRMASK
    CEFBS_None, // G_SMIN
    CEFBS_None, // G_SMAX
    CEFBS_None, // G_UMIN
    CEFBS_None, // G_UMAX
    CEFBS_None, // G_ABS
    CEFBS_None, // G_LROUND
    CEFBS_None, // G_LLROUND
    CEFBS_None, // G_BR
    CEFBS_None, // G_BRJT
    CEFBS_None, // G_VSCALE
    CEFBS_None, // G_INSERT_SUBVECTOR
    CEFBS_None, // G_EXTRACT_SUBVECTOR
    CEFBS_None, // G_INSERT_VECTOR_ELT
    CEFBS_None, // G_EXTRACT_VECTOR_ELT
    CEFBS_None, // G_SHUFFLE_VECTOR
    CEFBS_None, // G_SPLAT_VECTOR
    CEFBS_None, // G_STEP_VECTOR
    CEFBS_None, // G_VECTOR_COMPRESS
    CEFBS_None, // G_CTTZ
    CEFBS_None, // G_CTTZ_ZERO_UNDEF
    CEFBS_None, // G_CTLZ
    CEFBS_None, // G_CTLZ_ZERO_UNDEF
    CEFBS_None, // G_CTLS
    CEFBS_None, // G_CTPOP
    CEFBS_None, // G_BSWAP
    CEFBS_None, // G_BITREVERSE
    CEFBS_None, // G_FCEIL
    CEFBS_None, // G_FCOS
    CEFBS_None, // G_FSIN
    CEFBS_None, // G_FSINCOS
    CEFBS_None, // G_FTAN
    CEFBS_None, // G_FACOS
    CEFBS_None, // G_FASIN
    CEFBS_None, // G_FATAN
    CEFBS_None, // G_FATAN2
    CEFBS_None, // G_FCOSH
    CEFBS_None, // G_FSINH
    CEFBS_None, // G_FTANH
    CEFBS_None, // G_FSQRT
    CEFBS_None, // G_FFLOOR
    CEFBS_None, // G_FRINT
    CEFBS_None, // G_FNEARBYINT
    CEFBS_None, // G_ADDRSPACE_CAST
    CEFBS_None, // G_BLOCK_ADDR
    CEFBS_None, // G_JUMP_TABLE
    CEFBS_None, // G_DYN_STACKALLOC
    CEFBS_None, // G_STACKSAVE
    CEFBS_None, // G_STACKRESTORE
    CEFBS_None, // G_STRICT_FADD
    CEFBS_None, // G_STRICT_FSUB
    CEFBS_None, // G_STRICT_FMUL
    CEFBS_None, // G_STRICT_FDIV
    CEFBS_None, // G_STRICT_FREM
    CEFBS_None, // G_STRICT_FMA
    CEFBS_None, // G_STRICT_FSQRT
    CEFBS_None, // G_STRICT_FLDEXP
    CEFBS_None, // G_READ_REGISTER
    CEFBS_None, // G_WRITE_REGISTER
    CEFBS_None, // G_MEMCPY
    CEFBS_None, // G_MEMCPY_INLINE
    CEFBS_None, // G_MEMMOVE
    CEFBS_None, // G_MEMSET
    CEFBS_None, // G_BZERO
    CEFBS_None, // G_TRAP
    CEFBS_None, // G_DEBUGTRAP
    CEFBS_None, // G_UBSANTRAP
    CEFBS_None, // G_VECREDUCE_SEQ_FADD
    CEFBS_None, // G_VECREDUCE_SEQ_FMUL
    CEFBS_None, // G_VECREDUCE_FADD
    CEFBS_None, // G_VECREDUCE_FMUL
    CEFBS_None, // G_VECREDUCE_FMAX
    CEFBS_None, // G_VECREDUCE_FMIN
    CEFBS_None, // G_VECREDUCE_FMAXIMUM
    CEFBS_None, // G_VECREDUCE_FMINIMUM
    CEFBS_None, // G_VECREDUCE_ADD
    CEFBS_None, // G_VECREDUCE_MUL
    CEFBS_None, // G_VECREDUCE_AND
    CEFBS_None, // G_VECREDUCE_OR
    CEFBS_None, // G_VECREDUCE_XOR
    CEFBS_None, // G_VECREDUCE_SMAX
    CEFBS_None, // G_VECREDUCE_SMIN
    CEFBS_None, // G_VECREDUCE_UMAX
    CEFBS_None, // G_VECREDUCE_UMIN
    CEFBS_None, // G_SBFX
    CEFBS_None, // G_UBFX
    CEFBS_None, // ADJCALLSTACKDOWN
    CEFBS_None, // ADJCALLSTACKUP
    CEFBS_None, // LX32_LOAD_STACK_GUARD
    CEFBS_None, // LX32_PREALLOCATED_ARG
    CEFBS_None, // PseudoCALL
    CEFBS_None, // PseudoLA
    CEFBS_None, // PseudoNOP
    CEFBS_None, // PseudoRET
    CEFBS_None, // ADD
    CEFBS_None, // ADDI
    CEFBS_None, // AND
    CEFBS_None, // ANDI
    CEFBS_None, // AUIPC
    CEFBS_None, // BEQ
    CEFBS_None, // BGE
    CEFBS_None, // BGEU
    CEFBS_None, // BLT
    CEFBS_None, // BLTU
    CEFBS_None, // BNE
    CEFBS_None, // JAL
    CEFBS_None, // JALR
    CEFBS_None, // LB
    CEFBS_None, // LBU
    CEFBS_None, // LH
    CEFBS_None, // LHU
    CEFBS_None, // LUI
    CEFBS_None, // LW
    CEFBS_None, // OR
    CEFBS_None, // ORI
    CEFBS_None, // SB
    CEFBS_None, // SH
    CEFBS_None, // SLL
    CEFBS_None, // SLLI
    CEFBS_None, // SLT
    CEFBS_None, // SLTI
    CEFBS_None, // SLTIU
    CEFBS_None, // SLTU
    CEFBS_None, // SRA
    CEFBS_None, // SRAI
    CEFBS_None, // SRL
    CEFBS_None, // SRLI
    CEFBS_None, // SUB
    CEFBS_None, // SW
    CEFBS_None, // XOR
    CEFBS_None, // XORI
  };

  assert(Opcode < 368);
  return FeatureBitsets[RequiredFeaturesRefs[Opcode]];
}


} // namespace llvm::LX32_MC

#endif // GET_COMPUTE_FEATURES

#ifdef GET_AVAILABLE_OPCODE_CHECKER
#undef GET_AVAILABLE_OPCODE_CHECKER

namespace llvm::LX32_MC {

bool isOpcodeAvailable(unsigned Opcode, const FeatureBitset &Features) {
  FeatureBitset AvailableFeatures = computeAvailableFeatures(Features);
  FeatureBitset RequiredFeatures = computeRequiredFeatures(Opcode);
  FeatureBitset MissingFeatures =
      (AvailableFeatures & RequiredFeatures) ^
      RequiredFeatures;
  return !MissingFeatures.any();
}

} // namespace llvm::LX32_MC

#endif // GET_AVAILABLE_OPCODE_CHECKER

#ifdef ENABLE_INSTR_PREDICATE_VERIFIER
#undef ENABLE_INSTR_PREDICATE_VERIFIER

#include <sstream>

namespace llvm::LX32_MC {

#ifndef NDEBUG
static const char *SubtargetFeatureNames[] = {
  nullptr
};

#endif // NDEBUG

void verifyInstructionPredicates(
    unsigned Opcode, const FeatureBitset &Features) {
#ifndef NDEBUG
  FeatureBitset AvailableFeatures = computeAvailableFeatures(Features);
  FeatureBitset RequiredFeatures = computeRequiredFeatures(Opcode);
  FeatureBitset MissingFeatures =
      (AvailableFeatures & RequiredFeatures) ^
      RequiredFeatures;
  if (MissingFeatures.any()) {
    std::ostringstream Msg;
    Msg << "Attempting to emit " << &LX32InstrNameData[LX32InstrNameIndices[Opcode]]
        << " instruction but the ";
    for (unsigned i = 0, e = MissingFeatures.size(); i != e; ++i)
      if (MissingFeatures.test(i))
        Msg << SubtargetFeatureNames[i] << " ";
    Msg << "predicate(s) are not met";
    report_fatal_error(Msg.str().c_str());
  }
#endif // NDEBUG
}

} // namespace llvm::LX32_MC

#endif // ENABLE_INSTR_PREDICATE_VERIFIER

