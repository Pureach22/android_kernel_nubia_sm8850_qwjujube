__int64 __fastcall hdd_debugfs_process_ll_stats(__int64 *a1, int *a2, __int64 a3)
{
  __int64 v4; // x22
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int v16; // w8
  __int64 v17; // x20
  __int64 result; // x0
  unsigned int v19; // w8
  int v20; // w9
  int v21; // w8

  v4 = *a1;
  v7 = osif_request_priv(a3);
  v16 = *a2;
  v17 = v7;
  if ( (*a2 & 1) != 0 )
  {
    result = hdd_debugfs_process_radio_stats(v4, (unsigned int)a2[3], a2 + 7, (unsigned int)a2[5]);
    if ( a2[3] )
      goto LABEL_13;
    v19 = *(_DWORD *)(v17 + 28) & 0xFFFFFFFE;
    goto LABEL_7;
  }
  if ( (v16 & 2) == 0 )
  {
    if ( (v16 & 4) == 0 )
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: INVALID LL_STATS_NOTIFY RESPONSE",
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 "hdd_debugfs_process_ll_stats");
      goto LABEL_13;
    }
    result = hdd_debugfs_process_peer_stats(v4, a2 + 7);
    if ( a2[3] )
      goto LABEL_13;
    v19 = *(_DWORD *)(v17 + 28) & 0xFFFFFFFB;
LABEL_7:
    *(_DWORD *)(v17 + 28) = v19;
    goto LABEL_13;
  }
  result = ((__int64 (__fastcall *)(__int64 *, int *, _QWORD))hdd_debugfs_process_iface_stats)(
             a1,
             a2 + 7,
             (unsigned int)a2[5]);
  v20 = *(_DWORD *)(v17 + 28);
  v21 = *(unsigned __int8 *)(v17 + 49);
  if ( !a2[5] )
    v20 &= 0xFFFFFFF9;
  *(_DWORD *)(v17 + 28) = v20 & 0xFFFFFFFD;
  if ( v21 == 1 )
    *(_DWORD *)(v17 + 52) &= ~(1 << *((_BYTE *)a2 + 4));
LABEL_13:
  if ( !*(_DWORD *)(v17 + 28) && (*(_BYTE *)(v17 + 49) != 1 || !*(_DWORD *)(v17 + 52)) )
  {
    sme_radio_tx_mem_free(result);
    return osif_request_complete(a3);
  }
  return result;
}
