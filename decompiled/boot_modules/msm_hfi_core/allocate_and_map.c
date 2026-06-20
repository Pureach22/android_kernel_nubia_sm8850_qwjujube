__int64 __fastcall allocate_and_map(_QWORD *a1, __int64 *a2, int a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x20
  unsigned __int64 v9; // x2
  unsigned int v10; // w0
  unsigned int v11; // w0
  __int64 v12; // x3
  __int64 v13; // x4
  int v15; // w24
  unsigned int v16; // w19
  __int64 v17; // x30
  unsigned int v18; // w20
  __int64 v19; // x2
  __int64 v20; // x3
  __int64 v21; // x4
  __int64 v22; // x0
  int v23; // w8

  v6 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a2 )
    {
LABEL_10:
      printk(&unk_1905C, "allocate_and_map", 66, v6, a5);
      return 4294967274LL;
    }
  }
  else
  {
    v15 = a3;
    printk(&unk_1E83A, "allocate_and_map", 63, a4, a5);
    a3 = v15;
    if ( !a2 )
      goto LABEL_10;
  }
  if ( !a3 )
    goto LABEL_10;
  v9 = (a3 + 4095) & 0xFFFFF000;
  a2[3] = v9;
  v10 = smmu_alloc_and_map_for_drv(a1, a2, v9, a2 + 1, 1);
  if ( v10 )
  {
    v16 = v10;
    printk(&unk_1B782, "allocate_and_map", 75, v6, v10);
    return v16;
  }
  else
  {
    v11 = smmu_mmap_for_fw((__int64)a1, *a2, a2 + 2, a2[3], 7);
    if ( v11 )
    {
      v17 = v6;
      v18 = v11;
      printk(&unk_1E041, "allocate_and_map", 84, v17, v11);
      v22 = a2[1];
      if ( v22 )
        smmu_unmap_for_drv(v22, a2[3], v19, v20, v21);
      v23 = msm_hfi_core_debug_level;
      a2[3] = 0;
      a2[1] = 0;
      if ( (~v23 & 0x10001) == 0 )
        printk(&unk_1C28B, "allocate_and_map", 98, v20, v21);
      return v18;
    }
    else
    {
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1C28B, "allocate_and_map", 88, v12, v13);
      return 0;
    }
  }
}
