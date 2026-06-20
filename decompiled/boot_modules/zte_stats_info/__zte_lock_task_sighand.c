__int64 __fastcall _zte_lock_task_sighand(__int64 a1, __int64 *a2)
{
  __int64 lock; // x0
  __int64 v5; // x21
  __int64 v6; // x22

  lock = _rcu_read_lock();
  v5 = *(_QWORD *)(a1 + 2400);
  if ( v5 )
  {
    while ( 1 )
    {
      lock = raw_spin_lock_irqsave(v5);
      *a2 = lock;
      if ( v5 == *(_QWORD *)(a1 + 2400) )
        break;
      lock = raw_spin_unlock_irqrestore(v5, lock);
      v5 = *(_QWORD *)(a1 + 2400);
      v6 = 0;
      if ( !v5 )
        goto LABEL_6;
    }
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
LABEL_6:
  _rcu_read_unlock(lock);
  return v6;
}
