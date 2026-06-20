__int64 __fastcall rmnet_ctl_endpoint_post(__int64 result, __int64 a2)
{
  _WORD *v3; // x19
  __int64 lock; // x0
  __int64 (__fastcall **v5)(_QWORD); // x8
  _WORD *v6; // x0
  __int64 (__fastcall *v7)(_QWORD); // x8
  __int64 (__fastcall **v8)(_QWORD); // x22
  __int64 v9; // x21
  void *v10; // x0

  if ( result && a2 )
  {
    v3 = (_WORD *)result;
    lock = _rcu_read_lock();
    if ( a2 == 0xFFFFFFFFLL )
    {
      if ( (unsigned __int8)ipc_log_lvl >= 2u && qword_6B20 )
        ipc_log_string();
      v5 = (__int64 (__fastcall **)(_QWORD))qword_6B08;
      if ( !qword_6B08 || !*(_QWORD *)qword_6B08 )
      {
        lock = kfree(v3);
        return _rcu_read_unlock(lock);
      }
      v6 = v3;
      v3[90] = -1792;
      v7 = *v5;
    }
    else
    {
      if ( (unsigned __int8)ipc_log_lvl >= 2u )
      {
        lock = qword_6B20;
        if ( qword_6B20 )
          lock = ipc_log_string();
      }
      v8 = (__int64 (__fastcall **)(_QWORD))qword_6B08;
      if ( !qword_6B08 )
        return _rcu_read_unlock(lock);
      if ( !*(_QWORD *)qword_6B08 )
        return _rcu_read_unlock(lock);
      lock = _alloc_skb((unsigned int)a2, 2080, 0, 0xFFFFFFFFLL);
      if ( !lock )
        return _rcu_read_unlock(lock);
      v9 = lock;
      v10 = (void *)skb_put(lock, (unsigned int)a2);
      memcpy(v10, v3, (unsigned int)a2);
      v6 = (_WORD *)v9;
      *(_WORD *)(v9 + 180) = -1792;
      v7 = *v8;
    }
    if ( *((_DWORD *)v7 - 1) != 303786302 )
      __break(0x8228u);
    lock = v7(v6);
    return _rcu_read_unlock(lock);
  }
  return result;
}
