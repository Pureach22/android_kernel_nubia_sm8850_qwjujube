__int64 __fastcall hdd_beacon_debugstats_cb(
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
  __int64 v23; // x9
  __int64 v24; // x9
  __int64 v25; // x10
  __int64 v26; // x11
  const char *v27; // x2
  unsigned int v28; // w1

  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_beacon_debugstats_cb");
  v12 = osif_request_get(a2);
  if ( v12 )
  {
    v21 = v12;
    v22 = osif_request_priv(v12);
    v23 = *(_QWORD *)(a1 + 8);
    *(_QWORD *)v22 = *(_QWORD *)a1;
    *(_QWORD *)(v22 + 8) = v23;
    v25 = *(_QWORD *)(a1 + 24);
    v24 = *(_QWORD *)(a1 + 32);
    v26 = *(_QWORD *)(a1 + 16);
    *(_DWORD *)(v22 + 40) = *(_DWORD *)(a1 + 40);
    *(_QWORD *)(v22 + 24) = v25;
    *(_QWORD *)(v22 + 32) = v24;
    *(_QWORD *)(v22 + 16) = v26;
    osif_request_complete(v21);
    osif_request_put(v21);
    v27 = "%s: exit";
    v28 = 8;
  }
  else
  {
    v27 = "%s: Obsolete request";
    v28 = 2;
  }
  return qdf_trace_msg(0x33u, v28, v27, v13, v14, v15, v16, v17, v18, v19, v20, "hdd_beacon_debugstats_cb");
}
