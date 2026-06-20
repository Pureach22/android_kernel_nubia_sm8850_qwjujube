__int64 __fastcall target_if_p2p_lo_stop(
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
  __int64 wmi_unified_hdl; // x21
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

  wmi_unified_hdl = lmac_get_wmi_unified_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: psoc:%pK, vdev_id:%d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "target_if_p2p_lo_stop",
    a1,
    a2);
  if ( wmi_unified_hdl )
    return wmi_unified_p2p_lo_stop_cmd(wmi_unified_hdl, v21, v22, v23, v24, v25, v26, v27, v28);
  qdf_trace_msg(0x49u, 2u, "%s: Invalid wmi handle", v21, v22, v23, v24, v25, v26, v27, v28, "target_if_p2p_lo_stop");
  return 4;
}
