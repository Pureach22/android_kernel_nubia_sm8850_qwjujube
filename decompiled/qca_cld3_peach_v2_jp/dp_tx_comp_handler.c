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
  __int64 v88; // x8
  __int64 v89; // x0
  int v90; // w1
  int v91; // w9
  __int64 v92; // x8
  __int64 v93; // x22
  __int64 v94; // x8
  unsigned int v95; // w9
  unsigned int v96; // w8
  unsigned int v97; // w22
  __int64 v98; // x8
  unsigned int v99; // w23
  int v100; // w8
  unsigned int v102; // w10
  __int64 v103; // x8
  _DWORD *v104; // x8
  unsigned int v106; // [xsp+Ch] [xbp-94h]
  unsigned __int64 StatusReg; // [xsp+10h] [xbp-90h]
  unsigned int v108; // [xsp+28h] [xbp-78h]
  __int64 v112; // [xsp+40h] [xbp-60h]
  __int64 v113; // [xsp+48h] [xbp-58h]
  int v114; // [xsp+54h] [xbp-4Ch]
  __int64 v115; // [xsp+58h] [xbp-48h]
  int v116; // [xsp+64h] [xbp-3Ch]
  __int64 v117; // [xsp+68h] [xbp-38h]
  unsigned int v118; // [xsp+74h] [xbp-2Ch]
  __int64 v119; // [xsp+78h] [xbp-28h] BYREF
  _QWORD v120[2]; // [xsp+80h] [xbp-20h] BYREF
  int v121; // [xsp+90h] [xbp-10h]
  __int64 v122; // [xsp+98h] [xbp-8h]

  v122 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v119 = 0;
  if ( (unsigned __int8)a4 >= 6u )
    goto LABEL_204;
  v108 = *(_DWORD *)(a3 + 32);
  v115 = *(_QWORD *)(a2 + 1128);
  v114 = *(_DWORD *)(*(_QWORD *)(a2 + 40) + 672LL);
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
  v116 = 0;
  v118 = 0;
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
    v117 = v18;
    v27 = 0;
    v112 = 0;
    v113 = 0;
    if ( v15 < a5 )
      v26 = v15;
    if ( v114 <= 1 )
      v28 = 1;
    else
      v28 = v114;
    v106 = v16 + v28;
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
      v47 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v115 + 74392) + 192LL);
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
          ++*(_DWORD *)(a2 + 13492);
        v64 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v115 + 74392) + 168LL);
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
            ++*(_DWORD *)(a2 + 13500);
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
            ++*(_DWORD *)(a2 + 13520);
        }
        goto LABEL_90;
      }
      v58 = *(void (__fastcall **)(__int64, unsigned int *, __int64 *))(a2 + 1304);
      if ( *((_DWORD *)v58 - 1) != -1415423885 )
        __break(0x8228u);
      v58(a2, v46, &v119);
      v59 = v119;
      if ( !v119 )
        break;
      v60 = *(_BYTE *)(v119 + 64) & 0xE3 | (4 * (v48 & 7));
      *(_BYTE *)(v119 + 64) = v60;
      if ( v48 == 3 )
      {
        v121 = 0;
        v120[0] = 0;
        v120[1] = 0;
        qdf_mem_copy(v120, v46 + 2, 0x14u);
        qdf_mem_copy((void *)(v119 + 104), v46, 0x20u);
        v68 = v119;
        if ( !*(_QWORD *)(v119 + 56) )
        {
          dp_tx_dump_tx_desc_0(v119);
          v68 = v119;
        }
        v69 = *(_DWORD **)(a2 + 1328);
        if ( *(v69 - 1) != 2110698444 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD *, __int64))v69)(a2, v68, v120, a4);
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
          ++*(_DWORD *)(a2 + 13532);
        dp_tx_desc_check_corruption(v119, v7, v8, v9, v10, v11, v12, v13, v14);
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
            v59 = v119;
            dp_tx_comp_handler___last_ticks_61 = v76;
            v61 = *(_DWORD *)(v119 + 32);
          }
          *(_DWORD *)(v59 + 32) = v61 | 0x1000;
          v77 = dp_tx_comp_free_buf(a2, v59, 0, v7, v8, v9, v10, v11, v12, v13, v14);
          dp_tx_desc_release(v77, v119, *(unsigned __int8 *)(v119 + 67));
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
                    &unk_9BB309,
                    "0",
                    "dp_tx_comp_handler",
                    "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_tx.c");
            dump_stack(v75);
            v59 = v119;
          }
          qdf_mem_copy((void *)(v59 + 104), v46, 0x20u);
          v59 = v119;
LABEL_102:
          if ( **(unsigned __int8 **)(v59 + 56) > 1u )
            goto LABEL_204;
          v61 = *(_DWORD *)(v59 + 32);
          ++v118;
LABEL_104:
          if ( (v61 & 0x30000) != 0 )
          {
            v70 = *(_QWORD *)(v59 + 8);
            if ( v70 )
            {
              _qdf_nbuf_free(v70);
              v59 = v119;
            }
            v71 = v117;
            if ( v117 )
              v72 = (_QWORD *)v17;
            else
              v72 = (_QWORD *)v59;
            if ( !v117 )
              v71 = v59;
            *v72 = v59;
            v17 = v119;
            v117 = v71;
            *(_BYTE *)(v119 + 48) = -1;
            *(_DWORD *)(v17 + 32) = 0;
            *(_QWORD *)v17 = 0;
            *(_QWORD *)(v17 + 8) = 0;
            ++v116;
            ++v27;
            if ( !a2 )
              goto LABEL_38;
LABEL_117:
            if ( v27 >= v114 )
              ++*(_DWORD *)(a2 + 13524);
            goto LABEL_38;
          }
          v73 = (_QWORD *)v112;
          v74 = v113;
          if ( !v113 )
          {
            v73 = (_QWORD *)v59;
            v74 = v59;
          }
          *v73 = v59;
          *(_QWORD *)v119 = 0;
          v112 = v119;
          v113 = v74;
          ++v27;
          if ( a2 )
            goto LABEL_117;
        }
