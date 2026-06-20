__int64 __fastcall task_sched_boost_2(__int64 a1)
{
  char v1; // w19
  __int64 lock; // x0
  __int64 v4; // x8

  if ( sched_boost_type == 1 )
  {
    v1 = 1;
    return v1 & 1;
  }
  lock = _rcu_read_lock(a1);
  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 2872) + 8LL);
  if ( !v4 )
  {
    v1 = 0;
    goto LABEL_7;
  }
  if ( (unsigned int)sched_boost_type < 6 )
  {
    v1 = *(_BYTE *)(v4 + (unsigned int)sched_boost_type + 617);
LABEL_7:
    _rcu_read_unlock(lock);
    return v1 & 1;
  }
  __break(0x5512u);
  return task_fits_capacity_0(lock);
}
