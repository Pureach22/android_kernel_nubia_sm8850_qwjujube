__int64 __fastcall kgsl_iommu_lpac_fault_handler(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x22
  unsigned int v8; // w8
  int v9; // w0
  char v10; // w10
  int v11; // w9
  int v12; // w0
  __int64 v13; // x23
  int v14; // w22
  unsigned int v15; // w8
  int v16; // w0
  char v17; // w10
  int v18; // w9
  int v19; // w0

  v5 = *(_QWORD *)(a5 + 648);
  v8 = *(_DWORD *)(v5 + 1020);
  if ( v8 )
  {
    v11 = *(_DWORD *)(v5 + 1024);
  }
  else
  {
    v9 = readl_relaxed_1(*(_QWORD *)(v5 + 960) + 36LL);
    if ( v9 < 0 )
      v10 = 16;
    else
      v10 = 12;
    if ( v9 < 0 )
      v11 = 0x10000;
    else
      v11 = 4096;
    v8 = 2 << (((unsigned int)v9 >> 28) & 7) << v10;
    *(_DWORD *)(v5 + 1024) = v11;
    *(_DWORD *)(v5 + 1020) = v8;
  }
  v12 = readl_relaxed_1(*(_QWORD *)(v5 + 960) + v8 + (unsigned int)(*(_DWORD *)(a5 + 640) * v11) + 104LL);
  v13 = *(_QWORD *)(a5 + 648);
  v14 = v12;
  v15 = *(_DWORD *)(v13 + 1020);
  if ( v15 )
  {
    v18 = *(_DWORD *)(v13 + 1024);
  }
  else
  {
    v16 = readl_relaxed_1(*(_QWORD *)(v13 + 960) + 36LL);
    if ( v16 < 0 )
      v17 = 16;
    else
      v17 = 12;
    if ( v16 < 0 )
      v18 = 0x10000;
    else
      v18 = 4096;
    v15 = 2 << (((unsigned int)v16 >> 28) & 7) << v17;
    *(_DWORD *)(v13 + 1024) = v18;
    *(_DWORD *)(v13 + 1020) = v15;
  }
  v19 = readl_relaxed_1(*(_QWORD *)(v13 + 960) + v15 + (unsigned int)(*(_DWORD *)(a5 + 640) * v18) + 108LL);
  dev_crit(*(_QWORD *)(a5 - 56), "LPAC PAGE FAULT iova=0x%16lx, fsynr0=0x%x, fsynr1=0x%x\n", a3, v14, v19);
  return kgsl_iommu_fault_handler(a5, a5 + 624);
}
