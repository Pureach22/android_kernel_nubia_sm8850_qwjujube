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
        __int16 a19)
{
  unsigned __int16 *v26; // x24
  __int64 v27; // x28
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w25
  unsigned int v37; // w25
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x23
  __int64 v71; // x0
  unsigned __int8 *v72; // x1
  unsigned int v73; // w2
  unsigned __int8 v74; // w3
  unsigned int v75; // w4
  unsigned __int16 v76; // w5
  unsigned __int8 v77; // w6
  unsigned int v78; // w19
  unsigned int v79; // w20
  unsigned int v80; // w21
  int v81; // w23
  const char *v82; // x22
  __int64 v83; // x0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  const char *v92; // x2
  const char *v93; // x3
  int v94; // w8
  unsigned __int16 v95; // w8
  __int64 result; // x0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  __int64 v105; // x28
  __int64 v106; // x21
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  const char *v115; // x4
  __int64 v116; // x6
  __int64 v117; // x7
  int v118; // w8
  int v119; // w9
  _WORD *v120; // x8
  __int64 v121; // x0
  __int64 v122; // x1
  __int64 v123; // x9
  char v124; // w25
  __int64 v125; // x8
  __int64 v126; // x25
  _BYTE *v127; // x21
  unsigned int v128; // w26
  __int64 v129; // x27
  char v130; // w8
  char v131; // w8
  _BYTE *v132; // x27
  __int16 v133; // w9
  int v134; // w9
  unsigned int v135; // w8
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  char v152; // w25
  int v153; // w8
  char v154; // w9
  int v155; // w8
  unsigned int v156; // w8
  unsigned int v157; // w8
  unsigned int v158; // w8
  unsigned int v159; // w8
  char v160; // w8
  char v161; // w9
  char v162; // w10
  char v163; // w9
  char v164; // w10
  unsigned int v165; // w8
  unsigned int v166; // w8
  int v167; // w8
  int v168; // w8
  unsigned __int8 *v169; // x28
  __int64 v170; // x27
  void *v171; // x0
  double v172; // d0
  double v173; // d1
  double v174; // d2
  double v175; // d3
  double v176; // d4
  double v177; // d5
  double v178; // d6
  double v179; // d7
  __int64 v180; // x25
  unsigned __int8 *v181; // x1
  char *v182; // x28
  double v183; // d0
  double v184; // d1
  double v185; // d2
  double v186; // d3
  double v187; // d4
  double v188; // d5
  double v189; // d6
  double v190; // d7
  int v191; // w9
  unsigned int v192; // w1
  bool v193; // w8
  unsigned int v194; // w27
  char v195; // w9
  bool v196; // w8
  _BYTE *v197; // x25
  char v198; // w8
  double v199; // d0
  double v200; // d1
  double v201; // d2
  double v202; // d3
  double v203; // d4
  double v204; // d5
  double v205; // d6
  double v206; // d7
  double v207; // d0
  double v208; // d1
  double v209; // d2
  double v210; // d3
  double v211; // d4
  double v212; // d5
  double v213; // d6
  double v214; // d7
  int v215; // w8
  long double v216; // q0
  double v217; // d1
  double v218; // d2
  double v219; // d3
  double v220; // d4
  double v221; // d5
  double v222; // d6
  double v223; // d7
  __int64 v224; // x5
  __int64 v225; // x6
  __int64 v226; // x7
  int v227; // w8
  int v228; // w8
  double v229; // d0
  double v230; // d1
  double v231; // d2
  double v232; // d3
  double v233; // d4
  double v234; // d5
  double v235; // d6
  double v236; // d7
  double v237; // d0
  double v238; // d1
  double v239; // d2
  double v240; // d3
  double v241; // d4
  double v242; // d5
  double v243; // d6
  double v244; // d7
  double v245; // d0
  double v246; // d1
  double v247; // d2
  double v248; // d3
  double v249; // d4
  double v250; // d5
  double v251; // d6
  double v252; // d7
  __int16 v253; // w8
  _BOOL4 v254; // w10
  __int16 v255; // w12
  __int16 v256; // w9
  __int16 v257; // w8
  char v258; // w21
  int v259; // w10
  unsigned int v260; // w10
  unsigned int v261; // w10
  unsigned int v262; // w10
  char v263; // w9
  char v264; // w9
  __int16 v265; // w8
  __int16 v266; // w10
  __int16 v267; // w8
  int v268; // w21
  int v269; // w25
  __int64 v270; // x2
  int v271; // w9
  int v272; // w0
  __int16 v273; // w8
  double v274; // d0
  double v275; // d1
  double v276; // d2
  double v277; // d3
  double v278; // d4
  double v279; // d5
  double v280; // d6
  double v281; // d7
  __int64 v282; // x8
  int v283; // w8
  int v284; // w21
  double v285; // d0
  double v286; // d1
  double v287; // d2
  double v288; // d3
  double v289; // d4
  double v290; // d5
  double v291; // d6
  double v292; // d7
  double v293; // d0
  double v294; // d1
  double v295; // d2
  double v296; // d3
  double v297; // d4
  double v298; // d5
  double v299; // d6
  double v300; // d7
  unsigned int v301; // w4
  unsigned __int8 *v302; // x1
  unsigned __int16 v303; // w5
  __int64 v304; // x0
  unsigned int v305; // w2
  unsigned int v306; // w7
  double v307; // d0
  double v308; // d1
  double v309; // d2
  double v310; // d3
  double v311; // d4
  double v312; // d5
  double v313; // d6
  double v314; // d7
  double v315; // d0
  double v316; // d1
  double v317; // d2
  double v318; // d3
  double v319; // d4
  double v320; // d5
  double v321; // d6
  double v322; // d7
  __int16 v323; // w8
  const char *v324; // x4
  __int64 v325; // x5
  __int64 v326; // x6
  __int64 v327; // x7
  int v328; // w8
  unsigned __int16 v329; // w0
  double v330; // d0
  double v331; // d1
  double v332; // d2
  double v333; // d3
  double v334; // d4
  double v335; // d5
  double v336; // d6
  double v337; // d7
  __int64 v338; // x0
  double v339; // d0
  double v340; // d1
  double v341; // d2
  double v342; // d3
  double v343; // d4
  double v344; // d5
  double v345; // d6
  double v346; // d7
  __int64 v347; // x5
  __int64 v348; // x6
  __int64 v349; // x7
  int v350; // w8
  double v351; // d0
  double v352; // d1
  double v353; // d2
  double v354; // d3
  double v355; // d4
  double v356; // d5
  double v357; // d6
  double v358; // d7
  __int64 v359; // [xsp+0h] [xbp-100h]
  _WORD *v360; // [xsp+0h] [xbp-100h]
  __int64 v361; // [xsp+0h] [xbp-100h]
  unsigned int v362; // [xsp+28h] [xbp-D8h]
  unsigned int v363; // [xsp+2Ch] [xbp-D4h]
  unsigned int v364; // [xsp+2Ch] [xbp-D4h]
  unsigned int v365; // [xsp+30h] [xbp-D0h]
  char v366; // [xsp+34h] [xbp-CCh]
  char v367; // [xsp+38h] [xbp-C8h]
  char *v369; // [xsp+40h] [xbp-C0h]
  unsigned __int16 v370[6]; // [xsp+4Ch] [xbp-B4h] BYREF
  __int64 v371; // [xsp+58h] [xbp-A8h] BYREF
  __int64 v372; // [xsp+60h] [xbp-A0h]
  __int64 v373; // [xsp+68h] [xbp-98h]
  __int64 v374; // [xsp+70h] [xbp-90h]
  _QWORD v375[4]; // [xsp+78h] [xbp-88h] BYREF
  __int128 v376; // [xsp+98h] [xbp-68h] BYREF
  __int64 v377; // [xsp+A8h] [xbp-58h]
  __int64 v378; // [xsp+B0h] [xbp-50h]
  __int64 v379; // [xsp+B8h] [xbp-48h]
  __int64 v380; // [xsp+C0h] [xbp-40h]
  __int64 v381; // [xsp+C8h] [xbp-38h]
  __int64 v382; // [xsp+D0h] [xbp-30h]
  __int64 v383; // [xsp+D8h] [xbp-28h]
  __int64 v384; // [xsp+E0h] [xbp-20h]
  __int16 v385; // [xsp+E8h] [xbp-18h]
  __int64 v386; // [xsp+F0h] [xbp-10h]

  v386 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v369 = (char *)(a2 + 7024);
  v367 = *(_BYTE *)(a2 + 7024);
  v370[0] = 0;
  v26 = (unsigned __int16 *)dph_lookup_hash_entry(a9, a10, a11, a12, a13, a14, a15, a16, a1, a4, v370, a2 + 360);
  v27 = lim_search_pre_auth_list(a1, a4);
  if ( !v26 )
  {
    if ( *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 3207LL) == (unsigned __int8)pe_get_current_stas_count(a1) )
    {
      v70 = jiffies;
      if ( lim_process_assoc_req_no_sta_ctx___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          4u,
          "%s: Max Sta count reached : %d",
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          "lim_process_assoc_req_no_sta_ctx",
          *(unsigned __int16 *)(a1 + 3990));
        lim_process_assoc_req_no_sta_ctx___last_ticks = v70;
      }
      v71 = a1;
      v72 = a4;
      v73 = a3;
      v74 = 0;
      v75 = 0;
      v76 = 0;
      goto LABEL_14;
    }
    if ( !a19 && !v27 || v27 && *(_DWORD *)(v27 + 20) != 9 )
    {
      lim_send_deauth_mgmt_frame(a1, 9, a4, a2, 0);
      if ( (_BYTE)a3 )
        v115 = "ReAssoc";
      else
        v115 = "Assoc";
      if ( a4 )
      {
        v116 = *a4;
        v117 = a4[1];
        v118 = a4[2];
        v119 = a4[5];
      }
      else
      {
        v118 = 0;
        v116 = 0;
        v117 = 0;
        v119 = 0;
      }
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: rcvd %s req, sessionid: %d, without pre-auth ctx%02x:%02x:%02x:**:**:%02x",
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        "lim_process_assoc_req_no_sta_ctx",
        v115,
        *(unsigned __int16 *)(a2 + 8),
        v116,
        v117,
        v118,
        v119);
      goto LABEL_167;
    }
    if ( a19 )
    {
      v92 = "%s: can't get partner auth type";
      v93 = "lim_process_assoc_req_no_sta_ctx";
      goto LABEL_166;
    }
    v166 = *(_DWORD *)(v27 + 16);
    v365 = v166;
    if ( v166 == 3 )
    {
      *((_BYTE *)a5 + 3572) = 1;
      v166 = *(_DWORD *)(v27 + 16);
    }
    if ( v166 != 4 )
      lim_delete_pre_auth_node(a1, a4);
    if ( *(_DWORD *)(a2 + 88) == 1 && (*((_BYTE *)a5 + 3266) || *((_BYTE *)a5 + 3267)) && !*(_BYTE *)(a2 + 1620) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: reject assoc. wpa: %d, rsn: %d, privacy: %d",
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        "lim_send_assoc_ind_to_sme");
      goto LABEL_247;
    }
    if ( *v369 & 2 | v367 & 1 )
    {
      if ( *((_BYTE *)a5 + 3263) )
      {
        LOBYTE(v371) = 0;
        if ( (unsigned int)lim_admit_control_add_ts(
                             a1,
                             a4,
                             (__int64)(a5 + 35),
                             v62,
                             v63,
                             v64,
                             v65,
                             v66,
                             v67,
                             v68,
                             v69,
                             (__int64)a5 + 233,
                             0,
                             0,
                             0,
                             &v371,
                             a2) )
        {
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: AdmitControl: TSPEC rejected",
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            "lim_chk_wmm");
          v120 = a5 + 1804;
          v121 = a1;
          v122 = 33;
          goto LABEL_51;
        }
      }
      qdf_trace_msg(0x35u, 8u, "%s: AdmitControl: Sta OK!", v62, v63, v64, v65, v66, v67, v68, v69, "lim_chk_wmm");
    }
    v167 = *((unsigned __int8 *)a5 + 3267);
    v385 = 0;
    v383 = 0;
    v384 = 0;
    v382 = 0;
    v380 = 0;
    v381 = 0;
    v378 = 0;
    v379 = 0;
    v377 = 0;
    v376 = 0u;
    v374 = 0;
    memset(v375, 0, sizeof(v375));
    v372 = 0;
    v373 = 0;
    v371 = 0;
    if ( v167 )
    {
      if ( (unsigned int)dot11f_unpack_ie_rsn(a1, (char *)a5 + 749, *((unsigned __int8 *)a5 + 748), &v371, 0) )
      {
LABEL_98:
        v122 = 40;
LABEL_99:
        v120 = a5 + 1804;
        v121 = a1;
        goto LABEL_51;
      }
      if ( (unsigned int)WORD2(v375[0]) - 1 <= 5
        && ((*(_DWORD *)((char *)v375 + 6) | 0x10000000) == 0x18AC0F00
         || WORD2(v375[0]) != 1
         && ((*(_DWORD *)((char *)&v375[1] + 2) | 0x10000000) == 0x18AC0F00
          || WORD2(v375[0]) != 2
          && ((*(_DWORD *)((char *)&v375[1] + 6) | 0x10000000) == 0x18AC0F00
           || WORD2(v375[0]) != 3
           && ((*(_DWORD *)((char *)&v375[2] + 2) | 0x10000000) == 0x18AC0F00
            || WORD2(v375[0]) != 4
            && ((*(_DWORD *)((char *)&v375[2] + 6) | 0x10000000) == 0x18AC0F00
             || WORD2(v375[0]) != 5 && (*(_DWORD *)((char *)&v375[3] + 2) | 0x10000000) == 0x18AC0F00))))) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: SAE AKM present",
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          "lim_is_sae_akm_present");
        if ( (a5[1786] & 1) == 0 )
        {
          v169 = a4;
          if ( *(_DWORD *)(a2 + 7036) == 3 )
          {
            v169 = wlan_p2p_parse_assoc_ie_for_device_info(
                     (unsigned __int8 *)(*((_QWORD *)a5 + 411) + 4LL),
                     *((_DWORD *)a5 + 820) - 4);
            if ( !v169 )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: p2p_device info not foundi for vdev %d",
                v62,
                v63,
                v64,
                v65,
                v66,
                v67,
                v68,
                v69,
                "lim_is_sae_peer_allowed",
                *(unsigned __int8 *)(a2 + 10));
              goto LABEL_98;
            }
          }
          v364 = a3;
          v170 = WORD5(v376);
          if ( WORD5(v376) )
          {
            v171 = (void *)_qdf_mem_malloc(0x98u, "lim_is_pmkid_found_for_peer", 2295);
            if ( v171 )
            {
              v180 = (__int64)v171;
              if ( *((_DWORD *)a5 + 902) | (unsigned __int16)a5[1806] )
                v181 = (unsigned __int8 *)(a5 + 1804);
              else
                v181 = v169;
              qdf_mem_copy(v171, v181, 6u);
              if ( (cm_lookup_pmkid_using_bssid(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a2 + 10), v180) & 1) != 0 )
              {
                v182 = (char *)&v376 + 12;
                while ( (unsigned int)qdf_mem_cmp(v182, (const void *)(v180 + 6), 0x10u) )
                {
                  --v170;
                  v182 += 16;
                  if ( !v170 )
                  {
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: PMKID in cache doesn't match with PMKIDs from the peer",
                      v183,
                      v184,
                      v185,
                      v186,
                      v187,
                      v188,
                      v189,
                      v190,
                      "lim_is_pmkid_found_for_peer");
                    goto LABEL_121;
                  }
                }
                _qdf_mem_free(v180);
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Valid PMKID found for SAE peer",
                  v351,
                  v352,
                  v353,
                  v354,
                  v355,
                  v356,
                  v357,
                  v358,
                  "lim_is_sae_peer_allowed");
                a3 = v364;
                goto LABEL_233;
              }
