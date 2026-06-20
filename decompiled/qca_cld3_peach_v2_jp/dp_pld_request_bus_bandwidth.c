__int64 __fastcall dp_pld_request_bus_bandwidth(
        __int64 a1,
        unsigned __int64 a2,
        unsigned __int64 a3,
        unsigned int a4,
        char a5)
{
  __int64 context; // x0
  unsigned __int64 v11; // x1
  unsigned int v12; // w24
  char v13; // w19
  unsigned int v14; // w23
  __int64 v15; // x0
  __int64 v16; // x20
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
  int v33; // w22
  __int64 v34; // x8
  int (__fastcall *v35)(_QWORD); // x8
  __int64 (__fastcall *v36)(_QWORD); // x8
  __int64 v37; // x0
  __int64 v38; // x22
  unsigned int v39; // w19
  __int64 v40; // x21
  __int64 v41; // x20
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x8
  void (__fastcall *v51)(_QWORD); // x8
  __int64 v52; // x8
  void (__fastcall *v53)(_QWORD); // x8
  unsigned int v54; // w19
  char v55; // w9
  int v56; // w8
  unsigned __int64 v57; // x9
  unsigned __int64 v58; // x20
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x0
  __int64 (*v68)(void); // x8
  __int64 v69; // x0
  char updated; // w0
  void (__fastcall *v71)(_QWORD); // x8
  void (__fastcall *v72)(__int64, unsigned __int64, unsigned __int64); // x8
  _DWORD *v73; // x8
  __int64 v74; // x11
  int v75; // w21
  __int64 v76; // x8
  __int64 v77; // x9
  unsigned __int64 v78; // x8
  unsigned __int64 v79; // x9
  unsigned __int64 v80; // x20
  unsigned __int64 v81; // x9
  unsigned __int64 v82; // x19
  __int64 v83; // x0
  __int64 v84; // x1
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  unsigned __int64 v93; // x8
  char v94; // w9
  int v95; // w8
  unsigned __int64 v96; // x9
  unsigned __int64 v97; // x20
  int v98; // w9
  __int64 v99; // x9
  bool v100; // zf
  char v101; // w9
  int v102; // w8
  unsigned __int64 v103; // x9
  unsigned __int64 v104; // x20
  int v105; // w28
  int v106; // w8
  int v107; // w8
  char v108; // w8
  int v109; // w26
  int v110; // w8
  __int16 v111; // w8
  void (__fastcall *v112)(__int64, unsigned __int64 *, __int64); // x8
  __int64 v113; // x0
  const char *v114; // x2
  void (*v115)(void); // x8
  int v116; // w8
  __int64 v117; // x11
  __int64 v118; // x9
  unsigned __int64 v119; // x8
  unsigned __int64 v120; // x9
  unsigned __int64 v121; // x20
  unsigned __int64 v122; // x8
  unsigned __int64 v123; // x19
  __int64 v124; // x0
  __int64 v125; // x1
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  char v134; // w9
  int v135; // w8
  unsigned __int64 v136; // x9
  unsigned __int64 v137; // x20
  int v138; // w9
  __int64 v139; // x9
  char v141; // w9
  int v142; // w8
  unsigned __int64 v143; // x9
  unsigned __int64 v144; // x20
  int v145; // w28
  int v146; // w20
  unsigned int v147; // w27
  int v148; // w24
  int v149; // w9
  _DWORD *v150; // x8
  __int64 v151; // x0
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  void (*v160)(void); // x8
  int v161; // w21
  char v162; // w9
  int v163; // w8
  unsigned __int64 v164; // x9
  unsigned __int64 v165; // x20
  void (__fastcall *v166)(__int64, __int64 *); // x8
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  __int64 v175; // x8
  void (*v176)(void); // x8
  int v177; // w8
  __int64 v178; // x8
  __int64 v179; // x9
  __int64 (__fastcall *v180)(_QWORD); // x8
  __int64 v181; // x0
  int v182; // w8
  __int64 v183; // x0
  __int64 v184; // x8
  unsigned __int64 StatusReg; // x8
  double v186; // d0
  double v187; // d1
  double v188; // d2
  double v189; // d3
  double v190; // d4
  double v191; // d5
  double v192; // d6
  double v193; // d7
  unsigned __int64 v194; // x23
  double v195; // d0
  double v196; // d1
  double v197; // d2
  double v198; // d3
  double v199; // d4
  double v200; // d5
  double v201; // d6
  double v202; // d7
  __int64 v203; // x8
  unsigned int v204; // w24
  unsigned int v205; // w21
  unsigned int v206; // w22
  int v207; // w19
  int v208; // w27
  int v209; // w28
  int v210; // w20
  _DWORD *v211; // x9
  __int64 v212; // x23
  unsigned int *v213; // x26
  __int64 v214; // x5
  void (__fastcall *v215)(__int64, __int64); // x9
  __int64 v216; // x1
  double v217; // d0
  double v218; // d1
  double v219; // d2
  double v220; // d3
  double v221; // d4
  double v222; // d5
  double v223; // d6
  double v224; // d7
  __int64 v225; // x21
  _DWORD *v226; // x22
  __int64 v227; // x5
  __int64 v229; // [xsp+0h] [xbp-120h]
  __int64 v230; // [xsp+70h] [xbp-B0h]
  __int64 v231; // [xsp+78h] [xbp-A8h]
  int v232; // [xsp+84h] [xbp-9Ch]
  unsigned __int64 v233; // [xsp+88h] [xbp-98h]
  char v234; // [xsp+94h] [xbp-8Ch]
  int v235; // [xsp+94h] [xbp-8Ch]
  int v236; // [xsp+A8h] [xbp-78h]
  unsigned __int64 v237; // [xsp+B0h] [xbp-70h]
  __int64 v238; // [xsp+B0h] [xbp-70h]
  __int64 v239; // [xsp+C8h] [xbp-58h]
  unsigned __int64 v240; // [xsp+C8h] [xbp-58h]
  __int64 v241; // [xsp+D0h] [xbp-50h]
  __int64 v242; // [xsp+D8h] [xbp-48h] BYREF
  int v243; // [xsp+E0h] [xbp-40h]
  int v244; // [xsp+E4h] [xbp-3Ch] BYREF
  __int64 v245; // [xsp+E8h] [xbp-38h] BYREF
  __int64 v246; // [xsp+F0h] [xbp-30h] BYREF
  __int64 v247; // [xsp+F8h] [xbp-28h] BYREF
  __int64 v248; // [xsp+100h] [xbp-20h] BYREF
  unsigned __int64 v249[3]; // [xsp+108h] [xbp-18h] BYREF

  v249[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v247 = 0;
  v248 = 0;
  v246 = 0;
  v243 = 0;
  v242 = 0;
  _cds_get_context(61, "dp_pld_request_bus_bandwidth");
  context = _cds_get_context(71, "dp_pld_request_bus_bandwidth");
  if ( !context )
    JUMPOUT(0x278D84);
  v11 = a3 + a2;
  v239 = *(_QWORD *)(a1 + 376);
  v233 = a3 + a2;
  v231 = context;
  v234 = a5;
  if ( *(_BYTE *)(a1 + 880) )
    goto LABEL_3;
  if ( v11 > *(unsigned int *)(a1 + 56) )
  {
    v13 = 0;
    v12 = 8;
    v14 = 7;
    goto LABEL_8;
  }
  if ( v11 > *(unsigned int *)(a1 + 60) )
  {
    v12 = 7;
    v13 = 1;
    v14 = 6;
    goto LABEL_8;
  }
  if ( v11 > *(unsigned int *)(a1 + 64) )
  {
LABEL_3:
    v12 = 6;
    v13 = 1;
    v14 = 5;
  }
  else
  {
    if ( v11 <= *(unsigned int *)(a1 + 76) )
      JUMPOUT(0x278A34);
    updated = dp_sap_p2p_update_mid_high_tput(a1);
    if ( (updated & 1) != 0 )
      v14 = 9;
    else
      v14 = 4;
    if ( (updated & 1) != 0 )
      v12 = 5;
    else
      v12 = 4;
    v13 = 1;
  }
LABEL_8:
  if ( (ucfg_ipa_is_fw_wdi_activated(*(_QWORD *)a1) & 1) == 0
    && (policy_mgr_is_current_hwmode_dbs(*(_QWORD *)a1) & 1) != 0
    && ((unsigned __int8)v13 & (v233 > *(unsigned int *)(a1 + 68))) != 0 )
  {
    v14 = 6;
    v12 = 7;
  }
  v15 = *(_QWORD *)a1;
  LODWORD(v242) = 1;
  HIDWORD(v242) = v12;
  dp_bbm_apply_independent_policy(v15, (__int64)&v242);
  dp_rtpm_tput_policy_apply(a1, v12);
  v16 = _cds_get_context(71, "dp_low_tput_gro_flush_skip_handler");
  v241 = a1;
  v237 = a3;
  if ( *(_DWORD *)(a1 + 1104) && *(_BYTE *)(a1 + 371) == 1 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: flush queued GRO pkts",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "dp_low_tput_gro_flush_skip_handler");
    v33 = 0;
    while ( v16 )
    {
      if ( !*(_QWORD *)v16 )
        break;
      v34 = *(_QWORD *)(*(_QWORD *)v16 + 64LL);
      if ( !v34 )
        break;
      v35 = *(int (__fastcall **)(_QWORD))(v34 + 176);
      if ( !v35 )
        goto LABEL_25;
      if ( *((_DWORD *)v35 - 1) != 639071501 )
        __break(0x8228u);
      if ( v33 >= v35(v16) )
        goto LABEL_35;
LABEL_26:
      if ( v16 )
      {
        if ( *(_QWORD *)v16 )
        {
          v36 = *(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)v16 + 624LL);
          if ( v36 )
          {
            if ( *((_DWORD *)v36 - 1) != -1355198606 )
              __break(0x8228u);
            v37 = v36(v16);
            if ( v37 )
              dp_rx_tm_gro_flush_ind(v37 + 16, (unsigned int)v33, 1);
          }
          ++v33;
        }
        else
        {
          qdf_trace_msg(
            0x89u,
            8u,
            "%s: Invalid Instance:",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "cdp_soc_get_dp_txrx_handle");
          ++v33;
        }
      }
      else
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: invalid input param soc %pK",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "dp_rx_gro_flush_ind",
          0);
        ++v33;
      }
    }
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v25, v26, v27, v28, v29, v30, v31, v32, "cdp_get_num_rx_contexts");
LABEL_25:
    if ( v33 >= 0 )
      goto LABEL_35;
    goto LABEL_26;
  }
