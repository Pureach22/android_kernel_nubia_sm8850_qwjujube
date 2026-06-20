__int64 __fastcall hdd_unsafe_channel_restart_sap(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 bonded_chan_entry; // x0
  __int64 v4; // x21
  __int64 v5; // x20
  __int64 v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x22
  __int64 v24; // x8
  __int64 *v25; // x26
  __int64 v26; // x0
  unsigned int v27; // w27
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int *v44; // x8
  __int64 v45; // x22
  _QWORD *v46; // x1
  unsigned int v47; // w22
  unsigned int v48; // w8
  unsigned int v49; // w9
  unsigned __int64 v50; // x10
  __int64 v51; // x11
  bool v52; // w28
  __int64 v53; // x5
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
  unsigned int safe_channel_from_pcl_and_acs_range; // w22
  __int64 v71; // x0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned int v80; // w27
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  __int64 v105; // x22
  __int64 v106; // x0
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  __int64 v115; // x21
  __int64 v116; // x8
  __int64 v117; // x8
  unsigned int *v118; // x8
  unsigned int v119; // w10
  __int64 v120; // x8
  unsigned int v127; // w9
  __int64 v128; // x9
  unsigned __int64 v129; // x8
  __int64 v130; // x9
  unsigned int *v131; // x9
  unsigned int v132; // w12
  __int64 v133; // x9
  __int64 v135; // x0
  __int64 v136; // x22
  __int64 v137; // x9
  unsigned __int64 v138; // x8
  __int64 v139; // x9
  unsigned int *v140; // x9
  unsigned int v141; // w12
  __int64 v142; // x9
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  __int64 result; // x0
  unsigned int v161; // w19
  _QWORD *v162; // x20
  unsigned int v164; // w9
  unsigned int v166; // w9
  __int64 *v167; // [xsp+0h] [xbp-50h]
  unsigned __int64 v168; // [xsp+8h] [xbp-48h]
  unsigned int v169; // [xsp+14h] [xbp-3Ch] BYREF
  __int64 v170; // [xsp+18h] [xbp-38h] BYREF
  __int64 v171; // [xsp+20h] [xbp-30h] BYREF
  unsigned int v172; // [xsp+28h] [xbp-28h] BYREF
  unsigned int v173; // [xsp+2Ch] [xbp-24h] BYREF
  _BYTE v174[4]; // [xsp+30h] [xbp-20h] BYREF
  _BYTE v175[4]; // [xsp+34h] [xbp-1Ch] BYREF
  _BYTE v176[4]; // [xsp+38h] [xbp-18h] BYREF
  _BYTE v177[4]; // [xsp+3Ch] [xbp-14h] BYREF
  _QWORD v178[2]; // [xsp+40h] [xbp-10h] BYREF

  v178[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v172 = 0;
  v170 = 0;
  v171 = 0;
  v169 = 0;
  v177[0] = 0;
  v176[0] = 0;
  v175[0] = 0;
  v174[0] = 0;
  v173 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 32);
  }
  else
  {
    raw_spin_lock_bh(a1 + 32);
    *(_QWORD *)(a1 + 40) |= 1uLL;
  }
  v178[0] = 0;
  bonded_chan_entry = qdf_list_peek_front((_QWORD *)(a1 + 48), v178);
  if ( (_DWORD)bonded_chan_entry || (v46 = (_QWORD *)v178[0], v4 = v178[0] - 8LL, v178[0] == 8) )
  {
    v4 = 0;
    goto LABEL_7;
  }
  v128 = *(__int64 *)((char *)&off_18 + v178[0]);
  if ( v128 )
  {
    v129 = _ReadStatusReg(SP_EL0);
    ++*(_DWORD *)(v129 + 16);
    v130 = *(_QWORD *)(v128 + 1320);
    v131 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v130);
    do
      v132 = __ldxr(v131);
    while ( __stxr(v132 + 1, v131) );
    v133 = *(_QWORD *)(v129 + 16) - 1LL;
    *(_DWORD *)(v129 + 16) = v133;
    if ( !v133 || !*(_QWORD *)(v129 + 16) )
      goto LABEL_145;
  }
  while ( 2 )
  {
    _X8 = (unsigned int *)v46 + 13165;
    __asm { PRFM            #0x11, [X8] }
    do
      v164 = __ldxr(_X8);
    while ( __stxr(v164 + 1, _X8) );
    v178[0] = 0;
    v135 = qdf_list_peek_next((_QWORD *)(a1 + 48), v46, v178);
    if ( (_DWORD)v135 )
    {
LABEL_7:
      v5 = 0;
    }
    else
    {
      v136 = v178[0];
      v5 = v178[0] - 8LL;
      if ( v178[0] != 8 )
      {
        v137 = *(__int64 *)((char *)&off_18 + v178[0]);
        if ( v137 )
        {
          v138 = _ReadStatusReg(SP_EL0);
          ++*(_DWORD *)(v138 + 16);
          v139 = *(_QWORD *)(v137 + 1320);
          v140 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v139);
          do
            v141 = __ldxr(v140);
          while ( __stxr(v141 + 1, v140) );
          v142 = *(_QWORD *)(v138 + 16) - 1LL;
          *(_DWORD *)(v138 + 16) = v142;
          if ( !v142 || !*(_QWORD *)(v138 + 16) )
            preempt_schedule_notrace(v135);
        }
        _X8 = (unsigned int *)(v136 + 52660);
        __asm { PRFM            #0x11, [X8] }
        do
          v166 = __ldxr(_X8);
        while ( __stxr(v166 + 1, _X8) );
      }
    }
    v6 = *(_QWORD *)(a1 + 40);
    if ( (v6 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 40) = v6 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      if ( !v4 )
      {
LABEL_141:
        result = 0;
        goto LABEL_142;
      }
    }
    else
    {
      raw_spin_unlock(a1 + 32);
      if ( !v4 )
        goto LABEL_141;
    }
    v168 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( *(_DWORD *)(v4 + 40) != 1 )
      {
        v105 = jiffies;
        if ( hdd_unsafe_channel_restart_sap___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: skip device mode:%d",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "hdd_unsafe_channel_restart_sap");
          hdd_unsafe_channel_restart_sap___last_ticks = v105;
        }
        goto LABEL_97;
      }
      if ( (*(_QWORD *)(v4 + 1640) & 1) != 0 )
      {
        v25 = (__int64 *)(v4 + 52832);
        if ( v4 != -52832 )
          break;
      }
LABEL_97:
      hdd_adapter_dev_put_debug(v4, 0x24u, v7, v8, v9, v10, v11, v12, v13, v14);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v168 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v168 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 32);
        if ( v5 )
          goto LABEL_101;
LABEL_12:
        v23 = 0;
        v4 = 0;
        v24 = *(_QWORD *)(a1 + 40);
        if ( (v24 & 1) == 0 )
          goto LABEL_13;
LABEL_114:
        *(_QWORD *)(a1 + 40) = v24 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 32);
        v5 = v23;
        if ( !v4 )
          goto LABEL_141;
      }
      else
      {
        raw_spin_lock_bh(a1 + 32);
        *(_QWORD *)(a1 + 40) |= 1uLL;
        if ( !v5 )
          goto LABEL_12;
LABEL_101:
        v178[0] = 0;
        v106 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v5 + 8), v178);
        v23 = v178[0] - 8LL;
        if ( (_DWORD)v106 )
          v115 = 0;
        else
          v115 = v178[0] - 8LL;
        if ( v5 == v115 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Validation failed",
            v107,
            v108,
            v109,
            v110,
            v111,
            v112,
            v113,
            v114,
            "hdd_validate_next_adapter");
          hdd_adapter_dev_put_debug(v5, 0x24u, v15, v16, v17, v18, v19, v20, v21, v22);
          goto LABEL_12;
        }
        if ( v115 )
        {
          v116 = *(_QWORD *)(v115 + 32);
          if ( v116 )
          {
            ++*(_DWORD *)(v168 + 16);
            v117 = *(_QWORD *)(v116 + 1320);
            v118 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v117);
            do
              v119 = __ldxr(v118);
            while ( __stxr(v119 + 1, v118) );
            v120 = *(_QWORD *)(v168 + 16) - 1LL;
            *(_DWORD *)(v168 + 16) = v120;
            if ( !v120 || !*(_QWORD *)(v168 + 16) )
              preempt_schedule_notrace(v106);
          }
          _X8 = (unsigned int *)(v115 + 52668);
          __asm { PRFM            #0x11, [X8] }
          do
            v127 = __ldxr(_X8);
          while ( __stxr(v127 + 1, _X8) );
        }
        else
        {
          v23 = 0;
        }
        v4 = v5;
        v24 = *(_QWORD *)(a1 + 40);
        if ( (v24 & 1) != 0 )
          goto LABEL_114;
