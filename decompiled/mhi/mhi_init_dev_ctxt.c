__int64 __fastcall mhi_init_dev_ctxt(__int64 a1)
{
  __int64 *v2; // x20
  __int64 v3; // x0
  unsigned int v4; // w11
  unsigned int v5; // w8
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 v8; // x0
  unsigned int v9; // w8
  __int64 v10; // x23
  int v11; // w22
  __int64 *v12; // x21
  __int64 v13; // x8
  __int64 v14; // x26
  __int64 v15; // x27
  __int64 v16; // x1
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 v20; // x8
  __int64 v21; // x0
  _QWORD *v22; // x22
  __int64 v23; // x21
  __int64 v24; // x0
  unsigned __int64 v26; // x10
  unsigned __int64 v27; // x9
  __int64 v28; // x21
  __int64 v29; // x21

  *(_DWORD *)(a1 + 352) = 0;
  *(_DWORD *)(a1 + 356) = 0;
  v2 = (__int64 *)_kmalloc_cache_noprof(raw_read_lock_bh, 3520, 48);
  if ( v2 )
  {
    v3 = dma_alloc_attrs(*(_QWORD *)(a1 + 8), 44LL * *(unsigned int *)(a1 + 208), v2 + 4, 3264, 0);
    v2[1] = v3;
    if ( v3 )
    {
      v4 = *(_DWORD *)(a1 + 208);
      if ( v4 )
      {
        v5 = 0;
        v6 = v3 + 36;
        v7 = *(_QWORD *)(a1 + 176) + 204LL;
        do
        {
          if ( (*(_BYTE *)(v7 + 190) & 1) == 0 )
          {
            *(_WORD *)(v6 - 36) = ((*(_WORD *)(v7 + 28) & 3) << 8) | ((unsigned __int16)*(_DWORD *)(v7 + 24) << 10);
            *(_DWORD *)(v6 - 32) = *(_DWORD *)(v7 + 8);
            *(_DWORD *)(v6 - 28) = *(_DWORD *)v7;
            *(_DWORD *)(v7 + 56) = 0;
            *(_QWORD *)(v7 - 12) = v6;
            v4 = *(_DWORD *)(a1 + 208);
          }
          ++v5;
          v6 += 44;
          v7 += 400;
        }
        while ( v5 < v4 );
      }
      v8 = dma_alloc_attrs(*(_QWORD *)(a1 + 8), 44LL * *(unsigned int *)(a1 + 212), v2 + 3, 3264, 0);
      *v2 = v8;
      if ( v8 )
      {
        v9 = *(_DWORD *)(a1 + 212);
        v10 = *(_QWORD *)(a1 + 248);
        v11 = 0;
        if ( v9 )
        {
          v12 = (__int64 *)(v8 + 36);
          do
          {
            if ( (*(_BYTE *)(v10 + 258) & 1) == 0 )
            {
              *((_DWORD *)v12 - 9) = *((unsigned __int8 *)v12 - 36) | (*(_DWORD *)(v10 + 20) << 16);
              *((_DWORD *)v12 - 8) = 1;
              *((_DWORD *)v12 - 7) = *(_DWORD *)(v10 + 24);
              v13 = *(_QWORD *)(v10 + 112);
              *(_BYTE *)(v10 + 137) = 1;
              v14 = 16 * v13;
              v15 = 16 * v13 - 1;
              *(_QWORD *)(v10 + 96) = 16;
              *(_QWORD *)(v10 + 104) = 16 * v13;
              v16 = v15 + 16 * v13;
              *(_QWORD *)(v10 + 120) = v16;
              v17 = dma_alloc_attrs(*(_QWORD *)(a1 + 8), v16, v10 + 40, 3264, 0);
              *(_QWORD *)(v10 + 64) = v17;
              if ( !v17 )
                goto LABEL_19;
              v18 = *(_QWORD *)(v10 + 40);
              v19 = (v18 + v15) & -v14;
              *(_QWORD *)(v10 + 48) = v19;
              v20 = v17 + v19 - v18;
              *(_QWORD *)(v10 + 80) = v20;
              *(_QWORD *)(v10 + 88) = v20;
              *(_QWORD *)(v10 + 72) = v20;
              *(v12 - 3) = v19;
              *(v12 - 1) = v19;
              *v12 = v19;
              *(v12 - 2) = *(_QWORD *)(v10 + 104);
              *(_QWORD *)(v10 + 56) = v12;
              v9 = *(_DWORD *)(a1 + 212);
            }
            ++v11;
            v10 += 264;
            v12 = (__int64 *)((char *)v12 + 44);
          }
          while ( v11 < v9 );
        }
        v21 = dma_alloc_attrs(*(_QWORD *)(a1 + 8), 44, v2 + 5, 3264, 0);
        v2[2] = v21;
        if ( v21 )
        {
          v22 = *(_QWORD **)(a1 + 256);
          v23 = v21;
          v22[7] = 16;
          v22[8] = 2048;
          v22[9] = 128;
          v22[10] = 4095;
          v24 = dma_alloc_attrs(*(_QWORD *)(a1 + 8), 4095, v22, 3264, 0);
          v22[3] = v24;
          if ( v24 )
          {
            v26 = (*v22 + 2047LL) & 0xFFFFFFFFFFFFF800LL;
            v27 = v26 - *v22;
            v22[1] = v26;
            v22[5] = v24 + v27;
            v22[6] = v24 + v27;
            v22[4] = v24 + v27;
            *(_QWORD *)(v23 + 36) = v26;
            v28 = v23 + 36;
            *(_QWORD *)(v28 - 24) = v26;
            *(_QWORD *)(v28 - 8) = v26;
            *(_QWORD *)(v28 - 16) = v22[8];
            v22[2] = v28;
            *(_QWORD *)(a1 + 264) = v2;
            return 0;
          }
          dma_free_attrs(*(_QWORD *)(a1 + 8), 44, v2[2], v2[5], 0);
          v11 = *(_DWORD *)(a1 + 212);
          v10 = *(_QWORD *)(a1 + 248) + 264LL * v11;
        }
LABEL_19:
        if ( v11 - 1 >= 0 )
        {
          v29 = v10 - 224;
          do
          {
            if ( (*(_BYTE *)(v29 + 218) & 1) == 0 )
              dma_free_attrs(*(_QWORD *)(a1 + 8), *(_QWORD *)(v29 + 80), *(_QWORD *)(v29 + 24), *(_QWORD *)v29, 0);
            --v11;
            v29 -= 264;
          }
          while ( v11 > 0 );
        }
        dma_free_attrs(*(_QWORD *)(a1 + 8), 44LL * *(unsigned int *)(a1 + 212), *v2, v2[3], 0);
      }
      dma_free_attrs(*(_QWORD *)(a1 + 8), 44LL * *(unsigned int *)(a1 + 208), v2[1], v2[4], 0);
    }
    kfree(v2);
  }
  return 4294967284LL;
}
