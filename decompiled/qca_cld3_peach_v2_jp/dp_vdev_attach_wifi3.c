__int64 __fastcall dp_vdev_attach_wifi3(__int64 a1, unsigned __int8 a2, __int64 a3)
{
  unsigned __int8 *v5; // x19
  int v6; // w25
  int v7; // w26
  __int64 (__fastcall *v8)(_QWORD); // x8
  const void *v9; // x23
  __int64 v10; // x22
  int v11; // w27
  char v12; // w28
  size_t v13; // x0
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  _BYTE *v24; // x24
  __int64 v25; // x8
  __int64 v26; // x23
  unsigned int multiplier; // w0
  __int64 result; // x0
  unsigned int (*v29)(void); // x8
  unsigned int (*v30)(void); // x8
  unsigned __int64 StatusReg; // x8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w8
  unsigned int v43; // w10
  __int64 v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x8
  __int64 v54; // x8
  unsigned int (__fastcall *v55)(_QWORD); // x8
  __int64 v56; // x8
  int v57; // w0
  char raw_mode_war; // w0
  unsigned __int64 v59; // x8
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned int v68; // w8
  unsigned int v71; // w10
  __int64 *v72; // x8
  __int64 v73; // x8
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  int v82; // w8
  bool v83; // w5
  const char *v84; // x2
  const char *v85; // x3
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // x8
  __int64 v95; // x8
  void (__fastcall *v96)(_QWORD); // x8
  __int64 v97; // x0
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  void (__fastcall *v106)(__int64, __int64 *); // x8
  __int64 (__fastcall *v107)(__int64, __int64, __int64 *); // x8
  __int64 v108; // x0
  __int64 v109; // x1
  unsigned int v110; // w0
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  const char *v127; // x2
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  __int64 (__fastcall *v144)(__int64, __int64); // x8
  __int64 v145; // x0
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  __int64 v154; // x8
  __int64 v155; // x8
  __int64 v156; // x8
  __int64 (__fastcall *v157)(_QWORD); // x8
  unsigned int v164; // w9
  unsigned int v167; // w9
  unsigned int v170; // w9
  unsigned int v173; // w9
  __int64 v174; // [xsp+10h] [xbp-50h] BYREF
  _QWORD v175[9]; // [xsp+18h] [xbp-48h] BYREF

  v175[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v5 = nullptr;
  else
    v5 = *(unsigned __int8 **)(a1 + 72);
  v6 = *(_DWORD *)(a3 + 12);
  v7 = *(_DWORD *)(a3 + 16);
  v8 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1464);
  v9 = *(const void **)a3;
  v10 = *(unsigned __int8 *)(a3 + 8);
  v11 = *(_DWORD *)(a3 + 20);
  v12 = *(_BYTE *)(a3 + 9);
  if ( *((_DWORD *)v8 - 1) != -1391804861 )
    __break(0x8228u);
  v13 = v8(2);
  v14 = _qdf_mem_malloc(v13, "dp_vdev_attach_wifi3", 5258);
  v23 = v14;
  if ( !v5 )
  {
    qdf_trace_msg(
      0x7Cu,
      2u,
      "%s: %pK: DP PDEV is Null for pdev id %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "dp_vdev_attach_wifi3",
      a1,
      a2);
    _qdf_mem_free(v23);
    result = 16;
    goto LABEL_108;
  }
  if ( !v14 )
  {
    qdf_trace_msg(
      0x7Cu,
      2u,
      "%s: %pK: DP VDEV memory allocation failed",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "dp_vdev_attach_wifi3",
      a1);
    result = 16;
    goto LABEL_108;
  }
  v24 = (_BYTE *)(v14 + 42424);
  wlan_minidump_log(v15, v16, v17, v18, v19, v20, v21, v22, v14, 45424, *(_QWORD *)(a1 + 16));
  *(_QWORD *)(v23 + 24) = v5;
  *(_BYTE *)(v23 + 59) = v10;
  *(_BYTE *)(v23 + 45316) = v12;
  *(_DWORD *)(v23 + 32) = v6;
  *(_DWORD *)(v23 + 36) = v7;
  *(_DWORD *)(v23 + 45348) = v11;
  v25 = *(_QWORD *)(a1 + 24);
  *(_QWORD *)(v23 + 160) = 0;
  *(_QWORD *)(v23 + 88) = 0;
  *(_QWORD *)(v23 + 16) = v25;
  *(_QWORD *)(v23 + 312) = 0x100000000LL;
  LOBYTE(v25) = *v24;
  *(_DWORD *)(v23 + 272) = 0;
  *(_QWORD *)(v23 + 200) = 0;
  *(_QWORD *)(v23 + 208) = 0;
  *(_QWORD *)(v23 + 216) = 0;
  *(_DWORD *)(v23 + 42444) = 0;
  *(_BYTE *)(v23 + 80) = 0;
  *v24 = v25 & 0xFD;
  *(_DWORD *)(v23 + 42560) = 0;
  *(_DWORD *)(v23 + 42564) = 0;
  *(_DWORD *)(v23 + 42568) = 0;
  *(_DWORD *)(v23 + 42572) = 0;
  *(_DWORD *)(v23 + 42576) = 0;
  *(_DWORD *)(v23 + 42580) = 0;
  *(_DWORD *)(v23 + 42584) = 0;
  *(_DWORD *)(v23 + 42588) = 0;
  *(_DWORD *)(v23 + 42592) = 0;
  *(_DWORD *)(v23 + 42596) = 0;
  *(_DWORD *)(v23 + 42600) = 0;
  *(_DWORD *)(v23 + 42604) = 0;
  *(_DWORD *)(v23 + 42608) = 0;
  *(_DWORD *)(v23 + 42612) = 0;
  *(_DWORD *)(v23 + 42616) = 0;
  *(_DWORD *)(v23 + 42620) = 0;
  *(_DWORD *)(v23 + 42624) = 0;
  *(_DWORD *)(v23 + 42628) = 0;
  *(_DWORD *)(v23 + 42632) = 0;
  *(_DWORD *)(v23 + 42636) = 0;
  *(_DWORD *)(v23 + 42640) = 0;
  *(_DWORD *)(v23 + 42644) = 0;
  *(_DWORD *)(v23 + 42648) = 0;
  *(_DWORD *)(v23 + 42652) = 0;
  *(_DWORD *)(v23 + 42656) = 0;
  *(_DWORD *)(v23 + 42660) = 0;
  *(_DWORD *)(v23 + 42664) = 0;
  *(_DWORD *)(v23 + 42668) = 0;
  *(_DWORD *)(v23 + 42672) = 0;
  *(_DWORD *)(v23 + 42676) = 0;
  *(_DWORD *)(v23 + 42680) = 0;
  *(_DWORD *)(v23 + 42684) = 0;
  _X8 = (unsigned int *)(v23 + 42560);
  __asm { PRFM            #0x11, [X8] }
  do
    v164 = __ldxr(_X8);
  while ( __stxr(v164 + 1, _X8) );
  _X8 = (unsigned int *)(v23 + 42612);
  __asm { PRFM            #0x11, [X8] }
  do
    v167 = __ldxr(_X8);
  while ( __stxr(v167 + 1, _X8) );
  *(_DWORD *)(v23 + 42520) = 0;
  *(_BYTE *)(v23 + 62) = v5[1];
  qdf_mem_copy((void *)(v23 + 96), v9, 6u);
  *(_QWORD *)(v23 + 42472) = 0;
  *(_DWORD *)(v23 + 42712) = 0;
  *(_QWORD *)(v23 + 42720) = 0;
  *(_QWORD *)(v23 + 120) = 0;
  *(_DWORD *)(v23 + 136) = 0;
  *(_QWORD *)(v23 + 144) = 0;
  *(_QWORD *)(v23 + 128) = v23 + 120;
  *(_QWORD *)(v23 + 42480) = v23 + 42472;
  *(_DWORD *)(v23 + 42488) = 0;
  *(_QWORD *)(v23 + 42496) = 0;
  if ( *(_BYTE *)(a1 + 17784) == 2 && (unsigned int)wlan_cfg_get_num_contexts(*(_QWORD *)(a1 + 40)) )
  {
    if ( !*((_WORD *)v5 + 164) || *(_DWORD *)(v23 + 32) == 4 )
    {
      v26 = jiffies;
      multiplier = qdf_timer_get_multiplier();
      mod_timer(a1 + 17728, v26 + 2LL * multiplier);
    }
  }
  else
  {
    v29 = *(unsigned int (**)(void))(*(_QWORD *)(a1 + 8) + 200LL);
    if ( v29 )
    {
      if ( *((_DWORD *)v29 - 1) != 1696218653 )
        __break(0x8228u);
      if ( !v29() && *(_BYTE *)(a1 + 17784) == 1 && *(_DWORD *)(v23 + 32) == 4 )
      {
        if ( *(_BYTE *)(*(_QWORD *)(a1 + 40) + 817LL) != 1 )
          goto LABEL_26;
        v30 = *(unsigned int (**)(void))(*(_QWORD *)(a1 + 8) + 200LL);
        if ( !v30 )
          goto LABEL_26;
        if ( *((_DWORD *)v30 - 1) != 1696218653 )
          __break(0x8228u);
        if ( v30() || (*(_BYTE *)(a1 + 20216) & 0x10) != 0 )
LABEL_26:
          dp_monitor_vdev_timer_start(a1);
      }
    }
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 18928);
  }
  else
  {
    raw_spin_lock_bh(a1 + 18928);
    *(_QWORD *)(a1 + 18936) |= 1uLL;
  }
  v40 = *(_DWORD *)(v23 + 42560);
  while ( v40 )
  {
    _X12 = (unsigned int *)(v23 + 42560);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v43 = __ldxr(_X12);
      if ( v43 != v40 )
        break;
      if ( !__stlxr(v40 + 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v43 == v40;
    v40 = v43;
    if ( _ZF )
    {
      _X8 = (unsigned int *)(v23 + 42612);
      __asm { PRFM            #0x11, [X8] }
      do
        v170 = __ldxr(_X8);
      while ( __stxr(v170 + 1, _X8) );
      if ( (unsigned int)v10 >= 6 )
      {
        __break(0x5512u);
LABEL_137:
        _X8 = (unsigned int *)(v23 + 42612);
        __asm { PRFM            #0x11, [X8] }
        do
          v173 = __ldxr(_X8);
        while ( __stxr(v173 + 1, _X8) );
        *(_QWORD *)(v23 + 104) = 0;
        v72 = *((__int64 **)v5 + 38);
        *(_QWORD *)(v23 + 112) = v72;
        *v72 = v23;
        v73 = *((_QWORD *)v5 + 40);
        *((_QWORD *)v5 + 38) = v23 + 104;
        if ( (v73 & 1) == 0 )
          goto LABEL_71;
LABEL_127:
        *((_QWORD *)v5 + 40) = v73 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v5 + 312);
        goto LABEL_72;
      }
      if ( !*(_QWORD *)(a1 + 12912 + 8 * v10) )
        *(_QWORD *)(a1 + 12912 + 8 * v10) = v23;
      v44 = *(_QWORD *)(a1 + 18936);
      if ( (v44 & 1) == 0 )
        goto LABEL_44;
      goto LABEL_125;
    }
  }
  qdf_trace_msg(
    0x88u,
    5u,
    "%s: %pK: unable to get vdev reference at MAP vdev %pK vdev_id %u",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "dp_vdev_id_map_tbl_add",
    a1,
    v23,
    (unsigned int)v10);
  v44 = *(_QWORD *)(a1 + 18936);
  if ( (v44 & 1) == 0 )
  {
LABEL_44:
    raw_spin_unlock(a1 + 18928);
    goto LABEL_45;
  }
LABEL_125:
  *(_QWORD *)(a1 + 18936) = v44 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 18928);
LABEL_45:
  if ( *(_DWORD *)(v23 + 32) != 4 )
  {
    *(_DWORD *)(v23 + 40) = wlan_cfg_pkt_type(*(_QWORD *)(a1 + 40));
    v57 = wlan_cfg_pkt_type(*(_QWORD *)(a1 + 40));
    *(_BYTE *)(v23 + 72) = 0;
    *(_DWORD *)(v23 + 44) = v57;
    *(_WORD *)(v23 + 57) = 0;
    raw_mode_war = wlan_cfg_get_raw_mode_war(*(_QWORD *)(a1 + 40));
    *(_QWORD *)(v23 + 376) = 0;
    *(_QWORD *)(v23 + 384) = 0;
    *(_BYTE *)(v23 + 42448) = raw_mode_war & 1;
    *(_BYTE *)(v23 + 74) = 1;
    *(_BYTE *)(v23 + 45376) = 0;
    *(_BYTE *)(v23 + 392) = (*(_DWORD *)(v23 + 40) != 0) & wlan_cfg_get_dp_proto_stats(*(_QWORD *)(a1 + 40));
    *(_BYTE *)(v23 + 45377) = wlan_cfg_get_dp_eapol_stats(*(_QWORD *)(a1 + 40)) & 1;
    *(_QWORD *)(v23 + 45320) = 0;
    *(_QWORD *)(v23 + 45328) = 0;
    *(_QWORD *)(v23 + 45336) = 0;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v59 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v59 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v59 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v5 + 312);
    }
    else
    {
      raw_spin_lock_bh(v5 + 312);
      *((_QWORD *)v5 + 40) |= 1uLL;
    }
    v68 = *(_DWORD *)(v23 + 42560);
    while ( v68 )
    {
      _X12 = (unsigned int *)(v23 + 42560);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v71 = __ldxr(_X12);
        if ( v71 != v68 )
          break;
        if ( !__stlxr(v68 + 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v71 == v68;
      v68 = v71;
      if ( _ZF )
        goto LABEL_137;
    }
    qdf_trace_msg(
      0x88u,
      5u,
      "%s: %pK: unable to get vdev reference at MAP vdev %pK",
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      "dp_vdev_pdev_list_add",
      a1,
      v23);
    v73 = *((_QWORD *)v5 + 40);
    if ( (v73 & 1) != 0 )
      goto LABEL_127;
LABEL_71:
    raw_spin_unlock(v5 + 312);
LABEL_72:
    ++*((_WORD *)v5 + 164);
    v82 = *(_DWORD *)(v23 + 32);
    v83 = v82 != 6 && v82 != 3;
    *(_BYTE *)(v23 + 42440) = v83;
    qdf_trace_msg(
      0x7Cu,
      5u,
      "%s: %pK: wlan_cfg_ap_bridge_enabled %d",
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      "dp_vdev_attach_wifi3",
      a1);
    ((void (__fastcall *)(__int64))dp_tx_vdev_attach)(v23);
    v94 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v23 + 24) + 8LL) + 20056LL);
    if ( v94 )
    {
      v95 = *(_QWORD *)(v94 + 416);
      if ( v95 && (v96 = *(void (__fastcall **)(_QWORD))(v95 + 120)) != nullptr )
      {
        if ( *((_DWORD *)v96 - 1) != 341701128 )
          __break(0x8228u);
        v96(v23);
      }
      else
      {
        qdf_trace_msg(
          0x92u,
          8u,
          "%s: callback not registered",
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          "dp_monitor_vdev_attach");
      }
    }
    if ( v5[95456] )
    {
LABEL_104:
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Created vdev %pK (%02x:%02x:%02x:**:**:%02x) vdev_id %d",
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        "dp_vdev_attach_wifi3",
        v23,
        *(unsigned __int8 *)(v23 + 96),
        *(unsigned __int8 *)(v23 + 97),
        *(unsigned __int8 *)(v23 + 98),
        *(unsigned __int8 *)(v23 + 101),
        *(unsigned __int8 *)(v23 + 59));
      qdf_mem_set((void *)(v23 + 400), 0xA428u, 0);
      v144 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 1224);
      if ( *((_DWORD *)v144 - 1) != 1538590919 )
        __break(0x8228u);
      v145 = v144(a1, v23);
      if ( !(_DWORD)v145 )
      {
        dp_pdev_update_fast_rx_flag(v146, v147, v148, v149, v150, v151, v152, v153, v145, (__int64)v5);
        result = 0;
        goto LABEL_108;
      }
LABEL_107:
      result = 16;
      goto LABEL_108;
    }
    v97 = *(_QWORD *)(a1 + 40);
    memset(v175, 0, 64);
    v174 = 0;
    if ( (wlan_cfg_is_lro_enabled(v97) & 1) != 0
      || (wlan_cfg_is_gro_enabled(*(_QWORD *)(a1 + 40)) & 1) != 0
      || (wlan_cfg_is_rx_hash_enabled(*(_QWORD *)(a1 + 40)) & 1) != 0 )
    {
      qdf_mem_set(&v174, 0x48u, 0);
      if ( (wlan_cfg_is_lro_enabled(*(_QWORD *)(a1 + 40)) & 1) != 0
        || (wlan_cfg_is_gro_enabled(*(_QWORD *)(a1 + 40)) & 1) != 0 )
      {
        LODWORD(v174) = 1;
        HIDWORD(v174) = HIDWORD(v174) & 0xFFFC0000 | 0x1EE10;
      }
      v106 = *(void (__fastcall **)(__int64, __int64 *))(a1 + 1520);
      if ( *((_DWORD *)v106 - 1) != -506576576 )
        __break(0x8228u);
      v106(a1, &v174);
      v107 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)(a1 + 8) + 72LL);
      if ( v107 )
      {
        v108 = *(_QWORD *)(a1 + 16);
        v109 = *v5;
        if ( *((_DWORD *)v107 - 1) != -1564551887 )
          __break(0x8228u);
        v110 = v107(v108, v109, &v174);
        if ( !v110 )
        {
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: LRO CMD config: lro_enable: 0x%x tcp_flag 0x%x tcp_flag_mask 0x%x",
            v111,
            v112,
            v113,
            v114,
            v115,
            v116,
            v117,
            v118,
            "dp_lro_hash_setup",
            (unsigned int)v174,
            WORD2(v174) & 0x1FF,
            (HIDWORD(v174) >> 9) & 0x1FF);
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: toeplitz_hash_ipv4:",
            v128,
            v129,
            v130,
            v131,
            v132,
            v133,
            v134,
            v135,
            "dp_lro_hash_setup");
          ((void (__fastcall *)(__int64, __int64, _QWORD *, __int64))qdf_trace_hex_dump)(69, 8, v175, 20);
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: toeplitz_hash_ipv6:",
            v136,
            v137,
            v138,
            v139,
            v140,
            v141,
            v142,
            v143,
            "dp_lro_hash_setup");
          ((void (__fastcall *)(__int64, __int64, char *, __int64))qdf_trace_hex_dump)(69, 8, (char *)&v175[2] + 4, 44);
          v5[95456] = 1;
          goto LABEL_104;
        }
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: failed to send lro_hash_config to FW %u",
          v111,
          v112,
          v113,
          v114,
          v115,
          v116,
          v117,
          v118,
          "dp_lro_hash_setup",
          v110);
        goto LABEL_103;
      }
      v127 = "%s: lro_hash_config not configured";
    }
    else
    {
      v127 = "%s: LRO, GRO and RX hash disabled";
    }
    qdf_trace_msg(0x45u, 2u, v127, v98, v99, v100, v101, v102, v103, v104, v105, "dp_lro_hash_setup");
