__int64 __fastcall fastrpc_dma_buf_attach(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x22
  _QWORD *v4; // x19
  _QWORD *v5; // x21
  _QWORD *v6; // x1
  _QWORD *v7; // x2

  v2 = *(_QWORD **)(a1 + 112);
  v4 = (_QWORD *)_kmalloc_cache_noprof(snprintf, 3520, 40);
  if ( !v4 )
    return 4294967284LL;
  if ( (dma_get_sgtable_attrs(v2[4], v4 + 1, v2[6], v2[8] & ~(-1LL << *(_DWORD *)(v2[5] + 140LL)), v2[9], 0) & 0x80000000) != 0 )
  {
    dev_err(v2[4], "failed to get scatterlist from DMA API\n");
    kfree(v4);
    return 4294967274LL;
  }
  else
  {
    v5 = v4 + 3;
    *v4 = *(_QWORD *)(a2 + 8);
    v4[3] = v4 + 3;
    v4[4] = v4 + 3;
    *(_QWORD *)(a2 + 64) = v4;
    mutex_lock(v2 + 10);
    v6 = v2 + 16;
    v7 = (_QWORD *)v2[16];
    if ( (_QWORD *)v7[1] != v2 + 16 || v5 == v6 || v7 == v5 )
    {
      _list_add_valid_or_report(v4 + 3, v6, v7);
    }
    else
    {
      v7[1] = v5;
      v4[3] = v7;
      v4[4] = v6;
      *v6 = v5;
    }
    mutex_unlock(v2 + 10);
    return 0;
  }
}
