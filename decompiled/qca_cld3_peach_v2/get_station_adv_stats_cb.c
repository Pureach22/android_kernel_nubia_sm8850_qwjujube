__int64 __fastcall get_station_adv_stats_cb(__int64 a1, __int64 a2)
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
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  __int64 v23; // x21
  unsigned int v24; // w22
  void *v25; // x0

  v3 = osif_request_get(a2);
  if ( v3 )
  {
    v12 = v3;
    v13 = osif_request_priv(v3);
    if ( !*(_QWORD *)(a1 + 56) || (v22 = *(_DWORD *)(a1 + 48)) == 0 )
    {
      qdf_trace_msg(0x48u, 8u, "%s: Invalid stats", v14, v15, v16, v17, v18, v19, v20, v21, "get_station_adv_stats_cb");
      goto LABEL_9;
    }
    v23 = v13;
    v24 = 24 * v22;
    if ( 24 * v22 )
    {
      v25 = (void *)_qdf_mem_malloc((unsigned int)(24 * v22), "get_station_adv_stats_cb", 1566);
      *(_QWORD *)(v23 + 56) = v25;
      if ( !v25 )
      {
LABEL_9:
        osif_request_complete(v12);
        return osif_request_put(v12);
      }
      qdf_mem_copy(v25, *(const void **)(a1 + 56), v24);
      v22 = *(_DWORD *)(a1 + 48);
    }
    *(_DWORD *)(v23 + 48) = v22;
    goto LABEL_9;
  }
  return qdf_trace_msg(0x48u, 2u, "%s: Obsolete request", v4, v5, v6, v7, v8, v9, v10, v11, "get_station_adv_stats_cb");
}
