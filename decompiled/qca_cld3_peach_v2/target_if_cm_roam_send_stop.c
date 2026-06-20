__int64 __fastcall target_if_cm_roam_send_stop(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 *v11; // x9
  __int64 v12; // x20
  __int64 v13; // x19
  unsigned int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w19
  __int64 result; // x0
  const char *v27; // x2
  unsigned int v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w19
  __int64 v38; // x9
  __int64 v39; // x22
  __int64 v40; // x9
  unsigned int v41; // w21
  _DWORD *v42; // x8
  __int64 v43; // x0
  bool v44; // w21
  __int64 v45; // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x8
  unsigned int v63; // w20
  __int64 (__fastcall *v64)(__int64, __int64); // x8
  __int64 v65; // x1
  __int64 v66; // x0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x8
  int v76; // w9
  unsigned int v77; // w0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  unsigned int v86; // w19
  __int64 v87; // x5
  const char *v88; // x2

  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 )
  {
    v27 = "%s: PDEV is NULL";
    goto LABEL_9;
  }
  v11 = *(__int64 **)(v10 + 1240);
  if ( !v11 || (v12 = *v11) == 0 )
  {
    v27 = "%s: wmi_handle is null";
LABEL_9:
    qdf_trace_msg(0x49u, 2u, v27, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cm_roam_get_wmi_handle_from_vdev");
    return 16;
  }
  v13 = *(_QWORD *)(v10 + 80);
  if ( !v13 )
  {
    qdf_trace_msg(0x49u, 2u, "%s: psoc handle is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cm_roam_send_stop");
    return 4;
  }
  v16 = target_if_cm_roam_offload_11k_params(*v11, a2 + 1960);
  if ( v16 )
  {
    v25 = v16;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: 11k offload disable not sent, status %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "target_if_cm_roam_send_stop",
      v16);
    return v25;
  }
  v28 = wmi_unified_send_btm_config(v12, a2 + 2028);
  if ( v28 )
  {
    v37 = v28;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Sending BTM config to fw failed",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "target_if_cm_roam_send_stop");
    return v37;
  }
  if ( *(_BYTE *)(a2 + 3925) == 1 )
  {
    v38 = *(_QWORD *)(a1 + 216);
    if ( v38 )
    {
      v39 = *(_QWORD *)(v38 + 80);
      if ( v39 )
      {
        v40 = *(_QWORD *)(v39 + 2136);
        v41 = *(unsigned __int8 *)(a1 + 168);
        if ( v40 )
        {
          v42 = *(_DWORD **)(v40 + 1136);
          if ( v42 )
          {
            if ( *(v42 - 1) != -672477040 )
              __break(0x8228u);
            v43 = ((__int64 (__fastcall *)(__int64, _QWORD))v42)(v39, v41);
            if ( v43 )
            {
              *(_DWORD *)(v43 + 72) = 10000;
              v44 = (unsigned int)target_if_vdev_mgr_rsp_timer_start(v39, v43, 5u) == 0;
LABEL_47:
              v45 = a2;
              goto LABEL_25;
            }
            v87 = *(unsigned __int8 *)(v39 + 48);
            v88 = "%s: VDEV_%d: PSOC_%d No vdev rsp timer";
LABEL_46:
            qdf_trace_msg(
              0x68u,
              2u,
              v88,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              "target_if_start_rso_stop_timer",
              v41,
              v87);
            v44 = 0;
            goto LABEL_47;
          }
        }
        else
        {
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: rx_ops is NULL",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "target_if_vdev_mgr_get_rx_ops");
        }
        v87 = *(unsigned __int8 *)(v39 + 48);
        v88 = "%s: VEV_%d: PSOC_%d No Rx Ops";
        goto LABEL_46;
      }
    }
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: psoc handle is NULL",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "target_if_start_rso_stop_timer");
  }
  v45 = a2;
  v44 = 0;
