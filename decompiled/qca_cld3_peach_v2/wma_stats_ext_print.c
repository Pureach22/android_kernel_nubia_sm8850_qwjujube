__int64 __fastcall wma_stats_ext_print(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  __int64 v19; // x20
  __int64 v20; // x21
  unsigned __int16 v21; // w26
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int16 v30; // w0
  __int64 v31; // [xsp+0h] [xbp-30h]
  __int64 v32; // [xsp+8h] [xbp-28h]
  __int64 v33; // [xsp+10h] [xbp-20h]

  qdf_trace_msg(
    0x36u,
    8u,
    "%s: mpdu_enque 0x%x mpdu_requeue 0x%x rssi %d tx_bytes 0x%x rx_bytes 0x%x freq %d vdev_id %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wma_stats_ext_print",
    a1[1],
    a1[2],
    a1[83],
    a1[84],
    a1[85],
    (unsigned __int16)a1[86],
    HIWORD(a1[86]));
  LODWORD(v33) = a1[38];
  LODWORD(v32) = a1[77];
  LODWORD(v31) = a1[37];
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: BW counts: 20MHz tx %d rx %d, 40MHz tx %d rx %d, 80MHz tx %d rx %d, 160MHz tx %d rx %d, 320MHz tx %d rx %d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "wma_stats_ext_print",
    a1[35],
    a1[75],
    a1[36],
    a1[76],
    v31,
    v32,
    v33,
    a1[78],
    a1[39],
    a1[79]);
  result = _qdf_mem_malloc(0x1F4u, "wma_stats_ext_print", 720);
  if ( result )
  {
    v19 = result;
    v20 = 0;
    v21 = 0;
    do
    {
      while ( 1 )
      {
        v22 = scnprintf(v19 + v21, 500LL - v21, "MCS%d: tx %d rx %d, ", v20, a1[v20 + 3], a1[v20 + 43]);
        v21 += v30;
        if ( v21 <= 0x64u )
          break;
        qdf_trace_msg(0x36u, 8u, "%s: %s", v22, v23, v24, v25, v26, v27, v28, v29, "wma_stats_ext_print", v19);
        ++v20;
        v21 = 0;
        if ( v20 == 17 )
          return _qdf_mem_free(v19);
      }
      ++v20;
    }
    while ( v20 != 17 );
    if ( v21 )
      qdf_trace_msg(0x36u, 8u, "%s: %s", v22, v23, v24, v25, v26, v27, v28, v29, "wma_stats_ext_print", v19);
    return _qdf_mem_free(v19);
  }
  return result;
}
