__int64 __fastcall dp_peer_create_wifi3(__int64 a1, unsigned __int8 a2, const void *a3, int a4)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x19
  unsigned int v11; // w8
  unsigned int v18; // w10
  __int64 v19; // x21
  __int64 *v20; // x20
  unsigned __int64 v21; // x8
  __int64 v22; // x23
  __int64 v23; // x8
  __int64 (__fastcall *v24)(_QWORD); // x8
  size_t v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x8
  __int64 v51; // x8
  unsigned int (__fastcall *v52)(_QWORD); // x8
  __int64 v53; // x8
  unsigned int v54; // w8
  unsigned int v57; // w10
  unsigned int v58; // w24
  __int64 v59; // x6
  __int64 v60; // x7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x8
  unsigned int v86; // w8
  unsigned int v89; // w10
  __int64 v90; // x8
  _QWORD *v91; // x9
  _QWORD *v92; // x8
  __int64 v93; // x8
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x5
  __int64 v103; // x6
  __int64 v104; // x7
  int v105; // w8
  unsigned __int64 v106; // x8
  __int64 v107; // x8
  unsigned int v108; // w25
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  __int64 v117; // x8
  __int64 v118; // x8
  void (__fastcall *v119)(__int64, __int64); // x8
  const char *v120; // x2
  __int64 v121; // x8
  __int64 v122; // x8
  void (__fastcall *v123)(_QWORD); // x8
  __int64 v124; // x8
  __int64 v125; // x8
  int v126; // w9
  __int64 v127; // x8
  __int64 v128; // x6
  __int64 v129; // x7
  int v130; // w8
  int v131; // w9
  unsigned int v134; // w9
  __int64 v135; // x8
  unsigned int v138; // w9
  unsigned int v141; // w9
  unsigned int v144; // w9
  unsigned int v147; // w9
  __int64 v148; // [xsp+0h] [xbp-20h]

  result = 16;
  if ( a2 > 5u || !a3 )
    return result;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 18984);
  }
  else
  {
    raw_spin_lock_bh(a1 + 18984);
    *(_QWORD *)(a1 + 18992) |= 1uLL;
  }
  v10 = *(_QWORD *)(a1 + 8LL * a2 + 12960);
  if ( !v10 )
  {
LABEL_39:
    v53 = *(_QWORD *)(a1 + 18992);
    if ( (v53 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18992) = v53 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18984);
    }
    else
    {
      raw_spin_unlock(a1 + 18984);
    }
    return 16;
  }
  v11 = *(_DWORD *)(v10 + 43384);
  do
  {
    if ( !v11 )
      goto LABEL_39;
    _X12 = (unsigned int *)(v10 + 43384);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v18 = __ldxr(_X12);
      if ( v18 != v11 )
        break;
      if ( !__stlxr(v11 + 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v18 == v11;
    v11 = v18;
  }
  while ( !_ZF );
  _X8 = (unsigned int *)(v10 + 43416);
  __asm { PRFM            #0x11, [X8] }
  do
    v134 = __ldxr(_X8);
  while ( __stxr(v134 + 1, _X8) );
  v135 = *(_QWORD *)(a1 + 18992);
  if ( (v135 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 18992) = v135 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 18984);
  }
  else
  {
    raw_spin_unlock(a1 + 18984);
  }
  v19 = *(_QWORD *)(v10 + 24);
  v20 = *(__int64 **)(v19 + 8);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v21 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v21 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v21 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v20 + 2367);
    v22 = v20[2365];
    if ( !v22 )
      goto LABEL_23;
LABEL_77:
    while ( (*(_BYTE *)(v22 + 120) & 1) == 0
         || *(_QWORD *)(v22 + 24) != v10
         || *(_DWORD *)(v22 + 408) != a4
         || *(__int16 *)(v22 + 16) != -1
         || (unsigned int)qdf_mem_cmp(a3, (const void *)(v22 + 44), 6u) )
    {
LABEL_76:
      v22 = *(_QWORD *)(v22 + 248);
      if ( !v22 )
        goto LABEL_23;
    }
    v86 = *(_DWORD *)(v22 + 40);
    do
    {
      if ( !v86 )
        goto LABEL_76;
      _X12 = (unsigned int *)(v22 + 40);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v89 = __ldxr(_X12);
        if ( v89 != v86 )
          break;
        if ( !__stlxr(v86 + 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v89 == v86;
      v86 = v89;
    }
    while ( !_ZF );
    _X8 = (unsigned int *)(v22 + 312);
    __asm { PRFM            #0x11, [X8] }
    do
      v147 = __ldxr(_X8);
    while ( __stxr(v147 + 1, _X8) );
    v90 = *(_QWORD *)(v22 + 248);
    v91 = *(_QWORD **)(v22 + 256);
    if ( v90 )
      v92 = (_QWORD *)(v90 + 256);
    else
      v92 = v20 + 2366;
    *v92 = v91;
    *v91 = *(_QWORD *)(v22 + 248);
    *(_QWORD *)(v22 + 248) = 0;
    *(_QWORD *)(v22 + 256) = 0;
    v93 = v20[2368];
    if ( (v93 & 1) != 0 )
    {
      v20[2368] = v93 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v20 + 2367);
    }
    else
    {
      raw_spin_unlock(v20 + 2367);
    }
    *(_DWORD *)(v22 + 240) = 0;
    dp_peer_cleanup(v10, v22);
    dp_peer_vdev_list_add(v20, v10, v22);
    dp_peer_find_hash_add(v20, v22);
    if ( (unsigned int)dp_peer_rx_tids_create(v22) )
    {
      if ( v22 == -44 )
      {
        v104 = 0;
        v102 = 0;
        v103 = 0;
        v105 = 0;
      }
      else
      {
        v102 = *(unsigned __int8 *)(v22 + 44);
        v103 = *(unsigned __int8 *)(v22 + 45);
        v104 = *(unsigned __int8 *)(v22 + 46);
        v105 = *(unsigned __int8 *)(v22 + 49);
      }
      qdf_trace_msg(
        0x45u,
        1u,
        "%s: RX tid alloc fail for peer %pK (%02x:%02x:%02x:**:**:%02x)",
        v94,
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        "dp_peer_create_wifi3",
        v22,
        v102,
        v103,
        v104,
        v105);
      goto LABEL_120;
    }
    if ( *(_DWORD *)(v22 + 408) == 2 )
    {
      *(_DWORD *)(v22 + 480) = 0;
      *(_QWORD *)(v22 + 488) = 0;
      *(_BYTE *)(v22 + 476) = 0;
      *(_BYTE *)(v22 + 437) = 0;
      *(_BYTE *)(v22 + 449) = 0;
      *(_BYTE *)(v22 + 461) = 0;
      *(_BYTE *)(v22 + 473) = 0;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v106 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v106 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v106 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v20 + 2204);
      v107 = v20[2205];
      if ( (v107 & 1) == 0 )
      {
LABEL_106:
        raw_spin_unlock(v20 + 2204);
        goto LABEL_107;
      }
    }
    else
    {
      raw_spin_lock_bh(v20 + 2204);
      v107 = v20[2205] | 1;
      v20[2205] = v107;
      if ( (v107 & 1) == 0 )
        goto LABEL_106;
    }
    v20[2205] = v107 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v20 + 2204);
LABEL_107:
    v108 = 1;
    if ( *(_DWORD *)(v10 + 32) == 3 )
    {
      if ( (unsigned int)qdf_mem_cmp(a3, (const void *)(v10 + 96), 6u) )
        v108 = 1;
      else
        v108 = 2;
    }
    dp_peer_add_ast(v20, v22, a3, v108, 0);
    *(_BYTE *)(v22 + 120) = *(_BYTE *)(v22 + 120) & 0xDB | 4;
    dp_local_peer_id_alloc(v19, v22);
    *(_DWORD *)(v22 + 136) = 0;
    *(_QWORD *)(v22 + 144) = 0;
    qdf_mem_set((void *)(v22 + 168), 0x30u, 0);
    if ( *(_DWORD *)(v22 + 408) == 2 )
      goto LABEL_133;
    v117 = *(_QWORD *)(*(_QWORD *)(v19 + 8) + 20112LL);
    if ( v117 )
    {
      v118 = *(_QWORD *)(v117 + 416);
      if ( v118 )
      {
        v119 = *(void (__fastcall **)(__int64, __int64))(v118 + 336);
        if ( v119 )
        {
          if ( *((_DWORD *)v119 - 1) != -1878589846 )
            __break(0x8228u);
          v119(v19, v22);
          goto LABEL_126;
        }
      }
      v120 = "%s: callback not registered";
    }
    else
    {
      v120 = "%s: monitor soc is NULL";
    }
    qdf_trace_msg(
      0x92u,
      8u,
      v120,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      v115,
      v116,
      "dp_monitor_peer_tx_capture_filter_check");
LABEL_126:
    v121 = v20[2514];
    if ( v121 )
    {
      v122 = *(_QWORD *)(v121 + 416);
      if ( v122 && (v123 = *(void (__fastcall **)(_QWORD))(v122 + 160)) != nullptr )
      {
        if ( *((_DWORD *)v123 - 1) != 1810062434 )
          __break(0x8228u);
        v123(v22);
      }
      else
      {
        qdf_trace_msg(
          0x92u,
          8u,
          "%s: callback not registered",
          v109,
          v110,
          v111,
          v112,
          v113,
          v114,
          v115,
          v116,
          "dp_monitor_peer_reset_stats");
      }
    }
LABEL_133:
    v124 = *(_QWORD *)v22;
    if ( *(_QWORD *)v22 )
    {
      *(_DWORD *)(v124 + 120) = 0;
      *(_DWORD *)(v124 + 136) = 64;
      *(_QWORD *)(v124 + 128) = 0;
      *(_QWORD *)(v124 + 96) = v124 + 96;
      *(_QWORD *)(v124 + 104) = v124 + 96;
      *(_QWORD *)(v124 + 112) = 0x4000000000LL;
      v125 = *(_QWORD *)v22;
      if ( *(_QWORD *)v22 )
      {
        v126 = *(unsigned __int8 *)(v125 + 2281);
        *(_DWORD *)(v125 + 44) = 0;
        *(_QWORD *)(v125 + 36) = 0;
        *(_QWORD *)(v125 + 28) = 0;
        *(_QWORD *)(v125 + 20) = 0;
        *(_QWORD *)(v125 + 12) = 0;
        qdf_mem_set((void *)(v125 + 2288), (unsigned int)(4072 * v126), 0);
        v125 = *(_QWORD *)v22;
      }
      if ( *(_WORD *)(v125 + 168) )
      {
        *(_BYTE *)(v125 + 88) &= ~4u;
        v125 = *(_QWORD *)v22;
      }
      *(_BYTE *)(v125 + 10) &= ~4u;
      v127 = *(_QWORD *)v22;
      *(_BYTE *)(v127 + 2280) = 0;
      *(_DWORD *)(v127 + 2276) = 0;
    }
    if ( v22 == -44 )
    {
      v130 = 0;
      v128 = 0;
      v129 = 0;
      v131 = 0;
    }
    else
    {
      v128 = *(unsigned __int8 *)(v22 + 44);
      v129 = *(unsigned __int8 *)(v22 + 45);
      v130 = *(unsigned __int8 *)(v22 + 46);
      v131 = *(unsigned __int8 *)(v22 + 49);
    }
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: vdev %pK Reused peer %pK (%02x:%02x:%02x:**:**:%02x) vdev_ref_cnt %d peer_ref_cnt: %d",
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      v115,
      v116,
      "dp_peer_create_wifi3",
      v10,
      v22,
      v128,
      v129,
      v130,
      v131,
      *(_DWORD *)(v10 + 43384),
      *(_DWORD *)(v22 + 40));
    goto LABEL_143;
  }
  raw_spin_lock_bh(v20 + 2367);
  v20[2368] |= 1uLL;
  v22 = v20[2365];
  if ( v22 )
    goto LABEL_77;
