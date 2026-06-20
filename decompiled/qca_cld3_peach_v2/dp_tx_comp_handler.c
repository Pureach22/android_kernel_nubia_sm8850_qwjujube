__int64 __fastcall dp_tx_comp_handler(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned int a5)
{
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w22
  unsigned int v16; // w20
  __int64 v17; // x24
  __int64 v18; // x23
  unsigned int v19; // w8
  unsigned int v20; // w9
  unsigned int v21; // w11
  unsigned int v22; // w10
  unsigned int v23; // w11
  unsigned int v25; // w8
  int v26; // w8
  int v27; // w23
  int v28; // w22
  int v29; // w28
  __int64 v30; // x25
  char v31; // w12
  __int64 v32; // x10
  __int64 v33; // x26
  unsigned int v34; // w9
  __int64 v36; // x0
  __int64 v37; // x9
  unsigned __int64 v38; // x13
  __int64 v39; // x10
  __int64 v40; // x9
  __int64 v41; // x1
  unsigned int *v46; // x25
  __int64 (__fastcall *v47)(_QWORD); // x8
  unsigned __int8 v48; // w27
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v57; // w26
  void (__fastcall *v58)(__int64, unsigned int *, __int64 *); // x8
  __int64 v59; // x1
  char v60; // w8
  int v61; // w4
  __int64 v62; // x8
  __int64 v63; // x27
  __int64 (__fastcall *v64)(_QWORD); // x8
  char v65; // w0
  __int64 v66; // x27
  __int64 v67; // x25
  __int64 v68; // x1
  _DWORD *v69; // x8
  __int64 v70; // x0
  __int64 v71; // x9
  _QWORD *v72; // x8
  _QWORD *v73; // x8
  __int64 v74; // x9
  __int64 v75; // x0
  __int64 v76; // x25
  __int64 v77; // x0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x8
  __int64 v87; // x0
  int v88; // w1
  int v89; // w9
  __int64 v90; // x8
  __int64 v91; // x22
  __int64 v92; // x8
  unsigned int v93; // w9
  unsigned int v94; // w8
  unsigned int v95; // w22
  __int64 v96; // x8
  unsigned int v97; // w23
  int v98; // w8
  unsigned int v101; // w10
  __int64 v102; // x8
  _DWORD *v103; // x8
  unsigned int v105; // [xsp+Ch] [xbp-94h]
  unsigned __int64 StatusReg; // [xsp+10h] [xbp-90h]
  unsigned int v107; // [xsp+28h] [xbp-78h]
  __int64 v111; // [xsp+40h] [xbp-60h]
  __int64 v112; // [xsp+48h] [xbp-58h]
  int v113; // [xsp+54h] [xbp-4Ch]
  __int64 v114; // [xsp+58h] [xbp-48h]
  int v115; // [xsp+64h] [xbp-3Ch]
  __int64 v116; // [xsp+68h] [xbp-38h]
  unsigned int v117; // [xsp+74h] [xbp-2Ch]
  __int64 v118; // [xsp+78h] [xbp-28h] BYREF
  _QWORD v119[2]; // [xsp+80h] [xbp-20h] BYREF
  int v120; // [xsp+90h] [xbp-10h]
  __int64 v121; // [xsp+98h] [xbp-8h]

  v121 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v118 = 0;
  if ( (unsigned __int8)a4 >= 6u )
    goto LABEL_204;
  v107 = *(_DWORD *)(a3 + 32);
  v114 = *(_QWORD *)(a2 + 1128);
  v113 = *(_DWORD *)(*(_QWORD *)(a2 + 40) + 672LL);
  if ( (unsigned int)dp_srng_access_start(a1, a2, (char *)a3) )
  {
LABEL_175:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: HAL RING Access Failed -- %pK",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_tx_comp_handler",
      a3);
    v16 = 0;
    goto LABEL_203;
  }
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v115 = 0;
  v117 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 2 )
  {
    v19 = *(_DWORD *)(a3 + 120);
    v20 = *(_DWORD *)(a3 + 136);
    v21 = v20 - v19;
    if ( *(_DWORD *)(a3 + 116) )
    {
      if ( v20 < v19 )
        v21 += *(_DWORD *)(a3 + 36);
      v22 = *(_DWORD *)(a3 + 44);
      v23 = v21 / v22;
    }
    else
    {
      if ( v20 <= v19 )
        v21 += *(_DWORD *)(a3 + 36);
      v22 = *(_DWORD *)(a3 + 44);
      v23 = v21 / v22 - 1;
    }
    if ( v23 > *(_DWORD *)(a3 + 240) )
    {
      *(_DWORD *)(a3 + 240) = v23;
      *(_QWORD *)(a3 + 248) = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
    }
    if ( v23 >= *(_DWORD *)(a3 + 276) )
    {
      ++*(_DWORD *)(a3 + 300);
      if ( v15 )
        goto LABEL_32;
    }
    else if ( v23 >= *(_DWORD *)(a3 + 272) )
    {
      ++*(_DWORD *)(a3 + 296);
      if ( v15 )
        goto LABEL_32;
    }
    else if ( v23 >= *(_DWORD *)(a3 + 268) )
    {
      ++*(_DWORD *)(a3 + 292);
      if ( v15 )
        goto LABEL_32;
    }
    else if ( v23 >= *(_DWORD *)(a3 + 264) )
    {
      ++*(_DWORD *)(a3 + 288);
      if ( v15 )
        goto LABEL_32;
    }
    else if ( v23 >= *(_DWORD *)(a3 + 260) )
    {
      ++*(_DWORD *)(a3 + 284);
      if ( v15 )
        goto LABEL_32;
    }
    else
    {
      ++*(_DWORD *)(a3 + 280);
      if ( v15 )
        goto LABEL_32;
    }
    _CF = v20 >= v19;
    v25 = v20 - v19;
    if ( !_CF )
      v25 += *(_DWORD *)(a3 + 36);
    v15 = v25 / v22;
LABEL_32:
    v26 = a5;
    v116 = v18;
    v27 = 0;
    v111 = 0;
    v112 = 0;
    if ( v15 < a5 )
      v26 = v15;
    if ( v113 <= 1 )
      v28 = 1;
    else
      v28 = v113;
    v105 = v16 + v28;
LABEL_39:
    if ( !v26 )
      goto LABEL_124;
    v29 = 1 - v26;
    while ( 1 )
    {
      v30 = *(unsigned int *)(a3 + 120);
      if ( (_DWORD)v30 == *(_DWORD *)(a3 + 136) )
        goto LABEL_124;
      v31 = *(_BYTE *)(a3 + 78);
      v32 = *(_QWORD *)(a2 + 1128);
      v33 = *(_QWORD *)(a3 + 16);
      if ( *(_DWORD *)(a3 + 44) + (_DWORD)v30 == *(_DWORD *)(a3 + 36) )
        v34 = 0;
      else
        v34 = *(_DWORD *)(a3 + 44) + v30;
      *(_DWORD *)(a3 + 120) = v34;
      if ( (v31 & 4) != 0 )
      {
        _X27 = v33 + 4LL * v34;
        v36 = *(_QWORD *)(*(_QWORD *)(v32 + 8) + 40LL);
        if ( (*(_BYTE *)(v36 + 844) & 0x40) == 0 )
        {
          v37 = _X27 << 8 >> 8;
          v38 = (unsigned __int64)(v37 + 0x8000000000LL) >> 38;
          v39 = memstart_addr + v37 + 0x8000000000LL;
          v40 = v37 - kimage_voffset;
          if ( v38 )
            v41 = v40;
          else
            v41 = v39;
          _dma_sync_single_for_cpu(v36, v41);
        }
        __asm { PRFM            #0, [X27] }
      }
      v46 = (unsigned int *)(v33 + 4 * v30);
      if ( !v46 )
        goto LABEL_124;
      v47 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v114 + 74392) + 192LL);
      if ( *((_DWORD *)v47 - 1) != -1536295579 )
        __break(0x8228u);
      v48 = v47(v46);
      v57 = v48;
      if ( v48 && v48 != 3 )
      {
        v63 = jiffies;
        if ( dp_tx_comp_handler___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Tx comp release_src != TQM | FW but from %d",
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            "dp_tx_comp_handler",
            v57);
          dp_tx_comp_handler___last_ticks = v63;
        }
        hal_dump_comp_desc(v46);
        if ( a2 )
          ++*(_DWORD *)(a2 + 13548);
        v64 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v114 + 74392) + 168LL);
        if ( *((_DWORD *)v64 - 1) != -2091637267 )
          __break(0x8228u);
        v65 = v64(v46);
        v66 = jiffies;
        if ( v65 )
        {
          if ( dp_tx_comp_handler___last_ticks_53 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: Tx comp wbm_internal_error!!",
              v7,
              v8,
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              "dp_tx_comp_handler");
            dp_tx_comp_handler___last_ticks_53 = v66;
          }
          if ( a2 )
            ++*(_DWORD *)(a2 + 13556);
          if ( v57 == 2 )
            dp_handle_wbm_internal_error(a2, v46, (v46[2] >> 6) & 7);
        }
        else
        {
          if ( dp_tx_comp_handler___last_ticks_55 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: Tx comp wbm_internal_error false",
              v7,
              v8,
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              "dp_tx_comp_handler");
            dp_tx_comp_handler___last_ticks_55 = v66;
          }
          if ( a2 )
            ++*(_DWORD *)(a2 + 13576);
        }
        goto LABEL_90;
      }
      v58 = *(void (__fastcall **)(__int64, unsigned int *, __int64 *))(a2 + 1304);
      if ( *((_DWORD *)v58 - 1) != -1415423885 )
        __break(0x8228u);
      v58(a2, v46, &v118);
      v59 = v118;
      if ( !v118 )
        break;
      v60 = *(_BYTE *)(v118 + 64) & 0xE3 | (4 * (v48 & 7));
      *(_BYTE *)(v118 + 64) = v60;
      if ( v48 == 3 )
      {
        v120 = 0;
        v119[0] = 0;
        v119[1] = 0;
        qdf_mem_copy(v119, v46 + 2, 0x14u);
        qdf_mem_copy((void *)(v118 + 104), v46, 0x20u);
        v68 = v118;
        if ( !*(_QWORD *)(v118 + 56) )
        {
          dp_tx_dump_tx_desc_0(v118);
          v68 = v118;
        }
        v69 = *(_DWORD **)(a2 + 1328);
        if ( *(v69 - 1) != 2110698444 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD *, __int64))v69)(a2, v68, v119, a4);
        ++v27;
        if ( a2 )
          goto LABEL_117;
        goto LABEL_38;
      }
      v61 = *(_DWORD *)(v59 + 32);
      *(_BYTE *)(v59 + 49) = (v46[2] >> 13) & 0xF;
      if ( (v61 & 0x30000) != 0 )
        goto LABEL_104;
      *(_BYTE *)(v59 + 64) = v60;
      if ( (v61 & 4) != 0 )
        goto LABEL_102;
      if ( !v61 && *(unsigned __int8 *)(v59 + 48) == 255 )
      {
        v67 = jiffies;
        if ( dp_tx_comp_handler___last_ticks_58 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x87u,
            5u,
            "%s: Descriptor freed in vdev_detach %d",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "dp_tx_comp_handler",
            *(unsigned int *)(v59 + 36));
          dp_tx_comp_handler___last_ticks_58 = v67;
        }
        if ( a2 )
          ++*(_DWORD *)(a2 + 13588);
        dp_tx_desc_check_corruption(v118, v7, v8, v9, v10, v11, v12, v13, v14);
        goto LABEL_90;
      }
      v62 = *(_QWORD *)(v59 + 56);
      if ( v62 )
      {
        if ( *(_BYTE *)(v62 + 16) == 1 )
        {
          v76 = jiffies;
          if ( dp_tx_comp_handler___last_ticks_61 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x87u,
              5u,
              "%s: pdev in down state %d",
              v7,
              v8,
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              "dp_tx_comp_handler",
              *(unsigned int *)(v59 + 36));
            v59 = v118;
            dp_tx_comp_handler___last_ticks_61 = v76;
            v61 = *(_DWORD *)(v118 + 32);
          }
          *(_DWORD *)(v59 + 32) = v61 | 0x1000;
          v77 = dp_tx_comp_free_buf(a2, v59, 0, v7, v8, v9, v10, v11, v12, v13, v14);
          dp_tx_desc_release(v77, v118, *(unsigned __int8 *)(v118 + 67));
          ++v27;
          if ( a2 )
            goto LABEL_117;
        }
        else
        {
          if ( (~v61 & 0x220) != 0 )
          {
            qdf_trace_msg(
              0x87u,
              1u,
              "%s: Txdesc invalid, flgs = %x,id = %d",
              v7,
              v8,
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              "dp_tx_comp_handler");
            v75 = printk(
                    &unk_AAA255,
                    "0",
                    "dp_tx_comp_handler",
                    "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_tx.c");
            dump_stack(v75);
            v59 = v118;
          }
          qdf_mem_copy((void *)(v59 + 104), v46, 0x20u);
          v59 = v118;
LABEL_102:
          if ( **(unsigned __int8 **)(v59 + 56) > 1u )
            goto LABEL_204;
          v61 = *(_DWORD *)(v59 + 32);
          ++v117;
LABEL_104:
          if ( (v61 & 0x30000) != 0 )
          {
            v70 = *(_QWORD *)(v59 + 8);
            if ( v70 )
            {
              _qdf_nbuf_free(v70);
              v59 = v118;
            }
            v71 = v116;
            if ( v116 )
              v72 = (_QWORD *)v17;
            else
              v72 = (_QWORD *)v59;
            if ( !v116 )
              v71 = v59;
            *v72 = v59;
            v17 = v118;
            v116 = v71;
            *(_BYTE *)(v118 + 48) = -1;
            *(_DWORD *)(v17 + 32) = 0;
            *(_QWORD *)v17 = 0;
            *(_QWORD *)(v17 + 8) = 0;
            ++v115;
            ++v27;
            if ( !a2 )
              goto LABEL_38;
LABEL_117:
            if ( v27 >= v113 )
              ++*(_DWORD *)(a2 + 13580);
            goto LABEL_38;
          }
          v73 = (_QWORD *)v111;
          v74 = v112;
          if ( !v112 )
          {
            v73 = (_QWORD *)v59;
            v74 = v59;
          }
          *v73 = v59;
          *(_QWORD *)v118 = 0;
          v111 = v118;
          v112 = v74;
          ++v27;
          if ( a2 )
            goto LABEL_117;
        }
