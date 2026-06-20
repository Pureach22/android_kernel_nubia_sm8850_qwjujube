__int64 __fastcall dp_txrx_get_peer_stats_based_on_peer_type(int a1, int a2, int a3, void *a4)
{
  __int64 *v5; // x20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v5 = (__int64 *)dp_peer_find_hash_find(a1, a3);
  qdf_mem_set(a4, 0xE90u, 0);
  if ( !v5 )
    return 16;
  dp_get_peer_stats(v5, (__int64)a4, v6, v7, v8, v9, v10, v11, v12, v13);
  dp_peer_unref_delete((__int64)v5, 7u, v14, v15, v16, v17, v18, v19, v20, v21);
  return 0;
}
