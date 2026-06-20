__int64 __fastcall dp_pld_request_bus_bandwidth(
        __int64 a1,
        unsigned __int64 a2,
        unsigned __int64 a3,
        unsigned int a4,
        char a5)
{
  __int64 context; // x19
  __int64 result; // x0
  unsigned __int64 v12; // x1
  unsigned int v13; // w24
  char v14; // w19
  unsigned int v15; // w23
  __int64 v16; // x0
  int v17; // w21
  unsigned int v18; // w19
  __int64 v19; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  int v37; // w22
  __int64 v38; // x8
  int (__fastcall *v39)(_QWORD); // x8
  __int64 (__fastcall *v40)(_QWORD); // x8
  __int64 v41; // x0
  unsigned int v42; // w19
  __int64 v43; // x21
  __int64 v44; // x20
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x8
  void (__fastcall *v54)(_QWORD); // x8
  __int64 v55; // x8
  void (__fastcall *v56)(_QWORD); // x8
  unsigned int v57; // w19
  char v58; // w9
  int v59; // w8
  unsigned __int64 v60; // x9
  unsigned __int64 v61; // x20
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x0
  __int64 (*v71)(void); // x8
  __int64 v72; // x0
  char updated; // w0
  void (__fastcall *v74)(_QWORD); // x8
  void (__fastcall *v75)(_QWORD); // x8
  void (__fastcall *v76)(__int64, unsigned __int64, unsigned __int64); // x8
  _DWORD *v77; // x8
  __int64 v78; // x11
  int v79; // w21
  __int64 v80; // x8
  __int64 v81; // x9
  unsigned __int64 v82; // x8
  unsigned __int64 v83; // x9
  unsigned __int64 v84; // x20
  unsigned __int64 v85; // x9
  unsigned __int64 v86; // x19
  __int64 v87; // x0
  __int64 v88; // x1
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  unsigned __int64 v97; // x8
  char v98; // w9
  int v99; // w8
  unsigned __int64 v100; // x9
  unsigned __int64 v101; // x20
  int v102; // w9
  __int64 v103; // x9
  bool v104; // zf
  char v105; // w9
  int v106; // w8
  unsigned __int64 v107; // x9
  unsigned __int64 v108; // x20
  int v109; // w28
  int v110; // w8
  int v111; // w8
  char v112; // w8
  int v113; // w26
  int v114; // w8
  __int16 v115; // w8
  void (__fastcall *v116)(__int64, unsigned __int64 *, __int64); // x8
  __int64 v117; // x0
  const char *v118; // x2
  void (*v119)(void); // x8
  int v120; // w8
  __int64 v121; // x11
  __int64 v122; // x9
  unsigned __int64 v123; // x8
  unsigned __int64 v124; // x9
  unsigned __int64 v125; // x20
  unsigned __int64 v126; // x8
  unsigned __int64 v127; // x19
  __int64 v128; // x0
  __int64 v129; // x1
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  char v138; // w9
  int v139; // w8
  unsigned __int64 v140; // x9
  unsigned __int64 v141; // x20
  int v142; // w9
  __int64 v143; // x9
  char v145; // w9
  int v146; // w8
  unsigned __int64 v147; // x9
  unsigned __int64 v148; // x20
  int v149; // w28
  int v150; // w20
  unsigned int v151; // w27
  int v152; // w24
  int v153; // w9
  _DWORD *v154; // x8
  __int64 v155; // x0
  double v156; // d0
  double v157; // d1
  double v158; // d2
  double v159; // d3
  double v160; // d4
  double v161; // d5
  double v162; // d6
  double v163; // d7
  void (*v164)(void); // x8
  int v165; // w21
  int v166; // w19
  char v167; // w9
  int v168; // w8
  unsigned __int64 v169; // x9
  unsigned __int64 v170; // x20
  char v171; // w9
  int v172; // w8
  unsigned __int64 v173; // x9
  unsigned __int64 v174; // x20
  void (__fastcall *v175)(__int64, __int64 *); // x8
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  __int64 v184; // x8
  void (*v185)(void); // x8
  int v186; // w8
  __int64 v187; // x8
  __int64 v188; // x9
  __int64 (__fastcall *v189)(_QWORD); // x8
  unsigned int v190; // w20
  __int64 v191; // x0
  __int64 v192; // x25
  int v193; // w8
  __int64 v194; // x0
  __int64 v195; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v197; // x8
  double v198; // d0
  double v199; // d1
  double v200; // d2
  double v201; // d3
  double v202; // d4
  double v203; // d5
  double v204; // d6
  double v205; // d7
  unsigned __int8 *v206; // x9
  const char *v207; // x26
  unsigned __int8 *v208; // x23
  const char *v209; // x25
  double v210; // d0
  double v211; // d1
  double v212; // d2
  double v213; // d3
  double v214; // d4
  double v215; // d5
  double v216; // d6
  double v217; // d7
  __int64 v218; // x8
  unsigned int v219; // w24
  unsigned int v220; // w21
  unsigned int v221; // w22
  int v222; // w19
  unsigned int v223; // w27
  unsigned int v224; // w28
  unsigned int v225; // w20
  unsigned __int8 *v226; // x9
  __int64 v227; // x23
  unsigned int *v228; // x26
  __int64 v229; // x5
  void (__fastcall *v230)(__int64, __int64); // x9
  __int64 v231; // x1
  double v232; // d0
  double v233; // d1
  double v234; // d2
  double v235; // d3
  double v236; // d4
  double v237; // d5
  double v238; // d6
  double v239; // d7
  __int64 v240; // x21
  _DWORD *v241; // x22
  __int64 v242; // x5
  __int64 v243; // x8
  __int64 v244; // x19
  __int64 (__fastcall *v245)(_QWORD); // x8
  __int64 v246; // x0
  __int64 v247; // x8
  _DWORD *v248; // x8
  __int64 v249; // x8
  _DWORD *v250; // x8
  __int64 v251; // x8
  _DWORD *v252; // x8
  __int64 v253; // x8
  _DWORD *v254; // x8
  __int64 v255; // x8
  _DWORD *v256; // x8
  _DWORD *v257; // x8
  double v258; // d0
  double v259; // d1
  double v260; // d2
  double v261; // d3
  double v262; // d4
  double v263; // d5
  double v264; // d6
  double v265; // d7
  __int64 v266; // x8
  void (__fastcall *v267)(_QWORD); // x8
  __int64 v268; // x0
  __int64 v269; // [xsp+0h] [xbp-120h]
  __int64 v270; // [xsp+8h] [xbp-118h]
  __int64 v271; // [xsp+10h] [xbp-110h]
  __int64 v272; // [xsp+18h] [xbp-108h]
  __int64 v273; // [xsp+20h] [xbp-100h]
  __int64 v274; // [xsp+28h] [xbp-F8h]
  __int64 v275; // [xsp+30h] [xbp-F0h]
  __int64 v276; // [xsp+38h] [xbp-E8h]
  __int64 v277; // [xsp+70h] [xbp-B0h]
  __int64 v278; // [xsp+78h] [xbp-A8h]
  int v279; // [xsp+84h] [xbp-9Ch]
  unsigned __int64 v280; // [xsp+88h] [xbp-98h]
  char v281; // [xsp+94h] [xbp-8Ch]
  int v282; // [xsp+94h] [xbp-8Ch]
  int v283; // [xsp+98h] [xbp-88h]
  __int64 v284; // [xsp+98h] [xbp-88h]
  __int64 v285; // [xsp+A0h] [xbp-80h]
  int v286; // [xsp+A8h] [xbp-78h]
  __int64 **v287; // [xsp+A8h] [xbp-78h]
  unsigned __int64 v288; // [xsp+B0h] [xbp-70h]
  __int64 v289; // [xsp+B0h] [xbp-70h]
  unsigned __int64 v290; // [xsp+B8h] [xbp-68h]
  unsigned int v291; // [xsp+C4h] [xbp-5Ch]
  __int64 v292; // [xsp+C8h] [xbp-58h]
  unsigned int *v293; // [xsp+C8h] [xbp-58h]
  __int64 v294; // [xsp+D0h] [xbp-50h]
  __int64 v295; // [xsp+D8h] [xbp-48h] BYREF
  int v296; // [xsp+E0h] [xbp-40h]
  int v297; // [xsp+E4h] [xbp-3Ch] BYREF
  unsigned __int64 v298; // [xsp+E8h] [xbp-38h] BYREF
  __int64 v299; // [xsp+F0h] [xbp-30h] BYREF
  __int64 v300; // [xsp+F8h] [xbp-28h] BYREF
  __int64 v301; // [xsp+100h] [xbp-20h] BYREF
  unsigned __int64 v302[3]; // [xsp+108h] [xbp-18h] BYREF

  v302[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v300 = 0;
  v301 = 0;
  v299 = 0;
  v296 = 0;
  v295 = 0;
  context = _cds_get_context(61, "dp_pld_request_bus_bandwidth");
  result = _cds_get_context(71, "dp_pld_request_bus_bandwidth");
  if ( result )
  {
    v12 = a3 + a2;
    v285 = context;
    v292 = *(_QWORD *)(a1 + 376);
    v280 = a3 + a2;
    v278 = result;
    v281 = a5;
    if ( *(_BYTE *)(a1 + 880) )
    {
LABEL_3:
      v13 = 6;
      v14 = 1;
      v15 = 5;
      goto LABEL_8;
    }
    if ( v12 <= *(unsigned int *)(a1 + 56) )
    {
      if ( v12 <= *(unsigned int *)(a1 + 60) )
      {
        if ( v12 <= *(unsigned int *)(a1 + 64) )
        {
          if ( v12 <= *(unsigned int *)(a1 + 76) )
          {
            v14 = 1;
            if ( v12 <= *(unsigned int *)(a1 + 80) )
            {
              if ( v12 <= *(unsigned int *)(a1 + 84) )
                v15 = 1;
              else
                v15 = 2;
              v13 = v15;
            }
            else
            {
              v15 = 3;
              v13 = 3;
            }
          }
          else
          {
            updated = dp_sap_p2p_update_mid_high_tput(a1);
            if ( (updated & 1) != 0 )
              v15 = 9;
            else
              v15 = 4;
            if ( (updated & 1) != 0 )
              v13 = 5;
            else
              v13 = 4;
            v14 = 1;
          }
          goto LABEL_8;
        }
        goto LABEL_3;
      }
      v13 = 7;
      v14 = 1;
      v15 = 6;
    }
    else
    {
      v14 = 0;
      v13 = 8;
      v15 = 7;
    }
LABEL_8:
    if ( (ucfg_ipa_is_fw_wdi_activated(*(_QWORD *)a1) & 1) == 0
      && (policy_mgr_is_current_hwmode_dbs(*(_QWORD *)a1) & 1) != 0
      && ((unsigned __int8)v14 & (v280 > *(unsigned int *)(a1 + 68))) != 0 )
    {
      v15 = 6;
      v13 = 7;
    }
    v16 = *(_QWORD *)a1;
    LODWORD(v295) = 1;
    HIDWORD(v295) = v13;
    dp_bbm_apply_independent_policy(v16, (__int64)&v295);
    dp_rtpm_tput_policy_apply(a1, v13);
    v17 = *(_DWORD *)(a1 + 876);
    v18 = *(_DWORD *)(a1 + 128);
    v19 = _cds_get_context(71, "dp_low_tput_gro_flush_skip_handler");
    v294 = a1;
    v291 = v13;
    v288 = a3;
    v283 = v17;
    if ( v15 == 2 && v17 )
    {
      v28 = *(_DWORD *)(a1 + 1108) + 1;
      *(_DWORD *)(a1 + 1108) = v28;
      if ( v28 >= v18 )
        *(_DWORD *)(a1 + 1104) = 1;
LABEL_40:
      v286 = *(_DWORD *)(a1 + 1024);
      if ( v286 == v15 )
        goto LABEL_108;
      v42 = dp_pld_request_bus_bandwidth_prev_tput_level;
      v43 = _cds_get_context(71, "dp_set_tx_irq_affinity");
      v44 = _cds_get_context(61, "dp_set_tx_irq_affinity");
      if ( v13 < 6 || v42 > 5 )
      {
        if ( v13 <= 5 && v42 >= 6 )
        {
          if ( v43 && *(_QWORD *)v43 && (v55 = *(_QWORD *)(*(_QWORD *)v43 + 64LL)) != 0 )
          {
            v56 = *(void (__fastcall **)(_QWORD))(v55 + 288);
            if ( v56 )
            {
              if ( *((_DWORD *)v56 - 1) != -1666142433 )
                __break(0x8228u);
              v56(v43);
            }
          }
          else
          {
            qdf_trace_msg(
              0x89u,
              8u,
              "%s: Invalid Instance:",
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              "cdp_get_tx_rings_grp_bitmap");
          }
          hif_set_grp_intr_affinity(v44);
          if ( !*(_DWORD *)(a1 + 232) )
            goto LABEL_93;
LABEL_62:
          v57 = dp_pld_request_bus_bandwidth_prev_tput_level;
          v302[0] = 0;
          qdf_cpumask_clear(v302);
          if ( v13 >= 6 && v57 <= 5 )
          {
            v58 = 0;
            v59 = _cpu_online_mask;
            do
            {
              v60 = v59 & (unsigned int)(-1LL << v58);
              if ( !(_DWORD)v60 )
                break;
              v61 = __clz(__rbit64(v60));
              if ( ((*(unsigned int *)(a1 + 232) >> v61) & 1) != 0 )
              {
                qdf_cpumask_set_cpu((unsigned int)v61, (__int64)v302);
                v59 = _cpu_online_mask;
              }
              v58 = v61 + 1;
            }
            while ( v61 <= 0x1E );
            goto LABEL_72;
          }
          if ( v13 <= 5 && v57 >= 6 )
          {
            qdf_cpumask_setall(v302);
LABEL_72:
            if ( !qdf_cpumask_equal((_DWORD *)(a1 + 3016), v302) )
            {
              qdf_cpumask_copy((_QWORD *)(a1 + 3016), v302);
              v70 = *(_QWORD *)(a1 + 240);
              if ( v70 )
              {
                if ( *(_QWORD *)v70 )
                {
                  v71 = *(__int64 (**)(void))(**(_QWORD **)v70 + 624LL);
                  if ( v71 )
                  {
                    if ( *((_DWORD *)v71 - 1) != -1355198606 )
                      __break(0x8228u);
                    v72 = v71();
                    if ( v72 )
                      dp_rx_tm_set_cpu_mask(v72 + 16, v302);
                  }
                }
                else
                {
                  qdf_trace_msg(
                    0x89u,
                    8u,
                    "%s: Invalid Instance:",
                    v62,
                    v63,
                    v64,
                    v65,
                    v66,
                    v67,
                    v68,
                    v69,
                    "cdp_soc_get_dp_txrx_handle");
                }
              }
            }
          }
LABEL_93:
          dp_pld_request_bus_bandwidth_prev_tput_level = v13;
          *(_DWORD *)(a1 + 1024) = v15;
          if ( v15 > 2 )
          {
            v75 = *(void (__fastcall **)(_QWORD))(a1 + 600);
            if ( *((_DWORD *)v75 - 1) != -528599275 )
              __break(0x8228u);
            v75(v292);
            if ( *(_BYTE *)(a1 + 369) == 1 )
              dp_set_rps_cpu_mask(a1);
          }
          else
          {
            v74 = *(void (__fastcall **)(_QWORD))(a1 + 592);
            if ( *((_DWORD *)v74 - 1) != -528599275 )
              __break(0x8228u);
            v74(v292);
            if ( *(_BYTE *)(a1 + 369) == 1 )
              dp_clear_rps_cpu_mask(a1);
          }
          v76 = *(void (__fastcall **)(__int64, unsigned __int64, unsigned __int64))(a1 + 640);
          if ( *((_DWORD *)v76 - 1) != -166398397 )
            __break(0x8228u);
          v76(v292, a2, a3);
          dp_disable_rx_ol_for_low_tput(a1, *(unsigned int *)(a1 + 84) > a3);
          if ( v15 >= 4 )
          {
            v77 = *(_DWORD **)(a1 + 608);
            if ( *(v77 - 1) != -662079542 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))v77)(v292, 0, 0, 0);
          }
LABEL_108:
          qdf_dp_trace_apply_tput_policy(v15 > 1);
          v78 = *(_QWORD *)(a1 + 1064);
          v79 = *(_DWORD *)(a1 + 120);
          v80 = (unsigned int)(1000 * *(_DWORD *)(a1 + 88));
          v81 = *(_QWORD *)(a1 + 856);
          *(_QWORD *)(a1 + 856) = 0;
          v82 = v81 * v80 / (unsigned __int64)a4;
          v83 = *(_QWORD *)(a1 + 1056) + v82;
          *(_QWORD *)(a1 + 1056) = v82;
          v84 = v83 >> 1;
          if ( a3 >= v82 )
            v85 = a3 - v82;
          else
            v85 = 0;
          *(_QWORD *)(a1 + 1064) = v85;
          v86 = v84 + ((v78 + v85) >> 1);
          v87 = (__int64)qdf_cpumask_clear(&v300);
          v97 = *(unsigned int *)(a1 + 76);
          if ( v84 <= v97 )
          {
            if ( v86 <= v97 )
            {
              v279 = 0;
              goto LABEL_131;
            }
            v87 = (__int64)qdf_cpumask_clear(&v300);
            v105 = 0;
            v106 = _cpu_online_mask;
            do
            {
              v107 = v106 & (unsigned int)(-1LL << v105);
              if ( !(_DWORD)v107 )
                break;
              v108 = __clz(__rbit64(v107));
              if ( !cpu_topology[12 * (unsigned int)v108 + 2] )
              {
                v87 = qdf_cpumask_set_cpu((unsigned int)v108, (__int64)&v300);
                v106 = _cpu_online_mask;
              }
              v105 = v108 + 1;
            }
            while ( v108 < 0x1F );
            v279 = 0;
          }
          else
          {
            v87 = (__int64)qdf_cpumask_clear(&v300);
            v98 = 0;
            v99 = _cpu_online_mask;
            do
            {
              v100 = v99 & (unsigned int)(-1LL << v98);
              if ( !(_DWORD)v100 )
                break;
              v101 = __clz(__rbit64(v100));
              v102 = cpu_topology[12 * (unsigned int)v101 + 2];
              if ( (v102 & 0x80000000) == 0 )
              {
                v104 = v102 == 0;
                v103 = (1LL << v102) & 6;
                v104 = !v104 && v103 == 0;
                if ( !v104 )
                {
                  v87 = qdf_cpumask_set_cpu((unsigned int)v101, (__int64)&v300);
                  v99 = _cpu_online_mask;
                }
              }
              v98 = v101 + 1;
            }
            while ( v101 <= 0x1E );
            v279 = 1;
          }
          a1 = v294;
LABEL_131:
          if ( v86 <= *(unsigned int *)(a1 + 108) )
          {
            v112 = *(_BYTE *)(a1 + 104);
            *(_DWORD *)(a1 + 1152) = 0;
            if ( (v112 & 1) == 0 && (v281 & 1) == 0 )
            {
              v109 = 0;
              dp_pld_request_bus_bandwidth_next_rx_level = 0;
              *(_DWORD *)(a1 + 1048) = 0;
              goto LABEL_140;
            }
            v111 = 1;
            v109 = *(_DWORD *)(a1 + 1048);
          }
          else
          {
            v109 = *(_DWORD *)(a1 + 1048);
            if ( v109 == 3 || (v110 = *(_DWORD *)(a1 + 1152) + 1, *(_DWORD *)(a1 + 1152) = v110, v110 != v79) )
            {
LABEL_140:
              v113 = dp_pld_request_bus_bandwidth_next_rx_level;
              if ( v109 == dp_pld_request_bus_bandwidth_next_rx_level )
                goto LABEL_158;
              v114 = *(unsigned __int8 *)(a1 + 848);
              v302[0] = 0;
              *(_DWORD *)(a1 + 1048) = dp_pld_request_bus_bandwidth_next_rx_level;
              if ( v114 == 1 )
              {
                WORD2(v302[0]) = 1;
                v115 = 3;
                if ( !*(_DWORD *)(a1 + 100) )
                {
LABEL_146:
                  LODWORD(v302[0]) = v113;
                  if ( a1 )
                  {
                    if ( *(_BYTE *)(a1 + 124) == 1 )
                    {
                      v116 = *(void (__fastcall **)(__int64, unsigned __int64 *, __int64))(a1 + 552);
                      v117 = *(_QWORD *)a1;
                      if ( *((_DWORD *)v116 - 1) != 1848957961 )
                        __break(0x8228u);
                      v116(v117, v302, 1);
                      goto LABEL_158;
                    }
                    if ( (unsigned int)cds_get_radio_index(v87, v88) != -22 )
                    {
                      v119 = *(void (**)(void))(a1 + 544);
                      if ( *((_DWORD *)v119 - 1) != -1162056974 )
                        __break(0x8228u);
                      v119();
LABEL_158:
                      v120 = *(_DWORD *)(a1 + 88);
                      v121 = *(_QWORD *)(a1 + 1080);
                      *(_QWORD *)(a1 + 1096) = a2;
                      v122 = *(_QWORD *)(a1 + 864);
                      *(_QWORD *)(a1 + 864) = 0;
                      v123 = v122 * (unsigned __int64)(unsigned int)(1000 * v120) / a4;
                      v124 = *(_QWORD *)(a1 + 1072) + v123;
                      *(_QWORD *)(a1 + 1072) = v123;
                      v125 = v124 >> 1;
                      if ( a2 >= v123 )
                        v126 = a2 - v123;
                      else
                        v126 = 0;
                      *(_QWORD *)(a1 + 1080) = v126;
                      v127 = v125 + ((v121 + v126) >> 1);
                      v128 = (__int64)qdf_cpumask_clear(&v301);
                      v282 = v109;
                      if ( v125 <= *(unsigned int *)(a1 + 64) )
                      {
                        if ( v127 <= *(unsigned int *)(a1 + 76) )
                        {
                          v149 = 0;
                          goto LABEL_181;
                        }
                        v128 = (__int64)qdf_cpumask_clear(&v301);
                        v145 = 0;
                        v146 = _cpu_online_mask;
                        do
                        {
                          v147 = v146 & (unsigned int)(-1LL << v145);
                          if ( !(_DWORD)v147 )
                            break;
                          v148 = __clz(__rbit64(v147));
                          if ( !cpu_topology[12 * (unsigned int)v148 + 2] )
                          {
                            v128 = qdf_cpumask_set_cpu((unsigned int)v148, (__int64)&v301);
                            v146 = _cpu_online_mask;
                          }
                          v145 = v148 + 1;
                        }
                        while ( v148 < 0x1F );
                        v149 = 0;
                      }
                      else
                      {
                        v128 = (__int64)qdf_cpumask_clear(&v301);
                        v138 = 0;
                        v139 = _cpu_online_mask;
                        do
                        {
                          v140 = v139 & (unsigned int)(-1LL << v138);
                          if ( !(_DWORD)v140 )
                            break;
                          v141 = __clz(__rbit64(v140));
                          v142 = cpu_topology[12 * (unsigned int)v141 + 2];
                          if ( (v142 & 0x80000000) == 0 )
                          {
                            v104 = v142 == 0;
                            v143 = (1LL << v142) & 6;
                            if ( v104 || v143 != 0 )
                            {
                              v128 = qdf_cpumask_set_cpu((unsigned int)v141, (__int64)&v301);
                              v139 = _cpu_online_mask;
                            }
                          }
                          v138 = v141 + 1;
                        }
                        while ( v141 <= 0x1E );
                        v149 = 1;
                      }
                      a1 = v294;
LABEL_181:
                      v150 = v286;
                      if ( v127 <= *(unsigned int *)(a1 + 116) )
                        v151 = 1;
                      else
                        v151 = 3;
                      if ( *(_BYTE *)(a1 + 96) == 1 && *(_DWORD *)(a1 + 1088) != v151 )
                      {
                        v153 = *(unsigned __int8 *)(a1 + 124);
                        *(_DWORD *)(a1 + 1088) = v151;
                        v302[0] = v151 | 0x100000000LL;
                        LODWORD(v298) = v151;
                        if ( v153 == 1 )
                        {
                          v154 = *(_DWORD **)(a1 + 552);
                          v155 = *(_QWORD *)a1;
                          if ( *(v154 - 1) != 1848957961 )
                            __break(0x8228u);
                          ((void (__fastcall *)(__int64, unsigned __int64 *, _QWORD))v154)(v155, v302, 0);
                        }
                        else if ( (unsigned int)cds_get_radio_index(v128, v129) == -22 )
                        {
                          qdf_trace_msg(
                            0x45u,
                            2u,
                            "%s: Invalid radio index",
                            v156,
                            v157,
                            v158,
                            v159,
                            v160,
                            v161,
                            v162,
                            v163,
                            "wlan_dp_update_tcp_tx_param");
                        }
                        else
                        {
                          v164 = *(void (**)(void))(a1 + 544);
                          if ( *((_DWORD *)v164 - 1) != -1162056974 )
                            __break(0x8228u);
                          v164();
                        }
                        v152 = 1;
                      }
                      else
                      {
                        v152 = 0;
                      }
                      v277 = *(unsigned __int16 *)(a1 + 1136);
                      if ( v286 == v15 )
                      {
                        v165 = v279;
                        v166 = 0;
                      }
                      else
                      {
                        qdf_cpumask_clear(&v299);
                        if ( v15 > 3 )
                        {
                          qdf_cpumask_or(&v299, &v301, &v300);
                          if ( qdf_cpumask_empty(&v299) )
                          {
                            qdf_cpumask_clear(&v299);
                            v171 = 0;
                            v172 = _cpu_online_mask;
                            do
                            {
                              v173 = v172 & (unsigned int)(-1LL << v171);
                              if ( !(_DWORD)v173 )
                                break;
                              v174 = __clz(__rbit64(v173));
                              if ( !cpu_topology[12 * (unsigned int)v174 + 2] )
                              {
                                qdf_cpumask_set_cpu((unsigned int)v174, (__int64)&v299);
                                v172 = _cpu_online_mask;
                              }
                              v171 = v174 + 1;
                            }
                            while ( v174 < 0x1F );
                            a1 = v294;
                            v166 = 0;
                            v150 = v286;
                          }
                          else
                          {
                            v166 = 0;
                          }
                          v165 = v279;
                        }
                        else if ( v283 || v288 <= a2 )
                        {
                          v165 = 0;
                          v149 = 0;
                          v166 = 0;
                        }
                        else
                        {
                          v165 = 0;
                          v149 = 0;
                          v166 = 0;
                          if ( v15 == 2 )
                          {
                            qdf_cpumask_clear(&v299);
                            v167 = 0;
                            v168 = _cpu_online_mask;
                            do
                            {
                              v169 = v168 & (unsigned int)(-1LL << v167);
                              if ( !(_DWORD)v169 )
                                break;
                              v170 = __clz(__rbit64(v169));
                              if ( !cpu_topology[12 * (unsigned int)v170 + 2] )
                              {
                                qdf_cpumask_set_cpu((unsigned int)v170, (__int64)&v299);
                                v168 = _cpu_online_mask;
                              }
                              v167 = v170 + 1;
                            }
                            while ( v170 <= 0x1E );
                            a1 = v294;
                            v165 = 0;
                            v150 = v286;
                            v149 = 0;
                            v166 = 1;
                          }
                        }
                        v175 = *(void (__fastcall **)(__int64, __int64 *))(a1 + 584);
                        if ( *((_DWORD *)v175 - 1) != -1554341570 )
                          __break(0x8228u);
                        v175(v292, &v299);
                        if ( *(_QWORD *)v278
                          && (v184 = *(_QWORD *)(*(_QWORD *)v278 + 64LL)) != 0
                          && (v185 = *(void (**)(void))(v184 + 304)) != nullptr )
                        {
                          if ( *((_DWORD *)v185 - 1) != -251540498 )
                            __break(0x8228u);
                          v185();
                        }
                        else
                        {
                          qdf_trace_msg(
                            0x89u,
                            8u,
                            "%s: Invalid Instance:",
                            v176,
                            v177,
                            v178,
                            v179,
                            v180,
                            v181,
                            v182,
                            v183,
                            "cdp_set_bus_vote_lvl_high");
                        }
                      }
                      if ( v150 == v15 )
                        v186 = v152;
                      else
                        v186 = 1;
                      if ( v282 != v113 || v186 )
                      {
                        qdf_trace_msg(
                          0x45u,
                          5u,
                          "%s: tx:%llu[%llu(off)+%llu(no-off)] rx:%llu[%llu(off)+%llu(no-off)] next_level(vote %u rx %u t"
                          "x %u rtpm %lu) pm_qos(rx:%u,%*pb tx:%u,%*pb on_low_tput:%u)",
                          v130,
                          v131,
                          v132,
                          v133,
                          v134,
                          v135,
                          v136,
                          v137,
                          "dp_pld_request_bus_bandwidth",
                          a2,
                          *(_QWORD *)(a1 + 1080),
                          *(_QWORD *)(a1 + 1072),
                          v288,
                          *(_QWORD *)(a1 + 1064),
                          *(_QWORD *)(a1 + 1056),
                          v15,
                          dp_pld_request_bus_bandwidth_next_rx_level,
                          v151,
                          *(_QWORD *)(a1 + 1120),
                          v165,
                          nr_cpu_ids,
                          &v300,
                          v149,
                          nr_cpu_ids,
                          &v301,
                          v166);
                        v187 = *(_QWORD *)(a1 + 1144);
                        if ( v187 )
                        {
                          v188 = 40 * v277;
                          *(_DWORD *)(v187 + 40 * v277 + 24) = v151;
                          *(_DWORD *)(*(_QWORD *)(a1 + 1144) + v188 + 20) = dp_pld_request_bus_bandwidth_next_rx_level;
                          *(_BYTE *)(*(_QWORD *)(a1 + 1144) + v188 + 28) = v165;
                          *(_BYTE *)(*(_QWORD *)(a1 + 1144) + v188 + 29) = v149;
                          *(_DWORD *)(*(_QWORD *)(a1 + 1144) + v188 + 16) = v15;
                          *(_QWORD *)(*(_QWORD *)(a1 + 1144) + v188) = v288;
                          *(_QWORD *)(*(_QWORD *)(a1 + 1144) + v188 + 8) = a2;
                          __isb(0xFu);
                          *(_QWORD *)(*(_QWORD *)(a1 + 1144) + v188 + 32) = _ReadStatusReg(CNTVCT_EL0);
                          *(_WORD *)(a1 + 1136) = ((unsigned __int8)*(_WORD *)(a1 + 1136) + 1) & 0x7F;
                        }
                      }
                      v189 = *(__int64 (__fastcall **)(_QWORD))(a1 + 616);
                      if ( *((_DWORD *)v189 - 1) != 859392181 )
                        __break(0x8228u);
                      v190 = v291;
                      if ( (v189(v292) & 1) != 0 )
                        goto LABEL_335;
                      v191 = *(_QWORD *)a1;
                      v192 = *(_QWORD *)(a1 + 376);
                      v297 = 0;
                      wlan_mlme_stats_get_periodic_display_time(v191, &v297);
                      if ( !v297 )
                        goto LABEL_335;
                      v287 = (__int64 **)_cds_get_context(71, "dp_display_periodic_stats");
                      if ( !v287 )
                        goto LABEL_335;
                      v193 = ++dp_display_periodic_stats_counter;
                      if ( v280 )
                        dp_display_periodic_stats_data_in_time_period = 1;
                      if ( *(_DWORD *)(a1 + 88) * v193 < (unsigned int)(1000 * v297) )
                        goto LABEL_335;
                      v194 = _cds_get_context(61, "dp_display_periodic_stats");
                      ((void (__fastcall *)(__int64))hif_rtpm_display_last_busy_hist)(v194);
                      if ( dp_display_periodic_stats_data_in_time_period != 1 )
                      {
LABEL_334:
                        dp_display_periodic_stats_counter = 0;
                        dp_display_periodic_stats_data_in_time_period = 0;
LABEL_335:
                        hif_affinity_mgr_set_affinity(v285);
                        result = wlan_dp_lb_compute_stats_average(a1, v190);
                        goto LABEL_336;
                      }
                      v195 = *(_QWORD *)(a1 + 376);
                      v302[0] = 0;
                      v298 = 0;
                      v289 = v195;
                      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
                        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                      {
                        raw_spin_lock(a1 + 264);
                      }
                      else
                      {
                        raw_spin_lock_bh(a1 + 264);
                        *(_QWORD *)(a1 + 272) |= 1uLL;
                      }
                      dp_get_front_intf_no_lock(a1, v302);
                      dp_get_next_intf_no_lock(a1, v302[0], &v298);
                      v197 = *(_QWORD *)(a1 + 272);
                      v284 = v192;
                      if ( (v197 & 1) != 0 )
                      {
                        *(_QWORD *)(a1 + 272) = v197 & 0xFFFFFFFFFFFFFFFELL;
                        raw_spin_unlock_bh(a1 + 264);
                        v206 = (unsigned __int8 *)v302[0];
                        if ( !v302[0] )
                          goto LABEL_282;
                      }
                      else
                      {
                        raw_spin_unlock(a1 + 264);
                        v206 = (unsigned __int8 *)v302[0];
                        if ( !v302[0] )
                          goto LABEL_282;
                      }
                      v207 = "wlan_dp_display_txrx_stats";
                      v290 = _ReadStatusReg(SP_EL0);
                      do
                      {
                        while ( 1 )
                        {
                          if ( v206[3661] )
                          {
                            v293 = (unsigned int *)v206;
                            v208 = v206 + 232;
                            v209 = v207;
                            qdf_trace_msg(
                              0x45u,
                              5u,
                              "%s: dp_intf: %02x:%02x:%02x:**:**:%02x",
                              v198,
                              v199,
                              v200,
                              v201,
                              v202,
                              v203,
                              v204,
                              v205,
                              v207,
                              v206[20],
                              v206[21],
                              v206[22],
                              v206[25]);
                            v218 = 0;
                            v219 = 0;
                            v220 = 0;
                            v221 = 0;
                            v222 = 0;
                            v223 = 0;
                            v224 = 0;
                            v225 = 0;
                            do
                            {
                              v226 = &v208[v218];
                              v218 += 76;
                              v225 += *((_DWORD *)v226 + 15);
                              v224 += *((_DWORD *)v226 + 16);
                              v223 += *((_DWORD *)v226 + 17);
                              v222 += *((_DWORD *)v226 + 18);
                              v221 += *(_DWORD *)v226;
                              v220 += *((_DWORD *)v226 + 1);
                              v219 += *((_DWORD *)v226 + 2);
                            }
                            while ( v218 != 2432 );
                            v227 = 0;
                            v228 = v293 + 60;
                            do
                            {
                              v229 = *(v228 - 2);
                              if ( (_DWORD)v229 )
                                qdf_trace_msg(
                                  0x45u,
                                  5u,
                                  "%s: Tx CPU[%d]: called %u, dropped %u, orphaned %u",
                                  v210,
                                  v211,
                                  v212,
                                  v213,
                                  v214,
                                  v215,
                                  v216,
                                  v217,
                                  v209,
                                  (unsigned int)v227,
                                  v229,
                                  *(v228 - 1),
                                  *v228);
                              ++v227;
                              v228 += 19;
                            }
                            while ( v227 != 32 );
                            v207 = v209;
                            qdf_trace_msg(
                              0x45u,
                              5u,
                              "%s: TX - called %u, dropped %u orphan %u",
                              v210,
                              v211,
                              v212,
                              v213,
                              v214,
                              v215,
                              v216,
                              v217,
                              v209,
                              v221,
                              v220,
                              v219);
                            v230 = *(void (__fastcall **)(__int64, __int64))(v294 + 648);
                            v231 = *(_QWORD *)(v302[0] + 56);
                            if ( *((_DWORD *)v230 - 1) != 1130147156 )
                              __break(0x8229u);
                            v230(v289, v231);
                            v240 = 0;
                            v241 = v293 + 76;
                            do
                            {
                              v242 = (unsigned int)*(v241 - 3);
                              if ( (_DWORD)v242 )
                              {
                                LODWORD(v269) = *v241;
                                qdf_trace_msg(
                                  0x45u,
                                  5u,
                                  "%s: Rx CPU[%d]: packets %u, dropped %u, delivered %u, refused %u",
                                  v232,
                                  v233,
                                  v234,
                                  v235,
                                  v236,
                                  v237,
                                  v238,
                                  v239,
                                  v209,
                                  (unsigned int)v240,
                                  v242,
                                  (unsigned int)*(v241 - 2),
                                  (unsigned int)*(v241 - 1),
                                  v269);
                              }
                              ++v240;
                              v241 += 19;
                            }
                            while ( v240 != 32 );
                            a1 = v294;
                            LODWORD(v275) = *(_DWORD *)(v294 + 1128);
                            LODWORD(v276) = *(_DWORD *)(v294 + 1132);
                            LODWORD(v274) = v293[671];
                            LODWORD(v273) = v293[670];
                            LODWORD(v272) = v293[669];
                            LODWORD(v271) = v293[668];
                            LODWORD(v270) = v293[667];
                            LODWORD(v269) = v222;
                            qdf_trace_msg(
                              0x45u,
                              5u,
                              "%s: RX - packets %u, dropped %u, unsol_arp_mcast_drp %u, delivered %u, refused %u GRO - ag"
                              "g %u drop %u non-agg %u flush_skip %u low_tput_flush %u disabled(conc %u low-tput %u)",
                              v232,
                              v233,
                              v234,
                              v235,
                              v236,
                              v237,
                              v238,
                              v239,
                              v209,
                              v225,
                              v224,
                              v293[666],
                              v223,
                              v269,
                              v270,
                              v271,
                              v272,
                              v273,
                              v274,
                              v275,
                              v276);
                            v190 = v291;
                          }
                          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                            || (*(_DWORD *)(v290 + 16) & 0xF0000) != 0
                            || (*(_DWORD *)(v290 + 16) & 0xFF00) != 0 )
                          {
                            raw_spin_lock(a1 + 264);
                          }
                          else
                          {
                            raw_spin_lock_bh(a1 + 264);
                            *(_QWORD *)(a1 + 272) |= 1uLL;
                          }
                          v302[0] = v298;
                          dp_get_next_intf_no_lock(a1, v298, &v298);
                          v243 = *(_QWORD *)(a1 + 272);
                          if ( (v243 & 1) != 0 )
                            break;
                          raw_spin_unlock(a1 + 264);
                          v206 = (unsigned __int8 *)v302[0];
                          if ( !v302[0] )
                            goto LABEL_282;
                        }
                        *(_QWORD *)(a1 + 272) = v243 & 0xFFFFFFFFFFFFFFFELL;
                        raw_spin_unlock_bh(a1 + 264);
                        v206 = (unsigned __int8 *)v302[0];
                      }
                      while ( v302[0] );
LABEL_282:
                      if ( *v287 )
                      {
                        v244 = v284;
                        v245 = *(__int64 (__fastcall **)(_QWORD))(**v287 + 624);
                        if ( v245 )
                        {
                          if ( *((_DWORD *)v245 - 1) != -1355198606 )
                            __break(0x8228u);
                          v246 = v245(v287);
                          if ( v246 )
                            dp_rx_tm_dump_stats(v246 + 16);
                        }
                      }
                      else
                      {
                        qdf_trace_msg(
                          0x89u,
                          8u,
                          "%s: Invalid Instance:",
                          v198,
                          v199,
                          v200,
                          v201,
                          v202,
                          v203,
                          v204,
                          v205,
                          "cdp_soc_get_dp_txrx_handle");
                        v244 = v284;
                      }
                      if ( *v287 )
                      {
                        v247 = **v287;
                        if ( !v247 )
                          goto LABEL_324;
                        v248 = *(_DWORD **)(v247 + 528);
                        if ( v248 )
                        {
                          if ( *(v248 - 1) != 358154616 )
                            __break(0x8228u);
                          ((void (__fastcall *)(__int64 **, __int64, _QWORD))v248)(v287, 11, 0);
                        }
                      }
                      else
                      {
                        qdf_trace_msg(
                          0x89u,
                          8u,
                          "%s: Invalid Instance:",
                          v198,
                          v199,
                          v200,
                          v201,
                          v202,
                          v203,
                          v204,
                          v205,
                          "cdp_display_stats");
                      }
                      if ( *v287 )
                      {
                        v249 = **v287;
                        if ( !v249 )
                          goto LABEL_324;
                        v250 = *(_DWORD **)(v249 + 528);
                        if ( v250 )
                        {
                          if ( *(v250 - 1) != 358154616 )
                            __break(0x8228u);
                          ((void (__fastcall *)(__int64 **, __int64, _QWORD))v250)(v287, 12, 0);
                        }
                      }
                      else
                      {
                        qdf_trace_msg(
                          0x89u,
                          8u,
                          "%s: Invalid Instance:",
                          v198,
                          v199,
                          v200,
                          v201,
                          v202,
                          v203,
                          v204,
                          v205,
                          "cdp_display_stats");
                      }
                      if ( *v287 )
                      {
                        v251 = **v287;
                        if ( !v251 )
                          goto LABEL_324;
                        v252 = *(_DWORD **)(v251 + 528);
                        if ( v252 )
                        {
                          if ( *(v252 - 1) != 358154616 )
                            __break(0x8228u);
                          ((void (__fastcall *)(__int64 **, __int64, _QWORD))v252)(v287, 1, 0);
                        }
                      }
                      else
                      {
                        qdf_trace_msg(
                          0x89u,
                          8u,
                          "%s: Invalid Instance:",
                          v198,
                          v199,
                          v200,
                          v201,
                          v202,
                          v203,
                          v204,
                          v205,
                          "cdp_display_stats");
                      }
                      if ( !*v287 )
                      {
                        qdf_trace_msg(
                          0x89u,
                          8u,
                          "%s: Invalid Instance:",
                          v198,
                          v199,
                          v200,
                          v201,
                          v202,
                          v203,
                          v204,
                          v205,
                          "cdp_display_stats");
LABEL_317:
                        if ( *v287 )
                        {
                          v255 = **v287;
                          if ( v255 )
                          {
                            v256 = *(_DWORD **)(v255 + 528);
                            if ( v256 )
                            {
                              if ( *(v256 - 1) != 358154616 )
                                __break(0x8228u);
                              ((void (__fastcall *)(__int64 **, __int64, _QWORD))v256)(v287, 27, 0);
                            }
                          }
                        }
                        else
                        {
                          qdf_trace_msg(
                            0x89u,
                            8u,
                            "%s: Invalid Instance:",
                            v198,
                            v199,
                            v200,
                            v201,
                            v202,
                            v203,
                            v204,
                            v205,
                            "cdp_display_stats");
                        }
                        goto LABEL_324;
                      }
                      v253 = **v287;
                      if ( v253 )
                      {
                        v254 = *(_DWORD **)(v253 + 528);
                        if ( v254 )
                        {
                          if ( *(v254 - 1) != 358154616 )
                            __break(0x8228u);
                          ((void (__fastcall *)(__int64 **, __int64, _QWORD))v254)(v287, 5, 0);
                        }
                        goto LABEL_317;
                      }
LABEL_324:
                      v257 = *(_DWORD **)(a1 + 656);
                      if ( *(v257 - 1) != -315990003 )
                        __break(0x8228u);
                      ((void (__fastcall *)(__int64, _QWORD))v257)(v244, 0);
                      if ( *v287 && (v266 = (*v287)[8]) != 0 )
                      {
                        v267 = *(void (__fastcall **)(_QWORD))(v266 + 280);
                        if ( v267 )
                        {
                          if ( *((_DWORD *)v267 - 1) != 944657148 )
                            __break(0x8228u);
                          v267(v287);
                        }
                      }
                      else
                      {
                        qdf_trace_msg(
                          0x89u,
                          8u,
                          "%s: Invalid Instance:",
                          v258,
                          v259,
                          v260,
                          v261,
                          v262,
                          v263,
                          v264,
                          v265,
                          "cdp_display_txrx_hw_info");
                      }
                      qdf_dp_trace_dump_stats(v258, v259, v260, v261, v262, v263, v264, v265);
                      v268 = wlan_dp_stc_dump_periodic_stats(a1);
                      ucfg_ipa_dump_logging_stats(v268);
                      goto LABEL_334;
                    }
                    v118 = "%s: Invalid radio index";
                  }
                  else
                  {
                    v118 = "%s: psoc is null";
                  }
                  qdf_trace_msg(0x45u, 2u, v118, v89, v90, v91, v92, v93, v94, v95, v96, "wlan_dp_update_tcp_rx_param");
                  goto LABEL_158;
                }
              }
              else
              {
                v115 = 2;
                if ( !*(_DWORD *)(a1 + 100) )
                  goto LABEL_146;
              }
              WORD2(v302[0]) = v115;
              goto LABEL_146;
            }
            v111 = 3;
          }
          dp_pld_request_bus_bandwidth_next_rx_level = v111;
          goto LABEL_140;
        }
      }
      else
      {
        if ( v43 && *(_QWORD *)v43 && (v53 = *(_QWORD *)(*(_QWORD *)v43 + 64LL)) != 0 )
        {
          v54 = *(void (__fastcall **)(_QWORD))(v53 + 288);
          if ( v54 )
          {
            if ( *((_DWORD *)v54 - 1) != -1666142433 )
              __break(0x8228u);
            v54(v43);
          }
        }
        else
        {
          qdf_trace_msg(
            0x89u,
            8u,
            "%s: Invalid Instance:",
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            "cdp_get_tx_rings_grp_bitmap");
        }
        hif_set_grp_intr_affinity(v44);
        a1 = v294;
      }
      if ( !*(_DWORD *)(a1 + 232) )
        goto LABEL_93;
      goto LABEL_62;
    }
    if ( !*(_DWORD *)(a1 + 1104) || *(_BYTE *)(a1 + 371) != 1 )
    {
LABEL_39:
      a1 = v294;
      *(_DWORD *)(v294 + 1108) = 0;
      *(_DWORD *)(v294 + 1104) = 0;
      goto LABEL_40;
    }
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: flush queued GRO pkts",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "dp_low_tput_gro_flush_skip_handler");
    v37 = 0;
    while ( v19 )
    {
      if ( !*(_QWORD *)v19 )
        break;
      v38 = *(_QWORD *)(*(_QWORD *)v19 + 64LL);
      if ( !v38 )
        break;
      v39 = *(int (__fastcall **)(_QWORD))(v38 + 176);
      if ( !v39 )
        goto LABEL_29;
      if ( *((_DWORD *)v39 - 1) != 639071501 )
        __break(0x8228u);
      if ( v37 >= v39(v19) )
        goto LABEL_39;
LABEL_30:
      if ( v19 )
      {
        if ( *(_QWORD *)v19 )
        {
          v40 = *(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)v19 + 624LL);
          if ( v40 )
          {
            if ( *((_DWORD *)v40 - 1) != -1355198606 )
              __break(0x8228u);
            v41 = v40(v19);
            if ( v41 )
              dp_rx_tm_gro_flush_ind(v41 + 16, (unsigned int)v37, 1);
          }
          ++v37;
        }
        else
        {
          qdf_trace_msg(
            0x89u,
            8u,
            "%s: Invalid Instance:",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "cdp_soc_get_dp_txrx_handle");
          ++v37;
        }
      }
      else
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: invalid input param soc %pK",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "dp_rx_gro_flush_ind",
          0);
        ++v37;
      }
    }
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v29, v30, v31, v32, v33, v34, v35, v36, "cdp_get_num_rx_contexts");
LABEL_29:
    if ( v37 >= 0 )
      goto LABEL_39;
    goto LABEL_30;
  }
LABEL_336:
  _ReadStatusReg(SP_EL0);
  return result;
}
