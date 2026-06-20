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
  __int64 v91; // x9
  unsigned int v92; // w23
  unsigned __int8 v93; // w10
  unsigned __int8 v94; // w1
  unsigned int v95; // w24
  unsigned int v96; // w4
  void (__fastcall *v97)(__int64, __int64); // x8
  __int64 v98; // x1
  __int64 *v99; // x10
  _DWORD *v100; // x8
  int v101; // w9
  const char *v102; // x2
  __int64 *v103; // x9
  unsigned int v104; // w8
  _DWORD *v105; // x9
  __int64 *v106; // x10
  __int64 v107; // x8
  int v108; // w9
  __int64 *v109; // x9
  void (__fastcall *v110)(__int64, __int64 *, _QWORD); // x8
  __int64 v111; // x0
  unsigned __int8 *v112; // x8
  __int64 v113; // x0
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  __int64 v122; // x21
  __int64 v123; // x0
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  __int64 v132; // x22
  unsigned __int64 v133; // x8
  __int64 v134; // x8
  unsigned int *v135; // x8
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  __int64 v144; // x0
  __int64 v145; // x8
  void (__fastcall *v146)(_QWORD); // x8
  __int64 v148; // x0
  __int64 v149; // x23
  unsigned __int64 v150; // x8
  __int64 v151; // x8
  const char *v152; // x2
  __int64 v153; // x4
  unsigned int v154; // w1
  __int64 v155; // x8
  double v156; // d0
  double v157; // d1
  double v158; // d2
  double v159; // d3
  double v160; // d4
  double v161; // d5
  double v162; // d6
  double v163; // d7
  const char *v164; // x2
  double v165; // d0
  double v166; // d1
  double v167; // d2
  double v168; // d3
  double v169; // d4
  double v170; // d5
  double v171; // d6
  double v172; // d7
  const char *v173; // x2
  __int64 v174; // x0
  __int64 v175; // x21
  __int64 v176; // x0
  double v177; // d0
  double v178; // d1
  double v179; // d2
  double v180; // d3
  double v181; // d4
  double v182; // d5
  double v183; // d6
  double v184; // d7
  __int64 v185; // x22
  unsigned __int64 v186; // x8
  __int64 v187; // x8
  __int64 v188; // x11
  __int64 v189; // x9
  __int64 v190; // x8
  unsigned int *v191; // x8
  double v192; // d0
  double v193; // d1
  double v194; // d2
  double v195; // d3
  double v196; // d4
  double v197; // d5
  double v198; // d6
  double v199; // d7
  unsigned __int8 v200; // w8
  unsigned __int64 v201; // x25
  unsigned int *v202; // x8
  double v203; // d0
  double v204; // d1
  double v205; // d2
  double v206; // d3
  double v207; // d4
  double v208; // d5
  double v209; // d6
  double v210; // d7
  __int64 v211; // x26
  unsigned int v212; // w4
  __int64 v213; // x0
  __int64 v214; // x23
  __int64 v215; // x0
  double v216; // d0
  double v217; // d1
  double v218; // d2
  double v219; // d3
  double v220; // d4
  double v221; // d5
  double v222; // d6
  double v223; // d7
  __int64 v224; // x24
  __int64 v225; // x10
  __int64 v226; // x8
  double v227; // d0
  double v228; // d1
  double v229; // d2
  double v230; // d3
  double v231; // d4
  double v232; // d5
  double v233; // d6
  double v234; // d7
  int v235; // w8
  unsigned __int8 v236; // w8
  unsigned __int64 v237; // x24
  unsigned int v238; // w25
  __int64 v239; // x0
  double v240; // d0
  double v241; // d1
  double v242; // d2
  double v243; // d3
  double v244; // d4
  double v245; // d5
  double v246; // d6
  double v247; // d7
  __int64 v248; // x21
  __int64 v249; // x0
  unsigned int *v250; // x8
  double v251; // d0
  double v252; // d1
  double v253; // d2
  double v254; // d3
  double v255; // d4
  double v256; // d5
  double v257; // d6
  double v258; // d7
  __int64 v259; // x22
  __int64 v260; // x8
  unsigned int *v261; // x8
  double v262; // d0
  double v263; // d1
  double v264; // d2
  double v265; // d3
  double v266; // d4
  double v267; // d5
  double v268; // d6
  double v269; // d7
  double v270; // d0
  double v271; // d1
  double v272; // d2
  double v273; // d3
  double v274; // d4
  double v275; // d5
  double v276; // d6
  double v277; // d7
  double v278; // d0
  double v279; // d1
  double v280; // d2
  double v281; // d3
  double v282; // d4
  double v283; // d5
  double v284; // d6
  double v285; // d7
  double v286; // d0
  double v287; // d1
  double v288; // d2
  double v289; // d3
  double v290; // d4
  double v291; // d5
  double v292; // d6
  double v293; // d7
  unsigned int *v294; // x8
  double v295; // d0
  double v296; // d1
  double v297; // d2
  double v298; // d3
  double v299; // d4
  double v300; // d5
  double v301; // d6
  double v302; // d7
  __int64 v303; // x0
  __int64 v304; // x21
  __int64 v305; // x0
  double v306; // d0
  double v307; // d1
  double v308; // d2
  double v309; // d3
  double v310; // d4
  double v311; // d5
  double v312; // d6
  double v313; // d7
  __int64 v314; // x22
  unsigned __int64 v315; // x8
  __int64 v316; // x8
  _QWORD *peer; // x0
  double v318; // d0
  double v319; // d1
  double v320; // d2
  double v321; // d3
  double v322; // d4
  double v323; // d5
  double v324; // d6
  double v325; // d7
  __int64 v326; // x22
  __int64 v327; // x0
  double v328; // d0
  double v329; // d1
  double v330; // d2
  double v331; // d3
  double v332; // d4
  double v333; // d5
  double v334; // d6
  double v335; // d7
  __int64 v336; // x23
  double v337; // d0
  double v338; // d1
  double v339; // d2
  double v340; // d3
  double v341; // d4
  double v342; // d5
  double v343; // d6
  double v344; // d7
  double v345; // d0
  double v346; // d1
  double v347; // d2
  double v348; // d3
  double v349; // d4
  double v350; // d5
  double v351; // d6
  double v352; // d7
  int v353; // w8
  void (__fastcall *v354)(_QWORD, __int64); // x8
  __int64 v355; // x1
  unsigned int *v356; // x8
  double v357; // d0
  double v358; // d1
  double v359; // d2
  double v360; // d3
  double v361; // d4
  double v362; // d5
  double v363; // d6
  double v364; // d7
  __int64 v365; // x4
  __int64 v366; // x5
  __int64 v367; // x6
  __int64 v368; // x7
  _BYTE v369[4]; // [xsp+4h] [xbp-6Ch] BYREF
  __int64 v370; // [xsp+8h] [xbp-68h] BYREF
  __int64 v371; // [xsp+10h] [xbp-60h]
  __int64 v372; // [xsp+18h] [xbp-58h]
  __int64 v373; // [xsp+20h] [xbp-50h] BYREF
  __int64 v374; // [xsp+28h] [xbp-48h] BYREF
  __int64 v375; // [xsp+30h] [xbp-40h]
  __int64 v376; // [xsp+38h] [xbp-38h] BYREF
  void (__fastcall *v377)(_QWORD, __int64); // [xsp+40h] [xbp-30h]
  __int64 v378; // [xsp+48h] [xbp-28h]
  __int64 v379; // [xsp+50h] [xbp-20h] BYREF
  __int64 v380; // [xsp+58h] [xbp-18h]
  __int64 v381; // [xsp+60h] [xbp-10h]
  __int64 v382; // [xsp+68h] [xbp-8h]

  v382 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (ucfg_mc_cp_stats_is_req_pending(a1, 0) & 1) == 0 )
    goto LABEL_5;
  v380 = 0;
  v381 = 0;
  v378 = 0;
  v379 = 0;
  v376 = 0;
  v377 = nullptr;
  LOBYTE(v370) = 0;
  if ( (unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 0, &v376) )
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
          (unsigned int)v378,
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
        goto LABEL_219;
    }
    else
    {
      raw_spin_unlock(v81 + 24);
      if ( v84 )
        goto LABEL_219;
    }
  }
  v86 = *(_QWORD *)(v71 + 216);
  if ( !v86 )
  {
    v102 = "%s: pdev is null";
LABEL_217:
    qdf_trace_msg(0x62u, 2u, v102, v73, v74, v75, v76, v77, v78, v79, v80, "tgt_mc_cp_stats_get_tx_power");
LABEL_218:
    v84 = 0;
    goto LABEL_219;
  }
  v87 = *(_QWORD *)(v86 + 80);
  if ( !v87 )
  {
    v102 = "%s: psoc is null";
    goto LABEL_217;
  }
  macid_by_vdev_id = policy_mgr_mode_get_macid_by_vdev_id(v87, *(unsigned __int8 *)(v71 + 168));
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
      goto LABEL_219;
    }
    goto LABEL_218;
  }
  v148 = wlan_objmgr_pdev_get_comp_private_obj(v86, 0x1Bu);
  if ( !v148 )
  {
    v102 = "%s: pdev cp stats object is null";
    goto LABEL_217;
  }
  v149 = v148;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v150 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v150 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v150 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v148 + 24);
    v151 = *(_QWORD *)(v149 + 32);
  }
  else
  {
    raw_spin_lock_bh(v148 + 24);
    v151 = *(_QWORD *)(v149 + 32) | 1LL;
    *(_QWORD *)(v149 + 32) = v151;
  }
  v84 = *(_DWORD *)(*(_QWORD *)(v149 + 8) + 12672LL * macid_by_vdev_id);
  if ( (v151 & 1) != 0 )
  {
    *(_QWORD *)(v149 + 32) = v151 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v149 + 24);
  }
  else
  {
    raw_spin_unlock(v149 + 24);
  }
