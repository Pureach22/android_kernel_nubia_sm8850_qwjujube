__int64 __fastcall clk_branch2_hw_ctl_enable(__int64 a1)
{
  if ( clk_hw_get_parent(a1) && (clk_hw_is_prepared() & 1) != 0 )
    return clk_enable_regmap(a1);
  else
    return 4294967274LL;
}
