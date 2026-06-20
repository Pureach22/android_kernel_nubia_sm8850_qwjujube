void __usercall sub_4B69C(unsigned int a1@<W1>, unsigned int a2@<W8>)
{
  __int64 v2; // x19
  unsigned __int64 StatusReg; // x20
  __int64 busiest_queue; // x0
  __int64 v5; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    busiest_queue = _traceiter_walt_find_busiest_queue(0, a1, a2, v2);
    v5 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v5;
    if ( !v5 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(busiest_queue);
  }
  JUMPOUT(0x4B668);
}
