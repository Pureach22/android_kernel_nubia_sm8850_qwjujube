__int64 __fastcall tgt_mc_cp_stats_process_stats_event(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  const char *v30; // x2
  unsigned int v31; // w1
  __int64 v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  const char *v41; // x2
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x8
  const char *v51; // x2
  unsigned int v52; // w1
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  int v61; // w8
  unsigned int v62; // w21
  const char *v63; // x2
  unsigned int v64; // w8
  _DWORD *v65; // x9
  int v66; // w10
  int v67; // w8
  void (__fastcall *v68)(__int64, __int64); // x8
  __int64 v69; // x1
  __int64 v70; // x0
  __int64 v71; // x21
  __int64 comp_private_obj; // x0
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x23
  unsigned __int64 StatusReg; // x8
  __int64 v83; // x8
  unsigned int v84; // w22
  unsigned int *v85; // x8
  __int64 v86; // x23
  __int64 v87; // x0
  unsigned int macid_by_vdev_id; // w22
  __int64 v89; // x24
  unsigned int v90; // w8
  unsigned __int8 *v91; // x9
  __int64 v92; // x4
  unsigned int v93; // w24
  void (__fastcall *v94)(__int64, __int64); // x8
  __int64 v95; // x1
  __int64 *v96; // x10
  _DWORD *v97; // x8
  int v98; // w9
  const char *v99; // x2
  __int64 *v100; // x9
  unsigned int v101; // w8
  _DWORD *v102; // x9
  __int64 *v103; // x10
  __int64 v104; // x8
  int v105; // w9
  __int64 *v106; // x9
  void (__fastcall *v107)(__int64 *, __int64); // x8
  __int64 v108; // x0
  unsigned __int8 *v109; // x8
  __int64 v110; // x0
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  __int64 v119; // x21
  __int64 v120; // x0
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  __int64 v129; // x22
  unsigned __int64 v130; // x8
  __int64 v131; // x8
  unsigned int *v132; // x8
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  __int64 v141; // x0
  __int64 v142; // x8
  void (__fastcall *v143)(_QWORD); // x8
  __int64 v145; // x0
  __int64 v146; // x23
  unsigned __int64 v147; // x8
  __int64 v148; // x8
  unsigned __int8 v149; // w10
  __int64 v150; // x0
  __int64 v151; // x21
  __int64 v152; // x0
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  __int64 v161; // x22
  unsigned __int64 v162; // x8
  __int64 v163; // x8
  __int64 peer; // x0
  double v165; // d0
  double v166; // d1
  double v167; // d2
  double v168; // d3
  double v169; // d4
  double v170; // d5
  double v171; // d6
  double v172; // d7
  __int64 v173; // x22
  __int64 v174; // x0
  double v175; // d0
  double v176; // d1
  double v177; // d2
  double v178; // d3
  double v179; // d4
  double v180; // d5
  double v181; // d6
  double v182; // d7
  __int64 v183; // x23
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
  int v200; // w8
  void (__fastcall *v201)(_QWORD, __int64); // x8
  __int64 v202; // x1
  unsigned int *v203; // x8
  double v204; // d0
  double v205; // d1
  double v206; // d2
  double v207; // d3
  double v208; // d4
  double v209; // d5
  double v210; // d6
  double v211; // d7
  __int64 v212; // x4
  __int64 v213; // x5
  __int64 v214; // x6
  __int64 v215; // x7
  __int64 v216; // x8
  double v217; // d0
  double v218; // d1
  double v219; // d2
  double v220; // d3
  double v221; // d4
  double v222; // d5
  double v223; // d6
  double v224; // d7
  const char *v225; // x2
  double v226; // d0
  double v227; // d1
  double v228; // d2
  double v229; // d3
  double v230; // d4
  double v231; // d5
  double v232; // d6
  double v233; // d7
  const char *v234; // x2
  __int64 v235; // x0
  __int64 v236; // x21
  __int64 v237; // x0
  double v238; // d0
  double v239; // d1
  double v240; // d2
  double v241; // d3
  double v242; // d4
  double v243; // d5
  double v244; // d6
  double v245; // d7
  __int64 v246; // x22
  unsigned __int64 v247; // x8
  __int64 v248; // x8
  __int64 v249; // x11
  __int64 v250; // x9
  __int64 v251; // x8
  unsigned int *v252; // x8
  double v253; // d0
  double v254; // d1
  double v255; // d2
  double v256; // d3
  double v257; // d4
  double v258; // d5
  double v259; // d6
  double v260; // d7
  unsigned int v261; // w8
  unsigned __int8 v262; // w9
  unsigned __int64 v263; // x23
  unsigned int *v264; // x8
  double v265; // d0
  double v266; // d1
  double v267; // d2
  double v268; // d3
  double v269; // d4
  double v270; // d5
  double v271; // d6
  double v272; // d7
  __int64 v273; // x24
  __int64 v274; // x0
  __int64 v275; // x21
  __int64 v276; // x0
  double v277; // d0
  double v278; // d1
  double v279; // d2
  double v280; // d3
  double v281; // d4
  double v282; // d5
  double v283; // d6
  double v284; // d7
  __int64 v285; // x22
  __int64 v286; // x10
  __int64 v287; // x8
  double v288; // d0
  double v289; // d1
  double v290; // d2
  double v291; // d3
  double v292; // d4
  double v293; // d5
  double v294; // d6
  double v295; // d7
  int v296; // w8
  unsigned __int8 v297; // w8
  unsigned __int64 v298; // x24
  unsigned int v299; // w25
  __int64 v300; // x0
  double v301; // d0
  double v302; // d1
  double v303; // d2
  double v304; // d3
  double v305; // d4
  double v306; // d5
  double v307; // d6
  double v308; // d7
  __int64 v309; // x21
  __int64 v310; // x0
  unsigned int *v311; // x8
  double v312; // d0
  double v313; // d1
  double v314; // d2
  double v315; // d3
  double v316; // d4
  double v317; // d5
  double v318; // d6
  double v319; // d7
  __int64 v320; // x22
  __int64 v321; // x8
  unsigned int *v322; // x8
  double v323; // d0
  double v324; // d1
  double v325; // d2
  double v326; // d3
  double v327; // d4
  double v328; // d5
  double v329; // d6
  double v330; // d7
  void (__fastcall *v331)(__int64 *, __int64); // x23
  void *v332; // x0
  __int64 v333; // x0
  double v334; // d0
  double v335; // d1
  double v336; // d2
  double v337; // d3
  double v338; // d4
  double v339; // d5
  double v340; // d6
  double v341; // d7
  __int64 v342; // x21
  __int64 v343; // x0
  double v344; // d0
  double v345; // d1
  double v346; // d2
  double v347; // d3
  double v348; // d4
  double v349; // d5
  double v350; // d6
  double v351; // d7
  __int64 v352; // x22
  unsigned __int64 v353; // x8
  __int64 v354; // x25
  __int64 v355; // x8
  __int64 v356; // x10
  __int64 v357; // x11
  __int64 v358; // x12
  __int64 v359; // x10
  __int64 v360; // x11
  __int64 v361; // x12
  __int64 v362; // x10
  __int64 v363; // x11
  __int64 v364; // x12
  __int64 v365; // x9
  __int64 v366; // x10
  __int64 v367; // x8
  unsigned int *v368; // x8
  double v369; // d0
  double v370; // d1
  double v371; // d2
  double v372; // d3
  double v373; // d4
  double v374; // d5
  double v375; // d6
  double v376; // d7
  __int64 v377; // x0
  double v378; // d0
  double v379; // d1
  double v380; // d2
  double v381; // d3
  double v382; // d4
  double v383; // d5
  double v384; // d6
  double v385; // d7
  __int64 v386; // x21
  __int64 v387; // x0
  double v388; // d0
  double v389; // d1
  double v390; // d2
  double v391; // d3
  double v392; // d4
  double v393; // d5
  double v394; // d6
  double v395; // d7
  __int64 v396; // x22
  unsigned __int64 v397; // x8
  __int64 v398; // x8
  __int64 v399; // x8
  double v400; // d0
  double v401; // d1
  double v402; // d2
  double v403; // d3
  double v404; // d4
  double v405; // d5
  double v406; // d6
  double v407; // d7
  double v408; // d0
  double v409; // d1
  double v410; // d2
  double v411; // d3
  double v412; // d4
  double v413; // d5
  double v414; // d6
  double v415; // d7
  const char *v416; // x2
  unsigned int *v417; // x8
  double v418; // d0
  double v419; // d1
  double v420; // d2
  double v421; // d3
  double v422; // d4
  double v423; // d5
  double v424; // d6
  double v425; // d7
  unsigned int *v426; // x8
  double v427; // d0
  double v428; // d1
  double v429; // d2
  double v430; // d3
  double v431; // d4
  double v432; // d5
  double v433; // d6
  double v434; // d7
  __int64 v435; // x1
  double v436; // d0
  double v437; // d1
  double v438; // d2
  double v439; // d3
  double v440; // d4
  double v441; // d5
  double v442; // d6
  double v443; // d7
  char v444[4]; // [xsp+Ch] [xbp-104h] BYREF
  __int64 v445; // [xsp+10h] [xbp-100h] BYREF
  void (__fastcall *v446)(__int64 *, __int64); // [xsp+18h] [xbp-F8h]
  __int64 v447; // [xsp+20h] [xbp-F0h]
  __int64 v448; // [xsp+28h] [xbp-E8h] BYREF
  __int64 v449; // [xsp+30h] [xbp-E0h] BYREF
  __int64 v450; // [xsp+38h] [xbp-D8h]
  __int64 v451; // [xsp+40h] [xbp-D0h]
  __int64 v452; // [xsp+48h] [xbp-C8h] BYREF
  __int64 v453; // [xsp+50h] [xbp-C0h]
  __int64 v454; // [xsp+58h] [xbp-B8h]
  __int64 v455; // [xsp+60h] [xbp-B0h]
  int v456[2]; // [xsp+68h] [xbp-A8h]
  __int64 v457; // [xsp+70h] [xbp-A0h]
  __int64 v458; // [xsp+78h] [xbp-98h]
  __int64 v459; // [xsp+80h] [xbp-90h]
  int v460; // [xsp+88h] [xbp-88h]
  int v461; // [xsp+8Ch] [xbp-84h]
  __int64 v462; // [xsp+90h] [xbp-80h]
  __int64 v463; // [xsp+98h] [xbp-78h]
  __int64 v464; // [xsp+A0h] [xbp-70h]
  int v465; // [xsp+A8h] [xbp-68h]
  int v466; // [xsp+ACh] [xbp-64h]
  _BYTE *v467; // [xsp+B0h] [xbp-60h]
  __int64 v468; // [xsp+B8h] [xbp-58h]
  __int64 v469; // [xsp+C0h] [xbp-50h]
  __int64 v470; // [xsp+C8h] [xbp-48h]
  __int64 v471; // [xsp+D0h] [xbp-40h]
  __int64 v472; // [xsp+D8h] [xbp-38h]
  __int64 v473; // [xsp+E0h] [xbp-30h]
  int v474; // [xsp+E8h] [xbp-28h]
  int v475; // [xsp+ECh] [xbp-24h]
  void *v476; // [xsp+F0h] [xbp-20h]
  __int64 v477; // [xsp+F8h] [xbp-18h]
  void *v478; // [xsp+100h] [xbp-10h]
  __int64 v479; // [xsp+108h] [xbp-8h]

  v479 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (ucfg_mc_cp_stats_is_req_pending(a1, 0) & 1) == 0 )
    goto LABEL_5;
  v451 = 0;
  v452 = 0;
  v449 = 0;
  v450 = 0;
  LOBYTE(v445) = 0;
  if ( (unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 0, &v449) )
  {
    v12 = "%s: ucfg_mc_cp_stats_get_pending_req failed";
LABEL_4:
    qdf_trace_msg(0x62u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "tgt_mc_cp_stats_extract_vdev_and_extd_stats");
    goto LABEL_5;
  }
  if ( *(_QWORD *)(a2 + 8) )
  {
    tgt_mc_cp_stats_extract_tx_power(a1, a2, 0);
  }
  else if ( *(_QWORD *)(a2 + 192) )
  {
    tgt_mc_cp_stats_extract_vdev_extd_stats(a1, a2);
  }
  v70 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          a1,
          (unsigned int)v451,
          38);
  if ( !v70 )
  {
    v12 = "%s: vdev is null";
    goto LABEL_4;
  }
  v71 = v70;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v70, 0x1Bu);
  if ( comp_private_obj )
  {
    v81 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 24);
      v83 = *(_QWORD *)(v81 + 32);
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 24);
      v83 = *(_QWORD *)(v81 + 32) | 1LL;
      *(_QWORD *)(v81 + 32) = v83;
    }
    v84 = *(_DWORD *)(*(_QWORD *)(v81 + 8) + 136LL);
    if ( (v83 & 1) != 0 )
    {
      *(_QWORD *)(v81 + 32) = v83 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v81 + 24);
      if ( v84 )
        goto LABEL_145;
    }
    else
    {
      raw_spin_unlock(v81 + 24);
      if ( v84 )
        goto LABEL_145;
    }
  }
  v86 = *(_QWORD *)(v71 + 152);
  if ( !v86 )
  {
    v99 = "%s: pdev is null";
LABEL_143:
    qdf_trace_msg(0x62u, 2u, v99, v73, v74, v75, v76, v77, v78, v79, v80, "tgt_mc_cp_stats_get_tx_power");
LABEL_144:
    v84 = 0;
    goto LABEL_145;
  }
  v87 = *(_QWORD *)(v86 + 80);
  if ( !v87 )
  {
    v99 = "%s: psoc is null";
    goto LABEL_143;
  }
  macid_by_vdev_id = policy_mgr_mode_get_macid_by_vdev_id(v87, *(unsigned __int8 *)(v71 + 104));
  if ( macid_by_vdev_id >= 2 )
  {
    v89 = jiffies;
    v85 = (unsigned int *)(tgt_mc_cp_stats_get_tx_power___last_ticks - jiffies);
    if ( tgt_mc_cp_stats_get_tx_power___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: invalid mac_id %d",
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        "tgt_mc_cp_stats_get_tx_power",
        macid_by_vdev_id);
      v84 = 0;
      tgt_mc_cp_stats_get_tx_power___last_ticks = v89;
      goto LABEL_145;
    }
    goto LABEL_144;
  }
  v145 = wlan_objmgr_pdev_get_comp_private_obj(v86, 0x1Bu);
  if ( !v145 )
  {
    v99 = "%s: pdev cp stats object is null";
    goto LABEL_143;
  }
  v146 = v145;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v147 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v147 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v147 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v145 + 24);
    v148 = *(_QWORD *)(v146 + 32);
  }
  else
  {
    raw_spin_lock_bh(v145 + 24);
    v148 = *(_QWORD *)(v146 + 32) | 1LL;
    *(_QWORD *)(v146 + 32) = v148;
  }
  v84 = *(_DWORD *)(*(_QWORD *)(v146 + 8) + 12672LL * macid_by_vdev_id);
  if ( (v148 & 1) != 0 )
  {
    *(_QWORD *)(v146 + 32) = v148 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v146 + 24);
  }
  else
  {
    raw_spin_unlock(v146 + 24);
  }
