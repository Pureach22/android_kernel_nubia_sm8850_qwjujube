__int64 __fastcall wlan_cfg80211_mc_infra_cp_stats_dealloc(
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
  __int64 v10; // x0
  __int64 result; // x0

  if ( !a1 )
    return qdf_trace_msg(
             0x48u,
             2u,
             "%s: infar_cp_stats is NULL",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "wlan_cfg80211_mc_infra_cp_stats_dealloc");
  _qdf_mem_free(*(_QWORD *)(a1 + 16));
  v10 = *(_QWORD *)(a1 + 24);
  *(_QWORD *)(a1 + 16) = 0;
  result = _qdf_mem_free(v10);
  *(_QWORD *)(a1 + 24) = 0;
  return result;
}
