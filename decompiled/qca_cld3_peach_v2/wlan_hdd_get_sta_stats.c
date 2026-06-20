__int64 __fastcall wlan_hdd_get_sta_stats(__int64 a1, const void *a2, __int64 a3)
{
  __int64 v6; // x23
  unsigned __int8 v7; // w3
  __int64 *v8; // x22
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  __int64 v34; // x9
  const char *v35; // x2
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x20
  __int64 peer_stats_ext; // x0
  __int64 v63; // x22
  int v64; // w8
  char is_legacy_connection; // w0
  unsigned int v66; // w8
  char v67; // w9
  char v68; // w10
  int v69; // w11
  char v70; // w10
  int v71; // w9
  int v72; // w11
  __int64 v73; // x8
  int v74; // w4
  char v75; // w8
  __int64 v76; // x23
  char v77; // w8
  char v78; // w9
  char v79; // w8
  char v80; // w9
  __int64 v81; // x8
  __int64 *v82; // x27
  int v83; // w21
  __int64 v84; // x0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  int v93; // w10
  unsigned int v94; // w23
  unsigned int v95; // w26
  int v96; // w22
  int v97; // w12
  unsigned int v98; // w24
  unsigned int v99; // w25
  char v100; // w9
  int v101; // w28
  int v102; // w21
  bool is_link_speed_report_actual; // w0
  unsigned int v104; // w28
  int v105; // w8
  __int64 vdev_by_user; // x0
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  __int64 v115; // x21
  const char *v116; // x2
  const char *v117; // x3
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  unsigned int v126; // w22
  __int64 v127; // x4
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  __int64 cmpt_obj; // x0
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  unsigned __int8 v153; // w8
  __int64 v154; // x0
  unsigned __int8 v155; // w8
  __int64 v156; // x1
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  unsigned __int8 v165; // w21
  __int64 v166; // x1
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  unsigned __int8 v175; // w0
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  __int16 v192; // w8
  unsigned int v193; // w1
  char v194; // w8
  int v195; // w8
  char v196; // w8
  int v197; // w8
  __int64 v198; // x4
  unsigned int v199; // w22
  __int64 v200; // x4
  double v201; // d0
  double v202; // d1
  double v203; // d2
  double v204; // d3
  double v205; // d4
  double v206; // d5
  double v207; // d6
  double v208; // d7
  unsigned int v209; // w1
  char v210; // w8
  int v211; // w8
  char v212; // w8
  int v213; // w8
  __int64 v214; // x4
  __int64 v215; // x22
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
  __int64 v232; // x0
  __int64 v233; // x22
  _QWORD *context; // x0
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
  int v251; // w8
  int v252; // w9
  int v253; // w8
  int v254; // w9
  int v255; // w8
  int v256; // w9
  int v257; // w8
  int v258; // w21
  int v259; // w9
  __int64 v260; // x25
  __int64 v261; // x23
  __int64 v262; // x8
  unsigned int v263; // w22
  __int64 v264; // x23
  double v265; // d0
  double v266; // d1
  double v267; // d2
  double v268; // d3
  double v269; // d4
  double v270; // d5
  double v271; // d6
  double v272; // d7
  double v273; // d0
  double v274; // d1
  double v275; // d2
  double v276; // d3
  double v277; // d4
  double v278; // d5
  double v279; // d6
  double v280; // d7
  const char *v281; // x2
  const char *v282; // x3
  unsigned int v283; // w1
  _QWORD *v284; // x0
  __int64 v285; // x24
  __int64 v286; // x0
  _QWORD *v287; // x23
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
  unsigned int *v304; // x8
  double v305; // d0
  double v306; // d1
  double v307; // d2
  double v308; // d3
  double v309; // d4
  double v310; // d5
  double v311; // d6
  double v312; // d7
  double v313; // d0
  double v314; // d1
  double v315; // d2
  double v316; // d3
  double v317; // d4
  double v318; // d5
  double v319; // d6
  double v320; // d7
  __int64 v321; // x6
  __int64 v322; // x4
  __int64 v323; // x5
  const char *v324; // x2
  __int64 v325; // x7
  double v326; // d0
  double v327; // d1
  double v328; // d2
  double v329; // d3
  double v330; // d4
  double v331; // d5
  double v332; // d6
  double v333; // d7
  double v334; // d0
  double v335; // d1
  double v336; // d2
  double v337; // d3
  double v338; // d4
  double v339; // d5
  double v340; // d6
  double v341; // d7
  __int64 v342; // x8
  unsigned __int8 v343; // w6
  char v344; // w9
  char v345; // w8
  int v346; // w6
  int v347; // w21
  char v348; // w8
  int v349; // w9
  double v350; // d0
  double v351; // d1
  double v352; // d2
  double v353; // d3
  double v354; // d4
  double v355; // d5
  double v356; // d6
  double v357; // d7
  __int64 v358; // x3
  __int64 v359; // x4
  __int64 v360; // x5
  __int64 v361; // x6
  double v362; // d0
  double v363; // d1
  double v364; // d2
  double v365; // d3
  double v366; // d4
  double v367; // d5
  double v368; // d6
  double v369; // d7
  __int64 v370; // [xsp+0h] [xbp-180h]
  __int64 v371; // [xsp+8h] [xbp-178h]
  __int64 v372; // [xsp+10h] [xbp-170h]
  __int64 v373; // [xsp+18h] [xbp-168h]
  __int64 v374; // [xsp+20h] [xbp-160h]
  __int64 v375; // [xsp+28h] [xbp-158h]
  int v376; // [xsp+74h] [xbp-10Ch]
  __int64 v377; // [xsp+78h] [xbp-108h]
  const void *v378; // [xsp+80h] [xbp-100h]
  unsigned int v379; // [xsp+88h] [xbp-F8h]
  unsigned int v380; // [xsp+8Ch] [xbp-F4h]
  unsigned int v381; // [xsp+90h] [xbp-F0h]
  int v382; // [xsp+94h] [xbp-ECh] BYREF
  unsigned __int8 v383[4]; // [xsp+98h] [xbp-E8h] BYREF
  unsigned __int8 v384[4]; // [xsp+9Ch] [xbp-E4h] BYREF
  __int64 v385; // [xsp+A0h] [xbp-E0h] BYREF
  __int64 v386; // [xsp+A8h] [xbp-D8h]
  __int64 v387; // [xsp+B0h] [xbp-D0h]
  __int64 v388; // [xsp+B8h] [xbp-C8h]
  __int64 v389; // [xsp+C0h] [xbp-C0h]
  __int64 v390; // [xsp+C8h] [xbp-B8h]
  __int64 v391; // [xsp+D0h] [xbp-B0h]
  __int64 v392; // [xsp+D8h] [xbp-A8h]
  __int64 v393; // [xsp+E0h] [xbp-A0h]
  __int64 v394; // [xsp+E8h] [xbp-98h]
  __int64 v395; // [xsp+F0h] [xbp-90h]
  __int64 v396; // [xsp+F8h] [xbp-88h]
  __int64 v397; // [xsp+100h] [xbp-80h]
  __int64 v398; // [xsp+108h] [xbp-78h]
  __int64 v399; // [xsp+110h] [xbp-70h]
  __int64 v400; // [xsp+118h] [xbp-68h]
  __int64 v401; // [xsp+120h] [xbp-60h]
  __int64 v402; // [xsp+128h] [xbp-58h]
  __int64 v403; // [xsp+130h] [xbp-50h]
  __int64 v404; // [xsp+138h] [xbp-48h]
  __int64 v405; // [xsp+140h] [xbp-40h]
  __int64 v406; // [xsp+148h] [xbp-38h]
  __int64 v407; // [xsp+150h] [xbp-30h]
  char v408[4]; // [xsp+158h] [xbp-28h] BYREF
  char v409[4]; // [xsp+15Ch] [xbp-24h] BYREF
  __int64 v410; // [xsp+160h] [xbp-20h] BYREF
  _QWORD v411[3]; // [xsp+168h] [xbp-18h] BYREF

  v411[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)a1;
  v7 = *(_BYTE *)(a1 + 8);
  v382 = 0;
  v8 = *(__int64 **)(v6 + 24);
  qdf_mtrace(51, 51, 0x32u, v7, 0);
  if ( *(unsigned __int8 *)(a1 + 8) != 255 )
  {
    if ( !hdd_cm_is_vdev_associated((_DWORD *)a1) )
    {
      v35 = "%s: Not associated";
LABEL_172:
      result = qdf_trace_msg(0x33u, 8u, v35, v17, v18, v19, v20, v21, v22, v23, v24, "wlan_hdd_get_sta_stats");
      goto LABEL_173;
    }
    if ( hdd_is_roam_sync_in_progress(v8, *(unsigned __int8 *)(a1 + 8)) )
    {
      result = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: Roam sync is in progress, cannot continue with this request",
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 "wlan_hdd_get_sta_stats");
      v34 = *(_QWORD *)a3;
      *(_BYTE *)(a3 + 45) = *(_BYTE *)(a1 + 2688);
      *(_QWORD *)a3 = v34 | 0x80;
      goto LABEL_173;
    }
    if ( *((_BYTE *)v8 + 1819) == 1 )
      wlan_hdd_get_rcpi(v6, a2, &v382, 1, v25, v26, v27, v28, v29, v30, v31, v32);
    wlan_hdd_get_station_stats((_QWORD *)a1);
    wlan_hdd_get_peer_rx_rate_stats(a1);
    if ( (pmo_tgt_is_target_suspended(*v8) & 1) != 0 )
      goto LABEL_31;
    v44 = *(unsigned __int8 *)(a1 + 2861);
    v394 = 0;
    v395 = 0;
    v392 = 0;
    v393 = 0;
    v390 = 0;
    v391 = 0;
    v388 = 0;
    v389 = 0;
    v386 = 0;
    v387 = 0;
    v385 = 0;
    HIDWORD(v411[0]) = 0;
    if ( v44 )
    {
      if ( !*(_BYTE *)(a1 + 2860) )
      {
LABEL_31:
        v378 = a2;
        if ( *(_QWORD *)a1 && (v73 = *(_QWORD *)(*(_QWORD *)a1 + 24LL)) != 0 && *(_QWORD *)(v73 + 16) )
        {
          v74 = *(unsigned __int8 *)(a1 + 2708);
          v75 = *(_BYTE *)(a1 + 2704);
          *(_BYTE *)(a1 + 2688) = v74;
          *(_BYTE *)(a1 + 2689) = v75;
          LOBYTE(v385) = v75;
          if ( !v74 )
          {
            hdd_get_rssi_snr_by_bssid();
            LOBYTE(v74) = *(_BYTE *)(a1 + 2688);
          }
          if ( (v74 & 0x80) == 0 )
          {
            v76 = jiffies;
            if ( wlan_hdd_update_rssi___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Invalid RSSI %d, reset to -1",
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                "wlan_hdd_update_rssi");
              wlan_hdd_update_rssi___last_ticks = v76;
            }
            LOBYTE(v74) = -1;
            *(_BYTE *)(a1 + 2688) = -1;
            *(_BYTE *)(a1 + 2708) = -1;
          }
          *(_BYTE *)(a3 + 45) = v74;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: snr: %d, rssi: %d",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "wlan_hdd_update_rssi",
            *(unsigned int *)(a1 + 2704),
            (unsigned int)*(char *)(a1 + 2708));
          v77 = *(_BYTE *)(a3 + 45);
          v78 = v385;
          *(_BYTE *)(a1 + 840) = v77;
          v79 = v77 - v78;
          *(_BYTE *)(a1 + 732) = v79;
          v80 = *(_BYTE *)(a3 + 45);
          *(_BYTE *)(a1 + 1428) = v79;
          *(_BYTE *)(a1 + 1536) = v80;
          *(_QWORD *)a3 |= 0x80uLL;
        }
        else
        {
          qdf_trace_msg(0x33u, 2u, "%s: mac ctx NULL", v36, v37, v38, v39, v40, v41, v42, v43, "wlan_hdd_update_rssi");
        }
        hdd_lpass_notify_connect(a1);
        v81 = *(_QWORD *)a1;
        v386 = 0;
        v387 = 0;
        v385 = 0;
        v82 = *(__int64 **)(v81 + 24);
        v406 = 0;
        v407 = 0;
        v404 = 0;
        v405 = 0;
        v402 = 0;
        v403 = 0;
        v400 = 0;
        v401 = 0;
        v83 = 1;
        v398 = 0;
        v399 = 0;
        v396 = 0;
        v397 = 0;
        v394 = 0;
        v395 = 0;
        v392 = 0;
        v393 = 0;
        v390 = 0;
        v391 = 0;
        v388 = 0;
        v389 = 0;
        v84 = *v82;
        v410 = 0;
        v411[0] = 0;
        v409[0] = 1;
        v408[0] = 1;
        ucfg_mlme_stats_get_cfg_values(v84, v411, (_DWORD *)&v410 + 1, &v410, (_DWORD *)v411 + 1);
        v93 = *(_DWORD *)(a1 + 2856);
        v94 = *(unsigned __int8 *)(a1 + 2828);
        v95 = *(unsigned __int8 *)(a1 + 2832);
        v96 = *(unsigned __int16 *)(a1 + 2820);
        v97 = *(unsigned __int16 *)(a1 + 2824);
        v98 = *(unsigned __int8 *)(a1 + 2844);
        v99 = *(_DWORD *)(a1 + 2848);
        v380 = *(_DWORD *)(a1 + 2852);
        v381 = *(unsigned __int8 *)(a1 + 2845);
        if ( (v93 & 1) != 0 )
        {
          v105 = 1;
          v104 = *(_DWORD *)(a1 + 2856);
          goto LABEL_60;
        }
        v100 = *(_BYTE *)(a1 + 2809);
        v101 = *(unsigned __int16 *)(a1 + 2824);
        v409[0] = *(_BYTE *)(a1 + 2808);
        v102 = v93;
        v408[0] = v100;
        hdd_check_and_update_nss((__int64)v82, (unsigned __int8 *)v409, (unsigned __int8 *)v408);
        is_link_speed_report_actual = ucfg_mlme_stats_is_link_speed_report_actual(*v82);
        v97 = v101;
        v93 = v102;
        v104 = v102;
        if ( is_link_speed_report_actual )
        {
          if ( v94 == 255 && v96 )
            v93 = 1;
          else
            v93 = *(_DWORD *)(a1 + 2836);
          if ( v95 == 255 && v97 )
          {
            v95 = 0;
            v104 = 1;
            if ( v94 == 255 )
              v94 = 0;
LABEL_59:
            v105 = (unsigned __int8)v409[0];
            v83 = (unsigned __int8)v408[0];
LABEL_60:
            v379 = v93;
            v376 = v97;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: [RSSI %d, RLMS %u, rssi high %d, rssi mid %d, rssi low %d]-[Rate info: TX: %d, RX: %d]-[Rate flags: TX"
              ": 0x%x, RX: 0x%x]-[MCS Index: TX: %d, RX: %d]-[NSS: TX: %d, RX: %d]-[dcm: TX: %d, RX: %d]-[guard interval: TX: %d, RX: %d",
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              v91,
              v92,
              "wlan_hdd_update_rate_info",
              (unsigned int)*(char *)(a3 + 45),
              HIDWORD(v411[0]),
              LODWORD(v411[0]),
              HIDWORD(v410),
              v410,
              v96,
              v97,
              v93,
              v104,
              v94,
              v95,
              v105,
              v83,
              v98,
              v381,
              v99,
              v380);
            vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 0x51u, (__int64)"wlan_hdd_update_rate_info");
            if ( !vdev_by_user )
            {
              result = qdf_trace_msg(0x33u, 8u, "vdev object NULL", v107, v108, v109, v110, v111, v112, v113, v114);
              goto LABEL_173;
            }
            v115 = vdev_by_user;
            v377 = vdev_by_user;
            if ( *(unsigned __int8 *)(a3 + 45) == 128 )
            {
              v116 = "%s: don't fill tx rx rate for inactive link";
              v117 = "wlan_hdd_update_rate_info";
LABEL_63:
              qdf_trace_msg(0x33u, 8u, v116, v107, v108, v109, v110, v111, v112, v113, v114, v117);
              goto LABEL_136;
            }
            if ( !ucfg_mlme_stats_is_link_speed_report_actual(*v82) )
            {
              cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v115, v118, v119, v120, v121, v122, v123, v124, v125);
              if ( cmpt_obj )
                v153 = *(_BYTE *)(cmpt_obj + 23);
              else
                v153 = 0;
              v384[0] = v153;
              v154 = wlan_vdev_mlme_get_cmpt_obj(v115, v145, v146, v147, v148, v149, v150, v151, v152);
              if ( v154 )
                v155 = *(_BYTE *)(v154 + 23);
              else
                v155 = 0;
              v383[0] = v155;
              hdd_check_and_update_nss((__int64)v82, v384, v383);
              v165 = (unsigned __int8)hdd_report_max_rate(
                                        a1,
                                        v157,
                                        v158,
                                        v159,
                                        v160,
                                        v161,
                                        v162,
                                        v163,
                                        v164,
                                        v156,
                                        a3 + 56,
                                        *(_BYTE *)(a3 + 45),
                                        v379,
                                        v94,
                                        v96,
                                        v384[0]);
              v175 = (unsigned __int8)hdd_report_max_rate(
                                        a1,
                                        v167,
                                        v168,
                                        v169,
                                        v170,
                                        v171,
                                        v172,
                                        v173,
                                        v174,
                                        v166,
                                        a3 + 70,
                                        *(_BYTE *)(a3 + 45),
                                        v104,
                                        v95,
                                        v376,
                                        v383[0]);
              if ( (v165 & 1) == 0 || (v175 & 1) == 0 )
              {
                wlan_hdd_fill_os_rate_info(
                  v379,
                  v96,
                  a3 + 56,
                  v94,
                  v409[0],
                  v98,
                  v99,
                  v176,
                  v177,
                  v178,
                  v179,
                  v180,
                  v181,
                  v182,
                  v183);
                wlan_hdd_fill_os_rate_info(
                  v104,
                  v376,
                  a3 + 70,
                  v95,
                  v408[0],
                  v381,
                  v380,
                  v184,
                  v185,
                  v186,
                  v187,
                  v188,
                  v189,
                  v190,
                  v191);
              }
              v115 = v377;
LABEL_136:
              wlan_hdd_fill_summary_stats((_DWORD *)(a1 + 2704), a3, *(unsigned __int8 *)(a1 + 8));
              v215 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
              if ( !(unsigned int)_wlan_hdd_validate_context(
                                    v215,
                                    (__int64)"wlan_hdd_fill_per_link_summary_stats",
                                    v216,
                                    v217,
                                    v218,
                                    v219,
                                    v220,
                                    v221,
                                    v222,
                                    v223) )
              {
                if ( (*(_BYTE *)(v215 + 8238) & 1) != 0 )
                {
                  v232 = _qdf_mem_malloc(0x11C0u, "wlan_hdd_fill_per_link_summary_stats", 5882);
                  if ( v232 )
                  {
                    v233 = v232;
                    context = _cds_get_context(
                                71,
                                (__int64)"wlan_hdd_fill_per_link_summary_stats",
                                v224,
                                v225,
                                v226,
                                v227,
                                v228,
                                v229,
                                v230,
                                v231);
                    if ( (unsigned int)ucfg_dp_get_per_link_peer_stats(
                                         (__int64)context,
                                         v235,
                                         v236,
                                         v237,
                                         v238,
                                         v239,
                                         v240,
                                         v241,
                                         v242) )
                    {
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: Unable to get per link peer stats for the peer: %02x:%02x:%02x:**:**:%02x",
                        v243,
                        v244,
                        v245,
                        v246,
                        v247,
                        v248,
                        v249,
                        v250,
                        "wlan_hdd_fill_per_link_summary_stats",
                        *(unsigned __int8 *)(a1 + 308),
                        *(unsigned __int8 *)(a1 + 309),
                        *(unsigned __int8 *)(a1 + 310),
                        *(unsigned __int8 *)(a1 + 313));
                    }
                    else
                    {
                      *(_QWORD *)(a3 + 92) = 0;
                      v251 = *(_DWORD *)(a1 + 2728);
                      *(_DWORD *)(a3 + 92) = v251;
                      v252 = *(_DWORD *)(a1 + 2768);
                      *(_DWORD *)(a3 + 96) = v252;
                      v253 = *(_DWORD *)(a1 + 2732) + v251;
                      *(_DWORD *)(a3 + 92) = v253;
                      v254 = *(_DWORD *)(a1 + 2772) + v252;
                      *(_DWORD *)(a3 + 96) = v254;
                      v255 = *(_DWORD *)(a1 + 2736) + v253;
                      *(_DWORD *)(a3 + 92) = v255;
                      v256 = *(_DWORD *)(a1 + 2776) + v254;
                      *(_DWORD *)(a3 + 96) = v256;
                      v257 = *(_DWORD *)(a1 + 2740) + v255;
                      *(_DWORD *)(a3 + 92) = v257;
                      v258 = *(_DWORD *)(a1 + 2780) + v256;
                      *(_DWORD *)(a3 + 96) = v258;
                      v259 = *(_DWORD *)(v233 + 128);
                      *(_DWORD *)(a3 + 92) = v259;
                      *(_DWORD *)(a3 + 96) = *(_DWORD *)(v233 + 1836) + v258;
                      v260 = jiffies;
                      if ( wlan_hdd_fill_per_link_summary_stats___last_ticks - jiffies + 125 < 0 )
                      {
                        LODWORD(v371) = v259;
                        LODWORD(v370) = v257;
                        qdf_trace_msg(
                          0x33u,
                          8u,
                          "%s: for peer: %02x:%02x:%02x:**:**:%02xtx retries adjust from %d to %d",
                          v243,
                          v244,
                          v245,
                          v246,
                          v247,
                          v248,
                          v249,
                          v250,
                          "wlan_hdd_fill_per_link_summary_stats",
                          *(unsigned __int8 *)(a1 + 308),
                          *(unsigned __int8 *)(a1 + 309),
                          *(unsigned __int8 *)(a1 + 310),
                          *(unsigned __int8 *)(a1 + 313),
                          v370,
                          v371);
                        wlan_hdd_fill_per_link_summary_stats___last_ticks = v260;
                      }
                      v261 = jiffies;
                      if ( wlan_hdd_fill_per_link_summary_stats___last_ticks_279 - jiffies + 125 < 0 )
                      {
                        LODWORD(v370) = v258;
                        LODWORD(v371) = *(_DWORD *)(a3 + 96);
                        qdf_trace_msg(
                          0x33u,
                          8u,
                          "%s: for peer: %02x:%02x:%02x:**:**:%02xtx failed adjust from %d to %d",
                          v243,
                          v244,
                          v245,
                          v246,
                          v247,
                          v248,
                          v249,
                          v250,
                          "wlan_hdd_fill_per_link_summary_stats",
                          *(unsigned __int8 *)(a1 + 308),
                          *(unsigned __int8 *)(a1 + 309),
                          *(unsigned __int8 *)(a1 + 310),
                          *(unsigned __int8 *)(a1 + 313),
                          v370,
                          v371);
                        wlan_hdd_fill_per_link_summary_stats___last_ticks_279 = v261;
                      }
                    }
                    _qdf_mem_free(v233);
                    v115 = v377;
                  }
                }
                else
                {
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: mlo per link stats is not supported by FW",
                    v224,
                    v225,
                    v226,
                    v227,
                    v228,
                    v229,
                    v230,
                    v231,
                    "wlan_hdd_is_per_link_stats_supported");
                }
              }
              ucfg_dp_get_net_dev_stats(v115, &v385, v224, v225, v226, v227, v228, v229, v230, v231);
              v262 = v388;
              v263 = v386;
              *(_QWORD *)(a3 + 24) = v387;
              *(_QWORD *)(a3 + 32) = v262;
              *(_DWORD *)(a3 + 84) = v385;
              *(_DWORD *)(a3 + 88) = v263;
              v264 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
              if ( (unsigned int)_wlan_hdd_validate_context(
                                   v264,
                                   (__int64)"wlan_hdd_update_mlo_peer_stats",
                                   v265,
                                   v266,
                                   v267,
                                   v268,
                                   v269,
                                   v270,
                                   v271,
                                   v272) )
              {
                v281 = "%s: invalid hdd_ctx";
              }
              else
              {
                v284 = _cds_get_context(
                         71,
                         (__int64)"wlan_hdd_update_mlo_peer_stats",
                         v273,
                         v274,
                         v275,
                         v276,
                         v277,
                         v278,
                         v279,
                         v280);
                if ( (*(_BYTE *)(v264 + 8238) & 1) == 0 )
                {
                  v281 = "%s: mlo per link stats is not supported by FW";
                  v282 = "wlan_hdd_is_per_link_stats_supported";
                  v283 = 8;
                  goto LABEL_154;
                }
                v285 = (__int64)v284;
                v286 = _qdf_mem_malloc(0x11C0u, "wlan_hdd_update_mlo_peer_stats", 8132);
                if ( v286 )
                {
                  v287 = (_QWORD *)v286;
                  ucfg_dp_get_per_link_peer_stats(v285, v273, v274, v275, v276, v277, v278, v279, v280);
                  *(_QWORD *)(a3 + 32) = v287[12];
                  *(_QWORD *)(a3 + 24) = v287[363];
                  *(_DWORD *)(a3 + 88) = v287[11];
                  *(_DWORD *)(a3 + 84) = v287[362];
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "Updated sinfo with per peer stats",
                    v288,
                    v289,
                    v290,
                    v291,
                    v292,
                    v293,
                    v294,
                    v295);
                  _qdf_mem_free((__int64)v287);
LABEL_155:
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: TX packets dp_intf %d mlo adjusted %d",
                    v296,
                    v297,
                    v298,
                    v299,
                    v300,
                    v301,
                    v302,
                    v303,
                    "wlan_hdd_update_rate_info",
                    v263,
                    *(unsigned int *)(a3 + 88));
                  _hdd_objmgr_put_vdev_by_user(
                    v377,
                    0x51u,
                    (__int64)"wlan_hdd_update_rate_info",
                    v304,
                    v305,
                    v306,
                    v307,
                    v308,
                    v309,
                    v310,
                    v311,
                    v312);
                  qdf_mem_copy((void *)(a1 + 704), (const void *)(a3 + 56), 0xEu);
                  qdf_mem_copy((void *)(a1 + 1400), (const void *)(a3 + 56), 0xEu);
                  qdf_mem_copy((void *)(a1 + 718), (const void *)(a3 + 70), 0xEu);
                  *(_QWORD *)a3 |= 0x430CuLL;
                  if ( (v379 & 1) != 0 )
                  {
                    v325 = *(unsigned int *)(a3 + 84);
                    v323 = *(unsigned int *)(a3 + 88);
                    v322 = *(unsigned __int16 *)(a3 + 58);
                    v321 = *(unsigned __int16 *)(a3 + 72);
                    v324 = "%s: [TX: Reporting legacy rate %d pkt cnt %d]-[RX: Reporting legacy rate %d pkt cnt %d]";
                  }
                  else
                  {
                    v321 = *(unsigned int *)(a3 + 88);
                    v322 = *(unsigned __int8 *)(a3 + 60);
                    v323 = *(unsigned __int16 *)(a3 + 56);
                    v324 = "%s: [TX: Reporting MCS rate %d, flags 0x%x pkt cnt %d, nss %d, bw %d]-[RX: Reporting MCS rate"
                           " %d, flags 0x%x pkt cnt %d, nss %d, bw %d]";
                    v325 = *(unsigned __int8 *)(a3 + 61);
                    LODWORD(v373) = *(_DWORD *)(a3 + 84);
                    LODWORD(v375) = *(unsigned __int8 *)(a3 + 76);
                    LODWORD(v374) = *(unsigned __int8 *)(a3 + 75);
                    LODWORD(v372) = *(unsigned __int16 *)(a3 + 70);
                    LODWORD(v371) = *(unsigned __int8 *)(a3 + 74);
                    LODWORD(v370) = *(unsigned __int8 *)(a3 + 62);
                  }
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    v324,
                    v313,
                    v314,
                    v315,
                    v316,
                    v317,
                    v318,
                    v319,
                    v320,
                    "wlan_hdd_update_rate_info",
                    v322,
                    v323,
                    v321,
                    v325,
                    v370,
                    v371,
                    v372,
                    v373,
                    v374,
                    v375);
                  *(_DWORD *)(a3 + 212) = *(_DWORD *)(a1 + 4512);
                  *(_DWORD *)(a3 + 216) = *(_DWORD *)(a1 + 4528);
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: RX mpdu count %d fcs_err_count %d",
                    v326,
                    v327,
                    v328,
                    v329,
                    v330,
                    v331,
                    v332,
                    v333,
                    "hdd_fill_fcs_and_mpdu_count");
                  v342 = *(_QWORD *)a3;
                  *(_BYTE *)(a3 + 46) = 0x80;
                  *(_QWORD *)a3 = v342 | 0x3000000000LL;
                  v343 = *(_BYTE *)(a1 + 2948);
                  if ( v343 )
                  {
                    v344 = *(_BYTE *)(a3 + 47);
                    v345 = *(_BYTE *)(a1 + 2948);
                    *(_BYTE *)(a3 + 52) = v343;
                    *(_BYTE *)(a3 + 47) = v344 | 1;
                    if ( v343 != 128 )
                      *(_BYTE *)(a3 + 46) = v345;
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: RSSI for chain %d, vdev_id %d is %d",
                      v334,
                      v335,
                      v336,
                      v337,
                      v338,
                      v339,
                      v340,
                      v341,
                      "hdd_wlan_fill_per_chain_rssi_stats",
                      0,
                      *(unsigned __int8 *)(a1 + 8));
                  }
                  v346 = *(char *)(a1 + 2949);
                  v347 = *(unsigned __int8 *)(a3 + 52);
                  if ( *(_BYTE *)(a1 + 2949) )
                  {
                    v348 = *(_BYTE *)(a3 + 47);
                    v349 = *(char *)(a3 + 46);
                    *(_BYTE *)(a3 + 53) = v346;
                    *(_BYTE *)(a3 + 47) = v348 | 2;
                    if ( v346 > v349 )
                      *(_BYTE *)(a3 + 46) = v346;
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: RSSI for chain %d, vdev_id %d is %d",
                      v334,
                      v335,
                      v336,
                      v337,
                      v338,
                      v339,
                      v340,
                      v341,
                      "hdd_wlan_fill_per_chain_rssi_stats",
                      1,
                      *(unsigned __int8 *)(a1 + 8));
                  }
                  if ( v347 || *(_BYTE *)(a3 + 53) )
                    *(_QWORD *)a3 |= 0x4002000uLL;
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "Sending station stats for link %02x:%02x:%02x:**:**:%02x",
                    v334,
                    v335,
                    v336,
                    v337,
                    v338,
                    v339,
                    v340,
                    v341,
                    *(unsigned __int8 *)(a1 + 308),
                    *(unsigned __int8 *)(a1 + 309),
                    *(unsigned __int8 *)(a1 + 310),
                    *(unsigned __int8 *)(a1 + 313));
                  if ( (wlan_hdd_is_mlo_connection(a1, v350, v351, v352, v353, v354, v355, v356, v357) & 1) != 0 )
                  {
                    *(_BYTE *)(a1 + 5320) = *(_BYTE *)(a3 + 45);
                    *(_BYTE *)(a1 + 5321) = *(_BYTE *)(a3 + 46);
                    *(_BYTE *)(a1 + 5323) = *(_BYTE *)(a3 + 52);
                    *(_BYTE *)(a1 + 5324) = *(_BYTE *)(a3 + 53);
                    *(_BYTE *)(a1 + 5325) = *(_BYTE *)(a3 + 54);
                    *(_BYTE *)(a1 + 5326) = *(_BYTE *)(a3 + 55);
                    *(_BYTE *)(a1 + 5322) = *(_BYTE *)(a3 + 47);
                    qdf_mem_copy((void *)(a1 + 5328), (const void *)(a3 + 56), 0xEu);
                    qdf_mem_copy((void *)(a1 + 5342), (const void *)(a3 + 70), 0xEu);
                    v358 = *(unsigned __int8 *)(a1 + 308);
                    v359 = *(unsigned __int8 *)(a1 + 309);
                    v360 = *(unsigned __int8 *)(a1 + 310);
                    *(_QWORD *)(a1 + 5360) = *(_QWORD *)(a3 + 24);
                    v361 = *(unsigned __int8 *)(a1 + 313);
                    *(_QWORD *)(a1 + 5368) = *(_QWORD *)(a3 + 32);
                    *(_DWORD *)(a1 + 5376) = *(_DWORD *)(a3 + 84);
                    *(_DWORD *)(a1 + 5380) = *(_DWORD *)(a3 + 88);
                    *(_DWORD *)(a1 + 5384) = *(_DWORD *)(a3 + 92);
                    *(_DWORD *)(a1 + 5388) = *(_DWORD *)(a3 + 96);
                    *(_DWORD *)(a1 + 5392) = *(_DWORD *)(a3 + 212);
                    *(_DWORD *)(a1 + 5396) = *(_DWORD *)(a3 + 216);
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "copied sinfo for %02x:%02x:%02x:**:**:%02x into link_info",
                      v362,
                      v363,
                      v364,
                      v365,
                      v366,
                      v367,
                      v368,
                      v369,
                      v358,
                      v359,
                      v360,
                      v361);
                  }
                  wlan_hdd_fill_send_get_sta_ucast_stats(a1, v378, a3);
                  v35 = "%s: exit";
                  goto LABEL_172;
                }
                v281 = "%s: Failed to allocated memory for peer_stats";
              }
              v282 = "wlan_hdd_update_mlo_peer_stats";
              v283 = 2;
