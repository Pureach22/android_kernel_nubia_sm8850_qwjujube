void __fastcall sub_43B5C(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned __int64 StatusReg; // x19
  __int64 updated; // x0
  __int64 v5; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    updated = _traceiter_sched_update_updown_migrate_values(0, a2, a3);
    v5 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v5;
    if ( !v5 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(updated);
  }
  JUMPOUT(0x43B48);
}
