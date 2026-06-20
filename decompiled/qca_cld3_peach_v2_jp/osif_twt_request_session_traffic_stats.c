__int64 __fastcall osif_twt_request_session_traffic_stats(
        __int64 a1,
        int a2,
        const void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 infra_cp_stats; // x0
  __int64 v13; // x20
  unsigned int stats_response; // w19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 )
  {
    v24 = 0;
    infra_cp_stats = wlan_cfg80211_mc_twt_get_infra_cp_stats(a1, a2, a3, (int *)&v24, a4, a5, a6, a7, a8, a9, a10, a11);
    if ( infra_cp_stats )
    {
      v13 = infra_cp_stats;
      stats_response = osif_twt_get_stats_response(
                         a1,
                         *(_QWORD *)(infra_cp_stats + 16),
                         *(unsigned int *)(infra_cp_stats + 12));
      if ( stats_response )
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: TWT: Get_traffic_stats failed status: %d",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "osif_twt_request_session_traffic_stats",
          stats_response);
      _qdf_mem_free(*(_QWORD *)(v13 + 16));
      _qdf_mem_free(v13);
    }
    else
    {
      stats_response = v24;
    }
  }
  else
  {
    stats_response = 4;
  }
  _ReadStatusReg(SP_EL0);
  return stats_response;
}
