__int64 __fastcall dp_get_host_peer_stats(
        __int64 a1,
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
  __int64 v12; // x19
  void *v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x20
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v33; // x2
  _DWORD *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7

  if ( !a2 )
  {
    v33 = "%s: NULL peer mac addr\n";
LABEL_14:
    qdf_trace_msg(0x3Fu, 2u, v33, a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_host_peer_stats");
    return 16;
  }
  v12 = dp_peer_find_hash_find(a1, a2);
  if ( !v12 )
  {
    v34 = *(_DWORD **)(a1 + 1536);
    if ( !v34 )
      goto LABEL_13;
    if ( *(v34 - 1) != 69695039 )
      __break(0x8228u);
    v12 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, __int64))v34)(a1, a2, 0, 7, 255);
    if ( !v12 )
    {
LABEL_13:
      v33 = "%s: Invalid peer\n";
      goto LABEL_14;
    }
  }
  v13 = (void *)_qdf_mem_malloc(0x11C0u, "dp_get_host_peer_stats", 8744);
  if ( v13 )
  {
    v22 = (__int64)v13;
    qdf_mem_set(v13, 0x11C0u, 0);
    dp_get_peer_stats(v12, v22);
    dp_print_peer_stats(v12, v22);
    if ( *(_DWORD *)(v12 + 408) != 1 || (v23 = *(_QWORD *)(v12 + 416)) == 0 )
      v23 = v12;
    dp_peer_rxtid_stats(v23, dp_rx_tid_stats_cb, 0);
    _qdf_mem_free(v22);
    dp_peer_unref_delete(v12, 7u, v24, v25, v26, v27, v28, v29, v30, v31);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s: Memory allocation failed for cdp_peer_stats\n",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "dp_get_host_peer_stats");
    dp_peer_unref_delete(v12, 7u, v35, v36, v37, v38, v39, v40, v41, v42);
    return 2;
  }
}
