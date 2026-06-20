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
  int v42; // w27
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
  __int64 v69; // x26
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
  __int64 v81; // x26
  int v82; // w24
  __int64 v83; // x8
  _DWORD *v84; // x8
  unsigned __int8 v85; // w28
  _BYTE *v86; // x25
  int v87; // w8
  char v88; // w25
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  unsigned __int8 v105; // w1
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  __int64 v122; // x8
  void (*v123)(void); // x8
  __int64 v124; // x0
  __int64 v125; // x1
  __int64 v126; // x0
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  unsigned int *v135; // x8
  __int64 v136; // x24
  __int64 mlpeer; // x0
  __int64 v138; // x26
  __int64 mlpeer_by_aid; // x0
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  int v148; // w26
  const char *v149; // x23
  __int64 v150; // x8
  _DWORD *v151; // x8
  __int64 v152; // x1
  unsigned int v153; // w2
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  __int64 v162; // x8
  _DWORD *v163; // x8
  __int64 v164; // x2
  int v165; // w0
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  int v174; // w25
  __int64 v175; // x0
  __int64 v176; // x26
  __int64 v177; // x0
  __int64 v178; // x23
  char is_vdev_up; // w0
  double v180; // d0
  double v181; // d1
  double v182; // d2
  double v183; // d3
  double v184; // d4
  double v185; // d5
  double v186; // d6
  double v187; // d7
  __int64 v188; // x4
  __int64 v189; // x5
  __int64 v190; // x6
  __int64 v191; // x7
  int v192; // w8
  __int64 v193; // x4
  __int64 v194; // x5
  __int64 v195; // x6
  __int64 v196; // x7
  int v197; // w8
  int v198; // w9
  int v199; // w10
  int v200; // w11
  const char *v201; // x3
  _QWORD *peer_by_mac; // x0
  __int64 v203; // x8
  int peer; // w0
  double v205; // d0
  double v206; // d1
  double v207; // d2
  double v208; // d3
  double v209; // d4
  double v210; // d5
  double v211; // d6
  double v212; // d7
  int v213; // w24
  __int64 v214; // x8
  __int64 (__fastcall *v215)(__int64, __int64, unsigned __int8 *); // x8
  __int64 v216; // x1
  double v217; // d0
  double v218; // d1
  double v219; // d2
  double v220; // d3
  double v221; // d4
  double v222; // d5
  double v223; // d6
  double v224; // d7
  unsigned int v225; // w24
  char v226; // w24
  double v227; // d0
  double v228; // d1
  double v229; // d2
  double v230; // d3
  double v231; // d4
  double v232; // d5
  double v233; // d6
  double v234; // d7
  double v235; // d0
  double v236; // d1
  double v237; // d2
  double v238; // d3
  double v239; // d4
  double v240; // d5
  double v241; // d6
  double v242; // d7
  double v243; // d0
  double v244; // d1
  double v245; // d2
  double v246; // d3
  double v247; // d4
  double v248; // d5
  double v249; // d6
  double v250; // d7
  unsigned __int8 v251; // w1
  __int64 v252; // x0
  _DWORD *v253; // x0
  _DWORD *v254; // x25
  unsigned int v255; // w2
  __int64 v256; // x8
  _DWORD *v257; // x8
  __int64 v258; // x4
  __int64 v259; // x5
  __int64 v260; // x6
  __int64 v261; // x7
  char v262; // w23
  char v263; // w6
  unsigned int *v264; // x8
  double v265; // d0
  double v266; // d1
  double v267; // d2
  double v268; // d3
  double v269; // d4
  double v270; // d5
  double v271; // d6
  double v272; // d7
  unsigned int v273; // w8
  __int64 v274; // x9
  __int64 v275; // x8
  double v276; // d0
  double v277; // d1
  double v278; // d2
  double v279; // d3
  double v280; // d4
  double v281; // d5
  double v282; // d6
  double v283; // d7
  double v284; // d0
  double v285; // d1
  double v286; // d2
  double v287; // d3
  double v288; // d4
  double v289; // d5
  double v290; // d6
  double v291; // d7
  double v292; // d0
  double v293; // d1
  double v294; // d2
  double v295; // d3
  double v296; // d4
  double v297; // d5
  double v298; // d6
  double v299; // d7
  double v301; // d0
  double v302; // d1
  double v303; // d2
  double v304; // d3
  double v305; // d4
  double v306; // d5
  double v307; // d6
  double v308; // d7
  __int64 *v310; // x0
  double v311; // d0
  double v312; // d1
  double v313; // d2
  double v314; // d3
  double v315; // d4
  double v316; // d5
  double v317; // d6
  double v318; // d7
  double v319; // d0
  double v320; // d1
  double v321; // d2
  double v322; // d3
  double v323; // d4
  double v324; // d5
  double v325; // d6
  double v326; // d7
  double v327; // d0
  double v328; // d1
  double v329; // d2
  double v330; // d3
  double v331; // d4
  double v332; // d5
  double v333; // d6
  double v334; // d7
  double v335; // d0
  double v336; // d1
  double v337; // d2
  double v338; // d3
  double v339; // d4
  double v340; // d5
  double v341; // d6
  double v342; // d7
  double v343; // d0
  double v344; // d1
  double v345; // d2
  double v346; // d3
  double v347; // d4
  double v348; // d5
  double v349; // d6
  double v350; // d7
  double v351; // d0
  double v352; // d1
  double v353; // d2
  double v354; // d3
  double v355; // d4
  double v356; // d5
  double v357; // d6
  double v358; // d7
  double v359; // d0
  double v360; // d1
  double v361; // d2
  double v362; // d3
  double v363; // d4
  double v364; // d5
  double v365; // d6
  double v366; // d7
  double v367; // d0
  double v368; // d1
  double v369; // d2
  double v370; // d3
  double v371; // d4
  double v372; // d5
  double v373; // d6
  double v374; // d7
  __int64 v375; // x1
  double v376; // d0
  double v377; // d1
  double v378; // d2
  double v379; // d3
  double v380; // d4
  double v381; // d5
  double v382; // d6
  double v383; // d7
  unsigned int v384; // w0
  double v385; // d0
  double v386; // d1
  double v387; // d2
  double v388; // d3
  double v389; // d4
  double v390; // d5
  double v391; // d6
  double v392; // d7
  unsigned int v393; // w24
  double v394; // d0
  double v395; // d1
  double v396; // d2
  double v397; // d3
  double v398; // d4
  double v399; // d5
  double v400; // d6
  double v401; // d7
  double v402; // d0
  double v403; // d1
  double v404; // d2
  double v405; // d3
  double v406; // d4
  double v407; // d5
  double v408; // d6
  double v409; // d7
  int v410; // w8
  __int64 v411; // x0
  __int64 v412; // x1
  int v413; // w9
  int v414; // w8
  int v415; // w8
  __int64 v416; // x0
  double v417; // d0
  double v418; // d1
  double v419; // d2
  double v420; // d3
  double v421; // d4
  double v422; // d5
  double v423; // d6
  double v424; // d7
  __int64 v425; // x25
  __int64 v426; // x3
  unsigned __int16 *v427; // x26
  __int64 v428; // x6
  __int64 v429; // x7
  int v430; // w8
  int v431; // w9
  _QWORD *v432; // x26
  unsigned int *v433; // x8
  double v434; // d0
  double v435; // d1
  double v436; // d2
  double v437; // d3
  double v438; // d4
  double v439; // d5
  double v440; // d6
  double v441; // d7
  int moddtim_user; // w0
  unsigned int *v443; // x8
  double v444; // d0
  double v445; // d1
  double v446; // d2
  double v447; // d3
  double v448; // d4
  double v449; // d5
  double v450; // d6
  double v451; // d7
  __int16 v452; // w9
  unsigned int v453; // w11
  unsigned int v454; // w10
  unsigned int v455; // w8
  unsigned __int8 *v456; // x12
  bool v457; // cc
  unsigned __int64 v458; // x15
  int v459; // w16
  unsigned __int8 v460; // w17
  unsigned __int8 v461; // w0
  unsigned __int8 v462; // w16
  unsigned int v463; // w2
  double v464; // d0
  double v465; // d1
  double v466; // d2
  double v467; // d3
  double v468; // d4
  double v469; // d5
  double v470; // d6
  double v471; // d7
  __int64 v472; // x4
  __int64 v473; // x5
  __int64 v474; // x6
  __int64 v475; // x7
  double v476; // d0
  double v477; // d1
  double v478; // d2
  double v479; // d3
  double v480; // d4
  double v481; // d5
  double v482; // d6
  double v483; // d7
  unsigned __int8 peer_mlme_nss; // w0
  double v485; // d0
  double v486; // d1
  double v487; // d2
  double v488; // d3
  double v489; // d4
  double v490; // d5
  double v491; // d6
  double v492; // d7
  double v493; // d0
  double v494; // d1
  double v495; // d2
  double v496; // d3
  double v497; // d4
  double v498; // d5
  double v499; // d6
  double v500; // d7
  double v501; // d0
  double v502; // d1
  double v503; // d2
  double v504; // d3
  double v505; // d4
  double v506; // d5
  double v507; // d6
  double v508; // d7
  int v509; // w8
  int v510; // w9
  int v511; // w10
  double v512; // d0
  double v513; // d1
  double v514; // d2
  double v515; // d3
  double v516; // d4
  double v517; // d5
  double v518; // d6
  double v519; // d7
  double v520; // d0
  double v521; // d1
  double v522; // d2
  double v523; // d3
  double v524; // d4
  double v525; // d5
  double v526; // d6
  double v527; // d7
  double v528; // d0
  double v529; // d1
  double v530; // d2
  double v531; // d3
  double v532; // d4
  double v533; // d5
  double v534; // d6
  double v535; // d7
  unsigned __int8 v536; // w1
  double v537; // d0
  double v538; // d1
  double v539; // d2
  double v540; // d3
  double v541; // d4
  double v542; // d5
  double v543; // d6
  double v544; // d7
  double v545; // d0
  double v546; // d1
  double v547; // d2
  double v548; // d3
  double v549; // d4
  double v550; // d5
  double v551; // d6
  double v552; // d7
  unsigned int v557; // w20
  unsigned int v558; // w20
  unsigned int v561; // w21
  unsigned int v562; // w21
  __int64 v563; // [xsp+0h] [xbp-90h]
  __int64 v564; // [xsp+8h] [xbp-88h]
  __int64 v565; // [xsp+10h] [xbp-80h]
  __int64 v566; // [xsp+18h] [xbp-78h]
  char v567; // [xsp+44h] [xbp-4Ch]
  __int64 v568; // [xsp+48h] [xbp-48h]
  __int64 v569; // [xsp+50h] [xbp-40h] BYREF
  __int64 v570; // [xsp+58h] [xbp-38h]
  __int64 v571; // [xsp+60h] [xbp-30h]
  __int64 v572; // [xsp+68h] [xbp-28h]
  __int64 v573; // [xsp+70h] [xbp-20h]
  __int64 v574; // [xsp+78h] [xbp-18h]
  __int64 v575; // [xsp+80h] [xbp-10h]
  __int64 v576; // [xsp+88h] [xbp-8h]

  v576 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = a2[143];
  htc_hdl = lmac_get_htc_hdl(a1[3], a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !htc_hdl )
  {
    result = qdf_trace_msg(0x36u, 2u, "%s: HTC handle is NULL", v14, v15, v16, v17, v18, v19, v20, v21, "wma_add_sta");
    goto LABEL_190;
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
      *((_DWORD *)a2 + 28) = 0;
LABEL_155:
      v193 = a2[8];
      v194 = a2[143];
      v195 = *((unsigned __int16 *)a2 + 3);
      if ( a2 )
      {
        v196 = *a2;
        v197 = a2[1];
        v198 = a2[2];
        v199 = a2[5];
      }
      else
      {
        v198 = 0;
        v196 = 0;
        v197 = 0;
        v199 = 0;
      }
      v200 = *((_DWORD *)a2 + 28);
      v201 = "wma_add_sta_req_ap_mode";
      goto LABEL_159;
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
            wma_remove_peer(a1, a2 + 9, a2[143], 0, v45, v46, v47, v48, v49, v50, v51, v52);
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
              LODWORD(v563) = a2[14];
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
                a2[143],
                a2[9],
                a2[10],
                a2[11],
                v563);
              *((_DWORD *)a2 + 28) = 16;
              goto LABEL_155;
            }
          }
