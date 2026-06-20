void __usercall sub_61318(__int64 a1@<X0>, int a2@<W1>, int a3@<W2>, __int64 a4@<X8>)
{
  __int64 v4; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v6; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_DWORD *)(v4 + 28) = a2;
    *(_DWORD *)(v4 + 24) = a3;
    _traceiter_api_enable_rssi_reports(0, a1 + a4, *(unsigned int *)(v4 + 28), *(unsigned int *)(v4 + 24));
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x612D0);
}
