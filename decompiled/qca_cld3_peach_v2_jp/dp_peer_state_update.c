__int64 __fastcall dp_peer_state_update(__int64 a1, unsigned __int16 *a2, unsigned int a3)
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
  char v15; // w9
  __int64 v16; // x21
  char v17; // w10
  __int64 v18; // x9
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v28; // x5
  __int64 v29; // x6
  __int64 v30; // x7
  int v31; // w8

  v6 = dp_peer_find_hash_find(a1, a2, 0, 0xFFu, 7u);
  if ( v6 )
  {
    v15 = *(_BYTE *)(v6 + 120);
    v16 = v6;
    *(_DWORD *)(v6 + 124) = a3;
    v17 = v15 & 0xFD;
    v18 = *(_QWORD *)v6;
    *(_BYTE *)(v6 + 120) = v17 | (2 * (a3 == 3));
    if ( v18 )
    {
      *(_BYTE *)(v18 + 10) = *(_BYTE *)(v18 + 10) & 0xFE | ((2 * (unsigned int)(a3 == 3)) >> 1);
      a3 = *(_DWORD *)(v6 + 124);
    }
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: peer %pK state %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_peer_state_update",
      v6,
      a3);
    dp_peer_unref_delete(v16, 7u, v19, v20, v21, v22, v23, v24, v25, v26);
    return 0;
  }
  else
  {
    if ( a2 )
    {
      v28 = *(unsigned __int8 *)a2;
      v29 = *((unsigned __int8 *)a2 + 1);
      v30 = *((unsigned __int8 *)a2 + 2);
      v31 = *((unsigned __int8 *)a2 + 5);
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
      "%s: %pK: Failed to find peer for: [%02x:%02x:%02x:**:**:%02x]",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_peer_state_update",
      a1,
      v28,
      v29,
      v30,
      v31);
    return 16;
  }
}
