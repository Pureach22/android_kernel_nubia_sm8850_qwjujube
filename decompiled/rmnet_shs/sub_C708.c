void __fastcall sub_C708(unsigned int a1)
{
  __int64 v1; // x19
  unsigned __int64 StatusReg; // x21
  __int64 v4; // x0
  __int64 v5; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v4 = _traceiter_rmnet_shs_low(0, 2, 10, a1, 3567, 3567, 3567, v1);
    v5 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v5;
    if ( !v5 || (v4 = a1, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v4);
  }
  JUMPOUT(0xC6D4);
}
