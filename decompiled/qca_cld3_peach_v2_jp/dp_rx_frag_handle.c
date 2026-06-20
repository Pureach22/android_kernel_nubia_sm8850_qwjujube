__int64 __fastcall dp_rx_frag_handle(
        __int64 a1,
        unsigned int *a2,
        unsigned __int16 *a3,
        __int64 a4,
        _BYTE *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w24
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x26
  unsigned __int64 v36; // x24
  __int64 v37; // x27
  unsigned __int64 StatusReg; // x8
  __int64 v39; // x24
  __int64 v40; // x23
  __int64 v41; // x2
  unsigned __int16 *v42; // x24
  unsigned int v43; // t1
  int v44; // w8
  __int64 result; // x0
  __int64 v46; // x1
  __int64 v47; // x21
  __int64 v48; // x24
  __int64 v49; // x25
  __int64 v50; // x0
  __int64 v51; // x23
  __int64 v52; // x8
  __int64 v53; // x0
  __int64 v54; // x27
  __int64 (*v55)(void); // x8
  unsigned int v56; // w25
  __int64 (__fastcall *v57)(_QWORD); // x9
  __int64 v58; // x0
  unsigned __int16 v59; // w0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x24
  int v69; // w8
  unsigned int *v70; // x23
  int v71; // w9
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned __int16 *v80; // x23
  char v81; // w8
  __int64 v82; // x8
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  unsigned int v91; // w21
  __int64 v92; // x21
  __int64 v93; // x4
  __int64 v94; // x5
  __int64 v95; // x6
  unsigned int v96; // w19
  __int64 v97; // x0
  __int64 (__fastcall *v98)(_QWORD); // x8
  int v99; // w0
  unsigned int v100; // w9
  unsigned int v101; // w23
  unsigned int v102; // w8
  int v103; // w9
  int v104; // w9
  int v105; // w10
  __int64 v106; // x1
  __int64 (__fastcall *v107)(__int64, __int64); // x8
  unsigned __int16 v108; // w26
  __int64 ref_by_id_0; // x0
  __int64 v110; // x0
  unsigned __int8 (__fastcall *v111)(_QWORD); // x8
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  __int64 v120; // x0
  unsigned __int8 (__fastcall *v121)(_QWORD); // x8
  __int64 v122; // x0
  __int64 v123; // x8
  unsigned __int8 *v124; // x12
  char v125; // w10
  __int64 v126; // x21
  void (__fastcall *v127)(__int64, __int64, __int64, __int64, __int64, __int64); // x26
  unsigned __int64 v128; // x8
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  __int64 *v137; // x26
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  int v146; // w26
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  __int64 v155; // x4
  double v156; // d0
  double v157; // d1
  double v158; // d2
  double v159; // d3
  double v160; // d4
  double v161; // d5
  double v162; // d6
  double v163; // d7
  double v164; // d0
  double v165; // d1
  double v166; // d2
  double v167; // d3
  double v168; // d4
  double v169; // d5
  double v170; // d6
  double v171; // d7
  __int64 v172; // x23
  const char *v173; // x2
  double v174; // d0
  double v175; // d1
  double v176; // d2
  double v177; // d3
  double v178; // d4
  double v179; // d5
  double v180; // d6
  double v181; // d7
  char v182; // w8
  __int64 v183; // x8
  __int64 v184; // x22
  double v185; // d0
  double v186; // d1
  double v187; // d2
  double v188; // d3
  double v189; // d4
  double v190; // d5
  double v191; // d6
  double v192; // d7
  unsigned __int8 *v193; // x24
  unsigned int v194; // w21
  __int64 v195; // x3
  __int64 v196; // x4
  __int64 v197; // x5
  double v198; // d0
  double v199; // d1
  double v200; // d2
  double v201; // d3
  double v202; // d4
  double v203; // d5
  double v204; // d6
  double v205; // d7
  double v206; // d0
  double v207; // d1
  double v208; // d2
  double v209; // d3
  double v210; // d4
  double v211; // d5
  double v212; // d6
  double v213; // d7
  __int64 v214; // x8
  char v215; // w9
  __int64 v216; // x9
  unsigned int v217; // w21
  double v218; // d0
  double v219; // d1
  double v220; // d2
  double v221; // d3
  double v222; // d4
  double v223; // d5
  double v224; // d6
  double v225; // d7
  __int64 v226; // x0
  double v227; // d0
  double v228; // d1
  double v229; // d2
  double v230; // d3
  double v231; // d4
  double v232; // d5
  double v233; // d6
  double v234; // d7
  double v235; // d0
  double v236; // d1
  double v237; // d2
  double v238; // d3
  double v239; // d4
  double v240; // d5
  double v241; // d6
  double v242; // d7
  double v243; // d0
  double v244; // d1
  double v245; // d2
  double v246; // d3
  double v247; // d4
  double v248; // d5
  double v249; // d6
  double v250; // d7
  double v251; // d0
  double v252; // d1
  double v253; // d2
  double v254; // d3
  double v255; // d4
  double v256; // d5
  double v257; // d6
  double v258; // d7
  __int64 v259; // x21
  void (__fastcall *v260)(_QWORD); // x8
  _DWORD *v261; // x8
  unsigned __int64 v262; // x21
  __int64 v263; // x8
  __int64 v264; // x2
  __int64 v265; // x1
  __int64 v266; // x8
  __int64 v267; // x25
  unsigned __int8 *v268; // [xsp+10h] [xbp-40h]
  char v269; // [xsp+18h] [xbp-38h]
  __int64 *v270; // [xsp+18h] [xbp-38h]
  char v271; // [xsp+20h] [xbp-30h]
  int v272; // [xsp+20h] [xbp-30h]
  unsigned __int16 v273; // [xsp+24h] [xbp-2Ch]
  unsigned int *v274; // [xsp+28h] [xbp-28h]
  char v275[4]; // [xsp+34h] [xbp-1Ch] BYREF
  __int64 v276; // [xsp+38h] [xbp-18h] BYREF
  _QWORD v277[2]; // [xsp+40h] [xbp-10h] BYREF

  v277[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x45u,
    8u,
    "%s: Number of MSDUs to process, num_msdus: %d",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "dp_rx_frag_handle",
    *a3);
  if ( !*a3 )
  {
    qdf_trace_msg(0x3Fu, 2u, "Not sufficient MSDUs to process", v18, v19, v20, v21, v22, v23, v24, v25);
    result = 0;
    goto LABEL_18;
  }
  v26 = *(unsigned __int8 *)(a4 + 28);
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40))
    && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a1 + 40), v26)
    || (v35 = *(_QWORD *)(a1 + 72)) == 0 )
  {
    qdf_trace_msg(
      0x45u,
      8u,
      "pdev is null for pool_id = %d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      *(unsigned __int8 *)(a4 + 28));
    goto LABEL_17;
  }
  v36 = *(unsigned __int8 *)(a4 + 28);
  *a5 = v36;
  if ( v36 < 5 )
  {
    if ( (*(_BYTE *)(a4 + 30) & 2) == 0 )
    {
      v37 = *(_QWORD *)a4;
      v274 = a2;
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
      v39 = a1 + 12368 + 120LL * (unsigned int)v36;
      v40 = *(_QWORD *)a4;
      v43 = *(unsigned __int16 *)(v39 + 74);
      v42 = (unsigned __int16 *)(v39 + 74);
      v41 = v43;
      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 831LL) & 1) != 0 )
        goto LABEL_23;
      v44 = *(_DWORD *)(v40 + 48);
      if ( *(_DWORD *)(a1 + 20208) )
      {
        if ( (v44 & 0x2000000) == 0 )
        {
          if ( a1 )
            ++*(_DWORD *)(a1 + 14028);
LABEL_23:
          dp_ipa_handle_rx_buf_smmu_mapping(a1, v40, v41, 0, "dp_rx_nbuf_unmap_pool", 3162, 0);
          v47 = *(_QWORD *)(a1 + 24);
          v48 = *v42;
          v49 = *(_QWORD *)(v40 + 40);
          if ( (_qdf_is_pp_nbuf(v40) & 1) != 0 && *(_QWORD *)(v40 + 40) )
          {
            v50 = *(_QWORD *)(v47 + 40);
            if ( (*(_BYTE *)(v50 + 844) & 0x40) == 0 )
              _dma_sync_single_for_cpu(v50, v49);
          }
          else if ( v49 )
          {
            v51 = *(int *)(v40 + 212);
            qdf_mem_dp_rx_skb_cnt_dec();
            qdf_mem_dp_rx_skb_dec(v51);
            qdf_mem_skb_total_dec(v51);
            dma_unmap_page_attrs(*(_QWORD *)(v47 + 40), v49, v48, 2, 0);
          }
          *(_BYTE *)(a4 + 30) |= 2u;
          v52 = *(_QWORD *)(a1 + 18472);
          if ( (v52 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 18472) = v52 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 18464);
          }
          else
          {
            raw_spin_unlock(a1 + 18464);
          }
          v53 = *(_QWORD *)(v37 + 224);
          v54 = v35 + 94208;
          *(_QWORD *)(a4 + 8) = v53;
          v55 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 392LL);
          if ( *((_DWORD *)v55 - 1) != 855462014 )
            __break(0x8228u);
          v56 = v55();
          v57 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 856LL);
          v58 = *(_QWORD *)(a4 + 8);
          if ( *((_DWORD *)v57 - 1) != 646946022 )
            __break(0x8229u);
          v59 = v57(v58);
          a3[1] = v59;
          v68 = *(_QWORD *)a4;
          v276 = 0;
          v275[0] = 0;
          if ( (*(_BYTE *)(v68 + 68) & 4) != 0 )
          {
            v70 = (unsigned int *)(v68 + 112);
            v69 = *(_DWORD *)(v68 + 112);
            v71 = *(unsigned __int16 *)(v68 + 66);
            if ( v69 + v71 )
            {
LABEL_41:
              qdf_trace_msg(
                0x45u,
                5u,
                "%s: Dropping unexpected packet with skb_len: %d data len: %d cookie: %d",
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                v66,
                v67,
                "dp_rx_defrag_store_fragment",
                (unsigned int)(v71 + v69),
                *(unsigned int *)(v68 + 116),
                *(unsigned int *)(a4 + 24));
              v80 = nullptr;
              if ( a1 )
                ++*(_DWORD *)(a1 + 13620);
              goto LABEL_43;
            }
          }
          else
          {
            v70 = (unsigned int *)(v68 + 112);
            v69 = *(_DWORD *)(v68 + 112);
            if ( v69 )
            {
              v71 = 0;
              goto LABEL_41;
            }
          }
          v273 = v59;
          if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD))dp_rx_buffer_pool_refill)(
                  a1,
                  v68,
                  *(unsigned __int8 *)(a4 + 28))
              & 1) != 0 )
          {
            v80 = nullptr;
            goto LABEL_45;
          }
          v97 = *(_QWORD *)(a4 + 8);
          v98 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1272LL);
          if ( *((_DWORD *)v98 - 1) != 855462014 )
            __break(0x8228u);
          v99 = v98(v97);
          v100 = *v70;
          v101 = v99 + *(unsigned __int16 *)(a1 + 1138);
          v102 = v101 - v100;
          if ( v101 < v100 )
          {
            skb_trim(v68, v101);
            goto LABEL_68;
          }
          if ( *(_DWORD *)(v68 + 116) )
          {
            v102 = v101 - v100;
            if ( v101 != v100 )
            {
              v103 = 0;
              goto LABEL_65;
            }
          }
          else
          {
            v105 = *(_DWORD *)(v68 + 208);
            v104 = *(_DWORD *)(v68 + 212);
            if ( v104 - v105 < v102 )
            {
              v103 = v105 - v104;
LABEL_65:
              if ( (unsigned int)pskb_expand_head(v68, 0, v103 + v102, 2080) )
                dev_kfree_skb_any_reason(v68, 1);
            }
          }
          skb_put(v68, v101 - *(_DWORD *)(v68 + 112));
