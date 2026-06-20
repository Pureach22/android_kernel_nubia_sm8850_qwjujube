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
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x4
  __int64 v58; // x5
  __int64 v59; // x6
  __int64 v60; // x7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x4
  __int64 v70; // x5
  __int64 v71; // x6
  __int64 v72; // x7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  int v81; // w26
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  __int64 v98; // x4
  __int64 v99; // x5
  __int64 v100; // x6
  __int64 v101; // x7
  __int64 v102; // x4
  __int64 v103; // x5
  __int64 v104; // x6
  __int64 v105; // x7
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  __int64 v122; // x4
  __int64 v123; // x5
  __int64 v124; // x6
  __int64 v125; // x7
  __int64 v126; // [xsp+0h] [xbp-60h]
  __int64 v127; // [xsp+8h] [xbp-58h]
  int v128; // [xsp+40h] [xbp-20h] BYREF
  __int16 v129; // [xsp+44h] [xbp-1Ch]
  int v130; // [xsp+50h] [xbp-10h] BYREF
  __int16 v131; // [xsp+54h] [xbp-Ch]
  __int64 v132; // [xsp+58h] [xbp-8h]

  v132 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = (__int64 **)_cds_get_context(71, (__int64)"wma_add_peer", a8, a9, a10, a11, a12, a13, a14, a15);
  v31 = a1[3];
  v129 = 0;
  v128 = 0;
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
  objmgr_peer = wma_create_objmgr_peer((__int64)a1, a5, a2, a4);
  if ( !objmgr_peer )
  {
LABEL_17:
    result = 16;
    goto LABEL_18;
  }
  v34 = objmgr_peer;
  if ( a6 )
  {
    v131 = 0;
    v130 = 0;
    if ( !qdf_is_macaddr_equal_2((__int64)a6, (__int64)&v130) )
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
        a7 & 1,
        *a6,
        a6[1],
        a6[2],
        a6[5]);
    }
  }
  if ( (unsigned int)cdp_peer_create(context, a5, a2) )
  {
    if ( a2 )
    {
      v57 = *a2;
      v58 = a2[1];
      v59 = a2[2];
      v60 = a2[5];
    }
    else
    {
      v59 = 0;
      v57 = 0;
      v58 = 0;
      v60 = 0;
    }
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Unable to attach peer %02x:%02x:%02x:**:**:%02x",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "wma_add_peer",
      v57,
      v58,
      v59,
      v60);
    goto LABEL_29;
  }
  if ( wlan_cm_is_roam_sync_in_progress(a1[3], a5) )
  {
    if ( a2 )
    {
      v69 = *a2;
      v70 = a2[1];
      v71 = a2[2];
      v72 = a2[5];
    }
    else
    {
      v71 = 0;
      v69 = 0;
      v70 = 0;
      v72 = 0;
    }
    LODWORD(v126) = (unsigned __int8)a5;
    LODWORD(v127) = *(_DWORD *)(a1[65] + 488LL * (unsigned __int8)a5 + 244) + 1;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: LFR3: Created peer %02x:%02x:%02x:**:**:%02x vdev_id %d, peer_count %d",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "wma_add_peer",
      v69,
      v70,
      v71,
      v72,
      v126,
      v127);
    result = 0;
    goto LABEL_18;
  }
  qdf_mem_copy(&v128, a2, 6u);
  v81 = *(_DWORD *)(a1[3] + 20);
  if ( a4 == 2 )
  {
    cdp_peer_set_peer_as_tdls(context, a5, a2);
    if ( (v81 & 0x10000000) != 0 )
    {
      wma_acquire_wakelock(a1 + 391, 8000);
      if ( !wma_fill_hold_req(a1, a5, 0x11C5u, 0xFu, a2, a3, 0x1F40u) )
      {
        if ( a2 )
        {
          v122 = *a2;
          v123 = a2[1];
          v124 = a2[2];
          v125 = a2[5];
        }
        else
        {
          v124 = 0;
          v122 = 0;
          v123 = 0;
          v125 = 0;
        }
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: peer: %02x:%02x:%02x:**:**:%02x failed to fill peer create req",
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          "wma_add_peer",
          v122,
          v123,
          v124,
          v125);
        goto LABEL_42;
      }
    }
  }
  if ( (unsigned int)wmi_unified_peer_create_send(*a1) )
  {
    if ( a2 )
    {
      v98 = *a2;
      v99 = a2[1];
      v100 = a2[2];
      v101 = a2[5];
    }
    else
    {
      v100 = 0;
      v98 = 0;
      v99 = 0;
      v101 = 0;
    }
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: peer: %02x:%02x:%02x:**:**:%02x Unable to create peer",
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      "wma_add_peer",
      v98,
      v99,
      v100,
      v101);
    wma_remove_peer_req(a1, a5, 15, &v128);
    if ( a4 != 2 )
    {
LABEL_44:
      if ( (cdp_cfg_get_peer_unmap_conf_support((__int64)context, v106, v107, v108, v109, v110, v111, v112, v113) & 1) != 0 )
        cdp_peer_delete_sync(context, v114, v115, v116, v117, v118, v119, v120, v121);
      else
        cdp_peer_delete(context, v114, v115, v116, v117, v118, v119, v120, v121);
LABEL_29:
      wlan_objmgr_peer_obj_delete(v34, v73, v74, v75, v76, v77, v78, v79, v80);
      goto LABEL_17;
    }
LABEL_42:
    if ( (v81 & 0x10000000) != 0 )
      wma_release_wakelock(a1 + 391);
    goto LABEL_44;
  }
  if ( a2 )
  {
    v102 = *a2;
    v103 = a2[1];
    v104 = a2[2];
    v105 = a2[5];
  }
  else
  {
    v104 = 0;
    v102 = 0;
    v103 = 0;
    v105 = 0;
  }
  LODWORD(v126) = (unsigned __int8)a5;
  LODWORD(v127) = *(_DWORD *)(a1[65] + 488LL * (unsigned __int8)a5 + 244) + 1;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Created peer peer_addr %02x:%02x:%02x:**:**:%02x vdev_id %d, peer_count - %d",
    v90,
    v91,
    v92,
    v93,
    v94,
    v95,
    v96,
    v97,
    "wma_add_peer",
    v102,
    v103,
    v104,
    v105,
    v126,
    v127);
  wlan_roam_debug_log(a5, 0, 0xFFFFu, (__int64)a2, 0, 0, 0);
  result = 0;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
