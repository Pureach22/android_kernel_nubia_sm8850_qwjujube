__int64 __fastcall dp_rx_reo_err_entry_process(
        __int64 a1,
        __int64 a2,
        unsigned __int16 *a3,
        __int64 a4,
        unsigned int a5)
{
  __int64 v8; // x8
  __int64 (*v9)(void); // x8
  int v11; // w8
  __int64 v12; // x23
  int v13; // w25
  __int64 v14; // x1
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int16 v24; // w26
  __int64 v25; // x24
  int v26; // w25
  __int64 (__fastcall *v27)(__int64, __int64); // x8
  __int64 v28; // x1
  __int64 v29; // x0
  char v30; // w8
  __int64 v31; // x20
  __int64 *v32; // x22
  __int64 v33; // x9
  unsigned int v34; // w28
  __int64 v35; // x8
  int v36; // w21
  _QWORD *v37; // x25
  char v38; // w8
  __int64 v39; // x9
  __int64 v40; // x9
  int v41; // w8
  unsigned __int64 v42; // x9
  unsigned __int64 v43; // x8
  char v44; // w8
  void (__fastcall *v45)(__int64, unsigned __int16 *); // x8
  __int64 v46; // x0
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x8
  unsigned int (__fastcall *v50)(_QWORD); // x8
  __int64 v51; // x8
  void (__fastcall *v52)(__int64, unsigned __int64 *); // x9
  __int64 v53; // x0
  _DWORD *v54; // x8
  __int64 (__fastcall *v55)(__int64, __int64); // x8
  __int64 v56; // x1
  __int64 v57; // x26
  __int64 v58; // x20
  __int64 v59; // x23
  __int64 v60; // x8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 *v69; // x8
  __int64 v70; // x21
  int v71; // w27
  __int64 v72; // x23
  __int64 v73; // x0
  __int64 (__fastcall *v74)(_QWORD); // x8
  unsigned int v75; // w0
  _DWORD *v76; // x8
  unsigned int v77; // w10
  __int64 v78; // x6
  char v79; // w8
  unsigned __int8 (__fastcall *v80)(_QWORD); // x8
  __int64 (__fastcall *v81)(_QWORD); // x8
  _DWORD *v82; // x8
  unsigned int v83; // w8
  unsigned int v89; // w10
  __int64 v90; // x20
  __int64 v91; // x20
  __int64 v92; // x0
  __int64 v93; // x22
  __int64 v94; // x0
  unsigned int v97; // w9
  void (__fastcall *v98)(__int64 *, unsigned __int64 *); // x8
  unsigned int v99; // w8
  _QWORD *v100; // x8
  __int64 v102; // [xsp+0h] [xbp-160h]
  unsigned int *v105; // [xsp+18h] [xbp-148h]
  __int64 v106; // [xsp+20h] [xbp-140h]
  unsigned int v107; // [xsp+28h] [xbp-138h]
  unsigned int v108; // [xsp+2Ch] [xbp-134h]
  char v109; // [xsp+30h] [xbp-130h]
  int v110; // [xsp+34h] [xbp-12Ch]
  __int64 v111; // [xsp+38h] [xbp-128h]
  __int64 v112; // [xsp+40h] [xbp-120h]
  __int64 v113; // [xsp+48h] [xbp-118h]
  unsigned __int64 StatusReg; // [xsp+50h] [xbp-110h]
  _QWORD *v115; // [xsp+60h] [xbp-100h]
  char v116; // [xsp+6Ch] [xbp-F4h]
  unsigned int v117; // [xsp+84h] [xbp-DCh]
  __int64 v118; // [xsp+88h] [xbp-D8h]
  __int64 v119; // [xsp+90h] [xbp-D0h] BYREF
  __int64 v120; // [xsp+98h] [xbp-C8h] BYREF
  unsigned __int16 v121; // [xsp+A4h] [xbp-BCh] BYREF
  unsigned __int64 v122; // [xsp+A8h] [xbp-B8h] BYREF
  __int64 v123; // [xsp+B0h] [xbp-B0h]
  unsigned __int64 v124; // [xsp+B8h] [xbp-A8h] BYREF
  _QWORD v125[6]; // [xsp+C0h] [xbp-A0h] BYREF
  _QWORD v126[4]; // [xsp+F0h] [xbp-70h] BYREF
  _QWORD v127[6]; // [xsp+110h] [xbp-50h] BYREF
  _QWORD v128[4]; // [xsp+140h] [xbp-20h] BYREF

  v128[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 6400);
  v122 = 0;
  v123 = 0;
  v119 = 0;
  v120 = 0;
  v102 = v8;
  v9 = *(__int64 (**)(void))(a1 + 1432);
  if ( *((_DWORD *)v9 - 1) != 1020823628 )
    __break(0x8228u);
  v113 = v9();
  if ( (*(_BYTE *)(a1 + 20096) & 1) != 0 )
  {
    if ( a5 > 0xC || (v110 = 1, ((1 << a5) & 0x10A0) == 0) )
    {
      _ZF = a5 == 6 || a5 == 8;
      v11 = _ZF;
      v110 = v11;
    }
  }
  else
  {
    v110 = 0;
  }
  v12 = 0;
  v13 = 0;
  v14 = a4;
  v108 = a5;
  v109 = 0;
  v115 = nullptr;
  v107 = 17;
  StatusReg = _ReadStatusReg(SP_EL0);
  v15 = (unsigned int *)a2;
  v111 = 0;
  v112 = 0;
  v116 = 0;
  v117 = 0;
  memset(v127, 0, sizeof(v127));
  memset(v126, 0, sizeof(v126));
  memset(v125, 0, sizeof(v125));
  v121 = 0;
  while ( 1 )
  {
    v105 = v15;
    v106 = v14;
    hal_rx_msdu_list_get(*(_QWORD *)(a1 + 1128), v14, (__int64)v125, (__int16 *)&v121);
    v24 = v121;
    if ( v121 )
      break;
LABEL_171:
    if ( v106 )
    {
      v119 = *(_QWORD *)(v106 + 4);
      if ( !(_DWORD)v119 )
        goto LABEL_181;
      qdf_mem_set((void *)(v106 + 4), 8u, 0);
    }
    else
    {
      qdf_mem_set(&v119, 8u, 0);
      if ( !(_DWORD)v119 )
      {
LABEL_181:
        dp_rx_link_desc_return_by_addr(a1, v105, 0, v16, v17, v18, v19, v20, v21, v22, v23);
        if ( *a3 != (unsigned __int16)v13 )
          goto LABEL_185;
        goto LABEL_182;
      }
    }
    dp_rx_link_desc_return_by_addr(a1, v105, 0, v16, v17, v18, v19, v20, v21, v22, v23);
    v98 = *(void (__fastcall **)(__int64 *, unsigned __int64 *))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1456LL);
    v122 = (unsigned int)v119 | ((unsigned __int64)BYTE4(v119) << 32);
    if ( *((_DWORD *)v98 - 1) != -621572614 )
      __break(0x8228u);
    v98(&v119, &v122);
    v99 = ((unsigned int)v123 >> 5) & 0x3FF;
    if ( v99 >= *(unsigned __int16 *)(a1 + 1914) )
    {
      v14 = 0;
    }
    else
    {
      v100 = (_QWORD *)(*(_QWORD *)(a1 + 1920) + 24LL * v99);
      v14 = *v100 + v122 - v100[2];
    }
    v120 = v119;
    v15 = (unsigned int *)&v120;
  }
  v25 = 0;
  while ( v25 != 6 )
  {
    v27 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 1408);
    v28 = *((unsigned int *)v126 + v25);
    if ( *((_DWORD *)v27 - 1) != 207937137 )
      __break(0x8228u);
    v29 = v27(a1, v28);
    if ( !v29 )
    {
      v94 = printk(
              &unk_AAA255,
              "expr",
              "__dp_assert_always_internal",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
      dump_stack(v94);
      goto LABEL_19;
    }
    v30 = *(_BYTE *)(v29 + 30);
    v31 = v29;
    if ( (v30 & 1) == 0 || (v32 = *(__int64 **)v29) == nullptr )
    {
      if ( a1 )
        ++*(_DWORD *)(a1 + 14056);
      v93 = jiffies;
      if ( dp_rx_reo_err_entry_process___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Reaping rx_desc not in use!",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "dp_rx_reo_err_entry_process");
        dp_rx_reo_err_entry_process___last_ticks = v93;
      }
      dp_rx_dump_info_and_assert(a1, v102, a2, v31);
      goto LABEL_36;
    }
    if ( (v25 & 0x1FFFFFFFFFFFFFFFLL) == 6 )
      goto LABEL_184;
    v33 = 10;
    if ( (*((_BYTE *)v32 + 68) & 4) == 0 )
      v33 = 5;
    if ( v32[v33] != v127[v25] )
    {
      if ( a1 )
      {
        ++*(_DWORD *)(a1 + 14164);
        v30 = *(_BYTE *)(v29 + 30);
      }
      *(_BYTE *)(v29 + 30) = v30 | 4;
LABEL_36:
      v116 = 1;
      goto LABEL_19;
    }
    v34 = *(unsigned __int8 *)(v29 + 28);
    if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40))
      && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a1 + 40), v34) )
    {
      v118 = 0;
    }
    else
    {
      v118 = *(_QWORD *)(a1 + 72);
    }
    if ( v34 > 4 )
      break;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 18520);
    }
    else
    {
      raw_spin_lock_bh(a1 + 18520);
      *(_QWORD *)(a1 + 18528) |= 1uLL;
    }
    dp_rx_nbuf_unmap_pool(a1, a1 + 12416 + 120LL * v34, (__int64)v32);
    *(_BYTE *)(v31 + 30) |= 2u;
    v35 = *(_QWORD *)(a1 + 18528);
    v36 = v13;
    if ( (v35 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18528) = v35 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18520);
    }
    else
    {
      raw_spin_unlock(a1 + 18520);
    }
    v37 = &v125[v25];
    *((_WORD *)v32 + 30) = *((_WORD *)v37 + 2);
    v38 = *(_BYTE *)(v31 + 30);
    *(_QWORD *)v31 = 0;
    *(_BYTE *)(v31 + 30) = v38 & 0xFE;
    *(_QWORD *)v31 = *(_QWORD *)(v118 + 96120);
    v39 = *(_QWORD *)(v118 + 96128);
    *(_QWORD *)(v118 + 96120) = v31;
    if ( v39 && *(_QWORD *)v31 )
    {
      if ( v12 )
        goto LABEL_48;
    }
    else
    {
      *(_QWORD *)(v118 + 96128) = v31;
      if ( v12 )
      {
LABEL_48:
        *v115 = v32;
        v40 = *(_QWORD *)(v12 + 72);
        v41 = v40 + 0x1000000;
        v42 = v40 & 0xFFFFFFFF00FFFFFFLL;
        v43 = v41 & 0xFF000000;
        goto LABEL_51;
      }
    }
    v42 = 0x1000000;
    v12 = (__int64)v32;
    v43 = v32[9] & 0xFFFFFFFF00FFFFFFLL;
