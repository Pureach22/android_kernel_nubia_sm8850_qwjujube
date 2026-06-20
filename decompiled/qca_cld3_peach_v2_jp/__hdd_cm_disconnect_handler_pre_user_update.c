__int64 __fastcall _hdd_cm_disconnect_handler_pre_user_update(char *a1)
{
  __int64 v1; // x19
  __int64 v3; // x21
  void *v4; // x0
  __int64 vdev_by_user; // x0
  __int64 v6; // x21

  v1 = *(_QWORD *)a1;
  v3 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  hdd_reset_tsf_sync(*(_QWORD *)a1);
  v4 = qdf_mem_set(a1 + 908, 0x18u, 0);
  if ( (ucfg_ipa_is_enabled(v4) & 1) != 0
    && !(unsigned int)_wlan_hdd_validate_mac_address(a1 + 300, "hdd_handle_ipa_sta_mlo_disconn") )
  {
    ucfg_ipa_wlan_evt(
      *(_QWORD *)(v3 + 8),
      *(_QWORD *)(v1 + 32),
      *(unsigned int *)(v1 + 40),
      (unsigned __int8)a1[8],
      5,
      a1 + 300,
      0);
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 97, "__hdd_cm_disconnect_handler_pre_user_update");
  if ( vdev_by_user )
  {
    v6 = vdev_by_user;
    ucfg_dp_periodic_sta_stats_stop();
    _hdd_objmgr_put_vdev_by_user(v6, 97, "__hdd_cm_disconnect_handler_pre_user_update");
  }
  qdf_dp_trace_mgmt_pkt(5, a1[8], 0xFFu, 3, 29);
  hdd_wmm_dscp_initial_state(v1);
  return wlan_deregister_txrx_packetdump();
}
