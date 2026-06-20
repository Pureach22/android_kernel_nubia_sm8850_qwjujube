__int64 __fastcall dp_rx_process_be(__int64 a1, _DWORD *a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x19
  _DWORD *v5; // x22
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v7; // x8
  unsigned __int16 v8; // w0
  __int64 txrx_peer_and_vdev; // x26
  unsigned int v10; // w20
  __int64 v11; // x8
  int v12; // w24
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w8
  unsigned int v22; // w9
  unsigned int v23; // w11
  unsigned int v24; // w10
  unsigned int v25; // w11
  unsigned int v27; // w8
  __int64 v28; // x27
  unsigned int v29; // w25
  __int64 v30; // x28
  unsigned int v31; // w26
  unsigned int v32; // w20
  char v33; // w12
  __int64 v34; // x10
  __int64 v35; // x21
  unsigned int v36; // w9
  _DWORD *v42; // x21
  _BYTE *v43; // x20
  char v44; // w9
  char v45; // w8
  _BYTE *v46; // x9
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x23
  __int64 v56; // x23
  __int64 v57; // x0
  __int64 v58; // x23
  unsigned int v59; // w8
  unsigned int v60; // w9
  unsigned int v61; // w10
  int v62; // w14
  int v63; // w15
  __int16 v64; // w12
  unsigned int v65; // w11
  unsigned int v66; // w10
  __int64 v67; // x12
  unsigned int v68; // w21
  __int64 v69; // x23
  bool v70; // w8
  __int64 v71; // x9
  int v72; // w8
  unsigned __int64 v73; // x9
  unsigned __int64 v74; // x8
  __int64 v75; // x9
  int v76; // w8
  unsigned __int64 v77; // x9
  unsigned __int64 v78; // x8
  __int64 *v79; // x24
  char v80; // w10
  unsigned int v81; // w8
  _BYTE *v82; // x9
  int v83; // w8
  __int64 v84; // x0
  __int64 v85; // x20
  __int64 v86; // x8
  __int64 v87; // x4
  _QWORD *v88; // x28
  unsigned __int8 *v89; // x23
  __int64 v90; // x21
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  __int64 v99; // x25
  unsigned int v100; // w9
  unsigned int v101; // w20
  unsigned int v102; // w8
  unsigned int v103; // w21
  __int64 *ref_by_id; // x0
  int v105; // w9
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  unsigned int v114; // w8
  unsigned int v115; // w20
  __int64 v116; // x24
  unsigned __int8 *v117; // x22
  _QWORD *v118; // x23
  __int64 v119; // x24
  unsigned int v120; // w9
  unsigned int v121; // w28
  unsigned int v122; // w8
  __int64 v123; // x24
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  __int64 v132; // x20
  int v133; // w9
  __int64 v134; // x8
  __int64 v135; // x8
  __int64 v136; // x10
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  int v145; // w9
  int v146; // w10
  void (__fastcall *v147)(__int64, __int64, __int64, __int64, __int64, __int64); // x8
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  __int64 v156; // x24
  __int64 v157; // x8
  void (__fastcall *v158)(__int64, __int64 *, char *, __int64 *); // x8
  __int64 v159; // x2
  __int64 v160; // x3
  double v161; // d0
  double v162; // d1
  double v163; // d2
  double v164; // d3
  double v165; // d4
  double v166; // d5
  double v167; // d6
  double v168; // d7
  __int64 v169; // x9
  int v170; // w8
  unsigned __int64 v171; // x9
  unsigned __int64 v172; // x8
  __int64 v173; // x10
  __int64 v174; // x11
  __int64 v175; // x12
  __int64 v176; // x9
  __int64 v177; // x11
  __int64 v178; // x0
  int v179; // w8
  double v180; // d0
  double v181; // d1
  double v182; // d2
  double v183; // d3
  double v184; // d4
  double v185; // d5
  double v186; // d6
  double v187; // d7
  unsigned __int8 (__fastcall *v188)(_QWORD); // x8
  bool v189; // w24
  unsigned __int8 (__fastcall *v190)(_QWORD); // x8
  char v191; // w28
  unsigned __int8 (__fastcall *v192)(_QWORD); // x8
  __int64 v193; // x8
  __int64 v194; // x1
  __int64 v195; // x2
  __int64 v196; // x1
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  double v205; // d0
  double v206; // d1
  double v207; // d2
  double v208; // d3
  double v209; // d4
  double v210; // d5
  double v211; // d6
  double v212; // d7
  void (*v213)(void); // x8
  __int64 v214; // x8
  __int64 v215; // x10
  __int64 v216; // x9
  __int64 v217; // x8
  unsigned int num_pending; // w0
  _QWORD *v219; // x20
  int v220; // w8
  __int64 v221; // x20
  _DWORD *v222; // x8
  _DWORD *v223; // x8
  __int64 v224; // x0
  __int64 v225; // x8
  _DWORD *v226; // x8
  int v228; // [xsp+0h] [xbp-140h]
  int v229; // [xsp+14h] [xbp-12Ch]
  unsigned int v230; // [xsp+24h] [xbp-11Ch]
  unsigned int v231; // [xsp+28h] [xbp-118h]
  unsigned int v232; // [xsp+2Ch] [xbp-114h]
  __int64 v233; // [xsp+30h] [xbp-110h]
  unsigned int v234; // [xsp+3Ch] [xbp-104h]
  unsigned __int64 v235; // [xsp+48h] [xbp-F8h]
  __int64 *v236; // [xsp+50h] [xbp-F0h]
  _DWORD *v238; // [xsp+60h] [xbp-E0h]
  char is_peer_ext_stats_enabled; // [xsp+7Ch] [xbp-C4h]
  int v240; // [xsp+80h] [xbp-C0h]
  char v241; // [xsp+8Ch] [xbp-B4h]
  __int64 *v244; // [xsp+A0h] [xbp-A0h]
  _QWORD *v245; // [xsp+A0h] [xbp-A0h]
  __int64 v246; // [xsp+A8h] [xbp-98h]
  __int64 v247; // [xsp+B0h] [xbp-90h]
  int v248; // [xsp+B8h] [xbp-88h]
  __int64 v249; // [xsp+B8h] [xbp-88h]
  int v250; // [xsp+C0h] [xbp-80h] BYREF
  int v251; // [xsp+C4h] [xbp-7Ch] BYREF
  __int64 v252; // [xsp+C8h] [xbp-78h] BYREF
  int v253; // [xsp+D4h] [xbp-6Ch] BYREF
  unsigned __int8 *v254; // [xsp+D8h] [xbp-68h] BYREF
  __int64 v255; // [xsp+E0h] [xbp-60h] BYREF
  __int64 *v256; // [xsp+E8h] [xbp-58h] BYREF
  char v257[4]; // [xsp+F4h] [xbp-4Ch] BYREF
  __int64 v258; // [xsp+F8h] [xbp-48h] BYREF
  __int64 v259; // [xsp+100h] [xbp-40h] BYREF
  __int64 v260; // [xsp+108h] [xbp-38h] BYREF
  __int64 v261; // [xsp+110h] [xbp-30h]
  unsigned int v262; // [xsp+11Ch] [xbp-24h] BYREF
  _BYTE *v263; // [xsp+120h] [xbp-20h] BYREF
  _QWORD v264[3]; // [xsp+128h] [xbp-18h] BYREF

  v264[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 16);
  v257[0] = 0;
  v263 = nullptr;
  v264[0] = 0;
  v256 = nullptr;
  v262 = 0;
  v253 = 0;
  if ( (unsigned __int8)a3 >= 9u )
    goto LABEL_345;
  v5 = a2;
  HIDWORD(v247) = 0;
  v252 = 0;
  if ( !a2 || !v4 )
    goto LABEL_344;
  v246 = *(_QWORD *)(v4 + 1128);
  if ( !v246 )
  {
    HIDWORD(v247) = 0;
    goto LABEL_344;
  }
  v233 = *(_QWORD *)(v4 + 64);
  v232 = *(unsigned __int8 *)(a1 + 32);
  v234 = a2[8];
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v240 = (unsigned __int8)a3;
  if ( 10 * StatusReg >= StatusReg )
    v7 = 10 * StatusReg / 0xC0;
  else
    v7 = 10 * (StatusReg / 0xC0);
  *(_QWORD *)(v4 + 19976) = v7;
  hif_rtpm_mark_last_busy(4);
  v8 = wlan_cfg_rx_buffer_size(*(_QWORD *)(v4 + 40));
  txrx_peer_and_vdev = 0;
  v10 = 0;
  v247 = 0;
  v238 = v5;
  v235 = _ReadStatusReg(SP_EL0);
  v229 = v8;
  v241 = 1;
  while ( 2 )
  {
    if ( txrx_peer_and_vdev )
      dp_txrx_peer_unref_delete(v256, 2);
    v11 = *(_QWORD *)(v4 + 40);
    v255 = 0;
    v12 = *(_DWORD *)(v11 + 676);
    qdf_mem_set(&v262, 4u, 0);
    qdf_mem_set(v264, 8u, 0);
    qdf_mem_set(&v263, 8u, 0);
    v254 = nullptr;
    v250 = 0;
    v251 = 255;
    dp_pkt_get_timestamp(&v252);
    is_peer_ext_stats_enabled = wlan_cfg_is_peer_ext_stats_enabled(*(_QWORD *)(v4 + 40));
    if ( (unsigned int)dp_srng_access_start(a1, v4, v5) )
    {
      ++*(_DWORD *)(v4 + 13824);
      qdf_trace_msg(
        0x3Fu,
        2u,
        "%s: HAL RING Access Failed -- %pK",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "dp_rx_process_be",
        v5);
      v28 = 0;
      v29 = 0;
      goto LABEL_137;
    }
    v21 = v5[30];
    v22 = v5[34];
    v23 = v22 - v21;
    if ( v5[29] )
    {
      if ( v22 < v21 )
        v23 += v5[9];
      v24 = v5[11];
      v25 = v23 / v24;
    }
    else
    {
      if ( v22 <= v21 )
        v23 += v5[9];
      v24 = v5[11];
      v25 = v23 / v24 - 1;
    }
    if ( v25 > v5[60] )
    {
      v5[60] = v25;
      *((_QWORD *)v5 + 31) = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
    }
    if ( v25 >= v5[69] )
    {
      ++v5[75];
      if ( !v10 )
        goto LABEL_38;
    }
    else if ( v25 >= v5[68] )
    {
      ++v5[74];
      if ( !v10 )
        goto LABEL_38;
    }
    else if ( v25 >= v5[67] )
    {
      ++v5[73];
      if ( !v10 )
        goto LABEL_38;
    }
    else if ( v25 >= v5[66] )
    {
      ++v5[72];
      if ( !v10 )
        goto LABEL_38;
    }
    else if ( v25 >= v5[65] )
    {
      ++v5[71];
      if ( !v10 )
      {
LABEL_38:
        _CF = v22 >= v21;
        v27 = v22 - v21;
        if ( !_CF )
          v27 += v5[9];
        v10 = v27 / v24;
      }
    }
    else
    {
      ++v5[70];
      if ( !v10 )
        goto LABEL_38;
    }
    v28 = 0;
    v29 = 0;
    v30 = 0;
    v244 = nullptr;
    v236 = nullptr;
    if ( v10 >= a4 )
      v31 = a4;
    else
      v31 = v10;
    v248 = v12;
    v230 = a4 - v31;
    v231 = v31;
    while ( v31 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            v32 = v5[30];
            if ( v32 == v5[34] )
              goto LABEL_137;
            v33 = *((_BYTE *)v5 + 78);
            v34 = *(_QWORD *)(v4 + 1128);
            v35 = *((_QWORD *)v5 + 2);
            if ( v5[11] + v32 == v5[9] )
              v36 = 0;
            else
              v36 = v5[11] + v32;
            v5[30] = v36;
            if ( (v33 & 4) != 0 )
            {
              _X23 = v35 + 4LL * v36;
              if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v34 + 8) + 40LL) + 844LL) & 0x40) == 0 )
                _dma_sync_single_for_cpu();
              __asm { PRFM            #0, [X23] }
            }
            v42 = (_DWORD *)(v35 + 4LL * v32);
            if ( !v42 )
              goto LABEL_137;
            if ( (v42[7] & 6) == 0 )
            {
              qdf_trace_msg(
                0x7Eu,
                2u,
                "%s: %pK: HAL RING 0x%pK:error %d",
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                "dp_rx_process_be",
                v4,
                v5,
                0);
              if ( (unsigned __int8)a3 == 8 )
                goto LABEL_345;
              ++*(_DWORD *)(v4 + 14024 + 4LL * (unsigned __int8)a3);
            }
            v43 = (_BYTE *)((unsigned int)v42[5] | ((unsigned __int64)(unsigned int)v42[6] << 32));
            if ( !v43 )
              v43 = *(_BYTE **)(*(_QWORD *)(*(_QWORD *)(v4 + 22608) + 24LL * (v42[1] >> 21)) + ((v42[1] >> 9) & 0xFF8LL));
            if ( !(unsigned int)dp_rx_desc_sanity(v4, v246, v5, v42, v43) )
              break;
            if ( v43 && *(_QWORD *)v43 )
            {
              if ( (v43[30] & 2) != 0 )
              {
                v57 = printk(
                        &unk_AAA255,
                        "!rx_desc->unmapped",
                        "dp_rx_process_be",
                        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/be/dp_be_rx.c");
                dump_stack(v57);
              }
              dp_rx_nbuf_unmap(v4, v43, a3);
              dp_rx_buffer_pool_nbuf_free(v4, *(_QWORD *)v43, (unsigned __int8)v43[28]);
              if ( v43[29] || (unsigned __int8)v43[28] > 1u )
                goto LABEL_345;
              *(_QWORD *)v43 = 0;
              v44 = v43[30];
              *(_QWORD *)v43 = v264[0];
              v45 = v44 & 0xFE;
              v46 = v263;
              v43[30] = v45;
              v264[0] = v43;
              if ( !v46 || !*(_QWORD *)v43 )
                v263 = v43;
            }
          }
          if ( (v43[30] & 1) != 0 )
            break;
          ++*(_DWORD *)(v4 + 14056);
          v56 = jiffies;
          if ( dp_rx_process_be___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: Reaping rx_desc not in use!",
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              "dp_rx_process_be");
            dp_rx_process_be___last_ticks = v56;
          }
          dp_rx_dump_info_and_assert(v4, v5, v42, v43);
        }
        if ( !(unsigned int)dp_rx_desc_nbuf_sanity_check(v4, v42, v43) )
          break;
        ++*(_DWORD *)(v4 + 14164);
        v55 = jiffies;
        if ( dp_rx_process_be___last_ticks_6 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Nbuf sanity check failure!",
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            "dp_rx_process_be");
          dp_rx_process_be___last_ticks_6 = v55;
        }
        dp_rx_dump_info_and_assert(v4, v5, v42, v43);
        v43[30] |= 4u;
      }
      v58 = *(_QWORD *)v43;
      v260 = 0;
      v261 = 0;
      v258 = 0;
      qdf_mem_set(&v260, 0x10u, 0);
      qdf_mem_set(&v258, 8u, 0);
      v59 = v42[3];
      v60 = v42[4];
      v61 = v42[2];
      if ( (v60 & 2) != 0 )
      {
        *(_BYTE *)(v58 + 84) |= 4u;
        if ( (v61 & 0x200) != 0 )
        {
LABEL_98:
          *(_BYTE *)(v58 + 84) |= 8u;
          if ( (v61 & 0x2000) == 0 )
            goto LABEL_83;
          goto LABEL_99;
        }
      }
      else if ( (v61 & 0x200) != 0 )
      {
        goto LABEL_98;
      }
      if ( (v61 & 0x2000) == 0 )
        goto LABEL_83;