LABEL_219:
  wlan_objmgr_vdev_release_ref(v71, 0x26u, v85, v73, v74, v75, v76, v77, v78, v79, v80);
  v353 = *(_DWORD *)(a2 + 148);
  if ( (v353 & 0x80000000) == 0 || (v353 & 1) != 0 )
  {
    qdf_trace_msg(
      0x62u,
      8u,
      "%s: Last stats event",
      v345,
      v346,
      v347,
      v348,
      v349,
      v350,
      v351,
      v352,
      "tgt_mc_cp_stats_is_last_event");
    ucfg_mc_cp_stats_reset_pending_req(a1, 0, &v376, &v370);
    v354 = v377;
    if ( v377 )
    {
      if ( (unsigned __int8)v370 == 1 )
      {
        v355 = v376;
        if ( *((_DWORD *)v377 - 1) != 127008684 )
          __break(0x8228u);
        v354(v84, v355);
      }
    }
  }
LABEL_5:
  if ( (ucfg_mc_cp_stats_is_req_pending(a1, 2) & 1) != 0 )
    tgt_mc_cp_stats_extract_peer_stats(a1, a2, 0);
  if ( (ucfg_mc_cp_stats_is_req_pending(a1, 1) & 1) == 0 )
    goto LABEL_10;
  v374 = 0;
  v375 = 0;
  v372 = 0;
  v373 = 0;
  v370 = 0;
  v371 = 0;
  v369[0] = 0;
  if ( (unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 1, &v370) )
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
  v380 = 0;
  v381 = 0;
  v378 = 0;
  v379 = 0;
  v376 = 0;
  v377 = nullptr;
  if ( v32 )
  {
    if ( (unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 1, &v376) )
    {
      v41 = "%s: ucfg_mc_cp_stats_get_pending_req failed";
LABEL_19:
      qdf_trace_msg(
        0x62u,
        2u,
        v41,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "tgt_mc_cp_stats_extract_vdev_summary_stats");
      goto LABEL_133;
    }
    v90 = *(_DWORD *)(a2 + 88);
    if ( !v90 )
    {
      v94 = -1;
LABEL_131:
      v152 = "%s: vdev_id %d not found";
      v153 = v94;
      v154 = 8;
LABEL_132:
      qdf_trace_msg(
        0x62u,
        v154,
        v152,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "tgt_mc_cp_stats_extract_vdev_summary_stats",
        v153);
      goto LABEL_133;
    }
    v91 = *(_QWORD *)(a2 + 96);
    v92 = 0;
    v93 = 0;
    do
    {
      v95 = v93;
      v96 = *(unsigned __int8 *)(v91 + 104LL * v93);
      if ( BYTE6(v379) )
      {
        if ( v96 < 6
          || (qdf_trace_msg(
                0x62u,
                2u,
                "%s: Invalid vdev[%u] sent by firmware",
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                "update_ml_vdev_id_from_stats_event"),
              v91 = *(_QWORD *)(a2 + 96),
              v94 = -1,
              v96 = *(unsigned __int8 *)(v91 + 104LL * v95),
              v90 = *(_DWORD *)(a2 + 88),
              v96 == 255) )
        {
LABEL_76:
          v94 = v96;
          goto LABEL_130;
        }
      }
      else
      {
        v94 = v378;
        if ( v96 == (unsigned __int8)v378 )
          goto LABEL_76;
      }
      v93 = v95 + 1;
      v92 = (unsigned __int8)(v95 + 1);
    }
    while ( v90 > v92 );
    v95 = (unsigned __int8)(v95 + 1);
LABEL_130:
    if ( v90 == v92 )
      goto LABEL_131;
    v153 = v94;
    if ( v94 >= 6u )
    {
      v152 = "%s: invalid vdev id %d";
      v154 = 2;
      goto LABEL_132;
    }
    v303 = ((__int64 (__fastcall *)(__int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1);
    if ( !v303 )
    {
      v41 = "%s: vdev is null";
      goto LABEL_19;
    }
    v304 = v303;
    v305 = wlan_objmgr_vdev_get_comp_private_obj(v303, 0x1Bu);
    if ( v305 )
    {
      v314 = v305;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v315 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v315 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v315 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v305 + 24);
      }
      else
      {
        raw_spin_lock_bh(v305 + 24);
        *(_QWORD *)(v314 + 32) |= 1uLL;
      }
      qdf_mem_copy(
        (void *)(*(_QWORD *)(v314 + 8) + 12LL),
        (const void *)(*(_QWORD *)(a2 + 96) + 104LL * v95 + 4),
        0x64u);
      v316 = *(_QWORD *)(v314 + 32);
      if ( (v316 & 1) != 0 )
      {
        *(_QWORD *)(v314 + 32) = v316 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v314 + 24);
      }
      else
      {
        raw_spin_unlock(v314 + 24);
      }
      peer = wlan_objmgr_get_peer(a1, BYTE4(v378), &v379, 0x26u);
      if ( peer )
      {
        v326 = (__int64)peer;
        v327 = wlan_objmgr_peer_get_comp_private_obj((__int64)peer, 0x1Bu);
        if ( v327 )
        {
          v336 = v327;
          qdf_spin_lock_bh_10(v327 + 24);
          *(_BYTE *)(*(_QWORD *)(v336 + 8) + 8LL) = *(_BYTE *)(*(_QWORD *)(a2 + 96) + 104LL * v95 + 8);
          qdf_spin_unlock_bh_11(v336 + 24);
        }
        else
        {
          qdf_trace_msg(
            0x62u,
            2u,
            "%s: peer cp stats object is null",
            v328,
            v329,
            v330,
            v331,
            v332,
            v333,
            v334,
            v335,
            "tgt_mc_cp_stats_extract_vdev_summary_stats");
        }
        wlan_objmgr_peer_release_ref(v326, 0x26u, v337, v338, v339, v340, v341, v342, v343, v344);
      }
      else
      {
        if ( &v379 )
          v365 = (unsigned __int8)v379;
        else
          v365 = 0;
        if ( &v379 )
          v366 = BYTE1(v379);
        else
          v366 = 0;
        if ( &v379 )
          v367 = BYTE2(v379);
        else
          v367 = 0;
        if ( &v379 )
          v368 = BYTE5(v379);
        else
          v368 = 0;
        qdf_trace_msg(
          0x62u,
          8u,
          "%s: peer is null %02x:%02x:%02x:**:**:%02x",
          v318,
          v319,
          v320,
          v321,
          v322,
          v323,
          v324,
          v325,
          "tgt_mc_cp_stats_extract_vdev_summary_stats",
          v365,
          v366,
          v367,
          v368);
      }
    }
    else
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: vdev cp stats object is null",
        v306,
        v307,
        v308,
        v309,
        v310,
        v311,
        v312,
        v313,
        "tgt_mc_cp_stats_extract_vdev_summary_stats");
    }
    wlan_objmgr_vdev_release_ref(v304, 0x26u, v356, v357, v358, v359, v360, v361, v362, v363, v364);
  }
