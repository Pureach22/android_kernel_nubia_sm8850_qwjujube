void __fastcall sub_8AF8(int a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v6; // x0
  __int64 v7; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_DWORD *)(v4 + 28) = a1;
    _traceiter_rmnet_shs_low(0, 5, 20, a4, *(unsigned int *)(v4 + 28), 3567, 3567, 0);
    v6 = *(unsigned int *)(v4 + 28);
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v6);
  }
  JUMPOUT(0x8AE4);
}
