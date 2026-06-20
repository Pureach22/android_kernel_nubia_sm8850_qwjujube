__int64 __fastcall dp_get_host_peer_stats(
        int a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x0
  __int64 *v11; // x19
  void *v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  const char *v39; // x2
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  if ( !a2 )
  {
    v39 = "%s: NULL peer mac addr\n";
LABEL_7:
    qdf_trace_msg(0x3Fu, 2u, v39, a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_host_peer_stats");
    return 16;
  }
  v10 = dp_peer_find_hash_find(a1, a2);
  if ( !v10 )
  {
    v39 = "%s: Invalid peer\n";
    goto LABEL_7;
  }
  v11 = (__int64 *)v10;
  v12 = (void *)_qdf_mem_malloc(0xE90u, "dp_get_host_peer_stats", 8744);
  if ( v12 )
  {
    v21 = (__int64)v12;
    qdf_mem_set(v12, 0xE90u, 0);
    dp_get_peer_stats(v11, v21, v22, v23, v24, v25, v26, v27, v28, v29);
    dp_print_peer_stats(v11, v21);
    dp_peer_rxtid_stats(v11, dp_rx_tid_stats_cb, 0);
    _qdf_mem_free(v21);
    dp_peer_unref_delete((__int64)v11, 7u, v30, v31, v32, v33, v34, v35, v36, v37);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s: Memory allocation failed for cdp_peer_stats\n",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "dp_get_host_peer_stats");
    dp_peer_unref_delete((__int64)v11, 7u, v40, v41, v42, v43, v44, v45, v46, v47);
    return 2;
  }
}