LABEL_133:
  v155 = *(_QWORD *)(a2 + 128);
  v380 = 0;
  v381 = 0;
  v378 = 0;
  v379 = 0;
  v376 = 0;
  v377 = nullptr;
  if ( !v155 )
    goto LABEL_137;
  if ( !(unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 1, &v376) )
  {
    if ( !*(_DWORD *)(a2 + 120) )
      goto LABEL_137;
    v200 = 0;
    v201 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v211 = v200;
      v212 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 128) + 3LL * v200);
      if ( BYTE6(v379) )
      {
        if ( v212 >= 6 )
        {
          qdf_trace_msg(
            0x62u,
            2u,
            "%s: Invalid vdev[%u] sent by firmware",
            v156,
            v157,
            v158,
            v159,
            v160,
            v161,
            v162,
            v163,
            "update_ml_vdev_id_from_stats_event");
          v212 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 128) + 3 * v211);
          if ( v212 != 255 )
            goto LABEL_154;
        }
      }
      else if ( v212 != (unsigned __int8)v378 )
      {
        goto LABEL_154;
      }
      v213 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v212, 38);
      if ( !v213 )
      {
        v164 = "%s: vdev is null";
        goto LABEL_136;
      }
      v214 = v213;
      v215 = wlan_objmgr_vdev_get_comp_private_obj(v213, 0x1Bu);
      if ( !v215 )
      {
        qdf_trace_msg(
          0x62u,
          2u,
          "%s: vdev cp stats object is null",
          v216,
          v217,
          v218,
          v219,
          v220,
          v221,
          v222,
          v223,
          "tgt_mc_cp_stats_extract_vdev_chain_rssi_stats");
        wlan_objmgr_vdev_release_ref(v214, 0x26u, v294, v295, v296, v297, v298, v299, v300, v301, v302);
        goto LABEL_137;
      }
      v224 = v215;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v201 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v201 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v215 + 24);
      }
      else
      {
        raw_spin_lock_bh(v215 + 24);
        *(_QWORD *)(v224 + 32) |= 1uLL;
      }
      v225 = *(_QWORD *)(v224 + 8);
      *(_BYTE *)(v225 + 8) = *(_BYTE *)(*(_QWORD *)(a2 + 128) + 3 * v211 + 1);
      *(_BYTE *)(v225 + 9) = *(_BYTE *)(*(_QWORD *)(a2 + 128) + 3 * v211 + 2);
      v226 = *(_QWORD *)(v224 + 32);
      if ( (v226 & 1) != 0 )
      {
        *(_QWORD *)(v224 + 32) = v226 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v224 + 24);
      }
      else
      {
        raw_spin_unlock(v224 + 24);
      }
      wlan_objmgr_vdev_release_ref(v214, 0x26u, v202, v203, v204, v205, v206, v207, v208, v209, v210);
