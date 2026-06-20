__int64 __fastcall hfi_core_allocate_shared_mem(__int64 *a1, unsigned int a2, unsigned int a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x20
  unsigned int v7; // w21
  _QWORD *v10; // x0
  unsigned int v11; // w0
  unsigned int v12; // w0
  __int64 v13; // x3
  __int64 v14; // x4
  unsigned int v16; // w25
  __int64 v17; // x30
  void *v18; // x0
  __int64 v19; // x2
  unsigned int v20; // w19
  __int64 v21; // x30
  unsigned int v22; // w20
  __int64 v23; // x2
  __int64 v24; // x3
  __int64 v25; // x4
  __int64 v26; // x0
  int v27; // w8

  v6 = v5;
  v7 = a4;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_11:
      v17 = v6;
      v18 = &unk_1905C;
      v19 = 427;
LABEL_13:
      printk(v18, "hfi_core_allocate_shared_mem", v19, v17, a5);
      return 4294967274LL;
    }
  }
  else
  {
    v16 = a2;
    printk(&unk_1E83A, "hfi_core_allocate_shared_mem", 424, a4, a5);
    a2 = v16;
    if ( !a1 )
      goto LABEL_11;
  }
  if ( !a2 )
    goto LABEL_11;
  if ( (a2 & 0xFFF) != 0 )
  {
    v17 = v6;
    v18 = &unk_1DDEB;
    v19 = 432;
    goto LABEL_13;
  }
  v10 = (_QWORD *)drv_data;
  a1[3] = a2;
  v11 = smmu_alloc_and_map_for_drv(v10, a1, a2, a1 + 1, a3);
  if ( v11 )
  {
    v20 = v11;
    printk(&unk_1B782, "hfi_core_allocate_shared_mem", 441, v6, v11);
    return v20;
  }
  else
  {
    v12 = smmu_mmap_for_fw(drv_data, *a1, a1 + 2, a1[3], v7);
    if ( v12 )
    {
      v21 = v6;
      v22 = v12;
      printk(&unk_1E041, "hfi_core_allocate_shared_mem", 449, v21, v12);
      v26 = a1[1];
      if ( v26 )
        smmu_unmap_for_drv(v26, a1[3], v23, v24, v25);
      v27 = msm_hfi_core_debug_level;
      a1[3] = 0;
      a1[1] = 0;
      if ( (~v27 & 0x10001) == 0 )
        printk(&unk_1C28B, "hfi_core_allocate_shared_mem", 463, v24, v25);
      return v22;
    }
    else
    {
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1C28B, "hfi_core_allocate_shared_mem", 453, v13, v14);
      return 0;
    }
  }
}
