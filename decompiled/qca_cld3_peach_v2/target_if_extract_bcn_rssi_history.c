__int64 __fastcall target_if_extract_bcn_rssi_history(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x29
  __int64 v5; // x30
  unsigned int v7; // w8
  __int64 v12; // x0
  __int64 v13; // x0
  _DWORD *v14; // x23
  __int64 v15; // x25
  unsigned __int64 v16; // x24
  unsigned int recv_bcn_stats; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w19
  __int64 v27; // [xsp+8h] [xbp-48h]

  if ( (*(_BYTE *)(a2 + 2) & 8) == 0 )
    return 0;
  v27 = v5;
  v7 = *(_DWORD *)(a2 + 64);
  if ( !v7 )
    return 0;
  v12 = _qdf_mem_malloc(84LL * v7, "target_if_extract_bcn_rssi_history", 976);
  *(_QWORD *)(a3 + 208) = v12;
  if ( !v12 )
    return 2;
  v13 = _qdf_mem_malloc(0x54u, "target_if_extract_bcn_rssi_history", 980);
  if ( !v13 )
  {
    _qdf_mem_free(*(_QWORD *)(a3 + 208));
    *(_QWORD *)(a3 + 208) = 0;
    return 2;
  }
  *(_DWORD *)(a3 + 200) = 0;
  v14 = (_DWORD *)v13;
  if ( !*(_DWORD *)(a2 + 64) )
  {
LABEL_10:
    _qdf_mem_free((__int64)v14);
    return 0;
  }
  v15 = 0;
  v16 = 0;
  while ( 1 )
  {
    qdf_mem_set(v14, 0x54u, 0);
    recv_bcn_stats = wmi_extract_recv_bcn_stats(a1, a4, (unsigned int)v16, v14);
    if ( recv_bcn_stats )
      break;
    ++*(_DWORD *)(a3 + 200);
    *(_BYTE *)(*(_QWORD *)(a3 + 208) + v15) = *v14;
    qdf_mem_copy((void *)(*(_QWORD *)(a3 + 208) + v15 + 4), v14 + 1, 0x50u);
    ++v16;
    v15 += 84;
    if ( v16 >= *(unsigned int *)(a2 + 64) )
      goto LABEL_10;
  }
  v26 = recv_bcn_stats;
  qdf_trace_msg(
    0x62u,
    2u,
    "%s: Error:%d wmi_extract_recv_bcn_stats failed",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "target_if_extract_bcn_rssi_history",
    recv_bcn_stats,
    v4,
    v27);
  _qdf_mem_free((__int64)v14);
  return v26;
}
