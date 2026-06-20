__int64 __fastcall if_mgr_connect_complete(__int64 a1, int *a2)
{
  __int64 v2; // x22
  __int64 v3; // x19
  int v4; // w23
  unsigned int v5; // w20
  __int64 v7; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  char acs_mode_for_vdev; // w0

  v2 = *(_QWORD *)(a1 + 216);
  if ( !v2 )
    return 16;
  v3 = *(_QWORD *)(v2 + 80);
  if ( !v3 )
    return 16;
  v4 = *a2;
  v5 = *(unsigned __int8 *)(a1 + 168);
  v7 = *(_QWORD *)(v2 + 80);
  if ( *a2 )
  {
    ucfg_tdls_notify_connect_failure(v7);
  }
  else
  {
    if ( (cfg_p2p_is_roam_config_disabled(v7, a2) & 1) != 0 && *(_DWORD *)(a1 + 16) == 2 )
    {
      qdf_trace_msg(
        0x78u,
        8u,
        "%s: p2p client active, keep roam disabled",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "if_mgr_connect_complete");
      goto LABEL_11;
    }
    qdf_trace_msg(
      0x78u,
      8u,
      "%s: set pcl when connection on vdev id:%d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "if_mgr_connect_complete",
      v5);
    policy_mgr_set_pcl_for_connected_vdev(v3, v5, 0);
  }
  if_mgr_enable_roaming(v2, a1, 4);
LABEL_11:
  policy_mgr_check_n_start_opportunistic_timer(v3);
  if ( !*(_DWORD *)(a1 + 16)
    && (wlan_vdev_mlme_is_mlo_vdev(a1, v17, v18, v19, v20, v21, v22, v23, v24) & 1) != 0
    && (wlan_mlme_is_aux_emlsr_support(v3) & 1) == 0 )
  {
    wlan_handle_emlsr_sta_concurrency(v3, 0, 1);
  }
  if ( !wlan_cm_is_vdev_roaming(a1, v17, v18, v19, v20, v21, v22, v23, v24) )
  {
    acs_mode_for_vdev = wlan_util_vdev_mgr_get_acs_mode_for_vdev(a1);
    policy_mgr_check_concurrent_intf_and_restart_sap(v3, acs_mode_for_vdev & 1);
  }
  if ( !v4 )
    policy_mgr_trigger_roam_for_sta_sap_mcc_non_dbs(v3);
  wlan_ll_sap_switch_bearer_on_sta_connect_complete(v3, v5);
  return 0;
}
