unsigned __int64 __fastcall clk_alpha_pll_postdiv_recalc_rate(__int64 a1, unsigned __int64 a2)
{
  __int64 v4; // x8
  unsigned int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 - 8);
  v6 = 0;
  regmap_read(*(_QWORD *)(a1 + 24), *(_DWORD *)(a1 - 16) + (unsigned int)*(unsigned __int8 *)(v4 + 5), &v6);
  _ReadStatusReg(SP_EL0);
  return a2 >> (32 - (unsigned __int8)__clz((0xFFFFFFFFFFFFFFFFLL >> -*(_BYTE *)(a1 - 12)) & (v6 >> 8)));
}