LABEL_154:
              qdf_trace_msg(0x33u, v283, v281, v273, v274, v275, v276, v277, v278, v279, v280, v282);
              goto LABEL_155;
            }
            if ( !*(_BYTE *)(a1 + 2860) )
            {
              wlan_hdd_fill_os_rate_info(
                v379,
                v96,
                a3 + 56,
                v94,
                v409[0],
                v98,
                v99,
                v118,
                v119,
                v120,
                v121,
                v122,
                v123,
                v124,
                v125);
              goto LABEL_109;
            }
            v126 = *(unsigned __int8 *)(a1 + 2810);
            *(_BYTE *)(a3 + 61) = *(_BYTE *)(a1 + 2808);
            if ( v126 <= 1 )
            {
              qdf_mem_set((void *)(a3 + 56), 0xEu, 0);
              v127 = (unsigned __int16)*(_DWORD *)(a1 + 2820);
              *(_WORD *)(a3 + 58) = *(_DWORD *)(a1 + 2820);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Reporting legacy rate %d",
                v128,
                v129,
                v130,
                v131,
                v132,
                v133,
                v134,
                v135,
                "wlan_hdd_refill_actual_tx_rate",
                v127);
              goto LABEL_109;
            }
            if ( v126 == 255 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Driver failed to get rate",
                v118,
                v119,
                v120,
                v121,
                v122,
                v123,
                v124,
                v125,
                "wlan_hdd_refill_actual_tx_rate");
              if ( *(_WORD *)(a3 + 58) )
              {
LABEL_82:
                if ( v126 != 4 )
                  goto LABEL_83;
                goto LABEL_90;
              }
            }
            else if ( *(_WORD *)(a3 + 58) )
            {
              goto LABEL_82;
            }
            *(_WORD *)(a3 + 58) = 60;
            if ( v126 != 4 )
            {
LABEL_83:
              if ( v126 == 3 )
              {
                v192 = *(_WORD *)(a3 + 56) | 2;
              }
              else
              {
                if ( v126 != 2 )
                {
                  wlan_hdd_refill_os_eht_rateflags(a3 + 56, v126);
                  goto LABEL_92;
                }
                v192 = *(_WORD *)(a3 + 56) | 1;
              }
LABEL_91:
              *(_WORD *)(a3 + 56) = v192;
LABEL_92:
              *(_BYTE *)(a3 + 60) = *(_DWORD *)(a1 + 2828);
              v193 = *(unsigned __int8 *)(a1 + 2812);
              if ( v193 > 1 )
              {
                if ( v193 == 2 )
                {
                  v194 = 4;
                  goto LABEL_102;
                }
                if ( v193 == 3 )
                {
                  v194 = 5;
                  goto LABEL_102;
                }
              }
              else
              {
                if ( !*(_BYTE *)(a1 + 2812) )
                {
                  *(_BYTE *)(a3 + 62) = 0;
                  goto LABEL_103;
                }
                if ( v193 == 1 )
                {
                  v194 = 3;
LABEL_102:
                  *(_BYTE *)(a3 + 62) = v194;
                  goto LABEL_103;
                }
              }
              wlan_hdd_refill_os_eht_bw(a3 + 56);
LABEL_103:
              v195 = *(_DWORD *)(a1 + 2848);
              *(_BYTE *)(a3 + 64) = 0;
              if ( v195 == 3 )
                v196 = 2;
              else
                v196 = v195 == 2;
              *(_BYTE *)(a3 + 63) = v196;
              v197 = *(unsigned __int16 *)(a3 + 56);
              v198 = *(unsigned int *)(a1 + 2848);
              if ( (_DWORD)v198 == 1 )
              {
                v197 |= 4u;
                *(_WORD *)(a3 + 56) = v197;
                v198 = *(unsigned int *)(a1 + 2848);
              }
              LODWORD(v371) = v197;
              LODWORD(v370) = *(unsigned __int8 *)(a1 + 2808);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: sgi=%d, preamble=%d, bw=%d, mcs=%d, nss=%d, rate_flag=0x%x",
                v118,
                v119,
                v120,
                v121,
                v122,
                v123,
                v124,
                v125,
                "wlan_hdd_refill_actual_tx_rate",
                v198,
                v126,
                *(unsigned __int8 *)(a1 + 2812),
                *(unsigned int *)(a1 + 2828),
                v370,
                v371);
