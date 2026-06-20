__int64 __fastcall hdd_context_destroy(__int64 a1)
{
  double v2; // d0
  __int64 v3; // x2
  __int64 v4; // x3
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v2 = wlan_hdd_sar_timers_deinit();
  v12 = cds_set_context(0x33u, 0, v3, v4, v2, v5, v6, v7, v8, v9, v10, v11);
  v13 = spectral_scan_deactivate_service(v12);
  cnss_diag_deactivate_service(v13);
  if ( cesium_nl_srv_sock )
  {
    netlink_kernel_release();
    cesium_nl_srv_sock = 0;
  }
  v14 = ptt_sock_deactivate_svc();
  if ( (unsigned int)os_if_wifi_pos_deregister_nl(v14) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: os_if_wifi_pos_deregister_nl failed",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hdd_deactivate_wifi_pos");
  nl_srv_exit();
  hdd_context_deinit(a1);
  hdd_objmgr_release_and_destroy_psoc(a1);
  _qdf_mem_free(*(_QWORD *)(a1 + 104));
  *(_QWORD *)(a1 + 104) = 0;
  cfg_release();
  _qdf_delayed_work_destroy();
  return wiphy_free(*(_QWORD *)(a1 + 24));
}
