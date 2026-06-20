void __fastcall android_rvh_try_to_wake_up(__int64 a1, __int64 a2)
{
  int v2; // w18
  __int64 v3; // x28
  __int64 v4; // x8
  _DWORD *v6; // x22
  __int64 v7; // x8
  unsigned __int64 StatusReg; // x23
  char *v14; // x20
  __int64 v15; // x0
  __int64 v16; // x1
  void *v17; // x8
  int v18; // w26
  __int64 v19; // x21
  char *v20; // x0
  _BYTE *v21; // x8
  __int64 v22; // x0
  __int64 lock; // x0
  __int64 v24; // x19
  unsigned int v25; // w9

  v4 = *(unsigned int *)(a2 + 40);
  if ( (unsigned int)v4 >= 0x20 )
  {
    __break(0x5512u);
    *(_DWORD *)(v3 + 144) = v2;
    android_rvh_tick_entry();
  }
  else
  {
    if ( (_UNKNOWN *)a2 == &init_task )
      v6 = &vendor_data_pad;
    else
      v6 = (_DWORD *)(a2 + 5184);
    if ( (walt_disabled & 1) == 0 )
    {
      v7 = *((_QWORD *)&_per_cpu_offset + v4);
      StatusReg = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v14 = (char *)&runqueues + v7;
      v15 = raw_spin_rq_lock_nested((char *)&runqueues + v7, 0);
      v17 = *((void **)v14 + 444);
      *((_DWORD *)v14 + 848) &= 3u;
      if ( v17 && v17 != &balance_push_callback && (rq_pin_lock___already_done & 1) == 0 )
      {
        rq_pin_lock___already_done = 1;
        v15 = _warn_printk("rq->balance_callback && rq->balance_callback != &balance_push_callback");
        __break(0x800u);
      }
      v18 = v6[7];
      if ( walt_clock_suspended == 1 )
        v19 = sched_clock_last;
      else
        v19 = sched_clock(v15, v16);
      *((_BYTE *)v6 + 386) &= ((unsigned int)*((char *)v6 + 386) >> 7) & 0x7F;
      v20 = *((char **)v14 + 418);
      v21 = v20 + 5184;
      if ( v20 == (char *)&init_task )
        v21 = &vendor_data_pad;
      if ( (*v21 & 4) != 0 && (*(_WORD *)(a2 + 1728) & 8) != 0 )
        walt_update_task_ravg(v20, v14);
      walt_update_task_ravg(a2, v14);
      *((_QWORD *)v6 + 28) = v19;
      v22 = raw_spin_rq_unlock(v14);
      _WriteStatusReg(DAIF, StatusReg);
      lock = _rcu_read_lock(v22);
      v24 = *((_QWORD *)v6 + 30);
      if ( v24 )
      {
        if ( v6[7] - v18 >= 0 )
          v25 = v6[7] - v18;
        else
          v25 = v18 - v6[7];
        if ( v25 > (unsigned int)sched_ravg_window >> 2
          || v19 - *(_QWORD *)(v24 + 64) > (unsigned __int64)(unsigned int)sched_ravg_window )
        {
          raw_spin_lock(v24 + 4);
          set_preferred_cluster(v24, v19);
          lock = raw_spin_unlock(v24 + 4);
        }
      }
      _rcu_read_unlock(lock);
    }
  }
}
