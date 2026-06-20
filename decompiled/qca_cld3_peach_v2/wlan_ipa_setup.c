__int64 __fastcall wlan_ipa_setup(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 (*v23)(void); // x8
  char v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x0
  __int64 v34; // x8
  void (*v35)(void); // x8
  int v36; // w8
  int v37; // w9
  unsigned int inited; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  int v47; // w20
  int v48; // w3
  int v49; // w4
  int v50; // w5
  int v51; // w6
  int v52; // w7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w20
  int v62; // w3
  int v63; // w4
  int v64; // w5
  int v65; // w6
  int v66; // w7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  const char *v75; // x20
  unsigned int v76; // w19
  const char *v77; // x2
  char v78; // w5
  int v79; // w6
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 v88; // x0
  __int64 values; // x0
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  char v98; // w4
  int v99; // w8
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  int v108; // w3
  int v109; // w4
  int v110; // w5
  int v111; // w6
  int v112; // w7
  unsigned int v113; // w0
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  int v122; // w2
  int v123; // w3
  int v124; // w4
  int v125; // w5
  int v126; // w6
  int v127; // w7
  __int64 v128; // x0
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  int v137; // w8
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  unsigned int v146; // w20
  __int64 v147; // x22
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  int v156; // w2
  int v157; // w3
  int v158; // w4
  int v159; // w5
  int v160; // w6
  int v161; // w7
  const char *v162; // x1
  __int64 (__fastcall *v163)(); // x5
  void *v164; // x6
  __int64 (__fastcall *v165)(); // x7
  unsigned int v166; // w0
  __int64 v167; // x4
  char v168; // w0
  int v169; // w2
  int v170; // w3
  int v171; // w4
  int v172; // w5
  int v173; // w6
  int v174; // w7
  char v176[8]; // [xsp+0h] [xbp-40h] BYREF
  int v177; // [xsp+8h] [xbp-38h]
  __int64 v178; // [xsp+10h] [xbp-30h] BYREF
  __int64 (__fastcall *v179)(); // [xsp+18h] [xbp-28h]
  __int64 v180; // [xsp+20h] [xbp-20h]
  __int64 v181; // [xsp+28h] [xbp-18h]
  __int64 v182; // [xsp+30h] [xbp-10h]
  __int64 v183; // [xsp+38h] [xbp-8h]

  v12 = a1 + 6984;
  v183 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x61u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_ipa_setup");
  *(_DWORD *)(a1 + 7432) = 3;
  *(_BYTE *)(a1 + 1448) = 0;
  *(_QWORD *)(a1 + 1072) = 0xA0000000DLL;
  gp_ipa = a1;
  *(_QWORD *)(a1 + 1464) = a2;
  *(_QWORD *)(a1 + 1064) = a1;
  *(_BYTE *)(a1 + 1080) = 0;
  *(_QWORD *)(a1 + 1088) = 0;
  *(_DWORD *)(a1 + 1096) = 17;
  *(_BYTE *)(a1 + 1116) = 5;
  *(_DWORD *)(a1 + 1108) = 0;
  *(_DWORD *)(a1 + 1112) = 0;
  *(_QWORD *)(a1 + 1200) = 0xA0000000FLL;
  *(_BYTE *)(a1 + 1208) = 1;
  *(_DWORD *)(a1 + 1120) = 0;
  *(_QWORD *)(a1 + 1128) = 0;
  *(_QWORD *)(a1 + 1192) = a1;
  *(_QWORD *)(a1 + 1216) = 0;
  *(_DWORD *)(a1 + 1224) = 17;
  *(_BYTE *)(a1 + 1244) = 5;
  *(_DWORD *)(a1 + 1236) = 0;
  *(_DWORD *)(a1 + 1240) = 0;
  *(_QWORD *)(a1 + 1328) = 0xA00000011LL;
  *(_DWORD *)(a1 + 1352) = 17;
  *(_DWORD *)(a1 + 1248) = 0;
  *(_QWORD *)(a1 + 1256) = 0;
  *(_QWORD *)(a1 + 1320) = a1;
  *(_BYTE *)(a1 + 1336) = 2;
  *(_QWORD *)(a1 + 1344) = 0;
  *(_BYTE *)(a1 + 1372) = 5;
  *(_DWORD *)(a1 + 1364) = 0;
  *(_DWORD *)(a1 + 1368) = 0;
  *(_QWORD *)(a1 + 3344) = wlan_ipa_pm_flush;
  *(_QWORD *)(a1 + 3312) = 0xFFFFFFFE00000LL;
  *(_DWORD *)(a1 + 1376) = 0;
  *(_QWORD *)(a1 + 1384) = 0;
  *(_QWORD *)(a1 + 3352) = a1;
  *(_QWORD *)(a1 + 3320) = a1 + 3320;
  *(_QWORD *)(a1 + 3328) = a1 + 3320;
  v21 = *(_QWORD *)(a1 + 1456);
  *(_QWORD *)(a1 + 3336) = _qdf_defer_func;
  *(_DWORD *)(a1 + 3360) = 0;
  *(_QWORD *)(a1 + 3368) = 0;
  *(_DWORD *)(a1 + 3384) = 0;
  *(_QWORD *)(a1 + 3392) = 0;
  *(_DWORD *)(a1 + 3400) = 0;
  *(_QWORD *)(a1 + 3408) = 0;
  *(_WORD *)(a1 + 3441) = 0;
  *(_WORD *)(v12 + 480) = 0;
  *(_BYTE *)(v12 + 456) = 0;
  *(_BYTE *)(v12 + 482) = 0;
  if ( !v21 || !*(_QWORD *)v21 || (v22 = *(_QWORD *)(*(_QWORD *)v21 + 152LL)) == 0 )
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "cdp_ipa_opt_dp_ctrl_debug_enable");
    goto LABEL_9;
  }
  if ( !*(_QWORD *)(v22 + 240) )
  {
LABEL_9:
    v24 = 0;
    goto LABEL_10;
  }
  v23 = *(__int64 (**)(void))(v22 + 248);
  if ( *((_DWORD *)v23 - 1) != 944657148 )
    __break(0x8228u);
  v24 = v23();
