__int64 __fastcall ipa3_allocate_nat_device(__int64 a1)
{
  __int64 result; // x0
  _QWORD v3[3]; // [xsp+8h] [xbp-18h] BYREF

  v3[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = *(_QWORD *)(a1 + 32);
  v3[1] = 0;
  result = ipa3_allocate_nat_table(v3);
  if ( !(_DWORD)result )
    *(_QWORD *)(a1 + 40) = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
