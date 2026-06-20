__int64 __fastcall clk_branch2_init(__int64 a1)
{
  if ( !*(_QWORD *)(a1 + 88) )
    *(_QWORD *)(a1 + 88) = &clk_branch2_regmap_ops;
  return 0;
}
