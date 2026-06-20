__int64 __fastcall zcomp_decompress(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x0
  __int64 result; // x0
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 8);
  v6 = 4096;
  result = crypto_comp_decompress(v4, a2, a3, a4, &v6);
  _ReadStatusReg(SP_EL0);
  return result;
}
