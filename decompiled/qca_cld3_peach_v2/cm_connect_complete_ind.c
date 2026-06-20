__int64 __fastcall cm_connect_complete_ind(
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
  __int64 v11; // x21
  unsigned int v12; // w19
  __int64 v14; // x24
  unsigned int v15; // w23
  int v16; // w8
  __int16 v17; // w8
  __int64 v18; // x27
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 cmpt_obj; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x25
  _DWORD *crypto_params; // x0
  int v38; // w9
  _DWORD *v39; // x26
  char v40; // w8
  bool v41; // zf
  __int64 result; // x0
  __int64 v43; // x5
  const char *v44; // x2
  const char *v45; // x2
  int v46; // w9
  char v47; // w10
  unsigned __int64 StatusReg; // x9
  char v49; // w8
  int v50; // w10
  char v51; // w11
  __int64 v52; // x8
  char v53; // w8
  __int64 v54; // x9
  unsigned int v55; // w8
  int v56; // w9
  size_t v57; // x2
  __int16 v58; // w9
  char v59; // w10
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x8
  unsigned int v85; // w25
  unsigned int v86; // w9
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  int param; // w0
  unsigned int v96; // w26
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  __int64 v121; // x0
  int v122; // w8
  unsigned int v123; // w25
  char tdls_chan_switch_prohibited; // w25
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  char tdls_prohibited; // w0
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  double v150; // d0
  double v151; // d1
  double v152; // d2
  double v153; // d3
  double v154; // d4
  double v155; // d5
  double v156; // d6
  double v157; // d7
  __int64 v158; // x8
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  __int64 v167; // x8
  __int64 v168; // x0
  double v169; // d0
  double v170; // d1
  double v171; // d2
  double v172; // d3
  double v173; // d4
  double v174; // d5
  double v175; // d6
  double v176; // d7
  unsigned int v177; // w27
  char v178; // w26
  __int64 key; // x0
  int v180; // w25
  _BOOL4 v181; // w28
  double v182; // d0
  double v183; // d1
  double v184; // d2
  double v185; // d3
  double v186; // d4
  double v187; // d5
  double v188; // d6
  double v189; // d7
  double v190; // d0
  double v191; // d1
  double v192; // d2
  double v193; // d3
  double v194; // d4
  double v195; // d5
  double v196; // d6
  double v197; // d7
  unsigned int v198; // w25
  __int64 v199; // [xsp+0h] [xbp-60h]
  bool v200; // [xsp+8h] [xbp-58h] BYREF
  unsigned int v201; // [xsp+Ch] [xbp-54h] BYREF
  __int16 v202; // [xsp+10h] [xbp-50h] BYREF
  _QWORD v203[7]; // [xsp+12h] [xbp-4Eh] BYREF
  _BYTE v204[11]; // [xsp+4Ah] [xbp-16h]
  __int64 v205; // [xsp+58h] [xbp-8h]

  v205 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v200 = 0;
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev or rsp is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "cm_connect_complete_ind");
    result = 4;
    goto LABEL_116;
  }
  v11 = *(_QWORD *)(a1 + 216);
  v12 = *(unsigned __int8 *)(a1 + 168);
  if ( !v11 )
  {
    v43 = *(unsigned int *)(a2 + 4);
    v44 = "%s: vdev %d cm_id 0x%x: pdev not found";
LABEL_19:
    qdf_trace_msg(
      0x68u,
      2u,
      v44,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "cm_connect_complete_ind",
      *(unsigned __int8 *)(a1 + 168),
      v43);
    result = 4;
    goto LABEL_116;
  }
  v14 = *(_QWORD *)(v11 + 80);
  if ( !v14 )
  {
    v43 = *(unsigned int *)(a2 + 4);
    v44 = "%s: vdev %d cm_id 0x%x: psoc not found";
    goto LABEL_19;
  }
  v15 = *(_DWORD *)(a1 + 16);
  cm_csr_connect_done_ind(a1, a2);
  v16 = *(_DWORD *)(a2 + 52);
  v201 = 0;
  *(_DWORD *)&v204[7] = 0;
  if ( v16 )
    v17 = 9;
  else
    v17 = 8;
  *(_QWORD *)v204 = 0;
  memset(v203, 0, sizeof(v203));
  v202 = v17;
  wlan_mlme_get_sta_ch_width(a1, &v201, nullptr);
  v18 = *(_QWORD *)(a1 + 40);
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, v19, v20, v21, v22, v23, v24, v25, v26);
  if ( !cmpt_obj )
  {
    v45 = "%s: vdev component object is NULL";
LABEL_22:
    qdf_trace_msg(0x68u, 2u, v45, v28, v29, v30, v31, v32, v33, v34, v35, "cm_cp_stats_cstats_log_connect_event");
    goto LABEL_54;
  }
  v36 = cmpt_obj;
  crypto_params = (_DWORD *)wlan_crypto_vdev_get_crypto_params(a1);
  if ( !crypto_params )
  {
    v45 = "%s: crypto params is null";
    goto LABEL_22;
  }
  v38 = *crypto_params;
  v39 = crypto_params;
  v40 = 0;
  if ( *crypto_params && (v38 & 3) == 0 )
  {
    if ( (v38 & 0x10) != 0 )
    {
      v40 = (crypto_params[1] & 0x18001) != 0;
    }
    else
    {
      if ( (v38 & 4) == 0 )
      {
        if ( (v38 & 0x6C8) != 0 )
        {
          v41 = (crypto_params[5] & 0x10300A1) == 0;
          v40 = 4;
          goto LABEL_30;
        }
        if ( (v38 & 0x20) != 0 )
        {
          v41 = (crypto_params[5] & 1) == 0;
          v40 = 2;
        }
        else
        {
          if ( (v38 & 0x100) == 0 )
          {
            v40 = 0;
            goto LABEL_32;
          }
          v41 = (crypto_params[5] & 0x2000) == 0;
          v40 = 6;
        }
LABEL_30:
        if ( v41 )
          ++v40;
        goto LABEL_32;
      }
      v40 = 1;
    }
  }
