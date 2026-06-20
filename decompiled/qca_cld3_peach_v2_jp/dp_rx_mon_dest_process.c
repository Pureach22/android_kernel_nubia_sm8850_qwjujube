__int64 __fastcall dp_rx_mon_dest_process(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned __int8 *v14; // x8
  unsigned int v15; // w24
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x10
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v21; // x8
  __int64 v22; // x2
  __int64 v28; // x20
  int v29; // w23
  int v30; // w9
  char v31; // w12
  int v32; // w11
  __int64 v33; // x9
  unsigned int v34; // w10
  __int64 v36; // x0
  __int64 v37; // x9
  unsigned __int64 v38; // x13
  __int64 v39; // x10
  __int64 v40; // x9
  __int64 v41; // x1
  __int64 v42; // x8
  __int64 v43; // x8
  _DWORD *v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned __int8 *v53; // x9
  __int64 v54; // x20
  __int64 v55; // x21
  unsigned int v56; // w22
  unsigned int v57; // w23
  void (__fastcall *v58)(unsigned int *, unsigned __int64 *); // x8
  __int64 v59; // x26
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  char v68; // w9
  unsigned int v69; // w8
  unsigned int v70; // w8
  __int64 v71; // x20
  __int64 v72; // x10
  unsigned int v73; // w9
  __int64 v74; // x10
  __int64 v75; // x10
  _QWORD *v76; // x10
  unsigned __int64 v77; // x1
  unsigned __int16 v78; // w27
  unsigned __int64 v79; // x24
  _QWORD *v80; // x23
  unsigned int v81; // w25
  __int64 v82; // x28
  __int64 v83; // x0
  _DWORD *v84; // x8
  __int64 v85; // x9
  unsigned int v86; // w8
  int v87; // w19
  __int64 v88; // x9
  __int64 v89; // x25
  __int64 v90; // x21
  __int64 v91; // x22
  __int64 v92; // x0
  __int64 v93; // x26
  char v94; // w9
  char v95; // w8
  __int64 v96; // x9
  __int64 v97; // x26
  unsigned __int8 (__fastcall *v98)(_QWORD); // x8
  __int64 (__fastcall *v99)(__int64, unsigned int *); // x8
  unsigned int v100; // w22
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  unsigned int v109; // w5
  __int64 v110; // x8
  __int64 v111; // x0
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  _QWORD *v120; // x22
  int v121; // w25
  unsigned int (__fastcall *v122)(_QWORD); // x8
  void (__fastcall *v123)(__int64, __int64); // x8
  int v124; // w21
  __int64 (__fastcall *v125)(_QWORD); // x8
  unsigned __int16 v126; // w0
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  int v135; // w8
  unsigned __int16 v136; // w22
  unsigned int v137; // w27
  __int64 v138; // x8
  int v139; // w4
  __int64 (__fastcall *v140)(_QWORD); // x8
  int v141; // w0
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  __int64 v150; // x8
  char v151; // w22
  __int64 v152; // x8
  unsigned int (__fastcall *v153)(_QWORD); // x8
  __int64 (__fastcall *v154)(_QWORD); // x8
  char v155; // w22
  int v156; // w9
  int v157; // w10
  __int64 v158; // x0
  void (__fastcall *v159)(__int64, char *, __int64); // x8
  int v160; // w8
  unsigned int v161; // w26
  unsigned int v162; // w25
  unsigned int v163; // w9
  unsigned int v164; // w22
  unsigned int v165; // w8
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  int v174; // w9
  int v175; // w9
  int v176; // w10
  _QWORD *v177; // x8
  _QWORD *v178; // x9
  unsigned __int64 v179; // x1
  __int64 v180; // x2
  __int64 v181; // x3
  unsigned int v182; // w23
  void (__fastcall *v183)(__int64 *, unsigned __int64, __int64, __int64); // x8
  void (__fastcall *v184)(unsigned __int64, unsigned __int64 *); // x8
  double v185; // d0
  double v186; // d1
  double v187; // d2
  double v188; // d3
  double v189; // d4
  double v190; // d5
  double v191; // d6
  double v192; // d7
  __int64 v193; // x0
  __int64 v194; // x8
  __int64 v195; // x21
  __int64 v196; // x0
  __int64 v197; // x21
  unsigned int v198; // w8
  double v199; // d0
  double v200; // d1
  double v201; // d2
  double v202; // d3
  double v203; // d4
  double v204; // d5
  double v205; // d6
  double v206; // d7
  int v207; // w8
  int v208; // w8
  int v209; // w9
  char v210; // w12
  int v211; // w11
  __int64 v212; // x9
  unsigned int v213; // w10
  __int64 v215; // x0
  __int64 v216; // x9
  unsigned __int64 v217; // x13
  __int64 v218; // x10
  __int64 v219; // x9
  __int64 v220; // x1
  __int64 v222; // x9
  __int64 v223; // x8
  __int64 v224; // x8
  __int64 v225; // x8
  __int64 v226; // x10
  __int64 v227; // x9
  __int64 *v228; // x8
  __int64 *v229; // x10
  __int64 *v230; // x2
  __int64 v231; // x8
  __int64 v232; // [xsp+0h] [xbp-1A0h]
  unsigned int v233; // [xsp+1Ch] [xbp-184h]
  __int64 v234; // [xsp+20h] [xbp-180h]
  __int64 v235; // [xsp+28h] [xbp-178h]
  unsigned int v236; // [xsp+34h] [xbp-16Ch]
  __int64 v237; // [xsp+38h] [xbp-168h]
  unsigned int v238; // [xsp+44h] [xbp-15Ch]
  __int64 v239; // [xsp+48h] [xbp-158h]
  unsigned __int8 *v240; // [xsp+50h] [xbp-150h]
  _DWORD *v241; // [xsp+58h] [xbp-148h]
  unsigned int *v242; // [xsp+60h] [xbp-140h]
  unsigned int v243; // [xsp+68h] [xbp-138h]
  unsigned __int64 v244; // [xsp+70h] [xbp-130h]
  int v245; // [xsp+7Ch] [xbp-124h]
  _QWORD *v246; // [xsp+80h] [xbp-120h]
  _QWORD *v247; // [xsp+88h] [xbp-118h]
  int v248; // [xsp+94h] [xbp-10Ch]
  __int64 v249; // [xsp+98h] [xbp-108h]
  int v250; // [xsp+A4h] [xbp-FCh]
  unsigned int v251; // [xsp+A8h] [xbp-F8h]
  unsigned int v252; // [xsp+ACh] [xbp-F4h]
  unsigned __int8 *v253; // [xsp+B0h] [xbp-F0h]
  char v254; // [xsp+BCh] [xbp-E4h]
  unsigned __int16 v255; // [xsp+BCh] [xbp-E4h]
  __int64 v256; // [xsp+C8h] [xbp-D8h]
  __int64 v257; // [xsp+D0h] [xbp-D0h]
  char v258; // [xsp+DCh] [xbp-C4h]
  unsigned int v259; // [xsp+DCh] [xbp-C4h]
  __int64 v260; // [xsp+E0h] [xbp-C0h] BYREF
  unsigned int *v261; // [xsp+E8h] [xbp-B8h] BYREF
  unsigned __int64 v262; // [xsp+F0h] [xbp-B0h] BYREF
  __int64 v263; // [xsp+F8h] [xbp-A8h]
  unsigned __int16 v264[2]; // [xsp+100h] [xbp-A0h] BYREF
  char v265[4]; // [xsp+104h] [xbp-9Ch] BYREF
  __int64 v266; // [xsp+108h] [xbp-98h] BYREF
  _QWORD v267[6]; // [xsp+110h] [xbp-90h] BYREF
  _QWORD v268[4]; // [xsp+140h] [xbp-60h] BYREF
  _QWORD v269[8]; // [xsp+160h] [xbp-40h] BYREF

  v3 = a1;
  v269[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40))
    && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(v3 + 40), a3)
    || (v14 = *(unsigned __int8 **)(v3 + 72), v260 = 0, v261 = nullptr, (v240 = v14) == nullptr) )
  {
    result = qdf_trace_msg(
               0x85u,
               8u,
               "%s: %pK: pdev is null for mac_id = %d",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "dp_rx_mon_dest_process",
               v3,
               a3);
    goto LABEL_246;
  }
  v15 = (unsigned __int8)a3;
  v235 = a2;
  if ( (unsigned __int8)a3 >= 3u )
    goto LABEL_247;
  v16 = *((_QWORD *)v14 + 1);
  v17 = *((_QWORD *)v14 + 11945);
  v18 = *(_QWORD *)(v16 + 40);
  v243 = a3 & 3;
  if ( *(_BYTE *)(v18 + 633) == 1 )
  {
    if ( (unsigned __int8)a3 != 2 )
    {
      a2 = *(_QWORD *)(v16 + 80LL * (a3 & 3) + 640);
      if ( !a2 )
        goto LABEL_22;
      goto LABEL_14;
    }
LABEL_247:
    __break(0x5512u);
    __break(1u);
LABEL_248:
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s %d : HAL Mon Dest Ring access Failed -- %pK",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "dp_rx_mon_dest_process",
      697,
      a2);
    result = qdf_spin_unlock_bh_15(v237 + 32);
    goto LABEL_246;
  }
  if ( *(_BYTE *)(v18 + 804) != 1 )
  {
    if ( (unsigned __int8)a3 == 2 )
      goto LABEL_247;
    v16 += 80LL * (a3 & 3);
  }
  a2 = *(_QWORD *)(v16 + 320);
  if ( !a2 )
  {
LABEL_22:
    result = qdf_trace_msg(
               0x85u,
               2u,
               "%s: %pK: : HAL Monitor Destination Ring Init Failed -- %pK",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "dp_rx_mon_dest_process",
               v3,
               a2);
    goto LABEL_246;
  }
