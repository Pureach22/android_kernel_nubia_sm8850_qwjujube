__int64 __fastcall lim_enable_obss_detection_config(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x4
  __int64 result; // x0
  __int64 v23; // x4
  const char *v24; // x2
  int v25; // w0
  unsigned int v26; // w1

  if ( !a2 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: Invalid session, protection not enabled",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "lim_enable_obss_detection_config");
  if ( a2[428] )
  {
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2605LL) == 1 )
    {
      v12 = lim_obss_send_detection_cfg(a1, a2, 1);
      v21 = a2[10];
      if ( v12 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: vdev %d: offload enable failed, trying legacy",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "lim_enable_obss_detection_config",
          v21);
        a2[10006] = 0;
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: vdev %d: offload detection enabled",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "lim_enable_obss_detection_config",
          v21);
        a2[10006] = 1;
        result = lim_obss_send_detection_cfg(a1, a2, 1);
        if ( (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 2605LL) & 1) != 0 )
          return result;
      }
    }
    v25 = qdf_mc_timer_start((__int64)(a2 + 8064), 0xFA0u);
    v23 = a2[10];
    if ( !v25 )
    {
      v24 = "%s: vdev %d: legacy detection enabled";
      v26 = 8;
      return qdf_trace_msg(0x35u, v26, v24, a3, a4, a5, a6, a7, a8, a9, a10, "lim_enable_obss_detection_config", v23);
    }
    v24 = "%s: vdev %d: start timer failed";
  }
  else
  {
    v23 = a2[10];
    v24 = "%s: protectiond disabled, force policy, session %d";
  }
  v26 = 2;
  return qdf_trace_msg(0x35u, v26, v24, a3, a4, a5, a6, a7, a8, a9, a10, "lim_enable_obss_detection_config", v23);
}
