__int64 __fastcall dp_txrx_get_peer_stats_param(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 *a3,
        unsigned int a4,
        __int64 a5)
{
  __int64 v10; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int peer_extd_stats_param; // w19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _DWORD *v28; // x8
  __int64 v29; // x5
  __int64 v30; // x6
  __int64 v31; // x7
  int v32; // w8

  v10 = dp_peer_find_hash_find(a1, (int)a3);
  if ( v10 )
    goto LABEL_2;
  v28 = *(_DWORD **)(a1 + 1536);
  if ( !v28 )
    goto LABEL_11;
  if ( *(v28 - 1) != 69695039 )
    __break(0x8228u);
  v10 = ((__int64 (__fastcall *)(__int64, unsigned __int8 *, _QWORD, __int64, _QWORD))v28)(a1, a3, 0, 7, a2);
  if ( v10 )
  {
LABEL_2:
    if ( a4 > 3 )
    {
      if ( a4 == 4 || a4 > 0x11 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: %pK: Invalid stat type requested",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "dp_txrx_get_peer_stats_param",
          a1);
        peer_extd_stats_param = 16;
      }
      else
      {
        peer_extd_stats_param = dp_txrx_get_peer_extd_stats_param(v10, a4, a5);
      }
    }
    else
    {
      peer_extd_stats_param = dp_txrx_get_peer_per_pkt_stats_param(v10, a4, a5);
    }
    dp_peer_unref_delete(v10, 7u, v20, v21, v22, v23, v24, v25, v26, v27);
  }
  else
  {
LABEL_11:
    if ( a3 )
    {
      v29 = *a3;
      v30 = a3[1];
      v31 = a3[2];
      v32 = a3[5];
    }
    else
    {
      v31 = 0;
      v29 = 0;
      v30 = 0;
      v32 = 0;
    }
    qdf_trace_msg(
      0x81u,
      2u,
      "%s: %pK: Invalid Peer for Mac %02x:%02x:%02x:**:**:%02x",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "dp_txrx_get_peer_stats_param",
      a1,
      v29,
      v30,
      v31,
      v32);
    return 16;
  }
  return peer_extd_stats_param;
}
