__int64 __fastcall hdd_vdev_create(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x20
  __int64 v11; // x1
  __int64 *v12; // x20
  __int64 v13; // x28
  __int64 v14; // x22
  unsigned __int64 StatusReg; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 link_info_by_vdev; // x21
  _QWORD *v25; // x23
  _QWORD *v26; // x27
  int v27; // w8
  _QWORD *v28; // x9
  unsigned int v29; // w26
  _QWORD *context; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x8
  __int64 v40; // x9
  __int64 adapter; // x0
  __int64 v42; // x23
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned __int64 v59; // x8
  __int64 v60; // x8
  char v61; // w9
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x21
  _WORD *v71; // x1
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  int v80; // w8
  __int64 v81; // x0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x21
  __int64 result; // x0
  __int64 v92; // x20
  _QWORD *v93; // x8
  unsigned __int64 v94; // x8
  __int64 v95; // x8
  char v96; // w9
  unsigned int setup; // w0
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  unsigned int v106; // w22
  unsigned int v107; // w20
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  unsigned int v116; // w0
  unsigned int v117; // w0
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  int v126; // w8
  __int64 v127; // x22
  __int64 v128; // x0
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  unsigned int v137; // w0
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  __int64 v154; // x23
  unsigned int v155; // w23
  char support_mp0_discovery; // w0
  __int64 v157; // x3
  __int64 v158; // x0
  __int64 v159; // x2
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  unsigned int rts_profile; // w0
  __int64 v169; // x4
  const char *v170; // x2
  unsigned int v171; // w0
  unsigned __int64 v178; // x9
  unsigned __int64 v181; // x9
  __int64 v182; // [xsp+8h] [xbp-78h] BYREF
  __int64 v183; // [xsp+10h] [xbp-70h]
  __int64 v184; // [xsp+18h] [xbp-68h]
  _QWORD v185[2]; // [xsp+20h] [xbp-60h] BYREF
  __int64 v186; // [xsp+30h] [xbp-50h]
  _QWORD v187[8]; // [xsp+40h] [xbp-40h] BYREF

  v187[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)a1;
  v185[1] = 0;
  v186 = 0;
  v184 = 0;
  v185[0] = 0;
  v182 = 0;
  v183 = 0;
  qdf_trace_msg(0x33u, 8u, "creating new vdev", a2, a3, a4, a5, a6, a7, a8, a9);
  v12 = *(__int64 **)(v10 + 24);
  v13 = v12[1];
  if ( *(unsigned __int8 *)(v13 + 41) < (unsigned int)*((unsigned __int8 *)v12 + 852) )
    goto LABEL_34;
  v14 = *v12;
  if ( (ucfg_p2p_get_sta_vdev_for_p2p_dev_upon_vdev_exhaust_cap(*v12, v11) & 1) == 0 )
    goto LABEL_34;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v13 + 1240);
  }
  else
  {
    raw_spin_lock_bh(v13 + 1240);
    *(_QWORD *)(v13 + 1248) |= 1uLL;
  }
  v187[0] = 0;
  link_info_by_vdev = 0;
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(v13 + 48), v187) )
  {
    v26 = nullptr;
  }
  else
  {
    v25 = (_QWORD *)v187[0];
    v26 = nullptr;
    if ( v187[0] )
    {
      v26 = nullptr;
      link_info_by_vdev = 0;
      do
      {
        v27 = *(_DWORD *)((char *)&off_10 + (_QWORD)v25);
        if ( v27 )
          v28 = nullptr;
        else
          v28 = v25;
        if ( !v26 )
          v26 = v28;
        if ( v27 == 7 )
        {
          v29 = *((unsigned __int8 *)&dword_68 + (_QWORD)v25);
          context = _cds_get_context(
                      51,
                      (__int64)"wlan_hdd_get_link_info_from_vdev",
                      v16,
                      v17,
                      v18,
                      v19,
                      v20,
                      v21,
                      v22,
                      v23);
          link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)context, v29);
          if ( !link_info_by_vdev )
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: vdev %d Get adapter by vdev id failed",
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              "wlan_hdd_get_link_info_from_vdev",
              v29);
        }
        v187[0] = 0;
        if ( (unsigned int)qdf_list_peek_next((_QWORD *)(v13 + 48), v25, v187) )
          break;
        v25 = (_QWORD *)v187[0];
      }
      while ( v187[0] );
    }
  }
  v39 = v12[1];
  v40 = *(_QWORD *)(v39 + 1248);
  if ( (v40 & 1) != 0 )
  {
    *(_QWORD *)(v39 + 1248) = v40 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v39 + 1240);
    if ( !link_info_by_vdev )
      goto LABEL_34;
  }
  else
  {
    raw_spin_unlock(v39 + 1240);
    if ( !link_info_by_vdev )
      goto LABEL_34;
  }
  adapter = hdd_get_adapter((__int64)v12, 0);
  if ( adapter )
  {
    v42 = adapter;
    if ( (*(_QWORD *)(adapter + 1624) & 4) != 0 )
    {
      ucfg_p2p_set_sta_vdev_for_p2p_dev_operations(v14, 1);
      ucfg_p2p_psoc_priv_set_sta_vdev_id(*v12, *(_BYTE *)(*(_QWORD *)(v42 + 52824) + 8LL));
      if ( (unsigned int)wlan_mlme_set_p2p_device_mac_addr(
                           *(_QWORD *)(*(_QWORD *)(v42 + 52824) + 32LL),
                           (int *)(*(_QWORD *)link_info_by_vdev + 1617LL),
                           v43,
                           v44,
                           v45,
                           v46,
                           v47,
                           v48,
                           v49,
                           v50) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to set p2p mac addr",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "hdd_cache_p2p_macaddr_in_vdev");
      hdd_vdev_destroy(link_info_by_vdev, v51, v52, v53, v54, v55, v56, v57, v58);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v59 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v59 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v59 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(link_info_by_vdev + 16);
        v60 = *(_QWORD *)(link_info_by_vdev + 24);
      }
      else
      {
        raw_spin_lock_bh(link_info_by_vdev + 16);
        v60 = *(_QWORD *)(link_info_by_vdev + 24) | 1LL;
        *(_QWORD *)(link_info_by_vdev + 24) = v60;
      }
      v61 = *(_BYTE *)(*(_QWORD *)(v42 + 52824) + 8LL);
      *(_QWORD *)(link_info_by_vdev + 32) = v26;
      *(_BYTE *)(link_info_by_vdev + 8) = v61;
      if ( (v60 & 1) != 0 )
      {
        *(_QWORD *)(link_info_by_vdev + 24) = v60 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(link_info_by_vdev + 16);
      }
      else
      {
        raw_spin_unlock(link_info_by_vdev + 16);
      }
      _X8 = (unsigned __int64 *)(link_info_by_vdev + 4416);
      __asm { PRFM            #0x11, [X8] }
      do
        v181 = __ldxr(_X8);
      while ( __stxr(v181 | 1, _X8) );
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: max vdev create limit reached, use sta vdev for p2p device operation",
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        "hdd_vdev_create");
    }
  }
