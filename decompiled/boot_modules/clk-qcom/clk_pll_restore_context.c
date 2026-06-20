__int64 __fastcall clk_pll_restore_context(__int64 result)
{
  __int64 v1; // x8
  int v2; // w9
  unsigned int *v3; // x2

  v1 = *(_QWORD *)(result - 40);
  if ( v1 )
  {
    v2 = (int)(v1 - (_QWORD)&clk_alpha_pll_regs) / 25;
    v3 = *(unsigned int **)(result - 32);
    if ( !v3 )
      return result;
  }
  else
  {
    v2 = -22;
    v3 = *(unsigned int **)(result - 32);
    if ( !v3 )
      return result;
  }
  if ( v2 > 9 )
  {
    if ( v2 <= 13 )
    {
      if ( v2 == 10 || v2 == 12 )
        return clk_lucid_evo_pll_configure(result - 48, *(_QWORD *)(result + 24));
    }
    else
    {
      if ( v2 == 14 || v2 == 15 )
        return clk_rivian_evo_pll_configure(result - 48, *(_QWORD *)(result + 24));
      if ( v2 == 20 )
        return clk_regera_pll_configure(result - 48, *(_QWORD *)(result + 24));
    }
  }
  else if ( v2 > 5 )
  {
    switch ( v2 )
    {
      case 6:
        return clk_trion_pll_configure(result - 48, *(_QWORD *)(result + 24));
      case 7:
        return clk_agera_pll_configure(result - 48, *(_QWORD *)(result + 24));
      case 8:
        return clk_zonda_pll_configure(result - 48, *(_QWORD *)(result + 24));
    }
  }
  else
  {
    if ( (unsigned int)v2 < 2 )
      return clk_alpha_pll_configure((unsigned int *)(result - 48), *(_QWORD *)(result + 24), v3);
    if ( v2 == 5 )
      return clk_fabia_pll_configure(result - 48, *(_QWORD *)(result + 24));
  }
  return printk(&unk_29286);
}
