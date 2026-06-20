__int64 __fastcall dp_tx_latency_stats_fetch(__int64 a1, unsigned __int8 a2, unsigned __int16 *a3, __int64 a4)
{
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x20
  double v17; // d0
  unsigned int v18; // w0
  unsigned int v19; // w19
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x22
  __int64 v28; // x5
  __int64 v29; // x6
  __int64 v30; // x7
  int v31; // w8

  v7 = dp_peer_find_hash_find(a1, a3, 0, a2, 7u);
  if ( v7 )
  {
    v16 = v7;
    v17 = ((double (__fastcall *)(__int64, __int64))dp_tx_latency_stats_get_per_peer)(v7, a4);
    v19 = v18;
    dp_peer_unref_delete(v16, 7u, v17, v20, v21, v22, v23, v24, v25, v26);
  }
  else
  {
    v27 = jiffies;
    if ( dp_tx_latency_stats_fetch___last_ticks - jiffies + 125 < 0 )
    {
      if ( a3 )
      {
        v28 = *(unsigned __int8 *)a3;
        v29 = *((unsigned __int8 *)a3 + 1);
        v30 = *((unsigned __int8 *)a3 + 2);
        v31 = *((unsigned __int8 *)a3 + 5);
      }
      else
      {
        v30 = 0;
        v28 = 0;
        v29 = 0;
        v31 = 0;
      }
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: peer(vdev id %d mac %02x:%02x:%02x:**:**:%02x) not found",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "dp_tx_latency_stats_fetch",
        a2,
        v28,
        v29,
        v30,
        v31);
      dp_tx_latency_stats_fetch___last_ticks = v27;
    }
    return 4;
  }
  return v19;
}
