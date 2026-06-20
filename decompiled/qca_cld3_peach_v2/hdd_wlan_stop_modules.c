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
  __int64 v274; // x21
  __int64 v275; // x19
  double v276; // d0
  double v277; // d1
  double v278; // d2
  double v279; // d3
  double v280; // d4
  double v281; // d5
  double v282; // d6
  double v283; // d7
  __int64 v284; // x0
  __int64 v285; // x0
  double v286; // d0
  double v287; // d1
  double v288; // d2
  double v289; // d3
  double v290; // d4
  double v291; // d5
  double v292; // d6
  double v293; // d7
  unsigned int v299; // w9
  _QWORD *v300; // x1
  __int64 v301; // x9
  unsigned __int64 v302; // x8
  __int64 v303; // x9
  unsigned int *v304; // x9
  unsigned int v305; // w12
  __int64 v306; // x9
  __int64 v308; // x0
  __int64 v309; // x19
  __int64 v310; // x9
  unsigned __int64 v311; // x8
  __int64 v312; // x9
  unsigned int *v313; // x9
  unsigned int v314; // w12
  __int64 v315; // x9
  __int64 v317; // x0
  double v318; // d0
  double v319; // d1
  double v320; // d2
  double v321; // d3
  double v322; // d4
  double v323; // d5
  double v324; // d6
  double v325; // d7
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
  double v342; // d0
  double v343; // d1
  double v344; // d2
  double v345; // d3
  double v346; // d4
  double v347; // d5
  double v348; // d6
  double v349; // d7
  double v350; // d0
  double v351; // d1
  double v352; // d2
  double v353; // d3
  double v354; // d4
  double v355; // d5
  double v356; // d6
  double v357; // d7
  unsigned __int64 v358; // x8
  __int64 v359; // x0
  __int64 v360; // x22
  __int64 v361; // x21
  __int64 v362; // x8
  double v363; // d0
  double v364; // d1
  double v365; // d2
  double v366; // d3
  double v367; // d4
  double v368; // d5
  double v369; // d6
  double v370; // d7
  unsigned __int64 v371; // x20
  __int64 v372; // x27
  __int64 v373; // x8
  __int64 v374; // x0
  double v375; // d0
  double v376; // d1
  double v377; // d2
  double v378; // d3
  double v379; // d4
  double v380; // d5
  double v381; // d6
  double v382; // d7
  __int64 v383; // x19
  __int64 v384; // x8
  __int64 v385; // x8
  unsigned int *v386; // x8
  unsigned int v387; // w10
  __int64 v388; // x8
  double v390; // d0
  double v391; // d1
  double v392; // d2
  double v393; // d3
  double v394; // d4
  double v395; // d5
  double v396; // d6
  double v397; // d7
  unsigned int v399; // w9
  _QWORD *v400; // x1
  __int64 v401; // x9
  unsigned __int64 v402; // x8
  __int64 v403; // x9
  unsigned int *v404; // x9
  unsigned int v405; // w12
  __int64 v406; // x9
  __int64 v408; // x0
  __int64 v409; // x19
  __int64 v410; // x9
  unsigned __int64 v411; // x8
  __int64 v412; // x9
  unsigned int *v413; // x9
  unsigned int v414; // w12
  __int64 v415; // x9
  _QWORD *v418; // x19
  _QWORD *v419; // x19
  unsigned int v421; // w9
  unsigned int v423; // w9
  unsigned int v425; // w9
  unsigned int v427; // w9
  unsigned __int64 v428; // [xsp+10h] [xbp-30h]
  _QWORD *v429; // [xsp+18h] [xbp-28h]
  __int64 v430; // [xsp+20h] [xbp-20h] BYREF
  int v431; // [xsp+28h] [xbp-18h]
  _QWORD v432[2]; // [xsp+30h] [xbp-10h] BYREF

  v432[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  driver_state = cds_get_driver_state(a3, a4, a5, a6, a7, a8, a9, a10);
  v431 = 0;
  v430 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", v13, v14, v15, v16, v17, v18, v19, v20, "hdd_wlan_stop_modules");
  context = _cds_get_context(64, (__int64)"hdd_wlan_stop_modules", v21, v22, v23, v24, v25, v26, v27, v28);
  if ( !context )
  {
    v74 = -22;
    goto LABEL_190;
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
      goto LABEL_188;
    }
    if ( v74 != 1 )
    {
      if ( v74 != 2 )
      {
        v74 = -22;
LABEL_189:
        qdf_trace_msg(0x33u, 8u, "%s: exit", v84, v85, v86, v87, v88, v89, v90, v91, "hdd_wlan_stop_modules");
        goto LABEL_190;
      }
      v74 = 0;
      v92 = "%s: Modules already closed";
LABEL_188:
      qdf_trace_msg(0x33u, 8u, v92, v84, v85, v86, v87, v88, v89, v90, v91, "hdd_wlan_stop_modules");
      goto LABEL_189;
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
    v432[0] = 0;
    v244 = qdf_list_peek_front(a1 + 6, v432);
    v429 = a1;
    if ( (_DWORD)v244 || (v300 = (_QWORD *)v432[0], v245 = v432[0] - 8LL, v432[0] == 8) )
    {
      v245 = 0;
    }
    else
    {
      v301 = *(__int64 *)((char *)&off_18 + v432[0]);
      if ( v301 )
      {
        v302 = _ReadStatusReg(SP_EL0);
        ++*(_DWORD *)(v302 + 16);
        v303 = *(_QWORD *)(v301 + 1320);
        v304 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v303);
        do
          v305 = __ldxr(v304);
        while ( __stxr(v305 + 1, v304) );
        v306 = *(_QWORD *)(v302 + 16) - 1LL;
        *(_DWORD *)(v302 + 16) = v306;
        if ( !v306 || !*(_QWORD *)(v302 + 16) )
        {
          v418 = v300;
          preempt_schedule_notrace(v244);
          v300 = v418;
          a1 = v429;
        }
      }
      _X8 = (unsigned int *)(v300 + 6571);
      __asm { PRFM            #0x11, [X8] }
      do
        v421 = __ldxr(_X8);
      while ( __stxr(v421 + 1, _X8) );
      v432[0] = 0;
      v308 = qdf_list_peek_next(a1 + 6, v300, v432);
      if ( !(_DWORD)v308 )
      {
        v309 = v432[0];
        v246 = v432[0] - 8LL;
        if ( v432[0] != 8 )
        {
          v310 = *(__int64 *)((char *)&off_18 + v432[0]);
          if ( v310 )
          {
            v311 = _ReadStatusReg(SP_EL0);
            ++*(_DWORD *)(v311 + 16);
            v312 = *(_QWORD *)(v310 + 1320);
            v313 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v312);
            do
              v314 = __ldxr(v313);
            while ( __stxr(v314 + 1, v313) );
            v315 = *(_QWORD *)(v311 + 16) - 1LL;
            *(_DWORD *)(v311 + 16) = v315;
            if ( !v315 || !*(_QWORD *)(v311 + 16) )
              preempt_schedule_notrace(v308);
          }
          _X8 = (unsigned int *)(v309 + 52568);
          __asm { PRFM            #0x11, [X8] }
          do
            v425 = __ldxr(_X8);
          while ( __stxr(v425 + 1, _X8) );
        }
        a1 = v429;
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
            v428 = _ReadStatusReg(SP_EL0);
            while ( 1 )
            {
              if ( !*(_DWORD *)(v245 + 40) )
              {
                v274 = v245 + 52840;
                if ( v245 != -52840 )
                {
                  v275 = 0;
                  do
                  {
                    if ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v275 >> 3)) > 2 )
                      break;
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
                    v284 = *(_QWORD *)(v274 + 1520);
                    if ( v284 )
                    {
                      _qdf_mem_free(v284);
                      *(_QWORD *)(v274 + 1520) = 0;
                    }
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: cleanup previous ap bcn ie",
                      v276,
                      v277,
                      v278,
                      v279,
                      v280,
                      v281,
                      v282,
                      v283,
                      "hdd_cleanup_prev_ap_bcn_ie");
                    v285 = *(_QWORD *)(v274 + 968);
                    if ( v285 )
                    {
                      _qdf_mem_free(v285);
                      *(_QWORD *)(v274 + 968) = 0;
                      *(_DWORD *)(v274 + 960) = 0;
                    }
                    v274 += 6088;
                    v275 += 6088;
                  }
                  while ( v274 );
                }
              }
              hdd_adapter_dev_put_debug(v245, 0xDu, v248, v249, v250, v251, v252, v253, v254, v255);
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (*(_DWORD *)(v428 + 16) & 0xF0000) != 0
                || (*(_DWORD *)(v428 + 16) & 0xFF00) != 0 )
              {
                a1 = v429;
                raw_spin_lock(v429 + 4);
                if ( v246 )
                  goto LABEL_82;
LABEL_75:
                v256 = 0;
                v245 = 0;
                v257 = a1[5];
                if ( (v257 & 1) == 0 )
                  goto LABEL_76;
LABEL_105:
                a1[5] = v257 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(a1 + 4);
                v246 = v256;
                if ( !v245 )
                  break;
              }
              else
              {
                a1 = v429;
                raw_spin_lock_bh(v429 + 4);
                v429[5] |= 1uLL;
                if ( !v246 )
                  goto LABEL_75;
LABEL_82:
                v432[0] = 0;
                v258 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v246 + 8), v432);
                v256 = v432[0] - 8LL;
                if ( (_DWORD)v258 )
                  v267 = 0;
                else
                  v267 = v432[0] - 8LL;
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
                  hdd_adapter_dev_put_debug(v246, 0xDu, v286, v287, v288, v289, v290, v291, v292, v293);
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
                      ++*(_DWORD *)(v428 + 16);
                      v269 = *(_QWORD *)(v268 + 1320);
                      v270 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v269);
                      do
                        v271 = __ldxr(v270);
                      while ( __stxr(v271 + 1, v270) );
                      v272 = *(_QWORD *)(v428 + 16) - 1LL;
                      *(_DWORD *)(v428 + 16) = v272;
                      if ( !v272 || !*(_QWORD *)(v428 + 16) )
                        preempt_schedule_notrace(v258);
                    }
                    _X8 = (unsigned int *)(v267 + 52576);
                    __asm { PRFM            #0x11, [X8] }
                    do
                      v299 = __ldxr(_X8);
                    while ( __stxr(v299 + 1, _X8) );
                  }
                  else
                  {
                    v256 = 0;
                  }
                  v245 = v246;
                }
                a1 = v429;
                v257 = v429[5];
                if ( (v257 & 1) != 0 )
                  goto LABEL_105;