LABEL_38:
        ++v16;
        v26 = -v29;
        if ( v27 == v28 )
        {
          v16 = v105;
          v27 = v28;
          goto LABEL_124;
        }
        goto LABEL_39;
      }
      qdf_trace_msg(
        0x87u,
        3u,
        "%s: The pdev is NULL in TX desc, ignored.",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "dp_tx_comp_handler");
      dp_tx_dump_tx_desc_0(v118);
      if ( a2 )
        ++*(_DWORD *)(a2 + 13588);
LABEL_90:
      if ( ++v29 == 1 )
        goto LABEL_124;
    }
    v98 = *(_DWORD *)(a3 + 120);
    if ( !v98 )
      v98 = *(_DWORD *)(a3 + 36);
    *(_DWORD *)(a3 + 120) = v98 - *(_DWORD *)(a3 + 44);
LABEL_124:
    dp_srng_access_end(a1, a2, (char *)a3, v7, v8, v9, v10, v11, v12, v13, v14);
    if ( v112 )
      dp_tx_comp_process_desc_list(a2, v112, a4, v78, v79, v80, v81, v82, v83, v84, v85);
    if ( a2 )
    {
      if ( (unsigned __int8)a4 != 5 )
      {
        *(_DWORD *)(a2 + 13600 + 4LL * (unsigned __int8)a4) += v27;
        goto LABEL_129;
      }
LABEL_204:
      __break(0x5512u);
    }
