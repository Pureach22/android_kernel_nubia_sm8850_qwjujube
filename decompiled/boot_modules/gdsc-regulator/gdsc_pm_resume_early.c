__int64 __fastcall gdsc_pm_resume_early(__int64 a1, __int64 a2)
{
  if ( pm_suspend_target_state == 3 )
    return restore_hw_trig_clk_dis(a1, a2);
  else
    return 0;
}
