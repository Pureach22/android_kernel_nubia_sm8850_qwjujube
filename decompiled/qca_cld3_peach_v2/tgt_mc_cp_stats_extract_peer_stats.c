__int64 __fastcall tgt_mc_cp_stats_extract_peer_stats(__int64 a1, __int64 a2, char a3)
{
  __int64 v5; // x28
  __int64 v6; // x1
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned __int64 v16; // x8
  __int64 v17; // x22
  unsigned __int64 v18; // x25
  __int64 v19; // x21
  _QWORD *peer_by_mac; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x26
  __int64 comp_private_obj; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x27
  unsigned int *v40; // x24
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w8
  unsigned int v50; // w9
  __int64 v51; // x3
  __int64 v52; // x4
  __int64 v53; // x5
  __int64 v54; // x6
  int v55; // w21
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x8
  int v65; // w15
  int v66; // w24
  __int64 v67; // x22
  unsigned __int64 v68; // x23
  unsigned __int64 v69; // x8
  __int64 v70; // x21
  _QWORD *v71; // x0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x25
  __int64 v81; // x0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x26
  __int64 v91; // x28
  int v92; // w9
  __int64 v93; // x8
  int v94; // w8
  __int64 v95; // x8
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  int v104; // w21
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  int v113; // w8
  unsigned __int64 v114; // x8
  __int64 v115; // x25
  unsigned __int64 v116; // x21
  __int64 v117; // x23
  _QWORD *v118; // x0
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  __int64 v127; // x26
  __int64 v128; // x0
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  __int64 v137; // x27
  __int64 v138; // x8
  __int64 v139; // x24
  int v140; // w8
  __int64 v141; // x8
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  double v150; // d0
  double v151; // d1
  double v152; // d2
  double v153; // d3
  double v154; // d4
  double v155; // d5
  double v156; // d6
  double v157; // d7
  int v158; // w23
  __int64 v159; // x8
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  void (__fastcall *v168)(__int64 *, __int64); // x22
  __int64 v169; // x0
  double v170; // d0
  double v171; // d1
  double v172; // d2
  double v173; // d3
  double v174; // d4
  double v175; // d5
  double v176; // d6
  double v177; // d7
  __int64 v178; // x20
  __int64 v179; // x19
  __int64 v180; // x21
  int v181; // w15
  __int64 v182; // x21
  __int64 v183; // x19
  __int64 v184; // x1
  unsigned int *v185; // x8
  double v186; // d0
  double v187; // d1
  double v188; // d2
  double v189; // d3
  double v190; // d4
  double v191; // d5
  double v192; // d6
  double v193; // d7
  _QWORD *peer; // x0
  double v195; // d0
  double v196; // d1
  double v197; // d2
  double v198; // d3
  double v199; // d4
  double v200; // d5
  double v201; // d6
  double v202; // d7
  __int64 v203; // x0
  double v204; // d0
  double v205; // d1
  double v206; // d2
  double v207; // d3
  double v208; // d4
  double v209; // d5
  double v210; // d6
  double v211; // d7
  __int64 v212; // x21
  unsigned __int64 v213; // x8
  _QWORD *v214; // x8
  _QWORD *v215; // x9
  __int64 v216; // x10
  __int64 v217; // x12
  __int64 v218; // x13
  __int64 v219; // x10
  __int64 v220; // x12
  __int64 v221; // x13
  __int64 v222; // x10
  __int64 v223; // x11
  __int64 *v224; // x8
  _QWORD *v225; // x9
  __int64 v226; // x10
  __int64 v227; // x11
  __int64 v228; // x8
  __int64 v229; // x12
  __int64 v230; // x8
  __int64 v231; // [xsp+0h] [xbp-150h]
  __int64 v232; // [xsp+8h] [xbp-148h]
  unsigned __int64 StatusReg; // [xsp+18h] [xbp-138h]
  unsigned __int64 v234; // [xsp+18h] [xbp-138h]
  int v235; // [xsp+20h] [xbp-130h]
  unsigned __int64 v236; // [xsp+20h] [xbp-130h]
  int v237; // [xsp+20h] [xbp-130h]
  __int64 v238; // [xsp+28h] [xbp-128h]
  char v239[4]; // [xsp+34h] [xbp-11Ch] BYREF
  __int64 v240; // [xsp+38h] [xbp-118h] BYREF
  void (__fastcall *v241)(__int64 *, __int64); // [xsp+40h] [xbp-110h]
  __int64 v242; // [xsp+48h] [xbp-108h]
  _QWORD v243[3]; // [xsp+50h] [xbp-100h] BYREF
  __int64 v244; // [xsp+68h] [xbp-E8h] BYREF
  __int64 v245; // [xsp+70h] [xbp-E0h]
  __int64 v246; // [xsp+78h] [xbp-D8h]
  __int64 v247; // [xsp+80h] [xbp-D0h] BYREF
  __int64 v248; // [xsp+88h] [xbp-C8h]
  __int64 v249; // [xsp+90h] [xbp-C0h]
  __int64 v250; // [xsp+98h] [xbp-B8h]
  __int64 v251; // [xsp+A0h] [xbp-B0h]
  __int64 v252; // [xsp+A8h] [xbp-A8h]
  __int64 v253; // [xsp+B0h] [xbp-A0h]
  __int64 v254; // [xsp+B8h] [xbp-98h]
  __int64 v255; // [xsp+C0h] [xbp-90h]
  __int64 v256; // [xsp+C8h] [xbp-88h]
  __int64 v257; // [xsp+D0h] [xbp-80h]
  __int64 v258; // [xsp+D8h] [xbp-78h]
  __int64 v259; // [xsp+E0h] [xbp-70h]
  __int64 v260; // [xsp+E8h] [xbp-68h]
  __int64 v261; // [xsp+F0h] [xbp-60h]
  __int64 v262; // [xsp+F8h] [xbp-58h]
  __int64 v263; // [xsp+100h] [xbp-50h]
  __int64 v264; // [xsp+108h] [xbp-48h]
  __int64 v265; // [xsp+110h] [xbp-40h]
  __int64 v266; // [xsp+118h] [xbp-38h]
  __int64 v267; // [xsp+120h] [xbp-30h]
  __int64 v268; // [xsp+128h] [xbp-28h]
  __int64 v269; // [xsp+130h] [xbp-20h]
  __int64 v270; // [xsp+138h] [xbp-18h]
  __int64 v271; // [xsp+140h] [xbp-10h]

  v5 = a1;
  v271 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a3 & 1) != 0 )
    v6 = 1;
  else
    v6 = 2;
  v242 = 0;
  memset(v243, 0, sizeof(v243));
  v240 = 0;
  v241 = nullptr;
  v239[0] = 0;
  result = ucfg_mc_cp_stats_get_pending_req(a1, v6, &v240);
  if ( (_DWORD)result )
  {
    result = qdf_trace_msg(
               0x62u,
               2u,
               "%s: ucfg_mc_cp_stats_get_pending_req failed",
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               "tgt_mc_cp_stats_extract_peer_stats");
    goto LABEL_90;
  }
  v238 = v5;
  if ( *(_QWORD *)(a2 + 40) )
  {
    LODWORD(v16) = *(_DWORD *)(a2 + 32);
    if ( (_DWORD)v16 )
    {
      v17 = 0;
      v18 = 0;
      v235 = *(_DWORD *)(a2 + 32);
      StatusReg = _ReadStatusReg(SP_EL0);
      do
      {
        v19 = *(_QWORD *)(a2 + 40);
        if ( v19 + v17 )
        {
          peer_by_mac = wlan_objmgr_get_peer_by_mac(v5, (_BYTE *)(v19 + v17 + 9), 0x26u);
          if ( peer_by_mac )
          {
            v29 = (__int64)peer_by_mac;
            comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0x1Bu);
            if ( comp_private_obj )
            {
              v39 = comp_private_obj;
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
                || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(comp_private_obj + 24);
              }
              else
              {
                raw_spin_lock_bh(comp_private_obj + 24);
                *(_QWORD *)(v39 + 32) |= 1uLL;
              }
              v40 = *(unsigned int **)(v39 + 8);
              qdf_mem_copy((char *)v40 + 9, (const void *)(v19 + v17 + 9), 6u);
              v49 = *(_DWORD *)(v19 + v17);
              if ( v49 )
                *v40 = v49;
              v50 = *(_DWORD *)(v19 + v17 + 4);
              if ( v50 )
                v40[1] = v50;
              if ( *(_BYTE *)(v19 + v17 + 8) )
                *((_BYTE *)v40 + 8) = *(_BYTE *)(v19 + v17 + 8);
              if ( v40 == (unsigned int *)-9LL )
              {
                v53 = 0;
                v51 = 0;
                v52 = 0;
                v54 = 0;
              }
              else
              {
                v51 = *((unsigned __int8 *)v40 + 9);
                v52 = *((unsigned __int8 *)v40 + 10);
                v53 = *((unsigned __int8 *)v40 + 11);
                v54 = *((unsigned __int8 *)v40 + 14);
              }
              LODWORD(v232) = *((char *)v40 + 8);
              LODWORD(v231) = v40[1];
              qdf_trace_msg(
                0x62u,
                8u,
                "PEER STATS: peer_mac=%02x:%02x:%02x:**:**:%02x, tx_rate=%u, rx_rate=%u, peer_rssi=%d",
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                v51,
                v52,
                v53,
                v54,
                *v40,
                v231,
                v232);
              v64 = *(_QWORD *)(v39 + 32);
              v5 = v238;
              if ( (v64 & 1) != 0 )
              {
                *(_QWORD *)(v39 + 32) = v64 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v39 + 24);
              }
              else
              {
                raw_spin_unlock(v39 + 24);
              }
              v55 = 0;
            }
            else
            {
              qdf_trace_msg(
                0x62u,
                2u,
                "%s: peer_cp_stats_priv is null",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "tgt_mc_cp_stats_update_peer_stats");
              v55 = 14;
            }
            result = wlan_objmgr_peer_release_ref(v29, 0x26u, v56, v57, v58, v59, v60, v61, v62, v63);
          }
          else
          {
            result = qdf_trace_msg(
                       0x62u,
                       8u,
                       "%s: peer is null",
                       v21,
                       v22,
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       "tgt_mc_cp_stats_update_peer_stats");
            v55 = 14;
          }
        }
        else
        {
          v55 = 14;
        }
        if ( LOBYTE(v243[0]) != 255
          || BYTE1(v243[0]) != 255
          || BYTE2(v243[0]) != 255
          || BYTE3(v243[0]) != 255
          || BYTE4(v243[0]) != 255
          || BYTE5(v243[0]) != 255 )
        {
          result = qdf_mem_cmp((const void *)(*(_QWORD *)(a2 + 40) + v17 + 9), v243, 6u);
          if ( !(_DWORD)result )
          {
            if ( v55 )
              goto LABEL_90;
            v235 = v18;
          }
        }
        v16 = *(unsigned int *)(a2 + 32);
        ++v18;
        v17 += 88;
      }
      while ( v18 < v16 );
      v65 = v235;
    }
    else
    {
      v65 = 0;
    }
    if ( (unsigned __int8)(v243[0] & BYTE1(v243[0]) & BYTE2(v243[0]) & BYTE3(v243[0]) & BYTE4(v243[0]) & BYTE5(v243[0])) != 0xFF
      && v65 == (_DWORD)v16 )
    {
      result = qdf_trace_msg(
                 0x62u,
                 8u,
                 "%s: peer not found for stats",
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 "tgt_mc_cp_stats_extract_peer_stats");
    }
  }
  if ( *(_QWORD *)(a2 + 56) )
  {
    v66 = *(_DWORD *)(a2 + 48);
    if ( v66 )
    {
      v67 = 0;
      v68 = 0;
      v236 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        v70 = *(_QWORD *)(a2 + 56);
        if ( v70 + v67 )
        {
          v71 = wlan_objmgr_get_peer_by_mac(v5, (_BYTE *)(v70 + v67), 0x26u);
          if ( v71 )
          {
            v80 = (__int64)v71;
            v81 = wlan_objmgr_peer_get_comp_private_obj((__int64)v71, 0x1Bu);
            if ( v81 )
            {
              v90 = v81;
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (*(_DWORD *)(v236 + 16) & 0xF0000) != 0
                || (*(_DWORD *)(v236 + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(v81 + 24);
              }
              else
              {
                raw_spin_lock_bh(v81 + 24);
                *(_QWORD *)(v90 + 32) |= 1uLL;
              }
              v91 = *(_QWORD *)(*(_QWORD *)(v90 + 8) + 24LL);
              qdf_mem_copy((void *)v91, (const void *)(v70 + v67), 6u);
              v92 = *(_DWORD *)(v70 + v67 + 8);
              if ( v92 )
                *(_DWORD *)(v91 + 8) = v92;
              v93 = *(_QWORD *)(v70 + v67 + 16);
              if ( v93 )
                *(_QWORD *)(v91 + 16) = v93;
              v94 = *(_DWORD *)(v70 + v67 + 12);
              if ( v94 )
                *(_DWORD *)(v91 + 12) = v94;
              v95 = *(_QWORD *)(v90 + 32);
              if ( (v95 & 1) != 0 )
              {
                *(_QWORD *)(v90 + 32) = v95 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v90 + 24);
              }
              else
              {
                raw_spin_unlock(v90 + 24);
              }
              v5 = v238;
              v104 = 0;
            }
            else
            {
              qdf_trace_msg(
                0x62u,
                2u,
                "%s: peer_cp_stats_priv is null",
                v82,
                v83,
                v84,
                v85,
                v86,
                v87,
                v88,
                v89,
                "tgt_mc_cp_stats_update_peer_adv_stats");
              v104 = 14;
            }
            result = wlan_objmgr_peer_release_ref(v80, 0x26u, v96, v97, v98, v99, v100, v101, v102, v103);
          }
          else
          {
            result = qdf_trace_msg(
                       0x62u,
                       8u,
                       "%s: peer is null",
                       v72,
                       v73,
                       v74,
                       v75,
                       v76,
                       v77,
                       v78,
                       v79,
                       "tgt_mc_cp_stats_update_peer_adv_stats");
            v104 = 14;
          }
        }
        else
        {
          v104 = 14;
        }
        if ( LOBYTE(v243[0]) != 255
          || BYTE1(v243[0]) != 255
          || BYTE2(v243[0]) != 255
          || BYTE3(v243[0]) != 255
          || BYTE4(v243[0]) != 255
          || BYTE5(v243[0]) != 255 )
        {
          result = qdf_mem_cmp((const void *)(*(_QWORD *)(a2 + 56) + v67), v243, 6u);
          if ( !(_DWORD)result )
          {
            if ( v104 )
              goto LABEL_90;
            v66 = v68;
          }
        }
        v69 = *(unsigned int *)(a2 + 48);
        ++v68;
        v67 += 24;
        if ( v68 >= v69 )
          goto LABEL_86;
      }
    }
    LODWORD(v69) = 0;