LABEL_121:
              _qdf_mem_free(v180);
            }
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: No valid PMKID found for SAE peer",
              v172,
              v173,
              v174,
              v175,
              v176,
              v177,
              v178,
              v179,
              "lim_is_sae_peer_allowed");
            v122 = 53;
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: No PMKID present in RSNIE; Tried to use SAE AKM after non-SAE authentication",
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              "lim_is_sae_peer_allowed");
            v122 = 13;
          }
          a3 = v364;
          goto LABEL_99;
        }
      }
    }
LABEL_233:
    if ( (_BYTE)a3 )
      v324 = "ReAssoc";
    else
      v324 = "Assoc";
    if ( a4 )
    {
      v325 = *a4;
      v326 = a4[1];
      v327 = a4[2];
      v328 = a4[5];
    }
    else
    {
      v327 = 0;
      v325 = 0;
      v326 = 0;
      v328 = 0;
    }
    LODWORD(v359) = v328;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Received: %s Req  successful from %02x:%02x:%02x:**:**:%02x",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "lim_send_assoc_ind_to_sme",
      v324,
      v325,
      v326,
      v327,
      v359);
    v329 = lim_assign_peer_idx(a1, a2);
    v370[0] = v329;
    if ( v329 )
    {
      v338 = dph_add_hash_entry(v330, v331, v332, v333, v334, v335, v336, v337, a1, a4, v329, a2 + 360);
      if ( v338 )
      {
        v105 = v338;
        v366 = a7;
        goto LABEL_37;
      }
      if ( a4 )
      {
        v347 = *a4;
        v348 = a4[1];
        v349 = a4[2];
        v350 = a4[5];
      }
      else
      {
        v349 = 0;
        v347 = 0;
        v348 = 0;
        v350 = 0;
      }
      LODWORD(v361) = v350;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: couldn't add hash entry at DPH for aid: %d MacAddr:%02x:%02x:%02x:**:**:%02x",
        v339,
        v340,
        v341,
        v342,
        v343,
        v344,
        v345,
        v346,
        "lim_send_assoc_ind_to_sme",
        v370[0],
        v347,
        v348,
        v349,
        v361);
      lim_release_peer_idx(a1, v370[0], a2);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: PeerIdx not available. Reject associaton",
        v330,
        v331,
        v332,
        v333,
        v334,
        v335,
        v336,
        v337,
        "lim_send_assoc_ind_to_sme");
    }
