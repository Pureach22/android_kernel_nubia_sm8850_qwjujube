__int64 __fastcall lim_roam_fill_bss_descr(__int64 a1, unsigned __int16 *a2, __int64 a3, __int64 a4)
{
  unsigned int v7; // w22
  __int64 v8; // x19
  unsigned int v9; // w25
  char is_mlo_link; // w27
  unsigned int entry_by_mac_addr; // w24
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned __int8 *v20; // x24
  unsigned __int16 v21; // w9
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x4
  __int64 v32; // x28
  int v33; // w9
  int v34; // w10
  int v35; // w11
  int v36; // w12
  __int64 v37; // x3
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x0
  int v63; // w10
  size_t v64; // x2
  char v65; // w9
  __int64 v66; // x8
  __int64 v67; // x0
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned int v76; // w25
  _DWORD *v77; // x22
  int v78; // w27
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  unsigned int v87; // w9
  _QWORD *v88; // x8
  unsigned int v89; // w25
  __int64 v90; // x26
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  const char *v100; // x2
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  _DWORD *v117; // x0
  unsigned int v118; // w28
  const void *v119; // x26
  unsigned int v120; // w26
  void *v121; // x0
  const void *v122; // x25
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  __int64 v131; // x4
  __int64 v132; // x5
  __int64 v133; // x6
  __int64 v134; // x7
  __int64 v135; // x4
  unsigned int v136; // w27
  __int64 v137; // x26
  unsigned int v138; // w25
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  __int64 v147; // x4
  const char *v148; // x2
  unsigned int v149; // w25
  _DWORD *v150; // x22
  double v151; // d0
  double v152; // d1
  double v153; // d2
  double v154; // d3
  double v155; // d4
  double v156; // d5
  double v157; // d6
  double v158; // d7
  unsigned int v159; // w25
  __int64 v160; // x28
  __int64 v161; // x27
  __int64 v162; // x0
  __int64 v163; // x0
  const char *v164; // x2
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  unsigned int chan_freq; // w0
  __int64 v175; // x1
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  int v192; // w9
  __int64 v193; // x0
  void *v194; // x0
  const void *v195; // x1
  double v196; // d0
  double v197; // d1
  double v198; // d2
  double v199; // d3
  double v200; // d4
  double v201; // d5
  double v202; // d6
  double v203; // d7
  __int64 v204; // [xsp+0h] [xbp-1E0h]
  __int64 v205; // [xsp+0h] [xbp-1E0h]
  __int64 v206; // [xsp+8h] [xbp-1D8h]
  __int64 v207; // [xsp+10h] [xbp-1D0h]
  const void *v208; // [xsp+28h] [xbp-1B8h]
  char v209; // [xsp+34h] [xbp-1ACh]
  __int64 v210; // [xsp+38h] [xbp-1A8h]
  unsigned int v211; // [xsp+44h] [xbp-19Ch]
  _QWORD *v212; // [xsp+48h] [xbp-198h]
  unsigned int v213; // [xsp+48h] [xbp-198h]
  unsigned int v214; // [xsp+50h] [xbp-190h]
  int v215; // [xsp+54h] [xbp-18Ch]
  __int64 v216; // [xsp+58h] [xbp-188h] BYREF
  __int64 v217; // [xsp+60h] [xbp-180h]
  __int64 v218; // [xsp+68h] [xbp-178h]
  __int64 v219; // [xsp+70h] [xbp-170h]
  __int64 v220; // [xsp+78h] [xbp-168h] BYREF
  unsigned __int8 *v221; // [xsp+80h] [xbp-160h]
  _QWORD *v222; // [xsp+88h] [xbp-158h] BYREF
  _QWORD *v223; // [xsp+90h] [xbp-150h] BYREF
  int v224; // [xsp+98h] [xbp-148h] BYREF
  unsigned __int16 v225; // [xsp+9Ch] [xbp-144h]
  _DWORD s[74]; // [xsp+A8h] [xbp-138h] BYREF
  __int64 v227; // [xsp+1D0h] [xbp-10h]

  v227 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(unsigned __int8 *)(a4 + 10);
  v8 = *a2;
  v9 = a2[1];
  v225 = 0;
  v224 = 0;
  v218 = 0;
  v219 = 0;
  v216 = 0;
  v217 = 0;
  v220 = 0;
  v221 = nullptr;
  if ( (is_multi_link_roam(a2) & 1) == 0 )
  {
    v21 = a2[9];
    is_mlo_link = 0;
    v20 = (unsigned __int8 *)a2 + v8;
    v224 = *(_DWORD *)(a2 + 7);
    v225 = v21;
LABEL_6:
    v22 = _qdf_mem_malloc(0x1A08u, "lim_roam_fill_bss_descr", 2407);
    if ( !v22 )
    {
      entry_by_mac_addr = 2;
LABEL_81:
      _qdf_mem_free((__int64)v221);
      _qdf_mem_free(v22);
      goto LABEL_82;
    }
    if ( v9 <= 0x18 )
    {
      if ( (is_mlo_link & 1) != 0 )
        v31 = "link";
      else
        v31 = (const char *)&unk_98C763;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: very few bytes in synchInd %s beacon / probe resp frame! length: %d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "lim_roam_fill_bss_descr",
        v31,
        v9);
      goto LABEL_80;
    }
    if ( (is_mlo_link & 1) != 0 )
      v32 = 2496;
    else
      v32 = 12;
    if ( v20 == (unsigned __int8 *)-16LL )
    {
      v35 = 0;
      v33 = 0;
      v34 = 0;
      v36 = 0;
    }
    else
    {
      v33 = v20[16];
      v34 = v20[17];
      v35 = v20[18];
      v36 = v20[21];
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: LFR3:Beacon/Prb Rsp: %d bssid %02x:%02x:%02x:**:**:%02x beacon %02x:%02x:%02x:**:**:%02x",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "lim_roam_fill_bss_descr",
      *((unsigned __int8 *)a2 + v32),
      (unsigned __int8)v224,
      BYTE1(v224),
      BYTE2(v224),
      HIBYTE(v225),
      v33,
      v34,
      v35,
      v36);
    mgmt_txrx_frame_hex_dump((__int64)v20, v9, 0, v37, v38, v39, v40, v41, v42, v43, v44, v45);
    if ( !(*((_DWORD *)v20 + 4) | *((unsigned __int16 *)v20 + 10)) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: bssid is 0 in beacon/probe update it with bssId%02x:%02x:%02x:**:**:%02xin sync ind",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "lim_roam_gen_beacon_descr",
        (unsigned __int8)v224,
        BYTE1(v224),
        BYTE2(v224),
        HIBYTE(v225));
      qdf_mem_copy(v20 + 16, &v224, 6u);
    }
    v215 = *((unsigned __int8 *)a2 + v32);
    if ( (is_multi_link_roam(a2) & 1) == 0 && (unsigned int)qdf_mem_cmp(&v224, v20 + 16, 6u) )
    {
      LODWORD(v204) = v20[21];
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: LFR3:MBSSID Beacon/Prb Rsp: %d bssid %02x:%02x:%02x:**:**:%02x",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "lim_roam_gen_beacon_descr",
        *((unsigned __int8 *)a2 + 12),
        v20[16],
        v20[17],
        v20[18],
        v204);
      memset(s, 0, sizeof(s));
      v62 = *(_QWORD *)(a1 + 21632);
      v63 = *((_DWORD *)a2 + 16);
      v64 = a2[1];
      v65 = *(_BYTE *)(v62 + 40);
      s[9] = *((char *)a2 + 60);
      v66 = *a2;
      v222 = nullptr;
      v223 = nullptr;
      LOBYTE(s[12]) = v65;
      s[0] = v63;
      s[3] = -1;
      v67 = util_scan_unpack_beacon_frame(v62, (_BYTE *)a2 + v66, v64, 0x80u, (__int64)s);
      if ( !v67 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: failed to parse",
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          "lim_roam_gen_mbssid_beacon");
LABEL_77:
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: failed to gen mbssid beacon",
          v109,
          v110,
          v111,
          v112,
          v113,
          v114,
          v115,
          v116,
          "lim_roam_gen_beacon_descr");
        goto LABEL_78;
      }
      v76 = *(_DWORD *)(v67 + 16);
      v211 = v7;
      v77 = (_DWORD *)v67;
      v78 = qdf_list_peek_front((_QWORD *)v67, &v222);
      v87 = (unsigned __int8)v76;
      v209 = v76;
      v214 = (unsigned __int8)v76;
      v210 = v32;
      if ( v78 || (v88 = v222) == nullptr )
      {
        v76 = (unsigned __int8)v76;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: list peek front failure. list size %d",
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          "lim_roam_gen_mbssid_beacon",
          (unsigned __int8)v76);
        v117 = v77;
        v7 = v211;
