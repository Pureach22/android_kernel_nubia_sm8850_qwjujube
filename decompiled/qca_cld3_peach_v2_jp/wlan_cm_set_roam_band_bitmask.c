__int64 __fastcall wlan_cm_set_roam_band_bitmask(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  _QWORD v4[5]; // [xsp+8h] [xbp-28h] BYREF

  v4[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v4[1], 0, 24);
  v4[0] = a3;
  result = wlan_cm_roam_cfg_set_value(a1, a2, 0x1Bu, (unsigned int *)v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
