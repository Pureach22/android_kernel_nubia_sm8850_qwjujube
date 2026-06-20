// bad sp value at call has been detected, the output may be wrong!
void __fastcall dp_tx_mon_process_2_0(
        __int64 *a1,
        __int64 a2,
        unsigned int a3,
        int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20)
{
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  __int64 v33; // x25
  __int64 v34; // x23
  __int64 v35; // x27
  __int64 v36; // x26
  unsigned __int64 StatusReg; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w8
  unsigned int v47; // w9
  unsigned int v48; // w11
  unsigned int v49; // w11
  unsigned int v50; // w11
  __int64 v51; // x21
  unsigned int v52; // w26
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x9
  int v78; // w8
  unsigned __int8 v79; // w8
  unsigned int *v84; // x8
  int v85; // w28
  unsigned __int64 v87; // x9
  unsigned __int64 v88; // x13
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  unsigned __int64 v97; // x27
  unsigned int v98; // w8
  __int16 v99; // w24
  __int64 v100; // x25
  int v101; // w9
  unsigned int v102; // w8
  _QWORD *v103; // x9
  __int64 v104; // x1
  int v105; // w9
  char v106; // w12
  int v107; // w11
  __int64 v108; // x9
  unsigned int v109; // w10
  __int64 v111; // x0
  __int64 v112; // x9
  unsigned __int64 v113; // x13
  __int64 v114; // x10
  __int64 v115; // x9
  __int64 v116; // x1
  __int64 v118; // x10
  __int64 v119; // x9
  int v120; // w9
  char v121; // w12
  int v122; // w11
  __int64 v123; // x9
  unsigned int v124; // w10
  __int64 v126; // x0
  __int64 v127; // x9
  unsigned __int64 v128; // x13
  __int64 v129; // x10
  __int64 v130; // x9
  __int64 v131; // x1
  int v132; // w9
  char v133; // w12
  int v134; // w11
  __int64 v135; // x9
  unsigned int v136; // w10
  __int64 v138; // x0
  __int64 v139; // x9
  unsigned __int64 v140; // x13
  __int64 v141; // x10
  __int64 v142; // x9
  __int64 v143; // x1
  __int64 v145; // x0
  __int64 v146; // x0
  int v147; // w9
  char v148; // w12
  int v149; // w11
  __int64 v150; // x9
  unsigned int v151; // w10
  __int64 v153; // x0
  __int64 v154; // x9
  unsigned __int64 v155; // x13
  __int64 v156; // x10
  __int64 v157; // x9
  __int64 v158; // x1
  int v160; // w8
  unsigned __int64 v161; // [xsp+60h] [xbp-50h] BYREF
  __int128 v162; // [xsp+68h] [xbp-48h]
  __int64 v163; // [xsp+78h] [xbp-38h]
  unsigned int v164; // [xsp+84h] [xbp-2Ch] BYREF
  unsigned __int64 v165; // [xsp+88h] [xbp-28h] BYREF
  _QWORD *v166; // [xsp+90h] [xbp-20h] BYREF
  __int64 v167; // [xsp+98h] [xbp-18h]
  __int64 v168; // [xsp+A0h] [xbp-10h]
  __int64 v169; // [xsp+138h] [xbp+88h]
  __int64 v170; // [xsp+148h] [xbp+98h]
  __int64 v171; // [xsp+150h] [xbp+A0h]

  v168 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(a1[5]) && (unsigned __int8)wlan_cfg_get_pdev_idx(a1[5], a3)
    || (v32 = a1[9], v33 = a1[2514], v167 = 0, v164 = 0, !v32) )
  {
    qdf_trace_msg(
      0x92u,
      2u,
      "%s: %pK: pdev is null for mac_id = %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "dp_tx_mon_srng_process_2_0",
      a1,
      a3);
    goto LABEL_20;
  }
  if ( (unsigned __int8)a3 >= 3u || a3 >= 2 )
  {
    __break(0x5512u);
    JUMPOUT(0x65FA20);
  }
  v34 = *(_QWORD *)(v33 + 80LL * a3 + 536);
  if ( !v34 || !*(_BYTE *)(v34 + 1) )
  {
    qdf_trace_msg(
      0x92u,
      2u,
      "%s: %pK: : HAL Monitor Destination Ring Init Failed -- %pK",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "dp_tx_mon_srng_process_2_0",
      a1,
      v34);
    goto LABEL_20;
  }
  v35 = *(_QWORD *)(v32 + 96456);
  if ( !v35 )
    goto LABEL_20;
  v36 = v35 + 8 + 18528LL * (a3 & 3);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v36 + 32);
  }
  else
  {
    raw_spin_lock_bh(v36 + 32);
    *(_QWORD *)(v36 + 40) |= 1uLL;
  }
  LODWORD(v167) = 0;
  v165 = 0;
  v166 = nullptr;
  if ( (unsigned int)dp_srng_access_start(a2, (__int64)a1, (char *)v34) )
  {
    qdf_trace_msg(
      0x92u,
      2u,
      "%s: %s %d : HAL Mon Dest Ring access Failed -- %pK",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "dp_tx_mon_srng_process_2_0",
      "dp_tx_mon_srng_process_2_0",
      157,
      v34);
    qdf_spin_unlock_bh_19(v36 + 32);
    goto LABEL_20;
  }
  v46 = *(_DWORD *)(v34 + 120);
  v47 = *(_DWORD *)(v34 + 136);
  if ( *(_DWORD *)(v34 + 116) )
  {
    v48 = v47 - v46;
    if ( v47 < v46 )
      v48 += *(_DWORD *)(v34 + 36);
    v49 = v48 / *(_DWORD *)(v34 + 44);
  }
  else
  {
    v50 = v47 - v46;
    if ( v47 <= v46 )
      v50 += *(_DWORD *)(v34 + 36);
    v49 = v50 / *(_DWORD *)(v34 + 44) - 1;
  }
  if ( v49 > *(_DWORD *)(v34 + 240) )
  {
    *(_DWORD *)(v34 + 240) = v49;
    *(_QWORD *)(v34 + 248) = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
  }
  v51 = v35 + 2576LL * a3 + 39344;
  if ( v49 >= *(_DWORD *)(v34 + 276) )
  {
    ++*(_DWORD *)(v34 + 300);
  }
  else if ( v49 >= *(_DWORD *)(v34 + 272) )
  {
    ++*(_DWORD *)(v34 + 296);
  }
  else if ( v49 >= *(_DWORD *)(v34 + 268) )
  {
    ++*(_DWORD *)(v34 + 292);
  }
  else
  {
    if ( v49 >= *(_DWORD *)(v34 + 264) )
      JUMPOUT(0x65F288);
    if ( v49 >= *(_DWORD *)(v34 + 260) )
      ++*(_DWORD *)(v34 + 284);
    else
      ++*(_DWORD *)(v34 + 280);
  }
  v169 = v33;
  v170 = a2;
  if ( v47 == v46 )
  {
    v52 = 0;
LABEL_39:
    dp_srng_access_end(v170, (__int64)a1, (char *)v34, v38, v39, v40, v41, v42, v43, v44, v45);
    if ( (_DWORD)v167 )
      dp_mon_buffers_replenish(
        a1,
        (_QWORD *)(v169 + 456),
        v169 + 696,
        v167,
        &v165,
        &v166,
        &v164,
        24,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60);
    if ( (*(_QWORD *)(a15 + 40) & 1) != 0 )
      JUMPOUT(0x65F9EC);
    raw_spin_unlock(a15 + 32);
    qdf_trace_msg(
      0x92u,
      8u,
      "%s: mac_id: %d, work_done:%d tx_monitor_reap_cnt:%d",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "dp_tx_mon_srng_process_2_0",
      HIDWORD(a19),
      v52,
      (unsigned int)v167);
    v77 = *(_QWORD *)(v51 + 248) + (unsigned int)v167;
    v78 = *(_DWORD *)(v51 + 8);
    *(_QWORD *)(v51 + 240) += v164;
    *(_QWORD *)(v51 + 248) = v77;
    if ( v52 || !v78 )
    {
      if ( v52 && v78 )
      {
        *(_BYTE *)(v51 + 256) = 0;
        goto LABEL_20;
      }
      v79 = *(_BYTE *)(v51 + 256);
    }
    else
    {
      v79 = *(_BYTE *)(v51 + 256) + 1;
      *(_BYTE *)(v51 + 256) = v79;
    }
    if ( v79 >= 0x33u )
    {
      qdf_trace_msg(
        0x92u,
        3u,
        "%s: Tx monitor block got stuck!!!!!",
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        "dp_tx_mon_debug_status");
      v160 = *(_DWORD *)(v51 + 260);
      *(_BYTE *)(v51 + 256) = 0;
      *(_DWORD *)(v51 + 260) = v160 + 1;
    }
LABEL_20:
    JUMPOUT(0x65F140);
  }
  v52 = 0;
  v171 = v35;
  while ( 1 )
  {
    v84 = (unsigned int *)(*(_QWORD *)(v34 + 16) + 4LL * v46);
    v85 = v84 != nullptr;
    if ( v84 )
      _ZF = a4 == 0;
    else
      _ZF = 1;
    if ( _ZF )
      goto LABEL_39;
    v163 = 0;
    v161 = 0;
    v162 = 0u;
    v87 = *((_QWORD *)v84 + 1);
    *(_QWORD *)((char *)&v162 + 4) = HIDWORD(v87) & 0x80000;
    if ( (v87 & 0x8000000000000LL) != 0 )
    {
      v161 = 0;
      HIDWORD(v162) = *v84 & 0x3FF;
      LODWORD(v163) = (*v84 >> 10) & 0x3FF;
      HIDWORD(v163) = (*v84 >> 20) & 0x3FF;
      v88 = (((*(_QWORD *)v84 >> 30) & 1LL) << 33) | 0x80000;
    }
    else
    {
      v161 = *v84 | ((unsigned __int64)v84[1] << 32);
      *(_QWORD *)((char *)&v162 + 4) = v84[3] & 0x30000;
      v88 = *(_QWORD *)((_BYTE *)&v162 + 4) & 0xFFFFFFFFFFFFF000LL | v84[3] & 0xFFF;
    }
    *(_QWORD *)((char *)&v162 + 4) = v88;
    LODWORD(v162) = v84[2];
    *(_QWORD *)((char *)&v162 + 4) = HIDWORD(*((_QWORD *)v84 + 1)) & 0x40000LL | v88 & 0xFFFFFFFFFFFBFFFFLL;
    *(_QWORD *)((char *)&v162 + 4) = *(_QWORD *)((_BYTE *)&v162 + 4) & 0xFFFFFFFF0FFFFFFFLL | v84[3] & 0xF0000000;
    if ( (v88 & 0x80000) != 0 )
    {
      qdf_trace_msg(
        0x92u,
        8u,
        "%s: P_ID:%d INIT:%d E_DESC:%d R_ID:%d L_CNT:%d  DROP[PPDU:%d MPDU:%d TLV:%d] E_O_PPDU:%d",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "dp_tx_mon_srng_process_2_0");
      v118 = *(_QWORD *)(v51 + 160);
      v119 = *(_QWORD *)(v51 + 168);
      *(_QWORD *)(v51 + 152) += HIDWORD(v162);
      *(_QWORD *)(v51 + 160) = v118 + (unsigned int)v163;
      *(_QWORD *)(v51 + 168) = v119 + HIDWORD(v163);
      v120 = *(_DWORD *)(v34 + 120);
      if ( v120 != *(_DWORD *)(v34 + 136) )
      {
        v121 = *(_BYTE *)(v34 + 78);
        v122 = *(_DWORD *)(v34 + 44) + v120;
        v123 = *(_QWORD *)(v34 + 16);
        v124 = v122 == *(_DWORD *)(v34 + 36) ? 0 : v122;
        *(_DWORD *)(v34 + 120) = v124;
        if ( (v121 & 4) != 0 )
        {
          _X24 = v123 + 4LL * v124;
          v126 = *(_QWORD *)(*(_QWORD *)(a18 + 8) + 40LL);
          if ( (*(_BYTE *)(v126 + 844) & 0x40) == 0 )
          {
            v127 = _X24 << 8 >> 8;
            v128 = (unsigned __int64)(v127 + 0x8000000000LL) >> 38;
            v129 = memstart_addr + v127 + 0x8000000000LL;
            v130 = v127 - kimage_voffset;
            if ( v128 )
              v131 = v130;
            else
              v131 = v129;
            _dma_sync_single_for_cpu(v126, v131);
          }
          __asm { PRFM            #0, [X24] }
        }
      }
      goto LABEL_50;
    }
    qdf_trace_msg(
      0x92u,
      8u,
      "%s: P_ID:%d INIT:%d E_DESC:%d R_ID:%d L_CNT:%d BUF_ADDR: 0x%llx E_OFF: %d E_REA: %d",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "dp_tx_mon_srng_process_2_0");
    v97 = v161 | 0xFFFFFF0000000000LL;
    v98 = *(_DWORD *)((char *)&off_10 + (v161 | 0xFFFFFF0000000000LL));
    if ( ((v98 >> 2) & 0xFFFFFF) != v161 >> 40 )
      break;
    if ( (v98 & 2) == 0 )
      goto LABEL_61;
LABEL_62:
    if ( *(_DWORD *)(v97 + 28) != -559043635 )
    {
      qdf_trace_msg(
        0x92u,
        2u,
        "%s: Invalid monitor descriptor",
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        "dp_tx_mon_srng_process_2_0");
      v146 = printk(
               &unk_AAA255,
               "0",
               "dp_tx_mon_srng_process_2_0",
               "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/2.0/dp_tx_mon_2.0.c");
      dump_stack(v146);
    }
    v99 = WORD2(v162);
    v100 = *(_QWORD *)v97;
    *(_QWORD *)v97 = 0;
    LODWORD(v167) = v167 + 1;
    *(_QWORD *)v97 = 0;
    v101 = *(_DWORD *)(v97 + 16);
    *(_QWORD *)v97 = v165;
    v102 = v101 & 0xFFFFFFFE;
    v103 = v166;
    *(_DWORD *)(v97 + 16) = v102;
    v165 = v97;
    if ( !v103 || !*(_QWORD *)v97 )
      v166 = (_QWORD *)v97;
    if ( v100 )
    {
      ++*(_QWORD *)(v51 + 224);
      if ( (~DWORD1(v162) & 0x30000LL) != 0 )
      {
        dp_tx_mon_process_status_tlv(a1, a20, &v161, v100, v99 & 0xFFF, &v165, HIDWORD(a19));
        v132 = *(_DWORD *)(v34 + 120);
        if ( v132 != *(_DWORD *)(v34 + 136) )
        {
          v133 = *(_BYTE *)(v34 + 78);
          v134 = *(_DWORD *)(v34 + 44) + v132;
          v135 = *(_QWORD *)(v34 + 16);
          v136 = v134 == *(_DWORD *)(v34 + 36) ? 0 : v134;
          *(_DWORD *)(v34 + 120) = v136;
          if ( (v133 & 4) != 0 )
          {
            _X24 = v135 + 4LL * v136;
            v138 = *(_QWORD *)(*(_QWORD *)(a18 + 8) + 40LL);
            if ( (*(_BYTE *)(v138 + 844) & 0x40) == 0 )
            {
              v139 = _X24 << 8 >> 8;
              v140 = (unsigned __int64)(v139 + 0x8000000000LL) >> 38;
              v141 = memstart_addr + v139 + 0x8000000000LL;
              v142 = v139 - kimage_voffset;
              if ( v140 )
                v143 = v142;
              else
                v143 = v141;
              _dma_sync_single_for_cpu(v138, v143);
            }
            __asm { PRFM            #0, [X24] }
          }
        }
      }
      else
      {
        v104 = (unsigned int)v162;
        *(_DWORD *)v51 = v162;
        dp_tx_mon_update_end_reason(v171, v104, BYTE6(v162) & 3, HIDWORD(a19));
        ((void (__fastcall *)(__int64, __int64, _QWORD, unsigned __int64 *, _QWORD))dp_tx_mon_status_free_packet_buf)(
          a20,
          v100,
          v99 & 0xFFF,
          &v165,
          HIDWORD(a19));
        ++*(_QWORD *)(v51 + 232);
        page_frag_free(v100);
        v105 = *(_DWORD *)(v34 + 120);
        if ( v105 != *(_DWORD *)(v34 + 136) )
        {
          v106 = *(_BYTE *)(v34 + 78);
          v107 = *(_DWORD *)(v34 + 44) + v105;
          v108 = *(_QWORD *)(v34 + 16);
          v109 = v107 == *(_DWORD *)(v34 + 36) ? 0 : v107;
          *(_DWORD *)(v34 + 120) = v109;
          if ( (v106 & 4) != 0 )
          {
            _X24 = v108 + 4LL * v109;
            v111 = *(_QWORD *)(*(_QWORD *)(a18 + 8) + 40LL);
            if ( (*(_BYTE *)(v111 + 844) & 0x40) == 0 )
            {
              v112 = _X24 << 8 >> 8;
              v113 = (unsigned __int64)(v112 + 0x8000000000LL) >> 38;
              v114 = memstart_addr + v112 + 0x8000000000LL;
              v115 = v112 - kimage_voffset;
              if ( v113 )
                v116 = v115;
              else
                v116 = v114;
              _dma_sync_single_for_cpu(v111, v116);
            }
            __asm { PRFM            #0, [X24] }
          }
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x92u,
        8u,
        "%s: P_ID:%d INIT:%d E_DESC:%d R_ID:%d L_CNT:%d BUF_ADDR: 0x%llx E_OFF: %d E_REA: %d",
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        "dp_tx_mon_srng_process_2_0",
        (unsigned int)v162,
        (DWORD1(v162) >> 18) & 1,
        (DWORD1(v162) >> 19) & 1,
        (unsigned __int8)(DWORD1(v162) >> 20));
      v147 = *(_DWORD *)(v34 + 120);
      if ( v147 != *(_DWORD *)(v34 + 136) )
      {
        v148 = *(_BYTE *)(v34 + 78);
        v149 = *(_DWORD *)(v34 + 44) + v147;
        v150 = *(_QWORD *)(v34 + 16);
        v151 = v149 == *(_DWORD *)(v34 + 36) ? 0 : v149;
        *(_DWORD *)(v34 + 120) = v151;
        if ( (v148 & 4) != 0 )
        {
          _X24 = v150 + 4LL * v151;
          v153 = *(_QWORD *)(*(_QWORD *)(a18 + 8) + 40LL);
          if ( (*(_BYTE *)(v153 + 844) & 0x40) == 0 )
          {
            v154 = _X24 << 8 >> 8;
            v155 = (unsigned __int64)(v154 + 0x8000000000LL) >> 38;
            v156 = memstart_addr + v154 + 0x8000000000LL;
            v157 = v154 - kimage_voffset;
            if ( v155 )
              v158 = v157;
            else
              v158 = v156;
            _dma_sync_single_for_cpu(v153, v158);
          }
          __asm { PRFM            #0, [X24] }
        }
      }
    }
LABEL_50:
    v46 = *(_DWORD *)(v34 + 120);
    a4 -= v85;
    ++v52;
    if ( v46 == *(_DWORD *)(v34 + 136) )
      goto LABEL_39;
  }
  qdf_trace_msg(
    0x38u,
    2u,
    "%s: duplicate cookie found mon_desc:%pK",
    v89,
    v90,
    v91,
    v92,
    v93,
    v94,
    v95,
    v96,
    "dp_tx_mon_srng_process_2_0",
    v97);
  v145 = printk(
           &unk_AAA255,
           "0",
           "dp_tx_mon_srng_process_2_0",
           "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/2.0/dp_tx_mon_2.0.c");
  dump_stack(v145);
  if ( (*(_DWORD *)(v97 + 16) & 2) != 0 )
    goto LABEL_62;
LABEL_61:
  _qdf_mem_unmap_page(a1[3], *(_QWORD *)(v97 + 8), 2048, 2);
  *(_DWORD *)(v97 + 16) |= 2u;
  goto LABEL_62;
}
