__int64 __fastcall gh_dbgfs_trace_class_set(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = a2;
  _ReadStatusReg(SP_EL0);
  __asm { HVC             #0x603F }
  if ( (int)a2 > 29 )
  {
    if ( (unsigned int)a2 <= 0x3D )
    {
      if ( ((1LL << a2) & 0x7C000040000000LL) != 0 )
      {
        result = 4294967283LL;
        goto LABEL_15;
      }
      if ( ((1LL << a2) & 0x3000030000000000LL) != 0 )
      {
        result = 0xFFFFFFFFLL;
        goto LABEL_15;
      }
      if ( ((1LL << a2) & 0x180000000LL) != 0 )
      {
        result = 4294967280LL;
        goto LABEL_15;
      }
    }
LABEL_14:
    result = 4294967274LL;
    goto LABEL_15;
  }
  if ( (_DWORD)a2 == -1 )
  {
    result = 4294967201LL;
    goto LABEL_15;
  }
  if ( (_DWORD)a2 )
  {
    if ( (_DWORD)a2 == 10 )
    {
      result = 4294967284LL;
      goto LABEL_15;
    }
    goto LABEL_14;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