LABEL_32:
  v46 = *(_DWORD *)(a1 + 16);
  v47 = *(_BYTE *)(a1 + 168);
  v204[10] = v40;
  strcpy((char *)v203, "A");
  BYTE2(v203[0]) = v46;
  BYTE3(v203[0]) = v47;
  *(_QWORD *)((char *)v203 + 4) = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v49 = v201;
  v50 = *(_DWORD *)(a2 + 48);
  *(_QWORD *)((char *)&v203[1] + 4) = StatusReg;
  *(_WORD *)&v204[4] = v50;
  if ( v201 == 7 )
    v51 = 7;
  else
    v51 = -1;
  if ( v201 >= 7 )
    v49 = v51;
  v204[6] = v49;
  v52 = *(unsigned int *)(v18 + 28);
  if ( (unsigned int)v52 >= 0xB )
  {
    if ( (unsigned int)(v52 - 11) >= 0xA )
    {
      if ( (unsigned int)(v52 - 21) >= 0xA )
      {
        if ( (unsigned int)(v52 - 31) >= 0xA )
          v53 = -1;
        else
          v53 = 12;
      }
      else
      {
        v53 = 10;
      }
    }
    else
    {
      v53 = 5;
    }
  }
  else
  {
    v53 = byte_AEFE40[v52];
  }
  v54 = *(_QWORD *)(v36 + 536);
  v204[7] = v53;
  v204[8] = *(_BYTE *)(v54 + 24007);
  v55 = v39[1];
  if ( v55 )
  {
    if ( (v55 & 0x400) != 0 )
    {
      LOBYTE(v55) = 6;
    }
    else if ( (v55 & 0x200) != 0 )
    {
      LOBYTE(v55) = 5;
    }
    else if ( (v55 & 0x19CC) != 0 )
    {
      LOBYTE(v55) = 4;
    }
    else if ( (v55 & 2) != 0 )
    {
      LOBYTE(v55) = 3;
    }
    else if ( (v55 & 0x2010) != 0 )
    {
      LOBYTE(v55) = 7;
    }
    else if ( (v55 & 0x8001) != 0 )
    {
      LOBYTE(v55) = 1;
    }
    else
    {
      v55 = (v55 >> 15) & 2;
    }
  }
  v56 = *(_DWORD *)(a2 + 52);
  v204[9] = v55;
  v57 = *(unsigned __int8 *)(a2 + 14);
  *(_WORD *)&v204[2] = v56;
  LOBYTE(v203[3]) = v57;
  qdf_mem_copy((char *)&v203[3] + 1, (const void *)(a2 + 15), v57);
  v58 = *(_WORD *)(a2 + 9);
  v59 = *(_BYTE *)(a2 + 13);
  BYTE4(v203[2]) = *(_BYTE *)(a2 + 8);
  *(_WORD *)((char *)&v203[2] + 5) = v58;
  HIBYTE(v203[2]) = v59;
  wlan_cp_stats_cstats_write_to_buff(0, &v202, 69);
