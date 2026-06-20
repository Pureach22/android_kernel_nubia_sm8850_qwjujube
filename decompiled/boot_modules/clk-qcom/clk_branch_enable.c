__int64 __fastcall clk_branch_enable(__int64 a1)
{
  return clk_branch_toggle(a1, 1, clk_branch_check_halt);
}