LABEL_10:
  *(_BYTE *)(v12 + 528) = v24 & 1;
  *(_BYTE *)(v12 + 529) = 1;
  *(_QWORD *)(a1 + 3288) = 0;
  *(_QWORD *)(a1 + 3296) = 0;
  *(_QWORD *)(a1 + 3304) = 0;
  *(_QWORD *)(a1 + 4016) = a1 + 4016;
  *(_QWORD *)(a1 + 4024) = a1 + 4016;
  *(_QWORD *)(a1 + 4032) = 0x3E800000000LL;
  qdf_mutex_create(a1 + 4040);
  qdf_mutex_create(a1 + 7224);
  *(_DWORD *)(a1 + 7452) = 0;
  v33 = *(_QWORD *)(a1 + 1456);
  if ( v33 && *(_QWORD *)v33 && (v34 = *(_QWORD *)(*(_QWORD *)v33 + 152LL)) != 0 )
  {
    v35 = *(void (**)(void))(v34 + 208);
    if ( v35 )
    {
      if ( *((_DWORD *)v35 - 1) != -1710392634 )
        __break(0x8228u);
      v35();
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v25, v26, v27, v28, v29, v30, v31, v32, "cdp_ipa_set_smmu_mapped");
  }
  qdf_mem_set((void *)(a1 + 8), 0x108u, 0);
  qdf_mem_set((void *)(a1 + 272), 0x108u, 0);
  qdf_mem_set((void *)(a1 + 536), 0x108u, 0);
  qdf_mem_set((void *)(a1 + 800), 0x108u, 0);
  if ( (**(_BYTE **)(a1 + 1464) & 0x20) == 0 )
  {
    if ( !(unsigned int)wlan_ipa_setup_sys_pipe(a1) )
    {
LABEL_38:
      *(_BYTE *)(v12 + 529) = 2;
      qdf_event_create((_DWORD *)(a1 + 7800));
      *(_BYTE *)(v12 + 813) = 0;
      qdf_event_create((_DWORD *)(a1 + 7904));
      *(_BYTE *)(v12 + 917) = 0;
      qdf_event_create((_DWORD *)(a1 + 8008));
      *(_BYTE *)(v12 + 1021) = 0;
      qdf_event_create((_DWORD *)(a1 + 8152));
      qdf_event_create((_DWORD *)(a1 + 8112));
      v128 = qdf_event_create((_DWORD *)(a1 + 7472));
      v137 = *(unsigned __int8 *)(v12 + 453);
      *(_DWORD *)(a1 + 8056) = 0;
      *(_QWORD *)(a1 + 8064) = 0;
      if ( v137 == 1 )
      {
        if ( (wlan_ipa_config_is_opt_wifi_dp_enabled(v128) & 1) != 0 )
        {
          v146 = *(_DWORD *)(a1 + 7460);
          v147 = gp_ipa + 4096;
          if ( *(_BYTE *)(gp_ipa + 7512) == 1 )
          {
            qdf_trace_msg(
              0x61u,
              8u,
              "%s: opt_dp_ctrl, ipa debug enabled for unit testing",
              v138,
              v139,
              v140,
              v141,
              v142,
              v143,
              v144,
              v145,
              "__wlan_ipa_reg_flt_cbs");
            ipa_wdi_opt_dpath_register_flt_cb_per_inst(
              v146,
              wlan_ipa_wdi_opt_dpath_flt_rsrv_cb,
              &wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb_wrapper,
              wlan_ipa_wdi_opt_dpath_flt_add_cb,
              &wlan_ipa_wdi_opt_dpath_flt_rem_cb);
          }
          else
          {
            if ( *(_BYTE *)(gp_ipa + 7441) )
              v163 = wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb;
            else
              v163 = nullptr;
            if ( *(_BYTE *)(gp_ipa + 7441) )
              v164 = &wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb_wrapper;
            else
              v164 = nullptr;
            if ( *(_BYTE *)(gp_ipa + 7441) )
              v165 = wlan_ipa_wdi_opt_dpath_clk_status_cb;
            else
              v165 = nullptr;
            v166 = ipa_wdi_opt_dpath_register_flt_cb_per_inst_v2(
                     v146,
                     wlan_ipa_wdi_opt_dpath_flt_rsrv_cb,
                     &wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb_wrapper,
                     wlan_ipa_wdi_opt_dpath_flt_add_cb,
                     &wlan_ipa_wdi_opt_dpath_flt_rem_cb,
                     v163,
                     v164,
                     v165);
            v167 = v166;
            if ( v166 )
              goto LABEL_56;
          }
          v167 = 0;
          *(_BYTE *)(v147 + 3344) = 1;
LABEL_56:
          qdf_trace_msg(
            0x61u,
            8u,
            "%s: opt_dp: Register flt cb. status %d",
            v148,
            v149,
            v150,
            v151,
            v152,
            v153,
            v154,
            v155,
            "wlan_ipa_opt_dp_init",
            v167);
          _qdf_wake_lock_create((_QWORD *)(a1 + 0x2000), (__int64)"opt_dp");
          *(_WORD *)(v12 + 454) = 256;
          *(_WORD *)(v12 + 530) = 0;
          _qdf_runtime_lock_init((__int64 *)(a1 + 8432), "&ipa_ctx->opt_dp_runtime_lock");
          qdf_rtpm_register(3u, 0);
          goto LABEL_57;
        }
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp: Disabled from WLAN INI",
          v138,
          v139,
          v140,
          v141,
          v142,
          v143,
          v144,
          v145,
          "wlan_ipa_opt_dp_init");
        v162 = "opt_dp: Disabled from WLAN INI";
      }
      else
      {
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp: Disabled from IPA",
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          "wlan_ipa_opt_dp_init");
        v162 = "opt_dp: Disabled from IPA";
      }
      wlan_ipa_log_message((int)"wlan_ipa_opt_dp_init", (int)v162, v156, v157, v158, v159, v160, v161, v176[0]);
