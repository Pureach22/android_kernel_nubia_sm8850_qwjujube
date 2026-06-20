__int64 __fastcall rmnet_enable_all_flows(__int64 result)
{
  __int64 v1; // x19
  __int64 lock; // x0
  __int64 v3; // x20
  __int64 v4; // x19
  __int64 i; // x8
  __int64 v6; // x21

  if ( result )
  {
    v1 = result;
    lock = _rcu_read_lock();
    v3 = 0;
    v4 = v1 + 16;
    do
    {
      for ( i = *(_QWORD *)(v4 + 8 * v3); i; i = *(_QWORD *)(v6 + 16) )
      {
        v6 = i - 16;
        if ( i == 16 )
          break;
        lock = qmi_rmnet_enable_all_flows(*(_QWORD *)(i - 8));
      }
      ++v3;
    }
    while ( v3 != 255 );
    return _rcu_read_unlock(lock);
  }
  return result;
}