LABEL_99:
      *(_QWORD *)(v58 + 72) |= 0x800000uLL;
LABEL_83:
      if ( ((v59 >> 22) & 0xC) != 0 )
        v62 = 0;
      else
        v62 = ((v59 >> 22) & 0xF) + 1;
      *(_WORD *)(v58 + 62) = ((unsigned __int8)((*(_DWORD *)(v4 + 13356) & v59) >> *(_BYTE *)(v4 + 13352)) << *(_DWORD *)(v4 + 13328))
                           | ((*(_DWORD *)(v4 + 13340) & v59) >> *(_BYTE *)(v4 + 13336));
      v63 = *(_DWORD *)(v58 + 48);
      v64 = (unsigned __int8)((*(_DWORD *)(v4 + 13348) & v59) >> *(_BYTE *)(v4 + 13344))
          | (*(unsigned __int8 *)(v58 + 87) << 8);
      *(_WORD *)(v58 + 86) = v64;
      v65 = ((v59 >> 10) & 0xC000 | (v62 << 18)) + (v63 & 0xFFC33FFF);
      *(_DWORD *)(v58 + 48) = v65;
      if ( (v60 & 1) != 0 )
      {
        *(_BYTE *)(v58 + 84) |= 1u;
        if ( (v60 & 4) == 0 )
        {
LABEL_88:
          if ( (v60 & 0x100000) == 0 )
            goto LABEL_89;
          goto LABEL_102;
        }
      }
      else if ( (v60 & 4) == 0 )
      {
        goto LABEL_88;
      }
      *(_BYTE *)(v58 + 84) |= 2u;
      if ( (v60 & 0x100000) == 0 )
      {
LABEL_89:
        if ( (v60 & 0x80000) == 0 )
          goto LABEL_90;
        goto LABEL_103;
      }
