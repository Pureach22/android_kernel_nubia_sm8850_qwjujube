__int64 __fastcall wlan_mlo_t2lm_timer_expiry_handler(
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
  _WORD *v9; // x20
  __int64 first_active_vdev_by_ml_dev_ctx; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x4
  __int64 v29; // x5
  __int64 v30; // x6
  int v31; // w8
  int v32; // w9
  int v33; // w10
  int v34; // w11
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
  __int64 v51; // x8
  __int64 v52; // x4
  __int64 v53; // x5
  __int64 v54; // x6
  int v55; // w8
  int v56; // w9
  int v57; // w10
  int v58; // w11
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x20
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 bsspeer; // x0
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  __int64 v101; // x21
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  __int64 v118; // x1

  v9 = *(_WORD **)(a1 + 168);
  *(_BYTE *)(a1 + 96) = 0;
  *(_QWORD *)(a1 + 88) = 0;
  first_active_vdev_by_ml_dev_ctx = mlo_get_first_active_vdev_by_ml_dev_ctx(
                                      *((_QWORD *)v9 + 105),
                                      a2,
                                      a3,
                                      a4,
                                      a5,
                                      a6,
                                      a7,
                                      a8,
                                      a9);
  if ( first_active_vdev_by_ml_dev_ctx )
  {
    v19 = first_active_vdev_by_ml_dev_ctx;
    if ( *((_BYTE *)v9 + 10) == 1 )
    {
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: Expected duration expired for vdev_id:%d ",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "wlan_mlo_t2lm_handle_expected_duration_expiry",
        *(unsigned __int8 *)(first_active_vdev_by_ml_dev_ctx + 168));
      if ( *((_BYTE *)v9 + 65) == 1 )
      {
        qdf_trace_msg(
          0x99u,
          8u,
          "%s: Mapping switch time expired for vdev_id:%d ",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "wlan_mlo_t2lm_handle_mapping_switch_time_expiry",
          *(unsigned __int8 *)(v19 + 168));
        qdf_mem_copy(v9, v9 + 28, 0x38u);
        v28 = (unsigned __int16)*v9;
        v29 = *((unsigned int *)v9 + 1);
        v30 = *((unsigned __int8 *)v9 + 8);
        v31 = *((unsigned __int8 *)v9 + 10);
        v32 = *((_DWORD *)v9 + 4);
        v33 = (unsigned __int16)v9[10];
        v34 = (unsigned __int16)v9[18];
        *((_BYTE *)v9 + 9) = 0;
        v9[6] = 0;
        qdf_trace_msg(
          0x99u,
          8u,
          "%s: Established mapping: disabled_link_bitmap:%x dir:%d default_map:%d MSTP:%d EDP:%d MST:%d ED:%d ieee_link_m"
          "ap:%x hw_link_map:%x",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "wlan_mlo_t2lm_handle_mapping_switch_time_expiry",
          v28,
          v29,
          v30,
          0,
          v31,
          0,
          v32,
          v33,
          v34);
        qdf_mem_set(v9 + 28, 0x38u, 0);
        *((_DWORD *)v9 + 15) = 4;
      }
      else
      {
        qdf_mem_set(v9, 0x38u, 0);
        *((_DWORD *)v9 + 1) = 2;
        *((_BYTE *)v9 + 8) = 1;
        *v9 = 0;
        *((_BYTE *)v9 + 53) = 0;
        qdf_trace_msg(
          0x99u,
          8u,
          "%s: Set established mapping to default mapping",
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          "wlan_mlo_t2lm_handle_expected_duration_expiry");
        bsspeer = wlan_objmgr_vdev_try_get_bsspeer(v19, 0x5Au);
        if ( bsspeer )
        {
          v101 = bsspeer;
          v102 = wlan_t2lm_clear_peer_negotiation();
          wlan_objmgr_peer_release_ref(v101, 0x5Au, v102, v103, v104, v105, v106, v107, v108, v109);
        }
        else
        {
          qdf_trace_msg(
            0x99u,
            2u,
            "%s: Peer not found",
            v93,
            v94,
            v95,
            v96,
            v97,
            v98,
            v99,
            v100,
            "wlan_clear_peer_level_tid_to_link_mapping");
        }
      }
      wlan_mlo_dev_t2lm_notify_link_update(v19, (__int64)(v9 + 2), v43, v44, v45, v46, v47, v48, v49, v50);
      wlan_send_tid_to_link_mapping(v19, (__int64)(v9 + 2), v110, v111, v112, v113, v114, v115, v116, v117);
      v83 = *(_QWORD *)(v19 + 1360);
      if ( !v83 || !wlan_vdev_mlme_get_cmpt_obj(v19, v11, v12, v13, v14, v15, v16, v17, v18) )
        goto LABEL_23;
      if ( *(_BYTE *)(v83 + 2250) == 1 )
        goto LABEL_18;
      v51 = *(unsigned __int8 *)(v83 + 2305);
      if ( (v51 & 1) == 0 )
      {
LABEL_23:
        mlo_release_vdev_ref(v19, (unsigned int *)v51, v11, v12, v13, v14, v15, v16, v17, v18);
        return 0;
      }
    }
    else
    {
      v51 = *((unsigned __int8 *)v9 + 65);
      if ( (_DWORD)v51 != 1 )
        goto LABEL_23;
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: Mapping switch time expired for vdev_id:%d ",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "wlan_mlo_t2lm_handle_mapping_switch_time_expiry",
        *(unsigned __int8 *)(first_active_vdev_by_ml_dev_ctx + 168));
      qdf_mem_copy(v9, v9 + 28, 0x38u);
      v52 = (unsigned __int16)*v9;
      v53 = *((unsigned int *)v9 + 1);
      v54 = *((unsigned __int8 *)v9 + 8);
      v55 = *((unsigned __int8 *)v9 + 10);
      v56 = *((_DWORD *)v9 + 4);
      v57 = (unsigned __int16)v9[10];
      v58 = (unsigned __int16)v9[18];
      *((_BYTE *)v9 + 9) = 0;
      v9[6] = 0;
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: Established mapping: disabled_link_bitmap:%x dir:%d default_map:%d MSTP:%d EDP:%d MST:%d ED:%d ieee_link_map"
        ":%x hw_link_map:%x",
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        "wlan_mlo_t2lm_handle_mapping_switch_time_expiry",
        v52,
        v53,
        v54,
        0,
        v55,
        0,
        v56,
        v57,
        v58);
      qdf_mem_set(v9 + 28, 0x38u, 0);
      *((_DWORD *)v9 + 15) = 4;
      wlan_mlo_dev_t2lm_notify_link_update(v19, (__int64)(v9 + 2), v67, v68, v69, v70, v71, v72, v73, v74);
      wlan_send_tid_to_link_mapping(v19, (__int64)(v9 + 2), v75, v76, v77, v78, v79, v80, v81, v82);
      v83 = *(_QWORD *)(v19 + 1360);
      if ( !v83 || !wlan_vdev_mlme_get_cmpt_obj(v19, v11, v12, v13, v14, v15, v16, v17, v18) )
        goto LABEL_23;
      if ( *(_BYTE *)(v83 + 2250) == 1 )
      {
LABEL_18:
        v118 = *(unsigned int *)(v83 + 2256);
        v51 = 0xFFFFFF;
        if ( (_DWORD)v118 == 0xFFFFFF )
          goto LABEL_23;
        goto LABEL_22;
      }
      v51 = *(unsigned __int8 *)(v83 + 2305);
      if ( (_DWORD)v51 != 1 )
        goto LABEL_23;
    }
    v118 = *(unsigned __int16 *)(v83 + 2308);
LABEL_22:
    v11 = wlan_mlo_t2lm_timer_start(v19, v118);
    goto LABEL_23;
  }
  qdf_trace_msg(
    0x99u,
    2u,
    "%s: null vdev",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "wlan_mlo_t2lm_timer_expiry_handler");
  mlo_t2lm_reset_established_and_upcoming_mapping(*((_QWORD *)v9 + 105));
  return 0;
}
