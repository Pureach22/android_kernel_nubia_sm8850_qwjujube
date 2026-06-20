void __usercall sub_56480(__int64 a1@<X0>, __int64 a2@<X2>, __int64 a3@<X8>)
{
  __int64 v3; // x19
  __int64 v4; // x29
  unsigned __int64 StatusReg; // x20
  __int64 v6; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v4 - 8) = a2;
    _traceiter_drv_ipv6_addr_change(0, a1 + v3, a3 + 2688);
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(a1);
  }
  JUMPOUT(0x5641C);
}
