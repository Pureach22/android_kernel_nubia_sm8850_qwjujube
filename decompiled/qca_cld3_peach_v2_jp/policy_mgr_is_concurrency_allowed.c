__int64 __fastcall policy_mgr_is_concurrency_allowed(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        unsigned int a5,
        __int64 a6)
{
  __int64 context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _BOOL4 v31; // w27
  __int64 v32; // x28
  int v33; // w26
  __int64 v34; // x0
  __int64 v35; // x20
  __int64 result; // x0
  const char *v37; // x2
  const char *v38; // x3
  _BYTE *v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int ch_width; // w0
  __int64 v57; // x8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  _BOOL4 v66; // w25
  __int64 v67; // x20
  bool is_sta_sap_scc_allowed_on_dfs_chan; // w24
  int v69; // w0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // x20
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  __int64 v95; // x20
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  _BOOL4 v105; // w8
  int v106; // w24
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  __int64 v115; // x20
  __int64 v116; // x20
  int v117; // w0
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  __int64 v126; // x8
  __int64 v127; // x0
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  __int64 v136; // x20
  __int64 v137; // x20
  __int64 v138; // x20
  __int64 v139; // x24
  __int64 v140; // x8
  __int64 v141; // x8
  __int64 v142; // x0
  __int64 v143; // x0
  __int64 v144; // x24
  int v145; // w25
  int v146; // w26
  const char *v147; // x2
  __int64 v148; // x20
  __int64 v149; // x8
  __int64 v150; // x8
  __int64 v151; // x9
  __int64 v152; // [xsp+0h] [xbp-30h] BYREF
  __int64 v153; // [xsp+8h] [xbp-28h]
  __int64 v154; // [xsp+10h] [xbp-20h] BYREF
  __int64 v155; // [xsp+18h] [xbp-18h]
  unsigned int v156; // [xsp+20h] [xbp-10h]
  __int64 v157; // [xsp+28h] [xbp-8h]

  v157 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v156 = 0;
  v154 = 0;
  v155 = 0;
  v152 = 0;
  v153 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v37 = "%s: Invalid Context";
LABEL_9:
    qdf_trace_msg(0x4Fu, 2u, v37, v13, v14, v15, v16, v17, v18, v19, v20, "policy_mgr_is_concurrency_allowed", v152);
    goto LABEL_88;
  }
  v21 = context;
  v22 = policy_mgr_get_context(a1);
  v31 = v22 != 0;
  if ( !v22 )
  {
    v33 = 0;
    v38 = "policy_mgr_get_connection_count";
LABEL_13:
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v23, v24, v25, v26, v27, v28, v29, v30, v38, v152, v153);
    goto LABEL_14;
  }
  v32 = v22;
  qdf_mutex_acquire(v22 + 56);
  v33 = BYTE4(qword_81C47C) + BYTE4(qword_81C458) + BYTE4(qword_81C4A0) + BYTE4(qword_81C4C4) + BYTE4(qword_81C4E8);
  qdf_mutex_release(v32 + 56);
  if ( !v33 )
  {
    v31 = 0;
    goto LABEL_14;
  }
  v34 = policy_mgr_get_context(a1);
  if ( !v34 )
  {
    v38 = "policy_mgr_is_sub_20_mhz_enabled";
    goto LABEL_13;
  }
  if ( *(_BYTE *)(v34 + 1673) == 1 )
  {
    v35 = jiffies;
    if ( policy_mgr_is_concurrency_allowed___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: dont allow concurrency if Sub 20 MHz is enabled",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "policy_mgr_is_concurrency_allowed",
        v152,
        v153);
      result = 0;
      policy_mgr_is_concurrency_allowed___last_ticks = v35;
      goto LABEL_89;
    }
LABEL_88:
    result = 0;
    goto LABEL_89;
  }
  v31 = 1;
