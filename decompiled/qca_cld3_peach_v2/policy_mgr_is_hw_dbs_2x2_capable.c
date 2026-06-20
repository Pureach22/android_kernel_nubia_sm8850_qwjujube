bool __fastcall policy_mgr_is_hw_dbs_2x2_capable(__int64 a1)
{
  _BOOL8 result; // x0
  __int64 v2; // [xsp+8h] [xbp-18h] BYREF
  int v3; // [xsp+10h] [xbp-10h]
  __int64 v4; // [xsp+18h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  v2 = 0;
  result = (unsigned int)policy_mgr_get_hw_dbs_nss(a1, &v2) >= 2 && (_DWORD)v2 == HIDWORD(v2);
  _ReadStatusReg(SP_EL0);
  return result;
}
