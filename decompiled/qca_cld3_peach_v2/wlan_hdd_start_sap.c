__int64 __fastcall wlan_hdd_start_sap(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x21
  __int64 *v10; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x2
  __int64 result; // x0
  _QWORD *v30; // x22
  char v31; // w8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  const char *v56; // x2
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned __int64 v71; // x9

  v9 = *a1;
  if ( *(_DWORD *)(*a1 + 40LL) != 1 )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: SoftAp role has not been enabled",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "wlan_hdd_start_sap");
  v10 = *(__int64 **)(v9 + 24);
  mutex_lock(v10 + 24);
  if ( (a1[746] & 2) != 0 )
    goto LABEL_17;
  if ( (unsigned int)wlan_hdd_cfg80211_update_apies(a1, v12, v13, v14, v15, v16, v17, v18, v19) )
  {
    v28 = "%s: SAP Not able to set AP IEs";
LABEL_16:
    qdf_trace_msg(0x33u, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, "wlan_hdd_start_sap");
    goto LABEL_17;
  }
  wlan_reg_set_channel_params_for_pwrmode(
    v10[1],
    *((_DWORD *)a1 + 180),
    0,
    (__int64)(a1 + 91),
    0,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27);
  v30 = *(_QWORD **)(*a1 + 24LL);
  v31 = 0;
  if ( *((_BYTE *)a1 + 2149) == 1 )
  {
    if ( (mlo_ap_vdev_attach(a1[4], *((unsigned __int8 *)a1 + 2150), *((unsigned __int8 *)a1 + 2151)) & 1) == 0 )
    {
      v56 = "%s: SAP mlo mgr attach fail";
      goto LABEL_15;
    }
    v31 = *((_BYTE *)a1 + 2149);
  }
  if ( (((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))policy_mgr_is_mlo_sap_concurrency_allowed)(
          *v30,
          v31 & 1,
          *(unsigned __int8 *)(a1[4] + 168LL))
      & 1) == 0 )
  {
    v56 = "%s: MLO SAP concurrency check fails";
LABEL_15:
    qdf_trace_msg(0x33u, 2u, v56, v32, v33, v34, v35, v36, v37, v38, v39, "wlan_hdd_mlo_sap_reinit");
    v28 = "%s: SAP Not able to do mlo attach";
    goto LABEL_16;
  }
  qdf_event_reset((__int64)(a1 + 11));
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64 (__fastcall *)(__int64, int *, double, double, double, double, double, double, double, double), _QWORD *))wlansap_start_bss)(
                       a1[34],
                       hdd_hostapd_sap_event_cb,
                       a1 + 35) )
  {
LABEL_17:
    wlan_hdd_mlo_reset((__int64)a1);
    wlansap_reset_sap_config_add_ie(a1 + 35, 6);
    mutex_unlock(v10 + 24);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: SAP restart after SSR failed! Reload WLAN and try SAP again",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "wlan_hdd_start_sap");
    result = _qdf_mem_free(a1[304]);
    a1[304] = 0;
    return result;
  }
  wlan_hdd_set_sap_beacon_protection(v10, (__int64)a1, a1[304], v40, v41, v42, v43, v44, v45, v46, v47);
  qdf_trace_msg(0x33u, 8u, "%s: Waiting for SAP to start", v48, v49, v50, v51, v52, v53, v54, v55, "wlan_hdd_start_sap");
  if ( (unsigned int)qdf_wait_single_event((__int64)(a1 + 11), 0x32C8u) )
  {
    v28 = "%s: SAP Start failed";
    goto LABEL_16;
  }
  qdf_trace_msg(0x33u, 4u, "%s: SAP Start Success", v20, v21, v22, v23, v24, v25, v26, v27, "wlan_hdd_start_sap");
  wlansap_reset_sap_config_add_ie(a1 + 35, 6);
  _X8 = a1 + 746;
  __asm { PRFM            #0x11, [X8] }
  do
    v71 = __ldxr(_X8);
  while ( __stxr(v71 | 2, _X8) );
  if ( *((_DWORD *)a1 + 20) == 1 )
  {
    ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))policy_mgr_incr_active_session)(
      *v10,
      *(unsigned int *)(v9 + 40),
      *((unsigned __int8 *)a1 + 8),
      1);
    hdd_green_ap_start_state_mc(v10, *(unsigned int *)(v9 + 40), 1);
  }
  return mutex_unlock(v10 + 24);
}