LABEL_102:
      *(_BYTE *)(v58 + 84) |= 0x10u;
      if ( (v60 & 0x80000) == 0 )
      {
LABEL_90:
        if ( (v60 & 0x40000) == 0 )
          goto LABEL_91;
        goto LABEL_104;
      }
LABEL_103:
      *(_BYTE *)(v58 + 84) |= 0x20u;
      if ( (v60 & 0x40000) == 0 )
      {
LABEL_91:
        if ( (v61 & 0x8000000) == 0 )
          goto LABEL_93;
LABEL_92:
        *(_WORD *)(v58 + 86) = v64 & 0xF0FF | (v61 >> 28 << 8);
        goto LABEL_93;
      }
LABEL_104:
      *(_BYTE *)(v58 + 84) |= 0x40u;
      if ( (v61 & 0x8000000) != 0 )
        goto LABEL_92;
LABEL_93:
      v66 = v42[7];
      v67 = *(_QWORD *)(v58 + 72);
      v68 = (v59 >> 29) & 1;
      *(_WORD *)(v58 + 60) = (v60 >> 3) & 0x3FFF;
      *(_DWORD *)(v58 + 48) = v65 & 0xFFFFC1FF | (v66 >> 3) & 0x200;
      *(_QWORD *)(v58 + 72) = v67 & 0xFFFFFFFFFFC3FFFFLL | ((unsigned __int64)(unsigned __int8)a3 << 18);
      if ( !v68 )
      {
        v69 = *(_QWORD *)v43;
        if ( (*(_BYTE *)(*(_QWORD *)v43 + 84LL) & 2) != 0 )
        {
          *(_BYTE *)(v69 + 84) = *(_BYTE *)(*(_QWORD *)v43 + 84LL) & 0xFB;
          if ( (v241 & 1) != 0 )
          {
            v5[34] = **((_DWORD **)v5 + 16);
            v69 = *(_QWORD *)v43;
            if ( *(unsigned __int16 *)(*(_QWORD *)v43 + 60LL) / (v229 - *(unsigned __int16 *)(v4 + 1138)) + 1 > v31 )
            {
              ++*(_DWORD *)(v4 + 13700);
              v220 = v5[30];
              if ( !v220 )
                v220 = v238[9];
              v5 = v238;
              v238[30] = v220 - v238[11];
              goto LABEL_135;
            }
          }
          else
          {
            v69 = *(_QWORD *)v43;
          }
        }
        else if ( (v241 & 1) != 0 )
        {
          v70 = 1;
          goto LABEL_111;
        }
        v70 = (*(_BYTE *)(v69 + 84) & 2) == 0;
LABEL_111:
        v241 = v70;
        if ( v43[28] )
          goto LABEL_345;
        if ( (*(_BYTE *)(v4 + 18852) & 1) != 0 )
        {
          if ( v30 )
          {
            *v236 = v69;
            v69 = v30;
            v71 = *(_QWORD *)(v30 + 72);
            v72 = v71 + 0x1000000;
            v73 = v71 & 0xFFFFFFFF00FFFFFFLL;
            v74 = v72 & 0xFF000000;
          }
          else
          {
            v73 = 0x1000000;
            v74 = *(_QWORD *)(v69 + 72) & 0xFFFFFFFF00FFFFFFLL;
          }
          *(_QWORD *)(v69 + 72) = v74 | v73;
          v79 = *(__int64 **)v43;
          **(_QWORD **)v43 = 0;
          if ( (*(_BYTE *)(*(_QWORD *)v43 + 84LL) & 2) != 0 )
          {
            v30 = v69;
            v236 = v79;
            goto LABEL_125;
          }
          v30 = 0;
          if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD))dp_rx_buffer_pool_refill)(
                  v4,
                  v69,
                  (unsigned __int8)v43[28])
              & 1) != 0 )
          {
            v236 = nullptr;
LABEL_125:
            v12 = v248;
            goto LABEL_126;
          }
          v236 = nullptr;
          if ( v28 )
          {
            *v244 = v69;
            v83 = *(_DWORD *)(v69 + 72);
            v69 = v28;
            *(_BYTE *)(v28 + 75) = (unsigned int)(v83 + (*(unsigned __int8 *)(v28 + 75) << 24)) >> 24;
          }
        }
        else
        {
          if ( v28 )
          {
            *v244 = v69;
            v69 = v28;
            v75 = *(_QWORD *)(v28 + 72);
            v76 = v75 + 0x1000000;
            v77 = v75 & 0xFFFFFFFF00FFFFFFLL;
            v78 = v76 & 0xFF000000;
          }
          else
          {
            v77 = 0x1000000;
            v78 = *(_QWORD *)(v69 + 72) & 0xFFFFFFFF00FFFFFFLL;
          }
          *(_QWORD *)(v69 + 72) = v78 | v77;
          v79 = *(__int64 **)v43;
        }
        v28 = v69;
        *v79 = 0;
        v244 = v79;
        goto LABEL_125;
      }
