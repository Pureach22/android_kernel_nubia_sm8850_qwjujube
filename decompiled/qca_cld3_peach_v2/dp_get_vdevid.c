__int64 __fastcall dp_get_vdevid(__int64 a1, unsigned __int16 *a2, int a3, _BYTE *a4)
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
  _DWORD *v17; // x8
  __int64 v18; // x20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  if ( (a3 | 2) != 3 || (v8 = dp_peer_find_hash_find(a1, a2, 0, 0xFFu, 7u)) == 0 )
  {
    if ( (a3 & 0xFFFFFFFE) != 2 )
      return 16;
    v17 = *(_DWORD **)(a1 + 1536);
    if ( !v17 )
      return 16;
    if ( *(v17 - 1) != 69695039 )
      __break(0x8228u);
    v8 = ((__int64 (__fastcall *)(__int64, unsigned __int16 *, _QWORD, __int64, __int64))v17)(a1, a2, 0, 7, 255);
    if ( !v8 )
      return 16;
  }
  v18 = v8;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: peer %pK vdev %pK vdev id %d",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "dp_get_vdevid",
    v8,
    *(_QWORD *)(v8 + 24),
    *(unsigned __int8 *)(*(_QWORD *)(v8 + 24) + 59LL));
  *a4 = *(_BYTE *)(*(_QWORD *)(v18 + 24) + 59LL);
  dp_peer_unref_delete(v18, 7u, v19, v20, v21, v22, v23, v24, v25, v26);
  return 0;
}
