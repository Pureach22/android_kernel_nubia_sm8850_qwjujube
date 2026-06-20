// positive sp value has been detected, the output may be wrong!
__int64 __fastcall dp_config_enh_tx_monitor_2_0(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        int a13)
{
  unsigned int v13; // w26
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w3
  __int64 v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x9
  int v41; // w8
  unsigned __int8 v42; // w8
  unsigned int *v47; // x8
  int v48; // w28
  unsigned __int64 v50; // x9
  int v51; // w10
  int v52; // w9
  unsigned __int64 v53; // x11
  __int64 v54; // x13
  unsigned __int64 v55; // x13
  int v56; // w12
  unsigned __int64 v57; // x14
  unsigned __int64 v58; // x14
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned __int64 v67; // x9
  unsigned __int64 v68; // x27
  unsigned int v69; // w8
  int v70; // w24
  __int64 v71; // x25
  int v72; // w9
  unsigned int v73; // w8
  __int64 v74; // x9
  __int64 v75; // x1
  int v76; // w9
  char v77; // w12
  int v78; // w11
  __int64 v79; // x9
  unsigned int v80; // w10
  __int64 v82; // x0
  __int64 v83; // x9
  unsigned __int64 v84; // x13
  __int64 v85; // x10
  __int64 v86; // x9
  __int64 v87; // x1
  __int64 v89; // x10
  __int64 v90; // x9
  int v91; // w9
  char v92; // w12
  int v93; // w11
  __int64 v94; // x9
  unsigned int v95; // w10
  __int64 v97; // x0
  __int64 v98; // x9
  unsigned __int64 v99; // x13
  __int64 v100; // x10
  __int64 v101; // x9
  __int64 v102; // x1
  int v103; // w9
  char v104; // w12
  int v105; // w11
  __int64 v106; // x9
  unsigned int v107; // w10
  __int64 v109; // x0
  __int64 v110; // x9
  unsigned __int64 v111; // x13
  __int64 v112; // x10
  __int64 v113; // x9
  __int64 v114; // x1
  __int64 v116; // x0
  __int64 v117; // x0
  unsigned int v118; // w8
  int v119; // w9
  char v120; // w12
  int v121; // w11
  __int64 v122; // x9
  unsigned int v123; // w10
  __int64 v125; // x0
  __int64 v126; // x9
  unsigned __int64 v127; // x13
  __int64 v128; // x10
  __int64 v129; // x9
  __int64 v130; // x1
  int v132; // w8
  int v133; // w9
  int v134; // w10
  __int64 *v135; // x20
  __int64 v136; // x21
  int v137; // w22
  __int64 v138; // x23
  __int64 v139; // x24
  __int64 v140; // x25
  __int64 v141; // x27
  __int64 v142; // x29
  __int64 v143; // x30
  unsigned int v144; // w8
  __int64 v146; // x8
  __int64 v147; // x10
  __int64 v149; // x23
  __int64 v150; // x21
  __int64 v151; // x22
  unsigned __int16 dp_soc_tx_mon_buf_ring_size; // w1
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  __int64 result; // x0
  unsigned int v162; // w0
  __int64 v163; // x4
  __int64 v164; // x6
  unsigned int v165; // w19
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  __int64 v174; // [xsp-108h] [xbp-148h]
  __int64 v175; // [xsp-D0h] [xbp-110h]
  __int64 v176; // [xsp-C8h] [xbp-108h]
  __int64 v177; // [xsp-C0h] [xbp-100h]
  __int64 v178; // [xsp-B8h] [xbp-F8h]
  __int64 v179; // [xsp-B0h] [xbp-F0h]
  __int64 v180; // [xsp-A8h] [xbp-E8h]
  __int64 v181; // [xsp-A0h] [xbp-E0h]
  __int64 v182; // [xsp-98h] [xbp-D8h]
  __int64 v183; // [xsp-90h] [xbp-D0h]
  __int64 v184; // [xsp-88h] [xbp-C8h]
  unsigned int v185; // [xsp-7Ch] [xbp-BCh]
  __int64 v186; // [xsp-78h] [xbp-B8h]

  v144 = a3;
  if ( a3 >= 3u )
  {
    __break(0x5512u);
    if ( (a13 & 0x200000) != 0 )
      return dp_peer_set_tx_capture_enabled_2_0();
    *(_DWORD *)(v138 + 288) = v134;
    v180 = v140;
    v182 = v139;
    if ( v133 == a3 )
    {
      v13 = 0;
LABEL_23:
      dp_srng_access_end(v182, (__int64)v135, (char *)v138, a4, a5, a6, a7, a8, a9, a10, a11);
      v22 = *(_DWORD *)(v142 - 24);
      if ( v22 )
        dp_mon_buffers_replenish(
          v135,
          (_QWORD *)(v180 + 456),
          v180 + 696,
          v22,
          (_QWORD *)(v142 - 40),
          (_QWORD **)(v142 - 32),
          (_DWORD *)(v142 - 44),
          24,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21);
      v23 = *(_QWORD *)(v181 + 40);
      if ( (v23 & 1) != 0 )
      {
        *(_QWORD *)(v181 + 40) = v23 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v181 + 32);
      }
      else
      {
        raw_spin_unlock(v181 + 32);
      }
      qdf_trace_msg(
        0x92u,
        8u,
        "%s: mac_id: %d, work_done:%d tx_monitor_reap_cnt:%d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "dp_tx_mon_srng_process_2_0",
        v185,
        v13,
        *(unsigned int *)(v142 - 24));
      v40 = *(_QWORD *)(v136 + 248) + *(unsigned int *)(v142 - 24);
      v41 = *(_DWORD *)(v136 + 8);
      *(_QWORD *)(v136 + 240) += *(unsigned int *)(v142 - 44);
      *(_QWORD *)(v136 + 248) = v40;
      if ( v13 || !v41 )
      {
        if ( v13 && v41 )
        {
          *(_BYTE *)(v136 + 256) = 0;
LABEL_20:
          _ReadStatusReg(SP_EL0);
          return v13;
        }
        v42 = *(_BYTE *)(v136 + 256);
      }
      else
      {
        v42 = *(_BYTE *)(v136 + 256) + 1;
        *(_BYTE *)(v136 + 256) = v42;
      }
      if ( v42 >= 0x33u )
      {
        qdf_trace_msg(
          0x92u,
          3u,
          "%s: Tx monitor block got stuck!!!!!",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "dp_tx_mon_debug_status");
        v132 = *(_DWORD *)(v136 + 260);
        *(_BYTE *)(v136 + 256) = 0;
        *(_DWORD *)(v136 + 260) = v132 + 1;
      }
      goto LABEL_20;
    }
    v13 = 0;
    v183 = v141;
    while ( 1 )
    {
      v47 = (unsigned int *)(*(_QWORD *)(v138 + 16) + 4LL * v144);
      v48 = v47 != nullptr;
      if ( v47 )
        _ZF = v137 == 0;
      else
        _ZF = 1;
      if ( _ZF )
        goto LABEL_23;
      *(_QWORD *)(v142 - 64) = 0;
      *(_QWORD *)(v142 - 56) = 0;
      *(_QWORD *)(v142 - 80) = 0;
      *(_QWORD *)(v142 - 72) = 0;
      v50 = *((_QWORD *)v47 + 1);
      *(_QWORD *)(v142 - 68) = HIDWORD(v50) & 0x80000;
      if ( (v50 & 0x8000000000000LL) != 0 )
      {
        *(_QWORD *)(v142 - 80) = 0;
        v56 = *v47 & 0x3FF;
        *(_DWORD *)(v142 - 60) = v56;
        v52 = (*v47 >> 10) & 0x3FF;
        *(_DWORD *)(v142 - 56) = v52;
        v51 = (*v47 >> 20) & 0x3FF;
        *(_DWORD *)(v142 - 52) = v51;
        v55 = (((*(_QWORD *)v47 >> 30) & 1LL) << 33) | 0x80000;
        v53 = 0;
      }
      else
      {
        v51 = 0;
        v52 = 0;
        v53 = *v47 | ((unsigned __int64)v47[1] << 32);
        *(_QWORD *)(v142 - 80) = v53;
        v54 = v47[3] & 0x30000;
        *(_QWORD *)(v142 - 68) = v54;
        v55 = v54 & 0xFFFFFFFFFFFFF000LL | v47[3] & 0xFFF;
        v56 = 0;
      }
      *(_QWORD *)(v142 - 68) = v55;
      *(_DWORD *)(v142 - 72) = v47[2];
      v57 = HIDWORD(*((_QWORD *)v47 + 1)) & 0x40000LL | v55 & 0xFFFFFFFFFFFBFFFFLL;
      *(_QWORD *)(v142 - 68) = v57;
      v58 = v57 & 0xFFFFFFFF0FFFFFFFLL | v47[3] & 0xF0000000;
      *(_QWORD *)(v142 - 68) = v58;
      if ( (v55 & 0x80000) != 0 )
      {
        LODWORD(v178) = v51;
        LODWORD(v177) = v52;
        LODWORD(v176) = v56;
        LODWORD(v175) = (unsigned int)v58 >> 28;
        LODWORD(v179) = v55 >> 33;
        qdf_trace_msg(
          0x92u,
          8u,
          "%s: P_ID:%d INIT:%d E_DESC:%d R_ID:%d L_CNT:%d  DROP[PPDU:%d MPDU:%d TLV:%d] E_O_PPDU:%d",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "dp_tx_mon_srng_process_2_0",
          v175,
          v176,
          v177,
          v178,
          v179,
          v180);
        v89 = *(_QWORD *)(v136 + 160);
        v90 = *(_QWORD *)(v136 + 168);
        *(_QWORD *)(v136 + 152) += *(unsigned int *)(v142 - 60);
        *(_QWORD *)(v136 + 160) = v89 + *(unsigned int *)(v142 - 56);
        *(_QWORD *)(v136 + 168) = v90 + *(unsigned int *)(v142 - 52);
        v91 = *(_DWORD *)(v138 + 120);
        if ( v91 != *(_DWORD *)(v138 + 136) )
        {
          v92 = *(_BYTE *)(v138 + 78);
          v93 = *(_DWORD *)(v138 + 44) + v91;
          v94 = *(_QWORD *)(v138 + 16);
          v95 = v93 == *(_DWORD *)(v138 + 36) ? 0 : v93;
          *(_DWORD *)(v138 + 120) = v95;
          if ( (v92 & 4) != 0 )
          {
            _X24 = v94 + 4LL * v95;
            v97 = *(_QWORD *)(*(_QWORD *)(v184 + 8) + 40LL);
            if ( (*(_BYTE *)(v97 + 844) & 0x40) == 0 )
            {
              v98 = _X24 << 8 >> 8;
              v99 = (unsigned __int64)(v98 + 0x8000000000LL) >> 38;
              v100 = memstart_addr + v98 + 0x8000000000LL;
              v101 = v98 - kimage_voffset;
              if ( v99 )
                v102 = v101;
              else
                v102 = v100;
              _dma_sync_single_for_cpu(v97, v102);
            }
            __asm { PRFM            #0, [X24] }
          }
        }
        goto LABEL_35;
      }
      LODWORD(v178) = WORD1(v58) & 3;
      LODWORD(v177) = v58 & 0xFFF;
      LODWORD(v175) = (unsigned int)v58 >> 28;
      qdf_trace_msg(
        0x92u,
        8u,
        "%s: P_ID:%d INIT:%d E_DESC:%d R_ID:%d L_CNT:%d BUF_ADDR: 0x%llx E_OFF: %d E_REA: %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "dp_tx_mon_srng_process_2_0",
        v175,
        v53,
        v177,
        v178);
      v67 = *(_QWORD *)(v142 - 80);
      v68 = v67 | 0xFFFFFF0000000000LL;
      v69 = *(_DWORD *)((char *)&off_10 + (v67 | 0xFFFFFF0000000000LL));
      if ( ((v69 >> 2) & 0xFFFFFF) != v67 >> 40 )
        break;
      if ( (v69 & 2) == 0 )
        goto LABEL_46;
LABEL_47:
      if ( *(_DWORD *)(v68 + 28) != -559043635 )
      {
        qdf_trace_msg(
          0x92u,
          2u,
          "%s: Invalid monitor descriptor",
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          "dp_tx_mon_srng_process_2_0");
        v117 = printk(
                 &unk_AAA255,
                 "0",
                 "dp_tx_mon_srng_process_2_0",
                 "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/2.0/dp_tx_mon_2.0.c");
        dump_stack(v117);
      }
      v70 = *(_DWORD *)(v142 - 68);
      v71 = *(_QWORD *)v68;
      *(_QWORD *)v68 = 0;
      ++*(_DWORD *)(v142 - 24);
      *(_QWORD *)v68 = 0;
      v72 = *(_DWORD *)(v68 + 16);
      *(_QWORD *)v68 = *(_QWORD *)(v142 - 40);
      v73 = v72 & 0xFFFFFFFE;
      v74 = *(_QWORD *)(v142 - 32);
      *(_DWORD *)(v68 + 16) = v73;
      *(_QWORD *)(v142 - 40) = v68;
      if ( !v74 || !*(_QWORD *)v68 )
        *(_QWORD *)(v142 - 32) = v68;
      if ( v71 )
      {
        ++*(_QWORD *)(v136 + 224);
        if ( (~*(_DWORD *)(v142 - 68) & 0x30000) != 0 )
        {
          ((void (__fastcall *)(__int64 *, __int64, __int64, _QWORD, __int64, _QWORD))dp_tx_mon_process_status_tlv)(
            v135,
            v142 - 80,
            v71,
            v70 & 0xFFF,
            v142 - 40,
            v185);
          v103 = *(_DWORD *)(v138 + 120);
          if ( v103 != *(_DWORD *)(v138 + 136) )
          {
            v104 = *(_BYTE *)(v138 + 78);
            v105 = *(_DWORD *)(v138 + 44) + v103;
            v106 = *(_QWORD *)(v138 + 16);
            v107 = v105 == *(_DWORD *)(v138 + 36) ? 0 : v105;
            *(_DWORD *)(v138 + 120) = v107;
            if ( (v104 & 4) != 0 )
            {
              _X24 = v106 + 4LL * v107;
              v109 = *(_QWORD *)(*(_QWORD *)(v184 + 8) + 40LL);
              if ( (*(_BYTE *)(v109 + 844) & 0x40) == 0 )
              {
                v110 = _X24 << 8 >> 8;
                v111 = (unsigned __int64)(v110 + 0x8000000000LL) >> 38;
                v112 = memstart_addr + v110 + 0x8000000000LL;
                v113 = v110 - kimage_voffset;
                if ( v111 )
                  v114 = v113;
                else
                  v114 = v112;
                _dma_sync_single_for_cpu(v109, v114);
              }
              __asm { PRFM            #0, [X24] }
            }
          }
        }
        else
        {
          v75 = *(unsigned int *)(v142 - 72);
          *(_DWORD *)v136 = v75;
          dp_tx_mon_update_end_reason(v183, v75, *(_WORD *)(v142 - 66) & 3, v185);
          ((void (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD))dp_tx_mon_status_free_packet_buf)(
            v186,
            v71,
            v70 & 0xFFF,
            v142 - 40,
            v185);
          ++*(_QWORD *)(v136 + 232);
          page_frag_free(v71);
          v76 = *(_DWORD *)(v138 + 120);
          if ( v76 != *(_DWORD *)(v138 + 136) )
          {
            v77 = *(_BYTE *)(v138 + 78);
            v78 = *(_DWORD *)(v138 + 44) + v76;
            v79 = *(_QWORD *)(v138 + 16);
            v80 = v78 == *(_DWORD *)(v138 + 36) ? 0 : v78;
            *(_DWORD *)(v138 + 120) = v80;
            if ( (v77 & 4) != 0 )
            {
              _X24 = v79 + 4LL * v80;
              v82 = *(_QWORD *)(*(_QWORD *)(v184 + 8) + 40LL);
              if ( (*(_BYTE *)(v82 + 844) & 0x40) == 0 )
              {
                v83 = _X24 << 8 >> 8;
                v84 = (unsigned __int64)(v83 + 0x8000000000LL) >> 38;
                v85 = memstart_addr + v83 + 0x8000000000LL;
                v86 = v83 - kimage_voffset;
                if ( v84 )
                  v87 = v86;
                else
                  v87 = v85;
                _dma_sync_single_for_cpu(v82, v87);
              }
              __asm { PRFM            #0, [X24] }
            }
          }
        }
      }
      else
      {
        v118 = *(_DWORD *)(v142 - 68);
        LODWORD(v177) = v118 & 0xFFF;
        LODWORD(v178) = HIWORD(v118) & 3;
        LODWORD(v175) = v118 >> 28;
        qdf_trace_msg(
          0x92u,
          8u,
          "%s: P_ID:%d INIT:%d E_DESC:%d R_ID:%d L_CNT:%d BUF_ADDR: 0x%llx E_OFF: %d E_REA: %d",
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          "dp_tx_mon_srng_process_2_0",
          *(unsigned int *)(v142 - 72),
          (v118 >> 18) & 1,
          (v118 >> 19) & 1,
          (unsigned __int8)(v118 >> 20),
          v175,
          *(_QWORD *)(v142 - 80),
          v177,
          v178);
        v119 = *(_DWORD *)(v138 + 120);
        if ( v119 != *(_DWORD *)(v138 + 136) )
        {
          v120 = *(_BYTE *)(v138 + 78);
          v121 = *(_DWORD *)(v138 + 44) + v119;
          v122 = *(_QWORD *)(v138 + 16);
          v123 = v121 == *(_DWORD *)(v138 + 36) ? 0 : v121;
          *(_DWORD *)(v138 + 120) = v123;
          if ( (v120 & 4) != 0 )
          {
            _X24 = v122 + 4LL * v123;
            v125 = *(_QWORD *)(*(_QWORD *)(v184 + 8) + 40LL);
            if ( (*(_BYTE *)(v125 + 844) & 0x40) == 0 )
            {
              v126 = _X24 << 8 >> 8;
              v127 = (unsigned __int64)(v126 + 0x8000000000LL) >> 38;
              v128 = memstart_addr + v126 + 0x8000000000LL;
              v129 = v126 - kimage_voffset;
              if ( v127 )
                v130 = v129;
              else
                v130 = v128;
              _dma_sync_single_for_cpu(v125, v130);
            }
            __asm { PRFM            #0, [X24] }
          }
        }
      }
LABEL_35:
      v144 = *(_DWORD *)(v138 + 120);
      v137 -= v48;
      ++v13;
      if ( v144 == *(_DWORD *)(v138 + 136) )
        goto LABEL_23;
    }
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: duplicate cookie found mon_desc:%pK",
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      "dp_tx_mon_srng_process_2_0",
      v68);
    v116 = printk(
             &unk_AAA255,
             "0",
             "dp_tx_mon_srng_process_2_0",
             "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/2.0/dp_tx_mon_2.0.c");
    dump_stack(v116);
    if ( (*(_DWORD *)(v68 + 16) & 2) != 0 )
      goto LABEL_47;
LABEL_46:
    _qdf_mem_unmap_page(v135[3], *(_QWORD *)(v68 + 8), 2048, 2);
    *(_DWORD *)(v68 + 16) |= 2u;
    goto LABEL_47;
  }
  v174 = v143;
  v146 = *(_QWORD *)(a1 + 96456);
  v147 = *(_QWORD *)(a1 + 8);
  v149 = *(_QWORD *)(v147 + 20112);
  v150 = v146 + 36864;
  v151 = v146 + 2576LL * a3 + 39344;
  dp_soc_tx_mon_buf_ring_size = wlan_cfg_get_dp_soc_tx_mon_buf_ring_size(*(_QWORD *)(v147 + 40));
  result = 4;
  if ( a2 > 1u )
  {
    if ( a2 != 2 )
    {
      if ( a2 != 3 )
        return result;
LABEL_8:
      *(_WORD *)(v149 + 842) = 0;
      v162 = dp_vdev_set_monitor_mode_buf_rings_tx_2_0(
               a1,
               dp_soc_tx_mon_buf_ring_size,
               v153,
               v154,
               v155,
               v156,
               v157,
               v158,
               v159,
               v160);
      if ( !v162 )
      {
        qdf_mem_set((void *)(v151 + 152), 0x90u, 0);
        v163 = 1;
        *(_QWORD *)(v151 + 488) = 0;
        *(_DWORD *)(v151 + 496) = 0;
        *(_DWORD *)(v151 + 8) = 1;
        *(_WORD *)(v150 + 2472) = 1793;
        if ( a2 == 3 )
        {
          v163 = 3;
          *(_DWORD *)(v151 + 8) = 3;
          *(_BYTE *)(v150 + 2472) = 3;
        }
        v164 = 7;
        goto LABEL_16;
      }
LABEL_14:
      v165 = v162;
      qdf_trace_msg(
        0x92u,
        2u,
        "%s: Tx monitor buffer allocation failed",
        v153,
        v154,
        v155,
        v156,
        v157,
        v158,
        v159,
        v160,
        "dp_config_enh_tx_monitor_2_0",
        v142,
        v174);
      return v165;
    }
    *(_WORD *)(v149 + 842) = 0;
    v162 = dp_vdev_set_monitor_mode_buf_rings_tx_2_0(
             a1,
             dp_soc_tx_mon_buf_ring_size,
             v153,
             v154,
             v155,
             v156,
             v157,
             v158,
             v159,
             v160);
    if ( v162 )
      goto LABEL_14;
    v163 = 2;
    v164 = 4;
    *(_DWORD *)(v151 + 8) = 2;
    *(_WORD *)(v150 + 2472) = 1026;
  }
  else
  {
    if ( a2 )
    {
      if ( a2 != 1 )
        return result;
      goto LABEL_8;
    }
    v163 = 0;
    *(_DWORD *)(v151 + 8) = 0;
    *(_WORD *)(v150 + 2472) = 256;
    v164 = 1;
  }
LABEL_16:
  qdf_trace_msg(
    0x92u,
    5u,
    "%s: Tx monitor mode:%d mon_mode_flag:%d config_length:%d",
    v153,
    v154,
    v155,
    v156,
    v157,
    v158,
    v159,
    v160,
    "dp_config_enh_tx_monitor_2_0",
    v163,
    (unsigned int)v163,
    v164,
    v142,
    v174);
  dp_mon_filter_setup_tx_mon_mode(a1);
  dp_tx_mon_filter_update(a1, v166, v167, v168, v169, v170, v171, v172, v173);
  return 0;
}
