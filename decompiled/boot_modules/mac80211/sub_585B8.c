void __fastcall sub_585B8(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x22
  __int64 can_neg_ttlm; // x0
  __int64 v6; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    can_neg_ttlm = _traceiter_drv_can_neg_ttlm(0, a1, a2, a3);
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || (can_neg_ttlm = a1, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(can_neg_ttlm);
  }
  JUMPOUT(0x5854C);
}
