__int64 __fastcall dp_rx_peer_ext_evt(__int64 a1, unsigned __int16 *a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  int v12; // w9
  __int64 v13; // x19
  unsigned __int8 *v15; // x8
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7

  v3 = dp_peer_find_hash_find(a1, *((unsigned __int16 **)a2 + 1), 0, *((_BYTE *)a2 + 2), 0xCu);
  if ( v3 )
  {
    v12 = *(_DWORD *)(v3 + 500);
    *(_BYTE *)(v3 + 424) = *((_BYTE *)a2 + 3);
    *(_BYTE *)(v3 + 425) = *((_BYTE *)a2 + 4);
    if ( v12 )
    {
      v13 = v3;
      ((void (*)(void))dp_map_link_id_band)();
      v3 = v13;
    }
    dp_peer_unref_delete(v3, 0xCu, v4, v5, v6, v7, v8, v9, v10, v11);
    return 0;
  }
  else
  {
    v15 = *((unsigned __int8 **)a2 + 1);
    if ( v15 )
    {
      v16 = *v15;
      v17 = v15[1];
      v18 = v15[2];
      LODWORD(v15) = v15[5];
    }
    else
    {
      v18 = 0;
      v16 = 0;
      v17 = 0;
    }
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: peer NULL, id %u, MAC %02x:%02x:%02x:**:**:%02x, vdev_id %u",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "dp_rx_peer_ext_evt",
      *a2,
      v16,
      v17,
      v18,
      (_DWORD)v15,
      *((unsigned __int8 *)a2 + 2));
    return 16;
  }
}