LABEL_23:
  v23 = v20[2368];
  if ( (v23 & 1) != 0 )
  {
    v20[2368] = v23 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v20 + 2367);
  }
  else
  {
    raw_spin_unlock(v20 + 2367);
  }
  v24 = (__int64 (__fastcall *)(_QWORD))v20[183];
  if ( *((_DWORD *)v24 - 1) != -1391804861 )
    __break(0x8228u);
  v25 = v24(3);
  if ( !v25 )
  {
    wlan_minidump_log(v26, v27, v28, v29, v30, v31, v32, v33, 0, 520, v20[2]);
    goto LABEL_120;
  }
  v22 = _qdf_mem_malloc(v25, "dp_peer_create_wifi3", 6360);
  wlan_minidump_log(v34, v35, v36, v37, v38, v39, v40, v41, v22, 520, v20[2]);
  if ( !v22 )
  {
LABEL_120:
    dp_vdev_unref_delete(v20, v10, 7);
    return 16;
  }
  qdf_mem_set((void *)v22, 0x208u, 0);
  *(_QWORD *)(v22 + 24) = v10;
  *(_WORD *)(v22 + 16) = -1;
  qdf_mem_copy((void *)(v22 + 44), a3, 6u);
  *(_DWORD *)(v22 + 408) = a4;
  if ( a4 == 2 )
  {
    if ( (unsigned int)dp_txrx_peer_attach((__int64)v20, v22) )
    {
LABEL_67:
      _qdf_mem_free(v22);
      goto LABEL_120;
    }
    *(_DWORD *)(v22 + 480) = 0;
    *(_QWORD *)(v22 + 488) = 0;
    *(_BYTE *)(v22 + 476) = 0;
    *(_BYTE *)(v22 + 437) = 0;
    *(_BYTE *)(v22 + 449) = 0;
    *(_BYTE *)(v22 + 461) = 0;
    *(_BYTE *)(v22 + 473) = 0;
  }
  v50 = v20[2514];
  if ( v50 )
  {
    v51 = *(_QWORD *)(v50 + 416);
    if ( v51 && (v52 = *(unsigned int (__fastcall **)(_QWORD))(v51 + 136)) != nullptr )
    {
      if ( *((_DWORD *)v52 - 1) != -291477605 )
        __break(0x8228u);
      if ( !v52(v22) )
        goto LABEL_44;
    }
    else
    {
      qdf_trace_msg(
        0x92u,
        8u,
        "%s: callback not registered",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "dp_monitor_peer_attach");
    }
  }
  qdf_trace_msg(
    0x45u,
    3u,
    "%s: peer monitor ctx alloc failed",
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    "dp_peer_create_wifi3");
LABEL_44:
  *(_QWORD *)(v22 + 216) = 0;
  *(_QWORD *)(v22 + 224) = v22 + 216;
  v54 = *(_DWORD *)(v10 + 43384);
  while ( v54 )
  {
    _X12 = (unsigned int *)(v10 + 43384);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v57 = __ldxr(_X12);
      if ( v57 != v54 )
        break;
      if ( !__stlxr(v54 + 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v57 == v54;
    v54 = v57;
    if ( _ZF )
    {
      _X8 = (unsigned int *)(v10 + 43456);
      __asm { PRFM            #0x11, [X8] }
      do
        v144 = __ldxr(_X8);
      while ( __stxr(v144 + 1, _X8) );
      break;
    }
  }
  v58 = 1;
  if ( *(_DWORD *)(v10 + 32) == 3 )
  {
    if ( (unsigned int)qdf_mem_cmp(a3, (const void *)(v10 + 96), 6u) )
      v58 = 1;
    else
      v58 = 2;
  }
  *(_DWORD *)(v22 + 392) = 0;
  *(_QWORD *)(v22 + 400) = 0;
  dp_peer_add_ast(v20, v22, a3, v58, 0);
  *(_DWORD *)(v22 + 136) = 0;
  *(_QWORD *)(v22 + 144) = 0;
  *(_DWORD *)(v22 + 152) = 0;
  *(_QWORD *)(v22 + 160) = 0;
  *(_DWORD *)(v22 + 40) = 0;
  *(_DWORD *)(v22 + 264) = 0;
  *(_DWORD *)(v22 + 268) = 0;
  *(_DWORD *)(v22 + 272) = 0;
  *(_DWORD *)(v22 + 276) = 0;
  *(_DWORD *)(v22 + 280) = 0;
  *(_DWORD *)(v22 + 284) = 0;
  *(_DWORD *)(v22 + 288) = 0;
  *(_DWORD *)(v22 + 292) = 0;
  *(_DWORD *)(v22 + 296) = 0;
  *(_DWORD *)(v22 + 300) = 0;
  *(_DWORD *)(v22 + 304) = 0;
  *(_DWORD *)(v22 + 308) = 0;
  *(_DWORD *)(v22 + 312) = 0;
  *(_DWORD *)(v22 + 316) = 0;
  *(_DWORD *)(v22 + 320) = 0;
  *(_DWORD *)(v22 + 324) = 0;
  *(_DWORD *)(v22 + 328) = 0;
  *(_DWORD *)(v22 + 332) = 0;
  *(_DWORD *)(v22 + 336) = 0;
  *(_DWORD *)(v22 + 340) = 0;
  *(_DWORD *)(v22 + 344) = 0;
  *(_DWORD *)(v22 + 348) = 0;
  *(_DWORD *)(v22 + 352) = 0;
  *(_DWORD *)(v22 + 356) = 0;
  *(_DWORD *)(v22 + 360) = 0;
  *(_DWORD *)(v22 + 364) = 0;
  *(_DWORD *)(v22 + 368) = 0;
  *(_DWORD *)(v22 + 372) = 0;
  *(_DWORD *)(v22 + 376) = 0;
  *(_DWORD *)(v22 + 380) = 0;
  *(_DWORD *)(v22 + 384) = 0;
  _X8 = (unsigned int *)(v22 + 40);
  __asm { PRFM            #0x11, [X8] }
  do
    v138 = __ldxr(_X8);
  while ( __stxr(v138 + 1, _X8) );
  _X8 = (unsigned int *)(v22 + 312);
  __asm { PRFM            #0x11, [X8] }
  do
    v141 = __ldxr(_X8);
  while ( __stxr(v141 + 1, _X8) );
  dp_peer_vdev_list_add(v20, v10, v22);
  dp_peer_find_hash_add(v20, v22);
  v59 = *(unsigned __int8 *)(v22 + 44);
  v60 = *(unsigned __int8 *)(v22 + 45);
  *(_DWORD *)(v22 + 124) = 1;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: vdev %pK created peer %pK (%02x:%02x:%02x:**:**:%02x) vdev_ref_cnt %d peer_ref_cnt: %d",
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    "dp_peer_create_wifi3",
    v10,
    v22,
    v59,
    v60,
    *(unsigned __int8 *)(v22 + 46),
    *(unsigned __int8 *)(v22 + 49),
    *(_DWORD *)(v10 + 43384),
    *(_DWORD *)(v22 + 40));
  if ( !(unsigned int)qdf_mem_cmp((const void *)(v22 + 44), (const void *)(v10 + 96), 6u) )
  {
    if ( *(_DWORD *)(v10 + 32) == 3 )
    {
LABEL_63:
      if ( !(unsigned int)qdf_mem_cmp((const void *)(v22 + 44), (const void *)(v10 + 96), 6u) )
        *(_BYTE *)(v22 + 120) |= 0x10u;
      goto LABEL_65;
    }
    qdf_trace_msg(0x45u, 5u, "%s: vdev bss_peer!!", v69, v70, v71, v72, v73, v74, v75, v76, "dp_peer_create_wifi3");
    v85 = *(_QWORD *)v22;
    *(_BYTE *)(v22 + 120) |= 1u;
    if ( v85 )
      *(_BYTE *)(v85 + 88) |= 2u;
  }
  if ( *(_DWORD *)(v10 + 32) == 3 )
    goto LABEL_63;
LABEL_65:
  if ( (unsigned int)dp_peer_rx_tids_create(v22) )
  {
    LODWORD(v148) = *(unsigned __int8 *)(v22 + 49);
    qdf_trace_msg(
      0x45u,
      1u,
      "%s: RX tid alloc fail for peer %pK (%02x:%02x:%02x:**:**:%02x)",
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      "dp_peer_create_wifi3",
      v22,
      *(unsigned __int8 *)(v22 + 44),
      *(unsigned __int8 *)(v22 + 45),
      *(unsigned __int8 *)(v22 + 46),
      v148);
    goto LABEL_67;
  }
  *(_BYTE *)(v22 + 120) |= 4u;
  dp_local_peer_id_alloc(v19, v22);
  qdf_mem_set((void *)(v22 + 168), 0x30u, 0);
LABEL_143:
  dp_peer_update_state(v22, 1);
  dp_vdev_unref_delete(v20, v10, 7);
  return 0;
}
