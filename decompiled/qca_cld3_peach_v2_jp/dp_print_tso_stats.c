__int64 __fastcall dp_print_tso_stats(
        __int64 result,
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
  __int64 v10; // x23
  __int64 v11; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  __int64 v30; // x26
  char v31; // w27
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // [xsp+0h] [xbp-10h]
  __int64 v50; // [xsp+8h] [xbp-8h]

  if ( *(_BYTE *)(result + 1120) )
  {
    v10 = *(_QWORD *)(result + 72);
    v11 = result;
    DP_PRINT_STATS("TSO Statistics\n", a3, a4, a5, a6, a7, a8, a9, a10);
    DP_PRINT_STATS(
      "From stack: %llu | Successful completions: %llu | TSO Packets: %llu | TSO Completions: %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      *(_QWORD *)(v10 + 520),
      *(_QWORD *)(v10 + 3072),
      *(_QWORD *)(v10 + 91320),
      *(unsigned int *)(v10 + 91336));
    v29 = 0;
    v30 = v10 + 91384;
    do
    {
      DP_PRINT_STATS(
        "Packet_Id:[%u]: Packet Length %zu | No. of segments: %u",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        (unsigned int)v29,
        *(_QWORD *)(v30 + 360),
        *(unsigned __int8 *)(v30 + 352));
      if ( a2 == 1 )
      {
        v31 = *(_BYTE *)(v30 + 352);
        if ( v31 )
        {
          DP_PRINT_STATS(
            "Segment id:[%u] fragments: %u | Segment Length %u | TCP Seq no.: %u | ip_id: %u",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            0,
            *(unsigned int *)(v30 + 24),
            *(unsigned int *)(v30 + 28),
            *(unsigned int *)(v30 + 8),
            *(unsigned __int16 *)(v30 + 12));
          LODWORD(v50) = (*(_DWORD *)v30 >> 15) & 1;
          LODWORD(v49) = (*(_DWORD *)v30 >> 14) & 1;
          DP_PRINT_STATS(
            "fin: %u syn: %u rst: %u psh: %u ack: %u urg: %u ece: %u cwr: %u ns: %u",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            (*(_DWORD *)v30 >> 7) & 1,
            (*(_DWORD *)v30 >> 8) & 1,
            (*(_DWORD *)v30 >> 9) & 1,
            (*(_DWORD *)v30 >> 10) & 1,
            (*(_DWORD *)v30 >> 11) & 1,
            (*(_DWORD *)v30 >> 12) & 1,
            (*(_DWORD *)v30 >> 13) & 1,
            v49,
            v50);
          if ( v31 != 1 )
          {
            DP_PRINT_STATS(
              "Segment id:[%u] fragments: %u | Segment Length %u | TCP Seq no.: %u | ip_id: %u",
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              1,
              *(unsigned int *)(v30 + 200),
              *(unsigned int *)(v30 + 204),
              *(unsigned int *)(v30 + 184),
              *(unsigned __int16 *)(v30 + 188));
            v40 = *(_DWORD *)(v30 + 176);
            LODWORD(v50) = (v40 >> 15) & 1;
            LODWORD(v49) = (v40 >> 14) & 1;
            DP_PRINT_STATS(
              "fin: %u syn: %u rst: %u psh: %u ack: %u urg: %u ece: %u cwr: %u ns: %u",
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              (v40 >> 7) & 1,
              (v40 >> 8) & 1,
              (v40 >> 9) & 1,
              (v40 >> 10) & 1,
              (v40 >> 11) & 1,
              (v40 >> 12) & 1,
              (v40 >> 13) & 1,
              v49,
              v50);
          }
        }
      }
      ++v29;
      v30 += 376;
    }
    while ( v29 != 5 );
    result = DP_PRINT_STATS(
               "TSO Histogram: Single: %llu | 2-5 segs: %llu | 6-10: %llu segs | 11-15 segs: %llu | 16-20 segs: %llu | 20+ segs: %llu",
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               *(_QWORD *)(v10 + 93264),
               *(_QWORD *)(v10 + 93272),
               *(_QWORD *)(v10 + 93280),
               *(_QWORD *)(v10 + 93288),
               *(_QWORD *)(v10 + 93296),
               *(_QWORD *)(v10 + 93304));
    if ( *(unsigned __int8 *)(v11 + 1120) > 1u )
    {
      __break(0x5512u);
      return dp_stats_tso_segment_histogram_update(result);
    }
  }
  return result;
}
