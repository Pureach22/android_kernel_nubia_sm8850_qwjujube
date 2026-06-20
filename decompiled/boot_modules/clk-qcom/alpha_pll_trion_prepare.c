__int64 __fastcall alpha_pll_trion_prepare(__int64 a1)
{
  __int64 result; // x0
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  result = clk_prepare_regmap(a1);
  if ( !(_DWORD)result )
  {
    regmap_read(
      *(_QWORD *)(a1 + 24),
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 18LL),
      &v3);
    if ( (v3 & 0x4000000) != 0 )
    {
LABEL_5:
      result = 0;
      goto LABEL_6;
    }
    result = clk_trion_pll_enable(a1);
    if ( !(_DWORD)result )
    {
      clk_trion_pll_disable(a1);
      goto LABEL_5;
    }
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
