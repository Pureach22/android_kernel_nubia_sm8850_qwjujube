__int64 __fastcall sme_update_roam_scan_n_probes(__int64 a1, unsigned int a2, unsigned __int8 a3)
{
  __int64 v3; // x0
  __int64 result; // x0
  _QWORD v5[5]; // [xsp+8h] [xbp-28h] BYREF

  v5[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 21624);
  memset(&v5[1], 0, 24);
  v5[0] = a3;
  result = wlan_cm_roam_cfg_set_value(v3, a2, 0xFu, (unsigned int *)v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
