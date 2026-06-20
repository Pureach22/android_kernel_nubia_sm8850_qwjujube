__int64 __fastcall hdd_update_components_config(__int64 *a1)
{
  __int64 v2; // x0
  unsigned int wow_enable; // w0
  int v4; // w8
  char v5; // w9
  int v6; // w10
  __int64 v7; // x0
  unsigned int updated; // w20
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  char is_enabled; // w0
  __int64 v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // [xsp+8h] [xbp-88h] BYREF
  __int64 v29; // [xsp+10h] [xbp-80h]
  __int64 v30; // [xsp+18h] [xbp-78h]
  _QWORD v31[14]; // [xsp+20h] [xbp-70h] BYREF

  v31[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v30 = 0;
  memset(v31, 0, 104);
  v28 = 0;
  v29 = 0;
  ucfg_pmo_get_psoc_config(v2, &v28);
  wow_enable = ucfg_pmo_get_wow_enable(*a1);
  v4 = *((unsigned __int8 *)a1 + 854);
  v5 = wow_enable & 1;
  v6 = (wow_enable >> 1) & 1;
  v7 = *a1;
  BYTE4(v30) = v5;
  LOBYTE(v28) = v6;
  HIBYTE(v29) = 0;
  BYTE6(v29) = v4 != 0;
  wlan_mlme_get_sap_max_modulated_dtim(v7, (_BYTE *)v31 + 5);
  hdd_lpass_populate_pmo_config(&v28, a1);
  updated = ucfg_pmo_update_psoc_config(*a1, &v28);
  if ( updated )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed pmo psoc configuration; status:%d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "hdd_update_pmo_config",
      updated);
  result = qdf_status_to_os_return(updated);
  if ( !(_DWORD)result )
  {
    result = hdd_update_scan_config(a1);
    if ( !(_DWORD)result )
    {
      result = hdd_update_tdls_config(a1);
      if ( !(_DWORD)result )
      {
        v28 = 0x100000000LL;
        is_enabled = ucfg_ipa_is_enabled(result);
        v19 = *a1;
        LOBYTE(v28) = is_enabled & 1;
        if ( (unsigned int)ucfg_dp_update_config(v19, (unsigned __int8 *)&v28) )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: failed DP PSOC configuration update",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "hdd_update_dp_config");
          result = 4294967274LL;
        }
        else
        {
          result = hdd_update_dfs_config(a1);
          if ( !(_DWORD)result )
            result = hdd_update_regulatory_config(a1);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
