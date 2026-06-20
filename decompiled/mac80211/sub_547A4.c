void __usercall sub_547A4(__int64 a1@<X0>, __int64 a2@<X8>)
{
  __int64 v2; // x19
  __int64 v3; // x29
  unsigned __int64 StatusReg; // x21
  __int64 v5; // x0
  __int64 v6; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v3 - 8) = a1;
    _traceiter_drv_link_info_changed(0, v2, *(_QWORD *)(v3 - 8), a1 + a2);
    v5 = *(_QWORD *)(v3 - 8);
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v5);
  }
  JUMPOUT(0x5459C);
}
