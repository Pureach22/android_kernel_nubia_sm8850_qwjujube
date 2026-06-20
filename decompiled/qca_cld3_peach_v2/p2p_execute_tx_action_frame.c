__int64 __fastcall p2p_execute_tx_action_frame(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v10; // w8
  unsigned int v11; // w20
  unsigned __int8 *v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int8 *v21; // x21
  int v22; // w23
  unsigned __int8 *v23; // x22
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w4
  unsigned int v33; // w5
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  int v35; // w9
  char v36; // w28
  __int64 v37; // x0
  __int64 v38; // x21
  double updated; // d0
  unsigned int *v40; // x8
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w22
  int v49; // w25
  __int64 v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int v59; // w24
  __int64 v60; // x23
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 comp_private_obj; // x0
  unsigned int *v70; // x8
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  _DWORD *v79; // x24
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  int v88; // w8
  char v89; // w9
  char *v90; // x9
  int v91; // w8
  int v92; // w11
  int v93; // w8
  unsigned int *v94; // x8
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  const char *v103; // x2
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  unsigned int v112; // w0
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  unsigned int v121; // w23
  _BYTE *v122; // x27
  __int64 v123; // x24
  unsigned __int8 pdev_id_from_vdev_id; // w26
  _QWORD *peer; // x23
  unsigned __int16 v126; // w0
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  char v135; // w24
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  char v144; // w8
  const void *v145; // x1
  int v146; // w8
  unsigned __int8 *v147; // x21
  unsigned int v148; // w23
  unsigned __int8 *v149; // x0
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
  int v160; // w8
  __int64 *v161; // x22
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  __int64 (__fastcall *v170)(__int64, unsigned __int8 *); // x8
  __int64 v171; // x0
  __int64 *v172; // x8
  __int64 v173; // x1
  __int64 v174; // x0
  unsigned __int8 v175; // w0
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  unsigned int peer_mic_len; // w0
  double v185; // d0
  double v186; // d1
  double v187; // d2
  double v188; // d3
  double v189; // d4
  double v190; // d5
  double v191; // d6
  double v192; // d7
  __int64 v193; // x0
  __int64 v194; // x25
  __int64 v195; // x5
  __int64 v196; // x6
  __int64 v197; // x7
  int v198; // w8
  unsigned int *v199; // x8
  double next_seq_num; // d0
  __int16 v201; // w0
  __int16 v202; // w24
  double v203; // d1
  double v204; // d2
  double v205; // d3
  double v206; // d4
  double v207; // d5
  double v208; // d6
  double v209; // d7
  unsigned __int8 v210; // w9
  unsigned int v211; // w23
  unsigned int v212; // w27
  __int64 v213; // x24
  void *v214; // x0
  __int64 v215; // x1
  unsigned int v216; // w9
  char *v217; // x8
  __int64 *v218; // x8
  int v219; // w28
  __int64 v220; // x21
  unsigned __int8 *v221; // x24
  __int64 v222; // x23
  unsigned int v223; // w1
  const char *v224; // x2
  double v225; // d0
  double v226; // d1
  double v227; // d2
  double v228; // d3
  double v229; // d4
  double v230; // d5
  double v231; // d6
  double v232; // d7
  __int64 v233; // x20
  unsigned int mgmt_hw_tx_retry_count; // w25
  __int64 v236; // x27
  __int64 v237; // x0
  __int64 v238; // x22
  _QWORD *v239; // x26
  double v240; // d0
  double v241; // d1
  double v242; // d2
  double v243; // d3
  double v244; // d4
  double v245; // d5
  double v246; // d6
  double v247; // d7
  _BYTE *v248; // x2
  __int64 (__fastcall *v249)(); // x23
  __int64 (__fastcall *v250)(); // x24
  double v251; // d0
  double v252; // d1
  double v253; // d2
  double v254; // d3
  double v255; // d4
  double v256; // d5
  double v257; // d6
  double v258; // d7
  double v259; // d0
  double v260; // d1
  double v261; // d2
  double v262; // d3
  double v263; // d4
  double v264; // d5
  double v265; // d6
  double v266; // d7
  unsigned int *v267; // x8
  double v268; // d0
  double v269; // d1
  double v270; // d2
  double v271; // d3
  double v272; // d4
  double v273; // d5
  double v274; // d6
  double v275; // d7
  double v276; // d0
  double v277; // d1
  double v278; // d2
  double v279; // d3
  double v280; // d4
  double v281; // d5
  double v282; // d6
  double v283; // d7
  const char *v284; // x2
  unsigned int *v285; // x8
  double v286; // d0
  double v287; // d1
  double v288; // d2
  double v289; // d3
  double v290; // d4
  double v291; // d5
  double v292; // d6
  double v293; // d7
  __int64 v294; // x20
  double v295; // d0
  double v296; // d1
  double v297; // d2
  double v298; // d3
  double v299; // d4
  double v300; // d5
  double v301; // d6
  double v302; // d7
  const char *v303; // x2
  unsigned int v304; // w1
  unsigned int v305; // w22
  double v306; // d0
  double v307; // d1
  double v308; // d2
  double v309; // d3
  double v310; // d4
  double v311; // d5
  double v312; // d6
  double v313; // d7
  char *v314; // x23
  double v315; // d0
  double v316; // d1
  double v317; // d2
  double v318; // d3
  double v319; // d4
  double v320; // d5
  double v321; // d6
  double v322; // d7
  __int64 v323; // x6
  __int64 v324; // x7
  int v325; // w8
  int v326; // w9
  char v327; // w9
  __int64 v328; // [xsp+0h] [xbp-D0h]
  unsigned __int8 mlo_link_agnostic_flag; // [xsp+10h] [xbp-C0h]
  int v330; // [xsp+18h] [xbp-B8h]
  unsigned __int8 v331; // [xsp+18h] [xbp-B8h]
  __int64 v332; // [xsp+20h] [xbp-B0h] BYREF
  int v333[2]; // [xsp+28h] [xbp-A8h] BYREF
  unsigned __int8 v334[4]; // [xsp+34h] [xbp-9Ch] BYREF
  int v335[2]; // [xsp+38h] [xbp-98h] BYREF
  int v336; // [xsp+40h] [xbp-90h] BYREF
  __int16 v337; // [xsp+44h] [xbp-8Ch]
  _QWORD v338[6]; // [xsp+50h] [xbp-80h] BYREF
  __int64 v339; // [xsp+80h] [xbp-50h] BYREF
  __int64 v340; // [xsp+88h] [xbp-48h]
  __int128 v341; // [xsp+90h] [xbp-40h]
  __int64 v342; // [xsp+A0h] [xbp-30h]
  unsigned __int64 v343; // [xsp+A8h] [xbp-28h]
  __int64 v344; // [xsp+B0h] [xbp-20h]
  __int64 v345; // [xsp+B8h] [xbp-18h]
  __int64 v346; // [xsp+C0h] [xbp-10h]

  v346 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_DWORD *)(a1 + 244);
  v11 = *(_DWORD *)(a1 + 56);
  v332 = 0;
  *(_QWORD *)v333 = 0;
  memset(v338, 0, 43);
  if ( v10 == 5 )
  {
    if ( (int)v11 <= 36 )
    {
      qdf_trace_msg(
        0x4Eu,
        2u,
        "%s: Invalid header len for probe response",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "p2p_get_p2pie_from_probe_rsp");
LABEL_21:
      v36 = 0;
      LODWORD(v21) = 0;
LABEL_23:
      v48 = 0;
      v49 = 0;
LABEL_46:
      v112 = p2p_packet_alloc(v11, v333, &v332);
      if ( v112 )
      {
        v121 = v112;
        qdf_trace_msg(
          0x4Eu,
          2u,
          "%s: Failed to allocate %d bytes for a Probe Request.",
          v113,
          v114,
          v115,
          v116,
          v117,
          v118,
          v119,
          v120,
          "p2p_execute_tx_action_frame",
          v11);
LABEL_122:
        _ReadStatusReg(SP_EL0);
        return v121;
      }
      v122 = *(_BYTE **)(a1 + 48);
      LOWORD(v339) = 0;
      v123 = **(_QWORD **)(a1 + 16);
      v122[1] &= ~0x40u;
      pdev_id_from_vdev_id = wlan_get_pdev_id_from_vdev_id(v123, *(unsigned int *)(a1 + 24), 0xFu);
      peer = wlan_objmgr_get_peer(v123, pdev_id_from_vdev_id, v122 + 4, 0xFu);
      if ( peer )
        goto LABEL_50;
      peer = wlan_objmgr_get_peer(v123, pdev_id_from_vdev_id, v122 + 10, 0xFu);
      if ( peer )
        goto LABEL_50;
      v330 = v49;
      v193 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               v123,
               *(unsigned int *)(a1 + 24),
               15);
      if ( v193 )
      {
        v194 = v193;
        if ( *(_DWORD *)(v193 + 16) == 16 || *(_BYTE *)(a1 + 63) == 1 )
          peer = wlan_objmgr_get_peer(v123, pdev_id_from_vdev_id, (_BYTE *)(v193 + 74), 0xFu);
        else
          peer = nullptr;
        v199 = (unsigned int *)*(unsigned int *)(a1 + 264);
        if ( (_DWORD)v199 == 7 && (p2p_is_sta_vdev_usage_allowed_for_p2p_dev(v123) & 1) != 0 )
        {
          LOWORD(v339) = mlme_get_p2p_device_seq_num(v194, v127, v128, v129, v130, v131, v132, v133, v134);
          next_seq_num = p2p_get_next_seq_num(&v339, a1, v122 + 10);
          v202 = v201;
          mlme_set_p2p_device_seq_num(v194, v339, next_seq_num, v203, v204, v205, v206, v207, v208, v209);
        }
        else
        {
          v202 = 4096;
        }
        wlan_objmgr_vdev_release_ref(v194, 0xFu, v199, v127, v128, v129, v130, v131, v132, v133, v134);
        v126 = v202;
      }
      else
      {
        peer = nullptr;
        v126 = 4096;
      }
      v49 = v330;
      if ( !peer && v126 == 4096 )
      {
        qdf_trace_msg(
          0x4Eu,
          2u,
          "%s: no valid peer",
          v127,
          v128,
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          "p2p_populate_mac_header");
        goto LABEL_53;
      }
      if ( peer )
      {
LABEL_50:
        v127 = p2p_get_next_seq_num((char *)peer + 84, a1, v122 + 10);
        v135 = 0;
      }
      else
      {
        v135 = 1;
      }
      *(_WORD *)(*(_QWORD *)(a1 + 48) + 22LL) = *(_WORD *)(*(_QWORD *)(a1 + 48) + 22LL) & 0xF | (16 * v126);
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: seq num: %d",
        v127,
        v128,
        v129,
        v130,
        v131,
        v132,
        v133,
        v134,
        "p2p_populate_mac_header",
        v126);
      if ( (v135 & 1) == 0 )
        wlan_objmgr_peer_release_ref((__int64)peer, 0xFu, v136, v137, v138, v139, v140, v141, v142, v143);
