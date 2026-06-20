__int64 __fastcall dp_rx_process_be(__int64 a1, _DWORD *a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x19
  _DWORD *v5; // x22
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v7; // x8
  __int64 txrx_peer_and_vdev; // x26
  unsigned int v9; // w20
  __int64 v10; // x8
  int v11; // w24
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w8
  unsigned int v21; // w9
  unsigned int v22; // w11
  unsigned int v23; // w10
  unsigned int v24; // w11
  unsigned int v26; // w8
  __int64 v27; // x27
  unsigned int v28; // w25
  __int64 v29; // x28
  unsigned int v30; // w26
  unsigned int v31; // w20
  char v32; // w12
  __int64 v33; // x10
  __int64 v34; // x21
  unsigned int v35; // w9
  _DWORD *v41; // x21
  _BYTE *v42; // x20
  char v43; // w9
  char v44; // w8
  _BYTE *v45; // x9
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x23
  __int64 v55; // x23
  __int64 v56; // x0
  __int64 v57; // x23
  unsigned int v58; // w8
  unsigned int v59; // w9
  unsigned int v60; // w10
  int v61; // w11
  __int16 v62; // w12
  unsigned int v63; // w10
  unsigned int v64; // w21
  __int64 v65; // x12
  __int64 v66; // x23
  bool v67; // w8
  __int64 v68; // x9
  int v69; // w8
  unsigned __int64 v70; // x9
  unsigned __int64 v71; // x8
  __int64 v72; // x9
  int v73; // w8
  unsigned __int64 v74; // x9
  unsigned __int64 v75; // x8
  __int64 *v76; // x24
  char v77; // w10
  unsigned int v78; // w8
  _BYTE *v79; // x9
  int v80; // w8
  __int64 v81; // x0
  __int64 v82; // x20
  __int64 v83; // x8
  __int64 v84; // x4
  _QWORD *v85; // x28
  unsigned __int8 *v86; // x23
  __int64 v87; // x21
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  __int64 v96; // x25
  unsigned int v97; // w9
  unsigned int v98; // w20
  unsigned int v99; // w8
  unsigned int v100; // w21
  __int64 *ref_by_id; // x0
  int v102; // w9
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  unsigned int v111; // w20
  __int64 v112; // x24
  unsigned int v113; // w22
  unsigned __int8 *v114; // x20
  _QWORD *v115; // x23
  __int64 v116; // x24
  unsigned int v117; // w9
  unsigned int v118; // w28
  unsigned int v119; // w8
  __int64 v120; // x24
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  __int64 v129; // x20
  int v130; // w9
  __int64 v131; // x8
  __int64 v132; // x8
  __int64 v133; // x10
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  int v142; // w9
  int v143; // w10
  void (__fastcall *v144)(__int64, __int64, __int64, __int64, __int64, __int64); // x8
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  __int64 v153; // x24
  __int64 v154; // x8
  void (__fastcall *v155)(__int64, __int64 *, char *, __int64 *); // x8
  __int64 v156; // x2
  __int64 v157; // x3
  double v158; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  __int64 v166; // x9
  int v167; // w8
  unsigned __int64 v168; // x9
  unsigned __int64 v169; // x8
  __int64 v170; // x10
  __int64 v171; // x11
  __int64 v172; // x12
  __int64 v173; // x9
  __int64 v174; // x11
  __int64 v175; // x0
  int v176; // w8
  double v177; // d0
  double v178; // d1
  double v179; // d2
  double v180; // d3
  double v181; // d4
  double v182; // d5
  double v183; // d6
  double v184; // d7
  __int64 v185; // x22
  unsigned int v186; // w19
  unsigned __int8 *v187; // x20
  _QWORD *v188; // x23
  unsigned __int8 (__fastcall *v189)(_QWORD); // x8
  bool v190; // w24
  unsigned __int8 (__fastcall *v191)(_QWORD); // x8
  char v192; // w28
  unsigned __int8 (__fastcall *v193)(_QWORD); // x8
  __int64 v194; // x8
  __int64 v195; // x1
  __int64 v196; // x2
  __int64 v197; // x1
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
  void (*v214)(void); // x8
  __int64 v215; // x8
  __int64 v216; // x10
  __int64 v217; // x9
  __int64 v218; // x8
  unsigned int num_pending; // w0
  _QWORD *v220; // x20
  int v221; // w8
  __int64 v222; // x20
  _DWORD *v223; // x8
  _DWORD *v224; // x8
  __int64 v225; // x0
  __int64 v226; // x8
  _DWORD *v227; // x8
  int v229; // [xsp+0h] [xbp-140h]
  int v230; // [xsp+14h] [xbp-12Ch]
  __int64 v231; // [xsp+18h] [xbp-128h]
  unsigned int v232; // [xsp+24h] [xbp-11Ch]
  unsigned int v233; // [xsp+28h] [xbp-118h]
  unsigned int v234; // [xsp+2Ch] [xbp-114h]
  __int64 v235; // [xsp+30h] [xbp-110h]
  unsigned int v236; // [xsp+3Ch] [xbp-104h]
  __int64 v237; // [xsp+40h] [xbp-100h]
  unsigned __int64 v238; // [xsp+48h] [xbp-F8h]
  __int64 *v239; // [xsp+50h] [xbp-F0h]
  _DWORD *v241; // [xsp+60h] [xbp-E0h]
  __int64 v242; // [xsp+68h] [xbp-D8h]
  char is_peer_ext_stats_enabled; // [xsp+7Ch] [xbp-C4h]
  int v244; // [xsp+80h] [xbp-C0h]
  char v245; // [xsp+8Ch] [xbp-B4h]
  __int64 *v248; // [xsp+A0h] [xbp-A0h]
  _QWORD *v249; // [xsp+A0h] [xbp-A0h]
  __int64 v250; // [xsp+A8h] [xbp-98h]
  __int64 v251; // [xsp+B0h] [xbp-90h]
  int v252; // [xsp+B8h] [xbp-88h]
  __int64 v253; // [xsp+B8h] [xbp-88h]
  int v254; // [xsp+C0h] [xbp-80h] BYREF
  int v255; // [xsp+C4h] [xbp-7Ch] BYREF
  __int64 v256; // [xsp+C8h] [xbp-78h] BYREF
  int v257; // [xsp+D4h] [xbp-6Ch] BYREF
  unsigned __int8 *v258; // [xsp+D8h] [xbp-68h] BYREF
  __int64 v259; // [xsp+E0h] [xbp-60h] BYREF
  __int64 *v260; // [xsp+E8h] [xbp-58h] BYREF
  char v261[4]; // [xsp+F4h] [xbp-4Ch] BYREF
  __int64 v262; // [xsp+F8h] [xbp-48h] BYREF
  __int64 v263; // [xsp+100h] [xbp-40h] BYREF
  __int64 v264; // [xsp+108h] [xbp-38h] BYREF
  __int64 v265; // [xsp+110h] [xbp-30h]
  unsigned int v266; // [xsp+11Ch] [xbp-24h] BYREF
  _BYTE *v267; // [xsp+120h] [xbp-20h] BYREF
  _QWORD v268[3]; // [xsp+128h] [xbp-18h] BYREF

  v268[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 16);
  v261[0] = 0;
  v267 = nullptr;
  v268[0] = 0;
  v260 = nullptr;
  v266 = 0;
  v257 = 0;
  if ( (unsigned __int8)a3 >= 9u )
    goto LABEL_342;
  v5 = a2;
  HIDWORD(v251) = 0;
  v256 = 0;
  if ( !a2 || !v4 )
    goto LABEL_341;
  v250 = *(_QWORD *)(v4 + 1128);
  if ( !v250 )
  {
    HIDWORD(v251) = 0;
    goto LABEL_341;
  }
  v235 = *(_QWORD *)(v4 + 64);
  v234 = *(unsigned __int8 *)(a1 + 32);
  v236 = a2[8];
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v244 = (unsigned __int8)a3;
  if ( 10 * StatusReg >= StatusReg )
    v7 = 10 * StatusReg / 0xC0;
  else
    v7 = 10 * (StatusReg / 0xC0);
  *(_QWORD *)(v4 + 19920) = v7;
  hif_rtpm_mark_last_busy(4);
  txrx_peer_and_vdev = 0;
  v9 = 0;
  v251 = 0;
  v231 = v4 + 13968;
  v241 = v5;
  v242 = v4;
  v230 = (unsigned __int16)wlan_cfg_rx_buffer_size(*(_QWORD *)(v4 + 40));
  v237 = v4 + 14168;
  v238 = _ReadStatusReg(SP_EL0);
  v245 = 1;
  while ( 2 )
  {
    if ( txrx_peer_and_vdev )
      dp_txrx_peer_unref_delete(v260, 2);
    v10 = *(_QWORD *)(v4 + 40);
    v259 = 0;
    v11 = *(_DWORD *)(v10 + 676);
    qdf_mem_set(&v266, 4u, 0);
    qdf_mem_set(v268, 8u, 0);
    qdf_mem_set(&v267, 8u, 0);
    v258 = nullptr;
    v254 = 0;
    v255 = 255;
    dp_pkt_get_timestamp(&v256);
    is_peer_ext_stats_enabled = wlan_cfg_is_peer_ext_stats_enabled(*(_QWORD *)(v4 + 40));
    if ( (unsigned int)dp_srng_access_start(a1, v4, v5) )
    {
      ++*(_DWORD *)(v4 + 13768);
      qdf_trace_msg(
        0x3Fu,
        2u,
        "%s: HAL RING Access Failed -- %pK",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "dp_rx_process_be",
        v5);
      v27 = 0;
      v28 = 0;
      goto LABEL_134;
    }
    v20 = v5[30];
    v21 = v5[34];
    v22 = v21 - v20;
    if ( v5[29] )
    {
      if ( v21 < v20 )
        v22 += v5[9];
      v23 = v5[11];
      v24 = v22 / v23;
    }
    else
    {
      if ( v21 <= v20 )
        v22 += v5[9];
      v23 = v5[11];
      v24 = v22 / v23 - 1;
    }
    if ( v24 > v5[60] )
    {
      v5[60] = v24;
      *((_QWORD *)v5 + 31) = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
    }
    if ( v24 >= v5[69] )
    {
      ++v5[75];
      if ( !v9 )
        goto LABEL_38;
    }
    else if ( v24 >= v5[68] )
    {
      ++v5[74];
      if ( !v9 )
        goto LABEL_38;
    }
    else if ( v24 >= v5[67] )
    {
      ++v5[73];
      if ( !v9 )
        goto LABEL_38;
    }
    else if ( v24 >= v5[66] )
    {
      ++v5[72];
      if ( !v9 )
        goto LABEL_38;
    }
    else if ( v24 >= v5[65] )
    {
      ++v5[71];
      if ( !v9 )
      {
LABEL_38:
        _CF = v21 >= v20;
        v26 = v21 - v20;
        if ( !_CF )
          v26 += v5[9];
        v9 = v26 / v23;
      }
    }
    else
    {
      ++v5[70];
      if ( !v9 )
        goto LABEL_38;
    }
    v27 = 0;
    v28 = 0;
    v29 = 0;
    v248 = nullptr;
    v239 = nullptr;
    if ( v9 >= a4 )
      v30 = a4;
    else
      v30 = v9;
    v252 = v11;
    v232 = a4 - v30;
    v233 = v30;
    while ( v30 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            v31 = v5[30];
            if ( v31 == v5[34] )
              goto LABEL_134;
            v32 = *((_BYTE *)v5 + 78);
            v33 = *(_QWORD *)(v4 + 1128);
            v34 = *((_QWORD *)v5 + 2);
            if ( v5[11] + v31 == v5[9] )
              v35 = 0;
            else
              v35 = v5[11] + v31;
            v5[30] = v35;
            if ( (v32 & 4) != 0 )
            {
              _X23 = v34 + 4LL * v35;
              if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v33 + 8) + 40LL) + 844LL) & 0x40) == 0 )
                _dma_sync_single_for_cpu();
              __asm { PRFM            #0, [X23] }
            }
            v41 = (_DWORD *)(v34 + 4LL * v31);
            if ( !v41 )
              goto LABEL_134;
            if ( (v41[7] & 6) == 0 )
            {
              qdf_trace_msg(
                0x7Eu,
                2u,
                "%s: %pK: HAL RING 0x%pK:error %d",
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                "dp_rx_process_be",
                v4,
                v5,
                0);
              if ( (unsigned __int8)a3 == 8 )
                goto LABEL_342;
              ++*(_DWORD *)(v231 + 4LL * (unsigned __int8)a3);
            }
            v42 = (_BYTE *)((unsigned int)v41[5] | ((unsigned __int64)(unsigned int)v41[6] << 32));
            if ( !v42 )
              v42 = *(_BYTE **)(*(_QWORD *)(*(_QWORD *)(v4 + 22552) + 24LL * (v41[1] >> 21)) + ((v41[1] >> 9) & 0xFF8LL));
            if ( !(unsigned int)dp_rx_desc_sanity(v4, v250, v5, v41, v42) )
              break;
            if ( v42 && *(_QWORD *)v42 )
            {
              if ( (v42[30] & 2) != 0 )
              {
                v56 = printk(
                        &unk_9BB309,
                        "!rx_desc->unmapped",
                        "dp_rx_process_be",
                        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/be/dp_be_rx.c");
                dump_stack(v56);
              }
              dp_rx_nbuf_unmap(v4, v42, a3);
              dp_rx_buffer_pool_nbuf_free(v4, *(_QWORD *)v42, (unsigned __int8)v42[28]);
              if ( v42[29] || (unsigned __int8)v42[28] > 1u )
                goto LABEL_342;
              *(_QWORD *)v42 = 0;
              v43 = v42[30];
              *(_QWORD *)v42 = v268[0];
              v44 = v43 & 0xFE;
              v45 = v267;
              v42[30] = v44;
              v268[0] = v42;
              if ( !v45 || !*(_QWORD *)v42 )
                v267 = v42;
            }
          }
          if ( (v42[30] & 1) != 0 )
            break;
          ++*(_DWORD *)(v4 + 14000);
          v55 = jiffies;
          if ( dp_rx_process_be___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: Reaping rx_desc not in use!",
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              "dp_rx_process_be");
            dp_rx_process_be___last_ticks = v55;
          }
          dp_rx_dump_info_and_assert(v4, v5, v41, v42);
        }
        if ( !(unsigned int)dp_rx_desc_nbuf_sanity_check(v4, v41, v42) )
          break;
        ++*(_DWORD *)(v4 + 14108);
        v54 = jiffies;
        if ( dp_rx_process_be___last_ticks_6 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Nbuf sanity check failure!",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "dp_rx_process_be");
          dp_rx_process_be___last_ticks_6 = v54;
        }
        dp_rx_dump_info_and_assert(v4, v5, v41, v42);
        v42[30] |= 4u;
      }
      v57 = *(_QWORD *)v42;
      v264 = 0;
      v265 = 0;
      v262 = 0;
      qdf_mem_set(&v264, 0x10u, 0);
      qdf_mem_set(&v262, 8u, 0);
      v58 = v41[3];
      v59 = v41[4];
      v60 = v41[2];
      if ( (v59 & 2) != 0 )
      {
        *(_BYTE *)(v57 + 84) |= 4u;
        if ( (v60 & 0x200) != 0 )
        {
LABEL_95:
          *(_BYTE *)(v57 + 84) |= 8u;
          if ( (v60 & 0x2000) == 0 )
            goto LABEL_83;
          goto LABEL_96;
        }
      }
      else if ( (v60 & 0x200) != 0 )
      {
        goto LABEL_95;
      }
      if ( (v60 & 0x2000) == 0 )
        goto LABEL_83;
