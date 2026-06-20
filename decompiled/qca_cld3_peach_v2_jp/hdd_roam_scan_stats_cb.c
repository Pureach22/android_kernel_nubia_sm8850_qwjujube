__int64 __fastcall hdd_roam_scan_stats_cb(
        __int64 a1,
        _DWORD *a2,
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
  __int64 v21; // x19
  _QWORD *v22; // x21
  unsigned int v23; // w22
  void *v24; // x0
  void *v25; // x23
  const char *v26; // x2
  unsigned int v27; // w1

  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_roam_scan_stats_cb");
  v12 = osif_request_get(a1);
  if ( v12 )
  {
    v21 = v12;
    if ( a2 )
    {
      v22 = (_QWORD *)osif_request_priv(v12);
      v23 = 328 * *a2 + 8;
      v24 = (void *)_qdf_mem_malloc(v23, "hdd_roam_scan_stats_cb", 88);
      if ( v24 )
      {
        v25 = v24;
        qdf_mem_copy(v24, a2, v23);
        *v22 = v25;
      }
    }
    else
    {
      qdf_trace_msg(0x33u, 2u, "%s: Invalid response", v13, v14, v15, v16, v17, v18, v19, v20, "hdd_roam_scan_stats_cb");
    }
    osif_request_complete(v21);
    osif_request_put(v21);
    v26 = "%s: exit";
    v27 = 8;
  }
  else
  {
    v26 = "%s: Obsolete roam scan stats request";
    v27 = 2;
  }
  return qdf_trace_msg(0x33u, v27, v26, v13, v14, v15, v16, v17, v18, v19, v20, "hdd_roam_scan_stats_cb");
}
