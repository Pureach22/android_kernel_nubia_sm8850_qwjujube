__int64 hdd_component_deinit()
{
  __int64 v0; // x0
  __int64 v1; // x0
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x0
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
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  v0 = ucfg_mgmt_rx_srng_deinit();
  v1 = hdd_mlo_mgr_unregister_osif_ops(v0);
  v2 = ucfg_ll_sap_deinit(v1);
  v3 = ucfg_qmi_deinit(v2);
  v11 = ucfg_dp_deinit(v3, v4, v5, v6, v7, v8, v9, v10);
  v12 = ucfg_pre_cac_deinit(v11);
  v13 = ucfg_dlm_deinit(v12);
  ucfg_tdls_deinit(v13);
  v14 = policy_mgr_deinit();
  v15 = ucfg_interop_issues_ap_deinit(v14);
  v23 = ucfg_p2p_deinit(v15, v16, v17, v18, v19, v20, v21, v22);
  v24 = nan_deinit(v23);
  v25 = ucfg_action_oui_deinit(v24);
  v26 = ipa_deinit(v25);
  v27 = pmo_deinit(v26);
  v28 = disa_deinit(v27);
  ucfg_fwol_deinit(v28);
  ucfg_mlme_deinit();
  target_if_deinit(v29, v30, v31, v32, v33, v34, v35, v36);
  dispatcher_deinit();
  return ucfg_mlme_global_deinit();
}
