bool __fastcall policy_mgr_is_dual_mac_disabled_in_ini(__int64 a1)
{
  int v1; // w8
  unsigned __int8 v3[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 1;
  policy_mgr_get_dual_mac_feature(a1, v3);
  v1 = v3[0];
  _ReadStatusReg(SP_EL0);
  return (unsigned int)(v1 - 1) < 3;
}
