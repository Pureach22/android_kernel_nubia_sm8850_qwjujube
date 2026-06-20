__int64 __fastcall wma_add_sta(
        _QWORD *a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w20
  __int64 htc_hdl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 *v22; // x21
  __int64 v23; // x5
  __int64 v24; // x6
  __int64 v25; // x7
  int v26; // w8
  __int64 result; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x8
  __int64 v37; // x10
  _BOOL4 v38; // w9
  int v39; // w10
  bool v41; // w10
  int v42; // w26
  int v43; // w8
  _QWORD *v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  int v53; // w4
  _QWORD *v54; // x23
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 *v63; // x25
  int v64; // w8
  int v65; // w9
  int v66; // w10
  _BOOL4 v67; // w22
  _QWORD *context; // x0
  __int64 v69; // x25
  __int64 v70; // x23
  __int64 v71; // x8
  __int64 (*v72)(void); // x8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x27
  int v82; // w24
  __int64 v83; // x8
  _DWORD *v84; // x8
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  int peer; // w0
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  int v102; // w24
  int v103; // w8
  char v104; // w25
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  unsigned __int8 v121; // w1
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  __int64 v138; // x8
  void (*v139)(void); // x8
  __int64 v140; // x8
  __int64 (__fastcall *v141)(__int64, __int64, unsigned __int8 *); // x8
  __int64 v142; // x1
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  unsigned int v151; // w24
  char v152; // w24
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  double v161; // d0
  double v162; // d1
  double v163; // d2
  double v164; // d3
  double v165; // d4
  double v166; // d5
  double v167; // d6
  double v168; // d7
  double v169; // d0
  double v170; // d1
  double v171; // d2
  double v172; // d3
  double v173; // d4
  double v174; // d5
  double v175; // d6
  double v176; // d7
  unsigned __int8 v177; // w1
  __int64 v178; // x0
  unsigned int v179; // w2
  __int64 v180; // x4
  __int64 v181; // x5
  __int64 v182; // x6
  __int64 v183; // x7
  int v184; // w8
  int v185; // w9
  int v186; // w10
  int v187; // w11
  const char *v188; // x3
  __int64 v189; // x8
  _DWORD *v190; // x8
  __int64 v191; // x1
  unsigned int v192; // w2
  double v193; // d0
  double v194; // d1
  double v195; // d2
  double v196; // d3
  double v197; // d4
  double v198; // d5
  double v199; // d6
  double v200; // d7
  __int64 v201; // x8
  _DWORD *v202; // x8
  __int64 v203; // x2
  int v204; // w0
  double v205; // d0
  double v206; // d1
  double v207; // d2
  double v208; // d3
  double v209; // d4
  double v210; // d5
  double v211; // d6
  double v212; // d7
  int v213; // w25
  __int64 v214; // x23
  char is_vdev_up; // w0
  double v216; // d0
  double v217; // d1
  double v218; // d2
  double v219; // d3
  double v220; // d4
  double v221; // d5
  double v222; // d6
  double v223; // d7
  __int64 v224; // x4
  __int64 v225; // x5
  __int64 v226; // x6
  __int64 v227; // x7
  int v228; // w8
  unsigned int v229; // w8
  __int64 v230; // x9
  __int64 v231; // x8
  double v232; // d0
  double v233; // d1
  double v234; // d2
  double v235; // d3
  double v236; // d4
  double v237; // d5
  double v238; // d6
  double v239; // d7
  double v240; // d0
  double v241; // d1
  double v242; // d2
  double v243; // d3
  double v244; // d4
  double v245; // d5
  double v246; // d6
  double v247; // d7
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
  __int64 *v265; // x0
  double v266; // d0
  double v267; // d1
  double v268; // d2
  double v269; // d3
  double v270; // d4
  double v271; // d5
  double v272; // d6
  double v273; // d7
  double v274; // d0
  double v275; // d1
  double v276; // d2
  double v277; // d3
  double v278; // d4
  double v279; // d5
  double v280; // d6
  double v281; // d7
  double v282; // d0
  double v283; // d1
  double v284; // d2
  double v285; // d3
  double v286; // d4
  double v287; // d5
  double v288; // d6
  double v289; // d7
  double v291; // d0
  double v292; // d1
  double v293; // d2
  double v294; // d3
  double v295; // d4
  double v296; // d5
  double v297; // d6
  double v298; // d7
  double v299; // d0
  double v300; // d1
  double v301; // d2
  double v302; // d3
  double v303; // d4
  double v304; // d5
  double v305; // d6
  double v306; // d7
  double v307; // d0
  double v308; // d1
  double v309; // d2
  double v310; // d3
  double v311; // d4
  double v312; // d5
  double v313; // d6
  double v314; // d7
  _DWORD *v315; // x0
  _DWORD *v316; // x25
  __int64 v317; // x8
  _DWORD *v318; // x8
  __int64 v319; // x4
  __int64 v320; // x5
  __int64 v321; // x6
  __int64 v322; // x7
  char v323; // w23
  char v324; // w6
  double v325; // d0
  double v326; // d1
  double v327; // d2
  double v328; // d3
  double v329; // d4
  double v330; // d5
  double v331; // d6
  double v332; // d7
  double v333; // d0
  double v334; // d1
  double v335; // d2
  double v336; // d3
  double v337; // d4
  double v338; // d5
  double v339; // d6
  double v340; // d7
  __int64 v341; // x1
  double v342; // d0
  double v343; // d1
  double v344; // d2
  double v345; // d3
  double v346; // d4
  double v347; // d5
  double v348; // d6
  double v349; // d7
  unsigned int v350; // w0
  unsigned int v351; // w24
  unsigned int v352; // w24
  const char *v353; // x2
  unsigned int v354; // w1
  double v355; // d0
  double v356; // d1
  double v357; // d2
  double v358; // d3
  double v359; // d4
  double v360; // d5
  double v361; // d6
  double v362; // d7
  int v363; // w8
  __int64 v364; // x0
  __int64 v365; // x1
  int v366; // w9
  int v367; // w8
  int v368; // w8
  __int64 v369; // x0
  double v370; // d0
  double v371; // d1
  double v372; // d2
  double v373; // d3
  double v374; // d4
  double v375; // d5
  double v376; // d6
  double v377; // d7
  __int64 v378; // x25
  __int64 v379; // x3
  unsigned __int16 *v380; // x27
  __int64 v381; // x6
  __int64 v382; // x7
  int v383; // w8
  int v384; // w9
  unsigned int v385; // w11
  unsigned int v386; // w10
  unsigned int v387; // w8
  unsigned __int8 *v388; // x12
  bool v389; // cc
  unsigned __int64 v390; // x15
  int v391; // w16
  unsigned __int8 v392; // w17
  unsigned __int8 v393; // w0
  unsigned __int8 v394; // w16
  int moddtim_user; // w0
  unsigned int *v396; // x8
  double v397; // d0
  double v398; // d1
  double v399; // d2
  double v400; // d3
  double v401; // d4
  double v402; // d5
  double v403; // d6
  double v404; // d7
  __int16 v405; // w9
  unsigned int v406; // w2
  double v407; // d0
  double v408; // d1
  double v409; // d2
  double v410; // d3
  double v411; // d4
  double v412; // d5
  double v413; // d6
  double v414; // d7
  double v415; // d0
  double v416; // d1
  double v417; // d2
  double v418; // d3
  double v419; // d4
  double v420; // d5
  double v421; // d6
  double v422; // d7
  unsigned __int8 peer_mlme_nss; // w0
  __int64 v424; // x4
  __int64 v425; // x5
  __int64 v426; // x6
  __int64 v427; // x7
  double v428; // d0
  double v429; // d1
  double v430; // d2
  double v431; // d3
  double v432; // d4
  double v433; // d5
  double v434; // d6
  double v435; // d7
  double v436; // d0
  double v437; // d1
  double v438; // d2
  double v439; // d3
  double v440; // d4
  double v441; // d5
  double v442; // d6
  double v443; // d7
  double v444; // d0
  double v445; // d1
  double v446; // d2
  double v447; // d3
  double v448; // d4
  double v449; // d5
  double v450; // d6
  double v451; // d7
  int v452; // w8
  int v453; // w9
  int v454; // w10
  double v455; // d0
  double v456; // d1
  double v457; // d2
  double v458; // d3
  double v459; // d4
  double v460; // d5
  double v461; // d6
  double v462; // d7
  double v463; // d0
  double v464; // d1
  double v465; // d2
  double v466; // d3
  double v467; // d4
  double v468; // d5
  double v469; // d6
  double v470; // d7
  double v471; // d0
  double v472; // d1
  double v473; // d2
  double v474; // d3
  double v475; // d4
  double v476; // d5
  double v477; // d6
  double v478; // d7
  unsigned __int8 v479; // w1
  double v480; // d0
  double v481; // d1
  double v482; // d2
  double v483; // d3
  double v484; // d4
  double v485; // d5
  double v486; // d6
  double v487; // d7
  double v488; // d0
  double v489; // d1
  double v490; // d2
  double v491; // d3
  double v492; // d4
  double v493; // d5
  double v494; // d6
  double v495; // d7
  unsigned int v501; // w20
  unsigned int v502; // w20
  unsigned int v504; // w21
  unsigned int v505; // w21
  __int64 v506; // [xsp+0h] [xbp-80h]
  __int64 v507; // [xsp+8h] [xbp-78h]
  __int64 v508; // [xsp+10h] [xbp-70h]
  __int64 v509; // [xsp+18h] [xbp-68h]
  __int64 v510; // [xsp+38h] [xbp-48h]
  __int64 v511; // [xsp+40h] [xbp-40h] BYREF
  __int64 v512; // [xsp+48h] [xbp-38h]
  __int64 v513; // [xsp+50h] [xbp-30h]
  __int64 v514; // [xsp+58h] [xbp-28h]
  __int64 v515; // [xsp+60h] [xbp-20h]
  __int64 v516; // [xsp+68h] [xbp-18h]
  __int64 v517; // [xsp+70h] [xbp-10h]
  __int64 v518; // [xsp+78h] [xbp-8h]

  v518 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = a2[131];
  htc_hdl = lmac_get_htc_hdl(a1[3], a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !htc_hdl )
  {
    result = qdf_trace_msg(0x36u, 2u, "%s: HTC handle is NULL", v14, v15, v16, v17, v18, v19, v20, v21, "wma_add_sta");
    goto LABEL_149;
  }
  v22 = (__int64 *)htc_hdl;
  if ( a2 )
  {
    v23 = *a2;
    v24 = a2[1];
    v25 = a2[2];
    v26 = a2[5];
  }
  else
  {
    v25 = 0;
    v23 = 0;
    v24 = 0;
    v26 = 0;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Vdev %d BSSID %02x:%02x:%02x:**:**:%02x",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "wma_add_sta",
    v12,
    v23,
    v24,
    v25,
    v26);
  if ( *((unsigned __int16 *)a1 + 81) <= v12 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid vdev_id %hu",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "wma_is_vdev_in_ap_mode",
      v12);
    v36 = a1[65];
    v38 = 1;
  }
  else
  {
    v36 = a1[65];
    v37 = v36 + 488LL * v12;
    v38 = 1;
    if ( *(_DWORD *)(v37 + 164) == 1 )
    {
      v39 = *(_DWORD *)(v37 + 168);
      v41 = v39 == 3 || v39 == 0;
      v38 = !v41;
    }
  }
  v42 = *(_DWORD *)(v36 + 488LL * v12 + 164);
  if ( v42 == 7 )
    v43 = 3;
  else
    v43 = v38;
  if ( !v43 )
  {
    context = _cds_get_context(71, (__int64)"wma_add_sta_req_ap_mode", v28, v29, v30, v31, v32, v33, v34, v35);
    if ( a2[8] != 1 )
    {
      *((_DWORD *)a2 + 25) = 0;
LABEL_81:
      v180 = a2[8];
      v181 = a2[131];
      v182 = *((unsigned __int16 *)a2 + 3);
      if ( a2 )
      {
        v183 = *a2;
        v184 = a2[1];
        v185 = a2[2];
        v186 = a2[5];
      }
      else
      {
        v185 = 0;
        v183 = 0;
        v184 = 0;
        v186 = 0;
      }
      v187 = *((_DWORD *)a2 + 25);
      v188 = "wma_add_sta_req_ap_mode";
      goto LABEL_118;
    }
    v69 = a1[2];
    v70 = (__int64)context;
    if ( context )
    {
      if ( *context && (v71 = *(_QWORD *)(*context + 72LL)) != 0 )
      {
        v72 = *(__int64 (**)(void))(v71 + 24);
        if ( v72 )
        {
          if ( *((_DWORD *)v72 - 1) != 454466150 )
            __break(0x8228u);
          if ( (v72() & 1) != 0 )
          {
            wma_remove_peer(a1, a2 + 9, a2[131], 0, v45, v46, v47, v48, v49, v50, v51, v52);
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: Peer already exists, Deleted peer with peer_addr %02x:%02x:%02x:**:**:%02x",
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              "wma_add_sta_req_ap_mode",
              a2[9],
              a2[10],
              a2[11],
              a2[14]);
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x45u,
          1u,
          "%s invalid instance",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "cdp_find_peer_exist_on_vdev");
      }
      if ( *(_QWORD *)v70 )
      {
        v83 = *(_QWORD *)(*(_QWORD *)v70 + 72LL);
        if ( v83 )
        {
          v84 = *(_DWORD **)(v83 + 16);
          if ( v84 )
          {
            if ( *(v84 - 1) != 454466150 )
              __break(0x8228u);
            if ( (((__int64 (__fastcall *)(__int64, _QWORD, unsigned __int8 *))v84)(v70, 0, a2 + 9) & 1) != 0 )
            {
              LODWORD(v506) = a2[14];
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: My vdev id %d, but Peer exists on other vdev with peer_addr %02x:%02x:%02x:**:**:%02x",
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                "wma_add_sta_req_ap_mode",
                a2[131],
                a2[9],
                a2[10],
                a2[11],
                v506);
              *((_DWORD *)a2 + 25) = 16;
              goto LABEL_81;
            }
          }
LABEL_48:
          wma_delete_invalid_peer_entries(a2[131], a2 + 9, v45, v46, v47, v48, v49, v50, v51, v52);
          peer = wma_create_peer((__int64)a1, a2 + 9, 0, 0, a2[131], 0, 0, v85, v86, v87, v88, v89, v90, v91, v92);
          if ( peer )
          {
            v102 = peer;
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: Failed to create peer for %02x:%02x:%02x:**:**:%02x",
              v94,
              v95,
              v96,
              v97,
              v98,
              v99,
              v100,
              v101,
              "wma_add_sta_req_ap_mode",
              a2[9],
              a2[10],
              a2[11],
              a2[14]);
            *((_DWORD *)a2 + 25) = v102;
            goto LABEL_81;
          }
          if ( v70 && *(_QWORD *)v70 && (v140 = *(_QWORD *)(*(_QWORD *)v70 + 72LL)) != 0 )
          {
            v141 = *(__int64 (__fastcall **)(__int64, __int64, unsigned __int8 *))(v140 + 24);
            if ( v141 )
            {
              v142 = a2[131];
              if ( *((_DWORD *)v141 - 1) != 454466150 )
                __break(0x8228u);
              if ( (v141(v70, v142, a2 + 9) & 1) != 0 )
              {
                wmi_unified_send_txbf(a1, a2, v94, v95, v96, v97, v98, v99, v100, v101);
                v151 = *(unsigned __int16 *)(*(_QWORD *)(v69 + 8) + 2768LL);
                if ( v151 >= 0x100 )
                {
                  qdf_trace_msg(
                    0x36u,
                    8u,
                    "%s: set mcs_limit %x",
                    v143,
                    v144,
                    v145,
                    v146,
                    v147,
                    v148,
                    v149,
                    v150,
                    "wma_add_sta_req_ap_mode",
                    *(unsigned __int16 *)(*(_QWORD *)(v69 + 8) + 2768LL));
                  v385 = (unsigned __int8)v151 >> 3;
                  v386 = 0;
                  v387 = 0;
                  v388 = a2 + 60;
                  do
                  {
                    if ( v386 < v385 )
                    {
                      v388[v386++] = -1;
                      v387 += 8;
                    }
                    else if ( v386 <= v385 )
                    {
                      v389 = v387 > (unsigned __int8)v151;
                      v390 = (unsigned __int64)v387 >> 3;
                      v391 = 1 << (v387++ & 7);
                      v392 = v388[v390];
                      v393 = v392 & ~(_BYTE)v391;
                      v394 = v392 | v391;
                      if ( v389 )
                        v394 = v393;
                      v388[v390] = v394;
                      if ( v387 >= 8 * (v386 + 1) )
                        ++v386;
                    }
                    else
                    {
                      v388[v386] = 0;
                      v387 += 8;
                      ++v386;
                    }
                  }
                  while ( v387 < 0x80 );
                }
                v152 = wmi_service_enabled(*a1, 0x68u, v143, v144, v145, v146, v147, v148, v149, v150);
                if ( (v152 & 1) != 0 )
                {
                  if ( !wma_fill_hold_req(a1, a2[131], 0x1021u, 1u, nullptr, (__int64)a2, 0xFA0u) )
                  {
                    qdf_trace_msg(
                      0x36u,
                      2u,
                      "%s: Failed to alloc request for vdev_id %d",
                      v161,
                      v162,
                      v163,
                      v164,
                      v165,
                      v166,
                      v167,
                      v168,
                      "wma_add_sta_req_ap_mode",
                      a2[131]);
                    v177 = a2[131];
                    v178 = (__int64)a1;
                    *((_DWORD *)a2 + 25) = 16;
LABEL_223:
                    wma_remove_req(v178, v177, 1u, v169, v170, v171, v172, v173, v174, v175, v176);
                    v179 = a2[131];
                    goto LABEL_80;
                  }
                }
                else
                {
                  qdf_trace_msg(
                    0x36u,
                    2u,
                    "%s: WMI_SERVICE_PEER_ASSOC_CONF not enabled",
                    v153,
                    v154,
                    v155,
                    v156,
                    v157,
                    v158,
                    v159,
                    v160,
                    "wma_add_sta_req_ap_mode");
                }
                if ( !(unsigned int)wma_send_peer_assoc(a1, *((unsigned int *)a2 + 36), a2) )
                {
                  if ( a2[105] )
                    wma_set_peer_pmf_status(a1, a2 + 9);
                  if ( a2[19] && (unsigned int)wma_set_ap_peer_uapsd(a1, a2[131], a2 + 9) )
                  {
                    qdf_trace_msg(
                      0x36u,
                      2u,
                      "%s: Failed to set peer uapsd param for %02x:%02x:%02x:**:**:%02x",
                      v169,
                      v170,
                      v171,
                      v172,
                      v173,
                      v174,
                      v175,
                      v176,
                      "wma_add_sta_req_ap_mode",
                      a2[9],
                      a2[10],
                      a2[11],
                      a2[14]);
                    v406 = a2[131];
                    *((_DWORD *)a2 + 25) = 16;
                    wma_remove_peer(a1, a2 + 9, v406, 0, v407, v408, v409, v410, v411, v412, v413, v414);
                    if ( (v152 & 1) == 0 )
                      goto LABEL_81;
                  }
                  else
                  {
                    LODWORD(v506) = 2;
                    qdf_trace_msg(
                      0x36u,
                      8u,
                      "%s: Moving peer %02x:%02x:%02x:**:**:%02x to state %d",
                      v169,
                      v170,
                      v171,
                      v172,
                      v173,
                      v174,
                      v175,
                      v176,
                      "wma_add_sta_req_ap_mode",
                      a2[9],
                      a2[10],
                      a2[11],
                      a2[14],
                      v506);
                    cdp_peer_state_update(v70, v415, v416, v417, v418, v419, v420, v421, v422);
                    peer_mlme_nss = wma_objmgr_get_peer_mlme_nss(a1, a2 + 9);
                    *((_DWORD *)a2 + 25) = 0;
                    a2[151] = peer_mlme_nss;
                    if ( (v152 & 1) == 0 )
                      goto LABEL_81;
                  }
                  result = qdf_trace_msg(
                             0x36u,
                             8u,
                             "%s: WMI_SERVICE_PEER_ASSOC_CONF is enabled",
                             v45,
                             v46,
                             v47,
                             v48,
                             v49,
                             v50,
                             v51,
                             v52,
                             "wma_add_sta_req_ap_mode");
                  goto LABEL_120;
                }
                v179 = a2[131];
                *((_DWORD *)a2 + 25) = 16;
                if ( (v152 & 1) == 0 )
                  goto LABEL_80;
                v178 = (__int64)a1;
                v177 = v179;
                goto LABEL_223;
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0x45u,
              1u,
              "%s invalid instance",
              v94,
              v95,
              v96,
              v97,
              v98,
              v99,
              v100,
              v101,
              "cdp_find_peer_exist_on_vdev");
          }
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Failed to find peer handle using peer mac %02x:%02x:%02x:**:**:%02x",
            v94,
            v95,
            v96,
            v97,
            v98,
            v99,
            v100,
            v101,
            "wma_add_sta_req_ap_mode",
            a2[9],
            a2[10],
            a2[11],
            a2[14]);
          v179 = a2[131];
          *((_DWORD *)a2 + 25) = 16;
LABEL_80:
          wma_remove_peer(a1, a2 + 9, v179, 0, v169, v170, v171, v172, v173, v174, v175, v176);
          goto LABEL_81;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        1u,
        "%s invalid instance",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "cdp_find_peer_exist_on_vdev");
    }
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v45, v46, v47, v48, v49, v50, v51, v52, "cdp_find_peer_exist");
    goto LABEL_48;
  }
  if ( v43 == 3 )
  {
    result = wma_add_sta_ndi_mode(a1, a2);
    v67 = result == 0;
    goto LABEL_121;
  }
  v44 = _cds_get_context(71, (__int64)"wma_add_sta_req_sta_mode", v28, v29, v30, v31, v32, v33, v34, v35);
  v53 = a2[8];
  v516 = 0;
  v517 = 0;
  v514 = 0;
  v515 = 0;
  v512 = 0;
  v513 = 0;
  v511 = 0;
  if ( v53 != 4 )
  {
    v81 = a1[65] + 488LL * a2[131];
    if ( v53 )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: unsupported station type %d",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "wma_add_sta_req_sta_mode");
LABEL_37:
      v82 = 0;
LABEL_202:
      *(_WORD *)(v81 + 208) = *((_WORD *)a2 + 3);
      v380 = (unsigned __int16 *)(v81 + 208);
LABEL_203:
      *((_DWORD *)a2 + 25) = v82;
      if ( a2 )
      {
        v381 = *a2;
        v382 = a2[1];
        v383 = a2[2];
        v384 = a2[5];
      }
      else
      {
        v383 = 0;
        v381 = 0;
        v382 = 0;
        v384 = 0;
      }
      LODWORD(v506) = v383;
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: vdev_id %d aid %d sta mac %02x:%02x:%02x:**:**:%02x status %d",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "wma_add_sta_req_sta_mode",
        a2[131],
        *v380,
        v381,
        v382,
        v506,
        v384,
        v82);
      result = wlan_cm_is_roam_sync_in_progress(a1[3], a2[131]);
      if ( (result & 1) != 0 )
        goto LABEL_120;
      goto LABEL_119;
    }
    if ( a2[149] )
    {
      if ( v44 && *v44 && (v138 = *(_QWORD *)(*v44 + 72LL)) != 0 )
      {
        v139 = *(void (**)(void))(v138 + 40);
        if ( v139 )
        {
          if ( *((_DWORD *)v139 - 1) != 1499005600 )
            __break(0x8228u);
          v139();
        }
      }
      else
      {
        qdf_trace_msg(0x45u, 1u, "%s invalid instance", v45, v46, v47, v48, v49, v50, v51, v52, "cdp_peer_state_update");
      }
      v82 = 0;
      *(_DWORD *)(v81 + 228) = 1;
      *(_WORD *)(v81 + 208) = *((_WORD *)a2 + 3);
      goto LABEL_202;
    }
    v214 = (__int64)v44;
    is_vdev_up = wma_is_vdev_up(a2[131]);
    v224 = a2[131];
    if ( (is_vdev_up & 1) != 0 )
    {
      if ( a2 )
      {
        v225 = *a2;
        v226 = a2[1];
        v227 = a2[2];
        v228 = a2[5];
      }
      else
      {
        v227 = 0;
        v225 = 0;
        v226 = 0;
        v228 = 0;
      }
      LODWORD(v506) = v228;
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: vdev id %d is already UP for %02x:%02x:%02x:**:**:%02x",
        v216,
        v217,
        v218,
        v219,
        v220,
        v221,
        v222,
        v223,
        "wma_add_sta_req_sta_mode",
        v224,
        v225,
        v226,
        v227,
        v506);
      v82 = 16;
      goto LABEL_202;
    }
    if ( v214 && *(_QWORD *)v214 && (v317 = *(_QWORD *)(*(_QWORD *)v214 + 72LL)) != 0 )
    {
      v318 = *(_DWORD **)(v317 + 80);
      if ( v318 )
      {
        if ( *(v318 - 1) != -223539710 )
          __break(0x8228u);
        if ( ((unsigned int (__fastcall *)(__int64, _QWORD, unsigned __int8 *, __int64))v318)(
               v214,
               (unsigned int)v224,
               a2,
               1) == 1 )
        {
          if ( *((_DWORD *)a2 + 27) )
          {
            if ( a2 )
            {
              v319 = *a2;
              v320 = a2[1];
              v321 = a2[2];
              v322 = a2[5];
            }
            else
            {
              v321 = 0;
              v319 = 0;
              v320 = 0;
              v322 = 0;
            }
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: Update peer(%02x:%02x:%02x:**:**:%02x) state into conn",
              v216,
              v217,
              v218,
              v219,
              v220,
              v221,
              v222,
              v223,
              "wma_add_sta_req_sta_mode",
              v319,
              v320,
              v321,
              v322);
          }
          else
          {
            if ( a2 )
            {
              v424 = *a2;
              v425 = a2[1];
              v426 = a2[2];
              v427 = a2[5];
            }
            else
            {
              v426 = 0;
              v424 = 0;
              v425 = 0;
              v427 = 0;
            }
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: Update peer(%02x:%02x:%02x:**:**:%02x) state into auth",
              v216,
              v217,
              v218,
              v219,
              v220,
              v221,
              v222,
              v223,
              "wma_add_sta_req_sta_mode",
              v424,
              v425,
              v426,
              v427);
          }
          cdp_peer_state_update(v214, v428, v429, v430, v431, v432, v433, v434, v435);
          if ( wlan_cm_is_roam_sync_in_progress(a1[3], a2[131]) )
          {
            cdp_peer_state_update(v214, v436, v437, v438, v439, v440, v441, v442, v443);
            *(_DWORD *)(v81 + 228) = 1;
            *(_WORD *)(v81 + 208) = *((_WORD *)a2 + 3);
            if ( a2 )
            {
              v452 = a2[1];
              v453 = a2[2];
              v454 = a2[5];
            }
            else
            {
              v453 = 0;
              v452 = 0;
              v454 = 0;
            }
            LODWORD(v506) = v452;
            result = qdf_trace_msg(
                       0x36u,
                       8u,
                       "%s: LFR3:statype %d vdev %d aid %d bssid %02x:%02x:%02x:**:**:%02x",
                       v444,
                       v445,
                       v446,
                       v447,
                       v448,
                       v449,
                       v450,
                       v451,
                       "wma_add_sta_req_sta_mode",
                       a2[8],
                       a2[131],
                       v506,
                       v453,
                       v454);
            goto LABEL_120;
          }
          wmi_unified_send_txbf(a1, a2, v436, v437, v438, v439, v440, v441, v442, v443);
          v323 = wmi_service_enabled(*a1, 0x68u, v455, v456, v457, v458, v459, v460, v461, v462);
          if ( (v323 & 1) != 0 )
          {
            if ( !wma_fill_hold_req(a1, a2[131], 0x1021u, 1u, nullptr, (__int64)a2, 0xFA0u) )
            {
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: Failed to alloc request for vdev_id %d",
                v471,
                v472,
                v473,
                v474,
                v475,
                v476,
                v477,
                v478,
                "wma_add_sta_req_sta_mode",
                a2[131]);
              v479 = a2[131];
              *((_DWORD *)a2 + 25) = 16;
              wma_remove_req((__int64)a1, v479, 1u, v480, v481, v482, v483, v484, v485, v486, v487);
              wma_remove_peer(a1, a2, a2[131], 0, v488, v489, v490, v491, v492, v493, v494, v495);
              goto LABEL_37;
            }
          }
          else
          {
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: WMI_SERVICE_PEER_ASSOC_CONF not enabled",
              v463,
              v464,
              v465,
              v466,
              v467,
              v468,
              v469,
              v470,
              "wma_add_sta_req_sta_mode");
          }
          *(_BYTE *)(*(_QWORD *)(v81 + 200) + 243LL) = a2[243];
          qdf_mem_copy((void *)(*(_QWORD *)(v81 + 200) + 60LL), a2 + 60, 0x10u);
          if ( (unsigned int)wma_send_peer_assoc(a1, *(unsigned int *)(v81 + 240), *(_QWORD *)(v81 + 200)) )
          {
            result = wma_remove_peer(a1, a2, a2[131], 0, v216, v217, v218, v219, v220, v221, v222, v223);
            *(_WORD *)(v81 + 208) = *((_WORD *)a2 + 3);
            v380 = (unsigned __int16 *)(v81 + 208);
            if ( (v323 & 1) != 0 )
              goto LABEL_120;
            v82 = 16;
            goto LABEL_203;
          }
          if ( a2[105] )
          {
            wma_set_mgmt_frame_protection(a1);
            wma_set_peer_pmf_status(a1, a2);
          }