LABEL_129:
    if ( v116 )
    {
      if ( *(unsigned __int8 *)(v116 + 67) >= 7u )
        goto LABEL_204;
      v86 = *(_QWORD *)(v116 + 56) + 94208LL;
      _X9 = (unsigned int *)(*(_QWORD *)(v116 + 56) + 94396LL);
      __asm { PRFM            #0x11, [X9] }
      do
        v101 = __ldxr(_X9);
      while ( __stxr(v101 - v115, _X9) );
      v87 = *(unsigned int *)(v86 + 188);
      v88 = *(_DWORD *)(v86 + 192);
      if ( v88 < (int)v87 )
      {
        v88 = *(_DWORD *)(v86 + 188);
        *(_DWORD *)(v86 + 192) = v87;
      }
      qdf_mem_tx_desc_cnt_update(v87, v88);
    }
    if ( *(_BYTE *)(*(_QWORD *)(a2 + 40) + 685LL) != 1 || v16 >= a5 )
      goto LABEL_177;
    if ( !a3 )
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Error: Invalid hal_ring\n",
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        "hal_srng_dst_peek_sync_locked");
      goto LABEL_177;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a3 + 80);
    }
    else
    {
      raw_spin_lock_bh(a3 + 80);
      *(_QWORD *)(a3 + 88) |= 1uLL;
    }
    v89 = **(_DWORD **)(a3 + 128);
    v90 = *(unsigned int *)(a3 + 120);
    *(_DWORD *)(a3 + 136) = v89;
    if ( (_DWORD)v90 == v89 )
      v91 = 0;
    else
      v91 = *(_QWORD *)(a3 + 16) + 4 * v90;
    v92 = *(_QWORD *)(a3 + 88);
    if ( (v92 & 1) != 0 )
    {
      *(_QWORD *)(a3 + 88) = v92 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a3 + 80);
      if ( !v91 )
        goto LABEL_177;
