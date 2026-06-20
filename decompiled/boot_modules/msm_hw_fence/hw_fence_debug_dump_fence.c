__int64 __fastcall hw_fence_debug_dump_fence(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 result; // x0
  _QWORD v5[5]; // [xsp+8h] [xbp-38h] BYREF
  __int16 v6; // [xsp+30h] [xbp-10h]
  __int64 v7; // [xsp+38h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  memset(v5, 0, sizeof(v5));
  result = dump_fence_helper(a1, a2, v5, a3, a4);
  _ReadStatusReg(SP_EL0);
  return result;
}
