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
  unsigned int v43; // w1
  unsigned int v44; // w4
  unsigned int v45; // w23
  int v46; // w8
  unsigned int v47; // w4
  unsigned int v48; // w8
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x0
  unsigned int v59; // w25
  unsigned int v60; // w23
  unsigned int v61; // w24
  __int64 v62; // x4
  const char *v63; // x2
  const char *v64; // x3
  unsigned int v65; // w1
  int v66; // w9
  int v67; // w8
  unsigned int v68; // w26
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned int v77; // w8
  signed int v78; // w26
  unsigned int connection_count; // w0
  unsigned int v80; // w27
  unsigned __int8 v81; // w8
  int v82; // w10
  int v83; // w8
  unsigned __int8 cb_mode_for_freq; // w23
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  int v93; // w25
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x0
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  int v111; // w8
  __int64 v112; // x0
  unsigned int v113; // w1
  char v114; // w8
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  unsigned int v123; // w8
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  char v132; // w8
  int v133; // w9
  char v134; // w10
  unsigned int vht_ch_width; // w23
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  unsigned __int16 op_class_width; // w0
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  __int16 v154; // w8
  int v155; // w8
  int v156; // w8
  __int64 v157; // x0
  unsigned int v158; // w1
  char v159; // w8
  __int16 chanwidth_from_opclass_auto; // w0
  __int64 v161; // x0
  unsigned int v162; // w1
  char v163; // w8
  __int64 v164; // x0
  unsigned int v165; // w1
  int v166; // w9
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  double updated; // d0
  double v176; // d1
  double v177; // d2
  double v178; // d3
  double v179; // d4
  double v180; // d5
  double v181; // d6
  double v182; // d7
  __int64 ext_hdl; // x0
  char v184; // w8
  _DWORD *v185; // x8
  __int64 v186; // x1
  __int64 v187; // x23
  __int64 v188; // [xsp+0h] [xbp-70h]
  __int64 v189; // [xsp+8h] [xbp-68h]
  __int64 v190; // [xsp+10h] [xbp-60h]
  _QWORD v191[3]; // [xsp+28h] [xbp-48h] BYREF
  __int64 v192; // [xsp+40h] [xbp-30h] BYREF
  __int64 v193; // [xsp+48h] [xbp-28h]
  __int64 v194; // [xsp+50h] [xbp-20h]
  __int16 v195; // [xsp+5Ch] [xbp-14h] BYREF
  _BYTE v196[4]; // [xsp+60h] [xbp-10h] BYREF
  __int16 v197; // [xsp+64h] [xbp-Ch] BYREF
  char v198; // [xsp+66h] [xbp-Ah]
  __int64 v199; // [xsp+68h] [xbp-8h]

  v199 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v196[0] = 0;
  v195 = 0;
  v193 = 0;
  v194 = 0;
  v192 = 0;
  v198 = 0;
  v197 = 0;
  if ( a2 )
  {
    session_by_bssid = pe_find_session_by_bssid(a1, a2 + 28, v196);
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
        a2[28],
        a2[29],
        a2[30],
        a2[33]);
      goto LABEL_52;
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
            &v195,
            session_by_bssid + 360) )
    {
      v42 = "%s: sta_ds does not exist";
      v43 = 2;
LABEL_49:
      qdf_trace_msg(0x35u, v43, v42, v24, v25, v26, v27, v28, v29, v30, v31, "lim_handle_sta_csa_param");
      goto LABEL_50;
    }
    if ( *(_DWORD *)(v23 + 88) != 2 )
    {
      v42 = "%s: Invalid role to handle CSA";
LABEL_48:
      v43 = 8;
      goto LABEL_49;
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
      goto LABEL_50;
    }
    v44 = *(unsigned __int8 *)(v23 + 154);
    if ( v44 > 6 )
    {
      if ( v44 - 8 < 4 )
      {
        v46 = 0;
        v45 = 3;
        goto LABEL_26;
      }
      if ( v44 - 12 < 2 )
      {
LABEL_18:
        v45 = 7;
LABEL_25:
        v46 = 1;
        goto LABEL_26;
      }
      if ( v44 != 7 )
      {
LABEL_24:
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
          "lim_get_max_channel_width_from_dot11mode");
        v45 = 8;
        goto LABEL_25;
      }
    }
    else
    {
      v45 = 0;
      v46 = 1;
      if ( *(unsigned __int8 *)(v23 + 154) <= 4u )
      {
        if ( v44 - 1 >= 4 )
          goto LABEL_18;
LABEL_26:
        v47 = *((_DWORD *)a2 + 3);
        if ( v47 != 4 )
          v46 = 1;
        if ( v47 > v45 && v46 && v47 - 7 <= 0xFFFFFFFD )
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
          *((_DWORD *)a2 + 3) = v45;
        }
        else
        {
          v45 = *((_DWORD *)a2 + 3);
        }
        v48 = *(unsigned __int8 *)(v23 + 154);
        LODWORD(v192) = v45;
        if ( v48 <= 0xD && ((1 << v48) & 0x3001) != 0 )
        {
          v49 = *(_QWORD *)(v23 + 16);
          if ( v49 )
          {
            if ( v45 == 7 && (*(_BYTE *)(v23 + 10075) & 2) == 0 )
              LODWORD(v192) = 3;
            wlan_cm_sta_set_chan_param(
              v49,
              *((_DWORD *)a2 + 1),
              v45,
              *((unsigned __int16 *)a2 + 8),
              a2[19],
              a2[20],
              (unsigned int *)&v192,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31);
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: invalid input parameter",
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              "lim_set_csa_chan_param_11be");
          }
        }
        else
        {
          wlan_reg_set_channel_params_for_pwrmode(
            a1[2704],
            *((_DWORD *)a2 + 1),
            0,
            (__int64)&v192,
            0,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31);
        }
        *(_WORD *)(v23 + 7216) = WORD1(v194);
        qdf_mem_set(&v192, 0x18u, 0);
        v58 = *(_QWORD *)(v23 + 16);
        if ( !v58
          || (v59 = *(_DWORD *)(v23 + 284),
              v60 = *((_DWORD *)a2 + 1),
              v61 = *((_DWORD *)a2 + 3),
              wlan_cm_is_vdev_disconnecting(v58, v50, v51, v52, v53, v54, v55, v56, v57))
          || wlan_cm_is_vdev_disconnected(*(_QWORD *)(v23 + 16), v50, v51, v52, v53, v54, v55, v56, v57) )
        {
          v62 = *(unsigned __int8 *)(v23 + 10);
          v63 = "%s: CSA is ignored, vdev %d is disconnecting/ed";
          v64 = "lim_is_csa_channel_allowed";
          v65 = 3;
LABEL_46:
          qdf_trace_msg(0x35u, v65, v63, v50, v51, v52, v53, v54, v55, v56, v57, v64, v62);
LABEL_47:
          v42 = "%s: Channel switch is not allowed";
          goto LABEL_48;
        }
        if ( wlan_reg_is_24ghz_ch_freq(v60) && (unsigned __int16)wlan_reg_get_bw_value(v61) >= 0x15u )
        {
          v66 = *a2;
          v67 = a2[19];
          if ( v66 + 2 == v67 )
          {
            v68 = v60 + 20;
          }
          else if ( v66 - 2 == v67 )
          {
            v68 = v60 - 20;
          }
          else
          {
            v68 = 0;
          }
        }
        else
        {
          v68 = 0;
        }
        if ( (wlan_reg_get_bonded_channel_state_for_pwrmode(a1[2704], v60, v61, v68, 0) & 0xFFFFFFFB) == 0 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Invalid csa_freq %d ch_width %d ccfs0 %d ccfs1 %d sec_ch %d. Disconnect",
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            "lim_is_csa_channel_allowed",
            v60,
            v61,
            a2[19],
            a2[20],
            v68);
          ((void (__fastcall *)(_QWORD *, _QWORD, __int64, _QWORD))lim_tear_down_link_with_ap)(
            a1,
            *(unsigned __int8 *)(v23 + 8),
            65532,
            0);
          goto LABEL_47;
        }
        v77 = *(unsigned __int8 *)(v23 + 154);
        if ( v77 <= 0xD
          && ((1 << v77) & 0x3001) != 0
          && (a2[24] & 0x10) != 0
          && *((_WORD *)a2 + 8)
          && !wlan_reg_is_punc_bitmap_valid(*((_DWORD *)a2 + 3), *((_WORD *)a2 + 8)) )
        {
          v62 = *((unsigned __int16 *)a2 + 8);
          v63 = "%s: invalid puncture bitmap %d";
          v64 = "lim_is_validate_punc_bitmap";
          v65 = 2;
          goto LABEL_46;
        }
        v78 = *(_DWORD *)(*(_QWORD *)(v23 + 16) + 16LL);
        connection_count = policy_mgr_get_connection_count(a1[2703]);
        if ( connection_count >= 2 )
        {
          v80 = connection_count;
          if ( (policy_mgr_is_hw_dbs_capable(a1[2703]) & 1) != 0
            || (policy_mgr_is_interband_mcc_supported(a1[2703]) & 1) != 0 )
          {
            if ( v80 != 2
              && (policy_mgr_allow_concurrency_sta_csa(
                    a1[2703],
                    *(_BYTE *)(*(_QWORD *)(v23 + 16) + 168LL),
                    v78,
                    v60,
                    v61)
                & 1) == 0 )
            {
              goto LABEL_47;
            }
          }
          else if ( (wlan_reg_is_same_band_freqs(v59, v60) & 1) == 0 )
          {
            goto LABEL_47;
          }
        }
        if ( (wlan_mlo_is_csa_allow(*(_QWORD *)(v23 + 16), *((unsigned int *)a2 + 1)) & 1) == 0 )
        {
          v42 = "%s: Channel switch for MLO vdev is not allowed";
          goto LABEL_48;
        }
        lim_update_tdls_set_state_for_fw(v23, 0);
        lim_delete_tdls_peers(a1, v23, 0);
        v81 = a2[8];
        *(_BYTE *)(v23 + 7218) = 0;
        v82 = *(_DWORD *)(v23 + 164);
        *(_BYTE *)(v23 + 7224) = v81;
        *(_BYTE *)(v23 + 7208) = *a2;
        v83 = *((_DWORD *)a2 + 1);
        *(_DWORD *)(v23 + 7200) = 1;
        *(_BYTE *)(v23 + 7211) = v82;
        *(_DWORD *)(v23 + 7212) = 0;
        *(_WORD *)(v23 + 7216) = 0;
        *(_DWORD *)(v23 + 7204) = v83;
        *(_WORD *)(v23 + 7209) = 0;
        cb_mode_for_freq = lim_get_cb_mode_for_freq(a1, v23, *((unsigned int *)a2 + 1));
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Session %d vdev %d: vht: %d htC: %d ht: %d he %d cbmode %d",
          v85,
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          "lim_handle_sta_csa_param",
          *(unsigned __int16 *)(v23 + 8),
          *(unsigned __int8 *)(v23 + 10),
          *v32,
          *(unsigned __int8 *)(v23 + 155),
          *(unsigned __int8 *)(v23 + 160),
          *(unsigned __int8 *)(v23 + 8676),
          cb_mode_for_freq);
        v93 = *(unsigned __int8 *)(v23 + 160);
        *(_BYTE *)(v23 + 160) = 0;
        v102 = wlan_reg_read_current_country(a1[2703], &v197, v94, v95, v96, v97, v98, v99, v100, v101);
        v111 = *((_DWORD *)a2 + 6);
        if ( !v111 || (v111 & 0x10) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: new freq: %u, width: %d",
            v103,
            v104,
            v105,
            v106,
            v107,
            v108,
            v109,
            v110,
            "lim_handle_sta_csa_param",
            *((unsigned int *)a2 + 1),
            *((unsigned int *)a2 + 3));
          v123 = *(unsigned __int8 *)(v23 + 154);
          LODWORD(v192) = *((_DWORD *)a2 + 3);
          if ( v123 <= 0xD && ((1 << v123) & 0x3001) != 0 )
            lim_set_csa_chan_param_11be(v23, a2, &v192);
          else
            wlan_reg_set_channel_params_for_pwrmode(
              a1[2704],
              *((_DWORD *)a2 + 1),
              0,
              (__int64)&v192,
              0,
              v115,
              v116,
              v117,
              v118,
              v119,
              v120,
              v121,
              v122);
          LODWORD(v188) = HIDWORD(v193);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: idea width: %d, chn_seg0 %u chn_seg1 %u freq_seg0 %u freq_seg1 %u",
            v124,
            v125,
            v126,
            v127,
            v128,
            v129,
            v130,
            v131,
            "lim_handle_sta_csa_param",
            (unsigned int)v192,
            BYTE5(v192),
            BYTE6(v192),
            (unsigned int)v193,
            v188);
          *(_BYTE *)(v23 + 7211) = BYTE4(v192);
          v132 = BYTE5(v192);
          v133 = v192;
          *(_BYTE *)(v23 + 7209) = BYTE5(v192);
          v134 = BYTE6(v192);
          *(_DWORD *)(v23 + 7212) = v133;
          *(_BYTE *)(v23 + 7210) = v134;
          *(_WORD *)(v23 + 7216) = WORD1(v194);
          if ( v133 )
          {
            *(_BYTE *)(v23 + 7190) = v132;
            *(_DWORD *)(v23 + 7200) = 2;
            *(_BYTE *)(v23 + 7189) = v133;
            *(_BYTE *)(v23 + 7191) = v134;
            *(_BYTE *)(v23 + 160) = 1;
          }
          else
          {
            *(_BYTE *)(v23 + 160) = 0;
            *(_DWORD *)(v23 + 7200) = 1;
          }
          goto LABEL_125;
        }
        if ( cb_mode_for_freq )
        {
          if ( *v32 && *(_BYTE *)(v23 + 155) || *(_BYTE *)(v23 + 8676) == 1 )
          {
            if ( (v111 & 4) != 0 )
            {
              v102 = lim_process_csa_wbw_ie(a1, a2, v23 + 7189, v23);
              if ( !(_DWORD)v102 )
              {
                v156 = *(unsigned __int8 *)(v23 + 7189);
                *(_BYTE *)(v23 + 7211) = 0;
                if ( !v156 )
                  goto LABEL_124;
                v157 = a1[2704];
                v158 = *((_DWORD *)a2 + 1);
                LODWORD(v192) = v156;
                wlan_reg_set_channel_params_for_pwrmode(
                  v157,
                  v158,
                  0,
                  (__int64)&v192,
                  0,
                  v103,
                  v104,
                  v105,
                  v106,
                  v107,
                  v108,
                  v109,
                  v110);
                v159 = BYTE4(v192);
                *(_BYTE *)(v23 + 160) = 1;
                goto LABEL_123;
              }
              v111 = *((_DWORD *)a2 + 6);
            }
            if ( (v111 & 2) == 0 )
            {
              *(_DWORD *)(v23 + 7200) = 2;
              v112 = a1[2704];
              v113 = *((_DWORD *)a2 + 1);
              LODWORD(v192) = 1;
              wlan_reg_set_channel_params_for_pwrmode(
                v112,
                v113,
                0,
                (__int64)&v192,
                0,
                v103,
                v104,
                v105,
                v106,
                v107,
                v108,
                v109,
                v110);
              v114 = BYTE4(v192);
              *(_BYTE *)(v23 + 7189) = 1;
              *(_BYTE *)(v23 + 160) = 1;
              *(_BYTE *)(v23 + 7211) = v114;
              *(_WORD *)(v23 + 7190) = BYTE5(v192);
LABEL_124:
              v166 = *(unsigned __int8 *)(v23 + 7189);
              *(_WORD *)(v23 + 7209) = *(_WORD *)(v23 + 7190);
              *(_DWORD *)(v23 + 7212) = v166;
              goto LABEL_125;
            }
            vht_ch_width = wma_get_vht_ch_width(v102);
            if ( wlan_reg_is_6ghz_op_class(a1[2704], a2[18]) )
              op_class_width = wlan_reg_get_op_class_width();
            else
              op_class_width = wlan_reg_dmn_get_chanwidth_from_opclass_auto(
                                 (unsigned __int8 *)&v197,
                                 *a2,
                                 a2[18],
                                 v136,
                                 v137,
                                 v138,
                                 v139,
                                 v140,
                                 v141,
                                 v142,
                                 v143);
            if ( vht_ch_width < 2 && op_class_width > 0x9Fu )
              v154 = 80;
            else
              v154 = op_class_width;
            *(_DWORD *)(v23 + 7200) = 2;
            switch ( v154 )
            {
              case 40:
                v155 = 1;
                *(_BYTE *)(v23 + 7189) = 1;
                *(_BYTE *)(v23 + 160) = 1;
                break;
              case 80:
                v155 = 2;
                *(_BYTE *)(v23 + 7189) = 2;
                *(_BYTE *)(v23 + 160) = 1;
                break;
              case 160:
                v155 = 3;
                *(_BYTE *)(v23 + 7189) = 3;
                break;
              default:
                v155 = 0;
                *(_BYTE *)(v23 + 7189) = 0;
                *(_DWORD *)(v23 + 7200) = 1;
                break;
            }
            v164 = a1[2704];
            v165 = *((_DWORD *)a2 + 1);
            LODWORD(v192) = v155;
            wlan_reg_set_channel_params_for_pwrmode(
              v164,
              v165,
              0,
              (__int64)&v192,
              0,
              v145,
              v146,
              v147,
              v148,
              v149,
              v150,
              v151,
              v152);
            *(_WORD *)(v23 + 7190) = *(_WORD *)((char *)&v192 + 5);
            v159 = BYTE4(v192);
LABEL_123:
            *(_BYTE *)(v23 + 7211) = v159;
            goto LABEL_124;
          }
          if ( *(_BYTE *)(v23 + 155) )
          {
            if ( (v111 & 2) != 0 )
            {
              chanwidth_from_opclass_auto = wlan_reg_dmn_get_chanwidth_from_opclass_auto(
                                              (unsigned __int8 *)&v197,
                                              *a2,
                                              a2[18],
                                              v103,
                                              v104,
                                              v105,
                                              v106,
                                              v107,
                                              v108,
                                              v109,
                                              v110);
              *(_DWORD *)(v23 + 7200) = 2;
              if ( chanwidth_from_opclass_auto != 40 )
              {
                *(_DWORD *)(v23 + 7212) = 0;
                *(_BYTE *)(v23 + 7189) = 0;
                *(_DWORD *)(v23 + 7200) = 1;
                *(_BYTE *)(v23 + 7211) = 0;
                goto LABEL_125;
              }
              *(_DWORD *)(v23 + 7212) = 1;
              *(_BYTE *)(v23 + 7189) = 1;
              goto LABEL_118;
            }
            if ( v93 )
            {
              *(_DWORD *)(v23 + 7212) = 1;
              *(_DWORD *)(v23 + 7200) = 2;
LABEL_118:
              v161 = a1[2704];
              v162 = *((_DWORD *)a2 + 1);
              LODWORD(v192) = 1;
              wlan_reg_set_channel_params_for_pwrmode(
                v161,
                v162,
                0,
                (__int64)&v192,
                0,
                v103,
                v104,
                v105,
                v106,
                v107,
                v108,
                v109,
                v110);
              v163 = BYTE5(v192);
              *(_BYTE *)(v23 + 160) = 1;
              *(_BYTE *)(v23 + 7209) = v163;
              *(_BYTE *)(v23 + 7211) = BYTE4(v192);
            }
          }
        }
