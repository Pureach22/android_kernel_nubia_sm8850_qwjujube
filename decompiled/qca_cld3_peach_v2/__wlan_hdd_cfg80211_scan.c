__int64 __fastcall _wlan_hdd_cfg80211_scan(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x8
  __int64 v15; // x21
  __int64 *v16; // x19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v25; // x2
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  const char *v51; // x2
  unsigned int v52; // w1
  unsigned int v53; // w0
  const char *v54; // x4
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  const char *v63; // x2
  unsigned int v64; // w1
  __int64 con_sap_adapter; // x0
  _DWORD *v66; // x8
  unsigned int v67; // w24
  int v68; // w25
  __int64 v69; // x22
  int v70; // w5
  __int64 v71; // x7
  unsigned int v72; // w9
  __int64 v73; // x8
  const void *v74; // x1
  size_t v75; // x0
  void *v76; // x0
  __int64 v77; // x23
  size_t v78; // x2
  int v79; // w8
  unsigned __int8 sta_vdev_id; // w0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 sta_vdev_for_p2p_dev; // x0
  __int64 v90; // x22
  unsigned __int8 *v91; // x0
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  int v100; // w8
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
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
  unsigned int v133; // w19
  unsigned int *v134; // x8
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  __int64 v143; // x0
  __int64 v144; // x1
  __int64 v145; // x2
  __int64 v146; // x3
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
  size_t v163; // x25
  int v164; // [xsp+14h] [xbp-6Ch] BYREF
  char v165[4]; // [xsp+18h] [xbp-68h] BYREF
  char v166[4]; // [xsp+1Ch] [xbp-64h] BYREF
  __int64 v167; // [xsp+20h] [xbp-60h] BYREF
  __int64 v168; // [xsp+28h] [xbp-58h]
  __int64 v169; // [xsp+30h] [xbp-50h]
  __int64 v170; // [xsp+38h] [xbp-48h]
  __int64 v171; // [xsp+40h] [xbp-40h]
  __int64 v172; // [xsp+48h] [xbp-38h]
  __int64 v173; // [xsp+50h] [xbp-30h]
  __int64 v174; // [xsp+58h] [xbp-28h]
  __int64 v175; // [xsp+60h] [xbp-20h] BYREF
  __int64 v176; // [xsp+68h] [xbp-18h]
  int v177; // [xsp+70h] [xbp-10h] BYREF
  char v178[4]; // [xsp+74h] [xbp-Ch] BYREF
  __int64 v179; // [xsp+78h] [xbp-8h]

  v179 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a2 + 64);
  v178[0] = 0;
  v177 = 0;
  v15 = *(_QWORD *)(v14 + 32);
  v175 = 0;
  v176 = 0;
  v173 = 0;
  v174 = 0;
  v16 = *(__int64 **)(v15 + 2712);
  v171 = 0;
  v172 = 0;
  v169 = 0;
  v170 = 0;
  v167 = 0;
  v168 = 0;
  v166[0] = 0;
  v165[0] = 0;
  v164 = 0;
  if ( cds_is_fw_down(a4, a5, a6, a7, a8, a9, a10, a11) )
  {
    v25 = "%s: firmware is down, scan cmd cannot be processed";
LABEL_5:
    qdf_trace_msg(0x33u, 2u, v25, v17, v18, v19, v20, v21, v22, v23, v24, "__wlan_hdd_cfg80211_scan");
LABEL_6:
    result = 4294967274LL;
    goto LABEL_7;
  }
  if ( (unsigned int)hdd_get_conparam() == 5 )
  {
    v25 = "%s: Command not allowed in FTM mode";
    goto LABEL_5;
  }
  if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                       *(_BYTE *)(a1 + 8),
                       (__int64)"__wlan_hdd_cfg80211_scan",
                       v17,
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23,
                       v24) )
    goto LABEL_6;
  result = _wlan_hdd_validate_context(
             (__int64)v16,
             (__int64)"__wlan_hdd_cfg80211_scan",
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             v34);
  if ( (_DWORD)result )
    goto LABEL_7;
  qdf_mtrace(51, 51, 0x2Cu, *(_BYTE *)(a1 + 8), *(_DWORD *)(a2 + 12));
  if ( (sme_is_session_id_valid(v16[2], *(unsigned __int8 *)(a1 + 8)) & 1) == 0 )
    goto LABEL_6;
  if ( (unsigned int)wlan_mlme_get_self_recovery(*v16, v166) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to get self recovery ini config",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "__wlan_hdd_cfg80211_scan");
    result = 4294967291LL;
    goto LABEL_7;
  }
  if ( (ucfg_scan_is_connected_scan_enabled(*v16) & 1) == 0 && hdd_cm_is_vdev_associated((_DWORD *)a1) )
  {
    v51 = "%s: enable_connected_scan is false, Aborting scan";
    v52 = 4;
    goto LABEL_16;
  }
  v53 = *(_DWORD *)(v15 + 2728);
  if ( v53 == 11 || v53 == 6 )
  {
    v54 = qdf_opmode_str(v53);
    v63 = "%s: Scan not supported for %s";
    v64 = 2;
LABEL_21:
    qdf_trace_msg(0x33u, v64, v63, v55, v56, v57, v58, v59, v60, v61, v62, "__wlan_hdd_cfg80211_scan", v54);
    goto LABEL_6;
  }
  con_sap_adapter = hdd_get_con_sap_adapter(v15 + 2688, 1);
  if ( con_sap_adapter )
  {
    v66 = *(_DWORD **)(con_sap_adapter + 52832);
    v67 = v66[180];
    if ( !v67 )
      v67 = v66[606];
    v68 = v66[182];
    if ( (policy_mgr_is_hw_dbs_capable(*v16) & 1) == 0
      && (policy_mgr_is_sta_present_on_freq(*v16, v165, v67, &v164) & 1) == 0
      && ((wlan_reg_is_dfs_for_freq(v16[1], v67, v43, v44, v45, v46, v47, v48, v49, v50) & 1) != 0
       || wlan_reg_is_5ghz_ch_freq(v67) && v68 == 3) )
    {
      v51 = "%s: ##In DFS Master mode. Scan aborted";
      v52 = 2;
LABEL_16:
      qdf_trace_msg(0x33u, v52, v51, v43, v44, v45, v46, v47, v48, v49, v50, "__wlan_hdd_cfg80211_scan");
      if ( (unsigned int)wlan_hdd_enqueue_blocked_scan_request(v15, a2, a3) )
      {
        result = 4294967285LL;
      }
      else
      {
        queue_work_on(32, system_wq, v15 + 44392);
        result = 0;
      }
      goto LABEL_7;
    }
  }
  if ( (hdd_is_connection_in_progress(v178, &v177, v43, v44, v45, v46, v47, v48, v49, v50) & 1) != 0 )
  {
    ++_wlan_hdd_cfg80211_scan_scan_ebusy_cnt;
    v69 = jiffies;
    if ( _wlan_hdd_cfg80211_scan___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Scan not allowed. scan_ebusy_cnt: %d Session %d Reason %d",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "__wlan_hdd_cfg80211_scan");
      _wlan_hdd_cfg80211_scan___last_ticks = v69;
    }
    v70 = v177;
    if ( *((unsigned __int8 *)v16 + 1803) == (unsigned __int8)v178[0]
      && *((_DWORD *)v16 + 451) == v177
      && (v71 = v16[226]) != 0 )
    {
      v72 = (unsigned __int8)++*((_BYTE *)v16 + 1816);
      if ( v72 >= 0xF && v71 - jiffies < 0 )
      {
        v143 = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: scan reject threshold reached Session %d Reason %d count %d reject timestamp %lu jiffies %lu",
                 v55,
                 v56,
                 v57,
                 v58,
                 v59,
                 v60,
                 v61,
                 v62,
                 "__wlan_hdd_cfg80211_scan",
                 jiffies);
        v16[226] = 0;
        *((_BYTE *)v16 + 1816) = 0;
        if ( (cds_is_fatal_event_enabled(v143, v144, v145, v146) & 1) != 0 )
        {
          cds_flush_logs(1u, 2u, 11, 0, v166[0], v147, v148, v149, v150, v151, v152, v153, v154);
        }
        else
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Triggering SSR due to scan stuck",
            v147,
            v148,
            v149,
            v150,
            v151,
            v152,
            v153,
            v154,
            "__wlan_hdd_cfg80211_scan");
          _cds_trigger_recovery(
            5,
            (__int64)"__wlan_hdd_cfg80211_scan",
            595,
            v155,
            v156,
            v157,
            v158,
            v159,
            v160,
            v161,
            v162);
        }
        result = 4294967280LL;
      }
      else
      {
        result = 4294967280LL;
      }
    }
    else
    {
      *((_BYTE *)v16 + 1803) = v178[0];
      result = 4294967280LL;
      *((_DWORD *)v16 + 451) = v70;
      v73 = jiffies;
      *((_BYTE *)v16 + 1816) = 0;
      v16[226] = v73 + 75000;
    }
    goto LABEL_7;
  }
  if ( v16 )
  {
    v16[226] = 0;
    *((_BYTE *)v16 + 1803) = -1;
    *((_DWORD *)v16 + 451) = 0;
    *((_BYTE *)v16 + 1816) = 0;
  }
  v54 = *(const char **)(a2 + 24);
  LOBYTE(v167) = a3;
  LODWORD(v168) = 0;
  if ( v54 )
  {
    if ( (unsigned __int64)v54 >= 0x801 )
    {
      v63 = "%s: Invalid ie_len: %zu";
      v64 = 8;
      goto LABEL_21;
    }
    memset((void *)(v15 + 42312), 0, 0x804u);
    v78 = *(_QWORD *)(a2 + 24);
    if ( v78 >= 0x803 && (_wlan_hdd_cfg80211_scan___already_done & 1) == 0 )
    {
      _wlan_hdd_cfg80211_scan___already_done = 1;
      v163 = v78;
      _warn_printk(
        "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
        v78,
        "field \"scan_info->scan_add_ie.addIEdata\" at ../vendor/qcom/opensource/wlan/qcacld-3.0/core/hdd/src/wlan_hdd_scan.c:626",
        0x802u);
      v78 = v163;
      __break(0x800u);
    }
    memcpy((void *)(v15 + 42314), *(const void **)(a2 + 16), v78);
    *(_WORD *)(v15 + 42312) = *(_QWORD *)(a2 + 24);
    wlan_hdd_update_scan_ies(v15 + 42312, v15 + 42314, v15 + 42312);
  }
  else
  {
    v74 = *(const void **)(v15 + 44368);
    if ( v74 && *(_WORD *)(v15 + 44376) )
    {
      qdf_mem_copy((void *)(v15 + 42314), v74, *(unsigned __int16 *)(v15 + 44376));
      v75 = *(unsigned __int16 *)(v15 + 44376);
      *(_WORD *)(v15 + 42312) = v75;
      v76 = (void *)_qdf_mem_malloc(v75, "__wlan_hdd_cfg80211_scan", 641);
      v77 = (__int64)v76;
      v169 = (__int64)v76;
      if ( v76 )
      {
        qdf_mem_copy(v76, *(const void **)(v15 + 44368), *(unsigned __int16 *)(v15 + 44376));
        LODWORD(v168) = *(unsigned __int16 *)(v15 + 44376);
      }
      goto LABEL_56;
    }
  }
  v77 = 0;
