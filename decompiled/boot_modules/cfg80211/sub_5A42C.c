void __fastcall sub_5A42C(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x29
  unsigned __int64 StatusReg; // x23
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v5 + 24) = a3;
    v7 = _traceiter_rdev_testmode_cmd(0, v3, v4);
    v9 = *(_QWORD *)(v5 + 24);
    v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v10;
    if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v7, v8, v9);
  }
  JUMPOUT(0x5A3D4);
}
