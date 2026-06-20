__int64 __fastcall ml_nlink_conn_change_notify(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  char is_set_link_in_progress; // w24
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  const char *v17; // x5
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x20
  __int64 v28; // x0
  __int64 v29; // x0
  unsigned int started; // w22
  __int64 v31; // x0
  __int64 v32; // x1
  __int64 v33; // x2
  unsigned int v34; // w24
  unsigned int v35; // w23
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x1
  __int64 v40; // x2
  __int64 v41; // x0
  __int64 v42; // x1
  __int64 v43; // x2
  __int64 v44; // x3
  int v45; // w8
  __int64 v46; // x4
  const char *v47; // x2
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  const char *v56; // x2
  int v57; // w23
  char is_link_recfg_in_progress; // w0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x0
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned __int64 v76; // x8
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x0
  unsigned int *v86; // x8
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  __int64 v95; // x23
  __int64 v96; // x24
  unsigned int v97; // w21
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  _QWORD v115[2]; // [xsp+8h] [xbp-48h] BYREF
  __int16 v116; // [xsp+18h] [xbp-38h]
  _BYTE v117[4]; // [xsp+20h] [xbp-30h] BYREF
  _BYTE v118[4]; // [xsp+24h] [xbp-2Ch] BYREF
  int v119; // [xsp+28h] [xbp-28h] BYREF
  char v120; // [xsp+2Ch] [xbp-24h]
  _QWORD v121[2]; // [xsp+30h] [xbp-20h] BYREF
  int v122; // [xsp+40h] [xbp-10h]
  __int64 v123; // [xsp+48h] [xbp-8h]

  v123 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v116 = 0;
  v115[0] = 0;
  v115[1] = 0;
  is_set_link_in_progress = policy_mgr_is_set_link_in_progress(a1);
  if ( a3 > 0x1E )
    v17 = "Unknown";
  else
    v17 = off_B32D40[a3];
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: vdev %d %s(%d)",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "ml_nlink_conn_change_notify",
    (unsigned __int8)a2,
    v17,
    a3);
  v18 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 90);
  if ( v18 )
  {
    v27 = v18;
    switch ( a3 )
    {
      case 0u:
        v45 = *(_DWORD *)(a4 + 8);
        if ( v45 == 4 )
        {
          v57 = 1;
        }
        else
        {
          if ( v45 == 65534 )
          {
            v46 = *(unsigned __int8 *)(a4 + 1);
            v47 = "%s: REASON_HOST_ADD_LINK target link %d";
            goto LABEL_55;
          }
          v57 = 0;
        }
        is_link_recfg_in_progress = mlo_is_link_recfg_in_progress(v18);
        v67 = qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: set_link_in_prog %d link_recfg_in_prog %d reason %d",
                v59,
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                v66,
                "ml_nlink_conn_change_notify",
                is_set_link_in_progress & 1,
                is_link_recfg_in_progress & 1,
                *(unsigned int *)(a4 + 8));
        if ( (is_set_link_in_progress & 1) != 0 )
        {
          if ( v57 )
            started = 0;
          else
            started = 4;
        }
        else if ( (v57 & 1) != 0 )
        {
          started = 4;
        }
        else
        {
          if ( *(_DWORD *)(a4 + 8) == 7 )
          {
            v67 = mlo_is_link_recfg_in_progress(v27);
            if ( (v67 & 1) != 0 )
              goto LABEL_67;
          }
          ml_nlink_get_curr_force_state(v68, v69, v70, v71, v72, v73, v74, v75, v67, v27, v115);
          if ( ((WORD1(v115[0]) >> *(_BYTE *)(a4 + 1)) & 1) == 0 )
            goto LABEL_67;
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: target link %d is force inactive, don't switch to it",
            v107,
            v108,
            v109,
            v110,
            v111,
            v112,
            v113,
            v114,
            "ml_nlink_conn_change_notify");
          started = 4;
        }
        goto LABEL_68;
      case 1u:
        started = ml_nlink_swtich_dynamic_inactive_link(a1, v18);
        goto LABEL_68;
      case 2u:
      case 5u:
      case 8u:
        v28 = ml_nlink_clr_requested_emlsr_mode(v18, v18);
        v29 = ml_nlink_clr_force_state(v28, v27);
        ml_nlink_clr_emlsr_mode_disable_req(v29, v27, 1023);
        ml_nlink_reset_disallow_modes(v27);
        goto LABEL_67;
      case 3u:
        v41 = a1;
        v42 = v27;
        v43 = 1;
        v44 = 3;
        goto LABEL_40;
      case 4u:
      case 0xAu:
        v31 = a1;
        v32 = v27;
        v33 = a3;
        goto LABEL_50;
      case 6u:
        ml_nlink_init_disallow_modes(a1, v18);
        ml_nlink_undo_emlsr_downgrade_handler(a1, v27, 6);
        v41 = a1;
        v42 = v27;
        v43 = 2;
        v44 = 6;
        goto LABEL_40;
      case 7u:
      case 0xBu:
        v38 = a1;
        v39 = v27;
        v40 = a3;
        goto LABEL_43;
      case 9u:
        v41 = a1;
        v42 = v27;
        v43 = 2;
        v44 = 9;
        goto LABEL_40;
      case 0xCu:
        if ( !policy_mgr_is_vdev_ll_lt_sap(a1, (unsigned __int8)a2) )
          ml_nlink_undo_emlsr_downgrade_handler(a1, v27, 12);
        v41 = a1;
        v42 = v27;
        v43 = 2;
        v44 = 12;
        goto LABEL_40;
      case 0xDu:
        if ( policy_mgr_is_vdev_ll_lt_sap(a1, (unsigned __int8)a2) )
          ml_nlink_undo_emlsr_downgrade_handler(a1, v27, 13);
        v41 = a1;
        v42 = v27;
        v43 = 2;
        v44 = 13;
        goto LABEL_40;
      case 0xEu:
        started = ml_nlink_ap_csa_start_handler(a1, v18, a4);
        goto LABEL_68;
      case 0xFu:
        if ( policy_mgr_is_dual_sap_active(a1) )
          ml_nlink_state_change_handler(a1, v27, 1, 15, a4);
        ml_nlink_ap_csa_end_handler(a1, v27, a4);
        goto LABEL_67;
      case 0x10u:
      case 0x13u:
        v34 = *(_DWORD *)(v18 + 16);
        if ( v34 )
        {
          v35 = *(unsigned __int8 *)(v18 + 168);
          if ( !a1 )
            goto LABEL_65;
          goto LABEL_11;
        }
        if ( (unsigned int)mlme_get_roam_state(a1, a2) != 5 && (unsigned int)mlme_get_roam_state(a1, a2) != 6 )
        {
          v34 = *(_DWORD *)(v27 + 16);
          v35 = *(unsigned __int8 *)(v27 + 168);
          if ( !a1 )
            goto LABEL_65;
LABEL_11:
          v36 = *(_QWORD *)(a1 + 2800);
          if ( v36 )
          {
            v37 = *(_QWORD *)(v36 + 16);
            if ( v37 )
            {
              if ( (wmi_service_enabled(v37, 0x129u, v19, v20, v21, v22, v23, v24, v25, v26) & 1) != 0 )
              {
                started = ml_nlink_state_change(a1, 1, a3, a4);
                goto LABEL_68;
              }
              goto LABEL_66;
            }
          }
LABEL_65:
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: Invalid WMI handle",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            "ml_is_nlink_service_supported");
LABEL_66:
          policy_mgr_handle_ml_sta_links_on_vdev_up_csa(a1, v34, v35);
          goto LABEL_67;
        }
        v47 = "%s: vdev id %d in roam sync";
        v46 = (unsigned __int8)a2;
