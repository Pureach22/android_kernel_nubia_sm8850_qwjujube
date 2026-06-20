__int64 __fastcall dp_vdev_attach_wifi3(__int64 a1, unsigned __int8 a2, __int64 a3)
{
  unsigned __int8 *v6; // x22
  __int64 v7; // x21
  int v8; // w26
  int v9; // w27
  __int64 (__fastcall *v10)(_QWORD); // x8
  int v11; // w28
  char v12; // w19
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
  unsigned __int8 *v24; // x24
  _BYTE *v25; // x25
  __int64 v26; // x8
  __int64 v27; // x22
  __int64 v28; // x21
  const void *v29; // x1
  __int64 v30; // x19
  unsigned int multiplier; // w0
  __int64 result; // x0
  unsigned int (*v33)(void); // x8
  unsigned int (*v34)(void); // x8
  unsigned __int64 StatusReg; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w8
  unsigned int v47; // w10
  __int64 v48; // x8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x8
  __int64 v58; // x8
  unsigned int (__fastcall *v59)(_QWORD); // x8
  __int64 v60; // x8
  int v61; // w0
  char raw_mode_war; // w0
  unsigned __int64 v63; // x8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned int v72; // w8
  unsigned int v75; // w10
  __int64 *v76; // x8
  __int64 v77; // x8
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  int v86; // w8
  bool v87; // w5
  const char *v88; // x2
  const char *v89; // x3
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  __int64 v98; // x8
  __int64 v99; // x8
  void (__fastcall *v100)(_QWORD); // x8
  __int64 v101; // x0
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  void (__fastcall *v110)(__int64, __int64 *); // x8
  __int64 (__fastcall *v111)(__int64, __int64, __int64 *); // x8
  __int64 v112; // x0
  __int64 v113; // x1
  unsigned int v114; // w0
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  const char *v131; // x2
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  __int64 (__fastcall *v148)(__int64, __int64); // x8
  __int64 v149; // x0
  double v150; // d0
  double v151; // d1
  double v152; // d2
  double v153; // d3
  double v154; // d4
  double v155; // d5
  double v156; // d6
  double v157; // d7
  __int64 v158; // x8
  __int64 v159; // x8
  __int64 v160; // x8
  __int64 (__fastcall *v161)(_QWORD); // x8
  unsigned int v168; // w9
  unsigned int v171; // w9
  unsigned int v174; // w9
  unsigned int v177; // w9
  const void *v178; // [xsp+10h] [xbp-60h]
  __int64 v179; // [xsp+18h] [xbp-58h]
  __int64 v180; // [xsp+20h] [xbp-50h] BYREF
  _QWORD v181[9]; // [xsp+28h] [xbp-48h] BYREF

  v181[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
    v6 = nullptr;
  else
    v6 = *(unsigned __int8 **)(a1 + 72);
  v7 = *(unsigned __int8 *)(a3 + 8);
  v8 = *(_DWORD *)(a3 + 12);
  v9 = *(_DWORD *)(a3 + 16);
  v178 = *(const void **)a3;
  v10 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1464);
  v11 = *(_DWORD *)(a3 + 20);
  v12 = *(_BYTE *)(a3 + 9);
  if ( *((_DWORD *)v10 - 1) != -1391804861 )
    __break(0x8228u);
  v13 = v10(2);
  v14 = _qdf_mem_malloc(v13, "dp_vdev_attach_wifi3", 5258);
  v23 = v14;
  if ( !v6 )
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
    goto LABEL_110;
  }
  v179 = a1;
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
    goto LABEL_110;
  }
  v24 = v6;
  v25 = (_BYTE *)(v14 + 43248);
  wlan_minidump_log(v15, v16, v17, v18, v19, v20, v21, v22, v14, 46248, *(_QWORD *)(v179 + 16));
  *(_QWORD *)(v23 + 24) = v6;
  *(_BYTE *)(v23 + 59) = v7;
  *(_BYTE *)(v23 + 46140) = v12;
  *(_DWORD *)(v23 + 32) = v8;
  *(_DWORD *)(v23 + 36) = v9;
  *(_DWORD *)(v23 + 46172) = v11;
  v26 = *(_QWORD *)(v179 + 24);
  *(_QWORD *)(v23 + 168) = 0;
  *(_QWORD *)(v23 + 88) = 0;
  *(_QWORD *)(v23 + 16) = v26;
  *(_QWORD *)(v23 + 320) = 0x100000000LL;
  LOBYTE(v26) = *v25;
  *(_DWORD *)(v23 + 280) = 0;
  *(_QWORD *)(v23 + 208) = 0;
  *(_QWORD *)(v23 + 216) = 0;
  *(_QWORD *)(v23 + 224) = 0;
  *(_DWORD *)(v23 + 43268) = 0;
  *(_BYTE *)(v23 + 80) = 0;
  *v25 = v26 & 0xFD;
  *(_DWORD *)(v23 + 43384) = 0;
  *(_DWORD *)(v23 + 43388) = 0;
  *(_DWORD *)(v23 + 43392) = 0;
  *(_DWORD *)(v23 + 43396) = 0;
  *(_DWORD *)(v23 + 43400) = 0;
  *(_DWORD *)(v23 + 43404) = 0;
  *(_DWORD *)(v23 + 43408) = 0;
  *(_DWORD *)(v23 + 43412) = 0;
  *(_DWORD *)(v23 + 43416) = 0;
  *(_DWORD *)(v23 + 43420) = 0;
  *(_DWORD *)(v23 + 43424) = 0;
  *(_DWORD *)(v23 + 43428) = 0;
  *(_DWORD *)(v23 + 43432) = 0;
  *(_DWORD *)(v23 + 43436) = 0;
  *(_DWORD *)(v23 + 43440) = 0;
  *(_DWORD *)(v23 + 43444) = 0;
  *(_DWORD *)(v23 + 43448) = 0;
  *(_DWORD *)(v23 + 43452) = 0;
  *(_DWORD *)(v23 + 43456) = 0;
  *(_DWORD *)(v23 + 43460) = 0;
  *(_DWORD *)(v23 + 43464) = 0;
  *(_DWORD *)(v23 + 43468) = 0;
  *(_DWORD *)(v23 + 43472) = 0;
  *(_DWORD *)(v23 + 43476) = 0;
  *(_DWORD *)(v23 + 43480) = 0;
  *(_DWORD *)(v23 + 43484) = 0;
  *(_DWORD *)(v23 + 43488) = 0;
  *(_DWORD *)(v23 + 43492) = 0;
  *(_DWORD *)(v23 + 43496) = 0;
  *(_DWORD *)(v23 + 43500) = 0;
  *(_DWORD *)(v23 + 43504) = 0;
  *(_DWORD *)(v23 + 43508) = 0;
  _X8 = (unsigned int *)(v23 + 43384);
  __asm { PRFM            #0x11, [X8] }
  do
    v168 = __ldxr(_X8);
  while ( __stxr(v168 + 1, _X8) );
  _X8 = (unsigned int *)(v23 + 43436);
  __asm { PRFM            #0x11, [X8] }
  do
    v171 = __ldxr(_X8);
  while ( __stxr(v171 + 1, _X8) );
  v27 = v7;
  v28 = v179;
  *(_DWORD *)(v23 + 43344) = 0;
  *(_BYTE *)(v23 + 62) = v24[1];
  qdf_mem_copy((void *)(v23 + 96), v178, 6u);
  v29 = *(const void **)(a3 + 24);
  if ( v29 )
    qdf_mem_copy((void *)(v23 + 104), v29, 6u);
  *(_QWORD *)(v23 + 43296) = 0;
  *(_DWORD *)(v23 + 43536) = 0;
  *(_QWORD *)(v23 + 43544) = 0;
  *(_QWORD *)(v23 + 128) = 0;
  *(_DWORD *)(v23 + 144) = 0;
  *(_QWORD *)(v23 + 152) = 0;
  *(_QWORD *)(v23 + 136) = v23 + 128;
  *(_QWORD *)(v23 + 43304) = v23 + 43296;
  *(_DWORD *)(v23 + 43312) = 0;
  *(_QWORD *)(v23 + 43320) = 0;
  if ( *(_BYTE *)(v179 + 17840) == 2 && (unsigned int)wlan_cfg_get_num_contexts(*(_QWORD *)(v179 + 40)) )
  {
    if ( !*((_WORD *)v24 + 164) || *(_DWORD *)(v23 + 32) == 4 )
    {
      v30 = jiffies;
      multiplier = qdf_timer_get_multiplier();
      mod_timer(v179 + 17784, v30 + 2LL * multiplier);
    }
  }
  else
  {
    v33 = *(unsigned int (**)(void))(*(_QWORD *)(v179 + 8) + 200LL);
    if ( v33 )
    {
      if ( *((_DWORD *)v33 - 1) != 1696218653 )
        __break(0x8228u);
      if ( !v33() && *(_BYTE *)(v179 + 17840) == 1 && *(_DWORD *)(v23 + 32) == 4 )
      {
        if ( *(_BYTE *)(*(_QWORD *)(v179 + 40) + 817LL) != 1 )
          goto LABEL_28;
        v34 = *(unsigned int (**)(void))(*(_QWORD *)(v179 + 8) + 200LL);
        if ( !v34 )
          goto LABEL_28;
        if ( *((_DWORD *)v34 - 1) != 1696218653 )
          __break(0x8228u);
        if ( v34() || (*(_BYTE *)(v179 + 20272) & 0x10) != 0 )
LABEL_28:
          dp_monitor_vdev_timer_start(v179);
      }
    }
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v179 + 18984);
  }
  else
  {
    raw_spin_lock_bh(v179 + 18984);
    *(_QWORD *)(v179 + 18992) |= 1uLL;
  }
  v44 = *(_DWORD *)(v23 + 43384);
  while ( v44 )
  {
    _X12 = (unsigned int *)(v23 + 43384);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v47 = __ldxr(_X12);
      if ( v47 != v44 )
        break;
      if ( !__stlxr(v44 + 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v47 == v44;
    v44 = v47;
    if ( _ZF )
    {
      _X8 = (unsigned int *)(v23 + 43436);
      __asm { PRFM            #0x11, [X8] }
      do
        v174 = __ldxr(_X8);
      while ( __stxr(v174 + 1, _X8) );
      if ( (unsigned int)v27 >= 6 )
      {
        __break(0x5512u);
LABEL_139:
        _X8 = (unsigned int *)(v23 + 43436);
        __asm { PRFM            #0x11, [X8] }
        do
          v177 = __ldxr(_X8);
        while ( __stxr(v177 + 1, _X8) );
        *(_QWORD *)(v23 + 112) = 0;
        v76 = *((__int64 **)v24 + 38);
        *(_QWORD *)(v23 + 120) = v76;
        *v76 = v23;
        v77 = *((_QWORD *)v24 + 40);
        *((_QWORD *)v24 + 38) = v23 + 112;
        if ( (v77 & 1) == 0 )
          goto LABEL_73;
LABEL_129:
        *((_QWORD *)v24 + 40) = v77 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v24 + 312);
        goto LABEL_74;
      }
      if ( !*(_QWORD *)(v179 + 12960 + 8 * v27) )
        *(_QWORD *)(v179 + 12960 + 8 * v27) = v23;
      v48 = *(_QWORD *)(v179 + 18992);
      if ( (v48 & 1) == 0 )
        goto LABEL_46;
      goto LABEL_127;
    }
  }
  qdf_trace_msg(
    0x88u,
    5u,
    "%s: %pK: unable to get vdev reference at MAP vdev %pK vdev_id %u",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "dp_vdev_id_map_tbl_add",
    v179,
    v23,
    v27);
  v48 = *(_QWORD *)(v179 + 18992);
  if ( (v48 & 1) == 0 )
  {
LABEL_46:
    raw_spin_unlock(v179 + 18984);
    goto LABEL_47;
  }
LABEL_127:
  *(_QWORD *)(v179 + 18992) = v48 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(v179 + 18984);
LABEL_47:
  if ( *(_DWORD *)(v23 + 32) != 4 )
  {
    *(_DWORD *)(v23 + 40) = wlan_cfg_pkt_type(*(_QWORD *)(v179 + 40));
    v61 = wlan_cfg_pkt_type(*(_QWORD *)(v179 + 40));
    *(_BYTE *)(v23 + 72) = 0;
    *(_DWORD *)(v23 + 44) = v61;
    *(_WORD *)(v23 + 57) = 0;
    raw_mode_war = wlan_cfg_get_raw_mode_war(*(_QWORD *)(v179 + 40));
    *(_QWORD *)(v23 + 384) = 0;
    *(_QWORD *)(v23 + 392) = 0;
    *(_BYTE *)(v23 + 43272) = raw_mode_war & 1;
    *(_BYTE *)(v23 + 74) = 1;
    *(_BYTE *)(v23 + 46200) = 0;
    *(_BYTE *)(v23 + 400) = (*(_DWORD *)(v23 + 40) != 0) & wlan_cfg_get_dp_proto_stats(*(_QWORD *)(v179 + 40));
    *(_BYTE *)(v23 + 46201) = wlan_cfg_get_dp_eapol_stats(*(_QWORD *)(v179 + 40)) & 1;
    *(_QWORD *)(v23 + 46144) = 0;
    *(_QWORD *)(v23 + 46152) = 0;
    *(_QWORD *)(v23 + 46160) = 0;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v63 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v63 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v63 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v24 + 312);
    }
    else
    {
      raw_spin_lock_bh(v24 + 312);
      *((_QWORD *)v24 + 40) |= 1uLL;
    }
    v72 = *(_DWORD *)(v23 + 43384);
    while ( v72 )
    {
      _X12 = (unsigned int *)(v23 + 43384);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v75 = __ldxr(_X12);
        if ( v75 != v72 )
          break;
        if ( !__stlxr(v72 + 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v75 == v72;
      v72 = v75;
      if ( _ZF )
        goto LABEL_139;
    }
    qdf_trace_msg(
      0x88u,
      5u,
      "%s: %pK: unable to get vdev reference at MAP vdev %pK",
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      "dp_vdev_pdev_list_add",
      v179,
      v23);
    v77 = *((_QWORD *)v24 + 40);
    if ( (v77 & 1) != 0 )
      goto LABEL_129;
LABEL_73:
    raw_spin_unlock(v24 + 312);
LABEL_74:
    ++*((_WORD *)v24 + 164);
    v86 = *(_DWORD *)(v23 + 32);
    v87 = v86 != 6 && v86 != 3;
    *(_BYTE *)(v23 + 43264) = v87;
    qdf_trace_msg(
      0x7Cu,
      5u,
      "%s: %pK: wlan_cfg_ap_bridge_enabled %d",
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      "dp_vdev_attach_wifi3",
      v179);
    ((void (__fastcall *)(__int64))dp_tx_vdev_attach)(v23);
    v98 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v23 + 24) + 8LL) + 20112LL);
    if ( v98 )
    {
      v99 = *(_QWORD *)(v98 + 416);
      if ( v99 && (v100 = *(void (__fastcall **)(_QWORD))(v99 + 120)) != nullptr )
      {
        if ( *((_DWORD *)v100 - 1) != 341701128 )
          __break(0x8228u);
        v100(v23);
      }
      else
      {
        qdf_trace_msg(
          0x92u,
          8u,
          "%s: callback not registered",
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          "dp_monitor_vdev_attach");
      }
    }
    if ( v24[96352] )
    {
LABEL_106:
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Created vdev %pK (%02x:%02x:%02x:**:**:%02x) vdev_id %d",
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        v97,
        "dp_vdev_attach_wifi3",
        v23,
        *(unsigned __int8 *)(v23 + 96),
        *(unsigned __int8 *)(v23 + 97),
        *(unsigned __int8 *)(v23 + 98),
        *(unsigned __int8 *)(v23 + 101),
        *(unsigned __int8 *)(v23 + 59));
      qdf_mem_set((void *)(v23 + 408), 0xA758u, 0);
      v148 = *(__int64 (__fastcall **)(__int64, __int64))(v28 + 1224);
      if ( *((_DWORD *)v148 - 1) != 1538590919 )
        __break(0x8228u);
      v149 = v148(v28, v23);
      if ( !(_DWORD)v149 )
      {
        dp_pdev_update_fast_rx_flag(v150, v151, v152, v153, v154, v155, v156, v157, v149, (__int64)v24);
        result = 0;
        goto LABEL_110;
      }
LABEL_109:
      result = 16;
      goto LABEL_110;
    }
    v101 = *(_QWORD *)(v179 + 40);
    memset(v181, 0, 64);
    v180 = 0;
    if ( (wlan_cfg_is_lro_enabled(v101) & 1) != 0
      || (wlan_cfg_is_gro_enabled(*(_QWORD *)(v179 + 40)) & 1) != 0
      || (wlan_cfg_is_rx_hash_enabled(*(_QWORD *)(v179 + 40)) & 1) != 0 )
    {
      qdf_mem_set(&v180, 0x48u, 0);
      if ( (wlan_cfg_is_lro_enabled(*(_QWORD *)(v179 + 40)) & 1) != 0
        || (wlan_cfg_is_gro_enabled(*(_QWORD *)(v179 + 40)) & 1) != 0 )
      {
        LODWORD(v180) = 1;
        HIDWORD(v180) = HIDWORD(v180) & 0xFFFC0000 | 0x1EE10;
      }
      v110 = *(void (__fastcall **)(__int64, __int64 *))(v179 + 1568);
      if ( *((_DWORD *)v110 - 1) != -506576576 )
        __break(0x8228u);
      v110(v179, &v180);
      v111 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)(v179 + 8) + 72LL);
      if ( v111 )
      {
        v112 = *(_QWORD *)(v179 + 16);
        v113 = *v24;
        if ( *((_DWORD *)v111 - 1) != -1564551887 )
          __break(0x8228u);
        v114 = v111(v112, v113, &v180);
        if ( !v114 )
        {
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: LRO CMD config: lro_enable: 0x%x tcp_flag 0x%x tcp_flag_mask 0x%x",
            v115,
            v116,
            v117,
            v118,
            v119,
            v120,
            v121,
            v122,
            "dp_lro_hash_setup",
            (unsigned int)v180,
            WORD2(v180) & 0x1FF,
            (HIDWORD(v180) >> 9) & 0x1FF);
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: toeplitz_hash_ipv4:",
            v132,
            v133,
            v134,
            v135,
            v136,
            v137,
            v138,
            v139,
            "dp_lro_hash_setup");
          ((void (__fastcall *)(__int64, __int64, _QWORD *, __int64))qdf_trace_hex_dump)(69, 8, v181, 20);
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: toeplitz_hash_ipv6:",
            v140,
            v141,
            v142,
            v143,
            v144,
            v145,
            v146,
            v147,
            "dp_lro_hash_setup");
          ((void (__fastcall *)(__int64, __int64, char *, __int64))qdf_trace_hex_dump)(69, 8, (char *)&v181[2] + 4, 44);
          v28 = v179;
          v24[96352] = 1;
          goto LABEL_106;
        }
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: failed to send lro_hash_config to FW %u",
          v115,
          v116,
          v117,
          v118,
          v119,
          v120,
          v121,
          v122,
          "dp_lro_hash_setup",
          v114);
        v28 = v179;
        goto LABEL_105;
      }
      v131 = "%s: lro_hash_config not configured";
    }
    else
    {
      v131 = "%s: LRO, GRO and RX hash disabled";
    }
    qdf_trace_msg(0x45u, 2u, v131, v102, v103, v104, v105, v106, v107, v108, v109, "dp_lro_hash_setup");