LABEL_145:
  wlan_objmgr_vdev_release_ref(v71, 0x26u, v85, v73, v74, v75, v76, v77, v78, v79, v80);
  v200 = *(_DWORD *)(a2 + 148);
  if ( (v200 & 0x80000000) == 0 || (v200 & 1) != 0 )
  {
    qdf_trace_msg(
      0x62u,
      8u,
      "%s: Last stats event",
      v192,
      v193,
      v194,
      v195,
      v196,
      v197,
      v198,
      v199,
      "tgt_mc_cp_stats_is_last_event");
    ucfg_mc_cp_stats_reset_pending_req(a1, 0, &v449, &v445);
    v201 = (void (__fastcall *)(_QWORD, __int64))v450;
    if ( v450 )
    {
      if ( (unsigned __int8)v445 == 1 )
      {
        v202 = v449;
        if ( *(_DWORD *)(v450 - 4) != 127008684 )
          __break(0x8228u);
        v201(v84, v202);
      }
    }
  }
LABEL_5:
  if ( (ucfg_mc_cp_stats_is_req_pending(a1, 2) & 1) != 0 )
    tgt_mc_cp_stats_extract_peer_stats(a1, a2, 0);
  if ( (ucfg_mc_cp_stats_is_req_pending(a1, 1) & 1) == 0 )
    goto LABEL_10;
  v447 = 0;
  v448 = 0;
  v445 = 0;
  v446 = nullptr;
  v444[0] = 0;
  if ( (unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 1, &v445) )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: ucfg_mc_cp_stats_get_pending_req failed",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "tgt_mc_cp_stats_extract_station_stats");
    goto LABEL_10;
  }
  tgt_mc_cp_stats_extract_tx_power(a1, a2, 1);
  tgt_mc_cp_stats_extract_peer_stats(a1, a2, 1);
  v32 = *(_QWORD *)(a2 + 96);
  v451 = 0;
  v452 = 0;
  v449 = 0;
  v450 = 0;
  if ( !v32 )
    goto LABEL_170;
  if ( (unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 1, &v449) )
  {
    v41 = "%s: ucfg_mc_cp_stats_get_pending_req failed";
LABEL_19:
    qdf_trace_msg(0x62u, 2u, v41, v33, v34, v35, v36, v37, v38, v39, v40, "tgt_mc_cp_stats_extract_vdev_summary_stats");
    goto LABEL_170;
  }
  v90 = *(_DWORD *)(a2 + 88);
  if ( !v90 )
  {
    v92 = 255;
    goto LABEL_128;
  }
  v91 = *(unsigned __int8 **)(a2 + 96);
  v92 = (unsigned __int8)v451;
  if ( *v91 == (unsigned __int8)v451 )
  {
    v93 = 0;
    goto LABEL_129;
  }
  v149 = 0;
  do
    v93 = ++v149;
  while ( v90 > v149 && v91[104 * v149] != (unsigned __int8)v451 );
  if ( v90 == v149 )
  {
LABEL_128:
    qdf_trace_msg(
      0x62u,
      8u,
      "%s: vdev_id %d not found",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "tgt_mc_cp_stats_extract_vdev_summary_stats",
      v92);
    goto LABEL_170;
  }