LABEL_48:
          wma_delete_invalid_peer_entries(a2[143], a2 + 9, v45, v46, v47, v48, v49, v50, v51, v52);
          if ( a2 )
          {
            v85 = a2[372];
            v86 = a2 + 366;
          }
          else
          {
            v86 = nullptr;
            v85 = 0;
          }
          v124 = a1[3];
          v125 = a2[143];
          WORD2(v569) = 0;
          LODWORD(v569) = 0;
          v126 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                   v124,
                   v125,
                   8);
          if ( !v126 )
          {
            v148 = 16;
LABEL_154:
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: Conflict detected with mac address, peer create failed",
              v127,
              v128,
              v129,
              v130,
              v131,
              v132,
              v133,
              v134,
              "wma_add_sta_req_ap_mode");
            *((_DWORD *)a2 + 28) = v148;
            goto LABEL_155;
          }
          v135 = *(unsigned int **)(v126 + 1360);
          v136 = v126;
          v568 = v69;
          if ( !v135 )
            goto LABEL_116;
          qdf_mem_copy(&v569, a2 + 9, 6u);
          mlpeer = wlan_mlo_get_mlpeer(*(_QWORD *)(v136 + 1360), &v569);
          if ( mlpeer )
          {
            v138 = mlpeer;
            mlpeer_by_aid = wlan_mlo_get_mlpeer_by_aid(*(_QWORD *)(v136 + 1360));
            if ( !mlpeer_by_aid )
            {
              v149 = "%s: Link mac address conflicts with another MLO peer on same interface";
              goto LABEL_152;
            }
            if ( v138 != mlpeer_by_aid )
            {
              v148 = 16;
              v149 = "%s: Link mac address conflicts with another MLO peer on same interface";
LABEL_153:
              qdf_trace_msg(
                0x36u,
                2u,
                v149,
                v140,
                v141,
                v142,
                v143,
                v144,
                v145,
                v146,
                v147,
                "wma_validate_mac_for_conflict_on_same_ml_ctx");
              wlan_objmgr_vdev_release_ref(v136, 8u, v264, v265, v266, v267, v268, v269, v270, v271, v272);
              goto LABEL_154;
            }
          }
          v175 = wlan_mlo_get_mlpeer(*(_QWORD *)(v136 + 1360), v86);
          if ( !v175 )
            goto LABEL_112;
          v176 = v175;
          v177 = wlan_mlo_get_mlpeer_by_aid(*(_QWORD *)(v136 + 1360));
          if ( v177 )
          {
            if ( v176 != v177 )
            {
              v148 = 16;
              v149 = "%s: MLD mac address conflicts with another MLO peer on same interface";
              goto LABEL_153;
            }
LABEL_112:
            peer_by_mac = wlan_objmgr_get_peer_by_mac(a1[3], v86, 8u);
            if ( peer_by_mac )
            {
              v203 = peer_by_mac[98];
              if ( v203 && *(unsigned __int16 *)(v203 + 184) != *((unsigned __int16 *)a2 + 3) )
              {
                v432 = peer_by_mac;
                qdf_trace_msg(
                  0x36u,
                  2u,
                  "%s: MLD mac address conflicts with link mac address of another ML-peer on same interface",
                  v127,
                  v128,
                  v129,
                  v130,
                  v131,
                  v132,
                  v133,
                  v134,
                  "wma_validate_mac_for_conflict_on_same_ml_ctx");
                peer_by_mac = v432;
                v148 = 16;
                v567 = 0;
              }
              else
              {
                v148 = 0;
                v567 = 1;
              }
              wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 8u, v127, v128, v129, v130, v131, v132, v133, v134);
              wlan_objmgr_vdev_release_ref(v136, 8u, v433, v434, v435, v436, v437, v438, v439, v440, v441);
              if ( (v567 & 1) == 0 )
                goto LABEL_154;
LABEL_117:
              peer = wma_create_peer(
                       (__int64)a1,
                       a2 + 9,
                       0,
                       0,
                       a2[143],
                       (__int64)v86,
                       v85 & 1,
                       v127,
                       v128,
                       v129,
                       v130,
                       v131,
                       v132,
                       v133,
                       v134);
              if ( peer )
              {
                v213 = peer;
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
                  "wma_add_sta_req_ap_mode",
                  a2[9],
                  a2[10],
                  a2[11],
                  a2[14]);
                *((_DWORD *)a2 + 28) = v213;
                goto LABEL_155;
              }
              if ( v70 && *(_QWORD *)v70 && (v214 = *(_QWORD *)(*(_QWORD *)v70 + 72LL)) != 0 )
              {
                v215 = *(__int64 (__fastcall **)(__int64, __int64, unsigned __int8 *))(v214 + 24);
                if ( v215 )
                {
                  v216 = a2[143];
                  if ( *((_DWORD *)v215 - 1) != 454466150 )
                    __break(0x8228u);
                  if ( (v215(v70, v216, a2 + 9) & 1) != 0 )
                  {
                    wmi_unified_send_txbf(a1, a2, v205, v206, v207, v208, v209, v210, v211, v212);
                    v225 = *(unsigned __int16 *)(*(_QWORD *)(v568 + 8) + 2968LL);
                    if ( v225 >= 0x100 )
                    {
                      qdf_trace_msg(
                        0x36u,
                        8u,
                        "%s: set mcs_limit %x",
                        v217,
                        v218,
                        v219,
                        v220,
                        v221,
                        v222,
                        v223,
                        v224,
                        "wma_add_sta_req_ap_mode",
                        *(unsigned __int16 *)(*(_QWORD *)(v568 + 8) + 2968LL));
                      v453 = (unsigned __int8)v225 >> 3;
                      v454 = 0;
                      v455 = 0;
                      v456 = a2 + 60;
                      do
                      {
                        if ( v454 < v453 )
                        {
                          v456[v454++] = -1;
                          v455 += 8;
                        }
                        else if ( v454 <= v453 )
                        {
                          v457 = v455 > (unsigned __int8)v225;
                          v458 = (unsigned __int64)v455 >> 3;
                          v459 = 1 << (v455++ & 7);
                          v460 = v456[v458];
                          v461 = v460 & ~(_BYTE)v459;
                          v462 = v460 | v459;
                          if ( v457 )
                            v462 = v461;
                          v456[v458] = v462;
                          if ( v455 >= 8 * (v454 + 1) )
                            ++v454;
                        }
                        else
                        {
                          v456[v454] = 0;
                          v455 += 8;
                          ++v454;
                        }
                      }
                      while ( v455 < 0x80 );
                    }
                    v226 = wmi_service_enabled(*a1, 0x68u, v217, v218, v219, v220, v221, v222, v223, v224);
                    if ( (v226 & 1) != 0 )
                    {
                      if ( !wma_fill_hold_req(a1, a2[143], 0x1021u, 1u, nullptr, (__int64)a2, 0xFA0u) )
                      {
                        qdf_trace_msg(
                          0x36u,
                          2u,
                          "%s: Failed to alloc request for vdev_id %d",
                          v235,
                          v236,
                          v237,
                          v238,
                          v239,
                          v240,
                          v241,
                          v242,
                          "wma_add_sta_req_ap_mode",
                          a2[143]);
                        v251 = a2[143];
                        v252 = (__int64)a1;
                        *((_DWORD *)a2 + 28) = 16;
LABEL_255:
                        wma_remove_req(v252, v251, 1u, v243, v244, v245, v246, v247, v248, v249, v250);
                        v255 = a2[143];
                        goto LABEL_136;
                      }
                    }
                    else
                    {
                      qdf_trace_msg(
                        0x36u,
                        2u,
                        "%s: WMI_SERVICE_PEER_ASSOC_CONF not enabled",
                        v227,
                        v228,
                        v229,
                        v230,
                        v231,
                        v232,
                        v233,
                        v234,
                        "wma_add_sta_req_ap_mode");
                    }
                    if ( !(unsigned int)((__int64 (__fastcall *)(_QWORD *, _QWORD, unsigned __int8 *))wma_send_peer_assoc)(
                                          a1,
                                          *((unsigned int *)a2 + 39),
                                          a2) )
                    {
                      if ( a2[117] )
                        wma_set_peer_pmf_status(a1, a2 + 9);
                      if ( a2[19] && (unsigned int)wma_set_ap_peer_uapsd(a1, a2[143], a2 + 9) )
                      {
                        qdf_trace_msg(
                          0x36u,
                          2u,
                          "%s: Failed to set peer uapsd param for %02x:%02x:%02x:**:**:%02x",
                          v243,
                          v244,
                          v245,
                          v246,
                          v247,
                          v248,
                          v249,
                          v250,
                          "wma_add_sta_req_ap_mode",
                          a2[9],
                          a2[10],
                          a2[11],
                          a2[14]);
                        v463 = a2[143];
                        *((_DWORD *)a2 + 28) = 16;
                        wma_remove_peer(a1, a2 + 9, v463, 0, v464, v465, v466, v467, v468, v469, v470, v471);
                        if ( (v226 & 1) == 0 )
                          goto LABEL_155;
                      }
                      else
                      {
                        LODWORD(v563) = 2;
                        qdf_trace_msg(
                          0x36u,
                          8u,
                          "%s: Moving peer %02x:%02x:%02x:**:**:%02x to state %d",
                          v243,
                          v244,
                          v245,
                          v246,
                          v247,
                          v248,
                          v249,
                          v250,
                          "wma_add_sta_req_ap_mode",
                          a2[9],
                          a2[10],
                          a2[11],
                          a2[14],
                          v563);
                        cdp_peer_state_update(v70, v476, v477, v478, v479, v480, v481, v482, v483);
                        peer_mlme_nss = wma_objmgr_get_peer_mlme_nss(a1, a2 + 9);
                        *((_DWORD *)a2 + 28) = 0;
                        a2[163] = peer_mlme_nss;
                        if ( (v226 & 1) == 0 )
                          goto LABEL_155;
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
                      goto LABEL_161;
                    }
                    v255 = a2[143];
                    *((_DWORD *)a2 + 28) = 16;
                    if ( (v226 & 1) == 0 )
                      goto LABEL_136;
                    v252 = (__int64)a1;
                    v251 = v255;
                    goto LABEL_255;
                  }
                }
              }
              else
              {
                qdf_trace_msg(
                  0x45u,
                  1u,
                  "%s invalid instance",
                  v205,
                  v206,
                  v207,
                  v208,
                  v209,
                  v210,
                  v211,
                  v212,
                  "cdp_find_peer_exist_on_vdev");
              }
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: Failed to find peer handle using peer mac %02x:%02x:%02x:**:**:%02x",
                v205,
                v206,
                v207,
                v208,
                v209,
                v210,
                v211,
                v212,
                "wma_add_sta_req_ap_mode",
                a2[9],
                a2[10],
                a2[11],
                a2[14]);
              v255 = a2[143];
              *((_DWORD *)a2 + 28) = 16;
