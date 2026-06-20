__int64 __fastcall target_if_wifi_pos_deregister_events(
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
  _QWORD *v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  _QWORD *v21; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  _QWORD *v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8
  _QWORD *v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x8
  _QWORD *v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x8
  _QWORD *v62; // x0

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v11 = *(_QWORD **)(v9 + 16)) != nullptr )
  {
    wmi_unified_unregister_event_handler(v11, 0xA6u, a2, a3, a4, a5, a6, a7, a8, a9);
    v20 = *(_QWORD *)(a1 + 2800);
    if ( v20 )
      v21 = *(_QWORD **)(v20 + 16);
    else
      v21 = nullptr;
    wmi_unified_unregister_event_handler(v21, 0x1Au, v12, v13, v14, v15, v16, v17, v18, v19);
    v31 = *(_QWORD *)(a1 + 2800);
    if ( v31 )
      v32 = *(_QWORD **)(v31 + 16);
    else
      v32 = nullptr;
    wmi_unified_unregister_event_handler(v32, 0x1Bu, v23, v24, v25, v26, v27, v28, v29, v30);
    v41 = *(_QWORD *)(a1 + 2800);
    if ( v41 )
      v42 = *(_QWORD **)(v41 + 16);
    else
      v42 = nullptr;
    wmi_unified_unregister_event_handler(v42, 0x1Cu, v33, v34, v35, v36, v37, v38, v39, v40);
    v51 = *(_QWORD *)(a1 + 2800);
    if ( v51 && (v52 = *(_QWORD **)(v51 + 16)) != nullptr )
    {
      wmi_unified_unregister_event_handler(v52, 0x107u, v43, v44, v45, v46, v47, v48, v49, v50);
      v61 = *(_QWORD *)(a1 + 2800);
      if ( v61 )
        v62 = *(_QWORD **)(v61 + 16);
      else
        v62 = nullptr;
      wmi_unified_unregister_event_handler(v62, 0x108u, v53, v54, v55, v56, v57, v58, v59, v60);
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: psoc or psoc->tgt_if_handle is null",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "target_if_wifi_pos_unregister_11az_events");
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: psoc or psoc->tgt_if_handle is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_wifi_pos_deregister_events");
    return 4;
  }
}
