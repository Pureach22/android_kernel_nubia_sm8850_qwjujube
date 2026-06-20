__int64 rmnet_shs_update_cpu_proc_q_all_cpus()
{
  __int64 unlock; // x0
  __int64 v1; // x19
  _DWORD *v2; // x20
  __int64 lock; // x0
  char *v4; // x8

  unlock = ((__int64 (*)(void))_rcu_read_lock)();
  v1 = 0;
  v2 = &unk_194B8;
  _ReadStatusReg(SP_EL0);
  do
  {
    if ( ((_cpu_active_mask >> v1) & 1) != 0 )
    {
      lock = _rcu_read_lock(unlock);
      v4 = (char *)&softnet_data + _per_cpu_offset[v1];
      *v2 = *((_DWORD *)v4 + 32);
      v2[1] = *((_DWORD *)v4 + 59);
      unlock = _rcu_read_unlock(lock);
      v2[2] = v2[1] - *v2;
    }
    ++v1;
    v2 += 10;
  }
  while ( v1 != 8 );
  return _rcu_read_unlock(unlock);
}
