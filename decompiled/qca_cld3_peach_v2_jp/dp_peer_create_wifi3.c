__int64 __fastcall dp_peer_create_wifi3(__int64 a1, unsigned __int8 a2, const void *a3)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x19
  unsigned int v9; // w8
  unsigned int v16; // w10
  __int64 v17; // x21
  __int64 *v18; // x20
  unsigned __int64 v19; // x8
  __int64 v20; // x23
  __int64 v21; // x8
  __int64 (__fastcall *v22)(_QWORD); // x8
  size_t v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
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
  unsigned int v61; // w8
  unsigned int v64; // w10
  unsigned int v65; // w24
  __int64 v66; // x6
  __int64 v67; // x7
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
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 v92; // x8
  unsigned int v93; // w8
  unsigned int v96; // w10
  __int64 v97; // x8
  _QWORD *v98; // x9
  _QWORD *v99; // x8
  __int64 v100; // x8
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x5
  __int64 v110; // x6
  __int64 v111; // x7
  int v112; // w8
  unsigned __int64 v113; // x8
  __int64 v114; // x8
  unsigned int v115; // w25
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  __int64 v124; // x8
  __int64 v125; // x8
  void (__fastcall *v126)(__int64, __int64); // x8
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  const char *v135; // x2
  __int64 v136; // x8
  __int64 v137; // x8
  void (__fastcall *v138)(_QWORD); // x8
  __int64 v139; // x8
  __int64 v140; // x8
  int v141; // w9
  __int64 v142; // x6
  __int64 v143; // x7
  int v144; // w8
  int v145; // w9
  unsigned int *v146; // x8
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  unsigned int v157; // w9
  __int64 v158; // x8
  unsigned int v161; // w9
  unsigned int v164; // w9
  unsigned int v167; // w9
  unsigned int v170; // w9
  __int64 v171; // [xsp+0h] [xbp-20h]

  result = 16;
  if ( a2 > 5u || !a3 )
    return result;
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
  v8 = *(_QWORD *)(a1 + 8LL * a2 + 12912);
  if ( !v8 )
  {
LABEL_36:
    v60 = *(_QWORD *)(a1 + 18936);
    if ( (v60 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18936) = v60 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18928);
    }
    else
    {
      raw_spin_unlock(a1 + 18928);
    }
    return 16;
  }
  v9 = *(_DWORD *)(v8 + 42560);
  do
  {
    if ( !v9 )
      goto LABEL_36;
    _X12 = (unsigned int *)(v8 + 42560);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v16 = __ldxr(_X12);
      if ( v16 != v9 )
        break;
      if ( !__stlxr(v9 + 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v16 == v9;
    v9 = v16;
  }
  while ( !_ZF );
  _X8 = (unsigned int *)(v8 + 42592);
  __asm { PRFM            #0x11, [X8] }
  do
    v157 = __ldxr(_X8);
  while ( __stxr(v157 + 1, _X8) );
  v158 = *(_QWORD *)(a1 + 18936);
  if ( (v158 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 18936) = v158 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 18928);
  }
  else
  {
    raw_spin_unlock(a1 + 18928);
  }
  v17 = *(_QWORD *)(v8 + 24);
  v18 = *(__int64 **)(v17 + 8);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v19 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v19 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v19 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v18 + 2360);
    v20 = v18[2358];
    if ( !v20 )
      goto LABEL_23;
LABEL_74:
    while ( (*(_BYTE *)(v20 + 120) & 1) == 0
         || *(_QWORD *)(v20 + 24) != v8
         || *(__int16 *)(v20 + 16) != -1
         || (unsigned int)qdf_mem_cmp(a3, (const void *)(v20 + 44), 6u) )
    {
LABEL_73:
      v20 = *(_QWORD *)(v20 + 240);
      if ( !v20 )
        goto LABEL_23;
    }
    v93 = *(_DWORD *)(v20 + 40);
    do
    {
      if ( !v93 )
        goto LABEL_73;
      _X12 = (unsigned int *)(v20 + 40);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v96 = __ldxr(_X12);
        if ( v96 != v93 )
          break;
        if ( !__stlxr(v93 + 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v96 == v93;
      v93 = v96;
    }
    while ( !_ZF );
    _X8 = (unsigned int *)(v20 + 304);
    __asm { PRFM            #0x11, [X8] }
    do
      v161 = __ldxr(_X8);
    while ( __stxr(v161 + 1, _X8) );
    v97 = *(_QWORD *)(v20 + 240);
    v98 = *(_QWORD **)(v20 + 248);
    if ( v97 )
      v99 = (_QWORD *)(v97 + 248);
    else
      v99 = v18 + 2359;
    *v99 = v98;
    *v98 = *(_QWORD *)(v20 + 240);
    *(_QWORD *)(v20 + 240) = 0;
    *(_QWORD *)(v20 + 248) = 0;
    v100 = v18[2361];
    if ( (v100 & 1) != 0 )
    {
      v18[2361] = v100 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v18 + 2360);
    }
    else
    {
      raw_spin_unlock(v18 + 2360);
    }
    *(_DWORD *)(v20 + 232) = 0;
    dp_peer_cleanup(v8, v20);
    dp_peer_vdev_list_add(v18, v8, v20);
    dp_peer_find_hash_add(v18, v20);
    if ( (unsigned int)dp_peer_rx_tids_create(v20) )
    {
      if ( v20 == -44 )
      {
        v111 = 0;
        v109 = 0;
        v110 = 0;
        v112 = 0;
      }
      else
      {
        v109 = *(unsigned __int8 *)(v20 + 44);
        v110 = *(unsigned __int8 *)(v20 + 45);
        v111 = *(unsigned __int8 *)(v20 + 46);
        v112 = *(unsigned __int8 *)(v20 + 49);
      }
      qdf_trace_msg(
        0x45u,
        1u,
        "%s: RX tid alloc fail for peer %pK (%02x:%02x:%02x:**:**:%02x)",
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        v107,
        v108,
        "dp_peer_create_wifi3",
        v20,
        v109,
        v110,
        v111,
        v112);
      goto LABEL_113;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v113 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v113 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v113 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v18 + 2197);
      v114 = v18[2198];
      if ( (v114 & 1) == 0 )
      {
LABEL_100:
        raw_spin_unlock(v18 + 2197);
        goto LABEL_101;
      }
    }
    else
    {
      raw_spin_lock_bh(v18 + 2197);
      v114 = v18[2198] | 1;
      v18[2198] = v114;
      if ( (v114 & 1) == 0 )
        goto LABEL_100;
    }
    v18[2198] = v114 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v18 + 2197);
LABEL_101:
    v115 = 1;
    if ( *(_DWORD *)(v8 + 32) == 3 )
    {
      if ( (unsigned int)qdf_mem_cmp(a3, (const void *)(v8 + 96), 6u) )
        v115 = 1;
      else
        v115 = 2;
    }
    dp_peer_add_ast(v18, v20, a3, v115, 0);
    *(_BYTE *)(v20 + 120) = *(_BYTE *)(v20 + 120) & 0xDB | 4;
    dp_local_peer_id_alloc(v17, v20);
    *(_DWORD *)(v20 + 128) = 0;
    *(_QWORD *)(v20 + 136) = 0;
    qdf_mem_set((void *)(v20 + 160), 0x30u, 0);
    v124 = *(_QWORD *)(*(_QWORD *)(v17 + 8) + 20056LL);
    if ( v124 )
    {
      v125 = *(_QWORD *)(v124 + 416);
      if ( v125 )
      {
        v126 = *(void (__fastcall **)(__int64, __int64))(v125 + 336);
        if ( v126 )
        {
          if ( *((_DWORD *)v126 - 1) != -1878589846 )
            __break(0x8228u);
          v126(v17, v20);
          goto LABEL_117;
        }
      }
      v135 = "%s: callback not registered";
    }
    else
    {
      v135 = "%s: monitor soc is NULL";
    }
    qdf_trace_msg(
      0x92u,
      8u,
      v135,
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      "dp_monitor_peer_tx_capture_filter_check");
LABEL_117:
    v136 = v18[2507];
    if ( v136 )
    {
      v137 = *(_QWORD *)(v136 + 416);
      if ( v137 && (v138 = *(void (__fastcall **)(_QWORD))(v137 + 160)) != nullptr )
      {
        if ( *((_DWORD *)v138 - 1) != 1810062434 )
          __break(0x8228u);
        v138(v20);
      }
      else
      {
        qdf_trace_msg(
          0x92u,
          8u,
          "%s: callback not registered",
          v127,
          v128,
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          "dp_monitor_peer_reset_stats");
      }
    }
    v139 = *(_QWORD *)v20;
    if ( *(_QWORD *)v20 )
    {
      *(_DWORD *)(v139 + 120) = 0;
      *(_DWORD *)(v139 + 136) = 64;
      *(_QWORD *)(v139 + 128) = 0;
      *(_QWORD *)(v139 + 96) = v139 + 96;
      *(_QWORD *)(v139 + 104) = v139 + 96;
      *(_QWORD *)(v139 + 112) = 0x4000000000LL;
      v140 = *(_QWORD *)v20;
      if ( *(_QWORD *)v20 )
      {
        v141 = *(unsigned __int8 *)(v140 + 2221);
        *(_DWORD *)(v140 + 44) = 0;
        *(_QWORD *)(v140 + 36) = 0;
        *(_QWORD *)(v140 + 28) = 0;
        *(_QWORD *)(v140 + 20) = 0;
        *(_QWORD *)(v140 + 12) = 0;
        qdf_mem_set((void *)(v140 + 2224), (unsigned int)(3256 * v141), 0);
        v140 = *(_QWORD *)v20;
      }
      if ( *(_WORD *)(v140 + 168) )
      {
        *(_BYTE *)(v140 + 88) &= ~4u;
        v140 = *(_QWORD *)v20;
      }
      *(_BYTE *)(v140 + 10) &= ~4u;
    }
    if ( v20 == -44 )
    {
      v144 = 0;
      v142 = 0;
      v143 = 0;
      v145 = 0;
    }
    else
    {
      v142 = *(unsigned __int8 *)(v20 + 44);
      v143 = *(unsigned __int8 *)(v20 + 45);
      v144 = *(unsigned __int8 *)(v20 + 46);
      v145 = *(unsigned __int8 *)(v20 + 49);
    }
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: vdev %pK Reused peer %pK (%02x:%02x:%02x:**:**:%02x) vdev_ref_cnt %d peer_ref_cnt: %d",
      v127,
      v128,
      v129,
      v130,
      v131,
      v132,
      v133,
      v134,
      "dp_peer_create_wifi3",
      v8,
      v20,
      v142,
      v143,
      v144,
      v145,
      *(_DWORD *)(v8 + 42560),
      *(_DWORD *)(v20 + 40));
    goto LABEL_134;
  }
  raw_spin_lock_bh(v18 + 2360);
  v18[2361] |= 1uLL;
  v20 = v18[2358];
  if ( v20 )
    goto LABEL_74;