LABEL_126:
      dp_rx_nbuf_unmap(v4, v43, a3);
      if ( (unsigned int)dp_rx_add_to_ipa_desc_free_list(v4, v43, v68) )
      {
        if ( v43[29] || (unsigned __int8)v43[28] > 1u )
          goto LABEL_345;
        *(_QWORD *)v43 = 0;
        v80 = v43[30];
        v81 = v262 + 1;
        *(_QWORD *)v43 = v264[0];
        v82 = v263;
        v262 = v81;
        v43[30] = v80 & 0xFE;
        v264[0] = v43;
        if ( !v82 || !*(_QWORD *)v43 )
          v263 = v43;
      }
      ++v29;
      --v31;
      --a4;
      if ( ((unsigned __int8)v241 & ((int)v29 >= v12)) == 1 )
      {
        ++*(_DWORD *)(v4 + 13688);
LABEL_135:
        v241 = 1;
        goto LABEL_137;
      }
    }
    v29 = v231;
    a4 = v230;
LABEL_137:
    v84 = dp_srng_access_end(a1, v4, v5);
    ++*(_DWORD *)(v235 + 16);
    v85 = *(unsigned int *)(v235 + 40);
    v86 = *(_QWORD *)(v235 + 16) - 1LL;
    *(_DWORD *)(v235 + 16) = v86;
    if ( !v86 || !*(_QWORD *)(v235 + 16) )
      preempt_schedule(v84);
    if ( (unsigned __int8)a3 == 8 || (unsigned int)v85 >= 0x20 )
      goto LABEL_345;
    v87 = v262;
    *(_QWORD *)(v4 + 14224 + (v85 << 6) + 8LL * (unsigned __int8)a3) += v29;
    if ( (_DWORD)v87 )
    {
      LOBYTE(v228) = 0;
      _dp_rx_buffers_replenish(v4, 0, v4 + 80, v4 + 12416, v87, v264, &v263, 0, v228, "dp_rx_buffers_replenish_simple");
    }
    if ( !v28 )
    {
      txrx_peer_and_vdev = 0;
      goto LABEL_292;
    }
    v88 = nullptr;
    v89 = nullptr;
    txrx_peer_and_vdev = 0;
    v245 = nullptr;
    while ( 2 )
    {
      v90 = *(_QWORD *)v28;
      if ( (dp_rx_is_raw_frame_dropped(v28) & 1) != 0 )
      {
        if ( is_dp_verbose_debug_enabled == 1 )
          qdf_trace_msg(0x45u, 8u, "%s: drop raw frame", v91, v92, v93, v94, v95, v96, v97, v98, "dp_rx_process_be");
        ++*(_DWORD *)(v4 + 14156);
        goto LABEL_146;
      }
      v99 = *(_QWORD *)(v28 + 224);
      v100 = *(unsigned __int16 *)(v28 + 86);
      v101 = *(unsigned __int16 *)(v28 + 62);
      v249 = v90;
      v102 = v100 >> 8;
      *(_DWORD *)(v28 + 52) = *(_DWORD *)(v28 + 52) & 0xFFFFF000 | (*(_DWORD *)(v99 + 80) >> 20);
      if ( v88 && v255 && *(unsigned __int8 *)(v255 + 59) != (unsigned __int8)v100 )
      {
        dp_rx_deliver_to_stack(v4, v255, txrx_peer_and_vdev, v88, v245);
        LOBYTE(v102) = *(_BYTE *)(v28 + 87);
        v88 = nullptr;
        v245 = nullptr;
      }
      v103 = v102 & 0xF;
      if ( v103 >= 9 )
      {
        _ZF = is_dp_verbose_debug_enabled == 1;
        ++*(_DWORD *)(v4 + 14200);
        if ( _ZF )
          qdf_trace_msg(0x45u, 8u, "%s: drop invalid tid", v91, v92, v93, v94, v95, v96, v97, v98, "dp_rx_process_be");
        goto LABEL_218;
      }
      if ( !txrx_peer_and_vdev )
      {
        txrx_peer_and_vdev = dp_rx_get_txrx_peer_and_vdev(v4, v28, v101, &v256, &v255, &v254, &v250, &v251);
        if ( txrx_peer_and_vdev && v255 )
          goto LABEL_159;
        if ( is_dp_verbose_debug_enabled == 1 )
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: drop no peer frame",
            v180,
            v181,
            v182,
            v183,
            v184,
            v185,
            v186,
            v187,
            "dp_rx_process_be");
        goto LABEL_237;
      }
      if ( *(unsigned __int16 *)(txrx_peer_and_vdev + 8) != v101 )
      {
        dp_txrx_peer_unref_delete(v256, 2);
        ref_by_id = (__int64 *)dp_peer_get_ref_by_id(v4, v101, 2);
        if ( ref_by_id )
        {
          txrx_peer_and_vdev = *ref_by_id;
          if ( *ref_by_id )
          {
            v255 = *(_QWORD *)txrx_peer_and_vdev;
            v256 = ref_by_id;
            if ( v255 )
            {
              v105 = *(unsigned __int8 *)(*(_QWORD *)(v255 + 24) + 95938LL);
              v254 = *(unsigned __int8 **)(v255 + 24);
              v250 = v105;
              v251 = 255;
              goto LABEL_159;
            }
            _qdf_nbuf_free(v28);
            v216 = v255;
            ++*(_DWORD *)(v4 + 13748);
            if ( v216 )
              goto LABEL_159;
LABEL_190:
            if ( is_dp_verbose_debug_enabled == 1 )
            {
              qdf_trace_msg(
                0x45u,
                8u,
                "%s: drop by unmatch peer_id",
                v137,
                v138,
                v139,
                v140,
                v141,
                v142,
                v143,
                v144,
                "dp_rx_process_be");
              v90 = v249;
            }
            else
            {
LABEL_191:
              v90 = v249;
            }
            goto LABEL_146;
          }
          dp_peer_unref_delete(ref_by_id, 2);
        }
        *(_QWORD *)v28 = 0;
        dp_rx_deliver_to_stack_no_peer(v4, v28);
        txrx_peer_and_vdev = 0;
        goto LABEL_190;
      }
