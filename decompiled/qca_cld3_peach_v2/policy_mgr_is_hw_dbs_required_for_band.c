bool __fastcall policy_mgr_is_hw_dbs_required_for_band(__int64 a1, int a2)
{
  _BOOL8 result; // x0
  __int64 v4; // [xsp+8h] [xbp-18h] BYREF
  int v5; // [xsp+10h] [xbp-10h]
  __int64 v6; // [xsp+18h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  v4 = 0;
  result = (unsigned int)policy_mgr_get_hw_dbs_nss(a1, (int *)&v4) && (unsigned int)v4 >= HIDWORD(v4) && (v5 & a2) == 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
