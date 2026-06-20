__int64 __fastcall lim_process_sme_req_messages(__int64 a1, unsigned __int16 *a2)
{
  unsigned __int8 *v4; // x20
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const void *v22; // x1
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w21
  _BYTE *v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  _BYTE *v41; // x20
  _DWORD *v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  int v51; // w5
  __int64 v52; // x20
  unsigned int v53; // w0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x0
  __int64 v63; // x20
  __int64 v64; // x0
  __int64 v65; // x1
  char ready; // w19
  __int64 v67; // x0
  int v68; // w8
  int v69; // w9
  __int64 v70; // x21
  __int16 v71; // w9
  __int64 v72; // x0
  __int64 v73; // x21
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x0
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  __int64 v99; // x21
  __int64 ext_hdl; // x0
  unsigned int *v101; // x8
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  __int64 session_by_bssid; // x0
  __int64 v111; // x21
  const char *v112; // x2
  const char *v113; // x3
  __int64 v114; // x4
  __int64 v115; // x0
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  __int64 v124; // x1
  unsigned __int8 *v125; // x2
  const char *v126; // x2
  unsigned int v127; // w22
  __int64 session_by_vdev_id; // x0
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  __int64 v137; // x4
  __int64 v138; // x21
  __int64 v139; // x0
  unsigned int v140; // w1
  unsigned int v141; // w1
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  double v150; // d0
  double v151; // d1
  double v152; // d2
  double v153; // d3
  double v154; // d4
  double v155; // d5
  double v156; // d6
  double v157; // d7
  int v158; // w9
  char v159; // w8
  unsigned int v160; // w25
  double v161; // d0
  double v162; // d1
  double v163; // d2
  double v164; // d3
  double v165; // d4
  double v166; // d5
  double v167; // d6
  double v168; // d7
  unsigned __int8 v169; // w9
  int v170; // w8
  unsigned int v171; // w8
  int v172; // w9
  double v173; // d0
  double v174; // d1
  double v175; // d2
  double v176; // d3
  double v177; // d4
  double v178; // d5
  double v179; // d6
  double v180; // d7
  unsigned int v181; // w0
  double v182; // d0
  double v183; // d1
  double v184; // d2
  double v185; // d3
  double v186; // d4
  double v187; // d5
  double v188; // d6
  double v189; // d7
  unsigned int v190; // w22
  const char *v191; // x2
  __int64 v192; // x0
  const char *v193; // x2
  __int64 v194; // x8
  _DWORD *v195; // x0
  double v196; // d0
  double v197; // d1
  double v198; // d2
  double v199; // d3
  double v200; // d4
  double v201; // d5
  double v202; // d6
  double v203; // d7
  int v204; // w5
  __int64 v205; // x20
  unsigned int v206; // w0
  double v207; // d0
  double v208; // d1
  double v209; // d2
  double v210; // d3
  double v211; // d4
  double v212; // d5
  double v213; // d6
  double v214; // d7
  __int64 v215; // x0
  double v216; // d0
  double v217; // d1
  double v218; // d2
  double v219; // d3
  double v220; // d4
  double v221; // d5
  double v222; // d6
  double v223; // d7
  __int64 v224; // x1
  __int64 v225; // x21
  __int64 v226; // x4
  __int64 v227; // x5
  __int64 v228; // x6
  __int64 v229; // x7
  const char *v230; // x3
  _DWORD *v231; // x0
  __int16 v232; // w9
  const char *v233; // x3
  __int128 *v234; // x1
  __int64 v235; // x4
  __int64 v236; // x5
  const char *v237; // x2
  __int64 v238; // x6
  __int64 v239; // x7
  const char *v240; // x3
  const char *v241; // x2
  __int64 v242; // x0
  double v243; // d0
  double v244; // d1
  double v245; // d2
  double v246; // d3
  double v247; // d4
  double v248; // d5
  double v249; // d6
  double v250; // d7
  __int64 v251; // x0
  int v252; // w8
  __int64 v253; // x0
  unsigned int v254; // w0
  unsigned int v255; // w20
  unsigned __int8 v256; // w22
  _WORD *v257; // x26
  int v258; // w0
  __int16 v259; // w8
  unsigned __int64 v261; // x1
  _QWORD v262[3]; // [xsp+8h] [xbp-78h] BYREF
  __int64 v263; // [xsp+20h] [xbp-60h]
  __int64 v264; // [xsp+28h] [xbp-58h]
  __int64 v265; // [xsp+30h] [xbp-50h]
  __int64 v266; // [xsp+38h] [xbp-48h] BYREF
  int v267; // [xsp+40h] [xbp-40h]
  __int128 v268; // [xsp+48h] [xbp-38h] BYREF
  __int64 v269; // [xsp+58h] [xbp-28h]
  __int64 v270; // [xsp+60h] [xbp-20h]
  __int64 v271; // [xsp+68h] [xbp-18h]
  __int64 v272; // [xsp+70h] [xbp-10h]
  __int64 v273; // [xsp+78h] [xbp-8h]
  _QWORD vars0[2]; // [xsp+80h] [xbp+0h] BYREF

  v273 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((unsigned __int8 **)a2 + 1);
  v5 = lim_msg_str(*a2);
  qdf_trace_msg(0x35u, 8u, "Handle %s(0x%04X)", v6, v7, v8, v9, v10, v11, v12, v13, v5, *a2);
  switch ( *a2 )
  {
    case 0x13DCu:
      lim_process_sme_addts_rsp_timeout(a1, *((_DWORD *)a2 + 1));
      goto LABEL_189;
    case 0x1401u:
      ready = _lim_process_sme_sys_ready_ind(a1, v4);
      goto LABEL_190;
    case 0x1408u:
      lim_process_sme_disassoc_req(a1, a2);
      goto LABEL_189;
    case 0x140Bu:
    case 0x141Au:
      v22 = *((const void **)a2 + 1);
      v269 = 0;
      v268 = 0u;
      LOBYTE(v266) = 0;
      v262[0] = 0;
      qdf_mem_copy(&v268, v22, 0x18u);
      if ( pe_find_session_by_bssid(a1, (char *)&v268 + 12, &v266) )
      {
        _lim_process_sme_disassoc_cnf(a1, *((const void **)a2 + 1));
      }
      else
      {
        if ( vars0 == (__int64 *)((char *)&qword_28 + 4) )
          v226 = 0;
        else
          v226 = BYTE12(v268);
        if ( vars0 == (__int64 *)((char *)&qword_28 + 4) )
          v227 = 0;
        else
          v227 = BYTE13(v268);
        if ( vars0 == (__int64 *)((char *)&qword_28 + 4) )
          v228 = 0;
        else
          v228 = BYTE14(v268);
        if ( vars0 == (__int64 *)((char *)&qword_28 + 4) )
          v229 = 0;
        else
          v229 = BYTE1(v269);
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: session not found for bssid:%02x:%02x:%02x:**:**:%02x",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "lim_process_sme_disassoc_cnf",
          v226,
          v227,
          v228,
          v229);
        if ( !(unsigned int)lim_prepare_disconnect_done_ind(a1, v262, BYTE4(v268), 541, 0) )
          lim_send_sme_disassoc_deauth_ntf(a1, 0, v262[0]);
      }
      goto LABEL_189;
    case 0x140Cu:
      lim_process_sme_deauth_req(a1, a2);
      goto LABEL_189;
    case 0x1413u:
      _lim_process_sme_start_bss_req(a1, a2);
      goto LABEL_189;
    case 0x1416u:
      _lim_process_sme_assoc_cnf_new(a1, 0x1416u, v4, v14, v15, v16, v17, v18, v19, v20, v21);
      goto LABEL_189;
    case 0x1418u:
      _lim_process_sme_stop_bss_req(a1, a2);
      goto LABEL_189;
    case 0x141Cu:
      _lim_process_sme_addts_req(a1, v4);
      goto LABEL_189;
    case 0x141Eu:
      _lim_process_sme_delts_req(a1, v4);
      goto LABEL_189;
    case 0x1421u:
      WORD2(v268) = 0;
      LODWORD(v268) = 0;
      LOBYTE(v262[0]) = 0;
      if ( v4 )
      {
        session_by_bssid = pe_find_session_by_bssid(a1, v4 + 1, v262);
        if ( !session_by_bssid )
        {
          v235 = v4[1];
          v236 = v4[2];
          v237 = "%s: Session Does not exist for bssid: %02x:%02x:%02x:**:**:%02x";
          v238 = v4[3];
          v239 = v4[6];
          v240 = "__lim_process_sme_mscs_req";
          goto LABEL_152;
        }
        if ( *(_DWORD *)(session_by_bssid + 88) == 2 )
        {
          v111 = session_by_bssid;
          if ( (unsigned int)wlan_vdev_mlme_is_active(*(_QWORD *)(session_by_bssid + 16)) )
          {
            v112 = "%s: mscs req in unexpected vdev SM state:%d";
            v113 = "__lim_process_sme_mscs_req";
            v114 = *(unsigned int *)(*(_QWORD *)(v111 + 16) + 20LL);
            goto LABEL_156;
          }
          if ( v4[48] == 1 )
          {
            v193 = "%s: MSCS req already sent";
            goto LABEL_163;
          }
          qdf_mem_copy(&v268, (const void *)(v111 + 24), 6u);
          v261 = (unsigned int)v268 | ((unsigned __int64)WORD2(v268) << 32);
          v4[48] = 1;
          lim_send_mscs_req_action_frame(a1, v261, v4, v111);
          goto LABEL_189;
        }
        v193 = "%s: MSCS req received on AP - ignoring";
      }
      else
      {
        v193 = "%s: Buffer is Pointing to NULL";
      }
LABEL_163:
      v233 = "__lim_process_sme_mscs_req";
      goto LABEL_164;
    case 0x1427u:
      _lim_process_sme_session_update(a1, v4);
      goto LABEL_189;
    case 0x1428u:
      LOBYTE(v262[0]) = 0;
      LODWORD(v270) = 0;
      v269 = 0;
      v268 = 0u;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: received Update Beacon Interval message",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "__lim_process_sme_change_bi");
      if ( v4 )
      {
        qdf_mem_set(&v268, 0x1Cu, 0);
        v67 = pe_find_session_by_bssid(a1, v4 + 6, v262);
        if ( v67 )
        {
          v68 = *(unsigned __int16 *)(v67 + 7158);
          v69 = *((unsigned __int16 *)v4 + 2);
          if ( v68 != v69 )
          {
            *(_WORD *)(v67 + 7158) = v69;
            v68 = *((unsigned __int16 *)v4 + 2);
          }
          if ( *(unsigned __int16 *)(a1 + 12448) != v68 )
          {
            *(_WORD *)(a1 + 12448) = v68;
            v70 = v67;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: LIM send update BeaconInterval Indication: %d",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "__lim_process_sme_change_bi",
              *((unsigned __int16 *)v4 + 2));
            if ( !*(_BYTE *)(a1 + 14881) )
            {
              sch_set_fixed_beacon_fields(a1, v70);
              v71 = *((_WORD *)v4 + 2);
              LOBYTE(v268) = *(_BYTE *)(v70 + 10);
              WORD2(v268) = v71;
              HIWORD(v268) = 1;
              lim_send_beacon_params(a1, &v268, v70);
            }
          }
          goto LABEL_189;
        }
        v193 = "%s: Session does not exist for given BSSID";
      }
      else
      {
        v193 = "%s: Buffer is Pointing to NULL";
      }
      v233 = "__lim_process_sme_change_bi";
      goto LABEL_164;
    case 0x142Bu:
      rrm_process_neighbor_report_req(a1, *((_QWORD *)a2 + 1));
      goto LABEL_189;
    case 0x142Eu:
      rrm_process_beacon_report_xmit(a1, *((_QWORD *)a2 + 1));
      goto LABEL_189;
    case 0x1430u:
      rrm_process_chan_load_report_xmit(a1, *((_QWORD *)a2 + 1));
      goto LABEL_189;
    case 0x1431u:
      v271 = 0;
      v272 = 0;
      v269 = 0;
      v270 = 0;
      v268 = 0u;
      memset((char *)v262 + 4, 0, 20);
      if ( !v4 )
      {
        v193 = "%s: Buffer is Pointing to NULL";
        v233 = "lim_process_sap_ch_width_update";
        goto LABEL_164;
      }
      v127 = v4[8];
      session_by_vdev_id = pe_find_session_by_vdev_id(a1, v4[8]);
      if ( session_by_vdev_id )
      {
        v137 = *(unsigned int *)(session_by_vdev_id + 7036);
        v138 = session_by_vdev_id;
        if ( ((unsigned int)v137 | 2) == 3 )
        {
          v139 = *(_QWORD *)(a1 + 21632);
          v140 = *(_DWORD *)(v138 + 284);
          LODWORD(v262[0]) = *((_DWORD *)v4 + 1);
          wlan_reg_set_channel_params_for_pwrmode(
            v139,
            v140,
            0,
            (__int64)v262,
            0,
            v129,
            v130,
            v131,
            v132,
            v133,
            v134,
            v135,
            v136);
          v141 = *(_DWORD *)(v138 + 284);
          *(_BYTE *)(v138 + 7218) = 1;
          *(_DWORD *)(v138 + 7204) = v141;
          *(_BYTE *)(v138 + 7208) = wlan_reg_freq_to_chan(
                                      *(_QWORD *)(a1 + 21632),
                                      v141,
                                      v142,
                                      v143,
                                      v144,
                                      v145,
                                      v146,
                                      v147,
                                      v148,
                                      v149);
          v158 = *((_DWORD *)v4 + 1);
          *(_BYTE *)(v138 + 7209) = BYTE5(v262[0]);
          v159 = BYTE6(v262[0]);
          *(_DWORD *)(v138 + 7212) = v158;
          *(_BYTE *)(v138 + 7210) = v159;
          v160 = *((_DWORD *)v4 + 1);
          if ( v160 >= 3 && (unsigned int)wma_get_vht_ch_width() < 2 )
            v160 = 2;
          *(_DWORD *)(v138 + 7228) = v160;
          wlan_mlme_set_ap_oper_ch_width(
            *(_QWORD *)(v138 + 16),
            *((_DWORD *)v4 + 1),
            v150,
            v151,
            v152,
            v153,
            v154,
            v155,
            v156,
            v157);
          send_extended_chan_switch_action_frame(a1, *(unsigned int *)(v138 + 284), *((unsigned int *)v4 + 1));
          v169 = v4[4];
          v170 = *(unsigned __int8 *)(v138 + 7172);
          *(_BYTE *)(v138 + 7171) = 1;
          v171 = v170 & 0xFFFFFFF0 | v169 & 0xF;
          v172 = *(unsigned __int8 *)(v138 + 8635);
          *(_BYTE *)(v138 + 7172) = v171;
          if ( v172 )
          {
            v171 = v171 & 0xFFFFFF8F | (16 * (((unsigned int)(16 * v172 + 112) >> 4) & 7));
            *(_BYTE *)(v138 + 7172) = v171;
          }
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: ch width %d nss %d",
            v161,
            v162,
            v163,
            v164,
            v165,
            v166,
            v167,
            v168,
            "lim_update_bcn_with_new_ch_width",
            v171 & 0xF,
            (v171 >> 4) & 7);
          *(_BYTE *)(v138 + 7284) = 1;
          if ( (unsigned int)qdf_mc_timer_start(v138 + 8232, 0xC8u) )
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: cannot start ap_ecsa_timer",
              v173,
              v174,
              v175,
              v176,
              v177,
              v178,
              v179,
              v180,
              "lim_update_bcn_with_new_ch_width");
          v181 = sch_set_fixed_beacon_fields(a1, v138);
          if ( v181 )
          {
            v190 = v181;
            v191 = "%s: Unable to set op mode IE in beacon";
          }
          else
          {
            v254 = lim_send_beacon_ind(a1, v138, 8u, v182, v183, v184, v185, v186, v187, v188, v189);
            if ( !v254 )
              goto LABEL_179;
            v190 = v254;
            v191 = "%s: Unable to send beacon";
          }
          qdf_trace_msg(
            0x35u,
            2u,
            v191,
            v182,
            v183,
            v184,
            v185,
            v186,
            v187,
            v188,
            v189,
            "lim_update_bcn_with_new_ch_width");
          lim_nss_or_ch_width_update_rsp(a1, *(unsigned __int8 *)(v138 + 10), v190, 8);
