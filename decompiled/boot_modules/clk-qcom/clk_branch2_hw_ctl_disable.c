__int64 __fastcall clk_branch2_hw_ctl_disable(__int64 a1)
{
  __int64 result; // x0

  result = clk_hw_get_parent(a1);
  if ( result )
    return clk_disable_regmap(a1);
  return result;
}
