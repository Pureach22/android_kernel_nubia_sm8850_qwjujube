__int64 __fastcall osif_twt_disable_complete_cb(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x20
  _DWORD *v23; // x0
  const char *v25; // x2

  qdf_trace_msg(
    0x48u,
    8u,
    "%s: osif_handle_twt_disable_complete",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "osif_twt_disable_complete_cb");
  v13 = osif_request_get(a11);
  if ( v13 )
  {
    v22 = v13;
    v23 = (_DWORD *)osif_request_priv(v13);
    if ( v23 )
    {
      *v23 = *(_DWORD *)(a10 + 4);
      osif_request_complete(v22);
      osif_request_put(v22);
      return 0;
    }
    v25 = "%s: obsolete twt_en_priv";
  }
  else
  {
    v25 = "%s: obsolete request";
  }
  qdf_trace_msg(0x48u, 2u, v25, v14, v15, v16, v17, v18, v19, v20, v21, "osif_twt_disable_complete_cb");
  return 16;
}
