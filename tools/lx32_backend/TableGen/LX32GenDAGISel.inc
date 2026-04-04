/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* DAG Instruction Selector for the LX32 target                               *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

// *** NOTE: This file is #included into the middle of the target
// *** instruction selector class.  These functions are really methods.

// If GET_DAGISEL_DECL is #defined with any value, only function
// declarations will be included when this file is included.
// If GET_DAGISEL_BODY is #defined, its value should be the name of
// the instruction selector class. Function bodies will be emitted
// and each function's name will be qualified with the name of the
// class.
//
// When neither of the GET_DAGISEL* macros is defined, the functions
// are emitted inline.

#if defined(GET_DAGISEL_DECL) && defined(GET_DAGISEL_BODY)
#error GET_DAGISEL_DECL and GET_DAGISEL_BODY cannot be both defined, undef both for inline definitions
#endif

#ifdef GET_DAGISEL_BODY
#define LOCAL_DAGISEL_STRINGIZE(X) LOCAL_DAGISEL_STRINGIZE_(X)
#define LOCAL_DAGISEL_STRINGIZE_(X) #X
static_assert(sizeof(LOCAL_DAGISEL_STRINGIZE(GET_DAGISEL_BODY)) > 1,
   "GET_DAGISEL_BODY is empty: it should be defined with the class name");
#undef LOCAL_DAGISEL_STRINGIZE_
#undef LOCAL_DAGISEL_STRINGIZE
#endif

#if !defined(GET_DAGISEL_DECL) && !defined(GET_DAGISEL_BODY)
#define DAGISEL_INLINE 1
#else
#define DAGISEL_INLINE 0
#endif

#if !DAGISEL_INLINE
#define DAGISEL_CLASS_COLONCOLON GET_DAGISEL_BODY ::
#else
#define DAGISEL_CLASS_COLONCOLON
#endif

