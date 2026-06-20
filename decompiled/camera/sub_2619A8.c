void __fastcall sub_2619A8(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w22
  __int64 v3; // x0
  __int64 v4; // x8
  unsigned __int64 StatusReg; // [xsp+8h] [xbp+8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v3 = _traceiter_cam_cci_burst(0, a2, 0, 0, (__int64)"th_irq honoured irq1", v2);
    v4 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v4;
    if ( !v4 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v3);
  }
  JUMPOUT(0x261018);
}
