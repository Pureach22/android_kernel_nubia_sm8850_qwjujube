__int64 __fastcall target_if_mlo_register_event_handler(
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
  unsigned int v11; // w0
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
  unsigned int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 result; // x0
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  unsigned int v88; // w19
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 2800);
    if ( v9 && (v10 = *(_QWORD **)(v9 + 16)) != nullptr )
    {
      v11 = wmi_unified_register_event(*(_QWORD *)(v9 + 16), 249, (__int64)target_if_mlo_link_removal_event_handler);
      if ( v11 )
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: Couldn't register handler for Link removal WMI event %d",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "target_if_mlo_register_event_handler",
          v11);
      v20 = wmi_unified_register_event((__int64)v10, 250, (__int64)target_if_mlo_tlt_selection_event_handler);
      if ( v20 )
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: Couldn't register handler for 3 Link mlo tlt WMI event %d",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "target_if_mlo_register_event_handler",
          v20);
      v29 = wmi_unified_register_event_handler(
              v10,
              0xF8u,
              (__int64)target_if_mlo_link_set_active_resp_handler,
              2u,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28);
      if ( v29 )
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: Register mlo link set active resp cb errcode %d",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "target_if_mlo_register_event_handler",
          v29);
      wmi_unified_register_event_handler(
        v10,
        0x10Du,
        (__int64)target_if_mlo_vdev_tid_to_link_map_event_handler,
        2u,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37);
      wmi_unified_register_event_handler(
        v10,
        0x111u,
        (__int64)target_if_mlo_link_state_info_event_handler,
        2u,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45);
      v54 = wmi_unified_register_event_handler(
              v10,
              0xFBu,
              (__int64)target_if_mlo_link_disable_request_event_handler,
              2u,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53);
      if ( v54 )
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: Couldn't register handler for link disable request WMI event %d",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "target_if_mlo_register_event_handler",
          v54);
      if ( (unsigned int)wmi_unified_register_event_handler(
                           v10,
                           0xFCu,
                           (__int64)target_if_mlo_link_switch_request_event_handler,
                           2u,
                           v55,
                           v56,
                           v57,
                           v58,
                           v59,
                           v60,
                           v61,
                           v62) )
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: Register event:%d failed",
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          "target_if_mlo_register_link_switch_event_handler",
          252);
      if ( (unsigned int)wmi_unified_register_event_handler(
                           v10,
                           0xFDu,
                           (__int64)target_if_mlo_link_state_switch_event_handler,
                           2u,
                           v63,
                           v64,
                           v65,
                           v66,
                           v67,
                           v68,
                           v69,
                           v70) )
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: Register event:%d failed",
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          "target_if_mlo_register_link_switch_event_handler",
          253);
      result = wmi_unified_register_event_handler(
                 v10,
                 0xFEu,
                 (__int64)&target_if_mlo_link_recfg_indication_event_handler,
                 2u,
                 v71,
                 v72,
                 v73,
                 v74,
                 v75,
                 v76,
                 v77,
                 v78);
      if ( (_DWORD)result )
      {
        v88 = result;
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: Register event:%d failed",
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          "target_if_mlo_register_link_switch_event_handler",
          254);
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: Couldn't register handler for link switch WMI event %d",
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          "target_if_mlo_register_event_handler",
          v88);
        if ( v88 == 11 )
          return 0;
        else
          return v88;
      }
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: wmi_handle is null",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "target_if_mlo_register_event_handler");
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: PSOC is NULL!",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_mlo_register_event_handler");
    return 29;
  }
  return result;
}
