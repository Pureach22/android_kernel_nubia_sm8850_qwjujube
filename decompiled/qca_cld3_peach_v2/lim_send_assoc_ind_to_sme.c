__int64 __fastcall lim_send_assoc_ind_to_sme(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned __int8 *a4,
        _WORD *a5,
        int a6,
        char a7,
        _BYTE *a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        char a17,
        char a18,
        unsigned __int16 a19)
{
  char *v19; // x25
  __int64 v21; // x19
  char v23; // w8
  unsigned __int16 *v28; // x24
  __int64 v29; // x27
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w25
  unsigned int v39; // w25
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x23
  __int64 v73; // x0
  unsigned __int8 *v74; // x1
  unsigned int v75; // w2
  unsigned __int8 v76; // w3
  unsigned int v77; // w4
  unsigned __int16 v78; // w5
  unsigned int v79; // w19
  unsigned int v80; // w20
  unsigned int v81; // w21
  int v82; // w23
  const char *v83; // x22
  __int64 v84; // x0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  int v93; // w8
  unsigned __int16 v94; // w8
  __int64 result; // x0
  const char *v96; // x2
  const char *v97; // x3
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  __int64 v106; // x27
  unsigned __int8 *v107; // x20
  __int64 v108; // x10
  char v109; // w21
  unsigned __int16 *v110; // x11
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  const char *v119; // x4
  __int64 v120; // x6
  __int64 v121; // x7
  int v122; // w8
  int v123; // w9
  __int64 v124; // x6
  _WORD *v125; // x8
  __int64 v126; // x0
  __int64 v127; // x1
  __int64 v128; // x9
  unsigned int v129; // w22
  __int64 v130; // x8
  unsigned int v131; // w19
  _BYTE *v132; // x22
  unsigned int v133; // w28
  __int64 v134; // x26
  char v135; // w8
  char v136; // w8
  unsigned __int8 *v137; // x19
  _BYTE *v138; // x26
  __int16 v139; // w9
  int v140; // w9
  unsigned int v141; // w8
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
  __int64 v158; // x25
  __int64 v159; // x20
  int v160; // w8
  char v161; // w9
  int v162; // w8
  unsigned int v163; // w8
  unsigned int v164; // w8
  unsigned int v165; // w8
  unsigned int v166; // w8
  char v167; // w8
  char v168; // w9
  char v169; // w10
  char v170; // w9
  char v171; // w10
  unsigned int v172; // w8
  unsigned int v173; // w8
  unsigned __int8 *v174; // x3
  __int64 v175; // x4
  int v176; // w8
  double v177; // d0
  double v178; // d1
  double v179; // d2
  double v180; // d3
  double v181; // d4
  double v182; // d5
  double v183; // d6
  double v184; // d7
  unsigned __int8 *v185; // x27
  __int64 v186; // x26
  void *v187; // x0
  double v188; // d0
  double v189; // d1
  double v190; // d2
  double v191; // d3
  double v192; // d4
  double v193; // d5
  double v194; // d6
  double v195; // d7
  __int64 v196; // x19
  unsigned __int8 *v197; // x1
  char *v198; // x27
  double v199; // d0
  double v200; // d1
  double v201; // d2
  double v202; // d3
  double v203; // d4
  double v204; // d5
  double v205; // d6
  double v206; // d7
  int v207; // w8
  int v208; // w9
  unsigned int v209; // w1
  bool v210; // w8
  char v211; // w9
  bool v212; // w8
  unsigned __int8 *v213; // x21
  unsigned int v214; // w25
  char v215; // w8
  double v216; // d0
  double v217; // d1
  double v218; // d2
  double v219; // d3
  double v220; // d4
  double v221; // d5
  double v222; // d6
  double v223; // d7
  double v224; // d0
  double v225; // d1
  double v226; // d2
  double v227; // d3
  double v228; // d4
  double v229; // d5
  double v230; // d6
  double v231; // d7
  int v232; // w8
  long double v233; // q0
  double v234; // d1
  double v235; // d2
  double v236; // d3
  double v237; // d4
  double v238; // d5
  double v239; // d6
  double v240; // d7
  __int64 v241; // x5
  __int64 v242; // x6
  __int64 v243; // x7
  int v244; // w8
  int v245; // w8
  __int64 v246; // x1
  __int64 v247; // x0
  __int64 v248; // x2
  __int64 v249; // x3
  double v250; // d0
  double v251; // d1
  double v252; // d2
  double v253; // d3
  double v254; // d4
  double v255; // d5
  double v256; // d6
  double v257; // d7
  double v258; // d0
  double v259; // d1
  double v260; // d2
  double v261; // d3
  double v262; // d4
  double v263; // d5
  double v264; // d6
  double v265; // d7
  double v266; // d0
  double v267; // d1
  double v268; // d2
  double v269; // d3
  double v270; // d4
  double v271; // d5
  double v272; // d6
  double v273; // d7
  __int16 v274; // w8
  _BOOL4 v275; // w10
  __int16 v276; // w12
  __int16 v277; // w9
  __int16 v278; // w8
  char v279; // w22
  int v280; // w10
  unsigned int v281; // w10
  unsigned int v282; // w10
  unsigned int v283; // w10
  char v284; // w9
  char v285; // w9
  __int16 v286; // w8
  __int16 v287; // w10
  __int16 v288; // w8
  int v289; // w22
  int v290; // w9
  int v291; // w25
  __int64 v292; // x2
  int v293; // w0
  __int16 v294; // w8
  double v295; // d0
  double v296; // d1
  double v297; // d2
  double v298; // d3
  double v299; // d4
  double v300; // d5
  double v301; // d6
  double v302; // d7
  unsigned int v303; // w4
  unsigned __int16 v304; // w5
  __int64 v305; // x0
  unsigned __int8 *v306; // x1
  __int64 v307; // x8
  int v308; // w8
  int v309; // w21
  double v310; // d0
  double v311; // d1
  double v312; // d2
  double v313; // d3
  double v314; // d4
  double v315; // d5
  double v316; // d6
  double v317; // d7
  double v318; // d0
  double v319; // d1
  double v320; // d2
  double v321; // d3
  double v322; // d4
  double v323; // d5
  double v324; // d6
  double v325; // d7
  unsigned int v326; // w4
  unsigned __int8 *v327; // x1
  unsigned __int16 v328; // w5
  __int64 v329; // x0
  unsigned int v330; // w2
  unsigned int v331; // w7
  double v332; // d0
  double v333; // d1
  double v334; // d2
  double v335; // d3
  double v336; // d4
  double v337; // d5
  double v338; // d6
  double v339; // d7
  double v340; // d0
  double v341; // d1
  double v342; // d2
  double v343; // d3
  double v344; // d4
  double v345; // d5
  double v346; // d6
  double v347; // d7
  double v348; // d0
  double v349; // d1
  double v350; // d2
  double v351; // d3
  double v352; // d4
  double v353; // d5
  double v354; // d6
  double v355; // d7
  __int16 v356; // w8
  const char *v357; // x4
  __int64 v358; // x5
  __int64 v359; // x6
  __int64 v360; // x7
  int v361; // w8
  double v362; // d0
  double v363; // d1
  double v364; // d2
  double v365; // d3
  double v366; // d4
  double v367; // d5
  double v368; // d6
  double v369; // d7
  __int64 v370; // x0
  unsigned int v371; // w8
  unsigned __int16 v372; // w0
  double v373; // d0
  double v374; // d1
  double v375; // d2
  double v376; // d3
  double v377; // d4
  double v378; // d5
  double v379; // d6
  double v380; // d7
  __int64 v381; // x0
  double v382; // d0
  double v383; // d1
  double v384; // d2
  double v385; // d3
  double v386; // d4
  double v387; // d5
  double v388; // d6
  double v389; // d7
  __int64 v390; // x5
  __int64 v391; // x6
  __int64 v392; // x7
  int v393; // w8
  __int64 v394; // x2
  __int64 v395; // x5
  __int64 v396; // x6
  __int64 v397; // x7
  int v398; // w8
  double v399; // d0
  double v400; // d1
  double v401; // d2
  double v402; // d3
  double v403; // d4
  double v404; // d5
  double v405; // d6
  double v406; // d7
  __int64 v407; // x0
  unsigned int v408; // w8
  double v409; // d0
  double v410; // d1
  double v411; // d2
  double v412; // d3
  double v413; // d4
  double v414; // d5
  double v415; // d6
  double v416; // d7
  __int64 v417; // [xsp+0h] [xbp-120h]
  __int64 v418; // [xsp+0h] [xbp-120h]
  __int64 v419; // [xsp+0h] [xbp-120h]
  unsigned int v420; // [xsp+2Ch] [xbp-F4h]
  __int64 v421; // [xsp+30h] [xbp-F0h]
  unsigned int v422; // [xsp+3Ch] [xbp-E4h]
  unsigned int v423; // [xsp+3Ch] [xbp-E4h]
  unsigned __int16 *v424; // [xsp+40h] [xbp-E0h]
  unsigned int v425; // [xsp+4Ch] [xbp-D4h]
  char *v426; // [xsp+50h] [xbp-D0h]
  char v427; // [xsp+58h] [xbp-C8h]
  char v429; // [xsp+5Ch] [xbp-C4h]
  __int64 v430; // [xsp+60h] [xbp-C0h]
  unsigned int v431; // [xsp+68h] [xbp-B8h] BYREF
  unsigned __int16 v432[6]; // [xsp+6Ch] [xbp-B4h] BYREF
  __int64 v433; // [xsp+78h] [xbp-A8h] BYREF
  __int64 v434; // [xsp+80h] [xbp-A0h]
  __int64 v435; // [xsp+88h] [xbp-98h]
  __int64 v436; // [xsp+90h] [xbp-90h]
  _QWORD v437[4]; // [xsp+98h] [xbp-88h] BYREF
  __int128 v438; // [xsp+B8h] [xbp-68h] BYREF
  __int64 v439; // [xsp+C8h] [xbp-58h]
  __int64 v440; // [xsp+D0h] [xbp-50h]
  __int64 v441; // [xsp+D8h] [xbp-48h]
  __int64 v442; // [xsp+E0h] [xbp-40h]
  __int64 v443; // [xsp+E8h] [xbp-38h]
  __int64 v444; // [xsp+F0h] [xbp-30h]
  __int64 v445; // [xsp+F8h] [xbp-28h]
  __int64 v446; // [xsp+100h] [xbp-20h]
  __int16 v447; // [xsp+108h] [xbp-18h]
  __int64 v448; // [xsp+110h] [xbp-10h]

  v19 = (char *)(a2 + 7024);
  v21 = a2;
  v448 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = *(_BYTE *)(a2 + 7024);
  v432[0] = 0;
  v427 = v23;
  v431 = 0;
  v28 = (unsigned __int16 *)dph_lookup_hash_entry(a9, a10, a11, a12, a13, a14, a15, a16, a1, a4, v432, a2 + 360);
  v29 = lim_search_pre_auth_list(a1, a4);
  v430 = v21;
  if ( !v28 )
  {
    if ( *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 3407LL) == (unsigned __int8)pe_get_current_stas_count(a1) )
    {
      v72 = jiffies;
      if ( lim_process_assoc_req_no_sta_ctx___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          4u,
          "%s: Max Sta count reached : %d",
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          "lim_process_assoc_req_no_sta_ctx",
          *(unsigned __int16 *)(a1 + 3990));
        lim_process_assoc_req_no_sta_ctx___last_ticks = v72;
      }
      v73 = a1;
      v74 = a4;
      v75 = a3;
      v76 = 0;
      v77 = 0;
      v78 = 0;
      goto LABEL_14;
    }
    v426 = v19;
    if ( !a19 && !v29 || v29 && *(_DWORD *)(v29 + 20) != 9 )
    {
      lim_send_deauth_mgmt_frame(a1, 9, a4, v21, 0);
      if ( (_BYTE)a3 )
        v119 = "ReAssoc";
      else
        v119 = "Assoc";
      if ( a4 )
      {
        v120 = *a4;
        v121 = a4[1];
        v122 = a4[2];
        v123 = a4[5];
      }
      else
      {
        v122 = 0;
        v120 = 0;
        v121 = 0;
        v123 = 0;
      }
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: rcvd %s req, sessionid: %d, without pre-auth ctx%02x:%02x:%02x:**:**:%02x",
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        "lim_process_assoc_req_no_sta_ctx",
        v119,
        *(unsigned __int16 *)(v21 + 8),
        v120,
        v121,
        v122,
        v123);
      goto LABEL_51;
    }
    if ( a19 )
    {
      if ( (lim_mlo_partner_auth_type(v21, a19, &v431) & 1) == 0 )
      {
        v96 = "%s: can't get partner auth type";
        v97 = "lim_process_assoc_req_no_sta_ctx";
LABEL_178:
        qdf_trace_msg(0x35u, 2u, v96, v64, v65, v66, v67, v68, v69, v70, v71, v97);
        goto LABEL_51;
      }
      if ( v431 == 3 )
        *((_BYTE *)a5 + 3572) = 1;
    }
    else
    {
      v431 = *(_DWORD *)(v29 + 16);
      v173 = v431;
      if ( v431 == 3 )
      {
        *((_BYTE *)a5 + 3572) = 1;
        v173 = *(_DWORD *)(v29 + 16);
      }
      if ( v173 != 4 )
        lim_delete_pre_auth_node(a1, a4);
    }
    if ( *(_DWORD *)(v21 + 88) == 1 && (*((_BYTE *)a5 + 3266) || *((_BYTE *)a5 + 3267)) && !*(_BYTE *)(v21 + 1620) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: reject assoc. wpa: %d, rsn: %d, privacy: %d",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        "lim_send_assoc_ind_to_sme");
      goto LABEL_264;
    }
    if ( *v19 & 2 | v427 & 1 )
    {
      if ( *((_BYTE *)a5 + 3263) )
      {
        LOBYTE(v433) = 0;
        if ( (unsigned int)lim_admit_control_add_ts(
                             a1,
                             a4,
                             (__int64)(a5 + 35),
                             v64,
                             v65,
                             v66,
                             v67,
                             v68,
                             v69,
                             v70,
                             v71,
                             (__int64)a5 + 233,
                             0,
                             0,
                             0,
                             &v433,
                             v21) )
        {
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: AdmitControl: TSPEC rejected",
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            "lim_chk_wmm");
          v125 = a5 + 1878;
          v126 = a1;
          v127 = 33;
          v174 = a4;
          v175 = a3;
          v124 = v21;
LABEL_105:
          lim_send_assoc_rsp_mgmt_frame(v126, v127, 1, v174, v175, 0, v124, 0, v125);
          goto LABEL_51;
        }
      }
      qdf_trace_msg(0x35u, 8u, "%s: AdmitControl: Sta OK!", v64, v65, v66, v67, v68, v69, v70, v71, "lim_chk_wmm");
    }
    v176 = *((unsigned __int8 *)a5 + 3267);
    v447 = 0;
    v445 = 0;
    v446 = 0;
    v443 = 0;
    v444 = 0;
    v441 = 0;
    v442 = 0;
    v439 = 0;
    v440 = 0;
    v438 = 0u;
    memset(v437, 0, sizeof(v437));
    v435 = 0;
    v436 = 0;
    v433 = 0;
    v434 = 0;
    if ( v176 )
    {
      if ( (unsigned int)dot11f_unpack_ie_rsn(a1, (char *)a5 + 749, *((unsigned __int8 *)a5 + 748), &v433, 0) )
      {
        v124 = v21;
LABEL_102:
        v127 = 40;
LABEL_103:
        v125 = a5 + 1878;
        v126 = a1;
        goto LABEL_104;
      }
      if ( (unsigned int)WORD2(v437[0]) - 1 <= 5
        && ((*(_DWORD *)((char *)v437 + 6) | 0x10000000) == 0x18AC0F00
         || WORD2(v437[0]) != 1
         && ((*(_DWORD *)((char *)&v437[1] + 2) | 0x10000000) == 0x18AC0F00
          || WORD2(v437[0]) != 2
          && ((*(_DWORD *)((char *)&v437[1] + 6) | 0x10000000) == 0x18AC0F00
           || WORD2(v437[0]) != 3
           && ((*(_DWORD *)((char *)&v437[2] + 2) | 0x10000000) == 0x18AC0F00
            || WORD2(v437[0]) != 4
            && ((*(_DWORD *)((char *)&v437[2] + 6) | 0x10000000) == 0x18AC0F00
             || WORD2(v437[0]) != 5 && (*(_DWORD *)((char *)&v437[3] + 2) | 0x10000000) == 0x18AC0F00))))) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: SAE AKM present",
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          "lim_is_sae_akm_present");
        if ( (a5[1786] & 1) == 0 )
        {
          v185 = a4;
          if ( *(_DWORD *)(v21 + 7036) == 3 )
          {
            v185 = wlan_p2p_parse_assoc_ie_for_device_info(
                     (unsigned __int8 *)(*((_QWORD *)a5 + 411) + 4LL),
                     *((_DWORD *)a5 + 820) - 4);
            if ( !v185 )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: p2p_device info not foundi for vdev %d",
                v64,
                v65,
                v66,
                v67,
                v68,
                v69,
                v70,
                v71,
                "lim_is_sae_peer_allowed",
                *(unsigned __int8 *)(v21 + 10));
              v124 = v21;
              goto LABEL_102;
            }
          }
          v423 = a3;
          v186 = WORD5(v438);
          if ( WORD5(v438) )
          {
            v187 = (void *)_qdf_mem_malloc(0x98u, "lim_is_pmkid_found_for_peer", 2295);
            if ( v187 )
            {
              v196 = (__int64)v187;
              if ( *((_DWORD *)a5 + 939) | (unsigned __int16)a5[1880] )
                v197 = (unsigned __int8 *)(a5 + 1878);
              else
                v197 = v185;
              qdf_mem_copy(v187, v197, 6u);
              if ( (cm_lookup_pmkid_using_bssid(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(v430 + 10), v196) & 1) != 0 )
              {
                v198 = (char *)&v438 + 12;
                while ( (unsigned int)qdf_mem_cmp(v198, (const void *)(v196 + 6), 0x10u) )
                {
                  --v186;
                  v198 += 16;
                  if ( !v186 )
                  {
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: PMKID in cache doesn't match with PMKIDs from the peer",
                      v199,
                      v200,
                      v201,
                      v202,
                      v203,
                      v204,
                      v205,
                      v206,
                      "lim_is_pmkid_found_for_peer");
                    goto LABEL_122;
                  }
                }
                _qdf_mem_free(v196);
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Valid PMKID found for SAE peer",
                  v409,
                  v410,
                  v411,
                  v412,
                  v413,
                  v414,
                  v415,
                  v416,
                  "lim_is_sae_peer_allowed");
                a3 = v423;
                goto LABEL_243;
              }
