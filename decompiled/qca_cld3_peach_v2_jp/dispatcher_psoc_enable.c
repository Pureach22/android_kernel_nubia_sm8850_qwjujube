__int64 __fastcall dispatcher_psoc_enable(__int64 a1)
{
  int v2; // w0
  __int64 result; // x0

  if ( !(unsigned int)wlan_serialization_psoc_enable() )
  {
    if ( !(unsigned int)ucfg_scan_psoc_enable(a1) )
    {
      if ( !(unsigned int)wlan_cp_stats_enable(a1) )
      {
        if ( !(unsigned int)wlan_dcs_enable(a1) )
        {
          if ( !(unsigned int)wifi_pos_psoc_enable(a1) )
          {
            if ( !(unsigned int)wifi_dfs_psoc_enable(a1) )
            {
              if ( !(unsigned int)dispatcher_dbr_psoc_enable(a1) )
              {
                if ( !(unsigned int)wlan_crypto_psoc_enable(a1) )
                {
                  if ( !(unsigned int)wlan_mlme_psoc_enable(a1) )
                  {
                    v2 = wlan_spectral_psoc_enable(a1);
                    if ( v2 == 39 || !v2 )
                    {
                      if ( !(unsigned int)wlan_mgmt_txrx_psoc_enable(a1) )
                      {
                        if ( !(unsigned int)twt_psoc_enable(a1) )
                        {
                          if ( !(unsigned int)wlan_dbam_psoc_enable(a1) )
                          {
                            result = wlan_coap_enable(a1);
                            if ( !(_DWORD)result )
                              return result;
                            wlan_dbam_psoc_disable(a1);
                          }
                          twt_psoc_disable(a1);
                        }
                        wlan_mgmt_txrx_psoc_disable(a1);
                      }
                      wlan_spectral_psoc_disable(a1);
                    }
                    wlan_mlme_psoc_disable(a1);
                  }
                  wlan_crypto_psoc_disable(a1);
                }
                dispatcher_dbr_psoc_disable(a1);
              }
              wifi_dfs_psoc_disable(a1);
            }
            wifi_pos_psoc_disable(a1);
          }
          wlan_dcs_disable(a1);
        }
        wlan_cp_stats_disable(a1);
      }
      ucfg_scan_psoc_disable(a1);
    }
    wlan_serialization_psoc_disable(a1);
  }
  return 16;
}