LABEL_53:
      v144 = v36 ^ 1;
      if ( v48 - 1 > 0x23 )
        v144 = 1;
      if ( (v144 & 1) != 0 )
      {
        v147 = *(unsigned __int8 **)v333;
        v151 = *(const void **)(a1 + 48);
        v150 = v11;
        v149 = *(unsigned __int8 **)v333;
      }
      else
      {
        v145 = *(const void **)(a1 + 48);
        v146 = (_DWORD)v21 + v49;
        v147 = *(unsigned __int8 **)v333;
        v148 = v146 - (_DWORD)v145 + 2;
        qdf_mem_copy(*(void **)v333, v145, v148);
        qdf_mem_copy(&v147[v148], v338, v48);
        v149 = &v147[v148 + v48];
        v150 = v11 - v48 - v148;
        v151 = (const void *)(*(_QWORD *)(a1 + 48) + v148);
      }
      qdf_mem_copy(v149, v151, v150);
      v160 = *(_DWORD *)(a1 + 244);
      v339 = 0;
      if ( v160 == 13 )
      {
        v161 = *(__int64 **)(a1 + 16);
        if ( v161[23] )
        {
          if ( v11 < 0x1A )
          {
            v121 = 4;
LABEL_62:
            qdf_trace_msg(
              0x4Eu,
              2u,
              "%s: failed to populate rmf frame",
              v152,
              v153,
              v154,
              v155,
              v156,
              v157,
              v158,
              v159,
              "p2p_execute_tx_action_frame");
LABEL_120:
            if ( v332 )
              _qdf_nbuf_free(v332);
            goto LABEL_122;
          }
          if ( wlan_mgmt_is_rmf_mgmt_action_frame(v147[24] & 0x7F) )
          {
            v170 = (__int64 (__fastcall *)(__int64, unsigned __int8 *))v161[23];
            v171 = *(unsigned int *)(a1 + 24);
            if ( *((_DWORD *)v170 - 1) != 889470765 )
              __break(0x8228u);
            if ( (v170(v171, v147 + 4) & 1) != 0 )
            {
              if ( (v147[4] & 1) == 0 )
              {
                v337 = -1;
                v336 = -1;
                if ( (qdf_is_macaddr_equal(v147 + 4, &v336) & 1) == 0 )
                {
                  v172 = *(__int64 **)(a1 + 16);
                  v173 = *(unsigned int *)(a1 + 24);
                  LOBYTE(v336) = 0;
                  v174 = *v172;
                  v334[0] = 0;
                  v175 = wlan_get_pdev_id_from_vdev_id(v174, v173, 0xFu);
                  peer_mic_len = mlme_get_peer_mic_len(
                                   *v161,
                                   v175,
                                   v147 + 4,
                                   &v336,
                                   v334,
                                   v176,
                                   v177,
                                   v178,
                                   v179,
                                   v180,
                                   v181,
                                   v182,
                                   v183);
                  if ( peer_mic_len )
                  {
                    v121 = peer_mic_len;
                    qdf_trace_msg(
                      0x4Eu,
                      2u,
                      "%s: Failed to get peer mic length.",
                      v185,
                      v186,
                      v187,
                      v188,
                      v189,
                      v190,
                      v191,
                      v192,
                      "p2p_populate_rmf_field");
                    goto LABEL_62;
                  }
                  *(_QWORD *)v335 = 0;
                  v305 = v11 + v334[0] + (unsigned __int8)v336;
                  if ( (unsigned int)p2p_packet_alloc(v305, v335, &v339) )
                  {
                    v121 = 2;
                    qdf_trace_msg(
                      0x4Eu,
                      2u,
                      "%s: Failed to allocate %d bytes for rmf frame.",
                      v306,
                      v307,
                      v308,
                      v309,
                      v310,
                      v311,
                      v312,
                      v313,
                      "p2p_populate_rmf_field",
                      v305);
                    goto LABEL_62;
                  }
                  v314 = *(char **)v335;
                  qdf_mem_copy(*(void **)v335, v147, 0x18u);
                  qdf_mem_copy(&v314[v334[0] + 24], v147 + 24, v11 - 24);
                  *((_BYTE *)&off_0 + (_QWORD)v314 + 1) |= 0x40u;
                  if ( v147 == (unsigned __int8 *)-4LL )
                  {
                    v325 = 0;
                    v323 = 0;
                    v324 = 0;
                    v326 = 0;
                  }
                  else
                  {
                    v323 = v147[4];
                    v324 = v147[5];
                    v325 = v147[6];
                    v326 = v147[9];
                  }
                  LODWORD(v328) = v325;
                  qdf_trace_msg(
                    0x4Eu,
                    8u,
                    "%s: set protection 0x%x cat %d %02x:%02x:%02x:**:**:%02x",
                    v315,
                    v316,
                    v317,
                    v318,
                    v319,
                    v320,
                    v321,
                    v322,
                    "p2p_populate_rmf_field",
                    *(unsigned int *)(a1 + 244),
                    v147[24],
                    v323,
                    v324,
                    v328,
                    v326);
                  if ( v332 )
                    _qdf_nbuf_free(v332);
                  LOWORD(v11) = v305;
                  v327 = *(_BYTE *)(v339 + 60);
                  v332 = v339;
                  *(_QWORD *)v333 = v314;
                  *(_BYTE *)(v339 + 60) = v327 | 1;
                }
              }
            }
            else
            {
              if ( v147 == (unsigned __int8 *)-4LL )
              {
                v197 = 0;
                v195 = 0;
                v196 = 0;
                v198 = 0;
              }
              else
              {
                v195 = v147[4];
                v196 = v147[5];
                v197 = v147[6];
                v198 = v147[9];
              }
              LODWORD(v328) = v198;
              qdf_trace_msg(
                0x4Eu,
                8u,
                "%s: non rmf connection vdev %d %02x:%02x:%02x:**:**:%02x",
                v152,
                v153,
                v154,
                v155,
                v156,
                v157,
                v158,
                v159,
                "p2p_populate_rmf_field",
                *(unsigned int *)(a1 + 24),
                v195,
                v196,
                v197,
                v328);
            }
          }
          else
          {
            qdf_trace_msg(
              0x4Eu,
              8u,
              "%s: non rmf act frame 0x%x category %x",
              v162,
              v163,
              v164,
              v165,
              v166,
              v167,
              v168,
              v169,
              "p2p_populate_rmf_field",
              *(unsigned int *)(a1 + 244),
              v147[24]);
          }
        }
      }
      v218 = *(__int64 **)(a1 + 16);
      v344 = 0;
      v345 = 0;
      v219 = *(_DWORD *)(a1 + 44);
      v342 = 0;
      v343 = 0;
      v220 = v332;
      v221 = *(unsigned __int8 **)v333;
      v341 = 0u;
      v340 = 0;
      v222 = *v218;
      LODWORD(v218) = *(_DWORD *)(a1 + 24);
      v339 = v332;
      LOWORD(v340) = v11;
      BYTE2(v340) = (_BYTE)v218;
      *(_QWORD *)&v341 = *(_QWORD *)v333;
      WORD2(v340) = v219;
      if ( !v222 || (v342 = *(_QWORD *)(v222 + 2120)) == 0 )
      {
        v224 = "%s: qdf ctx is null";
        goto LABEL_116;
      }
      if ( !*(_DWORD *)(a1 + 240) && *(_DWORD *)(a1 + 244) == 13 )
      {
        v223 = *(_DWORD *)(a1 + 248);
        switch ( v223 )
        {
          case 0u:
LABEL_152:
            mgmt_hw_tx_retry_count = (unsigned __int8)wlan_mlme_get_mgmt_hw_tx_retry_count(v222, v223);
            goto LABEL_124;
          case 7u:
            v223 = 2;
            goto LABEL_152;
          case 3u:
            v223 = 1;
            goto LABEL_152;
        }
      }
      mgmt_hw_tx_retry_count = 0;
