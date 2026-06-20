__int64 __fastcall clk_branch2_disable(__int64 a1)
{
  return clk_branch_toggle(a1, 0, clk_branch2_check_halt);
}
