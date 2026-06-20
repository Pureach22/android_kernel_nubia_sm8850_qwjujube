__int64 __fastcall ucfg_mc_cp_stats_register_lost_link_info_cb(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  __int64 v12; // x8

  if ( !a1 )
    return qdf_trace_msg(
             0x62u,
             2u,
             "%s: psoc cp stats object is null",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "ucfg_mc_cp_stats_register_lost_link_info_cb");
  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu);
  if ( !result )
    return qdf_trace_msg(
             0x62u,
             2u,
             "%s: psoc cp stats object is null",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "ucfg_mc_cp_stats_register_lost_link_info_cb");
  v12 = *(_QWORD *)(result + 24);
  if ( !v12 )
    return qdf_trace_msg(
             0x62u,
             2u,
             "%s: psoc cp stats object is null",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "ucfg_mc_cp_stats_register_lost_link_info_cb");
  *(_QWORD *)(v12 + 48) = a2;
  return result;
}
