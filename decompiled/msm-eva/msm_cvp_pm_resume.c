__int64 __fastcall msm_cvp_pm_resume(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( (msm_cvp_debug & 4) == 0 || msm_cvp_debug_out )
    return 0;
  printk(&unk_94187, "info", "msm_cvp_pm_resume", a4);
  return 0;
}
