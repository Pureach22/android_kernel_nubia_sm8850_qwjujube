__int64 __fastcall ttlm_handle_rx_action_rsp_in_sta_in_progress_state(__int64 a1, __int64 a2)
{
  __int64 first_vdev_by_ml_peer; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 bsspeer; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int *v74; // x8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  unsigned int *v83; // x8
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
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7

  first_vdev_by_ml_peer = mlo_get_first_vdev_by_ml_peer(a1);
  if ( first_vdev_by_ml_peer )
  {
    v13 = first_vdev_by_ml_peer;
    bsspeer = wlan_objmgr_vdev_try_get_bsspeer(first_vdev_by_ml_peer, 0x5Au);
    if ( bsspeer )
    {
      v23 = bsspeer;
      if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 736) == 21 && (unsigned int)qdf_mc_timer_stop(a1 + 736) )
      {
        qdf_trace_msg(
          0x99u,
          2u,
          "%s: Failed to stop the TTLM request timer",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "ttlm_handle_rx_action_rsp_in_sta_in_progress_state");
        wlan_objmgr_peer_release_ref(v23, 0x5Au, v32, v33, v34, v35, v36, v37, v38, v39);
        wlan_objmgr_vdev_release_ref(v13, 0x5Au, v40, v41, v42, v43, v44, v45, v46, v47, v48);
        return 16;
      }
      if ( *(_DWORD *)(a2 + 8) )
      {
        qdf_trace_msg(
          0x99u,
          8u,
          "%s: T2LM rsp status: %d, clear ongoing tid mapping",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "ttlm_handle_rx_action_rsp_in_sta_in_progress_state");
        v50 = wlan_t2lm_clear_ongoing_negotiation(v23);
        wlan_mlo_send_ttlm_complete(v13, a1, 0, v50, v51, v52, v53, v54, v55, v56, v57);
        wlan_sm_transition_to(*(_QWORD *)(a1 + 720), 2u, v58, v59, v60, v61, v62, v63, v64, v65);
LABEL_9:
        wlan_objmgr_peer_release_ref(v23, 0x5Au, v66, v67, v68, v69, v70, v71, v72, v73);
        wlan_objmgr_vdev_release_ref(v13, 0x5Au, v74, v75, v76, v77, v78, v79, v80, v81, v82);
        return 0;
      }
      wlan_t2lm_clear_peer_negotiation(v23);
      qdf_mem_copy((void *)(a1 + 324), *(const void **)a2, 0x34u);
      if ( !(unsigned int)wlan_send_tid_to_link_mapping(v13, *(_QWORD *)a2, v92, v93, v94, v95, v96, v97, v98, v99) )
      {
        wlan_sm_transition_to(*(_QWORD *)(a1 + 720), 2u, v100, v101, v102, v103, v104, v105, v106, v107);
        wlan_mlo_send_ttlm_complete(v13, a1, 1, v116, v117, v118, v119, v120, v121, v122, v123);
        wlan_mlo_dev_t2lm_notify_link_update(v13, *(_QWORD *)a2, v124, v125, v126, v127, v128, v129, v130, v131);
        goto LABEL_9;
      }
      qdf_trace_msg(
        0x99u,
        2u,
        "%s: sending t2lm wmi failed",
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        v107,
        "ttlm_handle_rx_action_rsp_in_sta_in_progress_state");
      wlan_objmgr_peer_release_ref(v23, 0x5Au, v108, v109, v110, v111, v112, v113, v114, v115);
    }
    else
    {
      qdf_trace_msg(
        0x99u,
        2u,
        "%s: Peer is NULL",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "ttlm_handle_rx_action_rsp_in_sta_in_progress_state");
    }
    wlan_objmgr_vdev_release_ref(v13, 0x5Au, v83, v84, v85, v86, v87, v88, v89, v90, v91);
  }
  else
  {
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: VDEV is null",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "ttlm_handle_rx_action_rsp_in_sta_in_progress_state");
  }
  return 29;
}
