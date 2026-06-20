__int64 __fastcall sched_get_group_id(char *a1)
{
  __int64 lock; // x0
  _QWORD *v3; // x8
  unsigned int *v4; // x8
  unsigned int v5; // w19

  lock = _rcu_read_lock();
  v3 = &vendor_data_pad;
  if ( a1 != (char *)&init_task )
    v3 = a1 + 5184;
  v4 = (unsigned int *)v3[30];
  if ( v4 )
    v5 = *v4;
  else
    v5 = 0;
  _rcu_read_unlock(lock);
  return v5;
}
