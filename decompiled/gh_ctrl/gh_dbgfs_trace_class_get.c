__int64 __fastcall gh_dbgfs_trace_class_get(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0

  result = 0;
  _ReadStatusReg(SP_EL0);
  *a2 = 0;
  __asm { HVC             #0x603F }
  if ( a2 )
    *a2 = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