LABEL_47:
        v118 = 0;
        v119 = nullptr;
        if ( !v76 )
          goto LABEL_76;
        goto LABEL_63;
      }
      v212 = v77;
      v7 = v211;
      if ( (unsigned __int8)v76 < 2u )
        goto LABEL_62;
      v89 = 1;
      while ( 1 )
      {
        v90 = v88[3];
        if ( *(_DWORD *)(a2 + 7) == *(_DWORD *)(v90 + 1) && a2[9] == *(unsigned __int16 *)(v90 + 5) )
          break;
        v78 = qdf_list_peek_next(v212, v222, &v223);
        if ( v78 || (v88 = v223) == nullptr )
        {
          v135 = v89;
          v76 = v214;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: list remove failure i:%d, lsize:%d",
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            "lim_roam_gen_mbssid_beacon",
            v135,
            v214);
          v117 = v212;
          goto LABEL_47;
        }
        v87 = v214;
        ++v89;
        v222 = v223;
        if ( v214 == v89 )
          goto LABEL_62;
      }
      if ( v90 == -1 )
      {
        v133 = 0;
        v131 = 0;
        v132 = 0;
        v134 = 0;
      }
      else
      {
        v131 = *(unsigned __int8 *)(v90 + 1);
        v132 = *(unsigned __int8 *)(v90 + 2);
        v133 = *(unsigned __int8 *)(v90 + 3);
        v134 = *(unsigned __int8 *)(v90 + 6);
      }
      LODWORD(v206) = v214;
      LODWORD(v204) = *(_DWORD *)(v90 + 1888);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: matched BSSID %02x:%02x:%02x:**:**:%02x bcn len %d profiles %d",
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        "lim_roam_gen_mbssid_beacon",
        v131,
        v132,
        v133,
        v134,
        v204,
        v206);
      v136 = *(_DWORD *)(v90 + 1888);
      v137 = *(_QWORD *)(v90 + 1896);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 8, v137, v136);
      v87 = v214;
      if ( !v136 )
      {
LABEL_62:
        v149 = v87;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: failed to generate/find MBSSID beacon",
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          "lim_roam_gen_mbssid_beacon");
        v117 = v212;
        v118 = 0;
        v119 = nullptr;
        v78 = 0;
        if ( !v149 )
          goto LABEL_76;