LABEL_165:
          if ( (wlan_reg_is_ext_tpc_supported(a1[3], v216, v217, v218, v219, v220, v221, v222, v223) & 1) != 0 )
            v324 = 0;
          else
            v324 = a2[148];
          if ( (unsigned int)wma_vdev_set_bss_params(
                               a1,
                               a2[131],
                               *(_WORD *)(v81 + 174),
                               *(_BYTE *)(v81 + 178),
                               *(_BYTE *)(v81 + 177),
                               *(_BYTE *)(v81 + 176),
                               v324) )
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: Failed to bss params",
              v325,
              v326,
              v327,
              v328,
              v329,
              v330,
              v331,
              v332,
              "wma_add_sta_req_sta_mode");
          a2[114] = 0;
          if ( (wmi_service_enabled(*a1, 0x15u, v325, v326, v327, v328, v329, v330, v331, v332) & 1) != 0 )
          {
            v341 = a2[131];
            a2[114] = 1;
            if ( (wma_unified_csa_offload_enable(a1, v341) & 0x80000000) != 0 )
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: Unable to enable CSA offload for vdev_id:%d",
                v333,
                v334,
                v335,
                v336,
                v337,
                v338,
                v339,
                v340,
                "wma_add_sta_req_sta_mode",
                a2[131]);
          }
          if ( (wmi_service_enabled(*a1, 0x38u, v333, v334, v335, v336, v337, v338, v339, v340) & 1) != 0
            && (unsigned int)wmi_unified_nat_keepalive_en_cmd(*a1, a2[131]) )
          {
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: Unable to enable NAT keepalive for vdev_id:%d",
              v342,
              v343,
              v344,
              v345,
              v346,
              v347,
              v348,
              v349,
              "wma_add_sta_req_sta_mode",
              a2[131]);
          }
          *(_DWORD *)(v81 + 228) = 1;
          if ( a2[125] )
          {
            if ( a2[127] == 1 )
            {
              v350 = wma_smps_mode_to_force_mode_param(a2[126]);
              if ( (v350 & 0x80000000) == 0 )
              {
                v351 = v350;
                qdf_trace_msg(
                  0x36u,
                  8u,
                  "%s: Send SMPS force mode: %d",
                  v342,
                  v343,
                  v344,
                  v345,
                  v346,
                  v347,
                  v348,
                  v349,
                  "wma_add_sta_req_sta_mode",
                  a2[126]);
                wma_set_mimops(a1, a2[131], v351);
              }
            }
          }
          v352 = a2[131];
          if ( (a2[152] & 1) != 0 )
          {
            if ( !(unsigned int)wmi_unified_send_bss_color_change_enable_cmd(*a1) )
            {
LABEL_186:
              if ( a2[123] && a2[120] )
                wma_set_ppsconfig(a2[131], 1, 1);
              if ( a2[124] && (a2[21] || a2[115]) )
                v342 = wma_set_ppsconfig(a2[131], 3, 1);
              if ( (wmi_service_enabled(*a1, 0x9Cu, v342, v343, v344, v345, v346, v347, v348, v349) & 1) == 0 )
              {
                result = qdf_trace_msg(
                           0x36u,
                           8u,
                           "%s: listen interval offload is not set",
                           v355,
                           v356,
                           v357,
                           v358,
                           v359,
                           v360,
                           v361,
                           v362,
                           "wma_add_sta_req_sta_mode");
                v82 = 0;
                goto LABEL_231;
              }
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: listen interval offload enabled, setting params",
                v355,
                v356,
                v357,
                v358,
                v359,
                v360,
                v361,
                v362,
                "wma_add_sta_req_sta_mode");
              v363 = *((unsigned __int8 *)a1 + 2705);
              v364 = a1[3];
              v365 = a2[131];
              LODWORD(v511) = 123;
              HIDWORD(v511) = v363;
              v366 = *((unsigned __int8 *)a1 + 2711);
              v367 = *((unsigned __int8 *)a1 + 2709);
              LODWORD(v512) = 124;
              HIDWORD(v512) = v366;
              LODWORD(v513) = 195;
              HIDWORD(v513) = v367;
              v368 = *((unsigned __int8 *)a1 + 2710);
              LODWORD(v514) = 196;
              HIDWORD(v514) = v368;
              v369 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                       v364,
                       v365,
                       8);
              if ( !v369 )
              {
                result = qdf_trace_msg(
                           0x36u,
                           8u,
                           "%s: Invalid vdev",
                           v370,
                           v371,
                           v372,
                           v373,
                           v374,
                           v375,
                           v376,
                           v377,
                           "wma_add_sta_req_sta_mode");
                *(_WORD *)(v81 + 208) = *((_WORD *)a2 + 3);
                v380 = (unsigned __int16 *)(v81 + 208);
                if ( (v323 & 1) != 0 )
                  goto LABEL_120;
                v82 = 0;
                goto LABEL_203;
              }
              v378 = v369;
              if ( (((__int64 (*)(void))ucfg_pmo_get_moddtim_user_enable)() & 1) != 0 )
              {
                if ( (ucfg_pmo_get_moddtim_user_enable(v378) & 1) == 0
                  || (ucfg_pmo_get_moddtim_user_active(v378) & 1) != 0 )
                {
                  v379 = 4;
LABEL_228:
                  v82 = wma_send_multi_pdev_vdev_set_params(1, a2[131], &v511, v379);
                  if ( v82 )
                    qdf_trace_msg(
                      0x36u,
                      2u,
                      "%s: failed to send DTIM vdev setparams",
                      v397,
                      v398,
                      v399,
                      v400,
                      v401,
                      v402,
                      v403,
                      v404,
                      "wma_add_sta_req_sta_mode");
                  result = wlan_objmgr_vdev_release_ref(v378, 8u, v396, v397, v398, v399, v400, v401, v402, v403, v404);
LABEL_231:
                  v405 = *((_WORD *)a2 + 3);
                  a2[151] = *(_BYTE *)(v81 + 236);
                  *(_WORD *)(v81 + 208) = v405;
                  v380 = (unsigned __int16 *)(v81 + 208);
                  if ( (v323 & 1) != 0 )
                    goto LABEL_120;
                  goto LABEL_203;
                }
                moddtim_user = ucfg_pmo_get_moddtim_user(v378);
              }
              else
              {
                moddtim_user = *((unsigned __int8 *)a1 + 2708);
              }
              v379 = 5;
              LODWORD(v515) = 122;
              HIDWORD(v515) = moddtim_user;
              goto LABEL_228;
            }
            v353 = "%s: Failed to enable bss color change offload, vdev:%d";
            v354 = 2;
          }
          else
          {
            v353 = "%s: he_capable is not set for vdev_id:%d";
            v354 = 8;
          }
          qdf_trace_msg(
            0x36u,
            v354,
            v353,
            v342,
            v343,
            v344,
            v345,
            v346,
            v347,
            v348,
            v349,
            "wma_send_bss_color_change_enable",
            v352);
          goto LABEL_186;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        1u,
        "%s invalid instance",
        v216,
        v217,
        v218,
        v219,
        v220,
        v221,
        v222,
        v223,
        "cdp_peer_state_get",
        v224);
    }
    v323 = 0;
    goto LABEL_165;
  }
  v54 = _cds_get_context(71, (__int64)"wma_add_tdls_sta", v45, v46, v47, v48, v49, v50, v51, v52);
  v63 = (__int64 *)(a1[65] + 488LL * a2[131]);
  if ( a2 )
  {
    v64 = a2[1];
    v65 = a2[2];
    v66 = a2[5];
  }
  else
  {
    v65 = 0;
    v64 = 0;
    v66 = 0;
  }
  LODWORD(v506) = v64;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev:%d Type: %d, updateSta: %d, bssId: %02x:%02x:%02x:**:**:%02x, staMac: %02x:%02x:%02x:**:**:%02x",
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    "wma_add_tdls_sta",
    v506,
    v65,
    v66,
    a2[9],
    a2[10],
    a2[11],
    a2[14],
    v510,
    v511,
    v512,
    v513,
    v514,
    v515,
    v516,
    v517,
    v518);
  if ( *v63 && wlan_cm_is_vdev_roaming(*v63, v45, v46, v47, v48, v49, v50, v51, v52) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Vdev %d roaming in progress, reject add sta!",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "wma_add_tdls_sta",
      a2[131]);
    v103 = 12;
