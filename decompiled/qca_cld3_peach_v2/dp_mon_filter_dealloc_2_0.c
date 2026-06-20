__int64 __fastcall dp_mon_filter_dealloc_2_0(
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
  __int64 v9; // x20
  __int64 *v10; // x19
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 result; // x0
  const char *v15; // x2

  if ( !a1 )
  {
    v15 = "%s: Pdev context is null";
    return qdf_trace_msg(0x73u, 2u, v15, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_dealloc_2_0");
  }
  v9 = *(_QWORD *)(a1 + 96456);
  if ( !v9 )
  {
    v15 = "%s: Monitor pdev context is null";
    return qdf_trace_msg(0x73u, 2u, v15, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_dealloc_2_0");
  }
  v10 = *(__int64 **)(v9 + 39328);
  if ( !v10 )
  {
    v15 = "%s: Found NULL memory for the Monitor filter";
    return qdf_trace_msg(0x73u, 2u, v15, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_dealloc_2_0");
  }
  if ( *v10 )
  {
    _qdf_mem_free(*v10);
    *v10 = 0;
  }
  v11 = v10[1];
  if ( v11 )
  {
    _qdf_mem_free(v11);
    v10[1] = 0;
  }
  v12 = v10[2];
  if ( v12 )
  {
    _qdf_mem_free(v12);
    v10[2] = 0;
  }
  v13 = v10[3];
  if ( v13 )
  {
    _qdf_mem_free(v13);
    v10[3] = 0;
  }
  result = _qdf_mem_free((__int64)v10);
  *(_QWORD *)(v9 + 39328) = 0;
  return result;
}
