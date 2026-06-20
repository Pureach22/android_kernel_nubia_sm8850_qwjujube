__int64 __fastcall wlan_cfg80211_tdls_update_peer(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
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
  __int64 v30; // x8
  __int64 v31; // x21
  __int64 v32; // x0
  __int64 v33; // x20
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w4
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x19
  __int64 v60; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned int v77; // w8
  unsigned int v78; // w25
  __int64 v79; // x23
  __int64 v80; // x20
  __int64 result; // x0
  unsigned __int8 v82; // w20
  unsigned __int8 v83; // w24
  __int64 v84; // x0
  unsigned __int8 *v85; // x19
  unsigned int v86; // w0
  unsigned int v87; // w27
  unsigned __int64 v88; // x8
  int v89; // w11
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  unsigned int v98; // w8
  unsigned int v99; // w28
  int v100; // w21
  int v101; // w22
  unsigned int v102; // w26
  unsigned int v103; // w0
  unsigned int v104; // w27
  unsigned __int64 v105; // x8
  int v106; // w10
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  unsigned int v115; // w8
  size_t v116; // x2
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  unsigned __int64 v125; // x23
  int v126; // w8
  unsigned int v127; // w4
  const char *v128; // x2
  const char *v129; // x3
  __int64 v130; // x8
  _DWORD *v131; // x21
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  unsigned int updated; // w0
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  unsigned int v149; // w19
  size_t v150; // x2
  const void *v151; // x1
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  unsigned int *v168; // x22
  __int64 v169; // x20
  unsigned int v170; // t1
  char is_fw_6g_capable; // [xsp+4h] [xbp-6Ch]
  __int64 v172; // [xsp+8h] [xbp-68h]
  __int64 v173; // [xsp+10h] [xbp-60h]
  unsigned __int8 *v174; // [xsp+18h] [xbp-58h]
  char is_fw_11ax_capable; // [xsp+24h] [xbp-4Ch]
  __int64 v176; // [xsp+28h] [xbp-48h]
  __int64 v177; // [xsp+30h] [xbp-40h]
  unsigned __int64 v178; // [xsp+38h] [xbp-38h]
  __int64 v179; // [xsp+40h] [xbp-30h]
  unsigned int v180; // [xsp+4Ch] [xbp-24h]
  __int64 v181; // [xsp+50h] [xbp-20h]
  unsigned int *v182; // [xsp+58h] [xbp-18h]
  __int16 v183; // [xsp+64h] [xbp-Ch] BYREF
  unsigned __int8 v184; // [xsp+66h] [xbp-Ah]
  __int64 v185; // [xsp+68h] [xbp-8h]

  v185 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !(unsigned int)qdf_mem_cmp(a2, &wlan_cfg80211_tdls_validate_mac_addr_temp_mac, 6u) )
  {
    if ( a2 )
    {
      v18 = *a2;
      v19 = a2[1];
      v20 = a2[2];
      v21 = a2[5];
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
    goto LABEL_63;
  }
  if ( a2 )
  {
    v14 = *a2;
    v15 = a2[1];
    v16 = a2[2];
    v17 = a2[5];
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
  v30 = *(_QWORD *)(a1 + 152);
  if ( !v30 || (v31 = *(_QWORD *)(v30 + 80)) == 0 )
  {
    v80 = jiffies;
    if ( wlan_cfg80211_tdls_update_peer___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Invalid psoc",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wlan_cfg80211_tdls_update_peer");
      result = 0;
      wlan_cfg80211_tdls_update_peer___last_ticks = v80;
    }
    else
    {
      result = 0;
    }
    goto LABEL_96;
  }
  v174 = a2;
  v32 = _qdf_mem_malloc(0x23Cu, "wlan_cfg80211_tdls_update_peer", 727);
  if ( !v32 )
  {
LABEL_63:
    result = 4294967274LL;
    goto LABEL_96;
  }
  v33 = v32;
  is_fw_11ax_capable = ucfg_tdls_is_fw_11ax_capable(v31);
  is_fw_6g_capable = ucfg_tdls_is_fw_6g_capable(v31);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: sta cap %d, uapsd_queue %d, max_sp %d",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    "wlan_cfg80211_tdls_extract_params",
    *(unsigned __int16 *)(a3 + 40),
    *(unsigned __int8 *)(a3 + 32),
    *(unsigned __int8 *)(a3 + 33));
  *(_WORD *)(v33 + 16) = *(_WORD *)(a3 + 40);
  *(_BYTE *)(v33 + 132) = *(_BYTE *)(a3 + 32);
  *(_BYTE *)(v33 + 133) = *(_BYTE *)(a3 + 33);
  v50 = *(unsigned __int8 *)(a3 + 88);
  if ( v50 >= 0x21 )
  {
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: received oper classes:%d, resetting it to max supported: %d",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "wlan_cfg80211_tdls_extract_params");
    v50 = 32;
    *(_BYTE *)(a3 + 88) = 32;
  }
  qdf_mem_copy((void *)(v33 + 537), *(const void **)(a3 + 80), v50);
  v176 = a1;
  v177 = a3;
  *(_BYTE *)(v33 + 536) = *(_BYTE *)(a3 + 88);
  if ( !*(_BYTE *)(a3 + 72) )
    goto LABEL_65;
  v184 = 0;
  v183 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: null vdev",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "tdls_calc_channels_from_staparams");
    goto LABEL_65;
  }
  v59 = *(_QWORD *)(a1 + 152);
  if ( !v59 || (v60 = *(_QWORD *)(v59 + 80)) == 0 )
  {
LABEL_65:
    if ( !*(_BYTE *)(a3 + 56) )
      goto LABEL_67;
    goto LABEL_66;
  }
  v179 = *(_QWORD *)(a3 + 64);
  v172 = *(_QWORD *)(a3 + 80);
  wlan_reg_read_current_country(v60, &v183, v51, v52, v53, v54, v55, v56, v57, v58);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Country info from AP:%c%c 0x%x",
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    "tdls_calc_channels_from_staparams",
    (unsigned __int8)v183,
    HIBYTE(v183),
    v184);
  v77 = *(unsigned __int8 *)(a3 + 88);
  if ( !*(_BYTE *)(a3 + 88) )
  {
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Unique Channel List: supported_channels ",
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      "tdls_calc_channels_from_staparams");
    v78 = 0;
    goto LABEL_113;
  }
  v78 = 0;
  v79 = v33 + 140;
  v178 = 0;
  v182 = (unsigned int *)(v33 + 136);
  v173 = v33;
  v181 = v59;
  do
  {
    v180 = *(unsigned __int8 *)(a3 + 72);
    if ( *(_BYTE *)(a3 + 72) && v78 <= 0x63 )
    {
      v82 = 0;
      v83 = *(_BYTE *)(v172 + v178);
      while ( 1 )
      {
        v84 = v59;
        v85 = (unsigned __int8 *)(v179 + v82);
        v86 = wlan_reg_country_chan_opclass_to_freq(
                v84,
                (unsigned __int8 *)&v183,
                *v85,
                v83,
                0,
                v69,
                v70,
                v71,
                v72,
                v73,
                v74,
                v75,
                v76);
        if ( v86 )
        {
          v87 = v86;
          if ( v78 )
          {
            if ( *v182 == v86 )
              goto LABEL_56;
            v88 = 0;
            while ( v78 - 1LL != v88 )
            {
              v89 = *(_DWORD *)(v79 + 4 * v88++);
              if ( v89 == v86 )
              {
                if ( v88 < v78 )
                  goto LABEL_56;
                break;
              }
            }
          }
          if ( wlan_reg_is_6ghz_chan_freq(v86) && (tdls_is_6g_freq_allowed(v181, v87) & 1) == 0 )
          {
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: skipping non-psc or non-vlp freq %d",
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              v96,
              v97,
              "tdls_fill_chan_freq_from_supported_ch_list",
              v87);
          }
          else
          {
            v98 = *v85;
            v99 = v85[1];
            v182[v78] = v87;
            v100 = *v85;
            if ( v98 < 0xF )
              v101 = 1;
            else
              v101 = 4;
            qdf_trace_msg(
              0x48u,
              8u,
              "%s: freq %d index %d ",
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              v96,
              v97,
              "tdls_fill_chan_freq_from_supported_ch_list",
              v87,
              v78 + 1);
            if ( v99 >= 2 && v78 <= 0x62 )
            {
              ++v78;
              v59 = v181;
              v102 = 1;
              do
              {
                v100 += v101;
                v103 = wlan_reg_country_chan_opclass_to_freq(
                         v59,
                         (unsigned __int8 *)&v183,
                         v100,
                         v83,
                         0,
                         v69,
                         v70,
                         v71,
                         v72,
                         v73,
                         v74,
                         v75,
                         v76);
                if ( v103 )
                {
                  v104 = v103;
                  if ( *v182 != v103 )
                  {
                    v105 = 0;
                    while ( v78 - 1LL != v105 )
                    {
                      v106 = *(_DWORD *)(v79 + 4 * v105++);
                      if ( v106 == v103 )
                      {
                        if ( v105 < v78 )
                          goto LABEL_50;
                        break;
                      }
                    }
                    if ( wlan_reg_is_6ghz_chan_freq(v103) && (tdls_is_6g_freq_allowed(v181, v104) & 1) == 0 )
                    {
                      qdf_trace_msg(
                        0x48u,
                        8u,
                        "%s: skipping non-psc or non-vlp freq %d",
                        v107,
                        v108,
                        v109,
                        v110,
                        v111,
                        v112,
                        v113,
                        v114,
                        "tdls_fill_chan_freq_from_supported_ch_list",
                        v104);
                    }
                    else
                    {
                      v182[v78] = v104;
                      qdf_trace_msg(
                        0x48u,
                        8u,
                        "%s: freq %d index %d ",
                        v107,
                        v108,
                        v109,
                        v110,
                        v111,
                        v112,
                        v113,
                        v114,
                        "tdls_fill_chan_freq_from_supported_ch_list",
                        v104,
                        v78++);
                    }
LABEL_50:
                    v59 = v181;
                  }
                }
                ++v102;
              }
              while ( v102 < v99 && v78 < 0x64 );
              goto LABEL_57;
            }
            ++v78;
          }
        }
LABEL_56:
        v59 = v181;
LABEL_57:
        v82 += 2;
        if ( v180 <= v82 || v78 >= 0x64 )
        {
          a3 = v177;
          v33 = v173;
          v77 = *(unsigned __int8 *)(v177 + 88);
          break;
        }
      }
    }
    ++v178;
  }
  while ( v178 < v77 );
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Unique Channel List: supported_channels ",
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    v76,
    "tdls_calc_channels_from_staparams");
  if ( v78 )
  {
    v168 = v182;
    v169 = v78;
    do
    {
      v170 = *v168++;
      qdf_trace_msg(
        0x48u,
        8u,
        "%s:  %d,",
        v160,
        v161,
        v162,
        v163,
        v164,
        v165,
        v166,
        v167,
        "tdls_calc_channels_from_staparams",
        v170);
      --v169;
    }
    while ( v169 );
    v33 = v173;
  }
