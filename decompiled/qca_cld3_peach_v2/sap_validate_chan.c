__int64 __fastcall sap_validate_chan(
        unsigned int *a1,
        char a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  __int64 v24; // x20
  int v25; // w23
  unsigned int v26; // w8
  __int64 result; // x0
  char concurrency_mode; // w24
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned __int16 v37; // w0
  __int64 v38; // x4
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  bool v55; // w23
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  int v64; // w8
  __int64 v65; // x0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int v74; // w2
  unsigned __int8 v75; // w1
  unsigned __int8 existing_con_info; // w0
  __int64 v77; // x9
  __int64 v78; // x10
  const char *v79; // x2
  __int64 v80; // x9
  __int64 v81; // x10
  bool is_sta_sap_scc_allowed_on_dfs_chan; // w0
  bool v83; // w24
  __int64 v84; // x9
  __int64 v85; // x10
  __int64 v86; // x8
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  _QWORD *v95; // x0
  unsigned __int8 v96; // w0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  unsigned __int8 v105; // w23
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  _QWORD *v114; // x0
  _QWORD *v115; // x24
  __int64 v116; // x25
  __int64 v117; // x25
  __int64 v118; // x25
  __int64 v119; // x25
  __int64 v120; // x25
  __int64 v121; // x24
  const char *v122; // x2
  const char *v123; // x3
  unsigned int v124; // w1
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  __int64 v133; // x0
  __int64 v134; // x8
  __int64 v135; // [xsp+0h] [xbp-30h] BYREF
  __int64 v136; // [xsp+8h] [xbp-28h]
  __int64 v137; // [xsp+10h] [xbp-20h]
  unsigned int v138; // [xsp+18h] [xbp-18h] BYREF
  __int64 v139; // [xsp+1Ch] [xbp-14h] BYREF
  int v140; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v141; // [xsp+28h] [xbp-8h]

  v141 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v138 = 0;
  v136 = 0;
  v137 = 0;
  v135 = 0;
  context = _cds_get_context(52, (__int64)"sap_validate_chan", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
  {
    qdf_trace_msg(
      0x39u,
      1u,
      "%s: invalid MAC handle",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "sap_validate_chan",
      v135);
    result = 5;
    goto LABEL_83;
  }
  if ( !*a1 )
  {
    qdf_trace_msg(0x39u, 2u, "%s: Invalid channel", v15, v16, v17, v18, v19, v20, v21, v22, "sap_validate_chan", v135);
    result = 16;
    goto LABEL_83;
  }
  v23 = *((_QWORD *)a1 + 2);
  v24 = (__int64)context;
  if ( v23 )
  {
    v25 = *(_DWORD *)(v23 + 16);
    if ( v25 != 3 )
    {
      if ( v25 != 1 )
        goto LABEL_12;
      goto LABEL_6;
    }
    v55 = policy_mgr_go_scc_enforced(context[2703]);
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: go force scc enabled %d",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      "sap_validate_chan",
      v55,
      v135);
    v64 = *((unsigned __int8 *)a1 + 1560);
    v65 = *(_QWORD *)(v24 + 21624);
    v140 = 7;
    if ( v64 != 4 )
    {
      v74 = *a1;
      v75 = *((_BYTE *)a1 + 12);
      v139 = 0;
      existing_con_info = policy_mgr_fetch_existing_con_info(v65, v75, v74, &v140, (_DWORD *)&v139 + 1, &v139);
      if ( existing_con_info != 0xFF && v140 == 1 )
      {
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: concurrent sap vdev: %d on freq %d, skip GO force scc",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "sap_process_force_scc_with_go_start",
          existing_con_info,
          HIDWORD(v139));
        goto LABEL_65;
      }
    }
    if ( !v55 )
    {
LABEL_65:
      v25 = 3;
      goto LABEL_66;
    }
    if ( (policy_mgr_is_go_scc_strict(*(_QWORD *)(v24 + 21624)) & 1) != 0 )
    {
LABEL_21:
      v25 = 3;
      goto LABEL_12;
    }
    qdf_trace_msg(0x39u, 8u, "%s: liberal mode is enabled", v66, v67, v68, v69, v70, v71, v72, v73, "sap_validate_chan");
    v139 = 0;
    v140 = 7;
    v95 = _cds_get_context(52, (__int64)"sap_process_liberal_scc_for_go", v87, v88, v89, v90, v91, v92, v93, v94);
    if ( v95 )
    {
      v96 = policy_mgr_fetch_existing_con_info(v95[2703], *((_BYTE *)a1 + 12), *a1, &v140, (_DWORD *)&v139 + 1, &v139);
      v105 = v96;
      if ( v96 == 0xFF || v140 != 3 )
      {
        if ( v96 != 0xFF && (v140 & 0xFFFFFFFD) == 0 )
        {
          qdf_trace_msg(
            0x39u,
            8u,
            "%s: don't override channel, start go on %d",
            v97,
            v98,
            v99,
            v100,
            v101,
            v102,
            v103,
            v104,
            "sap_process_liberal_scc_for_go",
            *a1);
          goto LABEL_65;
        }
        goto LABEL_21;
      }
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: set forcescc flag for go vdev: %d",
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        "sap_process_liberal_scc_for_go",
        v96);
      v114 = _cds_get_context(53, (__int64)"sap_get_mac_context", v106, v107, v108, v109, v110, v111, v112, v113);
      if ( v114 )
      {
        v115 = v114;
        if ( *((_DWORD *)v114 + 3724) == 3 )
        {
          v116 = v114[1861];
          if ( *(unsigned __int8 *)(v116 + 12) == v105 )
          {
            qdf_trace_msg(
              0x39u,
              8u,
              "%s: update forcescc restart for vdev %d",
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              "sap_set_forcescc_required",
              v105);
            *(_BYTE *)(v116 + 1765) = 1;
          }
        }
        if ( *((_DWORD *)v115 + 3728) == 3 )
        {
          v117 = v115[1863];
          if ( *(unsigned __int8 *)(v117 + 12) == v105 )
          {
            qdf_trace_msg(
              0x39u,
              8u,
              "%s: update forcescc restart for vdev %d",
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              "sap_set_forcescc_required",
              v105);
            *(_BYTE *)(v117 + 1765) = 1;
          }
        }
        if ( *((_DWORD *)v115 + 3732) == 3 )
        {
          v118 = v115[1865];
          if ( *(unsigned __int8 *)(v118 + 12) == v105 )
          {
            qdf_trace_msg(
              0x39u,
              8u,
              "%s: update forcescc restart for vdev %d",
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              "sap_set_forcescc_required",
              v105);
            *(_BYTE *)(v118 + 1765) = 1;
          }
        }
        if ( *((_DWORD *)v115 + 3736) == 3 )
        {
          v119 = v115[1867];
          if ( *(unsigned __int8 *)(v119 + 12) == v105 )
          {
            qdf_trace_msg(
              0x39u,
              8u,
              "%s: update forcescc restart for vdev %d",
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              "sap_set_forcescc_required",
              v105);
            *(_BYTE *)(v119 + 1765) = 1;
          }
        }
        if ( *((_DWORD *)v115 + 3740) == 3 )
        {
          v120 = v115[1869];
          if ( *(unsigned __int8 *)(v120 + 12) == v105 )
          {
            qdf_trace_msg(
              0x39u,
              8u,
              "%s: update forcescc restart for vdev %d",
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              "sap_set_forcescc_required",
              v105);
            *(_BYTE *)(v120 + 1765) = 1;
          }
        }
        if ( *((_DWORD *)v115 + 3744) == 3 )
        {
          v121 = v115[1871];
          if ( *(unsigned __int8 *)(v121 + 12) == v105 )
          {
            qdf_trace_msg(
              0x39u,
              8u,
              "%s: update forcescc restart for vdev %d",
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              "sap_set_forcescc_required",
              v105);
            v25 = 3;
            *(_BYTE *)(v121 + 1765) = 1;
            goto LABEL_66;
          }
        }
        goto LABEL_65;
      }
      v122 = "%s: Invalid MAC context";
      v123 = "sap_set_forcescc_required";
      v124 = 2;
    }
    else
    {
      v122 = "%s: invalid MAC handle";
      v123 = "sap_process_liberal_scc_for_go";
      v124 = 1;
    }
    qdf_trace_msg(0x39u, v124, v122, v29, v30, v31, v32, v33, v34, v35, v36, v123);
    goto LABEL_65;
  }