LABEL_122:
              _qdf_mem_free(v196);
            }
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: No valid PMKID found for SAE peer",
              v188,
              v189,
              v190,
              v191,
              v192,
              v193,
              v194,
              v195,
              "lim_is_sae_peer_allowed");
            v127 = 53;
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: No PMKID present in RSNIE; Tried to use SAE AKM after non-SAE authentication",
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              v70,
              v71,
              "lim_is_sae_peer_allowed");
            v127 = 13;
          }
          a3 = v423;
          v124 = v430;
          goto LABEL_103;
        }
      }
    }
LABEL_243:
    if ( (_BYTE)a3 )
      v357 = "ReAssoc";
    else
      v357 = "Assoc";
    if ( a4 )
    {
      v358 = *a4;
      v359 = a4[1];
      v360 = a4[2];
      v361 = a4[5];
    }
    else
    {
      v360 = 0;
      v358 = 0;
      v359 = 0;
      v361 = 0;
    }
    LODWORD(v417) = v361;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Received: %s Req  successful from %02x:%02x:%02x:**:**:%02x",
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      "lim_send_assoc_ind_to_sme",
      v357,
      v358,
      v359,
      v360,
      v417);
    v370 = *(_QWORD *)(v430 + 16);
    if ( *(_DWORD *)(v370 + 16) == 1
      && (wlan_vdev_mlme_is_mlo_vdev(v370, v362, v363, v364, v365, v366, v367, v368, v369) & 1) != 0
      && *((_BYTE *)a5 + 3480)
      && (v371 = *(unsigned __int8 *)(v430 + 154), v371 <= 0xD)
      && ((1 << v371) & 0x3001) != 0
      && (a19 || (qdf_is_macaddr_zero_0(a5 + 1878) & 1) == 0) )
    {
      v372 = lim_assign_mlo_conn_idx(a1, v430, a19);
    }
    else
    {
      v372 = lim_assign_peer_idx(a1, v430);
    }
    v432[0] = v372;
    if ( v372 | a19 )
    {
      if ( v372 )
      {
        v381 = dph_add_hash_entry(v373, v374, v375, v376, v377, v378, v379, v380, a1, a4, v372, v430 + 360);
        v106 = v381;
        if ( !a19 && !v381 )
        {
          if ( a4 )
          {
            v390 = *a4;
            v391 = a4[1];
            v392 = a4[2];
            v393 = a4[5];
          }
          else
          {
            v392 = 0;
            v390 = 0;
            v391 = 0;
            v393 = 0;
          }
          v21 = v430;
          LODWORD(v419) = v393;
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: couldn't add hash entry at DPH for aid: %d MacAddr:%02x:%02x:%02x:**:**:%02x",
            v382,
            v383,
            v384,
            v385,
            v386,
            v387,
            v388,
            v389,
            "lim_send_assoc_ind_to_sme",
            v432[0],
            v390,
            v391,
            v392,
            v419);
          v407 = *(_QWORD *)(v430 + 16);
          if ( *(_DWORD *)(v407 + 16) == 1
            && (wlan_vdev_mlme_is_mlo_vdev(v407, v399, v400, v401, v402, v403, v404, v405, v406) & 1) != 0
            && *((_BYTE *)a5 + 3480)
            && (v408 = *(unsigned __int8 *)(v430 + 154), v408 <= 0xD)
            && ((1 << v408) & 0x3001) != 0
            && *((_BYTE *)a5 + 3576) )
          {
            lim_release_mlo_conn_idx(a1, v432[0], v430, 1);
          }
          else
          {
            lim_release_peer_idx(a1, v432[0], v430);
          }
          v77 = v431;
          v78 = v432[0];
          v73 = a1;
          v74 = a4;
          v75 = a3;
          v76 = 1;
LABEL_14:
          lim_reject_association(v73, v74, v75, v76, v77, v78, 0, 1u, v64, v65, v66, v67, v68, v69, v70, v71, v21);
LABEL_51:
          result = 0;
          goto LABEL_52;
        }
        if ( v381 )
        {
          lim_set_mlo_recv_assoc();
          goto LABEL_38;
        }
        if ( a4 )
        {
          v395 = *a4;
          v396 = a4[1];
          v397 = a4[2];
          v398 = a4[5];
        }
        else
        {
          v397 = 0;
          v395 = 0;
          v396 = 0;
          v398 = 0;
        }
        LODWORD(v419) = v398;
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: mlo partner peer couldn't add hash entry at DPH for aid: %d MacAddr:%02x:%02x:%02x:**:**:%02x",
          v382,
          v383,
          v384,
          v385,
          v386,
          v387,
          v388,
          v389,
          "lim_send_assoc_ind_to_sme",
          v432[0],
          v395,
          v396,
          v397,
          v419);
        v394 = *(unsigned __int8 *)(v430 + 10);
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: mlo partner PeerIdx not available. Reject associaton",
          v373,
          v374,
          v375,
          v376,
          v377,
          v378,
          v379,
          v380,
          "lim_send_assoc_ind_to_sme");
        v394 = *(unsigned __int8 *)(v430 + 10);
      }
      lim_send_sme_max_assoc_exceeded_ntf(a1, a4, v394);
      goto LABEL_51;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: PeerIdx not available. Reject associaton",
      v373,
      v374,
      v375,
      v376,
      v377,
      v378,
      v379,
      v380,
      "lim_send_assoc_ind_to_sme");
