bool __fastcall kgsl_iommu_ctx_terminated_on_fault(__int64 a1)
{
  __int64 v3; // x20
  unsigned int v4; // w8
  int v5; // w9
  int v6; // w0
  char v7; // w10
  int v8; // w0
  int v9; // w20

  if ( (*(_QWORD *)(a1 + 48) & 0x100) == 0 )
    return 0;
  if ( (*(_QWORD *)(a1 + 56) & 2) == 0 )
    return 0;
  kgsl_iommu_enable_clk(a1);
  v3 = *(_QWORD *)(a1 + 88);
  v4 = *(_DWORD *)(v3 + 1020);
  if ( v4 )
  {
    v5 = *(_DWORD *)(v3 + 1024);
  }
  else
  {
    v6 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v3 + 960) + 36LL));
    if ( v6 < 0 )
      v7 = 16;
    else
      v7 = 12;
    if ( v6 < 0 )
      v5 = 0x10000;
    else
      v5 = 4096;
    v4 = 2 << (((unsigned int)v6 >> 28) & 7) << v7;
    *(_DWORD *)(v3 + 1024) = v5;
    *(_DWORD *)(v3 + 1020) = v4;
  }
  v8 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v3 + 960) + v4 + (unsigned int)(*(_DWORD *)(a1 + 80) * v5) + 88LL));
  __dsb(0xDu);
  v9 = v8;
  kgsl_iommu_disable_clk(a1);
  return (v9 & 0xFFFFF9FF) != 0;
}
