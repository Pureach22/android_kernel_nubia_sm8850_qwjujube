__int64 __fastcall kgsl_cancel_events_timestamp(__int64 a1, __int64 a2, int a3)
{
  __int64 *v6; // x9
  __int64 *v7; // x25
  __int64 **v8; // x8

  raw_spin_lock(a2 + 8);
  v6 = *(__int64 **)(a2 + 16);
  if ( v6 != (__int64 *)(a2 + 16) )
  {
    do
    {
      v7 = (__int64 *)*v6;
      if ( *((_DWORD *)v6 - 6) == a3 )
      {
        v8 = (__int64 **)v6[1];
        if ( *v8 == v6 && (__int64 *)v7[1] == v6 )
        {
          v7[1] = (__int64)v8;
          *v8 = v7;
        }
        else
        {
          _list_del_entry_valid_or_report(v6);
        }
        *((_DWORD *)v6 + 16) = 2;
        *v6 = 0xDEAD000000000100LL;
        v6[1] = 0xDEAD000000000122LL;
        kthread_queue_work(*(_QWORD *)(a1 + 12976), v6 + 3);
      }
      v6 = v7;
    }
    while ( v7 != (__int64 *)(a2 + 16) );
  }
  return raw_spin_unlock(a2 + 8);
}
