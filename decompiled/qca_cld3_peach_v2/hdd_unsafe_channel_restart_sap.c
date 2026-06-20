__int64 __fastcall hdd_unsafe_channel_restart_sap(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  __int64 v16; // x26
  __int64 v17; // x0
  unsigned int v18; // w27
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int *v35; // x8
  __int64 v36; // x20
  unsigned int v37; // w22
  unsigned __int16 *bonded_chan_entry; // x0
  unsigned int v39; // w8
  unsigned int v40; // w9
  unsigned __int64 v41; // x10
  __int64 v42; // x11
  bool v43; // w20
  __int64 v44; // x5
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int safe_channel_from_pcl_and_acs_range; // w22
  __int64 v62; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned int v71; // w27
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
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
  __int64 v96; // x8
  __int64 v97; // x9
  __int64 v98; // x10
  __int64 v99; // x20
  __int64 v100; // x0
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x20
  __int64 v110; // x8
  __int64 v111; // x8
  unsigned int *v112; // x8
  unsigned int v113; // w10
  __int64 v114; // x8
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  unsigned int v129; // w9
  _QWORD *v130; // x1
  __int64 v131; // x9
  unsigned __int64 v132; // x8
  __int64 v133; // x9
  unsigned int *v134; // x9
  unsigned int v135; // w12
  __int64 v136; // x9
  __int64 v138; // x0
  __int64 v139; // x20
  __int64 v140; // x9
  unsigned __int64 v141; // x8
  __int64 v142; // x9
  unsigned int *v143; // x9
  unsigned int v144; // w12
  __int64 v145; // x9
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  double v155; // d0
  double v156; // d1
  double v157; // d2
  double v158; // d3
  double v159; // d4
  double v160; // d5
  double v161; // d6
  double v162; // d7
  __int64 result; // x0
  __int64 v164; // x8
  unsigned int v165; // w19
  _QWORD *v166; // x20
  unsigned int v168; // w9
  unsigned int v170; // w9
  __int64 *v171; // [xsp+8h] [xbp-58h]
  unsigned __int64 v172; // [xsp+10h] [xbp-50h]
  __int64 v173; // [xsp+18h] [xbp-48h]
  unsigned int v174; // [xsp+24h] [xbp-3Ch] BYREF
  __int64 v175; // [xsp+28h] [xbp-38h] BYREF
  unsigned int v176; // [xsp+30h] [xbp-30h] BYREF
  __int64 v177; // [xsp+34h] [xbp-2Ch] BYREF
  unsigned int v178; // [xsp+3Ch] [xbp-24h] BYREF
  _BYTE v179[4]; // [xsp+40h] [xbp-20h] BYREF
  _BYTE v180[4]; // [xsp+44h] [xbp-1Ch] BYREF
  _BYTE v181[4]; // [xsp+48h] [xbp-18h] BYREF
  _BYTE v182[4]; // [xsp+4Ch] [xbp-14h] BYREF
  _QWORD v183[2]; // [xsp+50h] [xbp-10h] BYREF

  v183[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v177 = 0;
  v176 = 0;
  v175 = 0;
  v174 = 0;
  v182[0] = 0;
  v181[0] = 0;
  v180[0] = 0;
  v179[0] = 0;
  v178 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
      goto LABEL_151;
  }
  raw_spin_lock(a1 + 32);
  while ( 2 )
  {
    v183[0] = 0;
    v3 = qdf_list_peek_front((_QWORD *)(a1 + 48), v183);
    if ( (_DWORD)v3 || (v130 = (_QWORD *)v183[0], v4 = v183[0] - 8LL, v183[0] == 8) )
    {
      v4 = 0;
    }
    else
    {
      v131 = *(__int64 *)((char *)&off_18 + v183[0]);
      if ( v131 )
      {
        v132 = _ReadStatusReg(SP_EL0);
        ++*(_DWORD *)(v132 + 16);
        v133 = *(_QWORD *)(v131 + 1320);
        v134 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v133);
        do
          v135 = __ldxr(v134);
        while ( __stxr(v135 + 1, v134) );
        v136 = *(_QWORD *)(v132 + 16) - 1LL;
        *(_DWORD *)(v132 + 16) = v136;
        if ( !v136 || !*(_QWORD *)(v132 + 16) )
        {
          v166 = v130;
          preempt_schedule_notrace(v3);
          v130 = v166;
        }
      }
      _X8 = (unsigned int *)v130 + 13165;
      __asm { PRFM            #0x11, [X8] }
      do
        v168 = __ldxr(_X8);
      while ( __stxr(v168 + 1, _X8) );
      v183[0] = 0;
      v138 = qdf_list_peek_next((_QWORD *)(a1 + 48), v130, v183);
      if ( !(_DWORD)v138 )
      {
        v139 = v183[0];
        v5 = v183[0] - 8LL;
        if ( v183[0] != 8 )
        {
          v140 = *(__int64 *)((char *)&off_18 + v183[0]);
          if ( v140 )
          {
            v141 = _ReadStatusReg(SP_EL0);
            ++*(_DWORD *)(v141 + 16);
            v142 = *(_QWORD *)(v140 + 1320);
            v143 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v142);
            do
              v144 = __ldxr(v143);
            while ( __stxr(v144 + 1, v143) );
            v145 = *(_QWORD *)(v141 + 16) - 1LL;
            *(_DWORD *)(v141 + 16) = v145;
            if ( !v145 || !*(_QWORD *)(v141 + 16) )
              preempt_schedule_notrace(v138);
          }
          _X8 = (unsigned int *)(v139 + 52660);
          __asm { PRFM            #0x11, [X8] }
          do
            v170 = __ldxr(_X8);
          while ( __stxr(v170 + 1, _X8) );
        }
        goto LABEL_8;
      }
    }
    v5 = 0;
LABEL_8:
    v6 = *(_QWORD *)(a1 + 40);
    if ( (v6 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 40) = v6 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      if ( !v4 )
      {
LABEL_148:
        result = 0;
        goto LABEL_149;
      }
    }
    else
    {
      raw_spin_unlock(a1 + 32);
      if ( !v4 )
        goto LABEL_148;
    }
    v172 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v173 = v5;
      if ( *(_DWORD *)(v4 + 40) == 1 )
        break;
      v99 = jiffies;
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
        hdd_unsafe_channel_restart_sap___last_ticks = v99;
      }
LABEL_104:
      hdd_adapter_dev_put_debug(v4, 0x24u, v7, v8, v9, v10, v11, v12, v13, v14);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v172 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v172 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 32);
        v4 = v173;
        if ( !v173 )
          goto LABEL_11;
      }
      else
      {
        raw_spin_lock_bh(a1 + 32);
        *(_QWORD *)(a1 + 40) |= 1uLL;
        v4 = v173;
        if ( !v173 )
          goto LABEL_11;
      }
      v183[0] = 0;
      v100 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(v4 + 8), v183);
      v5 = v183[0] - 8LL;
      if ( (_DWORD)v100 )
        v109 = 0;
      else
        v109 = v183[0] - 8LL;
      if ( v4 == v109 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Validation failed",
          v101,
          v102,
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          "hdd_validate_next_adapter");
        hdd_adapter_dev_put_debug(v4, 0x24u, v116, v117, v118, v119, v120, v121, v122, v123);
        v5 = 0;
        v4 = 0;
        v15 = *(_QWORD *)(a1 + 40);
        if ( (v15 & 1) == 0 )
          goto LABEL_12;
        goto LABEL_120;
      }
      if ( v109 )
      {
        v110 = *(_QWORD *)(v109 + 32);
        if ( v110 )
        {
          ++*(_DWORD *)(v172 + 16);
          v111 = *(_QWORD *)(v110 + 1320);
          v112 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v111);
          do
            v113 = __ldxr(v112);
          while ( __stxr(v113 + 1, v112) );
          v114 = *(_QWORD *)(v172 + 16) - 1LL;
          *(_DWORD *)(v172 + 16) = v114;
          if ( !v114 || !*(_QWORD *)(v172 + 16) )
            preempt_schedule_notrace(v100);
        }
        _X8 = (unsigned int *)(v109 + 52668);
        __asm { PRFM            #0x11, [X8] }
        do
          v129 = __ldxr(_X8);
        while ( __stxr(v129 + 1, _X8) );
        v15 = *(_QWORD *)(a1 + 40);
        if ( (v15 & 1) != 0 )
          goto LABEL_120;
LABEL_12:
        raw_spin_unlock(a1 + 32);
        if ( !v4 )
          goto LABEL_148;
      }
      else
      {
LABEL_11:
        v5 = 0;
        v15 = *(_QWORD *)(a1 + 40);
        if ( (v15 & 1) == 0 )
          goto LABEL_12;
LABEL_120:
        *(_QWORD *)(a1 + 40) = v15 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 32);
        if ( !v4 )
          goto LABEL_148;
      }
    }
    if ( (*(_QWORD *)(v4 + 1640) & 1) == 0 || (v16 = v4 + 52840, v4 == -52840) )
    {
      if ( (*(_QWORD *)(v4 + 1640) & 2) == 0 || (v16 = v4 + 58928, v4 == -58928) )
      {
        if ( (*(_QWORD *)(v4 + 1640) & 4) == 0 )
          goto LABEL_104;
        v16 = v4 + 65016;
        if ( v4 == -65016 )
          goto LABEL_104;
      }
    }
    while ( 1 )
    {
      if ( !*(_BYTE *)(v16 + 1424) )
      {
        v36 = jiffies;
        if ( hdd_unsafe_channel_restart_sap___last_ticks_248 - jiffies + 125 < 0 )
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
          hdd_unsafe_channel_restart_sap___last_ticks_248 = v36;
        }
        goto LABEL_97;
      }
      v17 = *(_QWORD *)a1;
      v18 = *(_DWORD *)(v16 + 2424);
      v178 = *(_DWORD *)(v16 + 752);
      if ( (unsigned int)ucfg_policy_mgr_get_sta_sap_scc_lte_coex_chnl(v17, v182) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: can't get scc on lte coex chnl, use def",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "hdd_unsafe_channel_restart_sap");
      if ( (policy_mgr_is_sta_sap_scc(*(_QWORD *)a1, v18, 0) & 1) != 0 && v182[0]
        || (policy_mgr_nan_sap_scc_on_unsafe_ch_chk(*(_QWORD *)a1, v18) & 1) != 0 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: SAP allowed in unsafe SCC channel",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "hdd_unsafe_channel_restart_sap");
        goto LABEL_29;
      }
      v37 = *(_DWORD *)(v16 + 2424);
      if ( !*(_BYTE *)(v16 + 1466) )
        break;
      bonded_chan_entry = wlan_reg_get_bonded_chan_entry(
                            v37,
                            *(unsigned __int8 *)(v16 + 1466),
                            0,
                            v27,
                            v28,
                            v29,
                            v30,
                            v31,
                            v32,
                            v33,
                            v34);
      if ( !bonded_chan_entry )
        break;
      v39 = *bonded_chan_entry;
      v40 = bonded_chan_entry[1];
      v41 = *(unsigned __int16 *)(a1 + 640);
      if ( *(_WORD *)(a1 + 640) )
        goto LABEL_50;
LABEL_29:
      if ( HIDWORD(v177) != v18 )
      {
        if ( HIDWORD(v177) )
        {
          if ( (_DWORD)v177 == v18 )
            goto LABEL_96;
          if ( (_DWORD)v177 )
          {
            if ( v176 == v18 )
              goto LABEL_96;
            if ( v176 )
            {
              if ( HIDWORD(v175) == v18 )
                goto LABEL_96;
              if ( HIDWORD(v175) )
              {
                if ( (_DWORD)v175 == v18 )
                  goto LABEL_96;
                if ( (_DWORD)v175 )
                {
                  if ( !v18 || v174 )
                    goto LABEL_96;
                  v35 = &v174;
                }
                else
                {
                  v35 = (unsigned int *)&v175;
                }
              }
              else
              {
                v35 = (unsigned int *)&v175 + 1;
              }
            }
            else
            {
              v35 = &v176;
            }
          }
          else
          {
            v35 = (unsigned int *)&v177;
          }
        }
        else
        {
          v35 = (unsigned int *)&v177 + 1;
        }
        *v35 = v18;
      }
LABEL_96:
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: ch freq:%d is safe. no need to change channel",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "hdd_unsafe_channel_restart_sap",
        v18);
