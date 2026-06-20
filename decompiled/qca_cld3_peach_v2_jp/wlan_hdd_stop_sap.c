__int64 __fastcall wlan_hdd_stop_sap(
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
  __int64 v9; // x20
  __int64 *v10; // x19
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x2
  unsigned int v22; // w1
  const char *v23; // x2
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double started; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned __int64 v46; // x10

  v9 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
  {
    v23 = "%s: ap_adapter is NULL here";
    return qdf_trace_msg(0x33u, 2u, v23, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_stop_sap");
  }
  v10 = *(__int64 **)(v9 + 24);
  result = _wlan_hdd_validate_context((__int64)v10, (__int64)"wlan_hdd_stop_sap", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (_DWORD)result )
    return result;
  mutex_lock(v10 + 24);
  if ( (*(_QWORD *)(a1 + 4416) & 2) != 0 )
  {
    wlan_hdd_del_station(v9, 0);
    qdf_trace_msg(0x33u, 8u, "%s: Now doing SAP STOPBSS", v24, v25, v26, v27, v28, v29, v30, v31, "wlan_hdd_stop_sap");
    qdf_event_reset(a1 + 128);
    if ( (unsigned int)wlansap_stop_bss(*(_QWORD *)(a1 + 272))
      || !(unsigned int)qdf_wait_single_event(a1 + 128, 0x4650u) )
    {
      _X8 = (unsigned __int64 *)(a1 + 4416);
      __asm { PRFM            #0x11, [X8] }
      do
        v46 = __ldxr(_X8);
      while ( __stxr(v46 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
      policy_mgr_decr_session_set_pcl(*v10, *(_DWORD *)(v9 + 40), *(unsigned __int8 *)(a1 + 8));
      started = hdd_green_ap_start_state_mc(v10, *(unsigned int *)(v9 + 40), 0);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: SAP stopped due to invalid channel vdev id %d",
        started,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "hdd_inform_stop_sap",
        *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(v9 + 52824) + 32LL) + 104LL));
      v13 = cfg80211_stop_iface(*(_QWORD *)(*(_QWORD *)(v9 + 24) + 24LL), v9 + 112, 3264);
      v21 = "%s: SAP Stop Success";
      v22 = 8;
      goto LABEL_9;
    }
    mutex_unlock(v10 + 24);
    v23 = "%s: SAP Stop Failed";
    return qdf_trace_msg(0x33u, 2u, v23, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_stop_sap");
  }
  v21 = "%s: Can't stop ap because its not started";
  v22 = 2;
LABEL_9:
  qdf_trace_msg(0x33u, v22, v21, v13, v14, v15, v16, v17, v18, v19, v20, "wlan_hdd_stop_sap");
  return mutex_unlock(v10 + 24);
}
