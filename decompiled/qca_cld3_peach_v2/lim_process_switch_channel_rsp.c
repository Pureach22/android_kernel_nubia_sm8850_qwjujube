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
  _BYTE *v25; // x25
  int v26; // w23
  __int64 v27; // x19
  int v28; // w8
  unsigned __int16 *v29; // x24
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
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  __int64 v106; // x0
  int v107; // w21
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  __int64 v116; // x4
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  __int64 v125; // x0
  int v126; // w23
  __int64 v127; // x0
  char v128; // w9
  __int64 v129; // x5
  unsigned __int8 v130; // w8
  __int64 v131; // x9
  unsigned int v132; // w22
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  int v141; // w0
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  const char *v150; // x2
  char v151; // w9
  __int64 v152; // x0
  int v153; // w0
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  unsigned __int8 *v162; // x10
  __int64 v163; // x7
  int v164; // w8
  int v165; // w9
  int v166; // w10
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  double v175; // d0
  double v176; // d1
  double v177; // d2
  double v178; // d3
  double v179; // d4
  double v180; // d5
  double v181; // d6
  double v182; // d7
  char v183; // w9
  __int64 v184; // x0
  __int64 v185; // x0
  __int64 v186; // x0
  int v187; // w1
  double v188; // d0
  double v189; // d1
  double v190; // d2
  double v191; // d3
  double v192; // d4
  double v193; // d5
  double v194; // d6
  double v195; // d7
  __int64 v196; // x0
  __int64 v197; // x22
  unsigned __int64 v198; // x24
  __int64 v199; // x21
  __int64 v200; // x0
  int v201; // w1
  double v202; // d0
  double v203; // d1
  double v204; // d2
  double v205; // d3
  double v206; // d4
  double v207; // d5
  double v208; // d6
  double v209; // d7
  double v210; // d0
  double v211; // d1
  double v212; // d2
  double v213; // d3
  double v214; // d4
  double v215; // d5
  double v216; // d6
  double v217; // d7
  unsigned __int8 *v218; // x11
  int v219; // w8
  int v220; // w9
  int v221; // w10
  int v222; // w11
  const char *v223; // x2
  double v224; // d0
  double v225; // d1
  double v226; // d2
  double v227; // d3
  double v228; // d4
  double v229; // d5
  double v230; // d6
  double v231; // d7
  __int16 v232; // w2
  double updated; // d0
  __int64 v234; // x3
  double v235; // d1
  double v236; // d2
  double v237; // d3
  double v238; // d4
  double v239; // d5
  double v240; // d6
  double v241; // d7
  double v242; // d0
  double v243; // d1
  double v244; // d2
  double v245; // d3
  double v246; // d4
  double v247; // d5
  double v248; // d6
  double v249; // d7
  char v250; // w9
  double v251; // d0
  double v252; // d1
  double v253; // d2
  double v254; // d3
  double v255; // d4
  double v256; // d5
  double v257; // d6
  double v258; // d7
  __int64 v259; // [xsp+0h] [xbp-B0h]
  __int64 v260; // [xsp+8h] [xbp-A8h]
  __int64 v261; // [xsp+10h] [xbp-A0h]
  unsigned int v262; // [xsp+24h] [xbp-8Ch] BYREF
  __int64 v263; // [xsp+28h] [xbp-88h] BYREF
  __int64 v264; // [xsp+30h] [xbp-80h] BYREF
  __int64 v265; // [xsp+38h] [xbp-78h] BYREF
  __int64 v266; // [xsp+40h] [xbp-70h] BYREF
  __int64 v267; // [xsp+48h] [xbp-68h]
  __int64 v268; // [xsp+50h] [xbp-60h]
  __int64 v269; // [xsp+58h] [xbp-58h]
  __int64 v270; // [xsp+60h] [xbp-50h]
  __int64 v271; // [xsp+68h] [xbp-48h] BYREF
  __int64 v272; // [xsp+70h] [xbp-40h]
  __int64 v273; // [xsp+78h] [xbp-38h]
  __int64 v274; // [xsp+80h] [xbp-30h]
  __int64 v275; // [xsp+88h] [xbp-28h]
  __int64 v276; // [xsp+90h] [xbp-20h]
  int v277; // [xsp+98h] [xbp-18h] BYREF
  __int16 v278; // [xsp+9Ch] [xbp-14h]
  int v279; // [xsp+A0h] [xbp-10h] BYREF
  __int16 v280; // [xsp+A4h] [xbp-Ch]
  __int64 v281; // [xsp+A8h] [xbp-8h]

  v12 = a1 + 0x2000;
  v281 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)(a1 + 8888) = "lim_process_switch_channel_rsp";
  v262 = 0;
  *(_BYTE *)(a1 + 8885) = 1;
  qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", a3, a4, a5, a6, a7, a8, a9, a10);
  v21 = *(unsigned __int8 *)(v12 + 693);
  v275 = 0;
  v276 = 0;
  v273 = 0;
  v274 = 0;
  v271 = 0;
  v272 = 0;
  if ( v21 )
  {
    if ( *(_WORD *)(v12 + 496) )
    {
      LOWORD(v271) = 5119;
      if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)&v271) )
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
          (unsigned __int16)v271);
    }
  }
  if ( !a2 )
  {
    v31 = "%s: Vdev start response is NULL";
LABEL_12:
    result = qdf_trace_msg(0x35u, 2u, v31, v13, v14, v15, v16, v17, v18, v19, v20, "lim_process_switch_channel_rsp");
LABEL_70:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v22 = a2[2];
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)a2);
  if ( !session_by_vdev_id )
  {
    v31 = "%s: session does not exist for given sessionId";
    goto LABEL_12;
  }
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
        wlan_reg_get_cur_6g_ap_pwr_type(*(_QWORD *)(a1 + 21632), &v262, v41, v42, v43, v44, v45, v46, v47, v48);
        if ( !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v27 + 284))
          || v262 != 3
          || (lim_set_tpc_power(a1, v27, 0, 1),
              !policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(v27 + 10))) )
        {
          lim_set_tpc_power(a1, v27, 0, 0);
        }
      }
      lim_send_sme_ap_channel_switch_resp(a1, v27, a2);
      policy_mgr_ap_csa_end(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(v27 + 10), v22 != 0, 0);
      policy_mgr_update_connection_info(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(v27 + 10));
      lim_check_conc_power_for_csa(a1, v27);
      lim_post_csa_ocv_sa_query_check(a1, v27, v22 == 0);
      goto LABEL_69;
    }
    if ( v26 != 4 )
    {
      if ( v26 == 5 )
      {
        v49 = *(_DWORD *)(v27 + 92);
        v275 = 0;
        v276 = 0;
        v273 = 0;
        v274 = 0;
        v271 = 0;
        v272 = 0;
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
            LOWORD(v271) = 5281;
            HIDWORD(v271) = v81;
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
                                 (unsigned __int16 *)&v271,
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
        policy_mgr_update_connection_info(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(v27 + 10));
      }
      goto LABEL_69;
    }
    goto LABEL_29;
  }
  if ( !v26 )
  {
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
LABEL_69:
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
          goto LABEL_70;
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
    goto LABEL_69;
  }
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
    policy_mgr_update_connection_info(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(v27 + 10));
    wlan_cm_handle_sta_sta_roaming_enablement(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(v27 + 10));
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
    goto LABEL_69;
  }
  v263 = 0;
  if ( v22 )
  {
    v64 = "%s: Change channel failed!!";
LABEL_59:
    qdf_trace_msg(0x35u, 2u, v64, v41, v42, v43, v44, v45, v46, v47, v48, "lim_process_switch_channel_join_req");
LABEL_60:
    v78 = *(_QWORD *)(v27 + 128);
    if ( v78 )
    {
      _qdf_mem_free(v78);
      *(_QWORD *)(v27 + 128) = 0;
    }
    v79 = *(_QWORD *)(v27 + 112);
    if ( v79 )
    {
      _qdf_mem_free(v79);
      *(_QWORD *)(v27 + 112) = 0;
    }
    v80 = *(_BYTE *)(v27 + 8);
    LODWORD(v263) = 502;
    BYTE6(v263) = v80;
    WORD2(v263) = 1;
    goto LABEL_65;
  }
  if ( !*(_QWORD *)(v27 + 128) || (v65 = *(_QWORD *)(v27 + 112)) == 0 )
  {
    v64 = "%s: invalid pointer!!";
    goto LABEL_59;
  }
  v66 = *(_DWORD *)(v27 + 72);
  v67 = *(unsigned __int8 *)(v65 + 4597);
  *(_DWORD *)(v27 + 72) = 2;
  *(_DWORD *)(v27 + 76) = v66;
  lim_apply_configuration((_QWORD *)a1, v27, v41, v42, v43, v44, v45, v46, v47, v48);
  if ( (*(_BYTE *)(*(_QWORD *)(v27 + 16) + 60LL) & 2) != 0 )
  {
    if ( (mlo_roam_is_auth_status_connected(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(v27 + 10)) & 1) != 0 )
    {
      v271 = 0;
      v272 = 0;
      v280 = 0;
      v279 = 0;
      v266 = 0;
      v264 = 0;
      v278 = 0;
      v277 = 0;
      if ( !v25[3416] )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: MLO_ROAM: vdev:%d num_partner_links is 0",
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          v105,
          "lim_process_switch_channel_join_mlo_roam",
          *(unsigned __int8 *)(v27 + 10));
        goto LABEL_60;
      }
      v106 = *(_QWORD *)(v27 + 16);
      LODWORD(v271) = 0;
      mlo_get_assoc_rsp(v106, &v271);
      if ( !(_DWORD)v271 )
        goto LABEL_60;
      v265 = 0;
      qdf_mem_copy(&v279, (const void *)(v27 + 30), 6u);
      v107 = 2;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: vdev:%d sta_link_addr%02x:%02x:%02x:**:**:%02x",
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        "lim_process_switch_channel_join_mlo_roam",
        *(unsigned __int8 *)(v27 + 10),
        (unsigned __int8)v279,
        BYTE1(v279),
        BYTE2(v279),
        HIBYTE(v280));
      BYTE6(v265) = *(_BYTE *)(v27 + 8);
      qdf_trace(53, 0xAu, 0, 1005);
      lim_process_mlm_join_cnf(a1, (__int64)&v265);
      v116 = (unsigned int)v271;
      *(_DWORD *)(v27 + 80) = 5;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: MLO_ROAM: reassoc rsp len %d ",
        v117,
        v118,
        v119,
        v120,
        v121,
        v122,
        v123,
        v124,
        "lim_process_switch_channel_join_mlo_roam",
        v116);
      v125 = _qdf_mem_malloc((unsigned int)v271, "lim_process_switch_channel_join_mlo_roam", 3023);
      v267 = v125;
      if ( !v125 )
        goto LABEL_116;
      v126 = v125;
      v127 = *(_QWORD *)(v27 + 16);
      LODWORD(v266) = v271;
      *(_DWORD *)(v27 + 72) = 11;
      mlo_get_link_mac_addr_from_reassoc_rsp(v127, &v277);
      v128 = v277;
      v129 = *(unsigned __int8 *)(v27 + 10);
      *(_BYTE *)(v27 + 183) = BYTE1(v277);
      v130 = BYTE2(v277);
      *(_BYTE *)(v27 + 182) = v128;
      v131 = *(_QWORD *)(v27 + 16);
      *(_WORD *)(v27 + 184) = __PAIR16__(HIBYTE(v277), v130);
      *(_WORD *)(v27 + 186) = v278;
      v132 = *(unsigned __int8 *)(v131 + 93);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: MLO ROAM: Generate and process assoc rsp for link_id:%d vdev %d",
        v133,
        v134,
        v135,
        v136,
        v137,
        v138,
        v139,
        v140,
        "lim_process_switch_channel_join_mlo_roam",
        *(unsigned __int8 *)(v131 + 93),
        v129);
      v141 = util_gen_link_assoc_rsp(v272, v271, 1, v132, v279, v126, v271, (__int64)&v266);
      if ( v141 )
      {
        v107 = v141;
        v150 = "%s: MLO_ROAM: link vdev:%d link_id:%d assoc rsp generation failed";
LABEL_115:
        qdf_trace_msg(
          0x35u,
          2u,
          v150,
          v142,
          v143,
          v144,
          v145,
          v146,
          v147,
          v148,
          v149,
          "lim_process_switch_channel_join_mlo_roam",
          *(unsigned __int8 *)(v27 + 10),
          v132);
        mlo_free_cache_link_assoc_rsp(*(_QWORD *)(v27 + 16), v132);
        v250 = *(_BYTE *)(v27 + 8);
        LODWORD(v264) = 500;
        WORD2(v264) = 1;
        BYTE6(v264) = v250;
        qdf_trace(53, 0xAu, 0, 1010);
        lim_process_mlm_assoc_cnf(a1, (unsigned int *)&v264, v251, v252, v253, v254, v255, v256, v257, v258);
        _qdf_mem_free(v267);
LABEL_116:
        if ( v107 == 4 )
          goto LABEL_60;
LABEL_117:
        if ( v107 != 24 )
          lim_process_bcn_tpe_and_set_tpc(a1, v27);
        goto LABEL_69;
      }
      updated = mlo_update_cache_link_assoc_rsp(*(_QWORD *)(v27 + 16), v132, &v266);
      mgmt_txrx_frame_hex_dump(v267, v266, 0, v234, updated, v235, v236, v237, v238, v239, v240, v241);
      lim_process_assoc_rsp_frame(a1, v267, v266, 1u, v27, v242, v243, v244, v245, v246, v247, v248, v249);
      if ( (*(_BYTE *)(v27 + 13282) & 1) != 0 )
      {
        v107 = 4;
        v150 = "%s: MLO_ROAM: link vdev:%d link_id:%d assoc rsp process failed";
        goto LABEL_115;
      }
      _qdf_mem_free(v267);