LABEL_159:
      *(_BYTE *)(v28 + 71) &= ~0x80u;
      qdf_dp_trace_set_track(v28, 1);
      *(_BYTE *)(v28 + 85) = *(_BYTE *)(v28 + 85) & 0xF8 | 3;
      if ( (*(_BYTE *)(txrx_peer_and_vdev + 10) & 8) != 0 && (v254[17] & 2) != 0 )
      {
        v114 = (*(_DWORD *)(v28 + 48) >> 18) & 0xF;
        if ( v114 >= 5 )
          goto LABEL_345;
      }
      else
      {
        v114 = 0;
      }
      v115 = v114;
      v116 = v255;
      *(_DWORD *)(v28 + 48) = *(_DWORD *)(v28 + 48) & 0xFE3FFFFF
                            | ((*(_BYTE *)(txrx_peer_and_vdev + v114 + 2221) & 7) << 22);
      if ( (*(_BYTE *)(v116 + 74) & 2) != 0 )
        *(_DWORD *)(v28 + 144) = v103;
      if ( (v250 != 0) | is_peer_ext_stats_enabled & 1 )
      {
        v178 = ktime_get_with_offset(0);
        v179 = *(_DWORD *)(v28 + 129);
        *(_QWORD *)(v28 + 32) = v178;
        *(_DWORD *)(v28 + 129) = v179 & 0xFFFFFFFC;
      }
      if ( v251 != v103 )
      {
        v251 = v103;
        v89 = &v254[5472 * v240 + 42680 + 608 * v103];
      }
      ++HIDWORD(v247);
      if ( (*(_BYTE *)(v28 + 84) & 2) == 0 && (*(_DWORD *)(v99 + 60) & 0x80000000) == 0 )
      {
        ++*(_DWORD *)(v4 + 13768);
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: MSDU DONE failure %d",
          v106,
          v107,
          v108,
          v109,
          v110,
          v111,
          v112,
          v113,
          "dp_rx_process_be");
        v213 = *(void (**)(void))(*(_QWORD *)(v246 + 74392) + 1240LL);
        if ( *((_DWORD *)v213 - 1) != 343547449 )
          __break(0x8228u);
        v213();
        ++*((_QWORD *)v89 + 38);
        goto LABEL_218;
      }
      if ( **(unsigned __int8 **)(v116 + 24) > 1u )
        goto LABEL_345;
      LODWORD(v247) = v247 + 1;
      if ( (*(_BYTE *)(v28 + 84) & 0x80) != 0 )
      {
        v117 = v89;
        v118 = v88;
        v188 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v4 + 1128) + 74392LL) + 496LL);
        if ( *((_DWORD *)v188 - 1) != -1147376687 )
          __break(0x8228u);
        v189 = v188(v99) != 0;
        v190 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v4 + 1128) + 74392LL) + 512LL);
        if ( *((_DWORD *)v190 - 1) != -1147376687 )
          __break(0x8228u);
        v191 = v190(v99) != 0;
        v192 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v4 + 1128) + 74392LL) + 568LL);
        if ( *((_DWORD *)v192 - 1) != -1147376687 )
          __break(0x8228u);
        *(_BYTE *)(v28 + 84) = (16 * v189) | (v191 << 6) | *(_BYTE *)(v28 + 84) & 0x8F | (32 * (v192(v99) != 0));
        v193 = *(_QWORD *)(v28 + 40);
        v194 = *(unsigned __int16 *)(v4 + 1138);
        if ( v193 )
          *(_QWORD *)(v28 + 40) = v193 + v194;
        skb_pull(v28, v194);
        goto LABEL_198;
      }
      if ( (*(_BYTE *)(v28 + 84) & 2) == 0 )
      {
        v117 = v89;
        v118 = v88;
        v119 = (*(_QWORD *)(v99 + 12) >> 58) & 3LL;
        v120 = *(_DWORD *)(v28 + 112);
        v121 = v119 + *(unsigned __int16 *)(v28 + 60) + *(unsigned __int16 *)(v4 + 1138);
        v122 = v121 - v120;
        if ( v121 < v120 )
        {
          skb_trim(v28, v121);
          goto LABEL_197;
        }
        if ( *(_DWORD *)(v28 + 116) )
        {
          v122 = v121 - v120;
          if ( v121 != v120 )
          {
            v133 = 0;
LABEL_194:
            if ( (unsigned int)pskb_expand_head(v28, 0, v133 + v122, 2080) )
              dev_kfree_skb_any_reason(v28, 1);
          }
        }
        else
        {
          v146 = *(_DWORD *)(v28 + 208);
          v145 = *(_DWORD *)(v28 + 212);
          if ( v145 - v146 < v122 )
          {
            v133 = v146 - v145;
            goto LABEL_194;
          }
        }
        skb_put(v28, v121 - *(_DWORD *)(v28 + 112));
LABEL_197:
        dp_rx_skip_tlvs(v4, v28, (unsigned int)v119);
LABEL_198:
        v88 = v118;
        v89 = v117;
        v5 = v238;
LABEL_199:
        v147 = *((void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))v254 + 12064);
        if ( v147 )
        {
          v195 = *(unsigned __int8 *)(v28 + 86);
          v196 = *v254;
          if ( *((_DWORD *)v147 - 1) != -915278510 )
            __break(0x8228u);
          v147(v4, v196, v195, v28, 1, 3);
        }
        if ( (unsigned int)dp_wds_rx_policy_check(v99, v255, txrx_peer_and_vdev) )
        {
          if ( (*(_BYTE *)(txrx_peer_and_vdev + 10) & 1) == 0
            && (*(_BYTE *)(v28 + 74) & 0x80) == 0
            && !_qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(v28 + 224))
            && !_qdf_nbuf_is_ipv4_wapi_pkt(v28) )
          {
            v90 = v249;
            ++*(_DWORD *)(txrx_peer_and_vdev + 4072LL * v115 + 3252);
            if ( is_dp_verbose_debug_enabled == 1 )
            {
              qdf_trace_msg(
                0x45u,
                8u,
                "%s: drop by unauthorized peer",
                v197,
                v198,
                v199,
                v200,
                v201,
                v202,
                v203,
                v204,
                "dp_rx_process_be");
              if ( !v28 )
                goto LABEL_146;
            }
            else if ( !v28 )
            {
              goto LABEL_146;
            }
            _qdf_nbuf_free(v28);
            goto LABEL_146;
          }
          v260 = 0;
          v261 = 0;
          v156 = *(_QWORD *)(v255 + 24);
          LODWORD(v258) = 0;
          v157 = *(_QWORD *)(v156 + 8);
          v259 = 0;
          v158 = *(void (__fastcall **)(__int64, __int64 *, char *, __int64 *))(*(_QWORD *)(*(_QWORD *)(v157 + 1128)
                                                                                          + 74392LL)
                                                                              + 1496LL);
          if ( *((_DWORD *)v158 - 1) != -1038736894 )
            __break(0x8228u);
          v158(v99, &v258, (char *)&v259 + 4, &v259);
          if ( !(_DWORD)v259 )
          {
            if ( (_DWORD)v258 )
            {
              if ( v156 )
                ++*(_DWORD *)(v156 + 492);
            }
            else if ( _qdf_nbuf_data_is_ipv4_udp_pkt(*(_QWORD *)(v28 + 224))
                   || _qdf_nbuf_data_is_ipv4_tcp_pkt(*(_QWORD *)(v28 + 224)) )
            {
              if ( !HIDWORD(v259) )
              {
                HIDWORD(v260) = 32;
                HIDWORD(v261) = 1;
                goto LABEL_210;
              }
LABEL_265:
              if ( v156 )
                ++*(_DWORD *)(v156 + 496);
            }
            else if ( _qdf_nbuf_data_is_ipv6_udp_pkt(*(_QWORD *)(v28 + 224))
                   || _qdf_nbuf_data_is_ipv6_tcp_pkt(*(_QWORD *)(v28 + 224)) )
            {
              if ( HIDWORD(v259) )
                goto LABEL_265;
              HIDWORD(v260) = 32;
            }
          }