LABEL_264:
    v303 = v431;
    v304 = v432[0];
    v305 = a1;
    v306 = a4;
    goto LABEL_265;
  }
  v426 = v19;
  v38 = *((_DWORD *)v28 + 2);
  if ( (*((_BYTE *)v28 + 661) & 1) != 0 || v38 != 14 )
  {
    v79 = *((unsigned __int8 *)v28 + 350);
    v80 = *((unsigned __int8 *)v28 + 351);
    v81 = *((unsigned __int8 *)v28 + 352);
    v82 = *((unsigned __int8 *)v28 + 355);
    if ( (_BYTE)a3 )
      v83 = "ReAssoc";
    else
      v83 = "Assoc";
    v84 = lim_mlm_state_str(v38);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: %s: peer:%02x:%02x:%02x:**:**:%02x in mlmState %d (%s) and sta del %d",
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      "lim_process_assoc_req_sta_ctx",
      v83,
      v79,
      v80,
      v81,
      v82,
      v38,
      v84,
      *((unsigned __int8 *)v28 + 661));
    goto LABEL_51;
  }
  v39 = v432[0];
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Re/Assoc request from station that is already associated",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "lim_process_assoc_req_sta_ctx");
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: PMF enabled: %d, SA Query state: %d",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "lim_process_assoc_req_sta_ctx",
    (*v28 >> 10) & 1,
    *((unsigned __int8 *)v28 + 644));
  if ( (*v28 & 0x400) == 0 )
    goto LABEL_5;
  v93 = *((unsigned __int8 *)v28 + 644);
  switch ( v93 )
  {
    case 3:
      *((_BYTE *)v28 + 644) = 1;
      break;
    case 2:
      v124 = v21;
      v125 = a5 + 1878;
      v126 = a1;
      v127 = 30;
LABEL_104:
      v174 = a4;
      v175 = a3;
      goto LABEL_105;
    case 1:
      *((_BYTE *)v28 + 645) = 0;
      lim_send_assoc_rsp_mgmt_frame(a1, 30, 1, a4, a3, v28, v21, 0, a5 + 1878);
      lim_send_sa_query_request_frame(a1, v28 + 320, a4, v21);
      v94 = v28[320];
      v28[321] = v94;
      v28[320] = v94 + 1;
      result = tx_timer_activate((char *)v28 + 376);
      if ( !(_DWORD)result )
      {
        *((_BYTE *)v28 + 644) = 2;
        goto LABEL_52;
      }
      v96 = "%s: PMF SA Query timer start failed!";
      v97 = "lim_process_assoc_req_sta_ctx";
      goto LABEL_178;
  }
