__int64 __fastcall lim_process_sme_req_messages(__int64 a1, unsigned __int16 *a2)
{
  unsigned int *v4; // x20
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
  char ready; // w21
  const void *v23; // x1
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  unsigned int v33; // w21
  _BYTE *v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  _BYTE *v43; // x20
  unsigned int v44; // w22
  __int64 session_by_vdev_id; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x4
  __int64 v55; // x21
  __int64 v56; // x0
  unsigned int v57; // w1
  unsigned int v58; // w1
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
  unsigned int v76; // w9
  char v77; // w8
  unsigned int v78; // w25
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  unsigned __int8 v87; // w9
  int v88; // w8
  unsigned int v89; // w8
  int v90; // w9
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  unsigned int v99; // w0
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  unsigned int v108; // w22
  const char *v109; // x2
  _DWORD *v110; // x0
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  unsigned int v119; // w5
  __int64 v120; // x20
  unsigned int v121; // w0
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  __int64 session_by_bssid; // x0
  __int64 v131; // x21
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  __int64 v140; // x0
  __int64 v141; // x20
  __int64 v142; // x0
  int v143; // w8
  int v144; // w9
  __int64 v145; // x21
  __int16 v146; // w9
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  _DWORD *v155; // x0
  double v156; // d0
  double v157; // d1
  double v158; // d2
  double v159; // d3
  double v160; // d4
  double v161; // d5
  double v162; // d6
  double v163; // d7
  unsigned int v164; // w5
  __int64 v165; // x20
  unsigned int v166; // w0
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  __int64 v175; // x0
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  __int64 v184; // x21
  __int64 ext_hdl; // x0
  unsigned int *v186; // x8
  double v187; // d0
  double v188; // d1
  double v189; // d2
  double v190; // d3
  double v191; // d4
  double v192; // d5
  double v193; // d6
  double v194; // d7
  __int64 v195; // x0
  __int64 v196; // x21
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  __int64 v205; // x0
  const char *v206; // x2
  __int64 v207; // x4
  __int64 v208; // x5
  __int64 v209; // x6
  __int64 v210; // x7
  const char *v211; // x3
  const char *v212; // x2
  const char *v213; // x3
  _DWORD *v214; // x0
  __int16 v215; // w9
  const char *v216; // x3
  __int128 *v217; // x1
  const char *v218; // x2
  __int64 v219; // x4
  __int64 v220; // x5
  const char *v221; // x2
  __int64 v222; // x6
  __int64 v223; // x7
  const char *v224; // x3
  double v225; // d0
  double v226; // d1
  double v227; // d2
  double v228; // d3
  double v229; // d4
  double v230; // d5
  double v231; // d6
  double v232; // d7
  __int64 v233; // x0
  unsigned int v235; // w0
  unsigned int v236; // w20
  unsigned __int8 v237; // w22
  _WORD *v238; // x26
  int v239; // w0
  __int16 v240; // w8
  unsigned __int64 v241; // x1
  __int128 v242; // [xsp+8h] [xbp-78h] BYREF
  __int64 v243; // [xsp+18h] [xbp-68h]
  __int64 v244; // [xsp+20h] [xbp-60h]
  __int64 v245; // [xsp+28h] [xbp-58h]
  __int64 v246; // [xsp+30h] [xbp-50h]
  __int64 v247; // [xsp+38h] [xbp-48h] BYREF
  int v248; // [xsp+40h] [xbp-40h]
  __int128 v249; // [xsp+48h] [xbp-38h] BYREF
  __int64 v250; // [xsp+58h] [xbp-28h]
  __int64 v251; // [xsp+60h] [xbp-20h]
  __int64 v252; // [xsp+68h] [xbp-18h]
  __int64 v253; // [xsp+70h] [xbp-10h]
  __int64 v254; // [xsp+78h] [xbp-8h]
  _QWORD vars0[2]; // [xsp+80h] [xbp+0h] BYREF

  v254 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((unsigned int **)a2 + 1);
  v5 = lim_msg_str(*a2);
  qdf_trace_msg(0x35u, 8u, "Handle %s(0x%04X)", v6, v7, v8, v9, v10, v11, v12, v13, v5, *a2);
  ready = 1;
  switch ( *a2 )
  {
    case 0x13DCu:
      lim_process_sme_addts_rsp_timeout(a1, *((_DWORD *)a2 + 1));
      goto LABEL_160;
    case 0x1401u:
      ready = _lim_process_sme_sys_ready_ind(a1, v4);
      goto LABEL_160;
    case 0x1408u:
      lim_process_sme_disassoc_req(a1, a2);
      goto LABEL_160;
    case 0x140Bu:
    case 0x141Au:
      v23 = *((const void **)a2 + 1);
      v250 = 0;
      v249 = 0u;
      LOBYTE(v247) = 0;
      *(_QWORD *)&v242 = 0;
      qdf_mem_copy(&v249, v23, 0x18u);
      if ( pe_find_session_by_bssid(a1, (char *)&v249 + 12, &v247) )
      {
        _lim_process_sme_disassoc_cnf(a1, *((const void **)a2 + 1));
      }
      else
      {
        if ( vars0 == (__int64 *)((char *)&qword_28 + 4) )
          v207 = 0;
        else
          v207 = BYTE12(v249);
        if ( vars0 == (__int64 *)((char *)&qword_28 + 4) )
          v208 = 0;
        else
          v208 = BYTE13(v249);
        if ( vars0 == (__int64 *)((char *)&qword_28 + 4) )
          v209 = 0;
        else
          v209 = BYTE14(v249);
        if ( vars0 == (__int64 *)((char *)&qword_28 + 4) )
          v210 = 0;
        else
          v210 = BYTE1(v250);
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: session not found for bssid:%02x:%02x:%02x:**:**:%02x",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "lim_process_sme_disassoc_cnf",
          v207,
          v208,
          v209,
          v210);
        if ( !(unsigned int)lim_prepare_disconnect_done_ind(a1, &v242, BYTE4(v249), 541, 0) )
          lim_send_sme_disassoc_deauth_ntf(a1, 0, v242);
      }
      goto LABEL_160;
    case 0x140Cu:
      lim_process_sme_deauth_req(a1, a2);
      goto LABEL_160;
    case 0x1413u:
      _lim_process_sme_start_bss_req(a1, a2);
      goto LABEL_160;
    case 0x1416u:
      _lim_process_sme_assoc_cnf_new(a1, 0x1416u, v4, v14, v15, v16, v17, v18, v19, v20, v21);
      goto LABEL_160;
    case 0x1418u:
      _lim_process_sme_stop_bss_req(a1, a2);
      goto LABEL_160;
    case 0x141Cu:
      _lim_process_sme_addts_req(a1, v4);
      goto LABEL_160;
    case 0x141Eu:
      _lim_process_sme_delts_req(a1, v4);
      goto LABEL_160;
    case 0x1421u:
      WORD2(v249) = 0;
      LODWORD(v249) = 0;
      LOBYTE(v242) = 0;
      if ( v4 )
      {
        session_by_bssid = pe_find_session_by_bssid(a1, (char *)v4 + 1, &v242);
        if ( !session_by_bssid )
        {
          v219 = *((unsigned __int8 *)v4 + 1);
          v220 = *((unsigned __int8 *)v4 + 2);
          v221 = "%s: Session Does not exist for bssid: %02x:%02x:%02x:**:**:%02x";
          v222 = *((unsigned __int8 *)v4 + 3);
          v223 = *((unsigned __int8 *)v4 + 6);
          v224 = "__lim_process_sme_mscs_req";
          goto LABEL_146;
        }
        if ( *(_DWORD *)(session_by_bssid + 88) == 2 )
        {
          v131 = session_by_bssid;
          if ( (unsigned int)wlan_vdev_mlme_is_active(*(_QWORD *)(session_by_bssid + 16)) )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: mscs req in unexpected vdev SM state:%d",
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              "__lim_process_sme_mscs_req",
              *(unsigned int *)(*(_QWORD *)(v131 + 16) + 20LL));
            goto LABEL_159;
          }
          if ( *((_BYTE *)v4 + 48) == 1 )
          {
            v212 = "%s: MSCS req already sent";
            goto LABEL_149;
          }
          qdf_mem_copy(&v249, (const void *)(v131 + 24), 6u);
          v241 = (unsigned int)v249 | ((unsigned __int64)WORD2(v249) << 32);
          *((_BYTE *)v4 + 48) = 1;
          lim_send_mscs_req_action_frame(a1, v241, v4, v131);
          goto LABEL_159;
        }
        v212 = "%s: MSCS req received on AP - ignoring";
      }
      else
      {
        v212 = "%s: Buffer is Pointing to NULL";
      }
