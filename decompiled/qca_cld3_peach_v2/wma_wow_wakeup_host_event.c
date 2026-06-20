__int64 __fastcall wma_wow_wakeup_host_event(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x23
  __int64 v12; // x20
  unsigned int v13; // w21
  unsigned int v14; // w22
  __int64 v16; // x24
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x24
  unsigned int v20; // w8
  const char *v21; // x25
  __int64 result; // x0
  unsigned int v23; // w21
  __int64 v24; // x22
  unsigned int wow_suspend_type; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x5
  unsigned int v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  int v62; // w8
  __int64 v63; // x21
  _QWORD *context; // x0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  _QWORD *v73; // x22
  const char *v74; // x2
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  int v83; // w8
  __int64 v84; // x9
  __int64 v85; // x4
  __int64 vdev_bssid; // x0
  __int64 v87; // x8
  unsigned int *v88; // x25
  unsigned int v89; // w22
  const char *v90; // x2
  const char *v91; // x3
  __int64 v92; // x4
  unsigned int matched; // w24
  const char *v94; // x2
  __int64 v95; // x27
  unsigned int v96; // w5
  const char *v97; // x3
  unsigned int v98; // w1
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  int v107; // w8
  unsigned int v108; // w20
  __int64 v109; // x21
  const void *v110; // x24
  unsigned int v111; // w23
  unsigned int v112; // w21
  __int64 v113; // x1
  __int64 v114; // x2
  __int64 v115; // x3
  const char *v116; // x0
  unsigned __int64 v117; // x23
  unsigned int interval_for_pagefault_wakeup_counts; // w22
  unsigned __int8 min_pagefault_wakeups_for_action; // w21
  unsigned __int64 v120; // x0
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  __int64 v129; // x10
  __int64 v130; // x8
  _QWORD *v131; // x0
  __int64 v132; // x9
  unsigned __int8 v133; // w24
  __int64 v134; // x0
  __int64 v135; // x0
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  __int64 v144; // x22
  int v145; // w0
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  __int64 v154; // x5
  unsigned int v155; // w21
  unsigned __int64 v156; // x4
  int v157; // w8
  unsigned int v158; // w0
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  _BYTE *v167; // x0
  double v168; // d0
  double v169; // d1
  double v170; // d2
  double v171; // d3
  double v172; // d4
  double v173; // d5
  double v174; // d6
  double v175; // d7
  __int64 v176; // x0
  double v177; // d0
  double v178; // d1
  double v179; // d2
  double v180; // d3
  double v181; // d4
  double v182; // d5
  double v183; // d6
  double v184; // d7
  double v185; // d0
  double v186; // d1
  double v187; // d2
  double v188; // d3
  double v189; // d4
  double v190; // d5
  double v191; // d6
  double v192; // d7
  const char *v193; // x2
  const char *v194; // x3
  __int64 v195; // x23
  double v196; // d0
  double v197; // d1
  double v198; // d2
  double v199; // d3
  double v200; // d4
  double v201; // d5
  double v202; // d6
  double v203; // d7
  __int64 v204; // x8
  unsigned int v205; // w1
  double v206; // d0
  double v207; // d1
  double v208; // d2
  double v209; // d3
  double v210; // d4
  double v211; // d5
  double v212; // d6
  double v213; // d7
  unsigned int v214; // w1
  double v215; // d0
  double v216; // d1
  double v217; // d2
  double v218; // d3
  double v219; // d4
  double v220; // d5
  double v221; // d6
  double v222; // d7
  int v223; // w8
  __int64 v224; // x4
  const char *v225; // x2
  unsigned __int8 v226; // w8
  __int64 v227; // x9
  _QWORD *v228; // x0
  double v229; // d0
  double v230; // d1
  double v231; // d2
  double v232; // d3
  double v233; // d4
  double v234; // d5
  double v235; // d6
  double v236; // d7
  _DWORD *v237; // x8
  __int64 v238; // x0
  unsigned __int8 v239; // w8
  int v240; // w21
  __int64 v241; // x24
  __int64 *v242; // x0
  __int64 *v243; // x23
  unsigned __int8 v244; // w27
  __int64 v245; // x8
  unsigned __int64 v246; // x21
  int v247; // w10
  int *v248; // x11
  int v249; // w13
  __int64 v250; // x14
  _BYTE *v251; // x15
  __int64 v252; // x16
  __int64 *v253; // x14
  char v254; // w15
  _BYTE *v255; // x22
  __int64 v256; // x0
  double v257; // d0
  double v258; // d1
  double v259; // d2
  double v260; // d3
  double v261; // d4
  double v262; // d5
  double v263; // d6
  double v264; // d7
  __int64 v265; // x25
  unsigned int v266; // w23
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
  __int64 v283; // x4
  __int64 v284; // x5
  __int64 v285; // x6
  __int64 v286; // x7
  __int64 v287; // x11
  __int64 v288; // x13
  _BYTE *v289; // x10
  __int64 *v290; // x12
  __int64 v291; // x13
  _BYTE *v292; // x14
  unsigned int v293; // w16
  unsigned int v294; // w15
  int v295; // w17
  int v296; // w0
  unsigned __int64 v297; // x28
  __int64 v298; // x22
  _BYTE *v299; // x24
  __int64 v300; // x8
  _QWORD *v301; // x0
  __int64 v302; // x9
  unsigned __int8 v303; // w23
  unsigned __int8 v304; // w8
  unsigned __int8 v305; // w0
  char v306; // w8
  _BYTE *v307; // x23
  __int64 v308; // x8
  unsigned int v309; // w25
  int v310; // w8
  int v311; // w8
  __int64 v312; // x9
  __int64 v313; // x10
  double v314; // d0
  double v315; // d1
  double v316; // d2
  double v317; // d3
  double v318; // d4
  double v319; // d5
  double v320; // d6
  double v321; // d7
  int v322; // w21
  char *v323; // x25
  _QWORD *v324; // x0
  double v325; // d0
  double v326; // d1
  double v327; // d2
  double v328; // d3
  double v329; // d4
  double v330; // d5
  double v331; // d6
  double v332; // d7
  void (__fastcall *v333)(char *, __int64); // x8
  int v334; // w8
  __int64 v335; // x5
  __int64 v336; // x6
  __int64 v337; // x7
  unsigned int v338; // w1
  int v339; // w8
  int v340; // w9
  int v341; // w10
  int v342; // w11
  int v343; // w9
  int v344; // w10
  int v345; // w11
  unsigned int v346; // w1
  signed int v347; // w25
  double v348; // d0
  double v349; // d1
  double v350; // d2
  double v351; // d3
  double v352; // d4
  double v353; // d5
  double v354; // d6
  double v355; // d7
  double v356; // d0
  double v357; // d1
  double v358; // d2
  double v359; // d3
  double v360; // d4
  double v361; // d5
  double v362; // d6
  double v363; // d7
  int icmpv6_subtype; // w0
  int v365; // w25
  const char *v366; // x3
  const char *v367; // x2
  unsigned int ipv4_proto; // w24
  double v369; // d0
  double v370; // d1
  double v371; // d2
  double v372; // d3
  double v373; // d4
  double v374; // d5
  double v375; // d6
  double v376; // d7
  unsigned __int8 ipv6_proto; // w0
  int v378; // w26
  unsigned __int8 ipv6_proto_mlq; // w24
  double v380; // d0
  double v381; // d1
  double v382; // d2
  double v383; // d3
  double v384; // d4
  double v385; // d5
  double v386; // d6
  double v387; // d7
  double v388; // d0
  double v389; // d1
  double v390; // d2
  double v391; // d3
  double v392; // d4
  double v393; // d5
  double v394; // d6
  double v395; // d7
  unsigned int v396; // w8
  __int64 v397; // [xsp+0h] [xbp-120h]
  __int64 v398; // [xsp+8h] [xbp-118h]
  int v399; // [xsp+8h] [xbp-118h]
  __int64 v400; // [xsp+10h] [xbp-110h]
  int v401; // [xsp+10h] [xbp-110h]
  __int64 v402; // [xsp+18h] [xbp-108h]
  int v403; // [xsp+18h] [xbp-108h]
  unsigned __int64 v404; // [xsp+28h] [xbp-F8h]
  _BYTE *v405; // [xsp+30h] [xbp-F0h]
  __int64 v406; // [xsp+38h] [xbp-E8h]
  char v407; // [xsp+4Ch] [xbp-D4h]
  __int64 v408; // [xsp+50h] [xbp-D0h] BYREF
  __int128 v409; // [xsp+58h] [xbp-C8h]
  __int64 v410; // [xsp+68h] [xbp-B8h]
  unsigned __int64 v411; // [xsp+70h] [xbp-B0h]
  unsigned __int64 v412; // [xsp+78h] [xbp-A8h]
  __int128 v413; // [xsp+80h] [xbp-A0h]
  __int64 v414; // [xsp+90h] [xbp-90h]
  __int64 v415; // [xsp+98h] [xbp-88h]
  __int64 *v416; // [xsp+A0h] [xbp-80h] BYREF
  __int128 v417; // [xsp+A8h] [xbp-78h]
  __int64 v418; // [xsp+B8h] [xbp-68h]
  __int64 v419; // [xsp+C0h] [xbp-60h]
  __int64 v420; // [xsp+C8h] [xbp-58h]
  __int64 v421; // [xsp+D0h] [xbp-50h]
  __int64 v422; // [xsp+D8h] [xbp-48h]
  __int64 v423; // [xsp+E0h] [xbp-40h]
  __int64 v424; // [xsp+E8h] [xbp-38h]
  __int64 v425; // [xsp+F0h] [xbp-30h]
  __int64 v426; // [xsp+F8h] [xbp-28h]
  __int64 v427; // [xsp+100h] [xbp-20h]
  __int64 v428; // [xsp+108h] [xbp-18h]
  __int64 v429; // [xsp+110h] [xbp-10h]

  v429 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && (v10 = *(_QWORD *)(a1 + 24)) != 0 )
  {
    if ( a2 )
    {
      v12 = *a2;
      v13 = *(_DWORD *)(*a2 + 4);
      if ( v13 < *(unsigned __int16 *)(a1 + 162) )
      {
        v14 = *(_DWORD *)(v12 + 12);
        if ( v14 == -1 )
        {
          if ( !wmi_get_runtime_pm_inprogress(*(_QWORD *)a1) )
          {
            v23 = *(_DWORD *)(v12 + 12);
            v24 = wma_wow_wake_reason_str(v23);
            wow_suspend_type = pmo_get_wow_suspend_type(*(_QWORD *)(a1 + 24));
            if ( wow_suspend_type > 2 )
              v34 = "unknown";
            else
              v34 = off_B09FD0[wow_suspend_type];
            qdf_trace_msg(
              0x36u,
              8u,
              "Non-WLAN triggered wakeup: %s (%d) (%s)",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v24,
              v23,
              v34);
          }
        }
        else
        {
          v16 = *(_QWORD *)(a1 + 520);
          v17 = wma_wow_wake_reason_str(v14);
          v18 = v16 + 488LL * v13;
          v19 = v17;
          v20 = *(_DWORD *)(v18 + 164) - 1;
          if ( v20 > 6 )
            v21 = "unknown";
          else
            v21 = off_B09F98[v20];
          v35 = pmo_get_wow_suspend_type(v10);
          if ( v35 > 2 )
            v44 = "unknown";
          else
            v44 = off_B09FD0[v35];
          qdf_trace_msg(
            0x36u,
            4u,
            "WLAN triggered wakeup: %s (%d), vdev: %d (%s) : (%s)",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v19,
            v14,
            v13,
            v21,
            v44);
          if ( *(_DWORD *)(v12 + 12) == 58 )
            qdf_is_drv_connected(v45, v46, v47, v48, v49, v50, v51, v52);
        }
        qdf_wow_wakeup_host_event(*(unsigned int *)(v12 + 12));
        v53 = *(_QWORD *)(a1 + 24);
        v427 = 0;
        v428 = 0;
        v425 = 0;
        v426 = 0;
        v423 = 0;
        v424 = 0;
        v421 = 0;
        v422 = 0;
        v419 = 0;
        v420 = 0;
        v418 = 0;
        v416 = nullptr;
        v417 = 0u;
        v414 = 0;
        v415 = 0;
        v413 = 0u;
        v411 = 0;
        v412 = 0;
        v410 = 0;
        v408 = 0;
        v409 = 0u;
        if ( !(unsigned int)ucfg_mc_cp_stats_get_psoc_wake_lock_stats(v53, &v416) )
        {
          qdf_mem_set(&v408, 0x50u, 0);
          HIDWORD(v408) = HIDWORD(v416);
          v409 = v417;
          v410 = v418;
          v411 = __PAIR64__(HIDWORD(v421), v422);
          v412 = __PAIR64__(HIDWORD(v420), v421);
          LODWORD(v413) = v420;
          *(_QWORD *)((char *)&v413 + 4) = v419;
          HIDWORD(v413) = HIDWORD(v422);
          host_diag_event_report_payload(2867, 80, &v408);
        }
        v62 = *(_DWORD *)(v12 + 12);
        if ( v62 != 58 )
          goto LABEL_33;
        v63 = *(_QWORD *)(a1 + 24);
        v416 = nullptr;
        *(_QWORD *)&v417 = 0;
        context = _cds_get_context(
                    53,
                    (__int64)"wma_wow_wakeup_pagefault_notify",
                    v54,
                    v55,
                    v56,
                    v57,
                    v58,
                    v59,
                    v60,
                    v61);
        if ( !context )
        {
          v74 = "%s: MAC context NULL";
          goto LABEL_31;
        }
        v73 = context;
        if ( (wlan_pmo_no_op_on_page_fault(v63) & 1) != 0 )
          goto LABEL_32;
        if ( wmi_get_runtime_pm_inprogress(*(_QWORD *)a1) )
        {
          v74 = "%s: Ignore run time pm wakeup";
LABEL_31:
          qdf_trace_msg(0x36u, 8u, v74, v65, v66, v67, v68, v69, v70, v71, v72, "wma_wow_wakeup_pagefault_notify");
          goto LABEL_32;
        }
        if ( !v73[1832] )
        {
          v74 = "%s: NULL pagefault action cb";
          goto LABEL_31;
        }
        if ( (wlan_pmo_enable_ssr_on_page_fault(v63) & 1) != 0 )
        {
          v117 = jiffies;
          interval_for_pagefault_wakeup_counts = wlan_pmo_get_interval_for_pagefault_wakeup_counts(*(_QWORD *)(a1 + 24));
          min_pagefault_wakeups_for_action = wlan_pmo_get_min_pagefault_wakeups_for_action(*(_QWORD *)(a1 + 24));
          v120 = _msecs_to_jiffies(interval_for_pagefault_wakeup_counts);
          v129 = v117 - v120;
          v130 = *(unsigned __int8 *)(a1 + 4396);
          if ( v117 >= v120 && *(_BYTE *)(a1 + 4396) )
          {
            v131 = *(_QWORD **)(a1 + 4400);
            v132 = 0;
            while ( v129 - v131[v132] >= 0 )
            {
              if ( v130 == ++v132 )
              {
                v132 = *(unsigned __int8 *)(a1 + 4396);
                v133 = *(_BYTE *)(a1 + 4396);
                goto LABEL_128;
              }
            }
            v133 = v132;
            if ( !(_BYTE)v132 )
              goto LABEL_129;
LABEL_128:
            v226 = v130 - v133;
            *(_BYTE *)(a1 + 4396) = v226;
            qdf_mem_copy(v131, &v131[v132], 8 * (unsigned int)v226);
            qdf_mem_set(
              (void *)(*(_QWORD *)(a1 + 4400) + 8LL * *(unsigned __int8 *)(a1 + 4396)),
              8 * (unsigned int)v133,
              0);
            LODWORD(v130) = *(unsigned __int8 *)(a1 + 4396);
          }
LABEL_129:
          v227 = *(_QWORD *)(a1 + 4400);
          *(_BYTE *)(a1 + 4396) = v130 + 1;
          *(_QWORD *)(v227 + 8LL * (unsigned int)v130) = v117;
          if ( *(unsigned __int8 *)(a1 + 4396) >= (unsigned int)min_pagefault_wakeups_for_action )
          {
            v228 = _cds_get_context(
                     53,
                     (__int64)"wma_wow_pagefault_action_cb",
                     v121,
                     v122,
                     v123,
                     v124,
                     v125,
                     v126,
                     v127,
                     v128);
            if ( v228 )
            {
              v237 = (_DWORD *)v228[1832];
              if ( *(v237 - 1) != -297509796 )
                __break(0x8228u);
              if ( !((unsigned int (__fastcall *)(_QWORD, __int64))v237)(0, 390) )
                goto LABEL_32;
            }
            else
            {
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: NULL mac ptr",
                v229,
                v230,
                v231,
                v232,
                v233,
                v234,
                v235,
                v236,
                "wma_wow_pagefault_action_cb");
            }
            v238 = *(_QWORD *)(a1 + 4400);
            v239 = *(_BYTE *)(a1 + 4396) - 1;
            *(_BYTE *)(a1 + 4396) = v239;
            qdf_mem_copy((void *)v238, (const void *)(v238 + 8), 8 * (unsigned int)v239);
            qdf_mem_set((void *)(*(_QWORD *)(a1 + 4400) + 8LL * *(unsigned __int8 *)(a1 + 4396)), 8u, 0);
          }
LABEL_32:
          v62 = *(_DWORD *)(v12 + 12);
LABEL_33:
          if ( v62 == 64 )
            hif_rtpm_set_autosuspend_delay(1200);
          ucfg_pmo_psoc_wakeup_host_event_received(*(_QWORD *)(a1 + 24));
          wma_print_wow_stats(a1, v12);
          v83 = *(_DWORD *)(v12 + 12);
          if ( (unsigned int)(v83 - 13) <= 0x36 && ((1LL << ((unsigned __int8)v83 - 13)) & 0x4480002813C801LL) != 0
            || (unsigned int)(v83 - 1) < 2 )
          {
            v84 = a2[4];
            v85 = *((unsigned int *)a2 + 10);
            v416 = nullptr;
            if ( v84 && (unsigned int)v85 > 4 )
            {
              vdev_bssid = wma_get_vdev_bssid(
                             *(_QWORD *)(*(_QWORD *)(a1 + 520) + 488LL * *(unsigned int *)(*a2 + 4)),
                             v75,
                             v76,
                             v77,
                             v78,
                             v79,
                             v80,
                             v81,
                             v82);
              v87 = *a2;
              if ( vdev_bssid )
              {
                v88 = (unsigned int *)a2[4];
                v89 = *v88;
                if ( *v88 > *((_DWORD *)a2 + 10) - 4 )
                {
                  v90 = "%s: Invalid pb_event_len from firmware, pb_event_len: %u, num_wow_packet_buffer: %u";
                  v91 = "wma_wake_event_piggybacked";
                  v92 = v89;
LABEL_42:
                  qdf_trace_msg(0x36u, 2u, v90, v75, v76, v77, v78, v79, v80, v81, v82, v91, v92);
                  matched = -22;
                  goto LABEL_52;
                }
                v110 = (const void *)vdev_bssid;
                v111 = *(_DWORD *)(v87 + 12);
                qdf_trace_msg(
                  0x36u,
                  8u,
                  "%s: piggybacked event buffer:",
                  v75,
                  v76,
                  v77,
                  v78,
                  v79,
                  v80,
                  v81,
                  v82,
                  "wma_wake_event_piggybacked");
                ((void (__fastcall *)(__int64, __int64, unsigned int *, _QWORD))qdf_trace_hex_dump)(54, 8, v88 + 1, v89);
                v112 = 45057;
                switch ( v111 )
                {
                  case 1u:
                  case 2u:
                  case 0x18u:
                    goto LABEL_105;
                  case 0xDu:
                    v112 = 106497;
                    goto LABEL_105;
                  case 0x1Bu:
                    v112 = 24577;
                    goto LABEL_105;
                  case 0x1Cu:
                    v112 = 163841;
                    goto LABEL_105;
                  case 0x1Du:
                  case 0x28u:
                    goto LABEL_111;
                  case 0x1Eu:
                    v112 = 118804;
                    goto LABEL_105;
                  case 0x21u:
                    v112 = 98306;
                    goto LABEL_105;
                  case 0x2Au:
                    v112 = 131073;
                    goto LABEL_105;
                  case 0x2Fu:
                    v112 = 237570;
                    goto LABEL_105;
                  case 0x3Cu:
                    v112 = 45064;
                    goto LABEL_105;
                  case 0x3Fu:
                    v112 = 20504;
LABEL_105:
                    wlan_roam_debug_log(0xFFu, 0xFu, 0xFFFFu, 0, 0, v111, v112);
                    v158 = wmitlv_check_and_pad_event_tlvs(a1, (__int64)(v88 + 1), v89);
                    if ( v158 )
                    {
                      qdf_trace_msg(
                        0x36u,
                        2u,
                        "%s: Bad TLVs; len:%d, event_id:%d, status:%d",
                        v159,
                        v160,
                        v161,
                        v162,
                        v163,
                        v164,
                        v165,
                        v166,
                        "wma_wake_event_piggybacked",
                        v89,
                        v112,
                        v158);
                      matched = -22;
                    }
                    else
                    {
                      LODWORD(v167) = 0;
                      switch ( v111 )
                      {
                        case 1u:
                          LODWORD(v167) = wma_wake_reason_ap_assoc_lost(a1, v416);
                          break;
                        case 2u:
                        case 0x18u:
                          wlan_roam_debug_log(*(_DWORD *)(*a2 + 4), 0xCu, 0xFFFFu, 0, 0, v111, v89);
                          if ( !v89 )
                          {
                            qdf_trace_msg(
                              0x36u,
                              8u,
                              "%s: Host woken up because of better AP beacon",
                              v168,
                              v169,
                              v170,
                              v171,
                              v172,
                              v173,
                              v174,
                              v175,
                              "wma_wake_event_piggybacked");
                            goto LABEL_166;
                          }
                          LODWORD(v167) = target_if_cm_roam_event(a1, (__int64)v416, v89);
                          break;
                        case 8u:
                          qdf_trace_msg(
                            0x36u,
                            2u,
                            "%s: WOW_REASON_TIMER_INTR_RECV received, indicating key exchange did not finish. Initiate disconnect",
                            v159,
                            v160,
                            v161,
                            v162,
                            v163,
                            v164,
                            v165,
                            v166,
                            "wma_wake_event_piggybacked");
                          v167 = (_BYTE *)_qdf_mem_malloc(0x14u, "wma_wake_event_piggybacked", 3374);
                          if ( v167 )
                          {
                            *v167 = 0;
                            v255 = v167;
                            v167[1] = *(_DWORD *)(*a2 + 4);
                            qdf_mem_copy(v167 + 10, v110, 6u);
                            qdf_mem_copy(v255 + 4, v110, 6u);
                            *((_WORD *)v255 + 8) = 1;
                            wma_send_msg(a1, 5057, v255, 0);
LABEL_166:
                            LODWORD(v167) = 0;
                          }
                          break;
                        case 0xDu:
                          LODWORD(v167) = wma_csa_offload_handler(
                                            a1,
                                            v416,
                                            v159,
                                            v160,
                                            v161,
                                            v162,
                                            v163,
                                            v164,
                                            v165,
                                            v166);
                          break;
                        case 0x1Bu:
                          LODWORD(v167) = wma_peer_sta_kickout_event_handler(a1, v416, v89);
                          break;
                        case 0x1Cu:
                          LODWORD(v167) = target_if_nan_rsp_handler(a1, v416, v89);
                          break;
                        case 0x1Eu:
                          LODWORD(v167) = wma_rssi_breached_event_handler(a1, v416, v89);
                          break;
                        case 0x21u:
                          LODWORD(v167) = target_if_nlo_complete_handler(
                                            a1,
                                            (__int64)v416,
                                            v159,
                                            v160,
                                            v161,
                                            v162,
                                            v163,
                                            v164,
                                            v165,
                                            v166);
                          break;
                        case 0x28u:
                        case 0x2Au:
                          break;
                        case 0x3Cu:
                          qdf_trace_msg(
                            0x36u,
                            8u,
                            "%s: Host woken up because of PMKID request event",
                            v159,
                            v160,
                            v161,
                            v162,
                            v163,
                            v164,
                            v165,
                            v166,
                            "wma_wake_event_piggybacked");
                          LODWORD(v167) = target_if_pmkid_request_event_handler(a1, (__int64)v416, v89);
                          break;
                        case 0x3Fu:
                          qdf_trace_msg(
                            0x36u,
                            8u,
                            "%s: Host woken up because of vdev disconnect event",
                            v159,
                            v160,
                            v161,
                            v162,
                            v163,
                            v164,
                            v165,
                            v166,
                            "wma_wake_event_piggybacked");
                          LODWORD(v167) = target_if_cm_roam_vdev_disconnect_event_handler(a1, (__int64)v416, v89);
                          break;
                        default:
                          v256 = wma_wow_wake_reason_str(v111);
                          qdf_trace_msg(
                            0x36u,
                            2u,
                            "%s: Wake reason %s(%u) is not a piggybacked event",
                            v257,
                            v258,
                            v259,
                            v260,
                            v261,
                            v262,
                            v263,
                            v264,
                            "wma_wake_event_piggybacked",
                            v256,
                            v111);
                          LODWORD(v167) = -22;
                          break;
                      }
                      matched = (unsigned int)v167;
                      wmitlv_free_allocated_event_tlvs(
                        v112,
                        (__int64 *)&v416,
                        v159,
                        v160,
                        v161,
                        v162,
                        v163,
                        v164,
                        v165,
                        v166);
                    }
                    break;
                  default:
                    v176 = wma_wow_wake_reason_str(v111);
                    qdf_trace_msg(
                      0x36u,
                      8u,
                      "%s: No Event Id for WOW reason %s(%d)",
                      v177,
                      v178,
                      v179,
                      v180,
                      v181,
                      v182,
                      v183,
                      v184,
                      "wow_get_wmi_eventid",
                      v176,
                      v111);
LABEL_111:
                    wlan_roam_debug_log(0xFFu, 0xFu, 0xFFFFu, 0, 0, v111, 0);
                    qdf_trace_msg(
                      0x36u,
                      2u,
                      "%s: Unable to find Event Id",
                      v185,
                      v186,
                      v187,
                      v188,
                      v189,
                      v190,
                      v191,
                      v192,
                      "wma_wake_event_piggybacked");
                    matched = -22;
                    break;
                }
                goto LABEL_52;
              }
              v85 = *(unsigned int *)(v87 + 4);
              v94 = "%s: Failed to get bssid for vdev_%d";
            }
            else
            {
              v94 = "%s: Invalid wow packet buffer from firmware %u";
            }
            v97 = "wma_wake_event_piggybacked";
            v98 = 2;
LABEL_50:
            qdf_trace_msg(0x36u, v98, v94, v75, v76, v77, v78, v79, v80, v81, v82, v97, v85);
            goto LABEL_51;
          }
          v95 = a2[4];
          if ( !v95 )
          {
            v134 = *(unsigned int *)(*a2 + 12);
            if ( (unsigned int)(v134 - 65) <= 7 && ((1 << (v134 - 65)) & 0xA1) != 0 )
            {
              v135 = wma_wow_wake_reason_str(v134);
              qdf_trace_msg(
                0x36u,
                4u,
                "%s: Wake reason %s",
                v136,
                v137,
                v138,
                v139,
                v140,
                v141,
                v142,
                v143,
                "wma_wake_event_no_payload",
                v135);
              goto LABEL_51;
            }
            if ( (_DWORD)v134 )
              goto LABEL_51;
            v157 = *(unsigned __int8 *)(*a2 + 4);
            LODWORD(v408) = 0;
            HIDWORD(v408) = v157;
            v416 = &v408;
            *(_QWORD *)&v417 = 0;
            matched = target_if_nlo_match_event_handler(a1, (__int64)&v416, v75, v76, v77, v78, v79, v80, v81, v82);
            goto LABEL_52;
          }
          v96 = *((_DWORD *)a2 + 10);
          if ( v96 <= 4 )
          {
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: Invalid wow packet buffer from firmware %u",
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              "wma_wake_event_packet",
              v96);
            matched = -22;
            goto LABEL_52;
          }
          v155 = *(_DWORD *)v95;
          if ( !*(_DWORD *)v95 )
          {
            v193 = "%s: Wake event packet is empty";
            v194 = "wma_wake_event_packet";
LABEL_113:
            qdf_trace_msg(0x36u, 2u, v193, v75, v76, v77, v78, v79, v80, v81, v82, v194);
            goto LABEL_51;
          }
          if ( v155 > v96 - 4 )
          {
            v90 = "%s: Invalid packet_len from firmware, packet_len: %u, num_wow_packet_buffer: %u";
            v91 = "wma_wake_event_packet";
            v92 = v155;
            goto LABEL_42;
          }
          v195 = *a2;
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Number of delayed packets received = %d",
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            "wma_wake_event_packet",
            *(unsigned int *)(*a2 + 20));
          v204 = *(unsigned int *)(v195 + 12);
          if ( (unsigned int)v204 <= 0x3A )
          {
            if ( ((1LL << v204) & 0x7804018018LL) != 0 )
            {
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: wow_buf_pkt_len: %u",
                v196,
                v197,
                v198,
                v199,
                v200,
                v201,
                v202,
                v203,
                "wma_wow_dump_mgmt_buffer",
                v155);
              if ( v155 >= 0x18 )
              {
                if ( is_wakeup_event_console_logs_enabled )
                  v205 = 4;
                else
                  v205 = 8;
                qdf_trace_msg(
                  0x36u,
                  v205,
                  "%s: RA: %02x:%02x:%02x:**:**:%02x TA: %02x:%02x:%02x:**:**:%02x",
                  v75,
                  v76,
                  v77,
                  v78,
                  v79,
                  v80,
                  v81,
                  v82,
                  "wma_wow_dump_mgmt_buffer",
                  *(unsigned __int8 *)(v95 + 8),
                  *(unsigned __int8 *)(v95 + 9),
                  *(unsigned __int8 *)(v95 + 10),
                  *(unsigned __int8 *)(v95 + 13),
                  *(unsigned __int8 *)(v95 + 14),
                  *(unsigned __int8 *)(v95 + 15),
                  *(unsigned __int8 *)(v95 + 16),
                  *(unsigned __int8 *)(v95 + 19));
                if ( is_wakeup_event_console_logs_enabled )
                  v214 = 4;
                else
                  v214 = 8;
                qdf_trace_msg(
                  0x36u,
                  v214,
                  "%s: TO_DS: %u, FROM_DS: %u",
                  v206,
                  v207,
                  v208,
                  v209,
                  v210,
                  v211,
                  v212,
                  v213,
                  "wma_wow_dump_mgmt_buffer",
                  *(_BYTE *)(v95 + 5) & 1,
                  *(_BYTE *)(v95 + 5) & 2);
                if ( (*(_BYTE *)(v95 + 5) & 3u) > 1 )
                {
                  if ( (*(_BYTE *)(v95 + 5) & 3) != 2 )
                  {
                    if ( v155 < 0x1E )
                      goto LABEL_286;
                    v224 = *(unsigned __int8 *)(v95 + 20);
                    v335 = *(unsigned __int8 *)(v95 + 21);
                    v336 = *(unsigned __int8 *)(v95 + 22);
                    v337 = *(unsigned __int8 *)(v95 + 25);
                    if ( is_wakeup_event_console_logs_enabled == 1 )
                    {
                      LODWORD(v402) = *(unsigned __int8 *)(v95 + 33);
                      v225 = "%s: DA: %02x:%02x:%02x:**:**:%02x SA: %02x:%02x:%02x:**:**:%02x";
                      LODWORD(v400) = *(unsigned __int8 *)(v95 + 30);
                      LODWORD(v398) = *(unsigned __int8 *)(v95 + 29);
                      v338 = 4;
                    }
                    else
                    {
                      v225 = "%s: DA: %02x:%02x:%02x:**:**:%02x SA: %02x:%02x:%02x:**:**:%02x";
                      v338 = 8;
                      LODWORD(v402) = *(unsigned __int8 *)(v95 + 33);
                      LODWORD(v400) = *(unsigned __int8 *)(v95 + 30);
                      LODWORD(v398) = *(unsigned __int8 *)(v95 + 29);
                    }
                    LODWORD(v397) = *(unsigned __int8 *)(v95 + 28);
LABEL_285:
                    qdf_trace_msg(
                      0x36u,
                      v338,
                      v225,
                      v215,
                      v216,
                      v217,
                      v218,
                      v219,
                      v220,
                      v221,
                      v222,
                      "wma_wow_dump_mgmt_buffer",
                      v224,
                      v335,
                      v336,
                      v337,
                      v397,
                      v398,
                      v400,
                      v402);
LABEL_286:
                    v367 = "%s: SEQ_NUM: %u, FRAG_NUM: %u";
                    if ( is_wakeup_event_console_logs_enabled != 1 )
                    {
                      qdf_trace_msg(
                        0x36u,
                        8u,
                        "%s: SEQ_NUM: %u, FRAG_NUM: %u",
                        v215,
                        v216,
                        v217,
                        v218,
                        v219,
                        v220,
                        v221,
                        v222,
                        "wma_wow_dump_mgmt_buffer",
                        *(unsigned __int16 *)(v95 + 26) >> 4,
                        *(_WORD *)(v95 + 26) & 0xF);
                      goto LABEL_51;
                    }
                    goto LABEL_287;
                  }
                  v223 = (unsigned __int8)is_wakeup_event_console_logs_enabled;
                  v224 = *(unsigned __int8 *)(v95 + 20);
                  v225 = "%s: SA: %02x:%02x:%02x:**:**:%02x";
                }
                else
                {
                  v223 = (unsigned __int8)is_wakeup_event_console_logs_enabled;
                  v224 = *(unsigned __int8 *)(v95 + 20);
                  if ( (*(_BYTE *)(v95 + 5) & 3) != 0 )
                    v225 = "%s: DA: %02x:%02x:%02x:**:**:%02x";
                  else
                    v225 = "%s: BSSID: %02x:%02x:%02x:**:**:%02x";
                }
                v335 = *(unsigned __int8 *)(v95 + 21);
                v336 = *(unsigned __int8 *)(v95 + 22);
                v337 = *(unsigned __int8 *)(v95 + 25);
                if ( v223 == 1 )
                  v338 = 4;
                else
                  v338 = 8;
                goto LABEL_285;
              }
              v193 = "%s: Insufficient buffer length for mgmt. packet";
              v194 = "wma_wow_dump_mgmt_buffer";
              goto LABEL_113;
            }
            if ( ((1LL << v204) & 0x8400040600LL) != 0 )
              goto LABEL_173;
            if ( v204 == 58 )
            {
              qdf_trace_msg(
                0x36u,
                4u,
                "%s: PF occurs during suspend: packet_len %u",
                v196,
                v197,
                v198,
                v199,
                v200,
                v201,
                v202,
                v203,
                "wma_wake_event_packet",
                v155);
              ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(54, 4, v95 + 4, v155);
              goto LABEL_51;
            }
          }
          if ( (unsigned int)(v204 - 74) >= 2 )
          {
            matched = -22;
            goto LABEL_52;
          }
