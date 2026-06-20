__int64 __fastcall dp_set_vdev_param_wrapper(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        _QWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v16; // x9
  __int64 v17; // x10
  unsigned int v18; // w24
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v28; // x26
  __int64 v29; // x23
  unsigned int v30; // w9
  unsigned int v37; // w11
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned __int64 v46; // x8
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x25
  __int64 v56; // x0
  unsigned int v57; // w8
  unsigned int v60; // w10
  __int64 v61; // x8
  unsigned int v64; // w9
  __int64 v65; // x8
  unsigned int *v66; // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  unsigned int v75; // w25
  __int64 v76; // x8
  unsigned __int64 v77; // x8
  __int64 v78; // x25
  unsigned int v79; // w9
  unsigned int v82; // w11
  unsigned int *v83; // x8
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  unsigned __int64 v92; // x28
  unsigned __int64 v93; // x8
  __int64 v94; // x26
  unsigned int v95; // w9
  unsigned int v98; // w11
  _DWORD *v99; // x8
  __int64 v100; // x0
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  unsigned int *v109; // x8
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  __int64 v118; // x8
  __int64 v119; // x8
  __int64 v120; // x9
  __int64 v121; // x10
  unsigned __int64 v122; // x8
  __int64 v123; // x22
  _BYTE *v124; // x24
  unsigned int v125; // w8
  unsigned int v128; // w10
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  __int64 v137; // x8
  __int64 result; // x0
  unsigned int v139; // w23
  unsigned int v140; // w0
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  __int64 v149; // x8
  unsigned int v150; // w21
  __int64 v151; // x8
  const char *v152; // x2
  const char *v153; // x3
  __int64 v154; // x4
  __int64 v155; // x8
  double v156; // d0
  double v157; // d1
  double v158; // d2
  double v159; // d3
  double v160; // d4
  double v161; // d5
  double v162; // d6
  double v163; // d7
  _DWORD *v164; // x8
  __int64 v165; // x0
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  unsigned int *v174; // x8
  double v175; // d0
  double v176; // d1
  double v177; // d2
  double v178; // d3
  double v179; // d4
  double v180; // d5
  double v181; // d6
  double v182; // d7
  __int64 v183; // x4
  const char *v184; // x3
  unsigned int v187; // w9
  __int64 v188; // x8
  unsigned int v191; // w9
  __int64 v192; // x8
  unsigned int v195; // w9
  __int64 v196; // x8
  unsigned int v199; // w9
  __int64 v200; // [xsp+30h] [xbp-50h] BYREF
  __int128 v201; // [xsp+38h] [xbp-48h]
  _BYTE v202[24]; // [xsp+48h] [xbp-38h] BYREF
  unsigned __int64 v203; // [xsp+60h] [xbp-20h]
  _BYTE v204[15]; // [xsp+68h] [xbp-18h]
  __int64 v205; // [xsp+78h] [xbp-8h]

  v205 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_QWORD *)((char *)a4 + 9);
  v17 = a4[2];
  v18 = *(unsigned __int8 *)a4;
  v203 = *(_QWORD *)((char *)a4 + 1);
  *(_QWORD *)v204 = v16;
  *(_QWORD *)&v204[7] = v17;
  if ( a3 == 6 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: update TDLS flag for vdev_id %d, val %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "dp_update_mlo_vdev_for_tdls",
      a2,
      v18);
    if ( a2 <= 5u )
    {
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
      v28 = a1 + 12960;
      v29 = *(_QWORD *)(a1 + 12960 + 8LL * a2);
      if ( v29 )
      {
        v30 = *(_DWORD *)(v29 + 43384);
        do
        {
          if ( !v30 )
            goto LABEL_41;
          _X13 = (unsigned int *)(v29 + 43384);
          __asm { PRFM            #0x11, [X13] }
          while ( 1 )
          {
            v37 = __ldxr(_X13);
            if ( v37 != v30 )
              break;
            if ( !__stlxr(v30 + 1, _X13) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v37 == v30;
          v30 = v37;
        }
        while ( !_ZF );
        _X8 = (unsigned int *)(v29 + 43472);
        __asm { PRFM            #0x11, [X8] }
        do
          v191 = __ldxr(_X8);
        while ( __stxr(v191 + 1, _X8) );
        v192 = *(_QWORD *)(a1 + 18992);
        if ( (v192 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 18992) = v192 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 18984);
        }
        else
        {
          raw_spin_unlock(a1 + 18984);
        }
        if ( *(_DWORD *)(v29 + 32) != 3 )
        {
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: vdev is not as expected for TDLS",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "dp_update_mlo_vdev_for_tdls");
          goto LABEL_95;
        }
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v46 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v46 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v46 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v29 + 144);
          v55 = *(_QWORD *)(v29 + 128);
          if ( !v55 )
            goto LABEL_49;
        }
        else
        {
          raw_spin_lock_bh(v29 + 144);
          *(_QWORD *)(v29 + 152) |= 1uLL;
          v55 = *(_QWORD *)(v29 + 128);
          if ( !v55 )
            goto LABEL_49;
        }
        while ( 2 )
        {
          v56 = v55;
          v55 = *(_QWORD *)(v55 + 56);
          v57 = *(_DWORD *)(v56 + 40);
          while ( v57 )
          {
            _X12 = (unsigned int *)(v56 + 40);
            __asm { PRFM            #0x11, [X12] }
            while ( 1 )
            {
              v60 = __ldxr(_X12);
              if ( v60 != v57 )
                break;
              if ( !__stlxr(v57 + 1, _X12) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v60 == v57;
            v57 = v60;
            if ( _ZF )
            {
              _X8 = (unsigned int *)(v56 + 312);
              __asm { PRFM            #0x11, [X8] }
              do
                v64 = __ldxr(_X8);
              while ( __stxr(v64 + 1, _X8) );
              if ( *(_DWORD *)(v56 + 408) == 1 )
              {
                v61 = *(_QWORD *)(v56 + 416);
                if ( v61 )
                {
                  v75 = *(unsigned __int8 *)(*(_QWORD *)(v61 + 24) + 59LL);
                  dp_peer_unref_delete(v56, 0xCu, v47, v48, v49, v50, v51, v52, v53, v54);
                  goto LABEL_50;
                }
              }
              dp_peer_unref_delete(v56, 0xCu, v47, v48, v49, v50, v51, v52, v53, v54);
              break;
            }
          }
          if ( v55 )
            continue;
          break;
        }
LABEL_49:
        v75 = 255;
LABEL_50:
        v76 = *(_QWORD *)(v29 + 152);
        if ( (v76 & 1) != 0 )
        {
          *(_QWORD *)(v29 + 152) = v76 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v29 + 144);
          if ( v75 <= 5 )
          {
LABEL_52:
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (v77 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v77 + 16) & 0xF0000) != 0)
              || (*(_DWORD *)(v77 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(a1 + 18984);
              v78 = *(_QWORD *)(v28 + 8LL * v75);
              if ( v78 )
              {
LABEL_56:
                v79 = *(_DWORD *)(v78 + 43384);
                do
                {
                  if ( !v79 )
                    goto LABEL_88;
                  _X13 = (unsigned int *)(v78 + 43384);
                  __asm { PRFM            #0x11, [X13] }
                  while ( 1 )
                  {
                    v82 = __ldxr(_X13);
                    if ( v82 != v79 )
                      break;
                    if ( !__stlxr(v79 + 1, _X13) )
                    {
                      __dmb(0xBu);
                      break;
                    }
                  }
                  _ZF = v82 == v79;
                  v79 = v82;
                }
                while ( !_ZF );
                _X8 = (unsigned int *)(v78 + 43472);
                __asm { PRFM            #0x11, [X8] }
                do
                  v195 = __ldxr(_X8);
                while ( __stxr(v195 + 1, _X8) );
                v196 = *(_QWORD *)(a1 + 18992);
                if ( (v196 & 1) != 0 )
                {
                  *(_QWORD *)(a1 + 18992) = v196 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(a1 + 18984);
                  if ( v78 == v29 )
                    goto LABEL_94;
                }
                else
                {
                  raw_spin_unlock(a1 + 18984);
                  if ( v78 == v29 )
                    goto LABEL_94;
                }
                qdf_trace_msg(
                  0x45u,
                  5u,
                  "%s: primary vdev [%d] %pK different from vdev [%d] %pK",
                  v84,
                  v85,
                  v86,
                  v87,
                  v88,
                  v89,
                  v90,
                  v91,
                  "dp_update_mlo_vdev_for_tdls",
                  *(unsigned __int8 *)(v78 + 59),
                  v78,
                  *(unsigned __int8 *)(v29 + 59),
                  v29);
                v92 = *(unsigned __int8 *)(v78 + 59);
                if ( v92 < 6 )
                {
                  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                    || (v93 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v93 + 16) & 0xF0000) != 0)
                    || (*(_DWORD *)(v93 + 16) & 0xFF00) != 0 )
                  {
                    raw_spin_lock(a1 + 18984);
                    v94 = *(_QWORD *)(v28 + 8 * v92);
                    if ( v94 )
                      goto LABEL_72;
                  }
                  else
                  {
                    raw_spin_lock_bh(a1 + 18984);
                    *(_QWORD *)(a1 + 18992) |= 1uLL;
                    v94 = *(_QWORD *)(v28 + 8 * v92);
                    if ( v94 )
                    {
LABEL_72:
                      v95 = *(_DWORD *)(v94 + 43384);
                      while ( v95 )
                      {
                        _X13 = (unsigned int *)(v94 + 43384);
                        __asm { PRFM            #0x11, [X13] }
                        while ( 1 )
                        {
                          v98 = __ldxr(_X13);
                          if ( v98 != v95 )
                            break;
                          if ( !__stlxr(v95 + 1, _X13) )
                          {
                            __dmb(0xBu);
                            break;
                          }
                        }
                        _ZF = v98 == v95;
                        v95 = v98;
                        if ( _ZF )
                        {
                          _X8 = (unsigned int *)(v94 + 43416);
                          __asm { PRFM            #0x11, [X8] }
                          do
                            v199 = __ldxr(_X8);
                          while ( __stxr(v199 + 1, _X8) );
                          qdf_spin_unlock_bh_7(a1 + 18984);
                          *(_BYTE *)(v94 + 328) = v18;
                          dp_tx_vdev_update_search_flags(v94);
                          v202[0] = v18;
                          *(_OWORD *)&v202[1] = __PAIR128__(*(unsigned __int64 *)v204, v203);
                          v99 = *(_DWORD **)(a1 + 1448);
                          *(_QWORD *)&v202[16] = *(_QWORD *)&v204[7];
                          if ( *(v99 - 1) != 608967745 )
                            __break(0x8228u);
                          v100 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _BYTE *))v99)(a1, v94, 6, v202);
                          dp_pdev_update_fast_rx_flag(
                            v101,
                            v102,
                            v103,
                            v104,
                            v105,
                            v106,
                            v107,
                            v108,
                            v100,
                            *(_QWORD *)(v94 + 24));
                          dp_vdev_unref_delete(a1, v94, 7u, v109, v110, v111, v112, v113, v114, v115, v116, v117);
                          goto LABEL_94;
                        }
                      }
                    }
                  }
                  v119 = *(_QWORD *)(a1 + 18992);
                  if ( (v119 & 1) != 0 )
                  {
                    *(_QWORD *)(a1 + 18992) = v119 & 0xFFFFFFFFFFFFFFFELL;
                    raw_spin_unlock_bh(a1 + 18984);
                  }
                  else
                  {
                    raw_spin_unlock(a1 + 18984);
                  }
                }
LABEL_94:
                dp_vdev_unref_delete(a1, v78, 0x15u, v83, v84, v85, v86, v87, v88, v89, v90, v91);
                goto LABEL_95;
              }
            }
            else
            {
              raw_spin_lock_bh(a1 + 18984);
              *(_QWORD *)(a1 + 18992) |= 1uLL;
              v78 = *(_QWORD *)(v28 + 8LL * v75);
              if ( v78 )
                goto LABEL_56;
            }
LABEL_88:
            v118 = *(_QWORD *)(a1 + 18992);
            if ( (v118 & 1) != 0 )
            {
              *(_QWORD *)(a1 + 18992) = v118 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(a1 + 18984);
            }
            else
            {
              raw_spin_unlock(a1 + 18984);
            }
          }
        }
        else
        {
          raw_spin_unlock(v29 + 144);
          if ( v75 <= 5 )
            goto LABEL_52;
        }
LABEL_95:
        dp_vdev_unref_delete(a1, v29, 0x15u, v66, v67, v68, v69, v70, v71, v72, v73, v74);
        goto LABEL_96;
      }
LABEL_41:
      v65 = *(_QWORD *)(a1 + 18992);
      if ( (v65 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 18992) = v65 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 18984);
      }
      else
      {
        raw_spin_unlock(a1 + 18984);
      }
    }
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: vdev is not as expected for TDLS",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "dp_update_mlo_vdev_for_tdls");
  }
