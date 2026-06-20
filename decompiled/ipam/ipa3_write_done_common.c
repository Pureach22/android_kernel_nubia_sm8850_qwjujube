__int64 __fastcall ipa3_write_done_common(__int64 a1, __int64 a2)
{
  int v2; // w27
  __int64 v3; // x22
  unsigned int v5; // w19
  _QWORD *v6; // x26
  _QWORD *v7; // x8
  __int64 v8; // x21
  _QWORD *v9; // x23
  __int64 v10; // x24
  _DWORD *v11; // x28
  unsigned int v12; // w25
  _QWORD *v13; // x1
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  _QWORD *v21; // [xsp+8h] [xbp-8h]

  if ( !a2 )
  {
    printk(&unk_3F2031, "ipa3_write_done_common");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v18 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d tx_pkt is NULL\n", "ipa3_write_done_common", 329);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
        ipc_log_string(v19, "ipa %s:%d tx_pkt is NULL\n", "ipa3_write_done_common", 329);
    }
    return 0;
  }
  v2 = *(_DWORD *)(a2 + 80);
  v3 = a2;
  if ( v2 < 1 )
    return 0;
  v5 = 0;
  v6 = (_QWORD *)(a1 + 1632);
  v21 = (_QWORD *)(a1 + 1664);
  while ( 1 )
  {
    raw_spin_lock_bh(a1 + 1684);
    if ( (_QWORD *)*v6 == v6 )
      break;
    v8 = *(_QWORD *)(v3 + 32);
    v7 = *(_QWORD **)(v3 + 40);
    v9 = (_QWORD *)(v3 + 32);
    if ( *v7 == v3 + 32 && *(_QWORD **)(v8 + 8) == v9 )
    {
      *(_QWORD *)(v8 + 8) = v7;
      *v7 = v8;
    }
    else
    {
      _list_del_entry_valid_or_report(v3 + 32);
    }
    *(_QWORD *)(v3 + 32) = 0xDEAD000000000100LL;
    *(_QWORD *)(v3 + 40) = 0xDEAD000000000122LL;
    --*(_DWORD *)a1;
    if ( (*(_BYTE *)(v3 + 96) & 1) == 0 )
      dma_unmap_page_attrs(*(_QWORD *)(ipa3_ctx + 34216), *(_QWORD *)(v3 + 16), *(unsigned int *)(v3 + 24), 1, 0);
    v11 = *(_DWORD **)(v3 + 48);
    v10 = *(_QWORD *)(v3 + 56);
    v12 = *(_DWORD *)(v3 + 64);
    if ( *(_DWORD *)(a1 + 1680) >= *(_DWORD *)(ipa3_ctx + 48776) || *(_DWORD *)(*(_QWORD *)(a1 + 1624) + 4LL) == 36 )
    {
      kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29440), v3);
    }
    else
    {
      v13 = *(_QWORD **)(a1 + 1672);
      if ( v9 == v21 || v9 == v13 || (_QWORD *)*v13 != v21 )
      {
        _list_add_valid_or_report(v3 + 32, v13);
      }
      else
      {
        *(_QWORD *)(a1 + 1672) = v9;
        *(_QWORD *)(v3 + 32) = v21;
        *(_QWORD *)(v3 + 40) = v13;
        *v13 = v9;
      }
      ++*(_DWORD *)(a1 + 1680);
    }
    raw_spin_unlock_bh(a1 + 1684);
    if ( v11 )
    {
      if ( *(v11 - 1) != 1607364836 )
        __break(0x823Cu);
      ((void (__fastcall *)(__int64, _QWORD))v11)(v10, v12);
    }
    ++v5;
    v3 = v8 - 32;
    if ( v2 == v5 )
      return (unsigned int)v2;
  }
  raw_spin_unlock_bh(a1 + 1684);
  if ( (unsigned int)__ratelimit(&ipa3_write_done_common__rs, "ipa3_write_done_common") )
    printk(&unk_3F513F, "ipa3_write_done_common");
  v14 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v15 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v15 )
    {
      ipc_log_string(v15, "ipa %s:%d list is empty missing descriptors", "ipa3_write_done_common", 338);
      v14 = ipa3_ctx;
    }
    v16 = *(_QWORD *)(v14 + 34160);
    if ( v16 )
      ipc_log_string(v16, "ipa %s:%d list is empty missing descriptors", "ipa3_write_done_common", 338);
  }
  return v5;
}