LABEL_173:
          qdf_trace_msg(
            0x36u,
            4u,
            "%s: Wake event packet:",
            v196,
            v197,
            v198,
            v199,
            v200,
            v201,
            v202,
            v203,
            "wma_wake_event_packet");
          ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(54, 8, v95 + 4, v155);
          v266 = *(_DWORD *)(v195 + 4);
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: packet length: %u",
            v267,
            v268,
            v269,
            v270,
            v271,
            v272,
            v273,
            v274,
            "wma_wow_parse_data_pkt",
            v155);
          if ( v155 < 0xE )
            goto LABEL_51;
          if ( is_wakeup_event_console_logs_enabled == 1 )
          {
            if ( v95 == -10 )
            {
              v285 = 0;
              v283 = 0;
              v284 = 0;
              v286 = 0;
            }
            else
            {
              v283 = *(unsigned __int8 *)(v95 + 10);
              v284 = *(unsigned __int8 *)(v95 + 11);
              v285 = *(unsigned __int8 *)(v95 + 12);
              v286 = *(unsigned __int8 *)(v95 + 15);
            }
            if ( v95 == -4 )
            {
              v341 = 0;
              v339 = 0;
              v340 = 0;
              v342 = 0;
            }
            else
            {
              v339 = *(unsigned __int8 *)(v95 + 4);
              v340 = *(unsigned __int8 *)(v95 + 5);
              v341 = *(unsigned __int8 *)(v95 + 6);
              v342 = *(unsigned __int8 *)(v95 + 9);
            }
            v403 = v342;
            v401 = v341;
            v399 = v340;
            v346 = 4;
          }
          else
          {
            if ( v95 == -10 )
            {
              v285 = 0;
              v283 = 0;
              v284 = 0;
              v286 = 0;
            }
            else
            {
              v283 = *(unsigned __int8 *)(v95 + 10);
              v284 = *(unsigned __int8 *)(v95 + 11);
              v285 = *(unsigned __int8 *)(v95 + 12);
              v286 = *(unsigned __int8 *)(v95 + 15);
            }
            if ( v95 == -4 )
            {
              v344 = 0;
              v339 = 0;
              v343 = 0;
              v345 = 0;
            }
            else
            {
              v339 = *(unsigned __int8 *)(v95 + 4);
              v343 = *(unsigned __int8 *)(v95 + 5);
              v344 = *(unsigned __int8 *)(v95 + 6);
              v345 = *(unsigned __int8 *)(v95 + 9);
            }
            v346 = 8;
            v403 = v345;
            v401 = v344;
            v399 = v343;
          }
          qdf_trace_msg(
            0x36u,
            v346,
            "%s: Src_mac: %02x:%02x:%02x:**:**:%02x, Dst_mac: %02x:%02x:%02x:**:**:%02x",
            v275,
            v276,
            v277,
            v278,
            v279,
            v280,
            v281,
            v282,
            "wma_wow_parse_data_pkt",
            v283,
            v284,
            v285,
            v286,
            v339,
            v399,
            v401,
            v403);
          ucfg_mc_cp_stats_inc_wake_lock_stats_by_dst_addr(*(_QWORD *)(a1 + 24), v266, v95 + 4);
          v347 = bswap32(*(unsigned __int16 *)(v95 + 16)) >> 16;
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Ether Type: 0x%04x",
            v348,
            v349,
            v350,
            v351,
            v352,
            v353,
            v354,
            v355,
            "wma_wow_get_pkt_proto_subtype",
            (unsigned int)v347);
          matched = 0;
          if ( v347 > 34524 )
          {
            if ( v347 == 34525 )
            {
              if ( v155 < 0x15 )
                goto LABEL_51;
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: IPV6 Packet",
                v356,
                v357,
                v358,
                v359,
                v360,
                v361,
                v362,
                v363,
                "wma_wow_get_pkt_proto_subtype");
              ipv6_proto = _qdf_nbuf_data_get_ipv6_proto(v95 + 4);
              v378 = ipv6_proto;
              ipv6_proto_mlq = ipv6_proto;
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: IPV6_proto_type: %u",
                v380,
                v381,
                v382,
                v383,
                v384,
                v385,
                v386,
                v387,
                "wma_wow_get_pkt_proto_subtype",
                ipv6_proto);
              if ( !v378 )
              {
                ipv6_proto_mlq = _qdf_nbuf_data_get_ipv6_proto_mlq(v95 + 4);
                qdf_trace_msg(
                  0x36u,
                  8u,
                  "%s: ICMPV6_proto_type: %u",
                  v388,
                  v389,
                  v390,
                  v391,
                  v392,
                  v393,
                  v394,
                  v395,
                  "wma_wow_get_pkt_proto_subtype",
                  ipv6_proto_mlq);
              }
              if ( ipv6_proto_mlq == 6 )
              {
                v366 = "IPV6 TCP Packet";
                v365 = 27;
                goto LABEL_261;
              }
              if ( ipv6_proto_mlq == 17 )
              {
                v366 = "IPV6 UDP Packet";
                v365 = 26;
                goto LABEL_261;
              }
              if ( ipv6_proto_mlq != 58 || v155 < 0x37 )
                goto LABEL_51;
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: ICMPV6 Packet",
                v215,
                v216,
                v217,
                v218,
                v219,
                v220,
                v221,
                v222,
                "wma_wow_get_pkt_proto_subtype");
              icmpv6_subtype = _qdf_nbuf_data_get_icmpv6_subtype((_BYTE *)(v95 + 4));
            }
            else
            {
              if ( v347 != 34958 )
                goto LABEL_52;
              if ( v155 < 0x15 )
                goto LABEL_51;
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: EAPOL Packet",
                v356,
                v357,
                v358,
                v359,
                v360,
                v361,
                v362,
                v363,
                "wma_wow_get_pkt_proto_subtype");
              icmpv6_subtype = _qdf_nbuf_data_get_eapol_subtype(v95 + 4);
            }
          }
          else if ( v347 == 2048 )
          {
            if ( v155 < 0x18 )
              goto LABEL_51;
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: IPV4 Packet",
              v356,
              v357,
              v358,
              v359,
              v360,
              v361,
              v362,
              v363,
              "wma_wow_get_pkt_proto_subtype");
            ipv4_proto = (unsigned __int8)_qdf_nbuf_data_get_ipv4_proto(v95 + 4);
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: IPV4_proto_type: %u",
              v369,
              v370,
              v371,
              v372,
              v373,
              v374,
              v375,
              v376,
              "wma_wow_get_pkt_proto_subtype",
              ipv4_proto);
            if ( ipv4_proto == 17 )
            {
              if ( v155 < 0x26 || !_qdf_nbuf_data_is_ipv4_dhcp_pkt(v95 + 4) )
              {
                v366 = "IPV4 UDP Packet";
                v365 = 24;
                goto LABEL_261;
              }
              if ( v155 < 0x11D )
                goto LABEL_51;
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: DHCP Packet",
                v215,
                v216,
                v217,
                v218,
                v219,
                v220,
                v221,
                v222,
                "wma_wow_get_pkt_proto_subtype");
              icmpv6_subtype = _qdf_nbuf_data_get_dhcp_subtype((_BYTE *)(v95 + 4));
            }
            else
            {
              if ( ipv4_proto == 6 )
              {
                v366 = "IPV4 TCP Packet";
                v365 = 25;
                goto LABEL_261;
              }
              if ( ipv4_proto != 1 || v155 < 0x23 )
                goto LABEL_51;
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: ICMP Packet",
                v215,
                v216,
                v217,
                v218,
                v219,
                v220,
                v221,
                v222,
                "wma_wow_get_pkt_proto_subtype");
              icmpv6_subtype = _qdf_nbuf_data_get_icmp_subtype(v95 + 4);
            }
          }
          else
          {
            if ( v347 != 2054 )
              goto LABEL_52;
            if ( v155 < 0x16 )
              goto LABEL_51;
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: ARP Packet",
              v356,
              v357,
              v358,
              v359,
              v360,
              v361,
              v362,
              v363,
              "wma_wow_get_pkt_proto_subtype");
            icmpv6_subtype = _qdf_nbuf_data_get_arp_subtype(v95 + 4);
          }
          v365 = icmpv6_subtype;
          if ( (unsigned int)(icmpv6_subtype - 1) > 0x1A )
            goto LABEL_262;
          v366 = off_B09FE8[icmpv6_subtype - 1];
