__int64 __fastcall lim_sta_send_add_bss(__int64 a1, _BYTE *a2, __int64 a3, __int64 a4, unsigned __int8 a5, __int64 a6)
{
  __int64 v12; // x27
  void *v13; // x0
  __int64 v14; // x19
  _BYTE *v15; // x28
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  char v24; // w8
  int v25; // w8
  int v26; // w8
  char ht_capability; // w0
  int v28; // w8
  unsigned int v29; // w24
  int v30; // w8
  _BYTE *v31; // x27
  _BYTE *v32; // x23
  unsigned int vht_ch_width; // w0
  _BYTE *v34; // x1
  unsigned int v35; // w8
  unsigned int v36; // w9
  unsigned int v37; // w11
  unsigned int v38; // w8
  char is_he_dynamic_smps_enabled; // w0
  __int64 v40; // x10
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x27
  char v67; // w8
  int v68; // w8
  char v69; // w10
  char v70; // w8
  char v71; // w24
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned int v80; // w8
  int v81; // w8
  int v82; // w8
  int v83; // w9
  unsigned int v84; // w8
  char v85; // w8
  unsigned __int8 v86; // w22
  char v87; // w24
  char v88; // w8
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  int v97; // w8
  int v98; // w8
  bool v99; // zf
  unsigned int v100; // w8
  char v101; // w8
  char v102; // w8
  bool v103; // w8
  __int64 hash_entry; // x0
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  __int16 v113; // w2
  int v114; // w3
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  int v131; // w8
  unsigned int v132; // w8
  int v133; // w8
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  int v142; // w8
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  double v151; // d0
  double v152; // d1
  double v153; // d2
  double v154; // d3
  double v155; // d4
  double v156; // d5
  double v157; // d6
  double v158; // d7
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  int v167; // w8
  unsigned __int16 ielen_from_bss_description; // w0
  int v169; // w8
  __int64 v170; // x0
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  unsigned __int8 v180; // [xsp+3Ch] [xbp-54h]
  __int64 v181; // [xsp+40h] [xbp-50h]
  __int64 v182; // [xsp+40h] [xbp-50h]
  __int64 v183; // [xsp+58h] [xbp-38h] BYREF
  __int64 v184; // [xsp+60h] [xbp-30h]
  __int64 v185; // [xsp+68h] [xbp-28h]
  __int64 v186; // [xsp+70h] [xbp-20h]
  __int64 v187; // [xsp+78h] [xbp-18h]
  __int64 v188; // [xsp+80h] [xbp-10h]
  __int64 v189; // [xsp+88h] [xbp-8h]

  v189 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a1 + 8);
  v13 = (void *)_qdf_mem_malloc(0x138u, "lim_sta_send_add_bss", 3818);
  if ( v13 )
  {
    v14 = (__int64)v13;
    v15 = (_BYTE *)(a6 + 7024);
    qdf_mem_copy(v13, (const void *)(a4 + 2), 6u);
    v181 = v12;
    *(_WORD *)(v14 + 14) = *(_WORD *)(a4 + 16);
    v24 = *(_BYTE *)(a3 + 83);
    *(_BYTE *)(v14 + 292) = a5;
    *(_BYTE *)(v14 + 16) = v24;
    if ( *(_BYTE *)(a6 + 154) == 3 )
      v25 = 1;
    else
      v25 = *(_DWORD *)(a4 + 20);
    *(_DWORD *)(v14 + 8) = v25;
    *(_BYTE *)(v14 + 12) = (*(_WORD *)a2 & 0x400) != 0;
    *(_BYTE *)(v14 + 13) = *(_BYTE *)(a6 + 7162);
    v26 = *(unsigned __int8 *)(a6 + 154);
    if ( (unsigned int)(v26 - 7) >= 7 && v26 != 5 && *(_BYTE *)(a6 + 154) || !a2[244] )
    {
      *(_BYTE *)(a6 + 155) = 0;
      goto LABEL_28;
    }
    ht_capability = lim_get_ht_capability(a1, 12, a6);
    if ( a2[244] )
    {
      *(_BYTE *)(v14 + 17) = a2[244];
      if ( a2[304] )
      {
        if ( ht_capability && (*(_WORD *)(a2 + 245) & 2) != 0 )
          v28 = (*(_DWORD *)(a2 + 306) >> 2) & 1;
        else
          v28 = 0;
        *(_DWORD *)(v14 + 296) = v28;
      }
    }
    if ( ht_capability )
    {
      if ( a2[2296] )
      {
        v30 = *(_DWORD *)(a6 + 7176);
LABEL_27:
        *(_DWORD *)(v14 + 296) = v30;
        *(_DWORD *)(v14 + 44) = v30;
        goto LABEL_28;
      }
      if ( (*(_WORD *)(a2 + 245) & 2) != 0 || *(_BYTE *)(a3 + 1200) && (*(_WORD *)(a3 + 1201) & 2) != 0 )
      {
        v30 = 1;
        goto LABEL_27;
      }
    }
    *(_DWORD *)(v14 + 296) = 0;
    *(_DWORD *)(v14 + 44) = 0;
    if ( (*(_BYTE *)(v12 + 2652) & 1) == 0 )
      *(_BYTE *)(v14 + 140) = 0;
LABEL_28:
    if ( *(_BYTE *)(a6 + 7170) )
    {
      v31 = a2 + 2296;
      if ( a2[2296] )
      {
        *(_BYTE *)(v14 + 294) = a2[2296];
        v32 = a2 + 2296;
        if ( a2 != (_BYTE *)-2312LL )
          goto LABEL_31;
        goto LABEL_53;
      }
      if ( a2[2420] )
      {
        v32 = a2 + 2420;
        *(_BYTE *)(v14 + 294) = a2[2420];
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: VHT Caps and Operation are present in vendor Specific IE",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "lim_sta_send_add_bss");
        if ( !*(_BYTE *)(v14 + 294) )
          goto LABEL_55;
        if ( a2 != (_BYTE *)-2436LL )
        {
LABEL_31:
          vht_ch_width = *(_DWORD *)(v14 + 296);
          if ( *v31 )
          {
            v34 = a2 + 2312;
            if ( a2 == (_BYTE *)-2312LL )
            {
LABEL_50:
              v35 = *(_DWORD *)(a6 + 7176);
              if ( vht_ch_width < v35 )
                v35 = vht_ch_width;
              *(_DWORD *)(v14 + 296) = v35;
              *(_DWORD *)(v14 + 44) = v35;
              goto LABEL_53;
            }
          }
          else
          {
            if ( a2[2420] )
              v34 = a2 + 2436;
            else
              v34 = nullptr;
            if ( a2[2420] )
              v31 = a2 + 2420;
            else
              v31 = nullptr;
            if ( !v34 )
              goto LABEL_50;
          }
          if ( v31 && *(_DWORD *)(a6 + 7176) && v34[1] == 1 )
            vht_ch_width = lim_get_vht_ch_width(v31, v34, a2 + 304, a2 + 244, a2 + 2335);
          goto LABEL_50;
        }
LABEL_53:
        if ( v32 )
        {
          v36 = (unsigned __int8)v32[3];
          v37 = *((unsigned __int16 *)v32 + 2);
          v38 = *(unsigned __int16 *)(v32 + 1)
              | ((v36 & 7) << 16) & 0xFFC7FFFF
              | (((v36 >> 3) & 1) << 19) & 0xFFCFFFFF
              | (((v36 >> 4) & 1) << 20) & 0xFFDFFFFF
              | (((v36 >> 5) & 1) << 21)
              | (((v36 >> 6) & 1) << 22) & 0xFC7FFFFF
              | ((v37 & 7) << 23);
          *(_DWORD *)(v14 + 160) = v38
                                 | (v37 << 23) & 0xC0000000
                                 | (((v37 >> 6) & 1) << 29)
                                 | (((v37 >> 5) & 1) << 28)
                                 | (((v37 >> 3) & 3) << 26);
          *(_BYTE *)(v14 + 52) = v38 >> 23;
        }
LABEL_55:
        if ( *(_BYTE *)(a6 + 8676) == 1 && a2[2508] )
        {
          if ( *(_DWORD *)(a6 + 7036) != 2 )
          {
            is_he_dynamic_smps_enabled = lim_is_he_dynamic_smps_enabled(a6);
            v40 = 0x400000000000LL;
            if ( (is_he_dynamic_smps_enabled & 1) == 0 )
              v40 = 0;
            *(_QWORD *)(a2 + 2509) = *(_QWORD *)(a2 + 2509) & 0xFFFFBFFFFFFFFFFFLL | v40;
          }
          lim_add_bss_he_cap(v14, a2);
          lim_add_bss_he_cfg(v14, a6);
          if ( !a2[2742] )
            goto LABEL_62;
        }
        else
        {
          lim_reset_session_he_capable(a6);
          if ( !a2[2742] )
          {
LABEL_62:
            *(_WORD *)(v14 + 310) = 0;
            goto LABEL_65;
          }
        }
        *(_WORD *)(v14 + 310) = *((_WORD *)a2 + 1372);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: bss_max_idle_period %d",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "lim_sta_send_add_bss");
LABEL_65:
        *(_BYTE *)(v14 + 28) = 1;
        qdf_mem_copy((void *)(v14 + 20), (const void *)(a4 + 2), 6u);
        *(_WORD *)(v14 + 36) = *(_WORD *)(*(_QWORD *)(a1 + 8) + 3204LL);
        v57 = dph_lookup_hash_entry(
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                a1,
                (unsigned __int8 *)(v14 + 20),
                (_WORD *)(v14 + 26),
                a6 + 360);
        if ( !v57 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Couldn't get assoc id for MAC ADDR: %02x:%02x:%02x:**:**:%02x",
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            "lim_sta_send_add_bss",
            *(unsigned __int8 *)(v14 + 29),
            *(unsigned __int8 *)(v14 + 30),
            *(unsigned __int8 *)(v14 + 31),
            *(unsigned __int8 *)(v14 + 34));
          v29 = 16;
LABEL_236:
          _qdf_mem_free(v14);
          goto LABEL_237;
        }
        v66 = v57;
        *(_WORD *)(v14 + 26) = *(_WORD *)(a6 + 180);
        v67 = *(_BYTE *)(a6 + 7273);
        *(_BYTE *)(v14 + 40) = 0;
        *(_BYTE *)(v14 + 124) = a5;
        *(_BYTE *)(v14 + 39) = v67;
        v68 = *(unsigned __int8 *)(a6 + 154);
        if ( (unsigned int)(v68 - 7) >= 7 && v68 != 5 && *(_BYTE *)(a6 + 154) || !*(_BYTE *)(a3 + 1200) )
        {
LABEL_142:
          if ( *(_BYTE *)(a6 + 8764) == 1 && *(_BYTE *)(a6 + 8676) == 1 && a2[2508] )
          {
            lim_intersect_ap_he_caps(a6, v14, a3, a2, a4);
            if ( *(_BYTE *)(v14 + 172) == 1 && *(_BYTE *)(v14 + 260) )
              *(_BYTE *)(v14 + 260) = (*(_BYTE *)(v14 + 185) & 0x10) != 0;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: he_mcs_12_13_map %0x",
              v89,
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              v96,
              "lim_update_he_mcs_12_13",
              *(unsigned __int16 *)(v66 + 896));
            if ( *(_WORD *)(v66 + 896) )
              *(_WORD *)(v14 + 258) = *(_WORD *)(v66 + 896);
            lim_update_he_6gop_assoc_resp(v14, a2 + 2568, a6);
            if ( *(_DWORD *)(a6 + 7036) != 2 )
              *(_WORD *)(a2 + 2609) = *(_WORD *)(a2 + 2609) & 0xE7FF | (*(_WORD *)(a6 + 7266) << 9) & 0x1800;
            lim_update_he_6ghz_band_caps(a1, a2 + 2608, v14 + 20);
          }
          if ( *(_BYTE *)(a3 + 2740) )
          {
            LOBYTE(v97) = *(_DWORD *)(a3 + 2757) & 0xF;
            if ( (*(_DWORD *)(a3 + 2757) & 0xF) == 0 )
            {
              v97 = *(_DWORD *)(a3 + 2753) & 0xF;
              if ( !v97 )
                LOBYTE(v97) = 1;
            }
            goto LABEL_184;
          }
          if ( *(_BYTE *)(a3 + 2640) )
          {
            v98 = *(unsigned __int16 *)(a3 + 2662);
          }
          else
          {
            if ( !*(_BYTE *)(a3 + 2484) )
            {
              if ( !*(_BYTE *)(a3 + 1200) )
              {
                LOBYTE(v97) = 1;
                goto LABEL_184;
              }
              v100 = *(unsigned __int8 *)(a3 + 1216);
              if ( (~v100 & 3) == 0 )
              {
                v97 = (v100 >> 2) & 3;
                if ( v97 )
                {
LABEL_184:
                  *(_BYTE *)(v14 + 170) = v97;
                  *(_BYTE *)(v14 + 151) = *(_BYTE *)(a6 + 10);
                  v101 = *(_BYTE *)(a3 + 2474);
                  *(_BYTE *)(v14 + 152) = v101;
                  v102 = v101 | (2 * *(_BYTE *)(a3 + 2473));
                  *(_BYTE *)(v14 + 152) = v102;
                  if ( !v102 && *(_BYTE *)(a6 + 7364) == 1 )
                    *(_BYTE *)(v14 + 152) = 1;
                  qdf_mem_copy((void *)(v14 + 154), a2, 2u);
                  qdf_mem_copy((void *)(v14 + 156), a2 + 245, 2u);
                  v103 = (*v15 & 2) != 0 && a2[2287] || (*v15 & 1) != 0 && a2[2286];
                  *(_BYTE *)(v14 + 38) = v103;
                  hash_entry = dph_get_hash_entry(a1, 1u, a6 + 360);
                  if ( hash_entry )
                    qdf_mem_copy((void *)(v14 + 56), (const void *)(hash_entry + 264), 0x3Eu);
                  else
                    qdf_trace_msg(
                      0x35u,
                      2u,
                      "%s: could not Update the supported rates",
                      v105,
                      v106,
                      v107,
                      v108,
                      v109,
                      v110,
                      v111,
                      v112,
                      "lim_sta_send_add_bss");
                  *(_DWORD *)(v14 + 128) = *(_DWORD *)(a6 + 424);
                  *(_BYTE *)(v14 + 293) = *(_BYTE *)(a6 + 7032);
                  if ( *(_DWORD *)(a6 + 7036) == 2 )
                    *(_BYTE *)(v14 + 133) = 1;
                  if ( (*v15 & 0x10) != 0 )
                  {
                    *(_BYTE *)(v14 + 18) = 1;
                    *(_BYTE *)(v14 + 125) = 1;
                  }
                  v113 = *(_WORD *)(a6 + 8);
                  if ( *(_DWORD *)(a6 + 72) == 10 )
                    v114 = 18;
                  else
                    v114 = 19;
                  *(_DWORD *)(a6 + 72) = v114;
                  qdf_trace(53, 0, v113, v114);
                  if ( *(_BYTE *)(v14 + 148) )
                  {
                    if ( *(_BYTE *)(v14 + 149) )
                      goto LABEL_205;
                  }
                  else
                  {
                    *(_WORD *)(v14 + 156) &= ~1u;
                    if ( *(_BYTE *)(v14 + 149) )
                      goto LABEL_205;
                  }
                  *(_DWORD *)(v14 + 160) &= ~0x10u;
LABEL_205:
                  if ( *(_BYTE *)(a6 + 7864) == 1 )
                    *(_BYTE *)(v14 + 300) = 1;
                  if ( cds_is_5_mhz_enabled(v115, v116, v117, v118, v119, v120, v121, v122) )
                  {
                    v131 = 5;
                  }
                  else
                  {
                    if ( !cds_is_10_mhz_enabled(v123, v124, v125, v126, v127, v128, v129, v130) )
                    {
LABEL_212:
                      if ( *(_BYTE *)(a6 + 7170) && a2[2296] || *(_BYTE *)(a6 + 8676) == 1 && a2[2508] )
                        v132 = 3;
                      else
                        v132 = 1;
                      if ( *(_DWORD *)(v14 + 296) > v132 )
                      {
                        *(_DWORD *)(v14 + 296) = v132;
                        *(_DWORD *)(v14 + 44) = v132;
                      }
                      *(_BYTE *)(v14 + 261) = *(_BYTE *)(a6 + 10045);
                      *(_BYTE *)(v14 + 262) = *(_BYTE *)(a6 + 10046);
                      v133 = **(unsigned __int8 **)(a6 + 9976);
                      if ( v133 == 1 )
                      {
                        *(_BYTE *)(v14 + 308) = 1;
                        v133 = **(unsigned __int8 **)(a6 + 9976);
                      }
                      qdf_trace_msg(
                        0x35u,
                        8u,
                        "%s: update %d MxAmpduDen %d mimoPS %d vht_mcs11 %d shortSlot %d BI %d DTIM %d enc type %d p2p ca"
                        "b STA %d is_fils:%d",
                        v123,
                        v124,
                        v125,
                        v126,
                        v127,
                        v128,
                        v129,
                        v130,
                        "lim_sta_send_add_bss",
                        a5,
                        *(unsigned __int8 *)(v14 + 53),
                        *(unsigned int *)(v14 + 48),
                        *(unsigned __int8 *)(v14 + 150),
                        *(unsigned __int8 *)(v14 + 12),
                        *(unsigned __int16 *)(v14 + 14),
                        *(unsigned __int8 *)(v14 + 16),
                        *(_DWORD *)(v14 + 128),
                        *(unsigned __int8 *)(v14 + 133),
                        v133);
                      *(_BYTE *)(a1 + 8885) = 0;
                      *(_QWORD *)(a1 + 8888) = "lim_sta_send_add_bss";
                      qdf_trace_msg(
                        0x35u,
                        8u,
                        "%s: Defer LIM msg %d",
                        v134,
                        v135,
                        v136,
                        v137,
                        v138,
                        v139,
                        v140,
                        v141,
                        "lim_sta_send_add_bss",
                        0);
                      v142 = *(unsigned __int8 *)(a1 + 8885);
                      v187 = 0;
                      v188 = 0;
                      v185 = 0;
                      v186 = 0;
                      v183 = 0;
                      v184 = 0;
                      if ( v142 )
                      {
                        if ( *(_WORD *)(a1 + 8688) )
                        {
                          LOWORD(v183) = 5119;
                          if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)&v183) )
                            qdf_trace_msg(
                              0x35u,
                              2u,
                              "%s: Failed to post lim msg:0x%x",
                              v143,
                              v144,
                              v145,
                              v146,
                              v147,
                              v148,
                              v149,
                              v150,
                              "lim_post_msg_to_process_deferred_queue",
                              (unsigned __int16)v183);
                        }
                      }
                      v29 = wma_send_peer_assoc_req(v14);
                      if ( v29 )
                      {
                        *(_BYTE *)(a1 + 8885) = 1;
                        *(_QWORD *)(a1 + 8888) = "lim_sta_send_add_bss";
                        qdf_trace_msg(
                          0x35u,
                          8u,
                          "%s: Defer LIM msg %d",
                          v151,
                          v152,
                          v153,
                          v154,
                          v155,
                          v156,
                          v157,
                          v158,
                          "lim_sta_send_add_bss",
                          1);
                        v167 = *(unsigned __int8 *)(a1 + 8885);
                        v187 = 0;
                        v188 = 0;
                        v185 = 0;
                        v186 = 0;
                        v183 = 0;
                        v184 = 0;
                        if ( v167 )
                        {
                          if ( *(_WORD *)(a1 + 8688) )
                          {
                            LOWORD(v183) = 5119;
                            if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)&v183) )
                              qdf_trace_msg(
                                0x35u,
                                2u,
                                "%s: Failed to post lim msg:0x%x",
                                v159,
                                v160,
                                v161,
                                v162,
                                v163,
                                v164,
                                v165,
                                v166,
                                "lim_post_msg_to_process_deferred_queue",
                                (unsigned __int16)v183);
                          }
                        }
                        qdf_trace_msg(
                          0x35u,
                          2u,
                          "%s: wma_send_peer_assoc_req failed=%X",
                          v159,
                          v160,
                          v161,
                          v162,
                          v163,
                          v164,
                          v165,
                          v166,
                          "lim_sta_send_add_bss",
                          v29);
                      }
                      else
                      {
                        v185 = 0;
                        v186 = 0;
                        v184 = 0;
                        ielen_from_bss_description = wlan_get_ielen_from_bss_description(a4);
                        v183 = a4 + 104;
                        v169 = ielen_from_bss_description;
                        v170 = *(_QWORD *)(a1 + 21552);
                        LODWORD(v184) = v169;
                        if ( (wlan_action_oui_search(v170, &v183, 24) & 1) != 0 )
                        {
                          qdf_trace_msg(
                            0x35u,
                            8u,
                            "%s: Limit vdev %d bw to 40M for IoT AP",
                            v171,
                            v172,
                            v173,
                            v174,
                            v175,
                            v176,
                            v177,
                            v178,
                            "lim_limit_bw_for_iot_ap",
                            *(unsigned __int8 *)(a6 + 10));
                          wma_set_vdev_bw(*(unsigned __int8 *)(a6 + 10), 1);
                        }
                      }
                      goto LABEL_236;
                    }
                    v131 = 6;
                  }
                  *(_DWORD *)(v14 + 296) = v131;
                  *(_DWORD *)(v14 + 44) = v131;
                  goto LABEL_212;
                }
              }
              if ( !*(_BYTE *)(a3 + 1207) )
              {
                if ( !*(_BYTE *)(a3 + 1206) )
                {
                  v99 = *(_BYTE *)(a3 + 1205) == 0;
LABEL_181:
                  if ( v99 )
                    LOBYTE(v97) = 1;
                  else
                    LOBYTE(v97) = 2;
                  goto LABEL_184;
                }
LABEL_179:
                LOBYTE(v97) = 3;
                goto LABEL_184;
              }
