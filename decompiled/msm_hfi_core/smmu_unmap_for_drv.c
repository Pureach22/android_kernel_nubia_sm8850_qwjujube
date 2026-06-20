__int64 __fastcall smmu_unmap_for_drv(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x21

  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !result )
      goto LABEL_4;
    goto LABEL_3;
  }
  v5 = result;
  printk(&unk_1E83A, "smmu_unmap_for_drv", 162, a4, a5);
  result = v5;
  if ( v5 )
LABEL_3:
    result = free_pages_exact();
LABEL_4:
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    return printk(&unk_1C28B, "smmu_unmap_for_drv", 167, a4, a5);
  return result;
}
