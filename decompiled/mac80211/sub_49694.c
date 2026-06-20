void __fastcall sub_49694(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v2; // w21
  unsigned __int64 StatusReg; // x24
  __int64 v5; // x0
  __int64 v6; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v5 = _traceiter_drv_return_int(0, v1, v2);
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || (v5 = a1, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v5);
  }
  JUMPOUT(0x49168);
}
