__int64 __fastcall dp_tx_send_msdu_multiple(
        __int64 a1,
        __int64 a2,
        int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x9
  unsigned int v15; // w24
  const char *v16; // x2
  __int64 v17; // x4
  __int64 v18; // x8
  __int64 v19; // x22
  unsigned int v20; // w27
  __int64 v21; // x26
  __int64 v22; // x0
  __int64 v23; // x25
  __int64 v25; // x0
  int v26; // w1
  __int64 v27; // x2
  __int64 v28; // x21
  char v29; // w8
  __int64 v30; // x24
  __int64 v31; // x22
  __int16 v32; // w8
  __int64 *v33; // x23
  __int64 v34; // x9
  __int64 v35; // x10
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w8
  __int64 v45; // x8
  int v46; // w9
  int v47; // w9
  int v48; // w9
  int v49; // w9
  int v50; // w9
  int v51; // w9
  __int64 v52; // x27
  int v53; // w13
  int v54; // w9
  int v55; // w10
  int v56; // w9
  int *v57; // x28
  __int64 v58; // x24
  unsigned __int16 *v59; // x22
  __int64 v60; // x0
  int v61; // t1
  int v62; // w8
  int v64; // w8
  __int64 v65; // x9
  __int16 v66; // w8
  int v67; // w8
  __int64 v68; // x8
  unsigned int (*v69)(void); // x8
  __int64 v70; // x26
  __int64 v71; // x22
  int v72; // w9
  int v73; // w8
  __int64 v74; // x9
  __int64 v76; // x0
  __int64 v77; // x8
  unsigned __int64 v78; // x13
  __int64 v79; // x10
  __int64 v80; // x8
  __int64 v81; // x1
  __int64 v83; // x22
  __int64 v84; // x0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x8
  int v94; // w8
  __int64 v95; // x0
  __int64 v96; // x0
  __int64 *v97; // x8
  unsigned int v98; // w9
  __int64 result; // x0
  __int64 *v100; // x8
  unsigned int v101; // w8
  __int64 v102; // x0
  __int64 v104; // x8
  __int64 v105; // x0
  int v106; // w8
  __int64 v107; // x22
  __int64 v108; // x25
  int v109; // w8
  _QWORD *v110; // x23
  __int64 v111; // x25
  __int64 v112; // x22
  __int64 v113; // x21
  int v114; // w9
  __int64 v115; // x8
  __int64 *v116; // x8
  __int64 *v117; // x8
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  unsigned int v131; // w10
  unsigned int v133; // w9
  unsigned int v135; // w9
  char v136; // [xsp+Ch] [xbp-F4h]
  __int64 v137; // [xsp+10h] [xbp-F0h]
  __int64 v138; // [xsp+20h] [xbp-E0h]
  char v139; // [xsp+2Ch] [xbp-D4h]
  __int64 v140; // [xsp+30h] [xbp-D0h]
  __int64 v141; // [xsp+38h] [xbp-C8h]
  unsigned __int64 StatusReg; // [xsp+40h] [xbp-C0h]
  __int64 v143; // [xsp+48h] [xbp-B8h]
  __int64 *v144; // [xsp+50h] [xbp-B0h]
  unsigned int v145; // [xsp+5Ch] [xbp-A4h]
  __int64 v146; // [xsp+60h] [xbp-A0h] BYREF
  __int64 v147; // [xsp+68h] [xbp-98h] BYREF
  __int64 v148; // [xsp+70h] [xbp-90h]
  __int64 v149; // [xsp+78h] [xbp-88h]
  __int64 v150; // [xsp+80h] [xbp-80h] BYREF
  __int64 v151; // [xsp+88h] [xbp-78h]
  __int64 v152; // [xsp+90h] [xbp-70h]
  __int64 v153; // [xsp+98h] [xbp-68h]
  __int64 v154; // [xsp+A0h] [xbp-60h]
  __int64 v155; // [xsp+A8h] [xbp-58h]
  _QWORD v156[10]; // [xsp+B0h] [xbp-50h] BYREF

  v156[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *a3 == 4 )
    a2 = **((_QWORD **)a3 + 3);
  if ( !a3[2] )
  {
LABEL_145:
    result = 0;
    goto LABEL_152;
  }
  v14 = *(_QWORD *)(a1 + 24);
  v143 = a1 + 45056;
  v15 = 0;
  v138 = v14;
  v136 = 0;
  v139 = 0;
  v140 = *(_QWORD *)(v14 + 8) + 6752LL;
  v137 = v14 + 94208;
  v144 = *(__int64 **)(v14 + 8);
  v141 = v14 + 8016;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( *(unsigned __int16 *)(a2 + 180) == 34958
      || (v19 = *(_QWORD *)(a1 + 24),
          v20 = *((unsigned __int8 *)a3 + 4),
          v21 = *(_QWORD *)(v19 + 8),
          (v22 = dp_tx_desc_alloc(v21, *((unsigned __int8 *)a3 + 4), a2)) == 0) )
    {
      if ( a1 )
      {
        if ( *((_BYTE *)a3 + 94) )
          goto LABEL_153;
        ++*(_QWORD *)(a1 + 680);
      }
      goto LABEL_110;
    }
    v23 = v22;
    _X9 = (unsigned int *)(v19 + 93500);
    __asm { PRFM            #0x11, [X9] }
    do
      v131 = __ldxr(_X9);
    while ( __stxr(v131 + 1, _X9) );
    v25 = *(unsigned int *)(v19 + 93500);
    v26 = *(_DWORD *)(v19 + 93504);
    if ( v26 < (int)v25 )
    {
      v26 = *(_DWORD *)(v19 + 93500);
      *(_DWORD *)(v19 + 93504) = v25;
    }
    v145 = v15;
    qdf_mem_tx_desc_cnt_update(v25, v26);
    *(_QWORD *)(v23 + 8) = a2;
    v27 = *(unsigned int *)(v23 + 36);
    v28 = a2;
    *(_BYTE *)(v23 + 65) = *a3;
    *(_BYTE *)(v23 + 64) = *(_BYTE *)(v23 + 64) & 0xFC | *(_BYTE *)(a1 + 40) & 3;
    v29 = *(_BYTE *)(a1 + 59);
    *(_QWORD *)(v23 + 56) = v19;
    *(_BYTE *)(v23 + 66) = 0;
    *(_BYTE *)(v23 + 48) = v29;
    dp_tx_trace_pkt(v21, a2, v27, *(unsigned __int8 *)(a1 + 59), *(unsigned int *)(v143 + 292));
    memset(v156, 0, 64);
    v154 = 0;
    v155 = 0;
    v152 = 0;
    v153 = 0;
    v150 = 0;
    v151 = 0;
    v148 = 0;
    v149 = 0;
    v147 = 0;
    if ( v20 >= 6 )
LABEL_153:
      __break(0x5512u);
    v30 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 8LL);
    v31 = v30 + 136LL * v20;
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0
      && (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0
      && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      break;
    }
    raw_spin_lock(v31 + 4144);
    v32 = *(_WORD *)(v31 + 4040);
    if ( !v32 )
      goto LABEL_103;
LABEL_20:
    v33 = *(__int64 **)(v31 + 4136);
    v34 = *(_QWORD *)(v31 + 4152);
    v35 = *v33;
    *(_WORD *)(v31 + 4040) = v32 - 1;
    *(_QWORD *)(v31 + 4136) = v35;
    if ( (v34 & 1) != 0 )
    {
      *(_QWORD *)(v31 + 4152) = v34 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v31 + 4144);
    }
    else
    {
      raw_spin_unlock(v31 + 4144);
    }
    qdf_mem_set(&v147, 0x88u, 0);
    if ( !v33 )
      goto LABEL_106;
    if ( *((_BYTE *)a3 + 13) && *(_DWORD *)(a1 + 64) )
    {
      qdf_mem_copy(v156, a3 + 14, 0x24u);
      _X8 = (unsigned int *)(v30 + 18700);
      __asm { PRFM            #0x11, [X8] }
      do
        v135 = __ldxr(_X8);
      while ( __stxr(v135 + 1, _X8) );
      *((_WORD *)v33 + 12) |= 1u;
    }
    v44 = *a3;
    if ( (unsigned int)(*a3 - 4) < 2 )
    {
LABEL_28:
      v45 = *((_QWORD *)a3 + 3);
      if ( *(_WORD *)(v45 + 8) )
      {
        v46 = *(unsigned __int8 *)(v45 + 28) | (*(unsigned __int16 *)(v45 + 30) << 16) | HIDWORD(v150);
        LODWORD(v150) = v150 | *(_DWORD *)(v45 + 24);
        HIDWORD(v150) = v46;
        if ( *(unsigned __int16 *)(v45 + 8) >= 2u )
        {
          v47 = *(unsigned __int8 *)(v45 + 44) | (*(unsigned __int16 *)(v45 + 46) << 16) | HIDWORD(v151);
          LODWORD(v151) = v151 | *(_DWORD *)(v45 + 40);
          HIDWORD(v151) = v47;
          if ( *(unsigned __int16 *)(v45 + 8) >= 3u )
          {
            v48 = *(unsigned __int8 *)(v45 + 60) | (*(unsigned __int16 *)(v45 + 62) << 16) | HIDWORD(v152);
            LODWORD(v152) = v152 | *(_DWORD *)(v45 + 56);
            HIDWORD(v152) = v48;
            if ( *(unsigned __int16 *)(v45 + 8) >= 4u )
            {
              v49 = *(unsigned __int8 *)(v45 + 76) | (*(unsigned __int16 *)(v45 + 78) << 16) | HIDWORD(v153);
              LODWORD(v153) = v153 | *(_DWORD *)(v45 + 72);
              HIDWORD(v153) = v49;
              if ( *(unsigned __int16 *)(v45 + 8) >= 5u )
              {
                v50 = *(unsigned __int8 *)(v45 + 92) | (*(unsigned __int16 *)(v45 + 94) << 16) | HIDWORD(v154);
                LODWORD(v154) = v154 | *(_DWORD *)(v45 + 88);
                HIDWORD(v154) = v50;
                if ( *(unsigned __int16 *)(v45 + 8) >= 6u )
                {
                  v51 = *(unsigned __int8 *)(v45 + 108) | (*(unsigned __int16 *)(v45 + 110) << 16) | HIDWORD(v155);
                  LODWORD(v155) = v155 | *(_DWORD *)(v45 + 104);
                  HIDWORD(v155) = v51;
                  if ( *(unsigned __int16 *)(v45 + 8) > 6u )
                    goto LABEL_153;
                }
              }
            }
          }
        }
      }
      goto LABEL_45;
    }
    if ( v44 == 1 )
    {
      v52 = *((_QWORD *)a3 + 4);
      v53 = *(_DWORD *)(v52 + 16);
      v54 = HIDWORD(v147) | *(_DWORD *)(v52 + 12);
      v55 = *(unsigned __int16 *)(v52 + 20);
      LODWORD(v147) = *(_DWORD *)(v52 + 8);
      HIDWORD(v147) = v54;
      v56 = *(_DWORD *)(v52 + 32);
      LODWORD(v148) = v148 | v53;
      HIDWORD(v148) |= v55;
      if ( v56 )
      {
        v57 = (int *)&v150 + 1;
        v58 = 0;
        v59 = (unsigned __int16 *)(v52 + 40);
        while ( 1 )
        {
          v146 = 0;
          if ( v58 == 6 )
            goto LABEL_153;
          v60 = *((_QWORD *)v59 + 2);
          if ( !v60 || !*v59 )
            break;
          _qdf_dmaaddr_to_32s(v60, (_DWORD *)&v146 + 1, &v146);
          v61 = *v59;
          v59 += 12;
          ++v58;
          v62 = (unsigned __int8)v146 | (v61 << 16) | *v57;
          *(v57 - 1) |= HIDWORD(v146);
          *v57 = v62;
          v57 += 2;
          if ( *(_DWORD *)(v52 + 32) <= (unsigned int)v58 )
            goto LABEL_45;
        }
        v102 = printk(
                 &unk_9BB309,
                 "expr",
                 "__dp_assert_always_internal",
                 "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
        dump_stack(v102);
      }
    }
    else if ( v44 == 2 )
    {
      goto LABEL_28;
    }
LABEL_45:
    ((void (__fastcall *)(__int64, __int64, __int64 *, __int64))qdf_trace_hex_dump)(69, 8, &v147, 136);
    qdf_mem_copy((void *)v33[1], &v147, 0x88u);
    a2 = v28;
    if ( *((_BYTE *)a3 + 13) || (*(_WORD *)(v28 + 69) & 0x800) != 0 )
    {
      *(_DWORD *)(v23 + 32) |= 2u;
      _X8 = (unsigned int *)(v21 + 18700);
      __asm { PRFM            #0x11, [X8] }
      do
        v133 = __ldxr(_X8);
      while ( __stxr(v133 + 1, _X8) );
    }
    v64 = *(_DWORD *)(v23 + 32);
    *(_QWORD *)(v23 + 72) = v33;
    *(_DWORD *)(v23 + 32) = v64 | 1;
    v65 = v33[2];
    v33[5] = *((_QWORD *)a3 + 4);
    v33[6] = *((_QWORD *)a3 + 5);
    *(_QWORD *)(v23 + 40) = v65;
    if ( (v33[3] & 1) != 0 )
      v66 = 136;
    else
      v66 = 72;
    *(_WORD *)(v23 + 16) = v66;
    v67 = *a3;
    if ( *a3 == 4 )
    {
      *(_QWORD *)(*(_QWORD *)(v23 + 72) + 32LL) = *(_QWORD *)(*((_QWORD *)a3 + 3) + 16LL);
      *(_DWORD *)(v23 + 32) |= 0x80u;
      v67 = *a3;
    }
    v15 = v145 + 1;
    *((_BYTE *)a3 + 95) = v145 + 1 < a3[2];
    if ( v67 == 1 )
    {
      v68 = **((_QWORD **)a3 + 4);
      if ( v68 )
      {
        *((_QWORD *)a3 + 4) = v68;
        _qdf_nbuf_inc_users(v28);
      }
    }
    v69 = (unsigned int (*)(void))v144[162];
    if ( *((_DWORD *)v69 - 1) != -1196775241 )
      __break(0x8228u);
    if ( v69() )
    {
      if ( !*((_BYTE *)a3 + 95) )
      {
        v70 = *(_QWORD *)(v140 + 80LL * (*((_BYTE *)a3 + 5) & 3));
        if ( v70 )
        {
          v71 = v144[141];
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v70 + 80);
          }
          else
          {
            raw_spin_lock_bh(v70 + 80);
            *(_QWORD *)(v70 + 88) |= 1uLL;
          }
          v72 = *(_DWORD *)(v70 + 116);
          v73 = **(_DWORD **)(v70 + 128);
          *(_DWORD *)(v70 + 136) = v73;
          if ( v72 )
          {
            if ( (*(_BYTE *)(v70 + 78) & 4) != 0 )
            {
              v74 = *(unsigned int *)(v70 + 120);
              if ( (_DWORD)v74 != v73 )
              {
                _X23 = *(_QWORD *)(v70 + 16) + 4 * v74;
                if ( _X23 )
                {
                  v76 = *(_QWORD *)(*(_QWORD *)(v71 + 8) + 40LL);
                  if ( (*(_BYTE *)(v76 + 844) & 0x40) == 0 )
                  {
                    v77 = _X23 << 8 >> 8;
                    v78 = (unsigned __int64)(v77 + 0x8000000000LL) >> 38;
                    v79 = memstart_addr + v77 + 0x8000000000LL;
                    v80 = v77 - kimage_voffset;
                    if ( v78 )
                      v81 = v80;
                    else
                      v81 = v79;
                    _dma_sync_single_for_cpu(v76, v81);
                  }
                  __asm { PRFM            #0, [X23] }
                }
              }
            }
          }
          dp_tx_ring_access_end_wrapper((__int64)v144, v70, 0);
        }
        else
        {
          qdf_trace_msg(
            0x38u,
            2u,
            "%s: Error: Invalid hal_ring\n",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "hal_srng_access_start");
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Fillmore: SRNG access start failed",
            v118,
            v119,
            v120,
            v121,
            v122,
            v123,
            v124,
            v125,
            "dp_flush_tcp_hp");
        }
      }
      v83 = jiffies;
      if ( dp_tx_send_msdu_multiple___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Tx_hw_enqueue Fail tx_desc %pK queue %d",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "dp_tx_send_msdu_multiple",
          v23,
          *((unsigned __int8 *)a3 + 5));
        dp_tx_send_msdu_multiple___last_ticks = v83;
      }
      v84 = ((__int64 (__fastcall *)(__int64, __int64, int *))dp_tx_get_tid)(a1, v28, a3);
      if ( *((unsigned __int8 *)a3 + 5) > 4uLL || *((unsigned __int8 *)a3 + 12) > 9uLL )
        goto LABEL_153;
      v93 = v141 + 6768LL * *((unsigned __int8 *)a3 + 5) + 752LL * *((unsigned __int8 *)a3 + 12);
      ++*(_QWORD *)(v93 + 560);
      v94 = *a3;
      if ( *a3 == 1 )
      {
        if ( !*((_QWORD *)a3 + 4) )
          goto LABEL_150;
        v95 = dp_tx_comp_free_buf((__int64)v144, v23, 0, v85, v86, v87, v88, v89, v90, v91, v92);
        dp_tx_desc_release(v95, v23, *((unsigned __int8 *)a3 + 4));
LABEL_9:
        if ( v15 >= a3[2] )
          goto LABEL_145;
      }
      else
      {
        if ( v94 == 2 )
        {
          v84 = ((__int64 (__fastcall *)(__int64 *, __int64, int *))dp_tx_sg_unmap_buf)(v144, v28, a3);
LABEL_150:
          dp_tx_desc_release(v84, v23, *((unsigned __int8 *)a3 + 4));
          goto LABEL_151;
        }
        if ( v94 != 4 )
          goto LABEL_150;
        if ( a3[2] == (unsigned __int8)(v136 + 1) )
          _qdf_nbuf_unmap(v144[3], **((_QWORD **)a3 + 3), 1);
        v96 = **((_QWORD **)a3 + 3);
        if ( v96 )
          v96 = _qdf_nbuf_free(v96);
        dp_tx_desc_release(v96, v23, *((unsigned __int8 *)a3 + 4));
        v97 = *(__int64 **)(*((_QWORD *)a3 + 3) + 112LL);
        if ( !v97 )
          goto LABEL_145;
        v98 = a3[2];
        *((_QWORD *)a3 + 3) = v97;
        a2 = *v97;
        ++v136;
        result = 0;
        if ( v15 >= v98 )
          goto LABEL_152;
      }
    }
    else
    {
      if ( *(_DWORD *)(v143 + 296) )
      {
        *(_QWORD *)(v23 + 96) = *((_QWORD *)a3 + 12);
        *(_QWORD *)(v23 + 88) = ktime_get_with_offset(0);
      }
      if ( *a3 == 4 || *a3 == 2 )
      {
        v100 = *(__int64 **)(*((_QWORD *)a3 + 3) + 112LL);
        if ( !v100 )
          goto LABEL_145;
        *((_QWORD *)a3 + 3) = v100;
        a2 = *v100;
      }
      v101 = a3[2];
LABEL_131:
      result = 0;
      if ( v15 >= v101 )
        goto LABEL_152;
    }
  }
  raw_spin_lock_bh(v31 + 4144);
  *(_QWORD *)(v31 + 4152) |= 1uLL;
  v32 = *(_WORD *)(v31 + 4040);
  if ( v32 )
    goto LABEL_20;