LABEL_105:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: LRO hash setup failure!",
      v123,
      v124,
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      "dp_vdev_attach_wifi3");
    goto LABEL_106;
  }
  v57 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v23 + 24) + 8LL) + 20112LL);
  if ( !v57 )
    goto LABEL_109;
  v58 = *(_QWORD *)(v57 + 416);
  if ( !v58 || (v59 = *(unsigned int (__fastcall **)(_QWORD))(v58 + 120)) == nullptr )
  {
    v88 = "%s: callback not registered";
    v89 = "dp_monitor_vdev_attach";
LABEL_78:
    qdf_trace_msg(0x92u, 8u, v88, v49, v50, v51, v52, v53, v54, v55, v56, v89);
    goto LABEL_109;
  }
  if ( *((_DWORD *)v59 - 1) != 341701128 )
    __break(0x8228u);
  if ( v59(v23) )
    goto LABEL_109;
  v60 = *(_QWORD *)(*(_QWORD *)(v23 + 24) + 96456LL);
  if ( v60 )
  {
    if ( *(_QWORD *)(v60 + 16) )
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: skip to set mvdev - vdev_id: %u, mac_id: %u",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "dp_monitor_pdev_set_mon_vdev",
        *(unsigned __int8 *)(v23 + 59),
        0);
    }
    else
    {
      *(_QWORD *)(v60 + 16) = v23;
      *(_BYTE *)(v60 + 9) = *(_BYTE *)(v23 + 59);
    }
    v158 = *(_QWORD *)(*(_QWORD *)(v23 + 24) + 96456LL);
    if ( *(_QWORD *)(v158 + 18544) )
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: skip to set mvdev - vdev_id: %u, mac_id: %u",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "dp_monitor_pdev_set_mon_vdev",
        *(unsigned __int8 *)(v23 + 59),
        1);
    }
    else
    {
      *(_QWORD *)(v158 + 18544) = v23;
      *(_BYTE *)(v158 + 18537) = *(_BYTE *)(v23 + 59);
    }
  }
  v159 = *(_QWORD *)(*((_QWORD *)v24 + 1) + 20112LL);
  if ( !v159 )
  {
    v88 = "%s: monitor soc is NULL";
    goto LABEL_124;
  }
  v160 = *(_QWORD *)(v159 + 416);
  if ( !v160 || (v161 = *(__int64 (__fastcall **)(_QWORD))(v160 + 464)) == nullptr )
  {
    v88 = "%s: callback not registered";
LABEL_124:
    v89 = "dp_monitor_vdev_set_monitor_mode_buf_rings";
    goto LABEL_78;
  }
  if ( *((_DWORD *)v161 - 1) != -1116635294 )
    __break(0x8228u);
  result = v161(v24);
LABEL_110:
  _ReadStatusReg(SP_EL0);
  return result;
}
