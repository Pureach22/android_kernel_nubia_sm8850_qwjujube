__int64 __fastcall wiphy_work_cancel(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x20
  __int64 v4; // x0
  _QWORD *v5; // x8
  __int64 v6; // x9
  _QWORD *v7; // x10
  unsigned __int64 StatusReg; // x21
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x8

  if ( a1 )
  {
    v2 = a2;
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
      a1 = _traceiter_wiphy_work_cancel(0, 0, v2);
      v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v12;
      if ( !v12 || (a1 = 0, !*(_QWORD *)(StatusReg + 16)) )
      {
        preempt_schedule_notrace(a1, v10, v11);
        a1 = 0;
      }
    }
  }
  v3 = a1 - 24;
  v4 = raw_spin_lock_irqsave(a1 - 24);
  v5 = (_QWORD *)*v2;
  v6 = v4;
  if ( (_QWORD *)*v2 != v2 )
  {
    v7 = (_QWORD *)v2[1];
    if ( (_QWORD *)*v7 == v2 && (_QWORD *)v5[1] == v2 )
    {
      v5[1] = v7;
      *v7 = v5;
    }
    else
    {
      _list_del_entry_valid_or_report(v2);
    }
    *v2 = v2;
    v2[1] = v2;
  }
  return raw_spin_unlock_irqrestore(v3, v6);
}