LABEL_54:
  cm_connect_info(
    a1,
    *(_DWORD *)(a2 + 52) == 0,
    (const void *)(a2 + 8),
    (unsigned __int8 *)(a2 + 14),
    *(_DWORD *)(a2 + 48));
  if ( !*(_DWORD *)(a2 + 52) )
  {
    if ( (*(_BYTE *)(a2 + 7) & 0x10) != 0 )
      ml_nlink_conn_change_notify(v14, v12, 1, 0);
    if ( (policy_mgr_ml_link_vdev_need_to_be_disabled(v14, a1, 0, v60, v61, v62, v63, v64, v65, v66, v67) & 1) != 0
      || (policy_mgr_is_hw_dbs_capable(v14) & 1) == 0
      && (wlan_vdev_mlme_is_mlo_vdev(a1, v76, v77, v78, v79, v80, v81, v82, v83) & 1) != 0
      && (*(_BYTE *)(a1 + 60) & 2) != 0 )
    {
      policy_mgr_update_flow_pool_map(v14, a1, v68, v69, v70, v71, v72, v73, v74, v75);
      policy_mgr_move_vdev_from_connection_to_disabled_tbl(v14, v12);
    }
    else
    {
      ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))policy_mgr_incr_active_session)(v14, v15, v12, 1);
    }
    ml_nlink_conn_change_notify(v14, v12, 6, 0);
    v84 = *(_QWORD *)(a2 + 80);
    v85 = *(unsigned __int8 *)(a1 + 168);
    if ( v84 )
    {
      v86 = *(_DWORD *)(a2 + 72);
      if ( v86 >= 0x19 )
        cm_update_prev_ap_ie(v14, *(unsigned __int8 *)(a1 + 168), v86 - 24, (const void *)(v84 + 24));
    }
    if ( (wlan_crypto_get_param(a1, 7u) & 0x10000800) != 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: Update the MDID in PMK cache for FT-SAE case",
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        "cm_process_connect_complete");
      cm_update_pmk_cache_ft(v14, v85, 0);
    }
    cm_update_owe_info(a1, a2);
    ((void (__fastcall *)(_QWORD))cm_csr_set_joined)(v85);
    cm_csr_send_set_ie(a1);
    param = wlan_crypto_get_param(a1, 1u);
    if ( (*(_BYTE *)(a2 + 1) & 1) != 0 )
    {
      v96 = 120000000;
    }
    else
    {
      if ( (*(_BYTE *)(a2 + 152) & 1) != 0
        || (param & 0xFFFDFFFF) == 0
        || (param & 0x8000) != 0
        || (param & 0x10001) != 0 )
      {
        cm_csr_set_ss_none(v85);
        if ( (wlan_vdev_mlme_is_mlo_vdev(a1, v113, v114, v115, v116, v117, v118, v119, v120) & 1) != 0 )
          mlo_enable_rso(v11, a1, a2);
        else
          cm_roam_start_init_on_connect(v11, v85);
        goto LABEL_80;
      }
      v96 = 70000000;
    }
    v97 = cm_csr_set_ss_wait_for_key(v85);
    if ( (unsigned int)cm_start_wait_for_key_timer(a1, v96, v97, v98, v99, v100, v101, v102, v103, v104) )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Failed wait for key timer start",
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        "cm_update_wait_for_key_timer");
      cm_csr_set_ss_none(v85);
    }