LABEL_179:
          v255 = *((_DWORD *)v4 + 1);
          v256 = 0;
          v267 = 0;
          v266 = 0;
          do
          {
            v257 = (_WORD *)(*(_QWORD *)(v138 + 368) + 1272LL * v256);
            if ( v257 && (*v257 & 8) != 0 )
            {
              v258 = lim_calculate_peer_ch_width(v138, v257 + 175, v255);
              v259 = *(unsigned __int8 *)(v138 + 10);
              LODWORD(v266) = v258;
              WORD2(v266) = v259;
              qdf_mem_copy((char *)&v266 + 6, v257 + 175, 6u);
              lim_send_mode_update(a1, &v266, v138);
            }
            ++v256;
          }
          while ( *(unsigned __int8 *)(a1 + 12272) >= (unsigned int)v256 );
          goto LABEL_189;
        }
        v241 = "%s: Invalid opmode %d";
      }
      else
      {
        v137 = *((unsigned int *)v4 + 2);
        v241 = "%s: vdev %d session not found";
      }
      qdf_trace_msg(
        0x35u,
        2u,
        v241,
        v129,
        v130,
        v131,
        v132,
        v133,
        v134,
        v135,
        v136,
        "lim_process_sap_ch_width_update",
        v137);
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: vdev %d: send bandwidth update fail",
        v243,
        v244,
        v245,
        v246,
        v247,
        v248,
        v249,
        v250,
        "lim_process_sap_ch_width_update",
        v127);
      v251 = _qdf_mem_malloc(0xCu, "lim_process_sap_ch_width_update", 9958);
      if ( v251 )
      {
        *(_BYTE *)v251 = -1;
        *(_QWORD *)(v251 + 4) = 0x1000000008LL;
      }
      v234 = &v268;
      *((_QWORD *)&v268 + 1) = v251;
      LOWORD(v268) = 5170;
      DWORD1(v268) = 0;