LABEL_86:
    if ( (unsigned __int8)(v243[0] & BYTE1(v243[0]) & BYTE2(v243[0]) & BYTE3(v243[0]) & BYTE4(v243[0]) & BYTE5(v243[0])) != 0xFF
      && v66 == (_DWORD)v69 )
    {
      result = qdf_trace_msg(
                 0x62u,
                 8u,
                 "%s: peer not found for extd stats",
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 "tgt_mc_cp_stats_extract_peer_stats");
    }
  }
  if ( (a3 & 1) == 0 )
  {
    v248 = 0;
    v249 = 0;
    v246 = 0;
    v247 = 0;
    v244 = 0;
    v245 = 0;
    result = ucfg_mc_cp_stats_get_pending_req(v5, 2, &v244);
    if ( (_DWORD)result )
    {
      result = qdf_trace_msg(
                 0x62u,
                 2u,
                 "%s: ucfg_mc_cp_stats_get_pending_req failed",
                 v105,
                 v106,
                 v107,
                 v108,
                 v109,
                 v110,
                 v111,
                 v112,
                 "tgt_mc_cp_stats_extract_peer_extd_stats");
      goto LABEL_93;
    }
    LODWORD(v114) = *(_DWORD *)(a2 + 64);
    if ( !(_DWORD)v114 )
    {
      v181 = 0;
LABEL_147:
      if ( (unsigned __int8)(v247 & BYTE1(v247) & BYTE2(v247) & BYTE3(v247) & BYTE4(v247) & BYTE5(v247)) != 0xFF
        && v181 == (_DWORD)v114 )
      {
        v182 = jiffies;
        if ( tgt_mc_cp_stats_extract_peer_extd_stats___last_ticks - jiffies + 125 < 0 )
        {
          result = qdf_trace_msg(
                     0x62u,
                     2u,
                     "%s: peer not found stats",
                     v105,
                     v106,
                     v107,
                     v108,
                     v109,
                     v110,
                     v111,
                     v112,
                     "tgt_mc_cp_stats_extract_peer_extd_stats");
          tgt_mc_cp_stats_extract_peer_extd_stats___last_ticks = v182;
        }
      }
LABEL_93:
      v113 = *(_DWORD *)(a2 + 148);
      if ( v113 < 0 )
      {
        if ( (v113 & 1) == 0 )
          goto LABEL_90;
      }
      else if ( !*(_QWORD *)(a2 + 40) )
      {
        goto LABEL_90;
      }
      qdf_trace_msg(
        0x62u,
        8u,
        "%s: Last stats event",
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        "tgt_mc_cp_stats_is_last_event");
      result = ucfg_mc_cp_stats_reset_pending_req(v5, 2, &v240, v239);
      if ( v239[0] != 1 )
        goto LABEL_90;
      v168 = v241;
      if ( !v241 )
        goto LABEL_90;
      v269 = 0;
      v270 = 0;
      v267 = 0;
      v268 = 0;
      v265 = 0;
      v266 = 0;
      v263 = 0;
      v264 = 0;
      v261 = 0;
      v262 = 0;
      v259 = 0;
      v260 = 0;
      v257 = 0;
      v258 = 0;
      v255 = 0;
      v256 = 0;
      v254 = 0;
      v252 = 0;
      v253 = 0;
      v250 = 0;
      v251 = 0;
      v248 = 0;
      v249 = 0;
      v246 = 0;
      v247 = 0;
      v244 = 0;
      v245 = 0;
      v169 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               v5,
               (unsigned int)v242,
               38);
      v178 = v169;
      if ( v169 )
      {
        if ( LOBYTE(v243[0]) != 255
          || BYTE1(v243[0]) != 255
          || BYTE2(v243[0]) != 255
          || BYTE3(v243[0]) != 255
          || BYTE4(v243[0]) != 255
          || BYTE5(v243[0]) != 255 )
        {
          peer = wlan_objmgr_get_peer(v5, BYTE4(v242), v243, 0x26u);
          v183 = (__int64)peer;
          if ( peer )
          {
            v203 = wlan_objmgr_peer_get_comp_private_obj((__int64)peer, 0x1Bu);
            if ( v203 )
            {
              v212 = v203;
              v249 = _qdf_mem_malloc(0x58u, "tgt_mc_cp_stats_prepare_raw_peer_rssi", 277);
              if ( v249 )
              {
                LODWORD(v248) = 1;
                v253 = _qdf_mem_malloc(0x20u, "tgt_mc_cp_stats_prepare_raw_peer_rssi", 284);
                if ( v253 )
                {
                  LODWORD(v252) = 1;
                  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                    || (v213 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v213 + 16) & 0xF0000) != 0)
                    || (*(_DWORD *)(v213 + 16) & 0xFF00) != 0 )
                  {
                    raw_spin_lock(v212 + 24);
                  }
                  else
                  {
                    raw_spin_lock_bh(v212 + 24);
                    *(_QWORD *)(v212 + 32) |= 1uLL;
                  }
                  v214 = *(_QWORD **)(v212 + 8);
                  v215 = (_QWORD *)v249;
                  v216 = v214[6];
                  v218 = v214[3];
                  v217 = v214[4];
                  *(_QWORD *)(v249 + 40) = v214[5];
                  v215[6] = v216;
                  v215[3] = v218;
                  v215[4] = v217;
                  v219 = v214[10];
                  v221 = v214[7];
                  v220 = v214[8];
                  v215[9] = v214[9];
                  v215[10] = v219;
                  v215[7] = v221;
                  v215[8] = v220;
                  v223 = v214[1];
                  v222 = v214[2];
                  *v215 = *v214;
                  v215[1] = v223;
                  v215[2] = v222;
                  v224 = (__int64 *)v214[2];
                  v225 = (_QWORD *)v253;
                  v227 = v224[2];
                  v226 = v224[3];
                  v229 = *v224;
                  v228 = v224[1];
                  *(_QWORD *)(v253 + 16) = v227;
                  v225[3] = v226;
                  *v225 = v229;
                  v225[1] = v228;
                  v230 = *(_QWORD *)(v212 + 32);
                  if ( (v230 & 1) != 0 )
                  {
                    *(_QWORD *)(v212 + 32) = v230 & 0xFFFFFFFFFFFFFFFELL;
                    raw_spin_unlock_bh(v212 + 24);
                  }
                  else
                  {
                    raw_spin_unlock(v212 + 24);
                  }
                }
              }
            }
            else
            {
              qdf_trace_msg(
                0x62u,
                2u,
                "%s: peer cp stats object is null",
                v204,
                v205,
                v206,
                v207,
                v208,
                v209,
                v210,
                v211,
                "tgt_mc_cp_stats_prepare_raw_peer_rssi");
            }
          }
          else
          {
            qdf_trace_msg(
              0x62u,
              8u,
              "%s: peer[%02x:%02x:%02x:**:**:%02x] is null",
              v195,
              v196,
              v197,
              v198,
              v199,
              v200,
              v201,
              v202,
              "tgt_mc_cp_stats_prepare_raw_peer_rssi",
              LOBYTE(v243[0]),
              BYTE1(v243[0]),
              BYTE2(v243[0]),
              BYTE5(v243[0]));
          }
          goto LABEL_153;
        }
        v179 = *(_QWORD *)(v169 + 216);
        v180 = *(unsigned __int16 *)(v179 + 72);
        v249 = _qdf_mem_malloc(88 * v180, "tgt_mc_cp_stats_prepare_raw_peer_rssi", 249);
        if ( v249 )
        {
          v253 = _qdf_mem_malloc(32 * v180, "tgt_mc_cp_stats_prepare_raw_peer_rssi", 255);
          if ( v253 )
            wlan_objmgr_pdev_iterate_obj_list(
              v179,
              3,
              (void (__fastcall *)(__int64, __int64, __int64))peer_rssi_iterator,
              (__int64)&v244,
              1,
              0x26u);
        }
      }
      else
      {
        qdf_trace_msg(
          0x62u,
          2u,
          "%s: vdev is null",
          v170,
          v171,
          v172,
          v173,
          v174,
          v175,
          v176,
          v177,
          "tgt_mc_cp_stats_prepare_raw_peer_rssi");
      }
      v183 = 0;