LABEL_149:
      v213 = "__lim_process_sme_mscs_req";
      goto LABEL_152;
    case 0x1427u:
      _lim_process_sme_session_update(a1, v4);
      goto LABEL_160;
    case 0x1428u:
      LOBYTE(v242) = 0;
      LODWORD(v251) = 0;
      v250 = 0;
      v249 = 0u;
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
        qdf_mem_set(&v249, 0x1Cu, 0);
        v142 = pe_find_session_by_bssid(a1, (char *)v4 + 6, &v242);
        if ( v142 )
        {
          v143 = *(unsigned __int16 *)(v142 + 7158);
          v144 = *((unsigned __int16 *)v4 + 2);
          if ( v143 != v144 )
          {
            *(_WORD *)(v142 + 7158) = v144;
            v143 = *((unsigned __int16 *)v4 + 2);
          }
          if ( *(unsigned __int16 *)(a1 + 12448) != v143 )
          {
            *(_WORD *)(a1 + 12448) = v143;
            v145 = v142;
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
            if ( !*(_BYTE *)(a1 + 14809) )
            {
              ((void (__fastcall *)(__int64, __int64))sch_set_fixed_beacon_fields)(a1, v145);
              v146 = *((_WORD *)v4 + 2);
              LOBYTE(v249) = *(_BYTE *)(v145 + 10);
              WORD2(v249) = v146;
              HIWORD(v249) = 1;
              lim_send_beacon_params(a1, &v249, v145);
            }
          }
LABEL_159:
          ready = 1;
          goto LABEL_160;
        }
        v212 = "%s: Session does not exist for given BSSID";
      }
      else
      {
        v212 = "%s: Buffer is Pointing to NULL";
      }
      v213 = "__lim_process_sme_change_bi";
      goto LABEL_152;
    case 0x142Bu:
      rrm_process_neighbor_report_req(a1, *((_QWORD *)a2 + 1));
      goto LABEL_160;
    case 0x142Eu:
      rrm_process_beacon_report_xmit(a1, *((_QWORD *)a2 + 1));
      goto LABEL_160;
    case 0x1430u:
      rrm_process_chan_load_report_xmit(a1, *((_QWORD *)a2 + 1));
      goto LABEL_160;
    case 0x1431u:
      v252 = 0;
      v253 = 0;
      v250 = 0;
      v251 = 0;
      v249 = 0u;
      HIDWORD(v242) = 0;
      *(_QWORD *)((char *)&v242 + 4) = 0;
      if ( !v4 )
      {
        v212 = "%s: Buffer is Pointing to NULL";
        v213 = "lim_process_sap_ch_width_update";
        goto LABEL_152;
      }
      v44 = *((unsigned __int8 *)v4 + 8);
      session_by_vdev_id = pe_find_session_by_vdev_id(a1, *((unsigned __int8 *)v4 + 8));
      if ( session_by_vdev_id )
      {
        v54 = *(unsigned int *)(session_by_vdev_id + 7036);
        v55 = session_by_vdev_id;
        if ( ((unsigned int)v54 | 2) == 3 )
        {
          v56 = *(_QWORD *)(a1 + 21560);
          v57 = *(_DWORD *)(v55 + 284);
          LODWORD(v242) = v4[1];
          wlan_reg_set_channel_params_for_pwrmode(
            v56,
            v57,
            0,
            (__int64)&v242,
            0,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53);
          v58 = *(_DWORD *)(v55 + 284);
          *(_BYTE *)(v55 + 7216) = 1;
          *(_DWORD *)(v55 + 7204) = v58;
          v67 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21560), v58, v59, v60, v61, v62, v63, v64, v65, v66);
          *(_BYTE *)(v55 + 7208) = v67;
          v76 = v4[1];
          *(_BYTE *)(v55 + 7209) = BYTE5(v242);
          v77 = BYTE6(v242);
          *(_DWORD *)(v55 + 7212) = v76;
          *(_BYTE *)(v55 + 7210) = v77;
          v78 = v4[1];
          if ( v78 >= 3 && (unsigned int)wma_get_vht_ch_width(v67) < 2 )
            v78 = 2;
          *(_DWORD *)(v55 + 7228) = v78;
          wlan_mlme_set_ap_oper_ch_width(*(_QWORD *)(v55 + 16), v4[1], v68, v69, v70, v71, v72, v73, v74, v75);
          send_extended_chan_switch_action_frame(a1, *(unsigned int *)(v55 + 284), v4[1]);
          v87 = *((_BYTE *)v4 + 4);
          v88 = *(unsigned __int8 *)(v55 + 7172);
          *(_BYTE *)(v55 + 7171) = 1;
          v89 = v88 & 0xFFFFFFF0 | v87 & 0xF;
          v90 = *(unsigned __int8 *)(v55 + 8635);
          *(_BYTE *)(v55 + 7172) = v89;
          if ( v90 )
          {
            v89 = v89 & 0xFFFFFF8F | (16 * (((unsigned int)(16 * v90 + 112) >> 4) & 7));
            *(_BYTE *)(v55 + 7172) = v89;
          }
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: ch width %d nss %d",
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            "lim_update_bcn_with_new_ch_width",
            v89 & 0xF,
            (v89 >> 4) & 7);
          *(_BYTE *)(v55 + 7284) = 1;
          if ( (unsigned int)qdf_mc_timer_start(v55 + 8232, 0xC8u) )
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: cannot start ap_ecsa_timer",
              v91,
              v92,
              v93,
              v94,
              v95,
              v96,
              v97,
              v98,
              "lim_update_bcn_with_new_ch_width");
          v99 = ((__int64 (__fastcall *)(__int64, __int64))sch_set_fixed_beacon_fields)(a1, v55);
          if ( v99 )
          {
            v108 = v99;
            v109 = "%s: Unable to set op mode IE in beacon";
          }
          else
          {
            v235 = lim_send_beacon_ind(a1, v55, 8u, v100, v101, v102, v103, v104, v105, v106, v107);
            if ( !v235 )
              goto LABEL_164;
            v108 = v235;
            v109 = "%s: Unable to send beacon";
          }
          qdf_trace_msg(
            0x35u,
            2u,
            v109,
            v100,
            v101,
            v102,
            v103,
            v104,
            v105,
            v106,
            v107,
            "lim_update_bcn_with_new_ch_width");
          lim_nss_or_ch_width_update_rsp(a1, *(unsigned __int8 *)(v55 + 10), v108, 8);