LABEL_55:
        qdf_trace_msg(0x8Fu, 8u, v47, v19, v20, v21, v22, v23, v24, v25, v26, "ml_nlink_conn_change_notify", v46);
LABEL_67:
        started = 0;
LABEL_68:
        if ( (policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr) & 1) == 0
          || (wlan_mlme_is_aux_emlsr_support(a1) & 1) == 0
          || a3 > 0x1E )
        {
          goto LABEL_83;
        }
        v76 = (unsigned int)(1 << a3);
        if ( (v76 & 0x63E0FC43) != 0 )
          goto LABEL_72;
        if ( (v76 & 0x3BC) != 0 )
        {
          if ( mlo_is_mld_sta(v27, v77, v78, v79, v80, v81, v82, v83, v84) )
          {
            policy_mgr_stop_emlsr_opportunistic_timer(a1);
          }
          else
          {
LABEL_72:
            v118[0] = 0;
            v117[0] = 0;
            v120 = 0;
            v119 = 0;
            v122 = 0;
            v121[0] = 0;
            v121[1] = 0;
            policy_mgr_get_ml_sta_info_psoc(a1, v118, v117, (__int64)&v119, (__int64)v121, nullptr, 0, 0);
            v76 = (unsigned int)v118[0] - 6;
            if ( (unsigned int)v76 >= 0xFFFFFFFB )
            {
              v85 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                      a1,
                      (unsigned __int8)v119,
                      90);
              if ( v85 )
              {
                v95 = *(_QWORD *)(v85 + 1360);
                if ( v95 )
                {
                  v86 = *(unsigned int **)(v95 + 2224);
                  if ( v86 )
                  {
                    v96 = v85;
                    qdf_mutex_acquire(v95 + 1656);
                    v97 = *(_DWORD *)(*(_QWORD *)(v95 + 2224) + 1448LL);
                    qdf_trace_msg(
                      0x8Fu,
                      8u,
                      "%s: disable_req 0x%x",
                      v98,
                      v99,
                      v100,
                      v101,
                      v102,
                      v103,
                      v104,
                      v105,
                      "ml_nlink_get_emlsr_mode_disable_req",
                      v97);
                    qdf_mutex_release(v95 + 1656);
                    v85 = v96;
                    if ( (v97 & 0x3FE) != 0 )
                    {
                      policy_mgr_restart_emlsr_opportunistic_timer(a1);
                      v85 = v96;
                    }
                  }
                }
                wlan_objmgr_vdev_release_ref(v85, 0x5Au, v86, v87, v88, v89, v90, v91, v92, v93, v94);
              }
              else
              {
                qdf_trace_msg(
                  0x8Fu,
                  2u,
                  "%s: invalid vdev for id %d",
                  v87,
                  v88,
                  v89,
                  v90,
                  v91,
                  v92,
                  v93,
                  v94,
                  "ml_nlink_get_affect_ml_sta",
                  (unsigned __int8)v119);
              }
            }
          }
        }