LABEL_147:
      if ( a2 )
        ++*(_DWORD *)(a2 + 13584);
      if ( (((__int64 (__fastcall *)(_QWORD, _QWORD))hif_exec_should_yield)(
              *(_QWORD *)(a2 + 64),
              *(unsigned __int8 *)(a1 + 32))
          & 1) != 0 )
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a3 + 80);
        }
        else
        {
          raw_spin_lock_bh(a3 + 80);
          *(_QWORD *)(a3 + 88) |= 1uLL;
        }
        v93 = *(_DWORD *)(a3 + 120);
        v94 = **(_DWORD **)(a3 + 128);
        v95 = v94 - v93;
        *(_DWORD *)(a3 + 136) = v94;
        if ( v94 < v93 )
          v95 += *(_DWORD *)(a3 + 36);
        v96 = *(_QWORD *)(a3 + 88);
        v97 = *(_DWORD *)(a3 + 44);
        if ( (v96 & 1) != 0 )
        {
          *(_QWORD *)(a3 + 88) = v96 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a3 + 80);
          if ( !v107 )
            goto LABEL_177;
        }
        else
        {
          raw_spin_unlock(a3 + 80);
          if ( !v107 )
            goto LABEL_177;
        }
        v15 = v95 / v97;
        if ( v15 < v107 >> 1 )
          goto LABEL_177;
        if ( a2 )
          ++*(_DWORD *)(a2 + 13624);
      }
      else
      {
        v15 = 0;
      }
      v18 = v116;
      v114 = *(_QWORD *)(a2 + 1128);
      v113 = *(_DWORD *)(*(_QWORD *)(a2 + 40) + 672LL);
      if ( (unsigned int)dp_srng_access_start(a1, a2, (char *)a3) )
        goto LABEL_175;
      continue;
    }
    break;
  }
  raw_spin_unlock(a3 + 80);
  if ( v91 )
    goto LABEL_147;
