__int64 __fastcall ucfg_mc_cp_stats_clear_channel_status(
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

  if ( !a1 )
    return qdf_trace_msg(
             0x62u,
             2u,
             "%s: pdev cp stats object is null",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "ucfg_mc_cp_stats_clear_channel_status");
  result = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Bu);
  if ( !result )
    return qdf_trace_msg(
             0x62u,
             2u,
             "%s: pdev cp stats object is null",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "ucfg_mc_cp_stats_clear_channel_status");
  *(_BYTE *)(*(_QWORD *)(result + 8) + 20LL) = 0;
  *(_BYTE *)(*(_QWORD *)(result + 8) + 12692LL) = 0;
  return result;
}
