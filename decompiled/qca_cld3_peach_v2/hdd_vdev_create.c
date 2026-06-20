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
  __int64 v10; // x24
  __int64 v11; // x1
  __int64 *v12; // x20
  __int64 v13; // x27
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
  _QWORD *v26; // x28
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
  __int64 v70; // x8
  unsigned int v71; // w10
  int v72; // w10
  _WORD *v73; // x1
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x0
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v91; // x21
  __int64 result; // x0
  __int64 v93; // x20
  _QWORD *v94; // x8
  unsigned __int64 v95; // x8
  __int64 v96; // x8
  char v97; // w9
  unsigned int setup; // w0
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  unsigned int v107; // w22
  unsigned int v108; // w20
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  unsigned int v117; // w0
  unsigned int v118; // w0
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  unsigned int v127; // w23
  __int64 v128; // x22
  __int64 v129; // x0
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  unsigned int v138; // w0
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  __int64 v155; // x23
  __int64 v156; // x0
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  __int64 v165; // x23
  unsigned int v166; // w23
  char support_mp0_discovery; // w0
  __int64 v168; // x3
  __int64 v169; // x0
  __int64 v170; // x2
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  unsigned int rts_profile; // w0
  __int64 v180; // x4
  const char *v181; // x2
  unsigned int v182; // w0
  unsigned __int64 v189; // x9
  unsigned __int64 v192; // x9
  __int64 v193; // [xsp+0h] [xbp-80h]
  __int64 v194; // [xsp+8h] [xbp-78h] BYREF
  __int64 v195; // [xsp+10h] [xbp-70h]
  __int64 v196; // [xsp+18h] [xbp-68h]
  __int64 v197; // [xsp+20h] [xbp-60h] BYREF
  __int64 v198; // [xsp+28h] [xbp-58h] BYREF
  __int64 v199; // [xsp+30h] [xbp-50h]
  _QWORD v200[8]; // [xsp+40h] [xbp-40h] BYREF

  v200[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)a1;
  v198 = 0;
  v199 = 0;
  v196 = 0;
  v197 = 0;
  v194 = 0;
  v195 = 0;
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
    raw_spin_lock(v13 + 1248);
  }
  else
  {
    raw_spin_lock_bh(v13 + 1248);
    *(_QWORD *)(v13 + 1256) |= 1uLL;
  }
  v193 = v10;
  v200[0] = 0;
  link_info_by_vdev = 0;
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(v13 + 48), v200) )
  {
    v26 = nullptr;
  }
  else
  {
    v25 = (_QWORD *)v200[0];
    v26 = nullptr;
    if ( v200[0] )
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
          v29 = (unsigned __int8)byte_A8[(_QWORD)v25];
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
        v200[0] = 0;
        if ( (unsigned int)qdf_list_peek_next((_QWORD *)(v13 + 48), v25, v200) )
          break;
        v25 = (_QWORD *)v200[0];
      }
      while ( v200[0] );
    }
  }
  v39 = v12[1];
  v40 = *(_QWORD *)(v39 + 1256);
  if ( (v40 & 1) != 0 )
  {
    *(_QWORD *)(v39 + 1256) = v40 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v39 + 1248);
    if ( !link_info_by_vdev )
      goto LABEL_34;
  }
  else
  {
    raw_spin_unlock(v39 + 1248);
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
      ucfg_p2p_psoc_priv_set_sta_vdev_id(*v12, *(_BYTE *)(*(_QWORD *)(v42 + 52832) + 8LL));
      if ( (unsigned int)wlan_mlme_set_p2p_device_mac_addr(
                           *(_QWORD *)(*(_QWORD *)(v42 + 52832) + 32LL),
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
      v61 = *(_BYTE *)(*(_QWORD *)(v42 + 52832) + 8LL);
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
      _X8 = (unsigned __int64 *)(link_info_by_vdev + 5968);
      __asm { PRFM            #0x11, [X8] }
      do
        v192 = __ldxr(_X8);
      while ( __stxr(v192 | 1, _X8) );
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
  v195 = 56;
  v71 = *(_DWORD *)(v70 + 40) & 0xFFFFFFFE;
  LODWORD(v194) = *(_DWORD *)(v70 + 40);
  if ( v71 == 2 )
    v72 = *(unsigned __int8 *)(v70 + 71200);
  else
    v72 = 255;
  HIDWORD(v199) = v72;
  if ( (*(_BYTE *)(v70 + 52800) & 1) != 0 )
  {
    qdf_ether_addr_copy((_WORD *)&v198 + 2, (_WORD *)(v70 + 1617));
    v73 = (_WORD *)(a1 + 72);
  }
  else if ( *(_DWORD *)(v70 + 40) == 6 )
  {
    v73 = (_WORD *)(a1 + 72);
  }
  else
  {
    v73 = (_WORD *)(v70 + 1617);
  }
  qdf_ether_addr_copy(&v197, v73);
  if ( (unsigned int)v197 | WORD2(v197) )
  {
    v82 = sme_vdev_create(v12[2], &v194);
    if ( !v82 )
    {
      qdf_trace_msg(0x33u, 2u, "%s: failed to create vdev", v83, v84, v85, v86, v87, v88, v89, v90, "hdd_vdev_create");
      result = 4294967274LL;
      goto LABEL_71;
    }
    v91 = v82;
    if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(v82, 5u, v83, v84, v85, v86, v87, v88, v89, v90) )
    {
      sme_vdev_delete(v12[2], v91);
      result = 4294967274LL;
      goto LABEL_71;
    }
    v94 = *(_QWORD **)(v91 + 680);
    if ( v94 )
    {
      *v94 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 32LL) + 992LL);
      v94[1] = a1;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v95 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v95 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v95 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 16);
      v96 = *(_QWORD *)(a1 + 24);
    }
    else
    {
      raw_spin_lock_bh(a1 + 16);
      v96 = *(_QWORD *)(a1 + 24) | 1LL;
      *(_QWORD *)(a1 + 24) = v96;
    }
    v97 = *(_BYTE *)(v91 + 168);
    *(_QWORD *)(a1 + 32) = v91;
    *(_BYTE *)(a1 + 8) = v97;
    if ( (v96 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 24) = v96 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 16);
    }
    else
    {
      raw_spin_unlock(a1 + 16);
    }
    osif_cm_osif_priv_init(v91);
    if ( (*(_BYTE *)(v10 + 52800) & 1) != 0 )
      hdd_mlo_t2lm_register_callback(v91);
    _X8 = (unsigned __int64 *)(a1 + 5968);
    __asm { PRFM            #0x11, [X8] }
    do
      v189 = __ldxr(_X8);
    while ( __stxr(v189 | 1, _X8) );
    setup = sme_vdev_post_vdev_create_setup(v12[2], v91);
    if ( setup )
    {
      v107 = setup;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to setup the vdev",
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        "hdd_vdev_create");
      v108 = qdf_status_to_os_return(v107);
LABEL_70:
      hdd_vdev_destroy(a1, v109, v110, v111, v112, v113, v114, v115, v116);
      result = v108;
      goto LABEL_71;
    }
    v117 = pmo_vdev_ready(v91, v12 + 1029);
    if ( !v117 )
    {
      v117 = ucfg_reg_11d_vdev_created_update(v91);
      if ( !v117 )
      {
        if ( (wma_capability_enhanced_mcast_filter() & 1) != 0 )
          v117 = pmo_core_enhanced_mc_filter_enable(v91);
        else
          v117 = pmo_core_enhanced_mc_filter_disable(v91);
      }
    }
    v118 = qdf_status_to_os_return(v117);
    if ( v118 )
    {
      v108 = v118;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to dispatch vdev ready event: %d",
        v119,
        v120,
        v121,
        v122,
        v123,
        v124,
        v125,
        v126,
        "hdd_vdev_create");
      goto LABEL_70;
    }
    v127 = *(_DWORD *)(v91 + 16);
    v128 = *v12;
    if ( v127 == 16 )
    {
      v166 = *(unsigned __int8 *)(v91 + 168);
      support_mp0_discovery = cfg_nan_get_support_mp0_discovery(*v12);
      sme_cli_set_command(v166, 156, support_mp0_discovery & 1, 1);
    }
    else
    {
      if ( v127 != 2 )
      {
        if ( v127 )
        {
          ucfg_fwol_configure_vdev_params(*v12, v91);
          if ( v127 > 1 )
            goto LABEL_95;
        }
        else
        {
          v129 = *v12;
          LOBYTE(v200[0]) = 0;
          if ( (unsigned int)wlan_mlme_get_rtt_mac_randomization(v129, v200) )
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: unable to get RTT MAC randomization value",
              v130,
              v131,
              v132,
              v133,
              v134,
              v135,
              v136,
              v137,
              "hdd_vdev_configure_rtt_mac_randomization");
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: setting RTT mac randomization param: %d",
            v130,
            v131,
            v132,
            v133,
            v134,
            v135,
            v136,
            v137,
            "hdd_vdev_configure_rtt_mac_randomization",
            LOBYTE(v200[0]),
            v193,
            v194,
            v195);
          v138 = sme_cli_set_command(*(unsigned __int8 *)(v91 + 168), 129, LOBYTE(v200[0]), 1);
          if ( v138 )
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: RTT mac randomization param set failed %d",
              v139,
              v140,
              v141,
              v142,
              v143,
              v144,
              v145,
              v146,
              "hdd_vdev_configure_rtt_mac_randomization",
              v138);
          LOBYTE(v200[0]) = 0;
          *(_WORD *)(v91 + 232) = cfg_tdls_get_max_peer_count(v128) + 19;
          wlan_mlme_get_bigtk_support(v128, v200);
          if ( LOBYTE(v200[0]) == 1 )
            mlme_set_bigtk_support(v91, 1, v147, v148, v149, v150, v151, v152, v153, v154);
          v155 = *(_QWORD *)a1;
          if ( (unsigned int)cds_get_conparam() != 5 && v155 )
            mlme_set_user_ps(v128, *(unsigned __int8 *)(v91 + 168), *(_BYTE *)(v155 + 1616));
          *(_BYTE *)(v91 + 160) = 0;
          ucfg_fwol_configure_vdev_params(v128, v91);
        }
        *(_BYTE *)(v91 + 94) = 1;