LABEL_164:
          v236 = v4[1];
          v237 = 0;
          v248 = 0;
          v247 = 0;
          do
          {
            v238 = (_WORD *)(*(_QWORD *)(v55 + 368) + 952LL * v237);
            if ( v238 && (*v238 & 8) != 0 )
            {
              v239 = lim_calculate_peer_ch_width(v55, v238 + 169, v236);
              v240 = *(unsigned __int8 *)(v55 + 10);
              LODWORD(v247) = v239;
              WORD2(v247) = v240;
              qdf_mem_copy((char *)&v247 + 6, v238 + 169, 6u);
              lim_send_mode_update(a1, &v247, v55);
            }
            ++v237;
          }
          while ( *(unsigned __int8 *)(a1 + 12272) >= (unsigned int)v237 );
          goto LABEL_159;
        }
        v218 = "%s: Invalid opmode %d";
      }
      else
      {
        v54 = v4[2];
        v218 = "%s: vdev %d session not found";
      }
      qdf_trace_msg(0x35u, 2u, v218, v46, v47, v48, v49, v50, v51, v52, v53, "lim_process_sap_ch_width_update", v54);
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: vdev %d: send bandwidth update fail",
        v225,
        v226,
        v227,
        v228,
        v229,
        v230,
        v231,
        v232,
        "lim_process_sap_ch_width_update",
        v44);
      v233 = _qdf_mem_malloc(0xCu, "lim_process_sap_ch_width_update", 9958);
      if ( v233 )
      {
        *(_BYTE *)v233 = -1;
        *(_QWORD *)(v233 + 4) = 0x1000000008LL;
      }
      v217 = &v249;
      *((_QWORD *)&v249 + 1) = v233;
      LOWORD(v249) = 5170;
      DWORD1(v249) = 0;
