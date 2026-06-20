__int64 __fastcall dp_get_vdevid(__int64 a1, unsigned __int16 *a2, __int64 a3, _BYTE *a4)
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
  __int64 v14; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v5 = dp_peer_find_hash_find(a1, a2, 0, 0xFFu, 7u);
  if ( !v5 )
    return 16;
  v14 = v5;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: peer %pK vdev %pK vdev id %d",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "dp_get_vdevid",
    v5,
    *(_QWORD *)(v5 + 24),
    *(unsigned __int8 *)(*(_QWORD *)(v5 + 24) + 59LL));
  *a4 = *(_BYTE *)(*(_QWORD *)(v14 + 24) + 59LL);
  dp_peer_unref_delete(v14, 7u, v15, v16, v17, v18, v19, v20, v21, v22);
  return 0;
}