LABEL_68:
          *(_QWORD *)(*(_QWORD *)(v68 + 216) + *(unsigned int *)(v68 + 212) + 8LL) = 0;
          v106 = *((unsigned int *)a3 + 2);
          v107 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 1432);
          if ( *((_DWORD *)v107 - 1) != 1020823628 )
            __break(0x8228u);
          v108 = v107(a1, v106);
          ref_by_id_0 = dp_txrx_peer_get_ref_by_id_0(a1, v108, &v276);
          if ( !ref_by_id_0 )
          {
            v172 = jiffies;
            if ( dp_rx_defrag_store_fragment___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x45u,
                5u,
                "%s: Unknown peer with peer_id %d, dropping fragment",
                v72,
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                "dp_rx_defrag_store_fragment",
                v108);
              dp_rx_defrag_store_fragment___last_ticks = v172;
            }
            v80 = nullptr;
            if ( a1 )
              ++*(_DWORD *)(a1 + 13624);
            goto LABEL_43;
          }
          v80 = (unsigned __int16 *)ref_by_id_0;
          if ( v56 >= 0x11 )
          {
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: TID out of bounds: %d",
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              "dp_rx_defrag_store_fragment",
              v56);
            v226 = printk(
                     &unk_9BB309,
                     "0",
                     "dp_rx_defrag_store_fragment",
                     "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_defrag.c");
            dump_stack(v226);
            goto LABEL_43;
          }
          v110 = *(_QWORD *)(a4 + 8);
          v111 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 664LL);
          if ( *((_DWORD *)v111 - 1) != -1147376687 )
            __break(0x8228u);
          if ( v111(v110) )
          {
            v120 = *(_QWORD *)(a4 + 8);
            v121 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 624LL);
            if ( *((_DWORD *)v121 - 1) != -1147376687 )
              __break(0x8228u);
            if ( v121(v120) )
            {
              v122 = *(_QWORD *)(a1 + 40);
              v123 = *(_QWORD *)(a4 + 8) + *(unsigned __int16 *)(a1 + 1138);
              v124 = *(unsigned __int8 **)(*(_QWORD *)v80 + 24LL);
              v125 = *(_BYTE *)(v123 + 1);
              LOBYTE(v123) = *(_BYTE *)(v123 + 22);
              v277[0] = 0;
              v271 = v125;
              v126 = (__int64)&v80[60 * v56 + 88];
              v269 = v123;
              v127 = *((void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))v124 + 11948);
              v268 = v124;
              wlan_cfg_rx_buffer_size(v122);
              if ( v127 )
              {
                v259 = *(_QWORD *)(v68 + 224);
                v260 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1272LL);
                if ( *((_DWORD *)v260 - 1) != 855462014 )
                  __break(0x8228u);
                v260(v259);
                v261 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 880LL);
                if ( *(v261 - 1) != -177782713 )
                  __break(0x8228u);
                ((void (__fastcall *)(__int64, _QWORD *))v261)(v259, v277);
                if ( a3[6] || (a3[3] & 0x10) != 0 )
                  v262 = *(unsigned __int16 *)(a1 + 1138);
                else
                  v262 = LOWORD(v277[0]) + (unsigned __int64)*(unsigned __int16 *)(a1 + 1138);
                v263 = *(_QWORD *)(v68 + 40);
                if ( v263 )
                  *(_QWORD *)(v68 + 40) = v263 + v262;
                skb_pull(v68, (unsigned int)v262);
                v264 = *(unsigned __int8 *)(v68 + 86);
                v265 = *v268;
                if ( *((_DWORD *)v127 - 1) != -915278510 )
                  __break(0x823Au);
                v127(a1, v265, v264, v68, 1, 3);
                v266 = *(_QWORD *)(v68 + 40);
                if ( v266 )
                  *(_QWORD *)(v68 + 40) = v266 - v262;
                skb_push(v68, (unsigned int)v262);
                v126 = (__int64)&v80[60 * v56 + 88];
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
                  goto LABEL_82;
              }
              else if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
              {
                goto LABEL_82;
              }
              v128 = _ReadStatusReg(SP_EL0);
              if ( (*(_DWORD *)(v128 + 16) & 0xF0000) == 0 && (*(_DWORD *)(v128 + 16) & 0xFF00) == 0 )
              {
                raw_spin_lock_bh(v126 + 72);
                *(_QWORD *)(v126 + 80) |= 1uLL;
                v137 = *(__int64 **)(v126 + 48);
                if ( v137 )
                  goto LABEL_83;
                goto LABEL_147;
              }
