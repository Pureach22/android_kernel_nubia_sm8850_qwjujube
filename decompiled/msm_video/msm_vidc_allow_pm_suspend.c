__int64 __fastcall msm_vidc_allow_pm_suspend(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w19

  if ( (core_in_valid_state(a1) & 1) != 0 )
  {
    v2 = a1;
    v3 = 1;
    if ( (is_core_sub_state(v2, 1) & 1) == 0 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_96D24, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_allow_pm_suspend");
      return 4;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      core_state_name(*(unsigned int *)(a1 + 3704));
      printk(&unk_86386, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_allow_pm_suspend");
    }
    return 0;
  }
  return v3;
}