LABEL_63:
        v208 = v119;
        v150 = v117;
        v213 = v118;
        v78 = qdf_list_remove_front(v117, &v223);
        v159 = 0;
        if ( !v78 )
        {
          v160 = (__int64)v223;
          if ( v223 )
          {
            v159 = 0;
            while ( 1 )
            {
              v161 = *(_QWORD *)(v160 + 24);
              if ( v161 )
              {
                v162 = *(_QWORD *)(v161 + 1320);
                if ( v162 )
                  _qdf_mem_free(v162);
                v163 = *(_QWORD *)(v161 + 1896);
                if ( v163 )
                  _qdf_mem_free(v163);
                _qdf_mem_free(v161);
              }
              _qdf_mem_free(v160);
              if ( (unsigned __int8)(v209 - 1) == v159 )
                break;
              ++v159;
              v78 = qdf_list_remove_front(v150, &v223);
              if ( !v78 )
              {
                v160 = (__int64)v223;
                if ( v223 )
                  continue;
              }
              goto LABEL_75;
            }
            _qdf_mem_free((__int64)v150);
            v32 = v210;
            v120 = v213;
            v7 = v211;
            v122 = v208;
            goto LABEL_84;
          }
        }
LABEL_75:
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: list remove failure i:%d, lsize:%d",
          v151,
          v152,
          v153,
          v154,
          v155,
          v156,
          v157,
          v158,
          "lim_roam_gen_mbssid_beacon",
          v159,
          v214);
        v118 = v213;
        v117 = v150;
        v7 = v211;
LABEL_76:
        _qdf_mem_free((__int64)v117);
        v122 = v119;
        v120 = v118;
        v32 = v210;
        if ( v78 )
          goto LABEL_77;