LABEL_154:
      v200 = v211 + 1;
      if ( *(_DWORD *)(a2 + 120) <= (unsigned int)(unsigned __int8)(v211 + 1) )
        goto LABEL_137;
    }
  }
  v164 = "%s: ucfg_mc_cp_stats_get_pending_req failed";
LABEL_136:
  qdf_trace_msg(
    0x62u,
    2u,
    v164,
    v156,
    v157,
    v158,
    v159,
    v160,
    v161,
    v162,
    v163,
    "tgt_mc_cp_stats_extract_vdev_chain_rssi_stats");
LABEL_137:
  v380 = 0;
  v381 = 0;
  v378 = 0;
  v379 = 0;
  v376 = 0;
  v377 = nullptr;
  if ( (unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 1, &v376) )
  {
    v173 = "%s: ucfg_mc_cp_stats_get_pending_req failed";
LABEL_139:
    qdf_trace_msg(
      0x62u,
      2u,
      v173,
      v165,
      v166,
      v167,
      v168,
      v169,
      v170,
      v171,
      v172,
      "tgt_mc_cp_stats_extract_pmf_bcn_stats");
    goto LABEL_172;
  }
  v174 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
           a1,
           (unsigned int)v378,
           38);
  if ( !v174 )
  {
    v173 = "%s: vdev is null";
    goto LABEL_139;
  }
  v175 = v174;
  v176 = wlan_objmgr_vdev_get_comp_private_obj(v174, 0x1Bu);
  if ( v176 )
  {
    v185 = v176;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v186 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v186 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v186 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v176 + 24);
    }
    else
    {
      raw_spin_lock_bh(v176 + 24);
      *(_QWORD *)(v185 + 32) |= 1uLL;
    }
    if ( *(_BYTE *)(a2 + 168) == 1 )
    {
      v187 = *(_QWORD *)(a2 + 168);
      v188 = *(_QWORD *)(a2 + 176);
      v189 = *(_QWORD *)(v185 + 8);
      *(_DWORD *)(v189 + 128) = *(_DWORD *)(a2 + 184);
      *(_QWORD *)(v189 + 112) = v187;
      *(_QWORD *)(v189 + 120) = v188;
    }
    v190 = *(_QWORD *)(v185 + 32);
    if ( (v190 & 1) != 0 )
    {
      *(_QWORD *)(v185 + 32) = v190 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v185 + 24);
    }
    else
    {
      raw_spin_unlock(v185 + 24);
    }
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: vdev cp stats object is null",
      v177,
      v178,
      v179,
      v180,
      v181,
      v182,
      v183,
      v184,
      "tgt_mc_cp_stats_extract_pmf_bcn_stats");
  }
  wlan_objmgr_vdev_release_ref(v175, 0x26u, v191, v192, v193, v194, v195, v196, v197, v198, v199);
