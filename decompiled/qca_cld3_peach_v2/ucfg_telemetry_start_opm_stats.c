__int64 __fastcall ucfg_telemetry_start_opm_stats(
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
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  __int64 v22; // x20

  if ( !a1 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_vdev_priv_obj");
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
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "ucfg_telemetry_start_opm_stats");
    return 4;
  }
  v20 = *(_QWORD *)(comp_private_obj + 32);
  if ( v20 )
    return dp_telemetry_start_opm_stats(v20, a2);
  if ( ucfg_telemetry_start_opm_stats___last_ticks - jiffies + 125 < 0 )
  {
    v22 = jiffies;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: DP interface not found",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "ucfg_telemetry_start_opm_stats");
    ucfg_telemetry_start_opm_stats___last_ticks = v22;
  }
  return 4;
}
