void __fastcall sub_44F20(__int64 a1, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x29
  unsigned __int64 StatusReg; // x20
  __int64 v7; // x1
  __int64 v8; // x0
  __int64 v9; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v5 + 24) = a1;
    *(_DWORD *)(v5 - 12) = a2;
    v7 = *(_QWORD *)(v5 + 24);
    *(_QWORD *)(v5 - 8) = a3;
    _traceiter_drv_set_key(0, v7, *(unsigned int *)(v5 - 12), *(_QWORD *)(v5 - 8), a4, a5);
    v8 = *(_QWORD *)(v5 + 24);
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v8);
  }
  JUMPOUT(0x44EC4);
}
