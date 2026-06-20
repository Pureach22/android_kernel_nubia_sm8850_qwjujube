__int64 __fastcall _dp_rx_buffers_replenish(
        __int64 a1,
        unsigned int a2,
        __int64 *a3,
        __int64 a4,
        unsigned int a5,
        unsigned int **a6,
        __int64 a7,
        char a8,
        char a9)
{
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  __int64 v26; // x21
  __int64 v27; // x24
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w9
  unsigned int v37; // w10
  unsigned int v38; // w8
  unsigned int v39; // w5
  __int64 v40; // x3
  unsigned __int16 v41; // w8
  unsigned int v42; // w26
  __int64 v43; // x9
  __int64 v44; // x10
  __int64 v45; // x3
  unsigned __int16 free_desc_list; // w0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int **v55; // x10
  unsigned int *v56; // x9
  unsigned int v57; // w8
  int v58; // w8
  __int64 v59; // x26
  unsigned int v60; // w25
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned __int64 StatusReg; // x8
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned int v78; // w27
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x2
  __int64 v88; // x8
  __int64 v89; // x25
  __int64 v90; // x3
  int v91; // w8
  __int64 v92; // x2
  __int64 v93; // x8
  __int64 v94; // x0
  __int64 v95; // x8
  __int64 v96; // x26
  unsigned int v97; // w21
  __int64 v98; // x20
  __int64 v99; // x28
  __int64 v100; // x0
  __int64 v101; // x1
  __int64 v102; // x8
  unsigned int v103; // w9
  __int64 v104; // x10
  __int64 v105; // x25
  __int64 *v106; // x8
  unsigned int *v107; // x26
  __int64 v108; // x5
  char v109; // w9
  int v110; // w10
  unsigned int *v111; // x8
  __int64 v112; // x2
  __int64 v113; // x3
  void (__fastcall *v114)(__int64, __int64, __int64, __int64); // x8
  unsigned int v115; // w8
  __int64 v116; // x0
  __int64 v117; // x0
  __int64 v118; // x0
  __int64 v119; // x25
  __int64 v120; // x26
  __int64 v121; // x8
  _DWORD *v122; // x2
  __int64 v123; // x8
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  unsigned int v132; // w8
  unsigned int v133; // w9
  __int16 v134; // w9
  unsigned __int16 v135; // w8
  void (__fastcall *v136)(_QWORD); // x9
  int v137; // w10
  unsigned int v138; // w8
  unsigned int v139; // w12
  _DWORD *v140; // x2
  __int64 v141; // x8
  unsigned int v148; // w10
  __int64 v149; // [xsp+8h] [xbp-48h]
  unsigned int v150; // [xsp+10h] [xbp-40h]
  unsigned int v151; // [xsp+14h] [xbp-3Ch]
  unsigned int **v152; // [xsp+20h] [xbp-30h] BYREF
  unsigned int *v153; // [xsp+28h] [xbp-28h] BYREF
  __int64 v154; // [xsp+30h] [xbp-20h] BYREF
  __int64 v155; // [xsp+38h] [xbp-18h]
  unsigned int v156; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v157; // [xsp+48h] [xbp-8h]

  v157 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_QWORD *)(a1 + 40);
  v156 = a5;
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(v16)
    && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a1 + 40), a2) )
  {
    v152 = nullptr;
    v153 = nullptr;
LABEL_4:
    qdf_trace_msg(
      0x7Eu,
      2u,
      "%s: %pK: pdev is null for mac_id = %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "__dp_rx_buffers_replenish",
      a1,
      a2);
    result = 16;
    goto LABEL_109;
  }
  v26 = *(_QWORD *)(a1 + 72);
  v154 = 0;
  v155 = 0;
  v152 = nullptr;
  v153 = nullptr;
  if ( !v26 )
    goto LABEL_4;
  v27 = *a3;
  if ( !*a3 )
  {
    qdf_trace_msg(
      0x7Eu,
      8u,
      "%s: %pK: rxdma srng not initialized",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "__dp_rx_buffers_replenish",
      a1);
    result = 16;
    *(_DWORD *)(v26 + 432) += v156;
    goto LABEL_109;
  }
  if ( is_dp_verbose_debug_enabled == 1 )
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: %pK: requested %d buffers for replenish",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "__dp_rx_buffers_replenish",
      a1,
      v156);
  if ( (dp_rx_buffers_is_skip_replenish(a1, a4, a6, a7, &v156, a2) & 1) != 0 )
    goto LABEL_108;
  hal_srng_access_start(*(_QWORD *)(a1 + 1128), v27);
  v36 = *(_DWORD *)(v27 + 120);
  v37 = **(_DWORD **)(v27 + 128);
  v38 = v37 - v36;
  *(_DWORD *)(v27 + 136) = v37;
  if ( v37 <= v36 )
    v38 += *(_DWORD *)(v27 + 36);
  v39 = v38 / *(_DWORD *)(v27 + 44) - 1;
  v151 = v39;
  if ( is_dp_verbose_debug_enabled == 1 )
  {
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: %pK: no of available entries in rxdma ring: %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "__dp_rx_buffers_replenish",
      a1);
    v39 = v151;
    if ( (a8 & 1) != 0 )
      goto LABEL_15;
  }
  else if ( (a8 & 1) != 0 )
  {
    goto LABEL_15;
  }
  if ( !*a6 && ((a9 & 1) != 0 || v39 > (unsigned int)(3 * *((_DWORD *)a3 + 13)) >> 2) )
  {
    v58 = *(_DWORD *)(v26 + 452);
    v42 = 0;
    v156 = v39;
    v40 = v39;
    *(_DWORD *)(v26 + 452) = v58 + 1;
    goto LABEL_34;
  }