LABEL_124:
      v236 = (mgmt_hw_tx_retry_count >> 4) & 7;
      v343 = (mgmt_hw_tx_retry_count << 28) | (unsigned __int64)(v236 << 55);
      if ( (unsigned int)v236 | mgmt_hw_tx_retry_count & 0xF )
        LOBYTE(v344) = 1;
      v331 = wlan_get_pdev_id_from_vdev_id(v222, *(unsigned int *)(a1 + 24), 0xFu);
      v237 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               v222,
               *(unsigned int *)(a1 + 24),
               15);
      if ( v237 )
      {
        v238 = v237;
        mlo_link_agnostic_flag = wlan_get_mlo_link_agnostic_flag(
                                   v237,
                                   v221 + 4,
                                   v152,
                                   v153,
                                   v154,
                                   v155,
                                   v156,
                                   v157,
                                   v158,
                                   v159);
        v239 = wlan_objmgr_get_peer(v222, v331, v221 + 4, 0xFu);
        if ( v239
          || (v239 = wlan_objmgr_get_peer(v222, v331, v221 + 10, 0xFu)) != nullptr
          || (*(_DWORD *)(v238 + 16) == 16 || *(_BYTE *)(a1 + 63) == 1)
          && (!(*(_DWORD *)(v238 + 80) | *(unsigned __int16 *)(v238 + 84))
            ? (v248 = (_BYTE *)(v238 + 74))
            : (v248 = (_BYTE *)(v238 + 80)),
              (v239 = wlan_objmgr_get_peer(v222, v331, v248, 0xFu)) != nullptr) )
        {
          if ( *(_BYTE *)(a1 + 62) )
            v249 = tgt_p2p_mgmt_download_comp_cb;
          else
            v249 = nullptr;
          if ( *(_BYTE *)(a1 + 62) )
            v250 = nullptr;
          else
            v250 = tgt_p2p_mgmt_ota_comp_cb;
          LODWORD(v328) = (mgmt_hw_tx_retry_count >> 4) & 7;
          qdf_trace_msg(
            0x4Eu,
            8u,
            "%s: length:%d, chanfreq:%d retry count:%d(%d, %d)",
            v240,
            v241,
            v242,
            v243,
            v244,
            v245,
            v246,
            v247,
            "p2p_mgmt_tx",
            (unsigned __int16)v11,
            (unsigned __int16)v219,
            mgmt_hw_tx_retry_count & 0x7F,
            mgmt_hw_tx_retry_count & 0xF,
            v328);
          *(_QWORD *)(a1 + 256) = v220;
          if ( (mlo_is_mld_sta(v238) & 1) != 0
            && !*(_DWORD *)(a1 + 240)
            && ((*(_DWORD *)(a1 + 244) == 13) & mlo_link_agnostic_flag) == 1 )
          {
            BYTE1(v345) = 1;
          }
          v121 = wlan_mgmt_txrx_mgmt_frame_tx(
                   (__int64)v239,
                   *(_QWORD *)(a1 + 16),
                   v220,
                   (__int64)v249,
                   (__int64)v250,
                   v251,
                   v252,
                   v253,
                   v254,
                   v255,
                   v256,
                   v257,
                   v258,
                   5,
                   (__int64)&v339);
          wlan_objmgr_peer_release_ref((__int64)v239, 0xFu, v259, v260, v261, v262, v263, v264, v265, v266);
          wlan_objmgr_vdev_release_ref(v238, 0xFu, v267, v268, v269, v270, v271, v272, v273, v274, v275);
          if ( !v121 )
          {
            if ( *(_BYTE *)(a1 + 62) == 1 )
            {
              p2p_send_tx_conf(a1, 1);
              p2p_remove_tx_context(a1);
LABEL_166:
              v121 = 0;
              goto LABEL_122;
            }
            if ( (unsigned int)qdf_mc_timer_init(a1 + 72, 0, (__int64)p2p_tx_timeout, *(_QWORD *)(a1 + 16)) )
            {
              v284 = "%s: failed to init tx timer tx_ctx:%pK";
            }
            else
            {
              if ( !(unsigned int)qdf_mc_timer_start(a1 + 72, 0x7D0u) )
              {
LABEL_157:
                v294 = *(_QWORD *)(a1 + 16);
                LOBYTE(v339) = 0;
                LOBYTE(v335[0]) = 0;
                if ( !p2p_find_tx_ctx(v294, a1, &v339, v335) )
                  goto LABEL_163;
                if ( (unsigned __int8)v339 == 1 )
                {
                  qdf_trace_msg(
                    0x4Eu,
                    8u,
                    "%s: find in wait for roc queue",
                    v295,
                    v296,
                    v297,
                    v298,
                    v299,
                    v300,
                    v301,
                    v302,
                    "p2p_move_tx_context_to_ack_queue");
                  if ( (unsigned int)qdf_list_remove_node(v294 + 32, (_QWORD *)a1) )
                    qdf_trace_msg(
                      0x4Eu,
                      2u,
                      "%s: Failed to remove off chan tx context from wait roc req queue",
                      v295,
                      v296,
                      v297,
                      v298,
                      v299,
                      v300,
                      v301,
                      v302,
                      "p2p_move_tx_context_to_ack_queue");
                }
                if ( LOBYTE(v335[0]) == 1 )
                {
                  v303 = "%s: Already in waiting for ack queue";
                  v304 = 8;
                }
                else
                {
LABEL_163:
                  if ( !(unsigned int)qdf_list_insert_back((_QWORD *)(v294 + 56), (_QWORD *)a1) )
                    goto LABEL_166;
                  v303 = "%s: Failed to insert off chan tx context to wait ack req queue";
                  v304 = 2;
                }
                qdf_trace_msg(
                  0x4Eu,
                  v304,
                  v303,
                  v295,
                  v296,
                  v297,
                  v298,
                  v299,
                  v300,
                  v301,
                  v302,
                  "p2p_move_tx_context_to_ack_queue");
                goto LABEL_166;
              }
              v284 = "%s: tx timer start failed tx_ctx:%pK";
            }
            qdf_trace_msg(0x4Eu, 2u, v284, v276, v277, v278, v279, v280, v281, v282, v283, "p2p_enable_tx_timer", a1);
            goto LABEL_157;
          }
LABEL_118:
          v233 = jiffies;
          if ( p2p_execute_tx_action_frame___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x4Eu,
              2u,
              "%s: failed to tx mgmt frame",
              v225,
              v226,
              v227,
              v228,
              v229,
              v230,
              v231,
              v232,
              "p2p_execute_tx_action_frame");
            p2p_execute_tx_action_frame___last_ticks = v233;
          }
          goto LABEL_120;
        }
        qdf_trace_msg(0x4Eu, 2u, "%s: no valid peer", v240, v241, v242, v243, v244, v245, v246, v247, "p2p_mgmt_tx");
        wlan_objmgr_vdev_release_ref(v238, 0xFu, v285, v286, v287, v288, v289, v290, v291, v292, v293);
