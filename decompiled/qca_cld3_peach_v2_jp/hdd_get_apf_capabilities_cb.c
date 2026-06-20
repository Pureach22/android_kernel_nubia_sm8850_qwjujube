__int64 __fastcall hdd_get_apf_capabilities_cb(
        __int64 a1,
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
  __int64 v22; // x0
  int v23; // w9
  const char *v24; // x2
  unsigned int v25; // w1

  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_get_apf_capabilities_cb");
  v12 = osif_request_get(a1);
  if ( v12 )
  {
    v21 = v12;
    v22 = osif_request_priv(v12);
    v23 = *(_DWORD *)(a2 + 8);
    *(_QWORD *)v22 = *(_QWORD *)a2;
    *(_DWORD *)(v22 + 8) = v23;
    osif_request_complete(v21);
    osif_request_put(v21);
    v24 = "%s: exit";
    v25 = 8;
  }
  else
  {
    v24 = "%s: Obsolete request";
    v25 = 2;
  }
  return qdf_trace_msg(0x33u, v25, v24, v13, v14, v15, v16, v17, v18, v19, v20, "hdd_get_apf_capabilities_cb");
}
