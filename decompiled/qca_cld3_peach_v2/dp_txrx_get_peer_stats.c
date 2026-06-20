__int64 __fastcall dp_txrx_get_peer_stats(__int64 a1, unsigned int a2, __int64 a3, void *a4)
{
  __int64 v8; // x0
  __int64 v9; // x20
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _DWORD *v19; // x8

  v8 = dp_peer_find_hash_find(a1, a3);
  if ( v8 )
  {
    v9 = v8;
    qdf_mem_set(a4, 0x11C0u, 0);
LABEL_3:
    dp_get_peer_stats(v9, (__int64)a4);
    dp_peer_unref_delete(v9, 7u, v10, v11, v12, v13, v14, v15, v16, v17);
    return 0;
  }
  v19 = *(_DWORD **)(a1 + 1536);
  if ( v19 )
  {
    if ( *(v19 - 1) != 69695039 )
      __break(0x8228u);
    v9 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD))v19)(a1, a3, 0, 7, a2);
    qdf_mem_set(a4, 0x11C0u, 0);
    if ( v9 )
      goto LABEL_3;
  }
  else
  {
    qdf_mem_set(a4, 0x11C0u, 0);
  }
  return 16;
}
