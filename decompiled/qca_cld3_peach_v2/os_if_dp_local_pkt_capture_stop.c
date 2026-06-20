__int64 __fastcall os_if_dp_local_pkt_capture_stop(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  _QWORD *v22; // x21
  _QWORD *v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  _QWORD *v32; // x19
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8
  _DWORD *v42; // x8
  __int64 v43; // x8
  _DWORD *v44; // x8

  context = _cds_get_context(71, (__int64)"os_if_dp_local_pkt_capture_stop", a3, a4, a5, a6, a7, a8, a9, a10);
  result = 4;
  if ( !a1 || !context )
    return result;
  v22 = context;
  v23 = _cds_get_context(71, (__int64)"os_if_stop_capture_allowed", v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !v23 )
    return 4;
  if ( a2 != 6 )
  {
    qdf_trace_msg(
      0x48u,
      3u,
      "%s: Operation not permitted in opmode: %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "os_if_stop_capture_allowed",
      a2);
    return 12;
  }
  v32 = v23;
  if ( !ucfg_dp_is_local_pkt_capture_enabled() )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: local pkt capture feature not enabled",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "os_if_stop_capture_allowed");
    return 11;
  }
  if ( !*v32 )
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "cdp_is_local_pkt_capture_running");
LABEL_22:
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: local pkt capture not running, no need to stop",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "os_if_stop_capture_allowed");
    return 12;
  }
  v41 = *(_QWORD *)(*v32 + 24LL);
  if ( !v41 )
    goto LABEL_22;
  v42 = *(_DWORD **)(v41 + 120);
  if ( !v42 )
    goto LABEL_22;
  if ( *(v42 - 1) != -1653155309 )
    __break(0x8228u);
  if ( (((__int64 (__fastcall *)(_QWORD *, _QWORD))v42)(v32, 0) & 1) == 0 )
    goto LABEL_22;
  if ( !*v22 )
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "cdp_stop_local_pkt_capture");
    return 16;
  }
  v43 = *(_QWORD *)(*v22 + 24LL);
  if ( !v43 )
    return 16;
  v44 = *(_DWORD **)(v43 + 112);
  if ( !v44 )
    return 16;
  if ( *(v44 - 1) != 261447488 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(_QWORD *, _QWORD))v44)(v22, 0);
}