LABEL_34:
  v70 = *(_QWORD *)a1;
  v71 = (_WORD *)(*(_QWORD *)a1 + 1617LL);
  LODWORD(v182) = *(_DWORD *)(*(_QWORD *)a1 + 40LL);
  qdf_ether_addr_copy(v185, v71);
  if ( (*(_DWORD *)(v70 + 40) & 0xFFFFFFFE) == 2 )
    v80 = *(unsigned __int8 *)(v70 + 57448);
  else
    v80 = 255;
  HIDWORD(v186) = v80;
  v183 = 56;
  if ( LODWORD(v185[0]) | WORD2(v185[0]) )
  {
    v81 = sme_vdev_create(v12[2], &v182);
    if ( !v81 )
    {
      qdf_trace_msg(0x33u, 2u, "%s: failed to create vdev", v82, v83, v84, v85, v86, v87, v88, v89, "hdd_vdev_create");
      result = 4294967274LL;
      goto LABEL_64;
    }
    v90 = v81;
    if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(v81, 5u, v82, v83, v84, v85, v86, v87, v88, v89) )
    {
      sme_vdev_delete(v12[2], v90);
      result = 4294967274LL;
      goto LABEL_64;
    }
    v93 = *(_QWORD **)(v90 + 608);
    if ( v93 )
    {
      *v93 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 32LL) + 992LL);
      v93[1] = a1;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v94 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v94 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v94 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 16);
      v95 = *(_QWORD *)(a1 + 24);
    }
    else
    {
      raw_spin_lock_bh(a1 + 16);
      v95 = *(_QWORD *)(a1 + 24) | 1LL;
      *(_QWORD *)(a1 + 24) = v95;
    }
    v96 = *(_BYTE *)(v90 + 104);
    *(_QWORD *)(a1 + 32) = v90;
    *(_BYTE *)(a1 + 8) = v96;
    if ( (v95 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 24) = v95 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 16);
    }
    else
    {
      raw_spin_unlock(a1 + 16);
    }
    osif_cm_osif_priv_init(v90);
    _X8 = (unsigned __int64 *)(a1 + 4416);
    __asm { PRFM            #0x11, [X8] }
    do
      v178 = __ldxr(_X8);
    while ( __stxr(v178 | 1, _X8) );
    setup = sme_vdev_post_vdev_create_setup(v12[2], v90);
    if ( setup )
    {
      v106 = setup;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to setup the vdev",
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        "hdd_vdev_create");
      v107 = qdf_status_to_os_return(v106);
LABEL_63:
      hdd_vdev_destroy(a1, v108, v109, v110, v111, v112, v113, v114, v115);
      result = v107;
      goto LABEL_64;
    }
    v116 = pmo_vdev_ready(v90, v12 + 1026);
    if ( !v116 )
    {
      v116 = ucfg_reg_11d_vdev_created_update(v90);
      if ( !v116 )
      {
        if ( (wma_capability_enhanced_mcast_filter() & 1) != 0 )
          v116 = pmo_core_enhanced_mc_filter_enable(v90);
        else
          v116 = pmo_core_enhanced_mc_filter_disable(v90);
      }
    }
    v117 = qdf_status_to_os_return(v116);
    if ( v117 )
    {
      v107 = v117;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to dispatch vdev ready event: %d",
        v118,
        v119,
        v120,
        v121,
        v122,
        v123,
        v124,
        v125,
        "hdd_vdev_create");
      goto LABEL_63;
    }
    v126 = *(_DWORD *)(v90 + 16);
    v127 = *v12;
    if ( v126 == 16 )
    {
      v155 = *(unsigned __int8 *)(v90 + 104);
      support_mp0_discovery = cfg_nan_get_support_mp0_discovery(*v12);
      sme_cli_set_command(v155, 156, support_mp0_discovery & 1, 1);
    }
    else
    {
      if ( v126 != 2 )
      {
        if ( v126 )
          goto LABEL_79;
        v128 = *v12;
        LOBYTE(v187[0]) = 0;
        if ( (unsigned int)wlan_mlme_get_rtt_mac_randomization(v128, v187) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: unable to get RTT MAC randomization value",
            v129,
            v130,
            v131,
            v132,
            v133,
            v134,
            v135,
            v136,
            "hdd_vdev_configure_rtt_mac_randomization");
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: setting RTT mac randomization param: %d",
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          "hdd_vdev_configure_rtt_mac_randomization",
          LOBYTE(v187[0]));
        v137 = sme_cli_set_command(*(unsigned __int8 *)(v90 + 104), 129, LOBYTE(v187[0]), 1);
        if ( v137 )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: RTT mac randomization param set failed %d",
            v138,
            v139,
            v140,
            v141,
            v142,
            v143,
            v144,
            v145,
            "hdd_vdev_configure_rtt_mac_randomization",
            v137);
      }
      LOBYTE(v187[0]) = 0;
      *(_WORD *)(v90 + 162) = cfg_tdls_get_max_peer_count(v127) + 19;
      wlan_mlme_get_bigtk_support(v127, v187);
      if ( LOBYTE(v187[0]) == 1 )
        mlme_set_bigtk_support(v90, 1, v146, v147, v148, v149, v150, v151, v152, v153);
      v154 = *(_QWORD *)a1;
      if ( (unsigned int)cds_get_conparam() != 5 && v154 )
        mlme_set_user_ps(v127, *(unsigned __int8 *)(v90 + 104), *(_BYTE *)(v154 + 1616));
      *(_BYTE *)(v90 + 92) = 0;
    }
