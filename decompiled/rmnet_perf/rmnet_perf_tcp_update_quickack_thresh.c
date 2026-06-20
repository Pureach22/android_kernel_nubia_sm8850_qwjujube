__int64 __fastcall rmnet_perf_tcp_update_quickack_thresh(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w19
  int v5; // w20
  __int64 lock; // x0
  __int64 i; // x8
  __int64 *j; // x10

  v4 = a2;
  if ( (_DWORD)result )
  {
    v5 = result;
    lock = _rcu_read_lock(result, a2, a3, a4);
    for ( i = 0; i != 16; ++i )
    {
      for ( j = (__int64 *)rmnet_perf_quickack_hash[i]; j; j = (__int64 *)*j )
      {
        if ( *((_DWORD *)j + 22) == v5 )
          *((_DWORD *)j + 23) = v4;
      }
    }
    return _rcu_read_unlock(lock);
  }
  else if ( (_DWORD)a2 == 1 )
  {
    enable_tcp = 1;
  }
  else if ( !(_DWORD)a2 )
  {
    enable_tcp = 0;
  }
  return result;
}
