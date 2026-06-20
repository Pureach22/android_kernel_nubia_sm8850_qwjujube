__int64 __fastcall alpha_pll_lucid_5lpe_prepare(__int64 a1)
{
  __int64 result; // x0
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  result = clk_prepare_regmap(a1);
  if ( !(_DWORD)result )
  {
    regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), &v3);
    if ( (v3 & 0x800) != 0 )
    {
LABEL_6:
      result = 0;
      goto LABEL_8;
    }
    if ( !clk_hw_get_parent(a1) )
    {
      result = 4294967274LL;
      goto LABEL_8;
    }
    result = alpha_pll_lucid_5lpe_enable(a1);
    if ( !(_DWORD)result )
    {
      alpha_pll_lucid_5lpe_disable(a1);
      goto LABEL_6;
    }
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
