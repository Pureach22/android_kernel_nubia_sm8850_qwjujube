void __fastcall sub_7244C(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x21
  unsigned __int64 StatusReg; // x22
  __int64 v5; // x0
  __int64 v6; // x2
  __int64 v7; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v5 = _traceiter_rdev_join_ocb(0, a1 + 992, a2, v2);
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || (v5 = v3, v6 = v2, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v5, a2, v6);
  }
  JUMPOUT(0x723E0);
}
