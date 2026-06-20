__int64 __fastcall hdd_objmgr_release_and_destroy_pdev(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w20
  unsigned int *v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  v9 = *(_QWORD *)(a1 + 8);
  *(_QWORD *)(a1 + 8) = 0;
  if ( !v9 )
    return 4294967274LL;
  target_if_free_pdev_tgt_info(v9, a2, a3, a4, a5, a6, a7, a8, a9);
  os_if_spectral_netlink_deinit(v9);
  wlan_cfg80211_scan_priv_deinit(v9);
  v10 = *(_QWORD *)(v9 + 24);
  *(_QWORD *)(v9 + 24) = 0;
  _qdf_mem_free(v10);
  v19 = wlan_objmgr_pdev_obj_delete(v9, v11, v12, v13, v14, v15, v16, v17, v18);
  wlan_objmgr_pdev_release_ref(v9, 5u, v20, v21, v22, v23, v24, v25, v26, v27, v28);
  return qdf_status_to_os_return(v19);
}