LABEL_158:
      sys_process_mmh_msg(a1, v217);
      goto LABEL_159;
    case 0x1434u:
      lim_process_ft_aggr_qos_req(a1, (__int64)v4);
      goto LABEL_160;
    case 0x1437u:
      _lim_process_sme_register_mgmt_frame_req(a1, v4);
      goto LABEL_160;
    case 0x143Au:
      lim_process_sme_tdls_mgmt_send_req(a1, v4);
      goto LABEL_160;
    case 0x143Cu:
      ((void (__fastcall *)(__int64, unsigned int *))lim_process_sme_tdls_add_sta_req)(a1, v4);
      goto LABEL_160;
    case 0x143Eu:
      lim_process_sme_tdls_del_sta_req(a1, v4);
      goto LABEL_160;
    case 0x1450u:
      v252 = 0;
      v253 = 0;
      v250 = 0;
      v251 = 0;
      *(_QWORD *)&v249 = 4260;
      *((_QWORD *)&v249 + 1) = v4;
      mac_trace_msg_tx(a1, 255, 4260);
      if ( (unsigned int)wma_post_ctrl_msg(a1, &v249) )
      {
        _qdf_mem_free((__int64)v4);
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Unable to forward request",
          v132,
          v133,
          v134,
          v135,
          v136,
          v137,
          v138,
          v139,
          "__lim_process_sme_get_tsm_stats_request");
      }
      ready = 0;
      goto LABEL_160;
    case 0x1454u:
      lim_process_sme_channel_change_request(a1, v4);
      goto LABEL_160;
    case 0x1456u:
      LOBYTE(v249) = 0;
      if ( v4 )
      {
        v195 = pe_find_session_by_bssid(a1, (char *)v4 + 5, &v249);
        if ( !v195 )
        {
          v219 = *((unsigned __int8 *)v4 + 5);
          v220 = *((unsigned __int8 *)v4 + 6);
          v221 = "%s: Session does not exist for given bssId: %02x:%02x:%02x:**:**:%02x";
          v222 = *((unsigned __int8 *)v4 + 7);
          v223 = *((unsigned __int8 *)v4 + 10);
          v224 = "lim_process_sme_start_beacon_req";
LABEL_146:
          qdf_trace_msg(0x35u, 2u, v221, v14, v15, v16, v17, v18, v19, v20, v21, v224, v219, v220, v222, v223);
          goto LABEL_159;
        }
        if ( *((_BYTE *)v4 + 4) == 1 )
        {
          v196 = v195;
          lim_apply_configuration((_QWORD *)a1, v195, v14, v15, v16, v17, v18, v19, v20, v21);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Start Beacon with ssid %.*s Ch freq %d",
            v197,
            v198,
            v199,
            v200,
            v201,
            v202,
            v203,
            v204,
            "lim_process_sme_start_beacon_req",
            *(unsigned __int8 *)(v196 + 36),
            v196 + 37,
            *(unsigned int *)(v196 + 284));
          lim_send_beacon(a1, v196);
          lim_enable_obss_detection_config(a1, v196);
          lim_send_obss_color_collision_cfg(a1, v196, 1);
          goto LABEL_159;
        }
        v212 = "%s: Invalid Beacon Start Indication";
      }
      else
      {
        v212 = "%s: Buffer is Pointing to NULL";
      }
      v213 = "lim_process_sme_start_beacon_req";
      goto LABEL_152;
    case 0x1457u:
      lim_process_sme_dfs_csa_ie_request(a1, v4);
      goto LABEL_160;
    case 0x145Du:
      lim_process_update_add_ies(a1, v4);
      goto LABEL_160;
    case 0x145Eu:
      lim_process_modify_add_ies(a1, v4);
      goto LABEL_160;
    case 0x1460u:
      _lim_process_sme_set_ht2040_mode(a1, v4);
      goto LABEL_160;
    case 0x1469u:
      lim_process_set_hw_mode(a1, v4);
      goto LABEL_160;
    case 0x146Cu:
      lim_process_nss_update_request(a1, v4);
      goto LABEL_160;
    case 0x1473u:
      v252 = 0;
      v253 = 0;
      v250 = 0;
      v251 = 0;
      v249 = 0u;
      v245 = 0;
      v246 = 0;
      v243 = 0;
      v244 = 0;
      v242 = 0u;
      if ( v4 )
      {
        v110 = (_DWORD *)_qdf_mem_malloc(0x18u, "lim_process_set_dual_mac_cfg_req", 255);
        if ( v110 )
        {
          *v110 = v4[2];
          v119 = v4[3];
          v120 = (__int64)v110;
          LOWORD(v249) = 4282;
          v110[1] = v119;
          *((_QWORD *)&v249 + 1) = v110;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Post SIR_HAL_PDEV_DUAL_MAC_CFG_REQ to WMA: %x %x",
            v111,
            v112,
            v113,
            v114,
            v115,
            v116,
            v117,
            v118,
            "lim_process_set_dual_mac_cfg_req");
          v121 = scheduler_post_message_debug(
                   0x35u,
                   0x36u,
                   54,
                   (unsigned __int16 *)&v249,
                   0x110u,
                   (__int64)"lim_process_set_dual_mac_cfg_req");
          if ( !v121 )
            goto LABEL_159;
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: scheduler_post_msg failed!(err=%d)",
            v122,
            v123,
            v124,
            v125,
            v126,
            v127,
            v128,
            v129,
            "lim_process_set_dual_mac_cfg_req",
            v121);
          _qdf_mem_free(v120);
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
      v214 = (_DWORD *)_qdf_mem_malloc(4u, "lim_process_set_dual_mac_cfg_req", 281);
      if ( !v214 )
        goto LABEL_159;
      v215 = 5236;
      goto LABEL_131;
    case 0x1476u:
      LOBYTE(v250) = 0;
      v249 = 0u;
      if ( !v4 )
      {
        v212 = "%s: Buffer is Pointing to NULL";
        v213 = "lim_process_set_ie_req";
        goto LABEL_152;
      }
      v175 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               *(_QWORD *)(a1 + 21552),
               *((unsigned __int8 *)v4 + 4),
               11);
      if ( v175 )
      {
        v184 = v175;
        ext_hdl = wlan_vdev_mlme_get_ext_hdl(v175, v176, v177, v178, v179, v180, v181, v182, v183);
        if ( ext_hdl )
        {
          if ( *(_BYTE *)(ext_hdl + 24227) )
          {
            lim_update_extcap_struct(a1, ext_hdl + 24227, &v249);
            if ( (*(_DWORD *)((_BYTE *)&v249 + 2) & 0x80000000) != 0 )
              *(_QWORD *)((char *)&v249 + 2) |= 0x100000000uLL;
            BYTE1(v249) = lim_compute_ext_cap_ie_length(&v249);
          }
          if ( (unsigned int)lim_send_ext_cap_ie(a1, *((unsigned __int8 *)v4 + 4), &v249, 1) )
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Unable to send ExtCap to FW",
              v187,
              v188,
              v189,
              v190,
              v191,
              v192,
              v193,
              v194,
              "lim_process_set_ie_req");
        }
        wlan_objmgr_vdev_release_ref(v184, 0xBu, v186, v187, v188, v189, v190, v191, v192, v193, v194);
      }
      goto LABEL_159;
    case 0x1477u:
      if ( !v4 )
      {
        v206 = "%s: Buffer is Pointing to NULL";
        goto LABEL_135;
      }
      v205 = pe_find_session_by_vdev_id(a1, *((unsigned __int8 *)v4 + 8));
      if ( v205 )
      {
        if ( *(_DWORD *)(v205 + 88) == 1 )
        {
          v206 = "%s: not an STA/CLI session";
LABEL_135:
          v216 = "lim_process_ext_change_channel";
          goto LABEL_138;
        }
        *(_BYTE *)(v205 + 7211) = 0;
        send_extended_chan_switch_action_frame(a1, v4[1], 0);
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Session not found for given vdev_id %d",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "lim_process_ext_change_channel",
          *((unsigned __int8 *)v4 + 8));
      }
