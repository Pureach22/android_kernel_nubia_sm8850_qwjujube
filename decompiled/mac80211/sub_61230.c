void __usercall sub_61230(__int64 a1@<X0>, int a2@<W1>, __int64 a3@<X8>)
{
  __int64 v3; // x9
  __int64 v4; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v6; // x0
  __int64 v7; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v4 + 24) = a1;
    *(_DWORD *)(v4 - 4) = a2;
    _traceiter_api_cqm_beacon_loss_notify(0, a3, a1 + v3);
    v6 = *(_QWORD *)(v4 + 24);
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v6);
  }
  JUMPOUT(0x61210);
}
