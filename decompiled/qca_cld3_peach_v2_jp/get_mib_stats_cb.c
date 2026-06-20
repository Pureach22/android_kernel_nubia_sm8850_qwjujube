__int64 __fastcall get_mib_stats_cb(__int64 a1, __int64 a2)
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
  __int64 v13; // x21
  void *v14; // x0

  v3 = osif_request_get(a2);
  if ( !v3 )
    return qdf_trace_msg(0x48u, 2u, "%s: Obsolete request", v4, v5, v6, v7, v8, v9, v10, v11, "get_mib_stats_cb");
  v12 = v3;
  v13 = osif_request_priv(v3);
  v14 = (void *)_qdf_mem_malloc(0xB0u, "get_mib_stats_cb", 1323);
  *(_QWORD *)(v13 + 112) = v14;
  if ( v14 )
  {
    *(_DWORD *)(v13 + 104) = *(_DWORD *)(a1 + 104);
    qdf_mem_copy(v14, *(const void **)(a1 + 112), 0xB0u);
  }
  osif_request_complete(v12);
  return osif_request_put(v12);
}
