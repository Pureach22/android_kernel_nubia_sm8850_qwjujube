__int64 __fastcall ucfg_dp_fim_display_stats(
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
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  __int64 v19; // x19

  if ( a1 )
  {
    result = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
    if ( result )
    {
      result = *(_QWORD *)(result + 32);
      if ( result )
        return dp_fim_display_stats();
      v19 = jiffies;
      if ( ucfg_dp_fim_display_stats___last_ticks_4 - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
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
                   "ucfg_dp_fim_display_stats");
        ucfg_dp_fim_display_stats___last_ticks_4 = v19;
      }
      return result;
    }
  }
  else
  {
    result = qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a2, a3, a4, a5, a6, a7, a8, a9, "dp_get_vdev_priv_obj");
  }
  v18 = jiffies;
  if ( ucfg_dp_fim_display_stats___last_ticks - jiffies + 125 < 0 )
  {
    result = qdf_trace_msg(
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
               "ucfg_dp_fim_display_stats");
    ucfg_dp_fim_display_stats___last_ticks = v18;
  }
  return result;
}