#ifdef GET_DAGISEL_DECL
void SelectCode(SDNode *N);
#endif
#if defined(GET_DAGISEL_BODY) || DAGISEL_INLINE
void DAGISEL_CLASS_COLONCOLON SelectCode(SDNode *N)
{
  // Some target values are emitted as 2 bytes, TARGET_VAL handles
  // this. Coverage indexes are emitted as 4 bytes,
  // COVERAGE_IDX_VAL handles this.
  #define TARGET_VAL(X) X & 255, unsigned(X) >> 8
  #define COVERAGE_IDX_VAL(X) X & 255, (unsigned(X) >> 8) & 255, (unsigned(X) >> 16) & 255, (unsigned(X) >> 24) & 255
  static const uint8_t MatcherTable[] = {
/*      0*/ OPC_SwitchOpcode /*13 cases */, 78, TARGET_VAL(ISD::LOAD), // ->82
/*      4*/  OPC_RecordMemRef,
/*      5*/  OPC_RecordNode, // #0 = 'ld' chained node
/*      6*/  OPC_MoveChild1,
/*      7*/  OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*     10*/  OPC_RecordChild0, // #1 = $rs1
/*     11*/  OPC_RecordChild1, // #2 = $imm12
/*     12*/  OPC_MoveChild1,
/*     13*/  OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*     16*/  OPC_CheckPredicate0, // Predicate_imm12
/*     17*/  OPC_MoveParent,
/*     18*/  OPC_MoveParent,
/*     19*/  OPC_CheckPredicate6, // Predicate_unindexedload
/*     20*/  OPC_CheckTypeI32,
/*     21*/  OPC_Scope /*5 children */, 10, // ->33
/*     23*/   OPC_CheckPredicate7, // Predicate_load
/*     24*/   OPC_EmitMergeInputChains1_0,
/*     25*/   OPC_EmitConvertToTarget2, // #3 = ConvertToTarget #2
/*     26*/   OPC_MorphNodeTo1, TARGET_VAL(LX32::LW), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 2/*#Ops*/, /*OperandList*/6, // Ops = #1 #3
              // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm12>>:$imm12))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 11
              // Dst: (LW:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*     33*/  /*Scope*/ 11, // ->45
/*     34*/   OPC_CheckPredicate4, // Predicate_sextload
/*     35*/   OPC_CheckPredicate1, // Predicate_sextloadi16
/*     36*/   OPC_EmitMergeInputChains1_0,
/*     37*/   OPC_EmitConvertToTarget2, // #3 = ConvertToTarget #2
/*     38*/   OPC_MorphNodeTo1, TARGET_VAL(LX32::LH), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 2/*#Ops*/, /*OperandList*/6, // Ops = #1 #3
              // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm12>>:$imm12))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 11
              // Dst: (LH:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*     45*/  /*Scope*/ 11, // ->57
/*     46*/   OPC_CheckPredicate5, // Predicate_zextload
/*     47*/   OPC_CheckPredicate1, // Predicate_zextloadi16
/*     48*/   OPC_EmitMergeInputChains1_0,
/*     49*/   OPC_EmitConvertToTarget2, // #3 = ConvertToTarget #2
/*     50*/   OPC_MorphNodeTo1, TARGET_VAL(LX32::LHU), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 2/*#Ops*/, /*OperandList*/6, // Ops = #1 #3
              // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm12>>:$imm12))<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>> - Complexity = 11
              // Dst: (LHU:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*     57*/  /*Scope*/ 11, // ->69
/*     58*/   OPC_CheckPredicate4, // Predicate_sextload
/*     59*/   OPC_CheckPredicate2, // Predicate_sextloadi8
/*     60*/   OPC_EmitMergeInputChains1_0,
/*     61*/   OPC_EmitConvertToTarget2, // #3 = ConvertToTarget #2
/*     62*/   OPC_MorphNodeTo1, TARGET_VAL(LX32::LB), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 2/*#Ops*/, /*OperandList*/6, // Ops = #1 #3
              // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm12>>:$imm12))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi8>> - Complexity = 11
              // Dst: (LB:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*     69*/  /*Scope*/ 11, // ->81
/*     70*/   OPC_CheckPredicate5, // Predicate_zextload
/*     71*/   OPC_CheckPredicate2, // Predicate_zextloadi8
/*     72*/   OPC_EmitMergeInputChains1_0,
/*     73*/   OPC_EmitConvertToTarget2, // #3 = ConvertToTarget #2
/*     74*/   OPC_MorphNodeTo1, TARGET_VAL(LX32::LBU), 0|OPFL_Chain|OPFL_MemRefs,
                   MVT::i32, 2/*#Ops*/, /*OperandList*/6, // Ops = #1 #3
              // Src: (ld:{ *:[i32] } (add:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm12>>:$imm12))<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 11
              // Dst: (LBU:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*     81*/  0, // End of Scope
/*     82*/ /*SwitchOpcode*/ 57, TARGET_VAL(ISD::STORE), // ->142
/*     85*/  OPC_RecordMemRef,
/*     86*/  OPC_RecordNode, // #0 = 'st' chained node
/*     87*/  OPC_RecordChild1, // #1 = $rs2
/*     88*/  OPC_CheckChild1TypeI32,
/*     89*/  OPC_MoveChild2,
/*     90*/  OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*     93*/  OPC_RecordChild0, // #2 = $rs1
/*     94*/  OPC_RecordChild1, // #3 = $imm12
/*     95*/  OPC_MoveChild1,
/*     96*/  OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*     99*/  OPC_CheckPredicate0, // Predicate_imm12
/*    100*/  OPC_MoveParent,
/*    101*/  OPC_MoveParent,
/*    102*/  OPC_CheckPredicate, 8, // Predicate_unindexedstore
/*    104*/  OPC_Scope /*2 children */, 10, // ->116
/*    106*/   OPC_CheckPredicate, 9, // Predicate_store
/*    108*/   OPC_EmitMergeInputChains1_0,
/*    109*/   OPC_EmitConvertToTarget3, // #4 = ConvertToTarget #3
/*    110*/   OPC_MorphNodeTo0, TARGET_VAL(LX32::SW), 0|OPFL_Chain|OPFL_MemRefs,
                   3/*#Ops*/, /*OperandList*/8, // Ops = #1 #2 #4
              // Src: (st GPR:{ *:[i32] }:$rs2, (add:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm12>>:$imm12))<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 11
              // Dst: (SW GPR:{ *:[i32] }:$rs2, GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*    116*/  /*Scope*/ 24, // ->141
/*    117*/   OPC_CheckPredicate, 10, // Predicate_truncstore
/*    119*/   OPC_Scope /*2 children */, 9, // ->130
/*    121*/    OPC_CheckPredicate1, // Predicate_truncstorei16
/*    122*/    OPC_EmitMergeInputChains1_0,
/*    123*/    OPC_EmitConvertToTarget3, // #4 = ConvertToTarget #3
/*    124*/    OPC_MorphNodeTo0, TARGET_VAL(LX32::SH), 0|OPFL_Chain|OPFL_MemRefs,
                    3/*#Ops*/, /*OperandList*/8, // Ops = #1 #2 #4
               // Src: (st GPR:{ *:[i32] }:$rs2, (add:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm12>>:$imm12))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 11
               // Dst: (SH GPR:{ *:[i32] }:$rs2, GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*    130*/   /*Scope*/ 9, // ->140
/*    131*/    OPC_CheckPredicate2, // Predicate_truncstorei8
/*    132*/    OPC_EmitMergeInputChains1_0,
/*    133*/    OPC_EmitConvertToTarget3, // #4 = ConvertToTarget #3
/*    134*/    OPC_MorphNodeTo0, TARGET_VAL(LX32::SB), 0|OPFL_Chain|OPFL_MemRefs,
                    3/*#Ops*/, /*OperandList*/8, // Ops = #1 #2 #4
               // Src: (st GPR:{ *:[i32] }:$rs2, (add:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm12>>:$imm12))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 11
               // Dst: (SB GPR:{ *:[i32] }:$rs2, GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*    140*/   0, // End of Scope
/*    141*/  0, // End of Scope
/*    142*/ /*SwitchOpcode*/ 25, TARGET_VAL(ISD::ADD), // ->170
/*    145*/  OPC_RecordChild0, // #0 = $rs1
/*    146*/  OPC_RecordChild1, // #1 = $imm12
/*    147*/  OPC_Scope /*2 children */, 13, // ->162
/*    149*/   OPC_MoveChild1,
/*    150*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*    153*/   OPC_CheckPredicate0, // Predicate_imm12
/*    154*/   OPC_MoveParent,
/*    155*/   OPC_EmitConvertToTarget1, // #2 = ConvertToTarget #1
/*    156*/   OPC_MorphNodeTo1None, TARGET_VAL(LX32::ADDI),
                   MVT::i32, 2/*#Ops*/, /*OperandList*/2, // Ops = #0 #2
              // Src: (add:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm12>>:$imm12) - Complexity = 7
              // Dst: (ADDI:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*    162*/  /*Scope*/ 6, // ->169
/*    163*/   OPC_MorphNodeTo1None, TARGET_VAL(LX32::ADD),
                   MVT::i32, 2/*#Ops*/, /*OperandList*/0, // Ops = #0 #1
              // Src: (add:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2) - Complexity = 3
              // Dst: (ADD:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2)
/*    169*/  0, // End of Scope
/*    170*/ /*SwitchOpcode*/ 56, TARGET_VAL(ISD::SETCC), // ->229
/*    173*/  OPC_RecordChild0, // #0 = $rs1
/*    174*/  OPC_Scope /*2 children */, 29, // ->205
/*    176*/   OPC_RecordChild1, // #1 = $imm12
/*    177*/   OPC_MoveChild1,
/*    178*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*    181*/   OPC_CheckPredicate0, // Predicate_imm12
/*    182*/   OPC_MoveParent,
/*    183*/   OPC_Scope /*2 children */, 9, // ->194
/*    185*/    OPC_CheckChild2CondCode, ISD::SETLT,
/*    187*/    OPC_EmitConvertToTarget1, // #2 = ConvertToTarget #1
/*    188*/    OPC_MorphNodeTo1None, TARGET_VAL(LX32::SLTI),
                    MVT::i32, 2/*#Ops*/, /*OperandList*/2, // Ops = #0 #2
               // Src: (setcc:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm12>>:$imm12, SETLT:{ *:[Other] }) - Complexity = 7
               // Dst: (SLTI:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*    194*/   /*Scope*/ 9, // ->204
/*    195*/    OPC_CheckChild2CondCode, ISD::SETULT,
/*    197*/    OPC_EmitConvertToTarget1, // #2 = ConvertToTarget #1
/*    198*/    OPC_MorphNodeTo1None, TARGET_VAL(LX32::SLTIU),
                    MVT::i32, 2/*#Ops*/, /*OperandList*/2, // Ops = #0 #2
               // Src: (setcc:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm12>>:$imm12, SETULT:{ *:[Other] }) - Complexity = 7
               // Dst: (SLTIU:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*    204*/   0, // End of Scope
/*    205*/  /*Scope*/ 22, // ->228
/*    206*/   OPC_CheckChild0TypeI32,
/*    207*/   OPC_RecordChild1, // #1 = $rs2
/*    208*/   OPC_Scope /*2 children */, 8, // ->218
/*    210*/    OPC_CheckChild2CondCode, ISD::SETLT,
/*    212*/    OPC_MorphNodeTo1None, TARGET_VAL(LX32::SLT),
                    MVT::i32, 2/*#Ops*/, /*OperandList*/0, // Ops = #0 #1
               // Src: (setcc:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2, SETLT:{ *:[Other] }) - Complexity = 3
               // Dst: (SLT:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2)
/*    218*/   /*Scope*/ 8, // ->227
/*    219*/    OPC_CheckChild2CondCode, ISD::SETULT,
/*    221*/    OPC_MorphNodeTo1None, TARGET_VAL(LX32::SLTU),
                    MVT::i32, 2/*#Ops*/, /*OperandList*/0, // Ops = #0 #1
               // Src: (setcc:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2, SETULT:{ *:[Other] }) - Complexity = 3
               // Dst: (SLTU:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2)
/*    227*/   0, // End of Scope
/*    228*/  0, // End of Scope
/*    229*/ /*SwitchOpcode*/ 25, TARGET_VAL(ISD::XOR), // ->257
/*    232*/  OPC_RecordChild0, // #0 = $rs1
/*    233*/  OPC_RecordChild1, // #1 = $imm12
/*    234*/  OPC_Scope /*2 children */, 13, // ->249
/*    236*/   OPC_MoveChild1,
/*    237*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*    240*/   OPC_CheckPredicate0, // Predicate_imm12
/*    241*/   OPC_MoveParent,
/*    242*/   OPC_EmitConvertToTarget1, // #2 = ConvertToTarget #1
/*    243*/   OPC_MorphNodeTo1None, TARGET_VAL(LX32::XORI),
                   MVT::i32, 2/*#Ops*/, /*OperandList*/2, // Ops = #0 #2
              // Src: (xor:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm12>>:$imm12) - Complexity = 7
              // Dst: (XORI:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*    249*/  /*Scope*/ 6, // ->256
/*    250*/   OPC_MorphNodeTo1None, TARGET_VAL(LX32::XOR),
                   MVT::i32, 2/*#Ops*/, /*OperandList*/0, // Ops = #0 #1
              // Src: (xor:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2) - Complexity = 3
              // Dst: (XOR:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2)
/*    256*/  0, // End of Scope
/*    257*/ /*SwitchOpcode*/ 25, TARGET_VAL(ISD::OR), // ->285
/*    260*/  OPC_RecordChild0, // #0 = $rs1
/*    261*/  OPC_RecordChild1, // #1 = $imm12
/*    262*/  OPC_Scope /*2 children */, 13, // ->277
/*    264*/   OPC_MoveChild1,
/*    265*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*    268*/   OPC_CheckPredicate0, // Predicate_imm12
/*    269*/   OPC_MoveParent,
/*    270*/   OPC_EmitConvertToTarget1, // #2 = ConvertToTarget #1
/*    271*/   OPC_MorphNodeTo1None, TARGET_VAL(LX32::ORI),
                   MVT::i32, 2/*#Ops*/, /*OperandList*/2, // Ops = #0 #2
              // Src: (or:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm12>>:$imm12) - Complexity = 7
              // Dst: (ORI:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*    277*/  /*Scope*/ 6, // ->284
/*    278*/   OPC_MorphNodeTo1None, TARGET_VAL(LX32::OR),
                   MVT::i32, 2/*#Ops*/, /*OperandList*/0, // Ops = #0 #1
              // Src: (or:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2) - Complexity = 3
              // Dst: (OR:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2)
/*    284*/  0, // End of Scope
/*    285*/ /*SwitchOpcode*/ 25, TARGET_VAL(ISD::AND), // ->313
/*    288*/  OPC_RecordChild0, // #0 = $rs1
/*    289*/  OPC_RecordChild1, // #1 = $imm12
/*    290*/  OPC_Scope /*2 children */, 13, // ->305
/*    292*/   OPC_MoveChild1,
/*    293*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*    296*/   OPC_CheckPredicate0, // Predicate_imm12
/*    297*/   OPC_MoveParent,
/*    298*/   OPC_EmitConvertToTarget1, // #2 = ConvertToTarget #1
/*    299*/   OPC_MorphNodeTo1None, TARGET_VAL(LX32::ANDI),
                   MVT::i32, 2/*#Ops*/, /*OperandList*/2, // Ops = #0 #2
              // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm12>>:$imm12) - Complexity = 7
              // Dst: (ANDI:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*    305*/  /*Scope*/ 6, // ->312
/*    306*/   OPC_MorphNodeTo1None, TARGET_VAL(LX32::AND),
                   MVT::i32, 2/*#Ops*/, /*OperandList*/0, // Ops = #0 #1
              // Src: (and:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2) - Complexity = 3
              // Dst: (AND:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2)
/*    312*/  0, // End of Scope
/*    313*/ /*SwitchOpcode*/ 25, TARGET_VAL(ISD::SHL), // ->341
/*    316*/  OPC_RecordChild0, // #0 = $rs1
/*    317*/  OPC_RecordChild1, // #1 = $imm12
/*    318*/  OPC_Scope /*2 children */, 13, // ->333
/*    320*/   OPC_MoveChild1,
/*    321*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*    324*/   OPC_CheckPredicate3, // Predicate_imm5
/*    325*/   OPC_MoveParent,
/*    326*/   OPC_EmitConvertToTarget1, // #2 = ConvertToTarget #1
/*    327*/   OPC_MorphNodeTo1None, TARGET_VAL(LX32::SLLI),
                   MVT::i32, 2/*#Ops*/, /*OperandList*/2, // Ops = #0 #2
              // Src: (shl:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm5>>:$imm12) - Complexity = 7
              // Dst: (SLLI:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*    333*/  /*Scope*/ 6, // ->340
/*    334*/   OPC_MorphNodeTo1None, TARGET_VAL(LX32::SLL),
                   MVT::i32, 2/*#Ops*/, /*OperandList*/0, // Ops = #0 #1
              // Src: (shl:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2) - Complexity = 3
              // Dst: (SLL:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2)
/*    340*/  0, // End of Scope
/*    341*/ /*SwitchOpcode*/ 25, TARGET_VAL(ISD::SRL), // ->369
/*    344*/  OPC_RecordChild0, // #0 = $rs1
/*    345*/  OPC_RecordChild1, // #1 = $imm12
/*    346*/  OPC_Scope /*2 children */, 13, // ->361
/*    348*/   OPC_MoveChild1,
/*    349*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*    352*/   OPC_CheckPredicate3, // Predicate_imm5
/*    353*/   OPC_MoveParent,
/*    354*/   OPC_EmitConvertToTarget1, // #2 = ConvertToTarget #1
/*    355*/   OPC_MorphNodeTo1None, TARGET_VAL(LX32::SRLI),
                   MVT::i32, 2/*#Ops*/, /*OperandList*/2, // Ops = #0 #2
              // Src: (srl:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm5>>:$imm12) - Complexity = 7
              // Dst: (SRLI:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*    361*/  /*Scope*/ 6, // ->368
/*    362*/   OPC_MorphNodeTo1None, TARGET_VAL(LX32::SRL),
                   MVT::i32, 2/*#Ops*/, /*OperandList*/0, // Ops = #0 #1
              // Src: (srl:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2) - Complexity = 3
              // Dst: (SRL:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2)
/*    368*/  0, // End of Scope
/*    369*/ /*SwitchOpcode*/ 25, TARGET_VAL(ISD::SRA), // ->397
/*    372*/  OPC_RecordChild0, // #0 = $rs1
/*    373*/  OPC_RecordChild1, // #1 = $imm12
/*    374*/  OPC_Scope /*2 children */, 13, // ->389
/*    376*/   OPC_MoveChild1,
/*    377*/   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*    380*/   OPC_CheckPredicate3, // Predicate_imm5
/*    381*/   OPC_MoveParent,
/*    382*/   OPC_EmitConvertToTarget1, // #2 = ConvertToTarget #1
/*    383*/   OPC_MorphNodeTo1None, TARGET_VAL(LX32::SRAI),
                   MVT::i32, 2/*#Ops*/, /*OperandList*/2, // Ops = #0 #2
              // Src: (sra:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] })<<P:Predicate_imm5>>:$imm12) - Complexity = 7
              // Dst: (SRAI:{ *:[i32] } GPR:{ *:[i32] }:$rs1, (imm:{ *:[i32] }):$imm12)
/*    389*/  /*Scope*/ 6, // ->396
/*    390*/   OPC_MorphNodeTo1None, TARGET_VAL(LX32::SRA),
                   MVT::i32, 2/*#Ops*/, /*OperandList*/0, // Ops = #0 #1
              // Src: (sra:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2) - Complexity = 3
              // Dst: (SRA:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2)
/*    396*/  0, // End of Scope
/*    397*/ /*SwitchOpcode*/ 35, TARGET_VAL(ISD::Constant), // ->435
/*    400*/  OPC_RecordNode, // #0 = $imm
/*    401*/  OPC_Scope /*2 children */, 10, // ->413
/*    403*/   OPC_CheckPredicate0, // Predicate_imm12
/*    404*/   OPC_EmitRegisterI32, LX32::X0, // #1
/*    406*/   OPC_EmitConvertToTarget0, // #2 = ConvertToTarget #0
/*    407*/   OPC_MorphNodeTo1None, TARGET_VAL(LX32::ADDI),
                   MVT::i32, 2/*#Ops*/, /*OperandList*/4, // Ops = #1 #2
              // Src: (imm:{ *:[i32] })<<P:Predicate_imm12>>:$imm - Complexity = 4
              // Dst: (ADDI:{ *:[i32] } X0:{ *:[i32] }, (imm:{ *:[i32] })<<P:Predicate_imm12>>:$imm)
/*    413*/  /*Scope*/ 20, // ->434
/*    414*/   OPC_EmitConvertToTarget0, // #1 = ConvertToTarget #0
/*    415*/   OPC_EmitNodeXForm, 0, 1, // #2 = HI20 #1
/*    418*/   OPC_EmitNode1None, TARGET_VAL(LX32::LUI),
                   MVT::i32, 1/*#Ops*/, /*OperandList*/3, // Ops = #2 Results = #3
/*    424*/   OPC_EmitConvertToTarget0, // #4 = ConvertToTarget #0
/*    425*/   OPC_EmitNodeXForm, 1, 4, // #5 = LO12 #4
/*    428*/   OPC_MorphNodeTo1None, TARGET_VAL(LX32::ADDI),
                   MVT::i32, 2/*#Ops*/, /*OperandList*/11, // Ops = #3 #5
              // Src: (imm:{ *:[i32] }):$imm - Complexity = 3
              // Dst: (ADDI:{ *:[i32] } (LUI:{ *:[i32] } (HI20:{ *:[i32] } (imm:{ *:[i32] }):$imm)), (LO12:{ *:[i32] } (imm:{ *:[i32] }):$imm))
/*    434*/  0, // End of Scope
/*    435*/ /*SwitchOpcode*/ 8, TARGET_VAL(ISD::SUB), // ->446
/*    438*/  OPC_RecordChild0, // #0 = $rs1
/*    439*/  OPC_RecordChild1, // #1 = $rs2
/*    440*/  OPC_MorphNodeTo1None, TARGET_VAL(LX32::SUB),
                  MVT::i32, 2/*#Ops*/, /*OperandList*/0, // Ops = #0 #1
             // Src: (sub:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2) - Complexity = 3
             // Dst: (SUB:{ *:[i32] } GPR:{ *:[i32] }:$rs1, GPR:{ *:[i32] }:$rs2)
/*    446*/ /*SwitchOpcode*/ 8, TARGET_VAL(LX32ISD::RET), // ->457
/*    449*/  OPC_RecordNode, // #0 = 'LX32ret' chained node
/*    450*/  OPC_CaptureGlueInput,
/*    451*/  OPC_EmitMergeInputChains1_0,
/*    452*/  OPC_MorphNodeTo0, TARGET_VAL(LX32::PseudoRET), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic0,
                  0/*#Ops*/, // Ops = None
             // Src: (LX32ret) - Complexity = 3
             // Dst: (PseudoRET)
/*    457*/ 0, // EndSwitchOpcode
  }; // Total Array size is 458 bytes

  // Opcode Histogram:
  // #OPC_Scope                                = 14
  // #OPC_RecordNode                           = 4
  // #OPC_RecordChild                          = 24
  // #OPC_RecordMemRef                         = 2
  // #OPC_CaptureGlueInput                     = 1
  // #OPC_MoveChild                            = 12
  // #OPC_MoveSibling                          = 0
  // #OPC_MoveParent                           = 12
  // #OPC_CheckSame                            = 0
  // #OPC_CheckChildSame                       = 0
  // #OPC_CheckPatternPredicate                = 0
  // #OPC_CheckPredicate                       = 26
  // #OPC_CheckOpcode                          = 12
  // #OPC_SwitchOpcode                         = 1
  // #OPC_CheckType                            = 1
  // #OPC_SwitchType                           = 0
  // #OPC_CheckChildType                       = 2
  // #OPC_CheckInteger                         = 0
  // #OPC_CheckChildInteger                    = 0
  // #OPC_CheckCondCode                        = 0
  // #OPC_CheckChild2CondCode                  = 4
  // #OPC_CheckValueType                       = 0
  // #OPC_CheckComplexPat                      = 0
  // #OPC_CheckAndImm                          = 0
  // #OPC_CheckOrImm                           = 0
  // #OPC_CheckImmAllOnesV                     = 0
  // #OPC_CheckImmAllZerosV                    = 0
  // #OPC_CheckFoldableChainNode               = 0
  // #OPC_EmitInteger                          = 0
  // #OPC_EmitRegister                         = 1
  // #OPC_EmitConvertToTarget                  = 20
  // #OPC_EmitMergeInputChains                 = 9
  // #OPC_EmitCopyToReg                        = 0
  // #OPC_EmitNode                             = 1
  // #OPC_EmitNodeXForm                        = 2
  // #OPC_CompleteMatch                        = 0
  // #OPC_MorphNodeTo                          = 30

  static const uint8_t OperandLists[] = {
  /* 0 */ 0, 1, 
  /* 2 */ 0, 2, 
  /* 4 */ 1, 2, 
  /* 6 */ 1, 3, 
  /* 8 */ 1, 2, 4, 
  /* 11 */ 3, 5, 
  };

  #undef COVERAGE_IDX_VAL
  #undef TARGET_VAL
  SelectCodeCommon(N, MatcherTable, sizeof(MatcherTable),
                   OperandLists);
}
#endif // GET_DAGISEL_BODY

