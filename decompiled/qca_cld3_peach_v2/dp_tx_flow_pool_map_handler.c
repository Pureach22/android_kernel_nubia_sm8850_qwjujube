__int64 __fastcall dp_tx_flow_pool_map_handler(
        _QWORD *a1,
        unsigned int a2,
        unsigned __int8 a3,
        unsigned int a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  _QWORD *v16; // x20
  __int64 v18; // x23
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _DWORD *v27; // x10
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 flow_pool; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  const char *v45; // x2
  const char *v46; // x3
  __int64 v47; // x4
  __int64 result; // x0
  __int64 v49; // x21
  __int64 v50; // x23
  __int64 v51; // x24
  unsigned __int64 StatusReg; // x8
  __int64 v53; // x22
  __int64 v54; // x25
  unsigned int v55; // w8
  unsigned int v61; // w10
  char v62; // w24
  __int64 v63; // x8
  unsigned __int64 v64; // x8
  __int64 v65; // x8
  __int64 v66; // x8
  unsigned __int64 v67; // x8
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x24
  __int64 v77; // x23
  unsigned int v78; // w8
  unsigned int v81; // w10
  char v83; // w8
  unsigned int v85; // w9
  __int64 v86; // x8
  __int64 v87; // x0
  __int64 v88; // x8
  double (__fastcall *v89)(__int64, __int64, __int64); // x8
  __int64 v90; // x1
  double v91; // d0
  unsigned int *v92; // x8
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  unsigned __int64 v100; // x8
  unsigned int v101; // w9
  unsigned int v104; // w11
  unsigned __int64 v105; // x8
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  _QWORD *v114; // x27
  unsigned __int64 v115; // x8
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  __int64 v124; // x22
  __int64 v125; // x8
  __int64 v126; // x0
  __int64 v127; // x1
  unsigned int v128; // w9
  unsigned int v131; // w11
  unsigned int *v132; // x8
  unsigned int v136; // w9
  __int64 v137; // x8
  int v138; // w8
  unsigned __int64 v139; // x8
  _QWORD *v140; // x0
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  __int64 v149; // x22
  __int64 (__fastcall *v150)(__int64, __int64); // x8
  __int64 v151; // x0
  __int64 v152; // x8
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  __int64 v161; // x8
  unsigned int *v162; // x8
  double v163; // d0
  double v164; // d1
  double v165; // d2
  double v166; // d3
  double v167; // d4
  double v168; // d5
  double v169; // d6
  double v170; // d7
  unsigned int v173; // w9
  __int64 v174; // x8
  unsigned int v177; // w9
  __int64 v178; // x8
  unsigned int v181; // w9
  unsigned int v184; // w9
  int v185; // [xsp+8h] [xbp-18h] BYREF
  __int16 v186; // [xsp+Ch] [xbp-14h]
  __int64 v187; // [xsp+18h] [xbp-8h]

  v16 = a1;
  v187 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = a1[1];
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: flow_id %d flow_type %d flow_pool_id %d flow_pool_size %d",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "dp_tx_flow_pool_map_handler",
    (unsigned __int8)a2,
    a3,
    (unsigned __int8)a4,
    a5);
  if ( !v18 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: soc is NULL", v19, v20, v21, v22, v23, v24, v25, v26, "dp_tx_flow_pool_map_handler");
    result = 5;
    goto LABEL_161;
  }
  v27 = *(_DWORD **)(v18 + 1880);
  ++*(_WORD *)(v18 + 12928);
  if ( *(v27 - 1) != 219348464 )
    __break(0x822Au);
  if ( (((__int64 (__fastcall *)(__int64, _QWORD, __int64))v27)(v18, a2, 30) & 1) != 0 )
    goto LABEL_160;
  flow_pool = dp_tx_create_flow_pool(v18, a4, a5, v28, v29, v30, v31, v32, v33, v34, v35);
  if ( !flow_pool )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: creation of flow_pool %d size %d failed",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "dp_tx_flow_pool_map_handler",
      (unsigned __int8)a4,
      a5);
    result = 1;
    goto LABEL_161;
  }
  if ( a3 )
  {
    v45 = "%s: flow type %d not supported";
    v46 = "dp_tx_flow_pool_map_handler";
    v47 = a3;
    goto LABEL_8;
  }
  if ( (unsigned __int8)a2 <= 5u )
  {
    v49 = v16[1];
    v50 = flow_pool;
    v51 = 18984;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v49 + 18984);
    }
    else
    {
      raw_spin_lock_bh(v49 + 18984);
      *(_QWORD *)(v49 + 18992) |= 1uLL;
    }
    v53 = *(_QWORD *)(v49 + 8LL * (unsigned __int8)a2 + 12960);
    if ( v53 )
    {
      v54 = v53 + 40960;
      v55 = *(_DWORD *)(v53 + 43384);
      while ( v55 )
      {
        _X12 = (unsigned int *)(v53 + 43384);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v61 = __ldxr(_X12);
          if ( v61 != v55 )
            break;
          if ( !__stlxr(v55 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v61 == v55;
        v55 = v61;
        if ( _ZF )
          goto LABEL_170;
      }
    }
    v63 = *(_QWORD *)(v49 + 18992);
    if ( (v63 & 1) != 0 )
    {
      *(_QWORD *)(v49 + 18992) = v63 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v49 + 18984);
    }
    else
    {
      raw_spin_unlock(v49 + 18984);
    }
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: invalid vdev_id %d",
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    "dp_tx_flow_pool_vdev_map",
    (unsigned __int8)a2);
  while ( 2 )
  {
    v16 = (_QWORD *)v16[1];
    if ( (wlan_cfg_get_dp_tx_page_pool_enabled(v16[5]) & 1) == 0 )
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Tx page pool disabled from INI",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "dp_tx_page_pool_vdev_attach");
      goto LABEL_160;
    }
    if ( (unsigned __int8)a2 > 5u )
      goto LABEL_112;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v100 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v100 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v100 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v16 + 2373);
    }
    else
    {
      raw_spin_lock_bh(v16 + 2373);
      v16[2374] |= 1uLL;
    }
    v54 = (unsigned __int8)a2;
    v49 = v16[(unsigned __int8)a2 + 1620];
    if ( !v49 )
    {
LABEL_110:
      v125 = v16[2374];
      if ( (v125 & 1) != 0 )
      {
        v16[2374] = v125 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v16 + 2373);
      }
      else
      {
        raw_spin_unlock(v16 + 2373);
      }
