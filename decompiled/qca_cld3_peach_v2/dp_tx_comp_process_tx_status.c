__int64 __fastcall dp_tx_comp_process_tx_status(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 *a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x19
  __int64 v17; // x24
  unsigned int v18; // w22
  __int64 v19; // x20
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x9
  __int64 v22; // x27
  unsigned __int64 v23; // x10
  unsigned int v24; // w28
  __int64 v25; // x22
  void (__fastcall **v26)(__int64, __int64, __int64, unsigned int *); // x28
  unsigned int v27; // w8
  unsigned int v28; // w26
  unsigned int v29; // w8
  unsigned int v30; // w9
  _DWORD *v31; // x8
  __int64 v32; // x1
  __int64 v33; // x0
  __int64 *v34; // x8
  __int64 v35; // x8
  unsigned int v36; // w9
  __int64 v37; // x25
  __int64 v38; // x9
  __int64 ref_by_id_1; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w22
  __int64 v49; // x28
  __int64 v50; // x25
  char v51; // w10
  __int64 v52; // x27
  void (__fastcall *v53)(__int64, __int64, __int64, unsigned int *); // x25
  __int64 v54; // x8
  __int64 v55; // x0
  __int64 v56; // x1
  __int64 v57; // x0
  unsigned int v58; // w8
  int v59; // w8
  __int64 v61; // x9
  char v62; // w11
  unsigned __int64 v63; // x9
  __int64 v64; // x9
  __int64 v65; // x8
  unsigned int v66; // w8
  int v67; // w1
  void (__fastcall *v69)(_QWORD); // x8
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned __int8 *v78; // x9
  _DWORD *v79; // x8
  int *v80; // x8
  __int64 v81; // x0
  __int64 v82; // x25
  int v83; // w24
  int v84; // w0
  unsigned int v85; // w9
  unsigned int v86; // w10
  unsigned int v87; // w11
  int v88; // w10
  unsigned int v91; // w10
  unsigned int v92; // w11
  int v93; // w10
  unsigned int v96; // w10
  unsigned int v97; // w11
  int v98; // w11
  __int64 v99; // x2
  __int64 v100; // x1
  unsigned int v103; // w10
  unsigned int v105; // w10
  unsigned int v112; // w10
  unsigned int v115; // w9
  unsigned int v118; // w14
  unsigned int v120; // w13
  unsigned int v122; // w11
  unsigned int v125; // w14
  unsigned int v127; // w13
  unsigned int v129; // w11
  unsigned int v132; // w12
  unsigned int v134; // w9
  unsigned int v136; // w9
  int v137; // [xsp+80h] [xbp-20h]
  unsigned int v138; // [xsp+88h] [xbp-18h]
  unsigned int v139; // [xsp+8Ch] [xbp-14h]
  unsigned int v140; // [xsp+90h] [xbp-10h]
  unsigned int v141; // [xsp+94h] [xbp-Ch] BYREF
  __int64 v142; // [xsp+98h] [xbp-8h]

  v142 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a2 + 8);
  if ( v13 )
  {
    v17 = result;
    if ( *(_BYTE *)(a2 + 65) == 1 )
      v18 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 72) + 40LL) + 36LL);
    else
      v18 = *(unsigned __int16 *)(a2 + 16);
    v20 = *(_QWORD *)(a3 + 8);
    v21 = (v20 >> 13) & 0xF;
    if ( v21 > 4 )
      LODWORD(v22) = 6;
    else
      LODWORD(v22) = dword_B2B408[v21];
    if ( *(_BYTE *)(result + 1142) == 1 )
    {
      v23 = *(_QWORD *)(a3 + 16);
      v24 = a5;
      qdf_trace_msg(
        0x87u,
        8u,
        "%s: --------------------\n"
        "Tx Completion Stats:\n"
        "--------------------\n"
        "ack_frame_rssi = %d\n"
        "first_msdu = %d\n"
        "last_msdu = %d\n"
        "msdu_part_of_amsdu = %d\n"
        "rate_stats valid = %d\n"
        "bw = %d\n"
        "pkt_type = %d\n"
        "stbc = %d\n"
        "ldpc = %d\n"
        "sgi = %d\n"
        "mcs = %d\n"
        "ofdma = %d\n"
        "tones_in_ru = %d\n"
        "tsf = %d\n"
        "ppdu_id = %d\n"
        "transmit_cnt = %d\n"
        "tid = %d\n"
        "peer_id = %d\n"
        "tx_status = %d\n"
        "tx_release_source = %d\n",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "dp_tx_comp_process_tx_status",
        (unsigned __int8)v23,
        ((unsigned int)v23 >> 8) & 1,
        ((unsigned int)v23 >> 9) & 1,
        ((unsigned int)v23 >> 10) & 1,
        BYTE4(v23) & 1,
        (v23 >> 33) & 7,
        (v23 >> 36) & 0xF,
        (v23 >> 40) & 1,
        (v23 >> 41) & 1,
        (v23 >> 42) & 3,
        (v23 >> 44) & 0xF,
        HIWORD(v23) & 1,
        (v23 >> 49) & 0xFFF,
        *(_DWORD *)(a3 + 24),
        HIDWORD(v20) & 0xFFFFFF,
        HIBYTE(v20) & 0x7F,
        (unsigned __int8)BYTE2(*(_DWORD *)(a3 + 28)),
        (unsigned __int16)*(_DWORD *)(a3 + 28),
        ((unsigned int)v20 >> 13) & 0xF,
        *(_DWORD *)(a3 + 8) & 7);
      v20 = *(_QWORD *)(a3 + 8);
      a5 = v24;
    }
    if ( v17 && (v20 & 0x1E000) == 0x2000 )
      ++*(_DWORD *)(v17 + 13544);
    if ( !a4 )
    {
      v29 = *(unsigned __int8 *)(v13 + 71);
      v30 = (v29 >> 3) & 0xF;
      if ( v30 <= 7 && ((1 << v30) & 0x92) != 0 && (v29 & 2) == 0 )
      {
        v31 = *(_DWORD **)(v17 + 1536);
        if ( v31 )
        {
          v32 = *(_QWORD *)(v13 + 224);
          if ( *(v31 - 1) != 69695039 )
            __break(0x8228u);
          v33 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, __int64))v31)(v17, v32, 0, 1, 255);
          if ( v33 )
          {
            if ( *(_DWORD *)(v33 + 408) != 1 || (v34 = *(__int64 **)(v33 + 416)) == nullptr )
              v34 = (__int64 *)v33;
            v35 = *v34;
            if ( v35 )
            {
              if ( (*(_BYTE *)(v35 + 10) & 8) != 0 && (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)v35 + 24LL) + 17LL) & 2) != 0 )
              {
                v62 = *(_BYTE *)(v17 + 20146);
                v36 = (((*(_DWORD *)(a3 + 12) & 0xFFFFFFu) >> *(_BYTE *)(v17 + 20145)) & ~(-1 << v62)) + 1;
                if ( (unsigned __int8)((((*(_DWORD *)(a3 + 12) & 0xFFFFFFu) >> *(_BYTE *)(v17 + 20145)) & ~(-1 << v62))
                                     + 1) >= 5u )
                {
                  LOBYTE(v36) = 0;
                  ++*(_DWORD *)(v35 + 2836);
                }
              }
              else
              {
                LOBYTE(v36) = 0;
              }
              *(_BYTE *)(v13 + 61) = *(_BYTE *)(v13 + 61) & 0xF1
                                   | (2 * (*(_BYTE *)(v35 + (unsigned __int8)v36 + 2276) & 7));
            }
            dp_peer_unref_delete(v33, 1u, a6, a7, a8, a9, a10, a11, a12, a13);
          }
        }
      }
      v37 = jiffies;
      if ( dp_tx_comp_process_tx_status___last_ticks_48 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: peer is null or deletion in progress",
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          "dp_tx_comp_process_tx_status",
          a5);
        dp_tx_comp_process_tx_status___last_ticks_48 = v37;
      }
      if ( v17 )
      {
        v38 = *(_QWORD *)(v17 + 13512) + v18;
        ++*(_QWORD *)(v17 + 13504);
        *(_QWORD *)(v17 + 13512) = v38;
      }
      ref_by_id_1 = dp_vdev_get_ref_by_id_1(v17, *(_BYTE *)(a2 + 48), 7u);
      if ( ref_by_id_1 )
      {
        v48 = *(_DWORD *)(ref_by_id_1 + 46172);
        dp_vdev_unref_delete(v17, ref_by_id_1, 7u, dword_B45C, v40, v41, v42, v43, v44, v45, v46, v47);
      }
      else
      {
        v48 = 17;
      }
      goto LABEL_173;
    }
    v25 = *a4;
    v139 = a5;
    v26 = (void (__fastcall **)(__int64, __int64, __int64, unsigned int *))(*a4 + 43336);
    if ( (*((_BYTE *)a4 + 10) & 8) != 0 && (*(_BYTE *)(*(_QWORD *)(v25 + 24) + 17LL) & 2) != 0 )
    {
      v51 = *(_BYTE *)(v17 + 20146);
      v27 = (((*(_DWORD *)(a3 + 12) & 0xFFFFFFu) >> *(_BYTE *)(v17 + 20145)) & ~(-1 << v51)) + 1;
      if ( (unsigned __int8)((((*(_DWORD *)(a3 + 12) & 0xFFFFFFu) >> *(_BYTE *)(v17 + 20145)) & ~(-1 << v51)) + 1) >= 5u )
      {
        LOBYTE(v27) = 0;
        ++*((_DWORD *)a4 + 709);
      }
    }
    else
    {
      LOBYTE(v27) = 0;
    }
    v28 = (unsigned __int8)v27;
    v140 = v22;
    *(_BYTE *)(v13 + 61) = *(_BYTE *)(v13 + 61) & 0xF1 | (2 * (*((_BYTE *)a4 + (unsigned __int8)v27 + 2221) & 7));
    v138 = *(_DWORD *)(v25 + 46172);
    if ( !v25 )
    {
      v141 = 0;
      v49 = jiffies;
      if ( dp_tx_update_uplink_delay___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: vdev is null or delete in progress",
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          "dp_tx_update_uplink_delay");
        dp_tx_update_uplink_delay___last_ticks = v49;
      }
      v50 = jiffies;
      if ( dp_tx_update_uplink_jitter___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: vdev is null or delete in progress",
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          "dp_tx_update_uplink_jitter");
        dp_tx_update_uplink_jitter___last_ticks = v50;
      }
