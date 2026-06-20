__int64 __fastcall send_green_ap_ll_ps_cmd_tlv(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  _DWORD *v13; // x8
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Green AP low latency PS: bcn interval: %u state: %u cookie: %u",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "send_green_ap_ll_ps_cmd_tlv",
    *((unsigned __int16 *)a2 + 1),
    *a2,
    *((unsigned int *)a2 + 1));
  v12 = wmi_buf_alloc_fl(a1, 0x14u, "send_green_ap_ll_ps_cmd_tlv", 0xA05u);
  if ( !v12 )
    return 2;
  v13 = *(_DWORD **)(v12 + 224);
  v14 = v12;
  *v13 = 73007120;
  v13[1] = *((unsigned __int16 *)a2 + 1);
  v13[2] = *a2;
  v13[3] = *((_DWORD *)a2 + 1);
  qdf_mtrace(49, 100, 0xEA1u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0x14u,
             0x1D021u,
             "send_green_ap_ll_ps_cmd_tlv",
             0xA15u,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Green AP Low latency PS cmd Failed",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "send_green_ap_ll_ps_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
