__int64 __fastcall send_set_auto_shutdown_timer_cmd_tlv(
        __int64 a1,
        unsigned int a2,
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
  __int64 v13; // x19
  _DWORD *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w20
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
    "%s: Set WMI_HOST_AUTO_SHUTDOWN_CFG_CMDID:TIMER_VAL=%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "send_set_auto_shutdown_timer_cmd_tlv",
    a2);
  v12 = wmi_buf_alloc_fl(a1, 8u, "send_set_auto_shutdown_timer_cmd_tlv", 0x7DEu);
  if ( v12 )
  {
    v13 = v12;
    v14 = *(_DWORD **)(v12 + 224);
    *v14 = 17891332;
    v14[1] = a2;
    wmi_mtrace(0x1D00Bu, 0xFFu, 0);
    v23 = wmi_unified_cmd_send_fl(
            a1,
            v13,
            8u,
            0x1D00Bu,
            "send_set_auto_shutdown_timer_cmd_tlv",
            0x7EFu,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22);
    if ( v23 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: WMI_HOST_AUTO_SHUTDOWN_CFG_CMDID Err %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "send_set_auto_shutdown_timer_cmd_tlv",
        v23);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v23;
}