LABEL_160:
      _ReadStatusReg(SP_EL0);
      return ready & 1;
    case 0x1479u:
      if ( v4 )
      {
        v32 = *((_QWORD *)v4 + 1);
        if ( v32 )
        {
          *(_QWORD *)(a1 + 21536) = v32;
          goto LABEL_160;
        }
        v206 = "%s: sme_req->callback is null";
      }
      else
      {
        v206 = "%s: msg_buf is null";
      }
      v216 = "lim_register_mgmt_frame_ind_cb";
      goto LABEL_138;
    case 0x147Bu:
      v252 = 0;
      v253 = 0;
      v250 = 0;
      v251 = 0;
      v249 = 0u;
      v245 = 0;
      v246 = 0;
      v243 = 0;
      v244 = 0;
      v242 = 0u;
      if ( v4 )
      {
        v155 = (_DWORD *)_qdf_mem_malloc(0x18u, "lim_process_set_antenna_mode_req", 334);
        if ( v155 )
        {
          v155[1] = v4[3];
          v164 = v4[2];
          v165 = (__int64)v155;
          *v155 = v164;
          *((_QWORD *)&v249 + 1) = v155;
          LOWORD(v249) = 4248;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Post SIR_HAL_SOC_ANTENNA_MODE_REQ to WMA: %d %d",
            v156,
            v157,
            v158,
            v159,
            v160,
            v161,
            v162,
            v163,
            "lim_process_set_antenna_mode_req");
          v166 = scheduler_post_message_debug(
                   0x35u,
                   0x36u,
                   54,
                   (unsigned __int16 *)&v249,
                   0x15Fu,
                   (__int64)"lim_process_set_antenna_mode_req");
          if ( !v166 )
            goto LABEL_159;
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: scheduler_post_msg failed!(err=%d)",
            v167,
            v168,
            v169,
            v170,
            v171,
            v172,
            v173,
            v174,
            "lim_process_set_antenna_mode_req",
            v166);
          _qdf_mem_free(v165);
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
      v214 = (_DWORD *)_qdf_mem_malloc(4u, "lim_process_set_antenna_mode_req", 360);
      if ( !v214 )
        goto LABEL_159;
      v215 = 5244;
