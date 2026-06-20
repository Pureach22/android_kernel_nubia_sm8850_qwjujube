__int64 __fastcall ipa3_cleanup_rx(__int64 a1)
{
  _QWORD *v2; // x24
  void (__fastcall *v3)(_QWORD); // x8
  __int64 v4; // x0
  _QWORD *v5; // x22
  _QWORD *v6; // x8
  _QWORD *v7; // t2
  __int64 v8; // x1
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 result; // x0
  __int64 v13; // x8
  unsigned int v14; // w22
  int i; // w21
  __int64 v16; // x8
  int v17; // w8
  __int64 v18; // x20
  __int64 v19; // x0
  __int64 v20; // x1
  void (__fastcall *v21)(_QWORD); // x8
  __int64 v22; // x0

  raw_spin_lock_bh(a1 + 1684);
  v2 = *(_QWORD **)(a1 + 1648);
  while ( v2 != (_QWORD *)(a1 + 1648) )
  {
    v5 = v2;
    v7 = v2;
    v2 = (_QWORD *)*v2;
    v6 = (_QWORD *)v7[1];
    if ( (_QWORD *)*v6 == v5 && (_QWORD *)v2[1] == v5 )
    {
      v2[1] = v6;
      *v6 = v2;
    }
    else
    {
      _list_del_entry_valid_or_report(v5);
    }
    v8 = v5[3];
    *v5 = 0xDEAD000000000100LL;
    v5[1] = 0xDEAD000000000122LL;
    v9 = ipa3_ctx;
    if ( v8 )
    {
      dma_unmap_page_attrs(*(_QWORD *)(ipa3_ctx + 34216), v8, *(unsigned int *)(a1 + 160), 2, 0);
    }
    else if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d DMA address already freed\n", "ipa3_cleanup_rx", 3872);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d DMA address already freed\n", "ipa3_cleanup_rx", 3872);
    }
    v3 = *(void (__fastcall **)(_QWORD))(a1 + 144);
    v4 = v5[2];
    if ( *((_DWORD *)v3 - 1) != 303786302 )
      __break(0x8228u);
    v3(v4);
    kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29448), v5);
  }
  result = raw_spin_unlock_bh(a1 + 1684);
  v13 = *(_QWORD *)(a1 + 368);
  if ( v13 )
  {
    v14 = *(_DWORD *)(v13 + 8);
    for ( i = *(_DWORD *)(v13 + 12); v14 != i; v14 = (v14 + 1) % *(_DWORD *)(v13 + 16) )
    {
      v18 = *(_QWORD *)(*(_QWORD *)v13 + 8LL * v14);
      v19 = *(_QWORD *)(ipa3_ctx + 34216);
      v20 = *(_QWORD *)(v18 + 24);
      if ( *(int *(__fastcall **)(int *))(a1 + 360) == ipa3_replenish_rx_page_recycle )
      {
        dma_unmap_page_attrs(v19, v20, *(unsigned int *)(v18 + 40), 2, 0);
        _free_pages(*(_QWORD *)(v18 + 16), *(unsigned int *)(v18 + 36));
      }
      else
      {
        dma_unmap_page_attrs(v19, v20, *(unsigned int *)(a1 + 160), 2, 0);
        v21 = *(void (__fastcall **)(_QWORD))(a1 + 144);
        v22 = *(_QWORD *)(v18 + 16);
        if ( *((_DWORD *)v21 - 1) != 303786302 )
          __break(0x8228u);
        v21(v22);
      }
      kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29448), v18);
      v13 = *(_QWORD *)(a1 + 368);
    }
    kfree(*(_QWORD *)v13);
    result = kfree(*(_QWORD *)(a1 + 368));
    v16 = *(_QWORD *)(a1 + 1624);
    *(_QWORD *)(a1 + 368) = 0;
    v17 = *(_DWORD *)(v16 + 4);
    if ( v17 == 95 || v17 == 35 )
      return rmnet_mem_unregister_notifier(&ipa3_rmnet_mem_blk);
  }
  return result;
}