LABEL_125:
        lim_cp_stats_cstats_log_csa_evt(
          v23,
          1,
          *(unsigned int *)(v23 + 7204),
          *(unsigned int *)(v23 + 7212),
          *(unsigned __int8 *)(v23 + 7224));
        LODWORD(v189) = *(unsigned __int8 *)(v23 + 7211);
        LODWORD(v190) = *(_DWORD *)(v23 + 284);
        LODWORD(v188) = *(unsigned __int8 *)(v23 + 7210);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: new ch %d: freq %d width: %d freq0 %d freq1 %d ht width %d, current freq %d: bw %d",
          v167,
          v168,
          v169,
          v170,
          v171,
          v172,
          v173,
          v174,
          "lim_handle_sta_csa_param",
          *(unsigned __int8 *)(v23 + 7208),
          *(unsigned int *)(v23 + 7204),
          *(unsigned int *)(v23 + 7212),
          *(unsigned __int8 *)(v23 + 7209),
          v188,
          v189,
          v190,
          *(_DWORD *)(v23 + 7176));
        v191[0] = v192;
        v191[1] = v193;
        v191[2] = v194;
        if ( (lim_sta_follow_csa(v23, a2, v23 + 7200, v191) & 1) == 0 )
          goto LABEL_50;
        if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(v23 + 16), v33, v34, v35, v36, v37, v38, v39, v40) & 1) != 0 )
          updated = update_csa_link_info(*(_QWORD *)(v23 + 16), *(unsigned __int8 *)(*(_QWORD *)(v23 + 16) + 93LL), a2);
        ext_hdl = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(v23 + 16), updated, v176, v177, v178, v179, v180, v181, v182);
        if ( !ext_hdl )
          goto LABEL_50;
        *(_DWORD *)(ext_hdl + 24252) = *((_DWORD *)a2 + 3);
        wlan_mlme_update_ch_width_from_ap(ext_hdl, 1);
        if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)a2 + 1)) && *(_BYTE *)(v23 + 154) == 2 )
        {
          v184 = 4;
        }
        else
        {
          if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)a2 + 1)) || (*(unsigned __int8 *)(v23 + 154) | 2) != 6 )
            goto LABEL_136;
          v184 = 2;
        }
        *(_BYTE *)(v23 + 154) = v184;
