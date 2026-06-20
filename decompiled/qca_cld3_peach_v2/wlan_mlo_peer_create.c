__int64 __fastcall wlan_mlo_peer_create(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        __int64 a4,
        __int16 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x22
  int v14; // w8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x4
  __int64 v29; // x5
  const char *v30; // x2
  __int64 result; // x0
  __int64 v32; // x25
  __int64 v33; // x24
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x20
  char v44; // w9
  unsigned __int16 v45; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int v54; // w9
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned int *v71; // x8
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned int *v80; // x8
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  unsigned int *v97; // x8
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  unsigned int *v106; // x8
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  __int64 *v123; // x28
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  unsigned int *v132; // x8
  __int64 mlpeer; // x0
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  unsigned int aid; // w0
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  unsigned int v151; // w19
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  unsigned int *v160; // x8
  double v161; // d0
  double v162; // d1
  double v163; // d2
  double v164; // d3
  double v165; // d4
  double v166; // d5
  double v167; // d6
  double v168; // d7
  unsigned int v169; // w0
  double v170; // d0
  double v171; // d1
  double v172; // d2
  double v173; // d3
  double v174; // d4
  double v175; // d5
  double v176; // d6
  double v177; // d7
  unsigned int v178; // w19
  __int64 v179; // x5
  __int64 v180; // x6
  __int64 v181; // x7
  int v182; // w8
  __int64 v183; // x24
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  double v192; // d0
  double v193; // d1
  double v194; // d2
  double v195; // d3
  double v196; // d4
  double v197; // d5
  double v198; // d6
  double v199; // d7
  unsigned int *v200; // x8
  double v201; // d0
  double v202; // d1
  double v203; // d2
  double v204; // d3
  double v205; // d4
  double v206; // d5
  double v207; // d6
  double v208; // d7
  __int64 v209; // x25
  double v210; // d0
  double v211; // d1
  double v212; // d2
  double v213; // d3
  double v214; // d4
  double v215; // d5
  double v216; // d6
  double v217; // d7
  unsigned int *v218; // x8
  double v219; // d0
  double v220; // d1
  double v221; // d2
  double v222; // d3
  double v223; // d4
  double v224; // d5
  double v225; // d6
  double v226; // d7
  double v227; // d0
  double v228; // d1
  double v229; // d2
  double v230; // d3
  double v231; // d4
  double v232; // d5
  double v233; // d6
  double v234; // d7
  unsigned int *v235; // x8
  double v236; // d0
  double v237; // d1
  double v238; // d2
  double v239; // d3
  double v240; // d4
  double v241; // d5
  double v242; // d6
  double v243; // d7
  unsigned int *v244; // x8
  double v245; // d0
  double v246; // d1
  double v247; // d2
  double v248; // d3
  double v249; // d4
  double v250; // d5
  double v251; // d6
  double v252; // d7
  int v253; // w8
  double v254; // d0
  double v255; // d1
  double v256; // d2
  double v257; // d3
  double v258; // d4
  double v259; // d5
  double v260; // d6
  double v261; // d7
  __int64 v262; // x5
  __int64 v263; // x6
  __int64 v264; // x7
  int v265; // w8
  char v266; // w8
  unsigned int v267; // w0
  unsigned int v268; // w21
  __int64 v269; // x5
  __int64 v270; // x6
  __int64 v271; // x7
  int v272; // w8
  __int64 *v273; // x8
  char v274; // w9
  const char *v275; // x2
  __int64 v276; // x24
  char v277; // w27
  __int64 v278; // x0
  double v279; // d0
  double v280; // d1
  double v281; // d2
  double v282; // d3
  double v283; // d4
  double v284; // d5
  double v285; // d6
  double v286; // d7
  int v287; // w8
  int v288; // w9
  unsigned __int8 *v289; // x10
  __int16 v290; // w9
  double v291; // d0
  double v292; // d1
  double v293; // d2
  double v294; // d3
  double v295; // d4
  double v296; // d5
  double v297; // d6
  double v298; // d7
  __int64 v299; // x0
  double v300; // d0
  double v301; // d1
  double v302; // d2
  double v303; // d3
  double v304; // d4
  double v305; // d5
  double v306; // d6
  double v307; // d7
  unsigned int *v308; // x8
  __int64 v309; // x0
  double v310; // d0
  double v311; // d1
  double v312; // d2
  double v313; // d3
  double v314; // d4
  double v315; // d5
  double v316; // d6
  double v317; // d7
  unsigned int *v318; // x8
  unsigned int v321; // w9
  unsigned int v324; // w8
  unsigned int v327; // w8
  __int64 v328; // x4
  int v329; // w8
  __int64 v330; // x5
  __int64 v331; // x6
  __int64 v332; // x7
  __int64 v333; // x5
  __int64 v334; // x6
  __int64 v335; // x7
  int v336; // w8
  double v337; // d0
  double v338; // d1
  double v339; // d2
  double v340; // d3
  double v341; // d4
  double v342; // d5
  double v343; // d6
  double v344; // d7
  unsigned int *v345; // x8
  double v346; // d0
  double v347; // d1
  double v348; // d2
  double v349; // d3
  double v350; // d4
  double v351; // d5
  double v352; // d6
  double v353; // d7
  double v354; // d0
  double v355; // d1
  double v356; // d2
  double v357; // d3
  double v358; // d4
  double v359; // d5
  double v360; // d6
  double v361; // d7
  unsigned int *v362; // x8
  double v363; // d0
  double v364; // d1
  double v365; // d2
  double v366; // d3
  double v367; // d4
  double v368; // d5
  double v369; // d6
  double v370; // d7
  double v371; // d0
  double v372; // d1
  double v373; // d2
  double v374; // d3
  double v375; // d4
  double v376; // d5
  double v377; // d6
  double v378; // d7
  int v379; // w8
  __int64 v380; // x0
  __int64 v381; // x8
  __int64 v382; // x8
  __int64 v383; // x2
  unsigned int v386; // w9
  unsigned int v393; // w9
  __int64 v394; // [xsp+0h] [xbp-70h]
  __int64 v395; // [xsp+8h] [xbp-68h]
  __int64 v396[2]; // [xsp+28h] [xbp-48h] BYREF
  __int64 v397; // [xsp+38h] [xbp-38h]
  __int64 v398; // [xsp+40h] [xbp-30h]
  __int64 v399; // [xsp+48h] [xbp-28h] BYREF
  __int64 v400; // [xsp+50h] [xbp-20h]
  __int64 v401; // [xsp+58h] [xbp-18h] BYREF
  __int64 v402[2]; // [xsp+60h] [xbp-10h] BYREF

  v402[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a1 + 1360);
  v401 = 0;
  v402[0] = 0;
  v399 = 0;
  v400 = 0;
  if ( !v13 )
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: ML dev ctx is NULL", a6, a7, a8, a9, a10, a11, a12, a13, "wlan_mlo_peer_create");
    result = 29;
    goto LABEL_75;
  }
  v14 = *(_DWORD *)(a1 + 16);
  if ( v14 != 1 )
  {
    v32 = 0;
    v33 = 0;
    if ( v14 )
      goto LABEL_7;
    goto LABEL_54;
  }
  if ( wlan_mlo_is_mld_ctx_exist(a2 + 792) )
  {
    v28 = *(unsigned __int8 *)(v13 + 16);
    v29 = a2[792];
    v30 = "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x is matching with one of the MLD address in the system";
LABEL_19:
    LODWORD(v394) = a2[797];
    qdf_trace_msg(
      0x8Fu,
      2u,
      v30,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlan_mlo_peer_create",
      v28,
      v29,
      a2[793],
      a2[794],
      v394);
LABEL_20:
    result = 16;
    goto LABEL_75;
  }
  if ( *a3 >= 2u )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x exceeds MAX assoc limit of %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wlan_mlo_peer_create",
      *(unsigned __int8 *)(v13 + 16),
      a2[792],
      a2[793],
      a2[794],
      a2[797],
      1);
    if ( !*(_DWORD *)(*(_QWORD *)(v13 + 2232) + 200LL) )
    {
LABEL_30:
      result = 1;
      goto LABEL_75;
    }
  }
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, unsigned __int8 *, __int64 *))wlan_mlo_dev_get_link_vdevs)(
                       a1,
                       v13,
                       a3,
                       &v401) )
  {
    v28 = *(unsigned __int8 *)(v13 + 16);
    v29 = a2[792];
    v30 = "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x get link vdevs failed";
    goto LABEL_19;
  }
  v33 = v401;
  if ( v401 )
  {
    if ( (unsigned int)wlan_vdev_is_mlo_peer_create_allowed(v401, v20, v21, v22, v23, v24, v25, v26, v27) )
    {
LABEL_43:
      wlan_mlo_dev_release_link_vdevs(&v401, v106, v107, v108, v109, v110, v111, v112, v113, v114);
      LODWORD(v395) = *(unsigned __int8 *)(v33 + 168);
      LODWORD(v394) = a2[797];
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x create not allowed on link vdev %d",
        v124,
        v125,
        v126,
        v127,
        v128,
        v129,
        v130,
        v131,
        "wlan_mlo_peer_create",
        *(unsigned __int8 *)(v13 + 16),
        a2[792],
        a2[793],
        a2[794],
        v394,
        v395);
      result = 4;
      goto LABEL_75;
    }
  }
  else
  {
    qdf_trace_msg(0x8Fu, 8u, "%s: vdev_link is null", v20, v21, v22, v23, v24, v25, v26, v27, "wlan_mlo_peer_create");
  }
  v32 = v402[0];
  if ( v402[0] )
  {
    if ( (unsigned int)wlan_vdev_is_mlo_peer_create_allowed(v402[0], v107, v108, v109, v110, v111, v112, v113, v114) )
    {
      v33 = v32;
      goto LABEL_43;
    }
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: vdev_link is null",
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      "wlan_mlo_peer_create");
  }
  if ( v33 )
  {
    if ( v33 != a1 && *(unsigned __int16 *)(v33 + 224) > (unsigned int)*(unsigned __int16 *)(v33 + 232) )
    {
      LODWORD(v395) = *(unsigned __int8 *)(v33 + 168);
      LODWORD(v394) = a2[797];
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x Max peer count reached on link vdev %d",
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        "wlan_mlo_peer_create",
        *(unsigned __int8 *)(v13 + 16),
        a2[792],
        a2[793],
        a2[794],
        v394,
        v395);
      v132 = (unsigned int *)*(unsigned int *)(*(_QWORD *)(v13 + 2232) + 200LL);
      if ( !(_DWORD)v132 )
        goto LABEL_84;
    }
  }
  if ( v32 )
  {
    if ( v32 != a1 && *(unsigned __int16 *)(v32 + 224) > (unsigned int)*(unsigned __int16 *)(v32 + 232) )
    {
      LODWORD(v395) = *(unsigned __int8 *)(v32 + 168);
      LODWORD(v394) = a2[797];
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x Max peer count reached on link vdev %d",
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        "wlan_mlo_peer_create",
        *(unsigned __int8 *)(v13 + 16),
        a2[792],
        a2[793],
        a2[794],
        v394,
        v395);
      v132 = (unsigned int *)*(unsigned int *)(*(_QWORD *)(v13 + 2232) + 200LL);
      if ( !(_DWORD)v132 )
      {
LABEL_84:
        wlan_mlo_dev_release_link_vdevs(&v401, v132, v107, v108, v109, v110, v111, v112, v113, v114);
        result = 1;
        goto LABEL_75;
      }
    }
  }
  if ( !*(_DWORD *)(a1 + 16) )
  {
LABEL_54:
    mlpeer = wlan_mlo_get_mlpeer(v13, a2 + 792);
    if ( mlpeer )
    {
      v43 = mlpeer;
      LODWORD(v394) = *(_DWORD *)(mlpeer + 200);
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: ML Peer %02x:%02x:%02x:**:**:%02x existed, state %d",
        v134,
        v135,
        v136,
        v137,
        v138,
        v139,
        v140,
        v141,
        "wlan_mlo_peer_create",
        *(unsigned __int8 *)(mlpeer + 104),
        *(unsigned __int8 *)(mlpeer + 105),
        *(unsigned __int8 *)(mlpeer + 106),
        *(unsigned __int8 *)(mlpeer + 109),
        v394);
      *(_DWORD *)(v43 + 200) = 0;
      LODWORD(v123) = 1;
      *(_BYTE *)(v43 + 97) = *a3;
      *(_DWORD *)(v43 + 212) = *((_DWORD *)a3 + 38);
      goto LABEL_59;
    }
  }
