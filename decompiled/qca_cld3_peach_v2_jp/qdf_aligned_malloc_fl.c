__int64 __fastcall qdf_aligned_malloc_fl(
        unsigned int *a1,
        __int64 *a2,
        __int64 *a3,
        __int64 *a4,
        unsigned int a5,
        const char *a6,
        unsigned int a7)
{
  __int64 v14; // x0
  __int64 v15; // x8
  unsigned __int64 v16; // x12
  __int64 v17; // x9
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 v20; // x27
  size_t v21; // x26
  int v22; // w0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x9
  unsigned __int64 v26; // x12
  __int64 v27; // x8
  __int64 v28; // x9
  __int64 v29; // x8
  unsigned int v37; // w9

  v14 = _qdf_mem_malloc(*a1, a6, a7);
  *a2 = v14;
  if ( v14 )
  {
    v15 = v14 << 8 >> 8;
    v16 = (unsigned __int64)(v15 + 0x8000000000LL) >> 38;
    v17 = memstart_addr + v15 + 0x8000000000LL;
    v18 = v15 - kimage_voffset;
    if ( !v16 )
      v18 = v17;
    v19 = a5 - 1;
    *a3 = v18;
    if ( (v18 & v19) == 0 )
      goto LABEL_13;
    v20 = *a2;
    v21 = (unsigned int)v19 + *a1;
    if ( *a2 && ((unsigned __int64)ksize(*a2) <= 0x2000 || !(unsigned int)wcnss_prealloc_put(v20)) )
    {
      v22 = ksize(v20);
      _X8 = &qdf_mem_stat;
      __asm { PRFM            #0x11, [X8] }
      do
        v37 = __ldxr((unsigned int *)&qdf_mem_stat);
      while ( __stxr(v37 - v22, (unsigned int *)&qdf_mem_stat) );
      kfree(v20);
    }
    v23 = _qdf_mem_malloc(v21, a6, a7);
    *a2 = v23;
    if ( v23 )
    {
      v24 = v23 << 8 >> 8;
      v25 = v24 + 0x8000000000LL;
      v26 = (unsigned __int64)(v24 + 0x8000000000LL) >> 38;
      v27 = v24 - kimage_voffset;
      v28 = memstart_addr + v25;
      if ( !v26 )
        v27 = v28;
      *a3 = v27;
      *a1 = v21;
      v18 = *a3;
LABEL_13:
      v29 = (a5 + v18 - 1) & -(__int64)a5;
      *a4 = v29;
      return v29 - *a3 + *a2;
    }
    qdf_trace_msg(56, 3, "%s: Failed to alloc %uB @ %s:%d", "qdf_aligned_malloc_fl", (unsigned int)v21, a6, a7);
  }
  else
  {
    qdf_trace_msg(56, 3, "%s: Failed to alloc %uB @ %s:%d", "qdf_aligned_malloc_fl", *a1, a6, a7);
  }
  return 0;
}