LABEL_5:
  if ( !(_BYTE)a3 && !(unsigned int)qdf_mem_cmp(v28 + 11, a5, 2u) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Received Assoc req in state: %X STAid: %d",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "lim_process_assoc_req_sta_ctx",
      *((unsigned int *)v28 + 2),
      v39);
    goto LABEL_51;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Rcvd Assoc req from STA already connected",
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    "lim_process_assoc_req_sta_ctx");
  v28[11] = *a5;
  if ( v29 && *(_DWORD *)(v29 + 20) == 9 )
  {
    v431 = *(_DWORD *)(v29 + 16);
    lim_delete_pre_auth_node(a1, a4);
  }
  else
  {
    v431 = *((_DWORD *)v28 + 3);
  }
  if ( (*v28 & 0x400) != 0 )
  {
    if ( (tx_timer_running(v28 + 188) & 1) != 0 )
      tx_timer_deactivate(v28 + 188);
    v56 = tx_timer_delete(v28 + 188);
  }
  v106 = (__int64)v28;
  if ( !dph_init_sta_state(v56, v57, v58, v59, v60, v61, v62, v63, a1, a4, v39, v21 + 360) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: could not Init STAid: %d",
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      "lim_process_assoc_req_sta_ctx",
      v39);
    goto LABEL_51;
  }
