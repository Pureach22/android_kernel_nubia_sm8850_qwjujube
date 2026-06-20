__int64 __fastcall nan_discovery_event_handler(
        unsigned __int16 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x19
  __int64 comp_private_obj; // x0
  int v12; // w21
  __int64 v13; // x20
  const char *v14; // x2
  __int64 result; // x0
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x21
  __int64 pdev_by_id; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x23
  _QWORD *first_vdev; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x24
  unsigned int *v56; // x8
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x0
  int v66; // w8
  __int16 v67; // w9
  const char *v68; // x3
  void (__fastcall *v69)(_QWORD); // x8
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned int *v78; // x8
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  unsigned int *v87; // x8
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
  __int64 v105; // x0
  void (__fastcall *v106)(_QWORD); // x8
  void (__fastcall *v107)(_QWORD); // x8
  __int64 v108; // x0
  unsigned int v109; // w25
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  unsigned int *v126; // x8
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  _BYTE v135[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v136; // [xsp+8h] [xbp-8h]

  v136 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && (v9 = *((__int64 **)a1 + 1)) != nullptr )
  {
    if ( *v9 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*v9, 0xFu);
      if ( comp_private_obj )
      {
        v12 = *a1;
        v13 = comp_private_obj;
        if ( v12 > 2 )
        {
          if ( v12 == 3 )
            goto LABEL_40;
          if ( v12 != 4 )
          {
            if ( v12 != 5 )
            {
              qdf_trace_msg(
                0x53u,
                2u,
                "%s: Unknown event ID type - %d",
                a2,
                a3,
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                "nan_discovery_event_handler",
                (unsigned int)v12);
              goto LABEL_40;
            }
            goto LABEL_18;
          }
          if ( *v9 )
          {
            v65 = wlan_objmgr_psoc_get_comp_private_obj(*v9, 0xFu);
            if ( v65 )
            {
              v66 = *((_DWORD *)v9 + 5);
              v67 = *((_WORD *)v9 + 12);
              *(_DWORD *)(v65 + 328) = v66;
              *(_WORD *)(v65 + 332) = v67;
              qdf_trace_msg(
                0x53u,
                8u,
                "%s: nan addr %02x:%02x:%02x:**:**:%02x",
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                "nan_handle_de_ind",
                (unsigned __int8)v66,
                BYTE1(v66),
                BYTE2(v66),
                HIBYTE(v67));
              goto LABEL_40;
            }
          }
          else
          {
            qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "nan_get_psoc_priv_obj");
          }
          v68 = "nan_handle_de_ind";
        }
        else
        {
          if ( !v12 )
            goto LABEL_40;
          if ( v12 != 1 )
          {
LABEL_18:
            v16 = *v9;
            v135[0] = 0;
            if ( (unsigned int)nan_get_disable_req_info(v16, v135) )
            {
              qdf_trace_msg(
                0x53u,
                2u,
                "%s: Unable to get nan disable req info",
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                "nan_handle_disable_ind");
              result = 16;
              goto LABEL_12;
            }
            if ( (unsigned __int8)v12 == 2 && v135[0] == 1 || (unsigned __int8)v12 == 5 && v135[0] == 2 )
            {
              qdf_trace_msg(
                0x53u,
                8u,
                "%s: drop evt_type %d disable_req_type %d",
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                "nan_handle_disable_ind",
                (unsigned int)v12);
              nan_cache_disable_req_info(*v9, 0);
LABEL_43:
              result = 0;
              goto LABEL_12;
            }
            nan_disable_cleanup(*v9, v17, v18, v19, v20, v21, v22, v23, v24);
LABEL_40:
            v69 = *(void (__fastcall **)(_QWORD))(v13 + 16);
            if ( *((_DWORD *)v69 - 1) != -1334644194 )
              __break(0x8228u);
            v69(v9);
            goto LABEL_43;
          }
          v25 = *v9;
          if ( *v9 )
          {
            v26 = wlan_objmgr_psoc_get_comp_private_obj(*v9, 0xFu);
            if ( v26 )
            {
              v35 = v26;
              pdev_by_id = wlan_objmgr_get_pdev_by_id(v25, 0, 0x14u);
              if ( pdev_by_id )
              {
                v45 = pdev_by_id;
                first_vdev = wlan_objmgr_pdev_get_first_vdev(pdev_by_id, 0x14u);
                if ( first_vdev )
                {
                  v55 = (__int64)first_vdev;
                  if ( *((_BYTE *)v9 + 12) == 1 )
                  {
                    if ( (unsigned int)nan_set_discovery_state(v25, 2, v47, v48, v49, v50, v51, v52, v53, v54) )
                    {
                      *(_QWORD *)(v35 + 276) = 0;
                      policy_mgr_check_n_start_opportunistic_timer(v25);
LABEL_65:
                      wlan_objmgr_pdev_release_ref(v45, 0x14u, v56, v57, v58, v59, v60, v61, v62, v63, v64);
                      wlan_objmgr_vdev_release_ref(v55, 0x14u, v126, v127, v128, v129, v130, v131, v132, v133, v134);
LABEL_52:
                      v105 = nan_cstats_log_nan_enable_resp_evt(v9);
                      v106 = *(void (__fastcall **)(_QWORD))(v35 + 144);
                      if ( v106 )
                      {
                        if ( *((_DWORD *)v106 - 1) != -440107680 )
                          __break(0x8228u);
                        v106(v105);
                      }
                      v107 = *(void (__fastcall **)(_QWORD))(v35 + 32);
                      if ( v107 )
                      {
                        v108 = *(_QWORD *)(v35 + 296);
                        if ( *((_DWORD *)v107 - 1) != 251140989 )
                          __break(0x8228u);
                        v107(v108);
                      }
                      goto LABEL_40;
                    }
                    *(_BYTE *)(v35 + 284) = *((_BYTE *)v9 + 13);
                    v109 = *((unsigned __int8 *)v9 + 14);
                    if ( (ucfg_nan_is_vdev_creation_allowed(v25) & 1) != 0 )
                    {
                      if ( v109 >= 6 )
                      {
                        qdf_trace_msg(
                          0x53u,
                          2u,
                          "%s: Invalid NAN vdev_id: %u",
                          v110,
                          v111,
                          v112,
                          v113,
                          v114,
                          v115,
                          v116,
                          v117,
                          "nan_handle_enable_rsp",
                          v109);
                        goto LABEL_48;
                      }
                    }
                    else
                    {
                      v109 = 4;
                    }
                    qdf_trace_msg(
                      0x53u,
                      8u,
                      "%s: NAN vdev_id: %u",
                      v110,
                      v111,
                      v112,
                      v113,
                      v114,
                      v115,
                      v116,
                      v117,
                      "nan_handle_enable_rsp",
                      v109);
                    policy_mgr_incr_active_session(v25, 0x10u, v109, 1);
                    policy_mgr_process_force_scc_for_nan(v25);
                    if_mgr_deliver_event(v55, 0x16u, 0, v118, v119, v120, v121, v122, v123, v124, v125);
                    goto LABEL_65;
                  }
                  qdf_trace_msg(
                    0x53u,
                    4u,
                    "%s: NAN enable has failed",
                    v47,
                    v48,
                    v49,
                    v50,
                    v51,
                    v52,
                    v53,
                    v54,
                    "nan_handle_enable_rsp");
LABEL_48:
                  wlan_objmgr_pdev_release_ref(v45, 0x14u, v87, v88, v89, v90, v91, v92, v93, v94, v95);
                  wlan_objmgr_vdev_release_ref(v55, 0x14u, v96, v97, v98, v99, v100, v101, v102, v103, v104);
                  goto LABEL_49;
                }
                qdf_trace_msg(
                  0x53u,
                  2u,
                  "%s: No vdev is up yet, unable to proceed!",
                  v47,
                  v48,
                  v49,
                  v50,
                  v51,
                  v52,
                  v53,
                  v54,
                  "nan_handle_enable_rsp");
                wlan_objmgr_pdev_release_ref(v45, 0x14u, v78, v79, v80, v81, v82, v83, v84, v85, v86);
              }
              else
              {
                qdf_trace_msg(
                  0x53u,
                  2u,
                  "%s: null pdev",
                  v37,
                  v38,
                  v39,
                  v40,
                  v41,
                  v42,
                  v43,
                  v44,
                  "nan_handle_enable_rsp");
              }
LABEL_49:
              *(_QWORD *)(v35 + 276) = 0;
              nan_set_discovery_state(v25, 0, v70, v71, v72, v73, v74, v75, v76, v77);
              if ( (ucfg_is_nan_dbs_supported(v25) & 1) != 0 )
                policy_mgr_check_n_start_opportunistic_timer(v25);
              ucfg_tdls_notify_connect_failure(v25);
              goto LABEL_52;
            }
          }
          else
          {
            qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "nan_get_psoc_priv_obj");
          }
          v68 = "nan_handle_enable_rsp";
        }
        qdf_trace_msg(0x53u, 2u, "%s: psoc_nan_obj is NULL", v27, v28, v29, v30, v31, v32, v33, v34, v68);
        goto LABEL_40;
      }
      v14 = "%s: psoc_nan_obj is null";
    }
    else
    {
      v14 = "%s: psoc is NULL";
    }
  }
  else
  {
    v14 = "%s: msg body is null";
  }
  qdf_trace_msg(0x53u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "nan_discovery_event_handler");
  result = 29;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
