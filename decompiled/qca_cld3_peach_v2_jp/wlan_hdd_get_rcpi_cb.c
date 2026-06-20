__int64 __fastcall wlan_hdd_get_rcpi_cb(
        __int64 a1,
        __int64 a2,
        int a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v15; // x0
  __int64 v16; // x19
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2

  if ( !a1 )
  {
    v26 = "%s: No rcpi context";
    return qdf_trace_msg(0x33u, 2u, v26, a5, a6, a7, a8, a9, a10, a11, a12, "wlan_hdd_get_rcpi_cb");
  }
  v15 = osif_request_get(a1);
  if ( !v15 )
  {
    v26 = "%s: Obsolete RCPI request";
    return qdf_trace_msg(0x33u, 2u, v26, a5, a6, a7, a8, a9, a10, a11, a12, "wlan_hdd_get_rcpi_cb");
  }
  v16 = v15;
  v17 = osif_request_priv(v15);
  *(_DWORD *)(v17 + 4) = a2;
  *(_WORD *)(v17 + 8) = WORD2(a2);
  if ( a4 )
  {
    *(_DWORD *)v17 = 0;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Error in computing RCPI",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_hdd_get_rcpi_cb");
  }
  else
  {
    *(_DWORD *)v17 = a3;
  }
  osif_request_complete(v16);
  return osif_request_put(v16);
}
