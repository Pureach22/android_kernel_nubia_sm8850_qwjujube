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
  __int64 v24; // x0
  int v25; // w1
  __int64 v26; // x2
  __int64 v27; // x21
  char v28; // w8
  __int64 v29; // x24
  __int64 v30; // x22
  __int16 v31; // w8
  __int64 *v32; // x23
  __int64 v33; // x9
  __int64 v34; // x10
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w8
  __int64 v44; // x8
  int v45; // w9
  int v46; // w9
  int v47; // w9
  int v48; // w9
  int v49; // w9
  int v50; // w9
  __int64 v51; // x27
  int v52; // w13
  int v53; // w9
  int v54; // w10
  int v55; // w9
  int *v56; // x28
  __int64 v57; // x24
  unsigned __int16 *v58; // x22
  __int64 v59; // x0
  int v60; // t1
  int v61; // w8
  int v63; // w8
  __int64 v64; // x9
  __int16 v65; // w8
  int v66; // w8
  __int64 v67; // x8
  unsigned int (*v68)(void); // x8
  __int64 v69; // x26
  __int64 v70; // x22
  int v71; // w9
  int v72; // w8
  __int64 v73; // x9
  __int64 v75; // x0
  __int64 v76; // x8
  unsigned __int64 v77; // x13
  __int64 v78; // x10
  __int64 v79; // x8
  __int64 v80; // x1
  __int64 v82; // x22
  __int64 v83; // x0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 v92; // x8
  int v93; // w8
  __int64 v94; // x0
  __int64 v95; // x0
  __int64 *v96; // x8
  unsigned int v97; // w9
  __int64 result; // x0
  __int64 *v99; // x8
  unsigned int v100; // w8
  __int64 v101; // x0
  __int64 v103; // x8
  __int64 v104; // x0
  int v105; // w8
  __int64 v106; // x22
  __int64 v107; // x25
  int v108; // w8
  _QWORD *v109; // x23
  __int64 v110; // x25
  __int64 v111; // x22
  __int64 v112; // x21
  int v113; // w9
  __int64 v114; // x8
  __int64 *v115; // x8
  __int64 *v116; // x8
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
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
  v140 = *(_QWORD *)(v14 + 8) + 6800LL;
  v137 = v14 + 94208;
  v144 = *(__int64 **)(v14 + 8);
  v141 = v14 + 8840;
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
        ++*(_QWORD *)(a1 + 688);
      }
      goto LABEL_110;
    }
    v23 = v22;
    _X9 = (unsigned int *)(v19 + 94396);
    __asm { PRFM            #0x11, [X9] }
    do
      v131 = __ldxr(_X9);
    while ( __stxr(v131 + 1, _X9) );
    v24 = *(unsigned int *)(v19 + 94396);
    v25 = *(_DWORD *)(v19 + 94400);
    if ( v25 < (int)v24 )
    {
      v25 = *(_DWORD *)(v19 + 94396);
      *(_DWORD *)(v19 + 94400) = v24;
    }
    v145 = v15;
    qdf_mem_tx_desc_cnt_update(v24, v25);
    *(_QWORD *)(v23 + 8) = a2;
    v26 = *(unsigned int *)(v23 + 36);
    v27 = a2;
    *(_BYTE *)(v23 + 65) = *a3;
    *(_BYTE *)(v23 + 64) = *(_BYTE *)(v23 + 64) & 0xFC | *(_BYTE *)(a1 + 40) & 3;
    v28 = *(_BYTE *)(a1 + 59);
    *(_QWORD *)(v23 + 56) = v19;
    *(_BYTE *)(v23 + 66) = 0;
    *(_BYTE *)(v23 + 48) = v28;
    dp_tx_trace_pkt(v21, a2, v26, *(unsigned __int8 *)(a1 + 59), *(unsigned int *)(v143 + 1116));
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
    v29 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 8LL);
    v30 = v29 + 136LL * v20;
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0
      && (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0
      && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      break;
    }
    raw_spin_lock(v30 + 4192);
    v31 = *(_WORD *)(v30 + 4088);
    if ( !v31 )
      goto LABEL_103;
