__int64 __fastcall msm_vidc_core_init_wait(__int64 a1)
{
  unsigned int v2; // w20
  int v4; // w22
  int i; // w20

  mutex_lock(a1 + 3856);
  if ( (is_core_state(a1, 2) & 1) == 0 )
  {
    if ( (is_core_state(a1, 0) & 1) != 0 || (is_core_state(a1, 3) & 1) != 0 )
    {
      if ( (msm_vidc_debug & 1) == 0 )
        goto LABEL_6;
    }
    else
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_89C96, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_core_init_wait");
      v4 = (int)*(_QWORD *)(a1 + 4352) / 10;
      if ( v4 >= 1 )
      {
        for ( i = 0; i != v4; ++i )
        {
          if ( *(_DWORD *)(a1 + 3704) != 1 )
            break;
          mutex_unlock(a1 + 3856);
          msleep_interruptible(10);
          mutex_lock(a1 + 3856);
        }
      }
      if ( (msm_vidc_debug & 2) != 0 )
      {
        core_state_name(*(unsigned int *)(a1 + 3704));
        printk(&unk_890EA, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_core_init_wait");
      }
      if ( (is_core_state(a1, 2) & 1) != 0 )
      {
        if ( (msm_vidc_debug & 2) != 0 )
        {
          printk(&unk_8CC20, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_core_init_wait");
          v2 = 0;
          goto LABEL_7;
        }
        goto LABEL_2;
      }
      if ( (is_core_state(a1, 1) & 1) != 0 )
      {
        if ( (msm_vidc_debug & 2) != 0 )
        {
          core_state_name(*(unsigned int *)(a1 + 3704));
          printk(&unk_84EF9, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_core_init_wait");
        }
        msm_vidc_change_core_state(a1, 3, "msm_vidc_core_init_wait");
        msm_vidc_change_core_sub_state(a1, 0, 64, "msm_vidc_core_init_wait");
        msm_vidc_core_deinit_locked(a1, 1);
        goto LABEL_6;
      }
      if ( (msm_vidc_debug & 1) == 0 )
      {
LABEL_6:
        v2 = -22;
        goto LABEL_7;
      }
    }
    core_state_name(*(unsigned int *)(a1 + 3704));
    printk(&unk_86386, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_core_init_wait");
    goto LABEL_6;
  }
LABEL_2:
  v2 = 0;
LABEL_7:
  mutex_unlock(a1 + 3856);
  return v2;
}
