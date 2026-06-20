__int64 __fastcall hdd_get_station_remote(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x22
  __int64 v12; // x21
  __int64 *sta_info_by_mac; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int64 v22; // x9
  __int64 v23; // x10
  __int64 *v24; // x19
  __int64 *v25; // x21
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 peer_stats; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w8
  int v44; // w24
  __int64 *v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int v54; // w8
  int v55; // w9
  int v56; // w9
  __int64 v57; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x23
  __int64 v67; // x21
  __int64 v68; // x25
  int v69; // w24
  __int64 v70; // x19
  int v71; // w0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  const char *v80; // x2
  _WORD *v81; // x21
  __int64 v82; // x25
  __int64 v83; // x26
  int v84; // w0
  _WORD *v85; // x25
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  const char *v94; // x2
  const char *v95; // x3
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  unsigned int v104; // w19
  __int64 v105; // x20
  unsigned int v106; // w20
  __int64 v107; // x0
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  __int64 v116; // x20
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  double v149; // d0
  double v150; // d1
  double v151; // d2
  double v152; // d3
  double v153; // d4
  double v154; // d5
  double v155; // d6
  double v156; // d7
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  __int64 v174; // x25
  __int64 v175; // x26
  int v176; // w0
  _WORD *v177; // x25
  __int64 v178; // x26
  __int64 v179; // x27
  int v180; // w0
  _WORD *v181; // x26
  double v182; // d0
  double v183; // d1
  double v184; // d2
  double v185; // d3
  double v186; // d4
  double v187; // d5
  double v188; // d6
  double v189; // d7
  __int64 v190; // x23
  __int64 v191; // x21
  __int64 v192; // x24
  int v193; // w0
  _WORD *v194; // x21
  double v195; // d0
  double v196; // d1
  double v197; // d2
  double v198; // d3
  double v199; // d4
  double v200; // d5
  double v201; // d6
  double v202; // d7
  __int64 v203; // x8
  int v204; // w4
  int v205; // w23
  int v206; // w21
  __int64 v207; // x8
  __int64 v208; // x2
  double v209; // d0
  double v210; // d1
  double v211; // d2
  double v212; // d3
  double v213; // d4
  double v214; // d5
  double v215; // d6
  double v216; // d7
  double v217; // d0
  double v218; // d1
  double v219; // d2
  double v220; // d3
  double v221; // d4
  double v222; // d5
  double v223; // d6
  double v224; // d7
  unsigned int v231; // w10
  __int64 *v232; // [xsp+30h] [xbp-30h] BYREF
  unsigned int v233; // [xsp+38h] [xbp-28h] BYREF
  _BYTE v234[4]; // [xsp+3Ch] [xbp-24h] BYREF
  __int64 *v235; // [xsp+40h] [xbp-20h] BYREF
  unsigned int v236; // [xsp+48h] [xbp-18h] BYREF
  unsigned __int16 v237; // [xsp+4Ch] [xbp-14h]
  unsigned int v238; // [xsp+50h] [xbp-10h] BYREF
  __int16 v239; // [xsp+54h] [xbp-Ch]
  __int64 v240; // [xsp+58h] [xbp-8h]

  v240 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *a1;
  v236 = a2;
  v237 = WORD2(a2);
  v12 = *(_QWORD *)(v11 + 24);
  sta_info_by_mac = hdd_get_sta_info_by_mac(
                      (__int64 **)(v11 + 38848),
                      (unsigned __int8 *)&v236,
                      0xAu,
                      3u,
                      a3,
                      a4,
                      a5,
                      a6,
                      a7,
                      a8,
                      a9,
                      a10);
  v232 = sta_info_by_mac;
  v22 = v236 | ((unsigned __int64)v237 << 32);
  if ( sta_info_by_mac )
  {
    v23 = *a1;
    v238 = v236;
    v24 = sta_info_by_mac;
    v239 = WORD2(v22);
    v25 = *(__int64 **)(v23 + 24);
    v234[0] = 0;
    v233 = 0;
    if ( (unsigned int)wlan_mlme_get_sap_get_peer_info(*v25, v234) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Unable to fetch sap ger peer info",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "hdd_get_connected_station_info");
    if ( v234[0] == 1 )
    {
      peer_stats = wlan_cfg80211_mc_cp_stats_get_peer_stats(a1[4], &v238, &v233, v26, v27, v28, v29, v30, v31, v32, v33);
      if ( !v233 && peer_stats )
      {
        *((_DWORD *)v24 + 32) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 56LL);
        *((_DWORD *)v24 + 33) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 64LL);
        *((_DWORD *)v24 + 18) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 8LL);
        v24[10] = *(_QWORD *)(*(_QWORD *)(peer_stats + 160) + 16LL);
        *((_DWORD *)v24 + 22) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 24LL);
        v24[12] = *(_QWORD *)(*(_QWORD *)(peer_stats + 160) + 32LL);
        *((_DWORD *)v24 + 125) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 128LL);
        *((_DWORD *)v24 + 126) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 132LL);
        wlan_cfg80211_mc_cp_stats_free_stats_event(peer_stats);
        v43 = 106;
        v44 = 1;
        goto LABEL_28;
      }
      v105 = peer_stats;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: fail to get tx/rx rate",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "hdd_get_connected_station_info");
      wlan_cfg80211_mc_cp_stats_free_stats_event(v105);
    }
    v44 = 0;
    v43 = 74;