LABEL_122:
      v107 = 0;
      goto LABEL_117;
    }
    if ( (wlan_cm_is_link_add_connecting(*(_QWORD *)(v27 + 16), v98, v99, v100, v101, v102, v103, v104, v105) & 1) == 0
      && (mlo_mgr_is_link_add_link_switch(*(_QWORD *)(v27 + 16)) & 1) == 0 )
    {
      v107 = lim_process_switch_channel_join_mlo(v27, a1);
      if ( v107 == 4 )
        goto LABEL_60;
      goto LABEL_117;
    }
    v151 = *(_BYTE *)(v27 + 8);
    v271 = 0;
    v266 = 0x1000001F4LL;
    BYTE6(v271) = v151;
    qdf_trace(53, 0xAu, 0, 1005);
    lim_process_mlm_join_cnf(a1, (__int64)&v271);
    v152 = *(_QWORD *)(v27 + 16);
    *(_DWORD *)(v27 + 72) = 10;
    *(_DWORD *)(v27 + 80) = 5;
    v153 = mlo_link_recfg_link_add_join_req(v152);
    if ( v153 )
    {
      if ( v153 == 24 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: vdev %d wait link_recfg rsp - no comm link",
          v154,
          v155,
          v156,
          v157,
          v158,
          v159,
          v160,
          v161,
          "lim_process_switch_channel_join_link_add",
          *(unsigned __int8 *)(*(_QWORD *)(v27 + 16) + 168LL));
        v107 = 24;
        goto LABEL_117;
      }
    }
    else if ( !(unsigned int)lim_mlo_link_recfg_add_process_assoc_rsp(a1, v27) )
    {
      goto LABEL_122;
    }
    BYTE6(v266) = *(_BYTE *)(v27 + 8);
    qdf_trace(53, 0xAu, 0, 1010);
    lim_process_mlm_assoc_cnf(a1, (unsigned int *)&v266, v167, v168, v169, v170, v171, v172, v173, v174);
    goto LABEL_60;
  }
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3534LL) != 1 )
    goto LABEL_93;
  v76 = (void *)(a1 + 3996);
  if ( (unsigned int)qdf_mem_cmp((const void *)(*(_QWORD *)(v27 + 128) + 6LL), (const void *)(a1 + 3996), 6u) )
  {
    v76 = (void *)(a1 + 4002);
    if ( (unsigned int)qdf_mem_cmp((const void *)(*(_QWORD *)(v27 + 128) + 6LL), (const void *)(a1 + 4002), 6u) )
      goto LABEL_93;
    v77 = 1;
  }
  else
  {
    v77 = 0;
  }
  v162 = *(unsigned __int8 **)(v27 + 128);
  if ( v162 == (unsigned __int8 *)-6LL )
  {
    v165 = 0;
    v163 = 0;
    v164 = 0;
    v166 = 0;
  }
  else
  {
    v163 = v162[6];
    v164 = v162[7];
    v165 = v162[8];
    v166 = v162[11];
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
    v163,
    v164,
    v165,
    v166);
  lim_send_deauth_mgmt_frame(a1, 1, *(_QWORD *)(v27 + 128) + 6LL, v27, 0);
  qdf_mem_set(v76, 6u, 0);