LABEL_131:
      *v214 = 2;
      v217 = &v242;
      LOWORD(v242) = v215;
      *((_QWORD *)&v242 + 1) = v214;
      DWORD1(v242) = 0;
      goto LABEL_158;
    case 0x147Fu:
      lim_process_set_pdev_IEs(a1, v4);
      goto LABEL_160;
    case 0x1480u:
      lim_process_set_vdev_ies_per_band(a1, v4);
      goto LABEL_160;
    case 0x1481u:
      _lim_process_send_disassoc_frame(a1, v4);
      goto LABEL_160;
    case 0x1482u:
      lim_process_sme_update_access_policy_vendor_ie(a1, v4);
      goto LABEL_160;
    case 0x148Bu:
      lim_process_sme_update_config(a1, v4);
      goto LABEL_160;
    case 0x1491u:
      lim_process_sme_set_addba_accept(a1, v4);
      goto LABEL_160;
    case 0x1492u:
      v33 = *((_DWORD *)a2 + 1);
      v34 = (_BYTE *)pe_find_session_by_vdev_id(a1, v33);
      if ( !v34 )
      {
        v211 = "lim_process_sme_update_active_edca_params";
        goto LABEL_125;
      }
      v43 = v34;
      v34[7140] = *(_BYTE *)(a1 + 21625);
      v34[7145] = *(_BYTE *)(a1 + 21626);
      v34[7150] = *(_BYTE *)(a1 + 21627);
      v34[7155] = *(_BYTE *)(a1 + 21628);
      if ( dph_get_hash_entry(a1, 1u, (__int64)(v34 + 360)) )
      {
        lim_send_edca_params(a1, v43 + 7136, (unsigned __int8)v43[10], 0);
        goto LABEL_159;
      }
      v212 = "%s: Self entry missing in Hash Table";
      v213 = "lim_process_sme_update_active_edca_params";
      goto LABEL_152;
    case 0x1493u:
      v33 = *((_DWORD *)a2 + 1);
      v140 = pe_find_session_by_vdev_id(a1, v33);
      if ( v140 )
      {
        v141 = v140;
        if ( dph_get_hash_entry(a1, 1u, v140 + 360) )
        {
          ready = 1;
          lim_send_edca_params(a1, a1 + 21681, *(unsigned __int8 *)(v141 + 10), 1);
          goto LABEL_160;
        }
        v212 = "%s: Self entry missing in Hash Table";
        v213 = "lim_process_sme_update_mu_edca_params";
LABEL_152:
        qdf_trace_msg(0x35u, 2u, v212, v14, v15, v16, v17, v18, v19, v20, v21, v213);
      }
      else
      {
        v211 = "lim_process_sme_update_mu_edca_params";
LABEL_125:
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Session does not exist: vdev_id %d",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v211,
          v33);
      }
      goto LABEL_159;
    case 0x1496u:
      lim_process_sme_cfg_action_frm_in_tb_ppdu(a1, v4);
      goto LABEL_160;
    case 0x14A2u:
      lim_process_sme_update_session_edca_txq_params(a1, v4);
      goto LABEL_160;
    case 0x14B4u:
      if ( v4 )
      {
        if ( !pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)v4) )
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: Session does not exist for given BSSID",
            v147,
            v148,
            v149,
            v150,
            v151,
            v152,
            v153,
            v154,
            "lim_process_sme_send_vdev_pause");
      }
      else
      {
        v206 = "%s: Buffer is NULL";
        v216 = "lim_process_sme_send_vdev_pause";
LABEL_138:
        qdf_trace_msg(0x35u, 2u, v206, v14, v15, v16, v17, v18, v19, v20, v21, v216);
      }
      goto LABEL_160;
    case 0x14B5u:
      goto LABEL_160;
    default:
      _qdf_mem_free(*((_QWORD *)a2 + 1));
      *((_QWORD *)a2 + 1) = 0;
      goto LABEL_159;
  }
}
