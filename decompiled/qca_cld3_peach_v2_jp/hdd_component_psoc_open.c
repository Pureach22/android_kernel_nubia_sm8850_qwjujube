__int64 __fastcall hdd_component_psoc_open(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w20
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  result = ucfg_mlme_psoc_open(a1);
  if ( !(_DWORD)result )
  {
    v3 = ucfg_dlm_psoc_open(a1);
    if ( !v3 )
    {
      v3 = ucfg_fwol_psoc_open(a1);
      if ( !v3 )
      {
        v3 = ucfg_pmo_psoc_open(a1);
        if ( !v3 )
        {
          v3 = ucfg_policy_mgr_psoc_open(a1);
          if ( !v3 )
          {
            v3 = ucfg_p2p_psoc_open(a1, v4, v5, v6, v7, v8, v9, v10, v11);
            if ( !v3 )
            {
              v3 = ucfg_tdls_psoc_open(a1);
              if ( !v3 )
              {
                v3 = ucfg_nan_psoc_open(a1);
                if ( !v3 )
                {
                  v3 = ucfg_twt_psoc_open(a1);
                  if ( !v3 )
                  {
                    v3 = ucfg_wifi_pos_psoc_open(a1);
                    if ( !v3 )
                    {
                      result = ucfg_dp_psoc_open(a1);
                      if ( !(_DWORD)result )
                        return result;
                      v3 = result;
                      ucfg_wifi_pos_psoc_close(a1);
                    }
                    ucfg_twt_psoc_close(a1);
                  }
                  ucfg_nan_psoc_close(a1);
                }
                v12 = ucfg_tdls_psoc_close(a1);
              }
              ucfg_p2p_psoc_close(a1, v12, v13, v14, v15, v16, v17, v18, v19);
            }
            ucfg_policy_mgr_psoc_close(a1);
          }
          ucfg_pmo_psoc_close(a1);
        }
        ucfg_fwol_psoc_close(a1);
      }
      ucfg_dlm_psoc_close(a1);
    }
    ucfg_mlme_psoc_close();
    return v3;
  }
  return result;
}