LABEL_23:
  v21 = v18[2361];
  if ( (v21 & 1) != 0 )
  {
    v18[2361] = v21 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v18 + 2360);
  }
  else
  {
    raw_spin_unlock(v18 + 2360);
  }
  v22 = (__int64 (__fastcall *)(_QWORD))v18[183];
  if ( *((_DWORD *)v22 - 1) != -1391804861 )
    __break(0x8228u);
  v23 = v22(3);
  if ( !v23 )
  {
    wlan_minidump_log(v24, v25, v26, v27, v28, v29, v30, v31, 0, 424, v18[2]);
    goto LABEL_113;
  }
  v20 = _qdf_mem_malloc(v23, "dp_peer_create_wifi3", 6360);
  wlan_minidump_log(v32, v33, v34, v35, v36, v37, v38, v39, v20, 424, v18[2]);
  if ( !v20 )
  {
LABEL_113:
    dp_vdev_unref_delete((__int64)v18, v8, 7u, v40, v41, v42, v43, v44, v45, v46, v47, v48);
    return 16;
  }
  qdf_mem_set((void *)v20, 0x1A8u, 0);
  *(_QWORD *)(v20 + 24) = v8;
  *(_WORD *)(v20 + 16) = -1;
  qdf_mem_copy((void *)(v20 + 44), a3, 6u);
  v57 = v18[2507];
  if ( v57 )
  {
    v58 = *(_QWORD *)(v57 + 416);
    if ( v58 && (v59 = *(unsigned int (__fastcall **)(_QWORD))(v58 + 136)) != nullptr )
    {
      if ( *((_DWORD *)v59 - 1) != -291477605 )
        __break(0x8228u);
      if ( !v59(v20) )
        goto LABEL_42;
    }
    else
    {
      qdf_trace_msg(
        0x92u,
        8u,
        "%s: callback not registered",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "dp_monitor_peer_attach");
    }
  }
  qdf_trace_msg(
    0x45u,
    3u,
    "%s: peer monitor ctx alloc failed",
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    "dp_peer_create_wifi3");
LABEL_42:
  *(_QWORD *)(v20 + 208) = 0;
  *(_QWORD *)(v20 + 216) = v20 + 208;
  v61 = *(_DWORD *)(v8 + 42560);
  while ( v61 )
  {
    _X12 = (unsigned int *)(v8 + 42560);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v64 = __ldxr(_X12);
      if ( v64 != v61 )
        break;
      if ( !__stlxr(v61 + 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v64 == v61;
    v61 = v64;
    if ( _ZF )
    {
      _X8 = (unsigned int *)(v8 + 42632);
      __asm { PRFM            #0x11, [X8] }
      do
        v170 = __ldxr(_X8);
      while ( __stxr(v170 + 1, _X8) );
      break;
    }
  }
  v65 = 1;
  if ( *(_DWORD *)(v8 + 32) == 3 )
  {
    if ( (unsigned int)qdf_mem_cmp(a3, (const void *)(v8 + 96), 6u) )
      v65 = 1;
    else
      v65 = 2;
  }
  *(_DWORD *)(v20 + 384) = 0;
  *(_QWORD *)(v20 + 392) = 0;
  dp_peer_add_ast(v18, v20, a3, v65, 0);
  *(_DWORD *)(v20 + 128) = 0;
  *(_QWORD *)(v20 + 136) = 0;
  *(_DWORD *)(v20 + 144) = 0;
  *(_QWORD *)(v20 + 152) = 0;
  *(_DWORD *)(v20 + 40) = 0;
  *(_DWORD *)(v20 + 256) = 0;
  *(_DWORD *)(v20 + 260) = 0;
  *(_DWORD *)(v20 + 264) = 0;
  *(_DWORD *)(v20 + 268) = 0;
  *(_DWORD *)(v20 + 272) = 0;
  *(_DWORD *)(v20 + 276) = 0;
  *(_DWORD *)(v20 + 280) = 0;
  *(_DWORD *)(v20 + 284) = 0;
  *(_DWORD *)(v20 + 288) = 0;
  *(_DWORD *)(v20 + 292) = 0;
  *(_DWORD *)(v20 + 296) = 0;
  *(_DWORD *)(v20 + 300) = 0;
  *(_DWORD *)(v20 + 304) = 0;
  *(_DWORD *)(v20 + 308) = 0;
  *(_DWORD *)(v20 + 312) = 0;
  *(_DWORD *)(v20 + 316) = 0;
  *(_DWORD *)(v20 + 320) = 0;
  *(_DWORD *)(v20 + 324) = 0;
  *(_DWORD *)(v20 + 328) = 0;
  *(_DWORD *)(v20 + 332) = 0;
  *(_DWORD *)(v20 + 336) = 0;
  *(_DWORD *)(v20 + 340) = 0;
  *(_DWORD *)(v20 + 344) = 0;
  *(_DWORD *)(v20 + 348) = 0;
  *(_DWORD *)(v20 + 352) = 0;
  *(_DWORD *)(v20 + 356) = 0;
  *(_DWORD *)(v20 + 360) = 0;
  *(_DWORD *)(v20 + 364) = 0;
  *(_DWORD *)(v20 + 368) = 0;
  *(_DWORD *)(v20 + 372) = 0;
  *(_DWORD *)(v20 + 376) = 0;
  _X8 = (unsigned int *)(v20 + 40);
  __asm { PRFM            #0x11, [X8] }
  do
    v164 = __ldxr(_X8);
  while ( __stxr(v164 + 1, _X8) );
  _X8 = (unsigned int *)(v20 + 304);
  __asm { PRFM            #0x11, [X8] }
  do
    v167 = __ldxr(_X8);
  while ( __stxr(v167 + 1, _X8) );
  dp_peer_vdev_list_add(v18, v8, v20);
  dp_peer_find_hash_add(v18, v20);
  v66 = *(unsigned __int8 *)(v20 + 44);
  v67 = *(unsigned __int8 *)(v20 + 45);
  *(_DWORD *)(v20 + 124) = 1;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: vdev %pK created peer %pK (%02x:%02x:%02x:**:**:%02x) vdev_ref_cnt %d peer_ref_cnt: %d",
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    "dp_peer_create_wifi3",
    v8,
    v20,
    v66,
    v67,
    *(unsigned __int8 *)(v20 + 46),
    *(unsigned __int8 *)(v20 + 49),
    *(_DWORD *)(v8 + 42560),
    *(_DWORD *)(v20 + 40));
  if ( !(unsigned int)qdf_mem_cmp((const void *)(v20 + 44), (const void *)(v8 + 96), 6u) )
  {
    if ( *(_DWORD *)(v8 + 32) == 3 )
    {
LABEL_61:
      if ( !(unsigned int)qdf_mem_cmp((const void *)(v20 + 44), (const void *)(v8 + 96), 6u) )
        *(_BYTE *)(v20 + 120) |= 0x10u;
      goto LABEL_63;
    }
    qdf_trace_msg(0x45u, 5u, "%s: vdev bss_peer!!", v76, v77, v78, v79, v80, v81, v82, v83, "dp_peer_create_wifi3");
    v92 = *(_QWORD *)v20;
    *(_BYTE *)(v20 + 120) |= 1u;
    if ( v92 )
      *(_BYTE *)(v92 + 88) |= 2u;
  }
  if ( *(_DWORD *)(v8 + 32) == 3 )
    goto LABEL_61;
LABEL_63:
  if ( (unsigned int)dp_peer_rx_tids_create(v20) )
  {
    LODWORD(v171) = *(unsigned __int8 *)(v20 + 49);
    qdf_trace_msg(
      0x45u,
      1u,
      "%s: RX tid alloc fail for peer %pK (%02x:%02x:%02x:**:**:%02x)",
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      "dp_peer_create_wifi3",
      v20,
      *(unsigned __int8 *)(v20 + 44),
      *(unsigned __int8 *)(v20 + 45),
      *(unsigned __int8 *)(v20 + 46),
      v171);
    _qdf_mem_free(v20);
    goto LABEL_113;
  }
  *(_BYTE *)(v20 + 120) |= 4u;
  dp_local_peer_id_alloc(v17, v20);
  qdf_mem_set((void *)(v20 + 160), 0x30u, 0);
LABEL_134:
  dp_peer_update_state(v20, 1);
  dp_vdev_unref_delete((__int64)v18, v8, 7u, v146, v147, v148, v149, v150, v151, v152, v153, v154);
  return 0;
}
