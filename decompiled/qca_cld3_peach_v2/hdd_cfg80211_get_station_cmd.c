__int64 __fastcall hdd_cfg80211_get_station_cmd(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v6; // x22
  __int64 v7; // x20
  __int64 v8; // x0
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x22
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w19
  unsigned int v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  unsigned int v38; // w1
  __int64 v39; // x19
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  char v48; // w8
  int v49; // w9
  unsigned int v50; // w9
  int v51; // w10
  int v52; // w11
  bool v53; // zf
  int v54; // w8
  unsigned int v55; // w9
  unsigned int v56; // w8
  unsigned int v57; // w11
  unsigned int v58; // w8
  __int64 v59; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x21
  __int64 v69; // x23
  int v70; // w0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  const char *v79; // x2
  _WORD *v80; // x23
  unsigned int station_assoc_fail; // w0
  const char *v82; // x2
  unsigned int v83; // w1
  const char *v84; // x2
  unsigned int v85; // w1
  int v86; // w4
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  __int64 v95; // x21
  __int64 v96; // x24
  int v97; // w0
  _WORD *v98; // x21
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  const char *v107; // x2
  __int64 v108; // x21
  __int64 v109; // x24
  int v110; // w0
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  const char *v119; // x2
  _WORD *v120; // x25
  __int64 v121; // x21
  __int64 v122; // x24
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  _WORD *v131; // x26
  bool is_vdev_associated; // w0
  __int64 v133; // x8
  unsigned int v134; // w0
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  unsigned int v143; // w21
  unsigned int v144; // w24
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  const char *v153; // x2
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  __int64 v162; // x21
  __int64 v163; // x23
  int v164; // w0
  _WORD *v165; // x21
  char v166; // w8
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  unsigned int v175; // w8
  unsigned int v176; // w8
  char v177; // w8
  int v178; // w8
  unsigned int v179; // w10
  int v180; // w11
  unsigned int v181; // w14
  int v182; // w14
  __int64 *v183; // [xsp+40h] [xbp-40h] BYREF
  unsigned int v184; // [xsp+48h] [xbp-38h] BYREF
  unsigned __int16 v185; // [xsp+4Ch] [xbp-34h]
  __int64 v186; // [xsp+58h] [xbp-28h] BYREF
  __int64 v187; // [xsp+60h] [xbp-20h]
  __int64 v188; // [xsp+68h] [xbp-18h]
  __int64 v189; // [xsp+70h] [xbp-10h]
  __int64 v190; // [xsp+78h] [xbp-8h]

  v6 = a2;
  v7 = a4;
  v190 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a2 + 32);
  v183 = nullptr;
  result = _osif_vdev_sync_op_start(v8, &v183, (__int64)"hdd_cfg80211_get_station_cmd");
  if ( !(_DWORD)result )
  {
    if ( !a1 )
    {
      __break(0x800u);
      goto LABEL_111;
    }
    v18 = *(_QWORD *)(v6 + 32);
    v188 = 0;
    v189 = 0;
    v186 = 0;
    v187 = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__hdd_cfg80211_get_station_cmd",
      v18 + 296);
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "__hdd_cfg80211_get_station_cmd");
      v27 = -1;