LABEL_174:
              LOBYTE(v97) = 4;
              goto LABEL_184;
            }
            v98 = *(unsigned __int16 *)(a3 + 2494);
          }
          if ( (~v98 & 0xC000) != 0 )
          {
            LOBYTE(v97) = 8;
            goto LABEL_184;
          }
          if ( (~v98 & 0x3000) != 0 )
          {
            LOBYTE(v97) = 7;
            goto LABEL_184;
          }
          if ( (~v98 & 0xC00) != 0 )
          {
            LOBYTE(v97) = 6;
            goto LABEL_184;
          }
          if ( (~v98 & 0x300) != 0 )
          {
            LOBYTE(v97) = 5;
            goto LABEL_184;
          }
          if ( (~v98 & 0xC0) == 0 )
          {
            if ( (~v98 & 0x30) == 0 )
            {
              v99 = (~v98 & 0xC) == 0;
              goto LABEL_181;
            }
            goto LABEL_179;
          }
          goto LABEL_174;
        }
        *(_BYTE *)(v14 + 41) = 1;
        if ( (*(_WORD *)(a6 + 7266) & 0x80) != 0 )
          *(_BYTE *)(v14 + 260) = a2[246] & 3;
        if ( !*(_BYTE *)(a6 + 7170)
          || (!*(_BYTE *)(a3 + 2484) || *(__int16 *)(a3 + 2490) == -1 || *(__int16 *)(a3 + 2494) == -1)
          && (!*(_BYTE *)(a3 + 2544) || *(__int16 *)(a3 + 2550) == -1 || *(__int16 *)(a3 + 2554) == -1) )
        {
          v69 = 0;
        }
        else
        {
          *(_BYTE *)(v14 + 135) = 1;
          *(_BYTE *)(v14 + 150) = *(_BYTE *)(v57 + 355);
          *(_BYTE *)(v14 + 136) = *(_BYTE *)(v57 + 352);
          if ( a2[2296] )
          {
            v69 = 0;
            v32 = a2 + 2296;
          }
          else if ( a2[2420] )
          {
            v32 = a2 + 2420;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: VHT Caps are in vendor Specific IE",
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              "lim_sta_send_add_bss");
            v69 = 1;
          }
          else
          {
            v69 = 0;
          }
          if ( v32 )
          {
            if ( ((*(_WORD *)(v32 + 1) & 0x800) != 0 || (v32[3] & 8) != 0) && (*(_BYTE *)(a6 + 7269) & 0x10) != 0 )
              *(_BYTE *)(v14 + 140) = 1;
            if ( (v32[3] & 8) != 0 && (*(_BYTE *)(a6 + 7270) & 0x10) != 0 )
              *(_BYTE *)(v14 + 142) = 1;
            if ( (*(_WORD *)(v32 + 1) & 0x1000) != 0 && (*(_BYTE *)(a6 + 7269) & 8) != 0 )
              *(_BYTE *)(v14 + 141) = 1;
            if ( *(_BYTE *)(v14 + 260) )
              *(_BYTE *)(v14 + 260) = v32[2] & 7;
          }
          if ( (unsigned int)(*(_DWORD *)(a6 + 7176) - 3) > 1 )
          {
            v70 = 0;
            *(_WORD *)(v14 + 137) = 0;
          }
          else
          {
            *(_BYTE *)(v14 + 137) = *(_BYTE *)(v66 + 356);
            *(_BYTE *)(v14 + 138) = *(_BYTE *)(v66 + 357);
            v70 = *(_BYTE *)(v66 + 358);
          }
          *(_BYTE *)(v14 + 139) = v70;
        }
        if ( *(_BYTE *)(a6 + 8676) == 1 && a2[2508] )
        {
          v180 = a5;
          v71 = v69;
          lim_intersect_ap_he_caps(a6, v14, a3, a2, a4);
          if ( *(_BYTE *)(v14 + 172) == 1 && *(_BYTE *)(v14 + 260) )
            *(_BYTE *)(v14 + 260) = (*(_BYTE *)(v14 + 185) & 0x10) != 0;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: he_mcs_12_13_map %0x",
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            "lim_update_he_mcs_12_13",
            *(unsigned __int16 *)(v66 + 896));
          v69 = v71;
          a5 = v180;
          if ( *(_WORD *)(v66 + 896) )
            *(_WORD *)(v14 + 258) = *(_WORD *)(v66 + 896);
        }
        if ( *(_DWORD *)(a6 + 7036) == 2 )
        {
          v80 = *(unsigned __int16 *)(a2 + 245);
        }
        else
        {
          v80 = *(_WORD *)(a2 + 245) & 0xFFF3 | (4 * ((*(unsigned __int16 *)(a6 + 7266) >> 2) & 3));
          *(_WORD *)(a2 + 245) = *(_WORD *)(a2 + 245) & 0xFFF3 | (4 * ((*(unsigned __int16 *)(a6 + 7266) >> 2) & 3));
        }
        *(_DWORD *)(v14 + 48) = (v80 >> 2) & 3;
        *(_BYTE *)(v14 + 53) = (a2[247] >> 2) & 7;
        if ( (*(_WORD *)(a6 + 7266) & 0x20) != 0 )
          v81 = ((unsigned __int8)a2[245] >> 5) & 1;
        else
          LOBYTE(v81) = 0;
        *(_BYTE *)(v14 + 55) = v81;
        if ( (*(_WORD *)(a6 + 7266) & 0x40) != 0 )
          v82 = ((unsigned __int8)a2[245] >> 6) & 1;
        else
          LOBYTE(v82) = 0;
        v83 = *(unsigned __int8 *)(v14 + 135);
        *(_BYTE *)(v14 + 54) = v82;
        if ( v83 )
        {
          v84 = a2[247] & 3;
          if ( *(unsigned __int8 *)(v14 + 52) >= v84 )
          {
            if ( !*(_BYTE *)(v14 + 140) )
              goto LABEL_128;
            goto LABEL_126;
          }
        }
        else
        {
          LOBYTE(v84) = a2[247] & 3;
        }
        *(_BYTE *)(v14 + 52) = v84;
        if ( !*(_BYTE *)(v14 + 140) )
        {
LABEL_128:
          if ( (*(_BYTE *)(a6 + 7236) & 1) != 0 )
            v85 = a2[245] & 1;
          else
            v85 = 0;
          *(_BYTE *)(v14 + 148) = v85;
          if ( a2[2296] )
          {
            v32 = a2 + 2296;
          }
          else if ( a2[2420] )
          {
            v32 = a2 + 2420;
            v182 = a4;
            v86 = a5;
            v87 = v69;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: VHT Caps is in vendor Specific IE",
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              "lim_sta_send_add_bss");
            v69 = v87;
            a5 = v86;
            a4 = v182;
          }
          if ( v32 && (*(_BYTE *)(a6 + 7236) & 2) != 0 )
          {
            if ( (v69 & 1) != 0 )
              v88 = v32[1];
            else
              v88 = a2[2297];
            *(_BYTE *)(v14 + 149) = (v88 & 0x10) != 0;
          }
          else
          {
            *(_BYTE *)(v14 + 149) = 0;
          }
          goto LABEL_142;
        }
LABEL_126:
        if ( *(_BYTE *)(v181 + 2679) == 1 )
        {
          *(_WORD *)(v14 + 148) = 0;
          goto LABEL_142;
        }
        goto LABEL_128;
      }
    }
    v32 = nullptr;
    *(_BYTE *)(v14 + 294) = 0;
    *(_BYTE *)(a6 + 7170) = 0;
    goto LABEL_55;
  }
  v29 = 2;
LABEL_237:
  _ReadStatusReg(SP_EL0);
  return v29;
}