LABEL_136:
              wma_remove_peer(a1, a2 + 9, v255, 0, v243, v244, v245, v246, v247, v248, v249, v250);
              goto LABEL_155;
            }
LABEL_116:
            wlan_objmgr_vdev_release_ref(v136, 8u, v135, v127, v128, v129, v130, v131, v132, v133, v134);
            goto LABEL_117;
          }
          v149 = "%s: MLD mac address conflicts with another MLO peer on same interface";
LABEL_152:
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: ML-peer with same mac address exists for a different AID",
            v140,
            v141,
            v142,
            v143,
            v144,
            v145,
            v146,
            v147,
            "wma_check_for_mlo_peer_conflict");
          v148 = 6;
          goto LABEL_153;
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
    goto LABEL_162;
  }
  v44 = _cds_get_context(71, (__int64)"wma_add_sta_req_sta_mode", v28, v29, v30, v31, v32, v33, v34, v35);
  v53 = a2[8];
  v574 = 0;
  v575 = 0;
  v572 = 0;
  v573 = 0;
  v570 = 0;
  v571 = 0;
  v569 = 0;
  if ( v53 != 4 )
  {
    v81 = a1[65] + 488LL * a2[143];
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
LABEL_221:
      *(_WORD *)(v81 + 208) = *((_WORD *)a2 + 3);
      v427 = (unsigned __int16 *)(v81 + 208);
LABEL_222:
      *((_DWORD *)a2 + 28) = v82;
      if ( a2 )
      {
        v428 = *a2;
        v429 = a2[1];
        v430 = a2[2];
        v431 = a2[5];
      }
      else
      {
        v430 = 0;
        v428 = 0;
        v429 = 0;
        v431 = 0;
      }
      LODWORD(v563) = v430;
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
        a2[143],
        *v427,
        v428,
        v429,
        v563,
        v431,
        v82);
      result = wlan_cm_is_roam_sync_in_progress(a1[3], a2[143]);
      if ( (result & 1) != 0 )
        goto LABEL_161;
      result = mlme_get_roam_state(a1[3], a2[143]);
      if ( (_DWORD)result == 6 )
        goto LABEL_161;
      goto LABEL_160;
    }
    if ( a2[161] )
    {
      if ( v44 && *v44 && (v122 = *(_QWORD *)(*v44 + 72LL)) != 0 )
      {
        v123 = *(void (**)(void))(v122 + 40);
        if ( v123 )
        {
          if ( *((_DWORD *)v123 - 1) != 1499005600 )
            __break(0x8228u);
          v123();
        }
      }
      else
      {
        qdf_trace_msg(0x45u, 1u, "%s invalid instance", v45, v46, v47, v48, v49, v50, v51, v52, "cdp_peer_state_update");
      }
      v82 = 0;
      *(_DWORD *)(v81 + 228) = 1;
      *(_WORD *)(v81 + 208) = *((_WORD *)a2 + 3);
      goto LABEL_221;
    }
    v178 = (__int64)v44;
    is_vdev_up = wma_is_vdev_up(a2[143]);
    v188 = a2[143];
    if ( (is_vdev_up & 1) != 0 )
    {
      if ( a2 )
      {
        v189 = *a2;
        v190 = a2[1];
        v191 = a2[2];
        v192 = a2[5];
      }
      else
      {
        v191 = 0;
        v189 = 0;
        v190 = 0;
        v192 = 0;
      }
      LODWORD(v563) = v192;
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: vdev id %d is already UP for %02x:%02x:%02x:**:**:%02x",
        v180,
        v181,
        v182,
        v183,
        v184,
        v185,
        v186,
        v187,
        "wma_add_sta_req_sta_mode",
        v188,
        v189,
        v190,
        v191,
        v563);
      v82 = 16;
      goto LABEL_221;
    }
    if ( v178 && *(_QWORD *)v178 && (v256 = *(_QWORD *)(*(_QWORD *)v178 + 72LL)) != 0 )
    {
      v257 = *(_DWORD **)(v256 + 80);
      if ( v257 )
      {
        if ( *(v257 - 1) != -223539710 )
          __break(0x8228u);
        if ( ((unsigned int (__fastcall *)(__int64, _QWORD, unsigned __int8 *, __int64))v257)(
               v178,
               (unsigned int)v188,
               a2,
               1) == 1 )
        {
          if ( *((_DWORD *)a2 + 30) )
          {
            if ( a2 )
            {
              v258 = *a2;
              v259 = a2[1];
              v260 = a2[2];
              v261 = a2[5];
            }
            else
            {
              v260 = 0;
              v258 = 0;
              v259 = 0;
              v261 = 0;
            }
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: Update peer(%02x:%02x:%02x:**:**:%02x) state into conn",
              v180,
              v181,
              v182,
              v183,
              v184,
              v185,
              v186,
              v187,
              "wma_add_sta_req_sta_mode",
              v258,
              v259,
              v260,
              v261);
          }
          else
          {
            if ( a2 )
            {
              v472 = *a2;
              v473 = a2[1];
              v474 = a2[2];
              v475 = a2[5];
            }
            else
            {
              v474 = 0;
              v472 = 0;
              v473 = 0;
              v475 = 0;
            }
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: Update peer(%02x:%02x:%02x:**:**:%02x) state into auth",
              v180,
              v181,
              v182,
              v183,
              v184,
              v185,
              v186,
              v187,
              "wma_add_sta_req_sta_mode",
              v472,
              v473,
              v474,
              v475);
          }
          cdp_peer_state_update(v178, v485, v486, v487, v488, v489, v490, v491, v492);
          if ( wlan_cm_is_roam_sync_in_progress(a1[3], a2[143])
            || (unsigned int)mlme_get_roam_state(a1[3], a2[143]) == 6 )
          {
            cdp_peer_state_update(v178, v493, v494, v495, v496, v497, v498, v499, v500);
            *(_DWORD *)(v81 + 228) = 1;
            *(_WORD *)(v81 + 208) = *((_WORD *)a2 + 3);
            if ( a2 )
            {
              v509 = a2[1];
              v510 = a2[2];
              v511 = a2[5];
            }
            else
            {
              v510 = 0;
              v509 = 0;
              v511 = 0;
            }
            LODWORD(v563) = v509;
            result = qdf_trace_msg(
                       0x36u,
                       8u,
                       "%s: LFR3:statype %d vdev %d aid %d bssid %02x:%02x:%02x:**:**:%02x",
                       v501,
                       v502,
                       v503,
                       v504,
                       v505,
                       v506,
                       v507,
                       v508,
                       "wma_add_sta_req_sta_mode",
                       a2[8],
                       a2[143],
                       v563,
                       v510,
                       v511);
            goto LABEL_161;
          }
          wmi_unified_send_txbf(a1, a2, v493, v494, v495, v496, v497, v498, v499, v500);
          v262 = wmi_service_enabled(*a1, 0x68u, v512, v513, v514, v515, v516, v517, v518, v519);
          if ( (v262 & 1) != 0 )
          {
            if ( !wma_fill_hold_req(a1, a2[143], 0x1021u, 1u, nullptr, (__int64)a2, 0xFA0u) )
            {
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: Failed to alloc request for vdev_id %d",
                v528,
                v529,
                v530,
                v531,
                v532,
                v533,
                v534,
                v535,
                "wma_add_sta_req_sta_mode",
                a2[143]);
              v536 = a2[143];
              *((_DWORD *)a2 + 28) = 16;
              wma_remove_req((__int64)a1, v536, 1u, v537, v538, v539, v540, v541, v542, v543, v544);
              wma_remove_peer(a1, a2, a2[143], 0, v545, v546, v547, v548, v549, v550, v551, v552);
              goto LABEL_37;
            }
          }
          else
          {
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: WMI_SERVICE_PEER_ASSOC_CONF not enabled",
              v520,
              v521,
              v522,
              v523,
              v524,
              v525,
              v526,
              v527,
              "wma_add_sta_req_sta_mode");
          }
          *(_BYTE *)(*(_QWORD *)(v81 + 200) + 255LL) = a2[255];
          qdf_mem_copy((void *)(*(_QWORD *)(v81 + 200) + 60LL), a2 + 60, 0x10u);
          if ( (unsigned int)((__int64 (__fastcall *)(_QWORD *, _QWORD, _QWORD))wma_send_peer_assoc)(
                               a1,
                               *(unsigned int *)(v81 + 240),
                               *(_QWORD *)(v81 + 200)) )
          {
            result = wma_remove_peer(a1, a2, a2[143], 0, v180, v181, v182, v183, v184, v185, v186, v187);
            *(_WORD *)(v81 + 208) = *((_WORD *)a2 + 3);
            v427 = (unsigned __int16 *)(v81 + 208);
            if ( (v262 & 1) != 0 )
              goto LABEL_161;
            v82 = 16;
            goto LABEL_222;
          }
          if ( a2[117] )
          {
            wma_set_mgmt_frame_protection(a1);
            wma_set_peer_pmf_status(a1, a2);
          }
