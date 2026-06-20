__int64 __fastcall dp_ipa_tx_opt_dp_ctrl_pkt(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 ref_by_id_2; // x0
  __int64 v6; // x22
  __int64 v7; // x21
  unsigned __int64 v8; // x24
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  int v17; // w2
  int v18; // w3
  int v19; // w4
  int v20; // w5
  int v21; // w6
  int v22; // w7
  unsigned int *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned __int64 StatusReg; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  _QWORD *v41; // x23
  __int16 v42; // w10
  __int64 v43; // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x24
  __int64 v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  int v62; // w2
  int v63; // w3
  int v64; // w4
  int v65; // w5
  int v66; // w6
  int v67; // w7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  int v76; // w2
  int v77; // w3
  int v78; // w4
  int v79; // w5
  int v80; // w6
  int v81; // w7
  int v82; // w2
  int v83; // w3
  int v84; // w4
  int v85; // w5
  int v86; // w6
  int v87; // w7
  __int64 result; // x0
  __int64 v89; // x8
  char v90; // w9
  __int64 v91; // x10
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  int v108; // w2
  int v109; // w3
  int v110; // w4
  int v111; // w5
  int v112; // w6
  int v113; // w7
  __int64 v114; // x26
  __int64 v115; // x27
  __int64 v116; // x24
  __int64 v117; // x25
  __int64 v118; // x0
  char v119; // w8
  int v120; // w9
  _DWORD *v121; // x0
  int v122; // w8
  unsigned int v123; // w9
  unsigned int v124; // w25
  unsigned int v125; // w8
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  int v134; // w9
  int v135; // w9
  int v136; // w10
  __int64 v137; // x26
  int v138; // w8
  unsigned __int64 v139; // x7
  unsigned int v140; // w27
  unsigned int v141; // w25
  unsigned int v142; // w26
  unsigned int v143; // w28
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  int v152; // w8
  int v153; // w8
  int v154; // w5
  int v155; // w6
  int v156; // w7
  __int64 v157; // x8
  __int64 v158; // x0
  char is_opt_wifi_dp_enabled; // w0
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  __int64 v168; // x8
  char *v169; // x0
  unsigned int *v170; // x8
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  int v179; // w2
  int v180; // w3
  int v181; // w4
  int v182; // w5
  int v183; // w6
  int v184; // w7
  __int64 v185; // x26
  __int64 v186; // x27
  __int64 v187; // x24
  __int64 v188; // x25
  __int64 v189; // x0
  __int64 v190; // x26
  __int64 v191; // x0
  int v192; // w2
  int v193; // w3
  int v194; // w4
  int v195; // w5
  int v196; // w6
  int v197; // w7
  char v198; // w8
  __int64 v199; // x9
  __int64 v200; // x26
  char v201; // [xsp+0h] [xbp-90h]
  char v202; // [xsp+0h] [xbp-90h]
  char v203; // [xsp+0h] [xbp-90h]
  char v204; // [xsp+0h] [xbp-90h]
  __int64 v205; // [xsp+8h] [xbp-88h] BYREF
  __int64 v206; // [xsp+10h] [xbp-80h]
  __int64 v207; // [xsp+18h] [xbp-78h] BYREF
  __int64 v208; // [xsp+20h] [xbp-70h]
  __int64 v209; // [xsp+28h] [xbp-68h]
  __int64 v210; // [xsp+30h] [xbp-60h]
  __int64 v211; // [xsp+38h] [xbp-58h]
  __int64 v212; // [xsp+40h] [xbp-50h]
  __int64 v213; // [xsp+48h] [xbp-48h]
  __int64 v214; // [xsp+50h] [xbp-40h]
  __int64 v215; // [xsp+58h] [xbp-38h]
  __int64 v216; // [xsp+60h] [xbp-30h]
  __int64 v217; // [xsp+68h] [xbp-28h]
  __int64 v218; // [xsp+70h] [xbp-20h]
  __int64 v219; // [xsp+78h] [xbp-18h]
  __int64 v220; // [xsp+80h] [xbp-10h]
  __int64 v221; // [xsp+88h] [xbp-8h]

  v221 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v219 = 0;
  v220 = 0;
  v217 = 0;
  v218 = 0;
  v215 = 0;
  v216 = 0;
  v213 = 0;
  v214 = 0;
  v211 = 0;
  v212 = 0;
  v209 = 0;
  v210 = 0;
  v207 = 0;
  v208 = 0;
  ref_by_id_2 = dp_vdev_get_ref_by_id_2();
  if ( !ref_by_id_2 )
  {
LABEL_18:
    if ( a3 )
      _qdf_nbuf_free(a3);
    result = 16;
    goto LABEL_21;
  }
  v6 = *(_QWORD *)(ref_by_id_2 + 24);
  v7 = ref_by_id_2;
  v8 = *(unsigned __int8 *)(v6 + 1);
  if ( v8 >= 5 )
    goto LABEL_85;
  if ( (unsigned int)ipa_opt_dpath_enable_clk_req(*(_QWORD *)(a1 + 16)) )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: clock enable timed out",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "dp_ipa_tx_opt_dp_ctrl_pkt");
    wlan_ipa_log_message(
      (int)"dp_ipa_tx_opt_dp_ctrl_pkt",
      (int)"clock enable timed out",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v201);
LABEL_17:
    dp_vdev_unref_delete(a1, v7, 0xEu, v23, v24, v25, v26, v27, v28, v29, v30, v31);
    goto LABEL_18;
  }
  if ( !*(_QWORD *)(a1 + 17832) )
  {
    qdf_trace_msg(0x45u, 2u, "%s: free list is empty", v9, v10, v11, v12, v13, v14, v15, v16, "dp_ipa_rx_get_free_desc");
    wlan_ipa_log_message((int)"dp_ipa_rx_get_free_desc", (int)"free list is empty", v76, v77, v78, v79, v80, v81, v201);
    goto LABEL_15;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 17848);
  }
  else
  {
    raw_spin_lock_bh(a1 + 17848);
    *(_QWORD *)(a1 + 17856) |= 1uLL;
  }
  v41 = *(_QWORD **)(a1 + 17832);
  v42 = *(_WORD *)(a1 + 17864);
  *(_QWORD *)(a1 + 17832) = *v41;
  *(_WORD *)(a1 + 17864) = v42 - 1;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: opt_dp_ctrl: rx desc allocated, list size %d",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "dp_ipa_rx_get_free_desc",
    (unsigned __int16)(v42 - 1));
  v43 = *(_QWORD *)(a1 + 17856);
  if ( (v43 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 17848);
    if ( v41 )
      goto LABEL_12;
LABEL_15:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: error on fetching free desc",
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      "dp_ipa_tx_opt_dp_ctrl_pkt");
    wlan_ipa_log_message(
      (int)"dp_ipa_tx_opt_dp_ctrl_pkt",
      (int)"error on fetching free desc",
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v201);
LABEL_16:
    ipa_opt_dpath_disable_clk_req(*(_QWORD *)(a1 + 16));
    goto LABEL_17;
  }
  *(_QWORD *)(a1 + 17856) = v43 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 17848);
  if ( !v41 )
    goto LABEL_15;
