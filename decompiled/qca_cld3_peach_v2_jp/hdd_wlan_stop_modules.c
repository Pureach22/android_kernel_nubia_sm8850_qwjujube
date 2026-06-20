__int64 __fastcall hdd_wlan_stop_modules(
        _QWORD *a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char driver_state; // w21
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
  _QWORD *context; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  _QWORD *v38; // x24
  __int64 v39; // x0
  int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x5
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int v74; // w20
  __int64 v75; // x0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  const char *v92; // x2
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  unsigned int v101; // w20
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  __int64 **v118; // x0
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  __int64 v127; // x8
  __int64 (*v128)(void); // x8
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  unsigned int v145; // w0
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  unsigned int v170; // w0
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  double v179; // d0
  double v180; // d1
  double v181; // d2
  double v182; // d3
  double v183; // d4
  double v184; // d5
  double v185; // d6
  double v186; // d7
  unsigned int v187; // w0
  double v188; // d0
  double v189; // d1
  double v190; // d2
  double v191; // d3
  double v192; // d4
  double v193; // d5
  double v194; // d6
  double v195; // d7
  unsigned int v196; // w0
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  __int64 v205; // x8
  _QWORD *v206; // x0
  __int64 v207; // x23
  unsigned int v208; // w25
  __int64 v209; // x0
  double v210; // d0
  double v211; // d1
  double v212; // d2
  double v213; // d3
  double v214; // d4
  double v215; // d5
  double v216; // d6
  double v217; // d7
  double v218; // d0
  double v219; // d1
  double v220; // d2
  double v221; // d3
  double v222; // d4
  double v223; // d5
  double v224; // d6
  double v225; // d7
  double v226; // d0
  double v227; // d1
  double v228; // d2
  double v229; // d3
  double v230; // d4
  double v231; // d5
  double v232; // d6
  double v233; // d7
  __int64 v234; // x0
  double v235; // d0
  double v236; // d1
  double v237; // d2
  double v238; // d3
  double v239; // d4
  double v240; // d5
  double v241; // d6
  double v242; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v244; // x0
  __int64 v245; // x20
  __int64 v246; // x22
  __int64 v247; // x8
  double v248; // d0
  double v249; // d1
  double v250; // d2
  double v251; // d3
  double v252; // d4
  double v253; // d5
  double v254; // d6
  double v255; // d7
  __int64 v256; // x21
  __int64 v257; // x8
  __int64 v258; // x0
  double v259; // d0
  double v260; // d1
  double v261; // d2
  double v262; // d3
  double v263; // d4
  double v264; // d5
  double v265; // d6
  double v266; // d7
  __int64 v267; // x19
  __int64 v268; // x8
  __int64 v269; // x8
  unsigned int *v270; // x8
  unsigned int v271; // w10
  __int64 v272; // x8
  double v274; // d0
  double v275; // d1
  double v276; // d2
  double v277; // d3
  double v278; // d4
  double v279; // d5
  double v280; // d6
  double v281; // d7
  __int64 v282; // x0
  __int64 v283; // x0
  double v284; // d0
  double v285; // d1
  double v286; // d2
  double v287; // d3
  double v288; // d4
  double v289; // d5
  double v290; // d6
  double v291; // d7
  unsigned int v297; // w9
  _QWORD *v298; // x1
  __int64 v299; // x9
  unsigned __int64 v300; // x8
  __int64 v301; // x9
  unsigned int *v302; // x9
  unsigned int v303; // w12
  __int64 v304; // x9
  __int64 v306; // x0
  __int64 v307; // x19
  __int64 v308; // x9
  unsigned __int64 v309; // x8
  __int64 v310; // x9
  unsigned int *v311; // x9
  unsigned int v312; // w12
  __int64 v313; // x9
  __int64 v315; // x0
  double v316; // d0
  double v317; // d1
  double v318; // d2
  double v319; // d3
  double v320; // d4
  double v321; // d5
  double v322; // d6
  double v323; // d7
  double v324; // d0
  double v325; // d1
  double v326; // d2
  double v327; // d3
  double v328; // d4
  double v329; // d5
  double v330; // d6
  double v331; // d7
  double v332; // d0
  double v333; // d1
  double v334; // d2
  double v335; // d3
  double v336; // d4
  double v337; // d5
  double v338; // d6
  double v339; // d7
  double v340; // d0
  double v341; // d1
  double v342; // d2
  double v343; // d3
  double v344; // d4
  double v345; // d5
  double v346; // d6
  double v347; // d7
  double v348; // d0
  double v349; // d1
  double v350; // d2
  double v351; // d3
  double v352; // d4
  double v353; // d5
  double v354; // d6
  double v355; // d7
  unsigned __int64 v356; // x8
  __int64 v357; // x0
  __int64 v358; // x22
  __int64 v359; // x21
  __int64 v360; // x8
  double v361; // d0
  double v362; // d1
  double v363; // d2
  double v364; // d3
  double v365; // d4
  double v366; // d5
  double v367; // d6
  double v368; // d7
  unsigned __int64 v369; // x20
  __int64 v370; // x27
  __int64 v371; // x8
  __int64 v372; // x0
  double v373; // d0
  double v374; // d1
  double v375; // d2
  double v376; // d3
  double v377; // d4
  double v378; // d5
  double v379; // d6
  double v380; // d7
  __int64 v381; // x19
  __int64 v382; // x8
  __int64 v383; // x8
  unsigned int *v384; // x8
  unsigned int v385; // w10
  __int64 v386; // x8
  double v388; // d0
  double v389; // d1
  double v390; // d2
  double v391; // d3
  double v392; // d4
  double v393; // d5
  double v394; // d6
  double v395; // d7
  unsigned int v397; // w9
  _QWORD *v398; // x1
  __int64 v399; // x9
  unsigned __int64 v400; // x8
  __int64 v401; // x9
  unsigned int *v402; // x9
  unsigned int v403; // w12
  __int64 v404; // x9
  __int64 v406; // x0
  __int64 v407; // x19
  __int64 v408; // x9
  unsigned __int64 v409; // x8
  __int64 v410; // x9
  unsigned int *v411; // x9
  unsigned int v412; // w12
  __int64 v413; // x9
  _QWORD *v416; // x19
  _QWORD *v417; // x19
  unsigned int v419; // w9
  unsigned int v421; // w9
  unsigned int v423; // w9
  unsigned int v425; // w9
  unsigned __int64 v426; // [xsp+10h] [xbp-30h]
  _QWORD *v427; // [xsp+18h] [xbp-28h]
  __int64 v428; // [xsp+20h] [xbp-20h] BYREF
  int v429; // [xsp+28h] [xbp-18h]
  _QWORD v430[2]; // [xsp+30h] [xbp-10h] BYREF

  v430[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  driver_state = cds_get_driver_state(a3, a4, a5, a6, a7, a8, a9, a10);
  v429 = 0;
  v428 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", v13, v14, v15, v16, v17, v18, v19, v20, "hdd_wlan_stop_modules");
  context = _cds_get_context(64, (__int64)"hdd_wlan_stop_modules", v21, v22, v23, v24, v25, v26, v27, v28);
  if ( !context )
  {
    v74 = -22;
    goto LABEL_189;
  }
  v38 = context;
  v39 = cds_set_driver_state(64, v30, v31, v32, v33, v34, v35, v36, v37);
  v40 = hdd_return_debugfs_threads_count(v39);
  v49 = *((unsigned __int8 *)a1 + 488);
  if ( v40 <= 0 && (v49 & 1) == 0
    || (qdf_trace_msg(
          0x33u,
          3u,
          "%s: Debugfs threads %d, wiphy suspend %d",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "hdd_wlan_stop_modules",
          (unsigned int)v40,
          v49),
        (cds_get_driver_state(v50, v51, v52, v53, v54, v55, v56, v57) & 4) != 0)
    || (cds_get_driver_state(v41, v42, v43, v44, v45, v46, v47, v48) & 8) != 0
    || (cds_get_driver_state(v41, v42, v43, v44, v45, v46, v47, v48) & 2) != 0
    || (a2 & 1) != 0 )
  {
    ucfg_dp_bus_bw_compute_timer_stop(*a1, v41, v42, v43, v44, v45, v46, v47, v48);
    v75 = policy_mgr_deregister_hdd_cb(*a1);
    if ( (_DWORD)v75 )
      v75 = qdf_trace_msg(
              0x33u,
              2u,
              "%s: HDD callback deregister with policy manager failed",
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              v83,
              "hdd_deregister_policy_manager_callback");
    hdd_free_user_wowl_ptrns(v75);
    v74 = *((_DWORD *)a1 + 366);
    if ( !v74 )
    {
      v92 = "%s: Modules not initialized just return";
      goto LABEL_187;
    }
    if ( v74 != 1 )
    {
      if ( v74 != 2 )
      {
        v74 = -22;
LABEL_188:
        qdf_trace_msg(0x33u, 8u, "%s: exit", v84, v85, v86, v87, v88, v89, v90, v91, "hdd_wlan_stop_modules");
        goto LABEL_189;
      }
      v74 = 0;
      v92 = "%s: Modules already closed";
LABEL_187:
      qdf_trace_msg(0x33u, 8u, v92, v84, v85, v86, v87, v88, v89, v90, v91, "hdd_wlan_stop_modules");
      goto LABEL_188;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Wlan transitioning (CLOSED <- ENABLED)",
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      "hdd_wlan_stop_modules");
    if ( (driver_state & 8) == 0 )
      ucfg_ipa_uc_shutdown_opt_dp_ctrl_cleanup(a1[1]);
    v93 = hdd_tx_powerboost_deinit(a1);
    if ( curr_con_mode == 8 )
    {
      v101 = 0;
    }
    else if ( curr_con_mode == 5 )
    {
      hdd_disable_power_management(a1, v93);
      v101 = 0;
    }
    else
    {
      hdd_disable_power_management(a1, v93);
      if ( !curr_con_mode )
        ucfg_dp_direct_link_deinit(*a1, (driver_state & 8) != 0);
      if ( (unsigned int)hdd_deconfigure_cds(a1, v102, v103, v104, v105, v106, v107, v108, v109) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to de-configure CDS",
          v110,
          v111,
          v112,
          v113,
          v114,
          v115,
          v116,
          v117,
          "hdd_wlan_stop_modules");
        v101 = -22;
      }
      else
      {
        v101 = 0;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: successfully Disabled the CDS modules!",
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        "hdd_wlan_stop_modules");
    }
    v118 = (__int64 **)_cds_get_context(71, (__int64)"hdd_wlan_stop_modules", v93, v94, v95, v96, v97, v98, v99, v100);
    if ( v118 && *v118 )
    {
      v127 = **v118;
      if ( v127 )
      {
        v128 = *(__int64 (**)(void))(v127 + 528);
        if ( v128 )
        {
          if ( *((_DWORD *)v128 - 1) != 358154616 )
            __break(0x8228u);
          v118 = (__int64 **)v128();
        }
      }
    }
    else
    {
      v118 = (__int64 **)qdf_trace_msg(
                           0x89u,
                           8u,
                           "%s: Invalid Instance:",
                           v119,
                           v120,
                           v121,
                           v122,
                           v123,
                           v124,
                           v125,
                           v126,
                           "cdp_display_stats");
    }
    hdd_destroy_sysfs_files(v118);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Closing CDS modules!",
      v129,
      v130,
      v131,
      v132,
      v133,
      v134,
      v135,
      v136,
      "hdd_wlan_stop_modules");
    if ( curr_con_mode != 8 )
    {
      v145 = cds_post_disable(v137, v138, v139, v140, v141, v142, v143, v144);
      if ( v145 )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to process post CDS disable! :%d",
          v146,
          v147,
          v148,
          v149,
          v150,
          v151,
          v152,
          v153,
          "hdd_wlan_stop_modules",
          v145);
      osif_dp_nud_unregister_netevent_notifier(*a1);
      unregister_inet6addr_notifier(a1 + 143);
      unregister_inetaddr_notifier(a1 + 147);
      hdd_deregister_cb((__int64)a1, v154, v155, v156, v157, v158, v159, v160, v161);
      hdd_runtime_suspend_context_deinit((__int64)a1);
      v170 = cds_dp_close(*a1, v162, v163, v164, v165, v166, v167, v168, v169);
      if ( v170 )
        qdf_trace_msg(
          0x33u,
          3u,
          "%s: Failed to stop CDS DP: %d",
          v171,
          v172,
          v173,
          v174,
          v175,
          v176,
          v177,
          v178,
          "hdd_wlan_stop_modules",
          v170);
      ucfg_mlme_pdev_close();
      dispatcher_pdev_close(a1[1]);
      v101 = hdd_objmgr_release_and_destroy_pdev(a1);
      if ( v101 )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to destroy pdev; errno:%d",
          v179,
          v180,
          v181,
          v182,
          v183,
          v184,
          v185,
          v186,
          "hdd_wlan_stop_modules",
          v101);
      v187 = cds_close(*a1);
      if ( v187 )
      {
        qdf_trace_msg(
          0x33u,
          3u,
          "%s: Failed to stop CDS: %d",
          v188,
          v189,
          v190,
          v191,
          v192,
          v193,
          v194,
          v195,
          "hdd_wlan_stop_modules",
          v187);
        v101 = -22;
      }
      v196 = wbuff_module_deinit();
      if ( v196 )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: WBUFF de-init unsuccessful; status: %d",
          v197,
          v198,
          v199,
          v200,
          v201,
          v202,
          v203,
          v204,
          "hdd_wlan_stop_modules",
          v196);
      hdd_component_psoc_close(*a1, (driver_state & 8) != 0);
      wlan_global_lmac_if_close(*a1);
    }
    if ( *a1 )
    {
      v205 = *(_QWORD *)(*a1 + 2800LL);
      if ( v205 )
        *(_BYTE *)(v205 + 486) = 0;
    }
    v206 = _cds_get_context(61, (__int64)"hdd_wlan_stop_modules", v137, v138, v139, v140, v141, v142, v143, v144);
    v207 = (__int64)v206;
    if ( v206 )
      v208 = v101;
    else
      v208 = -22;
    if ( curr_con_mode == 8 )
    {
      v209 = epping_disable();
      v206 = (_QWORD *)epping_close(v209);
    }
    v210 = ucfg_ipa_component_config_free(v206);
    hdd_hif_close((__int64)a1, v207, v210, v211, v212, v213, v214, v215, v216, v217);
    if ( (cds_get_driver_state(v218, v219, v220, v221, v222, v223, v224, v225) & 4) == 0
      && (cds_get_driver_state(v226, v227, v228, v229, v230, v231, v232, v233) & 8) == 0
      && (cds_get_driver_state(v226, v227, v228, v229, v230, v231, v232, v233) & 2) == 0 )
    {
      v208 = pld_power_off(v38[5]);
      if ( v208 )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to power down device; errno:%d",
          v226,
          v227,
          v228,
          v229,
          v230,
          v231,
          v232,
          v233,
          "hdd_wlan_stop_modules",
          v208);
    }
    v234 = wlan_hdd_free_cache_channels((__int64)a1, v226, v227, v228, v229, v230, v231, v232, v233);
    hdd_driver_mem_cleanup(v234);
    if ( (driver_state & 8) == 0 )
      v235 = wlan_hdd_free_sar_config(a1);
    hdd_sap_destroy_ctx_all((__int64)a1, (driver_state & 8) != 0, v235, v236, v237, v238, v239, v240, v241, v242);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 4);
    }
    else
    {
      raw_spin_lock_bh(a1 + 4);
      a1[5] |= 1uLL;
    }
    v430[0] = 0;
    v244 = qdf_list_peek_front(a1 + 6, v430);
    v427 = a1;
    if ( (_DWORD)v244 || (v298 = (_QWORD *)v430[0], v245 = v430[0] - 8LL, v430[0] == 8) )
    {
      v245 = 0;
    }
    else
    {
      v299 = *(__int64 *)((char *)&off_18 + v430[0]);
      if ( v299 )
      {
        v300 = _ReadStatusReg(SP_EL0);
        ++*(_DWORD *)(v300 + 16);
        v301 = *(_QWORD *)(v299 + 1320);
        v302 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v301);
        do
          v303 = __ldxr(v302);
        while ( __stxr(v303 + 1, v302) );
        v304 = *(_QWORD *)(v300 + 16) - 1LL;
        *(_DWORD *)(v300 + 16) = v304;
        if ( !v304 || !*(_QWORD *)(v300 + 16) )
        {
          v416 = v298;
          preempt_schedule_notrace(v244);
          v298 = v416;
          a1 = v427;
        }
      }
      _X8 = (unsigned int *)(v298 + 6571);
      __asm { PRFM            #0x11, [X8] }
      do
        v419 = __ldxr(_X8);
      while ( __stxr(v419 + 1, _X8) );
      v430[0] = 0;
      v306 = qdf_list_peek_next(a1 + 6, v298, v430);
      if ( !(_DWORD)v306 )
      {
        v307 = v430[0];
        v246 = v430[0] - 8LL;
        if ( v430[0] != 8 )
        {
          v308 = *(__int64 *)((char *)&off_18 + v430[0]);
          if ( v308 )
          {
            v309 = _ReadStatusReg(SP_EL0);
            ++*(_DWORD *)(v309 + 16);
            v310 = *(_QWORD *)(v308 + 1320);
            v311 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v310);
            do
              v312 = __ldxr(v311);
            while ( __stxr(v312 + 1, v311) );
            v313 = *(_QWORD *)(v309 + 16) - 1LL;
            *(_DWORD *)(v309 + 16) = v313;
            if ( !v313 || !*(_QWORD *)(v309 + 16) )
              preempt_schedule_notrace(v306);
          }
          _X8 = (unsigned int *)(v307 + 52568);
          __asm { PRFM            #0x11, [X8] }
          do
            v423 = __ldxr(_X8);
          while ( __stxr(v423 + 1, _X8) );
        }
        a1 = v427;
LABEL_72:
        v247 = a1[5];
        if ( (v247 & 1) != 0 )
        {
          a1[5] = v247 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 4);
          if ( v245 )
            goto LABEL_74;
        }
        else
        {
          raw_spin_unlock(a1 + 4);
          if ( v245 )
          {
LABEL_74:
            v426 = _ReadStatusReg(SP_EL0);
            while ( 1 )
            {
              if ( !*(_DWORD *)(v245 + 40) && v245 != -52832 )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: cleanup he operation info",
                  v248,
                  v249,
                  v250,
                  v251,
                  v252,
                  v253,
                  v254,
                  v255,
                  "hdd_cleanup_he_operation_info");
                v282 = *(_QWORD *)(v245 + 54328);
                if ( v282 )
                {
                  _qdf_mem_free(v282);
                  *(_QWORD *)(v245 + 54328) = 0;
                }
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: cleanup previous ap bcn ie",
                  v274,
                  v275,
                  v276,
                  v277,
                  v278,
                  v279,
                  v280,
                  v281,
                  "hdd_cleanup_prev_ap_bcn_ie");
                v283 = *(_QWORD *)(v245 + 53792);
                if ( v283 )
                {
                  _qdf_mem_free(v283);
                  *(_QWORD *)(v245 + 53792) = 0;
                  *(_DWORD *)(v245 + 53784) = 0;
                }
              }
              hdd_adapter_dev_put_debug(v245, 0xDu, v248, v249, v250, v251, v252, v253, v254, v255);
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (*(_DWORD *)(v426 + 16) & 0xF0000) != 0
                || (*(_DWORD *)(v426 + 16) & 0xFF00) != 0 )
              {
                a1 = v427;
                raw_spin_lock(v427 + 4);
                if ( v246 )
                  goto LABEL_82;
LABEL_75:
                v256 = 0;
                v245 = 0;
                v257 = a1[5];
                if ( (v257 & 1) == 0 )
                  goto LABEL_76;
LABEL_104:
                a1[5] = v257 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(a1 + 4);
                v246 = v256;
                if ( !v245 )
                  break;
              }
              else
              {
                a1 = v427;
                raw_spin_lock_bh(v427 + 4);
                v427[5] |= 1uLL;
                if ( !v246 )
                  goto LABEL_75;
LABEL_82:
                v430[0] = 0;
                v258 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v246 + 8), v430);
                v256 = v430[0] - 8LL;
                if ( (_DWORD)v258 )
                  v267 = 0;
                else
                  v267 = v430[0] - 8LL;
                if ( v246 == v267 )
                {
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: Validation failed",
                    v259,
                    v260,
                    v261,
                    v262,
                    v263,
                    v264,
                    v265,
                    v266,
                    "hdd_validate_next_adapter");
                  hdd_adapter_dev_put_debug(v246, 0xDu, v284, v285, v286, v287, v288, v289, v290, v291);
                  v256 = 0;
                  v245 = 0;
                }
                else
                {
                  if ( v267 )
                  {
                    v268 = *(_QWORD *)(v267 + 32);
                    if ( v268 )
                    {
                      ++*(_DWORD *)(v426 + 16);
                      v269 = *(_QWORD *)(v268 + 1320);
                      v270 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v269);
                      do
                        v271 = __ldxr(v270);
                      while ( __stxr(v271 + 1, v270) );
                      v272 = *(_QWORD *)(v426 + 16) - 1LL;
                      *(_DWORD *)(v426 + 16) = v272;
                      if ( !v272 || !*(_QWORD *)(v426 + 16) )
                        preempt_schedule_notrace(v258);
                    }
                    _X8 = (unsigned int *)(v267 + 52576);
                    __asm { PRFM            #0x11, [X8] }
                    do
                      v297 = __ldxr(_X8);
                    while ( __stxr(v297 + 1, _X8) );
                  }
                  else
                  {
                    v256 = 0;
                  }
                  v245 = v246;
                }
                a1 = v427;
                v257 = v427[5];
                if ( (v257 & 1) != 0 )
                  goto LABEL_104;