LABEL_14:
  if ( !*(_BYTE *)(a2 + 1) )
    goto LABEL_22;
  v234 = *(_QWORD *)(v3 + 1128);
  v239 = a2;
  v237 = v17 + 18528LL * (a3 & 3) + 8;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v237 + 32);
  }
  else
  {
    raw_spin_lock_bh(v237 + 32);
    *(_QWORD *)(v237 + 40) |= 1uLL;
  }
  if ( (unsigned int)dp_srng_access_start(v235, v3, (char *)a2) )
    goto LABEL_248;
  v21 = *(unsigned int *)(a2 + 120);
  v233 = *v240;
  if ( v21 == *(_DWORD *)(a2 + 136) )
  {
    v22 = a2;
    a2 = 0;
    goto LABEL_236;
  }
  v22 = a2;
  a2 = 0;
  v257 = v3;
  v238 = a3;
  v251 = (unsigned __int8)a3;
  v252 = *(_DWORD *)(v237 + 3264);
  while ( 2 )
  {
    v242 = (unsigned int *)(*(_QWORD *)(v22 + 16) + 4 * v21);
    if ( !v242 )
      goto LABEL_235;
    LOBYTE(v267[0]) = 0;
    v28 = *((_QWORD *)v240 + 11945) + 18528LL * v243;
    if ( *(_DWORD *)(v28 + 32) == 3 )
    {
LABEL_29:
      a3 = v238;
      v29 = dp_rx_mon_drop_one_mpdu(v240, v238, v242, &v261, &v260);
      v30 = *(_DWORD *)(v239 + 120);
      if ( v30 == *(_DWORD *)(v239 + 136) )
        goto LABEL_26;
      v31 = *(_BYTE *)(v239 + 78);
      v32 = *(_DWORD *)(v239 + 44) + v30;
      v33 = *(_QWORD *)(v239 + 16);
      v34 = v32 == *(_DWORD *)(v239 + 36) ? 0 : v32;
      *(_DWORD *)(v239 + 120) = v34;
      if ( (v31 & 4) == 0 )
        goto LABEL_26;
      _X20 = v33 + 4LL * v34;
      v36 = *(_QWORD *)(*(_QWORD *)(v234 + 8) + 40LL);
      if ( (*(_BYTE *)(v36 + 844) & 0x40) == 0 )
      {
        v37 = _X20 << 8 >> 8;
        v38 = (unsigned __int64)(v37 + 0x8000000000LL) >> 38;
        v39 = memstart_addr + v37 + 0x8000000000LL;
        v40 = v37 - kimage_voffset;
        if ( v38 )
          v41 = v40;
        else
          v41 = v39;
        _dma_sync_single_for_cpu(v36, v41);
      }
      __asm { PRFM            #0, [X20] }
      goto LABEL_25;
    }
    v42 = *(_QWORD *)(*((_QWORD *)v240 + 1) + 1128LL);
    if ( v42 && (v43 = *(_QWORD *)(v42 + 74392)) != 0 )
    {
      v44 = *(_DWORD **)(v43 + 1640);
      if ( v44 )
      {
        if ( *(v44 - 1) != 1978482051 )
          __break(0x8228u);
        if ( !((unsigned int (__fastcall *)(unsigned int *, _QWORD *))v44)(v242, v267)
          && LOBYTE(v267[0]) != *(unsigned __int8 *)(v28 + 8) )
        {
          goto LABEL_29;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x46u,
        2u,
        "%s: hal handle is NULL",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "hal_rx_reo_ent_get_src_link_id");
    }
    if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v3 + 40))
      && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(v3 + 40), v238) )
    {
      v53 = nullptr;
    }
    else
    {
      v53 = *(unsigned __int8 **)(v3 + 72);
    }
    memset(v269, 0, 48);
    memset(v268, 0, sizeof(v268));
    memset(v267, 0, sizeof(v267));
    v264[0] = 0;
    v262 = 0;
    v263 = 0;
    v266 = 0;
    v236 = a2;
    if ( !v53 )
    {
      qdf_trace_msg(
        0x85u,
        8u,
        "%s: %pK: pdev is null for mac_id = %d",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "dp_rx_mon_mpdu_pop",
        v3,
        v238);
      v71 = 0;
      v247 = nullptr;
      goto LABEL_214;
    }
    v253 = v53;
    v241 = v53 + 93492;
    v54 = *((_QWORD *)v53 + 11945);
    v55 = v54 + 18528LL * v243;
    v56 = v242[2];
    v57 = v242[7] >> 28;
    v58 = *(void (__fastcall **)(unsigned int *, unsigned __int64 *))(*(_QWORD *)(*(_QWORD *)(v3 + 1128) + 74392LL)
                                                                    + 1456LL);
    v59 = v55 + 8;
    if ( *((_DWORD *)v58 - 1) != -621572614 )
      __break(0x8228u);
    v58(v242, &v262);
    v262 = *v242 | ((unsigned __int64)*((unsigned __int8 *)v242 + 4) << 32);
    LODWORD(v232) = v57;
    qdf_trace_msg(
      0x45u,
      8u,
      "[%s][%d] ReoAddr=%pK, addrInfo=%pK, paddr=0x%llx, loopcnt=%d",
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      "hal_rx_reo_ent_buf_paddr_get",
      427,
      v242,
      v242,
      v232);
    *(_BYTE *)(v55 + 3229) = 0;
    v68 = 0;
    v69 = *((unsigned __int8 *)v242 + 24);
    if ( (v69 & 3) == 0 )
    {
      v70 = (v69 >> 2) & 0x1F;
      if ( v70 < 2 || v70 == 13 || v70 == 2 && (*(_DWORD *)(v54 + 39100) || *(_BYTE *)(v54 + 39098) == 1) )
      {
        v68 = 1;
        ++*(_DWORD *)(v55 + 1920);
      }
      else
      {
        v68 = 0;
      }
      *(_BYTE *)(v55 + 3229) = 1;
    }
    v71 = 0;
    a2 = 0;
    v245 = (unsigned __int8)v56;
    v258 = v68;
    v246 = nullptr;
    v247 = nullptr;
    v250 = 0;
    LOBYTE(v248) = 0;
    v249 = 0;
    v254 = 1;
    v256 = v59;
    do
    {
      if ( !v245 )
      {
        ++*v241;
        v258 = 1;
      }
      if ( *(_QWORD *)(v59 + 3224) == v262 )
      {
        v71 = 0;
        ++*(_DWORD *)(v59 + 1916);
        goto LABEL_210;
      }
      v72 = *((_QWORD *)v253 + 1);
      v73 = ((unsigned int)v263 >> 5) & 0x3FF;
      if ( *(_BYTE *)(*(_QWORD *)(v72 + 40) + 633LL) == 1 )
      {
        v74 = *(_QWORD *)(v72 + 20056);
        if ( v74 )
        {
          v75 = v74 + 40LL * v243;
          if ( v75 )
          {
            if ( v73 < *(unsigned __int16 *)(v75 + 2) )
            {
              v76 = (_QWORD *)(v75 + 8);
              goto LABEL_76;
            }
          }
        }
      }
      else if ( v73 < *(unsigned __int16 *)(v72 + 1866) )
      {
        v76 = (_QWORD *)(v72 + 1872);
LABEL_76:
        v77 = *(_QWORD *)(*v76 + 24LL * v73) + v262 - *(_QWORD *)(*v76 + 24LL * v73 + 16);
        if ( v77 )
          goto LABEL_77;
      }
      v196 = printk(
               &unk_9BB309,
               "rx_msdu_link_desc",
               "dp_rx_mon_mpdu_pop",
               "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/1.0/dp_rx_mon_dest_1.0.c");
      dump_stack(v196);
      v77 = 0;
LABEL_77:
      v244 = v77;
      hal_rx_msdu_list_get_0(*(_QWORD *)(v3 + 1128), v77, v267, v264);
      v78 = v264[0];
      if ( v264[0] )
      {
        v79 = 0;
        v80 = v267;
        while ( 1 )
        {
          if ( v79 == 6 )
            goto LABEL_247;
          v81 = *((_DWORD *)v268 + v79);
          if ( *(_BYTE *)(*(_QWORD *)(v3 + 40) + 633LL) == 1 )
            break;
          v84 = *(_DWORD **)(v3 + 1408);
          if ( *(v84 - 1) != 207937137 )
            __break(0x8228u);
          v82 = ((__int64 (__fastcall *)(__int64, _QWORD))v84)(v3, v81);
          if ( !v82 )
            goto LABEL_85;
LABEL_89:
          v71 = *(_QWORD *)v82;
          if ( *(_QWORD *)v82 && *(_DWORD *)(v59 + 3232) != v81 )
          {
            v85 = 40;
            if ( (*(_BYTE *)(v71 + 68) & 4) != 0 )
              v85 = 80;
            if ( v269[v79] == *(_QWORD *)(v71 + v85) && (*(_BYTE *)(v82 + 30) & 1) != 0 )
            {
              if ( (*(_BYTE *)(v82 + 30) & 2) == 0 )
              {
                if ( (*(_BYTE *)(*(_QWORD *)(v3 + 40) + 633LL) & 1) != 0 )
                {
                  v86 = v251;
                  v87 = a2;
                  v88 = 11408;
                }
                else
                {
                  v86 = *v253;
                  if ( v86 > 4 )
                    goto LABEL_247;
                  v87 = a2;
                  v88 = 12368;
                }
                v89 = *(_QWORD *)(v71 + 40);
                v90 = *(_QWORD *)(v257 + 24);
                v91 = *(unsigned __int16 *)(v257 + v88 + 120LL * v86 + 74);
                if ( (_qdf_is_pp_nbuf(*(_QWORD *)v82) & 1) != 0 && *(_QWORD *)(v71 + 40) )
                {
                  v92 = *(_QWORD *)(v90 + 40);
                  if ( (*(_BYTE *)(v92 + 844) & 0x40) == 0 )
                    _dma_sync_single_for_cpu(v92, v89);
                }
                else if ( v89 )
                {
                  v93 = *(int *)(v71 + 212);
                  qdf_mem_dp_rx_skb_cnt_dec();
                  qdf_mem_dp_rx_skb_dec(v93);
                  qdf_mem_skb_total_dec(v93);
                  dma_unmap_page_attrs(*(_QWORD *)(v90 + 40), v89, v91, 2, 0);
                }
                v59 = v256;
                LODWORD(a2) = v87;
                v3 = v257;
                *(_BYTE *)(v82 + 30) |= 2u;
              }
              if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD))dp_rx_buffer_pool_refill)(
                      v3,
                      v71,
                      *(unsigned __int8 *)(v82 + 28))
                  & 1) != 0 )
              {
                v71 = 0;
                *(_QWORD *)(v59 + 3224) = v262;
                goto LABEL_114;
              }
              if ( (v258 & 1) != 0 )
              {
                *(_QWORD *)(v59 + 3224) = v262;
                if ( *(_QWORD *)v82 )
                  _qdf_nbuf_free(*(_QWORD *)v82);
                v71 = 0;
                goto LABEL_114;
              }
              if ( *(_QWORD *)v82 )
                v97 = *(_QWORD *)(*(_QWORD *)v82 + 224LL);
              else
                v97 = 0;
              qdf_trace_msg(
                0x85u,
                8u,
                "%s: %pK: i=%d, ppdu_id=%x, num_msdus = %u",
                v6,
                v7,
                v8,
                v9,
                v10,
                v11,
                v12,
                v13,
                "dp_rx_mon_mpdu_pop",
                v3,
                (unsigned int)v79,
                v252,
                v78);
              if ( (v254 & 1) != 0 )
              {
                v98 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v3 + 1128) + 74392LL) + 936LL);
                if ( !v98 )
                  goto LABEL_254;
                if ( *((_DWORD *)v98 - 1) != -2091637267 )
                  __break(0x8228u);
                if ( v98(v97) )
                {
                  v99 = *(__int64 (__fastcall **)(__int64, unsigned int *))(*(_QWORD *)(*(_QWORD *)(v3 + 1128) + 74392LL)
                                                                          + 688LL);
                  if ( *((_DWORD *)v99 - 1) != 1363182085 )
                    __break(0x8228u);
                  v100 = v99(v97, v242);
                  qdf_trace_msg(
                    0x85u,
                    8u,
                    "%s: %pK: msdu_ppdu_id=%x",
                    v101,
                    v102,
                    v103,
                    v104,
                    v105,
                    v106,
                    v107,
                    v108,
                    "dp_rx_mon_mpdu_pop",
                    v3,
                    v100);
                  v109 = v252;
                  if ( v252 > v100 )
                  {
                    qdf_trace_msg(
                      0x85u,
                      8u,
                      "%s: %pK: ppdu_id=%d msdu_ppdu_id=%d",
                      v6,
                      v7,
                      v8,
                      v9,
                      v10,
                      v11,
                      v12,
                      v13,
                      "dp_rx_mon_mpdu_pop",
                      v3);
                    v109 = v252;
                  }
                  if ( v100 > v109 && (v100 - v109) >> 5 < 0x271 || v252 > v100 && v252 - v100 > 0x4E20 )
                  {
                    v15 = v251;
                    v71 = 0;
                    v252 = v100;
                    if ( (_DWORD)a2 )
                      goto LABEL_211;
                    goto LABEL_214;
                  }
                  v110 = 2976;
                  if ( v252 == v100 )
                    v110 = 2980;
                  ++*(_DWORD *)(v256 + v110);
                  *(_QWORD *)(v256 + 3224) = v262;
                  v111 = _qdf_nbuf_alloc(0, 256, 256, 4, 0, "dp_rx_mon_alloc_parent_buffer", 780);
                  if ( v111 )
                  {
                    v120 = (_QWORD *)v111;
                    qdf_mem_set(
                      *(void **)(v111 + 216),
                      *(_DWORD *)(v111 + 224) - (unsigned int)*(_QWORD *)(v111 + 216),
                      0);
                    v247 = v120;
                    *v120 = 0;
                    goto LABEL_137;
                  }
                  ++*((_DWORD *)v253 + 109);
                  if ( v97 )
                    page_frag_free(v97);
                  qdf_trace_msg(
                    0x85u,
                    8u,
                    "%s: failed to allocate parent buffer to hold all frag",
                    v112,
                    v113,
                    v114,
                    v115,
                    v116,
                    v117,
                    v118,
                    v119,
                    "dp_rx_mon_mpdu_pop");
                  v247 = nullptr;
                  v254 = 0;
                  v258 = 1;
LABEL_193:
                  v59 = v256;
                }
                else
                {
LABEL_254:
                  if ( *(_QWORD *)v82 )
                    _qdf_nbuf_free(*(_QWORD *)v82);
                  v59 = v256;
                  v71 = 0;
                  *(_QWORD *)(v256 + 3224) = v262;
                  v254 = 1;
LABEL_114:
                  v258 = 1;
                }
                a2 = (unsigned int)(a2 + 1);
                *(_DWORD *)(v59 + 3232) = *((_DWORD *)v268 + v79);
                *(_QWORD *)v82 = 0;
                v94 = *(_BYTE *)(v82 + 30);
                *(_QWORD *)v82 = v261;
                v95 = v94 & 0xFE;
                v96 = v260;
                *(_BYTE *)(v82 + 30) = v95;
                v261 = (unsigned int *)v82;
                if ( !v96 || !*(_QWORD *)v82 )
                  v260 = v82;
                goto LABEL_80;
              }
