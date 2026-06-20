__int64 __fastcall msm_vidc_smmu_fault_handler(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0

  if ( (is_core_sub_state(a5, 16) & 1) != 0 && *(_QWORD *)(a5 + 4560) )
  {
    result = msm_vidc_check_ratelimit();
    if ( (_DWORD)result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_90A1A, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_smmu_fault_handler");
      return 0;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_916FE, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_smmu_fault_handler");
    mutex_lock(a5 + 3856);
    msm_vidc_change_core_sub_state(a5, 0, 16, "msm_vidc_smmu_fault_handler");
    mutex_unlock(a5 + 3856);
    ((void (__fastcall *)(__int64))msm_vidc_print_core_info)(a5);
    return 4294967258LL;
  }
  return result;
}
