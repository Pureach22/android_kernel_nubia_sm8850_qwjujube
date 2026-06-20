__int64 __fastcall sched_walt_oscillate(__int64 a1)
{
  __int64 v1; // x22
  unsigned int v2; // w19
  __int64 result; // x0
  unsigned int v4; // w5
  unsigned int v5; // w21
  unsigned __int64 v6; // x8
  __int64 v7; // x27
  char *v8; // x23
  __int64 v9; // x0
  __int64 v10; // x1
  int v11; // w8
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x28
  __int64 v15; // x1
  unsigned __int64 StatusReg; // x23
  __int64 v17; // x8
  unsigned int v23; // w8
  unsigned __int64 v26; // x9
  unsigned __int64 v29; // x10
  int v30; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v2 = a1;
  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  result = ((__int64 (__fastcall *)(__int64, int *))should_oscillate)(a1, &v30);
  if ( (result & 1) == 0 )
    goto LABEL_12;
  v5 = v2 + 1;
  v6 = *(unsigned int *)(*(_QWORD *)cpu_array + 8LL * (num_sched_clusters - 1));
  if ( *(_DWORD *)(*(_QWORD *)cpu_array + 8LL * (num_sched_clusters - 1)) )
  {
    if ( v5 > ((unsigned int)__clz(v6) ^ 0x3F) )
      v5 = __clz(__rbit64(v6));
  }
  else if ( v5 > 0x20 )
  {
    v5 = 32;
  }
  if ( v2 >= 0x20 )
    goto LABEL_27;
  v7 = *((_QWORD *)&_per_cpu_offset + v2);
  v8 = (char *)&runqueues + v7;
  v9 = raw_spin_lock_irqsave((char *)&runqueues + v7);
  v1 = *(_QWORD *)((char *)&runqueues + v7 + 3344);
  v10 = v9;
  if ( *(_DWORD *)(v1 + 48) )
  {
    v11 = 100;
LABEL_11:
    v30 = v11;
    result = raw_spin_unlock_irqrestore((char *)&runqueues + v7, v9);
LABEL_12:
    oscillate_cpu = -1;
    goto LABEL_13;
  }
  if ( ((*(_QWORD *)(*(_QWORD *)(v1 + 1376) + (((unsigned __int64)v5 >> 3) & 0x1FFFFFF8)) >> v5) & 1) == 0 )
  {
    v11 = 103;
    goto LABEL_11;
  }
  if ( *((_DWORD *)v8 + 894) )
  {
    v11 = 101;
    goto LABEL_11;
  }
  result = v1 + 64;
  *((_DWORD *)v8 + 895) = v5;
  *((_DWORD *)v8 + 894) = 1;
  __asm { PRFM            #0x11, [X0] }
  do
    v23 = __ldxr((unsigned int *)result);
  while ( __stxr(v23 + 1, (unsigned int *)result) );
  if ( v23 )
  {
    if ( (((v23 + 1) | v23) & 0x80000000) == 0 )
      goto LABEL_20;
    v14 = v10;
    v15 = 1;
  }
  else
  {
    v14 = v10;
    v15 = 2;
  }
  result = refcount_warn_saturate(result, v15);
  v10 = v14;
LABEL_20:
  *(_QWORD *)&walt_rq[v7] = v1;
  if ( v5 < 0x20 )
  {
    _X8 = (unsigned __int64 *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v5) + 80];
    __asm { PRFM            #0x11, [X8] }
    do
      v26 = __ldxr(_X8);
    while ( __stlxr(v26 | 2, _X8) );
    __dmb(0xBu);
    raw_spin_unlock_irqrestore((char *)&runqueues + v7, v10);
    oscillate_cpu = v2;
    result = stop_one_cpu_nowait(v2, stop_walt_lb_active_migration, (char *)&runqueues + v7, v8 + 3584);
    if ( (result & 1) == 0 )
    {
      v13 = *((_QWORD *)&_per_cpu_offset + v5);
      v30 = 102;
      _X8 = (unsigned __int64 *)&walt_rq[v13 + 80];
      __asm { PRFM            #0x11, [X8] }
      do
        v29 = __ldxr(_X8);
      while ( __stxr(v29 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
      goto LABEL_12;
    }
    result = wake_up_if_idle(v5);
    v12 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
    if ( (unsigned int)v12 <= 0x1F )
    {
      oscillate_ts_ns = *(_QWORD *)((char *)&cpu_irqtime + *((_QWORD *)&_per_cpu_offset + v12) + 16);
      goto LABEL_13;
    }
  }
LABEL_27:
  __break(0x5512u);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    result = _traceiter_walt_oscillate(0, v1, v2, v5, 0xFFFFFFFF, v4);
    v17 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v17;
    if ( !v17 || !*(_QWORD *)(StatusReg + 16) )
      result = preempt_schedule_notrace(result);
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