LABEL_129:
  if ( (unsigned __int8)v451 < 6u )
  {
    v150 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
             a1,
             (unsigned __int8)v451,
             38);
    if ( !v150 )
    {
      v41 = "%s: vdev is null";
      goto LABEL_19;
    }
    v151 = v150;
    v152 = wlan_objmgr_vdev_get_comp_private_obj(v150, 0x1Bu);
    if ( v152 )
    {
      v161 = v152;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v162 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v162 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v162 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v152 + 24);
      }
      else
      {
        raw_spin_lock_bh(v152 + 24);
        *(_QWORD *)(v161 + 32) |= 1uLL;
      }
      qdf_mem_copy(
        (void *)(*(_QWORD *)(v161 + 8) + 12LL),
        (const void *)(*(_QWORD *)(a2 + 96) + 104LL * v93 + 4),
        0x64u);
      v163 = *(_QWORD *)(v161 + 32);
      if ( (v163 & 1) != 0 )
      {
        *(_QWORD *)(v161 + 32) = v163 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v161 + 24);
      }
      else
      {
        raw_spin_unlock(v161 + 24);
      }
      peer = wlan_objmgr_get_peer(a1, SBYTE4(v451), &v452, 0x26u);
      if ( peer )
      {
        v173 = peer;
        v174 = wlan_objmgr_peer_get_comp_private_obj(peer, 0x1Bu);
        if ( v174 )
        {
          v183 = v174;
          qdf_spin_lock_bh_10(v174 + 24);
          *(_BYTE *)(*(_QWORD *)(v183 + 8) + 8LL) = *(_BYTE *)(*(_QWORD *)(a2 + 96) + 104LL * v93 + 8);
          qdf_spin_unlock_bh_10(v183 + 24);
        }
        else
        {
          qdf_trace_msg(
            0x62u,
            2u,
            "%s: peer cp stats object is null",
            v175,
            v176,
            v177,
            v178,
            v179,
            v180,
            v181,
            v182,
            "tgt_mc_cp_stats_extract_vdev_summary_stats");
        }
        wlan_objmgr_peer_release_ref(v173, 0x26u, v184, v185, v186, v187, v188, v189, v190, v191);
      }
      else
      {
        if ( &v452 )
          v212 = (unsigned __int8)v452;
        else
          v212 = 0;
        if ( &v452 )
          v213 = BYTE1(v452);
        else
          v213 = 0;
        if ( &v452 )
          v214 = BYTE2(v452);
        else
          v214 = 0;
        if ( &v452 )
          v215 = BYTE5(v452);
        else
          v215 = 0;
        qdf_trace_msg(
          0x62u,
          8u,
          "%s: peer is null %02x:%02x:%02x:**:**:%02x",
          v165,
          v166,
          v167,
          v168,
          v169,
          v170,
          v171,
          v172,
          "tgt_mc_cp_stats_extract_vdev_summary_stats",
          v212,
          v213,
          v214,
          v215);
      }
    }
    else
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: vdev cp stats object is null",
        v153,
        v154,
        v155,
        v156,
        v157,
        v158,
        v159,
        v160,
        "tgt_mc_cp_stats_extract_vdev_summary_stats");
    }
    wlan_objmgr_vdev_release_ref(v151, 0x26u, v203, v204, v205, v206, v207, v208, v209, v210, v211);
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: invalid vdev id %d",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "tgt_mc_cp_stats_extract_vdev_summary_stats");
  }
