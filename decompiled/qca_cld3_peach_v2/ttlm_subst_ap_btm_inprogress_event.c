__int64 __fastcall ttlm_subst_ap_btm_inprogress_event(__int64 a1, __int16 a2, __int64 a3, __int64 a4)
{
  __int64 first_vdev_by_ml_peer; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x20
  __int64 bsspeer; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w0
  __int64 v44; // x8
  _BOOL4 v45; // w19
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  int v63; // w22
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned int *v72; // x8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7

  if ( a2 == 5 )
  {
    v43 = ttlm_handle_rx_action_rsp_in_sta_in_progress_state(a1, a4);
    v44 = *(_QWORD *)(a1 + 720);
    v45 = v43 == 0;
    wlan_sm_transition_to(v44, 2u, v46, v47, v48, v49, v50, v51, v52, v53);
    return v45;
  }
  if ( a2 != 7 )
    return 0;
  first_vdev_by_ml_peer = mlo_get_first_vdev_by_ml_peer(a1);
  if ( !first_vdev_by_ml_peer )
  {
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: vdev is null",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "ttlm_handle_btm_link_disable_t2lm_frame");
LABEL_11:
    wlan_sm_transition_to(*(_QWORD *)(a1 + 720), 2u, v55, v56, v57, v58, v59, v60, v61, v62);
    return 0;
  }
  v15 = first_vdev_by_ml_peer;
  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(first_vdev_by_ml_peer, 0x5Au);
  if ( !bsspeer )
  {
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: peer is null",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "ttlm_handle_btm_link_disable_t2lm_frame");
    goto LABEL_10;
  }
  v25 = bsspeer;
  if ( (unsigned int)wlan_t2lm_check_concurrency_curr_force(v15, a4) )
  {
    v26 = wlan_mlo_send_ttlm_complete(v15, a1, 0);
    wlan_objmgr_peer_release_ref(v25, 0x5Au, v26, v27, v28, v29, v30, v31, v32, v33);
LABEL_10:
    wlan_objmgr_vdev_release_ref(v15, 0x5Au, v34, v35, v36, v37, v38, v39, v40, v41, v42);
    goto LABEL_11;
  }
  v63 = t2lm_deliver_event(v15, v25, 2, a4, 0, a4 + 4);
  wlan_objmgr_peer_release_ref(v25, 0x5Au, v64, v65, v66, v67, v68, v69, v70, v71);
  wlan_objmgr_vdev_release_ref(v15, 0x5Au, v72, v73, v74, v75, v76, v77, v78, v79, v80);
  if ( v63 )
    goto LABEL_11;
  if ( (unsigned int)qdf_mc_timer_start(a1 + 736, 0x1388u) )
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: Failed to start the timer",
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      "ttlm_subst_ap_btm_inprogress_event");
  return 1;
}
