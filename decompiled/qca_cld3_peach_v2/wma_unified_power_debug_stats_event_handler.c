__int64 __fastcall wma_unified_power_debug_stats_event_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  _QWORD *context; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int *v20; // x22
  __int64 v21; // x4
  const char *v22; // x2
  unsigned int v24; // w21
  _QWORD *v25; // x23
  const void *v26; // x20
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x19
  unsigned int v37; // w8
  _DWORD *v38; // x8

  context = _cds_get_context(53, (__int64)"wma_unified_power_debug_stats_event_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
  {
    v22 = "%s: NULL mac ptr";
LABEL_8:
    qdf_trace_msg(0x36u, 8u, v22, v12, v13, v14, v15, v16, v17, v18, v19, "wma_unified_power_debug_stats_event_handler");
    return 4294967274LL;
  }
  v20 = *(unsigned int **)a10;
  if ( !*(_QWORD *)a10 )
  {
    v22 = "%s: NULL power stats event fixed param";
    goto LABEL_8;
  }
  v21 = v20[6];
  if ( (unsigned int)v21 > 0x179 || (unsigned int)v21 > *(_DWORD *)(a10 + 24) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: excess payload: LEN num_debug_register:%u",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_unified_power_debug_stats_event_handler");
    return 4294967274LL;
  }
  v24 = 4 * v21;
  v25 = context;
  v26 = *(const void **)(a10 + 16);
  v27 = _qdf_mem_malloc(4 * v21 + 32, "wma_unified_power_debug_stats_event_handler", 5883);
  if ( !v27 )
    return 4294967284LL;
  v36 = v27;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Cumulative sleep time %d cumulative total on time %d deep sleep enter counter %d last deep sleep enter tstamp ts"
    " %d debug registers fmt %d num debug register %d",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "wma_unified_power_debug_stats_event_handler",
    v20[1],
    v20[2],
    v20[3],
    v20[4],
    v20[5],
    v20[6]);
  *(_DWORD *)v36 = v20[1];
  *(_DWORD *)(v36 + 4) = v20[2];
  *(_DWORD *)(v36 + 8) = v20[3];
  *(_DWORD *)(v36 + 12) = v20[4];
  *(_DWORD *)(v36 + 16) = v20[5];
  v37 = v20[6];
  *(_QWORD *)(v36 + 24) = v36 + 32;
  *(_DWORD *)(v36 + 20) = v37;
  qdf_mem_copy((void *)(v36 + 32), v26, v24);
  v38 = (_DWORD *)v25[1632];
  if ( v38 )
  {
    if ( *(v38 - 1) != -1635532630 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64))v38)(v25, v36);
  }
  _qdf_mem_free(v36);
  return 0;
}