LABEL_149:
          if ( (wlan_reg_is_ext_tpc_supported(a1[3], v180, v181, v182, v183, v184, v185, v186, v187) & 1) != 0 )
            v263 = 0;
          else
            v263 = a2[160];
          if ( (unsigned int)wma_vdev_set_bss_params(
                               a1,
                               a2[143],
                               *(_WORD *)(v81 + 174),
                               *(_BYTE *)(v81 + 178),
                               *(_BYTE *)(v81 + 177),
                               *(_BYTE *)(v81 + 176),
                               v263) )
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: Failed to bss params",
              v359,
              v360,
              v361,
              v362,
              v363,
              v364,
              v365,
              v366,
              "wma_add_sta_req_sta_mode");
          a2[126] = 0;
          if ( (wmi_service_enabled(*a1, 0x15u, v359, v360, v361, v362, v363, v364, v365, v366) & 1) != 0 )
          {
            v375 = a2[143];
            a2[126] = 1;
            if ( (wma_unified_csa_offload_enable(a1, v375) & 0x80000000) != 0 )
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: Unable to enable CSA offload for vdev_id:%d",
                v367,
                v368,
                v369,
                v370,
                v371,
                v372,
                v373,
                v374,
                "wma_add_sta_req_sta_mode",
                a2[143]);
          }
          if ( (wmi_service_enabled(*a1, 0x38u, v367, v368, v369, v370, v371, v372, v373, v374) & 1) != 0
            && (unsigned int)wmi_unified_nat_keepalive_en_cmd(*a1, a2[143]) )
          {
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: Unable to enable NAT keepalive for vdev_id:%d",
              v376,
              v377,
              v378,
              v379,
              v380,
              v381,
              v382,
              v383,
              "wma_add_sta_req_sta_mode",
              a2[143]);
          }
          *(_DWORD *)(v81 + 228) = 1;
          if ( a2[137] )
          {
            if ( a2[139] == 1 )
            {
              v384 = wma_smps_mode_to_force_mode_param(a2[138]);
              if ( (v384 & 0x80000000) == 0 )
              {
                v393 = v384;
                qdf_trace_msg(
                  0x36u,
                  8u,
                  "%s: Send SMPS force mode: %d",
                  v385,
                  v386,
                  v387,
                  v388,
                  v389,
                  v390,
                  v391,
                  v392,
                  "wma_add_sta_req_sta_mode",
                  a2[138]);
                wma_set_mimops(a1, a2[143], v393);
              }
            }
          }
          wma_send_bss_color_change_enable(a1, a2);
          if ( a2[135] && a2[132] )
            wma_set_ppsconfig(a2[143], 1, 1);
          if ( a2[136] && (a2[21] || a2[127]) )
            v394 = wma_set_ppsconfig(a2[143], 3, 1);
          if ( (wmi_service_enabled(*a1, 0x9Cu, v394, v395, v396, v397, v398, v399, v400, v401) & 1) == 0 )
          {
            result = qdf_trace_msg(
                       0x36u,
                       8u,
                       "%s: listen interval offload is not set",
                       v402,
                       v403,
                       v404,
                       v405,
                       v406,
                       v407,
                       v408,
                       v409,
                       "wma_add_sta_req_sta_mode");
            v82 = 0;
            goto LABEL_238;
          }
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: listen interval offload enabled, setting params",
            v402,
            v403,
            v404,
            v405,
            v406,
            v407,
            v408,
            v409,
            "wma_add_sta_req_sta_mode");
          v410 = *((unsigned __int8 *)a1 + 2705);
          v411 = a1[3];
          v412 = a2[143];
          LODWORD(v569) = 123;
          HIDWORD(v569) = v410;
          v413 = *((unsigned __int8 *)a1 + 2711);
          v414 = *((unsigned __int8 *)a1 + 2709);
          LODWORD(v570) = 124;
          HIDWORD(v570) = v413;
          LODWORD(v571) = 195;
          HIDWORD(v571) = v414;
          v415 = *((unsigned __int8 *)a1 + 2710);
          LODWORD(v572) = 196;
          HIDWORD(v572) = v415;
          v416 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                   v411,
                   v412,
                   8);
          if ( !v416 )
          {
            result = qdf_trace_msg(
                       0x36u,
                       8u,
                       "%s: Invalid vdev",
                       v417,
                       v418,
                       v419,
                       v420,
                       v421,
                       v422,
                       v423,
                       v424,
                       "wma_add_sta_req_sta_mode");
            *(_WORD *)(v81 + 208) = *((_WORD *)a2 + 3);
            v427 = (unsigned __int16 *)(v81 + 208);
            if ( (v262 & 1) != 0 )
              goto LABEL_161;
            v82 = 0;
            goto LABEL_222;
          }
          v425 = v416;
          if ( (((__int64 (*)(void))ucfg_pmo_get_moddtim_user_enable)() & 1) != 0 )
          {
            if ( (ucfg_pmo_get_moddtim_user_enable(v425) & 1) == 0 || (ucfg_pmo_get_moddtim_user_active(v425) & 1) != 0 )
            {
              v426 = 4;
LABEL_235:
              v82 = wma_send_multi_pdev_vdev_set_params(1, a2[143], &v569, v426);
              if ( v82 )
                qdf_trace_msg(
                  0x36u,
                  2u,
                  "%s: failed to send DTIM vdev setparams",
                  v444,
                  v445,
                  v446,
                  v447,
                  v448,
                  v449,
                  v450,
                  v451,
                  "wma_add_sta_req_sta_mode");
              result = wlan_objmgr_vdev_release_ref(v425, 8u, v443, v444, v445, v446, v447, v448, v449, v450, v451);
LABEL_238:
              v452 = *((_WORD *)a2 + 3);
              a2[163] = *(_BYTE *)(v81 + 236);
              *(_WORD *)(v81 + 208) = v452;
              v427 = (unsigned __int16 *)(v81 + 208);
              if ( (v262 & 1) != 0 )
                goto LABEL_161;
              goto LABEL_222;
            }
            moddtim_user = ucfg_pmo_get_moddtim_user(v425);
          }
          else
          {
            moddtim_user = *((unsigned __int8 *)a1 + 2708);
          }
          v426 = 5;
          LODWORD(v573) = 122;
          HIDWORD(v573) = moddtim_user;
          goto LABEL_235;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        1u,
        "%s invalid instance",
        v180,
        v181,
        v182,
        v183,
        v184,
        v185,
        v186,
        v187,
        "cdp_peer_state_get",
        v188);
    }
    v262 = 0;
    goto LABEL_149;
  }
  v54 = _cds_get_context(71, (__int64)"wma_add_tdls_sta", v45, v46, v47, v48, v49, v50, v51, v52);
  v63 = (__int64 *)(a1[65] + 488LL * a2[143]);
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
  LODWORD(v563) = v64;
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
    v563,
    v65,
    v66,
    a2[9],
    a2[10],
    a2[11],
    a2[14]);
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
      a2[143]);
    v87 = 12;
