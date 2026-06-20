__int64 __fastcall cfg_p2p_is_roam_config_disabled(__int64 a1)
{
  int roam_disable_config; // w0
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  roam_disable_config = ucfg_mlme_get_roam_disable_config(a1, &v3);
  _ReadStatusReg(SP_EL0);
  return (roam_disable_config == 0) & (unsigned __int8)v3;
}