LABEL_171:
      sys_process_mmh_msg(a1, v234);
      goto LABEL_189;
    case 0x1434u:
      lim_process_ft_aggr_qos_req(a1, (__int64)v4);
      goto LABEL_189;
    case 0x1437u:
      _lim_process_sme_register_mgmt_frame_req(a1, v4);
      goto LABEL_189;
    case 0x143Au:
      lim_process_sme_tdls_mgmt_send_req(a1, v4);
      goto LABEL_189;
    case 0x143Cu:
      ((void (__fastcall *)(__int64, unsigned __int8 *))lim_process_sme_tdls_add_sta_req)(a1, v4);
      goto LABEL_189;
    case 0x143Eu:
      lim_process_sme_tdls_del_sta_req(a1, v4);
      goto LABEL_189;
    case 0x1450u:
      v271 = 0;
      v272 = 0;
      v269 = 0;
      v270 = 0;
      *(_QWORD *)&v268 = 4260;
      *((_QWORD *)&v268 + 1) = v4;
      mac_trace_msg_tx(a1, 255, 4260);
      if ( (unsigned int)wma_post_ctrl_msg(a1, &v268) )
      {
        _qdf_mem_free((__int64)v4);
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Unable to forward request",
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          "__lim_process_sme_get_tsm_stats_request");
      }
      ready = 0;
      goto LABEL_190;
    case 0x1454u:
      lim_process_sme_channel_change_request(a1, v4);
      goto LABEL_189;
    case 0x1456u:
      LOBYTE(v268) = 0;
      if ( v4 )
      {
        v72 = pe_find_session_by_bssid(a1, v4 + 5, &v268);
        if ( !v72 )
        {
          v235 = v4[5];
          v236 = v4[6];
          v237 = "%s: Session does not exist for given bssId: %02x:%02x:%02x:**:**:%02x";
          v238 = v4[7];
          v239 = v4[10];
          v240 = "lim_process_sme_start_beacon_req";
LABEL_152:
          qdf_trace_msg(0x35u, 2u, v237, v14, v15, v16, v17, v18, v19, v20, v21, v240, v235, v236, v238, v239);
          goto LABEL_189;
        }
        if ( v4[4] == 1 )
        {
          v73 = v72;
          lim_apply_configuration((_QWORD *)a1, v72, v14, v15, v16, v17, v18, v19, v20, v21);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Start Beacon with ssid %.*s Ch freq %d",
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            "lim_process_sme_start_beacon_req",
            *(unsigned __int8 *)(v73 + 36),
            v73 + 37,
            *(unsigned int *)(v73 + 284));
          lim_send_beacon(a1, v73);
          lim_enable_obss_detection_config(a1, v73);
          lim_send_obss_color_collision_cfg(a1, v73, 1);
          goto LABEL_189;
        }
        v193 = "%s: Invalid Beacon Start Indication";
      }
      else
      {
        v193 = "%s: Buffer is Pointing to NULL";
      }
      v233 = "lim_process_sme_start_beacon_req";
      goto LABEL_164;
    case 0x1457u:
      lim_process_sme_dfs_csa_ie_request(a1, v4);
      goto LABEL_189;
    case 0x145Du:
      lim_process_update_add_ies(a1, v4);
      goto LABEL_189;
    case 0x145Eu:
      lim_process_modify_add_ies(a1, v4);
      goto LABEL_189;
    case 0x1460u:
      _lim_process_sme_set_ht2040_mode(a1, v4);
      goto LABEL_189;
    case 0x1469u:
      lim_process_set_hw_mode(a1, v4);
      goto LABEL_189;
    case 0x146Cu:
      lim_process_nss_update_request(a1, v4);
      goto LABEL_189;
    case 0x1473u:
      v271 = 0;
      v272 = 0;
      v269 = 0;
      v270 = 0;
      v268 = 0u;
      v264 = 0;
      v265 = 0;
      v263 = 0;
      memset(v262, 0, sizeof(v262));
      if ( v4 )
      {
        v195 = (_DWORD *)_qdf_mem_malloc(0x18u, "lim_process_set_dual_mac_cfg_req", 255);
        if ( v195 )
        {
          *v195 = *((_DWORD *)v4 + 2);
          v204 = *((_DWORD *)v4 + 3);
          v205 = (__int64)v195;
          LOWORD(v268) = 4282;
          v195[1] = v204;
          *((_QWORD *)&v268 + 1) = v195;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Post SIR_HAL_PDEV_DUAL_MAC_CFG_REQ to WMA: %x %x",
            v196,
            v197,
            v198,
            v199,
            v200,
            v201,
            v202,
            v203,
            "lim_process_set_dual_mac_cfg_req");
          v206 = scheduler_post_message_debug(
                   0x35u,
                   0x36u,
                   54,
                   (unsigned __int16 *)&v268,
                   0x110u,
                   (__int64)"lim_process_set_dual_mac_cfg_req");
          if ( !v206 )
            goto LABEL_189;
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: scheduler_post_msg failed!(err=%d)",
            v207,
            v208,
            v209,
            v210,
            v211,
            v212,
            v213,
            v214,
            "lim_process_set_dual_mac_cfg_req",
            v206);
          _qdf_mem_free(v205);
        }
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Set Dual mac config is NULL",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "lim_process_set_dual_mac_cfg_req");
      }
      v231 = (_DWORD *)_qdf_mem_malloc(4u, "lim_process_set_dual_mac_cfg_req", 281);
      if ( !v231 )
        goto LABEL_189;
      v232 = 5236;
      goto LABEL_143;
    case 0x1476u:
      LOBYTE(v269) = 0;
      v268 = 0u;
      if ( !v4 )
      {
        v193 = "%s: Buffer is Pointing to NULL";
        v233 = "lim_process_set_ie_req";
        goto LABEL_164;
      }
      v90 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              *(_QWORD *)(a1 + 21624),
              v4[4],
              11);
      if ( v90 )
      {
        v99 = v90;
        ext_hdl = wlan_vdev_mlme_get_ext_hdl(v90, v91, v92, v93, v94, v95, v96, v97, v98);
        if ( ext_hdl )
        {
          if ( *(_BYTE *)(ext_hdl + 24227) )
          {
            lim_update_extcap_struct(a1, ext_hdl + 24227, &v268);
            if ( (*(_DWORD *)((_BYTE *)&v268 + 2) & 0x80000000) != 0 )
              *(_QWORD *)((char *)&v268 + 2) |= 0x100000000uLL;
            BYTE1(v268) = lim_compute_ext_cap_ie_length(&v268);
          }
          if ( (unsigned int)lim_send_ext_cap_ie(a1, v4[4], &v268, 1) )
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Unable to send ExtCap to FW",
              v102,
              v103,
              v104,
              v105,
              v106,
              v107,
              v108,
              v109,
              "lim_process_set_ie_req");
        }
        wlan_objmgr_vdev_release_ref(v99, 0xBu, v101, v102, v103, v104, v105, v106, v107, v108, v109);
      }
      goto LABEL_189;
    case 0x1477u:
      if ( !v4 )
      {
        v193 = "%s: Buffer is Pointing to NULL";
        goto LABEL_138;
      }
      v192 = pe_find_session_by_vdev_id(a1, v4[8]);
      if ( !v192 )
      {
        v114 = v4[8];
        v112 = "%s: Session not found for given vdev_id %d";
        v113 = "lim_process_ext_change_channel";
LABEL_156:
        qdf_trace_msg(0x35u, 2u, v112, v14, v15, v16, v17, v18, v19, v20, v21, v113, v114);
        goto LABEL_189;
      }
      if ( *(_DWORD *)(v192 + 88) == 1 )
      {
        v193 = "%s: not an STA/CLI session";
LABEL_138:
        v233 = "lim_process_ext_change_channel";
        goto LABEL_164;
      }
      *(_BYTE *)(v192 + 7211) = 0;
      send_extended_chan_switch_action_frame(a1, *((unsigned int *)v4 + 1), 0);
      goto LABEL_189;
    case 0x1479u:
      if ( v4 )
      {
        v194 = *((_QWORD *)v4 + 1);
        if ( v194 )
        {
          *(_QWORD *)(a1 + 21608) = v194;
          goto LABEL_189;
        }
        v193 = "%s: sme_req->callback is null";
      }
      else
      {
        v193 = "%s: msg_buf is null";
      }
      v233 = "lim_register_mgmt_frame_ind_cb";
      goto LABEL_164;
    case 0x147Bu:
      v271 = 0;
      v272 = 0;
      v269 = 0;
      v270 = 0;
      v268 = 0u;
      v264 = 0;
      v265 = 0;
      v263 = 0;
      memset(v262, 0, sizeof(v262));
      if ( v4 )
      {
        v42 = (_DWORD *)_qdf_mem_malloc(0x18u, "lim_process_set_antenna_mode_req", 334);
        if ( v42 )
        {
          v42[1] = *((_DWORD *)v4 + 3);
          v51 = *((_DWORD *)v4 + 2);
          v52 = (__int64)v42;
          *v42 = v51;
          *((_QWORD *)&v268 + 1) = v42;
          LOWORD(v268) = 4248;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Post SIR_HAL_SOC_ANTENNA_MODE_REQ to WMA: %d %d",
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            "lim_process_set_antenna_mode_req");
          v53 = scheduler_post_message_debug(
                  0x35u,
                  0x36u,
                  54,
                  (unsigned __int16 *)&v268,
                  0x15Fu,
                  (__int64)"lim_process_set_antenna_mode_req");
          if ( !v53 )
            goto LABEL_189;
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: scheduler_post_msg failed!(err=%d)",
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            "lim_process_set_antenna_mode_req",
            v53);
          _qdf_mem_free(v52);
        }
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Set antenna mode is NULL",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "lim_process_set_antenna_mode_req");
      }
      v231 = (_DWORD *)_qdf_mem_malloc(4u, "lim_process_set_antenna_mode_req", 360);
      if ( !v231 )
        goto LABEL_189;
      v232 = 5244;
