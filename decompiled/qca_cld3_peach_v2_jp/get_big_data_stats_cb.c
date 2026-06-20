__int64 __fastcall get_big_data_stats_cb(_DWORD *a1, __int64 a2)
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
  __int64 v12; // x20
  _DWORD *v13; // x0

  v3 = osif_request_get(a2);
  if ( !v3 )
    return qdf_trace_msg(0x48u, 2u, "%s: Obsolete request", v4, v5, v6, v7, v8, v9, v10, v11, "get_big_data_stats_cb");
  v12 = v3;
  v13 = (_DWORD *)osif_request_priv(v3);
  v13[1] = a1[1];
  *v13 = *a1;
  v13[2] = a1[2];
  v13[3] = a1[3];
  v13[4] = a1[4];
  v13[5] = a1[5];
  v13[6] = a1[6];
  v13[7] = a1[7];
  osif_request_complete(v12);
  return osif_request_put(v12);
}
