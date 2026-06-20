__int64 __fastcall print_c2c_reg_rules_info(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7

  if ( *(_BYTE *)(result + 372) == 1 )
  {
    v11 = result;
    qdf_trace_msg(
      0x31u,
      8u,
      "num C2C rules [AP, DEF CLI, SUB CLI] = [%d, %d, %d]",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      *(unsigned int *)(result + 212),
      *(unsigned int *)(result + 240),
      *(unsigned int *)(result + 244),
      v9,
      v10);
    qdf_trace_msg(
      0x31u,
      8u,
      "AP C2C POWER TYPE-[MIN BW, MAX BW] : [%d, %d]",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      *(unsigned int *)(v11 + 116),
      *(unsigned int *)(v11 + 132));
    qdf_trace_msg(
      0x31u,
      8u,
      "DEF CLI C2C POWER TYPE-[MIN BW, MAX BW] : [%d, %d]",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      *(unsigned int *)(v11 + 160),
      *(unsigned int *)(v11 + 192));
    qdf_trace_msg(
      0x31u,
      8u,
      "SUB CLI C2C POWER TYPE-[MIN BW, MAX BW] : [%d, %d]",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      *(unsigned int *)(v11 + 164),
      *(unsigned int *)(v11 + 196));
    qdf_trace_msg(
      0x31u,
      8u,
      "C2C NUM REG RULES [AP, DEF CLI, SUB CLI] = [%d, %d, %d]",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      *(unsigned int *)(v11 + 212),
      *(unsigned int *)(v11 + 240),
      *(unsigned int *)(v11 + 244));
    return qdf_trace_msg(
             0x31u,
             8u,
             "C2C DOMAIN CODE [AP, DEF CLI, SUB CLI] = [%d, %d, %d]",
             v44,
             v45,
             v46,
             v47,
             v48,
             v49,
             v50,
             v51,
             *(unsigned __int8 *)(v11 + 89),
             *(unsigned __int8 *)(v11 + 96),
             *(unsigned __int8 *)(v11 + 97));
  }
  return result;
}