LABEL_56:
  v79 = *(_DWORD *)(v15 + 2728);
  if ( v79 != 7 && v79 != 2 )
    goto LABEL_63;
  if ( (ucfg_nan_is_sta_p2p_ndp_supported(*v16) & 1) == 0 )
    ucfg_nan_disable_concurrency(*v16);
  if ( *(_DWORD *)(v15 + 2728) == 7 && (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(*v16) & 1) != 0 )
  {
    LODWORD(v176) = 7;
    sta_vdev_id = ucfg_p2p_psoc_priv_get_sta_vdev_id(*v16);
    sta_vdev_for_p2p_dev = wlan_hdd_get_sta_vdev_for_p2p_dev(
                             *v16,
                             sta_vdev_id,
                             0x4Fu,
                             v81,
                             v82,
                             v83,
                             v84,
                             v85,
                             v86,
                             v87,
                             v88);
  }
  else
  {
LABEL_63:
    sta_vdev_for_p2p_dev = _hdd_objmgr_get_vdev_by_user(a1, 0x4Fu, (__int64)"__wlan_hdd_cfg80211_scan");
  }
  v90 = sta_vdev_for_p2p_dev;
  if ( sta_vdev_for_p2p_dev )
  {
    if ( *(_DWORD *)(a2 + 8) == 1 )
    {
      v91 = *(unsigned __int8 **)a2;
      if ( *(_QWORD *)a2 )
      {
        if ( v91[32] >= 8u && !(unsigned int)qdf_mem_cmp(v91, "DIRECT-", 7u) )
          ucfg_p2p_status_scan(v90, v92, v93, v94, v95, v96, v97, v98, v99);
      }
    }
    if ( *(_DWORD *)(v15 + 2728) == 1 )
      v100 = 3;
    else
      v100 = 5;
    LODWORD(v172) = v100;
    if ( (unsigned int)wlan_mlme_get_scan_probe_unicast_ra(*v16, (_BYTE *)&v175 + 4) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to get unicast probe req ra cfg",
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        v107,
        v108,
        "__wlan_hdd_cfg80211_scan");
    HIBYTE(v175) = wlan_mlme_get_eht_mld_id(*v16);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: MLD ID: %d",
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      v115,
      v116,
      "__wlan_hdd_cfg80211_scan",
      HIBYTE(v175));
    if ( cds_is_10_mhz_enabled(v117, v118, v119, v120, v121, v122, v123, v124) )
      BYTE4(v172) = 1;
    if ( cds_is_5_mhz_enabled(v125, v126, v127, v128, v129, v130, v131, v132) )
      BYTE5(v172) = 1;
    v133 = wlan_cfg80211_scan(v90, a2, (char *)&v167);
    _hdd_objmgr_put_vdev_by_user(
      v90,
      0x4Fu,
      (__int64)"__wlan_hdd_cfg80211_scan",
      v134,
      v135,
      v136,
      v137,
      v138,
      v139,
      v140,
      v141,
      v142);
    v77 = v169;
  }
  else
  {
    v133 = -22;
  }
  if ( v77 )
    _qdf_mem_free(v77);
  result = v133;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