LABEL_95:
        v168 = *((unsigned int *)v12 + 312);
        v169 = v12[2];
        v170 = *(unsigned int *)(v91 + 16);
        memset(v200, 0, 56);
        sme_populate_nss_chain_params(v169, v200, v170, v168);
        sme_store_nss_chains_cfg_in_vdev(v91, v200);
        LOWORD(v200[0]) = 0;
        if ( (unsigned int)cds_get_conparam() != 5 )
        {
          rts_profile = ucfg_fwol_get_rts_profile(*v12, v200);
          if ( rts_profile )
          {
            v180 = rts_profile;
            v181 = "%s: FAILED TO GET RTSCTS Profile status:%d";
LABEL_100:
            qdf_trace_msg(
              0x33u,
              2u,
              v181,
              v171,
              v172,
              v173,
              v174,
              v175,
              v176,
              v177,
              v178,
              "hdd_vdev_configure_rtscts_enable",
              v180,
              v193);
            goto LABEL_101;
          }
          v182 = sme_cli_set_command(*(unsigned __int8 *)(v91 + 168), 44, LOWORD(v200[0]), 1);
          if ( v182 )
          {
            v180 = v182;
            v181 = "%s: FAILED TO SET RTSCTS Profile ret:%d";
            goto LABEL_100;
          }
        }
