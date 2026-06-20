__int64 __fastcall swi_setup_resources(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  _QWORD *v7; // x22
  __int64 v8; // x23
  int v9; // w0
  void *v10; // x0
  __int64 v11; // x2
  __int64 v13; // x22
  __int64 v14; // x23

  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( a1 < 4 )
      goto LABEL_3;
LABEL_13:
    printk(&unk_1D5EB, "swi_setup_resources", 207, v5, a1);
    return 4294967274LL;
  }
  v13 = a2;
  v14 = v5;
  printk(&unk_1E83A, "swi_setup_resources", 204, a4, a5);
  a2 = v13;
  v5 = v14;
  if ( a1 >= 4 )
    goto LABEL_13;
LABEL_3:
  if ( !a2 )
  {
    printk(&unk_19CD1, "swi_setup_resources", 212, v5, a5);
    return 4294967274LL;
  }
  v7 = (_QWORD *)(a2 + 176LL * a1);
  v8 = v7[11];
  if ( v8 )
  {
    if ( !v7[16] )
    {
      printk(&unk_19D08, "swi_setup_resources", 224, v5, a1);
      return 4294967274LL;
    }
    v9 = readl_relaxed(v8 + 12);
    writel_relaxed(v9 | 0x1000001u, v8 + 12);
    writel_relaxed(0, v8 + 16);
    writel_relaxed(*((unsigned int *)v7 + 32), v8 + 20);
    if ( (~msm_hfi_core_debug_level & 0x10002) != 0 )
    {
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      {
LABEL_8:
        v10 = &unk_1C28B;
        v11 = 245;
LABEL_19:
        printk(v10, "swi_setup_resources", v11, a4, a5);
      }
    }
    else
    {
      printk(&unk_1C2E5, "swi_setup_resources", 243, a1, v7[10]);
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        goto LABEL_8;
    }
  }
  else if ( (~msm_hfi_core_debug_level & 0x10004) == 0 )
  {
    v10 = &unk_1AE6F;
    v11 = 217;
    goto LABEL_19;
  }
  return 0;
}
