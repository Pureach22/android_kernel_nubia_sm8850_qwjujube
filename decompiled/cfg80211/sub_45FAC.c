void __usercall sub_45FAC(__int64 a1@<X0>, unsigned int a2@<W8>)
{
  __int64 v2; // x22
  unsigned __int64 StatusReg; // x21
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v4 = _traceiter_rdev_return_int(0, a1 + 992, a2);
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || (v4 = v2, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v4, v5, v6);
  }
  JUMPOUT(0x45E8C);
}