LABEL_7:
  v34 = _qdf_mem_malloc(0x388u, "wlan_mlo_peer_create", 1684);
  if ( !v34 )
  {
    LODWORD(v394) = a2[797];
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x mem alloc failed",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "wlan_mlo_peer_create",
      *(unsigned __int8 *)(v13 + 16),
      a2[792],
      a2[793],
      a2[794],
      v394);
    if ( v33 )
    {
      wlan_objmgr_vdev_release_ref(v33, 0x5Au, v80, v81, v82, v83, v84, v85, v86, v87, v88);
      v32 = v402[0];
    }
    if ( v32 )
      wlan_objmgr_vdev_release_ref(v32, 0x5Au, v80, v81, v82, v83, v84, v85, v86, v87, v88);
    result = 2;
    goto LABEL_75;
  }
  v43 = v34;
  *(_DWORD *)(v34 + 188) = 0;
  qdf_mutex_create(v34 + 120);
  *(_QWORD *)(v43 + 192) = v13;
  *(_DWORD *)(v43 + 200) = 0;
  v44 = *a3;
  *(_BYTE *)(v43 + 186) = -1;
  *(_WORD *)(v43 + 652) = 255;
  *(_BYTE *)(v43 + 97) = v44;
  v45 = mlo_ap_ml_peerid_alloc();
  *(_DWORD *)(v43 + 100) = v45;
  if ( v45 == 0xFFFF )
  {
    LODWORD(v394) = *(unsigned __int8 *)(v43 + 109);
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x invalid ml peer id",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "wlan_mlo_peer_create",
      *(unsigned __int8 *)(v13 + 16),
      *(unsigned __int8 *)(v43 + 104),
      *(unsigned __int8 *)(v43 + 105),
      *(unsigned __int8 *)(v43 + 106),
      v394);
    mlo_peer_free(v43, v89, v90, v91, v92, v93, v94, v95, v96);
    if ( v33 )
    {
      wlan_objmgr_vdev_release_ref(v33, 0x5Au, v97, v98, v99, v100, v101, v102, v103, v104, v105);
      v32 = v402[0];
    }
    if ( v32 )
    {
      wlan_objmgr_vdev_release_ref(v32, 0x5Au, v97, v98, v99, v100, v101, v102, v103, v104, v105);
      result = 1;
      goto LABEL_75;
    }
    goto LABEL_30;
  }
  v54 = *((_DWORD *)a2 + 198);
  *(_WORD *)(v43 + 108) = *((_WORD *)a2 + 398);
  *(_DWORD *)(v43 + 104) = v54;
  *(_DWORD *)(v43 + 212) = *((_DWORD *)a3 + 38);
  if ( !(unsigned int)ttlm_sm_create(v43) )
  {
    qdf_mutex_create(v43 + 552);
    *(_DWORD *)(v43 + 616) = 0;
    *(_BYTE *)(v43 + 620) = 0;
    if ( *(_DWORD *)(a1 + 16) == 1 )
    {
      if ( a5 != -1 )
      {
        LODWORD(v123) = 0;
        *(_WORD *)(v43 + 184) = a5;
        goto LABEL_59;
      }
      aid = mlo_peer_allocate_aid(v13, v43, v115, v116, v117, v118, v119, v120, v121, v122);
      if ( aid )
      {
        v151 = aid;
        LODWORD(v394) = *(unsigned __int8 *)(v43 + 109);
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x aid alloc failed",
          v143,
          v144,
          v145,
          v146,
          v147,
          v148,
          v149,
          v150,
          "wlan_mlo_peer_create",
          *(unsigned __int8 *)(v13 + 16),
          *(unsigned __int8 *)(v43 + 104),
          *(unsigned __int8 *)(v43 + 105),
          *(unsigned __int8 *)(v43 + 106),
          v394);
        mlo_peer_free(v43, v152, v153, v154, v155, v156, v157, v158, v159);
        wlan_mlo_dev_release_link_vdevs(&v401, v160, v161, v162, v163, v164, v165, v166, v167, v168);
        result = v151;
        goto LABEL_75;
      }
    }
    LODWORD(v123) = 0;
