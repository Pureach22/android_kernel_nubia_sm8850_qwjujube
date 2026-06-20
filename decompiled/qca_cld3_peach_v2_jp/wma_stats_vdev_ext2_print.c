__int64 __fastcall wma_stats_vdev_ext2_print(
        unsigned int *a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  __int64 v20; // x19
  __int64 v21; // x21
  unsigned __int16 v22; // w25
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int16 v31; // w0
  __int64 v32; // [xsp+0h] [xbp-30h]
  __int64 v33; // [xsp+8h] [xbp-28h]
  __int64 v34; // [xsp+10h] [xbp-20h]

  if ( !a1 )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: vdev_ext2_stats is NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wma_stats_vdev_ext2_print");
  qdf_trace_msg(
    0x36u,
    8u,
    "MPDU BW: 20MHz tx %d rx %d, 40MHz tx %d rx %d, 80MHz tx %d rx %d, 160MHz tx %d rx %d, 320MHz tx %d rx %d vdev_id %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a1[33],
    a1[77],
    a1[34],
    a1[78],
    a1[35],
    a1[79],
    a1[36],
    a1[80],
    a1[37],
    a1[81],
    a2);
  LODWORD(v33) = a1[44];
  LODWORD(v34) = a1[88];
  LODWORD(v32) = a1[87];
  qdf_trace_msg(
    0x36u,
    8u,
    "MPDU NSS0: tx %d rx %d NSS1: tx %d rx %d NSS2: tx %d rx %d NSS3: tx %d rx %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    a1[41],
    a1[85],
    a1[42],
    a1[86],
    a1[43],
    v32,
    v33,
    v34);
  result = _qdf_mem_malloc(0x1F4u, "wma_stats_vdev_ext2_print", 789);
  if ( result )
  {
    v20 = result;
    v21 = 0;
    v22 = 0;
    do
    {
      while ( 1 )
      {
        v23 = scnprintf(v20 + v22, 500LL - v22, "MPDU MCS %u: tx %u rx %u, ", v21, a1[v21 + 1], a1[v21 + 45]);
        v22 += v31;
        if ( v22 <= 0x64u )
          break;
        qdf_trace_msg(0x36u, 8u, "%s", v23, v24, v25, v26, v27, v28, v29, v30, v20);
        ++v21;
        v22 = 0;
        if ( v21 == 15 )
          return _qdf_mem_free(v20);
      }
      ++v21;
    }
    while ( v21 != 15 );
    if ( v22 )
      qdf_trace_msg(0x36u, 8u, "%s", v23, v24, v25, v26, v27, v28, v29, v30, v20);
    return _qdf_mem_free(v20);
  }
  return result;
}
