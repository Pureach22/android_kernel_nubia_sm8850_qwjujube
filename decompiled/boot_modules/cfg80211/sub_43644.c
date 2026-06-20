void __usercall sub_43644(__int64 a1@<X0>, __int64 a2@<X1>, __int64 a3@<X2>, char a4@<W3>, __int64 a5@<X8>)
{
  __int64 v5; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v5 + 24) = a2;
    *(_QWORD *)(v5 - 8) = a3;
    _traceiter_cfg80211_tx_mlme_mgmt(0, a5, *(_QWORD *)(v5 + 24), *(_QWORD *)(v5 - 8), a4 & 1);
    v7 = *(_QWORD *)(v5 + 24);
    v8 = *(_QWORD *)(v5 - 8);
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1, v7, v8);
  }
  JUMPOUT(0x43600);
}