LABEL_142:
      if ( (*(_BYTE *)(v13 + 61) & 1) != 0 )
      {
        if ( v25 )
        {
          if ( *(_QWORD *)(v25 + 88) )
          {
            v69 = *(void (__fastcall **)(_QWORD))(v25 + 248);
            if ( v69 )
            {
              if ( *((_DWORD *)v69 - 1) != -418403039 )
                __break(0x8228u);
              v69(v13);
            }
          }
        }
      }
      ((void (__fastcall *)(__int64, __int64, __int64 *, _QWORD, _QWORD))dp_tx_update_peer_stats)(a2, a3, a4, v139, v28);
      v78 = *(unsigned __int8 **)(v25 + 24);
      LODWORD(v22) = v140;
      v79 = *((_DWORD **)v78 + 12063);
      if ( v79 && !*(_BYTE *)(a2 + 65) )
      {
        v99 = *(unsigned __int8 *)(a2 + 48);
        v100 = *v78;
        if ( *(v79 - 1) != -915278510 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD, __int64))v79)(v17, v100, v99, v13, v140, 1);
      }
      v80 = (int *)(*a4 + 43528);
      if ( !*(_DWORD *)(*a4 + 46176) )
        goto LABEL_172;
      if ( !*(_QWORD *)(a2 + 96) )
        goto LABEL_172;
      if ( !*(_QWORD *)(a2 + 88) )
        goto LABEL_172;
      v141 = 0;
      v81 = dp_tx_compute_hw_delay_us(a3, *v80, &v141, v70, v71, v72, v73, v74, v75, v76, v77);
      if ( (_DWORD)v81 )
        goto LABEL_172;
      v82 = *(_QWORD *)(a2 + 96);
      v83 = (int)*(_QWORD *)(a2 + 88) / 1000;
      v84 = ktime_get_with_offset(v81);
      _X8 = (__int64)&a4[509 * v28 + 770];
      v85 = *(unsigned __int8 *)_X8;
      v86 = *(_DWORD *)(*a4 + 46184);
      if ( v86 )
      {
        v87 = v83 + (int)v82 / -1000;
        v88 = v87 / v86;
        if ( v88 >= 3 )
          v88 = 3;
        if ( v85 > 1 )
          goto LABEL_206;
        _X12 = (unsigned int *)(_X8 + 96LL * *(unsigned __int8 *)_X8 + 4);
        _X13 = (unsigned int *)(_X8 + 96LL * *(unsigned __int8 *)_X8 + 8);
        __asm { PRFM            #0x11, [X13] }
        do
          v118 = __ldxr(_X13);
        while ( __stxr(v118 + 1, _X13) );
        __asm { PRFM            #0x11, [X12] }
        do
          v120 = __ldxr(_X12);
        while ( __stxr(v120 + v87, _X12) );
        if ( (unsigned int)v88 > 4 )
          goto LABEL_206;
        _X10 = &_X12[v88 + 2];
        __asm { PRFM            #0x11, [X10] }
        do
          v122 = __ldxr(_X10);
        while ( __stxr(v122 + 1, _X10) );
      }
      v91 = *(_DWORD *)(*a4 + 46188);
      if ( v91 )
      {
        v92 = v84 / 1000 - v83;
        v93 = v92 / v91;
        if ( v93 >= 3 )
          v93 = 3;
        if ( v85 > 1 )
          goto LABEL_206;
        _X12 = (unsigned int *)(_X8 + 96LL * v85 + 28);
        _X13 = (unsigned int *)(_X8 + 96LL * v85 + 32);
        __asm { PRFM            #0x11, [X13] }
        do
          v125 = __ldxr(_X13);
        while ( __stxr(v125 + 1, _X13) );
        __asm { PRFM            #0x11, [X12] }
        do
          v127 = __ldxr(_X12);
        while ( __stxr(v127 + v92, _X12) );
        if ( (unsigned int)v93 > 4 )
          goto LABEL_206;
        _X10 = &_X12[v93 + 2];
        __asm { PRFM            #0x11, [X10] }
        do
          v129 = __ldxr(_X10);
        while ( __stxr(v129 + 1, _X10) );
      }
      v96 = v141;
      v97 = *(_DWORD *)(*a4 + 46192);
      if ( !v97 )
      {
LABEL_172:
        v48 = v138;
LABEL_173:
        result = qdf_dp_trace_ptr(
                   *(_QWORD *)(a2 + 8),
                   0x14u,
                   0xFFu,
                   (const void *)(v13 + 224),
                   8u,
                   *(_DWORD *)(a2 + 36),
                   (*(_DWORD *)(a3 + 8) >> 13) & 0xF,
                   v22,
                   v48);
        goto LABEL_174;
      }
      v98 = v141 / v97;
      if ( v98 >= 3 )
        v98 = 3;
      if ( v85 <= 1 )
      {
        _X8 += 96LL * v85 + 52;
        _X9 = (unsigned int *)(_X8 + 4);
        __asm { PRFM            #0x11, [X9] }
        do
          v132 = __ldxr(_X9);
        while ( __stxr(v132 + 1, _X9) );
        __asm { PRFM            #0x11, [X8] }
        do
          v134 = __ldxr((unsigned int *)_X8);
        while ( __stxr(v134 + v96, (unsigned int *)_X8) );
        if ( (unsigned int)v98 <= 4 )
        {
          _X8 += 4LL * (unsigned int)v98 + 8;
          goto LABEL_207;
        }
      }
LABEL_206:
      __break(0x5512u);
LABEL_207:
      __asm { PRFM            #0x11, [X8] }
      do
        v136 = __ldxr((unsigned int *)_X8);
      while ( __stxr(v136 + 1, (unsigned int *)_X8) );
      goto LABEL_172;
    }
    if ( !*(_DWORD *)(v25 + 280) )
    {
      v52 = *(_QWORD *)(v25 + 88);
      if ( v52 )
      {
        v53 = *v26;
        if ( *v26 )
        {
          v54 = *(_QWORD *)(a3 + 8);
          v55 = *(_QWORD *)(a2 + 8);
          v56 = *(_QWORD *)(v25 + 88);
          LOBYTE(v141) = 0;
          v137 = v54;
          if ( *((_DWORD *)v53 - 1) != -1046292560 )
            __break(0x8239u);
          v53(v55, v56, 6, &v141);
          if ( (*(_QWORD *)&v137 & 0x1E000LL) == 0 )
          {
            v57 = *(_QWORD *)(a2 + 8);
            if ( *((_DWORD *)v53 - 1) != -1046292560 )
              __break(0x8239u);
            v53(v57, v52, 7, &v141);
          }
        }
      }
    }
    v141 = 0;
    if ( !*(_DWORD *)(v25 + 43552)
      || (unsigned int)dp_tx_compute_hw_delay_us(
                         a3,
                         *(_DWORD *)(v25 + 43528),
                         &v141,
                         a6,
                         a7,
                         a8,
                         a9,
                         a10,
                         a11,
                         a12,
                         a13) )
    {
      LODWORD(v22) = 0;
LABEL_138:
      v66 = *(_DWORD *)(v25 + 46136);
      if ( *(_DWORD *)(v25 + 43552) )
      {
        if ( v66 >= (unsigned int)v22 )
          v67 = v66 - v22;
        else
          v67 = v22 - v66;
        _X9 = (unsigned int *)(v25 + 46128);
        __asm { PRFM            #0x11, [X9] }
        do
          v103 = __ldxr(_X9);
        while ( __stxr(v103 + v67, _X9) );
        _X9 = (unsigned int *)(v25 + 46132);
        __asm { PRFM            #0x11, [X9] }
        do
          v105 = __ldxr(_X9);
        while ( __stxr(v105 + 1, _X9) );
        *(_DWORD *)(v25 + 46136) = v22;
        *(_DWORD *)(v25 + 5232) = 6;
        dp_hist_update_stats((int *)(v25 + 5232), v67);
      }
      goto LABEL_142;
    }
    v58 = v141 / 0x3E8;
    v141 /= 0x3E8u;
    _X9 = (unsigned int *)(v25 + 43556);
    __asm { PRFM            #0x11, [X9] }
    do
      v112 = __ldxr(_X9);
    while ( __stxr(v112 + v58, _X9) );
    _X8 = (unsigned int *)(v25 + 43560);
    __asm { PRFM            #0x11, [X8] }
    do
      v115 = __ldxr(_X8);
    while ( __stxr(v115 + 1, _X8) );
    v59 = *(_DWORD *)(a3 + 28);
    v22 = v141;
    if ( (v59 & 0xFF0000u) > 0x80000 )
    {
      _X8 = 8;
      if ( *(_DWORD *)(v25 + 43592) )
        goto LABEL_63;
    }
    else
    {
      _X8 = BYTE2(v59);
      if ( *(_DWORD *)(v25 + 43592) )
      {
LABEL_63:
        if ( v141 >= (unsigned __int16)word_163A6 )
        {
          if ( v141 >= (unsigned __int16)word_163A8 )
          {
            if ( v141 >= (unsigned __int16)word_163AA )
            {
              if ( v141 >= (unsigned __int16)word_163AC )
              {
                if ( v141 >= (unsigned __int16)word_163AE )
                {
                  if ( v141 >= (unsigned __int16)word_163B0 )
                  {
                    v61 = 6;
                    if ( v141 >= (unsigned __int16)word_163B2 )
                      v61 = 7;
                  }
                  else
                  {
                    v61 = 5;
                  }
                }
                else
                {
                  v61 = 4;
                }
              }
              else
              {
                v61 = 3;
              }
            }
            else
            {
              v61 = 2;
            }
          }
          else
          {
            v61 = 1;
          }
        }
        else
        {
          v61 = 0;
        }
        if ( (unsigned int)_X8 > 8 )
          goto LABEL_206;
        v63 = v25 + ((unsigned __int64)(unsigned int)_X8 << 6) + 8 * v61;
        ++*(_QWORD *)(v63 + 43600);
      }
    }
    if ( *(_DWORD *)(v25 + 44176) )
    {
      if ( (_DWORD)v22 )
      {
        if ( (_DWORD)v22 == 1 )
        {
          v64 = 1;
        }
        else if ( (unsigned int)v22 >= 3 )
        {
          if ( (_DWORD)v22 == 3 )
          {
            v64 = 3;
          }
          else if ( (unsigned int)v22 >= 5 )
          {
            if ( (_DWORD)v22 == 5 )
            {
              v64 = 5;
            }
            else if ( (unsigned int)v22 >= 7 )
            {
              if ( (_DWORD)v22 == 7 )
              {
                v64 = 7;
              }
              else if ( (unsigned int)v22 >= 9 )
              {
                if ( (_DWORD)v22 == 9 )
                {
                  v64 = 9;
                }
                else if ( (unsigned int)v22 >= 0xF )
                {
                  if ( (unsigned int)v22 >= 0x14 )
                  {
                    if ( (unsigned int)v22 >= 0x19 )
                    {
                      if ( (unsigned int)v22 >= 0x1E )
                      {
                        if ( (unsigned int)v22 >= 0x23 )
                        {
                          if ( (unsigned int)v22 >= 0x28 )
                          {
                            if ( (unsigned int)v22 >= 0x2D )
                            {
                              if ( (unsigned int)v22 >= 0x32 )
                              {
                                if ( (unsigned int)v22 >= 0x3C )
                                {
                                  if ( (unsigned int)v22 >= 0x46 )
                                  {
                                    if ( (unsigned int)v22 >= 0x50 )
                                    {
                                      if ( (unsigned int)v22 >= 0x5A )
                                      {
                                        if ( (unsigned int)v22 >= 0x64 )
                                        {
                                          if ( (unsigned int)v22 >= 0xFA )
                                          {
                                            v64 = 24;
                                            if ( (unsigned int)v22 >= 0x1F4 )
                                              v64 = 25;
                                          }
                                          else
                                          {
                                            v64 = 23;
                                          }
                                        }
                                        else
                                        {
                                          v64 = 22;
                                        }
                                      }
                                      else
                                      {
                                        v64 = 21;
                                      }
                                    }
                                    else
                                    {
                                      v64 = 20;
                                    }
                                  }
                                  else
                                  {
                                    v64 = 19;
                                  }
                                }
                                else
                                {
                                  v64 = 18;
                                }
                              }
                              else
                              {
                                v64 = 17;
                              }
                            }
                            else
                            {
                              v64 = 16;
                            }
                          }
                          else
                          {
                            v64 = 15;
                          }
                        }
                        else
                        {
                          v64 = 14;
                        }
                      }
                      else
                      {
                        v64 = 13;
                      }
                    }
                    else
                    {
                      v64 = 12;
                    }
                  }
                  else
                  {
                    v64 = 11;
                  }
                }
                else
                {
                  v64 = 10;
                }
              }
              else
              {
                v64 = 8;
              }
            }
            else
            {
              v64 = 6;
            }
          }
          else
          {
            v64 = 4;
          }
        }
        else
        {
          v64 = 2;
        }
      }
      else
      {
        v64 = v22;
      }
      if ( (unsigned int)_X8 > 8 )
        goto LABEL_206;
      v65 = v25 + 208LL * (unsigned int)_X8 + 8 * v64;
      ++*(_QWORD *)(v65 + 44184);
    }
    *(_DWORD *)(v25 + 5104) = 5;
    dp_hist_update_stats((int *)(v25 + 5104), v22);
    goto LABEL_138;
  }
  v19 = jiffies;
  if ( dp_tx_comp_process_tx_status___last_ticks - jiffies + 125 < 0 )
  {
    result = qdf_trace_msg(
               0x45u,
               5u,
               "%s: invalid tx descriptor. nbuf NULL",
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               a13,
               "dp_tx_comp_process_tx_status");
    dp_tx_comp_process_tx_status___last_ticks = v19;
  }
LABEL_174:
  _ReadStatusReg(SP_EL0);
  return result;
}