LABEL_38:
        ++v16;
        v26 = -v29;
        if ( v27 == v28 )
        {
          v16 = v106;
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
      dp_tx_dump_tx_desc_0(v119);
      if ( a2 )
        ++*(_DWORD *)(a2 + 13532);
LABEL_90:
      if ( ++v29 == 1 )
        goto LABEL_124;
    }
    v100 = *(_DWORD *)(a3 + 120);
    if ( !v100 )
      v100 = *(_DWORD *)(a3 + 36);
    *(_DWORD *)(a3 + 120) = v100 - *(_DWORD *)(a3 + 44);
LABEL_124:
    dp_srng_access_end(a1, a2, (char *)a3, v7, v8, v9, v10, v11, v12, v13, v14);
    if ( v113 )
      dp_tx_comp_process_desc_list(a2, v113, a4, v78, v79, v80, v81, v82, v83, v84, v85);
    if ( a2 )
    {
      if ( (unsigned __int8)a4 != 5 )
      {
        *(_DWORD *)(a2 + 13544 + 4LL * (unsigned __int8)a4) += v27;
        goto LABEL_129;
      }
LABEL_204:
      __break(0x5512u);
    }
LABEL_129:
    if ( v117 )
    {
      if ( *(unsigned __int8 *)(v117 + 67) >= 7u )
        goto LABEL_204;
      v86 = *(_QWORD *)(v117 + 56);
      _X9 = (unsigned int *)(v86 + 93500);
      __asm { PRFM            #0x11, [X9] }
      do
        v102 = __ldxr(_X9);
      while ( __stxr(v102 - v116, _X9) );
      v88 = v86 + 90112;
      v89 = *(unsigned int *)(v88 + 3388);
      v90 = *(_DWORD *)(v88 + 3392);
      if ( v90 < (int)v89 )
      {
        v90 = *(_DWORD *)(v88 + 3388);
        *(_DWORD *)(v88 + 3392) = v89;
      }
      qdf_mem_tx_desc_cnt_update(v89, v90);
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
    v91 = **(_DWORD **)(a3 + 128);
    v92 = *(unsigned int *)(a3 + 120);
    *(_DWORD *)(a3 + 136) = v91;
    if ( (_DWORD)v92 == v91 )
      v93 = 0;
    else
      v93 = *(_QWORD *)(a3 + 16) + 4 * v92;
    v94 = *(_QWORD *)(a3 + 88);
    if ( (v94 & 1) != 0 )
    {
      *(_QWORD *)(a3 + 88) = v94 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a3 + 80);
      if ( !v93 )
        goto LABEL_177;
LABEL_147:
      if ( a2 )
        ++*(_DWORD *)(a2 + 13528);
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
        v95 = *(_DWORD *)(a3 + 120);
        v96 = **(_DWORD **)(a3 + 128);
        v97 = v96 - v95;
        *(_DWORD *)(a3 + 136) = v96;
        if ( v96 < v95 )
          v97 += *(_DWORD *)(a3 + 36);
        v98 = *(_QWORD *)(a3 + 88);
        v99 = *(_DWORD *)(a3 + 44);
        if ( (v98 & 1) != 0 )
        {
          *(_QWORD *)(a3 + 88) = v98 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a3 + 80);
          if ( !v108 )
            goto LABEL_177;
        }
        else
        {
          raw_spin_unlock(a3 + 80);
          if ( !v108 )
            goto LABEL_177;
        }
        v15 = v97 / v99;
        if ( v15 < v108 >> 1 )
          goto LABEL_177;
        if ( a2 )
          ++*(_DWORD *)(a2 + 13568);
      }
      else
      {
        v15 = 0;
      }
      v18 = v117;
      v115 = *(_QWORD *)(a2 + 1128);
      v114 = *(_DWORD *)(*(_QWORD *)(a2 + 40) + 672LL);
      if ( (unsigned int)dp_srng_access_start(a1, a2, (char *)a3) )
        goto LABEL_175;
      continue;
    }
    break;
  }
  raw_spin_unlock(a3 + 80);
  if ( v93 )
    goto LABEL_147;
LABEL_177:
  if ( *(_BYTE *)(a2 + 1120) )
  {
    if ( v118 )
    {
      if ( v118 == 1 )
      {
        v103 = *(_QWORD *)(a2 + 72);
        if ( v103 )
          ++*(_DWORD *)(v103 + 6712);
      }
      else
      {
        v104 = *(_DWORD **)(a2 + 72);
        if ( v118 > 0x14 )
        {
          if ( v118 > 0x28 )
          {
            if ( v118 > 0x3C )
            {
              if ( v118 > 0x50 )
              {
                if ( v118 > 0x64 )
                {
                  if ( v118 > 0xC8 )
                  {
                    if ( v104 )
                      ++v104[1685];
                  }
                  else if ( v104 )
                  {
                    ++v104[1684];
                  }
                }
                else if ( v104 )
                {
                  ++v104[1683];
                }
              }
              else if ( v104 )
              {
                ++v104[1682];
              }
            }
            else if ( v104 )
            {
              ++v104[1681];
            }
          }
          else if ( v104 )
          {
            ++v104[1680];
          }
        }
        else if ( v104 )
        {
          ++v104[1679];
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
