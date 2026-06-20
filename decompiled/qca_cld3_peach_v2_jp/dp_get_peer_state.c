__int64 __fastcall dp_get_peer_state(__int64 a1, unsigned __int8 a2, unsigned __int16 *a3, char a4)
{
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w19
  __int64 v15; // x20
  int v17; // [xsp+20h] [xbp-20h]
  int v18; // [xsp+28h] [xbp-18h]

  v5 = dp_peer_find_hash_find(a1, a3, 0, a2, 7u);
  if ( v5 )
  {
    v14 = *(_DWORD *)(v5 + 124);
    if ( (a4 & 1) != 0 )
    {
      v15 = v5;
      v18 = *(unsigned __int8 *)(v5 + 49);
      v17 = *(unsigned __int8 *)(v5 + 46);
      qdf_trace_msg(
        0x81u,
        5u,
        "%s: peer %pK tgt_peer: %pK peer MAC %02x:%02x:%02x:**:**:%02x tgt peer MAC %02x:%02x:%02x:**:**:%02x tgt peer state %d",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "dp_get_peer_state",
        v15,
        v15,
        v17,
        v18,
        *(unsigned __int8 *)(v5 + 44),
        *(unsigned __int8 *)(v5 + 45),
        v17,
        v18,
        *(_DWORD *)(v5 + 124));
      v5 = v15;
    }
    dp_peer_unref_delete(v5, 7u, v6, v7, v8, v9, v10, v11, v12, v13);
  }
  else
  {
    return 0;
  }
  return v14;
}
