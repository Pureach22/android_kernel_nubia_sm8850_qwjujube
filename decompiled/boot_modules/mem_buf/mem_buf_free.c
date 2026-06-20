__int64 __fastcall mem_buf_free(__int64 a1)
{
  _QWORD *v2; // x8
  __int64 v3; // x0
  __int64 v4; // x9

  mutex_lock(&mem_buf_list_lock);
  v2 = *(_QWORD **)(a1 + 80);
  v3 = a1 + 72;
  if ( *v2 == a1 + 72 && (v4 = *(_QWORD *)v3, *(_QWORD *)(*(_QWORD *)v3 + 8LL) == v3) )
  {
    *(_QWORD *)(v4 + 8) = v2;
    *v2 = v4;
  }
  else
  {
    _list_del_entry_valid_or_report(v3);
  }
  *(_QWORD *)(a1 + 72) = 0xDEAD000000000100LL;
  *(_QWORD *)(a1 + 80) = 0xDEAD000000000122LL;
  mutex_unlock(&mem_buf_list_lock);
  mem_buf_relinquish_mem(a1);
  kvfree(*(_QWORD *)(a1 + 16));
  if ( *(_DWORD *)(a1 + 48) == 1 )
    kfree(*(_QWORD *)(a1 + 56));
  if ( *(_DWORD *)(a1 + 32) == 1 )
    kfree(*(_QWORD *)(a1 + 40));
  kfree(*(_QWORD *)(a1 + 8));
  return kfree(a1);
}