LABEL_12:
  v52 = a1 + 12368 + 120LL * (unsigned int)v8;
  v205 = 0;
  v206 = 0;
  v53 = dp_pdev_nbuf_alloc_and_map(a1, &v205, v6, v52, 0, 0);
  if ( (_DWORD)v53 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: opt_dp_ctrl: nbuf allocation failed",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "dp_ipa_rx_buf_alloc_opt_dp_ctrl");
    wlan_ipa_log_message(
      (int)"dp_ipa_rx_buf_alloc_opt_dp_ctrl",
      (int)"opt_dp_ctrl: nbuf allocation failed",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v201);
LABEL_74:
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: opt_dp_ctrl: release rx descriptor and add to freelist",
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      "dp_ipa_tx_opt_dp_ctrl_pkt");
    wlan_ipa_log_message(
      (int)"dp_ipa_tx_opt_dp_ctrl_pkt",
      (int)"opt_dp_ctrl: release rx descriptor and add to freelist",
      v192,
      v193,
      v194,
      v195,
      v196,
      v197,
      v202);
    if ( (unsigned int)dp_rx_add_to_ipa_desc_free_list(a1, (__int64)v41, 0) )
    {
      v198 = *((_BYTE *)v41 + 30);
      *v41 = 0;
      *((_BYTE *)v41 + 30) = v198 & 0xFE;
      *v41 = *(_QWORD *)(v6 + 95224);
      v199 = *(_QWORD *)(v6 + 95232);
      *(_QWORD *)(v6 + 95224) = v41;
      if ( !v199 || !*v41 )
        *(_QWORD *)(v6 + 95232) = v41;
    }
    goto LABEL_16;
  }
  v89 = v206;
  v90 = *((_BYTE *)v41 + 30);
  *v41 = v206;
  v91 = v205;
  *((_BYTE *)v41 + 30) = v90 & 0xFD;
  v41[2] = v91;
  if ( (*(_BYTE *)(v89 + 49) & 1) == 0
    && *(_BYTE *)(*(_QWORD *)(a1 + 24) + 608LL) == 1
    && (wlan_ipa_is_shared_smmu_enabled(v53) & 1) == 0 )
  {
    if ( a1 )
      ++*(_DWORD *)(a1 + 14012);
    *(_DWORD *)(*v41 + 48LL) |= 0x100u;
    *(_DWORD *)(*v41 + 48LL) = *(_DWORD *)(*v41 + 48LL) & 0x3FFFFFF | 0x10000000;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: opt_dp_ctrl: smmu map nbuf",
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      "dp_ipa_rx_buf_alloc_opt_dp_ctrl");
    if ( (unsigned int)_dp_ipa_handle_buf_smmu_mapping(a1, *v41, *(unsigned __int16 *)(v52 + 74), 1) )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: opt_dp_ctrl: smmu map failed",
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        v107,
        "dp_ipa_rx_buf_alloc_opt_dp_ctrl");
      wlan_ipa_log_message(
        (int)"dp_ipa_rx_buf_alloc_opt_dp_ctrl",
        (int)"opt_dp_ctrl: smmu map failed",
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v201);
      v114 = *v41;
      v115 = *(_QWORD *)(a1 + 24);
      v116 = *(unsigned __int16 *)(v52 + 74);
      v117 = *(_QWORD *)(*v41 + 40LL);
      if ( (_qdf_is_pp_nbuf(*v41) & 1) != 0 && *(_QWORD *)(v114 + 40) )
      {
        v118 = *(_QWORD *)(v115 + 40);
        if ( (*(_BYTE *)(v118 + 844) & 0x40) == 0 )
        {
          _dma_sync_single_for_cpu(v118, v117);
          v119 = *((_BYTE *)v41 + 30);
          goto LABEL_72;
        }
      }
      else if ( v117 )
      {
        v200 = *(int *)(v114 + 212);
        qdf_mem_dp_rx_skb_cnt_dec();
        qdf_mem_dp_rx_skb_dec(v200);
        qdf_mem_skb_total_dec(v200);
        dma_unmap_page_attrs(*(_QWORD *)(v115 + 40), v117, v116, 2, 0);
      }
      v119 = *((_BYTE *)v41 + 30);