LABEL_136:
        v185 = (_DWORD *)a1[1553];
        if ( v185 )
        {
          v186 = *(unsigned __int8 *)(v23 + 10);
          if ( *(v185 - 1) != 491867520 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD *, __int64, __int64, __int64))v185)(a1, v186, 56, 2);
        }
        if ( (mlo_is_any_link_disconnecting(*(_QWORD *)(v23 + 16)) & 1) != 0 )
        {
          v187 = jiffies;
          if ( lim_handle_sta_csa_param___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x35u,
              4u,
              "%s: Ignore CSA, vdev is in not in conncted state",
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              "lim_handle_sta_csa_param");
            lim_handle_sta_csa_param___last_ticks = v187;
          }
          goto LABEL_50;
        }
        if ( (unsigned int)lim_prepare_for11h_channel_switch(a1, v23) )
        {
LABEL_50:
          if ( (a3 & 1) != 0 )
            wlan_mlme_send_csa_event_status_ind(*(_QWORD *)(v23 + 16), 0, v33, v34, v35, v36, v37, v38, v39, v40);
          goto LABEL_52;
        }
        lim_flush_bssid(a1, v23 + 24);
        *(_BYTE *)(v23 + 13284) = 1;
        lim_diag_event_report(a1, 24, v23, 0);
LABEL_52:
        result = _qdf_mem_free((__int64)a2);
        goto LABEL_53;
      }
      if ( v44 != 5 )
      {
        if ( v44 == 6 )
          goto LABEL_26;
        goto LABEL_24;
      }
    }
    v46 = 1;
    v45 = 1;
    goto LABEL_26;
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
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return result;
}
