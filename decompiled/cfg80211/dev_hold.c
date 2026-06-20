__int64 __fastcall dev_hold(__int64 result, __int64 a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v4; // x9
  unsigned int *v5; // x9
  unsigned int v6; // w12
  __int64 v7; // x9

  if ( result )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(StatusReg + 16);
    v4 = *(_QWORD *)(result + 1320);
    v5 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v4);
    do
      v6 = __ldxr(v5);
    while ( __stxr(v6 + 1, v5) );
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || !*(_QWORD *)(StatusReg + 16) )
      return preempt_schedule_notrace(result, a2, a3);
  }
  return result;
}
