__int64 __fastcall policy_mgr_get_sap_scc_freq_nan_present(__int64 a1)
{
  _QWORD *v1; // x18
  unsigned int disc_24g_ch_freq; // w19
  int v4; // w20
  __int64 result; // x0
  unsigned int v6; // w21
  unsigned int v7; // w21
  unsigned int v8; // w21
  unsigned int v9; // w21
  __int64 v10; // d4
  __int64 v11; // d5
  unsigned int v12; // [xsp+0h] [xbp-40h] BYREF
  unsigned int v13; // [xsp+4h] [xbp-3Ch] BYREF
  int v14; // [xsp+8h] [xbp-38h] BYREF
  char v15; // [xsp+Ch] [xbp-34h]
  int v16; // [xsp+10h] [xbp-30h] BYREF
  char v17; // [xsp+14h] [xbp-2Ch]
  int v18; // [xsp+18h] [xbp-28h] BYREF
  char v19; // [xsp+1Ch] [xbp-24h]
  __int64 v20; // [xsp+20h] [xbp-20h] BYREF
  __int64 v21; // [xsp+28h] [xbp-18h]
  unsigned int v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LOBYTE(v13) = 0;
  LOBYTE(v12) = 0;
  v19 = 0;
  v18 = 0;
  v17 = 0;
  v16 = 0;
  v22 = 0;
  v20 = 0;
  v21 = 0;
  v15 = 0;
  v14 = 0;
  disc_24g_ch_freq = wlan_nan_get_disc_24g_ch_freq();
  policy_mgr_get_ml_and_non_ml_mode_count(
    a1,
    &v13,
    (__int64)&v18,
    &v12,
    (__int64)&v16,
    (unsigned __int64)&v20,
    (unsigned __int64)&v14,
    0);
  if ( (unsigned __int8)v13 > 1u )
    goto LABEL_25;
  if ( !((unsigned __int8)v12 | (unsigned __int8)v13) )
    goto LABEL_25;
  v4 = (unsigned __int8)v12 + (unsigned __int8)v13;
  if ( !v4 )
    goto LABEL_25;
  if ( wlan_reg_is_24ghz_ch_freq(v20) )
    result = (unsigned int)v20;
  else
    result = 0;
  if ( v4 == 1 )
    goto LABEL_24;
  v6 = result;
  result = wlan_reg_is_24ghz_ch_freq(HIDWORD(v20)) ? HIDWORD(v20) : v6;
  if ( v4 == 2
    || ((v7 = result, !wlan_reg_is_24ghz_ch_freq(v21)) ? (result = v7) : (result = (unsigned int)v21),
        v4 == 3
     || ((v8 = result, !wlan_reg_is_24ghz_ch_freq(HIDWORD(v21))) ? (result = v8) : (result = HIDWORD(v21)),
         v4 == 4 || ((v9 = result, !wlan_reg_is_24ghz_ch_freq(v22)) ? (result = v9) : (result = v22), v4 == 5))) )
  {
LABEL_24:
    if ( (_DWORD)result )
    {
LABEL_26:
      _ReadStatusReg(SP_EL0);
      return result;
    }
LABEL_25:
    result = disc_24g_ch_freq;
    goto LABEL_26;
  }
  __break(0x5512u);
  *v1 = v10;
  v1[1] = v11;
  return policy_mgr_is_restart_sap_required(result);
}