LABEL_113:
  *(_BYTE *)(v33 + 134) = v78;
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: After removing duplcates supported_channels_len: %d",
    v160,
    v161,
    v162,
    v163,
    v164,
    v165,
    v166,
    v167,
    "tdls_calc_channels_from_staparams",
    v78);
  if ( *(_BYTE *)(a3 + 56) )
LABEL_66:
    qdf_mem_copy((void *)(v33 + 18), *(const void **)(a3 + 48), 8u);
LABEL_67:
  if ( *(_QWORD *)(a3 + 144) )
  {
    *(_BYTE *)(v33 + 59) = 1;
    qdf_mem_copy((void *)(v33 + 60), *(const void **)(a3 + 144), 0x1Au);
  }
  v115 = *(unsigned __int8 *)(a3 + 136);
  if ( v115 >= 0x20 )
    v116 = 32;
  else
    v116 = *(unsigned __int8 *)(a3 + 136);
  *(_BYTE *)(v33 + 26) = v116;
  if ( v115 )
  {
    qdf_mem_copy((void *)(v33 + 27), *(const void **)(v177 + 128), v116);
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Supported Rates with Length %d",
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      "wlan_cfg80211_tdls_extract_params",
      *(unsigned __int8 *)(v33 + 26));
    if ( *(_BYTE *)(v33 + 26) )
    {
      v125 = 0;
      do
      {
        if ( v125 == 32 )
          __break(0x5512u);
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: [%d]: %0x",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "wlan_cfg80211_tdls_extract_params",
          (unsigned int)v125,
          *(unsigned __int8 *)(v33 + 27 + v125));
        ++v125;
      }
      while ( v125 < *(unsigned __int8 *)(v33 + 26) );
    }
  }
  if ( *(_QWORD *)(v177 + 152) )
  {
    *(_BYTE *)(v33 + 86) = 1;
    qdf_mem_copy((void *)(v33 + 88), *(const void **)(v177 + 152), 0xCu);
  }
  if ( *(_QWORD *)(v177 + 144) || *(_QWORD *)(v177 + 152) || (v126 = *(_DWORD *)(v177 + 12), (v126 & 8) != 0) )
  {
    *(_BYTE *)(v33 + 569) = 1;
    if ( (*(_DWORD *)(v177 + 12) & 0x10) != 0 )
      goto LABEL_87;
LABEL_83:
    if ( (is_fw_11ax_capable & 1) != 0 )
      goto LABEL_84;
LABEL_88:
    v128 = "%s: tdls ax disabled";
    v129 = "wlan_cfg80211_tdls_extract_params";
    goto LABEL_89;
  }
  if ( (v126 & 0x10) == 0 )
    goto LABEL_83;