LABEL_51:
    *(_QWORD *)(v12 + 72) = v43 | v42;
    v44 = *(_BYTE *)v37;
    *v32 = 0;
    ++v117;
    if ( (v44 & 4) != 0 )
    {
      v115 = v32;
      v13 = v36;
      *((_BYTE *)v32 + 84) |= 2u;
      goto LABEL_19;
    }
    if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD))dp_rx_buffer_pool_refill)(a1, v12, v34) & 1) == 0 )
    {
      if ( !v110 )
      {
        v26 = v36;
        goto LABEL_79;
      }
      if ( (*(_BYTE *)v37 & 1) != 0 )
      {
        v26 = v36;
        if ( (v109 & 1) == 0 )
        {
          v45 = *(void (__fastcall **)(__int64, unsigned __int16 *))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL)
                                                                   + 1600LL);
          if ( v45 )
          {
            v46 = v32[28];
            if ( *((_DWORD *)v45 - 1) != -177782713 )
              __break(0x8228u);
            v45(v46, a3);
          }
        }
      }
      else
      {
        v26 = v36;
        if ( (v109 & 1) == 0 )
        {
          if ( (v116 & 1) != 0 )
          {
            v109 = 0;
            v116 = 1;
          }
          else
          {
            v92 = printk(
                    &unk_AAA255,
                    "0",
                    "dp_rx_reo_err_entry_process",
                    "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
            dump_stack(v92);
            v109 = 0;
            v116 = 0;
          }
          do
          {
LABEL_145:
            v90 = *(_QWORD *)v12;
            _qdf_nbuf_free(v12);
            v12 = v90;
          }
          while ( v90 );
          goto LABEL_18;
        }
      }
      v47 = *(_QWORD *)(a1 + 1128);
      v48 = v32[28];
      v124 = 0;
      v49 = *(_QWORD *)(v47 + 74392);
      v128[0] = 0;
      v128[1] = 0;
      v50 = *(unsigned int (__fastcall **)(_QWORD))(v49 + 544);
      if ( *((_DWORD *)v50 - 1) != 855462014 )
        __break(0x8228u);
      if ( !v50(v48) )
        goto LABEL_74;
      v51 = *(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL);
      v52 = *(void (__fastcall **)(__int64, unsigned __int64 *))(v51 + 1328);
      if ( v52 )
      {
        if ( *((_DWORD *)v52 - 1) != -153087695 )
          __break(0x8229u);
        v52(a2, &v124);
        v51 = *(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL);
      }
      v53 = v32[28];
      v54 = *(_DWORD **)(v51 + 1320);
      if ( *(v54 - 1) != 721645347 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *))v54)(v53, v128);
      if ( v128[0] > v124 )
      {
LABEL_74:
        v55 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 1432);
        v56 = *((unsigned int *)a3 + 2);
        if ( *((_DWORD *)v55 - 1) != 1020823628 )
          __break(0x8228u);
        v113 = v55(a1, v56);
        if ( a3[6] )
          dp_rx_bar_frame_handle(a1, (__int64)a3, v107, 0, v108);
        v109 = 1;