LABEL_14:
  v39 = (_BYTE *)policy_mgr_get_context(a1);
  if ( v39
    && (unsigned __int8)v39[2202] <= (unsigned int)(unsigned __int8)(v39[990]
                                                                   + v39[989]
                                                                   + v39[991]
                                                                   + v39[992]
                                                                   + v39[993]
                                                                   + v39[994]
                                                                   + v39[995]
                                                                   + v39[996]
                                                                   + v39[997]
                                                                   + v39[998]
                                                                   + v39[999]
                                                                   + v39[1000]
                                                                   + v39[1001]
                                                                   + v39[1002]
                                                                   + v39[1003]
                                                                   + v39[1004]) )
  {
    v67 = jiffies;
    if ( policy_mgr_is_concurrency_allowed___last_ticks_90 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Reached max concurrent connections: %d",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "policy_mgr_is_concurrency_allowed",
        *(unsigned __int8 *)(v21 + 2202));
      policy_mgr_is_concurrency_allowed___last_ticks_90 = v67;
    }
    policy_mgr_validate_conn_info(a1);
    goto LABEL_88;
  }
  if ( !a3 )
    goto LABEL_42;
  if ( wlan_reg_is_5ghz_ch_freq(a3) )
  {
    qdf_mem_set(&v152, 0x10u, 0);
    ch_width = policy_mgr_get_ch_width(a4, v48, v49, v50, v51, v52, v53, v54, v55);
    v57 = *(_QWORD *)(v21 + 8);
    LODWORD(v152) = ch_width;
    v66 = wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
            v57,
            a3,
            (unsigned int *)&v152,
            0,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65) == 2;
  }
  else
  {
    v66 = 0;
  }
  if ( (policy_mgr_allow_new_home_channel(a1, a2, a3, v33, v66, a5) & 1) == 0
    || (policy_mgr_is_5g_channel_allowed(a1, a3, &v154, 3u) & 1) == 0
    || (policy_mgr_is_5g_channel_allowed(a1, a3, &v154, 1u) & 1) == 0
    || (policy_mgr_is_6g_channel_allowed(a1, a2, a3) & 1) == 0 )
  {
    goto LABEL_88;
  }
  is_sta_sap_scc_allowed_on_dfs_chan = policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(a1);
  v69 = policy_mgr_go_scc_enforced(a1);
  if ( (a2 | 2) == 3 )
  {
    if ( is_sta_sap_scc_allowed_on_dfs_chan )
    {
      if ( (((a2 != 3) | v69) & (unsigned int)policy_mgr_is_sta_sap_scc(a1, a3, 0) & 1) != 0 || !v66 )
        goto LABEL_37;
    }
    else if ( !v66 )
    {
      goto LABEL_37;
    }
    if ( (policy_mgr_disallow_mcc(a1, a3) & 1) != 0 )
    {
      v78 = jiffies;
      if ( policy_mgr_is_concurrency_allowed___last_ticks_92 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: No MCC, SAP/GO about to come up on DFS channel",
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          "policy_mgr_is_concurrency_allowed");
        result = 0;
        policy_mgr_is_concurrency_allowed___last_ticks_92 = v78;
        goto LABEL_89;
      }
      goto LABEL_88;
    }
  }
LABEL_37:
  if ( (v31 & ((unsigned int)policy_mgr_is_hw_dbs_capable(a1) ^ 1)) == 1
    && wlan_reg_is_24ghz_ch_freq(a3)
    && (policy_mgr_is_sap_p2pgo_on_dfs(a1, v79, v80, v81, v82, v83, v84, v85, v86) & 1) != 0 )
  {
    v95 = jiffies;
    if ( policy_mgr_is_concurrency_allowed___last_ticks_94 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: MCC not allowed: SAP/P2PGO on DFS",
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        "policy_mgr_is_concurrency_allowed");
      result = 0;
      policy_mgr_is_concurrency_allowed___last_ticks_94 = v95;
      goto LABEL_89;
    }
    goto LABEL_88;
  }
