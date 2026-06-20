void __fastcall sub_7F344(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x19
  unsigned int v7; // w20
  unsigned int v8; // w23
  unsigned __int64 StatusReg; // x21
  __int64 v11; // x0
  __int64 v12; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v11 = _traceiter_kgsl_issueibcmds(0, v6, a3, v7, a5, a6, v8);
    v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v12;
    if ( !v12 || (v11 = a1, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v11);
  }
  JUMPOUT(0x7F300);
}
