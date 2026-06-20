__int64 __fastcall sme_get_roam_config_status(__int64 a1, unsigned int a2, _BYTE *a3)
{
  __int64 v4; // x0
  __int64 v6; // [xsp+8h] [xbp-28h] BYREF
  __int64 v7; // [xsp+10h] [xbp-20h]
  __int64 v8; // [xsp+18h] [xbp-18h]
  __int64 v9; // [xsp+20h] [xbp-10h]
  __int64 v10; // [xsp+28h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 21552);
  v8 = 0;
  v9 = 0;
  v6 = 0;
  v7 = 0;
  wlan_cm_roam_cfg_get_value(v4, a2, 0x12u, &v6);
  *a3 = v7;
  _ReadStatusReg(SP_EL0);
  return 0;
}
