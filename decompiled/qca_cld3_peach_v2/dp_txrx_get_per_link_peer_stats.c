__int64 __fastcall dp_txrx_get_per_link_peer_stats(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        void *a4,
        int a5,
        unsigned __int8 a6)
{
  __int64 v12; // x25
  _DWORD *v13; // x8
  __int64 v14; // x2
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  if ( (a5 | 2) != 3 || (v12 = dp_peer_find_hash_find(a1, a3)) == 0 )
  {
    if ( (a5 & 0xFFFFFFFE) != 2 )
      return 16;
    v13 = *(_DWORD **)(a1 + 1536);
    if ( !v13 )
      return 16;
    if ( *(v13 - 1) != 69695039 )
      __break(0x8228u);
    v12 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD))v13)(a1, a3, 0, 8, a2);
    if ( !v12 )
      return 16;
  }
  qdf_mem_set(a4, 0x11C0u, 0);
  dp_get_per_link_peer_stats(v12, (__int64)a4, v14, a6);
  dp_peer_unref_delete(v12, 8u, v15, v16, v17, v18, v19, v20, v21, v22);
  return 0;
}
