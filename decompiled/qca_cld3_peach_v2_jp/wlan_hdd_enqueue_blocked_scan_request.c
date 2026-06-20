__int64 __fastcall wlan_hdd_enqueue_blocked_scan_request(__int64 a1, __int64 a2, char a3)
{
  __int64 v6; // x0
  _QWORD *v7; // x20
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7

  v6 = _qdf_mem_malloc(0x30u, "wlan_hdd_enqueue_blocked_scan_request", 399);
  if ( v6 )
  {
    *(_BYTE *)(v6 + 28) = a3;
    v7 = (_QWORD *)v6;
    *(_QWORD *)(v6 + 32) = a1;
    *(_QWORD *)(v6 + 16) = a2;
    *(_DWORD *)(v6 + 24) = 0;
    qdf_mutex_acquire(a1 + 44448);
    if ( *(_DWORD *)(a1 + 44440) <= 7u )
    {
      qdf_list_insert_back((_QWORD *)(a1 + 44424), v7);
      qdf_mutex_release(a1 + 44448);
      return 0;
    }
    qdf_mutex_release(a1 + 44448);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Maximum number of block scan request reached!",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wlan_hdd_enqueue_blocked_scan_request");
    _qdf_mem_free((__int64)v7);
  }
  return 4294967274LL;
}
