__int64 __fastcall ipa3_alloc_rx_pkt_page(char a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x19
  unsigned int v6; // w21
  __int64 pages_entry; // x0
  __int64 v8; // x1
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  _QWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = kmem_cache_alloc_noprof(*(_QWORD *)(ipa3_ctx + 29448), 527808);
  v5 = v4;
  if ( v4 )
  {
    v6 = *(_DWORD *)(a2 + 1604);
    *(_DWORD *)(v4 + 36) = v6;
    if ( (a1 & 1) != 0 )
    {
      v15[0] = 0;
      pages_entry = rmnet_mem_get_pages_entry(552128, v6, (char *)v15 + 4, v15, 1);
      if ( pages_entry )
      {
        v8 = pages_entry;
LABEL_5:
        if ( v6 < *(_DWORD *)(v5 + 36) )
          ++*(_QWORD *)(ipa3_ctx + 32896);
      }
      else
      {
        while ( v6 )
        {
          v8 = rmnet_mem_get_pages_entry(552128, --v6, (char *)v15 + 4, v15, 1);
          if ( v8 )
            goto LABEL_5;
        }
        printk(&unk_3F7E91, "ipa3_rmnet_alloc_page");
        v12 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v13 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v13 )
          {
            ipc_log_string(v13, "ipa %s:%d rmnet page alloc fails\n", "ipa3_rmnet_alloc_page", 2779);
            v12 = ipa3_ctx;
          }
          v14 = *(_QWORD *)(v12 + 34160);
          if ( v14 )
            ipc_log_string(v14, "ipa %s:%d rmnet page alloc fails\n", "ipa3_rmnet_alloc_page", 2779);
        }
        v6 = 0;
        v8 = 0;
      }
    }
    else
    {
      v8 = _alloc_pages_noprof(920768, v6, 0, 0);
    }
    *(_DWORD *)(v5 + 36) = v6;
    v9 = ipa3_ctx;
    *(_QWORD *)(v5 + 16) = v8;
    if ( v8 )
    {
      *(_DWORD *)(v5 + 40) = 4096LL << v6;
      v10 = dma_map_page_attrs(*(_QWORD *)(v9 + 34216), v8, 0, (4096LL << v6) & 0xFFFFF000LL, 2, 0);
      *(_QWORD *)(v5 + 24) = v10;
      if ( v10 != -1 )
      {
        *(_BYTE *)(v5 + 32) = (a1 & 1) != 0;
        goto LABEL_17;
      }
      if ( (unsigned int)__ratelimit(&ipa3_alloc_rx_pkt_page__rs, "ipa3_alloc_rx_pkt_page") )
        printk(&unk_3CF8CD, "ipa3_alloc_rx_pkt_page");
      _free_pages(*(_QWORD *)(v5 + 16), *(unsigned int *)(v5 + 36));
      v9 = ipa3_ctx;
    }
    kmem_cache_free(*(_QWORD *)(v9 + 29448), v5);
    v5 = 0;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v5;
}
