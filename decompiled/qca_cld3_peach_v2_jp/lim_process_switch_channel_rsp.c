__int64 __fastcall lim_process_switch_channel_rsp(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w8
  unsigned int v22; // w22
  __int64 session_by_vdev_id; // x0
  __int64 v24; // x10
  _BYTE *v25; // x24
  int v26; // w23
  __int64 v27; // x19
  int v28; // w8
  unsigned __int16 *v29; // x25
  int v30; // w8
  const char *v31; // x2
  __int64 result; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // w8
  __int64 v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int v59; // w1
  _DWORD *v60; // x8
  __int64 v61; // x2
  __int64 v62; // x21
  const char *v63; // x2
  const char *v64; // x2
  __int64 v65; // x8
  int v66; // w9
  int v67; // w22
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  void *v76; // x21
  __int64 v77; // x4
  __int64 v78; // x0
  __int64 v79; // x0
  char v80; // w8
  int v81; // w4
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
  unsigned __int8 *v98; // x10
  __int64 v99; // x7
  int v100; // w8
  int v101; // w9
  int v102; // w10
  char v103; // w9
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  unsigned __int8 *v112; // x11
  int v113; // w8
  int v114; // w9
  int v115; // w10
  int v116; // w11
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  __int16 v125; // w2
  __int64 v126; // x2
  __int64 v127; // x1
  __int64 concurrent_session; // x0
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  __int64 v137; // x21
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  __int64 tx_ops; // x0
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  __int64 v155; // x8
  __int64 v156; // x21
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  __int64 cmpt_obj; // x0
  __int64 v166; // x22
  void (__fastcall *v167)(__int64, __int64, __int64); // x8
  __int64 v168; // x0
  __int64 v169; // x1
  void (__fastcall *v170)(__int64, __int64, __int64); // x8
  __int64 v171; // x0
  __int64 v172; // x1
  const char *v173; // x2
  __int64 v174; // [xsp+0h] [xbp-60h]
  __int64 v175; // [xsp+8h] [xbp-58h]
  __int64 v176; // [xsp+10h] [xbp-50h]
  unsigned int v177; // [xsp+20h] [xbp-40h] BYREF
  _BYTE v178[4]; // [xsp+24h] [xbp-3Ch] BYREF
  __int64 v179; // [xsp+28h] [xbp-38h] BYREF
  __int64 v180; // [xsp+30h] [xbp-30h]
  __int64 v181; // [xsp+38h] [xbp-28h]
  __int64 v182; // [xsp+40h] [xbp-20h]
  __int64 v183; // [xsp+48h] [xbp-18h]
  __int64 v184; // [xsp+50h] [xbp-10h]
  __int64 v185; // [xsp+58h] [xbp-8h]

  v12 = a1 + 0x2000;
  v185 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)(a1 + 8888) = "lim_process_switch_channel_rsp";
  v177 = 0;
  *(_BYTE *)(a1 + 8885) = 1;
  qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", a3, a4, a5, a6, a7, a8, a9, a10);
  v21 = *(unsigned __int8 *)(v12 + 693);
  v183 = 0;
  v184 = 0;
  v181 = 0;
  v182 = 0;
  v179 = 0;
  v180 = 0;
  if ( v21 )
  {
    if ( *(_WORD *)(v12 + 496) )
    {
      LOWORD(v179) = 5119;
      if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)&v179) )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to post lim msg:0x%x",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "lim_post_msg_to_process_deferred_queue",
          (unsigned __int16)v179);
    }
  }
  if ( a2 )
  {
    v22 = a2[2];
    session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)a2);
    if ( session_by_vdev_id )
    {
      v24 = *(_QWORD *)(session_by_vdev_id + 16);
      v25 = (_BYTE *)(session_by_vdev_id + 7280);
      v26 = *(unsigned __int16 *)(session_by_vdev_id + 152);
      v27 = session_by_vdev_id;
      *(_BYTE *)(session_by_vdev_id + 9794) = 0;
      *(_BYTE *)(session_by_vdev_id + 7281) = a2[4];
      v28 = a2[5];
      *(_WORD *)(session_by_vdev_id + 152) = 2989;
      *(_BYTE *)(session_by_vdev_id + 7280) = v28;
      v29 = *(unsigned __int16 **)(v24 + 40);
      if ( wlan_reg_is_24ghz_ch_freq(*v29) )
      {
        if ( *((_DWORD *)v29 + 7) == 2 )
          v30 = 1;
        else
          v30 = 2;
        *(_DWORD *)(v27 + 96) = v30;
      }
      else
      {
        *(_DWORD *)(v27 + 96) = 0;
      }
      lim_fill_dfs_p2p_group_params(v27);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: new network type for peer: %d, csa_reason_code = %d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "lim_process_switch_channel_rsp",
        *(unsigned int *)(v27 + 96),
        (unsigned int)v26);
      if ( v26 > 2 )
      {
        if ( v26 == 3 )
        {
          if ( !v22 )
          {
            wlan_reg_get_cur_6g_ap_pwr_type(*(_QWORD *)(a1 + 21560), &v177, v41, v42, v43, v44, v45, v46, v47, v48);
            if ( !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v27 + 284))
              || v177 != 3
              || (lim_set_tpc_power(a1, v27, 0, 1),
                  !policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(v27 + 10))) )
            {
              lim_set_tpc_power(a1, v27, 0, 0);
            }
          }
          lim_send_sme_ap_channel_switch_resp(a1, v27, a2);
          policy_mgr_update_connection_info(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(v27 + 10));
          lim_check_conc_power_for_csa(a1, v27);
          lim_post_csa_ocv_sa_query_check(a1, v27, v22 == 0);
          goto LABEL_67;
        }
        if ( v26 != 4 )
        {
          if ( v26 == 5 )
          {
            v49 = *(_DWORD *)(v27 + 92);
            v183 = 0;
            v184 = 0;
            v181 = 0;
            v182 = 0;
            v179 = 0;
            v180 = 0;
            if ( v49 == 3 )
            {
              v50 = *(_QWORD *)(v27 + 16);
              if ( v22 )
              {
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: Set channel failed for monitor mode vdev substate %d",
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  v46,
                  v47,
                  v48,
                  "lim_handle_mon_switch_channel_rsp",
                  *(unsigned int *)(v50 + 24));
                if ( (unsigned int)wlan_vdev_is_restart_progress(*(_QWORD *)(v27 + 16)) )
                  v59 = 5;
                else
                  v59 = 6;
                wlan_vdev_mlme_sm_deliver_evt(*(_QWORD *)(v27 + 16), v59, 0, 0, v51, v52, v53, v54, v55, v56, v57, v58);
              }
              else
              {
                wlan_vdev_mlme_sm_deliver_evt(v50, 7u, 0, 0, v41, v42, v43, v44, v45, v46, v47, v48);
                v81 = *(unsigned __int8 *)(v27 + 10);
                LOWORD(v179) = 5281;
                HIDWORD(v179) = v81;
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: vdev id %d ",
                  v82,
                  v83,
                  v84,
                  v85,
                  v86,
                  v87,
                  v88,
                  v89,
                  "lim_handle_mon_switch_channel_rsp");
                if ( (unsigned int)scheduler_post_message_debug(
                                     0x35u,
                                     0x34u,
                                     52,
                                     (unsigned __int16 *)&v179,
                                     0xE16u,
                                     (__int64)"lim_handle_mon_switch_channel_rsp") )
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "%s: Failed to post message montior mode vdev up",
                    v90,
                    v91,
                    v92,
                    v93,
                    v94,
                    v95,
                    v96,
                    v97,
                    "lim_handle_mon_switch_channel_rsp");
              }
            }
            policy_mgr_update_connection_info(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(v27 + 10));
          }
          goto LABEL_67;
        }
        goto LABEL_29;
      }
      if ( v26 )
      {
        if ( v26 != 1 )
        {
LABEL_29:
          v60 = *(_DWORD **)(a1 + 4040);
          if ( v60 )
          {
            v61 = *(_QWORD *)(a1 + 4048);
            if ( *(v60 - 1) != 1329690826 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))v60)(a1, v22, v61, v27);
          }
          policy_mgr_update_connection_info(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(v27 + 10));
          wlan_cm_handle_sta_sta_roaming_enablement(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(v27 + 10));
          if ( *(_DWORD *)(v27 + 7036) == 2 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Send p2p operating channel change conf action frame once first beacon is received on new channel",
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              "lim_process_switch_channel_rsp");
            v25[1393] = 1;
            v25[2515] = 1;
          }
          goto LABEL_67;
        }
        v179 = 0;
        if ( v22 )
        {
          v64 = "%s: Change channel failed!!";
          goto LABEL_58;
        }
        if ( !*(_QWORD *)(v27 + 128) || (v65 = *(_QWORD *)(v27 + 112)) == 0 )
        {
          v64 = "%s: invalid pointer!!";
          goto LABEL_58;
        }
        v66 = *(_DWORD *)(v27 + 72);
        v67 = *(unsigned __int8 *)(v65 + 4413);
        *(_DWORD *)(v27 + 72) = 2;
        *(_DWORD *)(v27 + 76) = v66;
        lim_apply_configuration((_QWORD *)a1, v27, v41, v42, v43, v44, v45, v46, v47, v48);
        if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3334LL) == 1 )
        {
          v76 = (void *)(a1 + 3996);
          if ( (unsigned int)qdf_mem_cmp((const void *)(*(_QWORD *)(v27 + 128) + 6LL), (const void *)(a1 + 3996), 6u) )
          {
            v76 = (void *)(a1 + 4002);
            if ( (unsigned int)qdf_mem_cmp((const void *)(*(_QWORD *)(v27 + 128) + 6LL), (const void *)(a1 + 4002), 6u) )
              goto LABEL_74;
            v77 = 1;
          }
          else
          {
            v77 = 0;
          }
          v98 = *(unsigned __int8 **)(v27 + 128);
          if ( v98 == (unsigned __int8 *)-6LL )
          {
            v101 = 0;
            v99 = 0;
            v100 = 0;
            v102 = 0;
          }
          else
          {
            v99 = v98[6];
            v100 = v98[7];
            v101 = v98[8];
            v102 = v98[11];
          }
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Index %d Sessionid: %d Send deauth on channel freq %d to BSSID: %02x:%02x:%02x:**:**:%02x",
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            "lim_process_switch_channel_join_req",
            v77,
            *(unsigned __int16 *)(v27 + 8),
            *(unsigned int *)(v27 + 284),
            v99,
            v100,
            v101,
            v102);
          lim_send_deauth_mgmt_frame(a1, 1, *(_QWORD *)(v27 + 128) + 6LL, v27, 0);
          qdf_mem_set(v76, 6u, 0);
        }
