__int64 __fastcall os_if_dp_nud_stats_info(
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
  __int64 *v9; // x8
  __int64 v10; // x8
  __int64 v11; // x22
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int64 v21; // x19
  __int64 v22; // x23

  if ( !a1 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: failed to get netdev",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "os_if_dp_nud_stats_info");
  v9 = *(__int64 **)(a1 + 680);
  if ( !v9 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: failed to get netdev",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "os_if_dp_nud_stats_info");
  v10 = *v9;
  if ( !v10 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: failed to get netdev",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "os_if_dp_nud_stats_info");
  v11 = *(_QWORD *)(v10 + 32);
  if ( !v11 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: failed to get netdev",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "os_if_dp_nud_stats_info");
  result = qdf_trace_msg(
             0x45u,
             5u,
             "%s: carrier state: %d",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "os_if_dp_nud_stats_info",
             (*(_QWORD *)(v11 + 168) & 4LL) == 0);
  if ( *(_DWORD *)(v11 + 1096) )
  {
    v21 = 0;
    v22 = 336;
    do
    {
      result = qdf_trace_msg(
                 0x45u,
                 5u,
                 "%s: Queue: %d status: %d txq->trans_start: %lu",
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 "os_if_dp_nud_stats_info",
                 (unsigned int)v21++,
                 *(_QWORD *)(*(_QWORD *)(v11 + 24) + v22) & 1LL,
                 *(_QWORD *)(*(_QWORD *)(v11 + 24) + v22 - 8));
      v22 += 384;
    }
    while ( v21 < *(unsigned int *)(v11 + 1096) );
  }
  return result;
}