LABEL_87:
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: TDLS peer pmf capable",
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    "wlan_cfg80211_tdls_extract_params");
  *(_BYTE *)(v33 + 570) = 1;
  if ( (is_fw_11ax_capable & 1) == 0 )
    goto LABEL_88;
LABEL_84:
  v127 = *(unsigned __int8 *)(v177 + 176);
  if ( v127 <= 0x10 )
  {
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: he_capa_len %d less than MIN_TDLS_HE_CAP_LEN",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "wlan_cfg80211_tdls_extract_he_params");
    goto LABEL_90;
  }
  if ( !*(_QWORD *)(v177 + 168) )
  {
    v128 = "%s: he_capa not present";
    v129 = "wlan_cfg80211_tdls_extract_he_params";
LABEL_89:
    qdf_trace_msg(0x48u, 8u, v128, v51, v52, v53, v54, v55, v56, v57, v58, v129);
    goto LABEL_90;
  }
  if ( v127 >= 0x1D )
    v150 = 29;
  else
    v150 = *(unsigned __int8 *)(v177 + 176);
  *(_BYTE *)(v33 + 100) = v150;
  qdf_mem_copy((void *)(v33 + 101), *(const void **)(v177 + 168), v150);
  if ( (is_fw_6g_capable & 1) != 0 )
  {
    v151 = *(const void **)(v177 + 192);
    if ( v151 )
    {
      qdf_mem_copy((void *)(v33 + 130), v151, 2u);
      goto LABEL_90;
    }
    v128 = "%s: 6 Ghz he_capa not present";
    v129 = "wlan_cfg80211_tdls_extract_6ghz_params";
    goto LABEL_89;
  }