LABEL_137:
              v121 = a2;
              v122 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v3 + 1128) + 74392LL) + 528LL);
              if ( *((_DWORD *)v122 - 1) != -1536295579 )
                __break(0x8228u);
              if ( v122(v97) )
              {
                v123 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(*(_QWORD *)(v3 + 1128) + 74392LL) + 288LL);
                if ( *((_DWORD *)v123 - 1) != -70876208 )
                  __break(0x8228u);
                v123(v97, v256 + 3336);
              }
              v124 = *(unsigned __int16 *)(v3 + 1140);
              v125 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v3 + 1128) + 74392LL) + 536LL);
              if ( *((_DWORD *)v125 - 1) != 855462014 )
                __break(0x8228u);
              v126 = v125(v97);
              v259 = *(_DWORD *)v80;
              if ( (*(_DWORD *)v80 & 4) != 0 )
              {
                v135 = 1664 - v124;
                v136 = 0;
                LODWORD(a2) = v121;
                v137 = v135 & 0xFFFFFF80;
                v138 = v249;
                v139 = v137 + v250;
                if ( (v248 & 1) == 0 )
                  v138 = v97;
                v249 = v138;
              }
              else
              {
                v255 = v126;
                v140 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v3 + 1128) + 74392LL) + 1232LL);
                if ( *((_DWORD *)v140 - 1) != -1536295579 )
                  __break(0x8228u);
                v141 = v140(v97);
                v150 = *(_QWORD *)(v3 + 1128);
                v151 = 4 * (v141 == 0);
                if ( v150 && (v152 = *(_QWORD *)(v150 + 74392)) != 0 )
                {
                  v153 = *(unsigned int (__fastcall **)(_QWORD))(v152 + 1536);
                  LODWORD(a2) = v121;
                  if ( v153 )
                  {
                    if ( *((_DWORD *)v153 - 1) != -1536295579 )
                      __break(0x8228u);
                    if ( v153(v97) )
                      v151 |= 8u;
                  }
                }
                else
                {
                  qdf_trace_msg(
                    0x46u,
                    2u,
                    "%s: hal handle is NULL",
                    v142,
                    v143,
                    v144,
                    v145,
                    v146,
                    v147,
                    v148,
                    v149,
                    "hal_rx_tlv_mpdu_len_err_get");
                  LODWORD(a2) = v121;
                }
                v154 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(v3 + 1128) + 74392LL) + 536LL);
                if ( *((_DWORD *)v154 - 1) != 855462014 )
                  __break(0x8228u);
                v155 = v151 & 0xCF | (16 * (v154(v97) & 3));
                v156 = *((unsigned __int16 *)v80 + 2);
                if ( (v248 & 1) != 0 )
                  v157 = v250;
                else
                  v157 = 0;
                if ( (v248 & 1) != 0 )
                  v158 = v249;
                else
                  v158 = v97;
                v159 = *(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)(*(_QWORD *)(v3 + 1128) + 74392LL)
                                                                       + 1576LL);
                v265[0] = v155;
                v137 = v156 - v157;
                if ( *((_DWORD *)v159 - 1) != -128330861 )
                  __break(0x8228u);
                v159(v158, v265, 1);
                v139 = v250;
                v136 = v255;
                v249 = 0;
                v160 = v245 - 1;
                if ( !v245 )
                  v160 = 0;
                v245 = v160;
              }
              v250 = v139;
              qdf_trace_msg(
                0x85u,
                8u,
                "%s: total_len %u frag_len %u flags %u",
                v127,
                v128,
                v129,
                v130,
                v131,
                v132,
                v133,
                v134,
                "dp_rx_mon_mpdu_pop");
              v161 = *(unsigned __int16 *)(v3 + 1140);
              v162 = v136;
              v163 = *(_DWORD *)(v71 + 112);
              v164 = v137 + v136 + v161;
              v165 = v164 - v163;
              if ( v164 < v163 )
              {
                skb_trim(v71, v164);
                goto LABEL_185;
              }
              if ( *(_DWORD *)(v71 + 116) )
              {
                v165 = v164 - v163;
                if ( v164 != v163 )
                {
                  v174 = 0;
LABEL_182:
                  if ( (unsigned int)pskb_expand_head(v71, 0, v174 + v165, 2080) )
                    dev_kfree_skb_any_reason(v71, 1);
                }
              }
              else
              {
                v176 = *(_DWORD *)(v71 + 208);
                v175 = *(_DWORD *)(v71 + 212);
                if ( v175 - v176 < v165 )
                {
                  v174 = v176 - v175;
                  goto LABEL_182;
                }
              }
              skb_put(v71, v164 - *(_DWORD *)(v71 + 112));
