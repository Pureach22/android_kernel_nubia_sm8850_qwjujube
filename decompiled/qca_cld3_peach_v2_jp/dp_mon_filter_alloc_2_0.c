__int64 __fastcall dp_mon_filter_alloc_2_0(
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
  __int64 v9; // x19
  __int64 *v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 *v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v29; // x2

  if ( !a1 )
  {
    v29 = "%s: pdev Context is null";
LABEL_11:
    qdf_trace_msg(0x73u, 2u, v29, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_alloc_2_0");
    return 16;
  }
  v9 = *(_QWORD *)(a1 + 95560);
  if ( !v9 )
  {
    v29 = "%s: Monitor pdev context is null";
    goto LABEL_11;
  }
  v10 = (__int64 *)_qdf_mem_malloc(0x20u, "dp_mon_filter_alloc_2_0", 99);
  if ( !v10 )
  {
    qdf_trace_msg(
      0x73u,
      2u,
      "%s: Monitor filter mem allocation failed",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "dp_mon_filter_alloc_2_0");
    return 2;
  }
  v19 = v10;
  qdf_mem_set(v10, 0x20u, 0);
  *v19 = _qdf_mem_malloc(0x2D0u, "dp_mon_filter_alloc_2_0", 110);
  *(_QWORD *)(v9 + 39328) = v19;
  if ( *v19 )
  {
    v19[1] = _qdf_mem_malloc(0x2D0u, "dp_mon_filter_alloc_2_0", 110);
    *(_QWORD *)(v9 + 39328) = v19;
    if ( v19[1] )
    {
      v19[2] = _qdf_mem_malloc(0x2D0u, "dp_mon_filter_alloc_2_0", 110);
      *(_QWORD *)(v9 + 39328) = v19;
      if ( v19[2] )
      {
        v19[3] = _qdf_mem_malloc(0x2D0u, "dp_mon_filter_alloc_2_0", 110);
        *(_QWORD *)(v9 + 39328) = v19;
        if ( v19[3] )
          return 0;
      }
    }
  }
  dp_mon_filter_dealloc(v9, v20, v21, v22, v23, v24, v25, v26, v27);
  return 16;
}
