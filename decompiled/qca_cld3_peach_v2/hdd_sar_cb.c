__int64 __fastcall hdd_sar_cb(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  __int64 v21; // x20
  void *v22; // x0
  const char *v23; // x2
  unsigned int v24; // w1

  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_sar_cb");
  if ( a2 )
  {
    v20 = osif_request_get(a1);
    if ( v20 )
    {
      v21 = v20;
      v22 = (void *)osif_request_priv(v20);
      memcpy(v22, a2, 0x408u);
      osif_request_complete(v21);
      osif_request_put(v21);
      v23 = "%s: exit";
    }
    else
    {
      v23 = "%s: Obsolete request";
    }
    v24 = 8;
  }
  else
  {
    v23 = "%s: response is NULL";
    v24 = 2;
  }
  return qdf_trace_msg(0x33u, v24, v23, v12, v13, v14, v15, v16, v17, v18, v19, "hdd_sar_cb");
}
