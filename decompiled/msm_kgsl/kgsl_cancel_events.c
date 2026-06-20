__int64 __fastcall kgsl_cancel_events(__int64 a1, __int64 a2)
{
  __int64 *v4; // x9
  __int64 **v5; // x8
  __int64 *v6; // x24

  raw_spin_lock(a2 + 8);
  v4 = *(__int64 **)(a2 + 16);
  if ( v4 != (__int64 *)(a2 + 16) )
  {
    do
    {
      v6 = (__int64 *)*v4;
      v5 = (__int64 **)v4[1];
      if ( *v5 == v4 && (__int64 *)v6[1] == v4 )
      {
        v6[1] = (__int64)v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
      }
      *((_DWORD *)v4 + 16) = 2;
      *v4 = 0xDEAD000000000100LL;
      v4[1] = 0xDEAD000000000122LL;
      kthread_queue_work(*(_QWORD *)(a1 + 12976), v4 + 3);
      v4 = v6;
    }
    while ( v6 != (__int64 *)(a2 + 16) );
  }
  return raw_spin_unlock(a2 + 8);
}
