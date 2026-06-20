__int64 __fastcall target_if_vdev_mgr_wmi_event_register(
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
  __int64 v10; // x19
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
  unsigned int v59; // w20
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 2800);
    if ( v9 && (v10 = *(_QWORD *)(v9 + 16)) != 0 )
    {
      if ( (unsigned int)wmi_unified_register_event_handler(
                           *(_QWORD *)(v9 + 16),
                           10,
                           target_if_vdev_mgr_stop_response_handler,
                           2) )
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: failed to register for stop response",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "target_if_vdev_mgr_wmi_event_register");
      if ( (unsigned int)wmi_unified_register_event_handler(v10, 171, target_if_vdev_mgr_delete_response_handler, 2) )
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: failed to register for delete response",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "target_if_vdev_mgr_wmi_event_register");
      if ( (unsigned int)wmi_unified_register_event_handler(v10, 7, target_if_vdev_mgr_start_response_handler, 2) )
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: failed to register for start response",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "target_if_vdev_mgr_wmi_event_register");
      if ( (unsigned int)wmi_unified_register_event_handler(
                           v10,
                           143,
                           target_if_vdev_mgr_peer_delete_all_response_handler,
                           2) )
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: failed to register for peer delete all response",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "target_if_vdev_mgr_wmi_event_register");
      if ( (unsigned int)wmi_unified_register_event_handler(
                           v10,
                           229,
                           target_if_vdev_mgr_multi_vdev_restart_resp_handler,
                           2) )
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: failed to register for multivdev restart response",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "target_if_vdev_mgr_wmi_event_register");
      if ( (wmi_service_enabled(v10, 0) & 1) != 0
        && (unsigned int)wmi_unified_register_event_handler(v10, 144, target_if_pdev_csa_status_event_handler, 2) )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: failed to register for csa event handler",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "target_if_vdev_mgr_wmi_event_register");
      }
      v59 = wmi_unified_register_event_handler(v10, 272, target_if_vdev_mgr_csa_ie_received_handler, 2);
      if ( v59 )
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: failed to register for CSA IE Received Event",
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "target_if_vdev_mgr_wmi_event_register");
      wmi_unified_register_event_handler(v10, 257, target_if_update_macaddr_conf_evt_handler, 2);
      wmi_unified_register_event_handler(v10, 258, target_if_quiet_offload_event_handler, 2);
      return v59;
    }
    else
    {
      qdf_trace_msg(
        0x68u,
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
        "target_if_vdev_mgr_wmi_event_register");
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: PSOC is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_vdev_mgr_wmi_event_register");
    return 29;
  }
}
