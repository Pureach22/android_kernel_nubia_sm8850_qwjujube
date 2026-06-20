__int64 __fastcall venus_hfi_pm_work_handler(__int64 a1)
{
  __int64 v2; // x4
  int v3; // w0
  void *v4; // x0
  const char *v5; // x1

  core_lock(a1 - 6112);
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_91BB3, "high", 0xFFFFFFFFLL, "codec", "venus_hfi_pm_work_handler");
  v2 = *(unsigned int *)(a1 + 340);
  if ( (unsigned int)v2 >= 0xA )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_81A1C, "err ", 0xFFFFFFFFLL, "codec", v2);
    *(_DWORD *)(a1 + 340) = 0;
    msm_vidc_change_core_state(a1 - 6112, 3u, (__int64)"venus_hfi_pm_work_handler");
    msm_vidc_change_core_sub_state(a1 - 6112, 0, 0x40u, (__int64)"venus_hfi_pm_work_handler");
    msm_vidc_core_deinit_locked(a1 - 6112, 1);
    return core_unlock(a1 - 6112);
  }
  if ( is_core_state(a1 - 6112, 0) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      core_state_name(*(_DWORD *)(a1 - 2408));
      printk(&unk_86386, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_pm_work_handler");
    }
    return core_unlock(a1 - 6112);
  }
  v3 = _power_collapse(a1 - 6112, 0);
  if ( v3 == -16 )
  {
    *(_DWORD *)(a1 + 340) = 0;
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_88903, "high", 0xFFFFFFFFLL, "codec", "venus_hfi_pm_work_handler");
    goto LABEL_21;
  }
  if ( v3 == -11 )
  {
    ++*(_DWORD *)(a1 + 340);
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_809C6, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_pm_work_handler");
LABEL_21:
    _schedule_power_collapse_work(a1 - 6112);
    return core_unlock(a1 - 6112);
  }
  if ( v3 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return core_unlock(a1 - 6112);
    v4 = &unk_83B84;
    v5 = "err ";
LABEL_25:
    printk(v4, v5, 0xFFFFFFFFLL, "codec", "venus_hfi_pm_work_handler");
    return core_unlock(a1 - 6112);
  }
  *(_DWORD *)(a1 + 340) = 0;
  if ( *(_QWORD *)(a1 - 1824) )
    cancel_delayed_work(a1);
  if ( (msm_vidc_debug & 2) != 0 )
  {
    v4 = &unk_86DB4;
    v5 = "high";
    goto LABEL_25;
  }
  return core_unlock(a1 - 6112);
}
