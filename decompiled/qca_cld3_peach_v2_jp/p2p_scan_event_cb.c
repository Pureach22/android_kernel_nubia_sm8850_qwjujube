__int64 __fastcall p2p_scan_event_cb(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _DWORD *a10,
        __int64 a11)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *current_roc_ctx; // x0
  int v22; // w8
  __int64 v23; // x19
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x4
  __int64 v33; // x21
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x20
  __int64 v51; // x4
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  int v60; // w0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x1
  __int64 result; // x0
  unsigned int v71; // w0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  const char *v80; // x2
  const char *v81; // x2
  const char *v82; // x3
  __int64 v83; // x4
  __int64 v84; // x20
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v94[3]; // [xsp+8h] [xbp-18h] BYREF

  v94[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: soc:%pK, scan event:%d flag:%d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "p2p_scan_event_cb",
    a11,
    (unsigned int)a10[1],
    (unsigned int)a10[10]);
  if ( !a11 )
  {
    v80 = "%s: Invalid P2P context";
LABEL_23:
    result = qdf_trace_msg(0x4Eu, 2u, v80, v13, v14, v15, v16, v17, v18, v19, v20, "p2p_scan_event_cb");
    goto LABEL_24;
  }
  current_roc_ctx = p2p_find_current_roc_ctx(a11);
  if ( !current_roc_ctx )
  {
    v80 = "%s: Failed to find valid P2P roc context";
    goto LABEL_23;
  }
  v22 = a10[10];
  v23 = (__int64)current_roc_ctx;
  if ( (v22 & 1) == 0 && *((_DWORD *)current_roc_ctx + 60) == 7 )
    v22 = 1;
  *((_DWORD *)current_roc_ctx + 61) = v22;
  qdf_mtrace(21, 78, a10[1], *a10, a10[5]);
  v32 = (unsigned int)a10[1];
  if ( (int)v32 <= 2 )
  {
    if ( !(_DWORD)v32 )
    {
      v32 = *(unsigned int *)(v23 + 28);
      v81 = "%s: scan started, scan id:%d";
      *(_DWORD *)(v23 + 224) = 2;
      v82 = "p2p_process_scan_start_evt";
      goto LABEL_34;
    }
    if ( (_DWORD)v32 == 1 )
    {
LABEL_10:
      v33 = *(_QWORD *)(v23 + 16);
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: vdev_id:%d scan_id:%d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "p2p_process_scan_complete_evt",
        *(unsigned int *)(v23 + 24),
        *(unsigned int *)(v23 + 28),
        0);
      qdf_runtime_pm_allow_suspend((__int64 *)(v33 + 176));
      if ( (unsigned int)qdf_mc_timer_stop_sync(v23 + 56) )
        qdf_trace_msg(
          0x4Eu,
          2u,
          "%s: Failed to stop roc timer",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "p2p_process_scan_complete_evt");
      if ( (unsigned int)qdf_mc_timer_destroy(v23 + 56) )
        qdf_trace_msg(
          0x4Eu,
          2u,
          "%s: Failed to destroy roc timer",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "p2p_process_scan_complete_evt");
      v50 = *(_QWORD *)v33;
      v51 = *(_QWORD *)v33;
      v94[0] = 4;
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: psoc:%pK, is register rx:%d",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "p2p_mgmt_rx_ops",
        v51,
        0);
      v94[1] = tgt_p2p_mgmt_frame_rx_cb;
      v60 = wlan_mgmt_txrx_deregister_rx_cb(v50, 5u, (__int64)v94, 1u, v52, v53, v54, v55, v56, v57, v58, v59);
      *(_DWORD *)(v33 + 216) = -1;
      if ( v60 )
        qdf_trace_msg(
          0x4Eu,
          2u,
          "%s: Failed to deregister mgmt rx callback",
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          "p2p_process_scan_complete_evt");
      if ( !*(_DWORD *)(v23 + 52) )
        v61 = p2p_send_roc_event(v23, 1);
      p2p_destroy_roc_ctx(v23, 0, 1, v61, v62, v63, v64, v65, v66, v67, v68);
      result = qdf_event_set(v33 + 96, v69);
      if ( *(_DWORD *)(v33 + 24) )
      {
        v71 = qdf_list_peek_front((_QWORD *)(v33 + 8), &v93);
        if ( v71 )
          result = qdf_trace_msg(
                     0x4Eu,
                     2u,
                     "%s: Failed to peek roc req from front, status %d",
                     v72,
                     v73,
                     v74,
                     v75,
                     v76,
                     v77,
                     v78,
                     v79,
                     "p2p_process_scan_complete_evt",
                     v71);
        else
          result = p2p_execute_roc_req(v93, v72, v73, v74, v75, v76, v77, v78, v79);
      }
      goto LABEL_24;
    }
LABEL_27:
    v81 = "%s: drop scan event, %d";
    v82 = "p2p_scan_event_cb";
LABEL_34:
    result = qdf_trace_msg(0x4Eu, 8u, v81, v24, v25, v26, v27, v28, v29, v30, v31, v82, v32);
    goto LABEL_24;
  }
  if ( (_DWORD)v32 != 3 )
  {
    if ( (_DWORD)v32 == 4 || (_DWORD)v32 == 6 )
      goto LABEL_10;
    goto LABEL_27;
  }
  v83 = *(unsigned int *)(v23 + 28);
  v84 = *(_QWORD *)(v23 + 16);
  *(_DWORD *)(v23 + 224) = 3;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: scan_id:%d, roc_state:%d",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "p2p_process_ready_on_channel_evt",
    v83,
    3);
  if ( (unsigned int)qdf_mc_timer_start(v23 + 56, *(_DWORD *)(v23 + 48) + 10) )
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: Remain on Channel timer start failed",
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      "p2p_process_ready_on_channel_evt");
  if ( !*(_DWORD *)(v23 + 52) )
  {
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: user required roc, send roc event",
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      "p2p_process_ready_on_channel_evt");
    v85 = p2p_send_roc_event(v23, 0);
  }
  result = p2p_ready_to_tx_frame(v84, v23, v85, v86, v87, v88, v89, v90, v91, v92);
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