LABEL_79:
        v57 = *(_QWORD *)(v12 + 224);
        v58 = v32[28];
        if ( (__int64 *)v12 != v32 )
        {
          *(_WORD *)(v12 + 60) = *((_WORD *)v32 + 30);
          v32 = dp_rx_sg_create(a1, (__int64 *)v12);
          *((_BYTE *)v32 + 84) |= 0x80u;
          if ( a1 )
            ++*(_DWORD *)(a1 + 14144);
        }
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 13304);
        }
        else
        {
          raw_spin_lock_bh(a1 + 13304);
          *(_QWORD *)(a1 + 13312) |= 1uLL;
        }
        if ( *(_DWORD *)(a1 + 13324) <= (unsigned int)(unsigned __int16)v113 )
        {
LABEL_87:
          v59 = 0;
        }
        else
        {
          v59 = *(_QWORD *)(*(_QWORD *)(a1 + 13136) + 8LL * (unsigned __int16)v113);
          if ( v59 )
          {
            if ( *(unsigned __int8 *)(v59 + 388) <= 2u )
            {
              v83 = *(_DWORD *)(v59 + 40);
              while ( v83 )
              {
                _X12 = (unsigned int *)(v59 + 40);
                __asm { PRFM            #0x11, [X12] }
                while ( 1 )
                {
                  v89 = __ldxr(_X12);
                  if ( v89 != v83 )
                    break;
                  if ( !__stlxr(v83 + 1, _X12) )
                  {
                    __dmb(0xBu);
                    break;
                  }
                }
                _ZF = v89 == v83;
                v83 = v89;
                if ( _ZF )
                {
                  _X8 = (unsigned int *)(v59 + 280);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v97 = __ldxr(_X8);
                  while ( __stxr(v97 + 1, _X8) );
                  goto LABEL_88;
                }
              }
            }
            goto LABEL_87;
          }
        }
LABEL_88:
        v60 = *(_QWORD *)(a1 + 13312);
        if ( (v60 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 13312) = v60 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 13304);
          if ( v59 )
            goto LABEL_90;
          goto LABEL_96;
        }
        raw_spin_unlock(a1 + 13304);
        if ( !v59 )
          goto LABEL_96;
