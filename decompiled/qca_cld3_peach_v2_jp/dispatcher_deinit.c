__int64 dispatcher_deinit()
{
  __int64 v0; // x0
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0

  v0 = scheduler_deinit();
  v1 = wlan_coap_deinit(v0);
  v2 = wlan_twt_deinit(v1);
  v3 = wlan_gpio_deinit(v2);
  v4 = wlan_if_mgr_deinit(v3);
  v5 = wlan_coex_deinit(v4);
  v6 = wlan_cfr_deinit(v5);
  wlan_cmn_mlme_deinit(v6);
  v7 = cfg_dispatcher_deinit();
  v8 = dispatcher_ftm_deinit(v7);
  v9 = wlan_green_ap_deinit(v8);
  v10 = wlan_spectral_deinit(v9);
  v11 = wlan_regulatory_deinit(v10);
  v12 = dfs_deinit(v11);
  v13 = wifi_pos_deinit(v12);
  v14 = wlan_cp_stats_deinit(v13);
  v15 = wlan_dcs_deinit(v14);
  v16 = wlan_crypto_deinit(v15);
  v17 = wlan_serialization_deinit(v16);
  v18 = ucfg_scan_deinit(v17);
  v19 = wlan_mgmt_txrx_deinit(v18);
  wlan_objmgr_global_obj_deinit(v19);
  return 0;
}
