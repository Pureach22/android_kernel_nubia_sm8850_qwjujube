__int64 __fastcall dp_tx_comp_process_tx_status(
        __int64 result,
        __int64 a2,
        __int64 a3,
        unsigned __int8 *a4,
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
  __int64 v13; // x19
  __int64 v18; // x24
  unsigned int v19; // w22
  __int64 v20; // x20
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x9
  __int64 v23; // x28
  unsigned __int64 v24; // x10
  __int64 v25; // x22
  __int64 v26; // x26
  __int64 v27; // x25
  __int64 v28; // x9
  __int64 ref_by_id_1; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w22
  __int64 v39; // x27
  __int64 v40; // x22
  __int64 v41; // x26
  void (__fastcall *v42)(__int64, __int64, __int64, unsigned int *); // x27
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 v45; // x1
  __int64 v46; // x0
  unsigned int v47; // w8
  int v48; // w8
  __int64 v50; // x9
  unsigned __int64 v51; // x9
  __int64 v52; // x9
  __int64 v53; // x8
  unsigned int v54; // w8
  int v55; // w1
  void (__fastcall *v57)(_QWORD); // x8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned __int8 *v66; // x9
  _DWORD *v67; // x8
  int *v68; // x8
  __int64 v69; // x0
  __int64 v70; // x25
  int v71; // w24
  int v72; // w0
  unsigned int v73; // w9
  unsigned int v74; // w10
  int v75; // w9
  unsigned int v78; // w9
  unsigned int v79; // w10
  int v80; // w9
  unsigned int v83; // w9
  unsigned int v84; // w10
  int v85; // w10
  __int64 v86; // x2
  __int64 v87; // x1
  unsigned int v90; // w10
  unsigned int v92; // w10
  unsigned int v99; // w10
  unsigned int v102; // w9
  unsigned int v105; // w13
  unsigned int v107; // w12
  unsigned int v109; // w10
  unsigned int v112; // w13
  unsigned int v114; // w12
  unsigned int v116; // w10
  unsigned int v119; // w12
  unsigned int v121; // w11
  unsigned int v123; // w9
  int v124; // [xsp+80h] [xbp-20h]
  unsigned int v125; // [xsp+8Ch] [xbp-14h]
  unsigned int v126; // [xsp+90h] [xbp-10h]
  unsigned int v127; // [xsp+94h] [xbp-Ch] BYREF
  __int64 v128; // [xsp+98h] [xbp-8h]

  v128 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a2 + 8);
  if ( v13 )
  {
    v18 = result;
    if ( *(_BYTE *)(a2 + 65) == 1 )
      v19 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 72) + 40LL) + 36LL);
    else
      v19 = *(unsigned __int16 *)(a2 + 16);
    v21 = *(_QWORD *)(a3 + 8);
    v22 = (v21 >> 13) & 0xF;
    if ( v22 > 4 )
      LODWORD(v23) = 6;
    else
      LODWORD(v23) = dword_A29090[v22];
    if ( *(_BYTE *)(result + 1142) == 1 )
    {
      v24 = *(_QWORD *)(a3 + 16);
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
        (unsigned __int8)v24,
        ((unsigned int)v24 >> 8) & 1,
        ((unsigned int)v24 >> 9) & 1,
        ((unsigned int)v24 >> 10) & 1,
        BYTE4(v24) & 1,
        (v24 >> 33) & 7,
        (v24 >> 36) & 0xF,
        (v24 >> 40) & 1,
        (v24 >> 41) & 1,
        (v24 >> 42) & 3,
        (v24 >> 44) & 0xF,
        HIWORD(v24) & 1,
        (v24 >> 49) & 0xFFF,
        *(_DWORD *)(a3 + 24),
        HIDWORD(v21) & 0xFFFFFF,
        HIBYTE(v21) & 0x7F,
        (unsigned __int8)BYTE2(*(_DWORD *)(a3 + 28)),
        (unsigned __int16)*(_DWORD *)(a3 + 28),
        ((unsigned int)v21 >> 13) & 0xF,
        *(_DWORD *)(a3 + 8) & 7);
      v21 = *(_QWORD *)(a3 + 8);
    }
    if ( v18 && (v21 & 0x1E000) == 0x2000 )
      ++*(_DWORD *)(v18 + 13488);
    if ( !a4 )
    {
      v27 = jiffies;
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
          "dp_tx_comp_process_tx_status");
        dp_tx_comp_process_tx_status___last_ticks_48 = v27;
      }
      if ( v18 )
      {
        v28 = *(_QWORD *)(v18 + 13456) + v19;
        ++*(_QWORD *)(v18 + 13448);
        *(_QWORD *)(v18 + 13456) = v28;
      }
      ref_by_id_1 = dp_vdev_get_ref_by_id_1(v18, *(_BYTE *)(a2 + 48), 7u);
      if ( ref_by_id_1 )
      {
        v38 = *(_DWORD *)(ref_by_id_1 + 45348);
        dp_vdev_unref_delete(v18, ref_by_id_1, 7u, (_DWORD *)off_B120 + 1, v30, v31, v32, v33, v34, v35, v36, v37);
      }
      else
      {
        v38 = 17;
      }
      goto LABEL_150;
    }
    v126 = v23;
    v23 = *(_QWORD *)a4;
    v25 = *(_QWORD *)a4 + 42512LL;
    v125 = *(_DWORD *)(*(_QWORD *)a4 + 45348LL);
    if ( !*(_QWORD *)a4 )
    {
      v127 = 0;
      v39 = jiffies;
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
        dp_tx_update_uplink_delay___last_ticks = v39;
      }
      v40 = jiffies;
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
        dp_tx_update_uplink_jitter___last_ticks = v40;
      }
