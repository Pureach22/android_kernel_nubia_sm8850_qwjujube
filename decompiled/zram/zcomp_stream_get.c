__int64 __fastcall zcomp_stream_get(__int64 *a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v2; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  ++*(_DWORD *)(StatusReg + 16);
  v2 = *a1;
  return _ReadStatusReg(TPIDR_EL1) + v2;
}