LABEL_210:
          _qdf_nbuf_set_rx_cksum(v28, &v260, v159, v160);
          if ( (v254[24] & 1) != 0 )
          {
LABEL_211:
            dp_rx_msdu_stats_update(v4, v28, v99, txrx_peer_and_vdev, a3, v89, v115);
            if ( *(_DWORD *)(v255 + 44) == 2
              && !*(_DWORD *)(v255 + 64)
              && *(_BYTE *)(v255 + 43264) == 1
              && (dp_rx_intrabss_fwd_be(v4, txrx_peer_and_vdev, v99, v28, v115) & 1) != 0 )
            {
              v90 = v249;
              ++*((_QWORD *)v89 + 33);
            }
            else
            {
              dp_rx_fill_gro_info(v4, v99, v28, &v253);
              dp_rx_mark_first_packet_after_wow_wakeup(*(_QWORD *)(v255 + 24), v99, v28);
              dp_rx_update_stats(v4, v28);
              dp_pkt_add_timestamp_0(*(_QWORD *)txrx_peer_and_vdev, 2, v252, v28);
              v90 = v249;
              if ( v88 )
              {
                *v245 = v28;
                v169 = v88[9];
                v170 = v169 + 0x1000000;
                v171 = v169 & 0xFFFFFFFF00FFFFFFLL;
                v172 = v170 & 0xFF000000;
              }
              else
              {
                v171 = 0x1000000;
                v88 = (_QWORD *)v28;
                v172 = *(_QWORD *)(v28 + 72) & 0xFFFFFFFF00FFFFFFLL;
              }
              v88[9] = v172 | v171;
              v173 = txrx_peer_and_vdev + 2288 + 4072LL * v115;
              *(_QWORD *)v28 = 0;
              v174 = *(_QWORD *)(txrx_peer_and_vdev + 40);
              v175 = *(_QWORD *)(v173 + 992);
              ++*(_QWORD *)(txrx_peer_and_vdev + 32);
              v176 = v174 + *(unsigned __int16 *)(v28 + 60);
              v177 = v175 + 1;
              LOBYTE(v175) = *(_BYTE *)(txrx_peer_and_vdev + 10);
              *(_QWORD *)(txrx_peer_and_vdev + 40) = v176;
              *(_QWORD *)(v173 + 992) = v177;
              *(_QWORD *)(v173 + 1000) += *(unsigned __int16 *)(v28 + 60);
              if ( (v175 & 2) != 0 )
              {
                v214 = txrx_peer_and_vdev + 2288 + 4072LL * v115;
                v215 = *(_QWORD *)(v214 + 984);
                ++*(_QWORD *)(v214 + 976);
                *(_QWORD *)(v214 + 984) = v215 + *(unsigned __int16 *)(v28 + 60);
              }
              v245 = (_QWORD *)v28;
              ++*((_QWORD *)v89 + 32);
            }
            goto LABEL_146;
          }
          if ( *(_BYTE *)(v255 + 80) != 1 || (dp_rx_multipass_process(txrx_peer_and_vdev, v28, v103) & 1) != 0 )
          {
            if ( (*(_BYTE *)(txrx_peer_and_vdev + 88) & 1) != 0
              && (*(_BYTE *)(v28 + 84) & 0x10) != 0
              && (*(_BYTE *)(v99 + 80) & 0x20) == 0 )
            {
              ++*((_QWORD *)v89 + 42);
              ++*(_DWORD *)(txrx_peer_and_vdev + 4072LL * v115 + 3120);
              if ( is_dp_verbose_debug_enabled == 1 )
              {
                qdf_trace_msg(
                  0x45u,
                  8u,
                  "%s: drop nawds",
                  v161,
                  v162,
                  v163,
                  v164,
                  v165,
                  v166,
                  v167,
                  v168,
                  "dp_rx_process_be");
                if ( !v28 )
                  goto LABEL_237;
              }
              else if ( !v28 )
              {
                goto LABEL_237;
              }
              goto LABEL_280;
            }
            if ( !*(_DWORD *)(v255 + 64) )
              goto LABEL_211;
            if ( (unsigned int)dp_rx_filter_mesh_packets() )
            {
              dp_rx_fill_mesh_stats(v255, v28, v99, txrx_peer_and_vdev);
              v5 = v238;
              goto LABEL_211;
            }
            qdf_trace_msg(
              0x7Eu,
              5u,
              "%s: %pK: mesh pkt filtered",
              v205,
              v206,
              v207,
              v208,
              v209,
              v210,
              v211,
              v212,
              "dp_rx_process_be",
              v4);
            ++*((_QWORD *)v89 + 43);
            v217 = *(_QWORD *)(v255 + 24);
            if ( v217 )
              ++*(_DWORD *)(v217 + 392);
          }
          else
          {
            ++*(_DWORD *)(txrx_peer_and_vdev + 4072LL * v115 + 3248);
            if ( is_dp_verbose_debug_enabled == 1 )
            {
              qdf_trace_msg(
                0x45u,
                8u,
                "%s: drop multi pass",
                v161,
                v162,
                v163,
                v164,
                v165,
                v166,
                v167,
                v168,
                "dp_rx_process_be");
              if ( !v28 )
                goto LABEL_237;
LABEL_280:
              _qdf_nbuf_free(v28);
LABEL_237:
              v5 = v238;
              v90 = v249;
              goto LABEL_146;
            }
          }
          if ( v28 )
            goto LABEL_280;
          goto LABEL_237;
        }
        qdf_trace_msg(
          0x7Eu,
          2u,
          "%s: %pK: Policy Check Drop pkt",
          v148,
          v149,
          v150,
          v151,
          v152,
          v153,
          v154,
          v155,
          "dp_rx_process_be",
          v4);
        ++*(_DWORD *)(txrx_peer_and_vdev + 4072LL * v115 + 3256);
        ++*((_QWORD *)v89 + 40);
        if ( !v28 )
          goto LABEL_191;
