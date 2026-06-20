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
  _QWORD *v30; // x23
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  char v39; // w8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  const char *v48; // x2
  const char *v49; // x2
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned __int64 v65; // x10
  unsigned __int64 v68; // x9

  v1 = *(_QWORD *)a1;
  v3 = *(_QWORD *)(a1 + 272);
  v4 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  mutex_lock(v4 + 24);
  if ( (*(_QWORD *)(a1 + 5968) & 2) == 0 )
    return mutex_unlock(v4 + 24);
  wlan_hdd_del_station(v1, 0);
  qdf_event_reset(a1 + 128);
  if ( !(unsigned int)wlansap_stop_bss(v3) && (unsigned int)qdf_wait_single_event(a1 + 128, 0x4650u) )
  {
    v29 = "%s: SAP Stop Failed";
    goto LABEL_8;
  }
  _X8 = (unsigned __int64 *)(a1 + 5968);
  __asm { PRFM            #0x11, [X8] }
  do
    v65 = __ldxr(_X8);
  while ( __stxr(v65 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  policy_mgr_decr_session_set_pcl(*v4, *(_DWORD *)(v1 + 40), *(unsigned __int8 *)(a1 + 8));
  started = hdd_green_ap_start_state_mc(v4, *(unsigned int *)(v1 + 40), 0);
  qdf_trace_msg(0x33u, 2u, "%s: SAP Stop Success", started, v6, v7, v8, v9, v10, v11, v12, "hdd_restart_sap");
  if ( (unsigned int)wlan_hdd_cfg80211_update_apies((__int64 *)a1, v13, v14, v15, v16, v17, v18, v19, v20) )
  {
    v29 = "%s: SAP Not able to set AP IEs";
LABEL_8:
    qdf_trace_msg(0x33u, 2u, v29, v21, v22, v23, v24, v25, v26, v27, v28, "hdd_restart_sap");
LABEL_20:
    wlansap_reset_sap_config_add_ie(a1 + 280, 6);
    return mutex_unlock(v4 + 24);
  }
  v30 = *(_QWORD **)(*(_QWORD *)a1 + 24LL);
  if ( *(_BYTE *)(a1 + 2149) == 1 )
  {
    if ( (mlo_ap_vdev_attach(*(_QWORD *)(a1 + 32), *(unsigned __int8 *)(a1 + 2150), *(unsigned __int8 *)(a1 + 2151)) & 1) == 0 )
    {
      v49 = "%s: SAP mlo mgr attach fail";
      goto LABEL_18;
    }
    v39 = *(_BYTE *)(a1 + 2149);
  }
  else
  {
    v39 = 0;
  }
  if ( (((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))policy_mgr_is_mlo_sap_concurrency_allowed)(
          *v30,
          v39 & 1,
          *(unsigned __int8 *)(*(_QWORD *)(a1 + 32) + 168LL))
      & 1) == 0 )
  {
    v49 = "%s: MLO SAP concurrency check fails";
LABEL_18:
    qdf_trace_msg(0x33u, 2u, v49, v31, v32, v33, v34, v35, v36, v37, v38, "wlan_hdd_mlo_sap_reinit");
    v48 = "%s: SAP Not able to do mlo attach";
    goto LABEL_19;
  }
  qdf_event_reset(a1 + 88);
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64 (__fastcall *)(__int64, int *, double, double, double, double, double, double, double, double), __int64))wlansap_start_bss)(
                       v3,
                       hdd_hostapd_sap_event_cb,
                       a1 + 280) )
  {
    v48 = "%s: SAP Start Bss fail";
LABEL_19:
    qdf_trace_msg(0x33u, 2u, v48, v40, v41, v42, v43, v44, v45, v46, v47, "hdd_restart_sap");
    wlan_hdd_mlo_reset(a1);
    goto LABEL_20;
  }
  qdf_trace_msg(0x33u, 4u, "%s: Waiting for SAP to start", v40, v41, v42, v43, v44, v45, v46, v47, "hdd_restart_sap");
  if ( (unsigned int)qdf_wait_single_event(a1 + 88, 0x32C8u) )
  {
    v48 = "%s: SAP Start failed";
    goto LABEL_19;
  }
  wlansap_reset_sap_config_add_ie(a1 + 280, 6);
  qdf_trace_msg(0x33u, 2u, "%s: SAP Start Success", v51, v52, v53, v54, v55, v56, v57, v58, "hdd_restart_sap");
  _X8 = (unsigned __int64 *)(a1 + 5968);
  __asm { PRFM            #0x11, [X8] }
  do
    v68 = __ldxr(_X8);
  while ( __stxr(v68 | 2, _X8) );
  if ( *(_DWORD *)(a1 + 80) == 1 )
  {
    ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))policy_mgr_incr_active_session)(
      *v4,
      *(unsigned int *)(v1 + 40),
      *(unsigned __int8 *)(a1 + 8),
      1);
    hdd_green_ap_start_state_mc(v4, *(unsigned int *)(v1 + 40), 1);
  }
  return mutex_unlock(v4 + 24);
}
