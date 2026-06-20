__int64 __fastcall wma_wmi_service_close(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 global_context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  __int64 *context; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x21
  __int64 v32; // x20
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // w8
  int v50; // w21
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x0

  v8 = qdf_trace_msg(0x36u, 8u, "%s: Enter", a1, a2, a3, a4, a5, a6, a7, a8, "wma_wmi_service_close");
  global_context = cds_get_global_context(v8, v9, v10, v11);
  if ( !global_context )
  {
    qdf_trace_msg(0x36u, 2u, "%s: Invalid CDS context", v13, v14, v15, v16, v17, v18, v19, v20, "wma_wmi_service_close");
    return 4;
  }
  v21 = global_context;
  context = _cds_get_context(54, (__int64)"wma_wmi_service_close", v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !context )
    return 4;
  v31 = *context;
  v32 = (__int64)context;
  if ( (unsigned int)_wmi_validate_handle(
                       *context,
                       (__int64)"wma_wmi_service_close",
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       v30) )
    return 4;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: calling wmi_unified_detach",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "wma_wmi_service_close");
  wmi_unified_detach(v31);
  v49 = *(unsigned __int16 *)(v32 + 162);
  *(_QWORD *)v32 = 0;
  if ( v49 )
  {
    v50 = 0;
    do
      wma_vdev_deinit(*(_QWORD *)(v32 + 520) + 488LL * (unsigned __int8)v50++, v41, v42, v43, v44, v45, v46, v47, v48);
    while ( *(unsigned __int16 *)(v32 + 162) > (unsigned int)(unsigned __int8)v50 );
  }
  _qdf_mem_free(*(_QWORD *)(v32 + 520));
  cds_free_context(54, v32, v51, v52, v53, v54, v55, v56, v57, v58);
  v67 = *(_QWORD *)(v21 + 72);
  if ( v67 )
    _qdf_mem_free(v67);
  *(_QWORD *)(v21 + 72) = 0;
  qdf_trace_msg(0x36u, 8u, "%s: Exit", v59, v60, v61, v62, v63, v64, v65, v66, "wma_wmi_service_close");
  return 0;
}