LABEL_54:
    *((_DWORD *)a2 + 25) = v103;
    goto LABEL_114;
  }
  if ( !a2[104] )
  {
    if ( v54 && *v54 && (v189 = *(_QWORD *)(*v54 + 72LL)) != 0 )
    {
      v190 = *(_DWORD **)(v189 + 120);
      if ( v190 )
      {
        v191 = a2[131];
        if ( *(v190 - 1) != -187609570 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, __int64, unsigned __int8 *))v190)(v54, v191, a2);
      }
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        1u,
        "%s invalid instance",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "cdp_peer_copy_mac_addr_raw");
    }
    v204 = wma_create_peer((__int64)a1, a2 + 9, (__int64)a2, 2u, a2[131], 0, 0, v45, v46, v47, v48, v49, v50, v51, v52);
    if ( v204 )
    {
      v213 = v204;
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to create peer for %02x:%02x:%02x:**:**:%02x",
        v205,
        v206,
        v207,
        v208,
        v209,
        v210,
        v211,
        v212,
        "wma_add_tdls_sta",
        a2[9],
        a2[10],
        a2[11],
        a2[14]);
      *((_DWORD *)a2 + 25) = v213;
      goto LABEL_114;
    }
    v315 = (_DWORD *)_qdf_mem_malloc(0x444u, "wma_add_tdls_sta", 5554);
    if ( !v315 )
    {
      v103 = 2;
      goto LABEL_54;
    }
    v315[3] = 0;
    v316 = v315;
    *v315 = a2[131];
    qdf_mem_copy(v315 + 1, a2 + 9, 6u);
    result = wma_update_tdls_peer_state(a1, v316);
    if ( (*(_BYTE *)(a1[3] + 23LL) & 0x10) != 0 )
      goto LABEL_120;
  }
  v104 = wmi_service_enabled(*a1, 0x68u, v45, v46, v47, v48, v49, v50, v51, v52);
  if ( (v104 & 1) != 0 )
  {
    if ( !wma_fill_hold_req(a1, a2[131], 0x1021u, 1u, nullptr, (__int64)a2, 0xFA0u) )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to alloc request for vdev_id %d",
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        v119,
        v120,
        "wma_add_tdls_sta",
        a2[131]);
      v121 = a2[131];
      *((_DWORD *)a2 + 25) = 16;
      wma_remove_req((__int64)a1, v121, 1u, v122, v123, v124, v125, v126, v127, v128, v129);
      wma_remove_peer(a1, a2 + 9, a2[131], 0, v130, v131, v132, v133, v134, v135, v136, v137);
      goto LABEL_114;
    }
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: WMI_SERVICE_PEER_ASSOC_CONF not enabled",
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      "wma_add_tdls_sta");
  }
  if ( a2[105] )
    wma_set_peer_pmf_status(a1, a2 + 9);
  result = wma_send_peer_assoc(a1, *((unsigned int *)a2 + 36), a2);
  if ( (_DWORD)result )
  {
    v192 = a2[131];
    *((_DWORD *)a2 + 25) = 16;
    wma_remove_peer(a1, a2 + 9, v192, 0, v45, v46, v47, v48, v49, v50, v51, v52);
    if ( v54 && *v54 && (v201 = *(_QWORD *)(*v54 + 72LL)) != 0 )
    {
      v202 = *(_DWORD **)(v201 + 128);
      if ( v202 )
      {
        v203 = a2[131];
        if ( *(v202 - 1) != 1944199495 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v202)(v54, 0, v203);
      }
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        1u,
        "%s invalid instance",
        v193,
        v194,
        v195,
        v196,
        v197,
        v198,
        v199,
        v200,
        "cdp_peer_add_last_real_peer");
    }
    wma_remove_req((__int64)a1, a2[131], 1u, v193, v194, v195, v196, v197, v198, v199, v200);
    goto LABEL_114;
  }
  if ( (v104 & 1) == 0 )
  {
LABEL_114:
    v180 = a2[8];
    v181 = a2[131];
    v182 = *((unsigned __int16 *)a2 + 3);
    if ( a2 )
    {
      v183 = *a2;
      v184 = a2[1];
      v185 = a2[2];
      v186 = a2[5];
    }
    else
    {
      v185 = 0;
      v183 = 0;
      v184 = 0;
      v186 = 0;
    }
    v187 = *((_DWORD *)a2 + 25);
    v188 = "wma_add_tdls_sta";
LABEL_118:
    LODWORD(v509) = v187;
    LODWORD(v508) = v186;
    LODWORD(v507) = v185;
    LODWORD(v506) = v184;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: statype %d vdev_id %d aid %d bssid %02x:%02x:%02x:**:**:%02x status %d",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v188,
      v180,
      v181,
      v182,
      v183,
      v506,
      v507,
      v508,
      v509);