LABEL_42:
  if ( !a2 )
  {
    v117 = policy_mgr_mode_specific_connection_count(a1, 0, nullptr);
    if ( v117 )
    {
      if ( v117 != 1 )
      {
        v137 = jiffies;
        if ( policy_mgr_allow_sta_concurrency___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: Disallow 3rd STA",
            v118,
            v119,
            v120,
            v121,
            v122,
            v123,
            v124,
            v125,
            "policy_mgr_allow_sta_concurrency");
          result = 0;
          policy_mgr_allow_sta_concurrency___last_ticks = v137;
          goto LABEL_89;
        }
        goto LABEL_88;
      }
      if ( !a1 || (v126 = *(_QWORD *)(a1 + 2800)) == 0 || (v127 = *(_QWORD *)(v126 + 16)) == 0 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: Invalid WMI handle",
          v118,
          v119,
          v120,
          v121,
          v122,
          v123,
          v124,
          v125,
          "policy_mgr_allow_multiple_sta_connections",
          v152);
        goto LABEL_71;
      }
      if ( (wmi_service_enabled(v127, 0xABu, v118, v119, v120, v121, v122, v123, v124, v125) & 1) == 0 )
      {
        v136 = jiffies;
        if ( policy_mgr_allow_multiple_sta_connections___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: STA+STA is not supported",
            v128,
            v129,
            v130,
            v131,
            v132,
            v133,
            v134,
            v135,
            "policy_mgr_allow_multiple_sta_connections");
          policy_mgr_allow_multiple_sta_connections___last_ticks = v136;
        }