LABEL_90:
        if ( *(_DWORD *)(v59 + 408) == 1 && (v69 = *(__int64 **)(v59 + 416)) != nullptr )
        {
          v70 = *v69;
          if ( *v69 )
            goto LABEL_93;
LABEL_95:
          dp_peer_unref_delete(v59, 4u, v61, v62, v63, v64, v65, v66, v67, v68);
LABEL_96:
          v72 = jiffies;
          if ( dp_rx_reo_err_entry_process___last_ticks_21 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: txrx_peer is null peer_id %u",
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              "dp_rx_reo_err_entry_process",
              (unsigned __int16)v113);
            v71 = 0;
            v70 = 0;
            dp_rx_reo_err_entry_process___last_ticks_21 = v72;
          }
          else
          {
            v71 = 0;
            v70 = 0;
          }
          v59 = v111;
        }
        else
        {
          v70 = *(_QWORD *)v59;
          if ( !*(_QWORD *)v59 )
            goto LABEL_95;
LABEL_93:
          v71 = 1;
        }
        v73 = v32[28];
        v74 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 600LL);
        if ( *((_DWORD *)v74 - 1) != 855462014 )
          __break(0x8228u);
        v75 = v74(v73);
        v76 = *(_DWORD **)(a1 + 1552);
        if ( v76 )
        {
          if ( *(v76 - 1) != -467135654 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64 *, _QWORD))v76)(v32, v75);
        }
        if ( v118 )
        {
          v77 = v108;
          v78 = v112;
          v79 = v71 ^ 1;
          if ( (*(_BYTE *)(v118 + 17) & 2) == 0 )
            v79 = 1;
          if ( (v79 & 1) == 0 && (*(_BYTE *)(v70 + 10) & 8) != 0 )
            v78 = (*((_DWORD *)v32 + 12) >> 18) & 0xF;
          if ( !v71 )
            goto LABEL_117;
        }
        else
        {
          v77 = v108;
          v78 = v112;
          if ( !v71 )
            goto LABEL_117;
        }
        if ( (unsigned __int8)v78 >= 5u )
          break;
        *((_DWORD *)v32 + 12) = v32[6] & 0xFE3FFFFF | ((*(_BYTE *)(v70 + (unsigned __int8)v78 + 2221) & 7) << 22);
