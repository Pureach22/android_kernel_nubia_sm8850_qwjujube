__int64 __fastcall android_rvh_wake_up_new_task(__int64 result, __int64 a2)
{
  __int64 v2; // x20
  __int64 inited; // x0
  unsigned __int64 *v5; // x22
  __int64 lock; // x0
  __int64 v7; // x8
  int v8; // w21
  unsigned __int64 v9; // x23
  __int64 v10; // x21
  __int64 v11; // x0
  __int64 v12; // x8
  int v13; // w24
  unsigned __int64 *v14; // x1
  unsigned __int64 v15; // x2
  unsigned __int64 *v16; // x0

  if ( (walt_disabled & 1) == 0 )
  {
    v2 = result;
    inited = init_new_task_load(a2);
    if ( (_UNKNOWN *)a2 == &init_task )
      v5 = (unsigned __int64 *)&vendor_data_pad;
    else
      v5 = (unsigned __int64 *)(a2 + 5184);
    lock = _rcu_read_lock(inited);
    v7 = *(_QWORD *)(*(_QWORD *)(a2 + 2872) + 8LL);
    if ( v7 )
    {
      v8 = *(unsigned __int8 *)(v7 + 616);
      _rcu_read_unlock(lock);
      if ( v8 == 1 )
      {
        v9 = qword_67BA0;
        v10 = raw_write_lock_irqsave(&related_thread_group_lock);
        v11 = _rcu_read_lock(v10);
        v12 = *(_QWORD *)(*(_QWORD *)(a2 + 2872) + 8LL);
        if ( v12 )
        {
          v13 = *(unsigned __int8 *)(v12 + 616);
          _rcu_read_unlock(v11);
          if ( v13 == 1 && !v5[30] )
          {
            raw_spin_lock(v9 + 4);
            atomic_store(v9, v5 + 30);
            v14 = (unsigned __int64 *)(v9 + 8);
            v15 = *(_QWORD *)(v9 + 8);
            v16 = v5 + 31;
            if ( *(_QWORD *)(v15 + 8) != v9 + 8 || v16 == v14 || (unsigned __int64 *)v15 == v16 )
            {
              _list_add_valid_or_report(v16, v14, v15);
            }
            else
            {
              *(_QWORD *)(v15 + 8) = v16;
              v5[31] = v15;
              v5[32] = (unsigned __int64)v14;
              *v14 = (unsigned __int64)v16;
            }
            raw_spin_unlock(v9 + 4);
          }
        }
        else
        {
          _rcu_read_unlock(v11);
        }
        raw_write_unlock_irqrestore(&related_thread_group_lock, v10);
      }
    }
    else
    {
      _rcu_read_unlock(lock);
    }
    return nbia_wakeup_new_task(v2, a2);
  }
  return result;
}
