__int64 __fastcall wma_open(__int64 a1, __int64 a2, unsigned __int16 *a3, int a4)
{
  int conparam; // w25
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x3
  __int64 global_context; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x27
  _QWORD *context; // x26
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  _QWORD *v40; // x0
  _QWORD *v41; // x28
  unsigned int v42; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w19
  __int64 result; // x0
  const char *v53; // x2
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned int inited; // w23
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  unsigned int ref; // w0
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // x0
  __int64 *v105; // x23
  __int64 v106; // x21
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  __int64 v131; // x23
  __int64 v132; // x9
  _QWORD *v133; // x8
  char v134; // w21
  __int64 v135; // x24
  _QWORD *v136; // x9
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  unsigned __int8 v153; // w0
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
  const char *v170; // x2
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
  _QWORD *v187; // x9
  __int16 v188; // w10
  __int64 v189; // x0
  char v190; // w9
  __int64 v191; // x0
  int active_uc_apf_mode; // w0
  __int64 v193; // x8
  int active_mc_bc_apf_mode; // w0
  _QWORD *v195; // x8
  unsigned int v196; // w9
  __int64 v197; // x0
  double v198; // d0
  double v199; // d1
  double v200; // d2
  double v201; // d3
  double v202; // d4
  double v203; // d5
  double v204; // d6
  double v205; // d7
  _QWORD *v206; // x8
  __int64 v207; // x21
  unsigned __int64 v208; // x9
  __int64 v209; // x10
  double v210; // d0
  double v211; // d1
  double v212; // d2
  double v213; // d3
  double v214; // d4
  double v215; // d5
  double v216; // d6
  double v217; // d7
  _QWORD *v218; // x3
  unsigned int v219; // w0
  double v220; // d0
  double v221; // d1
  double v222; // d2
  double v223; // d3
  double v224; // d4
  double v225; // d5
  double v226; // d6
  double v227; // d7
  const char *v228; // x2
  unsigned int v229; // w0
  unsigned int v230; // w0
  unsigned int v231; // w0
  double v232; // d0
  double v233; // d1
  double v234; // d2
  double v235; // d3
  double v236; // d4
  double v237; // d5
  double v238; // d6
  double v239; // d7
  double v240; // d0
  double v241; // d1
  double v242; // d2
  double v243; // d3
  double v244; // d4
  double v245; // d5
  double v246; // d6
  double v247; // d7
  _QWORD *v248; // x8
  __int64 v249; // x19
  unsigned __int64 v250; // x21
  unsigned int v251; // w0
  double v252; // d0
  double v253; // d1
  double v254; // d2
  double v255; // d3
  double v256; // d4
  double v257; // d5
  double v258; // d6
  double v259; // d7
  unsigned int v260; // w0
  unsigned int v261; // w0
  unsigned int v262; // w0
  _QWORD *v263; // x8
  __int64 v264; // x9
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
  double v281; // d0
  double v282; // d1
  double v283; // d2
  double v284; // d3
  double v285; // d4
  double v286; // d5
  double v287; // d6
  double v288; // d7
  double v289; // d0
  double v290; // d1
  double v291; // d2
  double v292; // d3
  double v293; // d4
  double v294; // d5
  double v295; // d6
  double v296; // d7
  double v297; // d0
  double v298; // d1
  double v299; // d2
  double v300; // d3
  double v301; // d4
  double v302; // d5
  double v303; // d6
  double v304; // d7
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
  double v321; // d0
  double v322; // d1
  double v323; // d2
  double v324; // d3
  double v325; // d4
  double v326; // d5
  double v327; // d6
  double v328; // d7
  double v329; // d0
  double v330; // d1
  double v331; // d2
  double v332; // d3
  double v333; // d4
  double v334; // d5
  double v335; // d6
  double v336; // d7
  double v337; // d0
  double v338; // d1
  double v339; // d2
  double v340; // d3
  double v341; // d4
  double v342; // d5
  double v343; // d6
  double v344; // d7
  _QWORD *v345; // x9
  __int64 v346; // x0
  char sta_mod_dtim; // w0
  __int64 v348; // x8
  char sta_teles_dtim; // w0
  __int64 v350; // x8
  char sta_min_teles_dtim; // w0
  __int64 v352; // x8
  double sta_dynamic_dtim; // d0
  _QWORD *v354; // x8
  char v355; // w0
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
  double v371; // d0
  double v372; // d1
  double v373; // d2
  double v374; // d3
  double v375; // d4
  double v376; // d5
  double v377; // d6
  double v378; // d7
  double v379; // d0
  double v380; // d1
  double v381; // d2
  double v382; // d3
  double v383; // d4
  double v384; // d5
  double v385; // d6
  double v386; // d7
  double v387; // d0
  double v388; // d1
  double v389; // d2
  double v390; // d3
  double v391; // d4
  double v392; // d5
  double v393; // d6
  double v394; // d7
  double v395; // d0
  double v396; // d1
  double v397; // d2
  double v398; // d3
  double v399; // d4
  double v400; // d5
  double v401; // d6
  double v402; // d7
  double v403; // d0
  double v404; // d1
  double v405; // d2
  double v406; // d3
  double v407; // d4
  double v408; // d5
  double v409; // d6
  double v410; // d7
  double v411; // d0
  double v412; // d1
  double v413; // d2
  double v414; // d3
  double v415; // d4
  double v416; // d5
  double v417; // d6
  double v418; // d7
  double v419; // d0
  double v420; // d1
  double v421; // d2
  double v422; // d3
  double v423; // d4
  double v424; // d5
  double v425; // d6
  double v426; // d7
  __int64 v427; // x0
  double v428; // d0
  double v429; // d1
  double v430; // d2
  double v431; // d3
  double v432; // d4
  double v433; // d5
  double v434; // d6
  double v435; // d7
  double v436; // d0
  double v437; // d1
  double v438; // d2
  double v439; // d3
  double v440; // d4
  double v441; // d5
  double v442; // d6
  double v443; // d7
  double v444; // d0
  double v445; // d1
  double v446; // d2
  double v447; // d3
  double v448; // d4
  double v449; // d5
  double v450; // d6
  double v451; // d7
  double v452; // d0
  double v453; // d1
  double v454; // d2
  double v455; // d3
  double v456; // d4
  double v457; // d5
  double v458; // d6
  double v459; // d7
  double v460; // d0
  double v461; // d1
  double v462; // d2
  double v463; // d3
  double v464; // d4
  double v465; // d5
  double v466; // d6
  double v467; // d7
  double v468; // d0
  double v469; // d1
  double v470; // d2
  double v471; // d3
  double v472; // d4
  double v473; // d5
  double v474; // d6
  double v475; // d7
  int v476; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v477[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v478[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v479; // [xsp+18h] [xbp-8h]

  v479 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)v478 = 0;
  v477[0] = 0;
  v476 = 0;
  conparam = cds_get_conparam();
  v17 = qdf_trace_msg(0x36u, 8u, "%s: Enter", v9, v10, v11, v12, v13, v14, v15, v16, "wma_open");
  global_context = cds_get_global_context(v17, v18, v19, v20);
  if ( !global_context )
  {
    v53 = "%s: Invalid CDS context";
LABEL_7:
    qdf_trace_msg(0x36u, 2u, v53, v22, v23, v24, v25, v26, v27, v28, v29, "wma_open");
    result = 4;
    goto LABEL_8;
  }
  v30 = global_context;
  g_wmi_version_info = 1;
  dword_85AA5C = 1632;
  context = _cds_get_context(64, (__int64)"wma_open", v22, v23, v24, v25, v26, v27, v28, v29);
  v40 = _cds_get_context(62, (__int64)"wma_open", v32, v33, v34, v35, v36, v37, v38, v39);
  if ( !v40 )
  {
    v53 = "%s: Invalid HTC handle";
    goto LABEL_7;
  }
  v41 = v40;
  v42 = cds_alloc_context(0x36u, (__int64 *)v478, 0x1458u, v22, v23, v24, v25, v26, v27, v28, v29);
  if ( v42 )
  {
    v51 = v42;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Memory allocation failed for wma_handle",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "wma_open");
    result = v51;
    goto LABEL_8;
  }
  qdf_mem_set(*(void **)v478, 0x1458u, 0);
  if ( (unsigned int)target_if_alloc_psoc_tgt_info(a1, v54, v55, v56, v57, v58, v59, v60, v61) )
  {
    inited = 2;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: target psoc info allocation failed",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "wma_open");
LABEL_34:
    cds_free_context(54, *(__int64 *)v478, v71, v72, v73, v74, v75, v76, v77, v78);
    qdf_trace_msg(0x36u, 8u, "%s: Exit", v171, v172, v173, v174, v175, v176, v177, v178, "wma_open");
    result = inited;
    goto LABEL_8;
  }
  if ( conparam != 5 )
  {
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v478 + 696LL), (__int64)"wlan_wow_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v478 + 896LL), (__int64)"wlan_auth_req_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v478 + 1096LL), (__int64)"wlan_assoc_req_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v478 + 1296LL), (__int64)"wlan_deauth_rec_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v478 + 1496LL), (__int64)"wlan_disassoc_rec_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v478 + 1696LL), (__int64)"wlan_ap_assoc_lost_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v478 + 1896LL), (__int64)"wlan_auto_shutdown_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v478 + 2096LL), (__int64)"wlan_roam_ho_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v478 + 2296LL), (__int64)"wlan_roam_preauth_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v478 + 2496LL), (__int64)"wlan_probe_req_wps_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v478 + 3968LL), (__int64)"wlan_sap_d3_wow_wake_lock");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v478 + 4168LL), (__int64)"wlan_go_d3_wow_wake_lock");
  }
  ref = wlan_objmgr_psoc_try_get_ref(a1, 8u, v62, v63, v64, v65, v66, v67, v68, v69);
  if ( ref )
  {
    inited = ref;
    qdf_trace_msg(0x36u, 2u, "%s: PSOC get_ref fails", v80, v81, v82, v83, v84, v85, v86, v87, "wma_open");
    goto LABEL_32;
  }
  *(_QWORD *)(*(_QWORD *)v478 + 24LL) = a1;
  if ( (wlan_pmo_no_op_on_page_fault(a1) & 1) == 0 )
  {
    inited = wma_init_pagefault_wakeup_history(*(_QWORD *)v478);
    if ( inited )
    {
LABEL_31:
      wlan_objmgr_psoc_release_ref(a1, 8u, v96, v97, v98, v99, v100, v101, v102, v103);
LABEL_32:
      target_if_free_psoc_tgt_info(a1, v88, v89, v90, v91, v92, v93, v94, v95);
      if ( (unsigned int)cds_get_conparam() != 5 )
      {
        _qdf_wake_lock_destroy(*(_QWORD *)v478 + 4168LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v478 + 3968LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v478 + 696LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v478 + 896LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v478 + 1096LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v478 + 1296LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v478 + 1496LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v478 + 1696LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v478 + 1896LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v478 + 2096LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v478 + 2296LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v478 + 2496LL);
      }
      goto LABEL_34;
    }
  }
  wma_target_if_open(*(_QWORD *)v478);
  v104 = _qdf_mem_malloc(0x20u, "wma_open", 3750);
  if ( !v104 )
  {
    inited = 2;
    goto LABEL_31;
  }
  *(_QWORD *)v104 = 0;
  v105 = (__int64 *)v104;
  *(_DWORD *)(v104 + 8) = 0;
  *(_BYTE *)(v104 + 12) = 0;
  *(_QWORD *)(v104 + 16) = a1;
  *(_WORD *)(v104 + 24) = 1024;
  wmi_tlv_init();
  v106 = wmi_unified_attach(*(__int64 *)v478, v105);
  _qdf_mem_free((__int64)v105);
  if ( !v106 )
  {
    v170 = "%s: failed to attach WMI";
LABEL_30:
    inited = 2;
    qdf_trace_msg(0x36u, 2u, v170, v107, v108, v109, v110, v111, v112, v113, v114, "wma_open");
    goto LABEL_31;
  }
  target_if_register_legacy_service_ready_cb((__int64)wma_legacy_service_ready_event_handler);
  qdf_trace_msg(
    0x36u,
    4u,
    "%s: WMA --> wmi_unified_attach - success",
    v115,
    v116,
    v117,
    v118,
    v119,
    v120,
    v121,
    v122,
    "wma_open");
  if ( a1 && (v131 = *(_QWORD *)(a1 + 2800)) != 0 )
  {
    v132 = v106;
    v133 = *(_QWORD **)v478;
    v134 = 0;
    *(_DWORD *)(v131 + 496) = a4;
    v135 = v132;
    *(_DWORD *)(v131 + 4488) = conparam;
    *(_QWORD *)(v131 + 16) = v132;
    *v133 = v132;
    *(_QWORD *)(v131 + 8) = v41;
  }
  else
  {
    v131 = 0;
    v135 = v106;
    **(_QWORD **)v478 = v106;
    v134 = 1;
  }
  v136 = *(_QWORD **)v478;
  *(_QWORD *)(*(_QWORD *)v478 + 8LL) = v30;
  v136[23] = context;
  *((_BYTE *)v136 + 3953) = *((_BYTE *)a3 + 128);
  init_deinit_register_tgt_psoc_ev_handlers(a1, v123, v124, v125, v126, v127, v128, v129, v130);
  target_if_roam_register_common_events(a1, v137, v138, v139, v140, v141, v142, v143, v144);
  target_if_roam_offload_register_events(a1, v145, v146, v147, v148, v149, v150, v151, v152);
  v153 = wma_init_max_no_of_peers(*(_QWORD *)v478, *a3);
  *a3 = v153;
  wlan_mlme_set_assoc_sta_limit(a1, v153);
  wlan_mlme_register_common_events(a1, v154, v155, v156, v157, v158, v159, v160, v161);
  if ( (v134 & 1) != 0 || v131 == -64 )
  {
    v170 = "%s: wlan_res_cfg is null";
    goto LABEL_30;
  }
  wma_set_default_tgt_config(v478[0], v131 + 64);
  if ( (unsigned int)wlan_mlme_get_tx_chainmask_cck(a1, v477) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to get tx_chainmask_cck",
      v162,
      v163,
      v164,
      v165,
      v166,
      v167,
      v168,
      v169,
      "wma_open");
    inited = 16;
    goto LABEL_31;
  }
  *(_BYTE *)(*(_QWORD *)v478 + 2922LL) = v477[0];
  if ( (unsigned int)wlan_mlme_get_self_gen_frm_pwr(a1, &v476) )
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to get self_gen_frm_pwr",
      v179,
      v180,
      v181,
      v182,
      v183,
      v184,
      v185,
      v186,
      "wma_open");
  v187 = *(_QWORD **)v478;
  *(_WORD *)(*(_QWORD *)v478 + 2920LL) = v476;
  v188 = *a3;
  a3[1] = 6;
  v189 = v187[3];
  *((_WORD *)v187 + 80) = v188;
  *((_WORD *)v187 + 81) = a3[1];
  v190 = ucfg_pmo_is_mc_addr_list_enabled(v189) & 1;
  v191 = *(_QWORD *)(*(_QWORD *)v478 + 24LL);
  *(_BYTE *)(*(_QWORD *)v478 + 692LL) = v190;
  active_uc_apf_mode = ucfg_pmo_get_active_uc_apf_mode(v191);
  v193 = *(_QWORD *)(*(_QWORD *)v478 + 24LL);
  *(_DWORD *)(*(_QWORD *)v478 + 3352LL) = active_uc_apf_mode;
  active_mc_bc_apf_mode = ucfg_pmo_get_active_mc_bc_apf_mode(v193);
  v195 = *(_QWORD **)v478;
  v196 = *(unsigned __int16 *)(*(_QWORD *)v478 + 162LL);
  *(_DWORD *)(*(_QWORD *)v478 + 3356LL) = active_mc_bc_apf_mode;
  v195[476] = 0;
  *((_BYTE *)v195 + 2704) = *((_BYTE *)a3 + 29);
  v197 = _qdf_mem_malloc(488LL * v196, "wma_open", 3849);
  v206 = *(_QWORD **)v478;
  v207 = v135;
  *(_QWORD *)(*(_QWORD *)v478 + 520LL) = v197;
  if ( !v197 )
  {
    inited = 2;
LABEL_55:
    _qdf_mem_free(*(_QWORD *)(v30 + 72));
    *(_QWORD *)(v30 + 72) = 0;
    _qdf_mem_free(v207);
    goto LABEL_31;
  }
  if ( *((_WORD *)v206 + 81) )
  {
    v208 = 0;
    v209 = 432;
    do
    {
      ++v208;
      *(_BYTE *)(v206[65] + v209) = 0;
      v209 += 488;
      v206 = *(_QWORD **)v478;
    }
    while ( v208 < *(unsigned __int16 *)(*(_QWORD *)v478 + 162LL) );
  }
  wmi_unified_register_event_handler(
    (_QWORD *)*v206,
    0x13u,
    (__int64)wma_unified_debug_print_event_handler,
    2u,
    v198,
    v199,
    v200,
    v201,
    v202,
    v203,
    v204,
    v205);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0x15u,
    (__int64)wma_profile_data_report_event_handler,
    2u,
    v210,
    v211,
    v212,
    v213,
    v214,
    v215,
    v216,
    v217);
  v218 = *(_QWORD **)v478;
  *(_QWORD *)(*(_QWORD *)v478 + 448LL) = a2;
  v218[364] = 0xFFFF0000FFFFLL;
  *((_BYTE *)v218 + 3364) = 0;
  *((_BYTE *)v218 + 3777) = *((_BYTE *)a3 + 38);
  v219 = qdf_mc_timer_init((__int64)(v218 + 366), 0, (__int64)wma_service_ready_ext_evt_timeout, (__int64)v218);
  if ( v219 )
  {
    inited = v219;
    v228 = "%s: Failed to initialize service ready ext timeout";
LABEL_50:
    qdf_trace_msg(0x36u, 2u, v228, v220, v221, v222, v223, v224, v225, v226, v227, "wma_open");
LABEL_51:
    wmi_unified_unregister_event_handler(**(_QWORD ***)v478, 0x13u, v232, v233, v234, v235, v236, v237, v238, v239);
    v248 = *(_QWORD **)v478;
    if ( *(_WORD *)(*(_QWORD *)v478 + 162LL) )
    {
      v249 = 0;
      v250 = 0;
      do
      {
        wma_vdev_deinit(v248[65] + v249, v240, v241, v242, v243, v244, v245, v246, v247);
        v248 = *(_QWORD **)v478;
        ++v250;
        v249 += 488;
      }
      while ( v250 < *(unsigned __int16 *)(*(_QWORD *)v478 + 162LL) );
    }
    _qdf_mem_free(v248[65]);
    v207 = v135;
    goto LABEL_55;
  }
  v229 = qdf_event_create((_DWORD *)(*(_QWORD *)v478 + 40LL));
  if ( v229 )
  {
    inited = v229;
    v228 = "%s: target suspend event initialization failed";
    goto LABEL_50;
  }
  v230 = qdf_event_create((_DWORD *)(*(_QWORD *)v478 + 344LL));
  if ( v230 )
  {
    inited = v230;
    v228 = "%s: failed to init tx_frm_download_comp_event";
    goto LABEL_50;
  }
  v231 = qdf_event_create((_DWORD *)(*(_QWORD *)v478 + 384LL));
  if ( v231 )
  {
    inited = v231;
    v228 = "%s: failed to init tx_queue_empty_event";
    goto LABEL_50;
  }
  v251 = cds_shutdown_notifier_register((__int64)wma_shutdown_notifier_cb, *(__int64 *)v478);
  if ( v251 )
  {
    inited = v251;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Shutdown notifier register failed: %d",
      v252,
      v253,
      v254,
      v255,
      v256,
      v257,
      v258,
      v259,
      "wma_open",
      v251);
    goto LABEL_51;
  }
  v260 = qdf_event_create((_DWORD *)(*(_QWORD *)v478 + 80LL));
  if ( v260 )
  {
    inited = v260;
    v228 = "%s: runtime_suspend event initialization failed";
    goto LABEL_50;
  }
  v261 = qdf_event_create((_DWORD *)(*(_QWORD *)v478 + 120LL));
  if ( v261 )
  {
    inited = v261;
    v228 = "%s: recovery event initialization failed";
    goto LABEL_50;
  }
  v262 = qdf_mutex_create(*(_QWORD *)v478 + 3816LL);
  if ( v262 )
  {
    inited = v262;
    v228 = "%s: Failed to create radio stats mutex";
    goto LABEL_50;
  }
  v263 = *(_QWORD **)v478;
  v264 = *(_QWORD *)v478 + 576LL;
  *(_QWORD *)(*(_QWORD *)v478 + 576LL) = *(_QWORD *)v478 + 576LL;
  v263[73] = v264;
  v263[74] = 0x200000000LL;
  *((_DWORD *)v263 + 150) = 0;
  v263[76] = 0;
  *((_DWORD *)v263 + 675) = 0;
  *((_DWORD *)v263 + 989) = 0;
  *((_DWORD *)v263 + 990) = 0;
  wmi_unified_register_event_handler(
    (_QWORD *)*v263,
    0xBu,
    (__int64)wma_peer_sta_kickout_event_handler,
    2u,
    v220,
    v221,
    v222,
    v223,
    v224,
    v225,
    v226,
    v227);
  v265 = wma_register_fw_state_events(**(_QWORD **)v478);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0xA8u,
    (__int64)wma_unified_power_debug_stats_event_handler,
    2u,
    v265,
    v266,
    v267,
    v268,
    v269,
    v270,
    v271,
    v272);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0xCEu,
    (__int64)wma_unified_beacon_debug_stats_event_handler,
    2u,
    v273,
    v274,
    v275,
    v276,
    v277,
    v278,
    v279,
    v280);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0x44u,
    (__int64)wma_link_speed_event_handler,
    2u,
    v281,
    v282,
    v283,
    v284,
    v285,
    v286,
    v287,
    v288);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0x46u,
    (__int64)wma_unified_bcntx_status_event_handler,
    2u,
    v289,
    v290,
    v291,
    v292,
    v293,
    v294,
    v295,
    v296);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0x67u,
    (__int64)wma_link_status_event_handler,
    2u,
    v297,
    v298,
    v299,
    v300,
    v301,
    v302,
    v303,
    v304);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0xC9u,
    (__int64)wma_roam_scan_stats_event_handler,
    2u,
    v305,
    v306,
    v307,
    v308,
    v309,
    v310,
    v311,
    v312);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0xD2u,
    (__int64)wma_cold_boot_cal_event_handler,
    0,
    v313,
    v314,
    v315,
    v316,
    v317,
    v318,
    v319,
    v320);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0xE3u,
    (__int64)wma_oem_event_handler,
    0,
    v321,
    v322,
    v323,
    v324,
    v325,
    v326,
    v327,
    v328);
  wma_register_ll_stats_event_handler(*(_QWORD *)v478);
  wmi_set_tgt_assert(**(_QWORD **)v478, *((_BYTE *)a3 + 121));
  if ( (unsigned int)dbglog_init(**(_QWORD **)v478) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Firmware Dbglog initialization failed",
      v329,
      v330,
      v331,
      v332,
      v333,
      v334,
      v335,
      v336,
      "wma_open");
    inited = qdf_mutex_destroy(*(_QWORD *)v478 + 3816LL);
    if ( inited )
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to destroy radio stats mutex",
        v337,
        v338,
        v339,
        v340,
        v341,
        v342,
        v343,
        v344,
        "wma_open");
    _qdf_wake_lock_destroy(*(_QWORD *)v478 + 3128LL);
    qdf_runtime_lock_deinit((__int64 *)(*(_QWORD *)v478 + 3344LL));
    qdf_runtime_lock_deinit((__int64 *)(*(_QWORD *)v478 + 3336LL));
    qdf_runtime_lock_deinit((__int64 *)(*(_QWORD *)v478 + 3328LL));
    goto LABEL_51;
  }
  v345 = *(_QWORD **)v478;
  *(_BYTE *)(*(_QWORD *)v478 + 2705LL) = *((_BYTE *)a3 + 4);
  v346 = v345[3];
  *((_WORD *)v345 + 1353) = a3[3];
  sta_mod_dtim = ucfg_pmo_get_sta_mod_dtim(v346);
  v348 = *(_QWORD *)(*(_QWORD *)v478 + 24LL);
  *(_BYTE *)(*(_QWORD *)v478 + 2708LL) = sta_mod_dtim;
  sta_teles_dtim = ucfg_pmo_get_sta_teles_dtim(v348);
  v350 = *(_QWORD *)(*(_QWORD *)v478 + 24LL);
  *(_BYTE *)(*(_QWORD *)v478 + 2709LL) = sta_teles_dtim;
  sta_min_teles_dtim = ucfg_pmo_get_sta_min_teles_dtim(v350);
  v352 = *(_QWORD *)(*(_QWORD *)v478 + 24LL);
  *(_BYTE *)(*(_QWORD *)v478 + 2710LL) = sta_min_teles_dtim;
  sta_dynamic_dtim = ucfg_pmo_get_sta_dynamic_dtim(v352);
  v354 = **(_QWORD ***)v478;
  *(_BYTE *)(*(_QWORD *)v478 + 2711LL) = v355;
  wmi_unified_register_event_handler(
    v354,
    0x56u,
    (__int64)wma_stats_ext_event_handler,
    2u,
    sta_dynamic_dtim,
    v356,
    v357,
    v358,
    v359,
    v360,
    v361,
    v362);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0x6Cu,
    (__int64)wma_rssi_breached_event_handler,
    2u,
    v363,
    v364,
    v365,
    v366,
    v367,
    v368,
    v369,
    v370);
  _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v478 + 3128LL), (__int64)"wlan_fw_rsp_wakelock");
  _qdf_runtime_lock_init((__int64 *)(*(_QWORD *)v478 + 3328LL), "&wma_handle->wmi_cmd_rsp_runtime_lock");
  _qdf_runtime_lock_init((__int64 *)(*(_QWORD *)v478 + 3336LL), "&wma_handle->sap_prevent_runtime_pm_lock");
  _qdf_runtime_lock_init((__int64 *)(*(_QWORD *)v478 + 3344LL), "&wma_handle->ndp_prevent_runtime_pm_lock");
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0xAAu,
    (__int64)wma_peer_assoc_conf_handler,
    2u,
    v371,
    v372,
    v373,
    v374,
    v375,
    v376,
    v377,
    v378);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0xEDu,
    (__int64)wma_peer_create_confirm_handler,
    2u,
    v379,
    v380,
    v381,
    v382,
    v383,
    v384,
    v385,
    v386);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0x8Eu,
    (__int64)wma_peer_delete_handler,
    2u,
    v387,
    v388,
    v389,
    v390,
    v391,
    v392,
    v393,
    v394);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0xFu,
    (__int64)wma_chan_info_event_handler,
    2u,
    v395,
    v396,
    v397,
    v398,
    v399,
    v400,
    v401,
    v402);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0x6Bu,
    (__int64)wma_flush_complete_evt_handler,
    0,
    v403,
    v404,
    v405,
    v406,
    v407,
    v408,
    v409,
    v410);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0xAEu,
    (__int64)wma_rx_aggr_failure_event_handler,
    2u,
    v411,
    v412,
    v413,
    v414,
    v415,
    v416,
    v417,
    v418);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0xD9u,
    (__int64)wma_antenna_isolation_event_handler,
    2u,
    v419,
    v420,
    v421,
    v422,
    v423,
    v424,
    v425,
    v426);
  v427 = *(_QWORD *)(*(_QWORD *)v478 + 24LL);
  *(_BYTE *)(*(_QWORD *)v478 + 3951LL) = *((_BYTE *)a3 + 120);
  if ( (unsigned int)ucfg_pmo_get_auto_power_fail_mode(v427) == 1 )
    wmi_unified_register_event_handler(
      **(_QWORD ***)v478,
      0xAFu,
      (__int64)wma_chip_power_save_failure_detected_handler,
      0,
      v428,
      v429,
      v430,
      v431,
      v432,
      v433,
      v434,
      v435);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0xBDu,
    (__int64)wma_pdev_div_info_evt_handler,
    0,
    v428,
    v429,
    v430,
    v431,
    v432,
    v433,
    v434,
    v435);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0xE0u,
    (__int64)wma_get_ani_level_evt_handler,
    0,
    v436,
    v437,
    v438,
    v439,
    v440,
    v441,
    v442,
    v443);
  ((void (__fastcall *)(__int64, __int64 (__fastcall *)()))qdf_register_debug_callback)(54, wma_state_info_dump);
  wifi_pos_register_get_phy_mode_cb(*(_QWORD *)(*(_QWORD *)v478 + 24LL), wma_get_phy_mode_cb);
  wifi_pos_register_get_fw_phy_mode_for_freq_cb(*(_QWORD *)(*(_QWORD *)v478 + 24LL), wma_get_fw_phy_mode_for_freq_cb);
  pmo_register_pause_bitmap_notifier(*(_QWORD *)(*(_QWORD *)v478 + 24LL), wma_vdev_update_pause_bitmap_0);
  pmo_register_get_pause_bitmap(*(_QWORD *)(*(_QWORD *)v478 + 24LL), wma_vdev_get_pause_bitmap);
  pmo_register_is_device_in_low_pwr_mode(*(_QWORD *)(*(_QWORD *)v478 + 24LL), wma_vdev_is_device_in_low_pwr_mode);
  pmo_register_get_dtim_period_callback(*(_QWORD *)(*(_QWORD *)v478 + 24LL), wma_vdev_get_dtim_period);
  pmo_register_get_beacon_interval_callback(*(_QWORD *)(*(_QWORD *)v478 + 24LL), wma_vdev_get_beacon_interval);
  v444 = wma_register_nan_callbacks(*(_QWORD *)v478);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0x10u,
    (__int64)wma_unified_phyerr_rx_event_handler,
    0,
    v444,
    v445,
    v446,
    v447,
    v448,
    v449,
    v450,
    v451);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0xB9u,
    (__int64)wma_vdev_obss_detection_info_handler,
    2u,
    v452,
    v453,
    v454,
    v455,
    v456,
    v457,
    v458,
    v459);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0xBAu,
    (__int64)wma_vdev_bss_color_collision_info_handler,
    0,
    v460,
    v461,
    v462,
    v463,
    v464,
    v465,
    v466,
    v467);
  wma_register_twt_events(*(_QWORD *)v478);
  v468 = wma_register_apf_events(*(_QWORD *)v478);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v478,
    0xFBu,
    (__int64)wma_latency_level_event_handler,
    0,
    v468,
    v469,
    v470,
    v471,
    v472,
    v473,
    v474,
    v475);
  wma_register_mws_coex_events(*(_QWORD *)v478);
  qdf_trace_register(54, (__int64)wma_trace_dump);
  wma_set_exclude_selftx_from_cca_busy_time(*((unsigned __int8 *)a3 + 145), *(_QWORD *)v478);
  result = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
