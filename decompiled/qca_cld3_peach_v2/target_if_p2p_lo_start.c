__int64 __fastcall target_if_p2p_lo_start(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 wmi_unified_hdl; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  const char *v31; // x2

  wmi_unified_hdl = lmac_get_wmi_unified_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( wmi_unified_hdl )
  {
    if ( a2 )
    {
      v21 = wmi_unified_hdl;
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
        "target_if_p2p_lo_start",
        a1,
        *a2);
      return wmi_unified_p2p_lo_start_cmd(v21, v22, v23, v24, v25, v26, v27, v28, v29);
    }
    v31 = "%s: lo start parameters is null";
  }
  else
  {
    v31 = "%s: Invalid wmi handle";
  }
  qdf_trace_msg(0x49u, 2u, v31, v13, v14, v15, v16, v17, v18, v19, v20, "target_if_p2p_lo_start");
  return 4;
}