LABEL_143:
      *v231 = 2;
      v234 = (__int128 *)v262;
      LOWORD(v262[0]) = v232;
      v262[1] = v231;
      HIDWORD(v262[0]) = 0;
      goto LABEL_171;
    case 0x147Fu:
      lim_process_set_pdev_IEs(a1, v4);
      goto LABEL_189;
    case 0x1480u:
      lim_process_set_vdev_ies_per_band(a1, v4);
      goto LABEL_189;
    case 0x1481u:
      _lim_process_send_disassoc_frame(a1, v4);
      goto LABEL_189;
    case 0x1482u:
      lim_process_sme_update_access_policy_vendor_ie(a1, v4);
      goto LABEL_189;
    case 0x148Bu:
      lim_process_sme_update_config(a1, v4);
      goto LABEL_189;
    case 0x1491u:
      lim_process_sme_set_addba_accept(a1, v4);
      goto LABEL_189;
    case 0x1492u:
      v31 = *((_DWORD *)a2 + 1);
      v32 = (_BYTE *)pe_find_session_by_vdev_id(a1, v31);
      if ( !v32 )
      {
        v230 = "lim_process_sme_update_active_edca_params";
        goto LABEL_130;
      }
      v41 = v32;
      v32[7140] = *(_BYTE *)(a1 + 21697);
      v32[7145] = *(_BYTE *)(a1 + 21698);
      v32[7150] = *(_BYTE *)(a1 + 21699);
      v32[7155] = *(_BYTE *)(a1 + 21700);
      if ( dph_get_hash_entry(a1, 1u, (__int64)(v32 + 360)) )
      {
        lim_send_edca_params(a1, v41 + 7136, (unsigned __int8)v41[10], 0);
        goto LABEL_189;
      }
      v193 = "%s: Self entry missing in Hash Table";
      v233 = "lim_process_sme_update_active_edca_params";
      goto LABEL_164;
    case 0x1493u:
      v31 = *((_DWORD *)a2 + 1);
      v62 = pe_find_session_by_vdev_id(a1, v31);
      if ( !v62 )
      {
        v230 = "lim_process_sme_update_mu_edca_params";
LABEL_130:
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Session does not exist: vdev_id %d",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v230,
          v31);
        goto LABEL_189;
      }
      v63 = v62;
      if ( dph_get_hash_entry(a1, 1u, v62 + 360) )
      {
        v64 = a1;
        v65 = a1 + 21753;
        ready = 1;
        lim_send_edca_params(v64, v65, *(unsigned __int8 *)(v63 + 10), 1);
        goto LABEL_190;
      }
      v193 = "%s: Self entry missing in Hash Table";
      v233 = "lim_process_sme_update_mu_edca_params";
      goto LABEL_164;
    case 0x1496u:
      lim_process_sme_cfg_action_frm_in_tb_ppdu(a1, v4);
      goto LABEL_189;
    case 0x14A2u:
      lim_process_sme_update_session_edca_txq_params(a1, v4);
      goto LABEL_189;
    case 0x14B4u:
      if ( !v4 )
      {
        v193 = "%s: Buffer is NULL";
        goto LABEL_145;
      }
      v215 = pe_find_session_by_vdev_id(a1, *v4);
      if ( !v215 )
      {
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: Session does not exist for given BSSID",
          v216,
          v217,
          v218,
          v219,
          v220,
          v221,
          v222,
          v223,
          "lim_process_sme_send_vdev_pause");
