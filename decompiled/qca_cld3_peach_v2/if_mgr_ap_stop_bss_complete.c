__int64 __fastcall if_mgr_ap_stop_bss_complete(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v3; // x20
  int v4; // w8
  unsigned __int8 sta_vdev_id; // w0
  __int64 result; // x0
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 216);
  if ( v2 && (v3 = *(_QWORD *)(v2 + 80)) != 0 )
  {
    v4 = *(_DWORD *)(a1 + 16);
    v8[0] = 0;
    if ( (v4 | 2) == 3 && (wlan_mlme_is_aux_emlsr_support(v3) & 1) == 0 )
      wlan_handle_emlsr_sta_concurrency(v3, 0, 1);
    if ( (cfg_p2p_is_roam_config_disabled(v3, a2) & 1) != 0 && *(_DWORD *)(a1 + 16) == 3 )
      if_mgr_enable_roaming(v2, a1, 1);
    if_mgr_enable_roaming(v2, a1, 8);
    policy_mgr_get_mcc_scc_switch(v3, v8);
    if ( *(_DWORD *)(a1 + 16) == 3 && v8[0] == 4 )
      policy_mgr_check_concurrent_intf_and_restart_sap(v3, 0);
    if ( (policy_mgr_is_vdev_ll_lt_sap(v3, *(unsigned __int8 *)(a1 + 168)) & 1) != 0 )
      policy_mgr_ll_lt_sap_restart_concurrent_sap(v3, 3);
    if ( *(_DWORD *)(a1 + 16) == 3 && (wlan_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(v3) & 1) != 0 )
    {
      sta_vdev_id = wlan_p2p_psoc_priv_get_sta_vdev_id(v3);
      wlan_p2p_del_random_mac(v3, sta_vdev_id, 0);
    }
    if ( (policy_mgr_is_dual_sap_active(v3) & 1) == 0 && (wlan_mlme_is_aux_emlsr_support(v3) & 1) != 0 )
      ml_nlink_conn_change_notify(v3, *(unsigned __int8 *)(a1 + 168), 30, 0);
    result = 0;
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
