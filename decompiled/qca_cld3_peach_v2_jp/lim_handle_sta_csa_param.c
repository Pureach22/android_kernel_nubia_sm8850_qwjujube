__int64 __fastcall lim_handle_sta_csa_param(
        _QWORD *a1,
        unsigned __int8 *a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 session_by_bssid; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned __int8 *v32; // x28
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 result; // x0
  const char *v42; // x2
  const char *v43; // x3
  unsigned int v44; // w1
  unsigned int v45; // w6
  unsigned int v46; // w23
  int v47; // w8
  unsigned int v48; // w4
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x0
  unsigned int v58; // w25
  unsigned int v59; // w23
  unsigned int v60; // w24
  int v61; // w9
  int v62; // w8
  unsigned int v63; // w26
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  signed int v72; // w26
  unsigned int connection_count; // w0
  unsigned int v74; // w27
  unsigned __int8 v75; // w8
  int v76; // w8
  int v77; // w10
  unsigned __int8 cb_mode_for_freq; // w23
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  int v87; // w24
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  __int64 v96; // x0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  int v105; // w8
  __int64 v106; // x0
  unsigned int v107; // w1
  char v108; // w8
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  unsigned int v117; // w8
  __int64 v118; // x4
  char v119; // w8
  int v120; // w9
  char v121; // w10
  unsigned int vht_ch_width; // w23
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  unsigned __int16 op_class_width; // w0
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  __int16 v141; // w8
  int v142; // w8
  int v143; // w8
  __int64 v144; // x0
  unsigned int v145; // w1
  char v146; // w8
  __int16 chanwidth_from_opclass_auto; // w0
  __int64 v148; // x0
  unsigned int v149; // w1
  char v150; // w8
  __int64 v151; // x0
  unsigned int v152; // w1
  int v153; // w9
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  int v170; // w23
  __int64 ext_hdl; // x0
  int v172; // w24
  unsigned int max_bw; // w0
  __int64 v174; // x0
  char v175; // w8
  _DWORD *v176; // x8
  __int64 v177; // x1
  __int64 v178; // [xsp+0h] [xbp-50h]
  __int64 v179; // [xsp+8h] [xbp-48h]
  __int64 v180; // [xsp+10h] [xbp-40h]
  __int64 v181; // [xsp+28h] [xbp-28h] BYREF
  __int64 v182; // [xsp+30h] [xbp-20h]
  __int16 v183; // [xsp+3Ch] [xbp-14h] BYREF
  _BYTE v184[4]; // [xsp+40h] [xbp-10h] BYREF
  __int16 v185; // [xsp+44h] [xbp-Ch] BYREF
  char v186; // [xsp+46h] [xbp-Ah]
  __int64 v187; // [xsp+48h] [xbp-8h]

  v187 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v184[0] = 0;
  v183 = 0;
  v181 = 0;
  v182 = 0;
  v186 = 0;
  v185 = 0;
  if ( a2 )
  {
    session_by_bssid = pe_find_session_by_bssid(a1, a2 + 24, v184);
    if ( !session_by_bssid )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Session does not exists for %02x:%02x:%02x:**:**:%02x",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "lim_handle_sta_csa_param",
        a2[24],
        a2[25],
        a2[26],
        a2[29]);
      goto LABEL_47;
    }
    v23 = session_by_bssid;
    if ( !dph_lookup_hash_entry(
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            (__int64)a1,
            (unsigned __int8 *)(session_by_bssid + 24),
            &v183,
            session_by_bssid + 360) )
    {
      v42 = "%s: sta_ds does not exist";
      v43 = "lim_handle_sta_csa_param";
      goto LABEL_10;
    }
    if ( *(_DWORD *)(v23 + 88) != 2 )
    {
      v42 = "%s: Invalid role to handle CSA";
LABEL_42:
      v43 = "lim_handle_sta_csa_param";
LABEL_43:
      v44 = 8;
      goto LABEL_44;
    }
    v32 = (unsigned __int8 *)(v23 + 7170);
    if ( *(_BYTE *)(v23 + 9794) == 1 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: ch switch inprogress, ignore CSA vdev %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "lim_handle_sta_csa_param",
        *(unsigned __int8 *)(v23 + 10));
      goto LABEL_45;
    }
    v45 = *(unsigned __int8 *)(v23 + 154);
    if ( v45 > 6 )
    {
      if ( v45 - 8 < 4 )
      {
        v47 = 0;
        v46 = 3;
        goto LABEL_27;
      }
      if ( v45 - 12 < 2 )
        goto LABEL_19;
      if ( v45 != 7 )
      {
LABEL_25:
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Invalid dot11mode %d",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "lim_get_max_channel_width_from_dot11mode",
          *(unsigned __int8 *)(v23 + 154));
        v45 = *(unsigned __int8 *)(v23 + 154);
        v46 = 8;
        goto LABEL_26;
      }
    }
    else
    {
      v46 = 0;
      v47 = 1;
      if ( *(unsigned __int8 *)(v23 + 154) <= 4u )
      {
        if ( v45 - 1 < 4 )
          goto LABEL_27;
LABEL_19:
        v46 = 7;
LABEL_26:
        v47 = 1;
LABEL_27:
        v48 = *((_DWORD *)a2 + 3);
        if ( v48 != 4 )
          v47 = 1;
        if ( v48 > v46 && v47 && v48 - 7 <= 0xFFFFFFFD )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Downgrade bw from %d to max supported bw %d for dot11mode %d ",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "lim_csa_update_channel_width_for_dot11mode");
          *((_DWORD *)a2 + 3) = v46;
          v45 = *(unsigned __int8 *)(v23 + 154);
        }
        else
        {
          v46 = *((_DWORD *)a2 + 3);
        }
        LODWORD(v181) = v46;
        if ( v45 > 0xD || ((1 << v45) & 0x3001) == 0 )
          wlan_reg_set_channel_params_for_pwrmode(
            a1[2695],
            *((_DWORD *)a2 + 1),
            0,
            (__int64)&v181,
            0,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31);
        qdf_mem_set(&v181, 0x10u, 0);
        v57 = *(_QWORD *)(v23 + 16);
        if ( !v57
          || (v58 = *(_DWORD *)(v23 + 284),
              v59 = *((_DWORD *)a2 + 1),
              v60 = *((_DWORD *)a2 + 3),
              wlan_cm_is_vdev_disconnecting(v57, v49, v50, v51, v52, v53, v54, v55, v56))
          || wlan_cm_is_vdev_disconnected(*(_QWORD *)(v23 + 16), v49, v50, v51, v52, v53, v54, v55, v56) )
        {
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: CSA is ignored, vdev %d is disconnecting/ed",
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            "lim_is_csa_channel_allowed",
            *(unsigned __int8 *)(v23 + 10));
LABEL_41:
          v42 = "%s: Channel switch is not allowed";
          goto LABEL_42;
        }
        if ( wlan_reg_is_24ghz_ch_freq(v59) && (unsigned __int16)wlan_reg_get_bw_value(v60) >= 0x15u )
        {
          v61 = *a2;
          v62 = a2[17];
          if ( v61 + 2 == v62 )
          {
            v63 = v59 + 20;
          }
          else if ( v61 - 2 == v62 )
          {
            v63 = v59 - 20;
          }
          else
          {
            v63 = 0;
          }
        }
        else
        {
          v63 = 0;
        }
        if ( (wlan_reg_get_bonded_channel_state_for_pwrmode(a1[2695], v59, v60, v63, 0) & 0xFFFFFFFB) == 0 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Invalid csa_freq %d ch_width %d ccfs0 %d ccfs1 %d sec_ch %d. Disconnect",
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            "lim_is_csa_channel_allowed",
            v59,
            v60,
            a2[17],
            a2[18],
            v63);
          lim_tear_down_link_with_ap((__int64)a1, *(unsigned __int8 *)(v23 + 8), 0xFFFCu, 0);
          goto LABEL_41;
        }
        v72 = *(_DWORD *)(*(_QWORD *)(v23 + 16) + 16LL);
        connection_count = policy_mgr_get_connection_count(a1[2694]);
        if ( connection_count >= 2 )
        {
          v74 = connection_count;
          if ( (policy_mgr_is_hw_dbs_capable(a1[2694]) & 1) != 0
            || (policy_mgr_is_interband_mcc_supported(a1[2694]) & 1) != 0 )
          {
            if ( v74 != 2
              && (policy_mgr_allow_concurrency_sta_csa(
                    a1[2694],
                    *(_BYTE *)(*(_QWORD *)(v23 + 16) + 104LL),
                    v72,
                    v59,
                    v60)
                & 1) == 0 )
            {
              goto LABEL_41;
            }
          }
          else if ( (wlan_reg_is_same_band_freqs(v58, v59) & 1) == 0 )
          {
            goto LABEL_41;
          }
        }
        lim_update_tdls_set_state_for_fw(v23, 0);
        lim_delete_tdls_peers(a1, v23, 0);
        v75 = a2[8];
        *(_BYTE *)(v23 + 7216) = 0;
        *(_BYTE *)(v23 + 7224) = v75;
        *(_BYTE *)(v23 + 7208) = *a2;
        v76 = *(_DWORD *)(v23 + 164);
        v77 = *((_DWORD *)a2 + 1);
        *(_DWORD *)(v23 + 7200) = 1;
        *(_DWORD *)(v23 + 7212) = 0;
        *(_BYTE *)(v23 + 7211) = v76;
        *(_DWORD *)(v23 + 7204) = v77;
        *(_WORD *)(v23 + 7209) = 0;
        cb_mode_for_freq = lim_get_cb_mode_for_freq(a1, v23, *((unsigned int *)a2 + 1));
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Session %d vdev %d: vht: %d htC: %d ht: %d he %d cbmode %d",
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          "lim_handle_sta_csa_param",
          *(unsigned __int16 *)(v23 + 8),
          *(unsigned __int8 *)(v23 + 10),
          *v32,
          *(unsigned __int8 *)(v23 + 155),
          *(unsigned __int8 *)(v23 + 160),
          *(unsigned __int8 *)(v23 + 8676),
          cb_mode_for_freq);
        v87 = *(unsigned __int8 *)(v23 + 160);
        *(_BYTE *)(v23 + 160) = 0;
        v96 = wlan_reg_read_current_country(a1[2694], &v185, v88, v89, v90, v91, v92, v93, v94, v95);
        v105 = *((_DWORD *)a2 + 5);
        if ( !v105 || (v105 & 0x10) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: new freq: %u, width: %d",
            v97,
            v98,
            v99,
            v100,
            v101,
            v102,
            v103,
            v104,
            "lim_handle_sta_csa_param",
            *((unsigned int *)a2 + 1),
            *((unsigned int *)a2 + 3));
          v117 = *(unsigned __int8 *)(v23 + 154);
          v118 = *((unsigned int *)a2 + 3);
          LODWORD(v181) = *((_DWORD *)a2 + 3);
          if ( v117 > 0xD || ((1 << v117) & 0x3001) == 0 )
          {
            wlan_reg_set_channel_params_for_pwrmode(
              a1[2695],
              *((_DWORD *)a2 + 1),
              0,
              (__int64)&v181,
              0,
              v109,
              v110,
              v111,
              v112,
              v113,
              v114,
              v115,
              v116);
            v118 = (unsigned int)v181;
          }
          LODWORD(v178) = HIDWORD(v182);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: idea width: %d, chn_seg0 %u chn_seg1 %u freq_seg0 %u freq_seg1 %u",
            v109,
            v110,
            v111,
            v112,
            v113,
            v114,
            v115,
            v116,
            "lim_handle_sta_csa_param",
            v118,
            BYTE5(v181),
            BYTE6(v181),
            (unsigned int)v182,
            v178);
          *(_BYTE *)(v23 + 7211) = BYTE4(v181);
          v119 = BYTE5(v181);
          v120 = v181;
          *(_BYTE *)(v23 + 7209) = BYTE5(v181);
          v121 = BYTE6(v181);
          *(_DWORD *)(v23 + 7212) = v120;
          *(_BYTE *)(v23 + 7210) = v121;
          if ( v120 )
          {
            *(_BYTE *)(v23 + 7188) = v119;
            *(_DWORD *)(v23 + 7200) = 2;
            *(_BYTE *)(v23 + 7187) = v120;
            *(_BYTE *)(v23 + 7189) = v121;
            *(_BYTE *)(v23 + 160) = 1;
          }
          else
          {
            *(_BYTE *)(v23 + 160) = 0;
            *(_DWORD *)(v23 + 7200) = 1;
          }
          goto LABEL_111;
        }
        if ( cb_mode_for_freq )
        {
          if ( *v32 && *(_BYTE *)(v23 + 155) || *(_BYTE *)(v23 + 8676) == 1 )
          {
            if ( (v105 & 4) != 0 )
            {
              v96 = lim_process_csa_wbw_ie(a1, a2, v23 + 7187, v23);
              if ( !(_DWORD)v96 )
              {
                v143 = *(unsigned __int8 *)(v23 + 7187);
                *(_BYTE *)(v23 + 7211) = 0;
                if ( !v143 )
                  goto LABEL_110;
                v144 = a1[2695];
                v145 = *((_DWORD *)a2 + 1);
                LODWORD(v181) = v143;
                wlan_reg_set_channel_params_for_pwrmode(
                  v144,
                  v145,
                  0,
                  (__int64)&v181,
                  0,
                  v97,
                  v98,
                  v99,
                  v100,
                  v101,
                  v102,
                  v103,
                  v104);
                v146 = BYTE4(v181);
                *(_BYTE *)(v23 + 160) = 1;
                goto LABEL_109;
              }
              v105 = *((_DWORD *)a2 + 5);
            }
            if ( (v105 & 2) == 0 )
            {
              *(_DWORD *)(v23 + 7200) = 2;
              v106 = a1[2695];
              v107 = *((_DWORD *)a2 + 1);
              LODWORD(v181) = 1;
              wlan_reg_set_channel_params_for_pwrmode(
                v106,
                v107,
                0,
                (__int64)&v181,
                0,
                v97,
                v98,
                v99,
                v100,
                v101,
                v102,
                v103,
                v104);
              v108 = BYTE4(v181);
              *(_BYTE *)(v23 + 7187) = 1;
              *(_BYTE *)(v23 + 160) = 1;
              *(_BYTE *)(v23 + 7211) = v108;
              *(_WORD *)(v23 + 7188) = BYTE5(v181);
LABEL_110:
              v153 = *(unsigned __int8 *)(v23 + 7187);
              *(_WORD *)(v23 + 7209) = *(_WORD *)(v23 + 7188);
              *(_DWORD *)(v23 + 7212) = v153;
              goto LABEL_111;
            }
            vht_ch_width = wma_get_vht_ch_width(v96);
            if ( wlan_reg_is_6ghz_op_class(a1[2695], a2[16]) )
              op_class_width = wlan_reg_get_op_class_width();
            else
              op_class_width = wlan_reg_dmn_get_chanwidth_from_opclass_auto(
                                 (unsigned __int8 *)&v185,
                                 *a2,
                                 a2[16],
                                 v123,
                                 v124,
                                 v125,
                                 v126,
                                 v127,
                                 v128,
                                 v129,
                                 v130);
            if ( vht_ch_width < 2 && op_class_width > 0x9Fu )
              v141 = 80;
            else
              v141 = op_class_width;
            *(_DWORD *)(v23 + 7200) = 2;
            switch ( v141 )
            {
              case 40:
                v142 = 1;
                *(_BYTE *)(v23 + 7187) = 1;
                *(_BYTE *)(v23 + 160) = 1;
                break;
              case 80:
                v142 = 2;
                *(_BYTE *)(v23 + 7187) = 2;
                *(_BYTE *)(v23 + 160) = 1;
                break;
              case 160:
                v142 = 3;
                *(_BYTE *)(v23 + 7187) = 3;
                break;
              default:
                v142 = 0;
                *(_BYTE *)(v23 + 7187) = 0;
                *(_DWORD *)(v23 + 7200) = 1;
                break;
            }
            v151 = a1[2695];
            v152 = *((_DWORD *)a2 + 1);
            LODWORD(v181) = v142;
            wlan_reg_set_channel_params_for_pwrmode(
              v151,
              v152,
              0,
              (__int64)&v181,
              0,
              v132,
              v133,
              v134,
              v135,
              v136,
              v137,
              v138,
              v139);
            *(_WORD *)(v23 + 7188) = *(_WORD *)((char *)&v181 + 5);
            v146 = BYTE4(v181);
LABEL_109:
            *(_BYTE *)(v23 + 7211) = v146;
            goto LABEL_110;
          }
          if ( !*(_BYTE *)(v23 + 155) )
            goto LABEL_111;
          if ( (v105 & 2) == 0 )
          {
            if ( !v87 )
              goto LABEL_111;
            *(_DWORD *)(v23 + 7212) = 1;
            *(_DWORD *)(v23 + 7200) = 2;
            goto LABEL_104;
          }
          chanwidth_from_opclass_auto = wlan_reg_dmn_get_chanwidth_from_opclass_auto(
                                          (unsigned __int8 *)&v185,
                                          *a2,
                                          a2[16],
                                          v97,
                                          v98,
                                          v99,
                                          v100,
                                          v101,
                                          v102,
                                          v103,
                                          v104);
          *(_DWORD *)(v23 + 7200) = 2;
          if ( chanwidth_from_opclass_auto == 40 )
          {
            *(_DWORD *)(v23 + 7212) = 1;
            *(_BYTE *)(v23 + 7187) = 1;
LABEL_104:
            v148 = a1[2695];
            v149 = *((_DWORD *)a2 + 1);
            LODWORD(v181) = 1;
            wlan_reg_set_channel_params_for_pwrmode(
              v148,
              v149,
              0,
              (__int64)&v181,
              0,
              v97,
              v98,
              v99,
              v100,
              v101,
              v102,
              v103,
              v104);
            v150 = BYTE5(v181);
            *(_BYTE *)(v23 + 160) = 1;
            *(_BYTE *)(v23 + 7209) = v150;
            *(_BYTE *)(v23 + 7211) = BYTE4(v181);
            goto LABEL_111;
          }
          *(_DWORD *)(v23 + 7212) = 0;
          *(_BYTE *)(v23 + 7187) = 0;
          *(_DWORD *)(v23 + 7200) = 1;
          *(_BYTE *)(v23 + 7211) = 0;
        }