LABEL_59:
    v169 = mlo_peer_attach_link_peer(v43, a2, 0);
    if ( v169 )
    {
      v178 = v169;
      if ( v43 == -104 )
      {
        v181 = 0;
        v179 = 0;
        v180 = 0;
        v182 = 0;
      }
      else
      {
        v179 = *(unsigned __int8 *)(v43 + 104);
        v180 = *(unsigned __int8 *)(v43 + 105);
        v181 = *(unsigned __int8 *)(v43 + 106);
        v182 = *(unsigned __int8 *)(v43 + 109);
      }
      LODWORD(v394) = v182;
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x link peer attach failed",
        v170,
        v171,
        v172,
        v173,
        v174,
        v175,
        v176,
        v177,
        "wlan_mlo_peer_create",
        *(unsigned __int8 *)(v13 + 16),
        v179,
        v180,
        v181,
        v394);
      if ( (_DWORD)v123 )
      {
        if ( *(_BYTE *)(v43 + 96) )
        {
LABEL_74:
          result = v178;
          goto LABEL_75;
        }
        mlo_dev_mlpeer_detach(v13, v43);
      }
      mlo_peer_free(v43, v192, v193, v194, v195, v196, v197, v198, v199);
      if ( v401 )
        wlan_objmgr_vdev_release_ref(v401, 0x5Au, v200, v201, v202, v203, v204, v205, v206, v207, v208);
      if ( v402[0] )
        wlan_objmgr_vdev_release_ref(v402[0], 0x5Au, v200, v201, v202, v203, v204, v205, v206, v207, v208);
      goto LABEL_74;
    }
    if ( *(_DWORD *)(a1 + 16) == 1 )
    {
      v183 = v401;
      if ( v401 )
      {
        if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(v401, 0x5Au, v170, v171, v172, v173, v174, v175, v176, v177) )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: VDEV is not in created state",
            v184,
            v185,
            v186,
            v187,
            v188,
            v189,
            v190,
            v191,
            "wlan_mlo_peer_create");
