__int64 __fastcall send_set_sta_ps_mode_cmd_tlv(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x0
  _DWORD *v15; // x8
  __int64 v16; // x21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Set Sta Mode Ps vdevId %d val %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "send_set_sta_ps_mode_cmd_tlv",
    a2,
    a3);
  v14 = wmi_buf_alloc_fl(a1, 0xCu, "send_set_sta_ps_mode_cmd_tlv", 0x1583u);
  if ( !v14 )
    return 2;
  v15 = *(_DWORD **)(v14 + 224);
  v16 = v14;
  *v15 = 7077896;
  v15[1] = a2;
  v15[2] = a3 != 0;
  qdf_mtrace(49, 100, 0x481u, a2, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v16,
             0xCu,
             0x9001u,
             "send_set_sta_ps_mode_cmd_tlv",
             0x1594u,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Set Sta Mode Ps Failed vdevId %d val %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "send_set_sta_ps_mode_cmd_tlv",
      a2,
      a3);
    wmi_buf_free();
    return 16;
  }
  return result;
}
