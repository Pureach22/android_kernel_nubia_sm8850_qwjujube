void __fastcall sub_21FF08(__int64 a1, __int64 a2, unsigned int a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x19
  unsigned int v6; // w21
  unsigned __int64 StatusReg; // x23
  __int64 v8; // x0
  __int64 v9; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v8 = _traceiter_cam_isp_activated_irq(0, v5, a3, v6, a5);
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v8);
  }
  JUMPOUT(0x21FD30);
}
