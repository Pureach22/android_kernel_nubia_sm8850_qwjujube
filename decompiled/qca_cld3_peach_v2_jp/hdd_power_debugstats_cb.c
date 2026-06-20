__int64 __fastcall hdd_power_debugstats_cb(
        __int64 *a1,
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
  __int64 v21; // x19
  _QWORD *v22; // x0
  __int64 v23; // x8
  __int64 v24; // x10
  __int64 v25; // x11
  int v26; // w8
  unsigned int v27; // w22
  _QWORD *v28; // x21
  void *v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  const char *v38; // x2
  unsigned int v39; // w1

  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_power_debugstats_cb");
  v12 = osif_request_get(a2);
  if ( v12 )
  {
    v21 = v12;
    v22 = (_QWORD *)osif_request_priv(v12);
    v23 = a1[3];
    v24 = *a1;
    v25 = a1[1];
    v22[2] = a1[2];
    v22[3] = v23;
    *v22 = v24;
    v22[1] = v25;
    v26 = *((_DWORD *)a1 + 5);
    if ( v26 )
    {
      v27 = 4 * v26;
      v28 = v22;
      v29 = (void *)_qdf_mem_malloc((unsigned int)(4 * v26), "hdd_power_debugstats_cb", 257);
      v28[3] = v29;
      if ( v29 )
      {
        qdf_mem_copy(v29, (const void *)a1[3], v27);
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Power stats memory alloc fails!",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "hdd_power_debugstats_cb");
        *((_DWORD *)v28 + 5) = 0;
      }
    }
    osif_request_complete(v21);
    osif_request_put(v21);
    v38 = "%s: exit";
    v39 = 8;
  }
  else
  {
    v38 = "%s: Obsolete request";
    v39 = 2;
  }
  return qdf_trace_msg(0x33u, v39, v38, v13, v14, v15, v16, v17, v18, v19, v20, "hdd_power_debugstats_cb");
}