LABEL_119:
    result = wma_send_msg_high_priority(a1, 4130, a2, 0);
  }
LABEL_120:
  v67 = 1;
LABEL_121:
  v229 = *((unsigned __int16 *)a1 + 81);
  if ( v229 <= v12 )
  {
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: Invalid vdev_id %hu",
               v45,
               v46,
               v47,
               v48,
               v49,
               v50,
               v51,
               v52,
               "wma_is_vdev_in_sap_mode",
               v12);
    if ( *((unsigned __int16 *)a1 + 81) > v12 )
      goto LABEL_125;
    goto LABEL_133;
  }
  v230 = a1[65] + 488LL * v12;
  if ( *(_DWORD *)(v230 + 164) != 1 || *(_DWORD *)(v230 + 168) )
  {
    if ( v229 > v12 )
    {
LABEL_125:
      v231 = a1[65] + 488LL * v12;
      if ( *(_DWORD *)(v231 + 164) == 1 && *(_DWORD *)(v231 + 168) == 3 )
      {
        if ( (wlan_pmo_get_go_mode_bus_suspend(a1[3]) & 1) != 0
          && (wmi_service_enabled(*a1, 0xE8u, v232, v233, v234, v235, v236, v237, v238, v239) & 1) != 0 )
        {
          qdf_trace_msg(0x31u, 4u, "%s: p2p go d3 wow", v240, v241, v242, v243, v244, v245, v246, v247, "wma_add_sta");
          _X8 = (unsigned int *)(a1 + 495);
          __asm { PRFM            #0x11, [X8] }
          do
          {
            v501 = __ldxr(_X8);
            v502 = v501 + 1;
          }
          while ( __stlxr(v502, _X8) );
          __dmb(0xBu);
          qdf_trace_msg(
            0x31u,
            8u,
            "%s: go d3 wow %d client connected",
            v248,
            v249,
            v250,
            v251,
            v252,
            v253,
            v254,
            v255,
            "wma_go_d3_wow_client_connect",
            v502);
          if ( v502 == 9 )
          {
            qdf_trace_msg(
              0x31u,
              4u,
              "%s: max clients connected acquire go d3 wow wake lock",
              v256,
              v257,
              v258,
              v259,
              v260,
              v261,
              v262,
              v263,
              "wma_go_d3_wow_client_connect");
            qdf_wake_lock_acquire((__int64)(a1 + 521), 0x1Cu);
          }
        }
        else
        {
          htc_vote_link_up(v22, 2);
          qdf_trace_msg(0x31u, 4u, "%s: p2p go d0 wow", v299, v300, v301, v302, v303, v304, v305, v306, "wma_add_sta");
        }
LABEL_147:
        v265 = a1 + 417;
        goto LABEL_148;
      }
      goto LABEL_134;
    }
LABEL_133:
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: Invalid vdev_id %hu",
               v45,
               v46,
               v47,
               v48,
               v49,
               v50,
               v51,
               v52,
               "wma_is_vdev_in_go_mode",
               v12);
LABEL_134:
    if ( v42 == 7 && v67 )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: disable runtime pm and vote for link up",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "wma_add_sta");
      htc_vote_link_up(v22, 3);
      v265 = a1 + 418;
LABEL_148:
      result = qdf_runtime_pm_prevent_suspend(v265);
      goto LABEL_149;
    }
    goto LABEL_149;
  }
  if ( (wlan_pmo_get_sap_mode_bus_suspend(a1[3]) & 1) != 0
    && (wmi_service_enabled(*a1, 0xE7u, v266, v267, v268, v269, v270, v271, v272, v273) & 1) != 0 )
  {
    qdf_trace_msg(0x31u, 8u, "%s: sap d3 wow", v274, v275, v276, v277, v278, v279, v280, v281, "wma_add_sta");
    _X8 = (unsigned int *)a1 + 989;
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v504 = __ldxr(_X8);
      v505 = v504 + 1;
    }
    while ( __stlxr(v505, _X8) );
    __dmb(0xBu);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: sap d3 wow %d client connected",
      v282,
      v283,
      v284,
      v285,
      v286,
      v287,
      v288,
      v289,
      "wma_sap_d3_wow_client_connect",
      v505);
    if ( v505 == 9 )
    {
      qdf_trace_msg(
        0x31u,
        4u,
        "%s: max clients connected acquire sap d3 wow wake lock",
        v291,
        v292,
        v293,
        v294,
        v295,
        v296,
        v297,
        v298,
        "wma_sap_d3_wow_client_connect");
      qdf_wake_lock_acquire((__int64)(a1 + 496), 0x1Bu);
    }
  }
  else
  {
    htc_vote_link_up(v22, 1);
    qdf_trace_msg(0x31u, 4u, "%s: sap d0 wow", v307, v308, v309, v310, v311, v312, v313, v314, "wma_add_sta");
  }
  result = policy_mgr_is_vdev_ll_lt_sap(a1[3], v12);
  if ( (result & 1) == 0 )
    goto LABEL_147;
LABEL_149:
  _ReadStatusReg(SP_EL0);
  return result;
}
