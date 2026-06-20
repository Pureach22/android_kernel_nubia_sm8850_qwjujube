bool __fastcall hfpll_is_enabled(__int64 a1)
{
  unsigned int *v1; // x8
  int v2; // w8
  int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(unsigned int **)(a1 - 16);
  v4 = 0;
  regmap_read(*(_QWORD *)(a1 + 24), *v1, &v4);
  v2 = v4;
  _ReadStatusReg(SP_EL0);
  return (~v2 & 7) == 0;
}