LABEL_109:
              wlan_hdd_fill_os_rate_info(
                v104,
                v376,
                a3 + 70,
                v95,
                v408[0],
                v381,
                v380,
                v136,
                v137,
                v138,
                v139,
                v140,
                v141,
                v142,
                v143);
              v199 = *(unsigned __int8 *)(a1 + 2811);
              *(_BYTE *)(a3 + 75) = *(_BYTE *)(a1 + 2809);
              if ( v199 <= 1 )
              {
                qdf_mem_set((void *)(a3 + 70), 0xEu, 0);
                v200 = (unsigned __int16)*(_DWORD *)(a1 + 2824);
                *(_WORD *)(a3 + 72) = *(_DWORD *)(a1 + 2824);
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: Reporting legacy rate %d",
                  v201,
                  v202,
                  v203,
                  v204,
                  v205,
                  v206,
                  v207,
                  v208,
                  "wlan_hdd_refill_actual_rate",
                  v200);
                goto LABEL_136;
              }
              if ( (int)v199 > 3 )
              {
                if ( v199 == 4 )
                {
                  *(_WORD *)(a3 + 70) |= 0x10u;
                }
                else
                {
                  if ( v199 == 255 )
                  {
                    v116 = "%s: Driver failed to get rate, reporting FW rate";
                    v117 = "wlan_hdd_refill_actual_rate";
                    goto LABEL_63;
                  }
                  wlan_hdd_refill_os_eht_rateflags(a3 + 70, v199);
                }
              }
              else if ( v199 == 2 )
              {
                *(_WORD *)(a3 + 70) |= 1u;
              }
              else
              {
                *(_WORD *)(a3 + 70) |= 2u;
              }
              *(_BYTE *)(a3 + 74) = *(_DWORD *)(a1 + 2832);
              v209 = *(unsigned __int8 *)(a1 + 2813);
              if ( v209 > 1 )
              {
                if ( v209 == 2 )
                {
                  v210 = 4;
                  goto LABEL_129;
                }
                if ( v209 == 3 )
                {
                  v210 = 5;
                  goto LABEL_129;
                }
              }
              else
              {
                if ( !*(_BYTE *)(a1 + 2813) )
                {
                  *(_BYTE *)(a3 + 76) = 0;
                  goto LABEL_130;
                }
                if ( v209 == 1 )
                {
                  v210 = 3;
LABEL_129:
                  *(_BYTE *)(a3 + 76) = v210;
                  goto LABEL_130;
                }
              }
              wlan_hdd_refill_os_eht_bw(a3 + 70);
