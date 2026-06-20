__int64 __fastcall clk_hfpll_recalc_rate(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  unsigned int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 - 16);
  v4 = *(_QWORD *)(a1 + 24);
  v6 = 0;
  regmap_read(v4, *(unsigned int *)(v3 + 4), &v6);
  _ReadStatusReg(SP_EL0);
  return v6 * a2;
}
