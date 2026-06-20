__int64 __fastcall dp_rx_wbm_err_process(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x8
  __int64 (__fastcall *v6)(__int64, __int64, __int64, __int64, char *); // x8
  __int64 v7; // x0
  __int64 v8; // x28
  __int64 v9; // x25
  __int64 v10; // x25
  _DWORD *v11; // x8
  __int64 (__fastcall *v12)(_QWORD); // x8
  unsigned int v13; // w0
  _DWORD *v14; // x8
  unsigned __int16 v15; // w21
  unsigned int v16; // w23
  __int64 v17; // x27
  __int64 v18; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 *v27; // x8
  __int64 v28; // x20
  unsigned int v29; // w26
  int v30; // w23
  __int64 (__fastcall *v31)(_QWORD); // x8
  unsigned int v32; // w0
  _DWORD *v33; // x8
  unsigned int v34; // w24
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w22
  __int64 v44; // x8
  __int64 v45; // x21
  __int64 *v46; // x0
  __int64 v47; // x20
  char v48; // w9
  char v49; // w9
  unsigned int v50; // w24
  unsigned int v51; // w5
  int v52; // w4
  unsigned __int64 v53; // x10
  unsigned int v54; // w4
  int v55; // w10
  unsigned int v56; // w8
  int v57; // w9
  unsigned int v58; // w8
  unsigned int v65; // w10
  __int64 v66; // x20
  __int64 v67; // x8
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x8
  unsigned int v77; // w9
  unsigned int v80; // w11
  unsigned int v81; // w8
  int v82; // w5
  __int64 v83; // x0
  __int64 v84; // x1
  __int64 v85; // x2
  __int64 *v86; // x3
  char v87; // w4
  _DWORD *v88; // x8
  __int64 v89; // x20
  unsigned __int8 (__fastcall *v90)(_QWORD); // x8
  __int64 (__fastcall *v91)(_QWORD); // x8
  __int64 (__fastcall *v92)(_QWORD); // x8
  unsigned __int8 (__fastcall *v93)(_QWORD); // x8
  __int64 (__fastcall *v94)(_QWORD); // x8
  __int64 (__fastcall *v95)(_QWORD); // x8
  __int64 (__fastcall *v96)(_QWORD); // x8
  char v97; // w0
  char v98; // w8
  __int64 v99; // x20
  __int64 v100; // x20
  __int64 v101; // x0
  __int64 v102; // x23
  __int64 v103; // x23
  __int64 v104; // x0
  unsigned int v105; // w8
  unsigned int v108; // w10
  unsigned int v111; // w9
  unsigned int v114; // w9
  unsigned int v117; // w9
  __int64 v119; // [xsp+0h] [xbp-60h]
  __int64 v120; // [xsp+8h] [xbp-58h]
  unsigned int v121; // [xsp+1Ch] [xbp-44h]
  __int64 v122; // [xsp+20h] [xbp-40h]
  unsigned __int64 StatusReg; // [xsp+38h] [xbp-28h]
  __int64 v124; // [xsp+40h] [xbp-20h]
  unsigned __int16 v125; // [xsp+48h] [xbp-18h]
  _QWORD v126[2]; // [xsp+50h] [xbp-10h] BYREF

  v126[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a2 + 1128);
  v126[0] = 0;
  v122 = v5;
  v6 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, char *))(a2 + 1760);
  if ( *((_DWORD *)v6 - 1) != 1996224321 )
    __break(0x8228u);
  v7 = v6(a1, a2, a3, a4, (char *)v126 + 4);
  if ( v7 )
  {
    v8 = v7;
    v121 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      v10 = *(_QWORD *)(v8 + 224);
      v11 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 1584LL);
      if ( *(v11 - 1) != -128330861 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *, __int64))v11)(v10, v126, 4);
      v12 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 600LL);
      if ( *((_DWORD *)v12 - 1) != 855462014 )
        __break(0x8228u);
      v13 = v12(v10);
      v14 = *(_DWORD **)(a2 + 1432);
      if ( *(v14 - 1) != 1020823628 )
        __break(0x8228u);
      v15 = ((__int64 (__fastcall *)(__int64, _QWORD))v14)(a2, v13);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a2 + 13304);
      }
      else
      {
        raw_spin_lock_bh(a2 + 13304);
        *(_QWORD *)(a2 + 13312) |= 1uLL;
      }
      v16 = v15;
      v125 = v15;
      if ( *(_DWORD *)(a2 + 13324) > (unsigned int)v15 )
      {
        v17 = *(_QWORD *)(*(_QWORD *)(a2 + 13136) + 8LL * v15);
        if ( !v17 )
          goto LABEL_22;
        if ( *(unsigned __int8 *)(v17 + 388) <= 2u )
        {
          v58 = *(_DWORD *)(v17 + 40);
          while ( v58 )
          {
            _X12 = (unsigned int *)(v17 + 40);
            __asm { PRFM            #0x11, [X12] }
            while ( 1 )
            {
              v65 = __ldxr(_X12);
              if ( v65 != v58 )
                break;
              if ( !__stlxr(v58 + 1, _X12) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v65 == v58;
            v58 = v65;
            if ( _ZF )
            {
              _X8 = (unsigned int *)(v17 + 280);
              __asm { PRFM            #0x11, [X8] }
              do
                v111 = __ldxr(_X8);
              while ( __stxr(v111 + 1, _X8) );
              goto LABEL_22;
            }
          }
        }
      }
      v17 = 0;
LABEL_22:
      v18 = *(_QWORD *)(a2 + 13312);
      if ( (v18 & 1) != 0 )
      {
        *(_QWORD *)(a2 + 13312) = v18 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a2 + 13304);
        if ( !v17 )
          goto LABEL_39;
      }
      else
      {
        raw_spin_unlock(a2 + 13304);
        if ( !v17 )
          goto LABEL_39;
      }
      if ( *(_DWORD *)(v17 + 408) == 1 && (v27 = *(__int64 **)(v17 + 416)) != nullptr )
      {
        v28 = *v27;
        if ( *v27 )
          goto LABEL_27;
      }
      else
      {
        v28 = *(_QWORD *)v17;
        if ( *(_QWORD *)v17 )
        {
LABEL_27:
          v29 = v15;
          v30 = 1;
          if ( (*(_BYTE *)(v8 + 84) & 2) != 0 )
            goto LABEL_41;
          goto LABEL_28;
        }
      }
      dp_peer_unref_delete(v17, 4u, v19, v20, v21, v22, v23, v24, v25, v26);
LABEL_39:
      v45 = jiffies;
      if ( dp_rx_wbm_err_process___last_ticks - jiffies + 125 < 0 )
      {
        LODWORD(v120) = (LODWORD(v126[0]) >> 19) & 0x1F;
        v29 = v16;
        LODWORD(v119) = (LODWORD(v126[0]) >> 17) & 3;
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: peer is null peer_id %u err_src %u, REO: push_rsn %u err_code %u, RXDMA: push_rsn %u err_code %u hit %llu",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "dp_rx_wbm_err_process",
          v16,
          v126[0] & 7,
          HIBYTE(LODWORD(v126[0])) & 3,
          (LODWORD(v126[0]) >> 26) & 0x1F,
          v119,
          v120,
          *(_QWORD *)(a2 + 13776));
        v30 = 0;
        v17 = 0;
        dp_rx_wbm_err_process___last_ticks = v45;
        v28 = 0;
        if ( (*(_BYTE *)(v8 + 84) & 2) != 0 )
        {
LABEL_41:
          v46 = dp_rx_sg_create(a2, (__int64 *)v8);
          v9 = *v46;
          if ( v46 )
            _qdf_nbuf_free((__int64)v46);
          v47 = jiffies;
          if ( dp_rx_wbm_err_process___last_ticks_54 - jiffies + 125 >= 0 )
          {
            if ( !v30 )
              goto LABEL_7;
            goto LABEL_70;
          }
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: scattered msdu dropped",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "dp_rx_wbm_err_process");
          dp_rx_wbm_err_process___last_ticks_54 = v47;
          if ( v30 )
            goto LABEL_70;
          goto LABEL_7;
        }
      }
      else
      {
        v29 = v16;
        v30 = 0;
        v28 = 0;
        v17 = 0;
        if ( (*(_BYTE *)(v8 + 84) & 2) != 0 )
          goto LABEL_41;
      }
LABEL_28:
      v124 = *(_QWORD *)v8;
      v31 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 600LL);
      if ( *((_DWORD *)v31 - 1) != 855462014 )
        __break(0x8228u);
      v32 = v31(v10);
      v33 = *(_DWORD **)(a2 + 1552);
      if ( v33 )
      {
        if ( *(v33 - 1) != -467135654 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v33)(v8, v32);
      }
      v34 = v126[0];
      v43 = v30;
      if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a2 + 40))
        && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a2 + 40), (v34 >> 13) & 3) )
      {
        v44 = 0;
      }
      else
      {
        v44 = *(_QWORD *)(a2 + 72);
        if ( v44 )
        {
          v48 = v30 ^ 1;
          if ( (*(_BYTE *)(v44 + 17) & 2) == 0 )
            v48 = 1;
          if ( (v48 & 1) == 0 && (*(_BYTE *)(v28 + 10) & 8) != 0 )
          {
            v50 = (*(_DWORD *)(v8 + 48) >> 18) & 0xF;
            v49 = 0;
          }
          else
          {
            v49 = 0;
            v50 = 0;
          }
          goto LABEL_53;
        }
      }
      v50 = 0;
      v49 = 1;