LABEL_54:
    *((_DWORD *)a2 + 28) = v87;
    goto LABEL_108;
  }
  if ( !a2[116] )
  {
    if ( v54 && *v54 && (v150 = *(_QWORD *)(*v54 + 72LL)) != 0 )
    {
      v151 = *(_DWORD **)(v150 + 120);
      if ( v151 )
      {
        v152 = a2[143];
        if ( *(v151 - 1) != -187609570 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, __int64, unsigned __int8 *))v151)(v54, v152, a2);
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
    v165 = wma_create_peer((__int64)a1, a2 + 9, (__int64)a2, 2u, a2[143], 0, 0, v45, v46, v47, v48, v49, v50, v51, v52);
    if ( v165 )
    {
      v174 = v165;
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to create peer for %02x:%02x:%02x:**:**:%02x",
        v166,
        v167,
        v168,
        v169,
        v170,
        v171,
        v172,
        v173,
        "wma_add_tdls_sta",
        a2[9],
        a2[10],
        a2[11],
        a2[14]);
      *((_DWORD *)a2 + 28) = v174;
      goto LABEL_108;
    }
    v253 = (_DWORD *)_qdf_mem_malloc(0x444u, "wma_add_tdls_sta", 5554);
    if ( !v253 )
    {
      v87 = 2;
      goto LABEL_54;
    }
    v253[3] = 0;
    v254 = v253;
    *v253 = a2[143];
    qdf_mem_copy(v253 + 1, a2 + 9, 6u);
    result = wma_update_tdls_peer_state(a1, v254);
    if ( (*(_BYTE *)(a1[3] + 23LL) & 0x10) != 0 )
      goto LABEL_161;
  }
  v88 = wmi_service_enabled(*a1, 0x68u, v45, v46, v47, v48, v49, v50, v51, v52);
  if ( (v88 & 1) != 0 )
  {
    if ( !wma_fill_hold_req(a1, a2[143], 0x1021u, 1u, nullptr, (__int64)a2, 0xFA0u) )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to alloc request for vdev_id %d",
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        "wma_add_tdls_sta",
        a2[143]);
      v105 = a2[143];
      *((_DWORD *)a2 + 28) = 16;
      wma_remove_req((__int64)a1, v105, 1u, v106, v107, v108, v109, v110, v111, v112, v113);
      wma_remove_peer(a1, a2 + 9, a2[143], 0, v114, v115, v116, v117, v118, v119, v120, v121);
      goto LABEL_108;
    }
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: WMI_SERVICE_PEER_ASSOC_CONF not enabled",
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      "wma_add_tdls_sta");
  }
  if ( a2[117] )
    wma_set_peer_pmf_status(a1, a2 + 9);
  result = ((__int64 (__fastcall *)(_QWORD *, _QWORD, unsigned __int8 *))wma_send_peer_assoc)(
             a1,
             *((unsigned int *)a2 + 39),
             a2);
  if ( (_DWORD)result )
  {
    v153 = a2[143];
    *((_DWORD *)a2 + 28) = 16;
    wma_remove_peer(a1, a2 + 9, v153, 0, v45, v46, v47, v48, v49, v50, v51, v52);
    if ( v54 && *v54 && (v162 = *(_QWORD *)(*v54 + 72LL)) != 0 )
    {
      v163 = *(_DWORD **)(v162 + 128);
      if ( v163 )
      {
        v164 = a2[143];
        if ( *(v163 - 1) != 1944199495 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v163)(v54, 0, v164);
      }
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        1u,
        "%s invalid instance",
        v154,
        v155,
        v156,
        v157,
        v158,
        v159,
        v160,
        v161,
        "cdp_peer_add_last_real_peer");
    }
    wma_remove_req((__int64)a1, a2[143], 1u, v154, v155, v156, v157, v158, v159, v160, v161);
    goto LABEL_108;
  }
  if ( (v88 & 1) == 0 )
  {
LABEL_108:
    v193 = a2[8];
    v194 = a2[143];
    v195 = *((unsigned __int16 *)a2 + 3);
    if ( a2 )
    {
      v196 = *a2;
      v197 = a2[1];
      v198 = a2[2];
      v199 = a2[5];
    }
    else
    {
      v198 = 0;
      v196 = 0;
      v197 = 0;
      v199 = 0;
    }
    v200 = *((_DWORD *)a2 + 28);
    v201 = "wma_add_tdls_sta";
LABEL_159:
    LODWORD(v566) = v200;
    LODWORD(v565) = v199;
    LODWORD(v564) = v198;
    LODWORD(v563) = v197;
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
      v201,
      v193,
      v194,
      v195,
      v196,
      v563,
      v564,
      v565,
      v566);
