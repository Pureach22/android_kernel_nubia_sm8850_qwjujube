__int64 __fastcall adreno_prop_ucode_version(__int64 a1, __int64 a2)
{
  int v2; // w10
  __int64 result; // x0
  _DWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 14320);
  v4[0] = *(_DWORD *)(a1 + 14288);
  v4[1] = v2;
  result = copy_prop(a2, v4, 8);
  _ReadStatusReg(SP_EL0);
  return result;
}
