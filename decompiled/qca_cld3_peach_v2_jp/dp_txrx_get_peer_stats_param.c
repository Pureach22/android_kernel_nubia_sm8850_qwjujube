__int64 __fastcall dp_txrx_get_peer_stats_param(__int64 a1, int a2, unsigned __int8 *a3, unsigned int a4, __int64 a5)
{
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  unsigned int peer_extd_stats_param; // w19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x5
  __int64 v29; // x6
  __int64 v30; // x7
  int v31; // w8

  v9 = dp_peer_find_hash_find(a1, (int)a3);
  if ( v9 )
  {
    v18 = v9;
    if ( a4 > 3 )
    {
      if ( a4 == 4 || a4 > 0x11 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: %pK: Invalid stat type requested",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "dp_txrx_get_peer_stats_param",
          a1);
        peer_extd_stats_param = 16;
      }
      else
      {
        peer_extd_stats_param = dp_txrx_get_peer_extd_stats_param(v9, a4, a5);
      }
    }
    else
    {
      peer_extd_stats_param = dp_txrx_get_peer_per_pkt_stats_param(v9, a4, a5);
    }
    dp_peer_unref_delete(v18, 7u, v20, v21, v22, v23, v24, v25, v26, v27);
  }
  else
  {
    if ( a3 )
    {
      v28 = *a3;
      v29 = a3[1];
      v30 = a3[2];
      v31 = a3[5];
    }
    else
    {
      v30 = 0;
      v28 = 0;
      v29 = 0;
      v31 = 0;
    }
    qdf_trace_msg(
      0x81u,
      2u,
      "%s: %pK: Invalid Peer for Mac %02x:%02x:%02x:**:**:%02x",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "dp_txrx_get_peer_stats_param",
      a1,
      v28,
      v29,
      v30,
      v31);
    return 16;
  }
  return peer_extd_stats_param;
}
