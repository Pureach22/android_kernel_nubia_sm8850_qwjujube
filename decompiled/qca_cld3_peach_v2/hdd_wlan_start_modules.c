__int64 __fastcall hdd_wlan_start_modules(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *context; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  _QWORD *v29; // x20
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 result; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  int v63; // w8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  char v80; // w23
  __int64 v81; // x0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  unsigned int v98; // w0
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  unsigned int v107; // w21
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  _QWORD *v116; // x0
  unsigned int v117; // w0
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
  unsigned int v134; // w0
  __int64 v135; // x22
  __int64 v136; // x0
  unsigned int v137; // w0
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  unsigned int v146; // w21
  unsigned int v147; // w0
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  __int64 v156; // x0
  unsigned int updated; // w0
  double v158; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  unsigned int v174; // w0
  double v175; // d0
  double v176; // d1
  double v177; // d2
  double v178; // d3
  double v179; // d4
  double v180; // d5
  double v181; // d6
  double v182; // d7
  unsigned int v183; // w0
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  unsigned int v192; // w21
  double v193; // d0
  double v194; // d1
  double v195; // d2
  double v196; // d3
  double v197; // d4
  double v198; // d5
  double v199; // d6
  double v200; // d7
  double v201; // d0
  double v202; // d1
  double v203; // d2
  double v204; // d3
  double v205; // d4
  double v206; // d5
  double v207; // d6
  double v208; // d7
  _QWORD *v209; // x0
  __int64 v210; // x8
  unsigned int v211; // w0
  double v212; // d0
  double v213; // d1
  double v214; // d2
  double v215; // d3
  double v216; // d4
  double v217; // d5
  double v218; // d6
  double v219; // d7
  unsigned int v220; // w0
  double v221; // d0
  double v222; // d1
  double v223; // d2
  double v224; // d3
  double v225; // d4
  double v226; // d5
  double v227; // d6
  double v228; // d7
  unsigned int v229; // w21
  unsigned int v230; // w0
  double v231; // d0
  double v232; // d1
  double v233; // d2
  double v234; // d3
  double v235; // d4
  double v236; // d5
  double v237; // d6
  double v238; // d7
  double v239; // d0
  double v240; // d1
  double v241; // d2
  double v242; // d3
  double v243; // d4
  double v244; // d5
  double v245; // d6
  double v246; // d7
  double v247; // d0
  double v248; // d1
  double v249; // d2
  double v250; // d3
  double v251; // d4
  double v252; // d5
  double v253; // d6
  double v254; // d7
  unsigned int v255; // w0
  double v256; // d0
  double v257; // d1
  double v258; // d2
  double v259; // d3
  double v260; // d4
  double v261; // d5
  double v262; // d6
  double v263; // d7
  unsigned int v264; // w21
  __int64 v265; // x8
  __int64 v266; // x0
  double v267; // d0
  double v268; // d1
  double v269; // d2
  double v270; // d3
  double v271; // d4
  double v272; // d5
  double v273; // d6
  double v274; // d7
  __int64 v275; // x22
  unsigned int driver_state; // w0
  double v277; // d0
  double v278; // d1
  double v279; // d2
  double v280; // d3
  double v281; // d4
  double v282; // d5
  double v283; // d6
  double v284; // d7
  _QWORD *v285; // x0
  double v286; // d0
  double v287; // d1
  double v288; // d2
  double v289; // d3
  double v290; // d4
  double v291; // d5
  double v292; // d6
  double v293; // d7
  double v294; // d0
  double v295; // d1
  double v296; // d2
  double v297; // d3
  double v298; // d4
  double v299; // d5
  double v300; // d6
  double v301; // d7
  double v302; // d0
  double v303; // d1
  double v304; // d2
  double v305; // d3
  double v306; // d4
  double v307; // d5
  double v308; // d6
  double v309; // d7
  double v310; // d0
  double v311; // d1
  double v312; // d2
  double v313; // d3
  double v314; // d4
  double v315; // d5
  double v316; // d6
  double v317; // d7
  double sysfs_files; // d0
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
  __int64 v342; // x0
  unsigned int v343; // w0
  unsigned int v344; // w20
  unsigned int v345; // w0
  double v346; // d0
  double v347; // d1
  double v348; // d2
  double v349; // d3
  double v350; // d4
  double v351; // d5
  double v352; // d6
  double v353; // d7
  __int64 v354; // x0
  double v355; // d0
  double v356; // d1
  double v357; // d2
  double v358; // d3
  double v359; // d4
  double v360; // d5
  double v361; // d6
  double v362; // d7
  double v363; // d0
  double v364; // d1
  double v365; // d2
  double v366; // d3
  double v367; // d4
  double v368; // d5
  double v369; // d6
  double v370; // d7
  __int64 v371; // [xsp+0h] [xbp-80h] BYREF
  _QWORD v372[6]; // [xsp+8h] [xbp-78h] BYREF
  _QWORD v373[9]; // [xsp+38h] [xbp-48h] BYREF

  v373[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v371 = 0;
  memset(v373, 0, 64);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_wlan_start_modules");
  context = _cds_get_context(64, (__int64)"hdd_wlan_start_modules", v12, v13, v14, v15, v16, v17, v18, v19);
  if ( !context )
  {
    qdf_trace_msg(0x33u, 8u, "%s: exit", v21, v22, v23, v24, v25, v26, v27, v28, "hdd_wlan_start_modules");
    result = 4294967274LL;
    goto LABEL_76;
  }
  v29 = context;
  _qdf_delayed_work_stop_sync();
  qdf_wake_lock_release((__int64)&wlan_wake_lock, 0x15u);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Stopped psoc idle timer",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "hdd_psoc_idle_timer_stop");
  if ( *((_DWORD *)a1 + 366) != 1 )
  {
    cds_clear_driver_state(64, v38, v39, v40, v41, v42, v43, v44, v45);
    v63 = *((_DWORD *)a1 + 366);
    if ( v63 == 2 )
    {
      qdf_trace_msg(0x33u, 8u, "Wlan transitioning (CLOSED -> ENABLED)", v55, v56, v57, v58, v59, v60, v61, v62);
      if ( (a2 & 1) != 0 )
        goto LABEL_10;
      v134 = pld_power_on(v29[5]);
      if ( !v134 )
      {
        v80 = 0;
LABEL_11:
        qdf_trace_msg(0x33u, 8u, "%s: enter", v72, v73, v74, v75, v76, v77, v78, v79, "hdd_init_adapter_ops_wq");
        v81 = alloc_workqueue("hdd_adapter_ops_wq", 131090, 1);
        a1[858] = v81;
        if ( v81 )
          qdf_trace_msg(0x33u, 8u, "%s: exit", v82, v83, v84, v85, v86, v87, v88, v89, "hdd_init_adapter_ops_wq");
        v90 = pld_set_fw_log_mode(a1[12], *(unsigned __int8 *)(a1[13] + 37LL));
        v98 = hdd_hif_open(
                v29[5],
                v90,
                v91,
                v92,
                v93,
                v94,
                v95,
                v96,
                v97,
                v29[1],
                v29[75],
                *((_DWORD *)v29 + 148),
                a2 & 1);
        if ( v98 )
        {
          v107 = v98;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to open hif; errno: %d",
            v99,
            v100,
            v101,
            v102,
            v103,
            v104,
            v105,
            v106,
            "hdd_wlan_start_modules");
          goto LABEL_73;
        }
        v116 = _cds_get_context(61, (__int64)"hdd_wlan_start_modules", v99, v100, v101, v102, v103, v104, v105, v106);
        if ( !v116 )
        {
          v107 = -22;
          goto LABEL_73;
        }
        if ( curr_con_mode == 8 )
        {
          v117 = epping_open();
          if ( v117 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Failed to open in epping mode: %d",
              v118,
              v119,
              v120,
              v121,
              v122,
              v123,
              v124,
              v125,
              "hdd_wlan_start_modules",
              v117);
            v107 = -22;
LABEL_72:
            v285 = _cds_get_context(
                     61,
                     (__int64)"hdd_wlan_start_modules",
                     v126,
                     v127,
                     v128,
                     v129,
                     v130,
                     v131,
                     v132,
                     v133);
            hdd_hif_close((__int64)a1, (__int64)v285, v286, v287, v288, v289, v290, v291, v292, v293);
LABEL_73:
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: enter",
              v108,
              v109,
              v110,
              v111,
              v112,
              v113,
              v114,
              v115,
              "hdd_deinit_adapter_ops_wq");
            _flush_workqueue(a1[858]);
            destroy_workqueue(a1[858]);
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: exit",
              v294,
              v295,
              v296,
              v297,
              v298,
              v299,
              v300,
              v301,
              "hdd_deinit_adapter_ops_wq");
            if ( (v80 & 1) == 0 )
              pld_power_off(v29[5]);
            goto LABEL_75;
          }
          v147 = epping_enable(v29[5], 0);
          if ( v147 )
          {
            v156 = qdf_trace_msg(
                     0x33u,
                     2u,
                     "%s: Failed to enable in epping mode : %d",
                     v148,
                     v149,
                     v150,
                     v151,
                     v152,
                     v153,
                     v154,
                     v155,
                     "hdd_wlan_start_modules",
                     v147);
            epping_close(v156);
            v107 = 0;
            goto LABEL_72;
          }
          qdf_trace_msg(
            0x33u,
            4u,
            "%s: epping mode enabled",
            v148,
            v149,
            v150,
            v151,
            v152,
            v153,
            v154,
            v155,
            "hdd_wlan_start_modules");
LABEL_35:
          *((_DWORD *)a1 + 366) = 1;
          qdf_trace_msg(0x33u, 8u, "Wlan transitioned (now ENABLED)", v166, v167, v168, v169, v170, v171, v172, v173);
          ucfg_ipa_reg_is_driver_unloading_cb(a1[1], cds_is_driver_unloading_0);
          ucfg_ipa_reg_sap_xmit_cb(a1[1], hdd_softap_ipa_start_xmit);
          ucfg_ipa_reg_send_to_nw_cb(a1[1], hdd_ipa_send_nbuf_to_network);
          ucfg_dp_reg_ipa_rsp_ind(a1[1]);
          if ( !(unsigned int)pld_get_thermal_state(a1[12], &v371, 1) && v371 )
            hdd_send_thermal_mitigation_val(a1, v371, 1);
          if ( !(unsigned int)pld_get_thermal_state(a1[12], &v371, 2) && v371 )
            hdd_send_thermal_mitigation_val(a1, v371, 2);
          if ( !(unsigned int)pld_get_thermal_state(a1[12], &v371, 3) && v371 )
            hdd_send_ddr_bw_mitigation_level(a1, v371, 3);
          hdd_register_get_port_status_notifier(a1);
          goto LABEL_4;
        }
        v135 = (__int64)v116;
        if ( (unsigned int)pld_is_ipa_offload_disabled(v29[5]) )
          ucfg_ipa_set_pld_enable(0);
        if ( (pld_is_ipa_shared_smmu_enable(v29[5]) & 1) != 0 )
          ucfg_ipa_set_shared_smmu_enable(1);
        ucfg_ipa_component_config_update(*a1);
        hdd_update_cds_ac_specs_params(a1);
        hdd_dp_register_callbacks(a1);
        v136 = *a1;
        memset(v372, 0, sizeof(v372));
        os_if_qmi_register_callbacks(v136, v372);
        v137 = hdd_component_psoc_open(*a1);
        if ( v137 )
        {
          v146 = v137;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to Open legacy components; status: %d",
            v138,
            v139,
            v140,
            v141,
            v142,
            v143,
            v144,
            v145,
            "hdd_wlan_start_modules",
            v137);
          v107 = qdf_status_to_os_return(v146);
        }
        else
        {
          updated = hdd_update_config(a1);
          if ( updated )
          {
            v107 = updated;
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Failed to update configuration; errno: %d",
              v158,
              v159,
              v160,
              v161,
              v162,
              v163,
              v164,
              v165,
              "hdd_wlan_start_modules");
          }
          else
          {
            v174 = wbuff_module_init();
            if ( v174 )
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: WBUFF init unsuccessful; status: %d",
                v175,
                v176,
                v177,
                v178,
                v179,
                v180,
                v181,
                v182,
                "hdd_wlan_start_modules",
                v174);
            v183 = cds_open(*a1, v175, v176, v177, v178, v179, v180, v181, v182);
            if ( v183 )
            {
              v192 = v183;
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Failed to Open CDS; status: %d",
                v184,
                v185,
                v186,
                v187,
                v188,
                v189,
                v190,
                v191,
                "hdd_wlan_start_modules",
                v183);
              v107 = qdf_status_to_os_return(v192);
            }
            else
            {
              hdd_populate_feature_set_cds_config(a1);
              v201 = hdd_set_qmi_stats_enabled(a1);
              v209 = _cds_get_context(
                       52,
                       (__int64)"hdd_wlan_start_modules",
                       v201,
                       v202,
                       v203,
                       v204,
                       v205,
                       v206,
                       v207,
                       v208);
              v210 = *a1;
              a1[2] = v209;
              ucfg_dp_set_rx_thread_affinity(v210);
              v211 = hdd_update_components_config(a1);
              if ( v211 )
              {
                v107 = v211;
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failed to update component configs; errno: %d",
                  v212,
                  v213,
                  v214,
                  v215,
                  v216,
                  v217,
                  v218,
                  v219,
                  "hdd_wlan_start_modules");
              }
              else
              {
                if ( curr_con_mode == 4 )
                  hdd_override_all_ps(a1);
                v220 = cds_dp_open(*a1, v212, v213, v214, v215, v216, v217, v218, v219);
                if ( v220 )
                {
                  v229 = v220;
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: Failed to Open cds post open; status: %d",
                    v221,
                    v222,
                    v223,
                    v224,
                    v225,
                    v226,
                    v227,
                    v228,
                    "hdd_wlan_start_modules",
                    v220);
                  v107 = qdf_status_to_os_return(v229);
                }
                else
                {
                  v230 = hdd_register_cb(a1);
                  if ( v230 )
                  {
                    v107 = v230;
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: Failed to register HDD callbacks!",
                      v231,
                      v232,
                      v233,
                      v234,
                      v235,
                      v236,
                      v237,
                      v238,
                      "hdd_wlan_start_modules");
                  }
                  else
                  {
                    v107 = hdd_register_notifiers(a1);
                    if ( !v107 )
                    {
                      hdd_nan_register_callbacks(a1);
                      v247 = hdd_sr_register_callbacks(a1);
                      v255 = cds_pre_enable(v247, v248, v249, v250, v251, v252, v253, v254);
                      if ( v255 )
                      {
                        v264 = v255;
                        qdf_trace_msg(
                          0x33u,
                          2u,
                          "%s: Failed to pre-enable CDS; status: %d",
                          v256,
                          v257,
                          v258,
                          v259,
                          v260,
                          v261,
                          v262,
                          v263,
                          "hdd_wlan_start_modules",
                          v255);
                        v107 = qdf_status_to_os_return(v264);
                      }
                      else
                      {
                        hdd_register_policy_manager_callback(*a1);
                        hdd_tx_powerboost_init(a1);
                        hdd_spectral_register_to_dbr(a1);
                        *((_BYTE *)a1 + 7115) = *(_BYTE *)(cfg_psoc_get_values(*a1) + 4008);
                        sysfs_files = hdd_create_sysfs_files(a1);
                        hdd_update_hw_sw_info(a1, sysfs_files, v319, v320, v321, v322, v323, v324, v325);
                        if ( curr_con_mode == 5 )
                        {
                          hdd_enable_power_management(a1);
                          qdf_trace_msg(
                            0x33u,
                            2u,
                            "%s: in ftm mode, no need to configure cds modules",
                            v326,
                            v327,
                            v328,
                            v329,
                            v330,
                            v331,
                            v332,
                            v333,
                            "hdd_wlan_start_modules");
                          qdf_trace_msg(
                            0x33u,
                            4u,
                            "%s: Enable FW log in ftm mode",
                            v334,
                            v335,
                            v336,
                            v337,
                            v338,
                            v339,
                            v340,
                            v341,
                            "hdd_wlan_start_modules");
                          hdd_set_fw_log_params(a1, 0);
                          v342 = hdd_set_pcie_params(a1, 0, v373);
                          if ( !(_DWORD)v342 )
                          {
                            v343 = sme_send_multi_pdev_vdev_set_params(v342, 0, v373, 1);
                            if ( v343 )
                            {
                              v344 = v343;
                              qdf_trace_msg(
                                0x33u,
                                2u,
                                "%s: failed to send pdev set params",
                                v166,
                                v167,
                                v168,
                                v169,
                                v170,
                                v171,
                                v172,
                                v173,
                                "hdd_wlan_start_modules");
                              result = v344;
                              goto LABEL_76;
                            }
                          }
                          goto LABEL_35;
                        }
                        v345 = hdd_configure_cds(a1);
                        if ( v345 )
                        {
                          v107 = v345;
                          qdf_trace_msg(
                            0x33u,
                            2u,
                            "%s: Failed to Enable cds modules; errno: %d",
                            v346,
                            v347,
                            v348,
                            v349,
                            v350,
                            v351,
                            v352,
                            v353,
                            "hdd_wlan_start_modules",
                            v345);
                        }
                        else
                        {
                          if ( curr_con_mode || !(unsigned int)ucfg_dp_direct_link_init(*a1) )
                          {
                            hdd_enable_power_management(a1);
                            hdd_set_hif_init_phase(v135, 0);
                            goto LABEL_35;
                          }
                          qdf_trace_msg(
                            0x38u,
                            2u,
                            "%s: Failed to initialize Direct Link datapath",
                            v363,
                            v364,
                            v365,
                            v366,
                            v367,
                            v368,
                            v369,
                            v370,
                            "hdd_wlan_start_modules");
                          hdd_deconfigure_cds(a1);
                          v107 = -22;
                        }
                        v354 = dispatcher_disable();
                        hdd_destroy_sysfs_files(v354);
                        v355 = hdd_tx_powerboost_deinit(a1);
                        cds_post_disable(v355, v356, v357, v358, v359, v360, v361, v362);
                      }
                      hdd_unregister_notifiers(a1);
                    }
                    hdd_deregister_cb(a1);
                  }
                  if ( *a1 )
                  {
                    v265 = *(_QWORD *)(*a1 + 2800LL);
                    if ( v265 )
                    {
                      if ( *(_BYTE *)(v265 + 485) == 1 )
                        hdd_runtime_suspend_context_deinit(a1);
                    }
                  }
                  v266 = a1[1];
                  if ( v266 )
                  {
                    dispatcher_pdev_close(v266);
                    hdd_objmgr_release_and_destroy_pdev(a1);
                  }
                  cds_dp_close(*a1, v239, v240, v241, v242, v243, v244, v245, v246);
                }
              }
              dispatcher_disable();
              *((_DWORD *)a1 + 366) = 2;
              qdf_trace_msg(
                0x33u,
                4u,
                "%s: Wlan transition aborted (now CLOSED)",
                v267,
                v268,
                v269,
                v270,
                v271,
                v272,
                v273,
                v274,
                "hdd_wlan_start_modules");
              cds_close(*a1);
            }
            v275 = *a1;
            driver_state = cds_get_driver_state(v193, v194, v195, v196, v197, v198, v199, v200);
            hdd_component_psoc_close(v275, (driver_state >> 3) & 1);
            wlan_global_lmac_if_close(*a1);
            cds_deinit_ini_config(v277, v278, v279, v280, v281, v282, v283, v284);
          }
        }
        v126 = ucfg_ipa_component_config_free();
        goto LABEL_72;
      }
      v107 = v134;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to power up device; errno:%d",
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        "hdd_wlan_start_modules");
    }
    else
    {
      if ( !v63 )
      {
        qdf_trace_msg(0x33u, 8u, "Wlan transitioning (UNINITIALIZED -> CLOSED)", v55, v56, v57, v58, v59, v60, v61, v62);
        qdf_trace_msg(0x33u, 8u, "Wlan transitioning (CLOSED -> ENABLED)", v64, v65, v66, v67, v68, v69, v70, v71);
LABEL_10:
        v80 = 1;
        goto LABEL_11;
      }
      v107 = -22;
    }
LABEL_75:
    cds_shutdown_notifier_purge();
    v302 = hdd_check_for_leaks(a1);
    cds_set_driver_state(64, v302, v303, v304, v305, v306, v307, v308, v309);
    qdf_trace_msg(0x33u, 8u, "%s: exit", v310, v311, v312, v313, v314, v315, v316, v317, "hdd_wlan_start_modules");
    result = v107;
    goto LABEL_76;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Driver modules already Enabled",
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    "hdd_wlan_start_modules");
LABEL_4:
  qdf_trace_msg(0x33u, 8u, "%s: exit", v46, v47, v48, v49, v50, v51, v52, v53, "hdd_wlan_start_modules");
  result = 0;
LABEL_76:
  _ReadStatusReg(SP_EL0);
  return result;
}
