void *__fastcall qdf_mem_malloc_atomic_fl(size_t a1, __int64 a2, unsigned int a3)
{
  void *v6; // x0
  void *v7; // x20
  __int64 v9; // x0
  __int64 v10; // x19
  int v11; // w0
  unsigned int v18; // w9

  if ( a1 - 4194305 <= 0xFFFFFFFFFFBFFFFFLL )
  {
    qdf_trace_msg(56, 2, "Cannot malloc %zu bytes @ %s:%d", a1, a2, a3);
    return nullptr;
  }
  if ( a1 > 0x2000 )
  {
    v6 = (void *)wcnss_prealloc_get(a1);
    if ( v6 )
    {
      v7 = v6;
      memset(v6, 0, a1);
      return v7;
    }
  }
  v9 = _kmalloc_noprof(a1, 2336);
  if ( !v9 )
  {
    qdf_trace_msg(56, 3, "Failed to malloc %zuB @ %s:%d", a1, a2, a3);
    return nullptr;
  }
  v10 = v9;
  v11 = ksize(v9);
  _X8 = &qdf_mem_stat;
  __asm { PRFM            #0x11, [X8] }
  do
    v18 = __ldxr((unsigned int *)&qdf_mem_stat);
  while ( __stxr(v18 + v11, (unsigned int *)&qdf_mem_stat) );
  return (void *)v10;
}
