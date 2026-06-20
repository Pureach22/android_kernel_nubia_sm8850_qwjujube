__int64 *__fastcall dp_tx_send_msdu_single(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
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
  __int64 *v13; // x21
  __int64 v14; // x23
  __int64 v15; // x24
  __int64 v16; // x26
  __int64 *v18; // x22
  unsigned __int64 v20; // x8
  __int64 v21; // x28
  unsigned int v22; // w27
  __int64 v24; // x0
  __int64 v25; // x0
  int v26; // w1
  int v27; // w8
  __int64 v28; // x2
  char v29; // w8
  __int64 v30; // x0
  int v31; // w8
  __int64 v32; // x8
  __int16 v33; // w27
  __int64 v34; // x9
  __int64 v35; // x1
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x8
  void *v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int v54; // w10
  int v55; // w9
  __int64 v57; // x9
  __int64 v58; // x27
  _QWORD *v59; // x25
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned __int64 StatusReg; // x8
  char is_pp_nbuf; // w0
  __int64 v70; // x9
  __int64 v71; // x8
  int v72; // w8
  unsigned int v73; // w22
  __int64 v74; // x0
  __int64 v75; // x8
  _DWORD *v76; // x8
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x24
  __int64 v86; // x24
  __int64 v87; // x27
  __int64 v88; // x22
  __int64 v89; // x23
  __int64 v90; // x25
  __int64 v91; // x0
  __int64 v92; // x24
  __int64 v93; // x26
  __int64 v94; // x0
  unsigned __int64 v95; // x0
  __int64 dma_addr; // x0
  __int64 v97; // x9
  __int64 v98; // x0
  __int64 v99; // x8
  int v101; // w0
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  unsigned int v116; // w10
  unsigned int v118; // w9
  __int64 v119; // [xsp+8h] [xbp-28h]
  int v120; // [xsp+14h] [xbp-1Ch]
  __int64 v121; // [xsp+18h] [xbp-18h]
  unsigned int v122; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v123; // [xsp+28h] [xbp-8h]

  v18 = (__int64 *)a2;
  v123 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = *(unsigned __int16 *)(a2 + 180);
  v21 = *(_QWORD *)(a1 + 24);
  v22 = *(unsigned __int8 *)(a3 + 94);
  v121 = *(unsigned __int8 *)(a3 + 12);
  if ( (_DWORD)v20 == 34958
    || (v14 = *(_QWORD *)(v21 + 8),
        v16 = *(unsigned __int8 *)(a3 + 4),
        v15 = a5,
        (v24 = dp_tx_desc_alloc(v14, v16, a2)) == 0) )
  {
    if ( a1 )
    {
      if ( v22 )
        goto LABEL_138;
      v97 = *(_QWORD *)(a1 + 704) + 1LL;
      ++*(_QWORD *)(a1 + 688);
      *(_QWORD *)(a1 + 704) = v97;
    }
    goto LABEL_85;
  }
  v13 = (__int64 *)v24;
  _X9 = (unsigned int *)(v21 + 94396);
  __asm { PRFM            #0x11, [X9] }
  do
    v116 = __ldxr(_X9);
  while ( __stxr(v116 + 1, _X9) );
  LODWORD(v119) = v22;
  v120 = a4;
  v25 = *(unsigned int *)(v21 + 94396);
  v26 = *(_DWORD *)(v21 + 94400);
  if ( v26 < (int)v25 )
  {
    v26 = *(_DWORD *)(v21 + 94396);
    *(_DWORD *)(v21 + 94400) = v25;
  }
  qdf_mem_tx_desc_cnt_update(v25, v26);
  v13[1] = (__int64)v18;
  *((_BYTE *)v13 + 65) = 0;
  if ( !v15 || (v27 = *(unsigned __int16 *)(v15 + 4), v27 == 6) )
    v27 = *(_DWORD *)(a1 + 40);
  v28 = *((unsigned int *)v13 + 9);
  *((_BYTE *)v13 + 64) = v13[8] & 0xFC | v27 & 3;
  v29 = *(_BYTE *)(a1 + 59);
  v13[7] = v21;
  v13[9] = 0;
  *((_BYTE *)v13 + 48) = v29;
  *((_BYTE *)v13 + 66) = 0;
  *((_WORD *)v13 + 8) = *((_WORD *)v18 + 56) - *((_DWORD *)v18 + 29);
  v30 = dp_tx_trace_pkt(v14, v18, v28, *(unsigned __int8 *)(a1 + 59), *(unsigned int *)(a1 + 46172));
  if ( *(_BYTE *)(a1 + 80) == 1 )
  {
    v30 = dp_tx_multipass_process(v14, a1, v18, a3);
    if ( (v30 & 1) == 0 )
    {
      v20 = v22;
      if ( a1 )
      {
        if ( v22 )
          goto LABEL_138;
        ++*(_DWORD *)(a1 + 800);
      }
      goto LABEL_84;
    }
  }
  if ( *(_BYTE *)(a3 + 13)
    || *(_DWORD *)(a1 + 32) == 5
    || (v31 = (*(unsigned __int16 *)((char *)v18 + 69) >> 11) & 1, v15) && (*(_BYTE *)(v15 + 12) & 1) != 0 )
  {
    v32 = v18[28];
    v33 = v32 & 7;
    if ( ((unsigned __int8)v32 & 7u) > (int)v32 - *((_DWORD *)v18 + 54) )
    {
      v20 = (unsigned int)v119;
      if ( a1 )
      {
        if ( (_DWORD)v119 )
          goto LABEL_138;
        ++*(_DWORD *)(a1 + 768);
      }
      goto LABEL_84;
    }
    v34 = v18[5];
    v35 = v32 & 7;
    if ( v34 )
      v18[5] = v34 - v35;
    if ( !skb_push(v18, v35) )
    {
      v30 = qdf_trace_msg(
              0x7Du,
              2u,
              "%s: qdf_nbuf_push_head failed",
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              "dp_tx_prepare_desc_single");
      v20 = (unsigned int)v119;
      if ( a1 )
      {
        if ( (_DWORD)v119 )
          goto LABEL_138;
        ++*(_DWORD *)(a1 + 792);
      }
      goto LABEL_84;
    }
    if ( *(_DWORD *)(a1 + 64) || *(_BYTE *)(a3 + 14) || (*(_BYTE *)(a3 + 57) & 2) != 0 || *(_BYTE *)(a3 + 13) )
    {
      if ( (unsigned int)(*((_DWORD *)v18 + 56) - *((_DWORD *)v18 + 54)) <= 0x27 )
      {
        v101 = pskb_expand_head(v18, 40, 0, 2080);
        if ( !v18 || v101 )
        {
          v30 = qdf_trace_msg(
                  0x38u,
                  2u,
                  "%s:  %s[%d] skb_realloc_headroom failed",
                  v102,
                  v103,
                  v104,
                  v105,
                  v106,
                  v107,
                  v108,
                  v109,
                  "dp_tx_prepare_htt_metadata",
                  "dp_tx_prepare_htt_metadata",
                  745);
          v20 = (unsigned int)v119;
          if ( !a1 )
            goto LABEL_84;
          goto LABEL_82;
        }
      }
      v44 = v18[5];
      if ( v44 )
        v18[5] = v44 - 40;
      v45 = (void *)skb_push(v18, 40);
      if ( !v45 )
      {
        v30 = qdf_trace_msg(
                0x7Du,
                2u,
                "%s: Error in filling HTT metadata",
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                "dp_tx_prepare_htt_metadata");
        v20 = (unsigned int)v119;
        if ( !a1 )
        {
LABEL_84:
          dp_tx_desc_release(v30, (__int64)v13, v16);
LABEL_85:
          v13 = &dp_pdev_nbuf_alloc_and_map_replenish___last_ticks;
          v92 = jiffies;
          if ( dp_tx_send_msdu_single___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: Tx_desc prepare Fail vdev_id %d vdev %pK queue %d",
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              a12,
              a13,
              "dp_tx_send_msdu_single",
              *(unsigned __int8 *)(a1 + 59),
              a1,
              *(unsigned __int8 *)(a3 + 4));
            dp_tx_send_msdu_single___last_ticks = v92;
          }
          v15 = v121;
          v14 = 0;
          goto LABEL_128;
        }
LABEL_82:
        if ( (_DWORD)v20 )
          goto LABEL_138;
        ++*(_DWORD *)(a1 + 796);
        goto LABEL_84;
      }
      qdf_mem_copy(v45, (const void *)(a3 + 56), 0x24u);
    }
    v54 = *((_DWORD *)v13 + 8);
    v55 = *((_DWORD *)v18 + 28) - *((_DWORD *)v18 + 29);
    *((_BYTE *)v13 + 66) = v33 | 0x28;
    *((_WORD *)v13 + 8) = v55;
    *((_DWORD *)v13 + 8) = v54 | 2;
    if ( (*(_BYTE *)(a3 + 76) & 8) != 0 )
      *((_DWORD *)v13 + 8) = v54 | 0x4002;
    *((_WORD *)v13 + 8) = v55 - (v33 | 0x28);
    v31 = 1;
  }
  if ( *(_BYTE *)(a3 + 104) == 1 )
  {
    *((_DWORD *)v13 + 8) |= 0x200000u;
    if ( v15 )
      goto LABEL_33;
  }
  else if ( v15 )
  {
LABEL_33:
    *((_DWORD *)v13 + 8) |= 2u;
    _X8 = (unsigned int *)(v14 + 18756);
    __asm { PRFM            #0x11, [X8] }
    do
      v118 = __ldxr(_X8);
    while ( __stxr(v118 + 1, _X8) );
    if ( !a1 )
      goto LABEL_37;
    goto LABEL_35;
  }
  if ( v31 )
    goto LABEL_33;
  if ( !a1 )
    goto LABEL_37;
LABEL_35:
  if ( *(_BYTE *)(a1 + 329) == 1 )
  {
    *((_DWORD *)v13 + 8) |= 0x100u;
    *(_BYTE *)(a1 + 329) = 0;
  }
LABEL_37:
  v20 = *(unsigned __int8 *)(a1 + 59);
  v119 = a1 + 45056;
  if ( v20 < 6 )
  {
    v57 = *(_QWORD *)(a1 + 24);
    v122 = 0;
    v58 = *(_QWORD *)(v57 + 8);
    v59 = *(_QWORD **)(v58 + 8 * v20 + 22456);
    if ( (wlan_cfg_get_dp_tx_page_pool_enabled(*(_QWORD *)(v58 + 40)) & 1) == 0 || !v59 || *((_BYTE *)v59 + 56) != 1 )
      goto LABEL_54;
    if ( v18[2] != 51931 )
      v18[5] = 0;
    if ( (*((_BYTE *)v13 + 33) & 1) != 0 || *((_DWORD *)v18 + 29) )
      goto LABEL_54;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v59 + 5);
    }
    else
    {
      raw_spin_lock_bh(v59 + 5);
      v59[6] |= 1uLL;
    }
    if ( v18[2] == 51931 )
    {
      is_pp_nbuf = _qdf_is_pp_nbuf(v18);
      v70 = 3;
      if ( (is_pp_nbuf & 1) == 0 )
        v70 = 4;
      v71 = v59[6];
      ++v59[v70];
      if ( (v71 & 1) == 0 )
      {
LABEL_53:
        raw_spin_unlock(v59 + 5);
LABEL_54:
        v16 = (__int64)v18;
        goto LABEL_55;
      }
    }
    else
    {
      v93 = *v59;
      if ( *v59 )
      {
        if ( (_qdf_page_pool_empty(*v59) & 1) == 0 )
        {
          v94 = _qdf_nbuf_page_pool_alloc(
                  *(_QWORD *)(v58 + 24),
                  *((unsigned int *)v18 + 53),
                  0,
                  0,
                  v93,
                  &v122,
                  "dp_tx_page_pool_handle_nbuf_single",
                  235);
          if ( v94 )
          {
            v16 = v94;
            ++v59[3];
            qdf_spin_unlock_bh_10((__int64)(v59 + 5));
            qdf_mem_copy(*(void **)(v16 + 224), (const void *)v18[28], *((unsigned int *)v18 + 28));
            qdf_nbuf_set_pktlen_0(v16, *((unsigned int *)v18 + 28));
            skb_copy_header(v16, v18);
            v95 = ((unsigned __int64)(((__int64)(*(_QWORD *)(v16 + 224) << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
                - 0x140000000LL;
            v20 = *(_QWORD *)(((unsigned __int64)(((__int64)(*(_QWORD *)(v16 + 224) << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
                            - 0x13FFFFFF8LL);
            if ( (v20 & 1) == 0 )
              goto LABEL_95;
            goto LABEL_139;
          }
        }
      }
      v71 = v59[6];
      ++v59[4];
      if ( (v71 & 1) == 0 )
        goto LABEL_53;
    }
    v59[6] = v71 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v59 + 5);
    goto LABEL_54;
  }
  while ( 1 )
  {
LABEL_138:
    __break(0x5512u);
LABEL_139:
    v95 = v20 - 1;
LABEL_95:
    dma_addr = _qdf_page_pool_get_dma_addr(v95);
    *(_QWORD *)(v16 + 40) = dma_addr
                          + v122
                          + (unsigned __int64)(unsigned int)(*(_DWORD *)(v16 + 224) - *(_DWORD *)(v16 + 216));
    v13[1] = v16;
    v13[18] = (__int64)v18;
LABEL_55:
    if ( (unsigned __int16)v120 == 0xFFFF )
    {
      v72 = *(unsigned __int16 *)(a1 + 60);
    }
    else if ( (unsigned __int16)v120 == 65534 )
    {
      v72 = *(unsigned __int16 *)(a1 + 60) | 0x1000;
    }
    else
    {
      if ( (unsigned __int16)v120 >= 0x4000u )
        printk(
          &unk_94DB9D,
          "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_tx.c",
          3622,
          "!((peer_id) & ~((HTT_TX_TCL_METADATA_PEER_ID_M) >> (HTT_TX_TCL_METADATA_PEER_ID_S)))");
      v72 = 4 * v120;
    }
    if ( *(_BYTE *)(a3 + 104) )
      v72 |= 0x2000u;
    if ( *(_BYTE *)(a3 + 13) )
      v73 = v72 | 2;
    else
      v73 = v72;
    if ( *(_DWORD *)a3 == 6 )
      goto LABEL_116;
    v74 = *(_QWORD *)(a1 + 16);
    if ( (*((_BYTE *)v13 + 33) & 1) != 0 )
      break;
    if ( !(unsigned int)qdf_nbuf_map_nbytes_single(v74, v16, *(unsigned int *)(v16 + 112)) )
      goto LABEL_65;
LABEL_116:
    v18 = &dp_pdev_nbuf_alloc_and_map_replenish___last_ticks;
    v14 = jiffies;
    if ( dp_tx_send_msdu_single___last_ticks_16 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: qdf_nbuf_map failed",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "dp_tx_send_msdu_single");
      dp_tx_send_msdu_single___last_ticks_16 = v14;
    }
    v15 = v121;
    if ( !a1 )
      goto LABEL_121;
    v20 = *(unsigned __int8 *)(a3 + 94);
    if ( !*(_BYTE *)(a3 + 94) )
    {
      ++*(_DWORD *)(a1 + 760);
LABEL_121:
      v14 = 2;
      goto LABEL_122;
    }
  }
  if ( (unsigned int)_qdf_nbuf_map_single(v74, v16, 1u) )
    goto LABEL_116;
LABEL_65:
  v75 = *(_QWORD *)(v16 + 40);
  if ( !v75 )
    goto LABEL_116;
  v13[5] = v75;
  v76 = *(_DWORD **)(v14 + 1296);
  if ( *(v76 - 1) != -1196775241 )
    __break(0x8228u);
  if ( !((unsigned int (__fastcall *)(__int64, __int64, __int64 *, _QWORD, __int64, __int64))v76)(
          v14,
          a1,
          v13,
          v73,
          v15,
          a3) )
  {
    if ( *(_DWORD *)(v119 + 1120) )
    {
      v13[12] = *(_QWORD *)(a3 + 96);
      v18 = nullptr;
      v13[11] = ktime_get_with_offset(0);
    }
    else
    {
      v18 = nullptr;
    }
    goto LABEL_131;
  }
  v85 = jiffies;
  if ( dp_tx_send_msdu_single___last_ticks_18 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x7Du,
      2u,
      "%s: Tx_hw_enqueue Fail tx_desc %pK queue %d",
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      "dp_tx_send_msdu_single",
      v13,
      *(unsigned __int8 *)(a3 + 5));
    dp_tx_send_msdu_single___last_ticks_18 = v85;
  }
  v86 = v13[1];
  v87 = *(_QWORD *)(v14 + 24);
  v88 = v13[5];
  v89 = *((unsigned __int16 *)v13 + 8);
  v90 = *(int *)(v86 + 212);
  qdf_mem_dp_tx_skb_cnt_dec();
  qdf_mem_dp_tx_skb_dec(v90);
  qdf_mem_skb_total_dec(v90);
  if ( *(_BYTE *)(v87 + 624) == 1 && (_qdf_is_pp_nbuf(v86) & 1) != 0 && *(_QWORD *)(v86 + 40) )
  {
    v91 = *(_QWORD *)(v87 + 40);
    if ( (*(_BYTE *)(v91 + 844) & 0x40) == 0 )
      _dma_sync_single_for_cpu(v91, v88);
  }
  else
  {
    dma_unmap_page_attrs(*(_QWORD *)(v87 + 40), v88, v89, 1, 0);
  }
  v15 = v121;
  v14 = 3;
LABEL_122:
  v98 = _qdf_is_pp_nbuf(v16);
  if ( (v98 & 1) != 0 && v13[18] )
  {
    if ( v16 )
      v98 = _qdf_nbuf_free(v16);
    v16 = v13[18];
    v13[1] = v16;
    v13[18] = 0;
  }
  dp_tx_desc_release(v98, (__int64)v13, *(unsigned __int8 *)(a3 + 4));
  v18 = (__int64 *)v16;
LABEL_128:
  ((void (__fastcall *)(__int64, __int64 *, __int64))dp_tx_get_tid)(a1, v18, a3);
  v20 = *(unsigned __int8 *)(a3 + 5);
  if ( v20 > 4 || (unsigned int)v15 > 9 )
    goto LABEL_138;
  v99 = v21 + 6768LL * *(unsigned __int8 *)(a3 + 5) + 752LL * (unsigned int)v15 + 8 * v14;
  ++*(_QWORD *)(v99 + 9376);
LABEL_131:
  _ReadStatusReg(SP_EL0);
  return v18;
}
