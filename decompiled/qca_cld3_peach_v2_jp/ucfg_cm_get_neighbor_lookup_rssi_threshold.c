__int64 __fastcall ucfg_cm_get_neighbor_lookup_rssi_threshold(__int64 a1, unsigned int a2, _BYTE *a3)
{
  _QWORD v5[5]; // [xsp+8h] [xbp-28h] BYREF

  v5[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v5, 0, 32);
  wlan_cm_roam_cfg_get_value(a1, a2, 0xEu, v5);
  *a3 = v5[0];
  _ReadStatusReg(SP_EL0);
  return 0;
}
