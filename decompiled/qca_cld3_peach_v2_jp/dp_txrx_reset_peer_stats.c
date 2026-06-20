__int64 __fastcall dp_txrx_reset_peer_stats(__int64 a1, int a2, int a3)
{
  __int64 v4; // x0
  __int64 *v5; // x19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  int v15; // w9
  __int64 v16; // x8
  __int64 v17; // x8
  void (__fastcall *v18)(_QWORD); // x8

  v4 = dp_peer_find_hash_find(a1, a3);
  if ( !v4 )
    return 16;
  v5 = (__int64 *)v4;
  qdf_mem_set((void *)(v4 + 160), 0x30u, 0);
  v14 = *v5;
  if ( *v5 )
  {
    v15 = *(unsigned __int8 *)(v14 + 2221);
    *(_DWORD *)(v14 + 44) = 0;
    *(_QWORD *)(v14 + 36) = 0;
    *(_QWORD *)(v14 + 28) = 0;
    *(_QWORD *)(v14 + 20) = 0;
    *(_QWORD *)(v14 + 12) = 0;
    qdf_mem_set((void *)(v14 + 2224), (unsigned int)(3256 * v15), 0);
  }
  v16 = *(_QWORD *)(a1 + 20056);
  if ( v16 )
  {
    v17 = *(_QWORD *)(v16 + 416);
    if ( v17 && (v18 = *(void (__fastcall **)(_QWORD))(v17 + 160)) != nullptr )
    {
      if ( *((_DWORD *)v18 - 1) != 1810062434 )
        __break(0x8228u);
      v18(v5);
    }
    else
    {
      qdf_trace_msg(
        0x92u,
        8u,
        "%s: callback not registered",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "dp_monitor_peer_reset_stats");
    }
  }
  dp_peer_unref_delete((__int64)v5, 7u, v6, v7, v8, v9, v10, v11, v12, v13);
  return 0;
}
