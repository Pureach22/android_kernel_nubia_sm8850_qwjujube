__int64 __fastcall hfi_core_deallocate_shared_mem(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  __int64 v8; // x2
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x0
  __int64 v13; // x30
  void *v14; // x0
  __int64 v15; // x2

  v6 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_11:
      v13 = v6;
      v14 = &unk_1905C;
      v15 = 475;
LABEL_13:
      printk(v14, "hfi_core_deallocate_shared_mem", v15, v13, a5);
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_1E83A, "hfi_core_deallocate_shared_mem", 472, a4, a5);
    if ( !a1 )
      goto LABEL_11;
  }
  v8 = a1[3];
  if ( !v8 )
    goto LABEL_11;
  if ( (unsigned int)smmu_unmmap_for_fw(drv_data, a1[2], v8, a4, a5) )
  {
    v13 = v6;
    v14 = &unk_1AE43;
    v15 = 483;
    goto LABEL_13;
  }
  v11 = a1[1];
  if ( v11 )
    smmu_unmap_for_drv(v11, a1[3], v9, v10, a5);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "hfi_core_deallocate_shared_mem", 490, v10, a5);
  return 0;
}
