__int64 __fastcall wlan_ipa_uc_disable_pipes(
        __int64 a1,
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
  __int64 v11; // x25
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w21
  unsigned int v29; // w22
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
  int v46; // w2
  int v47; // w3
  int v48; // w4
  int v49; // w5
  int v50; // w6
  int v51; // w7
  __int64 v52; // x0
  __int64 v53; // x8
  unsigned int (*v54)(void); // x8
  __int64 v55; // x0
  __int64 v56; // x8
  void (*v57)(void); // x8
  __int64 v58; // x0
  __int64 v59; // x8
  void (*v60)(void); // x8
  int v61; // w20
  int v62; // w28
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  int v71; // w3
  int v72; // w4
  int v73; // w5
  int v74; // w6
  int v75; // w7
  int v76; // w2
  int v77; // w3
  int v78; // w4
  int v79; // w5
  int v80; // w6
  int v81; // w7
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x0
  __int64 v91; // x8
  unsigned int (*v92)(void); // x8
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  __int64 v101; // x0
  __int64 v102; // x8
  void (*v103)(void); // x8
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  __int64 v112; // x0
  __int64 v113; // x8
  void (*v114)(void); // x8
  unsigned __int64 StatusReg; // x8
  __int64 v116; // x8
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  int v133; // w4
  int v134; // w5
  int v135; // w6
  int v136; // w7
  __int64 v138; // x8
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  __int64 v147; // x0
  __int64 v148; // x8
  void (*v149)(void); // x8
  __int64 v150; // x0
  __int64 v151; // x8
  __int64 (*v152)(void); // x8
  unsigned int v153; // w20
  unsigned int v154; // w21
  unsigned __int64 v155; // x8
  int v156; // w3
  int v157; // w4
  int v158; // w5
  int v159; // w6
  int v160; // w7
  __int64 v161; // x8
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  int v170; // w5
  int v171; // w6
  int v172; // w7
  char v173; // [xsp+0h] [xbp-10h]

  v11 = a1 + 4096;
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: enter: force_disable %u autonomy_disabled %u pipes_disabled %u",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_ipa_uc_disable_pipes",
    a2 & 1,
    *(unsigned int *)(a1 + 3432),
    *(unsigned int *)(a1 + 3436));
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp_ctrl, feature enable - %d, wlan_shutdown - %d, ssr - %d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wlan_ipa_uc_disable_pipes",
    *(unsigned __int8 *)(v11 + 3344),
    *(unsigned __int8 *)(v11 + 3368),
    *(unsigned __int8 *)(v11 + 3369));
  if ( *(_BYTE *)(v11 + 3344) == 1
    && *(_BYTE *)(v11 + 3368) == 1
    && (*(_BYTE *)(v11 + 3369) & 1) == 0
    && (*(_BYTE *)(v11 + 3370) & 1) == 0 )
  {
    qdf_event_reset(a1 + 7472);
    v28 = wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb(a1, 0, 1);
    v29 = qdf_wait_single_event(a1 + 7472, 0xC8u);
    *(_BYTE *)(v11 + 3370) = 1;
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: opt_dp_ctrl, return code of flt del by shutdown %d, status - %d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wlan_ipa_uc_disable_pipes",
      v28,
      v29);
    if ( v29 )
      v20 = wlan_ipa_ctrl_flt_db_deinit(a1, 204);
  }
  if ( ((cds_get_driver_state(v20, v21, v22, v23, v24, v25, v26, v27) & 4) != 0
     || (cds_get_driver_state(v38, v39, v40, v41, v42, v43, v44, v45) & 8) != 0)
    && ((*(_BYTE *)(v11 + 3342) & 1) != 0 || *(_BYTE *)(v11 + 3343) == 2) )
  {
    *(_BYTE *)(v11 + 3419) = 3;
    *(_WORD *)(v11 + 3342) = 768;
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: opt_dp: IPA notify filter rel_response as success in ssr/shutdown",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "wlan_ipa_release_cce_flt_ssr_shutdown");
    wlan_ipa_log_message(
      (int)"wlan_ipa_release_cce_flt_ssr_shutdown",
      (int)"opt_dp: IPA notify filter rel_response as success in ssr/shutdown",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v173);
    ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst(*(unsigned int *)(a1 + 7460), 1);
    v52 = *(_QWORD *)(a1 + 1456);
    if ( !v52 || !*(_QWORD *)v52 || (v53 = *(_QWORD *)(*(_QWORD *)v52 + 152LL)) == 0 )
    {
      qdf_trace_msg(0x45u, 1u, "%s invalid instance", v38, v39, v40, v41, v42, v43, v44, v45, "cdp_ipa_get_smmu_mapped");
      v55 = *(_QWORD *)(a1 + 1456);
      if ( !v55 )
        goto LABEL_27;
      goto LABEL_21;
    }
    v54 = *(unsigned int (**)(void))(v53 + 216);
    if ( v54 )
    {
      if ( *((_DWORD *)v54 - 1) != 639071501 )
        __break(0x8228u);
      if ( v54() )
      {
        v55 = *(_QWORD *)(a1 + 1456);
        if ( !v55 )
          goto LABEL_27;
LABEL_21:
        if ( *(_QWORD *)v55 )
        {
          v56 = *(_QWORD *)(*(_QWORD *)v55 + 152LL);
          if ( v56 )
          {
            v57 = *(void (**)(void))(v56 + 208);
            if ( v57 )
            {
              if ( *((_DWORD *)v57 - 1) != -1710392634 )
                __break(0x8228u);
              v57();
            }
            goto LABEL_28;
          }
        }
LABEL_27:
        qdf_trace_msg(
          0x45u,
          1u,
          "%s invalid instance",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "cdp_ipa_set_smmu_mapped");
LABEL_28:
        qdf_trace_msg(
          0x61u,
          4u,
          "%s: opt_dp: IPA smmu pool unmap",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "wlan_ipa_release_cce_flt_ssr_shutdown");
        v58 = *(_QWORD *)(a1 + 1456);
        if ( v58 && *(_QWORD *)v58 && (v59 = *(_QWORD *)(*(_QWORD *)v58 + 152LL)) != 0 )
        {
          v60 = *(void (**)(void))(v59 + 200);
          if ( v60 )
          {
            if ( *((_DWORD *)v60 - 1) != -712716066 )
              __break(0x8228u);
            v60();
          }
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            1u,
            "%s invalid instance",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "cdp_ipa_rx_buf_smmu_pool_mapping");
        }
      }
    }
  }
  if ( *(_BYTE *)(v11 + 3342) == 1 )
  {
    v61 = 0;
    do
    {
      v62 = v61;
      *(_BYTE *)(v11 + 3419) = 2;
      wlan_ipa_wdi_opt_dpath_flt_rsrv_rel_cb(a1);
      if ( v61 + 1 > 101 )
        ++v61;
      else
        v61 = 101;
      while ( *(_BYTE *)(v11 + 3342) == 1 )
      {
        qdf_sleep();
        if ( v61 == ++v62 )
        {
          qdf_trace_msg(
            0x61u,
            2u,
            "%s: opt_dp filter rel wait time exceed 1sec",
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            "wlan_ipa_uc_disable_pipes");
          goto LABEL_45;
        }
      }
      v61 = v62;
LABEL_45:
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: opt_dp: filter rel retry cnt: %d",
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        "wlan_ipa_uc_disable_pipes",
        *(unsigned __int8 *)(v11 + 3418));
      wlan_ipa_log_message(
        (int)"wlan_ipa_uc_disable_pipes",
        (int)"opt_dp: filter rel retry cnt: %d",
        *(unsigned __int8 *)(v11 + 3418),
        v71,
        v72,
        v73,
        v74,
        v75,
        v173);
    }
    while ( *(unsigned __int8 *)(v11 + 3418) <= 4u && *(_BYTE *)(v11 + 3342) == 1 && *(_BYTE *)(v11 + 3368) != 1 );
  }
  if ( *(_BYTE *)(v11 + 3368) != 1 || (*(_BYTE *)(v11 + 3342) & 1) == 0 && *(_BYTE *)(v11 + 3343) != 2 )
    goto LABEL_75;
  *(_BYTE *)(v11 + 3419) = 4;
  *(_WORD *)(v11 + 3342) = 768;
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: opt_dp: IPA notify filter rel_response as success in ssr/shutdown",
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    "wlan_ipa_release_cce_flt_ssr_shutdown");
  wlan_ipa_log_message(
    (int)"wlan_ipa_release_cce_flt_ssr_shutdown",
    (int)"opt_dp: IPA notify filter rel_response as success in ssr/shutdown",
    v76,
    v77,
    v78,
    v79,
    v80,
    v81,
    v173);
  ipa_wdi_opt_dpath_notify_flt_rlsd_per_inst(*(unsigned int *)(a1 + 7460), 1);
  v90 = *(_QWORD *)(a1 + 1456);
  if ( v90 && *(_QWORD *)v90 && (v91 = *(_QWORD *)(*(_QWORD *)v90 + 152LL)) != 0 )
  {
    v92 = *(unsigned int (**)(void))(v91 + 216);
    if ( !v92 )
      goto LABEL_75;
    if ( *((_DWORD *)v92 - 1) != 639071501 )
      __break(0x8228u);
    if ( !v92() )
      goto LABEL_75;
    v101 = *(_QWORD *)(a1 + 1456);
    if ( !v101 )
      goto LABEL_67;
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v82, v83, v84, v85, v86, v87, v88, v89, "cdp_ipa_get_smmu_mapped");
    v101 = *(_QWORD *)(a1 + 1456);
    if ( !v101 )
      goto LABEL_67;
  }
  if ( *(_QWORD *)v101 )
  {
    v102 = *(_QWORD *)(*(_QWORD *)v101 + 152LL);
    if ( v102 )
    {
      v103 = *(void (**)(void))(v102 + 208);
      if ( v103 )
      {
        if ( *((_DWORD *)v103 - 1) != -1710392634 )
          __break(0x8228u);
        v103();
      }
      goto LABEL_68;
    }
  }
