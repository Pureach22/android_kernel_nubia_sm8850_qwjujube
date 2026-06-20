__int64 __fastcall send_enable_specific_fw_logs_cmd_tlv(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v14; // x10
  unsigned int v15; // w22
  int v16; // w11
  int v17; // w12
  int *v18; // x13
  __int64 v19; // x15
  int v20; // w16
  int v21; // w17
  int *v22; // x8
  __int64 v23; // x9
  int v24; // t1
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  _DWORD *v34; // x23
  __int64 v35; // x20
  unsigned int v36; // w26
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned __int64 v45; // x8
  unsigned __int64 v46; // x21
  int v47; // w25
  int v48; // w5
  __int64 result; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7

  v10 = *(_QWORD *)(a1 + 328);
  if ( !v10 )
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Not received event/log list from FW, yet",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "send_enable_specific_fw_logs_cmd_tlv");
    return 2;
  }
  v11 = *(unsigned int *)(a1 + 320);
  if ( !(_DWORD)v11 )
  {
    v15 = 0;
    goto LABEL_18;
  }
  if ( (_DWORD)v11 == 1 )
  {
    v14 = 0;
    v15 = 0;
LABEL_14:
    v22 = (int *)(v10 + 4 * v14);
    v23 = v11 - v14;
    do
    {
      v24 = *v22++;
      if ( (~v24 & 0x60000) == 0 )
        ++v15;
      --v23;
    }
    while ( v23 );
    goto LABEL_18;
  }
  v14 = (unsigned int)v11 & 0xFFFFFFFE;
  v16 = 0;
  v17 = 0;
  v18 = (int *)(v10 + 4);
  v19 = v14;
  do
  {
    v20 = *(v18 - 1);
    v21 = *v18;
    v18 += 2;
    if ( (~v20 & 0x60000) == 0 )
      ++v16;
    if ( (~v21 & 0x60000) == 0 )
      ++v17;
    v19 -= 2;
  }
  while ( v19 );
  v15 = v17 + v16;
  if ( v14 != v11 )
    goto LABEL_14;
LABEL_18:
  v25 = wmi_buf_alloc_fl(a1, 4 * v15 + 12, "send_enable_specific_fw_logs_cmd_tlv", 0x2C90u);
  if ( !v25 )
    return 2;
  v34 = *(_DWORD **)(v25 + 224);
  v35 = v25;
  *v34 = 27328516;
  v34[1] = v15;
  v34[2] = (unsigned __int16)(4 * v15) | 0x100000;
  v36 = *(_DWORD *)(a2 + 4);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Length: %d Log_level: %d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "send_enable_specific_fw_logs_cmd_tlv",
    v15,
    v36 > 2);
  v45 = *(unsigned int *)(a1 + 320);
  if ( (_DWORD)v45 )
  {
    v46 = 0;
    v47 = 0;
    do
    {
      v48 = *(_DWORD *)(*(_QWORD *)(a1 + 328) + 4 * v46);
      if ( (~v48 & 0x60000) == 0 )
      {
        v34[v47 + 3] = v48 & 0x1FFFF | ((v36 > 2) << 17) | v34[v47 + 3] & 0xFFFC0000;
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: Idx:%d, val:%x",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "send_enable_specific_fw_logs_cmd_tlv",
          (unsigned int)v46);
        v45 = *(unsigned int *)(a1 + 320);
        ++v47;
      }
      ++v46;
    }
    while ( v46 < v45 );
  }
  qdf_mtrace(49, 100, 0xB09u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v35,
             4 * v15 + 12,
             0x16009u,
             "send_enable_specific_fw_logs_cmd_tlv",
             0x2CBDu,
             v50,
             v51,
             v52,
             v53,
             v54,
             v55,
             v56,
             v57);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: WMI_DIAG_EVENT_LOG_CONFIG_CMDID failed",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "send_enable_specific_fw_logs_cmd_tlv");
    wmi_buf_free();
    return 4;
  }
  return result;
}
