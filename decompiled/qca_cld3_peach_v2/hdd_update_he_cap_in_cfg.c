__int64 __fastcall hdd_update_he_cap_in_cfg(__int64 *a1)
{
  __int64 v2; // x0
  unsigned int he_ul_mumimo; // w0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w20
  __int64 result; // x0
  unsigned int v14; // w1
  _BYTE v15[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v16[4]; // [xsp+10h] [xbp-10h] BYREF
  int v17; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v17 = 0;
  v16[0] = 0;
  v15[0] = 0;
  he_ul_mumimo = wlan_mlme_cfg_get_he_ul_mumimo(v2, &v17);
  if ( he_ul_mumimo )
  {
    v12 = he_ul_mumimo;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not get CFG_HE_UL_MUMIMO",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hdd_update_he_cap_in_cfg");
    result = qdf_status_to_os_return(v12);
  }
  else
  {
    result = wlan_mlme_cfg_get_enable_ul_mimo(*a1, v15);
    if ( !(_DWORD)result )
    {
      result = wlan_mlme_cfg_get_enable_ul_ofdm(*a1, v16);
      if ( !(_DWORD)result )
      {
        if ( (v17 & 3) != 0 )
          v14 = v15[0] & 1;
        else
          v14 = 0;
        if ( (v17 & 2) != 0 )
          v14 = v15[0] & 1 | (2 * (v16[0] & 1));
        result = wlan_mlme_cfg_set_he_ul_mumimo(*a1, v14);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
