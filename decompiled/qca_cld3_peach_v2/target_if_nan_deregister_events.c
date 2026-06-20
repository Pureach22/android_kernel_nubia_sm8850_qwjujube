__int64 __fastcall target_if_nan_deregister_events(
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
  unsigned int v11; // w20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w21
  unsigned int v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w21
  unsigned int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w21
  unsigned int v50; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int v59; // w21
  unsigned int v60; // w0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w21
  unsigned int v70; // w0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  unsigned int v79; // w21
  unsigned int v80; // w0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  unsigned int v89; // w0
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD **)(v9 + 16)) != nullptr )
  {
    v11 = wmi_unified_unregister_event_handler(*(_QWORD **)(v9 + 16), 0xA4u, a2, a3, a4, a5, a6, a7, a8, a9);
    if ( v11 )
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: wmi event deregistration failed, ret: %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "target_if_nan_deregister_events",
        v11);
    v20 = wmi_unified_unregister_event_handler(v10, 0xA2u, v12, v13, v14, v15, v16, v17, v18, v19);
    if ( v20 )
    {
      v29 = v20;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: wmi event deregistration failed, ret: %d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "target_if_nan_deregister_events",
        v20);
      v11 = v29;
    }
    v30 = wmi_unified_unregister_event_handler(v10, 0xA1u, v21, v22, v23, v24, v25, v26, v27, v28);
    if ( v30 )
    {
      v39 = v30;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: wmi event deregistration failed, ret: %d",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "target_if_nan_deregister_events",
        v30);
      v11 = v39;
    }
    v40 = wmi_unified_unregister_event_handler(v10, 0xA0u, v31, v32, v33, v34, v35, v36, v37, v38);
    if ( v40 )
    {
      v49 = v40;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: wmi event deregistration failed, ret: %d",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "target_if_nan_deregister_events",
        v40);
      v11 = v49;
    }
    v50 = wmi_unified_unregister_event_handler(v10, 0x9Fu, v41, v42, v43, v44, v45, v46, v47, v48);
    if ( v50 )
    {
      v59 = v50;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: wmi event deregistration failed, ret: %d",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        "target_if_nan_deregister_events",
        v50);
      v11 = v59;
    }
    v60 = wmi_unified_unregister_event_handler(v10, 0x9Eu, v51, v52, v53, v54, v55, v56, v57, v58);
    if ( v60 )
    {
      v69 = v60;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: wmi event deregistration failed, ret: %d",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "target_if_nan_deregister_events",
        v60);
      v11 = v69;
    }
    v70 = wmi_unified_unregister_event_handler(v10, 0xA3u, v61, v62, v63, v64, v65, v66, v67, v68);
    if ( v70 )
    {
      v79 = v70;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: wmi event deregistration failed, ret: %d",
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        "target_if_nan_deregister_events",
        v70);
      v11 = v79;
    }
    v80 = wmi_unified_unregister_event_handler(v10, 0x9Du, v71, v72, v73, v74, v75, v76, v77, v78);
    if ( v80 )
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: wmi event deregistration failed, ret: %d",
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        "target_if_nan_deregister_events",
        v80);
      v11 = 1;
    }
    v89 = wmi_unified_unregister_event_handler(v10, 0xA5u, v81, v82, v83, v84, v85, v86, v87, v88);
    if ( !v89 )
      return 16 * (unsigned int)(v11 != 0);
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: wmi event deregistration failed, ret: %d",
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      "target_if_nan_deregister_events",
      v89);
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: handle is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_nan_deregister_events");
  }
  return 16;
}