LABEL_247:
    v76 = v370[0];
    v75 = v365;
    v71 = a1;
    v72 = a4;
    v73 = a3;
    v74 = 1;
    goto LABEL_14;
  }
  v36 = *((_DWORD *)v26 + 2);
  v366 = a7;
  if ( (*((_BYTE *)v26 + 645) & 1) != 0 || v36 != 14 )
  {
    v78 = *((unsigned __int8 *)v26 + 338);
    v79 = *((unsigned __int8 *)v26 + 339);
    v80 = *((unsigned __int8 *)v26 + 340);
    v81 = *((unsigned __int8 *)v26 + 343);
    if ( (_BYTE)a3 )
      v82 = "ReAssoc";
    else
      v82 = "Assoc";
    v83 = lim_mlm_state_str(v36);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: %s: peer:%02x:%02x:%02x:**:**:%02x in mlmState %d (%s) and sta del %d",
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      "lim_process_assoc_req_sta_ctx",
      v82,
      v78,
      v79,
      v80,
      v81,
      v36,
      v83,
      *((unsigned __int8 *)v26 + 645));
    goto LABEL_167;
  }
  v37 = v370[0];
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Re/Assoc request from station that is already associated",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "lim_process_assoc_req_sta_ctx");
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: PMF enabled: %d, SA Query state: %d",
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    "lim_process_assoc_req_sta_ctx",
    (*v26 >> 10) & 1,
    *((unsigned __int8 *)v26 + 628));
  if ( (*v26 & 0x400) != 0 )
  {
    v94 = *((unsigned __int8 *)v26 + 628);
    if ( v94 == 3 )
    {
      *((_BYTE *)v26 + 628) = 1;
      goto LABEL_5;
    }
    if ( v94 != 2 )
    {
      if ( v94 != 1 )
        goto LABEL_5;
      *((_BYTE *)v26 + 629) = 0;
      lim_send_assoc_rsp_mgmt_frame(a1, 30, 1, a4, a3, v26, a2, 0, a5 + 1804);
      lim_send_sa_query_request_frame(a1, v26 + 312, a4, a2);
      v95 = v26[312];
      v26[313] = v95;
      v26[312] = v95 + 1;
      result = tx_timer_activate((char *)v26 + 360);
      if ( !(_DWORD)result )
      {
        *((_BYTE *)v26 + 628) = 2;
        goto LABEL_168;
      }
      v92 = "%s: PMF SA Query timer start failed!";
      v93 = "lim_process_assoc_req_sta_ctx";
LABEL_166:
      qdf_trace_msg(0x35u, 2u, v92, v62, v63, v64, v65, v66, v67, v68, v69, v93);
      goto LABEL_167;
    }
    v120 = a5 + 1804;
    v121 = a1;
    v122 = 30;
LABEL_51:
    lim_send_assoc_rsp_mgmt_frame(v121, v122, 1, a4, a3, 0, a2, 0, v120);
    goto LABEL_167;
  }