LABEL_13:
        raw_spin_unlock(a1 + 32);
        v5 = v23;
        if ( !v4 )
          goto LABEL_141;
      }
    }
    while ( 1 )
    {
      if ( !*(_BYTE *)(v4 + 54248) )
      {
        v45 = jiffies;
        if ( hdd_unsafe_channel_restart_sap___last_ticks_235 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: skip acs:%d",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "hdd_unsafe_channel_restart_sap",
            0);
          hdd_unsafe_channel_restart_sap___last_ticks_235 = v45;
        }
        goto LABEL_92;
      }
      v26 = *(_QWORD *)a1;
      v27 = *(_DWORD *)(v4 + 54984);
      v173 = *(_DWORD *)(v4 + 53576);
      if ( (unsigned int)ucfg_policy_mgr_get_sta_sap_scc_lte_coex_chnl(v26, v177) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: can't get scc on lte coex chnl, use def",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "hdd_unsafe_channel_restart_sap");
      if ( (policy_mgr_is_sta_sap_scc(*(_QWORD *)a1, v27, 0) & 1) != 0 && v177[0]
        || (bonded_chan_entry = policy_mgr_nan_sap_scc_on_unsafe_ch_chk(*(_QWORD *)a1, v27), (bonded_chan_entry & 1) != 0) )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: SAP allowed in unsafe SCC channel",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "hdd_unsafe_channel_restart_sap");
        goto LABEL_24;
      }
      v46 = (_QWORD *)*(unsigned __int8 *)(v4 + 54290);
      v47 = *(_DWORD *)(v4 + 54984);
      if ( !*(_BYTE *)(v4 + 54290) )
        break;
      bonded_chan_entry = (__int64)wlan_reg_get_bonded_chan_entry(
                                     v47,
                                     (unsigned int)v46,
                                     0,
                                     v36,
                                     v37,
                                     v38,
                                     v39,
                                     v40,
                                     v41,
                                     v42,
                                     v43);
      if ( !bonded_chan_entry )
        break;
      v48 = *(unsigned __int16 *)bonded_chan_entry;
      v49 = *(unsigned __int16 *)(bonded_chan_entry + 2);
      v50 = *(unsigned __int16 *)(a1 + 640);
      if ( *(_WORD *)(a1 + 640) )
        goto LABEL_45;