LABEL_67:
  qdf_trace_msg(0x45u, 1u, "%s invalid instance", v93, v94, v95, v96, v97, v98, v99, v100, "cdp_ipa_set_smmu_mapped");
LABEL_68:
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: opt_dp: IPA smmu pool unmap",
    v93,
    v94,
    v95,
    v96,
    v97,
    v98,
    v99,
    v100,
    "wlan_ipa_release_cce_flt_ssr_shutdown");
  v112 = *(_QWORD *)(a1 + 1456);
  if ( !v112 || !*(_QWORD *)v112 || (v113 = *(_QWORD *)(*(_QWORD *)v112 + 152LL)) == 0 )
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      "cdp_ipa_rx_buf_smmu_pool_mapping");
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
      goto LABEL_76;
LABEL_80:
    raw_spin_lock(a1 + 3400);
    goto LABEL_81;
  }
  v114 = *(void (**)(void))(v113 + 200);
  if ( v114 )
  {
    if ( *((_DWORD *)v114 - 1) != -712716066 )
      __break(0x8228u);
    v114();
  }
LABEL_75:
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
    goto LABEL_80;
LABEL_76:
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    goto LABEL_80;
  raw_spin_lock_bh(a1 + 3400);
  *(_QWORD *)(a1 + 3408) |= 1uLL;
