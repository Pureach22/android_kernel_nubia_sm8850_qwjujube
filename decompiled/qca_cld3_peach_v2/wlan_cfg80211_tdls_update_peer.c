__int64 __fastcall wlan_cfg80211_tdls_update_peer(__int64 tdls_link_vdev, unsigned __int8 *a2, __int64 a3)
{
  unsigned __int8 *v3; // x21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x6
  __int64 v21; // x7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  char is_mlo_vdev; // w23
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x8
  __int64 v40; // x19
  __int64 v41; // x0
  unsigned int *v42; // x8
  __int64 v43; // x26
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int v60; // w4
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x8
  __int64 v70; // x0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  unsigned int v87; // w8
  __int64 v88; // x11
  unsigned int v89; // w26
  __int64 v90; // x25
  __int64 v91; // x21
  unsigned int v92; // w19
  unsigned __int8 v93; // w21
  unsigned __int8 v94; // w20
  unsigned __int8 *v95; // x22
  unsigned int v96; // w0
  unsigned int v97; // w19
  unsigned __int64 v98; // x8
  int v99; // w11
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  unsigned int v108; // w8
  unsigned int v109; // w24
  int v110; // w28
  int v111; // w23
  __int64 v112; // x22
  unsigned int v113; // w27
  unsigned int v114; // w0
  unsigned int v115; // w19
  unsigned __int64 v116; // x8
  int v117; // w10
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  unsigned int *v134; // x22
  __int64 v135; // x21
  unsigned int v136; // t1
  __int64 v137; // x4
  unsigned int v138; // w8
  size_t v139; // x2
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  unsigned __int64 v148; // x20
  int v149; // w8
  unsigned int v150; // w4
  const char *v151; // x2
  const char *v152; // x3
  __int64 v153; // x8
  _DWORD *v154; // x19
  double v155; // d0
  double v156; // d1
  double v157; // d2
  double v158; // d3
  double v159; // d4
  double v160; // d5
  double v161; // d6
  double v162; // d7
  unsigned int updated; // w0
  double v164; // d0
  double v165; // d1
  double v166; // d2
  double v167; // d3
  double v168; // d4
  double v169; // d5
  double v170; // d6
  double v171; // d7
  size_t v173; // x2
  const void *v174; // x1
  double v175; // d0
  double v176; // d1
  double v177; // d2
  double v178; // d3
  double v179; // d4
  double v180; // d5
  double v181; // d6
  double v182; // d7
  unsigned __int8 *v183; // [xsp+8h] [xbp-78h]
  char v184; // [xsp+14h] [xbp-6Ch]
  __int64 v185; // [xsp+18h] [xbp-68h]
  __int64 v186; // [xsp+20h] [xbp-60h]
  char is_fw_6g_capable; // [xsp+2Ch] [xbp-54h]
  __int64 v188; // [xsp+30h] [xbp-50h]
  char is_fw_11ax_capable; // [xsp+3Ch] [xbp-44h]
  __int64 v190; // [xsp+40h] [xbp-40h]
  __int64 v191; // [xsp+48h] [xbp-38h]
  __int64 v192; // [xsp+50h] [xbp-30h]
  unsigned int v193; // [xsp+5Ch] [xbp-24h]
  __int64 v194; // [xsp+60h] [xbp-20h]
  _DWORD *v195; // [xsp+68h] [xbp-18h]
  __int16 v196; // [xsp+74h] [xbp-Ch] BYREF
  unsigned __int8 v197; // [xsp+76h] [xbp-Ah]
  __int64 v198; // [xsp+78h] [xbp-8h]

  v3 = a2;
  v198 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)qdf_mem_cmp(a2, &wlan_cfg80211_tdls_validate_mac_addr_temp_mac, 6u) )
  {
    if ( v3 )
    {
      v14 = *v3;
      v15 = v3[1];
      v16 = v3[2];
      v17 = v3[5];
    }
    else
    {
      v16 = 0;
      v14 = 0;
      v15 = 0;
      v17 = 0;
    }
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Update TDLS peer %02x:%02x:%02x:**:**:%02x",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_cfg80211_tdls_update_peer",
      v14,
      v15,
      v16,
      v17);
    is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(tdls_link_vdev, v22, v23, v24, v25, v26, v27, v28, v29);
    if ( (is_mlo_vdev & 1) != 0 )
    {
      tdls_link_vdev = ucfg_tdls_get_tdls_link_vdev(tdls_link_vdev, 0x57u);
      if ( !tdls_link_vdev )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: no tdls link vdev",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "wlan_cfg80211_tdls_update_peer");
        v92 = -22;
        goto LABEL_109;
      }
    }
    v39 = *(_QWORD *)(tdls_link_vdev + 216);
    if ( !v39 || (v40 = *(_QWORD *)(v39 + 80)) == 0 )
    {
      v91 = jiffies;
      v42 = (unsigned int *)(wlan_cfg80211_tdls_update_peer___last_ticks - jiffies);
      if ( wlan_cfg80211_tdls_update_peer___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Invalid psoc",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "wlan_cfg80211_tdls_update_peer");
        v92 = 0;
        wlan_cfg80211_tdls_update_peer___last_ticks = v91;
      }
      else
      {
        v92 = 0;
      }
LABEL_107:
      if ( (is_mlo_vdev & 1) != 0 )
        ucfg_tdls_put_tdls_link_vdev(tdls_link_vdev, 0x57u, v42, v31, v32, v33, v34, v35, v36, v37, v38);
      goto LABEL_109;
    }
    v41 = _qdf_mem_malloc(0x248u, "wlan_cfg80211_tdls_update_peer", 727);
    if ( !v41 )
    {
      v92 = -22;
      goto LABEL_107;
    }
    v43 = v41;
    is_fw_11ax_capable = ucfg_tdls_is_fw_11ax_capable(v40);
    is_fw_6g_capable = ucfg_tdls_is_fw_6g_capable(v40);
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: sta cap %d, uapsd_queue %d, max_sp %d",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "wlan_cfg80211_tdls_extract_params",
      *(unsigned __int16 *)(a3 + 40),
      *(unsigned __int8 *)(a3 + 32),
      *(unsigned __int8 *)(a3 + 33));
    *(_WORD *)(v43 + 16) = *(_WORD *)(a3 + 40);
    *(_BYTE *)(v43 + 145) = *(_BYTE *)(a3 + 32);
    *(_BYTE *)(v43 + 146) = *(_BYTE *)(a3 + 33);
    v60 = *(unsigned __int8 *)(a3 + 88);
    if ( v60 >= 0x21 )
    {
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: received oper classes:%d, resetting it to max supported: %d",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "wlan_cfg80211_tdls_extract_params");
      v60 = 32;
      *(_BYTE *)(a3 + 88) = 32;
    }
    qdf_mem_copy((void *)(v43 + 549), *(const void **)(a3 + 80), v60);
    v191 = a3;
    *(_BYTE *)(v43 + 548) = *(_BYTE *)(a3 + 88);
    if ( *(_BYTE *)(a3 + 72) )
    {
      v197 = 0;
      v196 = 0;
      if ( !tdls_link_vdev )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: null vdev",
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          "tdls_calc_channels_from_staparams");
        goto LABEL_73;
      }
      v69 = *(_QWORD *)(tdls_link_vdev + 216);
      if ( v69 )
      {
        v70 = *(_QWORD *)(v69 + 80);
        if ( v70 )
        {
          v194 = *(_QWORD *)(tdls_link_vdev + 216);
          v185 = tdls_link_vdev;
          v186 = v43;
          v192 = *(_QWORD *)(a3 + 64);
          v183 = v3;
          v184 = is_mlo_vdev;
          v188 = *(_QWORD *)(a3 + 80);
          wlan_reg_read_current_country(v70, &v196, v61, v62, v63, v64, v65, v66, v67, v68);
          qdf_trace_msg(
            0x48u,
            8u,
            "%s: Country info from AP:%c%c 0x%x",
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            "tdls_calc_channels_from_staparams",
            (unsigned __int8)v196,
            HIBYTE(v196),
            v197);
          v87 = *(unsigned __int8 *)(a3 + 88);
          if ( !*(_BYTE *)(a3 + 88) )
          {
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: Unique Channel List: supported_channels ",
              v79,
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              "tdls_calc_channels_from_staparams");
            v89 = 0;
            goto LABEL_72;
          }
          v88 = 0;
          v89 = 0;
          v90 = v186 + 152;
          v195 = (_DWORD *)(v186 + 148);
          while ( 1 )
          {
            v193 = *(unsigned __int8 *)(a3 + 72);
            if ( *(_BYTE *)(a3 + 72) )
            {
              if ( v89 <= 0x63 )
                break;
            }
LABEL_23:
            if ( ++v88 >= (unsigned __int64)v87 )
            {
              qdf_trace_msg(
                0x48u,
                8u,
                "%s: Unique Channel List: supported_channels ",
                v79,
                v80,
                v81,
                v82,
                v83,
                v84,
                v85,
                v86,
                "tdls_calc_channels_from_staparams");
              if ( v89 )
              {
                v134 = (unsigned int *)(v186 + 148);
                v135 = v89;
                do
                {
                  v136 = *v134++;
                  qdf_trace_msg(
                    0x48u,
                    8u,
                    "%s:  %d,",
                    v126,
                    v127,
                    v128,
                    v129,
                    v130,
                    v131,
                    v132,
                    v133,
                    "tdls_calc_channels_from_staparams",
                    v136);
                  --v135;
                }
                while ( v135 );
                a3 = v191;
              }
LABEL_72:
              v137 = v89;
              *(_BYTE *)(v186 + 147) = v89;
              v43 = v186;
              qdf_trace_msg(
                0x48u,
                8u,
                "%s: After removing duplcates supported_channels_len: %d",
                v126,
                v127,
                v128,
                v129,
                v130,
                v131,
                v132,
                v133,
                "tdls_calc_channels_from_staparams",
                v137);
              tdls_link_vdev = v185;
              is_mlo_vdev = v184;
              v3 = v183;
              goto LABEL_73;
            }
          }
          v93 = 0;
          v190 = v88;
          v94 = *(_BYTE *)(v188 + v88);
          while ( 1 )
          {
            v95 = (unsigned __int8 *)(v192 + v93);
            v96 = wlan_reg_country_chan_opclass_to_freq(
                    v194,
                    (unsigned __int8 *)&v196,
                    *v95,
                    v94,
                    0,
                    v79,
                    v80,
                    v81,
                    v82,
                    v83,
                    v84,
                    v85,
                    v86);
            if ( v96 )
            {
              v97 = v96;
              if ( !v89 )
                goto LABEL_34;
              if ( *v195 != v96 )
                break;
            }
LABEL_58:
            v93 += 2;
            if ( v193 <= v93 || v89 >= 0x64 )
            {
              a3 = v191;
              v88 = v190;
              v87 = *(unsigned __int8 *)(v191 + 88);
              goto LABEL_23;
            }
          }
          v98 = 0;
          while ( v89 - 1LL != v98 )
          {
            v99 = *(_DWORD *)(v90 + 4 * v98++);
            if ( v99 == v96 )
            {
              if ( v98 < v89 )
                goto LABEL_58;
              break;
            }
          }
LABEL_34:
          if ( wlan_reg_is_6ghz_chan_freq(v96) && (tdls_is_6g_freq_allowed(v194, v97) & 1) == 0 )
          {
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: skipping non-psc or non-vlp freq %d",
              v100,
              v101,
              v102,
              v103,
              v104,
              v105,
              v106,
              v107,
              "tdls_fill_chan_freq_from_supported_ch_list",
              v97);
          }
          else
          {
            v108 = *v95;
            v109 = v95[1];
            v195[v89] = v97;
            v110 = *v95;
            if ( v108 < 0xF )
              v111 = 1;
            else
              v111 = 4;
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: freq %d index %d ",
              v100,
              v101,
              v102,
              v103,
              v104,
              v105,
              v106,
              v107,
              "tdls_fill_chan_freq_from_supported_ch_list",
              v97,
              v89 + 1);
            if ( v109 < 2 || v89 > 0x62 )
            {
              ++v89;
            }
            else
            {
              ++v89;
              v112 = v194;
              v113 = 1;
              do
              {
                v110 += v111;
                v114 = wlan_reg_country_chan_opclass_to_freq(
                         v112,
                         (unsigned __int8 *)&v196,
                         v110,
                         v94,
                         0,
                         v79,
                         v80,
                         v81,
                         v82,
                         v83,
                         v84,
                         v85,
                         v86);
                if ( v114 )
                {
                  v115 = v114;
                  if ( *v195 != v114 )
                  {
                    v116 = 0;
                    while ( v89 - 1LL != v116 )
                    {
                      v117 = *(_DWORD *)(v90 + 4 * v116++);
                      if ( v117 == v114 )
                      {
                        if ( v116 < v89 )
                          goto LABEL_52;
                        break;
                      }
                    }
                    if ( wlan_reg_is_6ghz_chan_freq(v114) && (tdls_is_6g_freq_allowed(v194, v115) & 1) == 0 )
                    {
                      qdf_trace_msg(
                        0x48u,
                        8u,
                        "%s: skipping non-psc or non-vlp freq %d",
                        v118,
                        v119,
                        v120,
                        v121,
                        v122,
                        v123,
                        v124,
                        v125,
                        "tdls_fill_chan_freq_from_supported_ch_list",
                        v115);
                    }
                    else
                    {
                      v195[v89] = v115;
                      qdf_trace_msg(
                        0x48u,
                        8u,
                        "%s: freq %d index %d ",
                        v118,
                        v119,
                        v120,
                        v121,
                        v122,
                        v123,
                        v124,
                        v125,
                        "tdls_fill_chan_freq_from_supported_ch_list",
                        v115,
                        v89++);
                    }
LABEL_52:
                    v112 = v194;
                  }
                }
                ++v113;
              }
              while ( v113 < v109 && v89 < 0x64 );
            }
          }
          goto LABEL_58;
        }
      }
    }