LABEL_28:
    if ( *((_BYTE *)v24 + 152) )
      v106 = v43 + 28;
    else
      v106 = v43;
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: buflen %d hdrlen %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "hdd_get_connected_station_info",
      v106,
      16);
    v107 = _cfg80211_alloc_reply_skb(v25[3], 103, 197, v106);
    if ( !v107 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        "hdd_get_connected_station_info");
      v104 = -12;
      goto LABEL_43;
    }
    v116 = v107;
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: stainfo",
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      v115,
      "hdd_get_connected_station_info");
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: maxrate %x tx_pkts %x tx_bytes %llx",
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      "hdd_get_connected_station_info",
      *((unsigned int *)v24 + 17),
      *((unsigned int *)v24 + 18),
      v24[10]);
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: rx_pkts %x rx_bytes %llx mode %x",
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      v131,
      v132,
      "hdd_get_connected_station_info",
      *((unsigned int *)v24 + 22),
      v24[12],
      *((unsigned __int8 *)v24 + 152));
    if ( *((_BYTE *)v24 + 152) )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: ampdu %d tx_stbc %d rx_stbc %d",
        v133,
        v134,
        v135,
        v136,
        v137,
        v138,
        v139,
        v140,
        "hdd_get_connected_station_info",
        *((unsigned __int8 *)v24 + 136),
        *((unsigned __int8 *)v24 + 144),
        *((unsigned __int8 *)v24 + 145));
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: wmm %d chwidth %d sgi %d",
        v141,
        v142,
        v143,
        v144,
        v145,
        v146,
        v147,
        v148,
        "hdd_get_connected_station_info",
        *((unsigned __int8 *)v24 + 48),
        *((unsigned int *)v24 + 37),
        *((unsigned __int8 *)v24 + 137));
    }
    LODWORD(v235) = *((_DWORD *)v24 + 17);
    if ( (unsigned int)nla_put(v116, 10, 4, &v235)
      || (LODWORD(v235) = *((_DWORD *)v24 + 18), (unsigned int)nla_put(v116, 11, 4, &v235))
      || (v235 = (__int64 *)v24[10], (unsigned int)nla_put_64bit(v116, 12, 8, &v235, 24))
      || (LODWORD(v235) = *((_DWORD *)v24 + 22), (unsigned int)nla_put(v116, 13, 4, &v235))
      || (v235 = (__int64 *)v24[12], (unsigned int)nla_put_64bit(v116, 14, 8, &v235, 24))
      || (LOBYTE(v235) = *((_BYTE *)v24 + 48), (unsigned int)nla_put(v116, 17, 1, &v235))
      || (LOBYTE(v235) = *((_BYTE *)v24 + 152), (unsigned int)nla_put(v116, 18, 1, &v235)) )
    {
LABEL_41:
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: put fail",
        v149,
        v150,
        v151,
        v152,
        v153,
        v154,
        v155,
        v156,
        "hdd_get_connected_station_info");
      sk_skb_reason_drop(0, v116, 2);
      v104 = -22;