LABEL_83:
        wlan_objmgr_vdev_release_ref(v27, 0x5Au, (unsigned int *)v76, v77, v78, v79, v80, v81, v82, v83, v84);
        break;
      case 0x11u:
        started = ml_nlink_tdls_event_handler(a1, v18, a4);
        goto LABEL_68;
      case 0x12u:
        started = ml_nlink_vendor_cmd_handler(a1, v18, a4);
        goto LABEL_68;
      case 0x14u:
        started = ml_nlink_emlsr_opportunistic_timer_handler(a1, a4);
        goto LABEL_68;
      case 0x15u:
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: NAN Pre-enable",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "ml_nlink_conn_change_notify");
        ml_nlink_nan_pre_enable_handler(a1);
        v41 = a1;
        v42 = v27;
        v43 = 1;
        v44 = 21;
LABEL_40:
        started = ml_nlink_state_change_handler(v41, v42, v43, v44, a4);
        goto LABEL_68;
      case 0x16u:
        started = ml_nlink_state_change_handler(a1, v18, 1, 22, a4);
        v56 = "%s: NAN Post-enable";
        goto LABEL_47;
      case 0x17u:
        ml_nlink_nan_post_disable_handler(a1);
        started = ml_nlink_state_change_handler(a1, v27, 2, 23, a4);
        v56 = "%s: NAN Post-disable";
LABEL_47:
        qdf_trace_msg(0x8Fu, 8u, v56, v48, v49, v50, v51, v52, v53, v54, v55, "ml_nlink_conn_change_notify");
        goto LABEL_68;
      case 0x18u:
        if ( !policy_mgr_is_vdev_ll_lt_sap(a1, (unsigned __int8)a2) )
          goto LABEL_67;
        v31 = a1;
        v32 = v27;
        v33 = 24;
LABEL_50:
        started = ml_nlink_emlsr_downgrade_handler(v31, v32, v33, a4);
        goto LABEL_68;
      case 0x19u:
        if ( !policy_mgr_is_vdev_ll_lt_sap(a1, (unsigned __int8)a2) )
          goto LABEL_67;
        v38 = a1;
        v39 = v27;
        v40 = 25;
LABEL_43:
        ml_nlink_undo_emlsr_downgrade_handler(v38, v39, v40);
        goto LABEL_67;
      case 0x1Au:
        started = ml_nlink_t2lm_event_handler(a1, v18, a4);
        goto LABEL_68;
      case 0x1Bu:
        started = ml_nlink_pre_t2lm_event_handler(a1, v18, a4);
        goto LABEL_68;
      case 0x1Cu:
        started = ml_nlink_link_recfg_completed_handler(a1, v18, a4);
        goto LABEL_68;
      case 0x1Du:
        v31 = a1;
        v32 = v27;
        v33 = 29;
        goto LABEL_50;
      case 0x1Eu:
        v38 = a1;
        v39 = v27;
        v40 = 30;
        goto LABEL_43;
      default:
        goto LABEL_67;
    }
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: invalid vdev id %d ",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "ml_nlink_conn_change_notify",
      (unsigned __int8)a2);
    started = 4;
  }
  _ReadStatusReg(SP_EL0);
  return started;
}
