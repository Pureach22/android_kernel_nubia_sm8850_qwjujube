__int64 __fastcall wlan_cp_stats_ctx_init_ol(_QWORD *a1)
{
  a1[19] = wlan_cp_stats_open_ol;
  a1[20] = wlan_cp_stats_close_ol;
  a1[21] = wlan_cp_stats_enable_ol;
  a1[22] = wlan_cp_stats_disable_ol;
  a1[10] = wlan_cp_stats_psoc_obj_init_ol;
  a1[11] = wlan_cp_stats_psoc_obj_deinit_ol;
  a1[12] = wlan_cp_stats_pdev_obj_init_ol;
  a1[13] = wlan_cp_stats_pdev_obj_deinit_ol;
  a1[14] = wlan_cp_stats_vdev_obj_init_ol;
  a1[15] = wlan_cp_stats_vdev_obj_deinit_ol;
  a1[16] = wlan_cp_stats_peer_obj_init_ol;
  a1[17] = wlan_cp_stats_peer_obj_deinit_ol;
  return 0;
}