LABEL_35:
  v38 = v241;
  *(_DWORD *)(v241 + 1108) = 0;
  *(_DWORD *)(v241 + 1104) = 0;
  v236 = *(_DWORD *)(v241 + 1024);
  if ( v236 != v14 )
  {
    v39 = dp_pld_request_bus_bandwidth_prev_tput_level;
    v40 = _cds_get_context(71, "dp_set_tx_irq_affinity");
    v41 = _cds_get_context(61, "dp_set_tx_irq_affinity");
    if ( v12 < 6 || v39 > 5 )
    {
      if ( v12 <= 5 && v39 >= 6 )
      {
        if ( v40 && *(_QWORD *)v40 && (v52 = *(_QWORD *)(*(_QWORD *)v40 + 64LL)) != 0 )
        {
          v53 = *(void (__fastcall **)(_QWORD))(v52 + 288);
          if ( v53 )
          {
            if ( *((_DWORD *)v53 - 1) != -1666142433 )
              __break(0x8228u);
            v53(v40);
          }
        }
        else
        {
          qdf_trace_msg(
            0x89u,
            8u,
            "%s: Invalid Instance:",
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "cdp_get_tx_rings_grp_bitmap");
        }
        hif_set_grp_intr_affinity(v41);
        if ( !*(_DWORD *)(v241 + 232) )
          goto LABEL_88;
LABEL_57:
        v54 = dp_pld_request_bus_bandwidth_prev_tput_level;
        v249[0] = 0;
        qdf_cpumask_clear(v249);
        if ( v12 >= 6 && v54 <= 5 )
        {
          v55 = 0;
          v56 = _cpu_online_mask;
          do
          {
            v57 = v56 & (unsigned int)(-1LL << v55);
            if ( !(_DWORD)v57 )
              break;
            v58 = __clz(__rbit64(v57));
            if ( ((*(unsigned int *)(v38 + 232) >> v58) & 1) != 0 )
            {
              qdf_cpumask_set_cpu((unsigned int)v58, (__int64)v249);
              v56 = _cpu_online_mask;
            }
            v55 = v58 + 1;
          }
          while ( v58 <= 0x1E );
          goto LABEL_67;
        }
        if ( v12 <= 5 && v54 >= 6 )
        {
          qdf_cpumask_setall(v249);
LABEL_67:
          if ( !qdf_cpumask_equal((_DWORD *)(v38 + 3016), v249) )
          {
            qdf_cpumask_copy((_QWORD *)(v38 + 3016), v249);
            v67 = *(_QWORD *)(v38 + 240);
            if ( v67 )
            {
              if ( *(_QWORD *)v67 )
              {
                v68 = *(__int64 (**)(void))(**(_QWORD **)v67 + 624LL);
                if ( v68 )
                {
                  if ( *((_DWORD *)v68 - 1) != -1355198606 )
                    __break(0x8228u);
                  v69 = v68();
                  if ( v69 )
                    dp_rx_tm_set_cpu_mask(v69 + 16, v249);
                }
              }
              else
              {
                qdf_trace_msg(
                  0x89u,
                  8u,
                  "%s: Invalid Instance:",
                  v59,
                  v60,
                  v61,
                  v62,
                  v63,
                  v64,
                  v65,
                  v66,
                  "cdp_soc_get_dp_txrx_handle");
              }
            }
          }
        }
LABEL_88:
        dp_pld_request_bus_bandwidth_prev_tput_level = v12;
        *(_DWORD *)(v38 + 1024) = v14;
        v71 = *(void (__fastcall **)(_QWORD))(v38 + 600);
        if ( *((_DWORD *)v71 - 1) != -528599275 )
          __break(0x8228u);
        v71(v239);
        if ( *(_BYTE *)(v38 + 369) == 1 )
          dp_set_rps_cpu_mask(v38);
        v72 = *(void (__fastcall **)(__int64, unsigned __int64, unsigned __int64))(v38 + 640);
        if ( *((_DWORD *)v72 - 1) != -166398397 )
          __break(0x8228u);
        v72(v239, a2, a3);
        dp_disable_rx_ol_for_low_tput(v38, *(unsigned int *)(v38 + 84) > a3);
        v73 = *(_DWORD **)(v38 + 608);
        if ( *(v73 - 1) != -662079542 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))v73)(v239, 0, 0, 0);
        goto LABEL_97;
      }
    }
    else
    {
      if ( v40 && *(_QWORD *)v40 && (v50 = *(_QWORD *)(*(_QWORD *)v40 + 64LL)) != 0 )
      {
        v51 = *(void (__fastcall **)(_QWORD))(v50 + 288);
        if ( v51 )
        {
          if ( *((_DWORD *)v51 - 1) != -1666142433 )
            __break(0x8228u);
          v51(v40);
        }
      }
      else
      {
        qdf_trace_msg(
          0x89u,
          8u,
          "%s: Invalid Instance:",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "cdp_get_tx_rings_grp_bitmap");
      }
      hif_set_grp_intr_affinity(v41);
      v38 = v241;
    }
    if ( !*(_DWORD *)(v38 + 232) )
      goto LABEL_88;
    goto LABEL_57;
  }
