__int64 __fastcall deferred_free(_QWORD *a1, __int64 a2, __int64 a3)
{
  _UNKNOWN **v3; // x20
  __int64 v6; // x9
  void *v7; // x2

  v3 = (_UNKNOWN **)(a1 + 2);
  a1[2] = a1 + 2;
  a1[3] = a1 + 2;
  *a1 = a3;
  a1[1] = a2;
  v6 = raw_spin_lock_irqsave(&free_list_lock);
  v7 = free_list;
  if ( free_list == (_UNKNOWN *)v3
    || v3 == &free_list
    || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)free_list) != &free_list )
  {
    _list_add_valid_or_report(v3, &free_list);
  }
  else
  {
    *(_QWORD *)((char *)&unk_8 + (_QWORD)free_list) = v3;
    a1[2] = v7;
    a1[3] = &free_list;
    free_list = v3;
  }
  list_nr_pages += a3;
  raw_spin_unlock_irqrestore(&free_list_lock, v6);
  return _wake_up(&freelist_waitqueue, 3, 1, 0);
}
