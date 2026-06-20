bool __fastcall dp_find_peer_exist_on_vdev(__int64 a1, unsigned __int8 a2, unsigned __int16 *a3)
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
  __int64 v12; // x19

  v3 = dp_peer_find_hash_find(a1, a3, 0, a2, 7u);
  v12 = v3;
  if ( v3 )
    dp_peer_unref_delete(v3, 7u, v4, v5, v6, v7, v8, v9, v10, v11);
  return v12 != 0;
}