LABEL_97:
  qdf_dp_trace_apply_tput_policy(v14 > 1);
  v74 = *(_QWORD *)(v38 + 1064);
  v75 = *(_DWORD *)(v38 + 120);
  v76 = (unsigned int)(1000 * *(_DWORD *)(v38 + 88));
  v77 = *(_QWORD *)(v38 + 856);
  *(_QWORD *)(v38 + 856) = 0;
  v78 = v77 * v76 / (unsigned __int64)a4;
  v79 = *(_QWORD *)(v38 + 1056) + v78;
  *(_QWORD *)(v38 + 1056) = v78;
  v80 = v79 >> 1;
  if ( a3 >= v78 )
    v81 = a3 - v78;
  else
    v81 = 0;
  *(_QWORD *)(v38 + 1064) = v81;
  v82 = v80 + ((v74 + v81) >> 1);
  v83 = (__int64)qdf_cpumask_clear(&v247);
  v93 = *(unsigned int *)(v38 + 76);
  if ( v80 <= v93 )
  {
    if ( v82 <= v93 )
    {
      v232 = 0;
      goto LABEL_120;
    }
    v83 = (__int64)qdf_cpumask_clear(&v247);
    v101 = 0;
    v102 = _cpu_online_mask;
    do
    {
      v103 = v102 & (unsigned int)(-1LL << v101);
      if ( !(_DWORD)v103 )
        break;
      v104 = __clz(__rbit64(v103));
      if ( !cpu_topology[12 * (unsigned int)v104 + 2] )
      {
        v83 = qdf_cpumask_set_cpu((unsigned int)v104, (__int64)&v247);
        v102 = _cpu_online_mask;
      }
      v101 = v104 + 1;
    }
    while ( v104 < 0x1F );
    v232 = 0;
  }
  else
  {
    v83 = (__int64)qdf_cpumask_clear(&v247);
    v94 = 0;
    v95 = _cpu_online_mask;
    do
    {
      v96 = v95 & (unsigned int)(-1LL << v94);
      if ( !(_DWORD)v96 )
        break;
      v97 = __clz(__rbit64(v96));
      v98 = cpu_topology[12 * (unsigned int)v97 + 2];
      if ( (v98 & 0x80000000) == 0 )
      {
        v100 = v98 == 0;
        v99 = (1LL << v98) & 6;
        v100 = !v100 && v99 == 0;
        if ( !v100 )
        {
          v83 = qdf_cpumask_set_cpu((unsigned int)v97, (__int64)&v247);
          v95 = _cpu_online_mask;
        }
      }
      v94 = v97 + 1;
    }
    while ( v97 <= 0x1E );
    v232 = 1;
  }
  v38 = v241;
