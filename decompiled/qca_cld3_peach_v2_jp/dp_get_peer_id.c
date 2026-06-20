__int64 __fastcall dp_get_peer_id(__int64 a1, int a2, int a3)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w19

  v4 = dp_peer_find_hash_find(a1, a3);
  if ( v4 )
  {
    v13 = *(unsigned __int16 *)(v4 + 16);
    dp_peer_unref_delete(v4, 7u, v5, v6, v7, v8, v9, v10, v11, v12);
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: %pK: Peer is NULL!", v5, v6, v7, v8, v9, v10, v11, v12, "dp_get_peer_id", a1);
    return 0xFFFF;
  }
  return v13;
}