LABEL_261:
          qdf_trace_msg(0x36u, 4u, "WOW Wakeup: %s rcvd", v215, v216, v217, v218, v219, v220, v221, v222, v366);
LABEL_262:
          matched = 0;
          if ( v365 <= 14 )
          {
            if ( (unsigned int)(v365 - 5) < 8 )
            {
              if ( v155 < 0x32 )
                goto LABEL_51;
              v367 = "%s: Pkt_len: %u, Transaction_id: %u";
              goto LABEL_287;
            }
            if ( (unsigned int)(v365 - 1) < 4 )
            {
              if ( v155 < 0x17 )
                goto LABEL_51;
              v367 = "%s: Pkt_len: %u, Key_len: %u";
              goto LABEL_287;
            }
          }
          else
          {
            if ( v365 <= 23 )
            {
              if ( (unsigned int)(v365 - 17) >= 7 )
              {
                ucfg_mc_cp_stats_inc_wake_lock_stats_by_protocol(*(_QWORD *)(a1 + 24), v266, (unsigned int)v365);
                if ( v155 < 0x2A )
                  goto LABEL_51;
                v367 = "%s: Pkt_len: %u, Seq_num: %u";
              }
              else
              {
                ucfg_mc_cp_stats_inc_wake_lock_stats_by_protocol(*(_QWORD *)(a1 + 24), v266, (unsigned int)v365);
                if ( v155 < 0x3E )
                  goto LABEL_51;
                v367 = "%s: Pkt_len: %u, Seq_num: %u";
              }
LABEL_287:
              qdf_trace_msg(0x36u, 4u, v367, v215, v216, v217, v218, v219, v220, v221, v222);
              goto LABEL_51;
            }
            if ( v365 <= 25 )
            {
              if ( v365 == 24 )
              {
                wma_log_pkt_ipv4(v95 + 4, v155);
                goto LABEL_51;
              }
              wma_log_pkt_ipv4(v95 + 4, v155);
              if ( v155 < 0x2A )
              {
LABEL_51:
                matched = 0;
                goto LABEL_52;
              }
              v396 = *(unsigned __int16 *)(v95 + 42);
              v94 = "%s: TCP_seq_num: %u";
              v97 = "wma_log_pkt_tcpv4";
              goto LABEL_302;
            }
            if ( v365 == 26 )
            {
              wma_log_pkt_ipv6(v95 + 4, v155);
              goto LABEL_51;
            }
            if ( v365 == 27 )
            {
              wma_log_pkt_ipv6(v95 + 4, v155);
              if ( v155 < 0x3E )
                goto LABEL_51;
              v396 = *(unsigned __int16 *)(v95 + 62);
              v94 = "%s: TCP_seq_num: %u";
              v97 = "wma_log_pkt_tcpv6";
LABEL_302:
              v85 = bswap32(v396) >> 16;
              v98 = 8;
              goto LABEL_50;
            }
          }