LABEL_185:
              v248 = (v259 >> 2) & 1;
              LODWORD(v232) = v137;
              qdf_trace_msg(
                0x85u,
                8u,
                "%s: %pK: rx_pkt_offset=%d, l2_hdr_offset=%d, msdu_len=%d, frag_len %u",
                v166,
                v167,
                v168,
                v169,
                v170,
                v171,
                v172,
                v173,
                "dp_rx_mon_mpdu_pop",
                v3,
                v161,
                v162,
                *((unsigned __int16 *)v80 + 2),
                v232);
              v177 = v247;
              if ( v247 )
              {
                v178 = v246;
                v254 = 0;
                v258 = 0;
                v246 = (_QWORD *)v71;
                if ( v178 )
                  v177 = v178;
                *v177 = v71;
              }
              else
              {
                v254 = 0;
                v258 = 0;
                v246 = (_QWORD *)v71;
                v247 = (_QWORD *)v71;
              }
              goto LABEL_193;
            }
          }
          ++*(_DWORD *)(v59 + 1920);
          *(_QWORD *)(v59 + 3224) = v262;
          v258 = 1;
LABEL_80:
          v78 = v264[0];
          ++v79;
          ++v80;
          if ( v79 >= v264[0] )
            goto LABEL_195;
        }
        if ( (v81 & 0xF0000) == 0 )
        {
          v82 = *(_QWORD *)(*(_QWORD *)(v3 + 11432) + 8LL * (unsigned __int8)BYTE1(*((_DWORD *)v268 + v79)))
              + (unsigned __int8)*((_DWORD *)v268 + v79) * (unsigned int)*(unsigned __int16 *)(v3 + 11412);
          if ( v82 )
            goto LABEL_89;
        }