LABEL_172:
  tgt_mc_cp_stats_extract_vdev_extd_stats(a1, a2);
  v380 = 0;
  v381 = 0;
  v378 = 0;
  v379 = 0;
  v376 = 0;
  v377 = nullptr;
  if ( !(unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 1, &v376) && *(_QWORD *)(a2 + 208) && *(_DWORD *)(a2 + 200) )
  {
    v236 = 0;
    v237 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v238 = v236;
      v239 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               a1,
               *(unsigned __int8 *)(*(_QWORD *)(a2 + 208) + 84LL * v236),
               38);
      if ( !v239 )
      {
        qdf_trace_msg(
          0x62u,
          2u,
          "%s: vdev is null",
          v240,
          v241,
          v242,
          v243,
          v244,
          v245,
          v246,
          v247,
          "tgt_mc_cp_stats_extract_vdev_bcn_rssi_history");
        goto LABEL_173;
      }
      v248 = v239;
      v249 = wlan_objmgr_vdev_get_comp_private_obj(v239, 0x1Bu);
      if ( !v249 )
        break;
      v259 = v249;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v237 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v237 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v249 + 24);
      }
      else
      {
        raw_spin_lock_bh(v249 + 24);
        *(_QWORD *)(v259 + 32) |= 1uLL;
      }
      qdf_mem_copy((void *)(*(_QWORD *)(v259 + 8) + 140LL), (const void *)(*(_QWORD *)(a2 + 208) + 84LL * v238), 0x54u);
      v260 = *(_QWORD *)(v259 + 32);
      if ( (v260 & 1) != 0 )
      {
        *(_QWORD *)(v259 + 32) = v260 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v259 + 24);
      }
      else
      {
        raw_spin_unlock(v259 + 24);
      }
      wlan_objmgr_vdev_release_ref(v248, 0x26u, v261, v262, v263, v264, v265, v266, v267, v268, v269);
      v236 = v238 + 1;
      if ( *(_DWORD *)(a2 + 200) <= (unsigned int)(unsigned __int8)(v238 + 1) )
        goto LABEL_173;
    }
    wlan_objmgr_vdev_release_ref(v248, 0x26u, v250, v251, v252, v253, v254, v255, v256, v257, v258);
  }