#ifdef GET_DAGISEL_DECL
bool CheckNodePredicate(SDValue Op, unsigned PredNo) const override;
#endif
#if defined(GET_DAGISEL_BODY) || DAGISEL_INLINE
bool DAGISEL_CLASS_COLONCOLON CheckNodePredicate(SDValue Op, unsigned PredNo) const
#if DAGISEL_INLINE
  override
#endif
{
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: {
    // Predicate_imm12
    auto *N = cast<ConstantSDNode>(Op.getNode());
    (void)N;
 return isInt<12>(N->getSExtValue()); 
  }
  case 1: {
    // Predicate_sextloadi16
    // Predicate_truncstorei16
    // Predicate_zextloadi16
    SDNode *N = Op.getNode();
    (void)N;
if (cast<MemSDNode>(N)->getMemoryVT() != MVT::i16) return false;
return true;

  }
  case 2: {
    // Predicate_sextloadi8
    // Predicate_truncstorei8
    // Predicate_zextloadi8
    SDNode *N = Op.getNode();
    (void)N;
if (cast<MemSDNode>(N)->getMemoryVT() != MVT::i8) return false;
return true;

  }
  case 3: {
    // Predicate_imm5
    auto *N = cast<ConstantSDNode>(Op.getNode());
    (void)N;
 return isUInt<5>(N->getZExtValue()); 
  }
  case 4: {
    // Predicate_sextload
    SDNode *N = Op.getNode();
    (void)N;
if (cast<LoadSDNode>(N)->getExtensionType() != ISD::SEXTLOAD) return false;
return true;

  }
  case 5: {
    // Predicate_zextload
    SDNode *N = Op.getNode();
    (void)N;
if (cast<LoadSDNode>(N)->getExtensionType() != ISD::ZEXTLOAD) return false;
return true;

  }
  case 6: {
    // Predicate_unindexedload
    SDNode *N = Op.getNode();
    (void)N;
if (cast<LoadSDNode>(N)->getAddressingMode() != ISD::UNINDEXED) return false;
return true;

  }
  case 7: {
    // Predicate_load
    SDNode *N = Op.getNode();
    (void)N;
if (cast<LoadSDNode>(N)->getExtensionType() != ISD::NON_EXTLOAD) return false;
return true;

  }
  case 8: {
    // Predicate_unindexedstore
    SDNode *N = Op.getNode();
    (void)N;
if (cast<StoreSDNode>(N)->getAddressingMode() != ISD::UNINDEXED) return false;
return true;

  }
  case 9: {
    // Predicate_store
    SDNode *N = Op.getNode();
    (void)N;
 if (cast<StoreSDNode>(N)->isTruncatingStore()) return false;
return true;

  }
  case 10: {
    // Predicate_truncstore
    SDNode *N = Op.getNode();
    (void)N;
 if (!cast<StoreSDNode>(N)->isTruncatingStore()) return false;
return true;

  }
  }
}
#endif // GET_DAGISEL_BODY