LABEL_52:
          ucfg_mc_cp_stats_inc_wake_lock_stats(
            *(_QWORD *)(a1 + 24),
            *(unsigned int *)(v12 + 4),
            *(unsigned int *)(v12 + 12));
          wma_print_wow_stats(a1, v12);
          v107 = *(_DWORD *)(v12 + 12);
          if ( v107 > 14 )
          {
            if ( v107 > 23 )
            {
              if ( v107 == 24 )
              {
                v108 = 500;
                v109 = 2096;
                goto LABEL_73;
              }
              if ( v107 == 59 )
              {
                v108 = 2000;
                v109 = 2296;
                goto LABEL_73;
              }
            }
            else
            {
              if ( v107 == 15 )
              {
                v108 = 1000;
                v109 = 896;
                goto LABEL_73;
              }
              if ( v107 == 16 )
              {
                v108 = 1000;
                v109 = 1096;
                goto LABEL_73;
              }
            }
          }
          else if ( v107 > 3 )
          {
            if ( v107 == 4 )
            {
              v108 = 1000;
              v109 = 1496;
              goto LABEL_73;
            }
            if ( v107 == 14 )
            {
              v108 = 3000;
              v109 = 2496;
              goto LABEL_73;
            }
          }
          else
          {
            if ( v107 == 1 )
            {
              v108 = 1000;
              v109 = 1696;
              goto LABEL_73;
            }
            if ( v107 == 3 )
            {
              v108 = 1000;
              v109 = 1296;
LABEL_73:
              qdf_trace_msg(
                0x36u,
                1u,
                "%s: Holding %d msec wake_lock",
                v99,
                v100,
                v101,
                v102,
                v103,
                v104,
                v105,
                v106,
                "wma_acquire_wow_wakelock",
                v108);
              cds_get_ring_log_level(0, v113, v114, v115);
              v116 = qdf_wake_lock_name(a1 + v109);
              ((void (__fastcall *)(__int64, const char *, _QWORD, _QWORD))host_diag_log_wlock)(12, v116, v108, 0);
              qdf_wake_lock_timeout_acquire(a1 + v109, v108);
            }
          }
          pmo_set_wow_suspend_type(*(_QWORD *)(a1 + 24), 3);
          result = matched;
          goto LABEL_9;
        }
        v144 = ktime_get_with_offset(1);
        v145 = wlan_pmo_get_interval_for_pagefault_wakeup_counts(v63);
        v154 = *((unsigned int *)a2 + 10);
        if ( (unsigned int)v154 <= 4 )
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Invalid wow packet buffer from FW %u",
            v146,
            v147,
            v148,
            v149,
            v150,
            v151,
            v152,
            v153,
            "wma_wow_pagefault_parse_event",
            (unsigned int)v154);
