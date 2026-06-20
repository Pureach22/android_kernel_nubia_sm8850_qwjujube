__int64 __fastcall wlan_hdd_free_cache_channels(
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
  __int64 result; // x0
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  result = qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_free_cache_channels");
  if ( *(_QWORD *)(a1 + 3616) )
  {
    qdf_mutex_acquire(a1 + 3624);
    **(_DWORD **)(a1 + 3616) = 0;
    v11 = *(_QWORD *)(a1 + 3616);
    if ( *(_QWORD *)(v11 + 8) )
    {
      _qdf_mem_free(*(_QWORD *)(v11 + 8));
      *(_QWORD *)(*(_QWORD *)(a1 + 3616) + 8LL) = 0;
      v11 = *(_QWORD *)(a1 + 3616);
    }
    _qdf_mem_free(v11);
    *(_QWORD *)(a1 + 3616) = 0;
    qdf_mutex_release(a1 + 3624);
    return qdf_trace_msg(0x33u, 8u, "%s: exit", v12, v13, v14, v15, v16, v17, v18, v19, "wlan_hdd_free_cache_channels");
  }
  return result;
}
