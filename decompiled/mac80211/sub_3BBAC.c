void __usercall sub_3BBAC(__int64 a1@<X0>, __int64 a2@<X8>)
{
  __int64 v2; // x9
  __int64 v3; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v5; // x10

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v3 + 24) = v2;
    _traceiter_drv_channel_switch_beacon(0, *(_QWORD *)(v3 + 24), a1, a2);
    v5 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v5;
    if ( !v5 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x3BB64);
}
