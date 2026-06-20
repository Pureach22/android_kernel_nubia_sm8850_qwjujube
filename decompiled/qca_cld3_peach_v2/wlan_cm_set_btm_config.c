__int64 __fastcall wlan_cm_set_btm_config(__int64 a1, unsigned int a2, unsigned __int8 a3)
{
  __int64 result; // x0
  _QWORD v4[5]; // [xsp+8h] [xbp-28h] BYREF

  v4[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  v4[1] = a3;
  v4[2] = 0;
  v4[3] = 0;
  result = wlan_cm_roam_cfg_set_value(a1, a2, 0x1Fu, (unsigned int *)v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