LABEL_84:
        if ( v215 )
        {
          LOWORD(s[0]) = 0;
          *(_DWORD *)v22 = *((_DWORD *)v20 + 6);
          *(_DWORD *)(v22 + 4) = *((_DWORD *)v20 + 7);
          *(_WORD *)(v22 + 8) = *((_WORD *)v20 + 16);
          dot11f_unpack_ff_capabilities(a1, v20 + 34, s);
          sir_copy_caps_info(a1, LOWORD(s[0]), v22);
        }
        *(_WORD *)a3 = v120 + 102;
        *(_BYTE *)(a3 + 48) = *((_BYTE *)a2 + v32) == 0;
        *(_BYTE *)(a3 + 24) = *((_BYTE *)a2 + 60);
        if ( (is_multi_link_roam(a2) & 1) != 0 )
        {
          chan_freq = mlo_roam_get_chan_freq(v7, a2);
        }
        else if ( (*(_BYTE *)(v22 + 2703) & 0x20) != 0 )
        {
          chan_freq = wlan_reg_chan_band_to_freq(
                        *(_QWORD *)(a1 + 21632),
                        *(unsigned __int8 *)(v22 + 2712),
                        4u,
                        v166,
                        v167,
                        v168,
                        v169,
                        v170,
                        v171,
                        v172,
                        v173);
        }
        else
        {
          if ( *(_BYTE *)(v22 + 2465) )
          {
            v175 = *(unsigned int *)(v22 + 72);
LABEL_93:
            *(_DWORD *)(a3 + 28) = v175;
            *(_DWORD *)(a3 + 20) = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))lim_get_nw_type)(
                                     a1,
                                     v175,
                                     0,
                                     v22);
            *(_WORD *)(a3 + 16) = *(_WORD *)(v22 + 8);
            *(_DWORD *)(a3 + 8) = *(_DWORD *)v22;
            *(_DWORD *)(a3 + 12) = *(_DWORD *)(v22 + 4);
            *(_WORD *)(a3 + 18) = *(_WORD *)(v22 + 10);
            qdf_mem_copy((void *)(a3 + 2), &v224, 6u);
            LODWORD(v204) = *(unsigned __int8 *)(a3 + 7);
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Non-tx bss desc: privacy bit: %d, bssid %02x:%02x:%02x:**:**:%02x",
              v176,
              v177,
              v178,
              v179,
              v180,
              v181,
              v182,
              v183,
              "lim_roam_fill_bss_descr",
              (*(unsigned __int16 *)(a3 + 18) >> 4) & 1,
              *(unsigned __int8 *)(a3 + 2),
              *(unsigned __int8 *)(a3 + 3),
              *(unsigned __int8 *)(a3 + 4),
              v204);
            if ( *(_BYTE *)(v22 + 2482) )
            {
              *(_BYTE *)(a3 + 44) = *(_BYTE *)(v22 + 2482);
              qdf_mem_copy((void *)(a3 + 45), (const void *)(v22 + 2446), 3u);
              v192 = *(unsigned __int16 *)(a3 + 45);
              v193 = *(_QWORD *)(a1 + 21624);
              LOBYTE(v217) = 1;
              LODWORD(v216) = v192;
              wlan_cm_roam_cfg_set_value(v193, v7, 0x14u, (unsigned int *)&v216);
            }
            LODWORD(v207) = *(unsigned __int8 *)(a3 + 47);
            LODWORD(v206) = *(unsigned __int8 *)(a3 + 46);
            LODWORD(v205) = *(unsigned __int8 *)(a3 + 45);
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: chan: %d rssi: %d ie_len %d mdie_present:%d mdie = %02x %02x %02x",
              v184,
              v185,
              v186,
              v187,
              v188,
              v189,
              v190,
              v191,
              "lim_roam_fill_bss_descr",
              *(unsigned int *)(a3 + 28),
              (unsigned int)*(char *)(a3 + 24),
              v120,
              *(unsigned __int8 *)(a3 + 44),
              v205,
              v206,
              v207);
            if ( v120 )
            {
              qdf_mem_copy((void *)(a3 + 104), v122, v120);
              _qdf_mem_free((__int64)v122);
              entry_by_mac_addr = 0;
              goto LABEL_81;
            }
            v164 = "%s: Beacon/Probe rsp doesn't have any IEs";
            goto LABEL_79;
          }
          if ( !*(_BYTE *)(v22 + 1260) )
          {
            v175 = *((unsigned int *)a2 + 16);
            goto LABEL_93;
          }
          chan_freq = wlan_reg_legacy_chan_to_freq(
                        *(_QWORD *)(a1 + 21632),
                        *(unsigned __int8 *)(v22 + 1261),
                        v166,
                        v167,
                        v168,
                        v169,
                        v170,
                        v171,
                        v172,
                        v173);
        }
        v175 = chan_freq;
        goto LABEL_93;
      }
      if ( *((_BYTE *)a2 + 12) )
      {
        v138 = v136 - 36;
        if ( (unsigned int)sir_parse_beacon_ie(a1, v22) || !*(_BYTE *)(v22 + 2460) )
        {
          v147 = a2[1];
          v148 = "%s: Parse error Beacon, length: %d";
LABEL_103:
          qdf_trace_msg(
            0x35u,
            2u,
            v148,
            v139,
            v140,
            v141,
            v142,
            v143,
            v144,
            v145,
            v146,
            "lim_roam_gen_mbssid_beacon",
            v147);
          v118 = 0;
          v119 = nullptr;
          v78 = 16;
          goto LABEL_104;
        }
      }
      else
      {
        if ( (unsigned int)sir_convert_probe_frame2_struct(a1, (int)v137 + 24, v136 - 24, v22)
          || !*(_BYTE *)(v22 + 2460) )
        {
          v147 = a2[1];
          v148 = "%s: Parse error ProbeResponse, length: %d";
          goto LABEL_103;
        }
        v138 = v136 - 36;
      }
      if ( v138 )
      {
        v194 = (void *)_qdf_mem_malloc(v138, "lim_roam_gen_mbssid_beacon", 2247);
        if ( !v194 )
          goto LABEL_77;
        v195 = (const void *)(v137 + 36);
        v119 = v194;
        qdf_mem_copy(v194, v195, v138);
        v118 = v138;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: beacon/probe Ie length: %d",
          v196,
          v197,
          v198,
          v199,
          v200,
          v201,
          v202,
          v203,
          "lim_roam_gen_mbssid_beacon",
          v138);
      }
      else
      {
        v118 = 0;
        v119 = nullptr;
      }
      v78 = 0;