LABEL_120:
  if ( v82 <= *(unsigned int *)(v38 + 108) )
  {
    v108 = *(_BYTE *)(v38 + 104);
    *(_DWORD *)(v38 + 1152) = 0;
    if ( (v108 & 1) == 0 && (v234 & 1) == 0 )
    {
      v105 = 0;
      dp_pld_request_bus_bandwidth_next_rx_level = 0;
      *(_DWORD *)(v38 + 1048) = 0;
      goto LABEL_129;
    }
    v107 = 1;
    v105 = *(_DWORD *)(v38 + 1048);
    goto LABEL_128;
  }
  v105 = *(_DWORD *)(v38 + 1048);
  if ( v105 != 3 )
  {
    v106 = *(_DWORD *)(v38 + 1152) + 1;
    *(_DWORD *)(v38 + 1152) = v106;
    if ( v106 == v75 )
    {
      v107 = 3;
LABEL_128:
      dp_pld_request_bus_bandwidth_next_rx_level = v107;
    }
  }
LABEL_129:
  v109 = dp_pld_request_bus_bandwidth_next_rx_level;
  if ( v105 == dp_pld_request_bus_bandwidth_next_rx_level )
    goto LABEL_147;
  v110 = *(unsigned __int8 *)(v38 + 848);
  v249[0] = 0;
  *(_DWORD *)(v38 + 1048) = dp_pld_request_bus_bandwidth_next_rx_level;
  if ( v110 != 1 )
  {
    v111 = 2;
    if ( !*(_DWORD *)(v38 + 100) )
      goto LABEL_135;
    goto LABEL_134;
  }
  WORD2(v249[0]) = 1;
  v111 = 3;
  if ( *(_DWORD *)(v38 + 100) )
