bool __fastcall dp_find_peer_exist_on_other_vdev(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int16 *a3,
        unsigned __int16 a4)
{
  unsigned int v4; // w23
  int v7; // w19
  int v8; // w24
  bool v9; // w22
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x21
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

  v4 = a4;
  if ( a4 )
  {
    v7 = 0;
    v8 = a2;
    v9 = 1;
    while ( 1 )
    {
      if ( v8 != v7 )
      {
        v10 = dp_peer_find_hash_find(a1, a3, 0, v7, 7u);
        if ( v10 )
          break;
      }
      v9 = ++v7 < v4;
      if ( v4 == v7 )
        return v9;
    }
    v19 = v10;
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
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Duplicate peer %02x:%02x:%02x:**:**:%02x already exist on vdev %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "dp_find_peer_exist_on_other_vdev",
      v20,
      v21,
      v22,
      v23,
      v7);
    dp_peer_unref_delete(v19, 7u, v24, v25, v26, v27, v28, v29, v30, v31);
  }
  else
  {
    return 0;
  }
  return v9;
}
