__int64 __fastcall hdd_adapter_check_duplicate_session(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0
  _QWORD v3[3]; // [xsp+8h] [xbp-18h] BYREF

  v3[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[1] = 0;
  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 24);
    if ( v1 )
      v1 = *(_QWORD *)(v1 + 16);
  }
  else
  {
    v1 = 0;
  }
  v3[0] = a1 + 1617;
  result = sme_check_for_duplicate_session(v1, v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
