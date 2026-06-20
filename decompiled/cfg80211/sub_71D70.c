void __fastcall sub_71D70(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x20
  __int64 v4; // x29
  unsigned __int64 StatusReg; // x21
  __int64 channel; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v4 + 24) = a2;
    *(_DWORD *)(v4 - 4) = a3;
    channel = _traceiter_rdev_get_channel(0, v3 + 992, *(_QWORD *)(v4 + 24), *(unsigned int *)(v4 - 4));
    v7 = *(_QWORD *)(v4 + 24);
    v8 = *(unsigned int *)(v4 - 4);
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(channel, v7, v8);
  }
  JUMPOUT(0x71D28);
}
