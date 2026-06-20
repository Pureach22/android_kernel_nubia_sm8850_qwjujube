__int64 __fastcall clk_alpha_pll_zonda_init(__int64 a1)
{
  if ( !*(_QWORD *)(a1 + 88) )
    *(_QWORD *)(a1 + 88) = &clk_alpha_pll_zonda_regmap_ops;
  return 0;
}
