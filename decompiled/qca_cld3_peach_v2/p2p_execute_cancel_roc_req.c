__int64 __fastcall p2p_execute_cancel_roc_req(
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
  __int64 *v10; // x22
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x23
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  __int64 v30; // x0
  unsigned int *v31; // x8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 *v40; // x20
  int v41; // w4
  int v42; // w8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w20
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int *v60; // x8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x21
  __int64 v78; // x4
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  _QWORD v96[3]; // [xsp+8h] [xbp-18h] BYREF

  v96[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(__int64 **)(a1 + 16);
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: p2p execute cancel roc req",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "p2p_execute_cancel_roc_req");
  *(_DWORD *)(a1 + 224) = 4;
  if ( (unsigned int)qdf_mc_timer_stop_sync(a1 + 56) )
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: Failed to stop roc timer, roc %pK",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "p2p_execute_cancel_roc_req",
      a1);
  v19 = *(_QWORD *)(a1 + 16);
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: abort scan, scan req id:%d, scan id:%d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "p2p_roc_abort",
    *(unsigned __int16 *)(v19 + 80),
    *(unsigned int *)(a1 + 28));
  v20 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)v19,
          *(unsigned int *)(a1 + 24),
          15);
  if ( v20 )
  {
    v29 = v20;
    v30 = _qdf_mem_malloc(0x20u, "p2p_roc_abort", 263);
    if ( v30 )
    {
      *(_QWORD *)v30 = v29;
      v40 = (__int64 *)v30;
      *(_DWORD *)(v30 + 12) = *(unsigned __int16 *)(v19 + 80);
      v41 = *(_DWORD *)(a1 + 28);
      *(_DWORD *)(v30 + 16) = v41;
      v42 = *(_DWORD *)(a1 + 24);
      *(_DWORD *)(v30 + 20) = 1;
      *(_DWORD *)(v30 + 24) = v42;
      qdf_mtrace(78, 21, 1u, *(_BYTE *)(v29 + 168), v41);
      v51 = wlan_scan_cancel(v40, v43, v44, v45, v46, v47, v48, v49, v50);
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: abort scan, scan req id:%d, scan id:%d, status:%d",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "p2p_roc_abort",
        *(unsigned __int16 *)(v19 + 80),
        *(unsigned int *)(a1 + 28),
        v51);
      wlan_objmgr_vdev_release_ref(v29, 0xFu, v60, v61, v62, v63, v64, v65, v66, v67, v68);
      if ( !v51 )
        goto LABEL_10;
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v29, 0xFu, v31, v32, v33, v34, v35, v36, v37, v38, v39);
      v51 = 2;
    }
  }
  else
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: vdev is NULL", v21, v22, v23, v24, v25, v26, v27, v28, "p2p_roc_abort");
    v51 = 4;
  }
  qdf_trace_msg(
    0x4Eu,
    2u,
    "%s: Failed to abort scan, status:%d, destroy roc %pK",
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    v76,
    "p2p_execute_cancel_roc_req",
    v51,
    a1);
  qdf_mc_timer_destroy(a1 + 56);
  v77 = *v10;
  v78 = *v10;
  v96[0] = 4;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: psoc:%pK, is register rx:%d",
    v79,
    v80,
    v81,
    v82,
    v83,
    v84,
    v85,
    v86,
    "p2p_mgmt_rx_ops",
    v78,
    0);
  v96[1] = tgt_p2p_mgmt_frame_rx_cb;
  wlan_mgmt_txrx_deregister_rx_cb(v77, 5u, (__int64)v96, 1u, v87, v88, v89, v90, v91, v92, v93, v94);
  p2p_destroy_roc_ctx(a1, 1, 1);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v51;
}
