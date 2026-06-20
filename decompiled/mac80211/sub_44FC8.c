void __fastcall sub_44FC8(int a1)
{
  __int64 v1; // x19
  __int64 v2; // x29
  unsigned __int64 StatusReg; // x20
  unsigned __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = *(unsigned int *)(StatusReg + 40);
  *(_DWORD *)(v2 + 24) = a1;
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + ((v4 >> 3) & 0x1FFFFFF8)) >> v4) & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v5 = _traceiter_drv_return_int(0, v1, *(unsigned int *)(v2 + 24));
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v5);
  }
  JUMPOUT(0x44EF8);
}
