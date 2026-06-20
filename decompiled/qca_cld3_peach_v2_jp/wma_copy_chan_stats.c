__int64 __fastcall wma_copy_chan_stats(
        unsigned int a1,
        const void *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  const void *v11; // x21
  __int64 v15; // x23
  __int64 v16; // x0
  size_t v18; // x0
  void *v19; // x0

  v11 = *(const void **)(a3 + 72);
  if ( !v11 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Num of channels in first event %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wma_copy_chan_stats",
      a1);
    *(_DWORD *)(a3 + 68) = a1;
    *(_QWORD *)(a3 + 72) = a2;
    return 0;
  }
  v15 = *(unsigned int *)(a3 + 68);
  if ( (unsigned int)v15 + a1 < 0x67 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Num of channels in Second event %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wma_copy_chan_stats",
      a1);
    v18 = 32LL * (*(_DWORD *)(a3 + 68) + a1);
    *(_DWORD *)(a3 + 68) += a1;
    v19 = (void *)_qdf_mem_malloc(v18, "wma_copy_chan_stats", 2335);
    *(_QWORD *)(a3 + 72) = v19;
    if ( !v19 )
    {
      _qdf_mem_free((__int64)a2);
      _qdf_mem_free((__int64)v11);
      return 4294967284LL;
    }
    qdf_mem_copy(v19, v11, (unsigned int)(32 * v15));
    qdf_mem_copy((void *)(*(_QWORD *)(a3 + 72) + 32 * v15), a2, 32 * a1);
    _qdf_mem_free((__int64)a2);
    v16 = (__int64)v11;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: total chan stats num unexpected %d new %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wma_copy_chan_stats",
      (unsigned int)v15,
      a1);
    v16 = (__int64)a2;
  }
  _qdf_mem_free(v16);
  return 0;
}
