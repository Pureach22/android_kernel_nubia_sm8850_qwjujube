// bad sp value at call has been detected, the output may be wrong!
void __fastcall lim_process_sme_tdls_add_sta_req(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        size_t a23,
        __int64 a24,
        __int64 a25,
        __int64 a26,
        __int64 a27,
        __int64 a28,
        __int64 a29,
        __int64 a30,
        __int64 a31,
        __int64 a32,
        __int64 a33,
        int a34)
{
  __int64 v36; // x4
  __int64 session_by_bssid; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x21
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  int v64; // w8
  __int64 v65; // x22
  __int64 v66; // x4
  __int64 v67; // x5
  const char *v68; // x2
  __int64 v69; // x6
  __int64 v70; // x7
  _QWORD *peer_by_mac; // x0
  __int64 v72; // x4
  __int64 v73; // x5
  const char *v74; // x2
  unsigned __int16 v75; // w0
  char v76; // w8
  __int64 v77; // x9
  __int64 hash_entry; // x0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x22
  int v88; // w8
  unsigned int v89; // w8
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  __int16 v98; // w8
  int v99; // w11
  char v100; // w13
  char v101; // w9
  __int16 v102; // w9
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  char is_fw_wideband_capable; // w23
  int v120; // w26
  int v121; // w8
  int v122; // w10
  __int64 v123; // x4
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  int v132; // w11
  char v133; // w9
  unsigned int v134; // w8
  unsigned int v135; // w9
  int v136; // w14
  int v137; // w13
  bool v138; // w8
  int v139; // w10
  char v140; // w11
  unsigned int v141; // w9
  int v142; // w12
  __int16 v143; // w10
  int v144; // w8
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  int v153; // w8
  char v154; // w8
  unsigned int v155; // w8
  __int64 v156; // x4
  __int64 v157; // x6
  char v158; // w8
  char v159; // w8
  char v160; // w9
  double v161; // d0
  double v162; // d1
  double v163; // d2
  double v164; // d3
  double v165; // d4
  double v166; // d5
  double v167; // d6
  double v168; // d7
  unsigned int v169; // w8
  double v170; // d0
  double v171; // d1
  double v172; // d2
  double v173; // d3
  double v174; // d4
  double v175; // d5
  double v176; // d6
  double v177; // d7
  unsigned __int64 *v178; // x24
  int v179; // w9
  unsigned __int64 v180; // x10
  double v181; // d0
  double v182; // d1
  double v183; // d2
  double v184; // d3
  double v185; // d4
  double v186; // d5
  double v187; // d6
  double v188; // d7
  __int16 v189; // w8
  __int16 v190; // w9
  double v191; // d0
  double v192; // d1
  double v193; // d2
  double v194; // d3
  double v195; // d4
  double v196; // d5
  double v197; // d6
  double v198; // d7
  double v199; // d0
  double v200; // d1
  double v201; // d2
  double v202; // d3
  double v203; // d4
  double v204; // d5
  double v205; // d6
  double v206; // d7
  bool is_24ghz_ch_freq; // w0
  unsigned __int64 v208; // x8
  __int64 v209; // x4
  const char *v210; // x2
  const char *v211; // x3
  unsigned __int8 v212; // w0
  int v213; // w9
  int v214; // w0
  int v215; // w9
  char v216; // w9
  _BYTE *v217; // x8
  char v218; // w10
  __int16 v219; // w8
  __int16 v220; // w9
  char v221; // w8
  unsigned int v222; // w4
  int v223; // w9
  int v224; // w10
  __int16 v225; // w8
  bool is_5ghz_ch_freq; // w0
  double v227; // d0
  double v228; // d1
  double v229; // d2
  double v230; // d3
  double v231; // d4
  double v232; // d5
  double v233; // d6
  double v234; // d7
  __int64 v235; // x8
  unsigned int v236; // w8
  unsigned int v237; // w23
  __int64 v238; // x9
  double v239; // d0
  double v240; // d1
  double v241; // d2
  double v242; // d3
  double v243; // d4
  double v244; // d5
  double v245; // d6
  double v246; // d7
  size_t v247; // x8
  double v248; // d0
  double v249; // d1
  double v250; // d2
  double v251; // d3
  double v252; // d4
  double v253; // d5
  double v254; // d6
  double v255; // d7
  double v256; // d0
  double v257; // d1
  double v258; // d2
  double v259; // d3
  double v260; // d4
  double v261; // d5
  double v262; // d6
  double v263; // d7
  double v264; // d0
  double v265; // d1
  double v266; // d2
  double v267; // d3
  double v268; // d4
  double v269; // d5
  double v270; // d6
  double v271; // d7
  double v272; // d0
  double v273; // d1
  double v274; // d2
  double v275; // d3
  double v276; // d4
  double v277; // d5
  double v278; // d6
  double v279; // d7
  double v280; // d0
  double v281; // d1
  double v282; // d2
  double v283; // d3
  double v284; // d4
  double v285; // d5
  double v286; // d6
  double v287; // d7
  double v288; // d0
  double v289; // d1
  double v290; // d2
  double v291; // d3
  double v292; // d4
  double v293; // d5
  double v294; // d6
  double v295; // d7
  double v296; // d0
  double v297; // d1
  double v298; // d2
  double v299; // d3
  double v300; // d4
  double v301; // d5
  double v302; // d6
  double v303; // d7
  double v304; // d0
  double v305; // d1
  double v306; // d2
  double v307; // d3
  double v308; // d4
  double v309; // d5
  double v310; // d6
  double v311; // d7
  double v312; // d0
  double v313; // d1
  double v314; // d2
  double v315; // d3
  double v316; // d4
  double v317; // d5
  double v318; // d6
  double v319; // d7
  double v320; // d0
  double v321; // d1
  double v322; // d2
  double v323; // d3
  double v324; // d4
  double v325; // d5
  double v326; // d6
  double v327; // d7
  double v328; // d0
  double v329; // d1
  double v330; // d2
  double v331; // d3
  double v332; // d4
  double v333; // d5
  double v334; // d6
  double v335; // d7
  double v336; // d0
  double v337; // d1
  double v338; // d2
  double v339; // d3
  double v340; // d4
  double v341; // d5
  double v342; // d6
  double v343; // d7
  double v344; // d0
  double v345; // d1
  double v346; // d2
  double v347; // d3
  double v348; // d4
  double v349; // d5
  double v350; // d6
  double v351; // d7
  double v352; // d0
  double v353; // d1
  double v354; // d2
  double v355; // d3
  double v356; // d4
  double v357; // d5
  double v358; // d6
  double v359; // d7
  double v360; // d0
  double v361; // d1
  double v362; // d2
  double v363; // d3
  double v364; // d4
  double v365; // d5
  double v366; // d6
  double v367; // d7
  double v368; // d0
  double v369; // d1
  double v370; // d2
  double v371; // d3
  double v372; // d4
  double v373; // d5
  double v374; // d6
  double v375; // d7
  int v376; // w25
  bool v377; // w0
  double v378; // d0
  double v379; // d1
  double v380; // d2
  double v381; // d3
  double v382; // d4
  double v383; // d5
  double v384; // d6
  double v385; // d7
  double v386; // d0
  double v387; // d1
  double v388; // d2
  double v389; // d3
  double v390; // d4
  double v391; // d5
  double v392; // d6
  double v393; // d7
  __int64 v394; // x0
  __int128 v395; // [xsp+90h] [xbp-40h] BYREF
  _QWORD v396[2]; // [xsp+A0h] [xbp-30h]
  _QWORD v397[4]; // [xsp+B0h] [xbp-20h]

  v397[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = *(unsigned __int8 *)(a2 + 4);
  LOBYTE(a22) = 0;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: vdev:%d TDLS Add STA Request Received",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_process_sme_tdls_add_sta_req",
    v36);
  session_by_bssid = pe_find_session_by_bssid(a1, (unsigned __int8 *)(a2 + 8), (unsigned __int8 *)&a22);
  if ( !session_by_bssid
    || (v46 = session_by_bssid, *(_DWORD *)(session_by_bssid + 88) != 2)
    || wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(session_by_bssid + 16), v38, v39, v40, v41, v42, v43, v44, v45)
    || (*(_DWORD *)(v46 + 80) | 2) != 0xA )
  {
    JUMPOUT(0x63AF4C);
  }
  WORD2(a22) = 0;
  v55 = dph_lookup_hash_entry(
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          a1,
          (unsigned __int8 *)(a2 + 20),
          (_WORD *)&a22 + 2,
          v46 + 360);
  v64 = *(_DWORD *)(a2 + 16);
  v65 = v55;
  if ( v55 )
  {
    if ( v64 == 1 )
    {
      v66 = *(unsigned __int8 *)(v46 + 10);
      v67 = *(unsigned __int8 *)(a2 + 20);
      v68 = "%s: vdev:%d TDLS entry for peer: %02x:%02x:%02x:**:**:%02x already exist, cannot add new entry";
      v69 = *(unsigned __int8 *)(a2 + 21);
      v70 = *(unsigned __int8 *)(a2 + 22);
LABEL_17:
      qdf_trace_msg(
        0x35u,
        2u,
        v68,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        "lim_tdls_setup_add_sta",
        v66,
        v67,
        v69,
        v70);
      goto LABEL_157;
    }
  }
  else if ( v64 == 2 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: vdev:%d TDLS update peer is given without peer creation",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      "lim_tdls_setup_add_sta",
      *(unsigned __int8 *)(v46 + 10));
    goto LABEL_157;
  }
  peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(a1 + 21624), (_BYTE *)(a2 + 20), 0x11u);
  if ( peer_by_mac )
  {
    wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 0x11u, v56, v57, v58, v59, v60, v61, v62, v63);
    if ( *(_DWORD *)(a2 + 16) == 1 )
    {
      v66 = *(unsigned __int8 *)(v46 + 10);
      v67 = *(unsigned __int8 *)(a2 + 20);
      v68 = "%s: vdev:%d peer: %02x:%02x:%02x:**:**:%02x peer_type:%d already exist on vdev:%d, cannot add new entry";
      v69 = *(unsigned __int8 *)(a2 + 21);
      v70 = *(unsigned __int8 *)(a2 + 22);
      goto LABEL_17;
    }
  }
  if ( v65 )
  {
    if ( *(_BYTE *)(v65 + 356) != 4 )
    {
      v72 = *(unsigned __int8 *)(a2 + 20);
      v73 = *(unsigned __int8 *)(a2 + 21);
      v74 = "%s: Non TDLS entry for peer: %02x:%02x:%02x:**:**:%02x already exist";
LABEL_25:
      qdf_trace_msg(
        0x35u,
        2u,
        v74,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        "lim_tdls_setup_add_sta",
        v72,
        v73,
        *(unsigned __int8 *)(a2 + 22),
        *(unsigned __int8 *)(a2 + 25));
LABEL_157:
      JUMPOUT(0x63AF40);
    }
LABEL_32:
    v88 = *(_DWORD *)(a2 + 16);
    a34 = 0;
    a32 = 0;
    a33 = 0;
    a30 = 0;
    a31 = 0;
    a28 = 0;
    a29 = 0;
    a26 = 0;
    a27 = 0;
    a25 = 0;
    if ( v88 == 2 )
    {
      v89 = *(unsigned __int16 *)(a2 + 70);
      if ( (v89 & 2) == 0 )
        v89 &= 0xFFBDu;
      *(_WORD *)((char *)&a27 + 1) = v89;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: SupportedChnlWidth: %d, mimoPS: %d, GF: %d, shortGI20:%d, shortGI40: %d, dsssCck: %d",
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        "lim_tdls_populate_dot11f_ht_caps",
        (v89 >> 1) & 1,
        (v89 >> 2) & 3,
        (v89 >> 4) & 1,
        (v89 >> 5) & 1);
      BYTE3(a27) = *(_BYTE *)(a2 + 72);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: AMPDU Param: %x",
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        v97,
        "lim_tdls_populate_dot11f_ht_caps");
      qdf_mem_copy((char *)&a27 + 4, (const void *)(a2 + 73), 0x10u);
      v98 = *(_WORD *)(a2 + 89);
      v99 = *(_DWORD *)(a2 + 91);
      v100 = *(_BYTE *)(a2 + 95);
      v101 = *(_BYTE *)(a2 + 69);
      LOWORD(a30) = a30 & 0xFE00 | HIWORD(v99) & 0x1FF;
      BYTE2(a30) = BYTE2(a30) & 0x80 | v100 & 0x7F;
      LOBYTE(a27) = v101;
      v102 = *(unsigned __int8 *)(a2 + 159);
      HIDWORD(a29) = WORD2(a29) & 0xFCF8 | v98 & 1 | v98 & 0x306 | (v99 << 16);
      *(_WORD *)v65 = *(_WORD *)v65 & 0xFBFF | (v102 << 10);
    }
    else if ( v88 == 1 )
    {
      populate_dot11f_ht_caps((_QWORD *)a1, v46, (__int64)&a27, v56, v57, v58, v59, v60, v61, v62, v63);
    }
    if ( *(_BYTE *)(a2 + 144) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: copy eht config from pe_session",
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        "lim_tdls_populate_dot11f_eht_caps");
      qdf_mem_copy((void *)(v65 + 932), (const void *)(v46 + 10072), 0x5Cu);
      qdf_mem_copy((void *)(v65 + 1024), (const void *)(v46 + 10164), 0xCu);
    }
    wlan_reg_get_max_chwidth(*(_QWORD *)(a1 + 21632), *(_DWORD *)(v46 + 284), v56, v57, v58, v59, v60, v61, v62, v63);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: p_ext_cap->tdls_wider_bw %d",
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      "lim_is_wide_band_set",
      (*(_QWORD *)(a2 + 28) >> 61) & 1LL);
    if ( (*(_BYTE *)(a2 + 35) & 0x20) != 0 )
      is_fw_wideband_capable = wlan_cfg80211_tdls_is_fw_wideband_capable(*(_QWORD *)(v46 + 16));
    else
      is_fw_wideband_capable = 0;
    v120 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5964LL);
    if ( (_BYTE)a27
      && (!(unsigned __int8)*(_DWORD *)(*(_QWORD *)(a1 + 8) + 5964LL)
       || (v120 & 0xFD) == 5
       || (v121 = v120 & 0xFE, v121 == 8)
       || v121 == 10
       || v121 == 12) )
    {
      v122 = *(_BYTE *)(v65 + 344) & 0xFE | (*(unsigned __int16 *)((char *)&a27 + 1) >> 4) & 1;
      v123 = (*(unsigned __int16 *)((char *)&a27 + 1) >> 1) & 1;
      *(_BYTE *)(v65 + 32) |= 8u;
      *(_BYTE *)(v65 + 344) = v122;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: peer htSupportedChannelWidthSet: 0x%x pe session htSupportedChannelWidthSet: 0x%x",
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        "lim_tdls_update_hash_node_info",
        v123,
        *(unsigned __int8 *)(v46 + 160));
      if ( (is_fw_wideband_capable & 1) != 0
        && (wlan_reg_is_dfs_for_freq(
              *(_QWORD *)(a1 + 21632),
              *(_DWORD *)(v46 + 284),
              v124,
              v125,
              v126,
              v127,
              v128,
              v129,
              v130,
              v131)
          & 1) == 0
        && !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v46 + 284)) )
      {
        JUMPOUT(0x63B098);
      }
      v132 = *(unsigned __int16 *)((char *)&a27 + 1) >> 1;
      if ( (v132 & 1u) >= *(unsigned __int8 *)(v46 + 160) )
        v133 = *(_BYTE *)(v46 + 160);
      else
        v133 = v132;
      v134 = *(_BYTE *)(v65 + 346) & 0xF7 | (8 * (v133 & 1));
      *(_BYTE *)(v65 + 346) = v134;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: sta->htSupportedChannelWidthSet: 0x%x",
        v124,
        v125,
        v126,
        v127,
        v128,
        v129,
        v130,
        v131,
        "lim_tdls_update_hash_node_info",
        (v134 >> 3) & 1);
      v135 = *(unsigned __int8 *)(v65 + 346);
      v136 = (v135 >> 3) & 1;
      LOBYTE(v135) = v135 & 0xF8 | BYTE3(a27) & 3;
      v137 = (*(unsigned __int16 *)((char *)&a27 + 1) >> 2) & 3;
      v138 = (*(_WORD *)((_BYTE *)&a27 + 1) & 0x800) != 0;
      v139 = (*(unsigned __int16 *)((char *)&a27 + 1) >> 3) & 4
           | (*(unsigned __int16 *)((char *)&a27 + 1) >> 9) & 8
           | (*(unsigned __int16 *)((char *)&a27 + 1) >> 5) & 2
           | (32 * ((BYTE3(a27) >> 2) & 7));
      v140 = *(_BYTE *)(v65 + 344) & 0x11;
      *(_DWORD *)(v65 + 360) = v136;
      *(_BYTE *)(v65 + 345) = v138;
      *(_DWORD *)(v65 + 340) = v137;
      *(_BYTE *)(v65 + 344) = v139 | v140;
      *(_BYTE *)(v65 + 346) = v135;
      lim_fill_rx_highest_supported_rate(a1, (_WORD *)(v65 + 304), (__int64)&a27 + 4);
      *(_WORD *)(v65 + 648) = *(_WORD *)(a2 + 70);
    }
    else
    {
      *(_BYTE *)(v65 + 32) &= ~8u;
    }
    v141 = *(_DWORD *)(a2 + 100);
    LOBYTE(a25) = *(_BYTE *)(a2 + 96);
    v142 = WORD2(a25) & 0xFE00 | (v141 >> 23);
    v143 = *(_WORD *)(a2 + 110);
    *(_WORD *)((char *)&a25 + 1) = v141 & 0xE7FF;
    LOWORD(v141) = *(_WORD *)(a2 + 104);
    BYTE3(a25) = BYTE3(a25) & 0x80 | BYTE2(v141) & 0x67;
    v144 = *(_DWORD *)(a2 + 106);
    WORD2(a25) = v142;
    HIWORD(a25) = v141;
    LODWORD(a26) = v144;
    WORD2(a26) = WORD2(a26) & 0xC000 | v143 & 0x3FFF;
    lim_log_vht_cap();
    if ( (_BYTE)a25 && (!(_BYTE)v120 || (v120 & 0xFEu) <= 0xC && ((1 << (v120 & 0xFE)) & 0x1500) != 0) )
    {
      *(_BYTE *)(v65 + 32) |= 0x10u;
      if ( (is_fw_wideband_capable & 1) == 0
        || wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v46 + 284))
        || (*(_BYTE *)(v65 + 357) = 1,
            (wlan_reg_is_dfs_for_freq(
               *(_QWORD *)(a1 + 21632),
               *(_DWORD *)(v46 + 284),
               v145,
               v146,
               v147,
               v148,
               v149,
               v150,
               v151,
               v152)
           & 1) != 0) )
      {
        v153 = *(_DWORD *)(v46 + 7176);
        if ( v153 )
          v154 = v153 - 1;
        else
          v154 = 0;
        *(_BYTE *)(v65 + 357) = v154;
      }
      v155 = *(unsigned __int8 *)(v65 + 346);
      if ( (v155 & 8) != 0 )
      {
        v156 = *(unsigned __int8 *)(v65 + 357);
        if ( (unsigned int)v156 < 2 )
          v157 = (unsigned int)(v156 + 1);
        else
          v157 = 3;
        *(_DWORD *)(v65 + 360) = v157;
      }
      else
      {
        v156 = *(unsigned __int8 *)(v65 + 357);
        v157 = 0;
        *(_DWORD *)(v65 + 360) = 0;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: vhtSupportedChannelWidthSet: %hu htSupportedChannelWidthSet: %hu sta_ch_width %d",
        v145,
        v146,
        v147,
        v148,
        v149,
        v150,
        v151,
        v152,
        "lim_tdls_update_hash_node_info",
        v156,
        (v155 >> 3) & 1,
        v157);
      v159 = BYTE1(a25);
      *(_BYTE *)(v65 + 365) = 0;
      *(_BYTE *)(v65 + 647) = (v159 & 0x10) != 0;
      v160 = *(_BYTE *)(a2 + 103) & 0xE7;
      *(_WORD *)(a2 + 101) &= 0xE7FFu;
      *(_BYTE *)(a2 + 103) = v160;
      *(_DWORD *)(v65 + 652) = *(_DWORD *)(a2 + 100);
    }
    else
    {
      v158 = *(_BYTE *)(v65 + 32);
      *(_BYTE *)(v65 + 357) = 0;
      *(_BYTE *)(v65 + 32) = v158 & 0xEF;
    }
    if ( !(_BYTE)v120 || (v120 & 0xFE) == 0xC || (v120 & 0xFE) == 0xA )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Populating HE IEs",
        v145,
        v146,
        v147,
        v148,
        v149,
        v150,
        v151,
        v152,
        "lim_tdls_update_node_he_caps");
      v169 = *(unsigned __int8 *)(a2 + 112);
      *(_QWORD *)((char *)v396 + 5) = 0;
      v396[0] = 0;
      v395 = 0u;
      if ( v169 < 0x11 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: He_capability invalid",
          v161,
          v162,
          v163,
          v164,
          v165,
          v166,
          v167,
          v168,
          "lim_tdls_populate_dot11f_he_caps");
        goto LABEL_101;
      }
      v178 = (unsigned __int64 *)(v65 + 865);
      qdf_mem_copy(&v395, (const void *)(a2 + 113), 0x1Du);
      v179 = DWORD1(v395);
      v180 = ((*(_QWORD *)((char *)&v395 + 4) >> 29) & 0x7FF000000LL
            | (*(_QWORD *)((char *)&v395 + 4) >> 31) & 0x3FFFFFLL
            | *(_QWORD *)(v65 + 873) & 0xFE00000000C00000LL
            | ((unsigned __int64)(BYTE12(v395) & 1) << 35)
            | ((unsigned __int64)((HIDWORD(v395) >> 14) & 1) << 49)
            | ((unsigned __int64)((HIDWORD(v395) >> 15) & 1) << 50)
            | ((unsigned __int64)((HIDWORD(v395) >> 1) & 1) << 36)
            | ((unsigned __int64)((HIDWORD(v395) >> 18) & 1) << 53)
            | ((unsigned __int64)((HIDWORD(v395) >> 19) & 1) << 54)
            | ((unsigned __int64)((HIDWORD(v395) >> 20) & 1) << 55)
            | ((unsigned __int64)((HIDWORD(v395) >> 2) & 7) << 37)
            | ((unsigned __int64)((HIDWORD(v395) >> 5) & 1) << 40)
            | ((unsigned __int64)((HIDWORD(v395) >> 6) & 1) << 41)
            | ((unsigned __int64)((HIDWORD(v395) >> 7) & 1) << 42)
            | ((unsigned __int64)((HIDWORD(v395) >> 8) & 1) << 43)
            | ((unsigned __int64)((HIDWORD(v395) >> 9) & 1) << 44)
            | ((unsigned __int64)((HIDWORD(v395) >> 10) & 1) << 45)
            | ((unsigned __int64)((HIDWORD(v395) >> 11) & 7) << 46)
            | ((unsigned __int64)(HIWORD(HIDWORD(v395)) & 1) << 51)
            | ((unsigned __int64)((HIDWORD(v395) >> 17) & 1) << 52))
           + ((unsigned __int64)((HIDWORD(v395) >> 21) & 1) << 56);
      *v178 = *v178 & 0x1FF8001000000LL
            | v395 & 1
            | (unsigned __int8)v395 & 0xFE
            | (unsigned __int64)(v395 & 0x300)
            | v395 & 0xC00
            | v395 & 0x7000
            | v395 & 0x18000
            | v395 & 0x20000
            | v395 & 0x40000
            | v395 & 0x80000
            | v395 & 0x100000
            | v395 & 0x200000
            | v395 & 0x400000
            | v395 & 0x800000
            | v395 & 0x2000000
            | v395 & 0x4000000
            | v395 & 0x18000000
            | v395 & 0x20000000
            | v395 & 0x40000000
            | (unsigned int)v395 & 0x80000000
            | ((unsigned __int64)(BYTE4(v395) & 0x7F) << 32)
            | (*(_QWORD *)((char *)&v395 + 4) >> 16 << 49);
      *(_QWORD *)(v65 + 873) = v180;
      LODWORD(v180) = *(_DWORD *)((char *)v396 + 1);
      *(_BYTE *)(v65 + 864) = 1;
      *(_DWORD *)(v65 + 884) = v180;
      if ( (v179 & 0x80000) != 0 )
        *(_DWORD *)(v65 + 888) = *(_DWORD *)((char *)v396 + 5);
      if ( (v179 & 0x100000) != 0 )
        *(_DWORD *)(v65 + 892) = *(_DWORD *)((char *)&v396[1] + 1);
      *(_BYTE *)(v65 + 38) = 1;
      v181 = lim_tdls_set_he_chan_width(a1, v65 + 864, v46, is_fw_wideband_capable & 1);
      lim_log_he_cap(v181, v182, v183, v184, v185, v186, v187, v188, a1, v65 + 864);
      if ( *(_BYTE *)(v46 + 8764) == 1 )
      {
        LOWORD(v395) = 0;
        if ( !*(_BYTE *)(a2 + 142) && !*(_BYTE *)(a2 + 143) )
          JUMPOUT(0x63B0E8);
        qdf_mem_copy(&v395, (const void *)(a2 + 142), 2u);
        v189 = *(_WORD *)(v65 + 927) & 0xC0 | v395 & 0x3F;
        v190 = (4 * v395) & 0xFB00;
        *(_BYTE *)(v65 + 926) = 1;
        *(_WORD *)(v65 + 927) = v189 | v190;
        lim_log_he_6g_cap(v191, v192, v193, v194, v195, v196, v197, v198, a1, v65 + 926);
        lim_update_stads_he_6ghz_op(v46, v65, v199, v200, v201, v202, v203, v204, v205, v206);
      }
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v46 + 284));
      v208 = *v178;
      if ( is_24ghz_ch_freq && (v208 & 0x4000000000000LL) != 0 )
      {
        v209 = 1;
      }
      else if ( (v208 & 0x20000000000000LL) != 0 )
      {
        v209 = 4;
      }
      else if ( (v208 & 0x10000000000000LL) != 0 )
      {
        v209 = 3;
      }
      else
      {
        v209 = (v208 >> 50) & 2;
      }
      *(_DWORD *)(v65 + 360) = v209;
      v210 = "%s: sta->ch_width %d";
      v211 = "lim_tdls_update_node_he_caps";
    }
    else
    {
      v210 = "%s: Not populating he cap as SelfDot11Mode not HE %d";
      v211 = "lim_tdls_update_hash_node_info";
      v209 = (unsigned __int8)v120;
    }
    qdf_trace_msg(0x35u, 8u, v210, v145, v146, v147, v148, v149, v150, v151, v152, v211, v209);
