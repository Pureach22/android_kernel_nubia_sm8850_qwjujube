__int64 __fastcall clk_branch_disable(__int64 a1)
{
  return clk_branch_toggle(a1, 0, clk_branch_check_halt);
}
