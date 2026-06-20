__int64 __fastcall ucfg_dp_qos_latency_stats_request(
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
  __int64 v19; // x9
  __int64 (*v20)(void); // x9
  __int64 v22; // x20

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
    if ( comp_private_obj )
    {
      v18 = *(_QWORD *)(**(_QWORD **)(comp_private_obj + 32) + 240LL);
      if ( v18 && *(_QWORD *)v18 )
      {
        v19 = *(_QWORD *)(*(_QWORD *)v18 + 8LL);
        if ( v19 )
        {
          v20 = *(__int64 (**)(void))(v19 + 280);
          if ( v20 )
          {
            if ( *((_DWORD *)v20 - 1) != 1056876082 )
              __break(0x8229u);
            return v20();
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x89u,
          2u,
          "%s: Invalid Instance:",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "cdp_qos_latency_stats_request");
      }
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a2, a3, a4, a5, a6, a7, a8, a9, "dp_get_vdev_priv_obj");
  }
  v22 = jiffies;
  if ( ucfg_dp_qos_latency_stats_request___last_ticks - jiffies + 125 < 0 )
  {
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
      "ucfg_dp_qos_latency_stats_request");
    ucfg_dp_qos_latency_stats_request___last_ticks = v22;
  }
  return 4;
}
