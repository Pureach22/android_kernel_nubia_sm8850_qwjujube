__int64 __fastcall gh_msgq_alloc_entry(int a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x0
  void *v6; // x2

  v2 = _kmalloc_cache_noprof(_init_waitqueue_head, 2336, 144);
  v3 = v2;
  if ( !v2 )
    return -12;
  *(_QWORD *)(v2 + 16) = -1;
  *(_QWORD *)(v2 + 24) = -1;
  *(_WORD *)(v2 + 64) = 256;
  *(_DWORD *)(v2 + 120) = a1;
  _init_waitqueue_head(v2 + 72, "&cap_table_entry->tx_wq", &gh_msgq_alloc_entry___key);
  _init_waitqueue_head(v3 + 96, "&cap_table_entry->rx_wq", &gh_msgq_alloc_entry___key_4);
  *(_QWORD *)(v3 + 56) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  v4 = kasprintf(2080, "gh_msgq_tx_%d", a1);
  *(_QWORD *)(v3 + 40) = v4;
  if ( !v4 )
  {
LABEL_8:
    kfree(v4);
    kfree(*(_QWORD *)(v3 + 48));
    kfree(v3);
    return -12;
  }
  v5 = kasprintf(2080, "gh_msgq_rx_%d", a1);
  *(_QWORD *)(v3 + 48) = v5;
  if ( !v5 )
  {
    v4 = *(_QWORD *)(v3 + 40);
    goto LABEL_8;
  }
  v6 = gh_msgq_cap_list;
  if ( gh_msgq_cap_list == (_UNKNOWN *)(v3 + 128)
    || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)gh_msgq_cap_list) != &gh_msgq_cap_list )
  {
    _list_add_valid_or_report();
  }
  else
  {
    *(_QWORD *)((char *)&unk_8 + (_QWORD)gh_msgq_cap_list) = v3 + 128;
    *(_QWORD *)(v3 + 128) = v6;
    *(_QWORD *)(v3 + 136) = &gh_msgq_cap_list;
    gh_msgq_cap_list = (_UNKNOWN *)(v3 + 128);
  }
  return v3;
}
