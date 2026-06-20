__int64 __fastcall smmu_mmap_for_fw(__int64 a1, __int64 a2, _QWORD *a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x22
  char v7; // w21
  __int64 v11; // x26
  __int64 v12; // x0
  unsigned int v13; // w0
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  int v17; // w8
  __int64 v19; // x26
  __int64 v20; // x30
  void *v21; // x0
  __int64 v22; // x2
  unsigned int v23; // w21

  v6 = v5;
  v7 = a5;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v19 = a1;
    printk(&unk_1E83A, "smmu_mmap_for_fw", 177, a4, a5);
    a1 = v19;
    if ( v19 )
      goto LABEL_3;
LABEL_13:
    v20 = v6;
    v21 = &unk_19CD1;
    v22 = 180;
LABEL_15:
    printk(v21, "smmu_mmap_for_fw", v22, v20, a5);
    return 4294967274LL;
  }
  if ( !a1 )
    goto LABEL_13;
LABEL_3:
  if ( !a3 )
    goto LABEL_13;
  v11 = *(_QWORD *)(a1 + 728);
  if ( !v11 )
    goto LABEL_13;
  v12 = *(_QWORD *)(v11 + 16);
  if ( !v12 )
  {
    v20 = v6;
    v21 = &unk_1DC42;
    v22 = 185;
    goto LABEL_15;
  }
  v13 = iommu_map(v12, *(_QWORD *)(v11 + 8), a2, a4, v7 & 7, 3264);
  if ( v13 )
  {
    v23 = v13;
    printk(&unk_1C69B, "smmu_mmap_for_fw", 207, v6, a2);
    return v23;
  }
  else
  {
    v16 = *(_QWORD *)(v11 + 8);
    *a3 = v16;
    v17 = msm_hfi_core_debug_level;
    if ( (~msm_hfi_core_debug_level & 0x10008) == 0 )
    {
      printk(&unk_1BF31, "smmu_mmap_for_fw", 213, a2, a4);
      v16 = *(_QWORD *)(v11 + 8);
      v17 = msm_hfi_core_debug_level;
    }
    *(_QWORD *)(v11 + 8) = v16 + a4;
    if ( (~v17 & 0x10001) == 0 )
      printk(&unk_1C28B, "smmu_mmap_for_fw", 218, v14, v15);
    return 0;
  }
}
