__int64 __fastcall wlan_hdd_start_sap(
        __int64 *a1,
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
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned __int64 v60; // x9

  v9 = *a1;
  if ( *(_DWORD *)(*a1 + 40) != 1 )
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
  if ( (a1[552] & 2) != 0 )
    goto LABEL_8;
  if ( (unsigned int)wlan_hdd_cfg80211_update_apies(a1, v12, v13, v14, v15, v16, v17, v18, v19) )
  {
    v28 = "%s: SAP Not able to set AP IEs";
LABEL_5:
    qdf_trace_msg(0x33u, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, "wlan_hdd_start_sap");
LABEL_8:
    wlansap_reset_sap_config_add_ie(a1 + 35, 6);
    mutex_unlock(v10 + 24);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: SAP restart after SSR failed! Reload WLAN and try SAP again",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "wlan_hdd_start_sap");
    result = _qdf_mem_free(a1[270]);
    a1[270] = 0;
    return result;
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
  qdf_event_reset((__int64)(a1 + 11));
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64 (__fastcall *)(__int64, int *, double, double, double, double, double, double, double, double), __int64 *))wlansap_start_bss)(
                       a1[34],
                       hdd_hostapd_sap_event_cb,
                       a1 + 35) )
    goto LABEL_8;
  wlan_hdd_set_sap_beacon_protection(v10, (__int64)a1, a1[270], v30, v31, v32, v33, v34, v35, v36, v37);
  qdf_trace_msg(0x33u, 8u, "%s: Waiting for SAP to start", v46, v47, v48, v49, v50, v51, v52, v53, "wlan_hdd_start_sap");
  if ( (unsigned int)qdf_wait_single_event((__int64)(a1 + 11), 0x32C8u) )
  {
    v28 = "%s: SAP Start failed";
    goto LABEL_5;
  }
  qdf_trace_msg(0x33u, 4u, "%s: SAP Start Success", v20, v21, v22, v23, v24, v25, v26, v27, "wlan_hdd_start_sap");
  wlansap_reset_sap_config_add_ie(a1 + 35, 6);
  _X8 = (unsigned __int64 *)(a1 + 552);
  __asm { PRFM            #0x11, [X8] }
  do
    v60 = __ldxr(_X8);
  while ( __stxr(v60 | 2, _X8) );
  if ( *((_DWORD *)a1 + 20) == 1 )
  {
    policy_mgr_incr_active_session(*v10, *(_DWORD *)(v9 + 40), *((unsigned __int8 *)a1 + 8), 1);
    hdd_green_ap_start_state_mc(v10, *(unsigned int *)(v9 + 40), 1);
  }
  return mutex_unlock(v10 + 24);
}
