__int64 __fastcall kgsl_cancel_event(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  _QWORD *v10; // x8
  int v11; // w11
  _QWORD *v12; // x9
  _QWORD *v13; // x10

  raw_spin_lock(a2 + 8);
  v10 = *(_QWORD **)(a2 + 16);
  while ( v10 != (_QWORD *)(a2 + 16) )
  {
    v11 = *((_DWORD *)v10 - 6);
    v12 = v10;
    v10 = (_QWORD *)*v10;
    if ( v11 == a3 && *(v12 - 2) == a4 && *(v12 - 1) == a5 )
    {
      v13 = (_QWORD *)v12[1];
      if ( (_QWORD *)*v13 == v12 && (_QWORD *)v10[1] == v12 )
      {
        v10[1] = v13;
        *v13 = v10;
      }
      else
      {
        _list_del_entry_valid_or_report(v12);
      }
      *v12 = 0xDEAD000000000100LL;
      v12[1] = 0xDEAD000000000122LL;
      *((_DWORD *)v12 + 16) = 2;
      kthread_queue_work(*(_QWORD *)(a1 + 12976), v12 + 3);
      return raw_spin_unlock(a2 + 8);
    }
  }
  return raw_spin_unlock(a2 + 8);
}