LABEL_5:
  if ( !(_BYTE)a3 && !(unsigned int)qdf_mem_cmp(v26 + 11, a5, 2u) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Received Assoc req in state: %X STAid: %d",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "lim_process_assoc_req_sta_ctx",
      *((unsigned int *)v26 + 2),
      v37);
    goto LABEL_167;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Rcvd Assoc req from STA already connected",
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    "lim_process_assoc_req_sta_ctx");
  v26[11] = *a5;
  if ( v27 && *(_DWORD *)(v27 + 20) == 9 )
  {
    v365 = *(_DWORD *)(v27 + 16);
    lim_delete_pre_auth_node(a1, a4);
  }
  else
  {
    v365 = *((_DWORD *)v26 + 3);
  }
  if ( (*v26 & 0x400) != 0 )
  {
    if ( (tx_timer_running(v26 + 180) & 1) != 0 )
      tx_timer_deactivate(v26 + 180);
    v54 = tx_timer_delete(v26 + 180);
  }
  v105 = (__int64)v26;
  if ( !dph_init_sta_state(v54, v55, v56, v57, v58, v59, v60, v61, a1, a4, v37, a2 + 360) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: could not Init STAid: %d",
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      "lim_process_assoc_req_sta_ctx",
      v37);
    goto LABEL_167;
  }
