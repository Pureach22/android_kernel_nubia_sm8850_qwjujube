__int64 __fastcall wma_add_peer(
        __int64 *a1,
        unsigned __int8 *a2,
        __int64 a3,
        int a4,
        unsigned int a5,
        unsigned __int8 *a6,
        char a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 **context; // x23
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  __int64 tgt_res_cfg; // x0
  __int64 objmgr_peer; // x0
  __int64 v34; // x22
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x4
  __int64 v44; // x5
  __int64 v45; // x6
  __int64 v46; // x7
  const char *v47; // x2
  __int64 result; // x0
  int v49; // w27
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x4
  __int64 v59; // x5
  __int64 v60; // x6
  __int64 v61; // x7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x4
  __int64 v71; // x5
  __int64 v72; // x6
  __int64 v73; // x7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  int v82; // w26
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  __int64 v99; // x4
  __int64 v100; // x5
  __int64 v101; // x6
  __int64 v102; // x7
  __int64 v103; // x4
  __int64 v104; // x5
  __int64 v105; // x6
  __int64 v106; // x7
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  __int64 v123; // x4
  __int64 v124; // x5
  __int64 v125; // x6
  __int64 v126; // x7
  __int64 v127; // [xsp+0h] [xbp-60h]
  __int64 v128; // [xsp+8h] [xbp-58h]
  __int64 v129; // [xsp+28h] [xbp-38h]
  _QWORD v130[2]; // [xsp+40h] [xbp-20h] BYREF
  int v131; // [xsp+50h] [xbp-10h] BYREF
  __int16 v132; // [xsp+54h] [xbp-Ch]
  __int64 v133; // [xsp+58h] [xbp-8h]

  v133 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = (__int64 **)_cds_get_context(71, (__int64)"wma_add_peer", a8, a9, a10, a11, a12, a13, a14, a15);
  v31 = a1[3];
  WORD2(v130[0]) = 0;
  LODWORD(v130[0]) = 0;
  if ( !v31 )
  {
    v47 = "%s: psoc is NULL";
LABEL_14:
    qdf_trace_msg(0x36u, 2u, v47, v23, v24, v25, v26, v27, v28, v29, v30, "wma_add_peer");
    result = 4;
    goto LABEL_18;
  }
  tgt_res_cfg = lmac_get_tgt_res_cfg(v31, v23, v24, v25, v26, v27, v28, v29, v30);
  if ( !tgt_res_cfg )
  {
    v47 = "%s: psoc target res cfg is null";
    goto LABEL_14;
  }
  if ( *(_DWORD *)(a1[65] + 488LL * (unsigned __int8)a5 + 244) >= *(_DWORD *)(tgt_res_cfg + 4) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: the peer count exceeds the limit %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wma_add_peer");
    goto LABEL_17;
  }
  if ( !context )
    goto LABEL_17;
  if ( (*a2 & 1) != 0 || !(*(_DWORD *)a2 | *((unsigned __int16 *)a2 + 2)) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid peer address received reject it",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wma_add_peer");
    goto LABEL_17;
  }
  objmgr_peer = wma_create_objmgr_peer((__int64)a1, a5, a2, a4, a6);
  if ( !objmgr_peer )
  {
LABEL_17:
    result = 16;
    goto LABEL_18;
  }
  v34 = objmgr_peer;
  if ( a6 )
  {
    v132 = 0;
    v131 = 0;
    if ( !qdf_is_macaddr_equal_2((__int64)a6, (__int64)&v131) )
    {
      *(_DWORD *)(v34 + 64) |= 1u;
      if ( a2 )
      {
        v43 = *a2;
        v44 = a2[1];
        v45 = a2[2];
        v46 = a2[5];
      }
      else
      {
        v45 = 0;
        v43 = 0;
        v44 = 0;
        v46 = 0;
      }
      v49 = a7 & 1;
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: peer %02x:%02x:%02x:**:**:%02xis_assoc_peer%d mld mac %02x:%02x:%02x:**:**:%02x",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "wma_add_peer",
        v43,
        v44,
        v45,
        v46,
        v49,
        *a6,
        a6[1],
        a6[2],
        a6[5],
        v129,
        0,
        0,
        v130[0]);
      qdf_mem_copy((void *)(v34 + 792), a6, 6u);
      *(_BYTE *)(v34 + 88) = v49;
    }
  }
  if ( (unsigned int)cdp_peer_create(context, a5, a2) )
  {
    if ( a2 )
    {
      v58 = *a2;
      v59 = a2[1];
      v60 = a2[2];
      v61 = a2[5];
    }
    else
    {
      v60 = 0;
      v58 = 0;
      v59 = 0;
      v61 = 0;
    }
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Unable to attach peer %02x:%02x:%02x:**:**:%02x",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "wma_add_peer",
      v58,
      v59,
      v60,
      v61);
    goto LABEL_30;
  }
  if ( wlan_cm_is_roam_sync_in_progress(a1[3], a5) || (unsigned int)mlme_get_roam_state(a1[3], a5) == 6 )
  {
    if ( a2 )
    {
      v70 = *a2;
      v71 = a2[1];
      v72 = a2[2];
      v73 = a2[5];
    }
    else
    {
      v72 = 0;
      v70 = 0;
      v71 = 0;
      v73 = 0;
    }
    LODWORD(v127) = (unsigned __int8)a5;
    LODWORD(v128) = *(_DWORD *)(a1[65] + 488LL * (unsigned __int8)a5 + 244) + 1;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: LFR3: Created peer %02x:%02x:%02x:**:**:%02x vdev_id %d, peer_count %d",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "wma_add_peer",
      v70,
      v71,
      v72,
      v73,
      v127,
      v128);
    result = 0;
    goto LABEL_18;
  }
  qdf_mem_copy(v130, a2, 6u);
  v82 = *(_DWORD *)(a1[3] + 20);
  if ( a4 == 2 )
  {
    cdp_peer_set_peer_as_tdls(context, a5, a2);
    if ( (v82 & 0x10000000) != 0 )
    {
      wma_acquire_wakelock(a1 + 391, 8000);
      if ( !wma_fill_hold_req(a1, a5, 0x11C5u, 0xFu, a2, a3, 0x1F40u) )
      {
        if ( a2 )
        {
          v123 = *a2;
          v124 = a2[1];
          v125 = a2[2];
          v126 = a2[5];
        }
        else
        {
          v125 = 0;
          v123 = 0;
          v124 = 0;
          v126 = 0;
        }
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: peer: %02x:%02x:%02x:**:**:%02x failed to fill peer create req",
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          v90,
          "wma_add_peer",
          v123,
          v124,
          v125,
          v126);
        goto LABEL_43;
      }
    }
  }
  if ( (unsigned int)wmi_unified_peer_create_send(*a1) )
  {
    if ( a2 )
    {
      v99 = *a2;
      v100 = a2[1];
      v101 = a2[2];
      v102 = a2[5];
    }
    else
    {
      v101 = 0;
      v99 = 0;
      v100 = 0;
      v102 = 0;
    }
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: peer: %02x:%02x:%02x:**:**:%02x Unable to create peer",
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      "wma_add_peer",
      v99,
      v100,
      v101,
      v102);
    wma_remove_peer_req(a1, a5, 15, v130);
    if ( a4 != 2 )
    {
LABEL_45:
      if ( (cdp_cfg_get_peer_unmap_conf_support((__int64)context, v107, v108, v109, v110, v111, v112, v113, v114) & 1) != 0 )
        cdp_peer_delete_sync(context, v115, v116, v117, v118, v119, v120, v121, v122);
      else
        cdp_peer_delete(context, v115, v116, v117, v118, v119, v120, v121, v122);
LABEL_30:
      wlan_objmgr_peer_obj_delete(v34, v74, v75, v76, v77, v78, v79, v80, v81);
      goto LABEL_17;
    }
LABEL_43:
    if ( (v82 & 0x10000000) != 0 )
      wma_release_wakelock(a1 + 391);
    goto LABEL_45;
  }
  if ( a2 )
  {
    v103 = *a2;
    v104 = a2[1];
    v105 = a2[2];
    v106 = a2[5];
  }
  else
  {
    v105 = 0;
    v103 = 0;
    v104 = 0;
    v106 = 0;
  }
  LODWORD(v127) = (unsigned __int8)a5;
  LODWORD(v128) = *(_DWORD *)(a1[65] + 488LL * (unsigned __int8)a5 + 244) + 1;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Created peer peer_addr %02x:%02x:%02x:**:**:%02x vdev_id %d, peer_count - %d",
    v91,
    v92,
    v93,
    v94,
    v95,
    v96,
    v97,
    v98,
    "wma_add_peer",
    v103,
    v104,
    v105,
    v106,
    v127,
    v128);
  wlan_roam_debug_log(a5, 0, 0xFFFFu, (__int64)a2, 0, 0, 0);
  result = 0;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