LABEL_96:
      *(_QWORD *)(v57 + 72) |= 0x800000uLL;
LABEL_83:
      *(_WORD *)(v57 + 62) = v58 & 0x3FFF;
      v61 = *(_DWORD *)(v57 + 48);
      v62 = (unsigned __int8)((*(_DWORD *)(v4 + 13292) & v58) >> *(_BYTE *)(v4 + 13288))
          | (*(unsigned __int8 *)(v57 + 87) << 8);
      *(_WORD *)(v57 + 86) = v62;
      *(_DWORD *)(v57 + 48) = v61 & 0xFFC3FFFF;
      if ( (v59 & 1) != 0 )
      {
        *(_BYTE *)(v57 + 84) |= 1u;
        if ( (v59 & 4) == 0 )
        {
LABEL_85:
          if ( (v59 & 0x100000) == 0 )
            goto LABEL_86;
          goto LABEL_99;
        }
      }
      else if ( (v59 & 4) == 0 )
      {
        goto LABEL_85;
      }
      *(_BYTE *)(v57 + 84) |= 2u;
      if ( (v59 & 0x100000) == 0 )
      {
LABEL_86:
        if ( (v59 & 0x80000) == 0 )
          goto LABEL_87;
        goto LABEL_100;
      }
LABEL_99:
      *(_BYTE *)(v57 + 84) |= 0x10u;
      if ( (v59 & 0x80000) == 0 )
      {
LABEL_87:
        if ( (v59 & 0x40000) == 0 )
          goto LABEL_88;
        goto LABEL_101;
      }
