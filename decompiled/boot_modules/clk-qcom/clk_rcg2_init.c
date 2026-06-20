__int64 __fastcall clk_rcg2_init(__int64 a1)
{
  if ( !*(_QWORD *)(a1 + 88) )
    *(_QWORD *)(a1 + 88) = clk_rcg2_regmap_ops;
  return 0;
}
