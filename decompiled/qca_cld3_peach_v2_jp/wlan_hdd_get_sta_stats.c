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
  __int64 result; // x0
  __int64 v26; // x9
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x20
  const char *v36; // x2
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int v45; // w8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 peer_stats_ext; // x0
  __int64 v55; // x22
  int v56; // w8
  char is_legacy_connection; // w0
  unsigned int v58; // w8
  char v59; // w9
  char v60; // w10
  int v61; // w11
  char v62; // w10
  int v63; // w9
  int v64; // w11
  __int64 v65; // x8
  int v66; // w4
  char v67; // w8
  __int64 v68; // x24
  char v69; // w8
  char v70; // w9
  char v71; // w8
  char v72; // w9
  __int64 v73; // x8
  int v74; // w25
  __int64 *v75; // x28
  __int64 v76; // x0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  int v85; // w22
  unsigned int v86; // w24
  unsigned int v87; // w26
  int v88; // w23
  int v89; // w11
  int v90; // w27
  char v91; // w9
  int v92; // w25
  bool is_link_speed_report_actual; // w0
  int v94; // w12
  int v95; // w8
  __int64 vdev_by_user; // x0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  __int64 v105; // x25
  const char *v106; // x2
  const char *v107; // x3
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  __int64 v116; // x5
  __int64 v117; // x4
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  __int64 cmpt_obj; // x0
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  unsigned __int8 v143; // w8
  __int64 v144; // x0
  unsigned __int8 v145; // w8
  __int64 v146; // x1
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  unsigned __int8 v155; // w25
  __int64 v156; // x1
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  unsigned __int8 v165; // w0
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  double v174; // d0
  double v175; // d1
  double v176; // d2
  double v177; // d3
  double v178; // d4
  double v179; // d5
  double v180; // d6
  double v181; // d7
  unsigned int v182; // w8
  int v183; // w8
  char v184; // w8
  int v185; // w8
  __int64 v186; // x4
  __int64 v187; // x5
  __int64 v188; // x4
  double v189; // d0
  double v190; // d1
  double v191; // d2
  double v192; // d3
  double v193; // d4
  double v194; // d5
  double v195; // d6
  double v196; // d7
  __int16 v197; // w8
  unsigned int v198; // w8
  int v199; // w8
  char v200; // w8
  int v201; // w8
  __int64 v202; // x4
  double v203; // d0
  double v204; // d1
  double v205; // d2
  double v206; // d3
  double v207; // d4
  double v208; // d5
  double v209; // d6
  double v210; // d7
  double v211; // d0
  double v212; // d1
  double v213; // d2
  double v214; // d3
  double v215; // d4
  double v216; // d5
  double v217; // d6
  double v218; // d7
  __int64 v219; // x8
  unsigned int v220; // w23
  double v221; // d0
  double v222; // d1
  double v223; // d2
  double v224; // d3
  double v225; // d4
  double v226; // d5
  double v227; // d6
  double v228; // d7
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
  unsigned int *v245; // x8
  double v246; // d0
  double v247; // d1
  double v248; // d2
  double v249; // d3
  double v250; // d4
  double v251; // d5
  double v252; // d6
  double v253; // d7
  double v254; // d0
  double v255; // d1
  double v256; // d2
  double v257; // d3
  double v258; // d4
  double v259; // d5
  double v260; // d6
  double v261; // d7
  __int64 v262; // x6
  __int64 v263; // x4
  __int64 v264; // x5
  const char *v265; // x2
  __int64 v266; // x7
  double v267; // d0
  double v268; // d1
  double v269; // d2
  double v270; // d3
  double v271; // d4
  double v272; // d5
  double v273; // d6
  double v274; // d7
  double v275; // d0
  double v276; // d1
  double v277; // d2
  double v278; // d3
  double v279; // d4
  double v280; // d5
  double v281; // d6
  double v282; // d7
  __int64 v283; // x8
  unsigned __int8 v284; // w6
  char v285; // w9
  char v286; // w8
  int v287; // w6
  int v288; // w22
  char v289; // w8
  int v290; // w9
  __int64 v291; // [xsp+0h] [xbp-170h]
  __int64 v292; // [xsp+8h] [xbp-168h]
  __int64 v293; // [xsp+10h] [xbp-160h]
  __int64 v294; // [xsp+18h] [xbp-158h]
  __int64 v295; // [xsp+20h] [xbp-150h]
  __int64 v296; // [xsp+28h] [xbp-148h]
  __int64 v297; // [xsp+68h] [xbp-108h]
  unsigned int v298; // [xsp+70h] [xbp-100h]
  int v299; // [xsp+74h] [xbp-FCh]
  int v300; // [xsp+78h] [xbp-F8h]
  int v301; // [xsp+7Ch] [xbp-F4h]
  int v302; // [xsp+80h] [xbp-F0h]
  int v303; // [xsp+84h] [xbp-ECh] BYREF
  unsigned __int8 v304[4]; // [xsp+88h] [xbp-E8h] BYREF
  unsigned __int8 v305[4]; // [xsp+8Ch] [xbp-E4h] BYREF
  __int64 v306; // [xsp+90h] [xbp-E0h] BYREF
  __int64 v307; // [xsp+98h] [xbp-D8h]
  __int64 v308; // [xsp+A0h] [xbp-D0h]
  __int64 v309; // [xsp+A8h] [xbp-C8h]
  __int64 v310; // [xsp+B0h] [xbp-C0h]
  __int64 v311; // [xsp+B8h] [xbp-B8h]
  __int64 v312; // [xsp+C0h] [xbp-B0h]
  __int64 v313; // [xsp+C8h] [xbp-A8h]
  __int64 v314; // [xsp+D0h] [xbp-A0h]
  __int64 v315; // [xsp+D8h] [xbp-98h]
  __int64 v316; // [xsp+E0h] [xbp-90h]
  __int64 v317; // [xsp+E8h] [xbp-88h]
  __int64 v318; // [xsp+F0h] [xbp-80h]
  __int64 v319; // [xsp+F8h] [xbp-78h]
  __int64 v320; // [xsp+100h] [xbp-70h]
  __int64 v321; // [xsp+108h] [xbp-68h]
  __int64 v322; // [xsp+110h] [xbp-60h]
  __int64 v323; // [xsp+118h] [xbp-58h]
  __int64 v324; // [xsp+120h] [xbp-50h]
  __int64 v325; // [xsp+128h] [xbp-48h]
  __int64 v326; // [xsp+130h] [xbp-40h]
  __int64 v327; // [xsp+138h] [xbp-38h]
  __int64 v328; // [xsp+140h] [xbp-30h]
  char v329[4]; // [xsp+148h] [xbp-28h] BYREF
  char v330[4]; // [xsp+14Ch] [xbp-24h] BYREF
  __int64 v331; // [xsp+150h] [xbp-20h] BYREF
  _QWORD v332[3]; // [xsp+158h] [xbp-18h] BYREF

  v332[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)a1;
  v7 = *(_BYTE *)(a1 + 8);
  v303 = 0;
  v8 = *(__int64 **)(v6 + 24);
  qdf_mtrace(51, 51, 0x32u, v7, 0);
  if ( *(unsigned __int8 *)(a1 + 8) != 255 )
  {
    if ( !hdd_cm_is_vdev_associated((_DWORD *)a1) )
    {
      v36 = "%s: Not associated";
LABEL_123:
      result = qdf_trace_msg(0x33u, 8u, v36, v9, v10, v11, v12, v13, v14, v15, v16, "wlan_hdd_get_sta_stats");
      goto LABEL_124;
    }
    if ( hdd_is_roam_sync_in_progress(v8, *(unsigned __int8 *)(a1 + 8)) )
    {
      result = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: Roam sync is in progress, cannot continue with this request",
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 "wlan_hdd_get_sta_stats");
      v26 = *(_QWORD *)a3;
      *(_BYTE *)(a3 + 45) = *(_BYTE *)(a1 + 2416);
      *(_QWORD *)a3 = v26 | 0x80;
      goto LABEL_124;
    }
    if ( *((_BYTE *)v8 + 1819) == 1 )
      wlan_hdd_get_rcpi(v6, a2, &v303, 1, v17, v18, v19, v20, v21, v22, v23, v24);
    wlan_hdd_get_station_stats((__int64 *)a1);
    wlan_hdd_get_peer_rx_rate_stats(a1);
    if ( (pmo_tgt_is_target_suspended(*v8) & 1) != 0 )
      goto LABEL_26;
    v45 = *(unsigned __int8 *)(a1 + 2589);
    v315 = 0;
    v316 = 0;
    v313 = 0;
    v314 = 0;
    v311 = 0;
    v312 = 0;
    v309 = 0;
    v310 = 0;
    v307 = 0;
    v308 = 0;
    v306 = 0;
    HIDWORD(v332[0]) = 0;
    if ( v45 )
    {
      if ( !*(_BYTE *)(a1 + 2588) )
      {
LABEL_26:
        if ( *(_QWORD *)a1 && (v65 = *(_QWORD *)(*(_QWORD *)a1 + 24LL)) != 0 && *(_QWORD *)(v65 + 16) )
        {
          v66 = *(unsigned __int8 *)(a1 + 2436);
          v67 = *(_BYTE *)(a1 + 2432);
          *(_BYTE *)(a1 + 2416) = v66;
          *(_BYTE *)(a1 + 2417) = v67;
          LOBYTE(v306) = v67;
          if ( !v66 )
          {
            hdd_get_rssi_snr_by_bssid();
            LOBYTE(v66) = *(_BYTE *)(a1 + 2416);
          }
          if ( (v66 & 0x80) == 0 )
          {
            v68 = jiffies;
            if ( wlan_hdd_update_rssi___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Invalid RSSI %d, reset to -1",
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                "wlan_hdd_update_rssi");
              wlan_hdd_update_rssi___last_ticks = v68;
            }
            LOBYTE(v66) = -1;
            *(_BYTE *)(a1 + 2416) = -1;
            *(_BYTE *)(a1 + 2436) = -1;
          }
          *(_BYTE *)(a3 + 45) = v66;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: snr: %d, rssi: %d",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "wlan_hdd_update_rssi",
            *(unsigned int *)(a1 + 2432),
            (unsigned int)*(char *)(a1 + 2436));
          v69 = *(_BYTE *)(a3 + 45);
          v70 = v306;
          *(_BYTE *)(a1 + 832) = v69;
          v71 = v69 - v70;
          *(_BYTE *)(a1 + 724) = v71;
          v72 = *(_BYTE *)(a3 + 45);
          *(_BYTE *)(a1 + 1404) = v71;
          *(_BYTE *)(a1 + 1512) = v72;
          *(_QWORD *)a3 |= 0x80uLL;
        }
        else
        {
          qdf_trace_msg(0x33u, 2u, "%s: mac ctx NULL", v37, v38, v39, v40, v41, v42, v43, v44, "wlan_hdd_update_rssi");
        }
        hdd_lpass_notify_connect(a1);
        v73 = *(_QWORD *)a1;
        v307 = 0;
        v308 = 0;
        v74 = 1;
        v306 = 0;
        v75 = *(__int64 **)(v73 + 24);
        v327 = 0;
        v328 = 0;
        v325 = 0;
        v326 = 0;
        v323 = 0;
        v324 = 0;
        v321 = 0;
        v322 = 0;
        v319 = 0;
        v320 = 0;
        v317 = 0;
        v318 = 0;
        v315 = 0;
        v316 = 0;
        v313 = 0;
        v314 = 0;
        v311 = 0;
        v312 = 0;
        v309 = 0;
        v310 = 0;
        v76 = *v75;
        v331 = 0;
        v332[0] = 0;
        v330[0] = 1;
        v329[0] = 1;
        ucfg_mlme_stats_get_cfg_values(v76, v332, (_DWORD *)&v331 + 1, &v331, (_DWORD *)v332 + 1);
        v85 = *(_DWORD *)(a1 + 2584);
        v86 = *(unsigned __int8 *)(a1 + 2556);
        v87 = *(unsigned __int8 *)(a1 + 2560);
        v88 = *(unsigned __int16 *)(a1 + 2548);
        v89 = *(unsigned __int16 *)(a1 + 2552);
        v302 = *(unsigned __int8 *)(a1 + 2573);
        v90 = *(_DWORD *)(a1 + 2576);
        v300 = *(unsigned __int8 *)(a1 + 2572);
        v301 = *(_DWORD *)(a1 + 2580);
        if ( (v85 & 1) != 0 )
        {
          v95 = 1;
          v94 = *(_DWORD *)(a1 + 2584);
          goto LABEL_55;
        }
        v91 = *(_BYTE *)(a1 + 2537);
        v92 = *(unsigned __int16 *)(a1 + 2552);
        v330[0] = *(_BYTE *)(a1 + 2536);
        v329[0] = v91;
        hdd_check_and_update_nss((__int64)v75, (unsigned __int8 *)v330, (unsigned __int8 *)v329);
        is_link_speed_report_actual = ucfg_mlme_stats_is_link_speed_report_actual(*v75);
        v89 = v92;
        v94 = v85;
        if ( is_link_speed_report_actual )
        {
          if ( v86 == 255 && v88 )
            v85 = 1;
          else
            v85 = *(_DWORD *)(a1 + 2564);
          if ( v87 == 255 && v92 )
          {
            v87 = 0;
            v94 = 1;
            if ( v86 == 255 )
              v86 = 0;
LABEL_54:
            v95 = (unsigned __int8)v330[0];
            v74 = (unsigned __int8)v329[0];
LABEL_55:
            v298 = v94;
            v299 = v89;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: [RSSI %d, RLMS %u, rssi high %d, rssi mid %d, rssi low %d]-[Rate info: TX: %d, RX: %d]-[Rate flags: TX"
              ": 0x%x, RX: 0x%x]-[MCS Index: TX: %d, RX: %d]-[NSS: TX: %d, RX: %d]-[dcm: TX: %d, RX: %d]-[guard interval: TX: %d, RX: %d",
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              v83,
              v84,
              "wlan_hdd_update_rate_info",
              (unsigned int)*(char *)(a3 + 45),
              HIDWORD(v332[0]),
              LODWORD(v332[0]),
              HIDWORD(v331),
              v331,
              v88,
              v89,
              v85,
              v94,
              v86,
              v87,
              v95,
              v74,
              v300,
              v302,
              v90,
              v301);
            vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 0x51u, (__int64)"wlan_hdd_update_rate_info");
            if ( !vdev_by_user )
            {
              result = qdf_trace_msg(0x33u, 8u, "vdev object NULL", v97, v98, v99, v100, v101, v102, v103, v104);
              goto LABEL_124;
            }
            v105 = vdev_by_user;
            if ( *(unsigned __int8 *)(a3 + 45) == 128 )
            {
              v106 = "%s: don't fill tx rx rate for inactive link";
              v107 = "wlan_hdd_update_rate_info";
LABEL_58:
              qdf_trace_msg(0x33u, 8u, v106, v97, v98, v99, v100, v101, v102, v103, v104, v107);
LABEL_105:
              wlan_hdd_fill_summary_stats((_DWORD *)(a1 + 2432), a3, *(unsigned __int8 *)(a1 + 8));
              _wlan_hdd_validate_context(
                *(_QWORD *)(*(_QWORD *)a1 + 24LL),
                (__int64)"wlan_hdd_fill_per_link_summary_stats",
                v203,
                v204,
                v205,
                v206,
                v207,
                v208,
                v209,
                v210);
              ucfg_dp_get_net_dev_stats(v105, &v306, v211, v212, v213, v214, v215, v216, v217, v218);
              v219 = v309;
              v220 = v307;
              *(_QWORD *)(a3 + 24) = v308;
              *(_QWORD *)(a3 + 32) = v219;
              *(_DWORD *)(a3 + 84) = v306;
              *(_DWORD *)(a3 + 88) = v220;
              if ( (unsigned int)_wlan_hdd_validate_context(
                                   *(_QWORD *)(*(_QWORD *)a1 + 24LL),
                                   (__int64)"wlan_hdd_update_mlo_peer_stats",
                                   v221,
                                   v222,
                                   v223,
                                   v224,
                                   v225,
                                   v226,
                                   v227,
                                   v228) )
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: invalid hdd_ctx",
                  v229,
                  v230,
                  v231,
                  v232,
                  v233,
                  v234,
                  v235,
                  v236,
                  "wlan_hdd_update_mlo_peer_stats");
              else
                _cds_get_context(
                  71,
                  (__int64)"wlan_hdd_update_mlo_peer_stats",
                  v229,
                  v230,
                  v231,
                  v232,
                  v233,
                  v234,
                  v235,
                  v236);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: TX packets dp_intf %d mlo adjusted %d",
                v237,
                v238,
                v239,
                v240,
                v241,
                v242,
                v243,
                v244,
                "wlan_hdd_update_rate_info",
                v220,
                *(unsigned int *)(a3 + 88));
              _hdd_objmgr_put_vdev_by_user(
                v105,
                0x51u,
                (__int64)"wlan_hdd_update_rate_info",
                v245,
                v246,
                v247,
                v248,
                v249,
                v250,
                v251,
                v252,
                v253);
              qdf_mem_copy((void *)(a1 + 696), (const void *)(a3 + 56), 0xEu);
              qdf_mem_copy((void *)(a1 + 1376), (const void *)(a3 + 56), 0xEu);
              qdf_mem_copy((void *)(a1 + 710), (const void *)(a3 + 70), 0xEu);
              *(_QWORD *)a3 |= 0x430CuLL;
              if ( (v85 & 1) != 0 )
              {
                v266 = *(unsigned int *)(a3 + 84);
                v264 = *(unsigned int *)(a3 + 88);
                v263 = *(unsigned __int16 *)(a3 + 58);
                v262 = *(unsigned __int16 *)(a3 + 72);
                v265 = "%s: [TX: Reporting legacy rate %d pkt cnt %d]-[RX: Reporting legacy rate %d pkt cnt %d]";
              }
              else
              {
                v262 = *(unsigned int *)(a3 + 88);
                v263 = *(unsigned __int8 *)(a3 + 60);
                v264 = *(unsigned __int16 *)(a3 + 56);
                v265 = "%s: [TX: Reporting MCS rate %d, flags 0x%x pkt cnt %d, nss %d, bw %d]-[RX: Reporting MCS rate %d,"
                       " flags 0x%x pkt cnt %d, nss %d, bw %d]";
                v266 = *(unsigned __int8 *)(a3 + 61);
                LODWORD(v294) = *(_DWORD *)(a3 + 84);
                LODWORD(v296) = *(unsigned __int8 *)(a3 + 76);
                LODWORD(v295) = *(unsigned __int8 *)(a3 + 75);
                LODWORD(v293) = *(unsigned __int16 *)(a3 + 70);
                LODWORD(v292) = *(unsigned __int8 *)(a3 + 74);
                LODWORD(v291) = *(unsigned __int8 *)(a3 + 62);
              }
              qdf_trace_msg(
                0x33u,
                8u,
                v265,
                v254,
                v255,
                v256,
                v257,
                v258,
                v259,
                v260,
                v261,
                "wlan_hdd_update_rate_info",
                v263,
                v264,
                v262,
                v266,
                v291,
                v292,
                v293,
                v294,
                v295,
                v296);
              *(_DWORD *)(a3 + 212) = *(_DWORD *)(a1 + 4240);
              *(_DWORD *)(a3 + 216) = *(_DWORD *)(a1 + 4256);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: RX mpdu count %d fcs_err_count %d",
                v267,
                v268,
                v269,
                v270,
                v271,
                v272,
                v273,
                v274,
                "hdd_fill_fcs_and_mpdu_count");
              v283 = *(_QWORD *)a3;
              *(_BYTE *)(a3 + 46) = 0x80;
              *(_QWORD *)a3 = v283 | 0x3000000000LL;
              v284 = *(_BYTE *)(a1 + 2676);
              if ( v284 )
              {
                v285 = *(_BYTE *)(a3 + 47);
                v286 = *(_BYTE *)(a1 + 2676);
                *(_BYTE *)(a3 + 52) = v284;
                *(_BYTE *)(a3 + 47) = v285 | 1;
                if ( v284 != 128 )
                  *(_BYTE *)(a3 + 46) = v286;
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: RSSI for chain %d, vdev_id %d is %d",
                  v275,
                  v276,
                  v277,
                  v278,
                  v279,
                  v280,
                  v281,
                  v282,
                  "hdd_wlan_fill_per_chain_rssi_stats",
                  0,
                  *(unsigned __int8 *)(a1 + 8));
              }
              v287 = *(char *)(a1 + 2677);
              v288 = *(unsigned __int8 *)(a3 + 52);
              if ( *(_BYTE *)(a1 + 2677) )
              {
                v289 = *(_BYTE *)(a3 + 47);
                v290 = *(char *)(a3 + 46);
                *(_BYTE *)(a3 + 53) = v287;
                *(_BYTE *)(a3 + 47) = v289 | 2;
                if ( v287 > v290 )
                  *(_BYTE *)(a3 + 46) = v287;
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: RSSI for chain %d, vdev_id %d is %d",
                  v275,
                  v276,
                  v277,
                  v278,
                  v279,
                  v280,
                  v281,
                  v282,
                  "hdd_wlan_fill_per_chain_rssi_stats",
                  1,
                  *(unsigned __int8 *)(a1 + 8));
              }
              if ( v288 || *(_BYTE *)(a3 + 53) )
                *(_QWORD *)a3 |= 0x4002000uLL;
              qdf_trace_msg(
                0x33u,
                8u,
                "Sending station stats for link %02x:%02x:%02x:**:**:%02x",
                v275,
                v276,
                v277,
                v278,
                v279,
                v280,
                v281,
                v282,
                *(unsigned __int8 *)(a1 + 300),
                *(unsigned __int8 *)(a1 + 301),
                *(unsigned __int8 *)(a1 + 302),
                *(unsigned __int8 *)(a1 + 305));
              wlan_hdd_fill_send_get_sta_ucast_stats(a1, a2, a3);
              v36 = "%s: exit";
              goto LABEL_123;
            }
            if ( !ucfg_mlme_stats_is_link_speed_report_actual(*v75) )
            {
              cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v105, v108, v109, v110, v111, v112, v113, v114, v115);
              if ( cmpt_obj )
                v143 = *(_BYTE *)(cmpt_obj + 23);
              else
                v143 = 0;
              v305[0] = v143;
              v144 = wlan_vdev_mlme_get_cmpt_obj(v105, v135, v136, v137, v138, v139, v140, v141, v142);
              v297 = v105;
              if ( v144 )
                v145 = *(_BYTE *)(v144 + 23);
              else
                v145 = 0;
              v304[0] = v145;
              hdd_check_and_update_nss((__int64)v75, v305, v304);
              v155 = (unsigned __int8)hdd_report_max_rate(
                                        a1,
                                        v147,
                                        v148,
                                        v149,
                                        v150,
                                        v151,
                                        v152,
                                        v153,
                                        v154,
                                        v146,
                                        a3 + 56,
                                        *(_BYTE *)(a3 + 45),
                                        v85,
                                        v86,
                                        v88,
                                        v305[0]);
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
                                        a3 + 70,
                                        *(_BYTE *)(a3 + 45),
                                        v298,
                                        v87,
                                        v299,
                                        v304[0]);
              if ( (v155 & 1) == 0 || (v165 & 1) == 0 )
              {
                wlan_hdd_fill_os_rate_info(
                  v85,
                  v88,
                  a3 + 56,
                  v86,
                  v330[0],
                  v300,
                  v90,
                  v166,
                  v167,
                  v168,
                  v169,
                  v170,
                  v171,
                  v172,
                  v173);
                wlan_hdd_fill_os_rate_info(
                  v298,
                  v299,
                  a3 + 70,
                  v87,
                  v329[0],
                  v302,
                  v301,
                  v174,
                  v175,
                  v176,
                  v177,
                  v178,
                  v179,
                  v180,
                  v181);
              }
              v105 = v297;
              goto LABEL_105;
            }
            if ( !*(_BYTE *)(a1 + 2588) )
            {
              wlan_hdd_fill_os_rate_info(
                v85,
                v88,
                a3 + 56,
                v86,
                v330[0],
                v300,
                v90,
                v108,
                v109,
                v110,
                v111,
                v112,
                v113,
                v114,
                v115);
              goto LABEL_88;
            }
            v116 = *(unsigned __int8 *)(a1 + 2538);
            *(_BYTE *)(a3 + 61) = *(_BYTE *)(a1 + 2536);
            if ( (unsigned int)v116 <= 1 )
            {
              qdf_mem_set((void *)(a3 + 56), 0xEu, 0);
              v117 = (unsigned __int16)*(_DWORD *)(a1 + 2548);
              *(_WORD *)(a3 + 58) = *(_DWORD *)(a1 + 2548);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Reporting legacy rate %d",
                v118,
                v119,
                v120,
                v121,
                v122,
                v123,
                v124,
                v125,
                "wlan_hdd_refill_actual_tx_rate",
                v117);
              goto LABEL_88;
            }
            if ( (_DWORD)v116 == 255 )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Driver failed to get rate",
                v108,
                v109,
                v110,
                v111,
                v112,
                v113,
                v114,
                v115,
                "wlan_hdd_refill_actual_tx_rate");
              v116 = 255;
              if ( *(_WORD *)(a3 + 58) )
                goto LABEL_78;
            }
            else if ( *(_WORD *)(a3 + 58) )
            {
LABEL_78:
              if ( (unsigned int)(v116 - 2) <= 2 )
                *(_WORD *)(a3 + 56) |= 0x1000020001uLL >> (16 * ((v116 - 2) & 0xF));
              *(_BYTE *)(a3 + 60) = *(_DWORD *)(a1 + 2556);
              v182 = *(unsigned __int8 *)(a1 + 2540);
              if ( v182 <= 3 )
                *(_BYTE *)(a3 + 62) = 0x5040300u >> (8 * v182);
              v183 = *(_DWORD *)(a1 + 2576);
              *(_BYTE *)(a3 + 64) = 0;
              if ( v183 == 3 )
                v184 = 2;
              else
                v184 = v183 == 2;
              *(_BYTE *)(a3 + 63) = v184;
              v185 = *(unsigned __int16 *)(a3 + 56);
              v186 = *(unsigned int *)(a1 + 2576);
              if ( (_DWORD)v186 == 1 )
              {
                v185 |= 4u;
                *(_WORD *)(a3 + 56) = v185;
                v186 = *(unsigned int *)(a1 + 2576);
              }
              LODWORD(v292) = v185;
              LODWORD(v291) = *(unsigned __int8 *)(a1 + 2536);
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: sgi=%d, preamble=%d, bw=%d, mcs=%d, nss=%d, rate_flag=0x%x",
                v108,
                v109,
                v110,
                v111,
                v112,
                v113,
                v114,
                v115,
                "wlan_hdd_refill_actual_tx_rate",
                v186,
                v116,
                *(unsigned __int8 *)(a1 + 2540),
                *(unsigned int *)(a1 + 2556),
                v291,
                v292);