LABEL_24:
      if ( v172 != v27 )
      {
        if ( v172 )
        {
          if ( HIDWORD(v171) == v27 )
            goto LABEL_91;
          if ( HIDWORD(v171) )
          {
            if ( (_DWORD)v171 == v27 )
              goto LABEL_91;
            if ( (_DWORD)v171 )
            {
              if ( HIDWORD(v170) == v27 )
                goto LABEL_91;
              if ( HIDWORD(v170) )
              {
                if ( (_DWORD)v170 == v27 )
                  goto LABEL_91;
                if ( (_DWORD)v170 )
                {
                  if ( !v27 || v169 )
                    goto LABEL_91;
                  v44 = &v169;
                }
                else
                {
                  v44 = (unsigned int *)&v170;
                }
              }
              else
              {
                v44 = (unsigned int *)&v170 + 1;
              }
            }
            else
            {
              v44 = (unsigned int *)&v171;
            }
          }
          else
          {
            v44 = (unsigned int *)&v171 + 1;
          }
        }
        else
        {
          v44 = &v172;
        }
        *v44 = v27;
      }
LABEL_91:
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: ch freq:%d is safe. no need to change channel",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "hdd_unsafe_channel_restart_sap",
        v27);
LABEL_92:
      if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v4 - *(_DWORD *)(v4 + 52832)) >> 4))
        || (*(_QWORD *)(v4 + 1640) & 1) == 0 )
      {
        goto LABEL_97;
      }
    }
    v48 = 0;
    v49 = 0;
    v50 = *(unsigned __int16 *)(a1 + 640);
    if ( !*(_WORD *)(a1 + 640) )
      goto LABEL_24;