LABEL_103:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: LRO hash setup failure!",
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      v125,
      v126,
      "dp_vdev_attach_wifi3");
    goto LABEL_104;
  }
  v53 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v23 + 24) + 8LL) + 20056LL);
  if ( !v53 )
    goto LABEL_107;
  v54 = *(_QWORD *)(v53 + 416);
  if ( !v54 || (v55 = *(unsigned int (__fastcall **)(_QWORD))(v54 + 120)) == nullptr )
  {
    v84 = "%s: callback not registered";
    v85 = "dp_monitor_vdev_attach";
LABEL_76:
    qdf_trace_msg(0x92u, 8u, v84, v45, v46, v47, v48, v49, v50, v51, v52, v85);
    goto LABEL_107;
  }
  if ( *((_DWORD *)v55 - 1) != 341701128 )
    __break(0x8228u);
  if ( v55(v23) )
    goto LABEL_107;
  v56 = *(_QWORD *)(*(_QWORD *)(v23 + 24) + 95560LL);
  if ( v56 )
  {
    if ( *(_QWORD *)(v56 + 16) )
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: skip to set mvdev - vdev_id: %u, mac_id: %u",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "dp_monitor_pdev_set_mon_vdev",
        *(unsigned __int8 *)(v23 + 59),
        0);
    }
    else
    {
      *(_QWORD *)(v56 + 16) = v23;
      *(_BYTE *)(v56 + 9) = *(_BYTE *)(v23 + 59);
    }
    v154 = *(_QWORD *)(*(_QWORD *)(v23 + 24) + 95560LL);
    if ( *(_QWORD *)(v154 + 18544) )
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: skip to set mvdev - vdev_id: %u, mac_id: %u",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "dp_monitor_pdev_set_mon_vdev",
        *(unsigned __int8 *)(v23 + 59),
        1);
    }
    else
    {
      *(_QWORD *)(v154 + 18544) = v23;
      *(_BYTE *)(v154 + 18537) = *(_BYTE *)(v23 + 59);
    }
  }
  v155 = *(_QWORD *)(*((_QWORD *)v5 + 1) + 20056LL);
  if ( !v155 )
  {
    v84 = "%s: monitor soc is NULL";
    goto LABEL_122;
  }
  v156 = *(_QWORD *)(v155 + 416);
  if ( !v156 || (v157 = *(__int64 (__fastcall **)(_QWORD))(v156 + 464)) == nullptr )
  {
    v84 = "%s: callback not registered";
LABEL_122:
    v85 = "dp_monitor_vdev_set_monitor_mode_buf_rings";
    goto LABEL_76;
  }
  if ( *((_DWORD *)v157 - 1) != -1116635294 )
    __break(0x8228u);
  result = v157(v5);
LABEL_108:
  _ReadStatusReg(SP_EL0);
  return result;
}