LABEL_6:
  if ( (wlan_nan_is_sta_sap_nan_allowed(context[2703]) & 1) != 0
    && (unsigned int)policy_mgr_mode_specific_connection_count(*(_QWORD *)(v24 + 21624), 5, nullptr) )
  {
    v26 = wlan_nan_sap_override_freq(*(_QWORD *)(v24 + 21624), *((unsigned __int8 *)a1 + 12), *a1);
    result = 0;
    *a1 = v26;
    goto LABEL_83;
  }
  v25 = 1;
LABEL_12:
  concurrency_mode = policy_mgr_get_concurrency_mode(*(_QWORD *)(v24 + 21624));
  if ( (policy_mgr_concurrent_beaconing_sessions_running(*(_QWORD *)(v24 + 21624))
     || (concurrency_mode & 3) == 3
     || (concurrency_mode & 9) == 9)
    && *((_BYTE *)a1 + 1560) )
  {
    v37 = sme_check_concurrent_channel_overlap(v24, *a1, a1[371]);
    v38 = *a1;
    v138 = v37;
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: After check overlap: sap freq %d con freq:%d",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "sap_validate_chan",
      v38);
    if ( wlan_reg_is_24ghz_ch_freq(*a1) )
    {
      LODWORD(v135) = 9;
    }
    else
    {
      v77 = *(_QWORD *)(a1 + 375);
      v78 = *(_QWORD *)(a1 + 377);
      v137 = *(_QWORD *)(a1 + 379);
      v135 = v77;
      v136 = v78;
    }
    if ( *((_BYTE *)a1 + 1560) != 5
      && (unsigned int)policy_mgr_valid_sap_conc_channel_check(
                         *(_QWORD *)(v24 + 21624),
                         &v138,
                         *a1,
                         *((unsigned __int8 *)a1 + 12),
                         (unsigned int *)&v135) )
    {
      v79 = "%s: SAP can't start (no MCC)";
LABEL_73:
      qdf_trace_msg(0x39u, 3u, v79, v47, v48, v49, v50, v51, v52, v53, v54, "sap_validate_chan", v135);
      result = 10;
      goto LABEL_83;
    }
    if ( (_DWORD)v135 == 9 )
    {
      v80 = *(_QWORD *)(a1 + 375);
      v81 = *(_QWORD *)(a1 + 377);
      v137 = *(_QWORD *)(a1 + 379);
      v135 = v80;
      v136 = v81;
    }
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: After check concurrency: con freq:%d",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "sap_validate_chan",
      v138,
      v135);
    is_sta_sap_scc_allowed_on_dfs_chan = policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(*(_QWORD *)(v24 + 21624));
    if ( v138 )
    {
      v83 = is_sta_sap_scc_allowed_on_dfs_chan;
      if ( (policy_mgr_sta_sap_scc_on_lte_coex_chan(*(_QWORD *)(v24 + 21624))
         || (((__int64 (__fastcall *)(_QWORD, _QWORD))policy_mgr_is_safe_channel)(*(_QWORD *)(v24 + 21624), v138) & 1) != 0)
        && v83
         | ((wlan_mlme_check_chan_param_has_dfs(
               *(_QWORD *)(v24 + 21632),
               (__int64)&v135,
               v138,
               v29,
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36)
           & 1) == 0)
        && (is_mcc_preferred(a1, v138) & 1) == 0 )
      {
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: Override ch freq %d (bw %d) to %d (bw %d) due to CC Intf",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "sap_validate_chan",
          *a1,
          a1[375],
          v138,
          (unsigned int)v135);
        v84 = v135;
        v85 = v136;
        *a1 = v138;
        v86 = v137;
        *(_QWORD *)(a1 + 375) = v84;
        *(_QWORD *)(a1 + 377) = v85;
        *(_QWORD *)(a1 + 379) = v86;
      }
    }
  }
