__int64 __fastcall hdd_restart_sap(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x22
  __int64 *v4; // x19
  double started; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned __int64 v45; // x10
  unsigned __int64 v48; // x9

  v1 = *(_QWORD *)a1;
  v3 = *(_QWORD *)(a1 + 272);
  v4 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  mutex_lock(v4 + 24);
  if ( (*(_QWORD *)(a1 + 4416) & 2) != 0 )
  {
    wlan_hdd_del_station(v1, 0);
    qdf_event_reset(a1 + 128);
    if ( !(unsigned int)wlansap_stop_bss(v3) && (unsigned int)qdf_wait_single_event(a1 + 128, 0x4650u) )
    {
      v29 = "%s: SAP Stop Failed";
      goto LABEL_12;
    }
    _X8 = (unsigned __int64 *)(a1 + 4416);
    __asm { PRFM            #0x11, [X8] }
    do
      v45 = __ldxr(_X8);
    while ( __stxr(v45 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
    policy_mgr_decr_session_set_pcl(*v4, *(_DWORD *)(v1 + 40), *(unsigned __int8 *)(a1 + 8));
    started = hdd_green_ap_start_state_mc(v4, *(unsigned int *)(v1 + 40), 0);
    qdf_trace_msg(0x33u, 2u, "%s: SAP Stop Success", started, v6, v7, v8, v9, v10, v11, v12, "hdd_restart_sap");
    if ( (unsigned int)wlan_hdd_cfg80211_update_apies((__int64 *)a1, v13, v14, v15, v16, v17, v18, v19, v20) )
    {
      v29 = "%s: SAP Not able to set AP IEs";
LABEL_12:
      qdf_trace_msg(0x33u, 2u, v29, v21, v22, v23, v24, v25, v26, v27, v28, "hdd_restart_sap");
      wlansap_reset_sap_config_add_ie(a1 + 280, 6);
      return mutex_unlock(v4 + 24);
    }
    qdf_event_reset(a1 + 88);
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64 (__fastcall *)(__int64, int *, double, double, double, double, double, double, double, double), __int64))wlansap_start_bss)(
                         v3,
                         hdd_hostapd_sap_event_cb,
                         a1 + 280) )
    {
      v29 = "%s: SAP Start Bss fail";
      goto LABEL_12;
    }
    qdf_trace_msg(0x33u, 4u, "%s: Waiting for SAP to start", v21, v22, v23, v24, v25, v26, v27, v28, "hdd_restart_sap");
    if ( (unsigned int)qdf_wait_single_event(a1 + 88, 0x32C8u) )
    {
      v29 = "%s: SAP Start failed";
      goto LABEL_12;
    }
    wlansap_reset_sap_config_add_ie(a1 + 280, 6);
    qdf_trace_msg(0x33u, 2u, "%s: SAP Start Success", v31, v32, v33, v34, v35, v36, v37, v38, "hdd_restart_sap");
    _X8 = (unsigned __int64 *)(a1 + 4416);
    __asm { PRFM            #0x11, [X8] }
    do
      v48 = __ldxr(_X8);
    while ( __stxr(v48 | 2, _X8) );
    if ( *(_DWORD *)(a1 + 80) == 1 )
    {
      policy_mgr_incr_active_session(*v4, *(_DWORD *)(v1 + 40), *(unsigned __int8 *)(a1 + 8), 1);
      hdd_green_ap_start_state_mc(v4, *(unsigned int *)(v1 + 40), 1);
    }
  }
  return mutex_unlock(v4 + 24);
}