LABEL_170:
  v216 = *(_QWORD *)(a2 + 128);
  v451 = 0;
  v452 = 0;
  v449 = 0;
  v450 = 0;
  if ( !v216 )
    goto LABEL_174;
  if ( !(unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 1, &v449) )
  {
    v261 = *(_DWORD *)(a2 + 120);
    if ( !v261 )
      goto LABEL_174;
    v262 = 0;
    v263 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v273 = v262;
      if ( *(unsigned __int8 *)(*(_QWORD *)(a2 + 128) + 3LL * v262) == (unsigned __int8)v451 )
      {
        v274 = ((__int64 (__fastcall *)(__int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1);
        if ( !v274 )
        {
          v225 = "%s: vdev is null";
          goto LABEL_173;
        }
        v275 = v274;
        v276 = wlan_objmgr_vdev_get_comp_private_obj(v274, 0x1Bu);
        if ( !v276 )
        {
          qdf_trace_msg(
            0x62u,
            2u,
            "%s: vdev cp stats object is null",
            v277,
            v278,
            v279,
            v280,
            v281,
            v282,
            v283,
            v284,
            "tgt_mc_cp_stats_extract_vdev_chain_rssi_stats");
          wlan_objmgr_vdev_release_ref(v275, 0x26u, v417, v418, v419, v420, v421, v422, v423, v424, v425);
          goto LABEL_174;
        }
        v285 = v276;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v263 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v263 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v276 + 24);
        }
        else
        {
          raw_spin_lock_bh(v276 + 24);
          *(_QWORD *)(v285 + 32) |= 1uLL;
        }
        v286 = *(_QWORD *)(v285 + 8);
        *(_BYTE *)(v286 + 8) = *(_BYTE *)(*(_QWORD *)(a2 + 128) + 3 * v273 + 1);
        *(_BYTE *)(v286 + 9) = *(_BYTE *)(*(_QWORD *)(a2 + 128) + 3 * v273 + 2);
        v287 = *(_QWORD *)(v285 + 32);
        if ( (v287 & 1) != 0 )
        {
          *(_QWORD *)(v285 + 32) = v287 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v285 + 24);
        }
        else
        {
          raw_spin_unlock(v285 + 24);
        }
        wlan_objmgr_vdev_release_ref(v275, 0x26u, v264, v265, v266, v267, v268, v269, v270, v271, v272);
        v261 = *(_DWORD *)(a2 + 120);
      }
      v262 = v273 + 1;
      if ( v261 <= (unsigned __int8)(v273 + 1) )
        goto LABEL_174;
    }
  }
  v225 = "%s: ucfg_mc_cp_stats_get_pending_req failed";
