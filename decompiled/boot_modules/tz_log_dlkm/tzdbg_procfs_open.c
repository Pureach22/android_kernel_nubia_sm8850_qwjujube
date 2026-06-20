__int64 __fastcall tzdbg_procfs_open(__int64 a1, __int64 a2)
{
  __int64 v4; // x19
  _UNKNOWN **v5; // x22
  void *v6; // x2
  __int64 result; // x0
  unsigned int v8; // w20
  _QWORD *v9; // x8
  _QWORD *v10; // x9

  v4 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 56);
  if ( !v4 )
    return 4294967284LL;
  *(_QWORD *)(v4 + 16) = a2;
  mutex_lock(&tzdbg_mutex);
  v5 = (_UNKNOWN **)(v4 + 24);
  v6 = clients_list;
  if ( clients_list == (_UNKNOWN *)(v4 + 24)
    || v5 == &clients_list
    || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)clients_list) != &clients_list )
  {
    _list_add_valid_or_report(v4 + 24, &clients_list);
  }
  else
  {
    *(_QWORD *)((char *)&unk_8 + (_QWORD)clients_list) = v5;
    *(_QWORD *)(v4 + 24) = v6;
    *(_QWORD *)(v4 + 32) = &clients_list;
    clients_list = (_UNKNOWN *)(v4 + 24);
  }
  mutex_unlock(&tzdbg_mutex);
  result = single_open(a2, 0, *(_QWORD *)(a1 + 696));
  if ( (_DWORD)result )
  {
    v8 = result;
    mutex_lock(&tzdbg_mutex);
    v9 = *(_QWORD **)(v4 + 32);
    if ( (_UNKNOWN **)*v9 == v5 && (v10 = *v5, *((_UNKNOWN ***)*v5 + 1) == v5) )
    {
      v10[1] = v9;
      *v9 = v10;
    }
    else
    {
      _list_del_entry_valid_or_report(v4 + 24);
    }
    *(_QWORD *)(v4 + 24) = 0xDEAD000000000100LL;
    *(_QWORD *)(v4 + 32) = 0xDEAD000000000122LL;
    mutex_unlock(&tzdbg_mutex);
    kfree(v4);
    return v8;
  }
  return result;
}
