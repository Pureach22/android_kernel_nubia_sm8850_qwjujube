__int64 __fastcall send_terminate_all_ndps_cmd_tlv(
        __int64 a1,
        int a2,
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
  int v15; // w10
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  qdf_trace_msg(0x31u, 8u, "%s: Enter", a3, a4, a5, a6, a7, a8, a9, a10, "send_terminate_all_ndps_cmd_tlv");
  v12 = wmi_buf_alloc_fl(a1, 0xCu, "send_terminate_all_ndps_cmd_tlv", 0x1A4u);
  if ( v12 )
  {
    v13 = *(_DWORD **)(v12 + 224);
    v14 = v12;
    v15 = v13[2];
    *v13 = 50266120;
    v13[1] = a2;
    v13[2] = v15 | 1;
    wmi_mtrace(0x38005u, 0xFFu, 0);
    v24 = wmi_unified_cmd_send_fl(
            a1,
            v14,
            0xCu,
            0x38005u,
            "send_terminate_all_ndps_cmd_tlv",
            0x1B1u,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23);
    if ( v24 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send NDP Terminate cmd: %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "send_terminate_all_ndps_cmd_tlv",
        v24);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v24;
}
