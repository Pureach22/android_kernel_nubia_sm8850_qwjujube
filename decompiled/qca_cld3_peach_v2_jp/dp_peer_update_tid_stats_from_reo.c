__int64 __fastcall dp_peer_update_tid_stats_from_reo(
        __int64 a1,
        int a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  unsigned __int16 v13; // x20^2
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 v23; // x11

  if ( a3[1] )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: REO stats failure %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "dp_peer_update_tid_stats_from_reo");
  v13 = HIWORD(a2);
  result = dp_peer_get_ref_by_id_3(a1);
  if ( result )
  {
    v22 = *(_QWORD *)(result + 88) + 144LL * v13;
    if ( v22 )
    {
      v23 = *(_QWORD *)(v22 + 128);
      *(_QWORD *)(v22 + 136) += (unsigned int)a3[24];
      *(_QWORD *)(v22 + 128) = v23 + (unsigned int)a3[23];
    }
    return dp_peer_unref_delete(result, 8u, v14, v15, v16, v17, v18, v19, v20, v21);
  }
  return result;
}
