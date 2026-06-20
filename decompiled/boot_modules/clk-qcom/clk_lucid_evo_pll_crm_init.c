__int64 __fastcall clk_lucid_evo_pll_crm_init(__int64 a1)
{
  if ( !*(_QWORD *)(a1 + 88) )
    *(_QWORD *)(a1 + 88) = &clk_lucid_evo_pll_crm_regmap_ops;
  return 0;
}
