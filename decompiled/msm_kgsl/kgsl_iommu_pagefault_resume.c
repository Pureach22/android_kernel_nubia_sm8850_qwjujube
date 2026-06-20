__int64 __fastcall kgsl_iommu_pagefault_resume(__int64 result, char a2)
{
  __int64 v2; // x19
  __int64 v4; // x21
  unsigned int v5; // w8
  int v6; // w9
  int v7; // w0
  char v8; // w10
  int v9; // w0
  __int64 v10; // x22
  int v11; // w21
  unsigned int v12; // w8
  int v13; // w9
  int v14; // w0
  char v15; // w10
  __int64 v16; // x21
  unsigned int v17; // w8
  int v18; // w9
  int v19; // w0
  char v20; // w10
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
  __int64 v43; // x20
  unsigned int v44; // w8
  int v45; // w9
  int v46; // w0
  char v47; // w10

  v2 = result;
  if ( *(_BYTE *)(result + 96) == 1 )
  {
    if ( (a2 & 1) != 0 )
    {
      v4 = *(_QWORD *)(result + 88);
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
      v9 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v4 + 960) + v5 + (unsigned int)(*(_DWORD *)(v2 + 80) * v6)));
      v10 = *(_QWORD *)(v2 + 88);
      v11 = v9;
      v12 = *(_DWORD *)(v10 + 1020);
      if ( v12 )
      {
        v13 = *(_DWORD *)(v10 + 1024);
      }
      else
      {
        v14 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v10 + 960) + 36LL));
        if ( v14 < 0 )
          v15 = 16;
        else
          v15 = 12;
        if ( v14 < 0 )
          v13 = 0x10000;
        else
          v13 = 4096;
        v12 = 2 << (((unsigned int)v14 >> 28) & 7) << v15;
        *(_DWORD *)(v10 + 1024) = v13;
        *(_DWORD *)(v10 + 1020) = v12;
      }
      writel_relaxed_2(
        v11 & 0xFFFFFE7F,
        (unsigned int *)(*(_QWORD *)(v10 + 960) + v12 + (unsigned int)(*(_DWORD *)(v2 + 80) * v13)));
      __dsb(0xEu);
    }
    v16 = *(_QWORD *)(v2 + 88);
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
    writel_relaxed_2(
      0xFFFFFFFF,
      (unsigned int *)(*(_QWORD *)(v16 + 960) + v17 + (unsigned int)(*(_DWORD *)(v2 + 80) * v18) + 88LL));
    __dsb(0xEu);
    v21 = *(_QWORD *)(v2 + 88);
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
    result = writel_relaxed_2(
               1u,
               (unsigned int *)(*(_QWORD *)(v21 + 960) + v22 + (unsigned int)(*(_DWORD *)(v2 + 80) * v23) + 8LL));
    __dsb(0xEu);
  }
  if ( *(_QWORD *)(v2 + 696) && *(_BYTE *)(v2 + 656) == 1 )
  {
    if ( (a2 & 1) != 0 )
    {
      v26 = *(_QWORD *)(v2 + 648);
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
      v31 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v26 + 960) + v27 + (unsigned int)(*(_DWORD *)(v2 + 640) * v28)));
      v32 = *(_QWORD *)(v2 + 648);
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
        v33 & 0xFFFFFE7F,
        (unsigned int *)(*(_QWORD *)(v32 + 960) + v34 + (unsigned int)(*(_DWORD *)(v2 + 640) * v35)));
      __dsb(0xEu);
    }
    v38 = *(_QWORD *)(v2 + 648);
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
    writel_relaxed_2(
      0xFFFFFFFF,
      (unsigned int *)(*(_QWORD *)(v38 + 960) + v39 + (unsigned int)(*(_DWORD *)(v2 + 640) * v40) + 88LL));
    __dsb(0xEu);
    v43 = *(_QWORD *)(v2 + 648);
    v44 = *(_DWORD *)(v43 + 1020);
    if ( v44 )
    {
      v45 = *(_DWORD *)(v43 + 1024);
    }
    else
    {
      v46 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(v43 + 960) + 36LL));
      if ( v46 < 0 )
        v47 = 16;
      else
        v47 = 12;
      if ( v46 < 0 )
        v45 = 0x10000;
      else
        v45 = 4096;
      v44 = 2 << (((unsigned int)v46 >> 28) & 7) << v47;
      *(_DWORD *)(v43 + 1024) = v45;
      *(_DWORD *)(v43 + 1020) = v44;
    }
    result = writel_relaxed_2(
               1u,
               (unsigned int *)(*(_QWORD *)(v43 + 960) + v44 + (unsigned int)(*(_DWORD *)(v2 + 640) * v45) + 8LL));
    __dsb(0xEu);
  }
  return result;
}