LABEL_117:
        v121 = 4;
        goto LABEL_118;
      }
      v224 = "%s: VDEV null";
LABEL_116:
      qdf_trace_msg(0x4Eu, 2u, v224, v152, v153, v154, v155, v156, v157, v158, v159, "p2p_mgmt_tx");
      goto LABEL_117;
    }
    vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(
                               &unk_969516,
                               4u,
                               (unsigned __int8 *)(*(_QWORD *)(a1 + 48) + 36LL),
                               (unsigned __int16)v11 - 36);
    while ( 1 )
    {
      v21 = vendor_ie_ptr_from_oui;
      if ( !vendor_ie_ptr_from_oui )
        goto LABEL_22;
      if ( vendor_ie_ptr_from_oui[1] == 255 )
      {
        v35 = *(_DWORD *)(a1 + 56);
        if ( (unsigned __int16)(*(_WORD *)(a1 + 48) - (_WORD)vendor_ie_ptr_from_oui + v35) >= 3uLL )
        {
          vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(
                                     &unk_969516,
                                     4u,
                                     vendor_ie_ptr_from_oui + 257,
                                     *(_WORD *)(a1 + 48) - (unsigned __int16)vendor_ie_ptr_from_oui + v35);
          if ( vendor_ie_ptr_from_oui )
            continue;
        }
      }
      goto LABEL_26;
    }
  }
  if ( *(_DWORD *)(a1 + 252) != 2 )
  {
    LODWORD(v21) = 0;
    v36 = 0;
    if ( v10 != 13 || *(_DWORD *)(a1 + 240) )
    {
      v48 = 0;
      v49 = 0;
      goto LABEL_46;
    }
    v37 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            **(_QWORD **)(a1 + 16),
            *(unsigned int *)(a1 + 24),
            15);
    if ( v37 )
    {
      v38 = v37;
      updated = wlan_mlo_update_action_frame_from_user(v37, *(_QWORD *)(a1 + 48), *(unsigned int *)(a1 + 56));
      wlan_objmgr_vdev_release_ref(v38, 0xFu, v40, updated, v41, v42, v43, v44, v45, v46, v47);
    }
    goto LABEL_21;
  }
  v12 = wlan_get_vendor_ie_ptr_from_oui(
          &unk_969516,
          4u,
          (unsigned __int8 *)(*(_QWORD *)(a1 + 48) + 30LL),
          (unsigned __int8)(v11 - 30));
  v21 = v12;
  if ( !v12 )
  {
LABEL_22:
    v36 = 0;
    goto LABEL_23;
  }
  v22 = v12[1];
  v23 = v12 + 6;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: pies:%pK, length:%d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "p2p_get_presence_noa_attr",
    v12 + 6,
    v12[1]);
  if ( (unsigned int)v22 >= 3 )
  {
    while ( 1 )
    {
      v32 = *(unsigned __int16 *)(v23 + 1);
      v33 = v22 - 3;
      v22 = v22 - 3 - v32;
      if ( v33 < v32 )
        break;
      if ( *v23 == 12 )
        goto LABEL_27;
      v23 += v32 + 3;
      if ( v22 <= 2 )
        goto LABEL_26;
    }
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: ****Invalid IEs, elem_len=%d left=%d*****",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "p2p_get_presence_noa_attr");
  }
