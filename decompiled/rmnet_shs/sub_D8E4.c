void __fastcall sub_D8E4(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x29
  unsigned __int64 StatusReg; // x21
  __int64 v6; // x0
  __int64 v7; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v4 + 24) = a1;
    _traceiter_rmnet_shs_high(0, 8, 40, a4, 3567, 3567, 3567, 0);
    v6 = *(_QWORD *)(v4 + 24);
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v6);
  }
  JUMPOUT(0xD814);
}
