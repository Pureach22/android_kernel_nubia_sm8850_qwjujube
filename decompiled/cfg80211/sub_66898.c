void __fastcall sub_66898(__int64 a1, __int64 a2, int a3, unsigned int a4, char a5, __int64 a6)
{
  __int64 v6; // x19
  __int64 v7; // x29
  unsigned __int64 StatusReg; // x20
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v7 - 16) = a6;
    *(_QWORD *)(v7 - 8) = a2;
    *(_DWORD *)(v7 - 20) = a3;
    v9 = _traceiter_rdev_add_key(
           0,
           v6 + 992,
           *(_QWORD *)(v7 - 8),
           *(unsigned int *)(v7 - 20),
           a4,
           a5 & 1,
           *(_QWORD *)(v7 - 16));
    v10 = *(_QWORD *)(v7 - 8);
    v11 = *(unsigned int *)(v7 - 20);
    v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v12;
    if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v9, v10, v11);
  }
  JUMPOUT(0x66854);
}