LABEL_74:
        if ( v67 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Skip sending join probe for MBSS candidate",
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            "lim_process_switch_channel_join_req");
          v103 = *(_BYTE *)(v27 + 8);
          LODWORD(v179) = 0;
          *(_DWORD *)(v27 + 72) = 3;
          BYTE6(v179) = v103;
          WORD2(v179) = 0;
LABEL_63:
          qdf_trace(53, 0xAu, 0, 1005);
          lim_process_mlm_join_cnf(a1, (__int64)&v179);
          goto LABEL_67;
        }
        lim_deactivate_and_change_timer(a1, 18);
        *(_BYTE *)(a1 + 2186) = *(_BYTE *)(v27 + 8);
        v112 = *(unsigned __int8 **)(v27 + 128);
        if ( v112 == (unsigned __int8 *)-6LL )
        {
          v115 = 0;
          v113 = 0;
          v114 = 0;
          v116 = 0;
        }
        else
        {
          v113 = v112[6];
          v114 = v112[7];
          v115 = v112[8];
          v116 = v112[11];
        }
        LODWORD(v176) = v115;
        LODWORD(v175) = v114;
        LODWORD(v174) = v113;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: vdev %d Send Probe req on freq %d %.*s %02x:%02x:%02x:**:**:%02x",
          v104,
          v105,
          v106,
          v107,
          v108,
          v109,
          v110,
          v111,
          "lim_process_switch_channel_join_req",
          *(unsigned __int8 *)(v27 + 10),
          *(unsigned int *)(v27 + 284),
          *(unsigned __int8 *)(v27 + 36),
          v27 + 37,
          v174,
          v175,
          v176,
          v116);
        qdf_trace(53, 0xDu, *(_WORD *)(v27 + 8), 2);
        if ( (unsigned int)tx_timer_activate((char *)(a1 + 1072)) )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: couldn't activate Join failure timer",
            v117,
            v118,
            v119,
            v120,
            v121,
            v122,
            v123,
            v124,
            "lim_process_switch_channel_join_req");
          v125 = *(_WORD *)(v27 + 8);
          *(_DWORD *)(v27 + 72) = *(_DWORD *)(v27 + 76);
          qdf_trace(53, 0, v125, *(_DWORD *)(a1 + 4020));
          v78 = *(_QWORD *)(v27 + 128);
          if ( !v78 )
            goto LABEL_60;
          goto LABEL_59;
        }
        v126 = *(unsigned int *)(v27 + 7036);
        v127 = *(unsigned __int8 *)(v27 + 10);
        v178[0] = 0;
        concurrent_session = lim_get_concurrent_session(a1, v127, v126);
        if ( concurrent_session )
        {
          v137 = concurrent_session;
          if ( (lim_is_power_change_required_for_sta(a1, v27, concurrent_session) & 1) != 0 )
            lim_update_tx_power(a1, v137, v27, 0);
        }
        if ( (wlan_reg_is_ext_tpc_supported(*(_QWORD *)(a1 + 21552), v129, v130, v131, v132, v133, v134, v135, v136) & 1) == 0 )
          goto LABEL_103;
        if ( (v25[2790] & 1) != 0 )
          goto LABEL_103;
        tx_ops = wlan_reg_get_tx_ops(*(_QWORD *)(a1 + 21552), v138, v139, v140, v141, v142, v143, v144, v145);
        if ( !tx_ops )
          goto LABEL_103;
        v155 = *(_QWORD *)(v27 + 112);
        if ( v155 )
        {
          v156 = tx_ops;
          lim_process_tpe_ie_from_beacon(a1, v27, v155 + 4364, v178);
          cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(v27 + 16), v157, v158, v159, v160, v161, v162, v163, v164);
          if ( cmpt_obj )
          {
            v166 = cmpt_obj;
            if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v27 + 284)) && v25[2789] == 3 )
            {
              lim_calculate_tpc(a1, v27, 1);
              v167 = *(void (__fastcall **)(__int64, __int64, __int64))(v156 + 144);
              if ( v167 )
              {
                v168 = *(_QWORD *)(a1 + 21552);
                v169 = *(unsigned __int8 *)(v27 + 10);
                if ( *((_DWORD *)v167 - 1) != 1094041931 )
                  __break(0x8228u);
                v167(v168, v169, v166 + 528);
              }
            }
            lim_calculate_tpc(a1, v27, 0);
            v170 = *(void (__fastcall **)(__int64, __int64, __int64))(v156 + 144);
            if ( v170 )
            {
              v171 = *(_QWORD *)(a1 + 21552);
              v172 = *(unsigned __int8 *)(v27 + 10);
              if ( *((_DWORD *)v170 - 1) != 1094041931 )
                __break(0x8228u);
              v170(v171, v172, v166 + 528);
            }
            goto LABEL_103;
          }
          v173 = "%s: vdev component object is NULL";
        }
        else
        {
          v173 = "%s: bss descriptor is NULL";
        }
        qdf_trace_msg(
          0x35u,
          2u,
          v173,
          v147,
          v148,
          v149,
          v150,
          v151,
          v152,
          v153,
          v154,
          "lim_process_bcn_tpe_and_set_tpc");