LABEL_26:
  v23 = nullptr;
LABEL_27:
  if ( *(_DWORD *)(a1 + 244) == 14 )
  {
    v48 = 0;
    v49 = 0;
LABEL_45:
    v36 = 1;
    goto LABEL_46;
  }
  v49 = v21[1];
  v50 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          **(_QWORD **)(a1 + 16),
          *(unsigned int *)(a1 + 24),
          15);
  if ( !v50 )
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: vdev obj is NULL", v51, v52, v53, v54, v55, v56, v57, v58, "p2p_get_vdev_noa_info");
LABEL_42:
    v103 = "%s: not valid noa information";
LABEL_43:
    qdf_trace_msg(0x4Eu, 8u, v103, v80, v81, v82, v83, v84, v85, v86, v87, "p2p_get_noa_attr_stream");
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: do not find out noa attr",
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      "p2p_update_noa_stream");
    LOBYTE(v48) = 0;
LABEL_44:
    v48 = (unsigned __int8)v48;
    v11 += (unsigned __int8)v48;
    goto LABEL_45;
  }
  v59 = *(_DWORD *)(v50 + 16);
  v60 = v50;
  qdf_trace_msg(0x4Eu, 8u, "%s: vdev mode:%d", v51, v52, v53, v54, v55, v56, v57, v58, "p2p_get_vdev_noa_info", v59);
  if ( v59 != 3 )
  {
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: invalid p2p vdev mode:%d",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "p2p_get_vdev_noa_info",
      v59);
