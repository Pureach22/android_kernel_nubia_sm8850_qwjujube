__int64 __fastcall policy_mgr_check_sta_ap_concurrent_ch_intf(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
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
  __int64 v27; // x20
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x8
  __int64 v37; // x20
  __int64 v38; // x0
  __int64 context; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x26
  _QWORD *v49; // x21
  unsigned int v50; // w24
  unsigned int operation_chan_freq_vdev_id; // w25
  unsigned int opmode_from_vdev_id; // w0
  unsigned int v53; // w23
  unsigned int existing_con_info; // w22
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  bool v63; // zf
  int v64; // w8
  _DWORD *v65; // x8
  unsigned int v66; // w23
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  _DWORD *v75; // x8
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 v92; // x5
  __int64 v93; // x6
  const char *v94; // x2
  __int64 v95; // x5
  __int64 v96; // x20
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  unsigned __int8 *v105; // x22
  unsigned int sap_mode_info; // w20
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
  const char *v123; // x2
  const char *v124; // x2
  const char *v125; // x3
  __int64 (*v126)(void); // x8
  unsigned int (__fastcall *v127)(__int64, __int64, unsigned int *); // x8
  __int64 v128; // x0
  __int64 v129; // x1
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  unsigned int (__fastcall *v138)(__int64, __int64, unsigned int *); // x8
  __int64 v139; // x0
  __int64 v140; // x1
  unsigned int (__fastcall *v141)(__int64, __int64, unsigned int *); // x8
  __int64 v142; // x0
  __int64 v143; // x1
  unsigned int (__fastcall *v144)(__int64, __int64, unsigned int *); // x8
  __int64 v145; // x0
  __int64 v146; // x1
  unsigned int (__fastcall *v147)(__int64, __int64, unsigned int *); // x8
  __int64 v148; // x0
  __int64 v149; // x1
  unsigned int *v150; // x8
  _DWORD *v151; // x8
  __int64 v152; // x2
  unsigned int v153; // [xsp+24h] [xbp-4Ch] BYREF
  unsigned int v154; // [xsp+28h] [xbp-48h] BYREF
  __int64 v155; // [xsp+2Ch] [xbp-44h]
  int v156; // [xsp+34h] [xbp-3Ch]
  unsigned int v157; // [xsp+38h] [xbp-38h] BYREF
  unsigned int v158; // [xsp+3Ch] [xbp-34h] BYREF
  unsigned int v159; // [xsp+40h] [xbp-30h] BYREF
  int v160; // [xsp+44h] [xbp-2Ch] BYREF
  int v161; // [xsp+48h] [xbp-28h] BYREF
  unsigned __int8 v162; // [xsp+4Ch] [xbp-24h] BYREF
  __int64 v163; // [xsp+50h] [xbp-20h] BYREF
  __int64 v164; // [xsp+58h] [xbp-18h] BYREF
  int v165; // [xsp+60h] [xbp-10h] BYREF
  __int64 v166; // [xsp+68h] [xbp-8h]

  v166 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: Invalid context",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "policy_mgr_check_sta_ap_concurrent_ch_intf");
    goto LABEL_103;
  }
  result = _qdf_op_protect();
  if ( !(_DWORD)result )
  {
    v27 = a1[262];
    *((_BYTE *)a1 + 1128) = 0;
    v153 = 0;
    v165 = 0;
    v163 = 0;
    v164 = 0;
    v162 = 0;
    v161 = 0;
    if ( !v27 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid work_info context",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "__policy_mgr_check_sta_ap_concurrent_ch_intf");
LABEL_102:
      result = _qdf_op_unprotect();
      goto LABEL_103;
    }
    a1[261] = qdf_get_current_task();
    if ( !*(_BYTE *)(v27 + 52) || (unsigned int)policy_mgr_nan_sap_post_enable_conc_check(*a1) != 24 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: p2p go vdev id: %d csa reason: %d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "__policy_mgr_check_sta_ap_concurrent_ch_intf",
        *(unsigned __int8 *)(v27 + 32),
        *(unsigned int *)(v27 + 44));
      v36 = a1[262];
      if ( *(unsigned __int8 *)(v36 + 32) != 255 )
      {
        policy_mgr_do_go_plus_go_force_scc(
          *a1,
          *(unsigned __int8 *)(v27 + 32),
          *(unsigned int *)(v27 + 36),
          *(unsigned int *)(v27 + 40));
        *(_BYTE *)(v27 + 32) = -1;
        goto LABEL_101;
      }
      v37 = *a1;
      if ( *(_DWORD *)(v36 + 44) )
      {
        v38 = *a1;
        v156 = 0;
        v157 = 0;
        v159 = 0;
        v160 = 7;
        v155 = 0;
        context = policy_mgr_get_context(v38);
        if ( context )
        {
          v48 = *(_QWORD *)(context + 2096);
          v49 = (_QWORD *)context;
          if ( v48 )
          {
            if ( !*(_DWORD *)(v48 + 44) )
              goto LABEL_101;
            v50 = *(unsigned __int8 *)(v48 + 48);
            operation_chan_freq_vdev_id = wlan_get_operation_chan_freq_vdev_id(
                                            *(_QWORD *)(context + 8),
                                            *(unsigned __int8 *)(v48 + 48));
            opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(v49[1], v50);
            v53 = policy_mgr_qdf_opmode_to_pm_con_mode(v37, opmode_from_vdev_id, v50);
            existing_con_info = (unsigned __int8)policy_mgr_fetch_existing_con_info(
                                                   v37,
                                                   v50,
                                                   operation_chan_freq_vdev_id,
                                                   &v160,
                                                   &v159,
                                                   &v157);
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: initiator vdev %d mode %d freq %d, existing vdev %d mode %d freq %d reason %d",
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              "policy_mgr_handle_sap_plus_go_force_scc",
              v50,
              v53,
              operation_chan_freq_vdev_id,
              existing_con_info,
              v160,
              v159,
              *(_DWORD *)(v48 + 44),
              0);
            if ( existing_con_info != 255 )
            {
              if ( v53 == 3 && v160 == 1
                || (v160 != 3 ? (v63 = v160 == 1) : (v63 = 1), !v63 ? (v64 = 0) : (v64 = 1), v53 == 1 && v64) )
              {
                v65 = (_DWORD *)v49[47];
                if ( v65 )
                {
                  v158 = 0;
                  if ( *(v65 - 1) != 801623019 )
                    __break(0x8228u);
                  v66 = ((__int64 (__fastcall *)(__int64, _QWORD, unsigned int *))v65)(v37, existing_con_info, &v158);
                  qdf_trace_msg(
                    0x4Fu,
                    8u,
                    "%s: vdev %d freq %d intf %d status %d",
                    v67,
                    v68,
                    v69,
                    v70,
                    v71,
                    v72,
                    v73,
                    v74,
                    "policy_mgr_handle_sap_plus_go_force_scc",
                    existing_con_info,
                    v159,
                    v158,
                    v66);
                  if ( !v66 && v158 && v158 != v159 )
                  {
                    v75 = (_DWORD *)v49[45];
                    v154 = v157;
                    if ( v75 )
                    {
                      if ( *(v75 - 1) != 157525345 )
                        __break(0x8228u);
                      if ( ((unsigned int (__fastcall *)(__int64, _QWORD))v75)(v37, existing_con_info) )
                        qdf_trace_msg(
                          0x4Fu,
                          8u,
                          "%s: no candidate valid bw for vdev %d intf %d",
                          v76,
                          v77,
                          v78,
                          v79,
                          v80,
                          v81,
                          v82,
                          v83,
                          "policy_mgr_handle_sap_plus_go_force_scc",
                          existing_con_info,
                          v158);
                    }
                    if ( (unsigned int)policy_mgr_valid_sap_conc_channel_check(
                                         v37,
                                         &v158,
                                         v159,
                                         existing_con_info,
                                         &v154) )
                    {
                      v93 = v158;
                      v92 = v159;
                      v94 = "%s: warning no candidate freq for vdev %d freq %d intf %d";
                    }
                    else
                    {
                      v151 = (_DWORD *)v49[42];
                      if ( v151 )
                      {
                        v152 = *(unsigned int *)(v48 + 44);
                        if ( *(v151 - 1) != -1125204353 )
                          __break(0x8228u);
                        ((void (__fastcall *)(__int64, _QWORD, __int64))v151)(v37, existing_con_info, v152);
                      }
                      if ( !(unsigned int)policy_mgr_change_sap_channel_with_csa(v37, existing_con_info, v158, v154, 1) )
                        goto LABEL_100;
                      v93 = v158;
                      v92 = v159;
                      v94 = "%s: warning sap/go vdev %d freq %d intf %d csa failed";
                    }
                    qdf_trace_msg(
                      0x4Fu,
                      2u,
                      v94,
                      v84,
                      v85,
                      v86,
                      v87,
                      v88,
                      v89,
                      v90,
                      v91,
                      "policy_mgr_handle_sap_plus_go_force_scc",
                      existing_con_info,
                      v92,
                      v93);
                  }
                }
              }
            }
LABEL_100:
            *(_DWORD *)(v48 + 44) = 0;
            *(_WORD *)(v48 + 48) = -1;
            goto LABEL_101;
          }
          v123 = "%s: invalid work info";
        }
        else
        {
          v123 = "%s: Invalid Context";
        }
        v125 = "policy_mgr_handle_sap_plus_go_force_scc";
LABEL_58:
        qdf_trace_msg(0x4Fu, 2u, v123, v40, v41, v42, v43, v44, v45, v46, v47, v125);
        goto LABEL_101;
      }
      policy_mgr_get_mcc_to_scc_switch_mode(*a1);
      v96 = *a1;
      if ( !(unsigned int)policy_mgr_get_sap_mode_count(*a1, 0)
        && !(unsigned int)policy_mgr_mode_specific_connection_count(v96, 3, 0) )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: No beaconing interface present",
          v97,
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          "__policy_mgr_check_sta_ap_concurrent_ch_intf");
        goto LABEL_101;
      }
      v105 = (unsigned __int8 *)&v161;
      sap_mode_info = policy_mgr_get_sap_mode_info(*a1, &v163, &v161);
      if ( sap_mode_info >= 5 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: No. of beaconing interface (SAP + LL LT SAP + GO):%d",
          v107,
          v108,
          v109,
          v110,
          v111,
          v112,
          v113,
          v114,
          "__policy_mgr_check_sta_ap_concurrent_ch_intf",
          sap_mode_info);
      }
      else
      {
        sap_mode_info += policy_mgr_get_mode_specific_conn_info(
                           *a1,
                           (char *)&v163 + 4 * sap_mode_info,
                           (char *)&v161 + sap_mode_info,
                           3);
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: No. of beaconing interface (SAP + LL LT SAP + GO):%d",
          v115,
          v116,
          v117,
          v118,
          v119,
          v120,
          v121,
          v122,
          "__policy_mgr_check_sta_ap_concurrent_ch_intf",
          sap_mode_info);
        if ( !sap_mode_info )
        {
          v123 = "%s: Could not retrieve SAP/GO operating channel&vdevid";
LABEL_92:
          v125 = "__policy_mgr_check_sta_ap_concurrent_ch_intf";
          goto LABEL_58;
        }
      }
      if ( (policy_mgr_is_any_conn_in_transition(*a1) & 1) != 0 )
      {
        v124 = "%s: defer sap conc check to a later time due to another sta/cli dicon/roam pending";
LABEL_61:
        qdf_trace_msg(
          0x4Fu,
          8u,
          v124,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "__policy_mgr_check_sta_ap_concurrent_ch_intf");
        _qdf_delayed_work_start((__int64)(a1 + 126), 0x7D0u);
        goto LABEL_101;
      }
      if ( (policy_mgr_is_ap_start_in_progress(*a1) & 1) != 0 )
      {
        v124 = "%s: defer sap conc check to a later time due to another sap/go start pending";
        goto LABEL_61;
      }
      v126 = (__int64 (*)(void))a1[40];
      if ( v126 )
      {
        if ( *((_DWORD *)v126 - 1) != 799902358 )
          __break(0x8228u);
        if ( (v126() & 1) != 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: wait as channel switch is already in progress",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "__policy_mgr_check_sta_ap_concurrent_ch_intf");
          if ( (unsigned int)qdf_wait_single_event((__int64)(a1 + 269), 0x7D0u) )
            qdf_trace_msg(
              0x4Fu,
              2u,
              "%s: wait for event failed, still continue with channel switch",
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              "__policy_mgr_check_sta_ap_concurrent_ch_intf");
        }
      }
      if ( !a1[37] )
      {
        v123 = "%s: SAP restart get channel callback in NULL";
        goto LABEL_92;
      }
      if ( sap_mode_info <= 5 )
      {
        policy_mgr_switch_sap_vdev_table_sequence(a1, &v161, sap_mode_info);
        v127 = (unsigned int (__fastcall *)(__int64, __int64, unsigned int *))a1[37];
        v128 = *a1;
        v129 = (unsigned __int8)v161;
        if ( *((_DWORD *)v127 - 1) != 801623019 )
          __break(0x8228u);
        if ( v127(v128, v129, &v153) )
        {
          if ( sap_mode_info == 1 )
            goto LABEL_101;
          v138 = (unsigned int (__fastcall *)(__int64, __int64, unsigned int *))a1[37];
          v139 = *a1;
          v140 = BYTE1(v161);
          if ( *((_DWORD *)v138 - 1) != 801623019 )
            __break(0x8228u);
          if ( v138(v139, v140, &v153) )
          {
            if ( sap_mode_info == 2 )
              goto LABEL_101;
            v141 = (unsigned int (__fastcall *)(__int64, __int64, unsigned int *))a1[37];
            v142 = *a1;
            v143 = BYTE2(v161);
            if ( *((_DWORD *)v141 - 1) != 801623019 )
              __break(0x8228u);
            if ( v141(v142, v143, &v153) )
            {
              if ( sap_mode_info == 3 )
                goto LABEL_101;
              v144 = (unsigned int (__fastcall *)(__int64, __int64, unsigned int *))a1[37];
              v145 = *a1;
              v146 = HIBYTE(v161);
              if ( *((_DWORD *)v144 - 1) != 801623019 )
                __break(0x8228u);
              if ( v144(v145, v146, &v153) )
              {
                if ( sap_mode_info == 4 )
                  goto LABEL_101;
                v147 = (unsigned int (__fastcall *)(__int64, __int64, unsigned int *))a1[37];
                v148 = *a1;
                v149 = v162;
                if ( *((_DWORD *)v147 - 1) != 801623019 )
                  __break(0x8228u);
                if ( v147(v148, v149, &v153) )
                  goto LABEL_101;
                v105 = &v162;
                v150 = (unsigned int *)&v165;
              }
              else
              {
                v105 = (unsigned __int8 *)&v161 + 3;
                v150 = (unsigned int *)&v164 + 1;
              }
            }
            else
            {
              v105 = (unsigned __int8 *)&v161 + 2;
              v150 = (unsigned int *)&v164;
            }
          }
          else
          {
            v105 = (unsigned __int8 *)&v161 + 1;
            v150 = (unsigned int *)&v163 + 1;
          }
        }
        else
        {
          v150 = (unsigned int *)&v163;
        }
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: SAP vdev id %d restarts, old ch freq :%d new ch freq: %d",
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          v137,
          "__policy_mgr_check_sta_ap_concurrent_ch_intf",
          *v105,
          *v150,
          v153);
      }
    }
