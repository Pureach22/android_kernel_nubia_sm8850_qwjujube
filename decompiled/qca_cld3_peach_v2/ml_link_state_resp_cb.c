__int64 __fastcall ml_link_state_resp_cb(const void *a1, __int64 a2)
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
  void *v13; // x0

  v3 = osif_request_get(a2);
  if ( !v3 )
    return qdf_trace_msg(0x33u, 2u, "%s: Obsolete request", v4, v5, v6, v7, v8, v9, v10, v11, "ml_link_state_resp_cb");
  v12 = v3;
  v13 = (void *)osif_request_priv(v3);
  qdf_mem_copy(v13, a1, 0x2Cu);
  osif_request_complete(v12);
  return osif_request_put(v12);
}
