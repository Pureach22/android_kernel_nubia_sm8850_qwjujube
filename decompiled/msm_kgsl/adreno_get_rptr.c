__int64 __fastcall adreno_get_rptr(__int64 a1)
{
  __int64 v1; // x8
  unsigned int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(int *)(a1 + 28);
  v3 = 0;
  kgsl_sharedmem_readl(*(_QWORD *)(a1 - 1320LL * (int)v1 - 14304), &v3, 32 * v1);
  _ReadStatusReg(SP_EL0);
  return v3;
}