LABEL_73:
    if ( *(_BYTE *)(a3 + 56) )
      qdf_mem_copy((void *)(v43 + 18), *(const void **)(a3 + 48), 8u);
    if ( *(_QWORD *)(a3 + 144) )
    {
      *(_BYTE *)(v43 + 59) = 1;
      qdf_mem_copy((void *)(v43 + 60), *(const void **)(a3 + 144), 0x1Au);
    }
    v138 = *(unsigned __int8 *)(a3 + 136);
    if ( v138 >= 0x20 )
      v139 = 32;
    else
      v139 = *(unsigned __int8 *)(a3 + 136);
    *(_BYTE *)(v43 + 26) = v139;
    if ( v138 )
    {
      qdf_mem_copy((void *)(v43 + 27), *(const void **)(v191 + 128), v139);
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: Supported Rates with Length %d",
        v140,
        v141,
        v142,
        v143,
        v144,
        v145,
        v146,
        v147,
        "wlan_cfg80211_tdls_extract_params",
        *(unsigned __int8 *)(v43 + 26));
      if ( *(_BYTE *)(v43 + 26) )
      {
        v148 = 0;
        do
        {
          if ( v148 == 32 )
            __break(0x5512u);
          qdf_trace_msg(
            0x48u,
            8u,
            "%s: [%d]: %0x",
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            "wlan_cfg80211_tdls_extract_params",
            (unsigned int)v148,
            *(unsigned __int8 *)(v43 + 27 + v148));
          ++v148;
        }
        while ( v148 < *(unsigned __int8 *)(v43 + 26) );
      }
    }
    if ( *(_QWORD *)(v191 + 152) )
    {
      *(_BYTE *)(v43 + 86) = 1;
      qdf_mem_copy((void *)(v43 + 88), *(const void **)(v191 + 152), 0xCu);
    }
    if ( *(_QWORD *)(v191 + 144) || *(_QWORD *)(v191 + 152) || (v149 = *(_DWORD *)(v191 + 12), (v149 & 8) != 0) )
    {
      *(_BYTE *)(v43 + 581) = 1;
      if ( (*(_DWORD *)(v191 + 12) & 0x10) == 0 )
      {
LABEL_91:
        if ( (is_fw_11ax_capable & 1) != 0 )
          goto LABEL_92;
        goto LABEL_96;
      }
    }
    else if ( (v149 & 0x10) == 0 )
    {
      goto LABEL_91;
    }
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: TDLS peer pmf capable",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "wlan_cfg80211_tdls_extract_params");
    *(_BYTE *)(v43 + 582) = 1;
    if ( (is_fw_11ax_capable & 1) != 0 )
    {
LABEL_92:
      v150 = *(unsigned __int8 *)(v191 + 176);
      if ( v150 <= 0x10 )
      {
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: he_capa_len %d less than MIN_TDLS_HE_CAP_LEN",
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          "wlan_cfg80211_tdls_extract_he_params");
        goto LABEL_98;
      }
      if ( *(_QWORD *)(v191 + 168) )
      {
        if ( v150 >= 0x1D )
          v173 = 29;
        else
          v173 = *(unsigned __int8 *)(v191 + 176);
        *(_BYTE *)(v43 + 100) = v173;
        qdf_mem_copy((void *)(v43 + 101), *(const void **)(v191 + 168), v173);
        if ( (is_fw_6g_capable & 1) == 0 )
        {
LABEL_98:
          if ( *(_QWORD *)(v191 + 200) )
          {
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: eht capa is present",
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              "wlan_cfg80211_tdls_extract_eht_params");
            *(_BYTE *)(v43 + 132) = 1;
            *(_BYTE *)(v43 + 133) = *(_BYTE *)(v191 + 208);
            qdf_mem_copy((void *)(v43 + 134), *(const void **)(v191 + 200), 0xBu);
            v153 = *(_QWORD *)(tdls_link_vdev + 680);
            if ( !v153 )
              goto LABEL_105;
          }
          else
          {
            *(_BYTE *)(v43 + 132) = 0;
            v153 = *(_QWORD *)(tdls_link_vdev + 680);
            if ( !v153 )
              goto LABEL_105;
          }
          v154 = *(_DWORD **)(v153 + 16);
          if ( v154 )
          {
            *(_DWORD *)(v43 + 12) = *(unsigned __int8 *)(tdls_link_vdev + 168);
            qdf_mem_copy((void *)v43, v3, 6u);
            *v154 = 0;
            updated = ucfg_tdls_update_peer(
                        tdls_link_vdev,
                        (unsigned int *)v43,
                        v155,
                        v156,
                        v157,
                        v158,
                        v159,
                        v160,
                        v161,
                        v162);
            if ( updated )
            {
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: ucfg_tdls_update_peer returned err %d",
                v164,
                v165,
                v166,
                v167,
                v168,
                v169,
                v170,
                v171,
                "wlan_cfg80211_tdls_update_peer",
                updated);
              v92 = -5;
            }
            else
            {
              if ( wait_for_completion_timeout(v154, 1250) )
              {
                if ( !v154[56] )
                {
                  v92 = 0;
                  goto LABEL_106;
                }
                qdf_trace_msg(
                  0x48u,
                  2u,
                  "%s: tdls update peer failed, status:%d",
                  v175,
                  v176,
                  v177,
                  v178,
                  v179,
                  v180,
                  v181,
                  v182,
                  "wlan_cfg80211_tdls_update_peer");
              }
              else
              {
                qdf_trace_msg(
                  0x48u,
                  2u,
                  "%s: timeout for tdls update peer indication %ld",
                  v175,
                  v176,
                  v177,
                  v178,
                  v179,
                  v180,
                  v181,
                  v182,
                  "wlan_cfg80211_tdls_update_peer",
                  0);
              }
              v92 = -1;
            }
LABEL_106:
            _qdf_mem_free(v43);
            goto LABEL_107;
          }