LABEL_96:
  v120 = a4[1];
  v121 = a4[2];
  v200 = *a4;
  *(_QWORD *)&v201 = v120;
  *((_QWORD *)&v201 + 1) = v121;
  if ( a2 > 5u )
  {
    result = 16;
    goto LABEL_157;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v122 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v122 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v122 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 18984);
  }
  else
  {
    raw_spin_lock_bh(a1 + 18984);
    *(_QWORD *)(a1 + 18992) |= 1uLL;
  }
  v123 = *(_QWORD *)(a1 + 8LL * a2 + 12960);
  if ( !v123 )
  {
LABEL_115:
    v137 = *(_QWORD *)(a1 + 18992);
    if ( (v137 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18992) = v137 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18984);
    }
    else
    {
      raw_spin_unlock(a1 + 18984);
    }
    result = 16;
    goto LABEL_157;
  }
  v124 = (_BYTE *)(v123 + 43248);
  v125 = *(_DWORD *)(v123 + 43384);
  do
  {
    if ( !v125 )
      goto LABEL_115;
    _X12 = (unsigned int *)(v123 + 43384);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v128 = __ldxr(_X12);
      if ( v128 != v125 )
        break;
      if ( !__stlxr(v125 + 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v128 == v125;
    v125 = v128;
  }
  while ( !_ZF );
  _X8 = (unsigned int *)(v123 + 43416);
  __asm { PRFM            #0x11, [X8] }
  do
    v187 = __ldxr(_X8);
  while ( __stxr(v187 + 1, _X8) );
  v188 = *(_QWORD *)(a1 + 18992);
  if ( (v188 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 18984);
LABEL_113:
    switch ( a3 )
    {
      case 0u:
        *(_BYTE *)(v123 + 56) = v200;
        goto LABEL_154;
      case 1u:
        *(_BYTE *)(v123 + 57) = v200;
        goto LABEL_154;
      case 2u:
        qdf_trace_msg(
          0x89u,
          2u,
          "%s: %pK: wds_enable %d for vdev(%pK) id(%d)",
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          "dp_set_vdev_param",
          a1,
          (unsigned __int8)v200,
          v123,
          *(unsigned __int8 *)(v123 + 59));
        *(_BYTE *)(v123 + 48) = v200;
        goto LABEL_154;
      case 3u:
        qdf_trace_msg(
          0x89u,
          2u,
          "%s: %pK: mec_enable %d for vdev(%pK) id(%d)",
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          "dp_set_vdev_param",
          a1,
          (unsigned __int8)v200,
          v123,
          *(unsigned __int8 *)(v123 + 59));
        *(_BYTE *)(v123 + 49) = v200;
        goto LABEL_154;
      case 4u:
        qdf_trace_msg(
          0x89u,
          2u,
          "%s: %pK: da_war_enable %d for vdev(%pK) id(%d)",
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          "dp_set_vdev_param",
          a1,
          (unsigned __int8)v200,
          v123,
          *(unsigned __int8 *)(v123 + 59));
        *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v123 + 24) + 8LL) + 18706LL) = v200;
        dp_wds_flush_ast_table_wifi3(*(_QWORD *)(*(_QWORD *)(v123 + 24) + 8LL));
        goto LABEL_154;
      case 5u:
        *v124 = *v124 & 0xFE | v200;
        goto LABEL_154;
      case 6u:
        *(_BYTE *)(v123 + 328) = v200;
        goto LABEL_154;
      case 7u:
        if ( (_DWORD)v200 )
        {
          if ( (_DWORD)v200 != *(_DWORD *)(v123 + 52) )
            qdf_timer_mod_0(*(_QWORD *)(*(_QWORD *)(v123 + 24) + 8LL) + 17648LL, v200);
        }
        else
        {
          timer_delete((timer_t)(*(_QWORD *)(*(_QWORD *)(v123 + 24) + 8LL) + 17648LL));
        }
        *(_DWORD *)(v123 + 52) = v200;
        goto LABEL_154;
      case 8u:
        if ( *(_DWORD *)(v123 + 32) == 3 )
          *(_BYTE *)(v123 + 43264) = 0;
        else
          *(_BYTE *)(v123 + 43264) = v200;
        goto LABEL_154;
      case 9u:
        *(_DWORD *)(v123 + 43268) = v200;
        goto LABEL_154;
      case 0xAu:
        *v124 = *v124 & 0xFB | (4 * v200);
        goto LABEL_154;
      case 0xBu:
        v152 = "%s: vdev %d Multipass enable %d";
        v153 = "dp_set_vdev_param";
        v154 = a2;
        *(_BYTE *)(v123 + 80) = v200;
        goto LABEL_134;
      case 0xCu:
        *(_DWORD *)(v123 + 40) = v200;
        goto LABEL_154;
      case 0xDu:
        *(_DWORD *)(v123 + 44) = v200;
        goto LABEL_154;
      case 0xFu:
        *(_BYTE *)(v123 + 43282) = v200;
        goto LABEL_154;
      case 0x10u:
        *(_BYTE *)(v123 + 43273) = v200;
        goto LABEL_154;
      case 0x13u:
        *(_BYTE *)(v123 + 58) = v200;
        goto LABEL_154;
      case 0x14u:
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: vdev_id %d enable hlod tid override %d",
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          "dp_set_vdev_param",
          a2,
          (unsigned __int8)v200);
        qdf_trace_msg(
          0x89u,
          5u,
          "%s: %pK: val %d",
          v156,
          v157,
          v158,
          v159,
          v160,
          v161,
          v162,
          v163,
          "dp_vdev_set_hlos_tid_override",
          *(_QWORD *)(*(_QWORD *)(v123 + 24) + 8LL),
          (unsigned __int8)v200);
        *(_BYTE *)(v123 + 74) = *(_BYTE *)(v123 + 74) & 0xFD | (2 * ((_BYTE)v200 != 0));
        goto LABEL_154;
      case 0x15u:
        *(_BYTE *)(v123 + 75) = v200;
        goto LABEL_154;
      case 0x1Au:
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: vdev_id %d drop 3 addr mcast :%d",
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          "dp_set_vdev_param",
          a2,
          (unsigned __int8)v200);
        *(_BYTE *)(v123 + 50) = v200;
        goto LABEL_154;
      case 0x1Bu:
        *v124 = *v124 & 0xFD | (2 * v200);
        goto LABEL_154;
      case 0x1Cu:
        *(_BYTE *)(v123 + 46142) = v200;
        goto LABEL_154;
      case 0x1Du:
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: vdev_id %d to_fw :%d",
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          "dp_set_vdev_param",
          a2,
          (unsigned __int8)v200);
        *(_BYTE *)(v123 + 46168) = v200;
        goto LABEL_154;
      case 0x1Eu:
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: set mac addr, old mac addr%02x:%02x:%02x:**:**:%02x new mac addr: %02x:%02x:%02x:**:**:%02x for vdev %d",
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          "dp_set_vdev_param",
          *(unsigned __int8 *)(v123 + 96),
          *(unsigned __int8 *)(v123 + 97),
          *(unsigned __int8 *)(v123 + 98),
          *(unsigned __int8 *)(v123 + 101),
          (unsigned __int8)v200,
          BYTE1(v200),
          BYTE2(v200),
          BYTE5(v200),
          *(unsigned __int8 *)(v123 + 59));
        qdf_mem_copy((void *)(v123 + 96), &v200, 6u);
        goto LABEL_154;
      case 0x1Fu:
        v155 = *(_QWORD *)(v123 + 43520);
        if ( !v155 )
        {
          v183 = *(unsigned __int8 *)(v123 + 59);
          v184 = "dp_monitor_set_chan_num";
          goto LABEL_164;
        }
        v152 = "%s: vdev_id %d channel number: %d";
        v153 = "dp_monitor_set_chan_num";
        *(_DWORD *)(v155 + 8) = v200;
        v154 = *(unsigned __int8 *)(v123 + 59);