LABEL_82:
          mlo_reset_link_peer(v43, a2);
          v227 = mlo_peer_detach_link_peer(v43, a2);
          mlo_peer_free(v43, v227, v228, v229, v230, v231, v232, v233, v234);
          wlan_mlo_dev_release_link_vdevs(&v401, v235, v236, v237, v238, v239, v240, v241, v242, v243);
          goto LABEL_20;
        }
        v399 = v183;
      }
      else
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: vdev_link is null",
          v170,
          v171,
          v172,
          v173,
          v174,
          v175,
          v176,
          v177,
          "wlan_mlo_peer_create");
      }
      v209 = v402[0];
      if ( v402[0] )
      {
        if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(v402[0], 0x5Au, v184, v185, v186, v187, v188, v189, v190, v191) )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: VDEV is not in created state",
            v210,
            v211,
            v212,
            v213,
            v214,
            v215,
            v216,
            v217,
            "wlan_mlo_peer_create");
          if ( v183 )
            wlan_objmgr_vdev_release_ref(v183, 0x5Au, v218, v219, v220, v221, v222, v223, v224, v225, v226);
          goto LABEL_82;
        }
        v400 = v209;
      }
      else
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: vdev_link is null",
          v184,
          v185,
          v186,
          v187,
          v188,
          v189,
          v190,
          v191,
          "wlan_mlo_peer_create");
      }
      if ( *(_DWORD *)(a1 + 16) == 1 )
      {
        v244 = (unsigned int *)*(unsigned int *)(*(_QWORD *)(v13 + 2232) + 200LL);
        if ( (_DWORD)v244
          || (mlo_peer_allocate_primary_umac(v13, v43, &v399),
              v244 = (unsigned int *)*(unsigned int *)(a1 + 16),
              (_DWORD)v244 == 1) )
        {
          if ( v399 )
            wlan_objmgr_vdev_release_ref(v399, 0x5Au, v244, v210, v211, v212, v213, v214, v215, v216, v217);
          if ( v400 )
            wlan_objmgr_vdev_release_ref(v400, 0x5Au, v244, v210, v211, v212, v213, v214, v215, v216, v217);
        }
      }
    }
    qdf_mutex_acquire(v43 + 120);
    while ( 2 )
    {
      _X8 = (unsigned int *)(v43 + 188);
      __asm { PRFM            #0x11, [X8] }
      do
        v386 = __ldxr(_X8);
      while ( __stxr(v386 + 1, _X8) );
      *((_QWORD *)a2 + 98) = v43;
      qdf_mutex_release(v43 + 120);
      v253 = *(_DWORD *)(a1 + 16);
      if ( v253 == 1 )
      {
        if ( (mlo_mgr_ml_peer_exist_on_diff_ml_ctx(a2 + 792, nullptr) & 1) != 0 )
        {
          if ( v43 == -104 )
          {
            v264 = 0;
            v262 = 0;
            v263 = 0;
            v265 = 0;
          }
          else
          {
            v262 = *(unsigned __int8 *)(v43 + 104);
            v263 = *(unsigned __int8 *)(v43 + 105);
            v264 = *(unsigned __int8 *)(v43 + 106);
            v265 = *(unsigned __int8 *)(v43 + 109);
          }
          LODWORD(v394) = v265;
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x is exists, creation failed",
            v254,
            v255,
            v256,
            v257,
            v258,
            v259,
            v260,
            v261,
            "wlan_mlo_peer_create",
            *(unsigned __int8 *)(v13 + 16),
            v262,
            v263,
            v264,
            v394);
          mlo_reset_link_peer(v43, a2);
          v354 = mlo_peer_detach_link_peer(v43, a2);
          mlo_peer_free(v43, v354, v355, v356, v357, v358, v359, v360, v361);
          wlan_mlo_dev_release_link_vdevs(&v401, v362, v363, v364, v365, v366, v367, v368, v369, v370);
          result = 14;
          goto LABEL_75;
        }
      }
      else
      {
        if ( v253 )
          v266 = 1;
        else
          v266 = (char)v123;
        if ( (v266 & 1) != 0 )
          goto LABEL_105;
      }
      v267 = mlo_dev_mlpeer_attach(v13, v43);
      if ( v267 )
      {
        v268 = v267;
        if ( v43 == -104 )
        {
          v271 = 0;
          v269 = 0;
          v270 = 0;
          v272 = 0;
        }
        else
        {
          v269 = *(unsigned __int8 *)(v43 + 104);
          v270 = *(unsigned __int8 *)(v43 + 105);
          v271 = *(unsigned __int8 *)(v43 + 106);
          v272 = *(unsigned __int8 *)(v43 + 109);
        }
        LODWORD(v394) = v272;
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x attach failed",
          v245,
          v246,
          v247,
          v248,
          v249,
          v250,
          v251,
          v252,
          "wlan_mlo_peer_create",
          *(unsigned __int8 *)(v13 + 16),
          v269,
          v270,
          v271,
          v394);
        qdf_mutex_acquire(v43 + 120);
        v336 = *((_DWORD *)a2 + 16);
        *((_QWORD *)a2 + 98) = 0;
        *((_DWORD *)a2 + 16) = v336 & 0xFFFFFFFE;
        qdf_mutex_release(v43 + 120);
        v337 = mlo_peer_detach_link_peer(v43, a2);
        mlo_peer_free(v43, v337, v338, v339, v340, v341, v342, v343, v344);
        if ( v401 )
          wlan_objmgr_vdev_release_ref(v401, 0x5Au, v345, v346, v347, v348, v349, v350, v351, v352, v353);
        if ( v402[0] )
          wlan_objmgr_vdev_release_ref(v402[0], 0x5Au, v345, v346, v347, v348, v349, v350, v351, v352, v353);
        result = v268;
        goto LABEL_75;
      }