#ifdef GET_DAGISEL_DECL
SDValue RunSDNodeXForm(SDValue V, unsigned XFormNo) override;
#endif
#if defined(GET_DAGISEL_BODY) || DAGISEL_INLINE
SDValue DAGISEL_CLASS_COLONCOLON RunSDNodeXForm(SDValue V, unsigned XFormNo)
#if DAGISEL_INLINE
  override
#endif
{
  switch (XFormNo) {
  default: llvm_unreachable("Invalid xform # in table?");
  case 0: {  // HI20
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  return CurDAG->getTargetConstant(
      ((uint64_t)N->getZExtValue() + 0x800) >> 12, SDLoc(N), MVT::i32);

  }
  case 1: {  // LO12
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Sign-extend the low 12 bits so that the result is a valid simm12.
  return CurDAG->getTargetConstant(
      SignExtend64<12>(N->getZExtValue() & 0xfff), SDLoc(N), MVT::i32);

  }
  }
}
#endif // GET_DAGISEL_BODY


#ifdef DAGISEL_INLINE
#undef DAGISEL_INLINE
#endif
#ifdef DAGISEL_CLASS_COLONCOLON
#undef DAGISEL_CLASS_COLONCOLON
#endif
#ifdef GET_DAGISEL_DECL
#undef GET_DAGISEL_DECL
#endif
#ifdef GET_DAGISEL_BODY
#undef GET_DAGISEL_BODY
#endif