LABEL_97:
      if ( (unsigned __int8)(73 * ((unsigned int)(v16 - *(_DWORD *)v16 - 52840) >> 3) + 1) <= 2u )
      {
        v96 = (unsigned __int8)(73 * ((unsigned int)(v16 - *(_DWORD *)v16 - 52840) >> 3) + 1);
        v16 = 0;
        v97 = v4 + 52840 + 6088LL * (unsigned int)v96;
        do
        {
          if ( v16 )
            break;
          v98 = *(_QWORD *)(v4 + 1640) >> v96++;
          v16 = (v98 << 63 >> 63) & v97;
          v97 += 6088;
        }
        while ( v96 != 3 );
        if ( v16 )
          continue;
      }
      goto LABEL_104;
    }
    v39 = 0;
    v40 = 0;
    v41 = *(unsigned __int16 *)(a1 + 640);
    if ( !*(_WORD *)(a1 + 640) )
      goto LABEL_29;
LABEL_50:
    v42 = 0;
    v43 = 1;
LABEL_52:
    if ( v42 == 102 )
    {
      __break(0x5512u);
LABEL_151:
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
      continue;
    }
    break;
  }
  v44 = *(unsigned __int16 *)(a1 + 2 * v42 + 642);
  if ( v37 != (_DWORD)v44 )
  {
    if ( v39 <= (unsigned int)v44 && v40 >= (unsigned int)v44 )
      goto LABEL_59;
    v43 = ++v42 < v41;
    if ( v41 == v42 )
      goto LABEL_29;
    goto LABEL_52;
  }
  v44 = v37;
