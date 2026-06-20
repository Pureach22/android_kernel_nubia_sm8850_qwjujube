void __usercall sub_B36CC(__int64 a1@<X0>, __int64 a2@<X8>)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x29
  unsigned __int64 StatusReg; // x21
  __int64 v6; // x0
  __int64 v7; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v4 + 24) = a1;
    _traceiter_drv_wake_tx_queue(0, *(_QWORD *)(v4 + 24), v3 + a2, v2);
    v6 = *(_QWORD *)(v4 + 24);
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v6);
  }
  JUMPOUT(0xB362C);
}
