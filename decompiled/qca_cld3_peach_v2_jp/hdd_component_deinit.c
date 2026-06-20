__int64 hdd_component_deinit()
{
  __int64 v0; // x0
  __int64 v1; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7

  v0 = ucfg_mgmt_rx_srng_deinit();
  v1 = ucfg_ll_sap_deinit(v0);
  v2 = ucfg_qmi_deinit(v1);
  v10 = ucfg_dp_deinit(v2, v3, v4, v5, v6, v7, v8, v9);
  v11 = ucfg_pre_cac_deinit(v10);
  v12 = ucfg_dlm_deinit(v11);
  v13 = ucfg_tdls_deinit(v12);
  v21 = policy_mgr_deinit(v13, v14, v15, v16, v17, v18, v19, v20);
  v22 = ucfg_interop_issues_ap_deinit(v21);
  v30 = ucfg_p2p_deinit(v22, v23, v24, v25, v26, v27, v28, v29);
  v31 = nan_deinit(v30);
  v32 = ucfg_action_oui_deinit(v31);
  v33 = ipa_deinit(v32);
  v34 = pmo_deinit(v33);
  v35 = disa_deinit(v34);
  ucfg_fwol_deinit(v35);
  ucfg_mlme_deinit();
  target_if_deinit(v36, v37, v38, v39, v40, v41, v42, v43);
  dispatcher_deinit();
  return ucfg_mlme_global_deinit();
}
