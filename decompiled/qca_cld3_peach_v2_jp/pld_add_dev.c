__int64 __fastcall pld_add_dev(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v8; // x23
  __int64 v9; // x0
  _QWORD *v10; // x1
  __int64 v11; // x9
  _QWORD *v12; // x0
  __int64 v13; // x2

  v8 = _kmalloc_cache_noprof(wcnss_check_pool_lists, 3520, 40);
  if ( !v8 )
    return 4294967284LL;
  *(_QWORD *)v8 = a2;
  *(_QWORD *)(v8 + 8) = a3;
  *(_DWORD *)(v8 + 32) = a4;
  v9 = raw_spin_lock_irqsave(a1 + 8);
  v10 = *(_QWORD **)(a1 + 24);
  v11 = v9;
  v12 = (_QWORD *)(v8 + 16);
  v13 = a1 + 16;
  if ( v8 == a1 || v10 == v12 || *v10 != v13 )
  {
    _list_add_valid_or_report(v12, v10);
  }
  else
  {
    *(_QWORD *)(a1 + 24) = v12;
    *(_QWORD *)(v8 + 16) = v13;
    *(_QWORD *)(v8 + 24) = v10;
    *v10 = v12;
  }
  raw_spin_unlock_irqrestore(a1 + 8, v11);
  return 0;
}