LABEL_59:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: op chn freq:%u is unsafe for chn list:%u",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "hdd_check_chn_bw_boundary_unsafe",
    v37,
    v44);
  if ( !v43 )
    goto LABEL_29;
  if ( (unsigned int)wlan_mlme_get_acs_support_for_dfs_ltecoex(*(_QWORD *)a1, v180) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: get_acs_support_for_dfs_ltecoex failed,set def",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "hdd_unsafe_channel_restart_sap");
  if ( (unsigned int)wlan_mlme_get_vendor_acs_support(*(_QWORD *)a1, v179) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: get_vendor_acs_support failed, set default",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "hdd_unsafe_channel_restart_sap");
  if ( v179[0] == 1 && v180[0] == 1 )
  {
    hdd_update_acs_timer_reason(v4, 2u);
    goto LABEL_97;
  }
  safe_channel_from_pcl_and_acs_range = HIDWORD(v177);
  if ( !HIDWORD(v177)
    || !policy_mgr_is_force_scc(*(_QWORD *)a1)
    || (wlan_reg_is_same_band_freqs(safe_channel_from_pcl_and_acs_range, v18) & 1) == 0 )
  {
    safe_channel_from_pcl_and_acs_range = v177;
    if ( !(_DWORD)v177
      || !policy_mgr_is_force_scc(*(_QWORD *)a1)
      || (wlan_reg_is_same_band_freqs(safe_channel_from_pcl_and_acs_range, v18) & 1) == 0 )
    {
      safe_channel_from_pcl_and_acs_range = v176;
      if ( !v176
        || !policy_mgr_is_force_scc(*(_QWORD *)a1)
        || (wlan_reg_is_same_band_freqs(safe_channel_from_pcl_and_acs_range, v18) & 1) == 0 )
      {
        safe_channel_from_pcl_and_acs_range = HIDWORD(v175);
        if ( !HIDWORD(v175)
          || !policy_mgr_is_force_scc(*(_QWORD *)a1)
          || (wlan_reg_is_same_band_freqs(safe_channel_from_pcl_and_acs_range, v18) & 1) == 0 )
        {
          safe_channel_from_pcl_and_acs_range = v175;
          if ( !(_DWORD)v175
            || !policy_mgr_is_force_scc(*(_QWORD *)a1)
            || (wlan_reg_is_same_band_freqs(safe_channel_from_pcl_and_acs_range, v18) & 1) == 0 )
          {
            safe_channel_from_pcl_and_acs_range = v174;
            if ( !v174
              || !policy_mgr_is_force_scc(*(_QWORD *)a1)
              || (wlan_reg_is_same_band_freqs(safe_channel_from_pcl_and_acs_range, v18) & 1) == 0 )
            {
              safe_channel_from_pcl_and_acs_range = wlansap_get_safe_channel_from_pcl_and_acs_range(
                                                      *(_QWORD *)(v16 + 272),
                                                      &v178);
              if ( !safe_channel_from_pcl_and_acs_range )
              {
                wlan_hdd_set_sap_csa_reason(*(_QWORD *)a1, *(_BYTE *)(v16 + 8), 6u);
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Unable to find safe chan, Stop the SAP if restriction mask is set else set txpower",
                  v88,
                  v89,
                  v90,
                  v91,
                  v92,
                  v93,
                  v94,
                  v95,
                  "hdd_unsafe_channel_restart_sap");
                hdd_stop_sap_set_tx_power(*(_QWORD *)a1, (__int64 *)v16);
                goto LABEL_97;
              }
            }
          }
        }
      }
    }
  }
  v62 = *(_QWORD *)a1;
  *(_DWORD *)(a1 + 1620) = 0;
  wlan_mlme_get_sap_internal_restart(v62, v181);
  if ( v181[0] != 1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: sending coex indication",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "hdd_unsafe_channel_restart_sap");
    wlan_hdd_send_svc_nlink_msg(*(unsigned int *)(a1 + 1456), 257, 0, 0);
    hdd_adapter_dev_put_debug(v4, 0x24u, v147, v148, v149, v150, v151, v152, v153, v154);
    result = 0;
    v164 = v173;
    if ( !v173 )
      goto LABEL_149;
    goto LABEL_144;
  }
  wlan_hdd_set_sap_csa_reason(*(_QWORD *)a1, *(_BYTE *)(v16 + 8), 6u);
  v71 = v178;
  if ( (unsigned int)_hdd_validate_adapter(
                       *(_QWORD *)v16,
                       (__int64)"hdd_switch_sap_chan_freq",
                       v72,
                       v73,
                       v74,
                       v75,
                       v76,
                       v77,
                       v78,
                       v79)
    || (v171 = *(__int64 **)(*(_QWORD *)v16 + 24LL),
        (unsigned int)_wlan_hdd_validate_context(
                        (__int64)v171,
                        (__int64)"hdd_switch_sap_chan_freq",
                        v80,
                        v81,
                        v82,
                        v83,
                        v84,
                        v85,
                        v86,
                        v87))
    || (qdf_trace_msg(
          0x33u,
          8u,
          "%s: chan freq:%d width:%d org bw %d",
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          "hdd_switch_sap_chan_freq",
          safe_channel_from_pcl_and_acs_range,
          v71,
          *(unsigned int *)(v16 + 752)),
        (unsigned int)policy_mgr_change_sap_channel_with_csa(
                        *v171,
                        *(unsigned __int8 *)(v16 + 8),
                        safe_channel_from_pcl_and_acs_range,
                        v71,
                        1)) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: CSA failed, check next SAP",
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      "hdd_unsafe_channel_restart_sap");
    goto LABEL_97;
  }
  hdd_adapter_dev_put_debug(v4, 0x24u, v80, v81, v82, v83, v84, v85, v86, v87);
  result = 24;
  v164 = v173;
  if ( v173 )
  {
LABEL_144:
    v165 = result;
    hdd_adapter_dev_put_debug(v164, 0x24u, v155, v156, v157, v158, v159, v160, v161, v162);
    result = v165;
  }
LABEL_149:
  _ReadStatusReg(SP_EL0);
  return result;
}