LABEL_38:
  v421 = a1;
  v107 = a4;
  if ( *((_BYTE *)a5 + 3296) )
  {
    v108 = v430;
    v109 = a7;
    v110 = a5 + 1648;
  }
  else
  {
    v108 = v430;
    if ( *((_BYTE *)a5 + 3344) && (v426[1604] & 1) != 0 )
    {
      v109 = a7;
      v110 = a5 + 1672;
    }
    else
    {
      v109 = a7;
      v110 = nullptr;
    }
  }
  v128 = *(_QWORD *)(v108 + 384);
  v129 = v431;
  v424 = v110;
  v425 = v432[0];
  if ( v128 )
  {
    v130 = *(unsigned __int16 *)(v106 + 348);
    v131 = v431;
    v132 = a8;
    v133 = a3;
    v134 = *(_QWORD *)(v128 + 8 * v130);
    if ( v134 )
    {
      lim_free_assoc_req_frm_buf(*(_QWORD *)(v128 + 8 * v130));
      _qdf_mem_free(v134);
      v110 = v424;
      v128 = *(_QWORD *)(v430 + 384);
      v130 = *(unsigned __int16 *)(v106 + 348);
    }
    *(_QWORD *)(v128 + 8 * v130) = a5;
    a3 = v133;
    *v132 = 1;
    a8 = v132;
    v129 = v131;
  }
  v422 = a3;
  if ( *((_BYTE *)a5 + 3261) )
  {
    v135 = *(_BYTE *)(v106 + 32) & 0xF7 | (8 * (a5[1580] & 1));
    *(_BYTE *)(v106 + 32) = v135;
    if ( v110 && *(_BYTE *)v110 )
      v136 = (16 * (*(_BYTE *)v110 & 1)) | v135 & 0xEF;
    else
      v136 = v135 & 0xEF;
  }
  else
  {
    v136 = *(_BYTE *)(v106 + 32) & 0xE7;
  }
  *(_BYTE *)(v106 + 32) = v136;
  v137 = v107;
  v138 = (char *)a5 + 3161;
  lim_update_stads_he_capable(v106, a5);
  lim_update_stads_eht_capable(v106, a5);
  *(_BYTE *)(v106 + 72) = *((_BYTE *)a5 + 3263) != 0;
  memcpy((void *)(v106 + 73), a5 + 35, 0xA3u);
  v139 = *(_WORD *)((char *)a5 + 233);
  *(_BYTE *)(v106 + 238) = *((_BYTE *)a5 + 235);
  *(_WORD *)(v106 + 236) = v139;
  v140 = *(_WORD *)v106 & 0xFFEF | (16 * ((*(unsigned __int8 *)a5 >> 5) & 1));
  *(_WORD *)v106 = v140;
  v141 = (unsigned __int16)*a5;
  *(_DWORD *)(v106 + 12) = v129;
  *(_DWORD *)(v106 + 16) = a6;
  *(_BYTE *)(v106 + 356) = 1;
  *(_BYTE *)(v106 + 39) = a18 & 1;
  *(_WORD *)v106 = v140 & 0xFFDE | (v141 >> 5) & 0x20;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: auth_type = %d, akm_type = %d",
    v142,
    v143,
    v144,
    v145,
    v146,
    v147,
    v148,
    v149,
    "lim_update_sta_ds",
    v129);
  v158 = v430;
  v159 = v421;
  *(_WORD *)(v106 + 20) = a5[1];
  *(_WORD *)(v106 + 22) = *a5;
  v160 = *(unsigned __int8 *)(v430 + 154);
  if ( ((unsigned int)(v160 - 7) < 7 || v160 == 5 || !*(_BYTE *)(v430 + 154)) && (*(_BYTE *)(v106 + 32) & 8) != 0 )
  {
    v161 = *(_BYTE *)(v106 + 344) & 0xFE | ((*v138 & 0x10) != 0);
    *(_BYTE *)(v106 + 344) = v161;
    v162 = (8 * *((unsigned __int8 *)a5 + 3163)) & 0xFFE0 | v161 & 0x1F;
    *(_BYTE *)(v106 + 344) = v162;
    v163 = v162 & 0xFFFFFFF7 | (8 * ((*(unsigned __int16 *)v138 >> 12) & 1));
    *(_BYTE *)(v106 + 344) = v163;
    v164 = v163 & 0xFFFFFFEF | (16 * ((*(unsigned __int16 *)v138 >> 15) & 1));
    *(_BYTE *)(v106 + 344) = v164;
    *(_BYTE *)(v106 + 345) = (*(_WORD *)v138 & 0x800) != 0;
    *(_BYTE *)(v106 + 346) = *(_BYTE *)(v106 + 346) & 0xF8 | *((_BYTE *)a5 + 3163) & 3;
    *(_DWORD *)(v106 + 340) = (*(unsigned __int16 *)v138 >> 2) & 3;
    if ( (*(_WORD *)(v430 + 7266) & 0x20) != 0 )
    {
      v165 = v164 & 0xFFFFFFFB | (4 * (((unsigned __int8)*v138 >> 5) & 1));
    }
    else
    {
      *v138 &= ~0x20u;
      v165 = *(_BYTE *)(v106 + 344) & 0xFB;
    }
    *(_BYTE *)(v106 + 344) = v165;
    if ( (*(_BYTE *)(v430 + 7266) & 0x40) != 0 )
    {
      v166 = v165 & 0xFFFFFFFD | (2 * (((unsigned __int8)*v138 >> 6) & 1));
    }
    else
    {
      *v138 &= ~0x40u;
      LOBYTE(v166) = *(_BYTE *)(v106 + 344) & 0xFD;
    }
    *(_BYTE *)(v106 + 344) = v166;
    v167 = *(_BYTE *)(v106 + 346);
    v168 = *v138;
    v169 = (4 * *v138) & 8 | v167 & 0xF7;
    *(_BYTE *)(v106 + 346) = v169;
    if ( (unsigned int)(*(_DWORD *)(v430 + 7176) - 5) >= 0xFFFFFFFC && (v168 & 2) != 0 )
    {
      v170 = v169 & 0xCF;
      v171 = *(_BYTE *)(v106 + 32);
      *(_BYTE *)(v106 + 346) = (16 * (*(_BYTE *)(v430 + 164) & 3)) | v170;
      *(_DWORD *)(v106 + 360) = 1;
      if ( (v171 & 0x10) != 0 )
      {
        if ( *((_BYTE *)a5 + 3312) )
        {
          v172 = *((_BYTE *)a5 + 3313) & 3;
        }
        else
        {
          v207 = (*(unsigned __int16 *)((char *)v424 + 1) >> 2) & 3;
          if ( v207 == 2 )
            goto LABEL_128;
          if ( v207 != 1 )
          {
            v172 = 2;
            if ( (v424[6] & 0x2000) != 0 )
            {
              v208 = (v424[2] >> 7) & 3;
              v172 = v208 ? 4 : 2;
              if ( v208 == 1 )
                v172 = 3;
            }
            goto LABEL_137;
          }
          if ( (v424[6] & 0x2000) != 0 && (v424[2] & 0x180) != 0 )
LABEL_128:
            v172 = 4;
          else
            v172 = 3;
        }
LABEL_137:
        *(_DWORD *)(v106 + 360) = v172;
        if ( v172 >= *(_DWORD *)(v430 + 7176) )
          v209 = *(_DWORD *)(v430 + 7176);
        else
          v209 = v172;
        *(_DWORD *)(v106 + 360) = v209;
        *(_DWORD *)(v106 + 360) = wlan_dnw_update_bandwidth(*(_QWORD *)(v430 + 16));
      }
    }
    else
    {
      *(_DWORD *)(v106 + 360) = 0;
      *(_BYTE *)(v106 + 346) = v167 & 0xC7;
    }
    *(_BYTE *)(v106 + 646) = *v138 & 1;
  }
  if ( *((_BYTE *)a5 + 3314) )
    v210 = (a5[1658] & 4) == 0;
  else
    v210 = 1;
  a3 = v422;
  v211 = *(_BYTE *)(v106 + 32);
  *(_BYTE *)(v106 + 662) = v210;
  if ( (v211 & 0x10) != 0 && v426[146] )
  {
    *(_BYTE *)(v106 + 346) = *(_BYTE *)(v106 + 346) & 0xF8 | v424[2] & 7;
    *(_BYTE *)(v106 + 647) = (*((_BYTE *)v424 + 1) & 0x10) != 0;
    v212 = (*(_BYTE *)(v430 + 7269) & 0x10) != 0 && (*(unsigned __int16 *)((char *)v424 + 1) & 0x800) != 0;
    *(_BYTE *)(v106 + 365) = v212;
    v429 = v109;
    if ( (*(_BYTE *)(v430 + 7269) & 8) != 0 && (*(unsigned __int16 *)((char *)v424 + 1) & 0x1000) != 0 )
    {
      v213 = v137;
      v214 = v422;
      v215 = 1;
    }
    else
    {
      v213 = v137;
      v214 = v422;
      v215 = 0;
    }
    *(_BYTE *)(v106 + 366) = v215;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: peer_caps: suBformer: %d, suBformee: %d",
      v150,
      v151,
      v152,
      v153,
      v154,
      v155,
      v156,
      v157,
      "lim_update_sta_ds",
      (*(unsigned __int16 *)((char *)v424 + 1) >> 11) & 1,
      (*(unsigned __int16 *)((char *)v424 + 1) >> 12) & 1);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: self_cap: suBformer: %d, suBformee: %d",
      v216,
      v217,
      v218,
      v219,
      v220,
      v221,
      v222,
      v223,
      "lim_update_sta_ds",
      (*(_DWORD *)(v430 + 7268) >> 11) & 1,
      (*(_DWORD *)(v430 + 7268) >> 12) & 1);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: connection's final cap: suBformer: %d, suBformee: %d",
      v224,
      v225,
      v226,
      v227,
      v228,
      v229,
      v230,
      v231,
      "lim_update_sta_ds",
      *(unsigned __int8 *)(v106 + 365),
      *(unsigned __int8 *)(v106 + 366));
    a3 = v214;
    v158 = v430;
    v137 = v213;
    v109 = v429;
  }
  *(_BYTE *)(v106 + 367) = 0;
  v232 = *(unsigned __int8 *)(v158 + 154);
  if ( ((unsigned int)(v232 - 7) < 7 || v232 == 5 || !*(_BYTE *)(v158 + 154))
    && (*(_BYTE *)(v106 + 32) & 0x10) != 0
    && *(_BYTE *)(*(_QWORD *)(v421 + 8) + 2884LL) == 1
    && *((_BYTE *)a5 + 3436)
    && *((_BYTE *)a5 + 3440) )
  {
    *(_BYTE *)(v106 + 367) = *((_BYTE *)a5 + 3441);
  }
  lim_intersect_sta_he_caps(v421, a5, v158, v106);
  lim_intersect_sta_eht_caps(v421, a5, v158, v106);
  lim_mlo_set_mld_mac_peer(v106, a5 + 1878);
  lim_mlo_save_mlo_info(v106, a5 + 1788);
  lim_mlo_save_eml_info(v106, a5 + 1876);
  *(_WORD *)(v106 + 1266) = a5[1877];
  lim_update_stads_he_6ghz_op(v158, v106);
  qdf_mem_copy((void *)(v106 + 1036), (char *)a5 + 3223, 0x22u);
  lim_update_stads_eht_bw_320mhz(v158, v106);
  if ( !(unsigned int)lim_populate_matching_rate_set(
                        v421,
                        v106,
                        (unsigned __int64)(a5 + 22),
                        (_BYTE *)a5 + 57,
                        (_BYTE *)a5 + 3164,
                        v158,
                        (__int64)v424,
                        (__int64)(a5 + 1686),
                        (__int64)(a5 + 1740)) )
  {
    if ( *((_BYTE *)a5 + 3312) )
    {
      v245 = ((*((unsigned __int8 *)a5 + 3313) >> 4) & 7) + 1;
    }
    else if ( (~*(unsigned __int16 *)(v106 + 310) & 0xC) != 0 )
    {
      LOBYTE(v245) = 2;
    }
    else
    {
      LOBYTE(v245) = 1;
    }
    *(_BYTE *)(v106 + 364) = v245;
    v274 = *(_WORD *)v106;
    v420 = v129;
    *(_WORD *)v106 &= 0xFF7Du;
    v275 = (v427 & 1) == 0;
    if ( (*a5 & 0x200) == 0 )
      v275 = 1;
    if ( v275 )
      v276 = 0;
    else
      v276 = 130;
    v277 = v274 & 0xFE3D;
    v278 = v276 | v274 & 0xFE3D;
    *(_WORD *)v106 = v276 | v277;
    if ( v275 && *((_BYTE *)a5 + 3261) && (*v426 & 2) != 0 )
    {
      v278 = v277 | 0x42;
      *(_WORD *)v106 = v277 | 0x42;
      v279 = *v426;
      if ( *((_BYTE *)a5 + 3220) )
      {
        if ( *(_DWORD *)(v158 + 88) == 1 && !*(_BYTE *)(v158 + 1936) && (a5[1611] & 0xF) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: UAPSD not supported, reply accordingly",
            *(double *)&v233,
            v234,
            v235,
            v236,
            v237,
            v238,
            v239,
            v240,
            "lim_update_sta_ds");
          v284 = *(_BYTE *)(v106 + 238) & 0x90;
          v278 = *(_WORD *)v106;
        }
        else
        {
          v280 = *(_BYTE *)(v106 + 238) & 0xF7 | (8 * ((*((unsigned __int8 *)a5 + 3222) >> 3) & 1));
          *(_BYTE *)(v106 + 238) = v280;
          v281 = v280 & 0xFFFFFFFB | (4 * ((*((unsigned __int8 *)a5 + 3222) >> 2) & 1));
          *(_BYTE *)(v106 + 238) = v281;
          v282 = v281 & 0xFFFFFFFE | a5[1611] & 1;
          *(_BYTE *)(v106 + 238) = v282;
          v283 = v282 & 0xFFFFFFFD | (2 * ((*((unsigned __int8 *)a5 + 3222) >> 1) & 1));
          *(_BYTE *)(v106 + 238) = v283;
          v284 = v283 & 0x9F | a5[1611] & 0x60;
        }
        *(_BYTE *)(v106 + 238) = v284;
      }
      v159 = v421;
      if ( ((*((_BYTE *)a5 + 3264) != 0) & ((unsigned __int8)(v279 & 4) >> 2)) != 0 )
        v278 |= 0x100u;
    }
    v285 = *(_BYTE *)(v106 + 32);
    v286 = v278 & 0xFBFF;
    if ( (v109 & 1) != 0 )
      v287 = 1024;
    else
      v287 = 0;
    v288 = v286 | v287;
    *(_WORD *)v106 = v288;
    *(_BYTE *)(v106 + 32) = v285 & 0xFE | a3 & 1;
    *(_BYTE *)(v106 + 644) = 1;
    if ( *(unsigned __int16 *)(*(_QWORD *)(v159 + 8) + 1044LL) >= 0xAu )
      v289 = *(unsigned __int16 *)(*(_QWORD *)(v159 + 8) + 1044LL);
    else
      v289 = 200;
    if ( (v109 & 1) == 0 )
      goto LABEL_215;
    v290 = *((unsigned __int8 *)a5 + 3267);
    v291 = *(unsigned __int8 *)(v158 + 8);
    v292 = *((unsigned __int8 *)a5 + 748);
    v447 = 0;
    v445 = 0;
    v446 = 0;
    v443 = 0;
    v444 = 0;
    v441 = 0;
    v442 = 0;
    v439 = 0;
    v440 = 0;
    v438 = 0u;
    memset(v437, 0, sizeof(v437));
    v435 = 0;
    v436 = 0;
    v433 = 0;
    v434 = 0;
    if ( (!v290 || (_DWORD)v292)
      && (v293 = dot11f_unpack_ie_rsn(v159, (char *)a5 + 749, v292, &v433, 0), v288 = *(_WORD *)v106, !v293)
      && (*(_WORD *)((_BYTE *)&v438 + 7) & 0x4000) != 0 )
    {
      v356 = v288 | 0x800;
      *(_WORD *)v106 = v356;
      *(_DWORD *)(v106 + 860) = *(_DWORD *)(v430 + 284);
      if ( (v356 & 0x400) != 0 )
        goto LABEL_209;
    }
    else
    {
      v294 = v288 & 0xF7FF;
      *(_WORD *)v106 = v294;
      if ( (v294 & 0x400) != 0 )
      {
LABEL_209:
        if ( (tx_timer_running(v106 + 376) & 1) != 0 )
          tx_timer_deactivate(v106 + 376);
        *(double *)&v233 = tx_timer_delete(v106 + 376);
      }
    }
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, const char *, __int64 (__fastcall *)(), _QWORD, unsigned __int64, _QWORD, _QWORD, long double))tx_timer_create_intern)(
                         v159,
                         v106 + 376,
                         "PMF SA Query timer",
                         lim_pmf_sa_query_timer_handler,
                         v291 | (v425 << 16),
                         (27487791 * (unsigned __int64)(unsigned int)(v289 << 10)) >> 38,
                         0,
                         0,
                         v233) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: could not create PMF SA Query timer",
        v295,
        v296,
        v297,
        v298,
        v299,
        v300,
        v301,
        v302,
        "lim_update_sta_ds");
      v303 = v420;
      v304 = v425;
      v305 = v159;
      v306 = v137;