LABEL_20:
    v32 = *(__int64 **)(v30 + 4184);
    v33 = *(_QWORD *)(v30 + 4200);
    v34 = *v32;
    *(_WORD *)(v30 + 4088) = v31 - 1;
    *(_QWORD *)(v30 + 4184) = v34;
    if ( (v33 & 1) != 0 )
    {
      *(_QWORD *)(v30 + 4200) = v33 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v30 + 4192);
    }
    else
    {
      raw_spin_unlock(v30 + 4192);
    }
    qdf_mem_set(&v147, 0x88u, 0);
    if ( !v32 )
      goto LABEL_106;
    if ( *((_BYTE *)a3 + 13) && *(_DWORD *)(a1 + 64) )
    {
      qdf_mem_copy(v156, a3 + 14, 0x24u);
      _X8 = (unsigned int *)(v29 + 18756);
      __asm { PRFM            #0x11, [X8] }
      do
        v135 = __ldxr(_X8);
      while ( __stxr(v135 + 1, _X8) );
      *((_WORD *)v32 + 12) |= 1u;
    }
    v43 = *a3;
    if ( (unsigned int)(*a3 - 4) < 2 )
    {
LABEL_28:
      v44 = *((_QWORD *)a3 + 3);
      if ( *(_WORD *)(v44 + 8) )
      {
        v45 = *(unsigned __int8 *)(v44 + 28) | (*(unsigned __int16 *)(v44 + 30) << 16) | HIDWORD(v150);
        LODWORD(v150) = v150 | *(_DWORD *)(v44 + 24);
        HIDWORD(v150) = v45;
        if ( *(unsigned __int16 *)(v44 + 8) >= 2u )
        {
          v46 = *(unsigned __int8 *)(v44 + 44) | (*(unsigned __int16 *)(v44 + 46) << 16) | HIDWORD(v151);
          LODWORD(v151) = v151 | *(_DWORD *)(v44 + 40);
          HIDWORD(v151) = v46;
          if ( *(unsigned __int16 *)(v44 + 8) >= 3u )
          {
            v47 = *(unsigned __int8 *)(v44 + 60) | (*(unsigned __int16 *)(v44 + 62) << 16) | HIDWORD(v152);
            LODWORD(v152) = v152 | *(_DWORD *)(v44 + 56);
            HIDWORD(v152) = v47;
            if ( *(unsigned __int16 *)(v44 + 8) >= 4u )
            {
              v48 = *(unsigned __int8 *)(v44 + 76) | (*(unsigned __int16 *)(v44 + 78) << 16) | HIDWORD(v153);
              LODWORD(v153) = v153 | *(_DWORD *)(v44 + 72);
              HIDWORD(v153) = v48;
              if ( *(unsigned __int16 *)(v44 + 8) >= 5u )
              {
                v49 = *(unsigned __int8 *)(v44 + 92) | (*(unsigned __int16 *)(v44 + 94) << 16) | HIDWORD(v154);
                LODWORD(v154) = v154 | *(_DWORD *)(v44 + 88);
                HIDWORD(v154) = v49;
                if ( *(unsigned __int16 *)(v44 + 8) >= 6u )
                {
                  v50 = *(unsigned __int8 *)(v44 + 108) | (*(unsigned __int16 *)(v44 + 110) << 16) | HIDWORD(v155);
                  LODWORD(v155) = v155 | *(_DWORD *)(v44 + 104);
                  HIDWORD(v155) = v50;
                  if ( *(unsigned __int16 *)(v44 + 8) > 6u )
                    goto LABEL_153;
                }
              }
            }
          }
        }
      }
      goto LABEL_45;
    }
    if ( v43 == 1 )
    {
      v51 = *((_QWORD *)a3 + 4);
      v52 = *(_DWORD *)(v51 + 16);
      v53 = HIDWORD(v147) | *(_DWORD *)(v51 + 12);
      v54 = *(unsigned __int16 *)(v51 + 20);
      LODWORD(v147) = *(_DWORD *)(v51 + 8);
      HIDWORD(v147) = v53;
      v55 = *(_DWORD *)(v51 + 32);
      LODWORD(v148) = v148 | v52;
      HIDWORD(v148) |= v54;
      if ( v55 )
      {
        v56 = (int *)&v150 + 1;
        v57 = 0;
        v58 = (unsigned __int16 *)(v51 + 40);
        while ( 1 )
        {
          v146 = 0;
          if ( v57 == 6 )
            goto LABEL_153;
          v59 = *((_QWORD *)v58 + 2);
          if ( !v59 || !*v58 )
            break;
          _qdf_dmaaddr_to_32s(v59, (_DWORD *)&v146 + 1, &v146);
          v60 = *v58;
          v58 += 12;
          ++v57;
          v61 = (unsigned __int8)v146 | (v60 << 16) | *v56;
          *(v56 - 1) |= HIDWORD(v146);
          *v56 = v61;
          v56 += 2;
          if ( *(_DWORD *)(v51 + 32) <= (unsigned int)v57 )
            goto LABEL_45;
        }
        v101 = printk(
                 &unk_AAA255,
                 "expr",
                 "__dp_assert_always_internal",
                 "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
        dump_stack(v101);
      }
    }
    else if ( v43 == 2 )
    {
      goto LABEL_28;
    }
LABEL_45:
    ((void (__fastcall *)(__int64, __int64, __int64 *, __int64))qdf_trace_hex_dump)(69, 8, &v147, 136);
    qdf_mem_copy((void *)v32[1], &v147, 0x88u);
    a2 = v27;
    if ( *((_BYTE *)a3 + 13) || (*(_WORD *)(v27 + 69) & 0x800) != 0 )
    {
      *(_DWORD *)(v23 + 32) |= 2u;
      _X8 = (unsigned int *)(v21 + 18756);
      __asm { PRFM            #0x11, [X8] }
      do
        v133 = __ldxr(_X8);
      while ( __stxr(v133 + 1, _X8) );
    }
    v63 = *(_DWORD *)(v23 + 32);
    *(_QWORD *)(v23 + 72) = v32;
    *(_DWORD *)(v23 + 32) = v63 | 1;
    v64 = v32[2];
    v32[5] = *((_QWORD *)a3 + 4);
    v32[6] = *((_QWORD *)a3 + 5);
    *(_QWORD *)(v23 + 40) = v64;
    if ( (v32[3] & 1) != 0 )
      v65 = 136;
    else
      v65 = 72;
    *(_WORD *)(v23 + 16) = v65;
    v66 = *a3;
    if ( *a3 == 4 )
    {
      *(_QWORD *)(*(_QWORD *)(v23 + 72) + 32LL) = *(_QWORD *)(*((_QWORD *)a3 + 3) + 16LL);
      *(_DWORD *)(v23 + 32) |= 0x80u;
      v66 = *a3;
    }
    v15 = v145 + 1;
    *((_BYTE *)a3 + 95) = v145 + 1 < a3[2];
    if ( v66 == 1 )
    {
      v67 = **((_QWORD **)a3 + 4);
      if ( v67 )
      {
        *((_QWORD *)a3 + 4) = v67;
        _qdf_nbuf_inc_users(v27);
      }
    }
    v68 = (unsigned int (*)(void))v144[162];
    if ( *((_DWORD *)v68 - 1) != -1196775241 )
      __break(0x8228u);
    if ( v68() )
    {
      if ( !*((_BYTE *)a3 + 95) )
      {
        v69 = *(_QWORD *)(v140 + 80LL * (*((_BYTE *)a3 + 5) & 3));
        if ( v69 )
        {
          v70 = v144[141];
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v69 + 80);
          }
          else
          {
            raw_spin_lock_bh(v69 + 80);
            *(_QWORD *)(v69 + 88) |= 1uLL;
          }
          v71 = *(_DWORD *)(v69 + 116);
          v72 = **(_DWORD **)(v69 + 128);
          *(_DWORD *)(v69 + 136) = v72;
          if ( v71 )
          {
            if ( (*(_BYTE *)(v69 + 78) & 4) != 0 )
            {
              v73 = *(unsigned int *)(v69 + 120);
              if ( (_DWORD)v73 != v72 )
              {
                _X23 = *(_QWORD *)(v69 + 16) + 4 * v73;
                if ( _X23 )
                {
                  v75 = *(_QWORD *)(*(_QWORD *)(v70 + 8) + 40LL);
                  if ( (*(_BYTE *)(v75 + 844) & 0x40) == 0 )
                  {
                    v76 = _X23 << 8 >> 8;
                    v77 = (unsigned __int64)(v76 + 0x8000000000LL) >> 38;
                    v78 = memstart_addr + v76 + 0x8000000000LL;
                    v79 = v76 - kimage_voffset;
                    if ( v77 )
                      v80 = v79;
                    else
                      v80 = v78;
                    _dma_sync_single_for_cpu(v75, v80);
                  }
                  __asm { PRFM            #0, [X23] }
                }
              }
            }
          }
          dp_tx_ring_access_end_wrapper((__int64)v144, v69, 0);
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
            v117,
            v118,
            v119,
            v120,
            v121,
            v122,
            v123,
            v124,
            "dp_flush_tcp_hp");
        }
      }
      v82 = jiffies;
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
        dp_tx_send_msdu_multiple___last_ticks = v82;
      }
      v83 = ((__int64 (__fastcall *)(__int64, __int64, int *))dp_tx_get_tid)(a1, v27, a3);
      if ( *((unsigned __int8 *)a3 + 5) > 4uLL || *((unsigned __int8 *)a3 + 12) > 9uLL )
        goto LABEL_153;
      v92 = v141 + 6768LL * *((unsigned __int8 *)a3 + 5) + 752LL * *((unsigned __int8 *)a3 + 12);
      ++*(_QWORD *)(v92 + 560);
      v93 = *a3;
      if ( *a3 == 1 )
      {
        if ( !*((_QWORD *)a3 + 4) )
          goto LABEL_150;
        v94 = dp_tx_comp_free_buf((__int64)v144, v23, 0, v84, v85, v86, v87, v88, v89, v90, v91);
        dp_tx_desc_release(v94, v23, *((unsigned __int8 *)a3 + 4));
LABEL_9:
        if ( v15 >= a3[2] )
          goto LABEL_145;
      }
      else
      {
        if ( v93 == 2 )
        {
          v83 = ((__int64 (__fastcall *)(__int64 *, __int64, int *))dp_tx_sg_unmap_buf)(v144, v27, a3);
LABEL_150:
          dp_tx_desc_release(v83, v23, *((unsigned __int8 *)a3 + 4));
          goto LABEL_151;
        }
        if ( v93 != 4 )
          goto LABEL_150;
        if ( a3[2] == (unsigned __int8)(v136 + 1) )
          _qdf_nbuf_unmap(v144[3], **((_QWORD **)a3 + 3), 1);
        v95 = **((_QWORD **)a3 + 3);
        if ( v95 )
          v95 = _qdf_nbuf_free(v95);
        dp_tx_desc_release(v95, v23, *((unsigned __int8 *)a3 + 4));
        v96 = *(__int64 **)(*((_QWORD *)a3 + 3) + 112LL);
        if ( !v96 )
          goto LABEL_145;
        v97 = a3[2];
        *((_QWORD *)a3 + 3) = v96;
        a2 = *v96;
        ++v136;
        result = 0;
        if ( v15 >= v97 )
          goto LABEL_152;
      }
    }
    else
    {
      if ( *(_DWORD *)(v143 + 1120) )
      {
        *(_QWORD *)(v23 + 96) = *((_QWORD *)a3 + 12);
        *(_QWORD *)(v23 + 88) = ktime_get_with_offset(0);
      }
      if ( *a3 == 4 || *a3 == 2 )
      {
        v99 = *(__int64 **)(*((_QWORD *)a3 + 3) + 112LL);
        if ( !v99 )
          goto LABEL_145;
        *((_QWORD *)a3 + 3) = v99;
        a2 = *v99;
      }
      v100 = a3[2];
LABEL_131:
      result = 0;
      if ( v15 >= v100 )
        goto LABEL_152;
    }
  }
  raw_spin_lock_bh(v30 + 4192);
  *(_QWORD *)(v30 + 4200) |= 1uLL;
  v31 = *(_WORD *)(v30 + 4088);
  if ( v31 )
    goto LABEL_20;