LABEL_66:
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: for configured channel, Ch_freq = %d",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "sap_validate_chan",
    *a1,
    v135);
  if ( !**((_BYTE **)a1 + 193) )
  {
    v133 = *(_QWORD *)(v24 + 21624);
    if ( v133 )
    {
      v134 = *(_QWORD *)(v133 + 2800);
      if ( v134 && (*(_BYTE *)(v134 + 994) & 2) != 0 && (policy_mgr_restrict_sap_on_unsafe_chan(v133) & 1) == 0 )
        goto LABEL_68;
    }
    else
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: null psoc",
        v125,
        v126,
        v127,
        v128,
        v129,
        v130,
        v131,
        v132,
        "sap_get_coex_fixed_chan_cap");
    }
  }
  if ( (policy_mgr_is_sap_freq_allowed(*(_QWORD *)(v24 + 21624), v25, *a1) & 1) == 0 )
  {
    v79 = "%s: Abort SAP start due to unsafe channel";
    goto LABEL_73;
  }
LABEL_68:
  if ( (a3 & 1) == 0 )
  {
    if ( (a2 & 1) == 0 )
    {
      result = 0;
      goto LABEL_83;
    }
    goto LABEL_80;
  }
  result = policy_mgr_update_and_wait_for_connection_update(
             *(_QWORD *)(v24 + 21624),
             *((_BYTE *)a1 + 12),
             *a1,
             2u,
             v47,
             v48,
             v49,
             v50,
             v51,
             v52,
             v53,
             v54);
  if ( !(_DWORD)result && (a2 & 1) != 0 )
  {
LABEL_80:
    qdf_trace_msg(
      0x39u,
      4u,
      "%s: ACS end due to Ch override. Sel Ch freq = %d",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "sap_validate_chan",
      *a1);
    *(_DWORD *)(*((_QWORD *)a1 + 193) + 564LL) = *a1;
    *(_WORD *)(*((_QWORD *)a1 + 193) + 42LL) = *((_WORD *)a1 + 749);
    sap_config_acs_result(v24, (__int64)a1, 0);
    result = 9;
  }
LABEL_83:
  _ReadStatusReg(SP_EL0);
  return result;
}
