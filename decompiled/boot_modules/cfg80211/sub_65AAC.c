void __fastcall sub_65AAC(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 v5; // x29
  unsigned __int64 StatusReg; // x20
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
    *(_QWORD *)(v5 - 8) = a2;
    *(_DWORD *)(v5 - 12) = a3;
    v7 = _traceiter_rdev_set_ap_chanwidth(0, v4 + 992, *(_QWORD *)(v5 - 8), *(unsigned int *)(v5 - 12), a4);
    v8 = *(_QWORD *)(v5 - 8);
    v9 = *(unsigned int *)(v5 - 12);
    v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v10;
    if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v7, v8, v9);
  }
  JUMPOUT(0x65A6C);
}
