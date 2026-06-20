__int64 __fastcall wma_wmi_work_close(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x19
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7

  qdf_trace_msg(0x36u, 8u, "%s: Enter", a1, a2, a3, a4, a5, a6, a7, a8, "wma_wmi_work_close");
  context = _cds_get_context(54, (__int64)"wma_wmi_work_close", v8, v9, v10, v11, v12, v13, v14, v15);
  if ( !context )
    return 4;
  v25 = *context;
  if ( (unsigned int)_wmi_validate_handle(
                       *context,
                       (__int64)"wma_wmi_work_close",
                       v17,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23,
                       v24) )
    return 4;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: calling wmi_unified_remove_work",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "wma_wmi_work_close");
  wmi_unified_remove_work(v25);
  qdf_trace_msg(0x36u, 8u, "%s: Exit", v35, v36, v37, v38, v39, v40, v41, v42, "wma_wmi_work_close");
  return 0;
}
