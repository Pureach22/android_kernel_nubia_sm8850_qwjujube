__int64 dispatcher_init()
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
  __int64 result; // x0

  if ( !(unsigned int)wlan_objmgr_global_obj_init() )
  {
    v0 = wlan_mlo_mgr_init();
    if ( !(_DWORD)v0 )
    {
      v1 = wlan_mgmt_txrx_init();
      if ( !(_DWORD)v1 )
      {
        v2 = ucfg_scan_init();
        if ( !(_DWORD)v2 )
        {
          v3 = wlan_serialization_init();
          if ( !(_DWORD)v3 )
          {
            v4 = wlan_crypto_init();
            if ( !(_DWORD)v4 )
            {
              v5 = wlan_cp_stats_init();
              if ( !(_DWORD)v5 )
              {
                v6 = wlan_dcs_init();
                if ( !(_DWORD)v6 )
                {
                  v7 = wifi_pos_init();
                  if ( !(_DWORD)v7 )
                  {
                    v8 = dfs_init();
                    if ( !(_DWORD)v8 )
                    {
                      v9 = wlan_regulatory_init();
                      if ( !(_DWORD)v9 )
                      {
                        v10 = wlan_green_ap_init();
                        if ( !(_DWORD)v10 )
                        {
                          v11 = dispatcher_ftm_init();
                          if ( !(_DWORD)v11 )
                          {
                            v12 = cfg_dispatcher_init();
                            if ( !(_DWORD)v12 )
                            {
                              if ( !(unsigned int)wlan_spectral_init() )
                              {
                                v13 = wlan_cmn_mlme_init();
                                if ( !(_DWORD)v13 )
                                {
                                  v14 = wlan_cfr_init();
                                  if ( !(_DWORD)v14 )
                                  {
                                    v15 = wlan_coex_init();
                                    if ( !(_DWORD)v15 )
                                    {
                                      v16 = wlan_if_mgr_init();
                                      if ( !(_DWORD)v16 )
                                      {
                                        v17 = wlan_gpio_init();
                                        if ( !(_DWORD)v17 )
                                        {
                                          v18 = wlan_twt_init();
                                          if ( !(_DWORD)v18 )
                                          {
                                            v19 = wlan_coap_init();
                                            if ( !(_DWORD)v19 )
                                            {
                                              result = scheduler_init();
                                              if ( !(_DWORD)result )
                                                return result;
                                              v19 = wlan_coap_deinit();
                                            }
                                            v18 = wlan_twt_deinit(v19);
                                          }
                                          v17 = wlan_gpio_deinit(v18);
                                        }
                                        v16 = wlan_if_mgr_deinit(v17);
                                      }
                                      v15 = wlan_coex_deinit(v16);
                                    }
                                    v14 = wlan_cfr_deinit(v15);
                                  }
                                  v13 = wlan_cmn_mlme_deinit(v14);
                                }
                                wlan_spectral_deinit(v13);
                              }
                              v12 = cfg_dispatcher_deinit();
                            }
                            v11 = dispatcher_ftm_deinit(v12);
                          }
                          v10 = wlan_green_ap_deinit(v11);
                        }
                        v9 = wlan_regulatory_deinit(v10);
                      }
                      v8 = dfs_deinit(v9);
                    }
                    v7 = wifi_pos_deinit(v8);
                  }
                  v6 = wlan_dcs_deinit(v7);
                }
                v5 = wlan_cp_stats_deinit(v6);
              }
              v4 = wlan_crypto_deinit(v5);
            }
            v3 = wlan_serialization_deinit(v4);
          }
          v2 = ucfg_scan_deinit(v3);
        }
        v1 = wlan_mgmt_txrx_deinit(v2);
      }
      v0 = wlan_objmgr_global_obj_deinit(v1);
    }
    wlan_mlo_mgr_deinit(v0);
  }
  return 16;
}