LABEL_173:
  qdf_trace_msg(
    0x62u,
    2u,
    v225,
    v217,
    v218,
    v219,
    v220,
    v221,
    v222,
    v223,
    v224,
    "tgt_mc_cp_stats_extract_vdev_chain_rssi_stats");
LABEL_174:
  v451 = 0;
  v452 = 0;
  v449 = 0;
  v450 = 0;
  if ( (unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 1, &v449) )
  {
    v234 = "%s: ucfg_mc_cp_stats_get_pending_req failed";
LABEL_176:
    qdf_trace_msg(
      0x62u,
      2u,
      v234,
      v226,
      v227,
      v228,
      v229,
      v230,
      v231,
      v232,
      v233,
      "tgt_mc_cp_stats_extract_pmf_bcn_stats");
    goto LABEL_205;
  }
  v235 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
           a1,
           (unsigned int)v451,
           38);
  if ( !v235 )
  {
    v234 = "%s: vdev is null";
    goto LABEL_176;
  }
  v236 = v235;
  v237 = wlan_objmgr_vdev_get_comp_private_obj(v235, 0x1Bu);
  if ( v237 )
  {
    v246 = v237;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v247 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v247 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v247 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v237 + 24);
    }
    else
    {
      raw_spin_lock_bh(v237 + 24);
      *(_QWORD *)(v246 + 32) |= 1uLL;
    }
    if ( *(_BYTE *)(a2 + 168) == 1 )
    {
      v248 = *(_QWORD *)(a2 + 168);
      v249 = *(_QWORD *)(a2 + 176);
      v250 = *(_QWORD *)(v246 + 8);
      *(_DWORD *)(v250 + 128) = *(_DWORD *)(a2 + 184);
      *(_QWORD *)(v250 + 112) = v248;
      *(_QWORD *)(v250 + 120) = v249;
    }
    v251 = *(_QWORD *)(v246 + 32);
    if ( (v251 & 1) != 0 )
    {
      *(_QWORD *)(v246 + 32) = v251 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v246 + 24);
    }
    else
    {
      raw_spin_unlock(v246 + 24);
    }
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: vdev cp stats object is null",
      v238,
      v239,
      v240,
      v241,
      v242,
      v243,
      v244,
      v245,
      "tgt_mc_cp_stats_extract_pmf_bcn_stats");
  }
  wlan_objmgr_vdev_release_ref(v236, 0x26u, v252, v253, v254, v255, v256, v257, v258, v259, v260);
LABEL_205:
  tgt_mc_cp_stats_extract_vdev_extd_stats(a1, a2);
  v451 = 0;
  v452 = 0;
  v449 = 0;
  v450 = 0;
  if ( !(unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 1, &v449) && *(_QWORD *)(a2 + 208) && *(_DWORD *)(a2 + 200) )
  {
    v297 = 0;
    v298 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v299 = v297;
      v300 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               a1,
               *(unsigned __int8 *)(*(_QWORD *)(a2 + 208) + 84LL * v297),
               38);
      if ( !v300 )
      {
        qdf_trace_msg(
          0x62u,
          2u,
          "%s: vdev is null",
          v301,
          v302,
          v303,
          v304,
          v305,
          v306,
          v307,
          v308,
          "tgt_mc_cp_stats_extract_vdev_bcn_rssi_history");
        goto LABEL_206;
      }
      v309 = v300;
      v310 = wlan_objmgr_vdev_get_comp_private_obj(v300, 0x1Bu);
      if ( !v310 )
        break;
      v320 = v310;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v298 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v298 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v310 + 24);
      }
      else
      {
        raw_spin_lock_bh(v310 + 24);
        *(_QWORD *)(v320 + 32) |= 1uLL;
      }
      qdf_mem_copy((void *)(*(_QWORD *)(v320 + 8) + 140LL), (const void *)(*(_QWORD *)(a2 + 208) + 84LL * v299), 0x54u);
      v321 = *(_QWORD *)(v320 + 32);
      if ( (v321 & 1) != 0 )
      {
        *(_QWORD *)(v320 + 32) = v321 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v320 + 24);
      }
      else
      {
        raw_spin_unlock(v320 + 24);
      }
      wlan_objmgr_vdev_release_ref(v309, 0x26u, v322, v323, v324, v325, v326, v327, v328, v329, v330);
      v297 = v299 + 1;
      if ( *(_DWORD *)(a2 + 200) <= (unsigned int)(unsigned __int8)(v299 + 1) )
        goto LABEL_206;
    }
    wlan_objmgr_vdev_release_ref(v309, 0x26u, v311, v312, v313, v314, v315, v316, v317, v318, v319);
  }