LABEL_130:
              v211 = *(_DWORD *)(a1 + 2852);
              *(_BYTE *)(a3 + 78) = 0;
              if ( v211 == 3 )
                v212 = 2;
              else
                v212 = v211 == 2;
              *(_BYTE *)(a3 + 77) = v212;
              v213 = *(unsigned __int16 *)(a3 + 70);
              v214 = *(unsigned int *)(a1 + 2852);
              if ( (_DWORD)v214 == 1 )
              {
                v213 |= 4u;
                *(_WORD *)(a3 + 70) = v213;
                v214 = *(unsigned int *)(a1 + 2852);
              }
              LODWORD(v371) = v213;
              LODWORD(v370) = *(unsigned __int8 *)(a1 + 2809);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: sgi=%d, preamble=%d, bw=%d, mcs=%d, nss=%d, rate_flag=0x%x",
                v107,
                v108,
                v109,
                v110,
                v111,
                v112,
                v113,
                v114,
                "wlan_hdd_refill_actual_rate",
                v214,
                v199,
                *(unsigned __int8 *)(a1 + 2813),
                *(unsigned int *)(a1 + 2832),
                v370,
                v371);
              goto LABEL_136;
            }
LABEL_90:
            v192 = *(_WORD *)(a3 + 56) | 0x10;
            goto LABEL_91;
          }
          v104 = *(_DWORD *)(a1 + 2840);
        }
        if ( v94 == 255 )
          v94 = 0;
        if ( v95 == 255 )
          v95 = 0;
        goto LABEL_59;
      }
    }
    if ( hdd_cm_is_vdev_roaming(a1) )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Roaming in progress",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "wlan_hdd_get_sta_tx_rate_stats");
      goto LABEL_31;
    }
    peer_stats_ext = wlan_cfg80211_mc_cp_stats_get_peer_stats_ext(*(_QWORD *)(a1 + 32), a1 + 308, (char *)v411 + 4);
    if ( HIDWORD(v411[0]) )
      goto LABEL_31;
    v63 = peer_stats_ext;
    wlan_hdd_fill_rate_info((__int64)&v385, *(_DWORD **)(peer_stats_ext + 160));
    v64 = BYTE2(v393);
    *(_BYTE *)(a1 + 2861) = 1;
    *(_BYTE *)(a1 + 2860) = v64;
    if ( v64 )
    {
      is_legacy_connection = hdd_is_legacy_connection(a1);
      v66 = v391;
      if ( (is_legacy_connection & 1) != 0 )
      {
        v67 = BYTE4(v391);
        *(_DWORD *)(a1 + 2820) = (unsigned int)v391 / 0x64;
      }
      else
      {
        v67 = BYTE4(v391);
        if ( (unsigned int)v391 >> 2 >= 0x659 && BYTE4(v391) >= 2u )
        {
          *(_BYTE *)(a1 + 2810) = BYTE4(v391);
          v68 = v393;
          v69 = BYTE6(v391);
          *(_BYTE *)(a1 + 2808) = BYTE5(v391);
          *(_BYTE *)(a1 + 2812) = v68;
          v70 = BYTE1(v393);
          *(_DWORD *)(a1 + 2828) = v69;
          v72 = v392;
          v71 = HIDWORD(v392);
          *(_BYTE *)(a1 + 2844) = v70;
          *(_DWORD *)(a1 + 2848) = v71;
          *(_DWORD *)(a1 + 2820) = v66 / 0x64;
          *(_DWORD *)(a1 + 2836) = v72;
          goto LABEL_30;
        }
        if ( (unsigned int)v391 >> 2 > 0x658 )
          goto LABEL_30;
        *(_DWORD *)(a1 + 2820) = (unsigned __int16)v391 / 0x64u;
      }
      *(_BYTE *)(a1 + 2810) = v67;
    }
LABEL_30:
    wlan_cfg80211_mc_cp_stats_free_stats_event(v63);
    goto LABEL_31;
  }
  if ( a1 )
  {
    wlan_hdd_copy_hdd_stats_to_sinfo(a3, a1 + 5320);
    if ( *(unsigned __int8 *)(a1 + 8) == 255 )
    {
      *(_WORD *)(a3 + 45) = -32640;
      *(_DWORD *)(a3 + 52) = -2139062144;
    }
    *(_QWORD *)a3 |= 0x3004007F8CuLL;
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid link_info", v9, v10, v11, v12, v13, v14, v15, v16, "wlan_hdd_update_sinfo");
  }
  result = wlan_hdd_fill_send_get_sta_ucast_stats(a1, a2, a3);
  v61 = jiffies;
  if ( wlan_hdd_get_sta_stats___last_ticks - jiffies + 125 < 0 )
  {
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: Sending Cached stats for standby link",
               v53,
               v54,
               v55,
               v56,
               v57,
               v58,
               v59,
               v60,
               "wlan_hdd_get_sta_stats");
    wlan_hdd_get_sta_stats___last_ticks = v61;
  }
LABEL_173:
  _ReadStatusReg(SP_EL0);
  return result;
}
