__int64 __fastcall tmc_etr_alloc_sg_buf(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 v4; // x23
  unsigned __int64 v5; // x24
  unsigned __int64 *v9; // x20
  unsigned __int64 v10; // x3
  int v11; // w8
  __int64 v12; // x9
  unsigned __int64 v13; // x9
  unsigned __int64 v14; // x0
  unsigned __int64 v15; // x21
  unsigned __int64 v16; // x9
  __int64 v17; // x8
  int v18; // w10
  int v19; // w10
  unsigned int *v20; // x9
  __int64 v21; // x13
  int v22; // w11
  int v23; // w14
  int v24; // w12
  __int64 v25; // x17
  bool v26; // zf
  __int64 v27; // x16
  __int16 v28; // w14
  int v29; // w17
  int v30; // w16
  __int64 v31; // x10
  int v32; // w8
  __int64 v33; // x23
  __int64 v34; // x22
  __int64 v36; // x8

  v4 = *(_QWORD *)(a1 + 16);
  v5 = *(_QWORD *)(a2 + 16);
  v9 = (unsigned __int64 *)_kmalloc_cache_noprof(vunmap, 3520, 16);
  if ( !v9 )
    return 4294967284LL;
  v10 = v5 >> 12;
  if ( (unsigned int)(v5 >> 12) >= 0x3FF )
  {
    v12 = ((unsigned __int64)(int)v10 * (unsigned __int128)0x40100401004011uLL) >> 64;
    v13 = (v12 + ((unsigned __int64)((int)v10 - v12) >> 1)) >> 9;
    v11 = v13 - ((int)v10 - 1023 * v13 < 2);
  }
  else
  {
    v11 = 0;
  }
  v14 = tmc_alloc_sg_table(v4 + 56, a3, (unsigned __int64)(v11 + (int)v10 + 1023LL) >> 10, v10, a4);
  v15 = v14;
  if ( v14 < 0xFFFFFFFFFFFFF001LL )
  {
    *v9 = v14;
    v9[1] = *(_QWORD *)(v14 + 24);
    v16 = *(int *)(v14 + 64);
    v17 = *(_QWORD *)(v14 + 72);
    if ( (unsigned int)v16 >= 0x3FF )
      v18 = v16 / 0x3FF - (v16 % 0x3FF < 2);
    else
      v18 = 0;
    v19 = v16 + v18 - 1;
    v20 = *(unsigned int **)(v14 + 8);
    if ( v19 < 1 )
    {
      v31 = 0;
    }
    else
    {
      v21 = *(_QWORD *)(v14 + 48);
      v22 = 0;
      v23 = 0;
      v24 = 0;
      do
      {
        v25 = v17 + 8LL * v22;
        v26 = v23 == 1023;
        v27 = v21 + 8LL * (v24 + 1);
        v28 = v23 + 1;
        if ( v26 )
        {
          v29 = 3;
        }
        else
        {
          ++v22;
          v27 = v25;
          v29 = 2;
        }
        v23 = v28 & 0x3FF;
        v30 = *(_DWORD *)(v27 + 1);
        if ( !v23 )
          ++v24;
        --v19;
        *v20++ = v30 & 0xFFFFFFF0 | v29;
      }
      while ( v19 );
      v31 = v22;
    }
    *v20 = (*(_QWORD *)(v17 + 8 * v31) >> 8) & 0xFFFFFFF0 | 1;
    v32 = *(_DWORD *)(v14 + 40);
    if ( v32 >= 1 )
    {
      v33 = 0;
      v34 = *(_QWORD *)(*(_QWORD *)v14 + 96LL);
      do
      {
        if ( (*(_BYTE *)(v34 + 844) & 0x40) == 0 )
        {
          _dma_sync_single_for_device(v34, *(_QWORD *)(*(_QWORD *)(v15 + 48) + 8 * v33), 4096, 1);
          v32 = *(_DWORD *)(v15 + 40);
        }
        ++v33;
      }
      while ( v33 < v32 );
    }
    v15 = (unsigned __int64)v9;
    if ( (unsigned __int64)v9 <= 0xFFFFFFFFFFFFF000LL )
      goto LABEL_28;
    return 4294967284LL;
  }
  kfree(v9);
  if ( v15 > 0xFFFFFFFFFFFFF000LL )
    return 4294967284LL;
LABEL_28:
  v36 = *(_QWORD *)(v15 + 8);
  *(_DWORD *)(a2 + 4) = 1;
  *(_QWORD *)(a2 + 24) = v36;
  *(_QWORD *)(a2 + 56) = v15;
  return 0;
}