LABEL_100:
      *(_BYTE *)(v57 + 84) |= 0x20u;
      if ( (v59 & 0x40000) == 0 )
      {
LABEL_88:
        if ( (v60 & 0x8000000) == 0 )
          goto LABEL_90;
LABEL_89:
        *(_WORD *)(v57 + 86) = v62 & 0xF0FF | (v60 >> 28 << 8);
        goto LABEL_90;
      }
LABEL_101:
      *(_BYTE *)(v57 + 84) |= 0x40u;
      if ( (v60 & 0x8000000) != 0 )
        goto LABEL_89;
LABEL_90:
      v63 = v41[7];
      v64 = (v58 >> 29) & 1;
      v65 = *(_QWORD *)(v57 + 72);
      *(_WORD *)(v57 + 60) = (v59 >> 3) & 0x3FFF;
      *(_DWORD *)(v57 + 48) = v61 & 0xFFC3C1FF | (v63 >> 3) & 0x200;
      *(_QWORD *)(v57 + 72) = v65 & 0xFFFFFFFFFFC3FFFFLL | ((unsigned __int64)(unsigned __int8)a3 << 18);
      if ( !v64 )
      {
        v66 = *(_QWORD *)v42;
        if ( (*(_BYTE *)(*(_QWORD *)v42 + 84LL) & 2) != 0 )
        {
          *(_BYTE *)(v66 + 84) = *(_BYTE *)(*(_QWORD *)v42 + 84LL) & 0xFB;
          if ( (v245 & 1) != 0 )
          {
            v5[34] = **((_DWORD **)v5 + 16);
            v66 = *(_QWORD *)v42;
            if ( *(unsigned __int16 *)(*(_QWORD *)v42 + 60LL) / (v230 - *(unsigned __int16 *)(v4 + 1138)) + 1 > v30 )
            {
              ++*(_DWORD *)(v4 + 13644);
              v221 = v5[30];
              if ( !v221 )
                v221 = v241[9];
              v5 = v241;
              v4 = v242;
              v241[30] = v221 - v241[11];
              goto LABEL_132;
            }
          }
          else
          {
            v66 = *(_QWORD *)v42;
          }
        }
        else if ( (v245 & 1) != 0 )
        {
          v67 = 1;
          goto LABEL_108;
        }
        v67 = (*(_BYTE *)(v66 + 84) & 2) == 0;
LABEL_108:
        v245 = v67;
        if ( v42[28] )
          goto LABEL_342;
        if ( (*(_BYTE *)(v4 + 18796) & 1) != 0 )
        {
          if ( v29 )
          {
            *v239 = v66;
            v66 = v29;
            v68 = *(_QWORD *)(v29 + 72);
            v69 = v68 + 0x1000000;
            v70 = v68 & 0xFFFFFFFF00FFFFFFLL;
            v71 = v69 & 0xFF000000;
          }
          else
          {
            v70 = 0x1000000;
            v71 = *(_QWORD *)(v66 + 72) & 0xFFFFFFFF00FFFFFFLL;
          }
          *(_QWORD *)(v66 + 72) = v71 | v70;
          v76 = *(__int64 **)v42;
          **(_QWORD **)v42 = 0;
          if ( (*(_BYTE *)(*(_QWORD *)v42 + 84LL) & 2) != 0 )
          {
            v29 = v66;
            v239 = v76;
            goto LABEL_122;
          }
          v29 = 0;
          if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD))dp_rx_buffer_pool_refill)(
                  v4,
                  v66,
                  (unsigned __int8)v42[28])
              & 1) != 0 )
          {
            v239 = nullptr;
LABEL_122:
            v11 = v252;
            goto LABEL_123;
          }
          v239 = nullptr;
          if ( v27 )
          {
            *v248 = v66;
            v80 = *(_DWORD *)(v66 + 72);
            v66 = v27;
            *(_BYTE *)(v27 + 75) = (unsigned int)(v80 + (*(unsigned __int8 *)(v27 + 75) << 24)) >> 24;
          }
        }
        else
        {
          if ( v27 )
          {
            *v248 = v66;
            v66 = v27;
            v72 = *(_QWORD *)(v27 + 72);
            v73 = v72 + 0x1000000;
            v74 = v72 & 0xFFFFFFFF00FFFFFFLL;
            v75 = v73 & 0xFF000000;
          }
          else
          {
            v74 = 0x1000000;
            v75 = *(_QWORD *)(v66 + 72) & 0xFFFFFFFF00FFFFFFLL;
          }
          *(_QWORD *)(v66 + 72) = v75 | v74;
          v76 = *(__int64 **)v42;
        }
        v27 = v66;
        *v76 = 0;
        v248 = v76;
        goto LABEL_122;
      }
