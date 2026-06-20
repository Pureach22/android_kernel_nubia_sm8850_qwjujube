__int64 __fastcall mhi_init_chan_ctxt(__int64 a1, __int64 a2)
{
  unsigned int v4; // w22
  __int64 v5; // x2
  __int64 v6; // x24
  __int64 v7; // x1
  __int64 v8; // x21
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x10
  __int64 v12; // x9
  __int64 v13; // x0
  __int64 v15; // x8
  __int64 v16; // x10
  __int64 v17; // x10
  __int64 v18; // x8

  v4 = *(_DWORD *)(a2 + 200);
  v5 = a2 + 104;
  v6 = 16LL * *(_QWORD *)(a2 + 176);
  *(_QWORD *)(a2 + 160) = 16;
  *(_QWORD *)(a2 + 168) = v6;
  v7 = v6 - 1 + v6;
  v8 = *(_QWORD *)(*(_QWORD *)(a1 + 264) + 8LL);
  *(_QWORD *)(a2 + 184) = v7;
  v9 = dma_alloc_attrs(*(_QWORD *)(a1 + 8), v7, v5, 3264, 0);
  *(_QWORD *)(a2 + 128) = v9;
  if ( v9 )
  {
    v10 = *(_QWORD *)(a2 + 104);
    v11 = *(_QWORD *)(a2 + 80);
    v12 = (v10 + v6 - 1) & -v6;
    *(_QWORD *)(a2 + 112) = v12;
    *(_QWORD *)(a2 + 136) = v9 + v12 - v10;
    *(_QWORD *)(a2 + 64) = 56;
    *(_QWORD *)(a2 + 72) = 56 * v11;
    v13 = vzalloc_noprof(*(_QWORD *)(a2 + 72));
    *(_QWORD *)(a2 + 40) = v13;
    if ( v13 )
    {
      v15 = v8 + 44LL * v4;
      *(_BYTE *)v15 = 1;
      v16 = *(_QWORD *)(a2 + 112);
      *(_QWORD *)(v15 + 36) = v16;
      v15 += 36;
      *(_QWORD *)(v15 - 24) = v16;
      *(_QWORD *)(v15 - 8) = v16;
      *(_QWORD *)(v15 - 16) = *(_QWORD *)(a2 + 168);
      v17 = *(_QWORD *)(a2 + 136);
      *(_QWORD *)(a2 + 120) = v15;
      v18 = *(_QWORD *)(a2 + 40);
      *(_BYTE *)(a2 + 225) = 1;
      *(_QWORD *)(a2 + 144) = v17;
      *(_QWORD *)(a2 + 152) = v17;
      *(_QWORD *)(a2 + 48) = v18;
      *(_QWORD *)(a2 + 56) = v18;
      __dmb(0xAu);
      return 0;
    }
    dma_free_attrs(*(_QWORD *)(a1 + 8), *(_QWORD *)(a2 + 184), *(_QWORD *)(a2 + 128), *(_QWORD *)(a2 + 104), 0);
  }
  return 4294967284LL;
}
