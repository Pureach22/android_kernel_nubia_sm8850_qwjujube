__int64 __fastcall cm_fw_roam_complete(
        __int64 *a1,
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
  __int64 v10; // x19
  unsigned int v13; // w20
  __int64 v14; // x21
  unsigned int updated; // w24
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  int v41; // w2
  unsigned int v42; // w3
  char acs_mode_for_vdev; // w0
  unsigned __int8 rso_pending_disable_req_bitmap; // w0
  unsigned __int8 v45; // w22
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7

  v10 = *(_QWORD *)(*a1 + 152);
  if ( v10 )
  {
    v13 = *(unsigned __int8 *)(*a1 + 104);
    v14 = *(_QWORD *)(v10 + 80);
    if ( wlan_reg_is_disable_for_pwrmode(
           *(_QWORD *)(*a1 + 152),
           *(_DWORD *)(a2 + 64),
           0,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10) )
    {
      wlan_cm_disconnect(*a1, 10, 65527, nullptr);
      return 16;
    }
    else
    {
      updated = policy_mgr_update_connection_info(v14, v13);
      if ( updated == 28 )
        policy_mgr_incr_active_session(v14, 0, v13, 1);
      if ( *(_BYTE *)(a2 + 306) == 1 )
        policy_mgr_hw_mode_transition_cb(
          *(_DWORD *)(a2 + 308),
          *(_DWORD *)(a2 + 312),
          *(_DWORD *)(a2 + 316),
          a2 + 320,
          *(_DWORD *)(a2 + 352),
          a2 + 356,
          v14);
      if ( *(_DWORD *)(a2 + 172) )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: Received pmk in roam sync. Length: %d",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "cm_fw_roam_complete");
        cm_check_and_set_sae_single_pmk_cap(v14, v13, (const void *)(a2 + 176), *(_DWORD *)(a2 + 172));
      }
      cm_csr_send_set_ie(*a1, v17, v18, v19, v20, v21, v22, v23, v24);
      if ( (wlan_cm_is_self_mld_roam_supported(v14, v25, v26, v27, v28, v29, v30, v31, v32) & 1) == 0 )
      {
        if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 64)) )
        {
          wlan_cm_set_disable_hi_rssi(v10, v13, 0);
        }
        else
        {
          wlan_cm_set_disable_hi_rssi(v10, v13, 1);
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: Disabling HI_RSSI, AP freq=%d rssi %d vdev id %d",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "cm_fw_roam_complete",
            *(unsigned int *)(a2 + 64),
            (unsigned int)*(char *)(a2 + 60),
            v13);
        }
      }
      policy_mgr_check_n_start_opportunistic_timer(v14);
      wlan_cm_handle_sta_sta_roaming_enablement(v14, v13);
      if ( *(_DWORD *)(a2 + 56) == 2 )
      {
        v41 = 2;
        v42 = 1;
      }
      else
      {
        v41 = 3;
        v42 = 4;
      }
      wlan_cm_roam_state_change(v10, v13, v41, v42);
      acs_mode_for_vdev = wlan_util_vdev_mgr_get_acs_mode_for_vdev(*a1);
      policy_mgr_check_concurrent_intf_and_restart_sap(v14, acs_mode_for_vdev & 1);
      rso_pending_disable_req_bitmap = mlme_get_rso_pending_disable_req_bitmap(v14, v13);
      if ( rso_pending_disable_req_bitmap )
      {
        v45 = rso_pending_disable_req_bitmap;
        mlme_clear_rso_pending_disable_req_bitmap(v14, v13);
        wlan_cm_disable_rso(v10, v13, v45, 48, v46, v47, v48, v49, v50, v51, v52, v53);
      }
      return updated;
    }
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: Failed to find pdev", a3, a4, a5, a6, a7, a8, a9, a10, "cm_fw_roam_complete");
    return 16;
  }
}