LABEL_47:
      _osif_vdev_sync_op_stop((__int64)v183, (__int64)"hdd_cfg80211_get_station_cmd");
      result = v27;
      goto LABEL_48;
    }
    v27 = _wlan_hdd_validate_context(
            a1 + 1536,
            (__int64)"__hdd_cfg80211_get_station_cmd",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26);
    if ( v27 )
      goto LABEL_47;
    v28 = _nla_parse(&v186, 3, a3, (unsigned int)v7, &hdd_get_station_policy, 31, 0);
    if ( v28 )
    {
      v27 = v28;
      v37 = "%s: Invalid ATTR";
      v38 = 2;
LABEL_46:
      qdf_trace_msg(0x33u, v38, v37, v29, v30, v31, v32, v33, v34, v35, v36, "__hdd_cfg80211_get_station_cmd");
      goto LABEL_47;
    }
    if ( v187 )
    {
      v7 = *(_QWORD *)(v18 + 73880);
      if ( v7 )
      {
        v6 = *(_QWORD *)v7;
        v39 = *(_QWORD *)(*(_QWORD *)v7 + 24LL);
        if ( wlan_cm_is_vdev_disconnected(*(_QWORD *)(v7 + 32), v29, v30, v31, v32, v33, v34, v35, v36) )
        {
          if ( *(_DWORD *)(v7 + 1004) | *(unsigned __int16 *)(v7 + 1008) )
          {
            v48 = *(_BYTE *)(v7 + 1467);
            if ( (v48 & 2) != 0 )
              v49 = 20;
            else
              v49 = 4;
            v50 = v49 & 0xFFFFFFDF | (32 * (v48 & 1));
            if ( (*(_BYTE *)(v7 + 1467) & 0x10) != 0 )
              v51 = 172;
            else
              v51 = 144;
            v52 = *(_DWORD *)(v7 + 960);
            v53 = (v48 & 0x20) == 0;
            v54 = v48 & 8;
            v55 = v50 + v51;
            if ( !v53 )
              v55 += 12;
            v56 = v54 + ((*(_DWORD *)(v7 + 1528) + 7) & 0xFFFFFFFC);
            if ( v52 )
              v57 = (v52 + 7) & 0xFFFFFFFC;
            else
              v57 = 0;
            v58 = v56 + v57 + v55;
            if ( v58 != -8 )
            {
              v59 = _cfg80211_alloc_reply_skb(*(_QWORD *)(v39 + 24), 103, 197, v58 + 8);
              if ( !v59 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
                  v60,
                  v61,
                  v62,
                  v63,
                  v64,
                  v65,
                  v66,
                  v67,
                  "hdd_get_station_info");
                v27 = -12;
                goto LABEL_45;
              }
              v68 = *(_QWORD *)(v59 + 216);
              v69 = *(unsigned int *)(v59 + 208);
              a1 = v59;
              v70 = nla_put(v59, 32769, 0, 0);
              v79 = "%s: nla_nest_start failed";
              if ( v70 < 0 )
                goto LABEL_58;
              v80 = (_WORD *)(v68 + v69);
              if ( !v80 )
                goto LABEL_58;
              if ( (unsigned int)nla_put(a1, 52, *(unsigned __int8 *)(v7 + 1544), v7 + 1545) )
              {
                v79 = "%s: put fail";
LABEL_58:
                qdf_trace_msg(0x33u, 2u, v79, v71, v72, v73, v74, v75, v76, v77, v78, "hdd_add_link_standard_info");
                v107 = "%s: link_standard_info put fail";
LABEL_59:
                qdf_trace_msg(0x33u, 2u, v107, v10, v11, v12, v13, v14, v15, v16, v17, "hdd_populate_station_info_skb");
                sk_skb_reason_drop(0, a1, 2);
                goto LABEL_44;
              }
              if ( (unsigned int)nla_put(a1, 6, 6, v7 + 1004) )
              {
                v79 = "%s: put bssid failed";
                goto LABEL_58;
              }
              v95 = *(_QWORD *)(a1 + 216);
              v96 = *(unsigned int *)(a1 + 208);
              v97 = nla_put(a1, 32852, 0, 0);
              v79 = "%s: hdd_add_survey_info failed";
              if ( v97 < 0 )
                goto LABEL_58;
              v98 = (_WORD *)(v95 + v96);
              if ( !v98 )
                goto LABEL_58;
              v184 = *(_DWORD *)(v7 + 1396);
              if ( (unsigned int)nla_put(a1, 1, 4, &v184)
                || (LOBYTE(v184) = *(_BYTE *)(v7 + 1428) + 100, (unsigned int)nla_put(a1, 2, 1, &v184)) )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: put fail",
                  v99,
                  v100,
                  v101,
                  v102,
                  v103,
                  v104,
                  v105,
                  v106,
                  "hdd_add_survey_info");
                v79 = "%s: hdd_add_survey_info failed";
                goto LABEL_58;
              }
              *v98 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v98;
              v108 = *(_QWORD *)(a1 + 216);
              v109 = *(unsigned int *)(a1 + 208);
              v110 = nla_put(a1, 32789, 0, 0);
              v119 = "%s: nla_nest_start failed";
              if ( v110 < 0 || (v120 = (_WORD *)(v108 + v109)) == nullptr )
              {
LABEL_79:
                qdf_trace_msg(0x33u, 2u, v119, v111, v112, v113, v114, v115, v116, v117, v118, "hdd_add_sta_info");
                v79 = "%s: hdd_add_sta_info failed";
                goto LABEL_58;
              }
              LOBYTE(v184) = *(_BYTE *)(v7 + 1536) + 100;
              if ( (unsigned int)nla_put(a1, 7, 1, &v184) )
              {
                v119 = "%s: put fail";
                goto LABEL_79;
              }
              if ( hdd_cm_is_vdev_associated((_DWORD *)v7) )
                hdd_get_max_tx_bitrate(v7);
              v121 = *(_QWORD *)(a1 + 216);
              v122 = *(unsigned int *)(a1 + 208);
              if ( (nla_put(a1, 32776, 0, 0) & 0x80000000) != 0 || (v131 = (_WORD *)(v121 + v122)) == nullptr )
              {
                v153 = "%s: nla_nest_start failed";
LABEL_77:
                qdf_trace_msg(0x33u, 2u, v153, v123, v124, v125, v126, v127, v128, v129, v130, "hdd_add_tx_bitrate");
                goto LABEL_78;
              }
              is_vdev_associated = hdd_cm_is_vdev_associated((_DWORD *)v7);
              v133 = 1400;
              if ( is_vdev_associated )
                v133 = 1640;
              v134 = cfg80211_calculate_bitrate(v7 + v133);
              v143 = v134;
              if ( v134 >= 0x10000 )
                v144 = 0;
              else
                v144 = v134;
              if ( v134 )
              {
                v184 = v134;
                if ( (unsigned int)nla_put(a1, 5, 4, &v184) )
                {
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: put fail bitrate: %u",
                    v145,
                    v146,
                    v147,
                    v148,
                    v149,
                    v150,
                    v151,
                    v152,
                    "hdd_add_tx_bitrate",
                    v143);
LABEL_78:
                  v119 = "%s: hdd_add_tx_bitrate failed";
                  goto LABEL_79;
                }
              }
              else
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Invalid bitrate: %u",
                  v135,
                  v136,
                  v137,
                  v138,
                  v139,
                  v140,
                  v141,
                  v142,
                  "hdd_add_tx_bitrate",
                  0);
              }
              if ( v144 )
              {
                LOWORD(v184) = v144;
                if ( (unsigned int)nla_put(a1, 1, 2, &v184) )
                {
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: put fail bitrate_compat: %u",
                    v154,
                    v155,
                    v156,
                    v157,
                    v158,
                    v159,
                    v160,
                    v161,
                    "hdd_add_tx_bitrate",
                    v144);
                  goto LABEL_78;
                }
              }
              else
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Invalid bitrate_compat: %u",
                  v145,
                  v146,
                  v147,
                  v148,
                  v149,
                  v150,
                  v151,
                  v152,
                  "hdd_add_tx_bitrate",
                  0);
              }
              LOBYTE(v184) = *(_BYTE *)(v7 + 1692);
              if ( (unsigned int)nla_put(a1, 7, 1, &v184) )
              {
                v153 = "%s: put fail";
                goto LABEL_77;
              }
              *v131 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v131;
              qdf_trace_msg(
                0x33u,
                8u,
                "STA Tx rate info:: bitrate:%d, bitrate_compat:%d, NSS:%d",
                v123,
                v124,
                v125,
                v126,
                v127,
                v128,
                v129,
                v130,
                v143,
                v144,
                *(unsigned __int8 *)(v7 + 1692));
              *v120 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v120;
              *v80 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v80;
              v162 = *(_QWORD *)(a1 + 216);
              v163 = *(unsigned int *)(a1 + 208);
              v164 = nla_put(a1, 32770, 0, 0);
              v107 = "%s: ap standard info fail";
              if ( v164 < 0 )
                goto LABEL_59;
              v165 = (_WORD *)(v162 + v163);
              if ( !v165 )
                goto LABEL_59;
              v166 = *(_BYTE *)(v7 + 1467);
              if ( (v166 & 2) != 0 )
              {
                if ( (unsigned int)nla_put(a1, 157, 12, v7 + 1455) )
                {
LABEL_94:
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: put fail",
                    v167,
                    v168,
                    v169,
                    v170,
                    v171,
                    v172,
                    v173,
                    v174,
                    "hdd_add_ap_standard_info");
                  v107 = "%s: ap standard info fail";
                  goto LABEL_59;
                }
                qdf_trace_msg(0x33u, 8u, "STA VHT capabilities:", v167, v168, v169, v170, v171, v172, v173, v174);
                ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(51, 8, v7 + 1455, 12);
                v166 = *(_BYTE *)(v7 + 1467);
              }
              if ( (v166 & 1) != 0 )
              {
                if ( (unsigned int)nla_put(a1, 31, 26, v7 + 1429) )
                  goto LABEL_94;
                qdf_trace_msg(0x33u, 8u, "STA HT capabilities:", v167, v168, v169, v170, v171, v172, v173, v174);
                ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(51, 8, v7 + 1429, 26);
              }
              *v165 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v165;
              v184 = *(_DWORD *)(v7 + 1532);
              if ( (unsigned int)nla_put(a1, 3, 4, &v184)
                || ((v175 = *(_DWORD *)(v7 + 1584) - 1, v175 > 0x1D) ? (v176 = 0) : (v176 = dword_B2D538[v175]),
                    (v184 = v176, (unsigned int)nla_put(a1, 4, 4, &v184))
                 || (v184 = hdd_convert_dot11mode(*(unsigned int *)(v7 + 1384)), (unsigned int)nla_put(a1, 5, 4, &v184))) )
              {
                v107 = "%s: Roam, AKM, dot11mode put fail";
                goto LABEL_59;
              }
              v177 = *(_BYTE *)(v7 + 1467);
              if ( (v177 & 0x10) != 0 )
              {
                if ( (unsigned int)nla_put(a1, 7, 22, v7 + 1472) )
                {
                  v107 = "%s: ht operation put fail";
                  goto LABEL_59;
                }
                qdf_trace_msg(0x33u, 8u, "STA HT operation:", v10, v11, v12, v13, v14, v15, v16, v17);
                ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(51, 8, v7 + 1472, 22);
                v177 = *(_BYTE *)(v7 + 1467);
              }
              if ( (v177 & 0x20) == 0 )
              {
LABEL_112:
                if ( (unsigned int)hdd_add_he_oper_info(a1, v7 + 80) )
                {
                  v107 = "%s: he operation info put fail";
                  goto LABEL_59;
                }
                v178 = *(char *)(v7 + 1467);
                if ( v178 < 0 )
                {
                  if ( (unsigned int)hdd_add_eht_oper_info(a1, v7 + 80) )
                  {
                    v107 = "%s: eht operation info put fail";
                    goto LABEL_59;
                  }
                  if ( (*(_BYTE *)(v7 + 1467) & 8) != 0 )
                    goto LABEL_116;
                }
                else if ( (v178 & 8) != 0 )
                {
LABEL_116:
                  if ( (unsigned int)nla_put(a1, 6, 3, v7 + 1469) )
                  {
                    v107 = "%s: hs20 put fail";
                    goto LABEL_59;
                  }
                  qdf_trace_msg(0x33u, 8u, "STA hs20 vendor IE:", v10, v11, v12, v13, v14, v15, v16, v17);
                  ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(51, 8, v7 + 1469, 3);
                }
                v184 = *(_DWORD *)(*(_QWORD *)v7 + 52400LL);
                if ( (unsigned int)nla_put(a1, 37, 4, &v184) )
                {
                  v107 = "%s: Failed to put disconnect reason";
                  goto LABEL_59;
                }
                if ( (unsigned int)hdd_add_prev_connected_bss_ies(a1, v7 + 80) )
                {
                  v107 = "%s: disconnect_reason put fail";
                  goto LABEL_59;
                }
                if ( (unsigned int)hdd_add_associated_bw(a1, v7 + 80) )
                {
                  v107 = "%s: associated bw put fail";
                  goto LABEL_59;
                }
                v179 = *(_DWORD *)(v7 + 1584) - 1;
                if ( v179 > 0x1D )
                  v180 = 0;
                else
                  v180 = dword_B2D538[v179];
                v181 = *(_DWORD *)(v7 + 1384) - 1;
                if ( v181 > 0xB )
                  v182 = 7;
                else
                  v182 = dword_B2D5B0[v181];
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "STA Info:: SSID:%.*s, BSSID:%02x:%02x:%02x:**:**:%02x, freq:%d, Noise:%d, signal:%d, roam_count:%d, la"
                  "st_auth_type:%d, dot11mode:%d, disconnect_reason:%d, ",
                  v10,
                  v11,
                  v12,
                  v13,
                  v14,
                  v15,
                  v16,
                  v17,
                  32,
                  v7 + 1545,
                  *(unsigned __int8 *)(v7 + 1004),
                  *(unsigned __int8 *)(v7 + 1005),
                  *(unsigned __int8 *)(v7 + 1006),
                  *(unsigned __int8 *)(v7 + 1009),
                  *(_DWORD *)(v7 + 1396),
                  *(char *)(v7 + 1428) + 100,
                  *(char *)(v7 + 1536) + 100,
                  *(_DWORD *)(v7 + 1532),
                  v180,
                  v182,
                  *(_DWORD *)(v6 + 52400));
                station_assoc_fail = cfg80211_vendor_cmd_reply(a1);
