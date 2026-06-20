__int64 __fastcall wiphy_work_queue(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x19
  _QWORD *v3; // x20
  __int64 v4; // x9
  __int64 v5; // x2
  _QWORD *v6; // x1
  unsigned __int64 StatusReg; // x21
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x8

  if ( a1 )
  {
    v2 = a1;
    v3 = a2;
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v9 = _traceiter_wiphy_work_queue(0, v2, v3);
      v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v12;
      if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v9, v10, v11);
    }
  }
  v4 = raw_spin_lock_irqsave(v2 - 24);
  if ( (_QWORD *)*v3 == v3 )
  {
    v5 = v2 - 40;
    v6 = *(_QWORD **)(v2 - 32);
    if ( (_QWORD *)(v2 - 40) == v3 || v6 == v3 || *v6 != v5 )
    {
      _list_add_valid_or_report(v3, v6);
    }
    else
    {
      *(_QWORD *)(v2 - 32) = v3;
      *v3 = v5;
      v3[1] = v6;
      *v6 = v3;
    }
  }
  raw_spin_unlock_irqrestore(v2 - 24, v4);
  return queue_work_on(32, system_unbound_wq, v2 - 72);
}