LABEL_80:
    if ( !*(_DWORD *)(a1 + 16) && (*(_BYTE *)(a1 + 60) & 2) != 0 )
    {
      HIDWORD(v199) = *(unsigned __int8 *)(a1 + 168);
      v121 = wlan_crypto_vdev_get_crypto_params(a1);
      if ( v121 )
      {
        v122 = *(_DWORD *)(v121 + 4);
        if ( v122 && (v122 & 0x20000) == 0 )
        {
          v123 = *(unsigned __int8 *)(a1 + 93);
          if ( (wlan_cm_is_link_add_connecting(a1, v105, v106, v107, v108, v109, v110, v111, v112) & 1) == 0
            && (mlo_mgr_is_link_add_link_switch(a1) & 1) == 0 )
          {
            if ( (mlo_is_set_key_defered(a1, v123) & 1) == 0 && (mlo_mgr_is_link_switch_in_progress(a1) & 1) == 0 )
            {
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: keys are not deferred for link_id %d",
                v169,
                v170,
                v171,
                v172,
                v173,
                v174,
                v175,
                v176,
                "cm_install_link_vdev_keys",
                v123);
              goto LABEL_89;
            }
            LODWORD(v199) = v123;
            wlan_crypto_aquire_lock();
            v177 = 0;
            v178 = 0;
            while ( 1 )
            {
              key = wlan_crypto_get_key(a1, 0, v177);
              if ( key )
              {
                v180 = *(_DWORD *)(key + 12);
                v181 = v180 == 0;
                if ( (unsigned int)mlme_cm_osif_send_keys(a1, v177, v181) )
                {
                  v198 = v199;
                  qdf_trace_msg(
                    0x8Fu,
                    2u,
                    "%s: MLO: fail to send key for vdev_id %d link_id %d , key_idx %d, pairwise %d",
                    v182,
                    v183,
                    v184,
                    v185,
                    v186,
                    v187,
                    v188,
                    v189,
                    "cm_install_link_vdev_keys",
                    HIDWORD(v199),
                    (unsigned int)v199,
                    v177,
                    v181);
                  wlan_crypto_release_lock();
                  if ( (v178 & 1) != 0 )
                  {
LABEL_130:
                    mlo_defer_set_keys(a1, v198, 0);
                    goto LABEL_89;
                  }
LABEL_129:
                  qdf_trace_msg(
                    0x68u,
                    2u,
                    "%s: No key found for link_id %d",
                    v190,
                    v191,
                    v192,
                    v193,
                    v194,
                    v195,
                    v196,
                    v197,
                    "cm_install_link_vdev_keys",
                    v198,
                    v199);
                  mlo_disconnect(a1, 5, 65514, 0);
                  goto LABEL_130;
                }
                qdf_trace_msg(
                  0x8Fu,
                  8u,
                  "%s: MLO: send keys for vdev_id %d link_id %d , key_idx %d, pairwise %d",
                  v182,
                  v183,
                  v184,
                  v185,
                  v186,
                  v187,
                  v188,
                  v189,
                  "cm_install_link_vdev_keys",
                  HIDWORD(v199),
                  (unsigned int)v199,
                  v177,
                  v180 == 0);
                if ( !v180 )
                  mlo_defer_set_keys(a1, (unsigned int)v199, 0);
                v178 = 1;
              }
              if ( ++v177 == 8 )
              {
                wlan_crypto_release_lock();
                v198 = v199;
                if ( (v178 & 1) != 0 )
                  goto LABEL_130;
                goto LABEL_129;
              }
            }
          }
          mlo_link_recfg_install_unicast_keys(a1);
        }
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: crypto params is null",
          v105,
          v106,
          v107,
          v108,
          v109,
          v110,
          v111,
          v112,
          "cm_install_link_vdev_keys");
      }
    }
