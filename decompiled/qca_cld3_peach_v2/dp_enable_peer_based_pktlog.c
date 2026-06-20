__int64 __fastcall dp_enable_peer_based_pktlog(__int64 a1, char a2, unsigned __int16 *a3, char a4)
{
  __int64 v4; // x8
  __int64 v6; // x21
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x8
  unsigned int v17; // w20

  if ( a2 )
    return 16;
  v4 = *(_QWORD *)(a1 + 72);
  if ( !v4 )
  {
    return 16;
  }
  else
  {
    v6 = *(_QWORD *)(v4 + 96456);
    v7 = dp_peer_find_hash_find(a1, a3, 0, 0xFFu, 7u);
    if ( v7 )
    {
      if ( *(_DWORD *)(v7 + 408) == 2 || (v16 = *(_QWORD *)(v7 + 8)) == 0 )
      {
        v17 = 16;
      }
      else
      {
        v17 = 0;
        *(_BYTE *)(v16 + 1) = a4;
        *(_BYTE *)(v6 + 39105) = a4;
      }
      dp_peer_unref_delete(v7, 7u, v8, v9, v10, v11, v12, v13, v14, v15);
    }
    else
    {
      qdf_trace_msg(0x92u, 2u, "%s: Peer is NULL", v8, v9, v10, v11, v12, v13, v14, v15, "dp_enable_peer_based_pktlog");
      return 16;
    }
  }
  return v17;
}
