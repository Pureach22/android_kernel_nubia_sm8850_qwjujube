__int64 __fastcall kgsl_iommu_get_current_ttbr0(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v4; // x21
  unsigned int v5; // w8
  int v6; // w9
  int v8; // w0
  char v9; // w10
  __int64 v10; // x20

  v2 = a1 + 64;
  if ( a2 && (*(_DWORD *)(a2 + 200) & 0x20000000) != 0 )
    v2 = a1 + 624;
  if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) != 0
    || (*(_BYTE *)(a1 + 11248) & 1) != 0
    || (*(_DWORD *)(v2 + 16) & 0x80000000) != 0 )
  {
    return 0;
  }
  kgsl_iommu_enable_clk(a1);
  v4 = *(_QWORD *)(v2 + 24);
  v5 = *(_DWORD *)(v4 + 1020);
  if ( v5 )
  {
    v6 = *(_DWORD *)(v4 + 1024);
  }
  else
  {
    v8 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v4 + 960) + 36LL));
    if ( v8 < 0 )
      v9 = 16;
    else
      v9 = 12;
    if ( v8 < 0 )
      v6 = 0x10000;
    else
      v6 = 4096;
    v5 = 2 << (((unsigned int)v8 >> 28) & 7) << v9;
    *(_DWORD *)(v4 + 1024) = v6;
    *(_DWORD *)(v4 + 1020) = v5;
  }
  v10 = readq_relaxed((_QWORD *)(*(_QWORD *)(v4 + 960) + v5 + (unsigned int)(*(_DWORD *)(v2 + 16) * v6) + 32LL));
  kgsl_iommu_disable_clk(a1);
  return v10;
}
