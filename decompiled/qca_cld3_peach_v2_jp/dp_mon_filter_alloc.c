__int64 *__fastcall dp_mon_filter_alloc(
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
  __int64 *v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 *v19; // x19
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0

  if ( !a1 )
  {
    qdf_trace_msg(0x73u, 2u, "%s: pdev Context is null", a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_alloc");
    return nullptr;
  }
  v10 = (__int64 *)_qdf_mem_malloc(0x20u, "dp_mon_filter_alloc", 901);
  v19 = v10;
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
      "dp_mon_filter_alloc");
    return v19;
  }
  qdf_mem_set(v10, 0x20u, 0);
  v20 = _qdf_mem_malloc(0x1CCu, "dp_mon_filter_alloc", 915);
  *v19 = v20;
  if ( !v20
    || (v29 = _qdf_mem_malloc(0x1CCu, "dp_mon_filter_alloc", 915), (v19[1] = v29) == 0)
    || (v30 = _qdf_mem_malloc(0x1CCu, "dp_mon_filter_alloc", 915), (v19[2] = v30) == 0)
    || (v31 = _qdf_mem_malloc(0x1CCu, "dp_mon_filter_alloc", 915), (v19[3] = v31) == 0) )
  {
    *(_QWORD *)(a1 + 37064) = v19;
    dp_mon_filter_dealloc(a1, v21, v22, v23, v24, v25, v26, v27, v28);
    return nullptr;
  }
  return v19;
}
