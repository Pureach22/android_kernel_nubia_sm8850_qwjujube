__int64 __fastcall dynamic_page_pool_create(int a1, int a2)
{
  __int64 v4; // x0
  __int64 v5; // x19
  void *v6; // x0
  void *v7; // x2

  v4 = _kmalloc_cache_noprof(of_property_read_string, 3264, 112);
  v5 = v4;
  if ( v4 )
  {
    *(_QWORD *)v4 = 0;
    *(_QWORD *)(v4 + 32) = v4 + 32;
    *(_QWORD *)(v4 + 40) = v4 + 32;
    *(_QWORD *)(v4 + 16) = v4 + 16;
    *(_QWORD *)(v4 + 24) = v4 + 16;
    *(_DWORD *)(v4 + 68) = a1 | 0x40000;
    *(_DWORD *)(v4 + 72) = a2;
    *(_DWORD *)(v4 + 64) = 0;
    mutex_lock(&pool_list_lock);
    v6 = (void *)(v5 + 80);
    v7 = pool_list;
    if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)pool_list) != &pool_list || pool_list == v6 )
    {
      _list_add_valid_or_report(v6);
    }
    else
    {
      *(_QWORD *)((char *)&unk_8 + (_QWORD)pool_list) = v6;
      *(_QWORD *)(v5 + 80) = v7;
      *(_QWORD *)(v5 + 88) = &pool_list;
      pool_list = (_UNKNOWN *)(v5 + 80);
    }
    mutex_unlock(&pool_list_lock);
  }
  return v5;
}
