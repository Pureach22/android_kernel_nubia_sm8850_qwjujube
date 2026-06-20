unsigned __int64 __fastcall clk_alpha_pll_postdiv_round_ro_rate(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 v6; // x8
  char v7; // w23
  char v8; // w22
  __int64 v9; // x0
  __int64 parent; // x0
  unsigned __int64 result; // x0
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 - 8);
  v12 = 0;
  regmap_read(*(_QWORD *)(a1 + 24), *(_DWORD *)(a1 - 16) + (unsigned int)*(unsigned __int8 *)(v6 + 5), &v12);
  v7 = __clz((v12 >> 8) & ~(unsigned int)(-1LL << *(_BYTE *)(a1 - 12)));
  v12 = (v12 >> 8) & ~(unsigned int)(-1LL << *(_BYTE *)(a1 - 12));
  v8 = 32 - v7;
  if ( (clk_hw_get_flags(a1) & 4) != 0 )
  {
    parent = clk_hw_get_parent(a1);
    if ( !parent )
    {
      result = -22;
      goto LABEL_6;
    }
    v9 = clk_hw_round_rate(parent, a2 << v8);
    *a3 = v9;
  }
  else
  {
    v9 = *a3;
  }
  result = (v9 + (unsigned __int64)(unsigned int)(1 << -v7) - 1) >> v8;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
