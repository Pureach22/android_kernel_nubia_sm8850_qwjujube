__int64 __fastcall policy_mgr_modify_dual_sap_band_pcl_filter(
        __int64 result,
        __int64 a2,
        __int64 a3,
        unsigned int *a4,
        int a5,
        __int64 a6,
        char a7)
{
  __int64 v12; // x24
  unsigned int v13; // w22
  unsigned __int8 v14; // w8
  __int64 v15; // x23
  _BYTE v16[4]; // [xsp+4h] [xbp-2Ch] BYREF
  int v17; // [xsp+8h] [xbp-28h] BYREF
  char v18; // [xsp+Ch] [xbp-24h]
  _QWORD v19[2]; // [xsp+10h] [xbp-20h] BYREF
  int v20; // [xsp+20h] [xbp-10h]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v19[0] = 0;
  v19[1] = 0;
  v18 = 0;
  v17 = 0;
  if ( a5 == 1 )
  {
    v12 = result;
    v16[0] = 0;
    result = policy_mgr_get_mode_specific_conn_info(result, (unsigned __int64)v19, (unsigned __int64)&v17, 1u);
    if ( (unsigned __int8)result == 1 )
    {
      result = policy_mgr_get_multi_sap_allowed_on_same_band(v12, v16);
      if ( (v16[0] & 1) == 0 )
      {
        result = policy_mgr_is_owe_connection_present(*(_QWORD *)(a6 + 8), a7);
        if ( (result & 1) == 0 )
        {
          if ( *a4 )
          {
            v13 = 0;
            v14 = 0;
            do
            {
              v15 = v14;
              result = wlan_reg_is_same_band_freqs(*(_DWORD *)(a2 + 4LL * v14), v19[0]);
              if ( (result & 1) == 0 )
              {
                *(_DWORD *)(a2 + 4LL * v13) = *(_DWORD *)(a2 + 4 * v15);
                *(_BYTE *)(a3 + v13++) = *(_BYTE *)(a3 + v15);
              }
              v14 = v15 + 1;
            }
            while ( *a4 > (unsigned __int8)(v15 + 1) );
          }
          else
          {
            v13 = 0;
          }
          *a4 = v13;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
