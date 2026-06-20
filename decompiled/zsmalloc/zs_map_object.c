__int64 __fastcall zs_map_object(__int64 a1, __int64 *a2, int a3)
{
  __int64 result; // x0
  char v4; // [xsp+7h] [xbp-9h] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = zs_map_object(a1, a2, a3, &v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
