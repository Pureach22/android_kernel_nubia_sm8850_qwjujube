__int64 __fastcall dp_txrx_get_per_link_peer_stats(int a1, int a2, int a3, void *a4)
{
  __int64 v5; // x0
  __int64 v6; // x19
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v5 = dp_peer_find_hash_find(a1, a3);
  if ( !v5 )
    return 16;
  v6 = v5;
  qdf_mem_set(a4, 0xE90u, 0);
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Per link stats not supported",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "dp_get_per_link_peer_stats");
  dp_peer_unref_delete(v6, 8u, v15, v16, v17, v18, v19, v20, v21, v22);
  return 4;
}