LABEL_134:
    WORD2(v249[0]) = v111;
LABEL_135:
  LODWORD(v249[0]) = v109;
  if ( !v38 )
  {
    v114 = "%s: psoc is null";
LABEL_143:
    qdf_trace_msg(0x45u, 2u, v114, v85, v86, v87, v88, v89, v90, v91, v92, "wlan_dp_update_tcp_rx_param");
    goto LABEL_147;
  }
  if ( *(_BYTE *)(v38 + 124) == 1 )
  {
    v112 = *(void (__fastcall **)(__int64, unsigned __int64 *, __int64))(v38 + 552);
    v113 = *(_QWORD *)v38;
    if ( *((_DWORD *)v112 - 1) != 1848957961 )
      __break(0x8228u);
    v112(v113, v249, 1);
    goto LABEL_147;
  }
  if ( (unsigned int)cds_get_radio_index(v83, v84) == -22 )
  {
    v114 = "%s: Invalid radio index";
    goto LABEL_143;
  }
  v115 = *(void (**)(void))(v38 + 544);
  if ( *((_DWORD *)v115 - 1) != -1162056974 )
    __break(0x8228u);
  v115();
LABEL_147:
  v116 = *(_DWORD *)(v38 + 88);
  v117 = *(_QWORD *)(v38 + 1080);
  *(_QWORD *)(v38 + 1096) = a2;
  v118 = *(_QWORD *)(v38 + 864);
  *(_QWORD *)(v38 + 864) = 0;
  v119 = v118 * (unsigned __int64)(unsigned int)(1000 * v116) / a4;
  v120 = *(_QWORD *)(v38 + 1072) + v119;
  *(_QWORD *)(v38 + 1072) = v119;
  v121 = v120 >> 1;
  if ( a2 >= v119 )
    v122 = a2 - v119;
  else
    v122 = 0;
  *(_QWORD *)(v38 + 1080) = v122;
  v123 = v121 + ((v117 + v122) >> 1);
  v124 = (__int64)qdf_cpumask_clear(&v248);
  v235 = v105;
  if ( v121 <= *(unsigned int *)(v38 + 64) )
  {
    if ( v123 <= *(unsigned int *)(v38 + 76) )
    {
      v145 = 0;
      goto LABEL_170;
    }
    v124 = (__int64)qdf_cpumask_clear(&v248);
    v141 = 0;
    v142 = _cpu_online_mask;
    do
    {
      v143 = v142 & (unsigned int)(-1LL << v141);
      if ( !(_DWORD)v143 )
        break;
      v144 = __clz(__rbit64(v143));
      if ( !cpu_topology[12 * (unsigned int)v144 + 2] )
      {
        v124 = qdf_cpumask_set_cpu((unsigned int)v144, (__int64)&v248);
        v142 = _cpu_online_mask;
      }
      v141 = v144 + 1;
    }
    while ( v144 < 0x1F );
    v145 = 0;
  }
  else
  {
    v124 = (__int64)qdf_cpumask_clear(&v248);
    v134 = 0;
    v135 = _cpu_online_mask;
    do
    {
      v136 = v135 & (unsigned int)(-1LL << v134);
      if ( !(_DWORD)v136 )
        break;
      v137 = __clz(__rbit64(v136));
      v138 = cpu_topology[12 * (unsigned int)v137 + 2];
      if ( (v138 & 0x80000000) == 0 )
      {
        v100 = v138 == 0;
        v139 = (1LL << v138) & 6;
        if ( v100 || v139 != 0 )
        {
          v124 = qdf_cpumask_set_cpu((unsigned int)v137, (__int64)&v248);
          v135 = _cpu_online_mask;
        }
      }
      v134 = v137 + 1;
    }
    while ( v137 <= 0x1E );
    v145 = 1;
  }
  v38 = v241;
