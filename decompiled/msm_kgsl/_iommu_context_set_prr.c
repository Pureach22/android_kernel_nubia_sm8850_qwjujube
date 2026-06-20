__int64 __fastcall iommu_context_set_prr(__int64 result, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x23
  __int64 v5; // x20
  unsigned int v6; // w8
  int v7; // w9
  int v8; // w0
  char v9; // w10
  int v10; // w0
  __int64 v11; // x21
  int v12; // w20
  unsigned int v13; // w8
  int v14; // w9
  int v15; // w0
  char v16; // w10

  if ( (*(_DWORD *)(a2 + 16) & 0x80000000) == 0 )
  {
    if ( *(_QWORD *)(a2 + 72) )
    {
      v3 = kgsl_vbo_zero_page;
      if ( kgsl_vbo_zero_page )
      {
        v4 = result;
        writel_relaxed_2(
          ((_DWORD)kgsl_vbo_zero_page + 0x40000000 + (memstart_addr >> 12 << 6)) << 6,
          (unsigned int *)(*(_QWORD *)(result + 904) + 24584LL));
        writel_relaxed_2(
          (unsigned __int64)(v3 + 0x140000000LL + (memstart_addr >> 12 << 6)) >> 26,
          (unsigned int *)(*(_QWORD *)(v4 + 904) + 24588LL));
        v5 = *(_QWORD *)(a2 + 24);
        v6 = *(_DWORD *)(v5 + 1020);
        if ( v6 )
        {
          v7 = *(_DWORD *)(v5 + 1024);
        }
        else
        {
          v8 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v5 + 960) + 36LL));
          if ( v8 < 0 )
            v9 = 16;
          else
            v9 = 12;
          if ( v8 < 0 )
            v7 = 0x10000;
          else
            v7 = 4096;
          v6 = 2 << (((unsigned int)v8 >> 28) & 7) << v9;
          *(_DWORD *)(v5 + 1024) = v7;
          *(_DWORD *)(v5 + 1020) = v6;
        }
        v10 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v5 + 960)
                                             + v6
                                             + (unsigned int)(*(_DWORD *)(a2 + 16) * v7)
                                             + 4LL));
        v11 = *(_QWORD *)(a2 + 24);
        v12 = v10;
        v13 = *(_DWORD *)(v11 + 1020);
        if ( v13 )
        {
          v14 = *(_DWORD *)(v11 + 1024);
        }
        else
        {
          v15 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v11 + 960) + 36LL));
          if ( v15 < 0 )
            v16 = 16;
          else
            v16 = 12;
          if ( v15 < 0 )
            v14 = 0x10000;
          else
            v14 = 4096;
          v13 = 2 << (((unsigned int)v15 >> 28) & 7) << v16;
          *(_DWORD *)(v11 + 1024) = v14;
          *(_DWORD *)(v11 + 1020) = v13;
        }
        result = writel_relaxed_2(
                   v12 | 0x20u,
                   (unsigned int *)(*(_QWORD *)(v11 + 960) + v13 + (unsigned int)(*(_DWORD *)(a2 + 16) * v14) + 4LL));
        __dsb(0xEu);
      }
    }
  }
  return result;
}