LABEL_88:
              wlan_hdd_fill_os_rate_info(
                v298,
                v299,
                a3 + 70,
                v87,
                v329[0],
                v302,
                v301,
                v126,
                v127,
                v128,
                v129,
                v130,
                v131,
                v132,
                v133);
              v187 = *(unsigned __int8 *)(a1 + 2539);
              *(_BYTE *)(a3 + 75) = *(_BYTE *)(a1 + 2537);
              if ( (unsigned int)v187 <= 1 )
              {
                qdf_mem_set((void *)(a3 + 70), 0xEu, 0);
                v188 = (unsigned __int16)*(_DWORD *)(a1 + 2552);
                *(_WORD *)(a3 + 72) = *(_DWORD *)(a1 + 2552);
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: Reporting legacy rate %d",
                  v189,
                  v190,
                  v191,
                  v192,
                  v193,
                  v194,
                  v195,
                  v196,
                  "wlan_hdd_refill_actual_rate",
                  v188);
                goto LABEL_105;
              }
              if ( (int)v187 > 3 )
              {
                if ( (_DWORD)v187 != 4 )
                {
                  if ( (_DWORD)v187 == 255 )
                  {
                    v106 = "%s: Driver failed to get rate, reporting FW rate";
                    v107 = "wlan_hdd_refill_actual_rate";
                    goto LABEL_58;
                  }
LABEL_97:
                  *(_BYTE *)(a3 + 74) = *(_DWORD *)(a1 + 2560);
                  v198 = *(unsigned __int8 *)(a1 + 2541);
                  if ( v198 <= 3 )
                    *(_BYTE *)(a3 + 76) = 0x5040300u >> (8 * v198);
                  v199 = *(_DWORD *)(a1 + 2580);
                  *(_BYTE *)(a3 + 78) = 0;
                  if ( v199 == 3 )
                    v200 = 2;
                  else
                    v200 = v199 == 2;
                  *(_BYTE *)(a3 + 77) = v200;
                  v201 = *(unsigned __int16 *)(a3 + 70);
                  v202 = *(unsigned int *)(a1 + 2580);
                  if ( (_DWORD)v202 == 1 )
                  {
                    v201 |= 4u;
                    *(_WORD *)(a3 + 70) = v201;
                    v202 = *(unsigned int *)(a1 + 2580);
                  }
                  LODWORD(v292) = v201;
                  LODWORD(v291) = *(unsigned __int8 *)(a1 + 2537);
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: sgi=%d, preamble=%d, bw=%d, mcs=%d, nss=%d, rate_flag=0x%x",
                    v97,
                    v98,
                    v99,
                    v100,
                    v101,
                    v102,
                    v103,
                    v104,
                    "wlan_hdd_refill_actual_rate",
                    v202,
                    v187,
                    *(unsigned __int8 *)(a1 + 2541),
                    *(unsigned int *)(a1 + 2560),
                    v291,
                    v292);
                  goto LABEL_105;
                }
                v197 = 16;
              }
              else if ( (_DWORD)v187 == 2 )
              {
                v197 = 1;
              }
              else
              {
                v197 = 2;
              }
              *(_WORD *)(a3 + 70) |= v197;
              goto LABEL_97;
            }
            *(_WORD *)(a3 + 58) = 60;
            goto LABEL_78;
          }
          v94 = *(_DWORD *)(a1 + 2568);
        }
        if ( v86 == 255 )
          v86 = 0;
        if ( v87 == 255 )
          v87 = 0;
        goto LABEL_54;
      }
    }
    if ( hdd_cm_is_vdev_roaming(a1) )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Roaming in progress",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "wlan_hdd_get_sta_tx_rate_stats");
      goto LABEL_26;
    }
    peer_stats_ext = wlan_cfg80211_mc_cp_stats_get_peer_stats_ext(*(_QWORD *)(a1 + 32), a1 + 300, (char *)v332 + 4);
    if ( HIDWORD(v332[0]) )
      goto LABEL_26;
    v55 = peer_stats_ext;
    wlan_hdd_fill_rate_info((__int64)&v306, *(_DWORD **)(peer_stats_ext + 160));
    v56 = BYTE2(v314);
    *(_BYTE *)(a1 + 2589) = 1;
    *(_BYTE *)(a1 + 2588) = v56;
    if ( v56 )
    {
      is_legacy_connection = hdd_is_legacy_connection(a1);
      v58 = v312;
      if ( (is_legacy_connection & 1) != 0 )
      {
        v59 = BYTE4(v312);
        *(_DWORD *)(a1 + 2548) = (unsigned int)v312 / 0x64;
      }
      else
      {
        v59 = BYTE4(v312);
        if ( (unsigned int)v312 >> 2 >= 0x659 && BYTE4(v312) >= 2u )
        {
          *(_BYTE *)(a1 + 2538) = BYTE4(v312);
          v60 = v314;
          v61 = BYTE6(v312);
          *(_BYTE *)(a1 + 2536) = BYTE5(v312);
          *(_BYTE *)(a1 + 2540) = v60;
          v62 = BYTE1(v314);
          *(_DWORD *)(a1 + 2556) = v61;
          v64 = v313;
          v63 = HIDWORD(v313);
          *(_BYTE *)(a1 + 2572) = v62;
          *(_DWORD *)(a1 + 2576) = v63;
          *(_DWORD *)(a1 + 2548) = v58 / 0x64;
          *(_DWORD *)(a1 + 2564) = v64;
          goto LABEL_25;
        }
        if ( (unsigned int)v312 >> 2 > 0x658 )
          goto LABEL_25;
        *(_DWORD *)(a1 + 2548) = (unsigned __int16)v312 / 0x64u;
      }
      *(_BYTE *)(a1 + 2538) = v59;
    }
LABEL_25:
    wlan_cfg80211_mc_cp_stats_free_stats_event(v55);
    goto LABEL_26;
  }
  result = wlan_hdd_fill_send_get_sta_ucast_stats(a1, a2, a3);
  v35 = jiffies;
  if ( wlan_hdd_get_sta_stats___last_ticks - jiffies + 125 < 0 )
  {
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: Sending Cached stats for standby link",
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               v34,
               "wlan_hdd_get_sta_stats");
    wlan_hdd_get_sta_stats___last_ticks = v35;
  }
LABEL_124:
  _ReadStatusReg(SP_EL0);
  return result;
}