LABEL_57:
      qdf_event_create((_DWORD *)(a1 + 7392));
      v168 = wlan_ipa_set_perf_level_bw_enabled(a1);
      v76 = 0;
      v75 = "exit: success";
      if ( (v168 & 1) != 0 )
        *(_BYTE *)(v12 + 464) = 3;
      v77 = "%s: exit: success";
      goto LABEL_60;
    }
    goto LABEL_24;
  }
  qdf_mem_set((void *)(a1 + 3496), 0xC8u, 0);
  *(_DWORD *)(a1 + 3705) = 0;
  *(_WORD *)(a1 + 3709) = 0;
  *(_WORD *)(a1 + 3720) = 0;
  *(_QWORD *)(a1 + 4104) = 0;
  *(_QWORD *)(a1 + 4112) = 0;
  *(_BYTE *)(a1 + 3440) = 1;
  *(_DWORD *)(a1 + 3436) = 1;
  *(_DWORD *)(a1 + 3432) = 1;
  *(_WORD *)v12 = 0;
  *(_BYTE *)(v12 + 1456) = 0;
  v181 = 0;
  v182 = 0;
  v179 = nullptr;
  v180 = 0;
  v178 = 0;
  v177 = 0;
  *(_QWORD *)v176 = 0;
  qdf_mem_set(&v178, 0x28u, 0);
  qdf_mem_set(v176, 0xCu, 0);
  v36 = *(_DWORD *)(a1 + 7432);
  v179 = wlan_ipa_uc_loaded_uc_cb;
  v180 = a1;
  v37 = *(unsigned __int8 *)(v12 + 472);
  LODWORD(v178) = v36;
  LODWORD(v182) = v37;
  inited = ipa_wdi_init_per_inst(&v178, v176);
  if ( inited )
  {
    v47 = inited;
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: ipa_wdi_init failed with ret=%d",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "wlan_ipa_wdi_init",
      inited);
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_init",
      (int)"ipa_wdi_init failed with ret=%d",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v176[0]);
    v61 = 16;