LABEL_101:
        qdf_trace_msg(
          0x33u,
          8u,
          "vdev %d created successfully",
          v171,
          v172,
          v173,
          v174,
          v175,
          v176,
          v177,
          v178,
          *(unsigned __int8 *)(a1 + 8),
          v193);
        result = 0;
        goto LABEL_71;
      }
      v156 = *v12;
      LOBYTE(v200[0]) = 0;
      *(_WORD *)(v91 + 232) = cfg_tdls_get_max_peer_count(v156) + 19;
      wlan_mlme_get_bigtk_support(v128, v200);
      if ( LOBYTE(v200[0]) == 1 )
        mlme_set_bigtk_support(v91, 1, v157, v158, v159, v160, v161, v162, v163, v164);
      v165 = *(_QWORD *)a1;
      if ( (unsigned int)cds_get_conparam() != 5 && v165 )
        mlme_set_user_ps(v128, *(unsigned __int8 *)(v91 + 168), *(_BYTE *)(v165 + 1616));
      *(_BYTE *)(v91 + 160) = 0;
    }
    ucfg_fwol_configure_vdev_params(v128, v91);
    goto LABEL_95;
  }
  v93 = jiffies;
  if ( hdd_populate_vdev_create_params___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: invalid mac addr",
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      "hdd_populate_vdev_create_params");
    hdd_populate_vdev_create_params___last_ticks = v93;
  }
  result = 4294967274LL;
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return result;
}
