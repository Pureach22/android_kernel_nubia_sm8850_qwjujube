__int64 __fastcall dp_rx_mon_status_process(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  __int64 v4; // x23
  unsigned int v6; // w21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x24
  __int64 v16; // x20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w9
  unsigned int v26; // w8
  unsigned int v27; // w11
  unsigned int v28; // w10
  unsigned int v29; // w11
  unsigned int v30; // w9
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned __int8 *v39; // x24
  __int64 v40; // x19
  int v41; // w8
  int *v42; // x22
  unsigned int v43; // w28
  __int64 *v44; // x21
  __int64 *v45; // x9
  __int64 v46; // x8
  char *v47; // x20
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  char *v56; // x23
  __int64 (__fastcall *v57)(char *, __int64); // x8
  int v58; // w8
  int v59; // w10
  __int64 v60; // x9
  __int64 v61; // x8
  __int64 v62; // x9
  char *v63; // x8
  __int64 v64; // x9
  __int64 v65; // x8
  unsigned __int64 v66; // x4
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  int v75; // w8
  unsigned int v76; // w0
  unsigned __int64 v77; // x8
  __int64 v78; // x21
  __int64 v79; // x20
  __int64 v80; // x9
  unsigned __int64 v81; // x8
  __int64 v82; // x23
  unsigned __int64 v83; // x8
  int v84; // w8
  __int64 v86; // x25
  unsigned int *v87; // x27
  int v88; // w26
  bool v89; // zf
  unsigned __int64 v90; // x19
  void (__fastcall *v91)(unsigned int *, __int64 *); // x8
  __int64 v92; // x20
  __int64 v93; // x26
  __int64 v94; // x8
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  unsigned int v103; // w8
  int v104; // w9
  unsigned int v105; // w8
  int v106; // w9
  int v107; // w10
  __int64 v108; // x24
  __int64 v109; // x21
  __int64 v110; // x23
  __int64 v111; // x28
  __int64 v112; // x0
  __int64 v113; // x19
  _QWORD *v114; // x8
  int v115; // w8
  __int64 v116; // x0
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  __int64 v125; // x2
  __int64 v126; // x9
  __int64 v127; // x1
  void (__fastcall *v128)(unsigned int *, __int64, __int64, __int64); // x8
  __int64 v129; // x3
  unsigned int v130; // w10
  int v131; // w8
  unsigned int v132; // w9
  unsigned int v133; // w12
  unsigned int v134; // w11
  __int64 v135; // x0
  int v136; // w12
  unsigned int v137; // w8
  int v138; // w9
  unsigned int v139; // w10
  __int64 v140; // x19
  __int64 v141; // x5
  __int64 v142; // x4
  int v143; // w0
  __int64 v144; // x21
  char v145; // w9
  char v146; // w8
  __int64 *v147; // x9
  __int64 v148; // x3
  _DWORD *v149; // x8
  __int64 v150; // [xsp+8h] [xbp-78h]
  __int64 v153; // [xsp+20h] [xbp-60h]
  __int64 v154; // [xsp+20h] [xbp-60h]
  int v155; // [xsp+28h] [xbp-58h]
  __int64 v156; // [xsp+28h] [xbp-58h]
  __int64 v157; // [xsp+30h] [xbp-50h]
  __int64 v158; // [xsp+30h] [xbp-50h]
  __int64 v159; // [xsp+38h] [xbp-48h]
  __int64 v160; // [xsp+40h] [xbp-40h]
  int v161; // [xsp+40h] [xbp-40h]
  unsigned int v162; // [xsp+54h] [xbp-2Ch]
  __int64 *v163; // [xsp+58h] [xbp-28h] BYREF
  __int64 v164; // [xsp+60h] [xbp-20h] BYREF
  __int64 v165; // [xsp+68h] [xbp-18h] BYREF
  __int64 v166; // [xsp+70h] [xbp-10h]
  __int64 v167; // [xsp+78h] [xbp-8h]

  v4 = a1;
  v6 = a3;
  v167 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40))
    && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(v4 + 40), v6)
    || (v160 = *(_QWORD *)(v4 + 72)) == 0 )
  {
    qdf_trace_msg(
      0x84u,
      8u,
      "%s: %pK: pdev is null for mac_id = %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_rx_mon_status_srng_process",
      v4,
      v6);
    v162 = 0;
    goto LABEL_33;
  }
  if ( (unsigned __int8)v6 >= 3u || v6 >= 2 )
    goto LABEL_215;
  v15 = *(_QWORD *)(v4 + 80LL * v6 + 800);
  if ( !v15 || !*(_BYTE *)(v15 + 1) )
  {
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s %d : HAL Monitor Status Ring Init Failed -- %pK",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_rx_mon_status_srng_process",
      679,
      v15);
    v162 = 0;
    goto LABEL_33;
  }
  v16 = *(_QWORD *)(v160 + 96456);
  v159 = *(_QWORD *)(v4 + 1128);
  if ( !(unsigned int)dp_srng_access_start(a2, v4, (char *)v15) )
  {
    v25 = *(_DWORD *)(v15 + 120);
    v26 = *(_DWORD *)(v15 + 136);
    v27 = v26 - v25;
    if ( *(_DWORD *)(v15 + 116) )
    {
      if ( v26 < v25 )
        v27 += *(_DWORD *)(v15 + 36);
      v28 = *(_DWORD *)(v15 + 44);
      v29 = v27 / v28;
    }
    else
    {
      if ( v26 <= v25 )
        v27 += *(_DWORD *)(v15 + 36);
      v28 = *(_DWORD *)(v15 + 44);
      v29 = v27 / v28 - 1;
    }
    if ( v29 > *(_DWORD *)(v15 + 240) )
    {
      *(_DWORD *)(v15 + 240) = v29;
      *(_QWORD *)(v15 + 248) = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
    }
    if ( v29 >= *(_DWORD *)(v15 + 276) )
    {
      ++*(_DWORD *)(v15 + 300);
    }
    else if ( v29 >= *(_DWORD *)(v15 + 272) )
    {
      ++*(_DWORD *)(v15 + 296);
    }
    else if ( v29 >= *(_DWORD *)(v15 + 268) )
    {
      ++*(_DWORD *)(v15 + 292);
    }
    else if ( v29 >= *(_DWORD *)(v15 + 264) )
    {
      ++*(_DWORD *)(v15 + 288);
    }
    else if ( v29 >= *(_DWORD *)(v15 + 260) )
    {
      ++*(_DWORD *)(v15 + 284);
    }
    else
    {
      ++*(_DWORD *)(v15 + 280);
    }
    v30 = (v28 + v25) % *(_DWORD *)(v15 + 36);
    if ( v30 != v26 )
    {
      v154 = v15;
      v156 = v4 + 11936;
      v86 = v16 + 8 + 18528LL * (v6 & 3) + 3240;
      v162 = 0;
      v158 = v4 + 11936 + 120LL * v6;
      while ( 1 )
      {
        v87 = (unsigned int *)(*(_QWORD *)(v15 + 16) + 4LL * v30);
        v88 = v87 != nullptr;
        if ( v87 )
          v89 = a4 == 0;
        else
          v89 = 1;
        if ( v89 )
          goto LABEL_32;
        v165 = 0;
        v166 = 0;
        v90 = *v87 | ((unsigned __int64)*((unsigned __int8 *)v87 + 4) << 32);
        if ( !v90 )
        {
          v163 = nullptr;
          v164 = 0;
          if ( !(unsigned __int16)dp_rx_get_free_desc_list(v4, a3, v158, 1u, &v164, &v163) )
            goto LABEL_213;
          v92 = v164;
          goto LABEL_171;
        }
        v91 = *(void (__fastcall **)(unsigned int *, __int64 *))(*(_QWORD *)(*(_QWORD *)(v4 + 1128) + 74392LL) + 1456LL);
        if ( *((_DWORD *)v91 - 1) != -621572614 )
          __break(0x8228u);
        v91(v87, &v165);
        if ( (v166 & 0xE0000) != 0
          || (v92 = *(_QWORD *)(*(_QWORD *)(v156 + 120 * (((unsigned __int64)(unsigned int)v166 >> 16) & 1) + 24)
                              + 8LL * BYTE1(v166))
                  + (unsigned __int8)v166
                  * (unsigned int)*(unsigned __int16 *)(v156
                                                      + 120 * (((unsigned __int64)(unsigned int)v166 >> 16) & 1)
                                                      + 4)) == 0 )
        {
          v135 = printk(
                   &unk_AAA255,
                   "rx_desc",
                   "dp_rx_mon_status_srng_process",
                   "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/1.0/dp_rx_mon_status_1.0.c");
          dump_stack(v135);
          v92 = 0;
        }
        v93 = *(_QWORD *)v92;
        v94 = 40;
        if ( (*(_BYTE *)(*(_QWORD *)v92 + 68LL) & 4) != 0 )
          v94 = 80;
        if ( *(_QWORD *)(v93 + v94) != v90 )
        {
          if ( v4 )
            ++*(_DWORD *)(v4 + 14164);
          v136 = *(_DWORD *)(v15 + 120);
          v131 = *(_DWORD *)(v15 + 44);
          v132 = *(_DWORD *)(v15 + 36);
          v88 = v87 != nullptr;
          v130 = (v131 + v136) % v132;
          v134 = *(_DWORD *)(v15 + 136);
          if ( v130 == v134 )
          {
            v134 = (v131 + v136) % v132;
            v130 = *(_DWORD *)(v15 + 120);
          }
          else
          {
            *(_DWORD *)(v15 + 120) = v130;
            *(_DWORD *)(v15 + 124) = v130;
          }
          goto LABEL_179;
        }
        _qdf_nbuf_sync_for_cpu(*(_QWORD *)(v4 + 24), *(_QWORD *)v92);
        if ( (**(_DWORD **)(v93 + 224) & 0x3FE) != 0x24C )
        {
          v138 = *(_DWORD *)(v15 + 116);
          v137 = *(_DWORD *)(v15 + 120);
          v139 = **(_DWORD **)(v15 + 128);
          v140 = jiffies;
          if ( dp_rx_mon_status_srng_process___last_ticks - jiffies + 125 < 0 )
          {
            if ( v138 )
              v141 = v137;
            else
              v141 = v139;
            if ( v138 )
              v142 = v139;
            else
              v142 = v137;
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: tlv tag status error hp:%u, tp:%u",
              v95,
              v96,
              v97,
              v98,
              v99,
              v100,
              v101,
              v102,
              "dp_rx_mon_status_srng_process",
              v142,
              v141);
            dp_rx_mon_status_srng_process___last_ticks = v140;
          }
          v143 = dp_rx_mon_handle_status_buf_done(v160, v15, a3, v95, v96, v97, v98, v99, v100, v101, v102);
          if ( !v143 )
          {
            v130 = *(_DWORD *)(v15 + 120);
            v131 = *(_DWORD *)(v15 + 44);
            v132 = *(_DWORD *)(v15 + 36);
            v134 = *(_DWORD *)(v15 + 136);
            v88 = v87 != nullptr;
            goto LABEL_179;
          }
          if ( v143 == 4 )
          {
            if ( (*(_BYTE *)(v92 + 30) & 2) == 0 )
            {
              qdf_nbuf_unmap_nbytes_single_0(*(_QWORD *)(v4 + 24), v93, *(unsigned __int16 *)(v158 + 74));
              *(_BYTE *)(v92 + 30) |= 2u;
            }
            if ( v93 )
              _qdf_nbuf_free(v93);
            v15 = v154;
            v88 = v87 != nullptr;
            goto LABEL_171;
          }
        }
        v103 = *(_DWORD *)(v93 + 112);
        if ( v103 < 0x581 )
          break;
        skb_trim(v93, 1408);
LABEL_160:
        if ( (*(_BYTE *)(v92 + 30) & 2) == 0 )
        {
          v108 = v4;
          v109 = *(_QWORD *)(v4 + 24);
          v110 = *(_QWORD *)(v93 + 40);
          v111 = *(unsigned __int16 *)(v158 + 74);
          if ( (_qdf_is_pp_nbuf(v93) & 1) != 0 && *(_QWORD *)(v93 + 40) )
          {
            v112 = *(_QWORD *)(v109 + 40);
            if ( (*(_BYTE *)(v112 + 844) & 0x40) == 0 )
              _dma_sync_single_for_cpu(v112, v110);
          }
          else if ( v110 )
          {
            v113 = *(int *)(v93 + 212);
            qdf_mem_dp_rx_skb_cnt_dec();
            qdf_mem_dp_rx_skb_dec(v113);
            qdf_mem_skb_total_dec(v113);
            dma_unmap_page_attrs(*(_QWORD *)(v109 + 40), v110, v111, 2, 0);
          }
          v4 = v108;
          v15 = v154;
          *(_BYTE *)(v92 + 30) |= 2u;
        }
        *(_QWORD *)v93 = 0;
        v114 = (_QWORD *)v86;
        if ( *(_QWORD *)v86 )
          v114 = *(_QWORD **)(v86 + 8);
        *v114 = v93;
        v115 = *(_DWORD *)(v86 + 16);
        *(_QWORD *)(v86 + 8) = v93;
        v88 = v87 != nullptr;
        *(_DWORD *)(v86 + 16) = v115 + 1;
LABEL_171:
        v116 = dp_rx_nbuf_prepare(v4, v160);
        if ( !v116 )
        {
          v163 = nullptr;
          v164 = 0;
          v144 = jiffies;
          if ( dp_rx_mon_status_srng_process___last_ticks_14 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: fail to allocate or map qdf_nbuf",
              v117,
              v118,
              v119,
              v120,
              v121,
              v122,
              v123,
              v124,
              "dp_rx_mon_status_srng_process");
            dp_rx_mon_status_srng_process___last_ticks_14 = v144;
          }
          *(_QWORD *)v92 = 0;
          v145 = *(_BYTE *)(v92 + 30);
          *(_QWORD *)v92 = v164;
          v146 = v145 & 0xFE;
          v147 = v163;
          *(_BYTE *)(v92 + 30) = v146;
          v164 = v92;
          if ( !v147 || !*(_QWORD *)v92 )
            v163 = (__int64 *)v92;
          dp_rx_add_desc_list_to_free_list(v4, &v164, &v163, a3, v158);
          v148 = (unsigned int)*(unsigned __int8 *)(v4 + 20060) + 3;
          v149 = *(_DWORD **)(*(_QWORD *)(v159 + 74392) + 1472LL);
          if ( *(v149 - 1) != -1494657337 )
            __break(0x8228u);
          ((void (__fastcall *)(unsigned int *, _QWORD, _QWORD, __int64))v149)(v87, 0, 0, v148);
LABEL_213:
          ++v162;
          goto LABEL_32;
        }
        v125 = *(unsigned int *)(v92 + 24);
        v126 = 40;
        if ( (*(_BYTE *)(v116 + 68) & 4) != 0 )
          v126 = 80;
        v127 = *(_QWORD *)(v116 + v126);
        *(_BYTE *)(v92 + 30) = *(_BYTE *)(v92 + 30) & 0xFC | 1;
        *(_QWORD *)v92 = v116;
        v128 = *(void (__fastcall **)(unsigned int *, __int64, __int64, __int64))(*(_QWORD *)(v159 + 74392) + 1472LL);
        v129 = (unsigned int)*(unsigned __int8 *)(v4 + 20060) + 3;
        if ( *((_DWORD *)v128 - 1) != -1494657337 )
          __break(0x8228u);
        v128(v87, v127, v125, v129);
        v130 = *(_DWORD *)(v15 + 120);
        v131 = *(_DWORD *)(v15 + 44);
        v132 = *(_DWORD *)(v15 + 36);
        v133 = (v131 + v130) % v132;
        v134 = *(_DWORD *)(v15 + 136);
        if ( v133 != v134 )
        {
          v130 = (v131 + v130) % v132;
          *(_DWORD *)(v15 + 120) = v133;
          *(_DWORD *)(v15 + 124) = v133;
        }
        ++v162;
LABEL_179:
        a4 -= v88;
        v30 = (v130 + v131) % v132;
        if ( v30 == v134 )
          goto LABEL_32;
      }
      if ( *(_DWORD *)(v93 + 116) )
      {
        if ( v103 != 1408 )
        {
          v104 = 0;
          v105 = 1408 - v103;
          goto LABEL_157;
        }
      }
      else
      {
        v107 = *(_DWORD *)(v93 + 208);
        v106 = *(_DWORD *)(v93 + 212);
        v105 = 1408 - v103;
        if ( v106 - v107 < v105 )
        {
          v104 = v107 - v106;
LABEL_157:
          if ( (unsigned int)pskb_expand_head(v93, 0, v104 + v105, 2080) )
            dev_kfree_skb_any_reason(v93, 1);
        }
      }
      skb_put(v93, (unsigned int)(1408 - *(_DWORD *)(v93 + 112)));
      goto LABEL_160;
    }
  }
  v162 = 0;
