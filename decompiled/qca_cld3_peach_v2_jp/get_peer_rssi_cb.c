__int64 __fastcall get_peer_rssi_cb(__int64 a1, __int64 a2)
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
  __int64 v13; // x0
  int v14; // w8
  unsigned int v15; // w21
  __int64 v16; // x22
  void *v17; // x0
  const char *v19; // x2

  v3 = osif_request_get(a2);
  if ( !v3 )
    return qdf_trace_msg(0x48u, 2u, "%s: Obsolete request", v4, v5, v6, v7, v8, v9, v10, v11, "get_peer_rssi_cb");
  v12 = v3;
  if ( *(_QWORD *)(a1 + 40) )
  {
    v13 = osif_request_priv(v3);
    v14 = *(_DWORD *)(a1 + 32);
    v15 = 88 * v14;
    if ( 88 * v14 )
    {
      v16 = v13;
      v17 = (void *)_qdf_mem_malloc((unsigned int)(88 * v14), "get_peer_rssi_cb", 469);
      *(_QWORD *)(v16 + 40) = v17;
      if ( v17 )
      {
        *(_DWORD *)(v16 + 32) = *(_DWORD *)(a1 + 32);
        qdf_mem_copy(v17, *(const void **)(a1 + 40), v15);
      }
      goto LABEL_10;
    }
    v19 = "%s: Invalid rssi stats";
  }
  else
  {
    v19 = "%s: no peer stats";
  }
  qdf_trace_msg(0x48u, 2u, v19, v4, v5, v6, v7, v8, v9, v10, v11, "get_peer_rssi_cb");
LABEL_10:
  osif_request_complete(v12);
  return osif_request_put(v12);
}