LABEL_111:
        lim_cp_stats_cstats_log_csa_evt(
          v23,
          1,
          *(unsigned int *)(v23 + 7204),
          *(unsigned int *)(v23 + 7212),
          *(unsigned __int8 *)(v23 + 7224));
        LODWORD(v179) = *(unsigned __int8 *)(v23 + 7211);
        LODWORD(v180) = *(_DWORD *)(v23 + 284);
        LODWORD(v178) = *(unsigned __int8 *)(v23 + 7210);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: new ch %d: freq %d width: %d freq0 %d freq1 %d ht width %d, current freq %d: bw %d",
          v154,
          v155,
          v156,
          v157,
          v158,
          v159,
          v160,
          v161,
          "lim_handle_sta_csa_param",
          *(unsigned __int8 *)(v23 + 7208),
          *(unsigned int *)(v23 + 7204),
          *(unsigned int *)(v23 + 7212),
          *(unsigned __int8 *)(v23 + 7209),
          v178,
          v179,
          v180,
          *(_DWORD *)(v23 + 7176));
        if ( *(_DWORD *)(v23 + 284) != *((_DWORD *)a2 + 1) )
          goto LABEL_119;
        v170 = v181;
        if ( *(_DWORD *)(v23 + 7176) != (_DWORD)v181 || *(unsigned __int8 *)(v23 + 7184) != BYTE6(v181) )
          goto LABEL_119;
        ext_hdl = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(v23 + 16), v162, v163, v164, v165, v166, v167, v168, v169);
        if ( ext_hdl )
        {
          v172 = *(_DWORD *)(ext_hdl + 24248);
          max_bw = wlan_mlme_get_max_bw();
          if ( v172 != 2 || v170 != 3 || max_bw < 3 )
          {
            v42 = "%s: Ignore CSA, no change in ch, bw and puncture";
            v43 = "lim_sta_follow_csa";
            goto LABEL_43;
          }
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: BW upgrade %d->%d",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "lim_sta_follow_csa",
            2,
            3);
