__int64 __fastcall clk_branch_debug_init(__int64 a1, __int64 a2)
{
  clk_common_debug_init();
  return clk_debug_measure_add(a1, a2);
}