LABEL_37:
  if ( *((_BYTE *)a5 + 3296) )
  {
    v106 = (__int64)(a5 + 1648);
  }
  else if ( *((_BYTE *)a5 + 3344) && (v369[1604] & 1) != 0 )
  {
    v106 = (__int64)(a5 + 1672);
  }
  else
  {
    v106 = 0;
  }
  v123 = *(_QWORD *)(a2 + 384);
  v124 = a18 & 1;
  v362 = v370[0];
  if ( v123 )
  {
    v125 = *(unsigned __int16 *)(v105 + 336);
    v126 = v106;
    v127 = a8;
    v128 = a3;
    v129 = *(_QWORD *)(v123 + 8 * v125);
    if ( v129 )
    {
      lim_free_assoc_req_frm_buf(*(_QWORD *)(v123 + 8 * v125));
      _qdf_mem_free(v129);
      v123 = *(_QWORD *)(a2 + 384);
      v125 = *(unsigned __int16 *)(v105 + 336);
    }
    *(_QWORD *)(v123 + 8 * v125) = a5;
    a3 = v128;
    *v127 = 1;
    a8 = v127;
    v106 = v126;
    v124 = a18 & 1;
  }
  v363 = a3;
  if ( *((_BYTE *)a5 + 3261) )
  {
    v130 = *(_BYTE *)(v105 + 32) & 0xF7 | (8 * (a5[1580] & 1));
    *(_BYTE *)(v105 + 32) = v130;
    if ( v106 && *(_BYTE *)v106 )
      v131 = (16 * (*(_BYTE *)v106 & 1)) | v130 & 0xEF;
    else
      v131 = v130 & 0xEF;
  }
  else
  {
    v131 = *(_BYTE *)(v105 + 32) & 0xE7;
  }
  *(_BYTE *)(v105 + 32) = v131;
  v132 = (char *)a5 + 3161;
  lim_update_stads_he_capable(v105, a5);
  *(_BYTE *)(v105 + 72) = *((_BYTE *)a5 + 3263) != 0;
  memcpy((void *)(v105 + 73), a5 + 35, 0xA3u);
  v133 = *(_WORD *)((char *)a5 + 233);
  *(_BYTE *)(v105 + 238) = *((_BYTE *)a5 + 235);
  *(_WORD *)(v105 + 236) = v133;
  v134 = *(_WORD *)v105 & 0xFFEF | (16 * ((*(unsigned __int8 *)a5 >> 5) & 1));
  *(_WORD *)v105 = v134;
  v135 = (unsigned __int16)*a5;
  *(_DWORD *)(v105 + 12) = v365;
  *(_DWORD *)(v105 + 16) = a6;
  *(_BYTE *)(v105 + 344) = 1;
  *(_BYTE *)(v105 + 39) = v124;
  *(_WORD *)v105 = v134 & 0xFFDE | (v135 >> 5) & 0x20;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: auth_type = %d, akm_type = %d",
    v136,
    v137,
    v138,
    v139,
    v140,
    v141,
    v142,
    v143,
    "lim_update_sta_ds");
  v152 = v366;
  *(_WORD *)(v105 + 20) = a5[1];
  *(_WORD *)(v105 + 22) = *a5;
  v153 = *(unsigned __int8 *)(a2 + 154);
  if ( ((unsigned int)(v153 - 7) < 7 || v153 == 5 || !*(_BYTE *)(a2 + 154)) && (*(_BYTE *)(v105 + 32) & 8) != 0 )
  {
    v154 = *(_BYTE *)(v105 + 332) & 0xFE | ((*v132 & 0x10) != 0);
    *(_BYTE *)(v105 + 332) = v154;
    v155 = (8 * *((unsigned __int8 *)a5 + 3163)) & 0xFFE0 | v154 & 0x1F;
    *(_BYTE *)(v105 + 332) = v155;
    v156 = v155 & 0xFFFFFFF7 | (8 * ((*(unsigned __int16 *)v132 >> 12) & 1));
    *(_BYTE *)(v105 + 332) = v156;
    v157 = v156 & 0xFFFFFFEF | (16 * ((*(unsigned __int16 *)v132 >> 15) & 1));
    *(_BYTE *)(v105 + 332) = v157;
    *(_BYTE *)(v105 + 333) = (*(_WORD *)v132 & 0x800) != 0;
    *(_BYTE *)(v105 + 334) = *(_BYTE *)(v105 + 334) & 0xF8 | *((_BYTE *)a5 + 3163) & 3;
    *(_DWORD *)(v105 + 328) = (*(unsigned __int16 *)v132 >> 2) & 3;
    if ( (*(_WORD *)(a2 + 7266) & 0x20) != 0 )
    {
      v158 = v157 & 0xFFFFFFFB | (4 * (((unsigned __int8)*v132 >> 5) & 1));
    }
    else
    {
      *v132 &= ~0x20u;
      v158 = *(_BYTE *)(v105 + 332) & 0xFB;
    }
    *(_BYTE *)(v105 + 332) = v158;
    if ( (*(_BYTE *)(a2 + 7266) & 0x40) != 0 )
    {
      v159 = v158 & 0xFFFFFFFD | (2 * (((unsigned __int8)*v132 >> 6) & 1));
    }
    else
    {
      *v132 &= ~0x40u;
      LOBYTE(v159) = *(_BYTE *)(v105 + 332) & 0xFD;
    }
    *(_BYTE *)(v105 + 332) = v159;
    v160 = *(_BYTE *)(v105 + 334);
    v161 = *v132;
    v162 = (4 * *v132) & 8 | v160 & 0xF7;
    *(_BYTE *)(v105 + 334) = v162;
    if ( (unsigned int)(*(_DWORD *)(a2 + 7176) - 5) >= 0xFFFFFFFC && (v161 & 2) != 0 )
    {
      v163 = v162 & 0xCF;
      v164 = *(_BYTE *)(v105 + 32);
      *(_BYTE *)(v105 + 334) = (16 * (*(_BYTE *)(a2 + 164) & 3)) | v163;
      *(_DWORD *)(v105 + 348) = 1;
      if ( (v164 & 0x10) != 0 )
      {
        if ( *((_BYTE *)a5 + 3312) )
        {
          v165 = *((_BYTE *)a5 + 3313) & 3;
        }
        else
        {
          v168 = (*(unsigned __int16 *)(v106 + 1) >> 2) & 3;
          if ( v168 == 2 )
            goto LABEL_104;
          if ( v168 != 1 )
          {
            v165 = 2;
            if ( (*(_WORD *)(v106 + 12) & 0x2000) != 0 )
            {
              v191 = (*(unsigned __int16 *)(v106 + 4) >> 7) & 3;
              v165 = v191 ? 4 : 2;
              if ( v191 == 1 )
                v165 = 3;
            }
            goto LABEL_131;
          }
          if ( (*(_WORD *)(v106 + 12) & 0x2000) != 0 && (*(_WORD *)(v106 + 4) & 0x180) != 0 )
LABEL_104:
            v165 = 4;
          else
            v165 = 3;
        }
LABEL_131:
        *(_DWORD *)(v105 + 348) = v165;
        if ( v165 >= *(_DWORD *)(a2 + 7176) )
          v192 = *(_DWORD *)(a2 + 7176);
        else
          v192 = v165;
        *(_DWORD *)(v105 + 348) = v192;
        *(_DWORD *)(v105 + 348) = wlan_dnw_update_bandwidth(*(_QWORD *)(a2 + 16));
      }
    }
    else
    {
      *(_DWORD *)(v105 + 348) = 0;
      *(_BYTE *)(v105 + 334) = v160 & 0xC7;
    }
    *(_BYTE *)(v105 + 630) = *v132 & 1;
  }
  if ( *((_BYTE *)a5 + 3314) )
    v193 = (a5[1658] & 4) == 0;
  else
    v193 = 1;
  v194 = v363;
  v195 = *(_BYTE *)(v105 + 32);
  *(_BYTE *)(v105 + 646) = v193;
  if ( (v195 & 0x10) != 0 && v369[146] )
  {
    *(_BYTE *)(v105 + 334) = *(_BYTE *)(v105 + 334) & 0xF8 | *(_BYTE *)(v106 + 4) & 7;
    *(_BYTE *)(v105 + 631) = (*(_BYTE *)(v106 + 1) & 0x10) != 0;
    v196 = (*(_BYTE *)(a2 + 7269) & 0x10) != 0 && (*(_WORD *)(v106 + 1) & 0x800) != 0;
    *(_BYTE *)(v105 + 353) = v196;
    if ( (*(_BYTE *)(a2 + 7269) & 8) != 0 && (*(_WORD *)(v106 + 1) & 0x1000) != 0 )
    {
      v197 = a8;
      v198 = 1;
    }
    else
    {
      v197 = a8;
      v198 = 0;
    }
    *(_BYTE *)(v105 + 354) = v198;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: peer_caps: suBformer: %d, suBformee: %d",
      v144,
      v145,
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      "lim_update_sta_ds",
      (*(unsigned __int16 *)(v106 + 1) >> 11) & 1,
      (*(unsigned __int16 *)(v106 + 1) >> 12) & 1);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: self_cap: suBformer: %d, suBformee: %d",
      v199,
      v200,
      v201,
      v202,
      v203,
      v204,
      v205,
      v206,
      "lim_update_sta_ds",
      (*(_DWORD *)(a2 + 7268) >> 11) & 1,
      (*(_DWORD *)(a2 + 7268) >> 12) & 1);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: connection's final cap: suBformer: %d, suBformee: %d",
      v207,
      v208,
      v209,
      v210,
      v211,
      v212,
      v213,
      v214,
      "lim_update_sta_ds",
      *(unsigned __int8 *)(v105 + 353),
      *(unsigned __int8 *)(v105 + 354));
    a8 = v197;
    v152 = v366;
    v194 = v363;
  }
  *(_BYTE *)(v105 + 355) = 0;
  v215 = *(unsigned __int8 *)(a2 + 154);
  if ( ((unsigned int)(v215 - 7) < 7 || v215 == 5 || !*(_BYTE *)(a2 + 154))
    && (*(_BYTE *)(v105 + 32) & 0x10) != 0
    && *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2680LL) == 1
    && *((_BYTE *)a5 + 3436)
    && *((_BYTE *)a5 + 3440) )
  {
    *(_BYTE *)(v105 + 355) = *((_BYTE *)a5 + 3441);
  }
  lim_intersect_sta_he_caps(a1, a5, a2, v105);
  lim_update_stads_he_6ghz_op(a2, v105);
  qdf_mem_copy((void *)(v105 + 902), (char *)a5 + 3223, 0x22u);
  v360 = a5 + 1740;
  if ( !(unsigned int)lim_populate_matching_rate_set(
                        a1,
                        v105,
                        (unsigned __int64)(a5 + 22),
                        (_BYTE *)a5 + 57,
                        (_BYTE *)a5 + 3164,
                        a2,
                        v106,
                        (__int64)(a5 + 1686)) )
  {
    if ( *((_BYTE *)a5 + 3312) )
    {
      v228 = ((*((unsigned __int8 *)a5 + 3313) >> 4) & 7) + 1;
    }
    else if ( (~*(unsigned __int16 *)(v105 + 310) & 0xC) != 0 )
    {
      LOBYTE(v228) = 2;
    }
    else
    {
      LOBYTE(v228) = 1;
    }
    *(_BYTE *)(v105 + 352) = v228;
    v253 = *(_WORD *)v105;
    *(_WORD *)v105 &= 0xFF7Du;
    v254 = (v367 & 1) == 0;
    if ( (*a5 & 0x200) == 0 )
      v254 = 1;
    if ( v254 )
      v255 = 0;
    else
      v255 = 130;
    v256 = v253 & 0xFE3D;
    v257 = v255 | v253 & 0xFE3D;
    *(_WORD *)v105 = v255 | v256;
    if ( v254 && *((_BYTE *)a5 + 3261) && (*v369 & 2) != 0 )
    {
      v257 = v256 | 0x42;
      *(_WORD *)v105 = v256 | 0x42;
      v258 = *v369;
      if ( *((_BYTE *)a5 + 3220) )
      {
        if ( *(_DWORD *)(a2 + 88) == 1 && !*(_BYTE *)(a2 + 1936) && (a5[1611] & 0xF) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: UAPSD not supported, reply accordingly",
            *(double *)&v216,
            v217,
            v218,
            v219,
            v220,
            v221,
            v222,
            v223,
            "lim_update_sta_ds",
            v360);
          v263 = *(_BYTE *)(v105 + 238) & 0x90;
          v257 = *(_WORD *)v105;
        }
        else
        {
          v259 = *(_BYTE *)(v105 + 238) & 0xF7 | (8 * ((*((unsigned __int8 *)a5 + 3222) >> 3) & 1));
          *(_BYTE *)(v105 + 238) = v259;
          v260 = v259 & 0xFFFFFFFB | (4 * ((*((unsigned __int8 *)a5 + 3222) >> 2) & 1));
          *(_BYTE *)(v105 + 238) = v260;
          v261 = v260 & 0xFFFFFFFE | a5[1611] & 1;
          *(_BYTE *)(v105 + 238) = v261;
          v262 = v261 & 0xFFFFFFFD | (2 * ((*((unsigned __int8 *)a5 + 3222) >> 1) & 1));
          *(_BYTE *)(v105 + 238) = v262;
          v263 = v262 & 0x9F | a5[1611] & 0x60;
        }
        *(_BYTE *)(v105 + 238) = v263;
      }
      if ( ((*((_BYTE *)a5 + 3264) != 0) & ((unsigned __int8)(v258 & 4) >> 2)) != 0 )
        v257 |= 0x100u;
    }
    v264 = *(_BYTE *)(v105 + 32);
    v265 = v257 & 0xFBFF;
    if ( (v152 & 1) != 0 )
      v266 = 1024;
    else
      v266 = 0;
    v267 = v265 | v266;
    *(_WORD *)v105 = v267;
    *(_BYTE *)(v105 + 32) = v264 & 0xFE | v194 & 1;
    *(_BYTE *)(v105 + 628) = 1;
    if ( *(unsigned __int16 *)(*(_QWORD *)(a1 + 8) + 1044LL) >= 0xAu )
      v268 = *(unsigned __int16 *)(*(_QWORD *)(a1 + 8) + 1044LL);
    else
      v268 = 200;
    if ( (v152 & 1) == 0 )
      goto LABEL_205;
    v269 = *(unsigned __int8 *)(a2 + 8);
    v270 = *((unsigned __int8 *)a5 + 748);
    v383 = 0;
    v384 = 0;
    v382 = 0;
    v271 = *((unsigned __int8 *)a5 + 3267);
    v385 = 0;
    v380 = 0;
    v381 = 0;
    v378 = 0;
    v379 = 0;
    v377 = 0;
    v376 = 0u;
    v374 = 0;
    memset(v375, 0, sizeof(v375));
    v372 = 0;
    v373 = 0;
    v371 = 0;
    if ( (!v271 || (_DWORD)v270)
      && (v272 = dot11f_unpack_ie_rsn(a1, (char *)a5 + 749, v270, &v371, 0), v267 = *(_WORD *)v105, !v272)
      && (*(_WORD *)((_BYTE *)&v376 + 7) & 0x4000) != 0 )
    {
      v323 = v267 | 0x800;
      *(_WORD *)v105 = v323;
      *(_DWORD *)(v105 + 832) = *(_DWORD *)(a2 + 284);
      if ( (v323 & 0x400) != 0 )
        goto LABEL_199;
    }
    else
    {
      v273 = v267 & 0xF7FF;
      *(_WORD *)v105 = v273;
      if ( (v273 & 0x400) != 0 )
      {
LABEL_199:
        if ( (tx_timer_running(v105 + 360) & 1) != 0 )
          tx_timer_deactivate(v105 + 360);
        *(double *)&v216 = tx_timer_delete(v105 + 360);
      }
    }
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, const char *, __int64 (__fastcall *)(), _QWORD, unsigned __int64, _QWORD, _QWORD, long double))tx_timer_create_intern)(
                         a1,
                         v105 + 360,
                         "PMF SA Query timer",
                         lim_pmf_sa_query_timer_handler,
                         v269 | (v362 << 16),
                         (27487791 * (unsigned __int64)(unsigned int)(v268 << 10)) >> 38,
                         0,
                         0,
                         v216) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: could not create PMF SA Query timer",
        v274,
        v275,
        v276,
        v277,
        v278,
        v279,
        v280,
        v281,
        "lim_update_sta_ds");
      v75 = v365;
      v71 = a1;
      v72 = a4;
      v73 = v194;
      v74 = 1;
      v76 = v362;
