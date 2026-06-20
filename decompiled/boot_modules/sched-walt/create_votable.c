__int64 __fastcall create_votable(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x19
  __int64 v9; // x0
  int v10; // w9
  __int64 v11; // x9
  void *v12; // x2

  if ( !a1 )
    return -22;
  if ( a2 >= 3 )
  {
    printk(&unk_6469C);
    return -22;
  }
  v8 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 136);
  if ( !v8 )
    return -12;
  v9 = kstrdup(a1, 3264);
  *(_QWORD *)v8 = v9;
  if ( !v9 )
  {
    kfree(v8);
    return -12;
  }
  *(_DWORD *)(v8 + 88) = 8;
  *(_DWORD *)(v8 + 92) = a2;
  if ( a2 == 2 )
    v10 = 0;
  else
    v10 = -22;
  *(_QWORD *)(v8 + 112) = a4;
  *(_QWORD *)(v8 + 120) = a3;
  *(_DWORD *)(v8 + 100) = v10;
  *(_DWORD *)(v8 + 104) = 0;
  *(_DWORD *)(v8 + 96) = -22;
  v11 = raw_spin_lock_irqsave(&votable_list_slock);
  v12 = votable_list;
  if ( votable_list == (_UNKNOWN *)(v8 + 8) || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)votable_list) != &votable_list )
  {
    _list_add_valid_or_report(v8 + 8, &votable_list, votable_list);
  }
  else
  {
    *(_QWORD *)((char *)&unk_8 + (_QWORD)votable_list) = v8 + 8;
    *(_QWORD *)(v8 + 8) = v12;
    *(_QWORD *)(v8 + 16) = &votable_list;
    votable_list = (_UNKNOWN *)(v8 + 8);
  }
  raw_spin_unlock_irqrestore(&votable_list_slock, v11);
  return v8;
}
