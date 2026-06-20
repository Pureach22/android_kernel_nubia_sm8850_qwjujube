void __fastcall sub_5E3E0(int a1)
{
  __int64 v1; // x19
  __int64 v2; // x29
  unsigned __int64 StatusReg; // x20
  unsigned __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = *(unsigned int *)(StatusReg + 40);
  *(_DWORD *)(v2 - 8) = a1;
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + ((v4 >> 3) & 0x1FFFFFF8)) >> v4) & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v5 = _traceiter_rdev_return_int(0, v1 + 992, *(unsigned int *)(v2 - 8));
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v5, v6, v7);
  }
  JUMPOUT(0x5E34C);
}