LABEL_43:
      hdd_put_sta_info_ref(v11 + 38848, (__int64 *)&v232, 1, 0xAu, v157, v158, v159, v160, v161, v162, v163, v164);
      goto LABEL_44;
    }
    if ( v44 )
    {
      LODWORD(v235) = *((_DWORD *)v24 + 32);
      if ( (unsigned int)nla_put(v116, 15, 4, &v235) )
        goto LABEL_41;
      LODWORD(v235) = *((_DWORD *)v24 + 33);
      if ( (unsigned int)nla_put(v116, 16, 4, &v235) )
        goto LABEL_41;
      LODWORD(v235) = *((_DWORD *)v24 + 125);
      if ( (unsigned int)nla_put(v116, 31, 4, &v235) )
        goto LABEL_41;
      LODWORD(v235) = *((_DWORD *)v24 + 126);
      if ( (unsigned int)nla_put(v116, 32, 4, &v235) )
        goto LABEL_41;
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: tx_rate %d rx_rate %d tx_retries_ratio %d tx_failed_retrylimit %d",
        v149,
        v150,
        v151,
        v152,
        v153,
        v154,
        v155,
        v156,
        "hdd_get_connected_station_info",
        *((unsigned int *)v24 + 32),
        *((unsigned int *)v24 + 33),
        *((unsigned int *)v24 + 125),
        *((unsigned int *)v24 + 126));
    }
    if ( !*((_BYTE *)v24 + 152)
      || (LOBYTE(v235) = *((_BYTE *)v24 + 136), !(unsigned int)nla_put(v116, 19, 1, &v235))
      && (LOBYTE(v235) = *((_BYTE *)v24 + 144), !(unsigned int)nla_put(v116, 20, 1, &v235))
      && (LOBYTE(v235) = *((_BYTE *)v24 + 145), !(unsigned int)nla_put(v116, 21, 1, &v235))
      && (LOBYTE(v235) = *((_DWORD *)v24 + 37), !(unsigned int)nla_put(v116, 22, 1, &v235))
      && (LOBYTE(v235) = *((_BYTE *)v24 + 137), !(unsigned int)nla_put(v116, 23, 1, &v235)) )
    {
      v104 = cfg80211_vendor_cmd_reply(v116);
      goto LABEL_43;
    }
    goto LABEL_41;
  }
  v238 = v236;
  v239 = WORD2(v22);
  v45 = hdd_get_sta_info_by_mac(
          (__int64 **)(v11 + 38888),
          (unsigned __int8 *)&v238,
          9u,
          3u,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21);
  v235 = v45;
  if ( !v45 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: peer %02x:%02x:%02x:**:**:%02x not found",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "hdd_get_cached_station_remote",
      (unsigned __int8)v238,
      BYTE1(v238),
      BYTE2(v238),
      HIBYTE(v239));
    v104 = -22;
    goto LABEL_44;
  }
  if ( *((_BYTE *)v45 + 166) )
    v54 = 20;
  else
    v54 = 4;
  v55 = *((_DWORD *)v45 + 66);
  if ( *((_BYTE *)v45 + 165) )
    v54 += 30;
  if ( v55 )
    v56 = v55 + 4;
  else
    v56 = 0;
  v57 = _cfg80211_alloc_reply_skb(*(_QWORD *)(v12 + 24), 103, 197, (unsigned int)(v54 + v56 + 116));
  if ( !v57 )
  {
    hdd_put_sta_info_ref(v11 + 38888, (__int64 *)&v235, 1, 9u, v58, v59, v60, v61, v62, v63, v64, v65);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
      v166,
      v167,
      v168,
      v169,
      v170,
      v171,
      v172,
      v173,
      "hdd_get_cached_station_remote");
    v104 = -12;
    goto LABEL_44;
  }
  v66 = (__int64)v235;
  v67 = *(_QWORD *)(v57 + 216);
  v68 = *(unsigned int *)(v57 + 208);
  v69 = *((char *)v235 + 212);
  v70 = v57;
  v71 = nla_put(v57, 32769, 0, 0);
  v80 = "%s: link standard put fail";
  if ( v71 < 0 )
    goto LABEL_25;
  v81 = (_WORD *)(v67 + v68);
  if ( !v81 )
    goto LABEL_25;
  v82 = *(_QWORD *)(v70 + 216);
  v83 = *(unsigned int *)(v70 + 208);
  v84 = nla_put(v70, 32852, 0, 0);
  v80 = "%s: link standard put fail";
  if ( v84 < 0 )
    goto LABEL_25;
  v85 = (_WORD *)(v82 + v83);
  if ( !v85 )
    goto LABEL_25;
  v233 = *((_DWORD *)v235 + 40);
  if ( (unsigned int)nla_put(v70, 1, 4, &v233) )
  {
    v94 = "%s: put fail";
    v95 = "hdd_add_survey_info_sap";
LABEL_24:
    qdf_trace_msg(0x33u, 2u, v94, v86, v87, v88, v89, v90, v91, v92, v93, v95);
    v80 = "%s: link standard put fail";
LABEL_25:
    qdf_trace_msg(0x33u, 2u, v80, v72, v73, v74, v75, v76, v77, v78, v79, "hdd_get_cached_station_remote");
    hdd_put_sta_info_ref(v11 + 38888, (__int64 *)&v235, 1, 9u, v96, v97, v98, v99, v100, v101, v102, v103);
    sk_skb_reason_drop(0, v70, 2);
    v104 = -22;
    goto LABEL_44;
  }
  *v85 = *(_WORD *)(v70 + 216) + *(_DWORD *)(v70 + 208) - (_WORD)v85;
  qdf_trace_msg(0x33u, 8u, "Remote STA freq: %d", v86, v87, v88, v89, v90, v91, v92, v93, *(unsigned int *)(v66 + 160));
  v174 = *(_QWORD *)(v70 + 216);
  v175 = *(unsigned int *)(v70 + 208);
  v176 = nla_put(v70, 32789, 0, 0);
  v80 = "%s: link standard put fail";
  if ( v176 < 0 )
    goto LABEL_25;
  v177 = (_WORD *)(v174 + v175);
  if ( !v177 )
    goto LABEL_25;
  LOBYTE(v233) = v69;
  if ( (unsigned int)nla_put(v70, 7, 1, &v233) )
  {
    v94 = "%s: put fail";
    v95 = "hdd_add_sta_info_sap";
    goto LABEL_24;
  }
  v178 = *(_QWORD *)(v70 + 216);
  v179 = *(unsigned int *)(v70 + 208);
  v180 = nla_put(v70, 32776, 0, 0);
  v80 = "%s: link standard put fail";
  if ( v180 < 0 )
    goto LABEL_25;
  v181 = (_WORD *)(v178 + v179);
  if ( !v181 )
    goto LABEL_25;
  LOBYTE(v233) = *(_BYTE *)(v66 + 50);
  if ( (unsigned int)nla_put(v70, 7, 1, &v233) )
  {
    v94 = "%s: put fail";
    v95 = "hdd_add_tx_bitrate_sap";
    goto LABEL_24;
  }
  *v181 = *(_WORD *)(v70 + 216) + *(_DWORD *)(v70 + 208) - (_WORD)v181;
  qdf_trace_msg(
    0x33u,
    8u,
    "Remote STA VHT NSS: %d",
    v86,
    v87,
    v88,
    v89,
    v90,
    v91,
    v92,
    v93,
    *(unsigned __int8 *)(v66 + 50));
  *v177 = *(_WORD *)(v70 + 216) + *(_DWORD *)(v70 + 208) - (_WORD)v177;
  qdf_trace_msg(
    0x33u,
    8u,
    "Remote STA RSSI: %d",
    v182,
    v183,
    v184,
    v185,
    v186,
    v187,
    v188,
    v189,
    (unsigned int)(v69 + 96));
  v233 = *(_DWORD *)(v66 + 208);
  if ( (unsigned int)nla_put(v70, 54, 4, &v233) )
  {
    v94 = "%s: Reason code put fail";
LABEL_72:
    v95 = "hdd_add_link_standard_info_sap";
    goto LABEL_24;
  }
  LOWORD(v233) = *(_WORD *)(v66 + 224);
  if ( (unsigned int)nla_put(v70, 171, 2, &v233) )
  {
    v94 = "%s: put fail";
    goto LABEL_72;
  }
  *v81 = *(_WORD *)(v70 + 216) + *(_DWORD *)(v70 + 208) - (_WORD)v81;
  v190 = (__int64)v235;
  v191 = *(_QWORD *)(v70 + 216);
  v192 = *(unsigned int *)(v70 + 208);
  v193 = nla_put(v70, 32770, 0, 0);
  v80 = "%s: ap standard put fail";
  if ( v193 < 0 )
    goto LABEL_25;
  v194 = (_WORD *)(v191 + v192);
  if ( !v194 )
    goto LABEL_25;
  if ( *(_BYTE *)(v190 + 166) == 1 )
  {
    if ( (unsigned int)nla_put(v70, 157, 12, v190 + 193) )
    {
LABEL_80:
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: put fail",
        v195,
        v196,
        v197,
        v198,
        v199,
        v200,
        v201,
        v202,
        "hdd_add_ap_standard_info_sap");
      v80 = "%s: ap standard put fail";
      goto LABEL_25;
    }
    qdf_trace_msg(0x33u, 8u, "Remote STA VHT capabilities len:%u", v195, v196, v197, v198, v199, v200, v201, v202, 12);
  }
  if ( *(_BYTE *)(v190 + 165) == 1 )
  {
    if ( (unsigned int)nla_put(v70, 31, 26, v190 + 167) )
      goto LABEL_80;
    qdf_trace_msg(0x33u, 8u, "Remote STA HT capabilities len:%u", v195, v196, v197, v198, v199, v200, v201, v202, 26);
  }
  *v194 = *(_DWORD *)(v70 + 216) + *(_DWORD *)(v70 + 208) - (_WORD)v194;
  v203 = (__int64)v235;
  v204 = *((_DWORD *)v235 + 37);
  if ( v204 <= 2 )
  {
    switch ( v204 )
    {
      case 0:
LABEL_92:
        v205 = 20;
        goto LABEL_94;
      case 1:
        v205 = 40;
        goto LABEL_94;
      case 2:
        v205 = 80;
LABEL_94:
        v206 = v205;
        goto LABEL_95;
    }
LABEL_91:
    qdf_trace_msg(0x33u, 8u, "%s: invalid enum: %d", v72, v73, v74, v75, v76, v77, v78, v79, "hdd_decode_ch_width");
    v203 = (__int64)v235;
    goto LABEL_92;
  }
  if ( (unsigned int)(v204 - 3) < 2 )
  {
    v205 = 160;
    goto LABEL_94;
  }
  if ( v204 != 5 )
    goto LABEL_91;
  v206 = 160;
  LOWORD(v205) = 320;
