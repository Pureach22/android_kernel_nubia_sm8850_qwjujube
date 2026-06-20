__int64 __fastcall wma_rx_aggr_failure_event_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10)
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
  __int64 v20; // x23
  __int64 v21; // x4
  const char *v22; // x2
  unsigned int v23; // w1
  _QWORD *v25; // x22
  __int64 v26; // x21
  _DWORD *v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w4
  _DWORD *v37; // x19
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned __int64 v46; // x20
  unsigned int *v47; // x23
  _DWORD *v48; // x8
  __int64 v49; // x0

  context = _cds_get_context(53, (__int64)"wma_rx_aggr_failure_event_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context || !context[1637] )
  {
    v22 = "%s: NULL mac ptr or HDD callback is null";
    v23 = 8;
LABEL_7:
    qdf_trace_msg(0x36u, v23, v22, v12, v13, v14, v15, v16, v17, v18, v19, "wma_rx_aggr_failure_event_handler");
    return 4294967274LL;
  }
  if ( !a10 )
  {
    v22 = "%s: Invalid stats ext event buf";
    v23 = 2;
    goto LABEL_7;
  }
  v20 = *a10;
  v21 = *(unsigned int *)(*a10 + 4);
  if ( (unsigned int)v21 >= 0x180 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Excess data from WMI num_failure_info %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_rx_aggr_failure_event_handler");
    return 4294967274LL;
  }
  v25 = context;
  v26 = a10[2];
  v27 = (_DWORD *)_qdf_mem_malloc(4 * v21 + 4, "wma_rx_aggr_failure_event_handler", 6230);
  if ( !v27 )
    return 4294967284LL;
  v36 = *(_DWORD *)(v20 + 4);
  v37 = v27;
  *v27 = v36;
  if ( v36 > *((_DWORD *)a10 + 6) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid no of hole count: %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "wma_rx_aggr_failure_event_handler");
    _qdf_mem_free((__int64)v37);
    return 4294967274LL;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: aggr holes_sum: %d\n",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "wma_rx_aggr_failure_event_handler");
  if ( *v37 )
  {
    v46 = 0;
    v47 = (unsigned int *)(v26 + 8);
    do
    {
      v37[v46 + 1] = *v47 - *(v47 - 1) + 1;
      qdf_trace_msg(
        0x36u,
        8u,
        "aggr_index: %d\tstart_seq: %d\tend_seq: %d\thole_info: %d mpdu lost",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        (unsigned int)v46++,
        *(v47 - 1),
        *v47);
      v47 += 3;
    }
    while ( v46 < (unsigned int)*v37 );
  }
  v48 = (_DWORD *)v25[1637];
  v49 = v25[1604];
  if ( *(v48 - 1) != -35895097 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _DWORD *))v48)(v49, v37);
  _qdf_mem_free((__int64)v37);
  return 0;
}
