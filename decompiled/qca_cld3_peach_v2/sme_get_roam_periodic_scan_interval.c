__int64 __fastcall sme_get_roam_periodic_scan_interval(__int64 a1, unsigned int a2, _DWORD *a3)
{
  __int64 v4; // x0
  _QWORD v6[5]; // [xsp+8h] [xbp-28h] BYREF

  v6[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 21624);
  memset(v6, 0, 32);
  wlan_cm_roam_cfg_get_value(v4, a2, 0x29u, v6);
  *a3 = v6[0];
  _ReadStatusReg(SP_EL0);
  return 0;
}
