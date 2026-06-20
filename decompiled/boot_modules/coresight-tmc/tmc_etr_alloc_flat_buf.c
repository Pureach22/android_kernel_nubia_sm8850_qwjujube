__int64 __fastcall tmc_etr_alloc_flat_buf(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x20
  _QWORD *v8; // x21
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x8
  __int64 v14; // x9

  if ( a4 )
    return 4294967274LL;
  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 152LL);
  v8 = (_QWORD *)_kmalloc_cache_noprof(arm64_use_ng_mappings, 3520, 40);
  if ( !v8 )
    return 4294967284LL;
  v9 = dma_alloc_noncontiguous(v7, *(_QWORD *)(a2 + 16), 2, 3264, 0);
  v8[4] = v9;
  if ( v9 )
  {
    v10 = *(_QWORD *)(a2 + 16);
    v8[1] = *(_QWORD *)(*(_QWORD *)v9 + 16LL);
    v11 = dma_vmap_noncontiguous(v7, v10, v9);
    v12 = *(_QWORD *)(a2 + 16);
    v8[2] = v11;
    if ( v11 )
    {
      v13 = *(_QWORD *)(a1 + 16);
      v14 = v8[1];
      v8[3] = v12;
      *(_DWORD *)(a2 + 4) = 0;
      *(_QWORD *)(a2 + 24) = v14;
      *v8 = v13 + 56;
      *(_QWORD *)(a2 + 56) = v8;
      return 0;
    }
    else
    {
      dma_free_noncontiguous(v7, v12, v8[4], 2);
      v8[4] = 0;
      return 4294967284LL;
    }
  }
  else
  {
    kfree(v8);
    return 4294967284LL;
  }
}