LABEL_206:
  v296 = *(_DWORD *)(a2 + 148);
  if ( v296 < 0 )
  {
    if ( (v296 & 1) == 0 )
      goto LABEL_10;
  }
  else if ( !*(_QWORD *)(a2 + 40) )
  {
    goto LABEL_10;
  }
  qdf_trace_msg(
    0x62u,
    8u,
    "%s: Last stats event",
    v288,
    v289,
    v290,
    v291,
    v292,
    v293,
    v294,
    v295,
    "tgt_mc_cp_stats_is_last_event");
  ucfg_mc_cp_stats_reset_pending_req(a1, 1, &v445, v444);
  if ( v444[0] == 1 )
  {
    v331 = v446;
    if ( v446 )
    {
      v477 = 0;
      v478 = nullptr;
      v474 = 0;
      v476 = nullptr;
      v472 = 0;
      v473 = 0;
      v470 = 0;
      v471 = 0;
      v468 = 0;
      v469 = 0;
      v466 = 0;
      v467 = nullptr;
      v463 = 0;
      v464 = 0;
      v462 = 0;
      v459 = 0;
      v461 = 0;
      v457 = 0;
      v458 = 0;
      v455 = 0;
      *(_QWORD *)v456 = 0;
      v453 = 0;
      v454 = 0;
      v451 = 0;
      v452 = 0;
      v449 = 0;
      v450 = 0;
      v460 = 1;
      v465 = 1;
      v475 = 1;
      v462 = _qdf_mem_malloc(0x68u, "tgt_mc_cp_stats_send_raw_station_stats", 1334);
      v467 = (_BYTE *)_qdf_mem_malloc(3u, "tgt_mc_cp_stats_send_raw_station_stats", 1335);
      v332 = (void *)_qdf_mem_malloc(8u, "tgt_mc_cp_stats_send_raw_station_stats", 1337);
      v476 = v332;
      if ( !v462 )
        goto LABEL_264;
      if ( !v467 )
        goto LABEL_264;
      if ( !v332 )
        goto LABEL_264;
      if ( (wlan_cp_stats_is_bcn_rssi_history_report_cfg_enable(a1) & 1) != 0 )
      {
        LODWORD(v477) = 1;
        v478 = (void *)_qdf_mem_malloc(0x54u, "tgt_mc_cp_stats_send_raw_station_stats", 1345);
        if ( !v478 )
          goto LABEL_264;
      }
      v333 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               a1,
               (unsigned int)v447,
               38);
      if ( v333 )
      {
        v342 = v333;
        v343 = wlan_objmgr_vdev_get_comp_private_obj(v333, 0x1Bu);
        if ( v343 )
        {
          v352 = v343;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (v353 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v353 + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(v353 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v343 + 24);
          }
          else
          {
            raw_spin_lock_bh(v343 + 24);
            *(_QWORD *)(v352 + 32) |= 1uLL;
          }
          v354 = *(_QWORD *)(v352 + 8);
          *(_BYTE *)v462 = v447;
          v355 = v462;
          *(_QWORD *)(v462 + 4) = *(_QWORD *)(v354 + 12);
          v356 = *(_QWORD *)(v354 + 36);
          v357 = *(_QWORD *)(v354 + 20);
          v358 = *(_QWORD *)(v354 + 28);
          *(_QWORD *)(v355 + 36) = *(_QWORD *)(v354 + 44);
          *(_QWORD *)(v355 + 28) = v356;
          *(_QWORD *)(v355 + 20) = v358;
          *(_QWORD *)(v355 + 12) = v357;
          v359 = *(_QWORD *)(v354 + 68);
          v360 = *(_QWORD *)(v354 + 52);
          v361 = *(_QWORD *)(v354 + 60);
          *(_QWORD *)(v355 + 68) = *(_QWORD *)(v354 + 76);
          *(_QWORD *)(v355 + 60) = v359;
          *(_QWORD *)(v355 + 52) = v361;
          *(_QWORD *)(v355 + 44) = v360;
          v362 = *(_QWORD *)(v354 + 100);
          v363 = *(_QWORD *)(v354 + 84);
          v364 = *(_QWORD *)(v354 + 92);
          *(_DWORD *)(v355 + 100) = *(_DWORD *)(v354 + 108);
          *(_QWORD *)(v355 + 92) = v362;
          *(_QWORD *)(v355 + 84) = v364;
          *(_QWORD *)(v355 + 76) = v363;
          *v467 = v447;
          qdf_mem_copy(v467 + 1, (const void *)(v354 + 8), 2u);
          LODWORD(v469) = *(_DWORD *)(v354 + 4);
          v366 = *(_QWORD *)(v354 + 112);
          v365 = *(_QWORD *)(v354 + 120);
          v474 = *(_DWORD *)(v354 + 128);
          v472 = v366;
          v473 = v365;
          qdf_mem_copy(v476, (const void *)(v354 + 132), 8u);
          if ( v478 )
            qdf_mem_copy(v478, (const void *)(v354 + 140), 0x54u);
          v367 = *(_QWORD *)(v352 + 32);
          if ( (v367 & 1) != 0 )
          {
            *(_QWORD *)(v352 + 32) = v367 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v352 + 24);
          }
          else
          {
            raw_spin_unlock(v352 + 24);
          }
          wlan_objmgr_vdev_release_ref(v342, 0x26u, v368, v369, v370, v371, v372, v373, v374, v375, v376);
          *(_QWORD *)v456 = _qdf_mem_malloc(0x18u, "tgt_mc_cp_stats_send_raw_station_stats", 1356);
          if ( !*(_QWORD *)v456 )
            goto LABEL_264;
          v377 = wlan_objmgr_get_peer(a1, SBYTE4(v447), &v448, 0x26u);
          if ( v377 )
          {
            v386 = v377;
            v387 = wlan_objmgr_peer_get_comp_private_obj(v377, 0x1Bu);
            if ( v387 )
            {
              v396 = v387;
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (v397 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v397 + 16) & 0xF0000) != 0)
                || (*(_DWORD *)(v397 + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(v387 + 24);
              }
              else
              {
                raw_spin_lock_bh(v387 + 24);
                *(_QWORD *)(v396 + 32) |= 1uLL;
              }
              v398 = *(_QWORD *)(v396 + 8);
              LODWORD(v468) = *(_DWORD *)v398 / 0x64u;
              HIDWORD(v468) = *(_DWORD *)(v398 + 4) / 0x64u;
              if ( *(_QWORD *)(v398 + 24) )
              {
                LODWORD(v455) = 1;
                qdf_mem_copy(*(void **)v456, *(const void **)(v398 + 24), 0x18u);
              }
              v399 = *(_QWORD *)(v396 + 32);
              if ( (v399 & 1) != 0 )
              {
                *(_QWORD *)(v396 + 32) = v399 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v396 + 24);
              }
              else
              {
                raw_spin_unlock(v396 + 24);
              }
              wlan_objmgr_peer_release_ref(v386, 0x26u, v400, v401, v402, v403, v404, v405, v406, v407);
              LODWORD(v449) = 1;
              v450 = _qdf_mem_malloc(0x3180u, "tgt_mc_cp_stats_send_raw_station_stats", 1367);
              if ( !v450 || !(unsigned int)tgt_send_pdev_mc_cp_stats(a1, &v449, &v445) )
                goto LABEL_264;
              v416 = "%s: tgt_send_pdev_mc_cp_stats failed";
              goto LABEL_263;
            }
            qdf_trace_msg(
              0x62u,
              2u,
              "%s: peer cp stats object is null",
              v388,
              v389,
              v390,
              v391,
              v392,
              v393,
              v394,
              v395,
              "tgt_send_peer_mc_cp_stats");
            wlan_objmgr_peer_release_ref(v386, 0x26u, v436, v437, v438, v439, v440, v441, v442, v443);
          }
          else
          {
            qdf_trace_msg(
              0x62u,
              8u,
              "%s: peer object is null",
              v378,
              v379,
              v380,
              v381,
              v382,
              v383,
              v384,
              v385,
              "tgt_send_peer_mc_cp_stats");
          }
          v416 = "%s: tgt_send_peer_mc_cp_stats failed";