LABEL_173:
  v235 = *(_DWORD *)(a2 + 148);
  if ( v235 < 0 )
  {
    if ( (v235 & 1) == 0 )
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
    v227,
    v228,
    v229,
    v230,
    v231,
    v232,
    v233,
    v234,
    "tgt_mc_cp_stats_is_last_event");
  ucfg_mc_cp_stats_reset_pending_req(a1, 1, &v370, v369);
  if ( v369[0] == 1 && v371 )
  {
    if ( !BYTE6(v373) )
    {
LABEL_198:
      qdf_trace_msg(
        0x62u,
        8u,
        "Invoking get_station_cb for vdev_id[%d]",
        v270,
        v271,
        v272,
        v273,
        v274,
        v275,
        v276,
        v277,
        (unsigned int)v372);
      tgt_mc_cp_stats_send_raw_station_stats(a1, &v370);
      goto LABEL_10;
    }
    LODWORD(v372) = HIBYTE(v373);
    qdf_mem_copy(&v373, (char *)&v374 + 1, 6u);
    qdf_trace_msg(
      0x62u,
      8u,
      "Invoking get_station_cb for ml vdev_id[%d]",
      v278,
      v279,
      v280,
      v281,
      v282,
      v283,
      v284,
      v285,
      (unsigned int)v372);
    tgt_mc_cp_stats_send_raw_station_stats(a1, &v370);
    if ( BYTE6(v373) > 1u )
    {
      LODWORD(v372) = (unsigned __int8)v374;
      qdf_mem_copy(&v373, (char *)&v374 + 7, 6u);
      qdf_trace_msg(
        0x62u,
        8u,
        "Invoking get_station_cb for ml vdev_id[%d]",
        v286,
        v287,
        v288,
        v289,
        v290,
        v291,
        v292,
        v293,
        (unsigned int)v372);
      tgt_mc_cp_stats_send_raw_station_stats(a1, &v370);
      if ( BYTE6(v373) > 2u )
      {
        __break(0x5512u);
        goto LABEL_198;
      }
    }
  }