LABEL_41:
    wlan_objmgr_vdev_release_ref(v60, 0xFu, v94, v95, v96, v97, v98, v99, v100, v101, v102);
    goto LABEL_42;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v60, 5u);
  if ( !comp_private_obj || (v79 = *(_DWORD **)(comp_private_obj + 8)) == nullptr )
  {
    qdf_trace_msg(0x4Eu, 8u, "%s: null noa info", v71, v72, v73, v74, v75, v76, v77, v78, "p2p_get_vdev_noa_info");
    goto LABEL_41;
  }
  wlan_objmgr_vdev_release_ref(v60, 0xFu, v70, v71, v72, v73, v74, v75, v76, v77, v78);
  v88 = v79[6];
  if ( !v88 && !v79[10] && !v79[1] )
  {
    v103 = "%s: opps ps and duration are 0";
    goto LABEL_43;
  }
  LOBYTE(v338[0]) = 12;
  v89 = v79[2] | ((unsigned __int8)v79[1] << 7);
  BYTE3(v338[0]) = *v79;
  BYTE4(v338[0]) = v89;
  if ( v88 )
  {
    *(_DWORD *)((char *)v338 + 6) = v88;
    v90 = (char *)&v338[2] + 2;
    v91 = v79[7];
    v92 = v79[8];
    BYTE5(v338[0]) = v79[5];
    *(_DWORD *)((char *)&v338[1] + 2) = v91;
    v93 = 18;
    *(_DWORD *)((char *)&v338[1] + 6) = v92;
  }
  else
  {
    v93 = 5;
    v90 = (char *)v338 + 5;
  }
  if ( v79[10] )
  {
    v93 += 13;
    *v90 = v79[9];
    *(_DWORD *)(v90 + 1) = v79[10];
    *(_DWORD *)(v90 + 5) = v79[11];
    *(_DWORD *)(v90 + 9) = v79[12];
  }
  *(_WORD *)((char *)v338 + 1) = v93 - 3;
  v210 = v21[1];
  if ( v23 )
  {
    v48 = *(unsigned __int16 *)(v23 + 1);
    v210 -= v48 + 3;
    v11 -= v48 + 3;
    v21[1] = v210;
  }
  else
  {
    v48 = v93;
  }
  v211 = v210;
  v212 = v48 + v210;
  if ( v212 < 0x100 )
    goto LABEL_104;
  v213 = (unsigned __int8)(v48 + v210 + 1);
  *(_QWORD *)((char *)&v341 + 7) = 0;
  v340 = 0;
  *(_QWORD *)&v341 = 0;
  v339 = 0;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: noa_stream:%pK, noa_len:%d, overflow_len:%d",
    v80,
    v81,
    v82,
    v83,
    v84,
    v85,
    v86,
    v87,
    "p2p_get_noa_attr_stream_in_mult_p2p_ies",
    v338,
    (unsigned __int8)v48,
    v213);
  if ( (unsigned __int8)v48 > 0x25u || (unsigned int)v213 > (unsigned __int8)v48 || (unsigned int)v213 > 0x1F )
  {
LABEL_103:
    LOBYTE(v212) = -1;
    v48 = (unsigned __int8)(v48 + 6);
LABEL_104:
    v21[1] = v212;
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: noa_len=%d orig_len=%d p2p_ie=%pK buf_len=%d nbytes copy=%d ",
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      "p2p_update_noa_stream",
      v48,
      v211,
      v21,
      v11,
      (_DWORD)v21 + v211 - *(_DWORD *)(a1 + 48) + 2);
    goto LABEL_44;
  }
  v214 = qdf_mem_copy(&v339, (char *)v338 + (v48 & 0x3F) - v213, (unsigned __int8)(v212 + 1));
  v216 = (unsigned __int8)v48 - (_DWORD)v213;
  if ( v216 <= 0x2A )
  {
    v217 = (char *)v338 + v216;
    *v217 = -35;
    if ( v216 != 42 )
    {
      v217[1] = v212 + 5;
      qdf_mem_copy((char *)v338 + (v48 & 0x3F) - v213 + 2, &unk_969516, 4u);
      qdf_mem_copy((char *)v338 + (v48 & 0x3F) - v213 + 6, &v339, (unsigned __int8)(v212 + 1));
      goto LABEL_103;
    }
  }
  __break(1u);
  return p2p_send_tx_conf(v214, v215);
}