LABEL_71:
        v138 = jiffies;
        if ( policy_mgr_allow_sta_concurrency___last_ticks_246 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: Multiple STA connections is not allowed",
            v128,
            v129,
            v130,
            v131,
            v132,
            v133,
            v134,
            v135,
            "policy_mgr_allow_sta_concurrency");
          result = 0;
          policy_mgr_allow_sta_concurrency___last_ticks_246 = v138;
          goto LABEL_89;
        }
        goto LABEL_88;
      }
    }
  }
  if ( (policy_mgr_allow_sap_go_concurrency(a1, a2, a3, 255) & 1) == 0 )
  {
    v116 = jiffies;
    if ( policy_mgr_is_concurrency_allowed___last_ticks_96 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: This concurrency combination is not allowed",
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        "policy_mgr_is_concurrency_allowed");
      result = 0;
      policy_mgr_is_concurrency_allowed___last_ticks_96 = v116;
      goto LABEL_89;
    }
    goto LABEL_88;
  }
  v105 = a2 == 3 && a3 != 0 && v31;
  if ( v105 && (wlan_mlme_get_p2p_p2p_conc_support(a1) & 1) == 0 )
  {
    v106 = policy_mgr_mode_specific_connection_count(a1, 3, &v154);
    qdf_mutex_acquire(v21 + 56);
    if ( !v106 )
      goto LABEL_74;
    if ( (unsigned int)v154 >= 5 )
      goto LABEL_103;
    if ( (wlan_reg_is_same_band_freqs(a3, *((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v154 + 1)) & 1) != 0 )
      goto LABEL_55;
    if ( v106 == 1 )
      goto LABEL_74;
    if ( HIDWORD(v154) > 4 )
      goto LABEL_103;
    if ( (wlan_reg_is_same_band_freqs(a3, *((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v154) + 1)) & 1) == 0 )
    {
      if ( v106 == 2 )
        goto LABEL_74;
      if ( (unsigned int)v155 > 4 )
        goto LABEL_103;
      if ( (wlan_reg_is_same_band_freqs(a3, *((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v155 + 1)) & 1) != 0 )
        goto LABEL_55;
      if ( v106 == 3 )
        goto LABEL_74;
      if ( HIDWORD(v155) > 4 )
        goto LABEL_103;
      if ( (wlan_reg_is_same_band_freqs(a3, *((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v155) + 1)) & 1) != 0 )
        goto LABEL_55;
      if ( v106 == 4 )
      {
LABEL_74:
        qdf_mutex_release(v21 + 56);
        goto LABEL_75;
      }
      if ( v156 > 4 )
        goto LABEL_103;
      if ( (wlan_reg_is_same_band_freqs(a3, *((_DWORD *)&pm_conc_connection_list + 9 * v156 + 1)) & 1) == 0 )
      {
        if ( v106 != 5 )
          goto LABEL_103;
        goto LABEL_74;
      }
    }
LABEL_55:
    v115 = jiffies;
    if ( policy_mgr_is_concurrency_allowed___last_ticks_98 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Don't allow P2P GO on same band",
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        "policy_mgr_is_concurrency_allowed");
      policy_mgr_is_concurrency_allowed___last_ticks_98 = v115;
    }
    qdf_mutex_release(v21 + 56);
    goto LABEL_88;
  }
LABEL_75:
  v139 = *(_QWORD *)(v21 + 8);
  if ( !v139 )
  {
    v147 = "%s: pdev is Null";
LABEL_86:
    qdf_trace_msg(
      0x4Fu,
      8u,
      v147,
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      "policy_mgr_allow_wapi_concurrency",
      v152);
    goto LABEL_87;
  }
  v140 = *(_QWORD *)(v139 + 80);
  if ( !v140 )
    goto LABEL_87;
  v141 = *(_QWORD *)(v140 + 2800);
  if ( !v141 || (v142 = *(_QWORD *)(v141 + 16)) == 0 )
  {
    v147 = "%s: Invalid WMI handle";
    goto LABEL_86;
  }
  if ( (wmi_service_enabled(v142, 0xE6u, v96, v97, v98, v99, v100, v101, v102, v103) & 1) == 0
    && (mlme_is_wapi_sta_active(v139) & 1) != 0 )
  {
    v143 = policy_mgr_get_context(*(_QWORD *)v21);
    if ( !v143 )
      goto LABEL_104;
    v144 = v143;
    qdf_mutex_acquire(v143 + 56);
    v145 = BYTE4(qword_81C4E8);
    v146 = BYTE4(qword_81C47C) + BYTE4(qword_81C458) + BYTE4(qword_81C4A0) + BYTE4(qword_81C4C4);
    qdf_mutex_release(v144 + 56);
    if ( v146 | v145 )
    {
LABEL_87:
      v148 = jiffies;
      if ( policy_mgr_is_concurrency_allowed___last_ticks_100 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: Don't allow new conn when wapi security conn existing",
          v96,
          v97,
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          "policy_mgr_is_concurrency_allowed");
        result = 0;
        policy_mgr_is_concurrency_allowed___last_ticks_100 = v148;
        goto LABEL_89;
      }
      goto LABEL_88;
    }
  }
  while ( 1 )
  {
    if ( (policy_mgr_is_third_conn_sta_p2p_p2p_valid(a1, a2) & 1) == 0 )
    {
      v37 = "%s: Don't allow third connection as GO or GC or STA with old fw";
      goto LABEL_9;
    }
    result = 1;
    if ( a2 != 1 || !a6 )
      goto LABEL_89;
    if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v21 + 8), a3, v13, v14, v15, v16, v17, v18, v19, v20) & 1) == 0 )
      break;
    v149 = *(unsigned int *)(a6 + 512);
    if ( !(_DWORD)v149 )
    {
LABEL_114:
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: SAP channel %d Not present in PCL",
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        "policy_mgr_is_concurrency_allowed",
        a3,
        v152);
      goto LABEL_88;
    }
    v150 = 4 * v149;
    v151 = 0;
    while ( v151 != 408 )
    {
      if ( *(_DWORD *)(a6 + v151) == a3 )
        goto LABEL_116;
      v151 += 4;
      if ( v150 == v151 )
        goto LABEL_114;
    }
LABEL_103:
    __break(0x5512u);
LABEL_104:
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      "policy_mgr_get_connection_count",
      v152);
  }
LABEL_116:
  result = 1;
LABEL_89:
  _ReadStatusReg(SP_EL0);
  return result;
}
