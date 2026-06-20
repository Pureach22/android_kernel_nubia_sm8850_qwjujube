void __fastcall sub_725D8(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x29
  unsigned __int64 StatusReg; // x21
  __int64 v5; // x0
  __int64 v6; // x2
  __int64 v7; // x1
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v3 + 24) = a2;
    v5 = _traceiter_rdev_leave_ocb(0, a1 + 992, *(_QWORD *)(v3 + 24));
    v7 = *(_QWORD *)(v3 + 24);
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || (v5 = v2, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v5, v7, v6);
  }
  JUMPOUT(0x7257C);
}
