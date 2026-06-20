__int64 __fastcall if_mgr_ap_start_bss_complete(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x22
  __int64 v3; // x20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  char v23; // w9
  char acs_mode_for_vdev; // w0
  unsigned __int8 sta_vdev_id; // w21
  unsigned int channel; // w0
  _QWORD v27[2]; // [xsp+0h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 216);
  if ( !v2 || (v3 = *(_QWORD *)(v2 + 80)) == 0 )
  {
    result = 16;
    goto LABEL_32;
  }
  if ( a2 && *a2 && (*(_DWORD *)(a1 + 16) | 2) == 3 && (wlan_mlme_is_aux_emlsr_support(*(_QWORD *)(v2 + 80)) & 1) != 0 )
    ml_nlink_conn_change_notify(v3, *(unsigned __int8 *)(a1 + 168), 11, 0);
  if ( (cfg_p2p_is_roam_config_disabled(v3, a2) & 1) != 0 && *(_DWORD *)(a1 + 16) == 3 )
  {
    qdf_trace_msg(
      0x78u,
      8u,
      "%s: p2p go mode, keep roam disabled",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "if_mgr_ap_start_bss_complete");
  }
  else if ( (policy_mgr_is_set_link_in_progress(v3) & 1) != 0 )
  {
    qdf_trace_msg(
      0x78u,
      8u,
      "%s: vdev: %d link switch in progress, Dont enable roaming",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "if_mgr_ap_start_bss_complete",
      *(unsigned __int8 *)(a1 + 168));
    v23 = *(_BYTE *)(a1 + 168);
    v27[0] = 1;
    BYTE4(v27[0]) = v23;
    wlan_objmgr_pdev_iterate_obj_list(
      v2,
      2,
      (void (__fastcall *)(__int64, __int64, __int64))if_mgr_defer_rso_enable_for_set_link_on_vdev,
      (__int64)v27,
      0,
      0x4Eu);
  }
  else
  {
    qdf_trace_msg(
      0x78u,
      8u,
      "%s: Enable Roaming after start bss complete",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "if_mgr_ap_start_bss_complete");
    if_mgr_enable_roaming(v2, a1, 1);
  }
  if ( *(_DWORD *)(a1 + 16) == 3 )
  {
    policy_mgr_check_sap_go_force_scc(v3, a1, 13);
    if ( !a2 )
      goto LABEL_25;
LABEL_22:
    if ( !*a2 || (wlan_tdls_notify_start_bss_failure(v3), !*a2) )
      policy_mgr_trigger_roam_for_sta_sap_mcc_non_dbs(v3);
    goto LABEL_25;
  }
  if ( (policy_mgr_is_vdev_ll_lt_sap(v3, *(unsigned __int8 *)(a1 + 168)) & 1) == 0 )
  {
    acs_mode_for_vdev = wlan_util_vdev_mgr_get_acs_mode_for_vdev(a1);
    policy_mgr_check_concurrent_intf_and_restart_sap(v3, acs_mode_for_vdev & 1);
    if ( !a2 )
      goto LABEL_25;
    goto LABEL_22;
  }
  policy_mgr_ll_lt_sap_restart_concurrent_sap(v3, 2);
  if ( a2 )
    goto LABEL_22;
LABEL_25:
  if ( *(_DWORD *)(a1 + 16) == 3 && (wlan_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(v3) & 1) != 0 )
  {
    sta_vdev_id = wlan_p2p_psoc_priv_get_sta_vdev_id(v3);
    channel = policy_mgr_mode_specific_get_channel(v3, 3);
    wlan_p2p_set_rand_mac_for_p2p_dev(v3, sta_vdev_id, channel, 0, 0);
  }
  if ( (policy_mgr_is_dual_sap_active(v3) & 1) != 0 && (wlan_mlme_is_aux_emlsr_support(v3) & 1) != 0 )
    ml_nlink_conn_change_notify(v3, *(unsigned __int8 *)(a1 + 168), 29, 0);
  result = 0;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
