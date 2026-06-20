__int64 __fastcall wma_config_plm(
        __int64 result,
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
  _QWORD *v11; // x20
  unsigned int started; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x5
  const char *v22; // x2
  const char *v23; // x3
  unsigned int v24; // w0
  const char *v25; // x4

  if ( result && a2 )
  {
    v11 = (_QWORD *)result;
    if ( *(_BYTE *)(a2 + 421) == 1 )
    {
      qdf_trace_msg(0x36u, 8u, "%s: PLM Start", a3, a4, a5, a6, a7, a8, a9, a10, "wma_plm_start");
      started = wmi_unified_plm_start_cmd(*v11, a2);
      v21 = started;
      if ( !started )
      {
        v22 = "%s: Plm start request sent successfully for vdev %d";
        v23 = "wma_plm_start";
        *(_BYTE *)(v11[65] + 488LL * *(unsigned __int8 *)(a2 + 420) + 172) = 1;
        return qdf_trace_msg(
                 0x36u,
                 8u,
                 v22,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v23,
                 *(unsigned __int8 *)(a2 + 420),
                 v21);
      }
    }
    else if ( (*(_BYTE *)(*(_QWORD *)(result + 520) + 488LL * *(unsigned __int8 *)(a2 + 420) + 172) & 1) != 0 )
    {
      qdf_trace_msg(0x36u, 8u, "%s: PLM Stop", a3, a4, a5, a6, a7, a8, a9, a10, "wma_plm_stop");
      v24 = wmi_unified_plm_stop_cmd(*v11, a2);
      v21 = v24;
      if ( !v24 )
      {
        v22 = "%s: Plm stop request sent successfully for vdev %d";
        v23 = "wma_plm_stop";
        *(_BYTE *)(v11[65] + 488LL * *(unsigned __int8 *)(a2 + 420) + 172) = 0;
        return qdf_trace_msg(
                 0x36u,
                 8u,
                 v22,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v23,
                 *(unsigned __int8 *)(a2 + 420),
                 v21);
      }
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: No active plm req found, skip plm stop req",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wma_plm_stop");
      v21 = 16;
    }
    if ( *(_BYTE *)(a2 + 421) )
      v25 = "start";
    else
      v25 = "stop";
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: PLM %s failed %d",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "wma_config_plm",
             v25,
             v21);
  }
  return result;
}