LABEL_10:
  if ( (ucfg_mc_cp_stats_is_req_pending(a1, 3) & 1) == 0 )
    goto LABEL_22;
  v29 = *(_QWORD *)(a2 + 112);
  v380 = 0;
  v381 = 0;
  v378 = 0;
  v379 = 0;
  v376 = 0;
  v377 = nullptr;
  LOBYTE(v370) = 0;
  if ( !v29 )
  {
    v30 = "%s: no mib stats";
    v31 = 8;
    goto LABEL_21;
  }
  if ( (unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 3, &v376) )
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
  ucfg_mc_cp_stats_reset_pending_req(a1, 3, &v376, &v370);
  v97 = v377;
  if ( v377 && (unsigned __int8)v370 == 1 )
  {
    v98 = v376;
    if ( *((_DWORD *)v377 - 1) != 488738581 )
      __break(0x8228u);
    v97(a2, v98);
  }
LABEL_22:
  if ( (ucfg_mc_cp_stats_is_req_pending(a1, 4) & 1) == 0 )
    goto LABEL_29;
  v50 = *(_QWORD *)(a2 + 160);
  v380 = 0;
  v381 = 0;
  v378 = 0;
  v379 = 0;
  v376 = 0;
  v377 = nullptr;
  LOBYTE(v370) = 0;
  if ( !v50 || !*(_DWORD *)(a2 + 156) )
  {
    v51 = "%s: no peer_stats_info_ext";
    v52 = 8;
    goto LABEL_28;
  }
  if ( (unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 4, &v376) )
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
  ucfg_mc_cp_stats_reset_pending_req(a1, 4, &v376, &v370);
  v68 = v377;
  if ( v377 && (unsigned __int8)v370 == 1 )
  {
    v69 = v376;
    if ( *((_DWORD *)v377 - 1) != 488738581 )
      __break(0x8228u);
    v68(a2, v69);
  }
LABEL_29:
  if ( (ucfg_mc_cp_stats_is_req_pending(a1, 5) & 1) == 0 )
    goto LABEL_100;
  v61 = *(_DWORD *)(a2 + 148);
  v380 = 0;
  v381 = 0;
  v378 = 0;
  v379 = 0;
  v376 = 0;
  v377 = nullptr;
  v374 = 0;
  v375 = 0;
  v372 = 0;
  v373 = 0;
  v370 = 0;
  v371 = 0;
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
    goto LABEL_68;
  }