LABEL_90:
  v130 = *(_QWORD *)(v176 + 608);
  if ( v130 && (v131 = *(_DWORD **)(v130 + 16)) != nullptr )
  {
    *(_DWORD *)(v33 + 12) = *(unsigned __int8 *)(v176 + 104);
    qdf_mem_copy((void *)v33, v174, 6u);
    *v131 = 0;
    updated = ucfg_tdls_update_peer(v176, (unsigned int *)v33, v132, v133, v134, v135, v136, v137, v138, v139);
    if ( updated )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: ucfg_tdls_update_peer returned err %d",
        v141,
        v142,
        v143,
        v144,
        v145,
        v146,
        v147,
        v148,
        "wlan_cfg80211_tdls_update_peer",
        updated);
      v149 = -5;
      goto LABEL_95;
    }
    if ( wait_for_completion_timeout(v131, 1250) )
    {
      if ( v131[56] )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: tdls update peer failed, status:%d",
          v152,
          v153,
          v154,
          v155,
          v156,
          v157,
          v158,
          v159,
          "wlan_cfg80211_tdls_update_peer");
        goto LABEL_116;
      }
      v149 = 0;
    }
    else
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: timeout for tdls update peer indication %ld",
        v152,
        v153,
        v154,
        v155,
        v156,
        v157,
        v158,
        v159,
        "wlan_cfg80211_tdls_update_peer",
        0);
LABEL_116:
      v149 = -1;
    }
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: osif priv or tdls priv is NULL",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "wlan_cfg80211_tdls_update_peer");
    v149 = -22;
  }
LABEL_95:
  _qdf_mem_free(v33);
  result = v149;
LABEL_96:
  _ReadStatusReg(SP_EL0);
  return result;
}
