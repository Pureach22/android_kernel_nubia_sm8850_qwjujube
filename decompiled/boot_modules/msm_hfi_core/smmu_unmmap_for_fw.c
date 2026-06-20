__int64 __fastcall smmu_unmmap_for_fw(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v11; // x23
  __int64 v12; // x24
  void *v13; // x0
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4

  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_8:
      v13 = &unk_19CD1;
      v14 = 229;
LABEL_10:
      printk(v13, "smmu_unmmap_for_fw", v14, v5, a5);
      return 4294967274LL;
    }
  }
  else
  {
    v11 = a1;
    v12 = v5;
    printk(&unk_1E83A, "smmu_unmmap_for_fw", 226, a4, a5);
    a1 = v11;
    v5 = v12;
    if ( !v11 )
      goto LABEL_8;
  }
  v8 = *(_QWORD *)(a1 + 728);
  if ( !v8 )
    goto LABEL_8;
  v9 = *(_QWORD *)(v8 + 16);
  if ( !v9 )
  {
    v13 = &unk_1DC42;
    v14 = 234;
    goto LABEL_10;
  }
  iommu_unmap(v9, a2, a3);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_1DFBE, "smmu_unmmap_for_fw", 240, a2, a3);
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1C28B, "smmu_unmmap_for_fw", 242, v15, v16);
  }
  return 0;
}