LABEL_134:
        qdf_trace_msg(0x45u, 5u, v152, v129, v130, v131, v132, v133, v134, v135, v136, v153, v154);
        goto LABEL_154;
      case 0x20u:
        v139 = v200;
        v140 = wlan_reg_freq_to_band(v200);
        v149 = *(_QWORD *)(v123 + 43520);
        v150 = v140;
        if ( v149 )
        {
          *(_DWORD *)(v149 + 12) = v200;
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: vdev_id %d freq: %d",
            v141,
            v142,
            v143,
            v144,
            v145,
            v146,
            v147,
            v148,
            "dp_monitor_set_chan_freq",
            *(unsigned __int8 *)(v123 + 59),
            v139);
          v151 = *(_QWORD *)(v123 + 43520);
          if ( v151 )
          {
LABEL_123:
            *(_DWORD *)(v151 + 16) = v150;
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: vdev_id %d ch band: %d",
              v129,
              v130,
              v131,
              v132,
              v133,
              v134,
              v135,
              v136,
              "dp_monitor_set_chan_band",
              *(unsigned __int8 *)(v123 + 59),
              v150);
            goto LABEL_154;
          }
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: mon vdev is null for vdev %u",
            v141,
            v142,
            v143,
            v144,
            v145,
            v146,
            v147,
            v148,
            "dp_monitor_set_chan_freq",
            *(unsigned __int8 *)(v123 + 59));
          v151 = *(_QWORD *)(v123 + 43520);
          if ( v151 )
            goto LABEL_123;
        }
        v183 = *(unsigned __int8 *)(v123 + 59);
        v184 = "dp_monitor_set_chan_band";
