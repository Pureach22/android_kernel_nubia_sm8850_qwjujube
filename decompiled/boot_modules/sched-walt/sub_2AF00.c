void __usercall sub_2AF00(__int64 a1@<X1>, unsigned __int16 a2@<W2>, int a3@<W8>)
{
  __int64 v3; // x29
  unsigned __int64 StatusReg; // x19
  __int64 updated; // x0
  __int64 v6; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_DWORD *)(v3 + 28) = a3;
    updated = _traceiter_sched_update_pred_demand(0, a1, a2, (unsigned __int16)a3);
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(updated);
  }
  JUMPOUT(0x2AEE0);
}