LABEL_76:
                raw_spin_unlock(a1 + 4);
                v246 = v256;
                if ( !v245 )
                  break;
              }
            }
          }
        }
        v315 = *a1;
        v428 = 0xB00000000LL;
        ucfg_dp_bbm_apply_independent_policy(v315, (__int64)&v428);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: enter",
          v316,
          v317,
          v318,
          v319,
          v320,
          v321,
          v322,
          v323,
          "hdd_deinit_adapter_ops_wq");
        _flush_workqueue(a1[855]);
        destroy_workqueue(a1[855]);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: exit",
          v324,
          v325,
          v326,
          v327,
          v328,
          v329,
          v330,
          v331,
          "hdd_deinit_adapter_ops_wq");
        hdd_deinit_qdf_ctx(v332, v333, v334, v335, v336, v337, v338, v339);
        hdd_check_for_leaks(a1, v340, v341, v342, v343, v344, v345, v346, v347);
        hdd_deinit_qdf_ctx(v348, v349, v350, v351, v352, v353, v354, v355);
        if ( curr_con_mode == 4 )
          hdd_restore_all_ps(a1);
        *((_BYTE *)a1 + 3256) = 0;
        *((_BYTE *)a1 + 6923) = 0;
        *((_DWORD *)a1 + 366) = 2;
        *((_BYTE *)a1 + 7032) = 0;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v356 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v356 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v356 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 4);
        }
        else
        {
          raw_spin_lock_bh(a1 + 4);
          a1[5] |= 1uLL;
        }
        v430[0] = 0;
        v357 = qdf_list_peek_front(a1 + 6, v430);
        if ( (_DWORD)v357 || (v398 = (_QWORD *)v430[0], v358 = v430[0] - 8LL, v430[0] == 8) )
        {
          v358 = 0;
        }
        else
        {
          v399 = *(__int64 *)((char *)&off_18 + v430[0]);
          if ( v399 )
          {
            v400 = _ReadStatusReg(SP_EL0);
            ++*(_DWORD *)(v400 + 16);
            v401 = *(_QWORD *)(v399 + 1320);
            v402 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v401);
            do
              v403 = __ldxr(v402);
            while ( __stxr(v403 + 1, v402) );
            v404 = *(_QWORD *)(v400 + 16) - 1LL;
            *(_DWORD *)(v400 + 16) = v404;
            if ( !v404 || !*(_QWORD *)(v400 + 16) )
            {
              v417 = v398;
              preempt_schedule_notrace(v357);
              v398 = v417;
              a1 = v427;
            }
          }
          _X8 = (unsigned int *)v398 + 13193;
          __asm { PRFM            #0x11, [X8] }
          do
            v421 = __ldxr(_X8);
          while ( __stxr(v421 + 1, _X8) );
          v430[0] = 0;
          v406 = qdf_list_peek_next(a1 + 6, v398, v430);
          if ( !(_DWORD)v406 )
          {
            v407 = v430[0];
            v359 = v430[0] - 8LL;
            if ( v430[0] != 8 )
            {
              v408 = *(__int64 *)((char *)&off_18 + v430[0]);
              if ( v408 )
              {
                v409 = _ReadStatusReg(SP_EL0);
                ++*(_DWORD *)(v409 + 16);
                v410 = *(_QWORD *)(v408 + 1320);
                v411 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v410);
                do
                  v412 = __ldxr(v411);
                while ( __stxr(v412 + 1, v411) );
                v413 = *(_QWORD *)(v409 + 16) - 1LL;
                *(_DWORD *)(v409 + 16) = v413;
                if ( !v413 || !*(_QWORD *)(v409 + 16) )
                  preempt_schedule_notrace(v406);
              }
              _X8 = (unsigned int *)(v407 + 52772);
              __asm { PRFM            #0x11, [X8] }
              do
                v425 = __ldxr(_X8);
              while ( __stxr(v425 + 1, _X8) );
            }
            a1 = v427;
            v360 = v427[5];
            if ( (v360 & 1) != 0 )
            {
LABEL_185:
              a1[5] = v360 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(a1 + 4);
              if ( !v358 )
                goto LABEL_186;
LABEL_138:
              v369 = _ReadStatusReg(SP_EL0);
              while ( 1 )
              {
                if ( !*(_DWORD *)(v358 + 40) )
                {
                  *(_DWORD *)(v358 + 57396) = 0;
                  *(_BYTE *)(v358 + 57400) = 0;
                  *(_DWORD *)(v358 + 57404) = 0;
                  *(_BYTE *)(v358 + 57408) = 0;
                  *(_DWORD *)(v358 + 57412) = 0;
                  *(_BYTE *)(v358 + 57416) = 0;
                  *(_DWORD *)(v358 + 57420) = 0;
                  *(_BYTE *)(v358 + 57424) = 0;
                  *(_DWORD *)(v358 + 57428) = 0;
                  *(_BYTE *)(v358 + 57432) = 0;
                }
                hdd_adapter_dev_put_debug(v358, 0x40u, v361, v362, v363, v364, v365, v366, v367, v368);
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                  || (*(_DWORD *)(v369 + 16) & 0xF0000) != 0
                  || (*(_DWORD *)(v369 + 16) & 0xFF00) != 0 )
                {
                  raw_spin_lock(a1 + 4);
                  if ( v359 )
                    goto LABEL_147;
LABEL_139:
                  v370 = 0;
                  v358 = 0;
                  v371 = a1[5];
                  if ( (v371 & 1) == 0 )
                    goto LABEL_140;
LABEL_162:
                  a1[5] = v371 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(a1 + 4);
                  v359 = v370;
                  if ( !v358 )
                    goto LABEL_186;
                }
                else
                {
                  raw_spin_lock_bh(a1 + 4);
                  a1[5] |= 1uLL;
                  if ( !v359 )
                    goto LABEL_139;
LABEL_147:
                  v430[0] = 0;
                  v372 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v359 + 8), v430);
                  v370 = v430[0] - 8LL;
                  if ( (_DWORD)v372 )
                    v381 = 0;
                  else
                    v381 = v430[0] - 8LL;
                  if ( v359 == v381 )
                  {
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: Validation failed",
                      v373,
                      v374,
                      v375,
                      v376,
                      v377,
                      v378,
                      v379,
                      v380,
                      "hdd_validate_next_adapter");
                    hdd_adapter_dev_put_debug(v359, 0x40u, v388, v389, v390, v391, v392, v393, v394, v395);
                    v370 = 0;
                    v358 = 0;
                  }
                  else
                  {
                    if ( v381 )
                    {
                      v382 = *(_QWORD *)(v381 + 32);
                      if ( v382 )
                      {
                        ++*(_DWORD *)(v369 + 16);
                        v383 = *(_QWORD *)(v382 + 1320);
                        v384 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v383);
                        do
                          v385 = __ldxr(v384);
                        while ( __stxr(v385 + 1, v384) );
                        v386 = *(_QWORD *)(v369 + 16) - 1LL;
                        *(_DWORD *)(v369 + 16) = v386;
                        if ( !v386 || !*(_QWORD *)(v369 + 16) )
                          preempt_schedule_notrace(v372);
                      }
                      _X8 = (unsigned int *)(v381 + 52780);
                      __asm { PRFM            #0x11, [X8] }
                      do
                        v397 = __ldxr(_X8);
                      while ( __stxr(v397 + 1, _X8) );
                    }
                    else
                    {
                      v370 = 0;
                    }
                    v358 = v359;
                  }
                  a1 = v427;
                  v371 = v427[5];
                  if ( (v371 & 1) != 0 )
                    goto LABEL_162;
LABEL_140:
                  raw_spin_unlock(a1 + 4);
                  v359 = v370;
                  if ( !v358 )
                    goto LABEL_186;
                }
              }
            }
LABEL_137:
            raw_spin_unlock(a1 + 4);
            if ( !v358 )
            {
LABEL_186:
              netlink_unregister_notifier(a1 + 1054);
              v74 = v208;
              v92 = "%s: Wlan transitioned (now CLOSED)";
              goto LABEL_187;
            }
            goto LABEL_138;
          }
        }
        v359 = 0;
        v360 = a1[5];
        if ( (v360 & 1) != 0 )
          goto LABEL_185;
        goto LABEL_137;
      }
    }
    v246 = 0;
    goto LABEL_72;
  }
  hdd_psoc_idle_timer_start((__int64)a1, v41, v42, v43, v44, v45, v46, v47, v48);
  cds_clear_driver_state(64, v58, v59, v60, v61, v62, v63, v64, v65);
  ucfg_dp_bus_bw_compute_timer_stop(*a1, v66, v67, v68, v69, v70, v71, v72, v73);
  v74 = -11;
LABEL_189:
  _ReadStatusReg(SP_EL0);
  return v74;
}