LABEL_89:
    tdls_chan_switch_prohibited = mlme_get_tdls_chan_switch_prohibited(
                                    a1,
                                    v105,
                                    v106,
                                    v107,
                                    v108,
                                    v109,
                                    v110,
                                    v111,
                                    v112);
    tdls_prohibited = mlme_get_tdls_prohibited(a1, v125, v126, v127, v128, v129, v130, v131, v132);
    v134 = wlan_tdls_notify_sta_connect(v12, tdls_chan_switch_prohibited & 1, tdls_prohibited & 1, a1);
    wlan_p2p_status_connect(a1, v134, v135, v136, v137, v138, v139, v140, v141);
    if ( *(_QWORD *)(a1 + 1360)
      && wlan_cm_is_vdev_connected(a1, v142, v143, v144, v145, v146, v147, v148, v149)
      && (*(_BYTE *)(a1 + 60) & 2) != 0
      && (mlo_check_if_all_links_up(a1) & 1) != 0 )
    {
      v158 = *(_QWORD *)(*(_QWORD *)(a1 + 1360) + 2224LL);
      if ( v158 == -320 )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: T2LM ctx is NULL",
          v150,
          v151,
          v152,
          v153,
          v154,
          v155,
          v156,
          v157,
          "cm_update_tid_mapping");
      }
      else
      {
        if ( (unsigned int)wlan_update_t2lm_mapping(a1, v158 + 320, *(_QWORD *)(v158 + 672)) )
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: T2LM IE beacon process failed",
            v159,
            v160,
            v161,
            v162,
            v163,
            v164,
            v165,
            v166,
            "cm_update_tid_mapping");
        ((void (__fastcall *)(__int64))wlan_connectivity_t2lm_status_event)(a1);
      }
    }
    cm_update_associated_ch_info(a1, 1);
    wlan_psoc_mlme_get_11be_capab(v14, &v200);
    if ( v200 && (unsigned int)policy_mgr_current_connections_update(v14, v12, *(_DWORD *)(a2 + 48), 0xEu, 0) == 16 )
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: Failed to take next action after connect",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "cm_connect_complete_ind");
    if ( !*(_DWORD *)(a2 + 52) )
      goto LABEL_111;
  }
  if ( (*(_BYTE *)(a2 + 7) & 0x30) == 0 )
  {
    v167 = *(_QWORD *)(a1 + 216);
    if ( v167 )
      v168 = *(_QWORD *)(v167 + 80);
    else
      v168 = 0;
    ucfg_policy_mgr_post_sta_p2p_start_failed(v168, *(unsigned __int8 *)(a1 + 168));
  }
LABEL_111:
  if ( !v15
    && ((*(_BYTE *)(a1 + 60) & 2) != 0
     || (wlan_vdev_mlme_is_mlo_vdev(a1, v60, v61, v62, v63, v64, v65, v66, v67) & 1) == 0) )
  {
    wlan_cm_roam_state_change(v11, v12, 1, 1);
  }
  result = 0;
LABEL_116:
  _ReadStatusReg(SP_EL0);
  return result;
}
