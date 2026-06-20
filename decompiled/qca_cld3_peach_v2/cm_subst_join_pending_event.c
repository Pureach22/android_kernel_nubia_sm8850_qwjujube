__int64 __fastcall cm_subst_join_pending_event(
        __int64 a1,
        unsigned __int16 a2,
        unsigned int a3,
        unsigned int *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v12; // w19
  __int64 result; // x0
  int v15; // w9
  __int64 *v16; // x21
  unsigned int v18; // w20
  __int64 v19; // x21
  unsigned int *v20; // x19
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 req_by_cm_id_fl; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w19
  __int64 v39; // x21
  unsigned int *v40; // x20
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x0
  unsigned int v58; // w1
  __int64 v59; // x21
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x21
  __int64 v69; // x21
  unsigned int v70; // w2
  __int64 v71; // x3

  v12 = a2;
  result = 0;
  v15 = 0;
  switch ( a2 )
  {
    case 0u:
      v38 = a3;
      v68 = a1;
      v40 = a4;
      if ( (unsigned int)cm_handle_connect_req_in_non_init_state((_BYTE *)a1, a4, 7) )
        return 0;
      v57 = *(_QWORD *)(v68 + 72);
      v58 = 6;
      goto LABEL_24;
    case 1u:
      v69 = a1;
      v20 = a4;
      v18 = a3;
      wlan_sm_transition_to(*(_QWORD *)(a1 + 72), 8u, a5, a6, a7, a8, a9, a10, a11, a12);
      v57 = *(_QWORD *)(v69 + 72);
      v58 = 1;
      goto LABEL_22;
    case 2u:
      goto LABEL_18;
    case 3u:
      v15 = 16;
LABEL_18:
      cm_connect_scan_resp((__int64 *)a1, a4, v15);
      return 1;
    case 4u:
    case 5u:
    case 0x26u:
      v16 = (__int64 *)a1;
      if ( (cm_check_cmid_match_list_head(a1, a4) & 1) == 0 )
        return 0;
      cm_ser_connect_after_mode_change_resp(v16, a4, v12);
      return 1;
    case 6u:
      cm_connect_start((__int64 *)a1, a4, a5, a6, a7, a8, a9, a10, a11, a12);
      return 1;
    case 7u:
      v38 = a3;
      v59 = a1;
      v40 = a4;
      if ( (cm_check_cmid_match_list_head(a1, a4) & 1) == 0 )
        return 0;
      wlan_sm_transition_to(*(_QWORD *)(v59 + 72), 9u, v60, v61, v62, v63, v64, v65, v66, v67);
      v57 = *(_QWORD *)(v59 + 72);
      v58 = 7;
      goto LABEL_24;
    case 0xCu:
      v18 = a3;
      v19 = a1;
      v20 = a4;
      if ( (cm_connect_resp_cmid_match_list_head(a1, (__int64)a4) & 1) == 0 )
        return 0;
      if ( *(_BYTE *)(v19 + 184) )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: vdev %d cm_id 0x%x: disconnect_count %d",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "cm_subst_join_pending_event",
          *(unsigned __int8 *)(*(_QWORD *)v19 + 168LL),
          v20[1]);
        req_by_cm_id_fl = cm_get_req_by_cm_id_fl(v19, v20[1], "cm_subst_join_pending_event", 664);
        if ( req_by_cm_id_fl )
          *(_BYTE *)(req_by_cm_id_fl + 20) = 1;
        wlan_sm_transition_to(*(_QWORD *)(v19 + 72), 3u, v30, v31, v32, v33, v34, v35, v36, v37);
        return 1;
      }
      wlan_sm_transition_to(*(_QWORD *)(v19 + 72), 0, v21, v22, v23, v24, v25, v26, v27, v28);
      v57 = *(_QWORD *)(v19 + 72);
      v58 = 12;
LABEL_22:
      v70 = v18;
      v71 = (__int64)v20;
      goto LABEL_25;
    case 0xDu:
      v38 = a3;
      v39 = a1;
      v40 = a4;
      if ( (unsigned int)cm_handle_discon_req_in_non_connected_state((__int64 *)a1, a4, 7) )
        return 0;
      wlan_sm_transition_to(*(_QWORD *)(v39 + 72), 3u, v41, v42, v43, v44, v45, v46, v47, v48);
      v57 = *(_QWORD *)(v39 + 72);
      v58 = 14;
LABEL_24:
      v70 = v38;
      v71 = (__int64)v40;
LABEL_25:
      wlan_sm_dispatch(v57, v58, v70, v71, v49, v50, v51, v52, v53, v54, v55, v56);
      return 1;
    case 0xFu:
      cm_disconnect_active((_DWORD *)a1, a4);
      return 1;
    case 0x10u:
      cm_disconnect_complete((_QWORD *)a1, a4);
      return 1;
    case 0x25u:
      cm_disconnect_continue_after_rso_stop(*(_QWORD *)a1, a4);
      return 1;
    default:
      return result;
  }
}
