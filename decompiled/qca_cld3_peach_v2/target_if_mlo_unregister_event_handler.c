__int64 __fastcall target_if_mlo_unregister_event_handler(
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
  __int64 v9; // x8
  _QWORD *v10; // x19
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
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  const char *v60; // x2

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 2800);
    if ( v9 )
    {
      v10 = *(_QWORD **)(v9 + 16);
      if ( v10 )
      {
        wmi_unified_unregister_event_handler(*(_QWORD **)(v9 + 16), 0xF8u, a2, a3, a4, a5, a6, a7, a8, a9);
        wmi_unified_unregister_event(v10, 0xF9u, v11, v12, v13, v14, v15, v16, v17, v18);
        wmi_unified_unregister_event(v10, 0xFAu, v19, v20, v21, v22, v23, v24, v25, v26);
        wmi_unified_unregister_event_handler(v10, 0x10Du, v27, v28, v29, v30, v31, v32, v33, v34);
        wmi_unified_unregister_event_handler(v10, 0x111u, v35, v36, v37, v38, v39, v40, v41, v42);
        wmi_unified_unregister_event(v10, 0xFBu, v43, v44, v45, v46, v47, v48, v49, v50);
        wmi_unified_unregister_event(v10, 0xFCu, v51, v52, v53, v54, v55, v56, v57, v58);
        return 0;
      }
    }
    v60 = "%s: wmi_handle is null";
  }
  else
  {
    v60 = "%s: PSOC is NULL!";
  }
  qdf_trace_msg(0x49u, 2u, v60, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_mlo_unregister_event_handler");
  return 4;
}