LABEL_218:
        _qdf_nbuf_free(v28);
        v90 = v249;
        goto LABEL_146;
      }
      v123 = *(unsigned __int16 *)(v28 + 60);
      v28 = dp_rx_sg_create(v4, v28);
      v249 = *(_QWORD *)v28;
      if ( (*(_BYTE *)(v28 + 74) & 0x80) != 0 )
      {
        v134 = *(_QWORD *)(v255 + 24);
        if ( v134 )
          ++*(_DWORD *)(v134 + 464);
        v135 = txrx_peer_and_vdev + 4072LL * v115;
        v136 = *(_QWORD *)(v135 + 3112) + v123;
        ++*(_QWORD *)(v135 + 3104);
        *(_QWORD *)(v135 + 3112) = v136;
        goto LABEL_199;
      }
      ++*(_DWORD *)(v4 + 14100);
      if ( (dp_rx_is_sg_supported() & 1) != 0 )
        goto LABEL_199;
      if ( v28 )
        _qdf_nbuf_free(v28);
      v132 = jiffies;
      if ( dp_rx_process_be___last_ticks_14 - jiffies + 125 >= 0 )
        goto LABEL_191;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: sg msdu len %d, dropped",
        v124,
        v125,
        v126,
        v127,
        v128,
        v129,
        v130,
        v131,
        "dp_rx_process_be",
        (unsigned int)v123);
      dp_rx_process_be___last_ticks_14 = v132;
      v90 = v249;