LABEL_79:
    ucfg_fwol_configure_vdev_params(v127, v90);
    v157 = *((unsigned int *)v12 + 312);
    v158 = v12[2];
    v159 = *(unsigned int *)(v90 + 16);
    memset(v187, 0, 56);
    sme_populate_nss_chain_params(v158, v187, v159, v157);
    sme_store_nss_chains_cfg_in_vdev(v90, v187);
    LOWORD(v187[0]) = 0;
    if ( (unsigned int)cds_get_conparam() != 5 )
    {
      rts_profile = ucfg_fwol_get_rts_profile(*v12, v187);
      if ( rts_profile )
      {
        v169 = rts_profile;
        v170 = "%s: FAILED TO GET RTSCTS Profile status:%d";
LABEL_84:
        qdf_trace_msg(
          0x33u,
          2u,
          v170,
          v160,
          v161,
          v162,
          v163,
          v164,
          v165,
          v166,
          v167,
          "hdd_vdev_configure_rtscts_enable",
          v169);
        goto LABEL_85;
      }
      v171 = sme_cli_set_command(*(unsigned __int8 *)(v90 + 104), 44, LOWORD(v187[0]), 1);
      if ( v171 )
      {
        v169 = v171;
        v170 = "%s: FAILED TO SET RTSCTS Profile ret:%d";
        goto LABEL_84;
      }
    }
LABEL_85:
    qdf_trace_msg(
      0x33u,
      8u,
      "vdev %d created successfully",
      v160,
      v161,
      v162,
      v163,
      v164,
      v165,
      v166,
      v167,
      *(unsigned __int8 *)(a1 + 8));
    result = 0;
    goto LABEL_64;
  }
  v92 = jiffies;
  if ( hdd_populate_vdev_create_params___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: invalid mac addr",
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      "hdd_populate_vdev_create_params");
    hdd_populate_vdev_create_params___last_ticks = v92;
  }
  result = 4294967274LL;
LABEL_64:
  _ReadStatusReg(SP_EL0);
  return result;
}
