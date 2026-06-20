__int64 __fastcall hdd_enable_monitor_mode(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 **context; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x8
  _DWORD *v28; // x8
  __int64 v29; // x1
  __int64 *v30; // x8
  __int64 v31; // x8
  _DWORD *v32; // x8

  context = (__int64 **)_cds_get_context(71, (__int64)"hdd_enable_monitor_mode", a2, a3, a4, a5, a6, a7, a8, a9);
  qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", v11, v12, v13, v14, v15, v16, v17, v18, "hdd_enable_monitor_mode", a1 + 296);
  if ( !context )
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance:",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "cdp_get_mon_vdev_from_pdev");
    goto LABEL_17;
  }
  if ( !*context )
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance:",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "cdp_get_mon_vdev_from_pdev");
    goto LABEL_11;
  }
  v27 = **context;
  if ( !v27 )
    return 0;
  v28 = *(_DWORD **)(v27 + 376);
  if ( !v28 )
  {
LABEL_11:
    v29 = 234;
    v30 = *context;
    if ( *context )
      goto LABEL_12;
LABEL_17:
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v19, v20, v21, v22, v23, v24, v25, v26, "cdp_set_monitor_mode");
    return 0;
  }
  if ( *(v28 - 1) != -1653155309 )
    __break(0x8228u);
  v29 = ((unsigned int (__fastcall *)(__int64 **, _QWORD))v28)(context, 0);
  v30 = *context;
  if ( !*context )
    goto LABEL_17;
LABEL_12:
  v31 = *v30;
  if ( !v31 )
    return 0;
  v32 = *(_DWORD **)(v31 + 168);
  if ( !v32 )
    return 0;
  if ( *(v32 - 1) != -254072184 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64 **, __int64, _QWORD))v32)(context, v29, 0);
}
