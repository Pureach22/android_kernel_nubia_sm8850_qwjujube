void __fastcall sub_1084C(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x24
  __int64 v5; // x25
  __int64 v6; // x26
  __int64 v7; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v9; // x0
  __int64 v10; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v9 = _traceiter_rmnet_shs_high(0, 8, 54, a4, *(unsigned int *)(v7 - 8), v6, v5, v4);
    v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v10;
    if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v9);
  }
  JUMPOUT(0x10634);
}