LABEL_103:
  v104 = *(_QWORD *)(v31 + 4152);
  if ( (v104 & 1) != 0 )
  {
    *(_QWORD *)(v31 + 4152) = v104 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v31 + 4144);
  }
  else
  {
    raw_spin_unlock(v31 + 4144);
  }
  qdf_mem_set(&v147, 0x88u, 0);
LABEL_106:
  if ( a1 )
  {
    if ( *((_BYTE *)a3 + 94) )
      goto LABEL_153;
    ++*(_QWORD *)(a1 + 680);
  }
  v105 = qdf_trace_msg(
           0x7Du,
           5u,
           "%s: Tx Extension Descriptor Alloc Fail",
           v36,
           v37,
           v38,
           v39,
           v40,
           v41,
           v42,
           v43,
           "dp_tx_prepare_desc");
  dp_tx_desc_release(v105, v23, v20);
  v15 = v145;
LABEL_110:
  v106 = *a3;
  if ( *a3 != 1 )
  {
    if ( v106 != 4 )
      goto LABEL_147;
    v110 = *(_QWORD **)(*((_QWORD *)a3 + 3) + 16LL);
    v111 = v110[2];
    if ( v111 )
    {
      v112 = *(_QWORD *)(*(_QWORD *)(v138 + 8) + 24LL);
      qdf_mem_dp_tx_skb_cnt_dec();
      qdf_mem_dp_tx_skb_dec(6);
      qdf_mem_skb_total_dec(6);
      dma_unmap_page_attrs(*(_QWORD *)(v112 + 40), v111, 6, 1, 0);
      v110[2] = 0;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v113 = v138;
      raw_spin_lock(v138 + 352);
    }
    else
    {
      v113 = v138;
      raw_spin_lock_bh(v138 + 352);
      *(_QWORD *)(v138 + 360) |= 1uLL;
    }
    *v110 = *(_QWORD *)(v137 + 784);
    v114 = *(_DWORD *)(v137 + 792);
    v115 = *(_QWORD *)(v113 + 360);
    *(_QWORD *)(v137 + 784) = v110;
    *(_DWORD *)(v137 + 792) = v114 - 1;
    if ( (v115 & 1) != 0 )
    {
      *(_QWORD *)(v113 + 360) = v115 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v113 + 352);
    }
    else
    {
      raw_spin_unlock(v113 + 352);
    }
    if ( a3[2] == (unsigned __int8)(v139 + 1) )
      _qdf_nbuf_unmap(v144[3], **((_QWORD **)a3 + 3), 1);
    v116 = *((__int64 **)a3 + 3);
    if ( *v116 )
    {
      _qdf_nbuf_free(*v116);
      v116 = *((__int64 **)a3 + 3);
    }
    v117 = (__int64 *)v116[14];
    ++v139;
    if ( v117 )
    {
      *((_QWORD *)a3 + 3) = v117;
      a2 = *v117;
    }
    v101 = a3[2];
    ++v15;
    goto LABEL_131;
  }
  v108 = *((_QWORD *)a3 + 4);
  v107 = *((_QWORD *)a3 + 5);
  qdf_trace_msg(0x45u, 0, "%s: Unmap the tso segment", a4, a5, a6, a7, a8, a9, a10, a11, "dp_tx_tso_unmap_segment");
  if ( !v108 )
  {
    v16 = "%s %d TSO desc is NULL!";
    v17 = 468;
LABEL_6:
    qdf_trace_msg(0x45u, 2u, v16, a4, a5, a6, a7, a8, a9, a10, a11, "dp_tx_tso_unmap_segment", v17);
    goto LABEL_7;
  }
  if ( !v107 )
  {
    v16 = "%s %d TSO num desc is NULL!";
    v17 = 472;
    goto LABEL_6;
  }
  v109 = *(_DWORD *)(v107 + 8);
  if ( v109 )
  {
    _qdf_nbuf_unmap_tso_segment(v144[3], v108, v109 == 1);
    --*(_DWORD *)(v107 + 8);
  }
LABEL_7:
  v18 = **((_QWORD **)a3 + 4);
  if ( v18 )
  {
    ++v15;
    *((_QWORD *)a3 + 4) = v18;
    goto LABEL_9;
  }
  v106 = *a3;
LABEL_147:
  if ( v106 == 2 )
    ((void (__fastcall *)(__int64 *, __int64, int *))dp_tx_sg_unmap_buf)(v144, a2, a3);
LABEL_151:
  result = a2;
LABEL_152:
  _ReadStatusReg(SP_EL0);
  return result;
}
