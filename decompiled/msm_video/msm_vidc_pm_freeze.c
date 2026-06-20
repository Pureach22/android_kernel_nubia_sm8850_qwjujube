__int64 __fastcall msm_vidc_pm_freeze(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x19
  void *v3; // x0

  if ( !result )
    return result;
  if ( !*(_QWORD *)(result + 136) )
    return 0;
  v1 = result;
  if ( !is_video_device(result) )
    return 0;
  v2 = *(_QWORD *)(v1 + 152);
  if ( v2 )
  {
    if ( !*(_QWORD *)(v2 + 4672) )
      return 4294967201LL;
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_7FB92, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_freeze");
    core_lock(v2);
    if ( *(_QWORD *)(v2 + 3528) == v2 + 3528 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_850C8, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_deinit_locked");
      if ( !(unsigned int)msm_vidc_core_deinit_locked(v2, 1) )
      {
        core_unlock(v2);
        return 0;
      }
      if ( (msm_vidc_debug & 1) == 0 )
        goto LABEL_22;
      v3 = &unk_97B13;
    }
    else
    {
      if ( (msm_vidc_debug & 1) == 0 )
      {
LABEL_22:
        core_unlock(v2);
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_8CECB, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_freeze");
        return 4294967171LL;
      }
      v3 = &unk_900CD;
    }
    printk(v3, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_deinit_locked");
    goto LABEL_22;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_807F4, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_pm_freeze");
  return 4294967274LL;
}