LABEL_170:
  v146 = v236;
  if ( v123 <= *(unsigned int *)(v38 + 116) )
    v147 = 1;
  else
    v147 = 3;
  if ( *(_BYTE *)(v38 + 96) == 1 && *(_DWORD *)(v38 + 1088) != v147 )
  {
    v149 = *(unsigned __int8 *)(v38 + 124);
    *(_DWORD *)(v38 + 1088) = v147;
    v249[0] = v147 | 0x100000000LL;
    LODWORD(v245) = v147;
    if ( v149 == 1 )
    {
      v150 = *(_DWORD **)(v38 + 552);
      v151 = *(_QWORD *)v38;
      if ( *(v150 - 1) != 1848957961 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, unsigned __int64 *, _QWORD))v150)(v151, v249, 0);
    }
    else if ( (unsigned int)cds_get_radio_index(v124, v125) == -22 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Invalid radio index",
        v152,
        v153,
        v154,
        v155,
        v156,
        v157,
        v158,
        v159,
        "wlan_dp_update_tcp_tx_param");
    }
    else
    {
      v160 = *(void (**)(void))(v38 + 544);
      if ( *((_DWORD *)v160 - 1) != -1162056974 )
        __break(0x8228u);
      v160();
    }
    v148 = 1;
  }
  else
  {
    v148 = 0;
  }
  v230 = *(unsigned __int16 *)(v38 + 1136);
  if ( v236 == v14 )
  {
    v161 = v232;
  }
  else
  {
    qdf_cpumask_clear(&v246);
    qdf_cpumask_or(&v246, &v248, &v247);
    if ( qdf_cpumask_empty(&v246) )
    {
      qdf_cpumask_clear(&v246);
      v162 = 0;
      v163 = _cpu_online_mask;
      do
      {
        v164 = v163 & (unsigned int)(-1LL << v162);
        if ( !(_DWORD)v164 )
          break;
        v165 = __clz(__rbit64(v164));
        if ( !cpu_topology[12 * (unsigned int)v165 + 2] )
        {
          qdf_cpumask_set_cpu((unsigned int)v165, (__int64)&v246);
          v163 = _cpu_online_mask;
        }
        v162 = v165 + 1;
      }
      while ( v165 < 0x1F );
      v38 = v241;
      v146 = v236;
    }
    v161 = v232;
    v166 = *(void (__fastcall **)(__int64, __int64 *))(v38 + 584);
    if ( *((_DWORD *)v166 - 1) != -1554341570 )
      __break(0x8228u);
    v166(v239, &v246);
    if ( *(_QWORD *)v231
      && (v175 = *(_QWORD *)(*(_QWORD *)v231 + 64LL)) != 0
      && (v176 = *(void (**)(void))(v175 + 304)) != nullptr )
    {
      if ( *((_DWORD *)v176 - 1) != -251540498 )
        __break(0x8228u);
      v176();
    }
    else
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance:",
        v167,
        v168,
        v169,
        v170,
        v171,
        v172,
        v173,
        v174,
        "cdp_set_bus_vote_lvl_high");
    }
  }
  if ( v146 == v14 )
    v177 = v148;
  else
    v177 = 1;
  if ( v235 != v109 || v177 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: tx:%llu[%llu(off)+%llu(no-off)] rx:%llu[%llu(off)+%llu(no-off)] next_level(vote %u rx %u tx %u rtpm %lu) pm_qo"
      "s(rx:%u,%*pb tx:%u,%*pb on_low_tput:%u)",
      v126,
      v127,
      v128,
      v129,
      v130,
      v131,
      v132,
      v133,
      "dp_pld_request_bus_bandwidth",
      a2,
      *(_QWORD *)(v38 + 1080),
      *(_QWORD *)(v38 + 1072),
      v237,
      *(_QWORD *)(v38 + 1064),
      *(_QWORD *)(v38 + 1056),
      v14,
      dp_pld_request_bus_bandwidth_next_rx_level,
      v147,
      *(_QWORD *)(v38 + 1120),
      v161,
      nr_cpu_ids,
      &v247,
      v145,
      nr_cpu_ids,
      &v248,
      0);
    v178 = *(_QWORD *)(v38 + 1144);
    if ( v178 )
    {
      v179 = 40 * v230;
      *(_DWORD *)(v178 + 40 * v230 + 24) = v147;
      *(_DWORD *)(*(_QWORD *)(v38 + 1144) + v179 + 20) = dp_pld_request_bus_bandwidth_next_rx_level;
      *(_BYTE *)(*(_QWORD *)(v38 + 1144) + v179 + 28) = v161;
      *(_BYTE *)(*(_QWORD *)(v38 + 1144) + v179 + 29) = v145;
      *(_DWORD *)(*(_QWORD *)(v38 + 1144) + v179 + 16) = v14;
      *(_QWORD *)(*(_QWORD *)(v38 + 1144) + v179) = v237;
      *(_QWORD *)(*(_QWORD *)(v38 + 1144) + v179 + 8) = a2;
      __isb(0xFu);
      *(_QWORD *)(*(_QWORD *)(v38 + 1144) + v179 + 32) = _ReadStatusReg(CNTVCT_EL0);
      *(_WORD *)(v38 + 1136) = ((unsigned __int8)*(_WORD *)(v38 + 1136) + 1) & 0x7F;
    }
  }
  v180 = *(__int64 (__fastcall **)(_QWORD))(v38 + 616);
  if ( *((_DWORD *)v180 - 1) != 859392181 )
    __break(0x8228u);
  if ( (v180(v239) & 1) != 0 )
    goto LABEL_243;
  v181 = *(_QWORD *)v38;
  v244 = 0;
  wlan_mlme_stats_get_periodic_display_time(v181, &v244);
  if ( !v244 || !_cds_get_context(71, "dp_display_periodic_stats") )
    goto LABEL_243;
  v182 = ++dp_display_periodic_stats_counter;
  if ( v233 )
    dp_display_periodic_stats_data_in_time_period = 1;
  if ( *(_DWORD *)(v38 + 88) * v182 < (unsigned int)(1000 * v244) )