LABEL_105:
      _X8 = (unsigned int *)(v43 + 188);
      __asm { PRFM            #0x11, [X8] }
      do
        v393 = __ldxr(_X8);
      while ( __stxr(v393 + 1, _X8) );
      v273 = (__int64 *)*(unsigned int *)(a1 + 16);
      if ( (_DWORD)v273 == 1 )
      {
        v273 = &v401;
        v123 = v402;
        v274 = 1;
        while ( 1 )
        {
          v276 = *v273;
          v277 = v274;
          if ( !*v273 || v276 == a1 )
            goto LABEL_110;
          v278 = *v273;
          v397 = 0;
          v398 = 0;
          if ( !(unsigned int)wlan_objmgr_vdev_try_get_ref(v278, 0x5Au, v245, v246, v247, v248, v249, v250, v251, v252) )
            break;
          v275 = "%s: VDEV is not in created state";
LABEL_109:
          qdf_trace_msg(0x8Fu, 2u, v275, v279, v280, v281, v282, v283, v284, v285, v286, "mlo_partner_peer_create_post");
LABEL_110:
          v274 = 0;
          v273 = v402;
          if ( (v277 & 1) == 0 )
            goto LABEL_146;
        }
        v396[0] = v276;
        _X8 = (unsigned int *)(v43 + 188);
        __asm { PRFM            #0x11, [X8] }
        do
          v321 = __ldxr(_X8);
        while ( __stxr(v321 + 1, _X8) );
        v287 = *a3;
        v396[1] = v43;
        if ( v287 )
        {
          v288 = *(unsigned __int8 *)(v276 + 93);
          v289 = a3 + 8;
          if ( v288 != a3[14] )
          {
            if ( v287 == 1 )
              goto LABEL_119;
            v289 = a3 + 56;
            if ( v288 != a3[62] )
            {
              if ( v287 == 2 )
                goto LABEL_119;
              v289 = a3 + 104;
              if ( v288 != a3[110] )
              {
                if ( v287 != 3 )
                {
                  __break(0x5512u);
                  continue;
                }
                goto LABEL_119;
              }
            }
          }
          v290 = *((_WORD *)v289 + 2);
          LODWORD(v397) = *(_DWORD *)v289;
          WORD2(v397) = v290;
        }
LABEL_119:
        if ( !(unsigned int)mlo_peer_create_get_frm_buf(v43, (__int64)v396, a4) )
        {
          if ( (unsigned int)mlo_msgq_post(0, v13, v396) )
          {
            if ( a4 )
              _qdf_nbuf_free(a4);
            _X9 = (unsigned int *)(v43 + 188);
            __asm { PRFM            #0x11, [X9] }
            do
            {
              v327 = __ldxr(_X9);
              v318 = (unsigned int *)(v327 - 1);
            }
            while ( __stlxr((unsigned int)v318, _X9) );
            __dmb(0xBu);
            if ( !(_DWORD)v318 )
            {
              v309 = *(_QWORD *)(v43 + 192);
              if ( v309 )
              {
                mlo_dev_mlpeer_detach(v309, v43);
                mlo_peer_free(v43, v310, v311, v312, v313, v314, v315, v316, v317);
              }
              else
              {
                qdf_trace_msg(
                  0x8Fu,
                  2u,
                  "%s: ML DEV is NULL",
                  v245,
                  v246,
                  v247,
                  v248,
                  v249,
                  v250,
                  v251,
                  v252,
                  "mlo_peer_cleanup");
              }
            }
            wlan_objmgr_vdev_release_ref(v276, 0x5Au, v318, v245, v246, v247, v248, v249, v250, v251, v252);
          }
          goto LABEL_110;
        }
        _X9 = (unsigned int *)(v43 + 188);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v324 = __ldxr(_X9);
          v308 = (unsigned int *)(v324 - 1);
        }
        while ( __stlxr((unsigned int)v308, _X9) );
        __dmb(0xBu);
        if ( !(_DWORD)v308 )
        {
          v299 = *(_QWORD *)(v43 + 192);
          if ( v299 )
          {
            mlo_dev_mlpeer_detach(v299, v43);
            mlo_peer_free(v43, v300, v301, v302, v303, v304, v305, v306, v307);
          }
          else
          {
            qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: ML DEV is NULL",
              v291,
              v292,
              v293,
              v294,
              v295,
              v296,
              v297,
              v298,
              "mlo_peer_cleanup");
          }
        }
        wlan_objmgr_vdev_release_ref(v276, 0x5Au, v308, v291, v292, v293, v294, v295, v296, v297, v298);
        v275 = "%s: nbuf clone is failed";
        goto LABEL_109;
      }
      break;
    }
