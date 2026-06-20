__int64 *__fastcall wma_check_and_set_wake_timer(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 *v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x21
  _BYTE *v29; // x9
  const char *v30; // x2
  const char *v31; // x3
  unsigned int v32; // w1

  result = _cds_get_context(54, (__int64)"wma_check_and_set_wake_timer", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !result )
    return result;
  v19 = result;
  if ( (wmi_service_enabled(*result, 0x92u, v11, v12, v13, v14, v15, v16, v17, v18) & 1) == 0 )
  {
    v30 = "%s: TIME_PATTERN is not enabled";
LABEL_12:
    v31 = "wma_check_and_set_wake_timer";
    v32 = 8;
    return (__int64 *)qdf_trace_msg(0x36u, v32, v30, v20, v21, v22, v23, v24, v25, v26, v27, v31);
  }
  if ( !*((_WORD *)v19 + 81) )
  {
LABEL_11:
    v30 = "%s: set key not in progress for any vdev";
    goto LABEL_12;
  }
  v28 = 0;
  v29 = (_BYTE *)(v19[65] + 432);
  while ( *(v29 - 248) != 1 || *v29 != 1 )
  {
    ++v28;
    v29 += 488;
    if ( *((unsigned __int16 *)v19 + 81) == v28 )
      goto LABEL_11;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: send timer pattern with time: %d and vdev = %d to fw",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "wma_wow_set_wake_time",
    a1,
    (unsigned __int8)v28);
  result = (__int64 *)wmi_unified_wow_timer_pattern_cmd(*v19, (unsigned int)v28, 0, a1);
  if ( (_DWORD)result )
  {
    v30 = "%s: Failed to send timer pattern to fw";
    v31 = "wma_wow_set_wake_time";
    v32 = 2;
    return (__int64 *)qdf_trace_msg(0x36u, v32, v30, v20, v21, v22, v23, v24, v25, v26, v27, v31);
  }
  return result;
}