LABEL_23:
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: IPA WDI init failed: ret=%d",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "wlan_ipa_setup",
      v61);
    wlan_ipa_log_message(
      (int)"wlan_ipa_setup",
      (int)"IPA WDI init failed: ret=%d",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v176[0]);
    goto LABEL_24;
  }
  v78 = v176[1];
  v79 = *(_DWORD *)&v176[4];
  *(_BYTE *)(v12 + 2) = v176[2];
  *(_BYTE *)(v12 + 452) = v78;
  *(_DWORD *)(a1 + 7460) = v79;
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: ipa_over_gsi: %d, is_smmu_enabled: %d, handle: %d",
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    "wlan_ipa_wdi_init");
  if ( v176[0] != 1 )
  {
    qdf_trace_msg(0x61u, 2u, "%s: IPA uc not ready", v80, v81, v82, v83, v84, v85, v86, v87, "wlan_ipa_wdi_init");
    wlan_ipa_log_message((int)"wlan_ipa_wdi_init", (int)"IPA uc not ready", v122, v123, v124, v125, v126, v127, v176[0]);
    goto LABEL_38;
  }
  qdf_trace_msg(0x61u, 8u, "%s: IPA uC READY", v80, v81, v82, v83, v84, v85, v86, v87, "wlan_ipa_wdi_init");
  v88 = *(_QWORD *)a1;
  *(_BYTE *)v12 = 1;
  values = cfg_psoc_get_values(v88);
  v98 = v177;
  v99 = *(_DWORD *)(values + 1112);
  *(_BYTE *)(v12 + 453) = v177;
  if ( (v98 & 1) == 0 && (v99 & 1) == 0 && **(_DWORD **)(a1 + 1464) == 637 )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s:  opt_wifi_datapath not support by IPA",
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      "wlan_ipa_wdi_init_set_opt_wifi_dp");
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: opt_dp: disabled from IPA, status - %d",
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      "wlan_ipa_wdi_init",
      *(unsigned __int8 *)(v12 + 453));
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_init",
      (int)"opt_dp: disabled from IPA, status - %d",
      *(unsigned __int8 *)(v12 + 453),
      v108,
      v109,
      v110,
      v111,
      v112,
      v176[0]);
    v113 = ipa_wdi_cleanup_per_inst(*(unsigned int *)(a1 + 7460));
    if ( v113 )
      qdf_trace_msg(
        0x61u,
        4u,
        "%s: ipa_wdi_cleanup failed ret=%d",
        v114,
        v115,
        v116,
        v117,
        v118,
        v119,
        v120,
        v121,
        "wlan_ipa_wdi_init",
        v113);
    ipa_set_cap_offload(0);
    v61 = 4;
    goto LABEL_23;
  }
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp: enabled from IPA : %d",
    v90,
    v91,
    v92,
    v93,
    v94,
    v95,
    v96,
    v97,
    "wlan_ipa_wdi_init",
    *(_QWORD *)v176);
  if ( (**(_BYTE **)(a1 + 1464) & 0x40) == 0 )
    goto LABEL_38;
  if ( !(unsigned int)wlan_ipa_setup_sys_pipe(a1) )
  {
    *(_QWORD *)(a1 + 7336) = wlan_ipa_mcc_work_handler;
    *(_QWORD *)(a1 + 7304) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(a1 + 7344) = a1;
    *(_QWORD *)(a1 + 7312) = a1 + 7312;
    *(_QWORD *)(a1 + 7320) = a1 + 7312;
    *(_QWORD *)(a1 + 7328) = _qdf_defer_func;
    goto LABEL_38;
  }
LABEL_24:
  qdf_mutex_destroy(a1 + 4040);
  qdf_mutex_destroy(a1 + 7224);
  if ( *(_DWORD *)(a1 + 4032) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: list length not equal to zero",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      "qdf_list_destroy");
  gp_ipa = 0;
  v75 = "exit: fail";
  v76 = 16;
  v77 = "%s: exit: fail";
LABEL_60:
  qdf_trace_msg(0x61u, 8u, v77, v67, v68, v69, v70, v71, v72, v73, v74, "wlan_ipa_setup");
  wlan_ipa_log_message((int)"wlan_ipa_setup", (int)v75, v169, v170, v171, v172, v173, v174, v176[0]);
  _ReadStatusReg(SP_EL0);
  return v76;
}
