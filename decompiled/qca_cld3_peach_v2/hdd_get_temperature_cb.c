__int64 __fastcall hdd_get_temperature_cb(
        int a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  const char *v22; // x2
  unsigned int v23; // w1

  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_get_temperature_cb");
  v12 = osif_request_get(a2);
  if ( v12 )
  {
    v21 = v12;
    *(_DWORD *)osif_request_priv(v12) = a1;
    osif_request_complete(v21);
    osif_request_put(v21);
    v22 = "%s: exit";
    v23 = 8;
  }
  else
  {
    v22 = "%s: Obsolete request";
    v23 = 2;
  }
  return qdf_trace_msg(0x33u, v23, v22, v13, v14, v15, v16, v17, v18, v19, v20, "hdd_get_temperature_cb");
}