LABEL_82:
              raw_spin_lock(v126 + 72);
              v137 = *(__int64 **)(v126 + 48);
              if ( v137 )
              {
LABEL_83:
                if ( v271 & 4 | v269 & 0xF || *v137 )
                {
                  v272 = v269 & 0xF;
                  qdf_trace_msg(
                    0x45u,
                    8u,
                    "%s: rx_tid %d",
                    v129,
                    v130,
                    v131,
                    v132,
                    v133,
                    v134,
                    v135,
                    v136,
                    "dp_rx_defrag_store_fragment",
                    v56);
                  if ( *v137 )
                  {
                    v270 = v137;
                    v146 = v273;
                    qdf_trace_msg(
                      0x45u,
                      8u,
                      "%s: rxseq %d",
                      v138,
                      v139,
                      v140,
                      v141,
                      v142,
                      v143,
                      v144,
                      v145,
                      "dp_rx_defrag_store_fragment",
                      v273);
                    v155 = *(unsigned int *)(v126 + 40);
                    if ( (_DWORD)v155 == v273 )
                      goto LABEL_100;
                    qdf_trace_msg(
                      0x45u,
                      8u,
                      "%s: mismatch cur_seq %d rxseq %d",
                      v147,
                      v148,
                      v149,
                      v150,
                      v151,
                      v152,
                      v153,
                      v154,
                      "dp_rx_defrag_store_fragment",
                      v155,
                      v273);
                    dp_rx_reorder_flush_frag((__int64)v80, v56, v156, v157, v158, v159, v160, v161, v162, v163);
                    if ( a1 )
                      ++*(_DWORD *)(a1 + 13616);
                    qdf_trace_msg(
                      0x45u,
                      8u,
                      "%s: cur rxseq %d",
                      v164,
                      v165,
                      v166,
                      v167,
                      v168,
                      v169,
                      v170,
                      v171,
                      "dp_rx_defrag_store_fragment",
                      v273);
LABEL_99:
                    *(_DWORD *)(v126 + 40) = v146;
LABEL_100:
                    if ( v272
                       | (unsigned int)((__int64 (__fastcall *)(unsigned __int16 *, _QWORD, __int64 *, __int64 *, __int64, char *))dp_rx_defrag_fraglist_insert)(
                                         v80,
                                         v56,
                                         v270,
                                         v270 + 1,
                                         v68,
                                         v275)
                      || *v270 != v68 )
                    {
                      v182 = *(_BYTE *)(a4 + 30);
                      *(_QWORD *)a4 = 0;
                      *(_BYTE *)(a4 + 30) = v182 & 0xFE;
                      *(_QWORD *)a4 = *(_QWORD *)(v54 + 1016);
                      v183 = *(_QWORD *)(v54 + 1024);
                      *(_QWORD *)(v54 + 1016) = a4;
                      if ( !v183 || !*(_QWORD *)a4 )
                        *(_QWORD *)(v54 + 1024) = a4;
                      v184 = v126;
                      v193 = v268;
                      if ( (unsigned int)dp_rx_link_desc_return(
                                           a1,
                                           v274,
                                           0,
                                           v174,
                                           v175,
                                           v176,
                                           v177,
                                           v178,
                                           v179,
                                           v180,
                                           v181) )
                        qdf_trace_msg(
                          0x45u,
                          2u,
                          "%s: Failed to return link desc",
                          v185,
                          v186,
                          v187,
                          v188,
                          v189,
                          v190,
                          v191,
                          v192,
                          "dp_rx_defrag_store_fragment");
                      v194 = 1;
                      goto LABEL_108;
                    }
                    if ( !(unsigned int)dp_rx_defrag_save_info_from_ring_desc(a1, v274, a4, v80, v56) )
                    {
                      v193 = v268;
                      v184 = v126;
                      v194 = 0;
LABEL_108:
                      if ( *(_DWORD *)(*((_QWORD *)v193 + 1) + 13152LL) )
                        dp_rx_defrag_waitlist_remove(v80, v56, v185, v186, v187, v188, v189, v190, v191, v192);
                      if ( v275[0] )
                      {
                        qdf_trace_msg(
                          0x3Fu,
                          8u,
                          "All fragments received for sequence: %d",
                          v185,
                          v186,
                          v187,
                          v188,
                          v189,
                          v190,
                          v191,
                          v192,
                          v273);
                        if ( (unsigned int)((__int64 (__fastcall *)(unsigned __int16 *, _QWORD, __int64))dp_rx_defrag)(
                                             v80,
                                             v56,
                                             *v270) )
                        {
                          qdf_trace_msg(
                            0x3Fu,
                            2u,
                            "Fragment processing failed",
                            v198,
                            v199,
                            v200,
                            v201,
                            v202,
                            v203,
                            v204,
                            v205);
                          v214 = *(_QWORD *)(v184 + 32);
                          v215 = *(_BYTE *)(v214 + 30);
                          *(_QWORD *)v214 = 0;
                          *(_BYTE *)(v214 + 30) = v215 & 0xFE;
                          *(_QWORD *)v214 = *(_QWORD *)(v54 + 1016);
                          v216 = *(_QWORD *)(v54 + 1024);
                          *(_QWORD *)(v54 + 1016) = v214;
                          if ( !v216 || !*(_QWORD *)v214 )
                            *(_QWORD *)(v54 + 1024) = v214;
                          v217 = v194 + 1;
                          if ( (unsigned int)dp_rx_link_desc_return(
                                               a1,
                                               *(unsigned int **)(v184 + 24),
                                               0,
                                               v206,
                                               v207,
                                               v208,
                                               v209,
                                               v210,
                                               v211,
                                               v212,
                                               v213) )
                            qdf_trace_msg(
                              0x45u,
                              2u,
                              "%s: Failed to return link desc",
                              v218,
                              v219,
                              v220,
                              v221,
                              v222,
                              v223,
                              v224,
                              v225,
                              "dp_rx_defrag_store_fragment");
                          ((void (__fastcall *)(unsigned __int16 *, _QWORD))dp_rx_defrag_cleanup)(v80, v56);
                          qdf_spin_unlock_bh_7(v184 + 72);
                          LODWORD(result) = v217;
LABEL_51:
                          v91 = result;
                          dp_txrx_peer_unref_delete(v276, 4u, v83, v84, v85, v86, v87, v88, v89, v90);
                          result = v91;
LABEL_52:
                          if ( a1 )
                            ++*(_DWORD *)(a1 + 13612);
                          v92 = jiffies;
                          if ( dp_rx_frag_handle___last_ticks - jiffies + 125 < 0 )
                          {
                            v93 = a3[1];
                            v94 = *a3;
                            v95 = *((unsigned int *)a3 + 1);
                            v96 = result;
                            qdf_trace_msg(
                              0x45u,
                              5u,
                              "%s: Rx Defrag err seq#:0x%x msdu_count:%d flags:%d",
                              v83,
                              v84,
                              v85,
                              v86,
                              v87,
                              v88,
                              v89,
                              v90,
                              "dp_rx_frag_handle",
                              v93,
                              v94,
                              v95);
                            result = v96;
                            dp_rx_frag_handle___last_ticks = v92;
                          }
                          goto LABEL_18;
                        }
                        dp_rx_defrag_reo_reinject((__int64)v80, v56, *v270, v195, v196, v197);
                        *v270 = 0;
                        v270[1] = 0;
                        qdf_trace_msg(
                          0x3Fu,
                          8u,
                          "Fragmented sequence successfully reinjected",
                          v243,
                          v244,
                          v245,
                          v246,
                          v247,
                          v248,
                          v249,
                          v250);
                        ((void (__fastcall *)(unsigned __int16 *, _QWORD))dp_rx_defrag_cleanup)(v80, v56);
                        qdf_spin_unlock_bh_7(v184 + 72);
                        dp_txrx_peer_unref_delete(v276, 4u, v251, v252, v253, v254, v255, v256, v257, v258);
                      }
                      else
                      {
                        *(_DWORD *)(v184 + 104) = *(_DWORD *)(*((_QWORD *)v193 + 1) + 13128LL)
                                                + jiffies_to_msecs(jiffies);
                        dp_rx_defrag_waitlist_add(v80, v56, v227, v228, v229, v230, v231, v232, v233, v234);
                        dp_txrx_peer_unref_delete(v276, 4u, v235, v236, v237, v238, v239, v240, v241, v242);
                        qdf_spin_unlock_bh_7(v184 + 72);
                      }
                      result = v194;
LABEL_18:
                      _ReadStatusReg(SP_EL0);
                      return result;
                    }
                    qdf_trace_msg(
                      0x45u,
                      2u,
                      "%s: Unable to store ring desc !",
                      v185,
                      v186,
                      v187,
                      v188,
                      v189,
                      v190,
                      v191,
                      v192,
                      "dp_rx_defrag_store_fragment");
                    goto LABEL_125;
                  }
                  if ( (v269 & 0xF) == 0 )
                  {
                    v270 = v137;
                    v146 = v273;
                    qdf_trace_msg(
                      0x45u,
                      8u,
                      "%s: cur rxseq %d",
                      v138,
                      v139,
                      v140,
                      v141,
                      v142,
                      v143,
                      v144,
                      v145,
                      "dp_rx_defrag_store_fragment",
                      v273);
                    ((void (__fastcall *)(unsigned __int16 *, _QWORD))dp_rx_defrag_cleanup)(v80, v56);
                    goto LABEL_99;
                  }
                }
                else
                {
                  qdf_trace_msg(
                    0x3Fu,
                    2u,
                    "Rcvd unfragmented pkt on REO Err srng, dropping",
                    v129,
                    v130,
                    v131,
                    v132,
                    v133,
                    v134,
                    v135,
                    v136);
                }
LABEL_125:
                qdf_spin_unlock_bh_7(v126 + 72);
LABEL_43:
                if ( v68 )
                  _qdf_nbuf_free(v68);
LABEL_45:
                v81 = *(_BYTE *)(a4 + 30);
                *(_QWORD *)a4 = 0;
                *(_BYTE *)(a4 + 30) = v81 & 0xFE;
                *(_QWORD *)a4 = *(_QWORD *)(v54 + 1016);
                v82 = *(_QWORD *)(v54 + 1024);
                *(_QWORD *)(v54 + 1016) = a4;
                if ( !v82 || !*(_QWORD *)a4 )
                  *(_QWORD *)(v54 + 1024) = a4;
                if ( (unsigned int)dp_rx_link_desc_return(a1, v274, 0, v72, v73, v74, v75, v76, v77, v78, v79) )
                  qdf_trace_msg(
                    0x45u,
                    2u,
                    "%s: Failed to return link desc",
                    v83,
                    v84,
                    v85,
                    v86,
                    v87,
                    v88,
                    v89,
                    v90,
                    "dp_rx_defrag_store_fragment");
                result = 1;
                if ( !v80 )
                  goto LABEL_52;
                goto LABEL_51;
              }
