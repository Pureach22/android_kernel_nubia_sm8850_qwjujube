void __fastcall sub_20EC0(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        char a12)
{
  __int64 v12; // x20
  unsigned int v13; // w21
  unsigned int v14; // w22
  __int64 v15; // x29
  unsigned __int64 StatusReg; // x23
  __int64 v17; // x0
  __int64 v18; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v17 = _traceiter_print_icmp_tx(0, v12, a3, v13, v14, v15 - 56, (__int64)&a12);
    v18 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v18;
    if ( !v18 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v17);
  }
  JUMPOUT(0x2087C);
}
