void __usercall sub_623FC(__int64 a1@<X1>, int a2@<W2>, __int64 a3@<X8>)
{
  __int64 v3; // x19
  __int64 v4; // x29
  unsigned __int64 StatusReg; // x20
  __int64 v6; // x0
  __int64 v7; // x2
  __int64 v8; // x1
  __int64 v9; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v4 - 8) = a1;
    *(_DWORD *)(v4 - 12) = a2;
    v6 = _traceiter_rdev_del_tx_ts(0, v3 + 992, *(_QWORD *)(v4 - 8), *(unsigned int *)(v4 - 12), a3 + 4);
    v7 = *(unsigned int *)(v4 - 12);
    v8 = *(_QWORD *)(v4 - 8);
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v6, v8, v7);
  }
  JUMPOUT(0x623A4);
}