LABEL_93:
  if ( !v67 )
  {
    lim_deactivate_and_change_timer(a1, 18);
    *(_BYTE *)(a1 + 2186) = *(_BYTE *)(v27 + 8);
    v218 = *(unsigned __int8 **)(v27 + 128);
    if ( v218 == (unsigned __int8 *)-6LL )
    {
      v221 = 0;
      v219 = 0;
      v220 = 0;
      v222 = 0;
    }
    else
    {
      v219 = v218[6];
      v220 = v218[7];
      v221 = v218[8];
      v222 = v218[11];
    }
    LODWORD(v261) = v221;
    LODWORD(v260) = v220;
    LODWORD(v259) = v219;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: vdev %d Send Probe req on freq %d %.*s %02x:%02x:%02x:**:**:%02x",
      v210,
      v211,
      v212,
      v213,
      v214,
      v215,
      v216,
      v217,
      "lim_process_switch_channel_join_req",
      *(unsigned __int8 *)(v27 + 10),
      *(unsigned int *)(v27 + 284),
      *(unsigned __int8 *)(v27 + 36),
      v27 + 37,
      v259,
      v260,
      v261,
      v222);
    qdf_trace(53, 0xDu, *(_WORD *)(v27 + 8), 2);
    if ( (unsigned int)tx_timer_activate((char *)(a1 + 1072)) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: couldn't activate Join failure timer",
        v224,
        v225,
        v226,
        v227,
        v228,
        v229,
        v230,
        v231,
        "lim_process_switch_channel_join_req");
      v232 = *(_WORD *)(v27 + 8);
      *(_DWORD *)(v27 + 72) = *(_DWORD *)(v27 + 76);
      qdf_trace(53, 0, v232, *(_DWORD *)(a1 + 4020));
      goto LABEL_60;
    }
    lim_process_bcn_tpe_and_set_tpc(a1, v27);
    lim_send_probe_req_mgmt_frame(a1, v27, *(_QWORD *)(v27 + 112) + 260LL, *(_QWORD *)(v27 + 112) + 262LL);
    if ( !(unsigned int)tx_timer_activate((char *)(a1 + 2136)) )
    {
      ++*(_BYTE *)(v27 + 13283);
      goto LABEL_69;
    }
    v64 = "%s: Periodic JoinReq timer activate failed";
    goto LABEL_59;
  }
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
  v183 = *(_BYTE *)(v27 + 8);
  v274 = 0;
  v275 = 0;
  v272 = 0;
  v273 = 0;
  v184 = *(_QWORD *)(v27 + 16);
  LODWORD(v263) = 0;
  *(_DWORD *)(v27 + 72) = 3;
  BYTE6(v263) = v183;
  WORD2(v263) = 0;
  v271 = 0;
  if ( !v184 )
  {
    v223 = "%s: vdev:%d is NULL";
LABEL_120:
    qdf_trace_msg(
      0x35u,
      2u,
      v223,
      v175,
      v176,
      v177,
      v178,
      v179,
      v180,
      v181,
      v182,
      "lim_update_mlo_mgr_ap_link_info_mbssid_connect",
      *(unsigned __int8 *)(v27 + 10));
    goto LABEL_65;
  }
  if ( (wlan_vdev_mlme_is_mlo_vdev(v184, v175, v176, v177, v178, v179, v180, v181, v182) & 1) == 0 )
  {
LABEL_65:
    qdf_trace(53, 0xAu, 0, 1005);
    lim_process_mlm_join_cnf(a1, (__int64)&v263);
    goto LABEL_69;
  }
  if ( !*(_QWORD *)(v27 + 112) )
  {
    v223 = "%s: vdev:%d lim_join_req is NULL";
    goto LABEL_120;
  }
  v185 = *(_QWORD *)(v27 + 16);
  if ( !*(_QWORD *)(*(_QWORD *)(v185 + 1360) + 3880LL) )
  {
    v223 = "%s: vdev:%d MLO Link_ctx not found";
    goto LABEL_120;
  }
  LOWORD(v271) = *(_DWORD *)(v27 + 284);
  mlo_mgr_reset_ap_link_info(v185);
  v186 = *(_QWORD *)(v27 + 16);
  v268 = v273;
  v269 = v274;
  v187 = *(unsigned __int8 *)(v186 + 93);
  v270 = v275;
  v266 = v271;
  v267 = v272;
  mlo_mgr_update_ap_link_info(v186, v187, v27 + 24);
  v196 = lim_update_mlo_mgr_info(
           a1,
           *(_QWORD *)(v27 + 16),
           (unsigned __int8 *)(v27 + 24),
           *(unsigned __int8 *)(*(_QWORD *)(v27 + 16) + 93LL),
           v188,
           v189,
           v190,
           v191,
           v192,
           v193,
           v194,
           v195);
  v197 = *(_QWORD *)(v27 + 112);
  if ( !*(_BYTE *)(v197 + 4368) )
    goto LABEL_65;
  v198 = 0;
  v199 = v197 + 4376;
  while ( v198 != 4 )
  {
    qdf_mem_set(&v271, 0x28u, 0);
    v200 = *(_QWORD *)(v27 + 16);
    LOWORD(v271) = *(_WORD *)(v199 + 10);
    v201 = *(unsigned __int8 *)(v199 + 6);
    v268 = v273;
    v269 = v274;
    v270 = v275;
    v266 = v271;
    v267 = v272;
    mlo_mgr_update_ap_link_info(v200, v201, v199);
    v196 = lim_update_mlo_mgr_info(
             a1,
             *(_QWORD *)(v27 + 16),
             (unsigned __int8 *)v199,
             *(unsigned __int8 *)(v199 + 6),
             v202,
             v203,
             v204,
             v205,
             v206,
             v207,
             v208,
             v209);
    ++v198;
    v199 += 48;
    if ( v198 >= *(unsigned __int8 *)(v197 + 4368) )
      goto LABEL_65;
  }
  __break(0x5512u);
  return lim_send_beacon_ind(v196);
}
