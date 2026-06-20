__int64 __fastcall ucfg_disable_nan_discovery(__int64 a1, const void *a2, unsigned int a3)
{
  int v6; // w0
  int v7; // w19
  unsigned int v8; // w23
  void *v9; // x0
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  char v44; // w25
  __int64 v45; // x20
  __int64 comp_private_obj; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x21
  unsigned int *v56; // x8
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w24
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  const char *v74; // x2
  unsigned int v75; // w1
  unsigned int *v76; // x8
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v86; // x0
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  __int64 v95; // x23
  __int64 v96; // x0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  __int64 v105; // x0
  unsigned int *v106; // x8
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  unsigned int v115; // w0
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
  __int64 v132; // [xsp+8h] [xbp-38h] BYREF
  __int64 v133; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v134)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v135)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-20h]
  __int64 v136; // [xsp+28h] [xbp-18h]
  __int64 v137; // [xsp+30h] [xbp-10h]
  __int64 v138; // [xsp+38h] [xbp-8h]

  v138 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = policy_mgr_mode_specific_connection_count(a1, 4, nullptr);
  if ( v6 )
  {
    v7 = v6;
    do
    {
      v8 = policy_mgr_mode_specific_vdev_id(a1, 4);
      if ( (unsigned int)ucfg_nan_disable_ndi(a1, v8) == 15 )
        policy_mgr_decr_session_set_pcl(a1, 0xBu, v8);
      --v7;
    }
    while ( v7 );
  }
  v9 = (void *)_qdf_mem_malloc(a3 + 24LL, "ucfg_disable_nan_discovery", 1415);
  if ( v9 )
  {
    v10 = (__int64)v9;
    qdf_mem_set(v9, a3 + 24, 0);
    *(_QWORD *)v10 = a1;
    *(_WORD *)(v10 + 8) = 257;
    if ( a2 && a3 )
    {
      *(_WORD *)(v10 + 12) = a3;
      qdf_mem_copy((void *)(v10 + 21), a2, a3);
    }
    if ( (cds_get_driver_state(v11, v12, v13, v14, v15, v16, v17, v18) & 8) != 0 )
    {
      nan_cleanup_pasn_peers(a1);
    }
    else
    {
      v136 = 0;
      v137 = 0;
      v134 = nullptr;
      v135 = nullptr;
      v132 = 0;
      v133 = 0;
      if ( (nan_is_pairing_allowed(a1, v19, v20, v21, v22, v23, v24, v25, v26) & 1) != 0 )
      {
        v35 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(a1, 16, 20);
        if ( v35 )
        {
          v44 = *(_BYTE *)(v35 + 104);
          v45 = v35;
          comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v35, 0xFu);
          if ( comp_private_obj )
          {
            v55 = comp_private_obj;
            if ( !*(_BYTE *)(comp_private_obj + 105) || (*(_BYTE *)(comp_private_obj + 106) & 1) != 0 )
            {
              qdf_trace_msg(
                0x53u,
                8u,
                "%s: num pasn peer %d peer_deletion %d",
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                "ucfg_nan_pasn_peer_delete_all");
              v65 = 0;
              goto LABEL_17;
            }
            *(_BYTE *)(comp_private_obj + 106) = 1;
            v86 = osif_request_alloc(ucfg_nan_pasn_peer_delete_all_params);
            if ( !v86 )
            {
              v65 = 2;
              qdf_trace_msg(
                0x53u,
                2u,
                "%s: Request allocation failure",
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                v93,
                v94,
                "ucfg_nan_pasn_peer_delete_all");
LABEL_17:
              *(_BYTE *)(v55 + 106) = 0;
              wlan_objmgr_vdev_release_ref(v45, 0x14u, v56, v57, v58, v59, v60, v61, v62, v63, v64);
              if ( !v65 )
                goto LABEL_22;
LABEL_28:
              v74 = "%s: Unable to delete all NAN Peer : %u";
              v75 = 2;
              goto LABEL_29;
            }
            v95 = v86;
            if ( a1 )
            {
              v96 = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
              if ( v96 )
              {
                *(_QWORD *)(v96 + 320) = osif_request_cookie(v95);
                v105 = _qdf_mem_malloc(0x10u, "ucfg_nan_pasn_peer_delete_all", 1366);
                v65 = 2;
                if ( v105 )
                {
                  *(_BYTE *)(v105 + 14) = v44;
                  *(_QWORD *)v105 = a1;
                  v133 = v105;
                  v134 = nan_pasn_scheduled_handler;
                  LOWORD(v132) = 2;
                  v135 = nan_pasn_flush_callback;
                  v115 = scheduler_post_message_debug(
                           0x53u,
                           0x53u,
                           72,
                           (unsigned __int16 *)&v132,
                           0x566u,
                           (__int64)"ucfg_nan_pasn_peer_delete_all");
                  if ( v115 )
                  {
                    v65 = v115;
                    qdf_trace_msg(
                      0x53u,
                      2u,
                      "%s: failed to post msg to NAN component, status: %d",
                      v116,
                      v117,
                      v118,
                      v119,
                      v120,
                      v121,
                      v122,
                      v123,
                      "ucfg_nan_pasn_peer_delete_all",
                      v115);
                    nan_pasn_flush_callback((unsigned __int16 *)&v132, v124, v125, v126, v127, v128, v129, v130, v131);
                  }
                  else if ( (unsigned int)osif_request_wait_for_response(v95) )
                  {
                    qdf_trace_msg(
                      0x53u,
                      2u,
                      "%s: NAN Delete all peer timed out waiting for confirmation",
                      v107,
                      v108,
                      v109,
                      v110,
                      v111,
                      v112,
                      v113,
                      v114,
                      "ucfg_nan_pasn_peer_delete_all");
                    v65 = 15;
                  }
                  else
                  {
                    v65 = 0;
                  }
                }
LABEL_41:
                *(_BYTE *)(v55 + 106) = 0;
                wlan_objmgr_vdev_release_ref(v45, 0x14u, v106, v107, v108, v109, v110, v111, v112, v113, v114);
                osif_request_put(v95);
                if ( !v65 )
                  goto LABEL_22;
                goto LABEL_28;
              }
            }
            else
            {
              qdf_trace_msg(
                0x53u,
                2u,
                "%s: psoc is null",
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                v93,
                v94,
                "nan_get_psoc_priv_obj");
            }
            qdf_trace_msg(
              0x53u,
              2u,
              "%s: psoc_nan_obj is null",
              v97,
              v98,
              v99,
              v100,
              v101,
              v102,
              v103,
              v104,
              "ucfg_nan_pasn_peer_delete_all");
            v65 = 4;
            goto LABEL_41;
          }
          qdf_trace_msg(
            0x53u,
            2u,
            "%s: NAN vdev priv obj is null",
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            "ucfg_nan_pasn_peer_delete_all");
          wlan_objmgr_vdev_release_ref(v45, 0x14u, v76, v77, v78, v79, v80, v81, v82, v83, v84);
        }
        else
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: Vdev is not found",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "ucfg_nan_pasn_peer_delete_all");
        }
        v65 = 29;
        goto LABEL_28;
      }
      qdf_trace_msg(
        0x53u,
        8u,
        "%s: NAN pairing is not allowed",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "ucfg_nan_pasn_peer_delete_all");
    }
LABEL_22:
    v65 = ucfg_nan_discovery_req((__int64 *)v10, 2u, v66, v67, v68, v69, v70, v71, v72, v73);
    if ( !v65 )
    {
      qdf_trace_msg(
        0x53u,
        8u,
        "%s: Successfully sent NAN Disable request",
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        "ucfg_disable_nan_discovery");
LABEL_30:
      _qdf_mem_free(v10);
      goto LABEL_31;
    }
    v74 = "%s: Unable to send NAN Disable request: %u";
    v75 = 8;
LABEL_29:
    qdf_trace_msg(0x53u, v75, v74, v66, v67, v68, v69, v70, v71, v72, v73, "ucfg_disable_nan_discovery", v65);
    goto LABEL_30;
  }
  v65 = -12;
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return v65;
}