LABEL_160:
    result = wma_send_msg_high_priority(a1, 4130, a2, 0);
  }
LABEL_161:
  v67 = 1;
LABEL_162:
  v273 = *((unsigned __int16 *)a1 + 81);
  if ( v273 <= v12 )
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
      goto LABEL_166;
    goto LABEL_174;
  }
  v274 = a1[65] + 488LL * v12;
  if ( *(_DWORD *)(v274 + 164) != 1 || *(_DWORD *)(v274 + 168) )
  {
    if ( v273 > v12 )
    {
LABEL_166:
      v275 = a1[65] + 488LL * v12;
      if ( *(_DWORD *)(v275 + 164) == 1 && *(_DWORD *)(v275 + 168) == 3 )
      {
        if ( (wlan_pmo_get_go_mode_bus_suspend(a1[3]) & 1) != 0
          && (wmi_service_enabled(*a1, 0xE8u, v276, v277, v278, v279, v280, v281, v282, v283) & 1) != 0 )
        {
          qdf_trace_msg(0x31u, 4u, "%s: p2p go d3 wow", v284, v285, v286, v287, v288, v289, v290, v291, "wma_add_sta");
          _X8 = (unsigned int *)a1 + 995;
          __asm { PRFM            #0x11, [X8] }
          do
          {
            v557 = __ldxr(_X8);
            v558 = v557 + 1;
          }
          while ( __stlxr(v558, _X8) );
          __dmb(0xBu);
          qdf_trace_msg(
            0x31u,
            8u,
            "%s: go d3 wow %d client connected",
            v292,
            v293,
            v294,
            v295,
            v296,
            v297,
            v298,
            v299,
            "wma_go_d3_wow_client_connect",
            v558);
          if ( v558 == 9 )
          {
            qdf_trace_msg(
              0x31u,
              4u,
              "%s: max clients connected acquire go d3 wow wake lock",
              v301,
              v302,
              v303,
              v304,
              v305,
              v306,
              v307,
              v308,
              "wma_go_d3_wow_client_connect");
            qdf_wake_lock_acquire((__int64)(a1 + 523), 0x1Cu);
          }
        }
        else
        {
          htc_vote_link_up(v22, 2);
          qdf_trace_msg(0x31u, 4u, "%s: p2p go d0 wow", v343, v344, v345, v346, v347, v348, v349, v350, "wma_add_sta");
        }
LABEL_188:
        v310 = a1 + 417;
        goto LABEL_189;
      }
      goto LABEL_175;
    }
LABEL_174:
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
LABEL_175:
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
      v310 = a1 + 418;
LABEL_189:
      result = qdf_runtime_pm_prevent_suspend(v310);
      goto LABEL_190;
    }
    goto LABEL_190;
  }
  if ( (wlan_pmo_get_sap_mode_bus_suspend(a1[3]) & 1) != 0
    && (wmi_service_enabled(*a1, 0xE7u, v311, v312, v313, v314, v315, v316, v317, v318) & 1) != 0 )
  {
    qdf_trace_msg(0x31u, 8u, "%s: sap d3 wow", v319, v320, v321, v322, v323, v324, v325, v326, "wma_add_sta");
    _X8 = (unsigned int *)(a1 + 497);
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v561 = __ldxr(_X8);
      v562 = v561 + 1;
    }
    while ( __stlxr(v562, _X8) );
    __dmb(0xBu);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: sap d3 wow %d client connected",
      v327,
      v328,
      v329,
      v330,
      v331,
      v332,
      v333,
      v334,
      "wma_sap_d3_wow_client_connect",
      v562);
    if ( v562 == 9 )
    {
      qdf_trace_msg(
        0x31u,
        4u,
        "%s: max clients connected acquire sap d3 wow wake lock",
        v335,
        v336,
        v337,
        v338,
        v339,
        v340,
        v341,
        v342,
        "wma_sap_d3_wow_client_connect");
      qdf_wake_lock_acquire((__int64)(a1 + 498), 0x1Bu);
    }
  }
  else
  {
    htc_vote_link_up(v22, 1);
    qdf_trace_msg(0x31u, 4u, "%s: sap d0 wow", v351, v352, v353, v354, v355, v356, v357, v358, "wma_add_sta");
  }
  result = policy_mgr_is_vdev_ll_lt_sap(a1[3], v12);
  if ( (result & 1) == 0 )
    goto LABEL_188;
LABEL_190:
  _ReadStatusReg(SP_EL0);
  return result;
}
