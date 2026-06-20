void __fastcall sub_695F0(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v4; // x29
  unsigned __int64 StatusReg; // x21
  __int64 station; // x0
  __int64 v7; // x1
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v4 + 24) = a2;
    station = _traceiter_rdev_get_station(0, v3 + 992, *(_QWORD *)(v4 + 24), a3);
    v7 = *(_QWORD *)(v4 + 24);
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(station, v7, a3);
  }
  JUMPOUT(0x695A8);
}
