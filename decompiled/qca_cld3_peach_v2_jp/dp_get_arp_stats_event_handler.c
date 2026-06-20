__int64 __fastcall dp_get_arp_stats_event_handler(__int64 a1, unsigned int *a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 comp_private_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x22
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
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
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  int v87; // w9
  unsigned int *v88; // x8
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  unsigned int *v98; // x8
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7

  v3 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 97);
  if ( !v3 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Can't get vdev by vdev_id:%d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "dp_get_arp_stats_event_handler",
      *a2);
    return 4;
  }
  v12 = v3;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v3, 0x2Eu);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Unable to get DP link for vdev_id %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "dp_get_arp_stats_event_handler",
      *a2);
    wlan_objmgr_vdev_release_ref(v12, 0x61u, v98, v99, v100, v101, v102, v103, v104, v105, v106);
    return 4;
  }
  v22 = *(_QWORD *)(comp_private_obj + 32);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: rsp->arp_req_enqueue :%x",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "dp_get_arp_stats_event_handler",
    a2[1]);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: rsp->arp_req_tx_success :%x",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "dp_get_arp_stats_event_handler",
    a2[2]);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: rsp->arp_req_tx_failure :%x",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "dp_get_arp_stats_event_handler",
    a2[3]);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: rsp->arp_rsp_recvd :%x",
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    "dp_get_arp_stats_event_handler",
    a2[4]);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: rsp->out_of_order_arp_rsp_drop_cnt :%x",
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    "dp_get_arp_stats_event_handler",
    a2[5]);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: rsp->dad_detected :%x",
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    "dp_get_arp_stats_event_handler",
    a2[6]);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: rsp->connect_status :%x",
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    "dp_get_arp_stats_event_handler",
    a2[7]);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: rsp->ba_session_establishment_status :%x",
    v71,
    v72,
    v73,
    v74,
    v75,
    v76,
    v77,
    v78,
    "dp_get_arp_stats_event_handler",
    a2[8]);
  v87 = *(unsigned __int8 *)(v22 + 3073);
  *(_WORD *)(v22 + 2736) = a2[4];
  *(_BYTE *)(v22 + 3073) = (a2[6] | v87) != 0;
  *(_BYTE *)(v22 + 3072) = a2[7] != 0;
  v88 = (unsigned int *)*((unsigned __int8 *)a2 + 36);
  if ( (_DWORD)v88 == 1 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: rsp->tcp_ack_recvd :%x",
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      "dp_get_arp_stats_event_handler",
      a2[10]);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: rsp->icmpv4_rsp_recvd :%x",
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      "dp_get_arp_stats_event_handler",
      a2[11]);
    *(_WORD *)(v22 + 2776) = a2[10];
    v88 = (unsigned int *)a2[11];
    *(_WORD *)(v22 + 2798) = (_WORD)v88;
  }
  wlan_objmgr_vdev_release_ref(v12, 0x61u, v88, v79, v80, v81, v82, v83, v84, v85, v86);
  return 0;
}
