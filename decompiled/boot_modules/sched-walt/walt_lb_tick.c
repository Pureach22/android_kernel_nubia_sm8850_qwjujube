__int64 __usercall walt_lb_tick@<X0>(__int64 a1@<X0>, _BYTE *a2@<X8>)
{
  __int64 v2; // x19
  __int64 v3; // x21
  void *v4; // x22
  __int64 v5; // x26
  _QWORD *v6; // x27
  __int64 v7; // x20
  __int64 result; // x0
  unsigned __int64 v9; // x8
  char v10; // w23
  __int64 v11; // x25
  __int64 v12; // x0
  __int64 v13; // x23
  __int64 energy_efficient_cpu; // x0
  unsigned int v15; // w24
  _BYTE *v16; // x8
  unsigned __int64 v23; // x10

  v7 = *(unsigned int *)(a1 + 3632);
  if ( (unsigned int)v7 >= 0x20 )
  {
    __break(0x5512u);
LABEL_34:
    _X8 = (unsigned __int64 *)(a2 + 80);
    __asm { PRFM            #0x11, [X8] }
    do
      v23 = __ldxr(_X8);
    while ( __stxr(v23 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
    goto LABEL_8;
  }
  v3 = *(_QWORD *)(a1 + 3344);
  v6 = &_per_cpu_offset;
  v5 = *((_QWORD *)&_per_cpu_offset + v7);
  v2 = a1;
  if ( (_UNKNOWN *)v3 == &init_task )
    v4 = &vendor_data_pad;
  else
    v4 = (void *)(v3 + 5184);
  raw_spin_lock(a1);
  if ( (unsigned int)available_idle_cpu((unsigned int)v7) )
  {
    a2 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v7)];
    if ( (*((_QWORD *)a2 + 10) & 2) != 0 && !*(_DWORD *)(v2 + 3576) )
      goto LABEL_34;
  }
LABEL_8:
  result = raw_spin_unlock(v2);
  if ( sched_boost_type == 4 )
  {
    v9 = *(unsigned int *)(v2 + 3632);
    if ( !(_DWORD)v9 )
    {
      v11 = raw_spin_lock_irqsave(&walt_lb_migration_lock);
      v10 = move_storage_load(v2);
      result = raw_spin_unlock_irqrestore(&walt_lb_migration_lock, v11);
      goto LABEL_13;
    }
    if ( ((*(unsigned __int64 *)((char *)&walt_enforce_high_irq_cpu_mask + ((v9 >> 3) & 0x1FFFFFF8)) >> v9) & 1) != 0 )
      return result;
  }
  v10 = 0;
LABEL_13:
  if ( *(int *)(v3 + 148) >= 100 )
  {
    result = walt_is_idle_task((char *)v3);
    if ( (result & 1) == 0 )
    {
      result = walt_cfs_tick(v2);
      if ( !((*(_QWORD *)(v2 + 3568) == 0) | v10 & 1) && !*(_DWORD *)(v3 + 48) && *(_DWORD *)(v3 + 1368) != 1 )
      {
        v12 = raw_spin_lock_irqsave(&walt_lb_migration_lock);
        v13 = v12;
        if ( walt_rotation_enabled == 1 )
        {
          walt_lb_check_for_rotation(v2);
          return raw_spin_unlock_irqrestore(&walt_lb_migration_lock, v13);
        }
        _rcu_read_lock(v12);
        energy_efficient_cpu = walt_find_energy_efficient_cpu(v3, (unsigned int)v7, 0, 1);
        v15 = energy_efficient_cpu;
        _rcu_read_unlock(energy_efficient_cpu);
        if ( (v15 & 0x80000000) != 0
          || !(unsigned int)available_idle_cpu(v15)
          || (check_for_higher_capacity(v15, (unsigned int)v7) & 1) == 0
          || *(_DWORD *)(*(_QWORD *)&walt_rq[v6[v7] + 8] + 32LL) != min_possible_cluster_id
          && (task_fits_max_0(v3, v15) & 1) == 0 )
        {
          return raw_spin_unlock_irqrestore(&walt_lb_migration_lock, v13);
        }
        raw_spin_lock(v2);
        if ( *(_DWORD *)(v3 + 48) || *(_DWORD *)(v2 + 3576) )
        {
          raw_spin_unlock(v2);
          return raw_spin_unlock_irqrestore(&walt_lb_migration_lock, v13);
        }
        *(_DWORD *)(v2 + 3580) = v15;
        *(_DWORD *)(v2 + 3576) = 1;
        get_task_struct(v3);
        *(_QWORD *)&walt_rq[v5] = v3;
        raw_spin_unlock(v2);
        mark_reserved(v15);
        raw_spin_unlock_irqrestore(&walt_lb_migration_lock, v13);
        trace_walt_active_load_balance(v3, (unsigned int)v7, v15, v4);
        if ( (stop_one_cpu_nowait((unsigned int)v7, stop_walt_lb_active_migration, v2, v2 + 3584) & 1) != 0 )
          return wake_up_if_idle(v15);
        else
          return clear_reserved(v15, v16);
      }
    }
  }
  return result;
}
