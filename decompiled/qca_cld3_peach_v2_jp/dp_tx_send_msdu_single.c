char *__fastcall dp_tx_send_msdu_single(
        __int64 a1,
        unsigned __int16 *a2,
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
  _QWORD *v13; // x21
  __int64 v14; // x23
  __int64 v15; // x24
  __int64 v16; // x26
  char *v18; // x22
  unsigned __int64 v20; // x8
  __int64 v21; // x28
  unsigned int v22; // w27
  __int64 v24; // x0
  __int64 v26; // x0
  int v27; // w1
  int v28; // w8
  __int64 v29; // x2
  char v30; // w8
  __int64 v31; // x0
  int v32; // w8
  __int64 v33; // x8
  __int16 v34; // w27
  __int64 v35; // x9
  __int64 v36; // x1
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x8
  void *v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  int v55; // w10
  int v56; // w9
  __int64 v58; // x9
  __int64 v59; // x27
  _QWORD *v60; // x25
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned __int64 StatusReg; // x8
  char is_pp_nbuf; // w0
  __int64 v71; // x9
  __int64 v72; // x8
  int v73; // w8
  unsigned int v74; // w22
  __int64 v75; // x0
  __int64 v76; // x8
  _DWORD *v77; // x8
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x24
  __int64 v87; // x24
  __int64 v88; // x27
  __int64 v89; // x22
  __int64 v90; // x23
  __int64 v91; // x25
  __int64 v92; // x0
  __int64 v93; // x24
  __int64 v94; // x26
  __int64 v95; // x0
  unsigned __int64 v96; // x0
  __int64 dma_addr; // x0
  __int64 v98; // x9
  __int64 v99; // x0
  __int64 v100; // x8
  int v102; // w0
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  unsigned int v116; // w10
  unsigned int v118; // w9
  __int64 v119; // [xsp+8h] [xbp-28h]
  int v120; // [xsp+14h] [xbp-1Ch]
  __int64 v121; // [xsp+18h] [xbp-18h]
  unsigned int v122; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v123; // [xsp+28h] [xbp-8h]

  v18 = (char *)a2;
  v123 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = a2[90];
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
      v98 = *(_QWORD *)(a1 + 696) + 1LL;
      ++*(_QWORD *)(a1 + 680);
      *(_QWORD *)(a1 + 696) = v98;
    }
    goto LABEL_85;
  }
  v13 = (_QWORD *)v24;
  _X9 = (unsigned int *)(v21 + 93500);
  __asm { PRFM            #0x11, [X9] }
  do
    v116 = __ldxr(_X9);
  while ( __stxr(v116 + 1, _X9) );
  LODWORD(v119) = v22;
  v120 = a4;
  v26 = *(unsigned int *)(v21 + 93500);
  v27 = *(_DWORD *)(v21 + 93504);
  if ( v27 < (int)v26 )
  {
    v27 = *(_DWORD *)(v21 + 93500);
    *(_DWORD *)(v21 + 93504) = v26;
  }
  qdf_mem_tx_desc_cnt_update(v26, v27);
  v13[1] = v18;
  *((_BYTE *)v13 + 65) = 0;
  if ( !v15 || (v28 = *(unsigned __int16 *)(v15 + 4), v28 == 6) )
    v28 = *(_DWORD *)(a1 + 40);
  v29 = *((unsigned int *)v13 + 9);
  *((_BYTE *)v13 + 64) = v13[8] & 0xFC | v28 & 3;
  v30 = *(_BYTE *)(a1 + 59);
  v13[7] = v21;
  v13[9] = 0;
  *((_BYTE *)v13 + 48) = v30;
  *((_BYTE *)v13 + 66) = 0;
  *((_WORD *)v13 + 8) = *((_WORD *)v18 + 56) - *((_DWORD *)v18 + 29);
  v31 = dp_tx_trace_pkt(v14, v18, v29, *(unsigned __int8 *)(a1 + 59), *(unsigned int *)(a1 + 45348));
  if ( *(_BYTE *)(a1 + 80) == 1 )
  {
    v31 = dp_tx_multipass_process(v14, a1, v18, a3);
    if ( (v31 & 1) == 0 )
    {
      v20 = v22;
      if ( a1 )
      {
        if ( v22 )
          goto LABEL_138;
        ++*(_DWORD *)(a1 + 792);
      }
      goto LABEL_84;
    }
  }
  if ( *(_BYTE *)(a3 + 13)
    || *(_DWORD *)(a1 + 32) == 5
    || (v32 = (*(unsigned __int16 *)(v18 + 69) >> 11) & 1, v15) && (*(_BYTE *)(v15 + 12) & 1) != 0 )
  {
    v33 = *((_QWORD *)v18 + 28);
    v34 = v33 & 7;
    if ( ((unsigned __int8)v33 & 7u) > (int)v33 - *((_DWORD *)v18 + 54) )
    {
      v20 = (unsigned int)v119;
      if ( a1 )
      {
        if ( (_DWORD)v119 )
          goto LABEL_138;
        ++*(_DWORD *)(a1 + 760);
      }
      goto LABEL_84;
    }
    v35 = *((_QWORD *)v18 + 5);
    v36 = v33 & 7;
    if ( v35 )
      *((_QWORD *)v18 + 5) = v35 - v36;
    if ( !skb_push(v18, v36) )
    {
      v31 = qdf_trace_msg(
              0x7Du,
              2u,
              "%s: qdf_nbuf_push_head failed",
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              "dp_tx_prepare_desc_single");
      v20 = (unsigned int)v119;
      if ( a1 )
      {
        if ( (_DWORD)v119 )
          goto LABEL_138;
        ++*(_DWORD *)(a1 + 784);
      }
      goto LABEL_84;
    }
    if ( *(_DWORD *)(a1 + 64) || *(_BYTE *)(a3 + 14) || (*(_BYTE *)(a3 + 57) & 2) != 0 || *(_BYTE *)(a3 + 13) )
    {
      if ( (unsigned int)(*((_DWORD *)v18 + 56) - *((_DWORD *)v18 + 54)) <= 0x27 )
      {
        v102 = pskb_expand_head(v18, 40, 0, 2080);
        if ( !v18 || v102 )
        {
          v31 = qdf_trace_msg(
                  0x38u,
                  2u,
                  "%s:  %s[%d] skb_realloc_headroom failed",
                  v103,
                  v104,
                  v105,
                  v106,
                  v107,
                  v108,
                  v109,
                  v110,
                  "dp_tx_prepare_htt_metadata",
                  "dp_tx_prepare_htt_metadata",
                  745);
          v20 = (unsigned int)v119;
          if ( !a1 )
            goto LABEL_84;
          goto LABEL_82;
        }
      }
      v45 = *((_QWORD *)v18 + 5);
      if ( v45 )
        *((_QWORD *)v18 + 5) = v45 - 40;
      v46 = (void *)skb_push(v18, 40);
      if ( !v46 )
      {
        v31 = qdf_trace_msg(
                0x7Du,
                2u,
                "%s: Error in filling HTT metadata",
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                "dp_tx_prepare_htt_metadata");
        v20 = (unsigned int)v119;
        if ( !a1 )
        {
LABEL_84:
          dp_tx_desc_release(v31, (__int64)v13, v16);
LABEL_85:
          v13 = &unk_85A000;
          v93 = jiffies;
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
            dp_tx_send_msdu_single___last_ticks = v93;
          }
          v15 = v121;
          v14 = 0;
          goto LABEL_128;
        }
LABEL_82:
        if ( (_DWORD)v20 )
          goto LABEL_138;
        ++*(_DWORD *)(a1 + 788);
        goto LABEL_84;
      }
      qdf_mem_copy(v46, (const void *)(a3 + 56), 0x24u);
    }
    v55 = *((_DWORD *)v13 + 8);
    v56 = *((_DWORD *)v18 + 28) - *((_DWORD *)v18 + 29);
    *((_BYTE *)v13 + 66) = v34 | 0x28;
    *((_WORD *)v13 + 8) = v56;
    *((_DWORD *)v13 + 8) = v55 | 2;
    if ( (*(_BYTE *)(a3 + 76) & 8) != 0 )
      *((_DWORD *)v13 + 8) = v55 | 0x4002;
    *((_WORD *)v13 + 8) = v56 - (v34 | 0x28);
    v32 = 1;
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
    _X8 = (unsigned int *)(v14 + 18700);
    __asm { PRFM            #0x11, [X8] }
    do
      v118 = __ldxr(_X8);
    while ( __stxr(v118 + 1, _X8) );
    if ( !a1 )
      goto LABEL_37;
    goto LABEL_35;
  }
  if ( v32 )
    goto LABEL_33;
  if ( !a1 )
    goto LABEL_37;
LABEL_35:
  if ( *(_BYTE *)(a1 + 321) == 1 )
  {
    *((_DWORD *)v13 + 8) |= 0x100u;
    *(_BYTE *)(a1 + 321) = 0;
  }
LABEL_37:
  v20 = *(unsigned __int8 *)(a1 + 59);
  v119 = a1 + 45056;
  if ( v20 < 6 )
  {
    v58 = *(_QWORD *)(a1 + 24);
    v122 = 0;
    v59 = *(_QWORD *)(v58 + 8);
    v60 = *(_QWORD **)(v59 + 8 * v20 + 22400);
    if ( (wlan_cfg_get_dp_tx_page_pool_enabled(*(_QWORD *)(v59 + 40)) & 1) == 0 || !v60 || *((_BYTE *)v60 + 56) != 1 )
      goto LABEL_54;
    if ( *((_QWORD *)v18 + 2) != 51931 )
      *((_QWORD *)v18 + 5) = 0;
    if ( (*((_BYTE *)v13 + 33) & 1) != 0 || *((_DWORD *)v18 + 29) )
      goto LABEL_54;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v60 + 5);
    }
    else
    {
      raw_spin_lock_bh(v60 + 5);
      v60[6] |= 1uLL;
    }
    if ( *((_QWORD *)v18 + 2) == 51931 )
    {
      is_pp_nbuf = _qdf_is_pp_nbuf(v18);
      v71 = 3;
      if ( (is_pp_nbuf & 1) == 0 )
        v71 = 4;
      v72 = v60[6];
      ++v60[v71];
      if ( (v72 & 1) == 0 )
      {
LABEL_53:
        raw_spin_unlock(v60 + 5);
LABEL_54:
        v16 = (__int64)v18;
        goto LABEL_55;
      }
    }
    else
    {
      v94 = *v60;
      if ( *v60 )
      {
        if ( (_qdf_page_pool_empty(*v60) & 1) == 0 )
        {
          v95 = _qdf_nbuf_page_pool_alloc(
                  *(_QWORD *)(v59 + 24),
                  *((unsigned int *)v18 + 53),
                  0,
                  0,
                  v94,
                  &v122,
                  "dp_tx_page_pool_handle_nbuf_single",
                  235);
          if ( v95 )
          {
            v16 = v95;
            ++v60[3];
            qdf_spin_unlock_bh_9((__int64)(v60 + 5));
            qdf_mem_copy(*(void **)(v16 + 224), *((const void **)v18 + 28), *((unsigned int *)v18 + 28));
            qdf_nbuf_set_pktlen_0(v16, *((unsigned int *)v18 + 28));
            skb_copy_header(v16, v18);
            v96 = ((unsigned __int64)(((__int64)(*(_QWORD *)(v16 + 224) << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
                - 0x140000000LL;
            v20 = *(_QWORD *)(((unsigned __int64)(((__int64)(*(_QWORD *)(v16 + 224) << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
                            - 0x13FFFFFF8LL);
            if ( (v20 & 1) == 0 )
              goto LABEL_95;
            goto LABEL_139;
          }
        }
      }
      v72 = v60[6];
      ++v60[4];
      if ( (v72 & 1) == 0 )
        goto LABEL_53;
    }
    v60[6] = v72 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v60 + 5);
    goto LABEL_54;
  }
  while ( 1 )
  {
LABEL_138:
    __break(0x5512u);
LABEL_139:
    v96 = v20 - 1;
LABEL_95:
    dma_addr = _qdf_page_pool_get_dma_addr(v96);
    *(_QWORD *)(v16 + 40) = dma_addr
                          + v122
                          + (unsigned __int64)(unsigned int)(*(_DWORD *)(v16 + 224) - *(_DWORD *)(v16 + 216));
    v13[1] = v16;
    v13[18] = v18;
LABEL_55:
    if ( (unsigned __int16)v120 == 0xFFFF )
    {
      v73 = *(unsigned __int16 *)(a1 + 60);
    }
    else if ( (unsigned __int16)v120 == 65534 )
    {
      v73 = *(unsigned __int16 *)(a1 + 60) | 0x1000;
    }
    else
    {
      if ( (unsigned __int16)v120 >= 0x4000u )
        printk(
          &unk_881311,
          "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_tx.c",
          3622,
          "!((peer_id) & ~((HTT_TX_TCL_METADATA_PEER_ID_M) >> (HTT_TX_TCL_METADATA_PEER_ID_S)))");
      v73 = 4 * v120;
    }
    if ( *(_BYTE *)(a3 + 104) )
      v73 |= 0x2000u;
    if ( *(_BYTE *)(a3 + 13) )
      v74 = v73 | 2;
    else
      v74 = v73;
    if ( *(_DWORD *)a3 == 6 )
      goto LABEL_116;
    v75 = *(_QWORD *)(a1 + 16);
    if ( (*((_BYTE *)v13 + 33) & 1) != 0 )
      break;
    if ( !(unsigned int)qdf_nbuf_map_nbytes_single(v75, v16, *(unsigned int *)(v16 + 112)) )
      goto LABEL_65;
LABEL_116:
    v18 = (char *)&unk_85A000;
    v14 = jiffies;
    if ( dp_tx_send_msdu_single___last_ticks_16 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: qdf_nbuf_map failed",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "dp_tx_send_msdu_single");
      dp_tx_send_msdu_single___last_ticks_16 = v14;
    }
    v15 = v121;
    if ( !a1 )
      goto LABEL_121;
    v20 = *(unsigned __int8 *)(a3 + 94);
    if ( !*(_BYTE *)(a3 + 94) )
    {
      ++*(_DWORD *)(a1 + 752);
LABEL_121:
      v14 = 2;
      goto LABEL_122;
    }
  }
  if ( (unsigned int)_qdf_nbuf_map_single(v75, v16, 1u) )
    goto LABEL_116;
LABEL_65:
  v76 = *(_QWORD *)(v16 + 40);
  if ( !v76 )
    goto LABEL_116;
  v13[5] = v76;
  v77 = *(_DWORD **)(v14 + 1296);
  if ( *(v77 - 1) != -1196775241 )
    __break(0x8228u);
  if ( !((unsigned int (__fastcall *)(__int64, __int64, _QWORD *, _QWORD, __int64, __int64))v77)(
          v14,
          a1,
          v13,
          v74,
          v15,
          a3) )
  {
    if ( *(_DWORD *)(v119 + 296) )
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
  v86 = jiffies;
  if ( dp_tx_send_msdu_single___last_ticks_18 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x7Du,
      2u,
      "%s: Tx_hw_enqueue Fail tx_desc %pK queue %d",
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      "dp_tx_send_msdu_single",
      v13,
      *(unsigned __int8 *)(a3 + 5));
    dp_tx_send_msdu_single___last_ticks_18 = v86;
  }
  v87 = v13[1];
  v88 = *(_QWORD *)(v14 + 24);
  v89 = v13[5];
  v90 = *((unsigned __int16 *)v13 + 8);
  v91 = *(int *)(v87 + 212);
  qdf_mem_dp_tx_skb_cnt_dec();
  qdf_mem_dp_tx_skb_dec(v91);
  qdf_mem_skb_total_dec(v91);
  if ( *(_BYTE *)(v88 + 624) == 1 && (_qdf_is_pp_nbuf(v87) & 1) != 0 && *(_QWORD *)(v87 + 40) )
  {
    v92 = *(_QWORD *)(v88 + 40);
    if ( (*(_BYTE *)(v92 + 844) & 0x40) == 0 )
      _dma_sync_single_for_cpu(v92, v89);
  }
  else
  {
    dma_unmap_page_attrs(*(_QWORD *)(v88 + 40), v89, v90, 1, 0);
  }
  v15 = v121;
  v14 = 3;
LABEL_122:
  v99 = _qdf_is_pp_nbuf(v16);
  if ( (v99 & 1) != 0 && v13[18] )
  {
    if ( v16 )
      v99 = _qdf_nbuf_free(v16);
    v16 = v13[18];
    v13[1] = v16;
    v13[18] = 0;
  }
  dp_tx_desc_release(v99, (__int64)v13, *(unsigned __int8 *)(a3 + 4));
  v18 = (char *)v16;
LABEL_128:
  ((void (__fastcall *)(__int64, char *, __int64))dp_tx_get_tid)(a1, v18, a3);
  v20 = *(unsigned __int8 *)(a3 + 5);
  if ( v20 > 4 || (unsigned int)v15 > 9 )
    goto LABEL_138;
  v100 = v21 + 6768LL * *(unsigned __int8 *)(a3 + 5) + 752LL * (unsigned int)v15 + 8 * v14;
  ++*(_QWORD *)(v100 + 8552);
LABEL_131:
  _ReadStatusReg(SP_EL0);
  return v18;
}