LABEL_243:
    JUMPOUT(0x278D70);
  v183 = _cds_get_context(61, "dp_display_periodic_stats");
  ((void (__fastcall *)(__int64))hif_rtpm_display_last_busy_hist)(v183);
  if ( dp_display_periodic_stats_data_in_time_period != 1 )
    JUMPOUT(0x278D68);
  v184 = *(_QWORD *)(v38 + 376);
  v249[0] = 0;
  v245 = 0;
  v238 = v184;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
      JUMPOUT(0x278DBC);
  }
  raw_spin_lock(v38 + 264);
  dp_get_front_intf_no_lock(v38, v249);
  dp_get_next_intf_no_lock(v38, v249[0], &v245);
  if ( (*(_QWORD *)(v38 + 272) & 1) != 0 )
    JUMPOUT(0x278A64);
  raw_spin_unlock(v38 + 264);
  if ( !v249[0] )
    JUMPOUT(0x278A7C);
  _ReadStatusReg(SP_EL0);
  if ( !*(_BYTE *)(v249[0] + 3661) )
    JUMPOUT(0x2789A0);
  v240 = v249[0];
  v194 = v249[0] + 232;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: dp_intf: %02x:%02x:%02x:**:**:%02x",
    v186,
    v187,
    v188,
    v189,
    v190,
    v191,
    v192,
    v193,
    "wlan_dp_display_txrx_stats",
    *(unsigned __int8 *)(v249[0] + 20),
    *(unsigned __int8 *)(v249[0] + 21),
    *(unsigned __int8 *)(v249[0] + 22),
    *(unsigned __int8 *)(v249[0] + 25));
  v203 = 0;
  v204 = 0;
  v205 = 0;
  v206 = 0;
  v207 = 0;
  v208 = 0;
  v209 = 0;
  v210 = 0;
  do
  {
    v211 = (_DWORD *)(v194 + v203);
    v203 += 76;
    v210 += v211[15];
    v209 += v211[16];
    v208 += v211[17];
    v207 += v211[18];
    v206 += *v211;
    v205 += v211[1];
    v204 += v211[2];
  }
  while ( v203 != 2432 );
  v212 = 0;
  v213 = (unsigned int *)(v240 + 240);
  do
  {
    v214 = *(v213 - 2);
    if ( (_DWORD)v214 )
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Tx CPU[%d]: called %u, dropped %u, orphaned %u",
        v195,
        v196,
        v197,
        v198,
        v199,
        v200,
        v201,
        v202,
        "wlan_dp_display_txrx_stats",
        (unsigned int)v212,
        v214,
        *(v213 - 1),
        *v213);
    ++v212;
    v213 += 19;
  }
  while ( v212 != 32 );
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: TX - called %u, dropped %u orphan %u",
    v195,
    v196,
    v197,
    v198,
    v199,
    v200,
    v201,
    v202,
    "wlan_dp_display_txrx_stats",
    v206,
    v205,
    v204);
  v215 = *(void (__fastcall **)(__int64, __int64))(v241 + 648);
  v216 = *(_QWORD *)(v249[0] + 56);
  if ( *((_DWORD *)v215 - 1) != 1130147156 )
    __break(0x8229u);
  v215(v238, v216);
  v225 = 0;
  v226 = (_DWORD *)(v240 + 304);
  do
  {
    v227 = (unsigned int)*(v226 - 3);
    if ( (_DWORD)v227 )
    {
      LODWORD(v229) = *v226;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Rx CPU[%d]: packets %u, dropped %u, delivered %u, refused %u",
        v217,
        v218,
        v219,
        v220,
        v221,
        v222,
        v223,
        v224,
        "wlan_dp_display_txrx_stats",
        (unsigned int)v225,
        v227,
        (unsigned int)*(v226 - 2),
        (unsigned int)*(v226 - 1),
        v229);
    }
    ++v225;
    v226 += 19;
  }
  while ( v225 != 32 );
  return sub_278954(69);
}
