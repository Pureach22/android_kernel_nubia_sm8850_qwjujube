__int64 __fastcall deinit_smmu(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  _QWORD *v8; // x23
  __int64 v9; // x8
  __int64 v10; // x2
  unsigned int v11; // w0
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x9
  int v15; // w8
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v19; // x4
  unsigned int v20; // w20
  __int64 v21; // x19
  __int64 v22; // x20

  v6 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_19:
      printk(&unk_19CD1, "deinit_smmu", 431, v6, a5);
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_1E83A, "deinit_smmu", 428, a4, a5);
    if ( !a1 )
      goto LABEL_19;
  }
  v8 = *(_QWORD **)(a1 + 728);
  if ( !v8 )
    goto LABEL_19;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    v9 = *(_QWORD *)(a1 + 808);
    if ( !v9 )
    {
LABEL_21:
      printk(&unk_1905C, "hfi_deinit_fw_trace_mem", 351, v6, a5);
      v20 = -22;
LABEL_23:
      printk(&unk_1DC75, "deinit_smmu", 438, v6, v19);
      return v20;
    }
  }
  else
  {
    printk(&unk_1E83A, "hfi_deinit_fw_trace_mem", 348, a4, a5);
    v9 = *(_QWORD *)(a1 + 808);
    if ( !v9 )
      goto LABEL_21;
  }
  v10 = *(_QWORD *)(v9 + 24);
  if ( !v10 )
    goto LABEL_21;
  v11 = smmu_unmmap_for_fw(a1, *(_QWORD *)(v9 + 16), v10, a4, a5);
  if ( v11 )
  {
    v20 = v11;
    printk(&unk_1AE43, "hfi_deinit_fw_trace_mem", 359, v6, v13);
    goto LABEL_23;
  }
  v14 = *(_QWORD *)(a1 + 808);
  v15 = msm_hfi_core_debug_level;
  v16 = *(_QWORD *)(v14 + 8);
  if ( !v16 )
    goto LABEL_12;
  v17 = *(_QWORD *)(v14 + 24);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v21 = *(_QWORD *)(v14 + 8);
    v22 = *(_QWORD *)(v14 + 24);
    printk(&unk_1E83A, "smmu_unmap_for_drv", 162, v12, v13);
    v17 = v22;
    v16 = v21;
  }
  free_pages_exact(v16, v17);
  v15 = msm_hfi_core_debug_level;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
LABEL_12:
    if ( (~v15 & 0x10001) != 0 )
      goto LABEL_13;
LABEL_25:
    printk(&unk_1C28B, "hfi_deinit_fw_trace_mem", 367, v12, v13);
    if ( !*v8 )
      goto LABEL_15;
    goto LABEL_14;
  }
  printk(&unk_1C28B, "smmu_unmap_for_drv", 167, v12, v13);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    goto LABEL_25;
LABEL_13:
  if ( *v8 )
LABEL_14:
    rproc_put();
LABEL_15:
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "deinit_smmu", 445, v12, v13);
  return 0;
}