LABEL_177:
  if ( *(_BYTE *)(a2 + 1120) )
  {
    if ( v117 )
    {
      if ( v117 == 1 )
      {
        v102 = *(_QWORD *)(a2 + 72);
        if ( v102 )
          ++*(_DWORD *)(v102 + 7528);
      }
      else
      {
        v103 = *(_DWORD **)(a2 + 72);
        if ( v117 > 0x14 )
        {
          if ( v117 > 0x28 )
          {
            if ( v117 > 0x3C )
            {
              if ( v117 > 0x50 )
              {
                if ( v117 > 0x64 )
                {
                  if ( v117 > 0xC8 )
                  {
                    if ( v103 )
                      ++v103[1889];
                  }
                  else if ( v103 )
                  {
                    ++v103[1888];
                  }
                }
                else if ( v103 )
                {
                  ++v103[1887];
                }
              }
              else if ( v103 )
              {
                ++v103[1886];
              }
            }
            else if ( v103 )
            {
              ++v103[1885];
            }
          }
          else if ( v103 )
          {
            ++v103[1884];
          }
        }
        else if ( v103 )
        {
          ++v103[1883];
        }
      }
    }
    if ( *(unsigned __int8 *)(a2 + 1120) > 1u )
      goto LABEL_204;
  }
LABEL_203:
  _ReadStatusReg(SP_EL0);
  return v16;
}
