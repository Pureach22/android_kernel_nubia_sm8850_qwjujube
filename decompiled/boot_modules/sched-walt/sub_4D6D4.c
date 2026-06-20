void __fastcall sub_4D6D4(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x19
  __int64 v5; // x21
  unsigned int v6; // w22
  unsigned __int64 StatusReg; // x20
  __int64 v8; // x0
  __int64 v9; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v8 = _traceiter_sched_select_task_rt(0, v4, v6, a4, v5);
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v8);
  }
  JUMPOUT(0x4D648);
}
