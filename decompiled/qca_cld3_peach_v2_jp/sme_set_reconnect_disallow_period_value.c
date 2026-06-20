__int64 __fastcall sme_set_reconnect_disallow_period_value(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 result; // x0
  _QWORD v6[5]; // [xsp+8h] [xbp-28h] BYREF

  v6[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 8);
  v6[1] = 0;
  v6[0] = a3;
  *(_DWORD *)(v3 + 1556) = a3;
  v4 = *(_QWORD *)(a1 + 21552);
  v6[2] = 0;
  v6[3] = 0;
  result = wlan_cm_roam_cfg_set_value(v4, a2, 0x2Du, (unsigned int *)v6);
  _ReadStatusReg(SP_EL0);
  return result;
}