LABEL_32:
  dp_srng_access_end(a2, v4, (char *)v15, v17, v18, v19, v20, v21, v22, v23, v24);
  v6 = a3;
LABEL_33:
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v4 + 40))
    && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(v4 + 40), v6)
    || (v39 = *(unsigned __int8 **)(v4 + 72)) == nullptr )
  {
    qdf_trace_msg(
      0x84u,
      8u,
      "%s: %pK: pdev is null for mac_id = %d",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "dp_rx_mon_status_process_tlv",
      v4,
      v6);
    goto LABEL_135;
  }
  v150 = v4;
  if ( (unsigned __int8)v6 >= 3u )
LABEL_215:
    __break(0x5512u);
  v40 = *((_QWORD *)v39 + 12057) + 18528LL * (v6 & 3);
  v157 = *((_QWORD *)v39 + 12057);
  if ( !*(_DWORD *)(v40 + 56) )
  {
    v41 = *(_DWORD *)(v40 + 3264);
    if ( v41 )
    {
      v42 = (int *)(v40 + 60);
      v43 = 2;
      v153 = *(_QWORD *)(v4 + 20112);
      v155 = *(unsigned __int8 *)(v157 + 39080);
      v161 = -1;
      while ( 1 )
      {
        v44 = *(__int64 **)(v40 + 3248);
        if ( !v44 )
          goto LABEL_135;
        v45 = *(__int64 **)(v40 + 3256);
        *(_DWORD *)(v40 + 3264) = v41 - 1;
        if ( v44 == v45 )
        {
          v46 = 0;
          *(_QWORD *)(v40 + 3256) = 0;
        }
        else
        {
          v46 = *v44;
        }
        *(_QWORD *)(v40 + 3248) = v46;
        *v44 = 0;
        v47 = (char *)v44[28];
        if ( *(_QWORD *)(v40 + 16)
          || *(_BYTE *)(v157 + 37256)
          || *(_DWORD *)(v157 + 39100)
          || (dp_cfr_rcc_mode_status(v39) & 1) != 0
          || (*(_BYTE *)(v157 + 39274) & 1) != 0
          || v155 )
        {
          break;
        }
LABEL_79:
        v65 = v40 + 3672 + 344LL * *(unsigned __int8 *)(v40 + 16625);
        v66 = *(unsigned __int8 *)(v65 + 306);
        if ( v66 >= 0xB )
          goto LABEL_215;
        *(_BYTE *)(v65 + 306) = encrypt_map[v66];
        qdf_trace_msg(
          0x92u,
          8u,
          "User: %d TLV enc_type = %d map enc_type = %d direction = %d",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55);
        dp_mon_rx_stats_update_rssi_dbm_params(v157, v40 + 3272);
        if ( *(_BYTE *)(v157 + 39105) )
        {
          ((void (__fastcall *)(__int64, __int64, __int64 *, _QWORD))dp_rx_process_peer_based_pktlog)(
            v150,
            v40 + 3272,
            v44,
            *v39);
        }
        else
        {
          v75 = *(unsigned __int8 *)(v157 + 39097);
          if ( v75 == 1 )
          {
            v76 = 265;
LABEL_128:
            v161 = v76;
            dp_wdi_event_handler(v76, v150, (__int64)v44, 0xFFFFu, 0xFFFFFFFF, *v39);
            goto LABEL_85;
          }
          if ( v75 == 2 )
          {
            v76 = 267;
            goto LABEL_128;
          }
          v76 = v161;
          if ( v161 != -1 )
            goto LABEL_128;
          v161 = -1;
        }
LABEL_85:
        if ( (*(_BYTE *)(v40 + 3369) & 2) != 0 && *(_BYTE *)(v157 + 37218) == 1 && *(_QWORD *)(v40 + 16) )
        {
          if ( (unsigned int)((__int64 (__fastcall *)(__int64, unsigned __int8 *, __int64, __int64 *, _QWORD))dp_rx_handle_smart_mesh_mode)(
                               v150,
                               v39,
                               v40 + 3272,
                               v44,
                               a3) )
            goto LABEL_90;
        }
        else if ( (*(_BYTE *)(v157 + 39317) & 1) != 0 || !*(_DWORD *)(v157 + 39100) )
        {
LABEL_90:
          _qdf_nbuf_free((__int64)v44);
        }
        if ( v43 != 1 )
        {
          if ( v43 != 3 )
            goto LABEL_42;
          dp_rx_mon_deliver_non_std(v150, a3);
          goto LABEL_122;
        }
        v77 = *(_QWORD *)(v40 + 3364);
        ++*(_DWORD *)(v40 + 1908);
        if ( ((v77 >> 47) & 0xF) - 1 <= 1 && *(_BYTE *)(v40 + 3291) )
        {
          v78 = v40 + 3672;
          if ( *(unsigned __int8 *)(v40 + 3291) >= 0x25u )
            v79 = 37;
          else
            v79 = *(unsigned __int8 *)(v40 + 3291);
          do
          {
            if ( *(_DWORD *)(v78 + 8) >> 30 == 1 )
            {
              v81 = *(unsigned int *)(v78 + 12);
              v82 = (v81 >> 16) & 7;
              v83 = *(_QWORD *)v78 & 0xFFFFFFFFFFFF8000LL
                  | (v81 >> 3) & 0xF
                  | (v81 >> 1) & 0x7F00
                  | (16 * (_BYTE)v81 + 16) & 0x70
                  | 0x80;
              *(_QWORD *)v78 = v83;
              if ( (int)v82 <= 2 )
              {
                if ( (_DWORD)v82 )
                {
                  if ( (_DWORD)v82 == 1 )
                    v80 = 0x10000;
                  else
                    v80 = 0x20000;
                }
                else
                {
                  v80 = 0x8000;
                }
              }
              else if ( (int)v82 > 4 )
              {
                if ( (_DWORD)v82 == 5 )
                {
                  v80 = 1212416;
                }
                else if ( (_DWORD)v82 == 6 )
                {
                  v80 = 2424832;
                }
                else
                {
                  qdf_trace_msg(
                    0x84u,
                    2u,
                    "%s: RU size to width convert err",
                    v67,
                    v68,
                    v69,
                    v70,
                    v71,
                    v72,
                    v73,
                    v74,
                    "dp_rx_ul_ofdma_ru_size_to_width");
                  v83 = *(_QWORD *)v78;
                  v80 = 0;
                }
              }
              else if ( (_DWORD)v82 == 3 )
              {
                v80 = 294912;
              }
              else
              {
                v80 = 589824;
              }
              *(_QWORD *)v78 = v80 | (v82 << 22) | v83 & 0xFFFFFFFFC0007FFFLL;
            }
            --v79;
            v78 += 344;
          }
          while ( v79 );
        }
        if ( !*(_BYTE *)(v157 + 37256)
          && !*(_DWORD *)(v157 + 39100)
          && (*(_BYTE *)(v157 + 37218) & 1) == 0
          && (dp_cfr_rcc_mode_status(v39) & 1) != 0 )
        {
          dp_rx_handle_cfr(v150, v39, v40 + 3272);
        }
        v84 = *(unsigned __int16 *)(v40 + 3360);
        *(_DWORD *)(v40 + 56) = 1;
        if ( v84 )
        {
          if ( *(_DWORD *)(v40 + 3356) )
            goto LABEL_120;
        }
        else
        {
          *(_WORD *)(v40 + 3360) = *(_DWORD *)(v40 + 24);
          if ( *(_DWORD *)(v40 + 3356) )
            goto LABEL_120;
        }
        *(_DWORD *)(v40 + 3356) = *(_DWORD *)(v40 + 28);
LABEL_120:
        if ( (*(_BYTE *)(v153 + 257) & 1) == 0 )
        {
          dp_rx_mon_dest_process(v150, a2, a3);
LABEL_122:
          *(_DWORD *)(v40 + 56) = 0;
          *(_BYTE *)(v40 + 3291) = 0;
          qdf_mem_set((void *)(v40 + 3344), 0x148u, 0);
          goto LABEL_42;
        }
        *(_DWORD *)(v40 + 56) = 0;
LABEL_42:
        v41 = *(_DWORD *)(v40 + 3264);
        if ( !v41 )
          goto LABEL_135;
      }
      v56 = v47;
      while ( 1 )
      {
        v57 = *(__int64 (__fastcall **)(char *, __int64))(*(_QWORD *)(*(_QWORD *)(*((_QWORD *)v39 + 1) + 1128LL)
                                                                    + 74392LL)
                                                        + 440LL);
        if ( *((_DWORD *)v57 - 1) != 624272941 )
          __break(0x8228u);
        v43 = v57(v56, v40 + 3272);
        if ( *(_BYTE *)(v157 + 39317) == 1 )
          dp_rx_handle_local_pkt_capture(v39, v40 + 3272, v44, a3, v43);
        v58 = *(unsigned __int8 *)(v40 + 16624);
        if ( v58 == 1 )
          break;
        if ( !*(_BYTE *)(v40 + 16624) )
        {
          v59 = *(_DWORD *)(v40 + 60);
          ++*(_DWORD *)(v40 + 64);
          if ( v59 != 1 )
          {
            v60 = 5;
            goto LABEL_63;
          }
          goto LABEL_64;
        }
LABEL_65:
        if ( (*(_DWORD *)v56 & 0x3FE) == 0x182 )
          v61 = 4;
        else
          v61 = (*(_DWORD *)v56 >> 10) & 0xFFF;
        v62 = 16;
        if ( !*(_BYTE *)(v157 + 39275) )
          v62 = 8;
        v63 = &v56[v62 + v61];
        v64 = -4;
        if ( *(_BYTE *)(v157 + 39275) )
          v64 = -8;
        v56 = (char *)((unsigned __int64)(v63 - 1) & v64);
        if ( (unsigned __int64)(v56 - v47) > 0x57F
          || 1408 - (v56 - v47) < (unsigned __int64)*(unsigned __int8 *)(v157 + 39276)
          || v43 > 0xA
          || ((1 << v43) & 0x561) == 0 )
        {
          goto LABEL_79;
        }
      }
      v89 = *(_DWORD *)(v40 + 60) == 0;
      v60 = 3;
      ++*(_DWORD *)(v40 + 68);
      if ( !v89 )
        v60 = 4;
      v58 = 1;
LABEL_63:
      ++v42[v60];
LABEL_64:
      *v42 = v58;
      *(_BYTE *)(v40 + 16624) = 2;
      goto LABEL_65;
    }
  }
LABEL_135:
  _ReadStatusReg(SP_EL0);
  return v162;
}
