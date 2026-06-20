__int64 zcomp_stream_put()
{
  unsigned __int64 StatusReg; // x8
  __int64 v1; // x9
  __int64 result; // x0

  _ReadStatusReg(TPIDR_EL1);
  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v1;
  if ( !v1 || !*(_QWORD *)(StatusReg + 16) )
    return preempt_schedule();
  return result;
}
