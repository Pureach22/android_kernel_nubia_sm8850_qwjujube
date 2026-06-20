__int64 __fastcall dp_txrx_get_peer_stats_based_on_peer_type(__int64 a1, unsigned int a2, __int64 a3, void *a4, int a5)
{
  __int64 v10; // x0
  __int64 v11; // x22
  _DWORD *v12; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( (a5 | 2) == 3 )
  {
    v10 = dp_peer_find_hash_find(a1, a3);
    if ( v10 )
    {
      v11 = v10;
      qdf_mem_set(a4, 0x11C0u, 0);
LABEL_9:
      dp_get_peer_stats(v11, (__int64)a4);
      dp_peer_unref_delete(v11, 7u, v13, v14, v15, v16, v17, v18, v19, v20);
      return 0;
    }
  }
  if ( (a5 & 0xFFFFFFFE) == 2 && (v12 = *(_DWORD **)(a1 + 1536)) != nullptr )
  {
    if ( *(v12 - 1) != 69695039 )
      __break(0x8228u);
    v11 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD))v12)(a1, a3, 0, 7, a2);
    qdf_mem_set(a4, 0x11C0u, 0);
    if ( v11 )
      goto LABEL_9;
  }
  else
  {
    qdf_mem_set(a4, 0x11C0u, 0);
  }
  return 16;
}
