__int64 __fastcall infra_cp_stats_reset_cb(unsigned int *a1, __int64 a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  v3 = osif_request_get(a2);
  if ( !v3 )
    return qdf_trace_msg(0x48u, 2u, "%s: Obsolete request", v4, v5, v6, v7, v8, v9, v10, v11, "infra_cp_stats_reset_cb");
  v12 = v3;
  osif_request_priv(v3);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: clear stats action %d req_id %d, status %d num_cp_stats %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "infra_cp_stats_reset_cb",
    *a1,
    a1[1],
    a1[2],
    a1[3]);
  osif_request_complete(v12);
  return osif_request_put(v12);
}
