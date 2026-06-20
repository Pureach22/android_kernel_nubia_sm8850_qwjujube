void __fastcall sub_42B30(int a1)
{
  __int64 v1; // x20
  __int64 v2; // x29
  unsigned __int64 StatusReg; // x22
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x0
  __int64 v7; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_DWORD *)(v2 - 4) = a1;
    _traceiter_rdev_return_int(0, v1 + 992, *(unsigned int *)(v2 - 4));
    v6 = *(unsigned int *)(v2 - 4);
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v6, v4, v5);
  }
  JUMPOUT(0x42A28);
}