LABEL_265:
      lim_reject_association(
        v305,
        v306,
        a3,
        1u,
        v303,
        v304,
        0,
        1u,
        v177,
        v178,
        v179,
        v180,
        v181,
        v182,
        v183,
        v184,
        v430);
      goto LABEL_51;
    }
    LODWORD(v418) = *(unsigned __int8 *)(v106 + 355);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Created pmf timer assoc-id:%d sta mac%02x:%02x:%02x:**:**:%02x",
      v295,
      v296,
      v297,
      v298,
      v299,
      v300,
      v301,
      v302,
      "lim_update_sta_ds",
      *(unsigned __int16 *)(v106 + 348),
      *(unsigned __int8 *)(v106 + 350),
      *(unsigned __int8 *)(v106 + 351),
      *(unsigned __int8 *)(v106 + 352),
      v418);
    v158 = v430;
LABEL_215:
    if ( *((_BYTE *)a5 + 3314) )
    {
      lim_set_stads_rtt_cap(v106, a5 + 1658, v159);
    }
    else
    {
      *(_BYTE *)(v106 + 656) = 0;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: ExtCap not present",
        *(double *)&v233,
        v234,
        v235,
        v236,
        v237,
        v238,
        v239,
        v240,
        "lim_update_sta_ds");
    }
    lim_ap_check_6g_compatible_peer(v159, v158);
    v307 = *(_QWORD *)(v158 + 384);
    if ( v307 )
      *(_QWORD *)(v307 + 8LL * *(unsigned __int16 *)(v106 + 348)) = a5;
    *a8 = 1;
    if ( (a17 & 1) != 0 )
      goto LABEL_221;
    if ( !v28 )
    {
      *(_BYTE *)(v106 + 32) &= ~2u;
      if ( (unsigned int)lim_add_sta(v159, (unsigned __int16 *)v106, 0, v158) )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: could not Add STA with assocId: %d",
          v332,
          v333,
          v334,
          v335,
          v336,
          v337,
          v338,
          v339,
          "lim_update_sta_ctx",
          *(unsigned __int16 *)(v106 + 348));
        lim_reject_association(
          v159,
          (unsigned __int8 *)(v106 + 350),
          *(_BYTE *)(v106 + 32) & 1,
          1u,
          *(_DWORD *)(v106 + 12),
          *(_WORD *)(v106 + 348),
          1u,
          1u,
          v340,
          v341,
          v342,
          v343,
          v344,
          v345,
          v346,
          v347,
          v158);
        goto LABEL_51;
      }
      goto LABEL_221;
    }
    v309 = *(_DWORD *)(v106 + 8);
    *(_BYTE *)(v106 + 32) |= 2u;
    if ( (unsigned __int8)a3 == 1 )
    {
      if ( (unsigned int)lim_add_sta(v159, (unsigned __int16 *)v106, 0, v158) )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: UPASD not supported, REASSOC Failed",
          v310,
          v311,
          v312,
          v313,
          v314,
          v315,
          v316,
          v317,
          "lim_update_sta_ctx");
        v326 = *(_DWORD *)(v106 + 12);
        v327 = (unsigned __int8 *)(v106 + 350);
        v328 = *(_WORD *)(v106 + 348);
        v329 = v159;
        v330 = *(_BYTE *)(v106 + 32) & 1;
        v331 = 3;
