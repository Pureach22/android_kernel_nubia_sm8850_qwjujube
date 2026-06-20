__int64 __fastcall wma_flush_complete_evt_handler(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x22
  _QWORD *v22; // x20
  unsigned int v23; // w19
  __int64 v24; // x0
  __int64 v25; // x1
  __int64 v26; // x2
  __int64 v27; // x3
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x8
  _DWORD *v53; // x8
  __int64 v54; // x2
  __int64 v55; // x4
  __int64 v56; // x5
  const char *v57; // x2
  _QWORD *v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  _QWORD *v67; // x20
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x0
  __int64 v77; // x1
  void (__fastcall *v78)(__int64, __int64); // x8
  __int64 is_log_report_in_progress; // x0
  __int64 v81; // x1
  __int64 v82; // x2
  __int64 v83; // x3
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  __int64 v100; // x0
  __int64 v101; // x1
  __int64 v102; // x2
  __int64 v103; // x3
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  const char *v112; // x2

  context = _cds_get_context(71, (__int64)"wma_flush_complete_evt_handler", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !a2 )
  {
    v57 = "%s: Invalid log flush complete event buffer";
LABEL_31:
    qdf_trace_msg(0x36u, 2u, v57, v13, v14, v15, v16, v17, v18, v19, v20, "wma_flush_complete_evt_handler");
    return 16;
  }
  v21 = *a2;
  v22 = context;
  v23 = *(_DWORD *)(*a2 + 4);
  v24 = qdf_trace_msg(
          0x36u,
          8u,
          "%s: Received reason code %d from FW",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "wma_flush_complete_evt_handler",
          v23);
  if ( !v23 )
  {
    is_log_report_in_progress = cds_is_log_report_in_progress(v24, v25, v26, v27);
    if ( (is_log_report_in_progress & 1) == 0 )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Received WMI flush event without sending CMD",
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        "wma_flush_complete_evt_handler");
      return 4294967274LL;
    }
    if ( (cds_is_log_report_in_progress(is_log_report_in_progress, v81, v82, v83) & 1) == 0 )
      goto LABEL_28;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Received WMI flush event in response to flush CMD",
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      "wma_flush_complete_evt_handler");
    v100 = qdf_mc_timer_stop(a1 + 2744);
    if ( (_DWORD)v100 )
      v100 = qdf_trace_msg(
               0x36u,
               2u,
               "%s: Failed to stop the log completion timeout",
               v104,
               v105,
               v106,
               v107,
               v108,
               v109,
               v110,
               v111,
               "wma_flush_complete_evt_handler");
    goto LABEL_34;
  }
  if ( v23 != 4105 )
  {
    if ( v23 == 4102 && *(_WORD *)(v21 + 14) == 681 )
    {
      qdf_trace_msg(0x36u, 8u, "Data Stall event:", v28, v29, v30, v31, v32, v33, v34, v35);
      v24 = qdf_trace_msg(
              0x36u,
              8u,
              "data_stall_type: %x vdev_id_bitmap: %x reason_code1: %x reason_code2: %x recovery_type: %x ",
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              *(unsigned int *)(v21 + 20),
              *(unsigned int *)(v21 + 16),
              *(unsigned int *)(v21 + 24),
              *(unsigned int *)(v21 + 28),
              *(unsigned int *)(v21 + 32));
      if ( v22 && *v22 )
      {
        v52 = *(_QWORD *)(*v22 + 64LL);
        if ( v52 )
        {
          v53 = *(_DWORD **)(v52 + 88);
          if ( v53 )
          {
            v55 = *(unsigned int *)(v21 + 16);
            v54 = *(unsigned int *)(v21 + 20);
            v56 = *(unsigned int *)(v21 + 32);
            if ( *(v53 - 1) != -889045584 )
              __break(0x8228u);
            v24 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, _QWORD, __int64, __int64))v53)(
                    v22,
                    2,
                    v54,
                    0,
                    v55,
                    v56);
          }
        }
      }
      else
      {
        v24 = qdf_trace_msg(
                0x45u,
                1u,
                "%s invalid instance",
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                "cdp_post_data_stall_event");
      }
    }
    if ( (cds_is_log_report_in_progress(v24, v25, v26, v27) & 1) != 0 )
    {
LABEL_28:
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Bug report already in progress - dropping! type:%d, indicator=%d reason_code=%d",
        v92,
        v93,
        v94,
        v95,
        v96,
        v97,
        v98,
        v99,
        "wma_flush_complete_evt_handler",
        1,
        3,
        v23);
      return 16;
    }
    v100 = cds_set_log_completion(1u, 3u, v23, 0);
    if ( (_DWORD)v100 )
    {
      v57 = "%s: Failed to set log trigger params";
      goto LABEL_31;
    }
LABEL_34:
    cds_logging_set_fw_flush_complete(v100, v101, v102, v103);
    return 0;
  }
  v58 = _cds_get_context(53, (__int64)"wma_process_cal_fail_info", v28, v29, v30, v31, v32, v33, v34, v35);
  if ( !v58 )
  {
    v112 = "%s: Invalid mac context";
LABEL_37:
    qdf_trace_msg(0x36u, 2u, v112, v59, v60, v61, v62, v63, v64, v65, v66, "wma_process_cal_fail_info");
    return 0;
  }
  if ( !v58[2804] )
  {
    v112 = "%s: Callback not registered for cal failure event";
    goto LABEL_37;
  }
  if ( *(_WORD *)(v21 + 42) != 1037 )
  {
    v112 = "%s: Invalid TLV header in cal failure event";
    goto LABEL_37;
  }
  v67 = v58;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Calibration failure event:",
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    "wma_process_cal_fail_info");
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: calType: %x calFailureReasonCode: %x",
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    "wma_process_cal_fail_info",
    *(unsigned int *)(v21 + 44),
    *(unsigned int *)(v21 + 48));
  v76 = *(unsigned int *)(v21 + 44);
  v77 = *(unsigned int *)(v21 + 48);
  v78 = (void (__fastcall *)(__int64, __int64))v67[2804];
  if ( *((_DWORD *)v78 - 1) != 2130452855 )
    __break(0x8228u);
  v78(v76, v77);
  return 0;
}
