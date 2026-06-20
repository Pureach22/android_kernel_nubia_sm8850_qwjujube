__int64 __fastcall msm_vidc_pm_resume(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x19

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
        if ( (msm_vidc_debug & 2) != 0 )
        {
          printk(&unk_8C295, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_resume");
          if ( *(_QWORD *)(v2 + 4704) )
          {
LABEL_7:
            if ( pm_suspend_target_state == 3 )
            {
              if ( (msm_vidc_debug & 2) != 0 )
                printk(&unk_82501, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_resume");
              return 0;
            }
          }
        }
        else if ( *(_QWORD *)(v2 + 4704) )
        {
          goto LABEL_7;
        }
        core_lock(v2);
        msm_vidc_change_core_sub_state(v2, 4, 0, "msm_vidc_pm_resume");
        core_unlock(v2);
        return 0;
      }
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_807F4, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_resume");
      return 4294967274LL;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
