__int64 __fastcall scm_scan_free_scan_request_mem(
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
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0

  if ( a1 )
  {
    v10 = *(_QWORD *)(a1 + 2032);
    if ( v10 )
    {
      *(_QWORD *)(a1 + 2032) = 0;
      *(_DWORD *)(a1 + 2024) = 0;
      _qdf_mem_free(v10);
    }
    v11 = *(_QWORD *)(a1 + 2048);
    if ( v11 )
    {
      *(_DWORD *)(a1 + 2040) = 0;
      *(_QWORD *)(a1 + 2048) = 0;
      _qdf_mem_free(v11);
    }
    v12 = *(_QWORD *)(a1 + 2064);
    if ( v12 )
    {
      *(_DWORD *)(a1 + 2056) = 0;
      *(_QWORD *)(a1 + 2064) = 0;
      _qdf_mem_free(v12);
    }
    _qdf_mem_free(a1);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x15u, 2u, "%s: null request", a2, a3, a4, a5, a6, a7, a8, a9, "scm_scan_free_scan_request_mem");
    return 16;
  }
}