LABEL_101:
    if ( *(_BYTE *)(v46 + 160) )
    {
      v212 = wlan_reg_freq_to_chan(
               *(_QWORD *)(a1 + 21632),
               *(_DWORD *)(v46 + 284),
               v170,
               v171,
               v172,
               v173,
               v174,
               v175,
               v176,
               v177);
      if ( *(_BYTE *)(v65 + 357) && (*(_BYTE *)(v65 + 32) & 0x10) != 0 )
      {
        v213 = v212 - 36;
        v214 = 6;
        switch ( v213 )
        {
          case 0:
          case 16:
          case 64:
          case 80:
          case 113:
            goto LABEL_114;
          case 4:
          case 20:
          case 68:
          case 84:
          case 117:
            v214 = 7;
            goto LABEL_114;
          case 8:
          case 24:
          case 72:
          case 88:
          case 121:
            v214 = 8;
            goto LABEL_114;
          case 12:
          case 28:
          case 76:
          case 92:
          case 125:
            v214 = 9;
            goto LABEL_114;
          case 129:
            JUMPOUT(0x63B120);
          default:
            goto LABEL_107;
        }
      }
      if ( (*(_BYTE *)(v65 + 32) & 8) != 0 )
      {
        v215 = v212 - 36;
        v214 = 1;
        switch ( v215 )
        {
          case 0:
          case 8:
          case 16:
          case 24:
          case 64:
          case 72:
          case 80:
          case 88:
          case 96:
          case 104:
          case 113:
          case 121:
            v214 = 3;
            goto LABEL_110;
          case 4:
          case 12:
          case 20:
          case 28:
          case 68:
          case 76:
          case 84:
          case 92:
          case 100:
          case 108:
          case 117:
          case 125:
            goto LABEL_110;
          default:
            break;
        }
      }
LABEL_107:
      v214 = 0;
LABEL_110:
      if ( (*(_BYTE *)(v65 + 32) & 0x10) != 0 )
      {
LABEL_114:
        v218 = 16 * (lim_get_htcb_state(v214) & 3);
        v217 = (_BYTE *)(v65 + 346);
        v216 = *(_BYTE *)(v65 + 346) & 0xCF;
      }
      else
      {
        v216 = 16 * v214;
        v217 = (_BYTE *)(v65 + 346);
        v218 = *(_BYTE *)(v65 + 346) & 0xCF;
      }
      *v217 = v218 | v216;
    }
    if ( (*(_WORD *)(a2 + 26) & 9) != 0 )
      v219 = 2;
    else
      v219 = 2 * (*(_BYTE *)(a2 + 69) != 0);
    v220 = *(_WORD *)v65;
    *(_QWORD *)((char *)v397 + 5) = 0;
    v397[0] = 0;
    *(_WORD *)v65 = v219 | v220 & 0xFF3D | 0x40;
    v221 = *(_BYTE *)(a2 + 157);
    v395 = 0u;
    a23 = 0;
    *(_BYTE *)(v65 + 238) = v221;
    v222 = *(unsigned __int8 *)(a2 + 36);
    if ( v222 < 0xD )
    {
      if ( !*(_BYTE *)(a2 + 36) )
      {
        LOBYTE(v397[0]) = 0;
        qdf_mem_set((void *)(v65 + 264), 0x4Cu, 0);
        is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(v46 + 284));
        v235 = 21590;
        if ( is_5ghz_ch_freq )
          v235 = 21600;
        v236 = *(unsigned __int8 *)(a1 + v235);
        if ( v236 >= *(unsigned __int8 *)(a1 + 21668) )
          v237 = *(unsigned __int8 *)(a1 + 21668);
        else
          v237 = v236;
        if ( (*(_BYTE *)(v65 + 32) & 8) != 0 )
        {
          v238 = *(_QWORD *)(a1 + 8);
          a23 = 16;
          if ( (unsigned int)wlan_mlme_get_cfg_str(
                               &v395,
                               v238 + 3056,
                               &a23,
                               v227,
                               v228,
                               v229,
                               v230,
                               v231,
                               v232,
                               v233,
                               v234) )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: could not retrieve supportedMCSSet",
              v239,
              v240,
              v241,
              v242,
              v243,
              v244,
              v245,
              v246,
              "lim_tdls_populate_matching_rate_set");
            JUMPOUT(0x63AEBC);
          }
          if ( v237 == 1 )
            BYTE1(v395) = 0;
          v247 = a23;
          if ( a23 )
          {
            *(_BYTE *)(v65 + 288) = *(_BYTE *)(a2 + 73) & v395;
            if ( v247 != 1 )
            {
              *(_BYTE *)(v65 + 289) = *(_BYTE *)(a2 + 74) & BYTE1(v395);
              if ( v247 != 2 )
              {
                *(_BYTE *)(v65 + 290) = *(_BYTE *)(a2 + 75) & BYTE2(v395);
                if ( v247 != 3 )
                {
                  *(_BYTE *)(v65 + 291) = *(_BYTE *)(a2 + 76) & BYTE3(v395);
                  if ( v247 != 4 )
                  {
                    *(_BYTE *)(v65 + 292) = *(_BYTE *)(a2 + 77) & BYTE4(v395);
                    if ( v247 != 5 )
                    {
                      *(_BYTE *)(v65 + 293) = *(_BYTE *)(a2 + 78) & BYTE5(v395);
                      if ( v247 != 6 )
                      {
                        *(_BYTE *)(v65 + 294) = *(_BYTE *)(a2 + 79) & BYTE6(v395);
                        if ( v247 != 7 )
                        {
                          *(_BYTE *)(v65 + 295) = *(_BYTE *)(a2 + 80) & BYTE7(v395);
                          if ( v247 != 8 )
                          {
                            *(_BYTE *)(v65 + 296) = *(_BYTE *)(a2 + 81) & BYTE8(v395);
                            if ( v247 != 9 )
                            {
                              *(_BYTE *)(v65 + 297) = *(_BYTE *)(a2 + 82) & BYTE9(v395);
                              if ( v247 != 10 )
                              {
                                *(_BYTE *)(v65 + 298) = *(_BYTE *)(a2 + 83) & BYTE10(v395);
                                if ( v247 != 11 )
                                {
                                  *(_BYTE *)(v65 + 299) = *(_BYTE *)(a2 + 84) & BYTE11(v395);
                                  if ( v247 != 12 )
                                  {
                                    *(_BYTE *)(v65 + 300) = *(_BYTE *)(a2 + 85) & BYTE12(v395);
                                    if ( v247 != 13 )
                                    {
                                      *(_BYTE *)(v65 + 301) = *(_BYTE *)(a2 + 86) & BYTE13(v395);
                                      if ( v247 != 14 )
                                      {
                                        *(_BYTE *)(v65 + 302) = *(_BYTE *)(a2 + 87) & BYTE14(v395);
                                        if ( v247 != 15 )
                                        {
                                          *(_BYTE *)(v65 + 303) = *(_BYTE *)(a2 + 88) & HIBYTE(v395);
                                          if ( v247 != 16 )
                                            JUMPOUT(0x63B280);
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: MCS Rate Set Bitmap from CFG and DPH",
            v239,
            v240,
            v241,
            v242,
            v243,
            v244,
            v245,
            v246,
            "lim_tdls_populate_matching_rate_set");
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: %x %x",
            v248,
            v249,
            v250,
            v251,
            v252,
            v253,
            v254,
            v255,
            "lim_tdls_populate_matching_rate_set",
            (unsigned __int8)v395,
            *(unsigned __int8 *)(v65 + 288));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: %x %x",
            v256,
            v257,
            v258,
            v259,
            v260,
            v261,
            v262,
            v263,
            "lim_tdls_populate_matching_rate_set",
            BYTE1(v395),
            *(unsigned __int8 *)(v65 + 289));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: %x %x",
            v264,
            v265,
            v266,
            v267,
            v268,
            v269,
            v270,
            v271,
            "lim_tdls_populate_matching_rate_set",
            BYTE2(v395),
            *(unsigned __int8 *)(v65 + 290));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: %x %x",
            v272,
            v273,
            v274,
            v275,
            v276,
            v277,
            v278,
            v279,
            "lim_tdls_populate_matching_rate_set",
            BYTE3(v395),
            *(unsigned __int8 *)(v65 + 291));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: %x %x",
            v280,
            v281,
            v282,
            v283,
            v284,
            v285,
            v286,
            v287,
            "lim_tdls_populate_matching_rate_set",
            BYTE4(v395),
            *(unsigned __int8 *)(v65 + 292));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: %x %x",
            v288,
            v289,
            v290,
            v291,
            v292,
            v293,
            v294,
            v295,
            "lim_tdls_populate_matching_rate_set",
            BYTE5(v395),
            *(unsigned __int8 *)(v65 + 293));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: %x %x",
            v296,
            v297,
            v298,
            v299,
            v300,
            v301,
            v302,
            v303,
            "lim_tdls_populate_matching_rate_set",
            BYTE6(v395),
            *(unsigned __int8 *)(v65 + 294));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: %x %x",
            v304,
            v305,
            v306,
            v307,
            v308,
            v309,
            v310,
            v311,
            "lim_tdls_populate_matching_rate_set",
            BYTE7(v395),
            *(unsigned __int8 *)(v65 + 295));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: %x %x",
            v312,
            v313,
            v314,
            v315,
            v316,
            v317,
            v318,
            v319,
            "lim_tdls_populate_matching_rate_set",
            BYTE8(v395),
            *(unsigned __int8 *)(v65 + 296));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: %x %x",
            v320,
            v321,
            v322,
            v323,
            v324,
            v325,
            v326,
            v327,
            "lim_tdls_populate_matching_rate_set",
            BYTE9(v395),
            *(unsigned __int8 *)(v65 + 297));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: %x %x",
            v328,
            v329,
            v330,
            v331,
            v332,
            v333,
            v334,
            v335,
            "lim_tdls_populate_matching_rate_set",
            BYTE10(v395),
            *(unsigned __int8 *)(v65 + 298));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: %x %x",
            v336,
            v337,
            v338,
            v339,
            v340,
            v341,
            v342,
            v343,
            "lim_tdls_populate_matching_rate_set",
            BYTE11(v395),
            *(unsigned __int8 *)(v65 + 299));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: %x %x",
            v344,
            v345,
            v346,
            v347,
            v348,
            v349,
            v350,
            v351,
            "lim_tdls_populate_matching_rate_set",
            BYTE12(v395),
            *(unsigned __int8 *)(v65 + 300));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: %x %x",
            v352,
            v353,
            v354,
            v355,
            v356,
            v357,
            v358,
            v359,
            "lim_tdls_populate_matching_rate_set",
            BYTE13(v395),
            *(unsigned __int8 *)(v65 + 301));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: %x %x",
            v360,
            v361,
            v362,
            v363,
            v364,
            v365,
            v366,
            v367,
            "lim_tdls_populate_matching_rate_set",
            BYTE14(v395),
            *(unsigned __int8 *)(v65 + 302));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: %x %x",
            v368,
            v369,
            v370,
            v371,
            v372,
            v373,
            v374,
            v375,
            "lim_tdls_populate_matching_rate_set",
            HIBYTE(v395),
            *(unsigned __int8 *)(v65 + 303));
        }
        lim_populate_vht_mcs_set(a1, (_WORD *)(v65 + 264), (__int64)&a25, v46, v237, 0);
        v376 = *(_DWORD *)(v46 + 7176);
        v377 = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v46 + 284));
        lim_populate_eht_mcs_set(
          a1,
          v65 + 264,
          v65 + 932,
          v46,
          v376,
          v377,
          v378,
          v379,
          v380,
          v381,
          v382,
          v383,
          v384,
          v385);
        lim_populate_he_mcs_set(
          a1,
          (_WORD *)(v65 + 264),
          v65 + 864,
          v46,
          v237,
          v386,
          v387,
          v388,
          v389,
          v390,
          v391,
          v392,
          v393);
        v394 = *(_QWORD *)(v46 + 16);
        a24 = 0;
        if ( v394 )
        {
          if ( wlan_objmgr_vdev_get_comp_private_obj(v394, 0xAu) )
            JUMPOUT(0x63ADF8);
          JUMPOUT(0x63AE88);
        }
        JUMPOUT(0x63AE70);
      }
      BYTE1(v397[0]) = *(_BYTE *)(a2 + 37);
      if ( v222 != 1 )
        JUMPOUT(0x63AFBC);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Supported rates length: %d more than the Max limit, reset to Max",
        v170,
        v171,
        v172,
        v173,
        v174,
        v175,
        v176,
        v177,
        "lim_tdls_populate_matching_rate_set");
      v223 = *(_DWORD *)(a2 + 38);
      v224 = *(_DWORD *)(a2 + 42);
      BYTE1(v397[0]) = *(_BYTE *)(a2 + 37);
      v225 = *(_WORD *)(a2 + 46);
      *(_DWORD *)((char *)v397 + 2) = v223;
      *(_DWORD *)((char *)v397 + 6) = v224;
      WORD1(v397[1]) = v225;
      BYTE4(v397[1]) = *(_BYTE *)(a2 + 48);
    }
    JUMPOUT(0x63B1B4);
  }
  v75 = lim_assign_peer_idx(a1, v46);
  WORD2(a22) = v75;
  if ( !v75 )
  {
    v72 = *(unsigned __int8 *)(a2 + 20);
    v73 = *(unsigned __int8 *)(a2 + 21);
    v74 = "%s: No more free AID for peer: %02x:%02x:%02x:**:**:%02x";
    goto LABEL_25;
  }
  v76 = v75 - 32;
  if ( v75 >= 0x20u )
  {
    if ( v75 > 0x3Fu )
    {
LABEL_29:
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Aid: %d, for peer: %02x:%02x:%02x:**:**:%02x",
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        "lim_tdls_setup_add_sta");
      hash_entry = dph_get_hash_entry(a1, WORD2(a22), v46 + 360);
      if ( hash_entry )
      {
        v87 = hash_entry;
        lim_del_sta(a1, hash_entry, 0, v46);
        lim_delete_dph_hash_entry(a1, (unsigned __int8 *)(v87 + 350), WORD2(a22), v46);
      }
      v65 = dph_add_hash_entry(
              v79,
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              a1,
              (unsigned __int8 *)(a2 + 20),
              WORD2(a22),
              v46 + 360);
      if ( !v65 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: vdev::%d add hash entry failed",
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          "lim_tdls_setup_add_sta",
          *(unsigned __int8 *)(v46 + 10));
        JUMPOUT(0x63AF00);
      }
      goto LABEL_32;
    }
    v77 = 7256;
  }
  else
  {
    v77 = 7252;
    v76 = v75;
  }
  *(_DWORD *)(v46 + v77) |= 1 << v76;
  goto LABEL_29;
}
