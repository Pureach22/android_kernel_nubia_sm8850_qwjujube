__int64 __fastcall kgsl_unlock_sgt(__int64 a1)
{
  __int64 result; // x0
  int v3; // [xsp+Ch] [xbp-14h] BYREF
  int v4; // [xsp+10h] [xbp-10h] BYREF
  int v5; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+18h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 7;
  v3 = 3;
  v4 = 10;
  do
    result = hyp_assign_table(a1, &v4, 1, &v3, &v5, 1);
  while ( (_DWORD)result == -11 );
  _ReadStatusReg(SP_EL0);
  return result;
}