LABEL_140:
          v74 = "%s: Failed during page fault payload parse";
          goto LABEL_31;
        }
        v156 = *(unsigned int *)a2[4];
        if ( !(_DWORD)v156 )
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Wake event packet is empty",
            v146,
            v147,
            v148,
            v149,
            v150,
            v151,
            v152,
            v153,
            "wma_wow_pagefault_parse_event");
          goto LABEL_140;
        }
        if ( v154 - 4 < v156 )
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Invalid packet_len from firmware, packet_len: %u, num_wow_packet_buffer: %u",
            v146,
            v147,
            v148,
            v149,
            v150,
            v151,
            v152,
            v153,
            "wma_wow_pagefault_parse_event");
          goto LABEL_140;
        }
        v240 = v145;
        v241 = ((unsigned int)v156 >> 2) - 1;
        v242 = (__int64 *)_qdf_mem_malloc(8 * v241, "wma_wow_pagefault_parse_event", 3683);
        v416 = v242;
        if ( !v242 )
          goto LABEL_140;
        v243 = v242;
        v244 = 0;
        v245 = (unsigned int)(1000 * v240);
        v246 = v144 / 1000;
        if ( (_DWORD)v241 )
        {
          v247 = 0;
          v248 = (int *)(a2[4] + 8);
          do
          {
            v249 = *v248;
            if ( (unsigned int)(*v248 + 1) >= 2 )
            {
              if ( v244 )
              {
                v250 = v244;
                v251 = (char *)v242 + 4;
                v252 = v244;
                while ( *((_DWORD *)v251 - 1) != v249 )
                {
                  --v252;
                  v251 += 8;
                  if ( !v252 )
                    goto LABEL_150;
                }
                ++*v251;
              }
              else
              {
                v250 = 0;
LABEL_150:
                v253 = &v242[v250];
                ++v244;
                v254 = *((_BYTE *)v253 + 4);
                *(_DWORD *)v253 = v249;
                *((_BYTE *)v253 + 4) = v254 + 1;
              }
            }
            ++v247;
            ++v248;
          }
          while ( (unsigned int)v241 > (unsigned __int8)v247 );
          LOBYTE(v417) = v244;
          BYTE1(v417) = v244;
          if ( v244 )
          {
            if ( v244 == 1 )
            {
              v265 = 1;
              v407 = 0;
              v244 = 1;
            }
            else
            {
              v287 = 0;
              v288 = 1;
              v265 = v244;
              v289 = (char *)v242 + 12;
              do
              {
                v290 = &v243[v287];
                v287 = v288;
                v291 = v244;
                v292 = v289;
                do
                {
                  v293 = (unsigned __int8)*v292;
                  v294 = *((unsigned __int8 *)v290 + 4);
                  if ( v293 > v294 )
                  {
                    v295 = *((_DWORD *)v292 - 1);
                    v296 = *(_DWORD *)v290;
                    *((_BYTE *)v290 + 4) = v293;
                    *(_DWORD *)v290 = v295;
                    *((_DWORD *)v292 - 1) = v296;
                    *v292 = v294;
                  }
                  --v291;
                  v292 += 8;
                }
                while ( v287 != v291 );
                v288 = v287 + 1;
                v289 += 8;
              }
              while ( v287 + 1 != v244 );
              v407 = 0;
            }
            goto LABEL_191;
          }
          v244 = 0;
          v265 = 0;
        }
        else
        {
          v265 = 0;
          BYTE1(v417) = 0;
        }
        v407 = 1;
