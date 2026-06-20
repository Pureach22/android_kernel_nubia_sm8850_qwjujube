__int64 __fastcall clock_pm_restore_early(__int64 a1, __int64 a2)
{
  clk_restore_context(a1, a2);
  clk_restore_critical_clocks(a1);
  return 0;
}
