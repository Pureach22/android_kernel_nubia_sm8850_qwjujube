__int64 __fastcall wlan_mlo_vdev_tid_to_link_map_event(__int64 a1, unsigned __int8 *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 cmpt_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x23
  __int64 v24; // x21
  __int64 v25; // x4
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int *v36; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  int v53; // w8
  int v54; // w8
  __int64 v55; // x4
  __int64 v56; // x5
  __int64 v57; // x6
  int v58; // w8
  int v59; // w9
  int v60; // w10
  int v61; // w11
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 bsspeer; // x0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x20
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  unsigned int *v96; // x8
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7

  v4 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 90);
  if ( !v4 )
  {
    qdf_trace_msg(0x99u, 2u, "%s: null vdev", v5, v6, v7, v8, v9, v10, v11, v12, "wlan_mlo_vdev_tid_to_link_map_event");
    return 29;
  }
  v13 = v4;
  if ( !*(_QWORD *)(v4 + 1360) )
  {
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: null mlo_dev_ctx",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_mlo_vdev_tid_to_link_map_event");
    mlo_release_vdev_ref(v13, v27, v28, v29, v30, v31, v32, v33, v34, v35);
    return 29;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v4, v5, v6, v7, v8, v9, v10, v11, v12);
  if ( !cmpt_obj )
  {
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: null vdev_mlme",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wlan_mlo_vdev_tid_to_link_map_event");
    mlo_release_vdev_ref(v13, v36, v37, v38, v39, v40, v41, v42, v43, v44);
    return 16;
  }
  v23 = *(_QWORD *)(v13 + 1360);
  v24 = cmpt_obj;
  if ( a1 )
    v25 = *(unsigned __int8 *)(a1 + 48);
  else
    v25 = 255;
  qdf_trace_msg(
    0x99u,
    8u,
    "%s: psoc_id:%d vdev_id:%d status:%d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "wlan_mlo_vdev_tid_to_link_map_event",
    v25,
    *a2,
    *((unsigned int *)a2 + 1));
  qdf_mutex_acquire(v23 + 2528);
  v53 = *((_DWORD *)a2 + 1);
  if ( v53 == 2 )
  {
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: Expected duration expired for vdev_id:%d ",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "wlan_mlo_t2lm_handle_expected_duration_expiry",
      *(unsigned __int8 *)(v13 + 168));
    if ( *(_BYTE *)(v23 + 2305) != 1 )
    {
      qdf_mem_set((void *)(v23 + 2240), 0x38u, 0);
      *(_DWORD *)(v23 + 2244) = 2;
      *(_BYTE *)(v23 + 2248) = 1;
      *(_WORD *)(v23 + 2240) = 0;
      *(_BYTE *)(v23 + 2293) = 0;
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: Set established mapping to default mapping",
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        "wlan_mlo_t2lm_handle_expected_duration_expiry");
      bsspeer = wlan_objmgr_vdev_try_get_bsspeer(v13, 0x5Au);
      if ( bsspeer )
      {
        v87 = bsspeer;
        v88 = wlan_t2lm_clear_peer_negotiation();
        wlan_objmgr_peer_release_ref(v87, 0x5Au, v88, v89, v90, v91, v92, v93, v94, v95);
      }
      else
      {
        qdf_trace_msg(
          0x99u,
          2u,
          "%s: Peer not found",
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          "wlan_clear_peer_level_tid_to_link_mapping");
      }
      goto LABEL_18;
    }
  }
  else
  {
    if ( v53 != 1 )
    {
      if ( v53 )
      {
        qdf_trace_msg(
          0x99u,
          2u,
          "%s: Invalid status",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "wlan_mlo_vdev_tid_to_link_map_event");
      }
      else
      {
        if ( (*(_BYTE *)(v23 + 2305) & 1) != 0 )
        {
          v54 = *((_DWORD *)a2 + 2) >> 10;
          *(_WORD *)(v24 + 40) = v54;
        }
        else
        {
          LOWORD(v54) = *(_WORD *)(v24 + 40);
        }
        qdf_trace_msg(
          0x99u,
          8u,
          "%s: vdev_id:%d updated mapping switch time:%d",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "wlan_mlo_vdev_tid_to_link_map_event",
          *a2,
          (unsigned __int16)v54);
      }
      goto LABEL_24;
    }
    *(_WORD *)(v24 + 40) = 0;
  }
  qdf_trace_msg(
    0x99u,
    8u,
    "%s: Mapping switch time expired for vdev_id:%d ",
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    "wlan_mlo_t2lm_handle_mapping_switch_time_expiry",
    *(unsigned __int8 *)(v13 + 168));
  qdf_mem_copy((void *)(v23 + 2240), (const void *)(v23 + 2296), 0x38u);
  v55 = *(unsigned __int16 *)(v23 + 2240);
  v56 = *(unsigned int *)(v23 + 2244);
  v57 = *(unsigned __int8 *)(v23 + 2248);
  v58 = *(unsigned __int8 *)(v23 + 2250);
  v59 = *(_DWORD *)(v23 + 2256);
  v60 = *(unsigned __int16 *)(v23 + 2260);
  v61 = *(unsigned __int16 *)(v23 + 2276);
  *(_BYTE *)(v23 + 2249) = 0;
  *(_WORD *)(v23 + 2252) = 0;
  qdf_trace_msg(
    0x99u,
    8u,
    "%s: Established mapping: disabled_link_bitmap:%x dir:%d default_map:%d MSTP:%d EDP:%d MST:%d ED:%d ieee_link_map:%x hw_link_map:%x",
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    "wlan_mlo_t2lm_handle_mapping_switch_time_expiry",
    v55,
    v56,
    v57,
    0,
    v58,
    0,
    v59,
    v60,
    v61);
  qdf_mem_set((void *)(v23 + 2296), 0x38u, 0);
  *(_DWORD *)(v23 + 2300) = 4;
LABEL_18:
  wlan_mlo_dev_t2lm_notify_link_update(v13, v23 + 2244);
LABEL_24:
  qdf_mutex_release(v23 + 2528);
  mlo_release_vdev_ref(v13, v96, v97, v98, v99, v100, v101, v102, v103, v104);
  return 0;
}