LABEL_191:
        v297 = v246 - v245;
        qdf_spinlock_acquire(a1 + 5208);
        v298 = 0;
        v406 = v265;
        v404 = v246;
        v405 = (char *)v243 + 4;
        while ( 1 )
        {
          v299 = (_BYTE *)(a1 + 4392 + 16 * v298);
          if ( v297 < v246 )
          {
            v300 = (unsigned __int8)v299[4];
            if ( v299[4] )
            {
              v301 = *((_QWORD **)v299 + 1);
              v302 = 0;
              while ( (__int64)(v297 - v301[v302]) >= 0 )
              {
                if ( v300 == ++v302 )
                {
                  v302 = (unsigned __int8)v299[4];
                  v303 = v299[4];
                  goto LABEL_199;
                }
              }
              v303 = v302;
              if ( !(_BYTE)v302 )
                goto LABEL_200;
LABEL_199:
              v304 = v300 - v303;
              v299[4] = v304;
              qdf_mem_copy(v301, &v301[v302], 8 * (unsigned int)v304);
              qdf_mem_set((void *)(*((_QWORD *)v299 + 1) + 8LL * (unsigned __int8)v299[4]), 8 * (unsigned int)v303, 0);
            }
          }
LABEL_200:
          v305 = wlan_pmo_get_min_pagefault_wakeups_for_action(*(_QWORD *)(a1 + 24));
          v306 = v244 ? v407 : 1;
          if ( (v306 & 1) == 0 )
            break;
LABEL_224:
          if ( !v244 )
          {
            BYTE1(v417) = 0;
LABEL_228:
            if ( *(_DWORD *)(a1 + 5200) )
            {
              wma_wow_pagefault_action_cb(*(_QWORD *)(a1 + 5192));
              *(_DWORD *)(a1 + 5200) = 0;
            }
            qdf_spinlock_release(a1 + 5208);
            _qdf_mem_free((__int64)v416);
            goto LABEL_32;
          }
          if ( ++v298 == 50 )
          {
            BYTE1(v417) = v244;
            wma_wow_pagefault_add_new_sym_from_event(a1, &v416, v246);
            goto LABEL_228;
          }
        }
        v307 = v405;
        v308 = v265;
        while ( 1 )
        {
          v309 = (unsigned __int8)*v307;
          if ( *v307 )
          {
            if ( *((_DWORD *)v307 - 1) == *(_DWORD *)v299 )
              break;
          }
          --v308;
          v307 += 8;
          if ( !v308 )
            goto LABEL_223;
        }
        v310 = (unsigned __int8)v299[4];
        if ( v310 + v309 < v305 )
        {
          v311 = 0;
          do
          {
            v312 = (unsigned __int8)v299[4];
            v313 = *((_QWORD *)v299 + 1);
            ++v311;
            v299[4] = v312 + 1;
            *(_QWORD *)(v313 + 8 * v312) = v246;
          }
          while ( v309 > (unsigned __int8)v311 );
LABEL_222:
          --v244;
          *v307 = 0;
LABEL_223:
          v265 = v406;
          goto LABEL_224;
        }
        qdf_mem_set(*((void **)v299 + 1), (unsigned int)(8 * v310), 0);
        v322 = *(_DWORD *)(a1 + 5200);
        v299[4] += v309;
        v323 = *(char **)(a1 + 5192);
        if ( (unsigned int)(v322 - 385) > 5 )
        {
          if ( v322 )
          {
LABEL_221:
            qdf_mem_copy(&v323[v322], v299, 6u);
            v334 = v322 + 6;
            v246 = v404;
            v299[4] = 0;
            *(_DWORD *)(a1 + 5200) = v334;
            goto LABEL_222;
          }
        }
        else
        {
          v324 = _cds_get_context(
                   53,
                   (__int64)"wma_wow_pagefault_action_cb",
                   v314,
                   v315,
                   v316,
                   v317,
                   v318,
                   v319,
                   v320,
                   v321);
          if ( v324 )
          {
            v333 = (void (__fastcall *)(char *, __int64))v324[1832];
            if ( *((_DWORD *)v333 - 1) != -297509796 )
              __break(0x8228u);
            v333(v323, 390);
          }
          else
          {
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: NULL mac ptr",
              v325,
              v326,
              v327,
              v328,
              v329,
              v330,
              v331,
              v332,
              "wma_wow_pagefault_action_cb");
          }
        }
        qdf_mem_set(v323, 0x186u, 0);
        v322 = 0;
        goto LABEL_221;
      }
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: received invalid vdev_id %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wma_wow_wakeup_host_event",
        v13);
      result = 4294967274LL;
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Wake event data is null",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wma_wow_wakeup_host_event");
      result = 4294967274LL;
    }
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
