unsigned __int64 __fastcall kgsl_iommu_context_clear_fsr(unsigned __int64 result, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x21
  unsigned int v5; // w8
  int v6; // w9
  __int64 v7; // x21
  unsigned int v8; // w8
  int v9; // w9
  int v10; // w0
  char v11; // w10
  __int64 v12; // x21
  unsigned int v13; // w8
  int v14; // w9
  int v15; // w0
  char v16; // w10
  int v17; // w0
  __int64 v18; // x22
  int v19; // w21
  unsigned int v20; // w8
  int v21; // w9
  int v22; // w0
  char v23; // w10
  int v24; // w0
  char v25; // w10
  int v26; // w0
  int v27; // w21

  v3 = result;
  if ( (*(_BYTE *)(a2 + 32) & 1) != 0 )
    goto LABEL_2;
  if ( (*(_QWORD *)(result + 48) & 0x100) != 0 && (*(_QWORD *)(result + 56) & 2) != 0 )
  {
    kgsl_iommu_enable_clk(result);
    v7 = *(_QWORD *)(a2 + 24);
    v8 = *(_DWORD *)(v7 + 1020);
    if ( v8 )
    {
      v9 = *(_DWORD *)(v7 + 1024);
    }
    else
    {
      v24 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v7 + 960) + 36LL));
      v25 = v24 < 0 ? 16 : 12;
      v9 = v24 < 0 ? 0x10000 : 4096;
      v8 = 2 << (((unsigned int)v24 >> 28) & 7) << v25;
      *(_DWORD *)(v7 + 1024) = v9;
      *(_DWORD *)(v7 + 1020) = v8;
    }
    v26 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v7 + 960) + v8 + (unsigned int)(*(_DWORD *)(a2 + 16) * v9) + 88LL));
    __dsb(0xDu);
    v27 = v26;
    result = kgsl_iommu_disable_clk(v3);
    if ( (v27 & 0xFFFFF9FF) != 0 )
    {
LABEL_2:
      kgsl_iommu_enable_clk(v3);
      if ( (unsigned int)__ratelimit(&kgsl_iommu_context_clear_fsr__rs, "kgsl_iommu_context_clear_fsr") )
        dev_err(*(_QWORD *)(v3 - 56), "Clearing pagefault bits in FSR\n");
      v4 = *(_QWORD *)(a2 + 24);
      v5 = *(_DWORD *)(v4 + 1020);
      if ( v5 )
      {
        v6 = *(_DWORD *)(v4 + 1024);
      }
      else
      {
        v10 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v4 + 960) + 36LL));
        if ( v10 < 0 )
          v11 = 16;
        else
          v11 = 12;
        if ( v10 < 0 )
          v6 = 0x10000;
        else
          v6 = 4096;
        v5 = 2 << (((unsigned int)v10 >> 28) & 7) << v11;
        *(_DWORD *)(v4 + 1024) = v6;
        *(_DWORD *)(v4 + 1020) = v5;
      }
      writel_relaxed_2(
        0xFFFFFFFF,
        (unsigned int *)(*(_QWORD *)(v4 + 960) + v5 + (unsigned int)(*(_DWORD *)(a2 + 16) * v6) + 88LL));
      v12 = *(_QWORD *)(a2 + 24);
      v13 = *(_DWORD *)(v12 + 1020);
      if ( v13 )
      {
        v14 = *(_DWORD *)(v12 + 1024);
      }
      else
      {
        v15 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v12 + 960) + 36LL));
        if ( v15 < 0 )
          v16 = 16;
        else
          v16 = 12;
        if ( v15 < 0 )
          v14 = 0x10000;
        else
          v14 = 4096;
        v13 = 2 << (((unsigned int)v15 >> 28) & 7) << v16;
        *(_DWORD *)(v12 + 1024) = v14;
        *(_DWORD *)(v12 + 1020) = v13;
      }
      v17 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v12 + 960) + v13 + (unsigned int)(*(_DWORD *)(a2 + 16) * v14)));
      v18 = *(_QWORD *)(a2 + 24);
      v19 = v17;
      v20 = *(_DWORD *)(v18 + 1020);
      if ( v20 )
      {
        v21 = *(_DWORD *)(v18 + 1024);
      }
      else
      {
        v22 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v18 + 960) + 36LL));
        if ( v22 < 0 )
          v23 = 16;
        else
          v23 = 12;
        if ( v22 < 0 )
          v21 = 0x10000;
        else
          v21 = 4096;
        v20 = 2 << (((unsigned int)v22 >> 28) & 7) << v23;
        *(_DWORD *)(v18 + 1024) = v21;
        *(_DWORD *)(v18 + 1020) = v20;
      }
      writel_relaxed_2(
        v19 | 0x40,
        (unsigned int *)(*(_QWORD *)(v18 + 960) + v20 + (unsigned int)(*(_DWORD *)(a2 + 16) * v21)));
      __dsb(0xEu);
      result = kgsl_iommu_disable_clk(v3);
      if ( *(_BYTE *)(a2 + 32) == 1 )
        *(_BYTE *)(a2 + 32) = 0;
    }
  }
  return result;
}