LABEL_119:
          v174 = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(v23 + 16), v162, v163, v164, v165, v166, v167, v168, v169);
          if ( !v174 )
          {
LABEL_45:
            if ( (a3 & 1) != 0 )
              wlan_mlme_send_csa_event_status_ind(*(_QWORD *)(v23 + 16), 0, v33, v34, v35, v36, v37, v38, v39, v40);
            goto LABEL_47;
          }
          *(_DWORD *)(v174 + 24252) = *((_DWORD *)a2 + 3);
          wlan_mlme_update_ch_width_from_ap(v174, 1);
          if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)a2 + 1)) && *(_BYTE *)(v23 + 154) == 2 )
          {
            v175 = 4;
          }
          else
          {
            if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)a2 + 1)) || (*(unsigned __int8 *)(v23 + 154) | 2) != 6 )
              goto LABEL_127;
            v175 = 2;
          }
          *(_BYTE *)(v23 + 154) = v175;
LABEL_127:
          v176 = (_DWORD *)a1[1553];
          if ( v176 )
          {
            v177 = *(unsigned __int8 *)(v23 + 10);
            if ( *(v176 - 1) != 491867520 )
              __break(0x8228u);
            ((void (__fastcall *)(_QWORD *, __int64, __int64, __int64))v176)(a1, v177, 56, 2);
          }
          if ( (unsigned int)lim_prepare_for11h_channel_switch(a1, v23) )
            goto LABEL_45;
          lim_flush_bssid(a1, v23 + 24);
          *(_BYTE *)(v23 + 10075) = 1;
          lim_diag_event_report(a1, 24, v23, 0);
LABEL_47:
          result = _qdf_mem_free((__int64)a2);
          goto LABEL_48;
        }
        v42 = "%s: null mlme priv";
        v43 = "lim_sta_follow_csa";
LABEL_10:
        v44 = 2;
LABEL_44:
        qdf_trace_msg(0x35u, v44, v42, v24, v25, v26, v27, v28, v29, v30, v31, v43);
        goto LABEL_45;
      }
      if ( v45 != 5 )
      {
        if ( v45 == 6 )
          goto LABEL_27;
        goto LABEL_25;
      }
    }
    v47 = 1;
    v46 = 1;
    goto LABEL_27;
  }
  result = qdf_trace_msg(
             0x35u,
             2u,
             "%s: limMsgQ body ptr is NULL",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "lim_handle_sta_csa_param");
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
