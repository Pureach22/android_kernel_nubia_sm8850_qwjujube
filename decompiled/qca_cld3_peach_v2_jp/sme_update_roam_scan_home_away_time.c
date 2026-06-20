__int64 __fastcall sme_update_roam_scan_home_away_time(
        __int64 a1,
        unsigned int a2,
        unsigned __int16 a3,
        unsigned __int8 a4)
{
  __int64 v4; // x0
  __int64 result; // x0
  _QWORD v6[5]; // [xsp+8h] [xbp-28h] BYREF

  v6[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 21552);
  v6[1] = a4;
  v6[2] = 0;
  v6[3] = 0;
  v6[0] = a3;
  result = wlan_cm_roam_cfg_set_value(v4, a2, 0x10u, (unsigned int *)v6);
  _ReadStatusReg(SP_EL0);
  return result;
}
