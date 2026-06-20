__int64 __fastcall _qdf_mem_alloc_consistent(__int64 a1, __int64 a2, __int64 a3, __int64 a4, const char *a5, int a6)
{
  int v6; // w19
  __int64 result; // x0
  unsigned __int64 StatusReg; // x9
  unsigned int v9; // w8
  unsigned int v16; // w9

  v6 = a3;
  if ( (unsigned __int64)(a3 - 4194305) > 0xFFFFFFFFFFBFFFFFLL )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 || *(_DWORD *)(StatusReg + 16) )
    {
      v9 = 2080;
    }
    else
    {
      v9 = 2080;
      if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
      {
        if ( *(_DWORD *)(StatusReg + 1412) )
          v9 = 2080;
        else
          v9 = 3264;
      }
    }
    result = dma_alloc_attrs(a2, a3, a4, v9, 0);
    if ( result )
    {
      _X8 = &dword_716984;
      __asm { PRFM            #0x11, [X8] }
      do
        v16 = __ldxr((unsigned int *)&dword_716984);
      while ( __stxr(v16 + v6, (unsigned int *)&dword_716984) );
    }
  }
  else
  {
    qdf_trace_msg(56, 2, "Cannot malloc %zu bytes @ %s:%d", a3, a5, a6);
    return 0;
  }
  return result;
}