LABEL_104:
      v117 = v212;
      if ( !v214 )
        goto LABEL_76;
      goto LABEL_63;
    }
    if ( v215 )
    {
      if ( (unsigned int)sir_parse_beacon_ie(a1, v22) || !*(_BYTE *)(v22 + 2460) )
      {
        v100 = "%s: Parse error Beacon, length: %d";
LABEL_42:
        qdf_trace_msg(0x35u, 2u, v100, v92, v93, v94, v95, v96, v97, v98, v99, "lim_roam_gen_beacon_descr", v9);
        goto LABEL_78;
      }
    }
    else if ( (unsigned int)sir_convert_probe_frame2_struct(a1, (int)v20 + 24, v9 - 24, v22) || !*(_BYTE *)(v22 + 2460) )
    {
      v100 = "%s: Parse error ProbeResponse, length: %d";
      goto LABEL_42;
    }
    if ( v9 < 0x25 )
    {
      v120 = 0;
      v122 = nullptr;
      goto LABEL_84;
    }
    v120 = v9 - 36;
    v121 = (void *)_qdf_mem_malloc(v9 - 36, "lim_roam_gen_beacon_descr", 2345);
    if ( v121 )
    {
      v122 = v121;
      qdf_mem_copy(v121, v20 + 36, v120);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: beacon/probe Ie length: %d",
        v123,
        v124,
        v125,
        v126,
        v127,
        v128,
        v129,
        v130,
        "lim_roam_gen_beacon_descr",
        v120);
      goto LABEL_84;
    }
LABEL_78:
    v164 = "%s: Failed to parse beacon";
LABEL_79:
    qdf_trace_msg(0x35u, 2u, v164, v101, v102, v103, v104, v105, v106, v107, v108, "lim_roam_fill_bss_descr");
LABEL_80:
    entry_by_mac_addr = 16;
    goto LABEL_81;
  }
  mlo_get_sta_link_mac_addr(v7, a2, &v224);
  is_mlo_link = wlan_vdev_mlme_get_is_mlo_link(*(_QWORD *)(a1 + 21624), v7);
  entry_by_mac_addr = wlan_scan_get_entry_by_mac_addr(*(_QWORD *)(a1 + 21632), &v224, (unsigned int *)&v220);
  if ( !entry_by_mac_addr && (_DWORD)v220 )
  {
    v20 = v221;
    v9 = (unsigned __int16)v220;
    goto LABEL_6;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Failed to get scan entry for %02x:%02x:%02x:**:**:%02x",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "lim_roam_fill_bss_descr",
    (unsigned __int8)v224,
    BYTE1(v224),
    BYTE2(v224),
    HIBYTE(v225));
LABEL_82:
  _ReadStatusReg(SP_EL0);
  return entry_by_mac_addr;
}