LABEL_15:
  v40 = v156;
  if ( v39 >= v156 )
  {
    if ( *a6 )
    {
      if ( *((_DWORD *)a3 + 13) - v39 <= 0x3F )
      {
        v43 = *(int *)(a4 + 108);
        if ( !(_DWORD)v43
          || (v44 = *(int *)(a4 + 112), (unsigned int)v43 > (unsigned int)v44) && (unsigned __int64)(v43 - v44) >= 0x40 )
        {
          if ( v156 + 64 <= v39 )
            v45 = 64;
          else
            v45 = v39 - v156;
          free_desc_list = dp_rx_get_free_desc_list(a1, a2, a4, v45, &v153, &v152);
          if ( free_desc_list )
          {
            v55 = v152;
            v42 = 0;
            v56 = *a6;
            *a6 = v153;
            v57 = v156;
            *v55 = v56;
            LODWORD(v55) = *(_DWORD *)(v26 + 456);
            v40 = v57 + free_desc_list;
            v156 = v57 + free_desc_list;
            *(_DWORD *)(v26 + 456) = (_DWORD)v55 - free_desc_list;
            goto LABEL_34;
          }
          v59 = jiffies;
          if ( _dp_rx_buffers_replenish___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: %pK:  no free rx_descs in freelist",
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              "__dp_rx_buffers_replenish",
              a1);
            _dp_rx_buffers_replenish___last_ticks = v59;
          }
        }
      }
      v40 = v156;
    }
    v42 = 0;
    goto LABEL_34;
  }
  v41 = v156 - v39;
  v156 = v39;
  v40 = v39;
  v42 = v41;
