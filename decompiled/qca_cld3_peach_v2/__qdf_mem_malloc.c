__int64 __fastcall _qdf_mem_malloc(size_t a1, const char *a2, int a3)
{
  __int64 result; // x0
  void *v5; // x0
  void *v6; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x1
  __int64 v9; // x19
  int v10; // w0
  unsigned int v17; // w9

  if ( a1 - 4194305 > 0xFFFFFFFFFFBFFFFFLL )
  {
    if ( a1 > 0x2000 && (v5 = (void *)wcnss_prealloc_get(a1)) != nullptr )
    {
      v6 = v5;
      memset(v5, 0, a1);
      return (__int64)v6;
    }
    else
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 || *(_DWORD *)(StatusReg + 16) )
      {
        v8 = 2336;
      }
      else
      {
        v8 = 2336;
        if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
        {
          if ( *(_DWORD *)(StatusReg + 1412) )
            v8 = 2336;
          else
            v8 = 3520;
        }
      }
      result = _kmalloc_noprof(a1, v8);
      if ( result )
      {
        v9 = result;
        v10 = ksize();
        _X8 = &qdf_mem_stat;
        __asm { PRFM            #0x11, [X8] }
        do
          v17 = __ldxr((unsigned int *)&qdf_mem_stat);
        while ( __stxr(v17 + v10, (unsigned int *)&qdf_mem_stat) );
        return v9;
      }
    }
  }
  else
  {
    qdf_trace_msg(56, 2, "Cannot malloc %zu bytes @ %s:%d", a1, a2, a3);
    return 0;
  }
  return result;
}
