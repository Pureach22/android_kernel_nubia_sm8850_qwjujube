void __fastcall sub_74B18(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x20
  __int64 v6; // x0
  __int64 v7; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v6 = _traceiter_kgsl_constraint(0, a1, a3, a4, 0, 0);
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || (v6 = a1, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v6);
  }
  JUMPOUT(0x74978);
}