LABEL_189:
        ready = 1;
        goto LABEL_190;
      }
      v224 = *(_QWORD *)(v215 + 16);
      if ( *(_DWORD *)(v224 + 16) )
      {
        v225 = v215;
        if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(v215 + 16), v216, v217, v218, v219, v220, v221, v222, v223) & 1) != 0 )
        {
          v193 = "%s: vdev is not ML STA";
LABEL_145:
          v233 = "lim_process_sme_send_vdev_pause";
          goto LABEL_164;
        }
        v224 = *(_QWORD *)(v225 + 16);
        v215 = v225;
      }
      v252 = *(unsigned __int16 *)(v215 + 7158);
      v253 = *(_QWORD *)(a1 + 21624);
      ready = 1;
      wlan_mlo_send_vdev_pause(v253, v224, *v4, v252 * (unsigned int)v4[1], 1);
LABEL_190:
      _ReadStatusReg(SP_EL0);
      return ready & 1;
    case 0x14B5u:
      if ( !v4 )
      {
        v193 = "%s: msg_buf is NULL";
        v233 = "lim_process_update_rnr_ies";
LABEL_164:
        qdf_trace_msg(0x35u, 2u, v193, v14, v15, v16, v17, v18, v19, v20, v21, v233);
        goto LABEL_189;
      }
      v115 = pe_find_session_by_vdev_id(a1, v4[8]);
      if ( v115 )
      {
        v124 = v115;
        if ( *((_WORD *)v4 + 5) )
        {
          v125 = *((unsigned __int8 **)v4 + 2);
          if ( *v125 != 201 )
          {
            v126 = "%s: EID: %d is not rnr";
            goto LABEL_173;
          }
          if ( v125[1] <= 1u )
          {
            v126 = "%s: invalid RNR IE len: %d ";
LABEL_173:
            qdf_trace_msg(0x35u, 8u, v126, v116, v117, v118, v119, v120, v121, v122, v123, "lim_process_update_rnr_ies");
LABEL_188:
            _qdf_mem_free(*((_QWORD *)v4 + 2));
            *((_QWORD *)v4 + 2) = 0;
            goto LABEL_189;
          }
          v242 = a1;
        }
        else
        {
          v242 = a1;
          v125 = nullptr;
        }
        lim_populate_rnr_entry(v242, v124, v125);
        goto LABEL_188;
      }
      v126 = "%s: Session not found for given vdev id %d";
      goto LABEL_173;
    default:
      _qdf_mem_free(*((_QWORD *)a2 + 1));
      *((_QWORD *)a2 + 1) = 0;
      goto LABEL_189;
  }
}