LABEL_105:
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: osif priv or tdls priv is NULL",
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            "wlan_cfg80211_tdls_update_peer");
          v92 = -22;
          goto LABEL_106;
        }
        v174 = *(const void **)(v191 + 192);
        if ( v174 )
        {
          qdf_mem_copy((void *)(v43 + 130), v174, 2u);
          goto LABEL_98;
        }
        v151 = "%s: 6 Ghz he_capa not present";
        v152 = "wlan_cfg80211_tdls_extract_6ghz_params";
      }
      else
      {
        v151 = "%s: he_capa not present";
        v152 = "wlan_cfg80211_tdls_extract_he_params";
      }
LABEL_97:
      qdf_trace_msg(0x48u, 8u, v151, v61, v62, v63, v64, v65, v66, v67, v68, v152);
      goto LABEL_98;
    }
LABEL_96:
    v151 = "%s: tdls ax disabled";
    v152 = "wlan_cfg80211_tdls_extract_params";
    goto LABEL_97;
  }
  if ( v3 )
  {
    v18 = *v3;
    v19 = v3[1];
    v20 = v3[2];
    v21 = v3[5];
  }
  else
  {
    v20 = 0;
    v18 = 0;
    v19 = 0;
    v21 = 0;
  }
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Invalid Mac address %02x:%02x:%02x:**:**:%02x cmd declined.",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "wlan_cfg80211_tdls_validate_mac_addr",
    v18,
    v19,
    v20,
    v21);
  v92 = -22;
LABEL_109:
  _ReadStatusReg(SP_EL0);
  return v92;
}