LABEL_123:
      dp_rx_nbuf_unmap(v4, v42, a3);
      if ( (unsigned int)dp_rx_add_to_ipa_desc_free_list(v4, v42, v64) )
      {
        if ( v42[29] || (unsigned __int8)v42[28] > 1u )
          goto LABEL_342;
        *(_QWORD *)v42 = 0;
        v77 = v42[30];
        v78 = v266 + 1;
        *(_QWORD *)v42 = v268[0];
        v79 = v267;
        v266 = v78;
        v42[30] = v77 & 0xFE;
        v268[0] = v42;
        if ( !v79 || !*(_QWORD *)v42 )
          v267 = v42;
      }
      ++v28;
      --v30;
      --a4;
      if ( ((unsigned __int8)v245 & ((int)v28 >= v11)) == 1 )
      {
        ++*(_DWORD *)(v4 + 13632);
LABEL_132:
        v245 = 1;
        goto LABEL_134;
      }
    }
    v28 = v233;
    a4 = v232;
LABEL_134:
    v81 = dp_srng_access_end(a1, v4, v5);
    ++*(_DWORD *)(v238 + 16);
    v82 = *(unsigned int *)(v238 + 40);
    v83 = *(_QWORD *)(v238 + 16) - 1LL;
    *(_DWORD *)(v238 + 16) = v83;
    if ( !v83 || !*(_QWORD *)(v238 + 16) )
      preempt_schedule(v81);
    if ( (unsigned __int8)a3 == 8 || (unsigned int)v82 >= 0x20 )
      goto LABEL_342;
    v84 = v266;
    *(_QWORD *)(v237 + (v82 << 6) + 8LL * (unsigned __int8)a3) += v28;
    if ( (_DWORD)v84 )
    {
      LOBYTE(v229) = 0;
      _dp_rx_buffers_replenish(v4, 0, v4 + 80, v4 + 12368, v84, v268, &v267, 0, v229, "dp_rx_buffers_replenish_simple");
    }
    if ( !v27 )
    {
      txrx_peer_and_vdev = 0;
      goto LABEL_289;
    }
    v85 = nullptr;
    v86 = nullptr;
    txrx_peer_and_vdev = 0;
    v249 = nullptr;
    while ( 2 )
    {
      v87 = *(_QWORD *)v27;
      if ( (dp_rx_is_raw_frame_dropped(v27) & 1) != 0 )
      {
        if ( is_dp_verbose_debug_enabled == 1 )
          qdf_trace_msg(0x45u, 8u, "%s: drop raw frame", v88, v89, v90, v91, v92, v93, v94, v95, "dp_rx_process_be");
        ++*(_DWORD *)(v4 + 14100);
        goto LABEL_143;
      }
      v96 = *(_QWORD *)(v27 + 224);
      v97 = *(unsigned __int16 *)(v27 + 86);
      v98 = *(unsigned __int16 *)(v27 + 62);
      v253 = v87;
      v99 = v97 >> 8;
      *(_DWORD *)(v27 + 52) = *(_DWORD *)(v27 + 52) & 0xFFFFF000 | (*(_DWORD *)(v96 + 80) >> 20);
      if ( v85 && v259 && *(unsigned __int8 *)(v259 + 59) != (unsigned __int8)v97 )
      {
        dp_rx_deliver_to_stack(v4, v259, txrx_peer_and_vdev, v85, v249);
        LOBYTE(v99) = *(_BYTE *)(v27 + 87);
        v85 = nullptr;
        v249 = nullptr;
      }
      v100 = v99 & 0xF;
      if ( v100 >= 9 )
      {
        _ZF = is_dp_verbose_debug_enabled == 1;
        ++*(_DWORD *)(v4 + 14144);
        if ( _ZF )
          qdf_trace_msg(0x45u, 8u, "%s: drop invalid tid", v88, v89, v90, v91, v92, v93, v94, v95, "dp_rx_process_be");
        goto LABEL_215;
      }
      if ( !txrx_peer_and_vdev )
      {
        txrx_peer_and_vdev = dp_rx_get_txrx_peer_and_vdev(v4, v27, v98, &v260, &v259, &v258, &v254, &v255);
        if ( txrx_peer_and_vdev && v259 )
          goto LABEL_156;
        if ( is_dp_verbose_debug_enabled == 1 )
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: drop no peer frame",
            v177,
            v178,
            v179,
            v180,
            v181,
            v182,
            v183,
            v184,
            "dp_rx_process_be");
        goto LABEL_234;
      }
      if ( *(unsigned __int16 *)(txrx_peer_and_vdev + 8) != v98 )
      {
        dp_txrx_peer_unref_delete(v260, 2);
        ref_by_id = (__int64 *)dp_peer_get_ref_by_id(v4, v98, 2);
        if ( ref_by_id )
        {
          txrx_peer_and_vdev = *ref_by_id;
          if ( *ref_by_id )
          {
            v259 = *(_QWORD *)txrx_peer_and_vdev;
            v260 = ref_by_id;
            if ( v259 )
            {
              v102 = *(unsigned __int8 *)(*(_QWORD *)(v259 + 24) + 95042LL);
              v258 = *(unsigned __int8 **)(v259 + 24);
              v254 = v102;
              v255 = 255;
              goto LABEL_156;
            }
            _qdf_nbuf_free(v27);
            v217 = v259;
            ++*(_DWORD *)(v4 + 13692);
            if ( v217 )
              goto LABEL_156;
LABEL_187:
            if ( is_dp_verbose_debug_enabled == 1 )
            {
              qdf_trace_msg(
                0x45u,
                8u,
                "%s: drop by unmatch peer_id",
                v134,
                v135,
                v136,
                v137,
                v138,
                v139,
                v140,
                v141,
                "dp_rx_process_be");
              v87 = v253;
            }
            else
            {
LABEL_188:
              v87 = v253;
            }
            goto LABEL_143;
          }
          dp_peer_unref_delete(ref_by_id, 2);
        }
        *(_QWORD *)v27 = 0;
        dp_rx_deliver_to_stack_no_peer(v4, v27);
        txrx_peer_and_vdev = 0;
        goto LABEL_187;
      }