LABEL_14:
      v77 = 0;
LABEL_15:
      lim_reject_association(v71, v72, v73, v74, v75, v76, v77, 1u, v62, v63, v64, v65, v66, v67, v68, v69, a2);
LABEL_167:
      result = 0;
      goto LABEL_168;
    }
    LODWORD(v360) = *(unsigned __int8 *)(v105 + 343);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Created pmf timer assoc-id:%d sta mac%02x:%02x:%02x:**:**:%02x",
      v274,
      v275,
      v276,
      v277,
      v278,
      v279,
      v280,
      v281,
      "lim_update_sta_ds",
      *(unsigned __int16 *)(v105 + 336),
      *(unsigned __int8 *)(v105 + 338),
      *(unsigned __int8 *)(v105 + 339),
      *(unsigned __int8 *)(v105 + 340),
      v360);
LABEL_205:
    if ( *((_BYTE *)a5 + 3314) )
    {
      lim_set_stads_rtt_cap(v105, a5 + 1658, a1);
    }
    else
    {
      *(_BYTE *)(v105 + 640) = 0;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: ExtCap not present",
        *(double *)&v216,
        v217,
        v218,
        v219,
        v220,
        v221,
        v222,
        v223,
        "lim_update_sta_ds");
    }
    lim_ap_check_6g_compatible_peer(a1, a2);
    v282 = *(_QWORD *)(a2 + 384);
    if ( v282 )
      *(_QWORD *)(v282 + 8LL * *(unsigned __int16 *)(v105 + 336)) = a5;
    *a8 = 1;
    if ( (a17 & 1) != 0 )
      goto LABEL_211;
    if ( v26 )
    {
      v284 = *(_DWORD *)(v105 + 8);
      *(_BYTE *)(v105 + 32) |= 2u;
      if ( (unsigned __int8)v194 == 1 )
      {
        if ( (unsigned int)lim_add_sta(a1, (unsigned __int16 *)v105, 0, a2) )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: UPASD not supported, REASSOC Failed",
            v285,
            v286,
            v287,
            v288,
            v289,
            v290,
            v291,
            v292,
            "lim_update_sta_ctx");
          v301 = *(_DWORD *)(v105 + 12);
          v302 = (unsigned __int8 *)(v105 + 338);
          v303 = *(_WORD *)(v105 + 336);
          v304 = a1;
          v305 = *(_BYTE *)(v105 + 32) & 1;
          v306 = 3;
LABEL_224:
          lim_reject_association(
            v304,
            v302,
            v305,
            1u,
            v301,
            v303,
            1u,
            v306,
            v293,
            v294,
            v295,
            v296,
            v297,
            v298,
            v299,
            v300,
            a2);
          result = 0;
          *(_DWORD *)(v105 + 8) = v284;
          goto LABEL_168;
        }
      }
      else
      {
        *(_DWORD *)(v105 + 8) = 23;
        if ( (unsigned int)lim_del_sta(a1, v105, 1, a2) )
        {
          LODWORD(v360) = *(unsigned __int8 *)(v105 + 343);
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Couldn't DEL STA, assocId: %d sta mac%02x:%02x:%02x:**:**:%02x",
            v315,
            v316,
            v317,
            v318,
            v319,
            v320,
            v321,
            v322,
            "lim_update_sta_ctx",
            *(unsigned __int16 *)(v105 + 336),
            *(unsigned __int8 *)(v105 + 338),
            *(unsigned __int8 *)(v105 + 339),
            *(unsigned __int8 *)(v105 + 340),
            v360);
          v301 = *(_DWORD *)(v105 + 12);
          v302 = (unsigned __int8 *)(v105 + 338);
          v303 = *(_WORD *)(v105 + 336);
          v304 = a1;
          v305 = *(_BYTE *)(v105 + 32) & 1;
          v306 = 1;
          goto LABEL_224;
        }
      }
    }
    else
    {
      *(_BYTE *)(v105 + 32) &= ~2u;
      if ( (unsigned int)lim_add_sta(a1, (unsigned __int16 *)v105, 0, a2) )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: could not Add STA with assocId: %d",
          v307,
          v308,
          v309,
          v310,
          v311,
          v312,
          v313,
          v314,
          "lim_update_sta_ctx",
          *(unsigned __int16 *)(v105 + 336));
        v75 = *(_DWORD *)(v105 + 12);
        v72 = (unsigned __int8 *)(v105 + 338);
        v76 = *(_WORD *)(v105 + 336);
        v71 = a1;
        v74 = 1;
        v73 = *(_BYTE *)(v105 + 32) & 1;
        v77 = 1;
        goto LABEL_15;
      }
    }
