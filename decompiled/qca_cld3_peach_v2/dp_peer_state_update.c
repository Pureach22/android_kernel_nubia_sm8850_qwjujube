__int64 __fastcall dp_peer_state_update(__int64 a1, unsigned __int16 *a2, int a3)
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
  __int64 v16; // x19
  unsigned int v17; // w8
  char v18; // w10
  __int64 v19; // x9
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  __int64 v29; // x4
  int v30; // w8
  __int64 v31; // x5
  __int64 v32; // x6
  __int64 v33; // x7
  int v34; // w8
  __int64 v36; // [xsp+0h] [xbp-10h]
  __int64 v37; // [xsp+8h] [xbp-8h]

  v6 = dp_peer_find_hash_find(a1, a2, 0, 0xFFu, 7u);
  if ( v6 )
  {
    v15 = *(_BYTE *)(v6 + 120);
    v16 = v6;
    *(_DWORD *)(v6 + 124) = a3;
    v17 = 2 * (a3 == 3);
    v18 = v15 & 0xFD;
    v19 = *(_QWORD *)v6;
    *(_BYTE *)(v6 + 120) = v18 | v17;
    if ( v19 )
    {
      *(_BYTE *)(v19 + 10) = *(_BYTE *)(v19 + 10) & 0xFE | (v17 >> 1);
      a3 = *(_DWORD *)(v6 + 124);
    }
    qdf_trace_msg(
      0x81u,
      5u,
      "%s: peer %pK MAC %02x:%02x:%02x:**:**:%02x state %d",
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
      *(unsigned __int8 *)(v6 + 44),
      *(unsigned __int8 *)(v6 + 45),
      *(unsigned __int8 *)(v6 + 46),
      *(unsigned __int8 *)(v6 + 49),
      a3);
    if ( *(_DWORD *)(v16 + 408) == 1 )
    {
      v28 = *(_QWORD *)(v16 + 416);
      if ( v28 )
      {
        if ( (*(_BYTE *)(v16 + 128) & 1) != 0 )
        {
          *(_DWORD *)(v28 + 124) = *(_DWORD *)(v16 + 124);
          *(_BYTE *)(**(_QWORD **)(v16 + 416) + 10LL) = *(_BYTE *)(**(_QWORD **)(v16 + 416) + 10LL) & 0xFE
                                                      | ((*(_BYTE *)(v16 + 120) & 2) != 0);
          v29 = *(_QWORD *)(v16 + 416);
          if ( v29 == -44 )
            v30 = 0;
          else
            v30 = *(unsigned __int8 *)(v29 + 49);
          LODWORD(v37) = *(_DWORD *)(v29 + 124);
          LODWORD(v36) = v30;
          qdf_trace_msg(
            0x81u,
            5u,
            "%s: mld peer %pK MAC %02x:%02x:%02x:**:**:%02x state %d",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "dp_peer_state_update",
            v36,
            v37);
        }
      }
    }
    dp_peer_unref_delete(v16, 7u, v20, v21, v22, v23, v24, v25, v26, v27);
    return 0;
  }
  else
  {
    if ( a2 )
    {
      v31 = *(unsigned __int8 *)a2;
      v32 = *((unsigned __int8 *)a2 + 1);
      v33 = *((unsigned __int8 *)a2 + 2);
      v34 = *((unsigned __int8 *)a2 + 5);
    }
    else
    {
      v33 = 0;
      v31 = 0;
      v32 = 0;
      v34 = 0;
    }
    qdf_trace_msg(
      0x81u,
      2u,
      "%s: %pK: Failed to find peer[%02x:%02x:%02x:**:**:%02x]",
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
      v31,
      v32,
      v33,
      v34);
    return 16;
  }
}