LABEL_37:
  if ( (unsigned int)ucfg_mc_cp_stats_get_pending_req(a1, 5, &v376) )
  {
    v63 = "%s: ucfg_mc_cp_stats_get_pending_req failed";
LABEL_68:
    qdf_trace_msg(0x62u, 2u, v63, v53, v54, v55, v56, v57, v58, v59, v60, "tgt_mc_cp_stats_extract_congestion_stats");
    goto LABEL_100;
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
        goto LABEL_88;
    }
    else
    {
      v99 = &v370 + 3 * (v66 & 1);
      *(_BYTE *)v99 = 1;
      *((_DWORD *)v99 + 1) = v65[3];
      *((_DWORD *)v99 + 2) = v65[2];
      *((_DWORD *)v99 + 3) = v65[4];
      if ( v64 <= 1 )
        goto LABEL_88;
    }
    v100 = *(_DWORD **)(a2 + 8);
    v101 = v100[3169];
    if ( (v101 & 0xFE) != 0 )
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
      v103 = &v370 + 3 * (v101 & 1);
      *(_BYTE *)v103 = 1;
      *((_DWORD *)v103 + 1) = v100[3171];
      *((_DWORD *)v103 + 2) = v100[3170];
      *((_DWORD *)v103 + 3) = v100[3172];
    }
  }
LABEL_88:
  v104 = *(_DWORD *)(a2 + 16);
  if ( !v104 )
    goto LABEL_96;
  v105 = *(_DWORD **)(a2 + 24);
  if ( (*v105 & 0xFE) != 0 )
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
      goto LABEL_96;
  }
  else
  {
    v106 = &v370 + 3 * (*v105 & 1);
    *((_BYTE *)v106 + 16) = 1;
    *((_DWORD *)v106 + 5) = v105[1];
    if ( v104 <= 1 )
      goto LABEL_96;
  }
  v107 = *(_QWORD *)(a2 + 24);
  v108 = *(_DWORD *)(v107 + 16);
  if ( (v108 & 0xFE) != 0 )
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
    v109 = &v370 + 3 * (v108 & 1);
    *((_BYTE *)v109 + 16) = 1;
    *((_DWORD *)v109 + 5) = *(_DWORD *)(v107 + 20);
  }
LABEL_96:
  v110 = (void (__fastcall *)(__int64, __int64 *, _QWORD))v377;
  if ( v377 )
  {
    v111 = (unsigned int)v378;
    if ( *((_DWORD *)v377 - 1) != 1252525472 )
      __break(0x8228u);
    v110(v111, &v370, v62);
  }
LABEL_100:
  v112 = *(unsigned __int8 **)(a2 + 80);
  if ( v112 )
  {
    v113 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *v112, 38);
    if ( v113 )
    {
      v122 = v113;
      v123 = wlan_objmgr_vdev_get_comp_private_obj(v113, 0x1Bu);
      if ( v123 )
      {
        v132 = v123;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v133 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v133 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v133 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v123 + 24);
        }
        else
        {
          raw_spin_lock_bh(v123 + 24);
          *(_QWORD *)(v132 + 32) |= 1uLL;
        }
        **(_DWORD **)(v132 + 8) = *(_DWORD *)(*(_QWORD *)(a2 + 80) + 4LL);
        v134 = *(_QWORD *)(v132 + 32);
        if ( (v134 & 1) != 0 )
        {
          *(_QWORD *)(v132 + 32) = v134 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v132 + 24);
        }
        else
        {
          raw_spin_unlock(v132 + 24);
        }
      }
      else
      {
        qdf_trace_msg(
          0x62u,
          2u,
          "%s: vdev cp stats object is null",
          v124,
          v125,
          v126,
          v127,
          v128,
          v129,
          v130,
          v131,
          "tgt_mc_cp_stats_extract_cca_stats");
      }
      wlan_objmgr_vdev_release_ref(v122, 0x26u, v135, v136, v137, v138, v139, v140, v141, v142, v143);
    }
    else
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: vdev is null",
        v114,
        v115,
        v116,
        v117,
        v118,
        v119,
        v120,
        v121,
        "tgt_mc_cp_stats_extract_cca_stats");
    }
  }
  if ( a1 )
  {
    v144 = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu);
    if ( v144 )
    {
      v145 = *(_QWORD *)(v144 + 24);
      if ( v145 )
      {
        v146 = *(void (__fastcall **)(_QWORD))(v145 + 48);
        if ( v146 )
        {
          if ( *((_DWORD *)v146 - 1) != 251140989 )
            __break(0x8228u);
          v146(a2);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
