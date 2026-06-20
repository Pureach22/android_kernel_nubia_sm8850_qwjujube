__int64 __fastcall kgsl_iommu_set_pf_policy(__int64 a1, unsigned __int64 a2)
{
  __int64 v4; // x21
  unsigned int v5; // w8
  int v6; // w9
  int v7; // w0
  char v8; // w10
  int v9; // w0
  unsigned int v10; // w21
  __int64 v11; // x22
  unsigned int v12; // w8
  int v13; // w9
  int v14; // w0
  char v15; // w10
  __int64 v16; // x21
  unsigned int v17; // w8
  int v18; // w9
  int v19; // w0
  char v20; // w10
  int v21; // w0
  unsigned int v22; // w21
  __int64 v23; // x22
  unsigned int v24; // w8
  int v25; // w9
  int v26; // w0
  char v27; // w10
  __int64 v28; // x20
  unsigned int v29; // w8
  int v30; // w9
  int v31; // w0
  char v32; // w10
  int v33; // w0
  unsigned int v34; // w20
  __int64 v35; // x21
  unsigned int v36; // w8
  int v37; // w9
  int v38; // w0
  char v39; // w10
  __int64 v40; // x20
  unsigned int v41; // w8
  int v42; // w9
  int v43; // w0
  char v44; // w10
  int v45; // w0
  unsigned int v46; // w20
  __int64 v47; // x21
  unsigned int v48; // w8
  int v49; // w9
  int v50; // w0
  char v51; // w10
  char v53; // [xsp+0h] [xbp-10h]
  char v54; // [xsp+0h] [xbp-10h]

  v53 = a2;
  if ( ((*(_QWORD *)(a1 + 56) >> 1) & 1) != ((a2 >> 1) & 1) )
  {
    kgsl_iommu_enable_clk(a1);
    v4 = *(_QWORD *)(a1 + 88);
    v5 = *(_DWORD *)(v4 + 1020);
    if ( v5 )
    {
      v6 = *(_DWORD *)(v4 + 1024);
    }
    else
    {
      v7 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v4 + 960) + 36LL));
      if ( v7 < 0 )
        v8 = 16;
      else
        v8 = 12;
      if ( v7 < 0 )
        v6 = 0x10000;
      else
        v6 = 4096;
      v5 = 2 << (((unsigned int)v7 >> 28) & 7) << v8;
      *(_DWORD *)(v4 + 1024) = v6;
      *(_DWORD *)(v4 + 1020) = v5;
    }
    v9 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v4 + 960) + v5 + (unsigned int)(*(_DWORD *)(a1 + 80) * v6)));
    if ( (v53 & 2) != 0 )
    {
      if ( (*(_QWORD *)(a1 + 48) & 0x100LL) != 0 )
        v10 = v9 & 0xFFFFFE7F;
      else
        v10 = v9 & 0xFFFFFE7F | 0x80;
    }
    else
    {
      v10 = v9 & 0xFFFFFE7F | 0x100;
    }
    v11 = *(_QWORD *)(a1 + 88);
    v12 = *(_DWORD *)(v11 + 1020);
    if ( v12 )
    {
      v13 = *(_DWORD *)(v11 + 1024);
    }
    else
    {
      v14 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v11 + 960) + 36LL));
      if ( v14 < 0 )
        v15 = 16;
      else
        v15 = 12;
      if ( v14 < 0 )
        v13 = 0x10000;
      else
        v13 = 4096;
      v12 = 2 << (((unsigned int)v14 >> 28) & 7) << v15;
      *(_DWORD *)(v11 + 1024) = v13;
      *(_DWORD *)(v11 + 1020) = v12;
    }
    writel_relaxed_2(v10, (unsigned int *)(*(_QWORD *)(v11 + 960) + v12 + (unsigned int)(*(_DWORD *)(a1 + 80) * v13)));
    if ( *(_QWORD *)(a1 + 696) )
    {
      v16 = *(_QWORD *)(a1 + 648);
      v17 = *(_DWORD *)(v16 + 1020);
      if ( v17 )
      {
        v18 = *(_DWORD *)(v16 + 1024);
      }
      else
      {
        v19 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v16 + 960) + 36LL));
        if ( v19 < 0 )
          v20 = 16;
        else
          v20 = 12;
        if ( v19 < 0 )
          v18 = 0x10000;
        else
          v18 = 4096;
        v17 = 2 << (((unsigned int)v19 >> 28) & 7) << v20;
        *(_DWORD *)(v16 + 1024) = v18;
        *(_DWORD *)(v16 + 1020) = v17;
      }
      v21 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v16 + 960) + v17 + (unsigned int)(*(_DWORD *)(a1 + 640) * v18)));
      if ( (v53 & 2) != 0 )
      {
        if ( (*(_QWORD *)(a1 + 48) & 0x100LL) != 0 )
          v22 = v21 & 0xFFFFFE7F;
        else
          v22 = v21 & 0xFFFFFE7F | 0x80;
      }
      else
      {
        v22 = v21 & 0xFFFFFE7F | 0x100;
      }
      v23 = *(_QWORD *)(a1 + 648);
      v24 = *(_DWORD *)(v23 + 1020);
      if ( v24 )
      {
        v25 = *(_DWORD *)(v23 + 1024);
      }
      else
      {
        v26 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v23 + 960) + 36LL));
        if ( v26 < 0 )
          v27 = 16;
        else
          v27 = 12;
        if ( v26 < 0 )
          v25 = 0x10000;
        else
          v25 = 4096;
        v24 = 2 << (((unsigned int)v26 >> 28) & 7) << v27;
        *(_DWORD *)(v23 + 1024) = v25;
        *(_DWORD *)(v23 + 1020) = v24;
      }
      writel_relaxed_2(
        v22,
        (unsigned int *)(*(_QWORD *)(v23 + 960) + v24 + (unsigned int)(*(_DWORD *)(a1 + 640) * v25)));
    }
    kgsl_iommu_disable_clk(a1);
  }
  if ( *(_QWORD *)(a1 + 696) )
  {
    v54 = a2;
    if ( ((*(_QWORD *)(a1 + 56) >> 1) & 1) != ((a2 >> 1) & 1) )
    {
      kgsl_iommu_enable_clk(a1);
      v28 = *(_QWORD *)(a1 + 88);
      v29 = *(_DWORD *)(v28 + 1020);
      if ( v29 )
      {
        v30 = *(_DWORD *)(v28 + 1024);
      }
      else
      {
        v31 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v28 + 960) + 36LL));
        if ( v31 < 0 )
          v32 = 16;
        else
          v32 = 12;
        if ( v31 < 0 )
          v30 = 0x10000;
        else
          v30 = 4096;
        v29 = 2 << (((unsigned int)v31 >> 28) & 7) << v32;
        *(_DWORD *)(v28 + 1024) = v30;
        *(_DWORD *)(v28 + 1020) = v29;
      }
      v33 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v28 + 960) + v29 + (unsigned int)(*(_DWORD *)(a1 + 80) * v30)));
      if ( (v54 & 2) != 0 )
      {
        if ( (*(_QWORD *)(a1 + 48) & 0x100LL) != 0 )
          v34 = v33 & 0xFFFFFE7F;
        else
          v34 = v33 & 0xFFFFFE7F | 0x80;
      }
      else
      {
        v34 = v33 & 0xFFFFFE7F | 0x100;
      }
      v35 = *(_QWORD *)(a1 + 88);
      v36 = *(_DWORD *)(v35 + 1020);
      if ( v36 )
      {
        v37 = *(_DWORD *)(v35 + 1024);
      }
      else
      {
        v38 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v35 + 960) + 36LL));
        if ( v38 < 0 )
          v39 = 16;
        else
          v39 = 12;
        if ( v38 < 0 )
          v37 = 0x10000;
        else
          v37 = 4096;
        v36 = 2 << (((unsigned int)v38 >> 28) & 7) << v39;
        *(_DWORD *)(v35 + 1024) = v37;
        *(_DWORD *)(v35 + 1020) = v36;
      }
      writel_relaxed_2(v34, (unsigned int *)(*(_QWORD *)(v35 + 960) + v36 + (unsigned int)(*(_DWORD *)(a1 + 80) * v37)));
      if ( *(_QWORD *)(a1 + 696) )
      {
        v40 = *(_QWORD *)(a1 + 648);
        v41 = *(_DWORD *)(v40 + 1020);
        if ( v41 )
        {
          v42 = *(_DWORD *)(v40 + 1024);
        }
        else
        {
          v43 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v40 + 960) + 36LL));
          if ( v43 < 0 )
            v44 = 16;
          else
            v44 = 12;
          if ( v43 < 0 )
            v42 = 0x10000;
          else
            v42 = 4096;
          v41 = 2 << (((unsigned int)v43 >> 28) & 7) << v44;
          *(_DWORD *)(v40 + 1024) = v42;
          *(_DWORD *)(v40 + 1020) = v41;
        }
        v45 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v40 + 960) + v41 + (unsigned int)(*(_DWORD *)(a1 + 640) * v42)));
        if ( (v54 & 2) != 0 )
        {
          if ( (*(_QWORD *)(a1 + 48) & 0x100LL) != 0 )
            v46 = v45 & 0xFFFFFE7F;
          else
            v46 = v45 & 0xFFFFFE7F | 0x80;
        }
        else
        {
          v46 = v45 & 0xFFFFFE7F | 0x100;
        }
        v47 = *(_QWORD *)(a1 + 648);
        v48 = *(_DWORD *)(v47 + 1020);
        if ( v48 )
        {
          v49 = *(_DWORD *)(v47 + 1024);
        }
        else
        {
          v50 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v47 + 960) + 36LL));
          if ( v50 < 0 )
            v51 = 16;
          else
            v51 = 12;
          if ( v50 < 0 )
            v49 = 0x10000;
          else
            v49 = 4096;
          v48 = 2 << (((unsigned int)v50 >> 28) & 7) << v51;
          *(_DWORD *)(v47 + 1024) = v49;
          *(_DWORD *)(v47 + 1020) = v48;
        }
        writel_relaxed_2(
          v46,
          (unsigned int *)(*(_QWORD *)(v47 + 960) + v48 + (unsigned int)(*(_DWORD *)(a1 + 640) * v49)));
      }
      kgsl_iommu_disable_clk(a1);
    }
  }
  return 0;
}
