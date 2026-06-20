__int64 __fastcall _qdf_mem_valloc(__int64 a1, const char *a2, int a3)
{
  if ( a1 )
    return vzalloc_noprof();
  qdf_trace_msg(56, 2, "%s: Valloc called with 0 bytes @ %s:%d", "__qdf_mem_valloc", a2, a3);
  return 0;
}
