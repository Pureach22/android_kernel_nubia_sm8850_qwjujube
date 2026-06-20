__int64 __fastcall wma_unified_beacon_debug_stats_event_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _QWORD *a10)
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
  _DWORD *v20; // x20
  _QWORD *v21; // x21
  _DWORD *v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x19
  void (__fastcall *v32)(__int64, __int64); // x8
  __int64 v33; // x1
  const char *v35; // x2
  unsigned int v36; // w1

  context = _cds_get_context(
              53,
              (__int64)"wma_unified_beacon_debug_stats_event_handler",
              a1,
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8);
  if ( !a10 )
  {
    v35 = "%s: Invalid stats event";
    v36 = 2;
    goto LABEL_11;
  }
  v20 = (_DWORD *)*a10;
  if ( !*a10 || !context || !context[1625] )
  {
    v35 = "%s: NULL mac ptr or HDD callback is null";
    v36 = 8;
LABEL_11:
    qdf_trace_msg(
      0x36u,
      v36,
      v35,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_unified_beacon_debug_stats_event_handler");
    return 4294967274LL;
  }
  v21 = context;
  v22 = (_DWORD *)_qdf_mem_malloc(0x2Cu, "wma_unified_beacon_debug_stats_event_handler", 5952);
  if ( !v22 )
    return 4294967284LL;
  v31 = (__int64)v22;
  v22[1] = v20[2];
  v22[2] = v20[3];
  *v22 = v20[1];
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Total beacon count %d total beacon miss count %d vdev_id %d",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "wma_unified_beacon_debug_stats_event_handler",
    (unsigned int)v20[2],
    (unsigned int)v20[3]);
  qdf_mem_copy((void *)(v31 + 12), v20 + 4, 0x20u);
  v32 = (void (__fastcall *)(__int64, __int64))v21[1625];
  v33 = v21[1624];
  if ( *((_DWORD *)v32 - 1) != -2068292899 )
    __break(0x8228u);
  v32(v31, v33);
  _qdf_mem_free(v31);
  return 0;
}