LABEL_117:
        v112 = v78;
        if ( v77 <= 0xC )
        {
          if ( ((1 << v77) & 0x1060) != 0 )
          {
            v80 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 560LL);
            if ( *((_DWORD *)v80 - 1) != -1147376687 )
              __break(0x8228u);
            if ( v80(v58) )
            {
              v81 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 392LL);
              if ( *((_DWORD *)v81 - 1) != 855462014 )
                __break(0x8228u);
              v107 = v81(v57);
            }
            dp_2k_jump_handle(a1, (__int64)v32, v58, v113, v107);
            goto LABEL_151;
          }
          if ( ((1 << v77) & 0x180) != 0 )
          {
            dp_rx_oor_handle(a1, v32, v113, v58);
LABEL_151:
            if ( v71 )
              dp_txrx_peer_unref_delete(v59, 4u, v16, v17, v18, v19, v20, v21, v22, v23);
            v111 = v59;
            goto LABEL_18;
          }
          if ( !v77 )
          {
            v82 = *(_DWORD **)(a1 + 1768);
            if ( *(v82 - 1) != 450902238 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64 *, __int64, _QWORD, __int64, __int64))v82)(a1, v32, v58, v34, v70, 1);
            goto LABEL_151;
          }
        }
        v91 = jiffies;
        if ( dp_rx_reo_err_entry_process___last_ticks_23 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Non-support error code %d",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "dp_rx_reo_err_entry_process",
            v108);
          dp_rx_reo_err_entry_process___last_ticks_23 = v91;
        }
        if ( v32 )
          _qdf_nbuf_free((__int64)v32);
        goto LABEL_151;
      }
      if ( a1 )
        ++*(_DWORD *)(a1 + 14188);
      v109 = 1;
      goto LABEL_145;
    }
    v26 = v36;
    v116 = 1;
LABEL_18:
    v24 = v121;
    v12 = 0;
    v13 = v26 + 1;
    v115 = nullptr;
LABEL_19:
    if ( ++v25 >= (unsigned __int64)v24 )
      goto LABEL_171;
  }
  __break(0x5512u);
LABEL_184:
  __break(1u);
LABEL_185:
  if ( a1 )
    ++*(_DWORD *)(a1 + 14152);
LABEL_182:
  _ReadStatusReg(SP_EL0);
  return v117;
}