LABEL_85:
        v83 = printk(
                &unk_9BB309,
                "rx_desc",
                "dp_rx_mon_mpdu_pop",
                "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/1.0/dp_rx_mon_dest_1.0.c");
        dump_stack(v83);
        v82 = 0;
        goto LABEL_89;
      }
LABEL_195:
      v179 = v262;
      v180 = (unsigned int)v263;
      v181 = BYTE4(v263);
      v182 = a2;
      v183 = *(void (__fastcall **)(__int64 *, unsigned __int64, __int64, __int64))(*(_QWORD *)(*(_QWORD *)(v3 + 1128)
                                                                                              + 74392LL)
                                                                                  + 1472LL);
      if ( *((_DWORD *)v183 - 1) != -1494657337 )
        __break(0x8228u);
      v183(&v266, v179, v180, v181);
      v184 = *(void (__fastcall **)(unsigned __int64, unsigned __int64 *))(*(_QWORD *)(*(_QWORD *)(v3 + 1128) + 74392LL)
                                                                         + 1456LL);
      if ( *((_DWORD *)v184 - 1) != -621572614 )
        __break(0x8228u);
      v184(v244 + 4, &v262);
      v193 = *((_QWORD *)v253 + 1);
      v194 = *(_QWORD *)(v193 + 40);
      v262 = *(unsigned int *)(v244 + 4) | ((unsigned __int64)*(unsigned __int8 *)(v244 + 8) << 32);
      if ( *(_BYTE *)(v194 + 633) == 1 )
      {
        v15 = v251;
        if ( !(unsigned int)dp_rx_mon_link_desc_return((__int64)v253, (unsigned int *)&v266, v243) )
          goto LABEL_65;
      }
      else
      {
        v15 = v251;
        if ( !(unsigned int)dp_rx_link_desc_return_by_addr(
                              v193,
                              (unsigned int *)&v266,
                              0,
                              v185,
                              v186,
                              v187,
                              v188,
                              v189,
                              v190,
                              v191,
                              v192) )
          goto LABEL_65;
      }
      v195 = jiffies;
      if ( dp_rx_mon_mpdu_pop___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: monitor link desc return failed",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "dp_rx_mon_mpdu_pop");
        dp_rx_mon_mpdu_pop___last_ticks = v195;
      }
