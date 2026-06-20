__int64 __fastcall wma_unified_radio_tx_mem_free(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x20
  unsigned int v11; // w21
  __int64 *v12; // x22
  __int64 v13; // x0

  if ( *(_QWORD *)(a1 + 3808) )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: free link_stats_results",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wma_unified_radio_tx_mem_free");
    qdf_mutex_acquire(a1 + 3816);
    v10 = *(_QWORD *)(a1 + 3808);
    if ( v10 && *(_DWORD *)(v10 + 20) )
    {
      v11 = 0;
      v12 = (__int64 *)(v10 + 100);
      do
      {
        v13 = *(v12 - 2);
        if ( v13 )
        {
          _qdf_mem_free(v13);
          *(v12 - 2) = 0;
        }
        if ( *v12 )
        {
          _qdf_mem_free(*v12);
          *v12 = 0;
        }
        ++v11;
        v12 += 10;
      }
      while ( v11 < *(_DWORD *)(v10 + 20) );
      v10 = *(_QWORD *)(a1 + 3808);
    }
    _qdf_mem_free(v10);
    *(_QWORD *)(a1 + 3808) = 0;
    qdf_mutex_release(a1 + 3816);
  }
  return 0;
}