LABEL_34:
  if ( !(_DWORD)v40 )
  {
    hal_srng_access_end(*(_QWORD *)(a1 + 1128), v27);
    v139 = 0;
    goto LABEL_106;
  }
  if ( !*a6 )
  {
    v60 = (unsigned __int16)dp_rx_get_free_desc_list(a1, a2, a4, v40, a6, a7);
    if ( !v60 )
    {
      qdf_trace_msg(
        0x7Eu,
        2u,
        "%s: %pK: no free rx_descs in freelist",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "__dp_rx_buffers_replenish",
        a1);
      *(_DWORD *)(v26 + 484) += v156;
      v140 = *(_DWORD **)(v27 + 144);
      if ( (*(_DWORD *)(v27 + 76) & 0x80000000) != 0 )
        *v140 = *(_DWORD *)(v27 + 120);
      else
        hal_delayed_reg_write(*(_QWORD *)(a1 + 1128), v27, v140, *(unsigned int *)(v27 + 120));
      v141 = *(_QWORD *)(v27 + 88);
      if ( (v141 & 1) != 0 )
      {
        *(_QWORD *)(v27 + 88) = v141 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v27 + 80);
      }
      else
      {
        raw_spin_unlock(v27 + 80);
      }
      result = 2;
      goto LABEL_109;
    }
    if ( is_dp_verbose_debug_enabled == 1 )
      qdf_trace_msg(
        0x45u,
        8u,
        "%s: %pK: %d rx desc allocated",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "__dp_rx_buffers_replenish",
        a1,
        v60);
    v156 = v60;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 18464);
  }
  else
  {
    raw_spin_lock_bh(a1 + 18464);
    *(_QWORD *)(a1 + 18472) |= 1uLL;
  }
  v78 = 0;
  v150 = v42;
  if ( !v156 )
    goto LABEL_85;
  while ( 1 )
  {
    while ( (*((_BYTE *)*a6 + 30) & 1) != 0 )
    {
      v117 = printk(
               &unk_9BB309,
               "expr",
               "__dp_assert_always_internal",
               "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
      dump_stack(v117);
      v107 = *(unsigned int **)*a6;
LABEL_72:
      v115 = v156;
      ++v78;
      *a6 = v107;
      if ( v78 >= v115 )
        goto LABEL_85;
    }
    if ( (*(_BYTE *)(a4 + 77) & 1) != 0 || !(unsigned int)dp_rx_page_pool_nbuf_alloc_and_map(a1, &v154, a2, 1) )
      goto LABEL_60;
    v155 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD))dp_rx_buffer_pool_nbuf_alloc)(a1, a2, a4, v151);
    if ( !v155 )
      break;
    ++*(_DWORD *)(v26 + 460);
    if ( !(unsigned int)dp_rx_buffer_pool_nbuf_map(a1, a4, &v154) )
    {
      v87 = *(unsigned __int16 *)(a4 + 74);
      v88 = 80;
      if ( (*(_BYTE *)(v155 + 68) & 4) == 0 )
        v88 = 40;
      v154 = *(_QWORD *)(v155 + v88);
      dp_ipa_handle_rx_buf_smmu_mapping(a1, v155, v87, 1, "dp_pdev_nbuf_alloc_and_map_replenish", 407, 3);
      v89 = v155;
      v90 = *(unsigned __int16 *)(a4 + 74);
      if ( *(_DWORD *)(a1 + 20208) && (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 831LL) & 1) == 0 )
      {
        v91 = *(_DWORD *)(v155 + 48);
        if ( (v91 & 0x2000000) != 0 )
        {
          if ( a1 )
            ++*(_DWORD *)(a1 + 14024);
        }
        else
        {
          v92 = *(_QWORD *)(v155 + 40);
          *(_DWORD *)(v155 + 48) = v91 | 0x2000000;
          v93 = *(_QWORD *)(a1 + 24);
          v94 = *(_QWORD *)(v93 + 40);
          if ( *(_BYTE *)(v93 + 608) == 1 && (v95 = *(_QWORD *)(v93 + 616)) != 0 )
          {
            v149 = v94;
            v96 = v26;
            v97 = a2;
            v98 = a7;
            v99 = v90;
            v100 = iommu_iova_to_phys(v95, v92);
            v92 = *(_QWORD *)(v89 + 40);
            v101 = v100;
            v94 = v149;
            v90 = v99;
            a7 = v98;
            a2 = v97;
            v26 = v96;
          }
          else
          {
            v101 = v92;
          }
          pld_audio_smmu_map(v94, v101, v92, v90);
        }
      }
LABEL_60:
      v102 = *(unsigned int *)(v27 + 120);
      v103 = (unsigned int)(*(_DWORD *)(v27 + 44) + v102) % *(_DWORD *)(v27 + 36);
      if ( v103 == *(_DWORD *)(v27 + 136)
        || (v104 = *(_QWORD *)(v27 + 16),
            *(_DWORD *)(v27 + 120) = v103,
            *(_DWORD *)(v27 + 124) = v103,
            (v105 = v104 + 4 * v102) == 0) )
      {
        v116 = printk(
                 &unk_9BB309,
                 "rxdma_ring_entry",
                 "__dp_rx_buffers_replenish",
                 "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx.c");
        dump_stack(v116);
        v105 = 0;
      }
      v106 = (__int64 *)*a6;
      v107 = *(unsigned int **)*a6;
      if ( *(_BYTE *)(a4 + 77) == 1 )
      {
        v108 = v154;
      }
      else
      {
        *v106 = v155;
        v108 = v154;
        v109 = *((_BYTE *)v106 + 30) & 0xFD;
        v106[2] = v154;
        *((_BYTE *)v106 + 30) = v109;
        v106 = (__int64 *)*a6;
      }
      v110 = (unsigned __int8)is_dp_verbose_debug_enabled;
      *((_BYTE *)v106 + 30) |= 1u;
      *((_BYTE *)*a6 + 30) &= ~4u;
      if ( v110 == 1 )
      {
        qdf_trace_msg(
          0x45u,
          8u,
          "%s: rx_netbuf=%pK, paddr=0x%llx, cookie=%d",
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          "__dp_rx_buffers_replenish",
          v155);
        v108 = v154;
      }
      v111 = *a6;
      if ( (*(_BYTE *)(a4 + 77) & 1) == 0 && v108 != *(_QWORD *)(*(_QWORD *)v111 + 40LL) )
      {
        v118 = printk(
                 &unk_9BB309,
                 "nbuf_frag_info.paddr == (((struct qdf_nbuf_cb *)(((*desc_list)->rx_desc.nbuf)->cb))->paddr.dma_addr)",
                 "__dp_rx_buffers_replenish",
                 "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx.c");
        dump_stack(v118);
        v108 = v154;
        v111 = *a6;
      }
      v112 = v111[6];
      v113 = *(unsigned __int8 *)(a4 + 72);
      v114 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL)
                                                                       + 1472LL);
      if ( *((_DWORD *)v114 - 1) != -1494657337 )
        __break(0x8228u);
      v114(v105, v108, v112, v113);
      goto LABEL_72;
    }
    dp_rx_buffer_pool_nbuf_free(a1, v155, a2);
    ++*(_DWORD *)(v26 + 444);
    v119 = jiffies;
    if ( dp_pdev_nbuf_alloc_and_map_replenish___last_ticks_56 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: nbuf map failed %d",
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        "dp_pdev_nbuf_alloc_and_map_replenish");
      dp_pdev_nbuf_alloc_and_map_replenish___last_ticks_56 = v119;
    }
    if ( v78 >= v156 )
      goto LABEL_85;
  }
  ++*(_DWORD *)(v26 + 436);
  v120 = jiffies;
  if ( dp_pdev_nbuf_alloc_and_map_replenish___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: nbuf alloc failed %d",
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      "dp_pdev_nbuf_alloc_and_map_replenish");
    dp_pdev_nbuf_alloc_and_map_replenish___last_ticks = v120;
  }