LABEL_65:
      a2 = v182;
    }
    while ( v262 );
    if ( v246 )
      *v246 = 0;
LABEL_210:
    if ( (_DWORD)a2 )
    {
LABEL_211:
      v29 = a2;
      v197 = v237;
      *(_DWORD *)(v237 + 28) = 0;
      goto LABEL_217;
    }
LABEL_214:
    v197 = v237;
    v198 = *(_DWORD *)(v237 + 28) + 1;
    *(_DWORD *)(v237 + 28) = v198;
    if ( v198 >= 0x11 )
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: destination ring stuck",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "dp_rx_mon_dest_process");
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: ppdu_id status=%d dest=%d",
        v199,
        v200,
        v201,
        v202,
        v203,
        v204,
        v205,
        v206,
        "dp_rx_mon_dest_process",
        *(unsigned int *)(v237 + 3264),
        v252);
      v207 = *(_DWORD *)(v237 + 2956);
      *(_DWORD *)(v237 + 3264) = v252;
      v29 = 0;
      a3 = v238;
      *(_DWORD *)(v237 + 2956) = v207 + 1;
      LODWORD(a2) = v236;
      goto LABEL_26;
    }
    v29 = 0;
LABEL_217:
    v208 = *(_DWORD *)(v197 + 3264);
    if ( v252 == v208 )
    {
      LODWORD(a2) = v236;
      if ( v247 && v71 )
      {
        ++*(_DWORD *)(v237 + 1908);
        ((void (__fastcall *)(__int64, _QWORD))dp_rx_mon_deliver)(v3, v238);
      }
      v209 = *(_DWORD *)(v239 + 120);
      if ( v209 != *(_DWORD *)(v239 + 136) )
      {
        v210 = *(_BYTE *)(v239 + 78);
        v211 = *(_DWORD *)(v239 + 44) + v209;
        v212 = *(_QWORD *)(v239 + 16);
        v213 = v211 == *(_DWORD *)(v239 + 36) ? 0 : v211;
        *(_DWORD *)(v239 + 120) = v213;
        if ( (v210 & 4) != 0 )
        {
          _X20 = v212 + 4LL * v213;
          v215 = *(_QWORD *)(*(_QWORD *)(v234 + 8) + 40LL);
          if ( (*(_BYTE *)(v215 + 844) & 0x40) == 0 )
          {
            v216 = _X20 << 8 >> 8;
            v217 = (unsigned __int64)(v216 + 0x8000000000LL) >> 38;
            v218 = memstart_addr + v216 + 0x8000000000LL;
            v219 = v216 - kimage_voffset;
            if ( v217 )
              v220 = v219;
            else
              v220 = v218;
            _dma_sync_single_for_cpu(v215, v220);
          }
          __asm { PRFM            #0, [X20] }
        }
      }
LABEL_25:
      a3 = v238;
LABEL_26:
      v22 = v239;
      a2 = (unsigned int)(v29 + a2);
      v21 = *(unsigned int *)(v239 + 120);
      if ( v21 == *(_DWORD *)(v239 + 136) )
        goto LABEL_236;
      continue;
    }
    break;
  }
  a2 = v236;
  v222 = *(unsigned int *)(v237 + 2952);
  if ( (unsigned int)v222 >= 0x80 )
    goto LABEL_247;
  *(_DWORD *)(v237 + 4 * v222 + 1928) = v208;
  v223 = *(unsigned int *)(v237 + 2952);
  if ( (unsigned int)v223 > 0x7F )
    goto LABEL_247;
  *(_DWORD *)(v237 + 4 * v223 + 2440) = v252;
  *(_DWORD *)(v237 + 2952) = ((unsigned __int8)*(_DWORD *)(v237 + 2952) + 1) & 0x7F;
  qdf_trace_msg(
    0x85u,
    8u,
    "%s: %pK: ppdu_id %x != ppdu_info.com_info.ppdu_id %x",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "dp_rx_mon_dest_process",
    v3);
  a2 = v29 + v236;
