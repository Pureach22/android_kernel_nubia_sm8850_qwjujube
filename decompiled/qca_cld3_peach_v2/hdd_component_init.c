__int64 hdd_component_init()
{
  __int64 result; // x0
  unsigned int v1; // w19
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x0
  __int64 v60; // x0
  unsigned int v61; // w0
  __int64 v62; // x0

  result = ucfg_mlme_global_init();
  if ( !(_DWORD)result )
  {
    v1 = dispatcher_init();
    if ( !v1 )
    {
      v1 = target_if_init((__int64)wma_get_psoc_from_scn_handle);
      if ( !v1 )
      {
        v1 = ucfg_mlme_init(v2, v3, v4, v5, v6, v7, v8, v9);
        if ( !v1 )
        {
          v1 = ucfg_fwol_init();
          if ( !v1 )
          {
            v18 = disa_init();
            v1 = v18;
            if ( !(_DWORD)v18 )
            {
              v19 = pmo_init();
              v1 = v19;
              if ( !(_DWORD)v19 )
              {
                v20 = ipa_init();
                v1 = v20;
                if ( !(_DWORD)v20 )
                {
                  v21 = ucfg_action_oui_init();
                  v1 = v21;
                  if ( !(_DWORD)v21 )
                  {
                    v22 = nan_init();
                    v1 = v22;
                    if ( !(_DWORD)v22 )
                    {
                      v31 = ucfg_p2p_init(v23, v24, v25, v26, v27, v28, v29, v30);
                      v1 = v31;
                      if ( !(_DWORD)v31 )
                      {
                        v1 = ucfg_interop_issues_ap_init();
                        if ( !v1 )
                        {
                          v40 = policy_mgr_init(v32, v33, v34, v35, v36, v37, v38, v39);
                          v1 = v40;
                          if ( !(_DWORD)v40 )
                          {
                            v1 = ucfg_tdls_init();
                            if ( !v1 )
                            {
                              v41 = ucfg_dlm_init();
                              v1 = v41;
                              if ( !(_DWORD)v41 )
                              {
                                v42 = ucfg_pre_cac_init();
                                v1 = v42;
                                if ( !(_DWORD)v42 )
                                {
                                  v42 = ucfg_dp_init(v43, v44, v45, v46, v47, v48, v49, v50);
                                  v1 = v42;
                                  if ( !(_DWORD)v42 )
                                  {
                                    v1 = ucfg_qmi_init();
                                    if ( !v1 )
                                    {
                                      v59 = ucfg_ll_sap_init();
                                      v1 = v59;
                                      if ( !(_DWORD)v59 )
                                      {
                                        v60 = hdd_mlo_mgr_register_osif_ops();
                                        v1 = v60;
                                        if ( !(_DWORD)v60 )
                                        {
                                          v61 = ucfg_mgmt_rx_srng_init();
                                          if ( !v61 )
                                          {
                                            hdd_register_cstats_ops();
                                            return 0;
                                          }
                                          v1 = v61;
                                          v60 = hdd_mlo_mgr_unregister_osif_ops();
                                        }
                                        v59 = ucfg_ll_sap_deinit(v60);
                                      }
                                      v51 = ucfg_qmi_deinit(v59);
                                    }
                                    v42 = ucfg_dp_deinit(v51, v52, v53, v54, v55, v56, v57, v58);
                                  }
                                }
                                v62 = ucfg_pre_cac_deinit(v42);
                                v41 = ucfg_dlm_deinit(v62);
                              }
                              ucfg_tdls_deinit(v41);
                            }
                            v40 = policy_mgr_deinit();
                          }
                          v32 = ucfg_interop_issues_ap_deinit(v40);
                        }
                        v31 = ucfg_p2p_deinit(v32, v33, v34, v35, v36, v37, v38, v39);
                      }
                      v22 = nan_deinit(v31);
                    }
                    v21 = ucfg_action_oui_deinit(v22);
                  }
                  v20 = ipa_deinit(v21);
                }
                v19 = pmo_deinit(v20);
              }
              v18 = disa_deinit(v19);
            }
            ucfg_fwol_deinit(v18);
          }
          ucfg_mlme_deinit();
        }
        target_if_deinit(v10, v11, v12, v13, v14, v15, v16, v17);
      }
      dispatcher_deinit();
    }
    ucfg_mlme_global_deinit();
    return v1;
  }
  return result;
}
