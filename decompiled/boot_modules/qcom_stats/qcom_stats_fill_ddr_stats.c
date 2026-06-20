__int64 __fastcall qcom_stats_fill_ddr_stats(__int64 a1, __int64 a2, unsigned int *a3)
{
  unsigned int v6; // w0
  __int64 v7; // x1
  int v8; // w24
  __int64 v9; // x21
  __int64 v10; // x23
  void *v11; // x22
  __int64 v12; // x0
  int v13; // w0
  __int64 v14; // x27

  v6 = readl_relaxed((unsigned int *)(a1 + 4));
  *a3 = v6;
  if ( v6 > 0x14 )
  {
    v11 = &unk_A209;
LABEL_10:
    printk(v11, v7);
    return 0;
  }
  if ( v6 )
  {
    v8 = 0;
    v9 = 0;
    v10 = a1 + 16;
    v11 = &unk_A1E8;
    while ( 1 )
    {
      v13 = readl_relaxed((unsigned int *)(v10 - 4));
      v14 = a2 + 32LL * v8;
      *(_DWORD *)(v14 + 4) = v13;
      if ( v8 >= 4 && !v13 && (*(_BYTE *)(*(_QWORD *)(drv + 8) + 38LL) & 1) != 0 )
        break;
      *(_DWORD *)v14 = readl_relaxed((unsigned int *)(v10 - 8));
      *(_QWORD *)(v14 + 8) = 3735936685LL;
      *(_QWORD *)(v14 + 16) = 3735936685LL;
      v12 = readq_relaxed(v10);
      *(_QWORD *)(v14 + 24) = v12;
      ++v8;
      v9 += v12;
      v10 += 16;
      if ( v8 >= *a3 )
        return v9;
    }
    goto LABEL_10;
  }
  return 0;
}