LABEL_112:
      v45 = "%s: invalid vdev_id %d";
      v46 = "dp_tx_page_pool_vdev_attach";
      v47 = (unsigned __int8)a2;
LABEL_8:
      qdf_trace_msg(0x45u, 2u, v45, v37, v38, v39, v40, v41, v42, v43, v44, v46, v47);
      goto LABEL_160;
    }
    v101 = *(_DWORD *)(v49 + 43384);
    do
    {
      if ( !v101 )
        goto LABEL_110;
      _X13 = (unsigned int *)(v49 + 43384);
      __asm { PRFM            #0x11, [X13] }
      while ( 1 )
      {
        v104 = __ldxr(_X13);
        if ( v104 != v101 )
          break;
        if ( !__stlxr(v101 + 1, _X13) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v104 == v101;
      v101 = v104;
    }
    while ( !_ZF );
    _X8 = (unsigned int *)(v49 + 43416);
    __asm { PRFM            #0x11, [X8] }
    do
      v177 = __ldxr(_X8);
    while ( __stxr(v177 + 1, _X8) );
    v178 = v16[2374];
    if ( (v178 & 1) != 0 )
    {
      v16[2374] = v178 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v16 + 2373);
    }
    else
    {
      raw_spin_unlock(v16 + 2373);
    }
    v51 = 22504;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v105 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v105 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v105 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v16 + 2813);
    }
    else
    {
      raw_spin_lock_bh(v16 + 2813);
      v16[2814] |= 1uLL;
    }
    v114 = v16 + 2807;
    if ( v16[(unsigned __int8)a2 + 2807] )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Not expected to have tx_pp attached for a new vdev",
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        "dp_tx_page_pool_vdev_attach");
      v126 = printk(
               &unk_AAA255,
               "0",
               "dp_tx_page_pool_vdev_attach",
               "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_tx_flow_control.c");
      dump_stack(v126);
      goto LABEL_157;
    }
    if ( *(_DWORD *)(v49 + 32) != 3 || !(*(_DWORD *)(v49 + 104) | *(unsigned __int16 *)(v49 + 108)) )
      break;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v115 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v115 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v115 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v16 + 2373);
    }
    else
    {
      raw_spin_lock_bh(v16 + 2373);
      v16[2374] |= 1uLL;
    }
    v124 = 0;
    while ( 1 )
    {
      v127 = v16[v124 + 1620];
      if ( v127 )
        break;
LABEL_115:
      if ( ++v124 == 6 )
      {
        v53 = 0;
        v50 = 0;
        goto LABEL_136;
      }
    }
    v128 = *(_DWORD *)(v127 + 43384);
    do
    {
      if ( !v128 )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Unable to get vdev ref",
          v116,
          v117,
          v118,
          v119,
          v120,
          v121,
          v122,
          v123,
          "dp_tx_page_pool_mlo_vdev_attach");
        goto LABEL_115;
      }
      _X13 = (unsigned int *)(v127 + 43384);
      __asm { PRFM            #0x11, [X13] }
      while ( 1 )
      {
        v131 = __ldxr(_X13);
        if ( v131 != v128 )
          break;
        if ( !__stlxr(v128 + 1, _X13) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v131 == v128;
      v128 = v131;
    }
    while ( !_ZF );
    _X8 = (unsigned int *)(v127 + 43416);
    __asm { PRFM            #0x11, [X8] }
    do
      v136 = __ldxr(_X8);
    while ( __stxr(v136 + 1, _X8) );
    v132 = (unsigned int *)*(unsigned int *)(v127 + 104);
    _ZF = (_DWORD)v132 == *(_DWORD *)(v49 + 104)
       && *(unsigned __int16 *)(v127 + 108) == *(unsigned __int16 *)(v49 + 108);
    if ( !_ZF )
    {
      dp_vdev_unref_delete((__int64)v16, v127, 7u, v132, v116, v117, v118, v119, v120, v121, v122, v123);
      goto LABEL_115;
    }
    v50 = v114[v124];
    dp_vdev_unref_delete((__int64)v16, v127, 7u, v132, v116, v117, v118, v119, v120, v121, v122, v123);
    v53 = (_DWORD)v124 != 6;
LABEL_136:
    v137 = v16[2374];
    if ( (v137 & 1) != 0 )
    {
      v16[2374] = v137 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v16 + 2373);
    }
    else
    {
      raw_spin_unlock(v16 + 2373);
    }
    if ( v50 )
      v138 = v53;
    else
      v138 = 0;
    if ( v138 == 1 && *(_BYTE *)(v50 + 56) == 1 )
    {
      v139 = *(unsigned __int8 *)(v49 + 59);
      if ( v139 <= 5 )
      {
        v114[v139] = v50;
        _X8 = (unsigned int *)(v50 + 60);
        __asm { PRFM            #0x11, [X8] }
        do
          v184 = __ldxr(_X8);
        while ( __stxr(v184 + 1, _X8) );
        goto LABEL_157;
      }
      __break(0x5512u);
LABEL_170:
      _X8 = (unsigned int *)(v54 + 2456);
      __asm { PRFM            #0x11, [X8] }
      do
        v173 = __ldxr(_X8);
      while ( __stxr(v173 + 1, _X8) );
      v174 = *(_QWORD *)(v49 + 18992);
      if ( (v174 & 1) != 0 )
      {
        *(_QWORD *)(v49 + 18992) = v174 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v49 + v51);
      }
      else
      {
        raw_spin_unlock(v49 + v51);
      }
      if ( *(_DWORD *)(v53 + 32) == 6 )
        v62 = *(_BYTE *)(*(_QWORD *)(v49 + 40) + 834LL);
      else
        v62 = 0;
      *(_QWORD *)(v54 + 2296) = v50;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v64 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v64 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v64 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v50 + 256);
      }
      else
      {
        raw_spin_lock_bh(v50 + 256);
        *(_QWORD *)(v50 + 264) |= 1uLL;
      }
      *(_QWORD *)(v50 + 280) = v49;
      *(_BYTE *)(v50 + 58) = a2;
      if ( (v62 & 1) != 0 )
      {
        *(_DWORD *)(v50 + 244) = *(_DWORD *)(v53 + 32);
        qdf_mem_set((void *)(v50 + 152), 0xAu, 0);
        qdf_mem_set((void *)(v50 + 164), 0x14u, 0);
        qdf_mem_set((void *)(v50 + 184), 0x14u, 0);
        qdf_mem_set((void *)(v50 + 204), 0x14u, 0);
        v65 = *(_QWORD *)(v50 + 264);
        *(_BYTE *)(v50 + 248) = 0;
        *(_DWORD *)(v50 + 240) = -1;
        *(_QWORD *)(v50 + 224) = -1;
        *(_QWORD *)(v50 + 232) = -1;
        if ( (v65 & 1) == 0 )
        {
          raw_spin_unlock(v50 + 256);
          v66 = *(_QWORD *)(v53 + 24);
          if ( v66 )
            goto LABEL_40;
LABEL_76:
          v89 = *(double (__fastcall **)(__int64, __int64, __int64))(v49 + 1880);
          v90 = *(unsigned __int8 *)(v53 + 59);
          if ( *((_DWORD *)v89 - 1) != 219348464 )
            __break(0x8228u);
          v91 = v89(v49, v90, 30);
          dp_vdev_unref_delete(v49, v53, 7u, v92, v91, v93, v94, v95, v96, v97, v98, v99);
          continue;
        }
        *(_QWORD *)(v50 + 264) = v65 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v50 + 256);
        v66 = *(_QWORD *)(v53 + 24);
        if ( !v66 )
          goto LABEL_76;
LABEL_40:
        if ( !*(_QWORD *)(v66 + 8) )
          goto LABEL_76;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v67 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v67 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v67 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v53 + 144);
          v76 = *(_QWORD *)(v53 + 128);
          if ( v76 )
            goto LABEL_45;
        }
        else
        {
          raw_spin_lock_bh(v53 + 144);
          *(_QWORD *)(v53 + 152) |= 1uLL;
          v76 = *(_QWORD *)(v53 + 128);
          while ( v76 )
          {
LABEL_45:
            v77 = v76;
            v76 = *(_QWORD *)(v76 + 56);
            v78 = *(_DWORD *)(v77 + 40);
            while ( v78 )
            {
              _X12 = (unsigned int *)(v77 + 40);
              __asm { PRFM            #0x11, [X12] }
              while ( 1 )
              {
                v81 = __ldxr(_X12);
                if ( v81 != v78 )
                  break;
                if ( !__stlxr(v78 + 1, _X12) )
                {
                  __dmb(0xBu);
                  break;
                }
              }
              _ZF = v81 == v78;
              v78 = v81;
              if ( _ZF )
              {
                _X8 = (unsigned int *)(v77 + 292);
                __asm { PRFM            #0x11, [X8] }
                do
                  v85 = __ldxr(_X8);
                while ( __stxr(v85 + 1, _X8) );
                v83 = *(_BYTE *)(v77 + 120);
                v186 = -1;
                v185 = -1;
                if ( (v83 & 1) == 0 && (unsigned int)qdf_mem_cmp((const void *)(v77 + 44), &v185, 6u) )
                  dp_tx_ndp_update_bw_thresholds(
                    *(__int64 **)v77,
                    5u,
                    *(_DWORD *)(*(_QWORD *)v77 + 2216LL),
                    v68,
                    v69,
                    v70,
                    v71,
                    v72,
                    v73,
                    v74,
                    v75);
                dp_peer_unref_delete(v77, 7u, v68, v69, v70, v71, v72, v73, v74, v75);
                break;
              }
            }
          }
        }
        v88 = *(_QWORD *)(v53 + 152);
        if ( (v88 & 1) != 0 )
        {
          *(_QWORD *)(v53 + 152) = v88 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v53 + 144);
          goto LABEL_76;
        }
        v87 = v53 + 144;
      }
      else
      {
        v86 = *(_QWORD *)(v50 + 264);
        if ( (v86 & 1) != 0 )
        {
          *(_QWORD *)(v50 + 264) = v86 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v50 + 256);
          goto LABEL_76;
        }
        v87 = v50 + 256;
      }
      raw_spin_unlock(v87);
      goto LABEL_76;
    }
    break;
  }
  v140 = (_QWORD *)_qdf_mem_malloc(0x40u, "dp_tx_page_pool_vdev_attach", 840);
  if ( v140 )
  {
    v140[6] = 0;
    v140[7] = 0;
    v149 = (__int64)v140;
    v140[4] = 0;
    v140[5] = 0;
    v140[2] = 0;
    v140[3] = 0;
    *v140 = 0;
    v140[1] = 0;
    v150 = *(__int64 (__fastcall **)(__int64, __int64))(v16[1] + 264LL);
    if ( !v150 )
      goto LABEL_152;
    if ( *((_DWORD *)v150 - 1) != 1104720864 )
      __break(0x8228u);
    v151 = v150(1, 10240);
    if ( v151 && (v152 = *(_QWORD *)(v151 + 8)) != 0 )
    {
      *(_QWORD *)v149 = v152;
      *(_QWORD *)(v149 + 8) = *(unsigned int *)(v151 + 16);
      *(_QWORD *)(v149 + 16) = *(_QWORD *)(v151 + 24);
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Tx pp init success pool_size %d pp_size %lu",
        v141,
        v142,
        v143,
        v144,
        v145,
        v146,
        v147,
        v148,
        "dp_tx_page_pool_init",
        *(unsigned int *)(v151 + 16));
      *(_DWORD *)(v149 + 40) = 0;
      *(_QWORD *)(v149 + 48) = 0;
      *(_DWORD *)(v149 + 60) = 0;
      *(_BYTE *)(v149 + 56) = 1;
      *(_BYTE *)(v16[3] + 624LL) = 1;
    }
    else
    {
LABEL_152:
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: failed to get tx page pool",
        v141,
        v142,
        v143,
        v144,
        v145,
        v146,
        v147,
        v148,
        "dp_tx_page_pool_init");
    }
    if ( (*(_BYTE *)(v149 + 56) & 1) != 0 )
    {
      v114[(unsigned __int8)a2] = v149;
      _X8 = (unsigned int *)(v149 + 60);
      __asm { PRFM            #0x11, [X8] }
      do
        v181 = __ldxr(_X8);
      while ( __stxr(v181 + 1, _X8) );
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Unable to init tx page pool for vdev %d",
        v153,
        v154,
        v155,
        v156,
        v157,
        v158,
        v159,
        v160,
        "dp_tx_page_pool_vdev_attach",
        (unsigned __int8)a2);
      _qdf_mem_free(v149);
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to allocated memory for tx page pool",
      v141,
      v142,
      v143,
      v144,
      v145,
      v146,
      v147,
      v148,
      "dp_tx_page_pool_vdev_attach");
  }
LABEL_157:
  v161 = v16[2814];
  if ( (v161 & 1) != 0 )
  {
    v16[2814] = v161 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v16 + 2813);
  }
  else
  {
    raw_spin_unlock(v16 + 2813);
  }
  dp_vdev_unref_delete((__int64)v16, v49, 7u, v162, v163, v164, v165, v166, v167, v168, v169, v170);
LABEL_160:
  result = 0;
LABEL_161:
  _ReadStatusReg(SP_EL0);
  return result;
}
