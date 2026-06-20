__int64 __fastcall msm_vidc_core_init(__int64 a1)
{
  unsigned int v2; // w20

  mutex_lock(a1 + 3856);
  if ( (core_in_valid_state(a1) & 1) != 0 )
  {
    v2 = 0;
  }
  else if ( (is_core_state(a1, 3) & 1) != 0 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      core_state_name(*(unsigned int *)(a1 + 3704));
      printk(&unk_86386, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_core_init");
    }
    v2 = -22;
  }
  else
  {
    if ( (unsigned int)msm_vidc_allow_core_state_change(a1, 1) != 1 && (msm_vidc_debug & 1) != 0 )
    {
      core_state_name(*(unsigned int *)(a1 + 3704));
      core_state_name(1);
      printk(&unk_87573, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_core_init");
    }
    msm_vidc_change_core_state(a1, 1, "msm_vidc_core_init");
    msm_vidc_change_core_sub_state(a1, 4, 0, "msm_vidc_core_init");
    msm_vidc_change_core_sub_state(a1, 16, 0, "msm_vidc_core_init");
    v2 = venus_hfi_core_init(a1);
    if ( v2 )
    {
      msm_vidc_change_core_state(a1, 3, "msm_vidc_core_init");
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_95625, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_core_init");
      msm_vidc_core_deinit_locked(a1, 1);
    }
  }
  mutex_unlock(a1 + 3856);
  return v2;
}