LABEL_153:
      v184 = v240;
      if ( *((_DWORD *)v168 - 1) != 488738581 )
        __break(0x8236u);
      v168(&v244, v184);
      result = ucfg_mc_cp_stats_free_stats_resources(&v244);
      if ( v178 )
        result = wlan_objmgr_vdev_release_ref(v178, 0x26u, v185, v186, v187, v188, v189, v190, v191, v192, v193);
      if ( v183 )
        result = wlan_objmgr_peer_release_ref(v183, 0x26u, v186, v187, v188, v189, v190, v191, v192, v193);
      goto LABEL_90;
    }
    v115 = 0;
    v116 = 0;
    v237 = *(_DWORD *)(a2 + 64);
    v234 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v117 = *(_QWORD *)(a2 + 72);
      if ( v117 + v115 )
      {
        v118 = wlan_objmgr_get_peer_by_mac(v238, (_BYTE *)(v117 + v115), 0x26u);
        if ( v118 )
        {
          v127 = (__int64)v118;
          v128 = wlan_objmgr_peer_get_comp_private_obj((__int64)v118, 0x1Bu);
          if ( v128 )
          {
            v137 = v128;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(v234 + 16) & 0xF0000) != 0
              || (*(_DWORD *)(v234 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v128 + 24);
            }
            else
            {
              raw_spin_lock_bh(v128 + 24);
              *(_QWORD *)(v137 + 32) |= 1uLL;
            }
            v138 = *(_QWORD *)(v137 + 8);
            v139 = *(_QWORD *)(v138 + 16);
            if ( v139 )
            {
              qdf_mem_copy(*(void **)(v138 + 16), (const void *)(v117 + v115), 6u);
              v140 = *(_DWORD *)(v117 + v115 + 28);
              if ( v140 )
                *(_DWORD *)(v139 + 28) = v140;
              v141 = *(_QWORD *)(v137 + 32);
              v5 = v238;
              if ( (v141 & 1) != 0 )
              {
                *(_QWORD *)(v137 + 32) = v141 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v137 + 24);
              }
              else
              {
                raw_spin_unlock(v137 + 24);
              }
              LODWORD(v231) = *(_DWORD *)(v117 + v115 + 28);
              qdf_trace_msg(
                0x62u,
                8u,
                "%s: peer_mac=%02x:%02x:%02x:**:**:%02x, rx_mc_bc_cnt=%u",
                v142,
                v143,
                v144,
                v145,
                v146,
                v147,
                v148,
                v149,
                "tgt_mc_cp_stats_update_peer_extd_stats",
                *(unsigned __int8 *)(v117 + v115),
                *(unsigned __int8 *)(v117 + v115 + 1),
                *(unsigned __int8 *)(v117 + v115 + 2),
                *(unsigned __int8 *)(v117 + v115 + 5),
                v231);
              v158 = 0;
            }
            else
            {
              v159 = *(_QWORD *)(v137 + 32);
              if ( (v159 & 1) != 0 )
              {
                *(_QWORD *)(v137 + 32) = v159 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v137 + 24);
              }
              else
              {
                raw_spin_unlock(v137 + 24);
              }
              v5 = v238;
              qdf_trace_msg(
                0x62u,
                2u,
                "%s: No peer_extd_mc_stats",
                v160,
                v161,
                v162,
                v163,
                v164,
                v165,
                v166,
                v167,
                "tgt_mc_cp_stats_update_peer_extd_stats");
              v158 = 4;
            }
          }
          else
          {
            qdf_trace_msg(
              0x62u,
              2u,
              "%s: peer_cp_stats_priv is null",
              v129,
              v130,
              v131,
              v132,
              v133,
              v134,
              v135,
              v136,
              "tgt_mc_cp_stats_update_peer_extd_stats");
            v5 = v238;
            v158 = 14;
          }
          result = wlan_objmgr_peer_release_ref(v127, 0x26u, v150, v151, v152, v153, v154, v155, v156, v157);
          goto LABEL_120;
        }
        result = qdf_trace_msg(
                   0x62u,
                   8u,
                   "%s: peer is null",
                   v119,
                   v120,
                   v121,
                   v122,
                   v123,
                   v124,
                   v125,
                   v126,
                   "tgt_mc_cp_stats_update_peer_extd_stats");
      }
      v5 = v238;
      v158 = 14;
LABEL_120:
      if ( (unsigned __int8)v247 != 255
        || BYTE1(v247) != 255
        || BYTE2(v247) != 255
        || BYTE3(v247) != 255
        || BYTE4(v247) != 255
        || BYTE5(v247) != 255 )
      {
        result = qdf_mem_cmp((const void *)(*(_QWORD *)(a2 + 72) + v115), &v247, 6u);
        if ( !(_DWORD)result )
        {
          if ( v158 )
            goto LABEL_93;
          v237 = v116;
        }
      }
      v114 = *(unsigned int *)(a2 + 64);
      ++v116;
      v115 += 32;
      if ( v116 >= v114 )
      {
        v181 = v237;
        goto LABEL_147;
      }
    }
  }
LABEL_90:
  _ReadStatusReg(SP_EL0);
  return result;
}
