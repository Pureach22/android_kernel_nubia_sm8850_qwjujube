__int64 __fastcall clock_pm_resume_early(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x1

  if ( pm_suspend_target_state != 3 )
    return 0;
  if ( (*(_WORD *)(a1 + 488) & 7) == 0 )
  {
    result = _pm_runtime_resume(a1, 4);
    if ( (result & 0x80000000) != 0 )
      return result;
    clk_restore_context(result, v3);
  }
  clk_restore_critical_clocks(a1);
  if ( (*(_WORD *)(a1 + 488) & 7) == 0 )
    _pm_runtime_idle(a1, 4);
  return 0;
}
