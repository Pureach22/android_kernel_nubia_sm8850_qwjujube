__int64 __fastcall dp_set_peer_as_tdls_peer(__int64 a1, unsigned __int8 a2, unsigned __int16 *a3, char a4)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x20
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  int v19; // w8
  __int64 v20; // x4
  __int64 v21; // x5
  __int64 v22; // x6
  __int64 v23; // x7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  char v32; // w9

  v6 = dp_peer_find_hash_find(a1, a3, 0, a2, 7u);
  if ( v6 )
  {
    v15 = v6;
    if ( a3 )
    {
      v16 = *(unsigned __int8 *)a3;
      v17 = *((unsigned __int8 *)a3 + 1);
      v18 = *((unsigned __int8 *)a3 + 2);
      v19 = *((unsigned __int8 *)a3 + 5);
    }
    else
    {
      v18 = 0;
      v16 = 0;
      v17 = 0;
      v19 = 0;
    }
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Set tdls flag %d for peer:%02x:%02x:%02x:**:**:%02x",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_set_peer_as_tdls_peer",
      a4 & 1,
      v16,
      v17,
      v18,
      v19);
    if ( (a4 & 1) != 0 )
      v32 = 32;
    else
      v32 = 0;
    *(_BYTE *)(v15 + 120) = *(_BYTE *)(v15 + 120) & 0xDF | v32;
    return dp_peer_unref_delete(v15, 7u, v24, v25, v26, v27, v28, v29, v30, v31);
  }
  else
  {
    if ( a3 )
    {
      v20 = *(unsigned __int8 *)a3;
      v21 = *((unsigned __int8 *)a3 + 1);
      v22 = *((unsigned __int8 *)a3 + 2);
      v23 = *((unsigned __int8 *)a3 + 5);
    }
    else
    {
      v22 = 0;
      v20 = 0;
      v21 = 0;
      v23 = 0;
    }
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Failed to find peer for:%02x:%02x:%02x:**:**:%02x",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "dp_set_peer_as_tdls_peer",
             v20,
             v21,
             v22,
             v23);
  }
}
