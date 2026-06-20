__int64 __fastcall ucfg_telemetry_stop_opm_stats(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 comp_private_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x0
  __int64 v20; // x20

  if ( !a1 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a2, a3, a4, a5, a6, a7, a8, a9, "dp_get_vdev_priv_obj");
    goto LABEL_6;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
LABEL_6:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: DP link not found",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "ucfg_telemetry_stop_opm_stats");
    return 4;
  }
  v18 = *(_QWORD *)(comp_private_obj + 32);
  if ( v18 )
    return dp_telemetry_stop_opm_stats(v18);
  if ( ucfg_telemetry_stop_opm_stats___last_ticks - jiffies + 125 < 0 )
  {
    v20 = jiffies;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: DP interface not found",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "ucfg_telemetry_stop_opm_stats");
    ucfg_telemetry_stop_opm_stats___last_ticks = v20;
  }
  return 4;
}