LABEL_164:
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: mon vdev is null for vdev %u",
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          v184,
          v183);
        goto LABEL_154;
      case 0x21u:
        qdf_trace_msg(
          0x89u,
          2u,
          "%s: %pK: eapol_over_control_port_disable %d for vdev(%pK) id(%d)",
          v129,
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          "dp_set_vdev_param",
          a1,
          (unsigned __int8)v200,
          v123,
          *(unsigned __int8 *)(v123 + 59));
        *(_BYTE *)(v123 + 46200) = v200;
        goto LABEL_154;
      default:
        goto LABEL_154;
    }
  }
  *(_QWORD *)(a1 + 18992) = v188 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 18984);
  if ( a3 <= 0x21 )
    goto LABEL_113;
LABEL_154:
  dp_tx_vdev_update_search_flags(v123);
  *(_QWORD *)v202 = v200;
  *(_OWORD *)&v202[8] = v201;
  v164 = *(_DWORD **)(a1 + 1448);
  if ( *(v164 - 1) != 608967745 )
    __break(0x8228u);
  v165 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _BYTE *))v164)(a1, v123, a3, v202);
  dp_pdev_update_fast_rx_flag(v166, v167, v168, v169, v170, v171, v172, v173, v165, *(_QWORD *)(v123 + 24));
  dp_vdev_unref_delete(a1, v123, 7u, v174, v175, v176, v177, v178, v179, v180, v181, v182);
  result = 0;
LABEL_157:
  _ReadStatusReg(SP_EL0);
  return result;
}
