__int64 __fastcall deinit_swi(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 v9; // x19
  __int64 v10; // x20
  __int64 v11; // x19
  __int64 v12; // x20
  __int64 v13; // x19
  __int64 v14; // x20
  __int64 v15; // x4
  __int64 v16; // x19
  __int64 v17; // x20

  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_14:
      printk(&unk_19CD1, "deinit_swi", 186, v5, a5);
      return 4294967274LL;
    }
  }
  else
  {
    v9 = a1;
    v10 = v5;
    printk(&unk_1E83A, "deinit_swi", 178, a4, a5);
    a1 = v9;
    v5 = v10;
    if ( !v9 )
      goto LABEL_14;
  }
  if ( !*(_QWORD *)a1 )
    goto LABEL_14;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !*(_QWORD *)(a1 + 768) )
      goto LABEL_6;
  }
  else
  {
    v11 = a1;
    v12 = v5;
    printk(&unk_1E83A, "unmap_mdss_register", 64, a4, a5);
    a1 = v11;
    v5 = v12;
    if ( !*(_QWORD *)(v11 + 768) )
      goto LABEL_6;
  }
  v13 = a1;
  v14 = v5;
  smmu_unmmap_for_fw(a1, *(_QWORD *)(a1 + 784), *(unsigned int *)(a1 + 776), a4, a5);
  *(_QWORD *)(v13 + 768) = 0;
  *(_DWORD *)(v13 + 776) = 0;
  *(_QWORD *)(v13 + 784) = 0;
  printk(&unk_1B14F, "unmap_mdss_register", 74, v14, v15);
  a1 = v13;
  v5 = v14;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_1C28B, "unmap_mdss_register", 76, a4, a5);
    a1 = v13;
    v5 = v14;
  }
LABEL_6:
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( *(_QWORD *)(a1 + 264) )
      goto LABEL_8;
  }
  else
  {
    v16 = a1;
    v17 = v5;
    printk(&unk_1E83A, "unmap_swi_register", 127, a4, a5);
    v5 = v17;
    if ( *(_QWORD *)(v16 + 264) )
    {
LABEL_8:
      memunmap();
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1C28B, "unmap_swi_register", 136, v6, v7);
      goto LABEL_10;
    }
  }
  printk(&unk_1AEB6, "unmap_swi_register", 130, v5, a5);
LABEL_10:
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "deinit_swi", 193, v6, v7);
  return 0;
}