LABEL_81:
  if ( (*(_BYTE *)(a1 + 3440) & 1) != 0 || *(_BYTE *)(a1 + 3441) == 1 )
  {
    v116 = *(_QWORD *)(a1 + 3408);
    if ( (v116 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 3408) = v116 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 3400);
    }
    else
    {
      raw_spin_unlock(a1 + 3400);
    }
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: IPA WDI Pipes are already deactivated",
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      "wlan_ipa_uc_disable_pipes");
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: pipes_down %d, pipes_down_in_progress %d",
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      v131,
      v132,
      "wlan_ipa_uc_disable_pipes",
      *(unsigned __int8 *)(a1 + 3440),
      *(unsigned __int8 *)(a1 + 3441));
    wlan_ipa_log_message(
      (int)"wlan_ipa_uc_disable_pipes",
      (int)"pipes_down %d, pipes_down_in_progress %d",
      *(unsigned __int8 *)(a1 + 3440),
      *(unsigned __int8 *)(a1 + 3441),
      v133,
      v134,
      v135,
      v136,
      v173);
    return 6;
  }
  v138 = *(_QWORD *)(a1 + 3408);
  *(_BYTE *)(a1 + 3441) = 1;
  if ( (v138 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 3408) = v138 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 3400);
    if ( *(_DWORD *)(a1 + 3432) )
    {
LABEL_88:
      if ( *(_DWORD *)(a1 + 3436) )
        goto LABEL_111;
      goto LABEL_101;
    }
  }
  else
  {
    raw_spin_unlock(a1 + 3400);
    if ( *(_DWORD *)(a1 + 3432) )
      goto LABEL_88;
  }
  v147 = *(_QWORD *)(a1 + 1456);
  if ( v147 && *(_QWORD *)v147 && (v148 = *(_QWORD *)(*(_QWORD *)v147 + 152LL)) != 0 )
  {
    v149 = *(void (**)(void))(v148 + 112);
    if ( v149 )
    {
      if ( *((_DWORD *)v149 - 1) != 261447488 )
        __break(0x8228u);
      v149();
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v139,
      v140,
      v141,
      v142,
      v143,
      v144,
      v145,
      v146,
      "cdp_ipa_disable_autonomy");
  }
  *(_DWORD *)(a1 + 3432) = 1;
  if ( *(_DWORD *)(a1 + 3436) )
  {
LABEL_111:
    v154 = 0;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      goto LABEL_117;
    goto LABEL_112;
  }