LABEL_156:
      *(_BYTE *)(v27 + 71) &= ~0x80u;
      qdf_dp_trace_set_track(v27, 1);
      *(_BYTE *)(v27 + 85) = *(_BYTE *)(v27 + 85) & 0xF8 | 3;
      if ( (*(_BYTE *)(txrx_peer_and_vdev + 10) & 8) != 0 && (v258[17] & 2) != 0 )
        v111 = (*(_DWORD *)(v27 + 48) >> 18) & 0xF;
      else
        v111 = 0;
      v112 = v259;
      if ( (*(_BYTE *)(v259 + 74) & 2) != 0 )
        *(_DWORD *)(v27 + 144) = v100;
      if ( (v254 != 0) | is_peer_ext_stats_enabled & 1 )
      {
        v175 = ktime_get_with_offset(0);
        v176 = *(_DWORD *)(v27 + 129);
        *(_QWORD *)(v27 + 32) = v175;
        *(_DWORD *)(v27 + 129) = v176 & 0xFFFFFFFC;
      }
      if ( v255 != v100 )
      {
        v255 = v100;
        v86 = &v258[5472 * v244 + 41856 + 608 * v100];
      }
      ++HIDWORD(v251);
      if ( (*(_BYTE *)(v27 + 84) & 2) == 0 && (*(_DWORD *)(v96 + 60) & 0x80000000) == 0 )
      {
        ++*(_DWORD *)(v4 + 13712);
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: MSDU DONE failure %d",
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          v109,
          v110,
          "dp_rx_process_be");
        v214 = *(void (**)(void))(*(_QWORD *)(v250 + 74392) + 1240LL);
        if ( *((_DWORD *)v214 - 1) != 343547449 )
          __break(0x8228u);
        v214();
        ++*((_QWORD *)v86 + 38);
        goto LABEL_215;
      }
      if ( **(unsigned __int8 **)(v112 + 24) > 1u )
        goto LABEL_342;
      LODWORD(v251) = v251 + 1;
      if ( (*(_BYTE *)(v27 + 84) & 0x80) != 0 )
      {
        v185 = v4;
        v186 = v111;
        v187 = v86;
        v188 = v85;
        v189 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v185 + 1128) + 74392LL) + 496LL);
        if ( *((_DWORD *)v189 - 1) != -1147376687 )
          __break(0x8228u);
        v190 = v189(v96) != 0;
        v191 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v185 + 1128) + 74392LL) + 512LL);
        if ( *((_DWORD *)v191 - 1) != -1147376687 )
          __break(0x8228u);
        v192 = v191(v96) != 0;
        v193 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v185 + 1128) + 74392LL) + 568LL);
        if ( *((_DWORD *)v193 - 1) != -1147376687 )
          __break(0x8228u);
        *(_BYTE *)(v27 + 84) = (16 * v190) | (v192 << 6) | *(_BYTE *)(v27 + 84) & 0x8F | (32 * (v193(v96) != 0));
        v194 = *(_QWORD *)(v27 + 40);
        v195 = *(unsigned __int16 *)(v185 + 1138);
        if ( v194 )
          *(_QWORD *)(v27 + 40) = v194 + v195;
        skb_pull(v27, v195);
        v85 = v188;
        v86 = v187;
        v111 = v186;
        v4 = v242;
        goto LABEL_195;
      }
      if ( (*(_BYTE *)(v27 + 84) & 2) == 0 )
      {
        v113 = v111;
        v114 = v86;
        v115 = v85;
        v116 = (*(_QWORD *)(v96 + 12) >> 58) & 3LL;
        v117 = *(_DWORD *)(v27 + 112);
        v118 = v116 + *(unsigned __int16 *)(v27 + 60) + *(unsigned __int16 *)(v4 + 1138);
        v119 = v118 - v117;
        if ( v118 < v117 )
        {
          skb_trim(v27, v118);
          goto LABEL_194;
        }
        if ( *(_DWORD *)(v27 + 116) )
        {
          v119 = v118 - v117;
          if ( v118 != v117 )
          {
            v130 = 0;
LABEL_191:
            if ( (unsigned int)pskb_expand_head(v27, 0, v130 + v119, 2080) )
              dev_kfree_skb_any_reason(v27, 1);
          }
        }
        else
        {
          v143 = *(_DWORD *)(v27 + 208);
          v142 = *(_DWORD *)(v27 + 212);
          if ( v142 - v143 < v119 )
          {
            v130 = v143 - v142;
            goto LABEL_191;
          }
        }
        skb_put(v27, v118 - *(_DWORD *)(v27 + 112));
LABEL_194:
        v4 = v242;
        dp_rx_skip_tlvs(v242, v27, (unsigned int)v116);
        v85 = v115;
        v86 = v114;
        v111 = v113;
LABEL_195:
        v5 = v241;
LABEL_196:
        v144 = *((void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))v258 + 11948);
        if ( v144 )
        {
          v196 = *(unsigned __int8 *)(v27 + 86);
          v197 = *v258;
          if ( *((_DWORD *)v144 - 1) != -915278510 )
            __break(0x8228u);
          v144(v4, v197, v196, v27, 1, 3);
        }
        if ( (unsigned int)dp_wds_rx_policy_check(v96, v259, txrx_peer_and_vdev) )
        {
          if ( (*(_BYTE *)(txrx_peer_and_vdev + 10) & 1) == 0
            && (*(_BYTE *)(v27 + 74) & 0x80) == 0
            && !_qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(v27 + 224))
            && !_qdf_nbuf_is_ipv4_wapi_pkt(v27) )
          {
            v87 = v253;
            ++*(_DWORD *)(txrx_peer_and_vdev + 3256LL * v111 + 3188);
            if ( is_dp_verbose_debug_enabled == 1 )
            {
              qdf_trace_msg(
                0x45u,
                8u,
                "%s: drop by unauthorized peer",
                v198,
                v199,
                v200,
                v201,
                v202,
                v203,
                v204,
                v205,
                "dp_rx_process_be");
              if ( !v27 )
                goto LABEL_143;
            }
            else if ( !v27 )
            {
              goto LABEL_143;
            }
            _qdf_nbuf_free(v27);
            goto LABEL_143;
          }
          v264 = 0;
          v265 = 0;
          v153 = *(_QWORD *)(v259 + 24);
          LODWORD(v262) = 0;
          v154 = *(_QWORD *)(v153 + 8);
          v263 = 0;
          v155 = *(void (__fastcall **)(__int64, __int64 *, char *, __int64 *))(*(_QWORD *)(*(_QWORD *)(v154 + 1128)
                                                                                          + 74392LL)
                                                                              + 1496LL);
          if ( *((_DWORD *)v155 - 1) != -1038736894 )
            __break(0x8228u);
          v155(v96, &v262, (char *)&v263 + 4, &v263);
          if ( !(_DWORD)v263 )
          {
            if ( (_DWORD)v262 )
            {
              if ( v153 )
                ++*(_DWORD *)(v153 + 492);
            }
            else if ( _qdf_nbuf_data_is_ipv4_udp_pkt(*(_QWORD *)(v27 + 224))
                   || _qdf_nbuf_data_is_ipv4_tcp_pkt(*(_QWORD *)(v27 + 224)) )
            {
              if ( !HIDWORD(v263) )
              {
                HIDWORD(v264) = 32;
                HIDWORD(v265) = 1;
                goto LABEL_207;
              }
LABEL_262:
              if ( v153 )
                ++*(_DWORD *)(v153 + 496);
            }
            else if ( _qdf_nbuf_data_is_ipv6_udp_pkt(*(_QWORD *)(v27 + 224))
                   || _qdf_nbuf_data_is_ipv6_tcp_pkt(*(_QWORD *)(v27 + 224)) )
            {
              if ( HIDWORD(v263) )
                goto LABEL_262;
              HIDWORD(v264) = 32;
            }
          }