LABEL_53:
      v51 = v126[0];
      if ( (v126[0] & 7) != 1 )
      {
        if ( (v126[0] & 7) != 2 )
          goto LABEL_197;
        v52 = HIBYTE(LODWORD(v126[0])) & 3;
        if ( v52 == 1 )
        {
          dp_rx_err_route_hdl(a2, v8, v28, v10, 2, v50);
          goto LABEL_197;
        }
        if ( v52 )
        {
          qdf_trace_msg(
            0x82u,
            1u,
            "%s: invalid reo push reason %u",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "dp_rx_wbm_err_process");
          _qdf_nbuf_free(v8);
          v101 = printk(
                   &unk_AAA255,
                   "expr",
                   "__dp_assert_always_internal",
                   "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
          dump_stack(v101);
          goto LABEL_197;
        }
        if ( a2 )
        {
          v53 = ((unsigned __int64)LODWORD(v126[0]) >> 26) & 0x1F;
          if ( (unsigned int)v53 >= 0xF )
            __break(0x5512u);
          ++*(_DWORD *)(a2 + 13964 + 4 * v53);
        }
        if ( (v49 & 1) == 0 )
          ++*(_DWORD *)(v44 + 508);
        v54 = (v51 >> 26) & 0x1F;
        if ( v54 <= 6 )
        {
          if ( !v54 )
          {
            v88 = *(_DWORD **)(a2 + 1768);
            if ( *(v88 - 1) != 450902238 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64, _QWORD, _QWORD))v88)(
              a2,
              v8,
              v10,
              (v51 >> 13) & 3,
              v28,
              0,
              v50);
            goto LABEL_197;
          }
          if ( v54 == 5 )
          {
            if ( v30 )
              ++*(_DWORD *)(v28 + 4072LL * v50 + 3228);
            v93 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 560LL);
            if ( *((_DWORD *)v93 - 1) != -1147376687 )
              __break(0x8228u);
            if ( v93(v10) )
            {
              v94 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v122 + 74392) + 392LL);
              if ( *((_DWORD *)v94 - 1) != 855462014 )
                __break(0x8228u);
              v121 = v94(v10);
            }
            v95 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 1272LL);
            if ( *((_DWORD *)v95 - 1) != 855462014 )
              __break(0x8228u);
            *(_WORD *)(v8 + 60) = v95(v10);
            *(_QWORD *)v8 = 0;
            dp_2k_jump_handle(a2, v8, v10, v125, v121);
            goto LABEL_197;
          }
          if ( v54 != 6 )
            goto LABEL_143;
        }
        else
        {
          if ( ((v51 >> 26) & 0x1F) > 0xA )
          {
            if ( v54 == 11 || v54 == 13 )
            {
              v9 = v124;
              if ( v30 )
                ++*(_DWORD *)(v28 + 4072LL * v50 + 3220);
              goto LABEL_211;
            }
LABEL_143:
            v89 = jiffies;
            v9 = v124;
            if ( dp_rx_wbm_err_process___last_ticks_56 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x45u,
                5u,
                "%s: Got pkt with REO ERROR: %d",
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                "dp_rx_wbm_err_process");
              dp_rx_wbm_err_process___last_ticks_56 = v89;
            }
            goto LABEL_211;
          }
          if ( v54 == 7 )
          {
            if ( v30 )
              ++*(_DWORD *)(v28 + 4072LL * v50 + 3224);
            v90 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 560LL);
            if ( *((_DWORD *)v90 - 1) != -1147376687 )
              __break(0x8228u);
            if ( v90(v10) )
            {
              v91 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v122 + 74392) + 392LL);
              if ( *((_DWORD *)v91 - 1) != 855462014 )
                __break(0x8228u);
              v121 = v91(v10);
            }
            v92 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL) + 1272LL);
            if ( *((_DWORD *)v92 - 1) != 855462014 )
              __break(0x8228u);
            *(_WORD *)(v8 + 60) = v92(v10);
            *(_QWORD *)v8 = 0;
            dp_rx_oor_handle(a2, v8, v125, v10);
            goto LABEL_197;
          }
          if ( v54 != 8 )
            goto LABEL_143;
        }
        v9 = v124;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a2 + 13304);
        }
        else
        {
          raw_spin_lock_bh(a2 + 13304);
          *(_QWORD *)(a2 + 13312) |= 1uLL;
        }
        if ( *(_DWORD *)(a2 + 13324) <= v29 )
        {
LABEL_112:
          v66 = 0;
        }
        else
        {
          v66 = *(_QWORD *)(*(_QWORD *)(a2 + 13136) + 8LL * v125);
          if ( v66 )
          {
            if ( *(unsigned __int8 *)(v66 + 388) <= 2u )
            {
              v105 = *(_DWORD *)(v66 + 40);
              while ( v105 )
              {
                _X12 = (unsigned int *)(v66 + 40);
                __asm { PRFM            #0x11, [X12] }
                while ( 1 )
                {
                  v108 = __ldxr(_X12);
                  if ( v108 != v105 )
                    break;
                  if ( !__stlxr(v105 + 1, _X12) )
                  {
                    __dmb(0xBu);
                    break;
                  }
                }
                _ZF = v108 == v105;
                v105 = v108;
                if ( _ZF )
                {
                  _X8 = (unsigned int *)(v66 + 280);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v117 = __ldxr(_X8);
                  while ( __stxr(v117 + 1, _X8) );
                  goto LABEL_113;
                }
              }
            }
            goto LABEL_112;
          }
        }
LABEL_113:
        v67 = *(_QWORD *)(a2 + 13312);
        if ( (v67 & 1) != 0 )
        {
          *(_QWORD *)(a2 + 13312) = v67 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a2 + 13304);
          if ( v66 )
            goto LABEL_115;
        }
        else
        {
          raw_spin_unlock(a2 + 13304);
          if ( v66 )
          {
LABEL_115:
            if ( *(_DWORD *)(v66 + 408) == 1 && (v76 = *(_QWORD *)(v66 + 416)) != 0 )
            {
              v77 = *(_DWORD *)(v76 + 40);
              while ( v77 )
              {
                _X13 = (unsigned int *)(v76 + 40);
                __asm { PRFM            #0x11, [X13] }
                while ( 1 )
                {
                  v80 = __ldxr(_X13);
                  if ( v80 != v77 )
                    break;
                  if ( !__stlxr(v77 + 1, _X13) )
                  {
                    __dmb(0xBu);
                    break;
                  }
                }
                _ZF = v80 == v77;
                v77 = v80;
                if ( _ZF )
                {
                  _X8 = (unsigned int *)(v76 + 280);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v114 = __ldxr(_X8);
                  while ( __stxr(v114 + 1, _X8) );
                  v102 = *(_QWORD *)(v66 + 416);
                  dp_peer_unref_delete(v66, 4u, v68, v69, v70, v71, v72, v73, v74, v75);
                  v66 = v102;
                  if ( !v102 )
                    goto LABEL_194;
                  goto LABEL_189;
                }
              }
            }
            else
            {
LABEL_189:
              v103 = jiffies;
              if ( dp_rx_err_handle_bar___last_ticks - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x45u,
                  5u,
                  "%s: BAR update to H.W is skipped",
                  v68,
                  v69,
                  v70,
                  v71,
                  v72,
                  v73,
                  v74,
                  v75,
                  "dp_rx_err_handle_bar");
                dp_rx_err_handle_bar___last_ticks = v103;
              }
              if ( a2 )
                ++*(_DWORD *)(a2 + 14180);
            }
            dp_peer_unref_delete(v66, 4u, v68, v69, v70, v71, v72, v73, v74, v75);
          }
        }
