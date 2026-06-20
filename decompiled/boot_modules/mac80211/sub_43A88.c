void __usercall sub_43A88(__int64 a1@<X0>, int a2@<W2>, __int64 a3@<X3>, unsigned int a4@<W8>)
{
  __int64 v4; // x19
  __int64 v5; // x29
  unsigned __int64 StatusReg; // x21
  __int64 v7; // x0
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v5 + 24) = a1;
    *(_DWORD *)(v5 - 4) = a2;
    _traceiter_drv_conf_tx(0, *(_QWORD *)(v5 + 24), v4, a4, *(unsigned int *)(v5 - 4), a3);
    v7 = *(_QWORD *)(v5 + 24);
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v7);
  }
  JUMPOUT(0x43A14);
}
