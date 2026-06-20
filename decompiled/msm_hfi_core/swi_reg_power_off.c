__int64 __fastcall swi_reg_power_off(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x8
  __int64 v7; // x21
  int v8; // w0
  void *v9; // x0
  __int64 v10; // x2
  unsigned int v12; // w21
  __int64 v13; // x22
  __int64 v14; // x23

  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( a1 < 4 )
      goto LABEL_3;
LABEL_12:
    printk(&unk_1D5EB, "swi_reg_power_off", 259, v5, a1);
    return 4294967274LL;
  }
  v12 = a1;
  v13 = a2;
  v14 = v5;
  printk(&unk_1E83A, "swi_reg_power_off", 256, a4, a5);
  a2 = v13;
  v5 = v14;
  a1 = v12;
  if ( v12 >= 4 )
    goto LABEL_12;
LABEL_3:
  if ( !a2 )
  {
    printk(&unk_19CD1, "swi_reg_power_off", 264, v5, a5);
    return 4294967274LL;
  }
  v6 = a2 + 176LL * a1;
  v7 = *(_QWORD *)(v6 + 88);
  if ( v7 )
  {
    if ( !*(_QWORD *)(v6 + 128) )
    {
      printk(&unk_19D08, "swi_reg_power_off", 276, v5, a1);
      return 4294967274LL;
    }
    v8 = readl_relaxed((unsigned int *)(v7 + 8));
    writel_relaxed(v8 | 2, (unsigned int *)(v7 + 8));
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    {
      v9 = &unk_1C28B;
      v10 = 286;
LABEL_16:
      printk(v9, "swi_reg_power_off", v10, a4, a5);
    }
  }
  else if ( (~msm_hfi_core_debug_level & 0x10004) == 0 )
  {
    v9 = &unk_1A6DE;
    v10 = 269;
    goto LABEL_16;
  }
  return 0;
}