LABEL_194:
        _qdf_nbuf_free(v8);
        if ( !v43 )
          goto LABEL_7;
        goto LABEL_70;
      }
      v55 = (LODWORD(v126[0]) >> 17) & 3;
      if ( v55 == 2 )
      {
        qdf_trace_msg(
          0x82u,
          2u,
          "%s: rxdma push reason %u",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "dp_rx_wbm_err_process",
          2);
        if ( a2 )
          ++*(_DWORD *)(a2 + 14196);
        _qdf_nbuf_free(v8);
        goto LABEL_197;
      }
      if ( v55 == 1 )
      {
        dp_rx_err_route_hdl(a2, v8, v28, v10, 1, v50);
        goto LABEL_197;
      }
      if ( v55 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: invalid rxdma push reason %u, wbm_err 0x%x",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "dp_rx_wbm_err_process",
          3);
        _qdf_nbuf_free(v8);
        v104 = printk(
                 &unk_AAA255,
                 "expr",
                 "__dp_assert_always_internal",
                 "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
        dump_stack(v104);
        goto LABEL_197;
      }
      if ( a2 )
        ++*(_DWORD *)(a2 + 13832 + 4 * (((unsigned __int64)LODWORD(v126[0]) >> 19) & 0x1F));
      if ( (v49 & 1) == 0 )
        ++*(_DWORD *)(v44 + 500);
      v56 = (v51 >> 19) & 0x1F;
      if ( v56 <= 7 )
      {
        switch ( v56 )
        {
          case 3u:
            v96 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v122 + 74392) + 504LL);
            if ( v96 )
            {
              if ( *((_DWORD *)v96 - 1) != -1147376687 )
                __break(0x8228u);
              v97 = v96(v10);
              v98 = v30 ^ 1;
              if ( !v97 )
                v98 = 1;
              if ( (v98 & 1) == 0 )
              {
                dp_rx_process_mic_error(a2, v8, v10, (__int64 *)v28);
                ++*(_DWORD *)(v28 + 4072LL * v50 + 3208);
                goto LABEL_197;
              }
            }
            if ( v30 )
            {
              ++*(_DWORD *)(v28 + 4072LL * v50 + 3212);
              _qdf_nbuf_free(v8);
LABEL_186:
              v9 = v124;
LABEL_70:
              dp_txrx_peer_unref_delete(v17, 4u, v35, v36, v37, v38, v39, v40, v41, v42);
              goto LABEL_7;
            }
            dp_rx_process_rxdma_err(
              a2,
              v8,
              v10,
              nullptr,
              (LODWORD(v126[0]) >> 19) & 0x1F,
              (LODWORD(v126[0]) >> 13) & 3,
              v50);
            break;
          case 4u:
            dp_rx_process_mic_error(a2, v8, v10, (__int64 *)v28);
            if ( v30 )
            {
              ++*(_DWORD *)(v28 + 4072LL * v50 + 3208);
              goto LABEL_186;
            }
            break;
          case 5u:
