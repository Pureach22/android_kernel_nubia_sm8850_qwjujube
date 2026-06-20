void __fastcall sub_10CBD0(__int64 a1, int a2)
{
  __int64 v2; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v4; // x0
  __int64 v5; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v2 + 24) = a1;
    *(_DWORD *)(v2 - 4) = a2;
    _traceiter_kgsl_pwr_request_state(0, *(_QWORD *)(v2 + 24), *(unsigned int *)(v2 - 4));
    v4 = *(_QWORD *)(v2 + 24);
    v5 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v5;
    if ( !v5 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v4);
  }
  JUMPOUT(0x10CBB8);
}