LABEL_76:
                raw_spin_unlock(a1 + 4);
                v246 = v256;
                if ( !v245 )
                  break;
              }
            }
          }
        }
        v317 = *a1;
        v430 = 0xB00000000LL;
        ucfg_dp_bbm_apply_independent_policy(v317, (__int64)&v430);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: enter",
          v318,
          v319,
          v320,
          v321,
          v322,
          v323,
          v324,
          v325,
          "hdd_deinit_adapter_ops_wq");
        _flush_workqueue(a1[858]);
        destroy_workqueue(a1[858]);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: exit",
          v326,
          v327,
          v328,
          v329,
          v330,
          v331,
          v332,
          v333,
          "hdd_deinit_adapter_ops_wq");
        hdd_deinit_qdf_ctx(v334, v335, v336, v337, v338, v339, v340, v341);
        hdd_check_for_leaks(a1, v342, v343, v344, v345, v346, v347, v348, v349);
        hdd_deinit_qdf_ctx(v350, v351, v352, v353, v354, v355, v356, v357);
        if ( curr_con_mode == 4 )
          hdd_restore_all_ps(a1);
        *((_BYTE *)a1 + 3256) = 0;
        *((_BYTE *)a1 + 6947) = 0;
        *((_DWORD *)a1 + 366) = 2;
        *((_BYTE *)a1 + 7056) = 0;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v358 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v358 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v358 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 4);
        }
        else
        {
          raw_spin_lock_bh(a1 + 4);
          a1[5] |= 1uLL;
        }
        v432[0] = 0;
        v359 = qdf_list_peek_front(a1 + 6, v432);
        if ( (_DWORD)v359 || (v400 = (_QWORD *)v432[0], v360 = v432[0] - 8LL, v432[0] == 8) )
        {
          v360 = 0;
        }
        else
        {
          v401 = *(__int64 *)((char *)&off_18 + v432[0]);
          if ( v401 )
          {
            v402 = _ReadStatusReg(SP_EL0);
            ++*(_DWORD *)(v402 + 16);
            v403 = *(_QWORD *)(v401 + 1320);
            v404 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v403);
            do
              v405 = __ldxr(v404);
            while ( __stxr(v405 + 1, v404) );
            v406 = *(_QWORD *)(v402 + 16) - 1LL;
            *(_DWORD *)(v402 + 16) = v406;
            if ( !v406 || !*(_QWORD *)(v402 + 16) )
            {
              v419 = v400;
              preempt_schedule_notrace(v359);
              v400 = v419;
              a1 = v429;
            }
          }
          _X8 = (unsigned int *)v400 + 13193;
          __asm { PRFM            #0x11, [X8] }
          do
            v423 = __ldxr(_X8);
          while ( __stxr(v423 + 1, _X8) );
          v432[0] = 0;
          v408 = qdf_list_peek_next(a1 + 6, v400, v432);
          if ( !(_DWORD)v408 )
          {
            v409 = v432[0];
            v361 = v432[0] - 8LL;
            if ( v432[0] != 8 )
            {
              v410 = *(__int64 *)((char *)&off_18 + v432[0]);
              if ( v410 )
              {
                v411 = _ReadStatusReg(SP_EL0);
                ++*(_DWORD *)(v411 + 16);
                v412 = *(_QWORD *)(v410 + 1320);
                v413 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v412);
                do
                  v414 = __ldxr(v413);
                while ( __stxr(v414 + 1, v413) );
                v415 = *(_QWORD *)(v411 + 16) - 1LL;
                *(_DWORD *)(v411 + 16) = v415;
                if ( !v415 || !*(_QWORD *)(v411 + 16) )
                  preempt_schedule_notrace(v408);
              }
              _X8 = (unsigned int *)(v409 + 52772);
              __asm { PRFM            #0x11, [X8] }
              do
                v427 = __ldxr(_X8);
              while ( __stxr(v427 + 1, _X8) );
            }
            a1 = v429;
            v362 = v429[5];
            if ( (v362 & 1) != 0 )
            {
LABEL_186:
              a1[5] = v362 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(a1 + 4);
              if ( !v360 )
                goto LABEL_187;
LABEL_139:
              v371 = _ReadStatusReg(SP_EL0);
              while ( 1 )
              {
                if ( !*(_DWORD *)(v360 + 40) )
                {
                  *(_DWORD *)(v360 + 71148) = 0;
                  *(_BYTE *)(v360 + 71152) = 0;
                  *(_DWORD *)(v360 + 71156) = 0;
                  *(_BYTE *)(v360 + 71160) = 0;
                  *(_DWORD *)(v360 + 71164) = 0;
                  *(_BYTE *)(v360 + 71168) = 0;
                  *(_DWORD *)(v360 + 71172) = 0;
                  *(_BYTE *)(v360 + 71176) = 0;
                  *(_DWORD *)(v360 + 71180) = 0;
                  *(_BYTE *)(v360 + 71184) = 0;
                }
                hdd_adapter_dev_put_debug(v360, 0x40u, v363, v364, v365, v366, v367, v368, v369, v370);
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                  || (*(_DWORD *)(v371 + 16) & 0xF0000) != 0
                  || (*(_DWORD *)(v371 + 16) & 0xFF00) != 0 )
                {
                  raw_spin_lock(a1 + 4);
                  if ( v361 )
                    goto LABEL_148;
LABEL_140:
                  v372 = 0;
                  v360 = 0;
                  v373 = a1[5];
                  if ( (v373 & 1) == 0 )
                    goto LABEL_141;
LABEL_163:
                  a1[5] = v373 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(a1 + 4);
                  v361 = v372;
                  if ( !v360 )
                    goto LABEL_187;
                }
                else
                {
                  raw_spin_lock_bh(a1 + 4);
                  a1[5] |= 1uLL;
                  if ( !v361 )
                    goto LABEL_140;
LABEL_148:
                  v432[0] = 0;
                  v374 = qdf_list_peek_next(a1 + 6, (_QWORD *)(v361 + 8), v432);
                  v372 = v432[0] - 8LL;
                  if ( (_DWORD)v374 )
                    v383 = 0;
                  else
                    v383 = v432[0] - 8LL;
                  if ( v361 == v383 )
                  {
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: Validation failed",
                      v375,
                      v376,
                      v377,
                      v378,
                      v379,
                      v380,
                      v381,
                      v382,
                      "hdd_validate_next_adapter");
                    hdd_adapter_dev_put_debug(v361, 0x40u, v390, v391, v392, v393, v394, v395, v396, v397);
                    v372 = 0;
                    v360 = 0;
                  }
                  else
                  {
                    if ( v383 )
                    {
                      v384 = *(_QWORD *)(v383 + 32);
                      if ( v384 )
                      {
                        ++*(_DWORD *)(v371 + 16);
                        v385 = *(_QWORD *)(v384 + 1320);
                        v386 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v385);
                        do
                          v387 = __ldxr(v386);
                        while ( __stxr(v387 + 1, v386) );
                        v388 = *(_QWORD *)(v371 + 16) - 1LL;
                        *(_DWORD *)(v371 + 16) = v388;
                        if ( !v388 || !*(_QWORD *)(v371 + 16) )
                          preempt_schedule_notrace(v374);
                      }
                      _X8 = (unsigned int *)(v383 + 52780);
                      __asm { PRFM            #0x11, [X8] }
                      do
                        v399 = __ldxr(_X8);
                      while ( __stxr(v399 + 1, _X8) );
                    }
                    else
                    {
                      v372 = 0;
                    }
                    v360 = v361;
                  }
                  a1 = v429;
                  v373 = v429[5];
                  if ( (v373 & 1) != 0 )
                    goto LABEL_163;
LABEL_141:
                  raw_spin_unlock(a1 + 4);
                  v361 = v372;
                  if ( !v360 )
                    goto LABEL_187;
                }
              }
            }
LABEL_138:
            raw_spin_unlock(a1 + 4);
            if ( !v360 )
            {
LABEL_187:
              netlink_unregister_notifier(a1 + 1058);
              v74 = v208;
              v92 = "%s: Wlan transitioned (now CLOSED)";
              goto LABEL_188;
            }
            goto LABEL_139;
          }
        }
        v361 = 0;
        v362 = a1[5];
        if ( (v362 & 1) != 0 )
          goto LABEL_186;
        goto LABEL_138;
      }
    }
    v246 = 0;
    goto LABEL_72;
  }
  hdd_psoc_idle_timer_start((__int64)a1, v41, v42, v43, v44, v45, v46, v47, v48);
  cds_clear_driver_state(64, v58, v59, v60, v61, v62, v63, v64, v65);
  ucfg_dp_bus_bw_compute_timer_stop(*a1, v66, v67, v68, v69, v70, v71, v72, v73);
  v74 = -11;
LABEL_190:
  _ReadStatusReg(SP_EL0);
  return v74;
}
