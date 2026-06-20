__int64 __fastcall smmu_mmap_debug_trace_mem_for_fw(__int64 a1, __int64 a2, _QWORD *a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x21
  __int64 v10; // x25
  __int64 v11; // x0
  unsigned int v12; // w0
  __int64 v14; // x25
  __int64 v15; // x30
  void *v16; // x0
  __int64 v17; // x2
  __int64 v18; // x30
  unsigned int v19; // w21
  __int64 v20; // x3
  __int64 v21; // x4

  v6 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v14 = a1;
    printk(&unk_1E83A, "smmu_mmap_debug_trace_mem_for_fw", 252, a4, a5);
    a1 = v14;
    if ( v14 )
      goto LABEL_3;
LABEL_10:
    v15 = v6;
    v16 = &unk_19CD1;
    v17 = 255;
LABEL_12:
    printk(v16, "smmu_mmap_debug_trace_mem_for_fw", v17, v15, a5);
    return 4294967274LL;
  }
  if ( !a1 )
    goto LABEL_10;
LABEL_3:
  if ( !a3 )
    goto LABEL_10;
  v10 = *(_QWORD *)(a1 + 728);
  if ( !v10 )
    goto LABEL_10;
  v11 = *(_QWORD *)(v10 + 16);
  if ( !v11 )
  {
    v15 = v6;
    v16 = &unk_1DC42;
    v17 = 260;
    goto LABEL_12;
  }
  v12 = iommu_map(v11, *(_QWORD *)(v10 + 8) + 4259840LL, a2, a4, 3, 3264);
  if ( v12 )
  {
    v18 = v6;
    v19 = v12;
    printk(&unk_1C69B, "smmu_mmap_debug_trace_mem_for_fw", 274, v18, a2);
    return v19;
  }
  else
  {
    *a3 = *(_QWORD *)(v10 + 8) + 4259840LL;
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    {
      printk(&unk_1C87D, "smmu_mmap_debug_trace_mem_for_fw", 281, a2, a4);
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1C28B, "smmu_mmap_debug_trace_mem_for_fw", 283, v20, v21);
    }
    return 0;
  }
}