LABEL_103:
  v103 = *(_QWORD *)(v30 + 4200);
  if ( (v103 & 1) != 0 )
  {
    *(_QWORD *)(v30 + 4200) = v103 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v30 + 4192);
  }
  else
  {
    raw_spin_unlock(v30 + 4192);
  }
  qdf_mem_set(&v147, 0x88u, 0);
LABEL_106:
  if ( a1 )
  {
    if ( *((_BYTE *)a3 + 94) )
      goto LABEL_153;
    ++*(_QWORD *)(a1 + 688);
  }
  v104 = qdf_trace_msg(
           0x7Du,
           5u,
           "%s: Tx Extension Descriptor Alloc Fail",
           v35,
           v36,
           v37,
           v38,
           v39,
           v40,
           v41,
           v42,
           "dp_tx_prepare_desc");
  dp_tx_desc_release(v104, v23, v20);
  v15 = v145;
LABEL_110:
  v105 = *a3;
  if ( *a3 != 1 )
  {
    if ( v105 != 4 )
      goto LABEL_147;
    v109 = *(_QWORD **)(*((_QWORD *)a3 + 3) + 16LL);
    v110 = v109[2];
    if ( v110 )
    {
      v111 = *(_QWORD *)(*(_QWORD *)(v138 + 8) + 24LL);
      qdf_mem_dp_tx_skb_cnt_dec();
      qdf_mem_dp_tx_skb_dec(6);
      qdf_mem_skb_total_dec(6);
      dma_unmap_page_attrs(*(_QWORD *)(v111 + 40), v110, 6, 1, 0);
      v109[2] = 0;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v112 = v138;
      raw_spin_lock(v138 + 352);
    }
    else
    {
      v112 = v138;
      raw_spin_lock_bh(v138 + 352);
      *(_QWORD *)(v138 + 360) |= 1uLL;
    }
    *v109 = *(_QWORD *)(v137 + 1680);
    v113 = *(_DWORD *)(v137 + 1688);
    v114 = *(_QWORD *)(v112 + 360);
    *(_QWORD *)(v137 + 1680) = v109;
    *(_DWORD *)(v137 + 1688) = v113 - 1;
    if ( (v114 & 1) != 0 )
    {
      *(_QWORD *)(v112 + 360) = v114 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v112 + 352);
    }
    else
    {
      raw_spin_unlock(v112 + 352);
    }
    if ( a3[2] == (unsigned __int8)(v139 + 1) )
      _qdf_nbuf_unmap(v144[3], **((_QWORD **)a3 + 3), 1);
    v115 = *((__int64 **)a3 + 3);
    if ( *v115 )
    {
      _qdf_nbuf_free(*v115);
      v115 = *((__int64 **)a3 + 3);
    }
    v116 = (__int64 *)v115[14];
    ++v139;
    if ( v116 )
    {
      *((_QWORD *)a3 + 3) = v116;
      a2 = *v116;
    }
    v100 = a3[2];
    ++v15;
    goto LABEL_131;
  }
  v107 = *((_QWORD *)a3 + 4);
  v106 = *((_QWORD *)a3 + 5);
  qdf_trace_msg(0x45u, 0, "%s: Unmap the tso segment", a4, a5, a6, a7, a8, a9, a10, a11, "dp_tx_tso_unmap_segment");
  if ( !v107 )
  {
    v16 = "%s %d TSO desc is NULL!";
    v17 = 468;
LABEL_6:
    qdf_trace_msg(0x45u, 2u, v16, a4, a5, a6, a7, a8, a9, a10, a11, "dp_tx_tso_unmap_segment", v17);
    goto LABEL_7;
  }
  if ( !v106 )
  {
    v16 = "%s %d TSO num desc is NULL!";
    v17 = 472;
    goto LABEL_6;
  }
  v108 = *(_DWORD *)(v106 + 8);
  if ( v108 )
  {
    _qdf_nbuf_unmap_tso_segment(v144[3], v107, v108 == 1);
    --*(_DWORD *)(v106 + 8);
  }
LABEL_7:
  v18 = **((_QWORD **)a3 + 4);
  if ( v18 )
  {
    ++v15;
    *((_QWORD *)a3 + 4) = v18;
    goto LABEL_9;
  }
  v105 = *a3;
LABEL_147:
  if ( v105 == 2 )
    ((void (__fastcall *)(__int64 *, __int64, int *))dp_tx_sg_unmap_buf)(v144, a2, a3);
LABEL_151:
  result = a2;
LABEL_152:
  _ReadStatusReg(SP_EL0);
  return result;
}
