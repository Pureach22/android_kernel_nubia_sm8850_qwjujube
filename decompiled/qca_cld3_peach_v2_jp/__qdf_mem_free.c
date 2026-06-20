__int64 __fastcall _qdf_mem_free(__int64 result)
{
  __int64 v1; // x19
  int v2; // w0
  unsigned int v9; // w9

  if ( result )
  {
    v1 = result;
    if ( (unsigned __int64)ksize(result) <= 0x2000 || (result = wcnss_prealloc_put(v1), !(_DWORD)result) )
    {
      v2 = ksize(v1);
      _X8 = &qdf_mem_stat;
      __asm { PRFM            #0x11, [X8] }
      do
        v9 = __ldxr((unsigned int *)&qdf_mem_stat);
      while ( __stxr(v9 - v2, (unsigned int *)&qdf_mem_stat) );
      return kfree(v1);
    }
  }
  return result;
}
