__int64 __fastcall unmap_res(__int64 a1, _QWORD *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x20
  __int64 v8; // x2
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x0
  __int64 v13; // x23
  __int64 v14; // x30
  void *v15; // x0
  __int64 v16; // x2

  v6 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a2 )
    {
LABEL_11:
      v14 = v6;
      v15 = &unk_1905C;
      v16 = 111;
LABEL_13:
      printk(v15, "unmap_res", v16, v14, a5);
      return 4294967274LL;
    }
  }
  else
  {
    v13 = a1;
    printk(&unk_1E83A, "unmap_res", 108, a4, a5);
    a1 = v13;
    if ( !a2 )
      goto LABEL_11;
  }
  v8 = a2[3];
  if ( !v8 )
    goto LABEL_11;
  if ( (unsigned int)smmu_unmmap_for_fw(a1, a2[2], v8, a4, a5) )
  {
    v14 = v6;
    v15 = &unk_1AE43;
    v16 = 119;
    goto LABEL_13;
  }
  v11 = a2[1];
  if ( v11 )
    smmu_unmap_for_drv(v11, a2[3], v9, v10, a5);
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "unmap_res", 126, v10, a5);
  return 0;
}