LABEL_101:
  if ( (a2 & 1) == 0 )
  {
    *(_QWORD *)(a1 + 3424) = jiffies;
    *(_DWORD *)(a1 + 3416) = 1;
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: done. pending_tx_start_ticks %llu wait_on_pending %u",
      v139,
      v140,
      v141,
      v142,
      v143,
      v144,
      v145,
      v146,
      "wlan_ipa_set_pending_tx_timer");
    goto LABEL_111;
  }
  v150 = *(_QWORD *)(a1 + 1456);
  if ( v150 && *(_QWORD *)v150 && (v151 = *(_QWORD *)(*(_QWORD *)v150 + 152LL)) != 0 )
  {
    v152 = *(__int64 (**)(void))(v151 + 160);
    if ( !v152 )
      goto LABEL_109;
    if ( *((_DWORD *)v152 - 1) != 1755644319 )
      __break(0x8228u);
    v153 = v152();
    if ( !v153 )
    {
LABEL_109:
      *(_DWORD *)(a1 + 3436) = 1;
      *(_QWORD *)(a1 + 3424) = 0;
      *(_DWORD *)(a1 + 3416) = 0;
      qdf_trace_msg(
        0x61u,
        4u,
        "%s: done",
        v139,
        v140,
        v141,
        v142,
        v143,
        v144,
        v145,
        v146,
        "wlan_ipa_reset_pending_tx_timer");
      goto LABEL_111;
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v139,
      v140,
      v141,
      v142,
      v143,
      v144,
      v145,
      v146,
      "cdp_ipa_disable_pipes");
    v153 = 16;
  }
  qdf_trace_msg(
    0x61u,
    2u,
    "%s: Disable IPA WDI PIPE failed: ret=%u",
    v139,
    v140,
    v141,
    v142,
    v143,
    v144,
    v145,
    v146,
    "wlan_ipa_uc_disable_pipes",
    v153);
  wlan_ipa_log_message(
    (int)"wlan_ipa_uc_disable_pipes",
    (int)"Disable IPA WDI PIPE failed: ret=%u",
    v153,
    v156,
    v157,
    v158,
    v159,
    v160,
    v173);
  v154 = 16;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
    goto LABEL_117;
LABEL_112:
  v155 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v155 + 16) & 0xF0000) == 0 && (*(_DWORD *)(v155 + 16) & 0xFF00) == 0 )
  {
    raw_spin_lock_bh(a1 + 3400);
    *(_QWORD *)(a1 + 3408) |= 1uLL;
    goto LABEL_118;
  }
LABEL_117:
  raw_spin_lock(a1 + 3400);
LABEL_118:
  if ( *(_DWORD *)(a1 + 3436) && *(_DWORD *)(a1 + 3432) )
    *(_BYTE *)(a1 + 3440) = 1;
  v161 = *(_QWORD *)(a1 + 3408);
  *(_BYTE *)(a1 + 3441) = 0;
  if ( (v161 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 3408) = v161 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 3400);
  }
  else
  {
    raw_spin_unlock(a1 + 3400);
  }
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: exit: ipa_pipes_down %u autonomy_disabled %u pipes_disabled %u",
    v162,
    v163,
    v164,
    v165,
    v166,
    v167,
    v168,
    v169,
    "wlan_ipa_uc_disable_pipes",
    *(unsigned __int8 *)(a1 + 3440),
    *(unsigned int *)(a1 + 3432),
    *(unsigned int *)(a1 + 3436));
  wlan_ipa_log_message(
    (int)"wlan_ipa_uc_disable_pipes",
    (int)"exit: ipa_pipes_down %u autonomy_disabled %u pipes_disabled %u",
    *(unsigned __int8 *)(a1 + 3440),
    *(_DWORD *)(a1 + 3432),
    *(_DWORD *)(a1 + 3436),
    v170,
    v171,
    v172,
    v173);
  return v154;
}
