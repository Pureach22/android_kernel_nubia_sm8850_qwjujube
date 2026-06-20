__int64 __fastcall kgsl_iommu_start(__int64 a1)
{
  __int64 v2; // x20
  unsigned int v3; // w8
  int v4; // w9
  int v5; // w0
  char v6; // w10
  int v7; // w0
  unsigned int v8; // w20
  __int64 v9; // x21
  unsigned int v10; // w8
  int v11; // w9
  int v12; // w0
  char v13; // w10
  __int64 v14; // x20
  unsigned int v15; // w8
  int v16; // w9
  int v17; // w0
  char v18; // w10
  int v19; // w0
  unsigned int v20; // w20
  __int64 v21; // x21
  unsigned int v22; // w8
  int v23; // w9
  int v24; // w0
  char v25; // w10
  __int64 v26; // x20
  unsigned int v27; // w8
  int v28; // w9
  int v29; // w0
  char v30; // w10
  int v31; // w0
  __int64 v32; // x21
  int v33; // w20
  unsigned int v34; // w8
  int v35; // w9
  int v36; // w0
  char v37; // w10
  __int64 v38; // x20
  unsigned int v39; // w8
  int v40; // w9
  int v41; // w0
  char v42; // w10
  int v43; // w0
  __int64 v44; // x22
  int v45; // w20
  unsigned int v46; // w8
  int v47; // w9
  int v48; // w0
  char v49; // w10
  __int64 v51; // [xsp+8h] [xbp-8h]
  __int64 v52; // [xsp+8h] [xbp-8h]

  kgsl_iommu_enable_clk(a1);
  if ( *(_DWORD *)(a1 + 12) != 1 )
  {
    writel_relaxed_2(2u, (unsigned int *)(*(_QWORD *)(a1 + 904) + 26624LL));
    writel_relaxed_2(1u, (unsigned int *)(*(_QWORD *)(a1 + 904) + 25760LL));
    __dsb(0xEu);
  }
  v2 = *(_QWORD *)(a1 + 88);
  v3 = *(_DWORD *)(v2 + 1020);
  v51 = *(_QWORD *)(a1 + 56);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v2 + 1024);
  }
  else
  {
    v5 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v2 + 960) + 36LL));
    if ( v5 < 0 )
      v6 = 16;
    else
      v6 = 12;
    if ( v5 < 0 )
      v4 = 0x10000;
    else
      v4 = 4096;
    v3 = 2 << (((unsigned int)v5 >> 28) & 7) << v6;
    *(_DWORD *)(v2 + 1024) = v4;
    *(_DWORD *)(v2 + 1020) = v3;
  }
  v7 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v2 + 960) + v3 + (unsigned int)(*(_DWORD *)(a1 + 80) * v4)));
  if ( (v51 & 2) != 0 )
  {
    if ( (*(_QWORD *)(a1 + 48) & 0x100LL) != 0 )
      v8 = v7 & 0xFFFFFE7F;
    else
      v8 = v7 & 0xFFFFFE7F | 0x80;
  }
  else
  {
    v8 = v7 & 0xFFFFFE7F | 0x100;
  }
  v9 = *(_QWORD *)(a1 + 88);
  v10 = *(_DWORD *)(v9 + 1020);
  if ( v10 )
  {
    v11 = *(_DWORD *)(v9 + 1024);
  }
  else
  {
    v12 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v9 + 960) + 36LL));
    if ( v12 < 0 )
      v13 = 16;
    else
      v13 = 12;
    if ( v12 < 0 )
      v11 = 0x10000;
    else
      v11 = 4096;
    v10 = 2 << (((unsigned int)v12 >> 28) & 7) << v13;
    *(_DWORD *)(v9 + 1024) = v11;
    *(_DWORD *)(v9 + 1020) = v10;
  }
  writel_relaxed_2(v8, (unsigned int *)(*(_QWORD *)(v9 + 960) + v10 + (unsigned int)(*(_DWORD *)(a1 + 80) * v11)));
  iommu_context_set_prr(a1, a1 + 64);
  if ( *(_BYTE *)(a1 + 40) == 1 )
    iommu_context_set_prr(a1, a1 + 344);
  if ( *(_QWORD *)(a1 + 696) )
  {
    iommu_context_set_prr(a1, a1 + 624);
    v14 = *(_QWORD *)(a1 + 648);
    v15 = *(_DWORD *)(v14 + 1020);
    v52 = *(_QWORD *)(a1 + 56);
    if ( v15 )
    {
      v16 = *(_DWORD *)(v14 + 1024);
    }
    else
    {
      v17 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v14 + 960) + 36LL));
      if ( v17 < 0 )
        v18 = 16;
      else
        v18 = 12;
      if ( v17 < 0 )
        v16 = 0x10000;
      else
        v16 = 4096;
      v15 = 2 << (((unsigned int)v17 >> 28) & 7) << v18;
      *(_DWORD *)(v14 + 1024) = v16;
      *(_DWORD *)(v14 + 1020) = v15;
    }
    v19 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v14 + 960) + v15 + (unsigned int)(*(_DWORD *)(a1 + 640) * v16)));
    if ( (v52 & 2) != 0 )
    {
      if ( (*(_QWORD *)(a1 + 48) & 0x100LL) != 0 )
        v20 = v19 & 0xFFFFFE7F;
      else
        v20 = v19 & 0xFFFFFE7F | 0x80;
    }
    else
    {
      v20 = v19 & 0xFFFFFE7F | 0x100;
    }
    v21 = *(_QWORD *)(a1 + 648);
    v22 = *(_DWORD *)(v21 + 1020);
    if ( v22 )
    {
      v23 = *(_DWORD *)(v21 + 1024);
    }
    else
    {
      v24 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v21 + 960) + 36LL));
      if ( v24 < 0 )
        v25 = 16;
      else
        v25 = 12;
      if ( v24 < 0 )
        v23 = 0x10000;
      else
        v23 = 4096;
      v22 = 2 << (((unsigned int)v24 >> 28) & 7) << v25;
      *(_DWORD *)(v21 + 1024) = v23;
      *(_DWORD *)(v21 + 1020) = v22;
    }
    writel_relaxed_2(v20, (unsigned int *)(*(_QWORD *)(v21 + 960) + v22 + (unsigned int)(*(_DWORD *)(a1 + 640) * v23)));
  }
  v26 = *(_QWORD *)(a1 + 88);
  v27 = *(_DWORD *)(v26 + 1020);
  if ( v27 )
  {
    v28 = *(_DWORD *)(v26 + 1024);
  }
  else
  {
    v29 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v26 + 960) + 36LL));
    if ( v29 < 0 )
      v30 = 16;
    else
      v30 = 12;
    if ( v29 < 0 )
      v28 = 0x10000;
    else
      v28 = 4096;
    v27 = 2 << (((unsigned int)v29 >> 28) & 7) << v30;
    *(_DWORD *)(v26 + 1024) = v28;
    *(_DWORD *)(v26 + 1020) = v27;
  }
  v31 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v26 + 960) + v27 + (unsigned int)(*(_DWORD *)(a1 + 80) * v28) + 48LL));
  v32 = *(_QWORD *)(a1 + 88);
  v33 = v31;
  v34 = *(_DWORD *)(v32 + 1020);
  if ( v34 )
  {
    v35 = *(_DWORD *)(v32 + 1024);
  }
  else
  {
    v36 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v32 + 960) + 36LL));
    if ( v36 < 0 )
      v37 = 16;
    else
      v37 = 12;
    if ( v36 < 0 )
      v35 = 0x10000;
    else
      v35 = 4096;
    v34 = 2 << (((unsigned int)v36 >> 28) & 7) << v37;
    *(_DWORD *)(v32 + 1024) = v35;
    *(_DWORD *)(v32 + 1020) = v34;
  }
  writel_relaxed_2(
    v33 & 0xFF7FFF7F,
    (unsigned int *)(*(_QWORD *)(v32 + 960) + v34 + (unsigned int)(*(_DWORD *)(a1 + 80) * v35) + 48LL));
  __dsb(0xEu);
  if ( *(_QWORD *)(a1 + 696) )
  {
    v38 = *(_QWORD *)(a1 + 648);
    v39 = *(_DWORD *)(v38 + 1020);
    if ( v39 )
    {
      v40 = *(_DWORD *)(v38 + 1024);
    }
    else
    {
      v41 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v38 + 960) + 36LL));
      if ( v41 < 0 )
        v42 = 16;
      else
        v42 = 12;
      if ( v41 < 0 )
        v40 = 0x10000;
      else
        v40 = 4096;
      v39 = 2 << (((unsigned int)v41 >> 28) & 7) << v42;
      *(_DWORD *)(v38 + 1024) = v40;
      *(_DWORD *)(v38 + 1020) = v39;
    }
    v43 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v38 + 960)
                                         + v39
                                         + (unsigned int)(*(_DWORD *)(a1 + 640) * v40)
                                         + 48LL));
    v44 = *(_QWORD *)(a1 + 648);
    v45 = v43;
    v46 = *(_DWORD *)(v44 + 1020);
    if ( v46 )
    {
      v47 = *(_DWORD *)(v44 + 1024);
    }
    else
    {
      v48 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v44 + 960) + 36LL));
      if ( v48 < 0 )
        v49 = 16;
      else
        v49 = 12;
      if ( v48 < 0 )
        v47 = 0x10000;
      else
        v47 = 4096;
      v46 = 2 << (((unsigned int)v48 >> 28) & 7) << v49;
      *(_DWORD *)(v44 + 1024) = v47;
      *(_DWORD *)(v44 + 1020) = v46;
    }
    writel_relaxed_2(
      v45 & 0xFF7FFF7F,
      (unsigned int *)(*(_QWORD *)(v44 + 960) + v46 + (unsigned int)(*(_DWORD *)(a1 + 640) * v47) + 48LL));
    __dsb(0xEu);
  }
  kgsl_iommu_disable_clk(a1);
  return 0;
}