LABEL_119:
      if ( (*(_BYTE *)(v13 + 61) & 1) != 0 )
      {
        if ( v23 )
        {
          if ( *(_QWORD *)(v23 + 88) )
          {
            v57 = *(void (__fastcall **)(_QWORD))(v23 + 240);
            if ( v57 )
            {
              if ( *((_DWORD *)v57 - 1) != -418403039 )
                __break(0x8228u);
              v57(v13);
            }
          }
        }
      }
      ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD, _QWORD))dp_tx_update_peer_stats)(
        a2,
        a3,
        a4,
        a5,
        0);
      v66 = *(unsigned __int8 **)(v23 + 24);
      LODWORD(v23) = v126;
      v67 = *((_DWORD **)v66 + 11947);
      if ( v67 && !*(_BYTE *)(a2 + 65) )
      {
        v86 = *(unsigned __int8 *)(a2 + 48);
        v87 = *v66;
        if ( *(v67 - 1) != -915278510 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD, __int64))v67)(v18, v87, v86, v13, v126, 1);
      }
      v68 = (int *)(*(_QWORD *)a4 + 42704LL);
      if ( !*(_DWORD *)(*(_QWORD *)a4 + 45352LL) )
        goto LABEL_149;
      if ( !*(_QWORD *)(a2 + 96) )
        goto LABEL_149;
      if ( !*(_QWORD *)(a2 + 88) )
        goto LABEL_149;
      v127 = 0;
      v69 = dp_tx_compute_hw_delay_us(a3, *v68, &v127, v58, v59, v60, v61, v62, v63, v64, v65);
      if ( (_DWORD)v69 )
        goto LABEL_149;
      v70 = *(_QWORD *)(a2 + 96);
      v71 = (int)*(_QWORD *)(a2 + 88) / 1000;
      v72 = ktime_get_with_offset(v69);
      _X8 = a4[5280];
      v73 = *(_DWORD *)(*(_QWORD *)a4 + 45360LL);
      if ( v73 )
      {
        v74 = v71 + (int)v70 / -1000;
        v75 = v74 / v73;
        if ( v75 >= 3 )
          v75 = 3;
        if ( (unsigned int)_X8 > 1 )
          goto LABEL_183;
        _X11 = (unsigned int *)&a4[96 * a4[5280] + 5284];
        _X12 = (unsigned int *)&a4[96 * a4[5280] + 5288];
        __asm { PRFM            #0x11, [X12] }
        do
          v105 = __ldxr(_X12);
        while ( __stxr(v105 + 1, _X12) );
        __asm { PRFM            #0x11, [X11] }
        do
          v107 = __ldxr(_X11);
        while ( __stxr(v107 + v74, _X11) );
        if ( (unsigned int)v75 > 4 )
          goto LABEL_183;
        _X9 = &_X11[v75 + 2];
        __asm { PRFM            #0x11, [X9] }
        do
          v109 = __ldxr(_X9);
        while ( __stxr(v109 + 1, _X9) );
      }
      v78 = *(_DWORD *)(*(_QWORD *)a4 + 45364LL);
      if ( v78 )
      {
        v79 = v72 / 1000 - v71;
        v80 = v79 / v78;
        if ( v80 >= 3 )
          v80 = 3;
        if ( (unsigned int)_X8 > 1 )
          goto LABEL_183;
        _X11 = (unsigned int *)&a4[96 * (unsigned int)_X8 + 5308];
        _X12 = (unsigned int *)&a4[96 * (unsigned int)_X8 + 5312];
        __asm { PRFM            #0x11, [X12] }
        do
          v112 = __ldxr(_X12);
        while ( __stxr(v112 + 1, _X12) );
        __asm { PRFM            #0x11, [X11] }
        do
          v114 = __ldxr(_X11);
        while ( __stxr(v114 + v79, _X11) );
        if ( (unsigned int)v80 > 4 )
          goto LABEL_183;
        _X9 = &_X11[v80 + 2];
        __asm { PRFM            #0x11, [X9] }
        do
          v116 = __ldxr(_X9);
        while ( __stxr(v116 + 1, _X9) );
      }
      v83 = v127;
      v84 = *(_DWORD *)(*(_QWORD *)a4 + 45368LL);
      if ( !v84 )
      {
LABEL_149:
        v38 = v125;
LABEL_150:
        result = qdf_dp_trace_ptr(
                   *(_QWORD *)(a2 + 8),
                   0x14u,
                   0xFFu,
                   (const void *)(v13 + 224),
                   8u,
                   *(_DWORD *)(a2 + 36),
                   (*(_DWORD *)(a3 + 8) >> 13) & 0xF,
                   v23,
                   v38);
        goto LABEL_151;
      }
      v85 = v127 / v84;
      if ( v85 >= 3 )
        v85 = 3;
      if ( (unsigned int)_X8 <= 1 )
      {
        _X8 = (__int64)&a4[96 * (unsigned int)_X8 + 5332];
        _X11 = (unsigned int *)(_X8 + 4);
        __asm { PRFM            #0x11, [X11] }
        do
          v119 = __ldxr(_X11);
        while ( __stxr(v119 + 1, _X11) );
        __asm { PRFM            #0x11, [X8] }
        do
          v121 = __ldxr((unsigned int *)_X8);
        while ( __stxr(v121 + v83, (unsigned int *)_X8) );
        if ( (unsigned int)v85 <= 4 )
        {
          _X8 += 4LL * (unsigned int)v85 + 8;
          goto LABEL_184;
        }
      }
LABEL_183:
      __break(0x5512u);
LABEL_184:
      __asm { PRFM            #0x11, [X8] }
      do
        v123 = __ldxr((unsigned int *)_X8);
      while ( __stxr(v123 + 1, (unsigned int *)_X8) );
      goto LABEL_149;
    }
    if ( !*(_DWORD *)(v23 + 272) )
    {
      v41 = *(_QWORD *)(v23 + 88);
      if ( v41 )
      {
        v42 = *(void (__fastcall **)(__int64, __int64, __int64, unsigned int *))v25;
        if ( *(_QWORD *)v25 )
        {
          v43 = *(_QWORD *)(a3 + 8);
          v44 = *(_QWORD *)(a2 + 8);
          v45 = *(_QWORD *)(v23 + 88);
          LOBYTE(v127) = 0;
          v124 = v43;
          if ( *((_DWORD *)v42 - 1) != -1046292560 )
            __break(0x823Bu);
          v42(v44, v45, 6, &v127);
          if ( (*(_QWORD *)&v124 & 0x1E000LL) == 0 )
          {
            v46 = *(_QWORD *)(a2 + 8);
            if ( *((_DWORD *)v42 - 1) != -1046292560 )
              __break(0x823Bu);
            v42(v46, v41, 7, &v127);
          }
        }
      }
    }
    v127 = 0;
    if ( !*(_DWORD *)(v25 + 216)
      || (unsigned int)dp_tx_compute_hw_delay_us(a3, *(_DWORD *)(v25 + 192), &v127, a6, a7, a8, a9, a10, a11, a12, a13) )
    {
      LODWORD(v26) = 0;
LABEL_115:
      v54 = *(_DWORD *)(v25 + 2800);
      if ( *(_DWORD *)(v25 + 216) )
      {
        if ( v54 >= (unsigned int)v26 )
          v55 = v54 - v26;
        else
          v55 = v26 - v54;
        _X9 = (unsigned int *)(v25 + 2792);
        __asm { PRFM            #0x11, [X9] }
        do
          v90 = __ldxr(_X9);
        while ( __stxr(v90 + v55, _X9) );
        _X9 = (unsigned int *)(v25 + 2796);
        __asm { PRFM            #0x11, [X9] }
        do
          v92 = __ldxr(_X9);
        while ( __stxr(v92 + 1, _X9) );
        *(_DWORD *)(v25 + 2800) = v26;
        *(_DWORD *)(v23 + 4776) = 6;
        dp_hist_update_stats((int *)(v23 + 4776), v55);
      }
      goto LABEL_119;
    }
    v47 = v127 / 0x3E8;
    v127 /= 0x3E8u;
    _X9 = (unsigned int *)(v25 + 220);
    __asm { PRFM            #0x11, [X9] }
    do
      v99 = __ldxr(_X9);
    while ( __stxr(v99 + v47, _X9) );
    _X8 = (unsigned int *)(v25 + 224);
    __asm { PRFM            #0x11, [X8] }
    do
      v102 = __ldxr(_X8);
    while ( __stxr(v102 + 1, _X8) );
    v48 = *(_DWORD *)(a3 + 28);
    v26 = v127;
    if ( (v48 & 0xFF0000u) > 0x80000 )
    {
      _X8 = 8;
      if ( *(_DWORD *)(v25 + 256) )
        goto LABEL_42;
    }
    else
    {
      _X8 = BYTE2(v48);
      if ( *(_DWORD *)(v25 + 256) )
      {
LABEL_42:
        if ( v127 >= (unsigned __int16)word_15A86 )
        {
          if ( v127 >= (unsigned __int16)word_15A88 )
          {
            if ( v127 >= (unsigned __int16)word_15A8A )
            {
              if ( v127 >= (unsigned __int16)word_15A8C )
              {
                if ( v127 >= (unsigned __int16)word_15A8E )
                {
                  if ( v127 >= (unsigned __int16)word_15A90 )
                  {
                    v50 = 6;
                    if ( v127 >= (unsigned __int16)word_15A92 )
                      v50 = 7;
                  }
                  else
                  {
                    v50 = 5;
                  }
                }
                else
                {
                  v50 = 4;
                }
              }
              else
              {
                v50 = 3;
              }
            }
            else
            {
              v50 = 2;
            }
          }
          else
          {
            v50 = 1;
          }
        }
        else
        {
          v50 = 0;
        }
        if ( (unsigned int)_X8 > 8 )
          goto LABEL_183;
        v51 = v23 + ((unsigned __int64)(unsigned int)_X8 << 6) + 8 * v50;
        ++*(_QWORD *)(v51 + 42776);
      }
    }
    if ( *(_DWORD *)(v25 + 840) )
    {
      if ( (_DWORD)v26 )
      {
        if ( (_DWORD)v26 == 1 )
        {
          v52 = 1;
        }
        else if ( (unsigned int)v26 >= 3 )
        {
          if ( (_DWORD)v26 == 3 )
          {
            v52 = 3;
          }
          else if ( (unsigned int)v26 >= 5 )
          {
            if ( (_DWORD)v26 == 5 )
            {
              v52 = 5;
            }
            else if ( (unsigned int)v26 >= 7 )
            {
              if ( (_DWORD)v26 == 7 )
              {
                v52 = 7;
              }
              else if ( (unsigned int)v26 >= 9 )
              {
                if ( (_DWORD)v26 == 9 )
                {
                  v52 = 9;
                }
                else if ( (unsigned int)v26 >= 0xF )
                {
                  if ( (unsigned int)v26 >= 0x14 )
                  {
                    if ( (unsigned int)v26 >= 0x19 )
                    {
                      if ( (unsigned int)v26 >= 0x1E )
                      {
                        if ( (unsigned int)v26 >= 0x23 )
                        {
                          if ( (unsigned int)v26 >= 0x28 )
                          {
                            if ( (unsigned int)v26 >= 0x2D )
                            {
                              if ( (unsigned int)v26 >= 0x32 )
                              {
                                if ( (unsigned int)v26 >= 0x3C )
                                {
                                  if ( (unsigned int)v26 >= 0x46 )
                                  {
                                    if ( (unsigned int)v26 >= 0x50 )
                                    {
                                      if ( (unsigned int)v26 >= 0x5A )
                                      {
                                        if ( (unsigned int)v26 >= 0x64 )
                                        {
                                          if ( (unsigned int)v26 >= 0xFA )
                                          {
                                            v52 = 24;
                                            if ( (unsigned int)v26 >= 0x1F4 )
                                              v52 = 25;
                                          }
                                          else
                                          {
                                            v52 = 23;
                                          }
                                        }
                                        else
                                        {
                                          v52 = 22;
                                        }
                                      }
                                      else
                                      {
                                        v52 = 21;
                                      }
                                    }
                                    else
                                    {
                                      v52 = 20;
                                    }
                                  }
                                  else
                                  {
                                    v52 = 19;
                                  }
                                }
                                else
                                {
                                  v52 = 18;
                                }
                              }
                              else
                              {
                                v52 = 17;
                              }
                            }
                            else
                            {
                              v52 = 16;
                            }
                          }
                          else
                          {
                            v52 = 15;
                          }
                        }
                        else
                        {
                          v52 = 14;
                        }
                      }
                      else
                      {
                        v52 = 13;
                      }
                    }
                    else
                    {
                      v52 = 12;
                    }
                  }
                  else
                  {
                    v52 = 11;
                  }
                }
                else
                {
                  v52 = 10;
                }
              }
              else
              {
                v52 = 8;
              }
            }
            else
            {
              v52 = 6;
            }
          }
          else
          {
            v52 = 4;
          }
        }
        else
        {
          v52 = 2;
        }
      }
      else
      {
        v52 = v26;
      }
      if ( (unsigned int)_X8 > 8 )
        goto LABEL_183;
      v53 = v23 + 208LL * (unsigned int)_X8 + 8 * v52;
      ++*(_QWORD *)(v53 + 43360);
    }
    *(_DWORD *)(v23 + 4648) = 5;
    dp_hist_update_stats((int *)(v23 + 4648), v26);
    goto LABEL_115;
  }
  v20 = jiffies;
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
    dp_tx_comp_process_tx_status___last_ticks = v20;
  }
LABEL_151:
  _ReadStatusReg(SP_EL0);
  return result;
}