LABEL_72:
      v191 = *v41;
      *((_BYTE *)v41 + 30) = v119 | 2;
      if ( v191 )
        _qdf_nbuf_free(v191);
      goto LABEL_74;
    }
  }
  if ( (*(_BYTE *)(a3 + 68) & 4) != 0 )
    v120 = *(unsigned __int16 *)(a3 + 66);
  else
    v120 = 0;
  qdf_mem_copy(
    (void *)(*(_QWORD *)(*v41 + 224LL) + *(unsigned __int16 *)(a1 + 1140) + 2LL),
    *(const void **)(a3 + 224),
    (unsigned int)(*(_DWORD *)(a3 + 112) + v120));
  v121 = (_DWORD *)*v41;
  if ( (*(_BYTE *)(a3 + 68) & 4) != 0 )
    v122 = *(unsigned __int16 *)(a3 + 66);
  else
    v122 = 0;
  v123 = v121[28];
  v124 = *(_DWORD *)(a3 + 112) + v122;
  v125 = v124 - v123;
  if ( v124 < v123 )
  {
    skb_trim(v121, v124);
    goto LABEL_48;
  }
  if ( v121[29] )
  {
    v125 = v124 - v123;
    if ( v124 != v123 )
    {
      v134 = 0;
      goto LABEL_45;
    }
  }
  else
  {
    v136 = v121[52];
    v135 = v121[53];
    if ( v135 - v136 < v125 )
    {
      v134 = v136 - v135;
LABEL_45:
      v137 = *v41;
      v138 = pskb_expand_head(v121, 0, v134 + v125, 2080);
      v121 = (_DWORD *)v137;
      if ( v138 )
      {
        dev_kfree_skb_any_reason(v137, 1);
        v121 = (_DWORD *)v137;
      }
    }
  }
  skb_put(v121, v124 - v121[28]);
