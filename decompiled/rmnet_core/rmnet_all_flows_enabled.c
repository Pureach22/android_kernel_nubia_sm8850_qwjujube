bool __fastcall rmnet_all_flows_enabled(__int64 a1)
{
  __int64 lock; // x0
  bool v3; // w20
  unsigned __int64 v4; // x21
  __int64 v5; // x19
  __int64 i; // x8
  __int64 v8; // x22

  if ( a1 )
  {
    lock = _rcu_read_lock();
    v3 = 0;
    v4 = 0;
    v5 = a1 + 16;
    do
    {
      for ( i = *(_QWORD *)(v5 + 8 * v4); i; i = *(_QWORD *)(v8 + 16) )
      {
        v8 = i - 16;
        if ( i == 16 )
          break;
        lock = qmi_rmnet_all_flows_enabled(*(_QWORD *)(i - 8));
        if ( (lock & 1) == 0 )
          goto LABEL_12;
      }
      v3 = v4++ > 0xFD;
    }
    while ( v4 != 255 );
LABEL_12:
    _rcu_read_unlock(lock);
  }
  else
  {
    return 1;
  }
  return v3;
}
