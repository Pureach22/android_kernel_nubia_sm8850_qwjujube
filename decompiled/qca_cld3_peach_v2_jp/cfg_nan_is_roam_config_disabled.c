__int64 __fastcall cfg_nan_is_roam_config_disabled(__int64 a1)
{
  int roam_disable_config; // w0
  unsigned int v2; // w8
  unsigned int v3; // w8
  unsigned int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  roam_disable_config = ucfg_mlme_get_roam_disable_config(a1, &v5);
  v2 = v5;
  _ReadStatusReg(SP_EL0);
  v3 = (v2 >> 1) & 1;
  if ( roam_disable_config )
    return 0;
  else
    return v3;
}
