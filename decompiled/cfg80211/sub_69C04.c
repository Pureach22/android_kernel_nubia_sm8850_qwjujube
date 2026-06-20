void __fastcall sub_69C04(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 v5; // x29
  unsigned __int64 StatusReg; // x20
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v5 - 8) = a2;
    v7 = _traceiter_rdev_change_station(0, v4 + 992, *(_QWORD *)(v5 - 8), a3, a4);
    v8 = *(_QWORD *)(v5 - 8);
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v7, v8, a3);
  }
  JUMPOUT(0x69BC4);
}
