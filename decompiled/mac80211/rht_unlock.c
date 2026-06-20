unsigned __int64 *__fastcall rht_unlock(unsigned __int64 *result, unsigned __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x9
  unsigned __int64 v4; // x19
  unsigned __int64 v10; // x9

  __asm { PRFM            #0x11, [X0] }
  do
    v10 = __ldxr(result);
  while ( __stlxr(v10 & 0xFFFFFFFFFFFFFFFELL, result) );
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v3;
  if ( !v3 || !*(_QWORD *)(StatusReg + 16) )
  {
    v4 = a2;
    result = (unsigned __int64 *)preempt_schedule();
    a2 = v4;
  }
  _WriteStatusReg(DAIF, a2);
  return result;
}