LABEL_207:
          _qdf_nbuf_set_rx_cksum(v27, &v264, v156, v157);
          if ( (v258[24] & 1) != 0 )
          {
LABEL_208:
            dp_rx_msdu_stats_update(v4, v27, v96, txrx_peer_and_vdev, a3, v86, v111);
            if ( *(_DWORD *)(v259 + 44) == 2
              && !*(_DWORD *)(v259 + 64)
              && *(_BYTE *)(v259 + 42440) == 1
              && (dp_rx_intrabss_fwd_be(v4, txrx_peer_and_vdev, v96, v27, v111) & 1) != 0 )
            {
              v87 = v253;
              ++*((_QWORD *)v86 + 33);
            }
            else
            {
              dp_rx_fill_gro_info(v4, v96, v27, &v257);
              dp_rx_mark_first_packet_after_wow_wakeup(*(_QWORD *)(v259 + 24), v96, v27);
              dp_rx_update_stats(v4, v27);
              dp_pkt_add_timestamp_0(*(_QWORD *)txrx_peer_and_vdev, 2, v256, v27);
              v87 = v253;
              if ( v85 )
              {
                *v249 = v27;
                v166 = v85[9];
                v167 = v166 + 0x1000000;
                v168 = v166 & 0xFFFFFFFF00FFFFFFLL;
                v169 = v167 & 0xFF000000;
              }
              else
              {
                v168 = 0x1000000;
                v85 = (_QWORD *)v27;
                v169 = *(_QWORD *)(v27 + 72) & 0xFFFFFFFF00FFFFFFLL;
              }
              v85[9] = v169 | v168;
              v170 = txrx_peer_and_vdev + 2224 + 3256LL * v111;
              *(_QWORD *)v27 = 0;
              v171 = *(_QWORD *)(txrx_peer_and_vdev + 40);
              v172 = *(_QWORD *)(v170 + 992);
              ++*(_QWORD *)(txrx_peer_and_vdev + 32);
              v173 = v171 + *(unsigned __int16 *)(v27 + 60);
              v174 = v172 + 1;
              LOBYTE(v172) = *(_BYTE *)(txrx_peer_and_vdev + 10);
              *(_QWORD *)(txrx_peer_and_vdev + 40) = v173;
              *(_QWORD *)(v170 + 992) = v174;
              *(_QWORD *)(v170 + 1000) += *(unsigned __int16 *)(v27 + 60);
              if ( (v172 & 2) != 0 )
              {
                v215 = txrx_peer_and_vdev + 2224 + 3256LL * v111;
                v216 = *(_QWORD *)(v215 + 984);
                ++*(_QWORD *)(v215 + 976);
                *(_QWORD *)(v215 + 984) = v216 + *(unsigned __int16 *)(v27 + 60);
              }
              v249 = (_QWORD *)v27;
              ++*((_QWORD *)v86 + 32);
            }
            goto LABEL_143;
          }
          if ( *(_BYTE *)(v259 + 80) != 1 || (dp_rx_multipass_process(txrx_peer_and_vdev, v27, v100) & 1) != 0 )
          {
            if ( (*(_BYTE *)(txrx_peer_and_vdev + 88) & 1) != 0
              && (*(_BYTE *)(v27 + 84) & 0x10) != 0
              && (*(_BYTE *)(v96 + 80) & 0x20) == 0 )
            {
              ++*((_QWORD *)v86 + 42);
              ++*(_DWORD *)(txrx_peer_and_vdev + 3256LL * v111 + 3056);
              if ( is_dp_verbose_debug_enabled == 1 )
              {
                qdf_trace_msg(
                  0x45u,
                  8u,
                  "%s: drop nawds",
                  v158,
                  v159,
                  v160,
                  v161,
                  v162,
                  v163,
                  v164,
                  v165,
                  "dp_rx_process_be");
                if ( !v27 )
                  goto LABEL_234;
              }
              else if ( !v27 )
              {
                goto LABEL_234;
              }
              goto LABEL_277;
            }
            if ( !*(_DWORD *)(v259 + 64) )
              goto LABEL_208;
            if ( (unsigned int)dp_rx_filter_mesh_packets() )
            {
              dp_rx_fill_mesh_stats(v259, v27, v96, txrx_peer_and_vdev);
              v5 = v241;
              v4 = v242;
              goto LABEL_208;
            }
            qdf_trace_msg(
              0x7Eu,
              5u,
              "%s: %pK: mesh pkt filtered",
              v206,
              v207,
              v208,
              v209,
              v210,
              v211,
              v212,
              v213,
              "dp_rx_process_be",
              v242);
            ++*((_QWORD *)v86 + 43);
            v218 = *(_QWORD *)(v259 + 24);
            if ( v218 )
              ++*(_DWORD *)(v218 + 392);
          }
          else
          {
            ++*(_DWORD *)(txrx_peer_and_vdev + 3256LL * v111 + 3184);
            if ( is_dp_verbose_debug_enabled == 1 )
            {
              qdf_trace_msg(
                0x45u,
                8u,
                "%s: drop multi pass",
                v158,
                v159,
                v160,
                v161,
                v162,
                v163,
                v164,
                v165,
                "dp_rx_process_be");
              if ( !v27 )
                goto LABEL_234;
LABEL_277:
              _qdf_nbuf_free(v27);
LABEL_234:
              v5 = v241;
              v4 = v242;
              v87 = v253;
              goto LABEL_143;
            }
          }
          if ( v27 )
            goto LABEL_277;
          goto LABEL_234;
        }
        qdf_trace_msg(
          0x7Eu,
          2u,
          "%s: %pK: Policy Check Drop pkt",
          v145,
          v146,
          v147,
          v148,
          v149,
          v150,
          v151,
          v152,
          "dp_rx_process_be",
          v4);
        ++*(_DWORD *)(txrx_peer_and_vdev + 3256LL * v111 + 3192);
        ++*((_QWORD *)v86 + 40);
        if ( !v27 )
          goto LABEL_188;