LABEL_95:
  v233 = *(unsigned __int8 *)(v203 + 226);
  if ( (unsigned int)nla_put(v70, 18, 4, &v233)
    || (LOBYTE(v233) = v206, (unsigned int)nla_put(v70, 22, 1, &v233))
    || (LOWORD(v233) = v205, (unsigned int)nla_put(v70, 40, 2, &v233)) )
  {
    v80 = "%s: remote ch put fail";
    goto LABEL_25;
  }
  v233 = *((_DWORD *)v235 + 32) / 0x3E8u;
  if ( (unsigned int)nla_put(v70, 15, 4, &v233) )
  {
    v80 = "%s: tx rate put fail";
    goto LABEL_25;
  }
  v233 = *((_DWORD *)v235 + 33) / 0x3E8u;
  if ( (unsigned int)nla_put(v70, 16, 4, &v233) )
  {
    v80 = "%s: rx rate put fail";
    goto LABEL_25;
  }
  v233 = *((unsigned __int8 *)v235 + 164);
  if ( (unsigned int)nla_put(v70, 5, 4, &v233) )
  {
    v80 = "%s: dot11 mode put fail";
    goto LABEL_25;
  }
  v233 = *((_DWORD *)v235 + 58);
  if ( (unsigned int)nla_put(v70, 26, 4, &v233) )
  {
    v80 = "%s: rx mc bc put fail";
    goto LABEL_25;
  }
  v207 = (__int64)v235;
  if ( *((_DWORD *)v235 + 57) )
  {
    v233 = *((_DWORD *)v235 + 57);
    if ( (unsigned int)nla_put(v70, 25, 4, &v233) )
    {
      v80 = "%s: rx retry count put fail";
      goto LABEL_25;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "Remote STA retry count: %d",
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      *((unsigned int *)v235 + 57));
    v207 = (__int64)v235;
  }
  v208 = *(unsigned int *)(v207 + 264);
  if ( (_DWORD)v208 )
  {
    if ( (unsigned int)nla_put(v70, 38, v208, *(_QWORD *)(v207 + 272)) )
    {
      v80 = "%s: Failed to put assoc req IEs";
      goto LABEL_25;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "Remote STA assoc req IE len: %d",
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      *((unsigned int *)v235 + 66));
    v207 = (__int64)v235;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "Remote STA Info:: freq:%d, RSSI:%d, Tx NSS:%d, Reason code:%d,capability:0x%x, Supported mode:%d, chan_width:%d, Tx "
    "rate:%d,Rx rate:%d, dot11mode:%d",
    v72,
    v73,
    v74,
    v75,
    v76,
    v77,
    v78,
    v79,
    *(unsigned int *)(v207 + 160),
    (unsigned int)*(char *)(v207 + 212),
    *(unsigned __int8 *)(v207 + 50),
    *(unsigned int *)(v207 + 208),
    *(unsigned __int16 *)(v207 + 224),
    *(unsigned __int8 *)(v207 + 226),
    v206,
    *(_DWORD *)(v207 + 128),
    *(_DWORD *)(v207 + 132),
    *(unsigned __int8 *)(v207 + 164));
  hdd_sta_info_detach(v11 + 38888, (__int64 *)&v235, v209, v210, v211, v212, v213, v214, v215, v216);
  hdd_put_sta_info_ref(v11 + 38888, (__int64 *)&v235, 1, 9u, v217, v218, v219, v220, v221, v222, v223, v224);
  _X8 = (unsigned int *)(v11 + 38928);
  __asm { PRFM            #0x11, [X8] }
  do
    v231 = __ldxr(_X8);
  while ( __stxr(v231 - 1, _X8) );
  v104 = cfg80211_vendor_cmd_reply(v70);
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return v104;
}
