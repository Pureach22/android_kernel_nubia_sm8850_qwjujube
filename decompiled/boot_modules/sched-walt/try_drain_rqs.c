__int64 __fastcall try_drain_rqs(_QWORD *a1)
{
  unsigned __int64 StatusReg; // x23
  __int64 v4; // x22
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x27
  char v8; // w8
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x22

  if ( (((__int64 (*)(void))kthread_should_stop)() & 1) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      v4 = raw_spin_lock_irqsave(&walt_drain_pending_lock);
      if ( (unsigned int)_sw_hweight64(*(unsigned int *)a1) )
      {
        v7 = *(unsigned int *)a1;
        raw_spin_unlock_irqrestore(&walt_drain_pending_lock, v4);
        v8 = 0;
        do
        {
          v9 = v7 & (-1LL << v8);
          if ( !v9 )
            break;
          v10 = __clz(__rbit64(v9));
          if ( ((_cpu_online_mask >> v10) & 1) != 0 && !(unsigned int)available_idle_cpu((unsigned int)v10) )
            stop_one_cpu((unsigned int)v10, &drain_rq_cpu_stop, 0);
          v8 = v10 + 1;
        }
        while ( v10 < 0x1F );
        v4 = raw_spin_lock_irqsave(&walt_drain_pending_lock);
        *a1 &= v7 ^ 0xFFFFFFFFLL;
      }
      v5 = raw_spin_unlock_irqrestore(&walt_drain_pending_lock, v4);
      *(_DWORD *)(StatusReg + 48) = 1;
      __dmb(0xBu);
      v6 = schedule(v5);
      *(_DWORD *)(StatusReg + 48) = 0;
      __dmb(0xBu);
    }
    while ( (kthread_should_stop(v6) & 1) == 0 );
  }
  return 0;
}
