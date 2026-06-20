void __usercall sub_15294(
        __int64 a1@<X8>,
        __int64 a2,
        char a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        char a9)
{
  __int64 v9; // x9
  __int64 v10; // x21
  unsigned int v11; // w22
  unsigned __int64 StatusReg; // x20
  __int64 v13; // x0
  __int64 v14; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v13 = _traceiter_print_udp_rx(0, v10, &a9, &a3, a1 + v9, v11);
    v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v14;
    if ( !v14 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v13);
  }
  JUMPOUT(0x15220);
}