LABEL_103:
        lim_send_probe_req_mgmt_frame(a1, v27, *(_QWORD *)(v27 + 112) + 260LL, *(_QWORD *)(v27 + 112) + 262LL);
        if ( !(unsigned int)tx_timer_activate((char *)(a1 + 2136)) )
        {
          ++v25[2794];
          goto LABEL_67;
        }
        v64 = "%s: Periodic JoinReq timer activate failed";
LABEL_58:
        qdf_trace_msg(0x35u, 2u, v64, v41, v42, v43, v44, v45, v46, v47, v48, "lim_process_switch_channel_join_req");
        v78 = *(_QWORD *)(v27 + 128);
        if ( !v78 )
        {
LABEL_60:
          v79 = *(_QWORD *)(v27 + 112);
          if ( v79 )
          {
            _qdf_mem_free(v79);
            *(_QWORD *)(v27 + 112) = 0;
          }
          v80 = *(_BYTE *)(v27 + 8);
          LODWORD(v179) = 502;
          BYTE6(v179) = v80;
          WORD2(v179) = 1;
          goto LABEL_63;
        }
LABEL_59:
        _qdf_mem_free(v78);
        *(_QWORD *)(v27 + 128) = 0;
        goto LABEL_60;
      }
      v62 = *(_QWORD *)(v27 + 144);
      if ( v62 )
      {
        if ( v22 )
        {
          v63 = "%s: Change channel failed!!";
        }
        else
        {
          qdf_trace(53, 0xDu, *(_WORD *)(v27 + 8), 6);
          if ( !(unsigned int)tx_timer_activate((char *)(a1 + 544)) )
          {
LABEL_67:
            result = qdf_trace_msg(
                       0x35u,
                       8u,
                       "%s: updated session bandwidth: %d",
                       v41,
                       v42,
                       v43,
                       v44,
                       v45,
                       v46,
                       v47,
                       v48,
                       "lim_process_switch_channel_rsp",
                       *(unsigned int *)(v27 + 7176));
            goto LABEL_68;
          }
          v63 = "%s: could not start Reassociation failure timer";
        }
        qdf_trace_msg(0x35u, 2u, v63, v41, v42, v43, v44, v45, v46, v47, v48, "lim_process_switch_channel_re_assoc_req");
        _qdf_mem_free(v62);
        *(_QWORD *)(v27 + 144) = 0;
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: pLimMlmReassocReq does not exist for given switchChanSession",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "lim_process_switch_channel_re_assoc_req");
      }
      qdf_trace(53, 0xAu, 0, 1015);
      goto LABEL_67;
    }
    v31 = "%s: session does not exist for given sessionId";
  }
  else
  {
    v31 = "%s: Vdev start response is NULL";
  }
  result = qdf_trace_msg(0x35u, 2u, v31, v13, v14, v15, v16, v17, v18, v19, v20, "lim_process_switch_channel_rsp");
LABEL_68:
  _ReadStatusReg(SP_EL0);
  return result;
}
