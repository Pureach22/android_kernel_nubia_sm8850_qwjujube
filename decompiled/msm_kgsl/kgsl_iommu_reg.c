__int64 __fastcall kgsl_iommu_reg(__int64 a1, unsigned int a2)
{
  __int64 v2; // x21
  unsigned int v5; // w8
  int v6; // w9
  int v7; // w0
  char v8; // w10

  v2 = *(_QWORD *)(a1 + 24);
  v5 = *(_DWORD *)(v2 + 1020);
  if ( v5 )
  {
    v6 = *(_DWORD *)(v2 + 1024);
  }
  else
  {
    v7 = readl_relaxed_1(*(_QWORD *)(v2 + 960) + 36LL);
    if ( v7 < 0 )
      v8 = 16;
    else
      v8 = 12;
    if ( v7 < 0 )
      v6 = 0x10000;
    else
      v6 = 4096;
    v5 = 2 << (((unsigned int)v7 >> 28) & 7) << v8;
    *(_DWORD *)(v2 + 1024) = v6;
    *(_DWORD *)(v2 + 1020) = v5;
  }
  return *(_QWORD *)(v2 + 960) + v5 + (unsigned int)(v6 * *(_DWORD *)(a1 + 16)) + a2;
}