LABEL_45:
    v51 = 0;
    v52 = 1;
LABEL_47:
    if ( v51 == 102 )
    {
      __break(0x5512u);
LABEL_145:
      v162 = v46;
      preempt_schedule_notrace(bonded_chan_entry);
      v46 = v162;
      continue;
    }
    break;
  }
  v53 = *(unsigned __int16 *)(a1 + 2 * v51 + 642);
  if ( v47 != (_DWORD)v53 )
  {
    if ( v48 <= (unsigned int)v53 && v49 >= (unsigned int)v53 )
      goto LABEL_54;
    v52 = ++v51 < v50;
    if ( v50 == v51 )
      goto LABEL_24;
    goto LABEL_47;
  }
  v53 = v47;
LABEL_54:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: op chn freq:%u is unsafe for chn list:%u",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "hdd_check_chn_bw_boundary_unsafe",
    v47,
    v53);
  if ( !v52 )
    goto LABEL_24;
  if ( (unsigned int)wlan_mlme_get_acs_support_for_dfs_ltecoex(*(_QWORD *)a1, v175) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: get_acs_support_for_dfs_ltecoex failed,set def",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "hdd_unsafe_channel_restart_sap");
  if ( (unsigned int)wlan_mlme_get_vendor_acs_support(*(_QWORD *)a1, v174) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: get_vendor_acs_support failed, set default",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "hdd_unsafe_channel_restart_sap");
  if ( v174[0] == 1 && v175[0] == 1 )
  {
    hdd_update_acs_timer_reason(v4, 2u);
    goto LABEL_92;
  }
  safe_channel_from_pcl_and_acs_range = v172;
  if ( !v172
    || !policy_mgr_is_force_scc(*(_QWORD *)a1)
    || (wlan_reg_is_same_band_freqs(safe_channel_from_pcl_and_acs_range, v27) & 1) == 0 )
  {
    safe_channel_from_pcl_and_acs_range = HIDWORD(v171);
    if ( !HIDWORD(v171)
      || !policy_mgr_is_force_scc(*(_QWORD *)a1)
      || (wlan_reg_is_same_band_freqs(safe_channel_from_pcl_and_acs_range, v27) & 1) == 0 )
    {
      safe_channel_from_pcl_and_acs_range = v171;
      if ( !(_DWORD)v171
        || !policy_mgr_is_force_scc(*(_QWORD *)a1)
        || (wlan_reg_is_same_band_freqs(safe_channel_from_pcl_and_acs_range, v27) & 1) == 0 )
      {
        safe_channel_from_pcl_and_acs_range = HIDWORD(v170);
        if ( !HIDWORD(v170)
          || !policy_mgr_is_force_scc(*(_QWORD *)a1)
          || (wlan_reg_is_same_band_freqs(safe_channel_from_pcl_and_acs_range, v27) & 1) == 0 )
        {
          safe_channel_from_pcl_and_acs_range = v170;
          if ( !(_DWORD)v170
            || !policy_mgr_is_force_scc(*(_QWORD *)a1)
            || (wlan_reg_is_same_band_freqs(safe_channel_from_pcl_and_acs_range, v27) & 1) == 0 )
          {
            safe_channel_from_pcl_and_acs_range = v169;
            if ( !v169
              || !policy_mgr_is_force_scc(*(_QWORD *)a1)
              || (wlan_reg_is_same_band_freqs(safe_channel_from_pcl_and_acs_range, v27) & 1) == 0 )
            {
              safe_channel_from_pcl_and_acs_range = wlansap_get_safe_channel_from_pcl_and_acs_range(
                                                      *(_QWORD *)(v4 + 53104),
                                                      &v173);
              if ( !safe_channel_from_pcl_and_acs_range )
              {
                wlan_hdd_set_sap_csa_reason(*(_QWORD *)a1, *(_BYTE *)(v4 + 52840), 6u);
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Unable to find safe chan, Stop the SAP if restriction mask is set else set txpower",
                  v97,
                  v98,
                  v99,
                  v100,
                  v101,
                  v102,
                  v103,
                  v104,
                  "hdd_unsafe_channel_restart_sap");
                hdd_stop_sap_set_tx_power(*(_QWORD *)a1, (__int64 *)(v4 + 52832));
                goto LABEL_92;
              }
            }
          }
        }
      }
    }
  }
  v71 = *(_QWORD *)a1;
  *(_DWORD *)(a1 + 1620) = 0;
  wlan_mlme_get_sap_internal_restart(v71, v176);
  if ( v176[0] != 1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: sending coex indication",
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      "hdd_unsafe_channel_restart_sap");
    wlan_hdd_send_svc_nlink_msg(*(unsigned int *)(a1 + 1456), 257, 0, 0);
    hdd_adapter_dev_put_debug(v4, 0x24u, v144, v145, v146, v147, v148, v149, v150, v151);
    result = 0;
    if ( !v5 )
      goto LABEL_142;
    goto LABEL_137;
  }
  wlan_hdd_set_sap_csa_reason(*(_QWORD *)a1, *(_BYTE *)(v4 + 52840), 6u);
  v80 = v173;
  if ( (unsigned int)_hdd_validate_adapter(
                       *v25,
                       (__int64)"hdd_switch_sap_chan_freq",
                       v81,
                       v82,
                       v83,
                       v84,
                       v85,
                       v86,
                       v87,
                       v88)
    || (v167 = *(__int64 **)(*v25 + 24),
        (unsigned int)_wlan_hdd_validate_context(
                        (__int64)v167,
                        (__int64)"hdd_switch_sap_chan_freq",
                        v89,
                        v90,
                        v91,
                        v92,
                        v93,
                        v94,
                        v95,
                        v96))
    || (qdf_trace_msg(
          0x33u,
          8u,
          "%s: chan freq:%d width:%d org bw %d",
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          "hdd_switch_sap_chan_freq",
          safe_channel_from_pcl_and_acs_range,
          v80,
          *(unsigned int *)(v4 + 53576)),
        (unsigned int)policy_mgr_change_sap_channel_with_csa(
                        *v167,
                        *(unsigned __int8 *)(v4 + 52840),
                        safe_channel_from_pcl_and_acs_range,
                        v80,
                        1)) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: CSA failed, check next SAP",
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      "hdd_unsafe_channel_restart_sap",
      v167);
    goto LABEL_92;
  }
  hdd_adapter_dev_put_debug(v4, 0x24u, v89, v90, v91, v92, v93, v94, v95, v96);
  result = 24;
  if ( v5 )
  {
LABEL_137:
    v161 = result;
    hdd_adapter_dev_put_debug(v5, 0x24u, v152, v153, v154, v155, v156, v157, v158, v159);
    result = v161;
  }
LABEL_142:
  _ReadStatusReg(SP_EL0);
  return result;
}