LABEL_263:
          qdf_trace_msg(
            0x62u,
            2u,
            v416,
            v408,
            v409,
            v410,
            v411,
            v412,
            v413,
            v414,
            v415,
            "tgt_mc_cp_stats_send_raw_station_stats");
LABEL_264:
          v435 = v445;
          if ( *((_DWORD *)v331 - 1) != 488738581 )
            __break(0x8237u);
          v331(&v449, v435);
          ucfg_mc_cp_stats_free_stats_resources(&v449);
          goto LABEL_10;
        }
        qdf_trace_msg(
          0x62u,
          2u,
          "%s: vdev cp stats object is null",
          v344,
          v345,
          v346,
          v347,
          v348,
          v349,
          v350,
          v351,
          "tgt_send_vdev_mc_cp_stats");
        wlan_objmgr_vdev_release_ref(v342, 0x26u, v426, v427, v428, v429, v430, v431, v432, v433, v434);
      }
      else
      {
        qdf_trace_msg(
          0x62u,
          2u,
          "%s: vdev object is null",
          v334,
          v335,
          v336,
          v337,
          v338,
          v339,
          v340,
          v341,
          "tgt_send_vdev_mc_cp_stats");
      }
      v416 = "%s: tgt_send_vdev_mc_cp_stats failed";
      goto LABEL_263;
    }
  }
LABEL_10:
  if ( (ucfg_mc_cp_stats_is_req_pending(a1, 3) & 1) == 0 )
    goto LABEL_22;
  v29 = *(_QWORD *)(a2 + 112);
  v451 = 0;
  v452 = 0;
  v449 = 0;
  v450 = 0;
  LOBYTE(v445) = 0;
  if ( !v29 )
  {
    v30 = "%s: no mib stats";
    v31 = 8;
    goto LABEL_21;
  }
  if ( (unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 3, &v449) )
  {
    v30 = "%s: ucfg_mc_cp_stats_get_pending_req failed";
    v31 = 2;
LABEL_21:
    qdf_trace_msg(0x62u, v31, v30, v21, v22, v23, v24, v25, v26, v27, v28, "tgt_mc_cp_stats_extract_mib_stats");
    goto LABEL_22;
  }
  v67 = *(_DWORD *)(a2 + 148);
  if ( v67 < 0 )
  {
    if ( (v67 & 1) == 0 )
      goto LABEL_22;
  }
  else if ( !*(_QWORD *)(a2 + 40) )
  {
    goto LABEL_22;
  }
  qdf_trace_msg(
    0x62u,
    8u,
    "%s: Last stats event",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "tgt_mc_cp_stats_is_last_event");
  ucfg_mc_cp_stats_reset_pending_req(a1, 3, &v449, &v445);
  v94 = (void (__fastcall *)(__int64, __int64))v450;
  if ( v450 && (unsigned __int8)v445 == 1 )
  {
    v95 = v449;
    if ( *(_DWORD *)(v450 - 4) != 488738581 )
      __break(0x8228u);
    v94(a2, v95);
  }
LABEL_22:
  if ( (ucfg_mc_cp_stats_is_req_pending(a1, 4) & 1) == 0 )
    goto LABEL_29;
  v50 = *(_QWORD *)(a2 + 160);
  v451 = 0;
  v452 = 0;
  v449 = 0;
  v450 = 0;
  LOBYTE(v445) = 0;
  if ( !v50 || !*(_DWORD *)(a2 + 156) )
  {
    v51 = "%s: no peer_stats_info_ext";
    v52 = 8;
    goto LABEL_28;
  }
  if ( (unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 4, &v449) )
  {
    v51 = "%s: ucfg_mc_cp_stats_get_pending_req failed";
    v52 = 2;
LABEL_28:
    qdf_trace_msg(
      0x62u,
      v52,
      v51,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "tgt_mc_cp_stats_extract_peer_stats_info_ext");
    goto LABEL_29;
  }
  ucfg_mc_cp_stats_reset_pending_req(a1, 4, &v449, &v445);
  v68 = (void (__fastcall *)(__int64, __int64))v450;
  if ( v450 && (unsigned __int8)v445 == 1 )
  {
    v69 = v449;
    if ( *(_DWORD *)(v450 - 4) != 488738581 )
      __break(0x8228u);
    v68(a2, v69);
  }
