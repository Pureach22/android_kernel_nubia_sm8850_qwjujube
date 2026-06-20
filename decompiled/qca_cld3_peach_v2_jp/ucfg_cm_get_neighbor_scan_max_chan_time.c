__int64 __fastcall ucfg_cm_get_neighbor_scan_max_chan_time(__int64 a1, unsigned int a2)
{
  _QWORD v3[5]; // [xsp+8h] [xbp-28h] BYREF

  v3[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v3, 0, 32);
  wlan_cm_roam_cfg_get_value(a1, a2, 7u, v3);
  _ReadStatusReg(SP_EL0);
  return LODWORD(v3[0]);
}
