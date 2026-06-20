__int64 __fastcall ucfg_nan_request_process_cb(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19

  v2 = osif_request_get(a1);
  if ( !v2 )
    return qdf_trace_msg(
             0x53u,
             8u,
             "%s: Obsolete request (cookie:0x%pK), do nothing",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "ucfg_nan_request_process_cb",
             a1);
  v11 = v2;
  osif_request_complete(v2);
  return osif_request_put(v11);
}