LABEL_215:
        _qdf_nbuf_free(v27);
        v87 = v253;
        goto LABEL_143;
      }
      v120 = *(unsigned __int16 *)(v27 + 60);
      v27 = dp_rx_sg_create(v4, v27);
      v253 = *(_QWORD *)v27;
      if ( (*(_BYTE *)(v27 + 74) & 0x80) != 0 )
      {
        v131 = *(_QWORD *)(v259 + 24);
        if ( v131 )
          ++*(_DWORD *)(v131 + 464);
        v132 = txrx_peer_and_vdev + 3256LL * v111;
        v133 = *(_QWORD *)(v132 + 3048) + v120;
        ++*(_QWORD *)(v132 + 3040);
        *(_QWORD *)(v132 + 3048) = v133;
        goto LABEL_196;
      }
      ++*(_DWORD *)(v4 + 14044);
      if ( (dp_rx_is_sg_supported() & 1) != 0 )
        goto LABEL_196;
      if ( v27 )
        _qdf_nbuf_free(v27);
      v129 = jiffies;
      if ( dp_rx_process_be___last_ticks_14 - jiffies + 125 >= 0 )
        goto LABEL_188;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: sg msdu len %d, dropped",
        v121,
        v122,
        v123,
        v124,
        v125,
        v126,
        v127,
        v128,
        "dp_rx_process_be",
        (unsigned int)v120);
      dp_rx_process_be___last_ticks_14 = v129;
      v87 = v253;