LABEL_85:
  v121 = *(_QWORD *)(a1 + 18472);
  if ( (v121 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 18472) = v121 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 18464);
  }
  else
  {
    raw_spin_unlock(a1 + 18464);
  }
  v122 = *(_DWORD **)(v27 + 144);
  if ( (*(_DWORD *)(v27 + 76) & 0x80000000) != 0 )
  {
    *v122 = *(_DWORD *)(v27 + 120);
    v123 = *(_QWORD *)(v27 + 88);
    if ( (v123 & 1) != 0 )
      goto LABEL_94;
LABEL_89:
    raw_spin_unlock(v27 + 80);
  }
  else
  {
    hal_delayed_reg_write(*(_QWORD *)(a1 + 1128), v27, v122, *(unsigned int *)(v27 + 120));
    v123 = *(_QWORD *)(v27 + 88);
    if ( (v123 & 1) == 0 )
      goto LABEL_89;
LABEL_94:
    *(_QWORD *)(v27 + 88) = v123 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v27 + 80);
  }
  if ( *(_BYTE *)(a1 + 18800) == 1 )
  {
    v132 = *(unsigned __int16 *)(a1 + 18804);
    v133 = *(unsigned __int16 *)(a1 + 18802);
    if ( v132 <= v133 )
    {
      v134 = ~(_WORD)v133;
      LOWORD(v132) = v132 + *(_WORD *)(a1 + 18816);
    }
    else
    {
      v134 = ~(_WORD)v133;
    }
    v135 = v132 + v134;
    v136 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 320LL);
    if ( v136 )
    {
      if ( v135 >= 0x200u )
      {
        if ( *((_DWORD *)v136 - 1) != -1106481425 )
          __break(0x8229u);
        v136(a1);
      }
    }
  }
  if ( is_dp_verbose_debug_enabled == 1 )
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: replenished buffers %d, rx desc added back to free list %u",
      v124,
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      v131,
      "__dp_rx_buffers_replenish",
      v78,
      v150);
  v137 = *(_DWORD *)(v26 + 456);
  v138 = v156 - v78;
  *(_QWORD *)(v26 + 416) += v78;
  *(_DWORD *)(v26 + 456) = v137 + v138;
  if ( *(_DWORD *)(a4 + 108) )
  {
    v139 = v150;
    _X9 = (unsigned int *)(a4 + 112);
    __asm { PRFM            #0x11, [X9] }
    do
      v148 = __ldxr(_X9);
    while ( __stxr(v148 - v138, _X9) );
  }
  else
  {
    v139 = v150;
  }
LABEL_106:
  *(_DWORD *)(v26 + 512) += v139;
  if ( *a6 )
    dp_rx_add_desc_list_to_free_list(a1, a6, a7, a2, a4);
LABEL_108:
  result = 0;
LABEL_109:
  _ReadStatusReg(SP_EL0);
  return result;
}
