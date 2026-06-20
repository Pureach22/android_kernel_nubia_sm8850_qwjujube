__int64 __fastcall wlan_process_bcn_prbrsp_t2lm_ie(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x23
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 bsspeer; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x22
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  const char *v58; // x2
  unsigned int v59; // w21
  unsigned int v60; // w8
  bool v61; // cc
  __int16 v62; // w8
  __int16 v63; // w9
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x20
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  int v81; // w1
  unsigned int v82; // w19

  if ( !wlan_cm_is_vdev_connected(a1, a4, a5, a6, a7, a8, a9, a10, a11) )
    return 0;
  if ( !a1 )
    return 29;
  v14 = *(_QWORD *)(a1 + 1360);
  if ( !v14 )
    return 29;
  qdf_mutex_acquire(v14 + 2528);
  if ( (*(_BYTE *)(v14 + 2250) & 1) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 10) & 1) == 0 )
      goto LABEL_19;
    if ( *(_DWORD *)(a2 + 16) < *(_DWORD *)(v14 + 2256) )
    {
      if ( !(unsigned int)qdf_mem_cmp((const void *)(v14 + 2260), (const void *)(a2 + 20), 0x10u) )
        *(_DWORD *)(v14 + 2256) = *(_DWORD *)(a2 + 16);
      goto LABEL_19;
    }
  }
  else if ( (*(_BYTE *)(a2 + 10) & 1) == 0 )
  {
    goto LABEL_19;
  }
  if ( (*(_BYTE *)(a2 + 9) & 1) == 0 )
  {
    if ( !(unsigned int)qdf_mem_cmp((const void *)(v14 + 2260), (const void *)(a2 + 20), 0x10u) )
    {
      v58 = "%s: T2LM mapping is already configured";
      goto LABEL_33;
    }
    qdf_mem_copy((void *)(v14 + 2244), (const void *)(a2 + 4), 0x34u);
    wlan_mlo_dev_t2lm_notify_link_update(a1, v14 + 2244, v24, v25, v26, v27, v28, v29, v30, v31);
    bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x5Au);
    if ( bsspeer )
    {
      v41 = bsspeer;
      v42 = wlan_t2lm_clear_peer_negotiation();
      wlan_objmgr_peer_release_ref(v41, 0x5Au, v42, v43, v44, v45, v46, v47, v48, v49);
    }
    else
    {
      qdf_trace_msg(
        0x99u,
        2u,
        "%s: Peer not found",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "wlan_clear_peer_level_tid_to_link_mapping");
    }
    wlan_send_tid_to_link_mapping(a1, v14 + 2244, v50, v51, v52, v53, v54, v55, v56, v57);
  }
LABEL_19:
  if ( *(_BYTE *)(a2 + 65) != 1 )
    goto LABEL_25;
  if ( (unsigned int)qdf_mem_cmp((const void *)(v14 + 2260), (const void *)(a2 + 76), 0x10u) )
  {
    v59 = a3 >> 10;
    qdf_mem_copy((void *)(v14 + 2300), (const void *)(a2 + 60), 0x34u);
    v60 = *(unsigned __int16 *)(v14 + 2308);
    v61 = v60 > (unsigned __int16)v59;
    v62 = v60 - v59;
    if ( v61 )
      v63 = -294;
    else
      v63 = -295;
    *(_WORD *)(v14 + 2308) = v62 + v63;
LABEL_25:
    qdf_mutex_release(v14 + 2528);
    qdf_mutex_acquire(v14 + 2528);
    if ( (*(_BYTE *)(v14 + 2250) & 1) == 0 && *(_BYTE *)(v14 + 2305) != 1 )
      goto LABEL_37;
    v72 = *(_QWORD *)(a1 + 1360);
    if ( !v72 || !wlan_vdev_mlme_get_cmpt_obj(a1, v64, v65, v66, v67, v68, v69, v70, v71) )
      goto LABEL_37;
    if ( *(_BYTE *)(v72 + 2250) == 1 )
    {
      v81 = *(_DWORD *)(v72 + 2256);
      if ( v81 == 0xFFFFFF )
        goto LABEL_37;
    }
    else
    {
      if ( *(_BYTE *)(v72 + 2305) != 1 )
      {
LABEL_37:
        v82 = 0;
        goto LABEL_38;
      }
      v81 = *(unsigned __int16 *)(v72 + 2308);
    }
    wlan_mlo_t2lm_timer_start(a1, v81, v73, v74, v75, v76, v77, v78, v79, v80);
    goto LABEL_37;
  }
  v58 = "%s: Ongoing mapping is already established";
LABEL_33:
  qdf_trace_msg(0x99u, 8u, v58, v16, v17, v18, v19, v20, v21, v22, v23, "wlan_update_mapping_switch_time_expected_dur");
  v82 = 6;
LABEL_38:
  qdf_mutex_release(v14 + 2528);
  return v82;
}
