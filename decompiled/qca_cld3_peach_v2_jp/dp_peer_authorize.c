__int64 __fastcall dp_peer_authorize(__int64 a1, int a2, int a3, int a4)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w8
  __int64 v18; // x9
  __int64 v19; // x22

  v8 = dp_peer_find_hash_find(a1, a3);
  if ( v8 )
  {
    v17 = 2 * (a4 != 0);
    v18 = *(_QWORD *)v8;
    *(_BYTE *)(v8 + 120) = *(_BYTE *)(v8 + 120) & 0xFD | v17;
    if ( v18 )
    {
      *(_BYTE *)(v18 + 10) = *(_BYTE *)(v18 + 10) & 0xFE | (v17 >> 1);
      if ( (*(_BYTE *)(v8 + 120) & 2) != 0 )
      {
LABEL_5:
        dp_peer_unref_delete(v8, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
        return 0;
      }
    }
    else if ( a4 )
    {
      goto LABEL_5;
    }
    v19 = v8;
    dp_peer_flush_frags(a1, a2, a3);
    v8 = v19;
    goto LABEL_5;
  }
  qdf_trace_msg(0x89u, 8u, "%s: %pK: Peer is NULL!", v9, v10, v11, v12, v13, v14, v15, v16, "dp_peer_authorize", a1);
  return 16;
}
