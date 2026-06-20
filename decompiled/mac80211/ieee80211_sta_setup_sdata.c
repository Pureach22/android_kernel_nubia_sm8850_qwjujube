__int64 __fastcall ieee80211_sta_setup_sdata(__int64 a1)
{
  __int64 v2; // x21
  __int64 result; // x0
  char v4; // w8
  __int64 v5; // x9
  int v6; // w8

  *(_QWORD *)(a1 + 2384) = a1 + 2384;
  *(_QWORD *)(a1 + 2392) = a1 + 2384;
  v2 = a1 + 2648;
  *(_QWORD *)(a1 + 2400) = ieee80211_sta_monitor_work;
  *(_QWORD *)(a1 + 2408) = a1 + 2408;
  *(_QWORD *)(a1 + 2416) = a1 + 2408;
  *(_QWORD *)(a1 + 2424) = ieee80211_beacon_connection_loss_work;
  *(_QWORD *)(a1 + 2432) = a1 + 2432;
  *(_QWORD *)(a1 + 2440) = a1 + 2432;
  *(_QWORD *)(a1 + 2448) = ieee80211_csa_connection_drop_work_0;
  init_timer_key(a1 + 2680, &wiphy_delayed_work_timer, 0, 0, 0);
  *(_QWORD *)(a1 + 2648) = v2;
  *(_QWORD *)(a1 + 2656) = v2;
  *(_QWORD *)(a1 + 2664) = ieee80211_tdls_peer_del_work;
  init_timer_key(a1 + 2992, &wiphy_delayed_work_timer, 0, 0, 0);
  *(_QWORD *)(a1 + 2960) = a1 + 2960;
  *(_QWORD *)(a1 + 2968) = a1 + 2960;
  *(_QWORD *)(a1 + 2976) = ieee80211_ml_reconf_work;
  init_timer_key(a1 + 2264, ieee80211_sta_timer, 0, 0, 0);
  init_timer_key(a1 + 2344, ieee80211_sta_bcn_mon_timer, 0, 0, 0);
  init_timer_key(a1 + 2304, ieee80211_sta_conn_mon_timer, 0, 0, 0);
  init_timer_key(a1 + 2904, &wiphy_delayed_work_timer, 0, 0, 0);
  *(_QWORD *)(a1 + 2872) = a1 + 2872;
  *(_QWORD *)(a1 + 2880) = a1 + 2872;
  *(_QWORD *)(a1 + 2888) = ieee80211_sta_handle_tspec_ac_params_wk;
  init_timer_key(a1 + 3072, &wiphy_delayed_work_timer, 0, 0, 0);
  *(_QWORD *)(a1 + 3040) = a1 + 3040;
  *(_QWORD *)(a1 + 3048) = a1 + 3040;
  *(_QWORD *)(a1 + 3056) = ieee80211_tid_to_link_map_work;
  result = init_timer_key(a1 + 3192, &wiphy_delayed_work_timer, 0, 0, 0);
  *(_QWORD *)(a1 + 3160) = a1 + 3160;
  *(_QWORD *)(a1 + 3168) = a1 + 3160;
  *(_QWORD *)(a1 + 3176) = ieee80211_neg_ttlm_timeout_work;
  *(_QWORD *)(a1 + 3128) = a1 + 3128;
  *(_QWORD *)(a1 + 3136) = a1 + 3128;
  *(_QWORD *)(a1 + 3144) = ieee80211_teardown_ttlm_work;
  v4 = *(_BYTE *)(a1 + 181);
  v5 = *(_QWORD *)(a1 + 1616);
  *(_DWORD *)(a1 + 2500) = 0;
  *(_BYTE *)(a1 + 2496) = v4;
  *(_DWORD *)(a1 + 2516) = *(unsigned __int8 *)(v5 + 168);
  v6 = *(unsigned __int8 *)(v5 + 169);
  *(_DWORD *)(a1 + 2736) = 0;
  *(_QWORD *)(a1 + 2728) = 0;
  *(_DWORD *)(a1 + 2520) = v6;
  *(_QWORD *)(a1 + 2720) = 0;
  *(_WORD *)(a1 + 2504) = 4096;
  return result;
}