LABEL_147:
              v267 = jiffies;
              if ( dp_rx_defrag_store_fragment___last_ticks_52 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x45u,
                  2u,
                  "%s: Rcvd Fragmented pkt before tid setup for peer %pK",
                  v129,
                  v130,
                  v131,
                  v132,
                  v133,
                  v134,
                  v135,
                  v136,
                  "dp_rx_defrag_store_fragment",
                  v80);
                dp_rx_defrag_store_fragment___last_ticks_52 = v267;
              }
              qdf_spin_unlock_bh_7(v126 + 72);
              goto LABEL_43;
            }
            v173 = "Invalid frame control field, dropping MPDU";
          }
          else
          {
            v173 = "Invalid MPDU seq control field, dropping MPDU";
          }
          qdf_trace_msg(0x3Fu, 2u, v173, v112, v113, v114, v115, v116, v117, v118, v119);
          goto LABEL_43;
        }
      }
      else
      {
        if ( (v44 & 0x2000000) == 0 )
          goto LABEL_23;
        if ( a1 )
        {
          ++*(_DWORD *)(a1 + 14032);
          v44 = *(_DWORD *)(v40 + 48);
        }
      }
      v46 = *(_QWORD *)(v40 + 40);
      *(_DWORD *)(v40 + 48) = v44 & 0xFDFFFFFF;
      pld_audio_smmu_unmap(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL), v46, v41);
      v41 = *v42;
      goto LABEL_23;
    }
LABEL_17:
    result = 0;
    goto LABEL_18;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))dp_rx_defrag_save_info_from_ring_desc)();
}