LABEL_48:
  v139 = *((unsigned __int8 *)v41 + 28);
  *((_BYTE *)v41 + 30) |= 0x21u;
  if ( v139 <= 3 )
  {
    v140 = *((_DWORD *)v41 + 4);
    v142 = *((_DWORD *)v41 + 5);
    v141 = *((_DWORD *)v41 + 6);
    v143 = *(unsigned __int8 *)(a1 + 12368 + 120LL * (unsigned int)v139 + 72);
    v203 = *(_BYTE *)(a1 + 12368 + 120LL * (unsigned int)v139 + 72);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: opt_dp_ctrl: paddr_lo: 0x%x, paddr_hi: 0x%x, cookie: 0x%x, pool_id: 0x%x, manager: 0x%x",
      v126,
      v127,
      v128,
      v129,
      v130,
      v131,
      v132,
      v133,
      "dp_ipa_tx_opt_dp_ctrl_pkt",
      v140,
      v142,
      v141);
    qdf_mem_set(&v207, 0x70u, 0);
    HIDWORD(v217) |= v140;
    if ( v142 >= 0x100 )
      printk(
        &unk_881311,
        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_ipa.c",
        4217,
        "!((paddr_hi) & ~((HTT_RX_BUFFER_ADDR_INFO_ADDR_39_32_M) >> (HTT_RX_BUFFER_ADDR_INFO_ADDR_39_32_S)))");
    v152 = v218 | v142;
    LODWORD(v218) = v218 | v142;
    if ( v143 >= 0x10 )
    {
      printk(
        &unk_881311,
        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_ipa.c",
        4219,
        "!((manager) & ~((HTT_RX_BUFFER_ADDR_INFO_RETURN_BUFFER_MANAGER_M) >> (HTT_RX_BUFFER_ADDR_INFO_RETURN_BUFFER_MANAGER_S)))");
      v152 = v218;
    }
    v153 = v152 | (v143 << 8);
    LODWORD(v218) = v153;
    if ( v141 >= 0x100000 )
    {
      printk(
        &unk_881311,
        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_ipa.c",
        4221,
        "!((cookie) & ~((HTT_RX_BUFFER_ADDR_INFO_SW_BUFFER_COOKIE_M) >> (HTT_RX_BUFFER_ADDR_INFO_SW_BUFFER_COOKIE_S)))");
      v153 = v218;
    }
    LODWORD(v218) = v153 | (v141 << 12);
    ++dp_ipa_tx_opt_dp_ctrl_pkt_ctrl_pkt;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: opt_dp_ctrl: metadata[7]: 0x%x, metadata[8]: 0x%x, ctrl_pkt cnt: %d",
      v144,
      v145,
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      "dp_ipa_tx_opt_dp_ctrl_pkt",
      HIDWORD(v217));
    wlan_ipa_log_message(
      (int)"dp_ipa_tx_opt_dp_ctrl_pkt",
      (int)"opt_dp_ctrl: metadata[7]: 0x%x, metadata[8]: 0x%x, ctrl_pkt cnt: %d",
      SHIDWORD(v217),
      v218,
      dp_ipa_tx_opt_dp_ctrl_pkt_ctrl_pkt,
      v154,
      v155,
      v156,
      v203);
    v157 = *(_QWORD *)(*(_QWORD *)(v7 + 24) + 8LL);
    BYTE4(v207) = *(_BYTE *)(v7 + 59);
    v158 = *(_QWORD *)(v157 + 40);
    if ( *(_BYTE *)(v158 + 540) == 1 )
    {
      is_opt_wifi_dp_enabled = ipa_config_is_opt_wifi_dp_enabled();
      v168 = *(_QWORD *)(v7 + 24);
      if ( (is_opt_wifi_dp_enabled & 1) == 0 )
      {
        LOBYTE(v168) = *(_BYTE *)v168;
LABEL_64:
        BYTE5(v207) = v168;
        BYTE6(v218) = 0;
        LOBYTE(v220) = 1;
        BYTE5(v208) = 1;
        v169 = dp_tx_send_msdu_single(
                 v7,
                 (unsigned __int16 *)a3,
                 (__int64)&v207,
                 0xFFFF,
                 0,
                 v160,
                 v161,
                 v162,
                 v163,
                 v164,
                 v165,
                 v166,
                 v167);
        if ( !v169 )
        {
          dp_vdev_unref_delete(a1, v7, 0xEu, v170, v171, v172, v173, v174, v175, v176, v177, v178);
          result = 0;
LABEL_21:
          _ReadStatusReg(SP_EL0);
          return result;
        }
        a3 = (__int64)v169;
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: opt_dp_ctrl: unmap rx buffer",
          v171,
          v172,
          v173,
          v174,
          v175,
          v176,
          v177,
          v178,
          "dp_ipa_tx_opt_dp_ctrl_pkt");
        wlan_ipa_log_message(
          (int)"dp_ipa_tx_opt_dp_ctrl_pkt",
          (int)"opt_dp_ctrl: unmap rx buffer",
          v179,
          v180,
          v181,
          v182,
          v183,
          v184,
          v204);
        dp_ipa_handle_rx_buf_smmu_mapping(
          a1,
          *v41,
          *(unsigned __int16 *)(v52 + 74),
          0,
          (__int64)"dp_ipa_tx_opt_dp_ctrl_pkt",
          0x1092u,
          0);
        v185 = *v41;
        v186 = *(_QWORD *)(a1 + 24);
        v187 = *(unsigned __int16 *)(v52 + 74);
        v188 = *(_QWORD *)(*v41 + 40LL);
        if ( (_qdf_is_pp_nbuf(*v41) & 1) != 0 && *(_QWORD *)(v185 + 40) )
        {
          v189 = *(_QWORD *)(v186 + 40);
          if ( (*(_BYTE *)(v189 + 844) & 0x40) == 0 )
            _dma_sync_single_for_cpu(v189, v188);
        }
        else if ( v188 )
        {
          v190 = *(int *)(v185 + 212);
          qdf_mem_dp_rx_skb_cnt_dec();
          qdf_mem_dp_rx_skb_dec(v190);
          qdf_mem_skb_total_dec(v190);
          dma_unmap_page_attrs(*(_QWORD *)(v186 + 40), v188, v187, 2, 0);
        }
        v119 = *((_BYTE *)v41 + 30) & 0xFC;
        goto LABEL_72;
      }
      v158 = *(_QWORD *)(*(_QWORD *)(v168 + 8) + 40LL);
    }
    if ( (wlan_cfg_is_lapb_enabled(v158) & 1) != 0 )
    {
      v168 = *(_QWORD *)(v7 + 24);
      if ( (*(_DWORD *)(a3 + 168) & 0xF000000) == 0xB000000 )
        LOBYTE(v168) = *(_BYTE *)(*(_QWORD *)(v168 + 8) + 7153LL) - 1;
      else
        LODWORD(v168) = *(unsigned __int16 *)(a3 + 124) % (*(unsigned __int8 *)(*(_QWORD *)(v168 + 8) + 7153LL) - 1);
    }
    else
    {
      LOWORD(v168) = (unsigned int)*(_WORD *)(a3 + 124)
                   % *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(v7 + 24) + 8LL) + 7153LL);
    }
    goto LABEL_64;
  }
LABEL_85:
  __break(0x5512u);
  return dp_vdev_get_ref_by_id_2();
}