LABEL_234:
        lim_reject_association(
          v329,
          v327,
          v330,
          1u,
          v326,
          v328,
          1u,
          v331,
          v318,
          v319,
          v320,
          v321,
          v322,
          v323,
          v324,
          v325,
          v158);
        result = 0;
        *(_DWORD *)(v106 + 8) = v309;
        goto LABEL_52;
      }
    }
    else
    {
      *(_DWORD *)(v106 + 8) = 23;
      if ( (unsigned int)lim_del_sta(v159, v106, 1, v158) )
      {
        LODWORD(v418) = *(unsigned __int8 *)(v106 + 355);
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Couldn't DEL STA, assocId: %d sta mac%02x:%02x:%02x:**:**:%02x",
          v348,
          v349,
          v350,
          v351,
          v352,
          v353,
          v354,
          v355,
          "lim_update_sta_ctx",
          *(unsigned __int16 *)(v106 + 348),
          *(unsigned __int8 *)(v106 + 350),
          *(unsigned __int8 *)(v106 + 351),
          *(unsigned __int8 *)(v106 + 352),
          v418);
        v326 = *(_DWORD *)(v106 + 12);
        v327 = (unsigned __int8 *)(v106 + 350);
        v328 = *(_WORD *)(v106 + 348);
        v329 = v159;
        v330 = *(_BYTE *)(v106 + 32) & 1;
        v331 = 1;
        goto LABEL_234;
      }
    }