LABEL_143:
      v27 = v87;
      if ( v87 )
        continue;
      break;
    }
    if ( v85 )
    {
      if ( txrx_peer_and_vdev )
      {
        dp_rx_deliver_to_stack(v4, v259, txrx_peer_and_vdev, v85, v249);
      }
      else
      {
        do
        {
          v220 = (_QWORD *)*v85;
          *v85 = 0;
          dp_rx_deliver_to_stack_no_peer(v4, v85);
          v85 = v220;
        }
        while ( v220 );
      }
    }
LABEL_289:
    if ( *(_BYTE *)(*(_QWORD *)(v4 + 40) + 684LL) == 1 && HIDWORD(v251) )
    {
      if ( a4 )
      {
        num_pending = dp_rx_srng_get_num_pending(v250, v5, v236, v261);
        if ( num_pending )
        {
          v9 = num_pending;
          ++*(_DWORD *)(v4 + 13636);
          if ( (((__int64 (__fastcall *)(__int64, _QWORD))hif_exec_should_yield)(v235, v234) & 1) == 0 )
            continue;
          if ( v261[0] == 1 )
          {
            ++*(_DWORD *)(v4 + 13640);
            continue;
          }
        }
      }
      v222 = v259;
      if ( v259 )
      {
        v223 = *(_DWORD **)(v259 + 184);
        if ( v223 )
        {
          if ( *(v223 - 1) != 1663771268 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD))v223)(v4, (unsigned __int8)a3);
        }
        v224 = *(_DWORD **)(v222 + 152);
        if ( v224 && v257 )
        {
          v225 = *(_QWORD *)(v222 + 88);
          if ( *(v224 - 1) != 1663771268 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD))v224)(v225, (unsigned __int8)a3);
        }
      }
    }
    break;
  }
  if ( txrx_peer_and_vdev )
    dp_txrx_peer_unref_delete(v260, 2);
  if ( *(_BYTE *)(v4 + 1120) )
  {
    if ( (_DWORD)v251 )
    {
      if ( (_DWORD)v251 == 1 )
      {
        v226 = *(_QWORD *)(v4 + 72);
        if ( v226 )
          ++*(_DWORD *)(v226 + 6744);
      }
      else
      {
        v227 = *(_DWORD **)(v4 + 72);
        if ( (unsigned int)v251 > 0x14 )
        {
          if ( (unsigned int)v251 > 0x28 )
          {
            if ( (unsigned int)v251 > 0x3C )
            {
              if ( (unsigned int)v251 > 0x50 )
              {
                if ( (unsigned int)v251 > 0x64 )
                {
                  if ( (unsigned int)v251 > 0xC8 )
                  {
                    if ( v227 )
                      ++v227[1693];
                  }
                  else if ( v227 )
                  {
                    ++v227[1692];
                  }
                }
                else if ( v227 )
                {
                  ++v227[1691];
                }
              }
              else if ( v227 )
              {
                ++v227[1690];
              }
            }
            else if ( v227 )
            {
              ++v227[1689];
            }
          }
          else if ( v227 )
          {
            ++v227[1688];
          }
        }
        else if ( v227 )
        {
          ++v227[1687];
        }
      }
    }
    if ( *(unsigned __int8 *)(v4 + 1120) > 1u )
LABEL_342:
      __break(0x5512u);
  }
LABEL_341:
  _ReadStatusReg(SP_EL0);
  return HIDWORD(v251);
}