LABEL_101:
    *((_DWORD *)a1 + 241) = 0;
    a1[261] = 0;
    goto LABEL_102;
  }
  if ( (_DWORD)result == -11 )
  {
    if ( (qdf_is_driver_unloading() & 1) != 0
      || (qdf_is_recovering() & 1) != 0
      || (result = qdf_is_driver_state_module_stop(), (result & 1) != 0) )
    {
      result = qdf_trace_msg(
                 0x4Fu,
                 8u,
                 "%s: driver not ready",
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 "policy_mgr_check_sta_ap_concurrent_ch_intf");
    }
    else if ( a1[262] )
    {
      v95 = (unsigned __int8)++*((_BYTE *)a1 + 1128);
      result = qdf_trace_msg(
                 0x4Fu,
                 8u,
                 "%s: qdf_op start fail, ret %d, work_fail_count %d",
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 "policy_mgr_check_sta_ap_concurrent_ch_intf",
                 4294967285LL,
                 v95);
      if ( *((unsigned __int8 *)a1 + 1128) < 2u )
        result = _qdf_delayed_work_start((__int64)(a1 + 126), 0x7D0u);
      else
        *((_BYTE *)a1 + 1128) = 0;
    }
  }
LABEL_103:
  _ReadStatusReg(SP_EL0);
  return result;
}
