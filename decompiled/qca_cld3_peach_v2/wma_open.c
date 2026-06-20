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
  __int64 v162; // x23
  double v163; // d0
  double v164; // d1
  double v165; // d2
  double v166; // d3
  double v167; // d4
  double v168; // d5
  double v169; // d6
  double v170; // d7
  const char *v171; // x2
  double v172; // d0
  double v173; // d1
  double v174; // d2
  double v175; // d3
  double v176; // d4
  double v177; // d5
  double v178; // d6
  double v179; // d7
  double v180; // d0
  double v181; // d1
  double v182; // d2
  double v183; // d3
  double v184; // d4
  double v185; // d5
  double v186; // d6
  double v187; // d7
  _QWORD *v188; // x9
  __int16 v189; // w10
  __int64 v190; // x0
  char v191; // w9
  __int64 v192; // x0
  int active_uc_apf_mode; // w0
  __int64 v194; // x8
  int active_mc_bc_apf_mode; // w0
  _QWORD *v196; // x8
  unsigned int v197; // w9
  __int64 v198; // x0
  double v199; // d0
  double v200; // d1
  double v201; // d2
  double v202; // d3
  double v203; // d4
  double v204; // d5
  double v205; // d6
  double v206; // d7
  _QWORD *v207; // x8
  __int64 v208; // x21
  unsigned __int64 v209; // x9
  __int64 v210; // x10
  double v211; // d0
  double v212; // d1
  double v213; // d2
  double v214; // d3
  double v215; // d4
  double v216; // d5
  double v217; // d6
  double v218; // d7
  _QWORD *v219; // x3
  unsigned int v220; // w0
  double v221; // d0
  double v222; // d1
  double v223; // d2
  double v224; // d3
  double v225; // d4
  double v226; // d5
  double v227; // d6
  double v228; // d7
  const char *v229; // x2
  unsigned int v230; // w0
  unsigned int v231; // w0
  unsigned int v232; // w0
  double v233; // d0
  double v234; // d1
  double v235; // d2
  double v236; // d3
  double v237; // d4
  double v238; // d5
  double v239; // d6
  double v240; // d7
  double v241; // d0
  double v242; // d1
  double v243; // d2
  double v244; // d3
  double v245; // d4
  double v246; // d5
  double v247; // d6
  double v248; // d7
  _QWORD *v249; // x8
  __int64 v250; // x19
  unsigned __int64 v251; // x21
  unsigned int v252; // w0
  double v253; // d0
  double v254; // d1
  double v255; // d2
  double v256; // d3
  double v257; // d4
  double v258; // d5
  double v259; // d6
  double v260; // d7
  unsigned int v261; // w0
  unsigned int v262; // w0
  unsigned int v263; // w0
  _QWORD *v264; // x8
  __int64 v265; // x9
  double v266; // d0
  double v267; // d1
  double v268; // d2
  double v269; // d3
  double v270; // d4
  double v271; // d5
  double v272; // d6
  double v273; // d7
  double v274; // d0
  double v275; // d1
  double v276; // d2
  double v277; // d3
  double v278; // d4
  double v279; // d5
  double v280; // d6
  double v281; // d7
  double v282; // d0
  double v283; // d1
  double v284; // d2
  double v285; // d3
  double v286; // d4
  double v287; // d5
  double v288; // d6
  double v289; // d7
  double v290; // d0
  double v291; // d1
  double v292; // d2
  double v293; // d3
  double v294; // d4
  double v295; // d5
  double v296; // d6
  double v297; // d7
  double v298; // d0
  double v299; // d1
  double v300; // d2
  double v301; // d3
  double v302; // d4
  double v303; // d5
  double v304; // d6
  double v305; // d7
  double v306; // d0
  double v307; // d1
  double v308; // d2
  double v309; // d3
  double v310; // d4
  double v311; // d5
  double v312; // d6
  double v313; // d7
  double v314; // d0
  double v315; // d1
  double v316; // d2
  double v317; // d3
  double v318; // d4
  double v319; // d5
  double v320; // d6
  double v321; // d7
  double v322; // d0
  double v323; // d1
  double v324; // d2
  double v325; // d3
  double v326; // d4
  double v327; // d5
  double v328; // d6
  double v329; // d7
  double v330; // d0
  double v331; // d1
  double v332; // d2
  double v333; // d3
  double v334; // d4
  double v335; // d5
  double v336; // d6
  double v337; // d7
  double v338; // d0
  double v339; // d1
  double v340; // d2
  double v341; // d3
  double v342; // d4
  double v343; // d5
  double v344; // d6
  double v345; // d7
  _QWORD *v346; // x9
  __int64 v347; // x0
  char sta_mod_dtim; // w0
  __int64 v349; // x8
  char sta_teles_dtim; // w0
  __int64 v351; // x8
  char sta_min_teles_dtim; // w0
  __int64 v353; // x8
  double sta_dynamic_dtim; // d0
  _QWORD *v355; // x8
  char v356; // w0
  double v357; // d1
  double v358; // d2
  double v359; // d3
  double v360; // d4
  double v361; // d5
  double v362; // d6
  double v363; // d7
  double v364; // d0
  double v365; // d1
  double v366; // d2
  double v367; // d3
  double v368; // d4
  double v369; // d5
  double v370; // d6
  double v371; // d7
  double v372; // d0
  double v373; // d1
  double v374; // d2
  double v375; // d3
  double v376; // d4
  double v377; // d5
  double v378; // d6
  double v379; // d7
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
  double v396; // d0
  double v397; // d1
  double v398; // d2
  double v399; // d3
  double v400; // d4
  double v401; // d5
  double v402; // d6
  double v403; // d7
  double v404; // d0
  double v405; // d1
  double v406; // d2
  double v407; // d3
  double v408; // d4
  double v409; // d5
  double v410; // d6
  double v411; // d7
  double v412; // d0
  double v413; // d1
  double v414; // d2
  double v415; // d3
  double v416; // d4
  double v417; // d5
  double v418; // d6
  double v419; // d7
  double v420; // d0
  double v421; // d1
  double v422; // d2
  double v423; // d3
  double v424; // d4
  double v425; // d5
  double v426; // d6
  double v427; // d7
  __int64 v428; // x0
  double v429; // d0
  double v430; // d1
  double v431; // d2
  double v432; // d3
  double v433; // d4
  double v434; // d5
  double v435; // d6
  double v436; // d7
  double v437; // d0
  double v438; // d1
  double v439; // d2
  double v440; // d3
  double v441; // d4
  double v442; // d5
  double v443; // d6
  double v444; // d7
  double v445; // d0
  double v446; // d1
  double v447; // d2
  double v448; // d3
  double v449; // d4
  double v450; // d5
  double v451; // d6
  double v452; // d7
  double v453; // d0
  double v454; // d1
  double v455; // d2
  double v456; // d3
  double v457; // d4
  double v458; // d5
  double v459; // d6
  double v460; // d7
  double v461; // d0
  double v462; // d1
  double v463; // d2
  double v464; // d3
  double v465; // d4
  double v466; // d5
  double v467; // d6
  double v468; // d7
  double v469; // d0
  double v470; // d1
  double v471; // d2
  double v472; // d3
  double v473; // d4
  double v474; // d5
  double v475; // d6
  double v476; // d7
  int v477; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v478[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v479[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v480; // [xsp+18h] [xbp-8h]

  v480 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)v479 = 0;
  v478[0] = 0;
  v477 = 0;
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
  dword_923C14 = 1632;
  context = _cds_get_context(64, (__int64)"wma_open", v22, v23, v24, v25, v26, v27, v28, v29);
  v40 = _cds_get_context(62, (__int64)"wma_open", v32, v33, v34, v35, v36, v37, v38, v39);
  if ( !v40 )
  {
    v53 = "%s: Invalid HTC handle";
    goto LABEL_7;
  }
  v41 = v40;
  v42 = cds_alloc_context(0x36u, (__int64 *)v479, 0x1468u, v22, v23, v24, v25, v26, v27, v28, v29);
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
  qdf_mem_set(*(void **)v479, 0x1468u, 0);
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
    cds_free_context(54, *(__int64 *)v479, v71, v72, v73, v74, v75, v76, v77, v78);
    qdf_trace_msg(0x36u, 8u, "%s: Exit", v172, v173, v174, v175, v176, v177, v178, v179, "wma_open");
    result = inited;
    goto LABEL_8;
  }
  if ( conparam != 5 )
  {
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v479 + 696LL), (__int64)"wlan_wow_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v479 + 896LL), (__int64)"wlan_auth_req_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v479 + 1096LL), (__int64)"wlan_assoc_req_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v479 + 1296LL), (__int64)"wlan_deauth_rec_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v479 + 1496LL), (__int64)"wlan_disassoc_rec_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v479 + 1696LL), (__int64)"wlan_ap_assoc_lost_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v479 + 1896LL), (__int64)"wlan_auto_shutdown_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v479 + 2096LL), (__int64)"wlan_roam_ho_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v479 + 2296LL), (__int64)"wlan_roam_preauth_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v479 + 2496LL), (__int64)"wlan_probe_req_wps_wl");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v479 + 3984LL), (__int64)"wlan_sap_d3_wow_wake_lock");
    _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v479 + 4184LL), (__int64)"wlan_go_d3_wow_wake_lock");
  }
  ref = wlan_objmgr_psoc_try_get_ref(a1, 8u, v62, v63, v64, v65, v66, v67, v68, v69);
  if ( ref )
  {
    inited = ref;
    qdf_trace_msg(0x36u, 2u, "%s: PSOC get_ref fails", v80, v81, v82, v83, v84, v85, v86, v87, "wma_open");
    goto LABEL_32;
  }
  *(_QWORD *)(*(_QWORD *)v479 + 24LL) = a1;
  if ( (wlan_pmo_no_op_on_page_fault(a1) & 1) == 0 )
  {
    inited = wma_init_pagefault_wakeup_history(*(_QWORD *)v479);
    if ( inited )
    {
LABEL_31:
      wlan_objmgr_psoc_release_ref(a1, 8u, v96, v97, v98, v99, v100, v101, v102, v103);
LABEL_32:
      target_if_free_psoc_tgt_info(a1, v88, v89, v90, v91, v92, v93, v94, v95);
      if ( (unsigned int)cds_get_conparam() != 5 )
      {
        _qdf_wake_lock_destroy(*(_QWORD *)v479 + 4184LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v479 + 3984LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v479 + 696LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v479 + 896LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v479 + 1096LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v479 + 1296LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v479 + 1496LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v479 + 1696LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v479 + 1896LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v479 + 2096LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v479 + 2296LL);
        _qdf_wake_lock_destroy(*(_QWORD *)v479 + 2496LL);
      }
      goto LABEL_34;
    }
  }
  wma_target_if_open(*(_QWORD *)v479);
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
  v106 = wmi_unified_attach(*(__int64 *)v479, v105);
  _qdf_mem_free((__int64)v105);
  if ( !v106 )
  {
    v171 = "%s: failed to attach WMI";
LABEL_30:
    inited = 2;
    qdf_trace_msg(0x36u, 2u, v171, v107, v108, v109, v110, v111, v112, v113, v114, "wma_open");
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
    v133 = *(_QWORD **)v479;
    v134 = 0;
    *(_DWORD *)(v131 + 496) = a4;
    v135 = v132;
    *(_DWORD *)(v131 + 5768) = conparam;
    *(_QWORD *)(v131 + 16) = v132;
    *v133 = v132;
    *(_QWORD *)(v131 + 8) = v41;
  }
  else
  {
    v131 = 0;
    v135 = v106;
    **(_QWORD **)v479 = v106;
    v134 = 1;
  }
  v136 = *(_QWORD **)v479;
  *(_QWORD *)(*(_QWORD *)v479 + 8LL) = v30;
  v136[23] = context;
  *((_BYTE *)v136 + 3953) = *((_BYTE *)a3 + 128);
  init_deinit_register_tgt_psoc_ev_handlers(a1, v123, v124, v125, v126, v127, v128, v129, v130);
  target_if_roam_register_common_events(a1, v137, v138, v139, v140, v141, v142, v143, v144);
  target_if_roam_offload_register_events(a1, v145, v146, v147, v148, v149, v150, v151, v152);
  v153 = wma_init_max_no_of_peers(*(_QWORD *)v479, *a3);
  *a3 = v153;
  wlan_mlme_set_assoc_sta_limit(a1, v153);
  wlan_mlme_register_common_events(a1, v154, v155, v156, v157, v158, v159, v160, v161);
  if ( (v134 & 1) != 0 || (v162 = v131 + 64) == 0 )
  {
    v171 = "%s: wlan_res_cfg is null";
    goto LABEL_30;
  }
  wma_set_default_tgt_config(v479[0], v162);
  wma_update_num_tdls_vdevs_if_11be_mlo(a1, v162);
  if ( (unsigned int)wlan_mlme_get_tx_chainmask_cck(a1, v478) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to get tx_chainmask_cck",
      v163,
      v164,
      v165,
      v166,
      v167,
      v168,
      v169,
      v170,
      "wma_open");
    inited = 16;
    goto LABEL_31;
  }
  *(_BYTE *)(*(_QWORD *)v479 + 2922LL) = v478[0];
  if ( (unsigned int)wlan_mlme_get_self_gen_frm_pwr(a1, &v477) )
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to get self_gen_frm_pwr",
      v180,
      v181,
      v182,
      v183,
      v184,
      v185,
      v186,
      v187,
      "wma_open");
  v188 = *(_QWORD **)v479;
  *(_WORD *)(*(_QWORD *)v479 + 2920LL) = v477;
  v189 = *a3;
  a3[1] = 6;
  v190 = v188[3];
  *((_WORD *)v188 + 80) = v189;
  *((_WORD *)v188 + 81) = a3[1];
  v191 = ucfg_pmo_is_mc_addr_list_enabled(v190) & 1;
  v192 = *(_QWORD *)(*(_QWORD *)v479 + 24LL);
  *(_BYTE *)(*(_QWORD *)v479 + 692LL) = v191;
  active_uc_apf_mode = ucfg_pmo_get_active_uc_apf_mode(v192);
  v194 = *(_QWORD *)(*(_QWORD *)v479 + 24LL);
  *(_DWORD *)(*(_QWORD *)v479 + 3352LL) = active_uc_apf_mode;
  active_mc_bc_apf_mode = ucfg_pmo_get_active_mc_bc_apf_mode(v194);
  v196 = *(_QWORD **)v479;
  v197 = *(unsigned __int16 *)(*(_QWORD *)v479 + 162LL);
  *(_DWORD *)(*(_QWORD *)v479 + 3356LL) = active_mc_bc_apf_mode;
  v196[476] = 0;
  *((_BYTE *)v196 + 2704) = *((_BYTE *)a3 + 29);
  v198 = _qdf_mem_malloc(488LL * v197, "wma_open", 3849);
  v207 = *(_QWORD **)v479;
  v208 = v135;
  *(_QWORD *)(*(_QWORD *)v479 + 520LL) = v198;
  if ( !v198 )
  {
    inited = 2;
LABEL_55:
    _qdf_mem_free(*(_QWORD *)(v30 + 72));
    *(_QWORD *)(v30 + 72) = 0;
    _qdf_mem_free(v208);
    goto LABEL_31;
  }
  if ( *((_WORD *)v207 + 81) )
  {
    v209 = 0;
    v210 = 432;
    do
    {
      ++v209;
      *(_BYTE *)(v207[65] + v210) = 0;
      v210 += 488;
      v207 = *(_QWORD **)v479;
    }
    while ( v209 < *(unsigned __int16 *)(*(_QWORD *)v479 + 162LL) );
  }
  wmi_unified_register_event_handler(
    (_QWORD *)*v207,
    0x13u,
    (__int64)wma_unified_debug_print_event_handler,
    2u,
    v199,
    v200,
    v201,
    v202,
    v203,
    v204,
    v205,
    v206);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0x15u,
    (__int64)wma_profile_data_report_event_handler,
    2u,
    v211,
    v212,
    v213,
    v214,
    v215,
    v216,
    v217,
    v218);
  v219 = *(_QWORD **)v479;
  *(_QWORD *)(*(_QWORD *)v479 + 448LL) = a2;
  v219[364] = 0xFFFF0000FFFFLL;
  *((_BYTE *)v219 + 3364) = 0;
  *((_BYTE *)v219 + 3777) = *((_BYTE *)a3 + 38);
  v220 = qdf_mc_timer_init((__int64)(v219 + 366), 0, (__int64)wma_service_ready_ext_evt_timeout, (__int64)v219);
  if ( v220 )
  {
    inited = v220;
    v229 = "%s: Failed to initialize service ready ext timeout";
LABEL_50:
    qdf_trace_msg(0x36u, 2u, v229, v221, v222, v223, v224, v225, v226, v227, v228, "wma_open");
LABEL_51:
    wmi_unified_unregister_event_handler(**(_QWORD ***)v479, 0x13u, v233, v234, v235, v236, v237, v238, v239, v240);
    v249 = *(_QWORD **)v479;
    if ( *(_WORD *)(*(_QWORD *)v479 + 162LL) )
    {
      v250 = 0;
      v251 = 0;
      do
      {
        wma_vdev_deinit(v249[65] + v250, v241, v242, v243, v244, v245, v246, v247, v248);
        v249 = *(_QWORD **)v479;
        ++v251;
        v250 += 488;
      }
      while ( v251 < *(unsigned __int16 *)(*(_QWORD *)v479 + 162LL) );
    }
    _qdf_mem_free(v249[65]);
    v208 = v135;
    goto LABEL_55;
  }
  v230 = qdf_event_create((_DWORD *)(*(_QWORD *)v479 + 40LL));
  if ( v230 )
  {
    inited = v230;
    v229 = "%s: target suspend event initialization failed";
    goto LABEL_50;
  }
  v231 = qdf_event_create((_DWORD *)(*(_QWORD *)v479 + 344LL));
  if ( v231 )
  {
    inited = v231;
    v229 = "%s: failed to init tx_frm_download_comp_event";
    goto LABEL_50;
  }
  v232 = qdf_event_create((_DWORD *)(*(_QWORD *)v479 + 384LL));
  if ( v232 )
  {
    inited = v232;
    v229 = "%s: failed to init tx_queue_empty_event";
    goto LABEL_50;
  }
  v252 = cds_shutdown_notifier_register((__int64)wma_shutdown_notifier_cb, *(__int64 *)v479);
  if ( v252 )
  {
    inited = v252;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Shutdown notifier register failed: %d",
      v253,
      v254,
      v255,
      v256,
      v257,
      v258,
      v259,
      v260,
      "wma_open",
      v252);
    goto LABEL_51;
  }
  v261 = qdf_event_create((_DWORD *)(*(_QWORD *)v479 + 80LL));
  if ( v261 )
  {
    inited = v261;
    v229 = "%s: runtime_suspend event initialization failed";
    goto LABEL_50;
  }
  v262 = qdf_event_create((_DWORD *)(*(_QWORD *)v479 + 120LL));
  if ( v262 )
  {
    inited = v262;
    v229 = "%s: recovery event initialization failed";
    goto LABEL_50;
  }
  v263 = qdf_mutex_create(*(_QWORD *)v479 + 3816LL);
  if ( v263 )
  {
    inited = v263;
    v229 = "%s: Failed to create radio stats mutex";
    goto LABEL_50;
  }
  v264 = *(_QWORD **)v479;
  v265 = *(_QWORD *)v479 + 576LL;
  *(_QWORD *)(*(_QWORD *)v479 + 576LL) = *(_QWORD *)v479 + 576LL;
  v264[73] = v265;
  v264[74] = 0x200000000LL;
  *((_DWORD *)v264 + 150) = 0;
  v264[76] = 0;
  *((_DWORD *)v264 + 675) = 0;
  *((_DWORD *)v264 + 994) = 0;
  *((_DWORD *)v264 + 995) = 0;
  wmi_unified_register_event_handler(
    (_QWORD *)*v264,
    0xBu,
    (__int64)wma_peer_sta_kickout_event_handler,
    2u,
    v221,
    v222,
    v223,
    v224,
    v225,
    v226,
    v227,
    v228);
  v266 = wma_register_fw_state_events(**(_QWORD **)v479);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0xA8u,
    (__int64)wma_unified_power_debug_stats_event_handler,
    2u,
    v266,
    v267,
    v268,
    v269,
    v270,
    v271,
    v272,
    v273);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0xCEu,
    (__int64)wma_unified_beacon_debug_stats_event_handler,
    2u,
    v274,
    v275,
    v276,
    v277,
    v278,
    v279,
    v280,
    v281);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0x44u,
    (__int64)wma_link_speed_event_handler,
    2u,
    v282,
    v283,
    v284,
    v285,
    v286,
    v287,
    v288,
    v289);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0x46u,
    (__int64)wma_unified_bcntx_status_event_handler,
    2u,
    v290,
    v291,
    v292,
    v293,
    v294,
    v295,
    v296,
    v297);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0x67u,
    (__int64)wma_link_status_event_handler,
    2u,
    v298,
    v299,
    v300,
    v301,
    v302,
    v303,
    v304,
    v305);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0xC9u,
    (__int64)wma_roam_scan_stats_event_handler,
    2u,
    v306,
    v307,
    v308,
    v309,
    v310,
    v311,
    v312,
    v313);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0xD2u,
    (__int64)wma_cold_boot_cal_event_handler,
    0,
    v314,
    v315,
    v316,
    v317,
    v318,
    v319,
    v320,
    v321);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0xE3u,
    (__int64)wma_oem_event_handler,
    0,
    v322,
    v323,
    v324,
    v325,
    v326,
    v327,
    v328,
    v329);
  wma_register_ll_stats_event_handler(*(_QWORD *)v479);
  wmi_set_tgt_assert(**(_QWORD **)v479, *((_BYTE *)a3 + 121));
  if ( (unsigned int)dbglog_init(**(_QWORD **)v479) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Firmware Dbglog initialization failed",
      v330,
      v331,
      v332,
      v333,
      v334,
      v335,
      v336,
      v337,
      "wma_open");
    inited = qdf_mutex_destroy(*(_QWORD *)v479 + 3816LL);
    if ( inited )
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to destroy radio stats mutex",
        v338,
        v339,
        v340,
        v341,
        v342,
        v343,
        v344,
        v345,
        "wma_open");
    _qdf_wake_lock_destroy(*(_QWORD *)v479 + 3128LL);
    qdf_runtime_lock_deinit((__int64 *)(*(_QWORD *)v479 + 3344LL));
    qdf_runtime_lock_deinit((__int64 *)(*(_QWORD *)v479 + 3336LL));
    qdf_runtime_lock_deinit((__int64 *)(*(_QWORD *)v479 + 3328LL));
    goto LABEL_51;
  }
  v346 = *(_QWORD **)v479;
  *(_BYTE *)(*(_QWORD *)v479 + 2705LL) = *((_BYTE *)a3 + 4);
  v347 = v346[3];
  *((_WORD *)v346 + 1353) = a3[3];
  sta_mod_dtim = ucfg_pmo_get_sta_mod_dtim(v347);
  v349 = *(_QWORD *)(*(_QWORD *)v479 + 24LL);
  *(_BYTE *)(*(_QWORD *)v479 + 2708LL) = sta_mod_dtim;
  sta_teles_dtim = ucfg_pmo_get_sta_teles_dtim(v349);
  v351 = *(_QWORD *)(*(_QWORD *)v479 + 24LL);
  *(_BYTE *)(*(_QWORD *)v479 + 2709LL) = sta_teles_dtim;
  sta_min_teles_dtim = ucfg_pmo_get_sta_min_teles_dtim(v351);
  v353 = *(_QWORD *)(*(_QWORD *)v479 + 24LL);
  *(_BYTE *)(*(_QWORD *)v479 + 2710LL) = sta_min_teles_dtim;
  sta_dynamic_dtim = ucfg_pmo_get_sta_dynamic_dtim(v353);
  v355 = **(_QWORD ***)v479;
  *(_BYTE *)(*(_QWORD *)v479 + 2711LL) = v356;
  wmi_unified_register_event_handler(
    v355,
    0x56u,
    (__int64)wma_stats_ext_event_handler,
    2u,
    sta_dynamic_dtim,
    v357,
    v358,
    v359,
    v360,
    v361,
    v362,
    v363);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0x6Cu,
    (__int64)wma_rssi_breached_event_handler,
    2u,
    v364,
    v365,
    v366,
    v367,
    v368,
    v369,
    v370,
    v371);
  _qdf_wake_lock_create((_QWORD *)(*(_QWORD *)v479 + 3128LL), (__int64)"wlan_fw_rsp_wakelock");
  _qdf_runtime_lock_init((__int64 *)(*(_QWORD *)v479 + 3328LL), "&wma_handle->wmi_cmd_rsp_runtime_lock");
  _qdf_runtime_lock_init((__int64 *)(*(_QWORD *)v479 + 3336LL), "&wma_handle->sap_prevent_runtime_pm_lock");
  _qdf_runtime_lock_init((__int64 *)(*(_QWORD *)v479 + 3344LL), "&wma_handle->ndp_prevent_runtime_pm_lock");
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0xAAu,
    (__int64)wma_peer_assoc_conf_handler,
    2u,
    v372,
    v373,
    v374,
    v375,
    v376,
    v377,
    v378,
    v379);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0xEDu,
    (__int64)wma_peer_create_confirm_handler,
    2u,
    v380,
    v381,
    v382,
    v383,
    v384,
    v385,
    v386,
    v387);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0x8Eu,
    (__int64)wma_peer_delete_handler,
    2u,
    v388,
    v389,
    v390,
    v391,
    v392,
    v393,
    v394,
    v395);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0xFu,
    (__int64)wma_chan_info_event_handler,
    2u,
    v396,
    v397,
    v398,
    v399,
    v400,
    v401,
    v402,
    v403);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0x6Bu,
    (__int64)wma_flush_complete_evt_handler,
    0,
    v404,
    v405,
    v406,
    v407,
    v408,
    v409,
    v410,
    v411);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0xAEu,
    (__int64)wma_rx_aggr_failure_event_handler,
    2u,
    v412,
    v413,
    v414,
    v415,
    v416,
    v417,
    v418,
    v419);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0xD9u,
    (__int64)wma_antenna_isolation_event_handler,
    2u,
    v420,
    v421,
    v422,
    v423,
    v424,
    v425,
    v426,
    v427);
  v428 = *(_QWORD *)(*(_QWORD *)v479 + 24LL);
  *(_BYTE *)(*(_QWORD *)v479 + 3951LL) = *((_BYTE *)a3 + 120);
  if ( (unsigned int)ucfg_pmo_get_auto_power_fail_mode(v428) == 1 )
    wmi_unified_register_event_handler(
      **(_QWORD ***)v479,
      0xAFu,
      (__int64)wma_chip_power_save_failure_detected_handler,
      0,
      v429,
      v430,
      v431,
      v432,
      v433,
      v434,
      v435,
      v436);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0xBDu,
    (__int64)wma_pdev_div_info_evt_handler,
    0,
    v429,
    v430,
    v431,
    v432,
    v433,
    v434,
    v435,
    v436);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0xE0u,
    (__int64)wma_get_ani_level_evt_handler,
    0,
    v437,
    v438,
    v439,
    v440,
    v441,
    v442,
    v443,
    v444);
  ((void (__fastcall *)(__int64, __int64 (__fastcall *)()))qdf_register_debug_callback)(54, wma_state_info_dump);
  wifi_pos_register_get_phy_mode_cb(*(_QWORD *)(*(_QWORD *)v479 + 24LL), wma_get_phy_mode_cb);
  wifi_pos_register_get_fw_phy_mode_for_freq_cb(*(_QWORD *)(*(_QWORD *)v479 + 24LL), wma_get_fw_phy_mode_for_freq_cb);
  pmo_register_pause_bitmap_notifier(*(_QWORD *)(*(_QWORD *)v479 + 24LL), wma_vdev_update_pause_bitmap_0);
  pmo_register_get_pause_bitmap(*(_QWORD *)(*(_QWORD *)v479 + 24LL), wma_vdev_get_pause_bitmap);
  pmo_register_is_device_in_low_pwr_mode(*(_QWORD *)(*(_QWORD *)v479 + 24LL), wma_vdev_is_device_in_low_pwr_mode);
  pmo_register_get_dtim_period_callback(*(_QWORD *)(*(_QWORD *)v479 + 24LL), wma_vdev_get_dtim_period);
  pmo_register_get_beacon_interval_callback(*(_QWORD *)(*(_QWORD *)v479 + 24LL), wma_vdev_get_beacon_interval);
  v445 = wma_register_nan_callbacks(*(_QWORD *)v479);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0x10u,
    (__int64)wma_unified_phyerr_rx_event_handler,
    0,
    v445,
    v446,
    v447,
    v448,
    v449,
    v450,
    v451,
    v452);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0xB9u,
    (__int64)wma_vdev_obss_detection_info_handler,
    2u,
    v453,
    v454,
    v455,
    v456,
    v457,
    v458,
    v459,
    v460);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0xBAu,
    (__int64)wma_vdev_bss_color_collision_info_handler,
    0,
    v461,
    v462,
    v463,
    v464,
    v465,
    v466,
    v467,
    v468);
  wma_register_twt_events(*(_QWORD *)v479);
  v469 = wma_register_apf_events(*(_QWORD *)v479);
  wmi_unified_register_event_handler(
    **(_QWORD ***)v479,
    0x106u,
    (__int64)wma_latency_level_event_handler,
    0,
    v469,
    v470,
    v471,
    v472,
    v473,
    v474,
    v475,
    v476);
  wma_register_mws_coex_events(*(_QWORD *)v479);
  qdf_trace_register(54, (__int64)wma_trace_dump);
  wma_set_exclude_selftx_from_cca_busy_time(*((unsigned __int8 *)a3 + 145), *(_QWORD *)v479);
  result = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
