__int64 __fastcall msm_vidc_pm_suspend(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x19
  int v3; // w0
  char v4; // w8
  void *v5; // x0
  unsigned int v6; // w20
  unsigned int v7; // w0

  if ( result )
  {
    if ( *(_QWORD *)(result + 136) )
    {
      v1 = result;
      if ( !is_video_device(result) )
        return 0;
      v2 = *(_QWORD *)(v1 + 152);
      if ( v2 )
      {
        core_lock(v2);
        v3 = msm_vidc_allow_pm_suspend(v2);
        if ( v3 != 1 )
        {
          if ( v3 != 4 )
          {
            if ( (msm_vidc_debug & 2) != 0 )
              printk(&unk_844EC, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_suspend");
            goto LABEL_26;
          }
          if ( (msm_vidc_debug & 2) != 0 )
            printk(&unk_824CC, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_suspend");
          goto LABEL_9;
        }
        if ( (msm_vidc_debug & 2) != 0 )
        {
          printk(&unk_8C295, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_suspend");
          if ( !*(_QWORD *)(v2 + 4704) )
            goto LABEL_34;
        }
        else if ( !*(_QWORD *)(v2 + 4704) )
        {
          goto LABEL_34;
        }
        if ( pm_suspend_target_state == 3 )
        {
          v4 = msm_vidc_debug;
          if ( (msm_vidc_debug & 2) != 0 )
          {
            printk(&unk_959D6, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_suspend");
            v4 = msm_vidc_debug;
          }
          if ( *(_QWORD *)(v2 + 3528) == v2 + 3528 )
          {
            if ( (v4 & 2) != 0 )
              printk(&unk_850C8, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_deinit_locked");
            if ( !(unsigned int)msm_vidc_core_deinit_locked(v2, 1) )
              goto LABEL_26;
            if ( (msm_vidc_debug & 1) != 0 )
            {
              v5 = &unk_97B13;
LABEL_39:
              printk(v5, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_deinit_locked");
              if ( (msm_vidc_debug & 1) != 0 )
              {
                printk(&unk_8B811, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_suspend");
                v6 = -125;
                goto LABEL_27;
              }
            }
          }
          else if ( (v4 & 1) != 0 )
          {
            v5 = &unk_900CD;
            goto LABEL_39;
          }
          v6 = -125;
          goto LABEL_27;
        }
LABEL_34:
        v7 = msm_vidc_suspend();
        if ( v7 == -95 )
          goto LABEL_26;
        if ( v7 )
        {
          v6 = v7;
          if ( (msm_vidc_debug & 1) != 0 )
            printk(&unk_8DB09, "err ", 0xFFFFFFFFLL, "codec", v7);
          goto LABEL_27;
        }
LABEL_9:
        msm_vidc_change_core_sub_state(v2, 0, 4, "msm_vidc_pm_suspend");
LABEL_26:
        v6 = 0;
LABEL_27:
        core_unlock(v2);
        return v6;
      }
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_807F4, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_suspend");
      return 4294967274LL;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
