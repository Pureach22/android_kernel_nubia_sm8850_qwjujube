void __fastcall sub_65828(__int64 a1, int a2, unsigned int a3)
{
  __int64 v3; // x19
  __int64 v4; // x29
  unsigned __int64 StatusReg; // x20
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_DWORD *)(v4 - 4) = a2;
    v6 = _traceiter_rdev_set_antenna(0, v3 + 992, *(unsigned int *)(v4 - 4), a3);
    v7 = *(unsigned int *)(v4 - 4);
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v6, v7, a3);
  }
  JUMPOUT(0x657E8);
}