LABEL_235:
  a3 = v238;
  v22 = v239;
LABEL_236:
  dp_srng_access_end(v235, v3, (char *)v22, v6, v7, v8, v9, v10, v11, v12, v13);
  v224 = *(_QWORD *)(v237 + 40);
  if ( (v224 & 1) != 0 )
  {
    *(_QWORD *)(v237 + 40) = v224 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(v237 + 32);
    if ( !(_DWORD)a2 )
      goto LABEL_246;
LABEL_238:
    ++*(_DWORD *)(v237 + 1904);
    v225 = *((_QWORD *)v240 + 1);
    v226 = v225 + 80LL * v243;
    v227 = *(_QWORD *)(v225 + 40);
    v228 = (__int64 *)(v225 + 80);
    v229 = (__int64 *)(v226 + 480);
    if ( *(_BYTE *)(v227 + 633) )
      v230 = v229;
    else
      v230 = v228;
    if ( (*(_BYTE *)(*(_QWORD *)(v3 + 40) + 633LL) & 1) != 0 )
    {
      v231 = 11408;
LABEL_245:
      result = _dp_rx_buffers_replenish(v3, a3, v230, v3 + v231 + 120LL * v15, a2, &v261, (__int64)&v260, 0, 0);
      goto LABEL_246;
    }
    v15 = v233;
    if ( v233 <= 4 )
    {
      v231 = 12368;
      goto LABEL_245;
    }
    goto LABEL_247;
  }
  result = raw_spin_unlock(v237 + 32);
  if ( (_DWORD)a2 )
    goto LABEL_238;
LABEL_246:
  _ReadStatusReg(SP_EL0);
  return result;
}
