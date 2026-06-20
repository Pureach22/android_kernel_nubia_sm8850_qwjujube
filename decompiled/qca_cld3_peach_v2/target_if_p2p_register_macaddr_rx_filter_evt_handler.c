__int64 __fastcall target_if_p2p_register_macaddr_rx_filter_evt_handler(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *wmi_unified_hdl; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w0

  wmi_unified_hdl = (_QWORD *)lmac_get_wmi_unified_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: psoc:%pK, register %d mac addr rx evt",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "target_if_p2p_register_macaddr_rx_filter_evt_handler",
    a1,
    a2 & 1);
  if ( wmi_unified_hdl )
  {
    if ( (a2 & 1) != 0 )
      v29 = wmi_unified_register_event((__int64)wmi_unified_hdl, 82, (__int64)target_p2p_mac_rx_filter_event_handler);
    else
      v29 = wmi_unified_unregister_event(wmi_unified_hdl, 0x52u, v21, v22, v23, v24, v25, v26, v27, v28);
    return 16 * (unsigned int)(v29 != 0);
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Invalid wmi handle",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "target_if_p2p_register_macaddr_rx_filter_evt_handler");
    return 4;
  }
}
