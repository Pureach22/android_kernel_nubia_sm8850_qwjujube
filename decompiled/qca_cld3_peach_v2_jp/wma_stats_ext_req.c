__int64 __fastcall wma_stats_ext_req(
        __int64 *a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _DWORD *v12; // x0
  __int64 v13; // x20
  size_t v14; // x2
  unsigned int v15; // w19

  if ( a1 )
  {
    v12 = (_DWORD *)_qdf_mem_malloc((unsigned int)a2[1] + 12LL, "wma_stats_ext_req", 4322);
    if ( v12 )
    {
      v13 = (__int64)v12;
      *v12 = *a2;
      v14 = (unsigned int)a2[1];
      v12[1] = v14;
      if ( (_DWORD)v14 )
        qdf_mem_copy(v12 + 3, a2 + 2, v14);
      *(_DWORD *)(v13 + 8) = 0;
      v15 = wmi_unified_stats_ext_req_cmd(*a1);
      _qdf_mem_free(v13);
      return v15;
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(0x36u, 2u, "%s: wma handle is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wma_stats_ext_req");
    return 16;
  }
}
