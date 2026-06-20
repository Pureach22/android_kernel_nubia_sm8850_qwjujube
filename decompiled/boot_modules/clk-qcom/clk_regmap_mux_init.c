__int64 __fastcall clk_regmap_mux_init(__int64 a1)
{
  if ( !*(_QWORD *)(a1 + 88) )
    *(_QWORD *)(a1 + 88) = &clk_regmap_mux_regmap_ops;
  return 0;
}