LABEL_25:
  if ( (unsigned int)wmi_unified_roam_scan_offload_mode_cmd(v12, v45 + 4) )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: vdev:%d Send RSO mode cmd failed",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "target_if_cm_roam_send_stop",
      *(unsigned int *)(a2 + 4));
    if ( v44 )
    {
      v62 = *(_QWORD *)(v13 + 2136);
      if ( v62 )
      {
        if ( *(_QWORD *)(v62 + 1072) )
        {
          v63 = *(unsigned __int8 *)(a1 + 168);
          v64 = *(__int64 (__fastcall **)(__int64, __int64))(v62 + 1136);
          v65 = *(unsigned __int8 *)(a1 + 168);
          if ( *((_DWORD *)v64 - 1) != -672477040 )
            __break(0x8228u);
          v66 = v64(v13, v65);
          if ( v66 )
            target_if_vdev_mgr_rsp_timer_stop(v13, v66, 5u);
          else
            qdf_trace_msg(
              0x68u,
              2u,
              "%s: vdev response timer is null VDEV_%d PSOC_%d",
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              "target_if_cm_roam_abort_rso_stop_timer",
              v63,
              *(unsigned __int8 *)(v13 + 48));
          return 0;
        }
      }
      else
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: rx_ops is NULL",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "target_if_vdev_mgr_get_rx_ops");
      }
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: No Rx Ops",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "target_if_cm_roam_abort_rso_stop_timer");
    }
    return 0;
  }
  target_if_cm_roam_scan_offload_rssi_thresh(v12, (char *)(a2 + 3816), v46, v47, v48, v49, v50, v51, v52, v53);
  v75 = a2;
  if ( *(_BYTE *)(a2 + 1) || (v77 = target_if_cm_roam_scan_filter(v12, 2, a2 + 2064), v75 = a2, !v77) )
  {
    target_if_cm_roam_disconnect_params(v12, 2, v75 + 3552);
    target_if_cm_roam_idle_params(v12, 2, a2 + 3564);
    if ( !*(_DWORD *)(a2 + 12) )
    {
      v76 = *(unsigned __int8 *)(a1 + 168);
      *(_DWORD *)(a2 + 3596) = 0;
      *(_DWORD *)(a2 + 3592) = v76;
      *(_DWORD *)(a2 + 3604) = 0;
      *(_DWORD *)(a2 + 3656) = -1;
      *(_DWORD *)(a2 + 3664) = -1;
      *(_DWORD *)(a2 + 3672) = -1;
      *(_DWORD *)(a2 + 3680) = -1;
      *(_DWORD *)(a2 + 3688) = -1;
      *(_DWORD *)(a2 + 3696) = -1;
      *(_DWORD *)(a2 + 3704) = -1;
      *(_DWORD *)(a2 + 3712) = -1;
      *(_DWORD *)(a2 + 3720) = -1;
      *(_DWORD *)(a2 + 3728) = -1;
      *(_DWORD *)(a2 + 3736) = -1;
      *(_DWORD *)(a2 + 3744) = -1;
      *(_DWORD *)(a2 + 3752) = -1;
      *(_DWORD *)(a2 + 3760) = -1;
      *(_DWORD *)(a2 + 3768) = -1;
      *(_DWORD *)(a2 + 3776) = -1;
      *(_DWORD *)(a2 + 3784) = -1;
      *(_DWORD *)(a2 + 3792) = -1;
      *(_DWORD *)(a2 + 3800) = -1;
      *(_DWORD *)(a2 + 3808) = -1;
      target_if_cm_roam_triggers(a1, a2 + 3592);
    }
    result = 0;
  }
  else
  {
    v86 = v77;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: clear for roam scan filter failed",
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      "target_if_cm_roam_send_stop");
    result = v86;
  }
  if ( v44 )
    *(_BYTE *)(a2 + 3924) = 0;
  return result;
}