LABEL_221:
    if ( *(_DWORD *)(v158 + 88) == 1 )
    {
      v308 = *(unsigned __int8 *)(v158 + 154);
      if ( ((unsigned int)(v308 - 7) < 7 || v308 == 5 || !*(_BYTE *)(v158 + 154))
        && *((_BYTE *)a5 + 3160)
        && *((_BYTE *)a5 + 3261) )
      {
        lim_post_sm_state_update(v159, *(unsigned int *)(v106 + 340), v106 + 350, *(unsigned __int8 *)(v158 + 10));
      }
    }
    result = 1;
    goto LABEL_52;
  }
  if ( v137 )
  {
    v241 = *v137;
    v242 = v137[1];
    v243 = v137[2];
    v244 = v137[5];
  }
  else
  {
    v243 = 0;
    v241 = 0;
    v242 = 0;
    v244 = 0;
  }
  LODWORD(v418) = v244;
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Couldn't update hash entry for aid: %d MacAddr: %02x:%02x:%02x:**:**:%02x",
    *(double *)&v233,
    v234,
    v235,
    v236,
    v237,
    v238,
    v239,
    v240,
    "lim_update_sta_ds",
    v425,
    v241,
    v242,
    v243,
    v418);
  if ( (lim_is_mlo_conn(v158, v106) & 1) != 0 )
  {
    if ( (lim_is_mlo_recv_assoc(v106) & 1) != 0 )
    {
      v246 = v425;
      v247 = v421;
      v248 = v158;
      v249 = 1;
    }
    else
    {
      v246 = v425;
      v247 = v421;
      v248 = v158;
      v249 = 0;
    }
    lim_release_mlo_conn_idx(v247, v246, v248, v249);
  }
  else
  {
    lim_release_peer_idx(v421, v425, v158);
  }
  lim_reject_association(v421, v137, a3, 1u, v129, v425, 0, 1u, v250, v251, v252, v253, v254, v255, v256, v257, v158);
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Delete dph hash entry",
    v258,
    v259,
    v260,
    v261,
    v262,
    v263,
    v264,
    v265,
    "lim_update_sta_ds");
  result = dph_delete_hash_entry(
             v266,
             v267,
             v268,
             v269,
             v270,
             v271,
             v272,
             v273,
             v421,
             v137,
             *(_WORD *)(v106 + 348),
             v158 + 360);
  if ( (_DWORD)result )
  {
    v96 = "%s: error deleting hash entry";
    v97 = "lim_update_sta_ds";
    goto LABEL_178;
  }
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return result;
}
