__int64 __fastcall clk_rivian_evo_pll_recalc_rate(__int64 a1, __int64 a2)
{
  __int64 v3; // x9
  unsigned int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 - 40);
  v5 = 0;
  regmap_read(*(_QWORD *)(a1 + 24), *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(v3 + 1), &v5);
  _ReadStatusReg(SP_EL0);
  return v5 * a2;
}