LABEL_129:
            if ( v30 )
            {
              ++*(_DWORD *)(v28 + 4072LL * v50 + 3232);
              v51 = v126[0];
            }
            v81 = v51 >> 19;
            v82 = (v51 >> 13) & 3;
            v83 = a2;
            v84 = v8;
            v85 = v10;
            v86 = (__int64 *)v28;
            v87 = v81 & 0x1F;
            goto LABEL_139;
          default:
            goto LABEL_174;
        }
      }
      else
      {
        if ( ((v51 >> 19) & 0x1F) <= 0xF )
        {
          if ( v56 == 8 )
            goto LABEL_129;
          if ( v56 != 15 )
            goto LABEL_174;
          v9 = v124;
          if ( v30 )
          {
            ++*(_QWORD *)(v28 + 2288 + 4072LL * v50 + 840);
            if ( (*(_BYTE *)(v8 + 68) & 4) != 0 )
              v57 = *(unsigned __int16 *)(v8 + 66);
            else
              v57 = 0;
            *(_QWORD *)(v28 + 2288 + 4072LL * v50 + 848) += (unsigned int)(*(_DWORD *)(v8 + 112) + v57);
          }
LABEL_211:
          _qdf_nbuf_free(v8);
          if ( !v30 )
            goto LABEL_7;
          goto LABEL_70;
        }
        if ( v56 != 16 )
        {
          if ( v56 == 17 )
          {
            v82 = (v51 >> 13) & 3;
            v83 = a2;
            v84 = v8;
            v85 = v10;
            v86 = (__int64 *)v28;
            v87 = 17;
LABEL_139:
            dp_rx_process_rxdma_err(v83, v84, v85, v86, v87, v82, v50);
            goto LABEL_197;
          }
LABEL_174:
          _qdf_nbuf_free(v8);
          v99 = jiffies;
          if ( dp_rx_wbm_err_process___last_ticks_58 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: RXDMA error %d",
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              "dp_rx_wbm_err_process",
              (LODWORD(v126[0]) >> 19) & 0x1F);
            dp_rx_wbm_err_process___last_ticks_58 = v99;
          }
          v43 = v30;
LABEL_197:
          v9 = v124;
          if ( !v43 )
            goto LABEL_7;
          goto LABEL_70;
        }
        _qdf_nbuf_free(v8);
        if ( v30 )
        {
          v100 = jiffies;
          v9 = v124;
          if ( dp_rx_amsdu_adr_mismatch_hdl___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: RXDMA error %d",
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              "dp_rx_amsdu_adr_mismatch_hdl",
              16);
            dp_rx_amsdu_adr_mismatch_hdl___last_ticks = v100;
          }
          goto LABEL_70;
        }
      }
      v9 = v124;
LABEL_7:
      v8 = v9;
    }
    while ( v9 );
  }
  _ReadStatusReg(SP_EL0);
  return HIDWORD(v126[0]);
}