LABEL_146:
    if ( v401 )
      wlan_objmgr_vdev_release_ref(v401, 0x5Au, (unsigned int *)v273, v245, v246, v247, v248, v249, v250, v251, v252);
    if ( v402[0] )
      wlan_objmgr_vdev_release_ref(v402[0], 0x5Au, (unsigned int *)v273, v245, v246, v247, v248, v249, v250, v251, v252);
    v328 = *(unsigned __int8 *)(v13 + 16);
    v329 = v43 + 104;
    if ( *(_DWORD *)(v43 + 200) == 2 )
    {
      if ( v43 == -104 )
      {
        v332 = 0;
        v330 = 0;
        v331 = 0;
      }
      else
      {
        v330 = *(unsigned __int8 *)(v43 + 104);
        v331 = *(unsigned __int8 *)(v43 + 105);
        v332 = *(unsigned __int8 *)(v43 + 106);
        v329 = *(unsigned __int8 *)(v43 + 109);
      }
      LODWORD(v394) = v329;
      qdf_trace_msg(
        0x8Fu,
        4u,
        "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x allocation failed",
        v245,
        v246,
        v247,
        v248,
        v249,
        v250,
        v251,
        v252,
        "wlan_mlo_peer_create",
        v328,
        v330,
        v331,
        v332,
        v394);
      wlan_mlo_peer_release_ref(v43);
      goto LABEL_20;
    }
    if ( v43 == -104 )
    {
      v335 = 0;
      v333 = 0;
      v334 = 0;
    }
    else
    {
      v333 = *(unsigned __int8 *)(v43 + 104);
      v334 = *(unsigned __int8 *)(v43 + 105);
      v335 = *(unsigned __int8 *)(v43 + 106);
      v329 = *(unsigned __int8 *)(v43 + 109);
    }
    LODWORD(v394) = v329;
    qdf_trace_msg(
      0x8Fu,
      4u,
      "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x allocated %pK",
      v245,
      v246,
      v247,
      v248,
      v249,
      v250,
      v251,
      v252,
      "wlan_mlo_peer_create",
      v328,
      v333,
      v334,
      v335,
      v394,
      v43);
    v379 = *(_DWORD *)(a1 + 16);
    if ( v379 == 1 )
    {
      if ( *(_BYTE *)(v43 + 97) != 1 || *(_BYTE *)(v43 + 96) != 1 || (v380 = *(_QWORD *)(v43 + 16)) == 0 )
      {
LABEL_173:
        v381 = *((_QWORD *)a2 + 12);
        if ( v381 && (v382 = *(_QWORD *)(v381 + 216)) != 0 )
          v383 = *(_QWORD *)(v382 + 80);
        else
          v383 = 0;
        wlan_minidump_log(v371, v372, v373, v374, v375, v376, v377, v378, v43, 904, v383);
        wlan_mlo_peer_release_ref(v43);
        result = 0;
        goto LABEL_75;
      }
      mlo_mlme_peer_assoc_resp(v380);
      v379 = *(_DWORD *)(a1 + 16);
    }
    if ( !v379 )
      wlan_clear_peer_level_tid_to_link_mapping(a1);
    goto LABEL_173;
  }
  qdf_trace_msg(
    0x8Fu,
    2u,
    "%s: TTLM state machine create failed",
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    "wlan_mlo_peer_create");
  mlo_peer_free(v43, v63, v64, v65, v66, v67, v68, v69, v70);
  if ( v33 )
  {
    wlan_objmgr_vdev_release_ref(v33, 0x5Au, v71, v72, v73, v74, v75, v76, v77, v78, v79);
    v32 = v402[0];
  }
  if ( v32 )
    wlan_objmgr_vdev_release_ref(v32, 0x5Au, v71, v72, v73, v74, v75, v76, v77, v78, v79);
  result = 4;
LABEL_75:
  _ReadStatusReg(SP_EL0);
  return result;
}
