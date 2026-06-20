__int64 __fastcall hdd_adapter_put(__int64 result)
{
  __int64 v1; // x9
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x9
  unsigned int *v4; // x9
  unsigned int v5; // w12
  __int64 v6; // x9

  v1 = *(_QWORD *)(result + 32);
  if ( v1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(StatusReg + 16);
    v3 = *(_QWORD *)(v1 + 1320);
    v4 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v3);
    do
      v5 = __ldxr(v4);
    while ( __stxr(v5 - 1, v4) );
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || !*(_QWORD *)(StatusReg + 16) )
      return preempt_schedule_notrace(result);
  }
  return result;
}