LABEL_146:
      v28 = v90;
      if ( v90 )
        continue;
      break;
    }
    if ( v88 )
    {
      if ( txrx_peer_and_vdev )
      {
        dp_rx_deliver_to_stack(v4, v255, txrx_peer_and_vdev, v88, v245);
      }
      else
      {
        do
        {
          v219 = (_QWORD *)*v88;
          *v88 = 0;
          dp_rx_deliver_to_stack_no_peer(v4, v88);
          v88 = v219;
        }
        while ( v219 );
      }
    }
LABEL_292:
    if ( *(_BYTE *)(*(_QWORD *)(v4 + 40) + 684LL) == 1 && HIDWORD(v247) )
    {
      if ( a4 )
      {
        num_pending = dp_rx_srng_get_num_pending(v246, v5, v234, v257);
        if ( num_pending )
        {
          v10 = num_pending;
          ++*(_DWORD *)(v4 + 13692);
          if ( (((__int64 (__fastcall *)(__int64, _QWORD))hif_exec_should_yield)(v233, v232) & 1) == 0 )
            continue;
          if ( v257[0] == 1 )
          {
            ++*(_DWORD *)(v4 + 13696);
            continue;
          }
        }
      }
      v221 = v255;
      if ( v255 )
      {
        v222 = *(_DWORD **)(v255 + 192);
        if ( v222 )
        {
          if ( *(v222 - 1) != 1663771268 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD))v222)(v4, (unsigned __int8)a3);
        }
        v223 = *(_DWORD **)(v221 + 160);
        if ( v223 && v253 )
        {
          v224 = *(_QWORD *)(v221 + 88);
          if ( *(v223 - 1) != 1663771268 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD))v223)(v224, (unsigned __int8)a3);
        }
      }
    }
    break;
  }
  if ( txrx_peer_and_vdev )
    dp_txrx_peer_unref_delete(v256, 2);
  if ( *(_BYTE *)(v4 + 1120) )
  {
    if ( (_DWORD)v247 )
    {
      if ( (_DWORD)v247 == 1 )
      {
        v225 = *(_QWORD *)(v4 + 72);
        if ( v225 )
          ++*(_DWORD *)(v225 + 7560);
      }
      else
      {
        v226 = *(_DWORD **)(v4 + 72);
        if ( (unsigned int)v247 > 0x14 )
        {
          if ( (unsigned int)v247 > 0x28 )
          {
            if ( (unsigned int)v247 > 0x3C )
            {
              if ( (unsigned int)v247 > 0x50 )
              {
                if ( (unsigned int)v247 > 0x64 )
                {
                  if ( (unsigned int)v247 > 0xC8 )
                  {
                    if ( v226 )
                      ++v226[1897];
                  }
                  else if ( v226 )
                  {
                    ++v226[1896];
                  }
                }
                else if ( v226 )
                {
                  ++v226[1895];
                }
              }
              else if ( v226 )
              {
                ++v226[1894];
              }
            }
            else if ( v226 )
            {
              ++v226[1893];
            }
          }
          else if ( v226 )
          {
            ++v226[1892];
          }
        }
        else if ( v226 )
        {
          ++v226[1891];
        }
      }
    }
    if ( *(unsigned __int8 *)(v4 + 1120) > 1u )
LABEL_345:
      __break(0x5512u);
  }
LABEL_344:
  _ReadStatusReg(SP_EL0);
  return HIDWORD(v247);
}