LABEL_31:
                v27 = station_assoc_fail;
LABEL_45:
                v37 = "%s: exit";
                v38 = 8;
                goto LABEL_46;
              }
              if ( (unsigned int)nla_put(a1, 8, 5, v7 + 1494) )
              {
                v107 = "%s: vht operation put fail";
                goto LABEL_59;
              }
LABEL_111:
              qdf_trace_msg(0x33u, 8u, "STA VHT operation:", v10, v11, v12, v13, v14, v15, v16, v17);
              ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(51, 8, v7 + 1494, 5);
              goto LABEL_112;
            }
            v84 = "%s: BSS ie size calculation failed";
          }
          else
          {
            v84 = "%s: Connection never happened";
          }
          v85 = 2;
        }
        else
        {
          v84 = "%s: Station is not in disconnect state, command is not supported";
          v85 = 8;
        }
        qdf_trace_msg(0x33u, v85, v84, v40, v41, v42, v43, v44, v45, v46, v47, "hdd_get_station_info");
LABEL_44:
        v27 = -22;
        goto LABEL_45;
      }
      v82 = "%s: link_info NULL";
      v83 = 8;
    }
    else
    {
      if ( v188 )
      {
        station_assoc_fail = hdd_get_station_assoc_fail(*(_QWORD *)(v18 + 55520));
        goto LABEL_31;
      }
      if ( v189 )
      {
        v86 = *(_DWORD *)(v18 + 2728);
        v185 = 0;
        v184 = 0;
        if ( (v86 | 2) == 3 )
        {
          nla_memcpy(&v184, v189, 6);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: STATION_REMOTE %02x:%02x:%02x:**:**:%02x",
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            v93,
            v94,
            "__hdd_cfg80211_get_station_cmd",
            (unsigned __int8)v184,
            BYTE1(v184),
            BYTE2(v184),
            HIBYTE(v185));
          station_assoc_fail = hdd_get_station_remote(*(_QWORD *)(v18 + 55520), v184 | ((unsigned __int64)v185 << 32));
          goto LABEL_31;
        }
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: invalid device_mode:%d",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "__hdd_cfg80211_get_station_cmd");
LABEL_34:
        v27 = -22;
        goto LABEL_47;
      }
      v82 = "%s: get station info cmd type failed";
      v83 = 2;
    }
    qdf_trace_msg(0x33u, v83, v82, v29, v30, v31, v32, v33, v34, v35, v36, "__hdd_cfg80211_get_station_cmd");
    goto LABEL_34;
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