LABEL_29:
  if ( (ucfg_mc_cp_stats_is_req_pending(a1, 5) & 1) == 0 )
    goto LABEL_95;
  v61 = *(_DWORD *)(a2 + 148);
  v447 = 0;
  v448 = 0;
  v445 = 0;
  v446 = nullptr;
  v453 = 0;
  v454 = 0;
  v451 = 0;
  v452 = 0;
  v449 = 0;
  v450 = 0;
  if ( (v61 & 0x80000000) == 0 )
  {
    if ( *(_QWORD *)(a2 + 40) )
      goto LABEL_32;
LABEL_35:
    v62 = 0;
    if ( *(_DWORD *)a2 )
      goto LABEL_37;
    goto LABEL_36;
  }
  if ( (v61 & 1) == 0 )
    goto LABEL_35;
LABEL_32:
  qdf_trace_msg(
    0x62u,
    8u,
    "%s: Last stats event",
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    "tgt_mc_cp_stats_is_last_event");
  v62 = 1;
  if ( *(_DWORD *)a2 )
    goto LABEL_37;
LABEL_36:
  if ( !*(_DWORD *)(a2 + 16) )
  {
    v63 = "%s: no congestion sta for pdev";
    goto LABEL_67;
  }
LABEL_37:
  if ( (unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 5, &v445) )
  {
    v63 = "%s: ucfg_mc_cp_stats_get_pending_req failed";
LABEL_67:
    qdf_trace_msg(0x62u, 2u, v63, v53, v54, v55, v56, v57, v58, v59, v60, "tgt_mc_cp_stats_extract_congestion_stats");
    goto LABEL_95;
  }
  v64 = *(_DWORD *)a2;
  if ( *(_DWORD *)a2 )
  {
    v65 = *(_DWORD **)(a2 + 8);
    v66 = v65[1];
    if ( (v66 & 0xFE) != 0 )
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: part1 pdev id error",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "tgt_mc_cp_stats_extract_congestion_stats");
      if ( *(_DWORD *)a2 <= 1u )
        goto LABEL_83;
    }
    else
    {
      v96 = &v449 + 3 * (v66 & 1);
      *(_BYTE *)v96 = 1;
      *((_DWORD *)v96 + 1) = v65[3];
      *((_DWORD *)v96 + 2) = v65[2];
      *((_DWORD *)v96 + 3) = v65[4];
      if ( v64 <= 1 )
        goto LABEL_83;
    }
    v97 = *(_DWORD **)(a2 + 8);
    v98 = v97[3169];
    if ( (v98 & 0xFE) != 0 )
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: part1 pdev id error",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "tgt_mc_cp_stats_extract_congestion_stats");
    }
    else
    {
      v100 = &v449 + 3 * (v98 & 1);
      *(_BYTE *)v100 = 1;
      *((_DWORD *)v100 + 1) = v97[3171];
      *((_DWORD *)v100 + 2) = v97[3170];
      *((_DWORD *)v100 + 3) = v97[3172];
    }
  }
LABEL_83:
  v101 = *(_DWORD *)(a2 + 16);
  if ( !v101 )
    goto LABEL_91;
  v102 = *(_DWORD **)(a2 + 24);
  if ( (*v102 & 0xFE) != 0 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: part2 pdev id error",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "tgt_mc_cp_stats_extract_congestion_stats");
    if ( *(_DWORD *)(a2 + 16) <= 1u )
      goto LABEL_91;
  }
  else
  {
    v103 = &v449 + 3 * (*v102 & 1);
    *((_BYTE *)v103 + 16) = 1;
    *((_DWORD *)v103 + 5) = v102[1];
    if ( v101 <= 1 )
      goto LABEL_91;
  }
  v104 = *(_QWORD *)(a2 + 24);
  v105 = *(_DWORD *)(v104 + 16);
  if ( (v105 & 0xFE) != 0 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: part2 pdev id error",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "tgt_mc_cp_stats_extract_congestion_stats");
  }
  else
  {
    v106 = &v449 + 3 * (v105 & 1);
    *((_BYTE *)v106 + 16) = 1;
    *((_DWORD *)v106 + 5) = *(_DWORD *)(v104 + 20);
  }
LABEL_91:
  v107 = v446;
  if ( v446 )
  {
    v108 = (unsigned int)v447;
    if ( *((_DWORD *)v446 - 1) != 1252525472 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64 *, _QWORD))v107)(v108, &v449, v62);
  }
LABEL_95:
  v109 = *(unsigned __int8 **)(a2 + 80);
  if ( v109 )
  {
    v110 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *v109, 38);
    if ( v110 )
    {
      v119 = v110;
      v120 = wlan_objmgr_vdev_get_comp_private_obj(v110, 0x1Bu);
      if ( v120 )
      {
        v129 = v120;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v130 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v130 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v130 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v120 + 24);
        }
        else
        {
          raw_spin_lock_bh(v120 + 24);
          *(_QWORD *)(v129 + 32) |= 1uLL;
        }
        **(_DWORD **)(v129 + 8) = *(_DWORD *)(*(_QWORD *)(a2 + 80) + 4LL);
        v131 = *(_QWORD *)(v129 + 32);
        if ( (v131 & 1) != 0 )
        {
          *(_QWORD *)(v129 + 32) = v131 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v129 + 24);
        }
        else
        {
          raw_spin_unlock(v129 + 24);
        }
      }
      else
      {
        qdf_trace_msg(
          0x62u,
          2u,
          "%s: vdev cp stats object is null",
          v121,
          v122,
          v123,
          v124,
          v125,
          v126,
          v127,
          v128,
          "tgt_mc_cp_stats_extract_cca_stats");
      }
      wlan_objmgr_vdev_release_ref(v119, 0x26u, v132, v133, v134, v135, v136, v137, v138, v139, v140);
    }
    else
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: vdev is null",
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        "tgt_mc_cp_stats_extract_cca_stats");
    }
  }
  if ( a1 )
  {
    v141 = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu);
    if ( v141 )
    {
      v142 = *(_QWORD *)(v141 + 24);
      if ( v142 )
      {
        v143 = *(void (__fastcall **)(_QWORD))(v142 + 48);
        if ( v143 )
        {
          if ( *((_DWORD *)v143 - 1) != 251140989 )
            __break(0x8228u);
          v143(a2);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