LABEL_211:
    if ( *(_DWORD *)(a2 + 88) == 1 )
    {
      v283 = *(unsigned __int8 *)(a2 + 154);
      if ( ((unsigned int)(v283 - 7) < 7 || v283 == 5 || !*(_BYTE *)(a2 + 154))
        && *((_BYTE *)a5 + 3160)
        && *((_BYTE *)a5 + 3261) )
      {
        lim_post_sm_state_update(a1, *(unsigned int *)(v105 + 328), v105 + 338, *(unsigned __int8 *)(a2 + 10));
      }
    }
    result = 1;
    goto LABEL_168;
  }
  if ( a4 )
  {
    v224 = *a4;
    v225 = a4[1];
    v226 = a4[2];
    v227 = a4[5];
  }
  else
  {
    v226 = 0;
    v224 = 0;
    v225 = 0;
    v227 = 0;
  }
  LODWORD(v360) = v227;
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Couldn't update hash entry for aid: %d MacAddr: %02x:%02x:%02x:**:**:%02x",
    *(double *)&v216,
    v217,
    v218,
    v219,
    v220,
    v221,
    v222,
    v223,
    "lim_update_sta_ds",
    v362,
    v224,
    v225,
    v226,
    v360);
  lim_release_peer_idx(a1, v362, a2);
  lim_reject_association(a1, a4, v194, 1u, v365, v362, 0, 1u, v229, v230, v231, v232, v233, v234, v235, v236, a2);
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Delete dph hash entry",
    v237,
    v238,
    v239,
    v240,
    v241,
    v242,
    v243,
    v244,
    "lim_update_sta_ds");
  result = dph_delete_hash_entry(
             v245,
             v246,
             v247,
             v248,
             v249,
             v250,
             v251,
             v252,
             a1,
             a4,
             *(_WORD *)(v105 + 336),
             a2 + 360);
  if ( (_DWORD)result )
  {
    v92 = "%s: error deleting hash entry";
    v93 = "lim_update_sta_ds";
    goto LABEL_166;
  }
LABEL_168:
  _ReadStatusReg(SP_EL0);
  return result;
}
