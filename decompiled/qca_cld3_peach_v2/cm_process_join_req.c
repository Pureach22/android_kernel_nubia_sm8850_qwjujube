__int64 __fastcall cm_process_join_req(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w21
  _QWORD *v20; // x21
  _QWORD *v21; // x0
  __int64 v22; // x20
  __int64 v23; // x8
  __int64 session_by_bssid; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned __int8 *v33; // x11
  int v34; // w8
  int v35; // w9
  int v36; // w10
  int v37; // w11
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x22
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x3
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  _WORD *v60; // x23
  __int64 v61; // x0
  unsigned __int8 *v62; // x9
  __int64 v63; // x6
  __int64 v64; // x7
  int v65; // w8
  int v66; // w9
  bool *v67; // x25
  __int64 param; // x0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x8
  size_t v78; // x2
  __int64 v79; // x8
  unsigned int v80; // t1
  __int64 v81; // x12
  __int64 v82; // x9
  __int64 v83; // x11
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  int v92; // w8
  _DWORD *v93; // x24
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  unsigned int v102; // w26
  int v103; // w27
  int v104; // w3
  int v105; // w9
  unsigned int v106; // w8
  char v107; // w10
  bool v108; // w12
  int v109; // w8
  int v110; // w8
  __int64 v111; // x0
  int v112; // w26
  int v113; // w0
  __int64 v114; // x0
  unsigned __int8 *v115; // x26
  int v116; // w0
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  unsigned int v125; // w8
  __int64 v126; // x4
  int v127; // w26
  int v128; // w0
  __int64 v129; // x0
  void *v130; // x0
  int v131; // w26
  int v132; // w0
  __int64 v133; // x0
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  unsigned __int8 v142; // w9
  size_t v143; // x2
  void *v144; // x0
  unsigned __int8 *v145; // x1
  __int64 v146; // x28
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  double v155; // d0
  double v156; // d1
  double v157; // d2
  double v158; // d3
  double v159; // d4
  double v160; // d5
  double v161; // d6
  double v162; // d7
  __int64 v163; // x27
  __int64 v164; // x8
  __int64 peer_pmksa; // x0
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  unsigned __int8 *v174; // x27
  char *v175; // x0
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  int v184; // w0
  int v185; // w26
  unsigned __int8 *v186; // x1
  int v187; // w2
  unsigned __int8 *ie_ptr_from_eid; // x0
  double v189; // d0
  double v190; // d1
  double v191; // d2
  double v192; // d3
  double v193; // d4
  double v194; // d5
  double v195; // d6
  double v196; // d7
  unsigned __int8 *v197; // x27
  unsigned __int8 *v198; // x0
  double v199; // d0
  double v200; // d1
  double v201; // d2
  double v202; // d3
  double v203; // d4
  double v204; // d5
  double v205; // d6
  double v206; // d7
  char *v207; // x0
  double v208; // d0
  double v209; // d1
  double v210; // d2
  double v211; // d3
  double v212; // d4
  double v213; // d5
  double v214; // d6
  double v215; // d7
  unsigned __int8 v216; // w8
  unsigned int v217; // w9
  __int64 v218; // x0
  char v219; // w28
  __int64 v220; // x27
  unsigned int rsnxe_len_by_gen; // w8
  __int64 v222; // x0
  double v223; // d0
  double v224; // d1
  double v225; // d2
  double v226; // d3
  double v227; // d4
  double v228; // d5
  double v229; // d6
  double v230; // d7
  _BYTE *v231; // x27
  double v232; // d0
  double v233; // d1
  double v234; // d2
  double v235; // d3
  double v236; // d4
  double v237; // d5
  double v238; // d6
  double v239; // d7
  const char *v240; // x2
  unsigned int v241; // w0
  double v242; // d0
  double v243; // d1
  double v244; // d2
  double v245; // d3
  double v246; // d4
  double v247; // d5
  double v248; // d6
  double v249; // d7
  __int64 ext_hdl; // x0
  double v251; // d0
  double v252; // d1
  double v253; // d2
  double v254; // d3
  double v255; // d4
  double v256; // d5
  double v257; // d6
  double v258; // d7
  __int64 v259; // x8
  size_t v260; // x2
  __int64 v261; // x25
  __int64 v262; // x8
  __int64 v263; // x0
  __int64 v264; // x26
  int appended; // w28
  double v266; // d0
  double v267; // d1
  double v268; // d2
  double v269; // d3
  double v270; // d4
  double v271; // d5
  double v272; // d6
  double v273; // d7
  int v274; // w8
  double v275; // d0
  double v276; // d1
  double v277; // d2
  double v278; // d3
  double v279; // d4
  double v280; // d5
  double v281; // d6
  double v282; // d7
  size_t v283; // x2
  double v284; // d0
  double v285; // d1
  double v286; // d2
  double v287; // d3
  double v288; // d4
  double v289; // d5
  double v290; // d6
  double v291; // d7
  __int64 v292; // x0
  __int64 v293; // x24
  __int64 v294; // x8
  unsigned int v295; // w26
  bool *v296; // x28
  void *v297; // x25
  unsigned int v298; // w26
  __int64 v299; // x8
  __int64 v300; // x8
  double v301; // d0
  double v302; // d1
  double v303; // d2
  double v304; // d3
  double v305; // d4
  double v306; // d5
  double v307; // d6
  double v308; // d7
  const char *v309; // x2
  double v310; // d0
  double v311; // d1
  double v312; // d2
  double v313; // d3
  double v314; // d4
  double v315; // d5
  double v316; // d6
  double v317; // d7
  __int64 v318; // x1
  void *v319; // x0
  size_t v320; // x2
  __int64 v321; // x0
  double v322; // d0
  double v323; // d1
  double v324; // d2
  double v325; // d3
  double v326; // d4
  double v327; // d5
  double v328; // d6
  double v329; // d7
  __int64 v330; // x23
  double v331; // d0
  double v332; // d1
  double v333; // d2
  double v334; // d3
  double v335; // d4
  double v336; // d5
  double v337; // d6
  double v338; // d7
  double v339; // d0
  double v340; // d1
  double v341; // d2
  double v342; // d3
  double v343; // d4
  double v344; // d5
  double v345; // d6
  double v346; // d7
  unsigned int v347; // [xsp+30h] [xbp-C0h]
  unsigned int v348; // [xsp+3Ch] [xbp-B4h]
  int v349; // [xsp+40h] [xbp-B0h] BYREF
  bool v350; // [xsp+44h] [xbp-ACh] BYREF
  _QWORD v351[10]; // [xsp+48h] [xbp-A8h] BYREF
  __int64 v352; // [xsp+98h] [xbp-58h]
  _QWORD v353[4]; // [xsp+A0h] [xbp-50h] BYREF
  _QWORD v354[6]; // [xsp+C0h] [xbp-30h] BYREF

  v354[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(54, (__int64)"lim_cm_handle_join_req", a2, a3, a4, a5, a6, a7, a8, a9);
  v19 = 4;
  if ( !a1 || !context )
    goto LABEL_13;
  v20 = context;
  v21 = _cds_get_context(53, (__int64)"lim_cm_handle_join_req", v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !v21 )
  {
    v19 = 4;
LABEL_13:
    cm_free_join_req((__int64)a1);
    goto LABEL_14;
  }
  v22 = (__int64)v21;
  lim_diag_event_report(v21, 3, 0, 0);
  v23 = *((_QWORD *)a1 + 6);
  LOBYTE(v351[0]) = 0;
  session_by_bssid = pe_find_session_by_bssid(v22, v23 + 1, v351);
  if ( session_by_bssid || (session_by_bssid = pe_find_session_by_vdev_id(v22, *a1)) != 0 )
  {
    v33 = *((unsigned __int8 **)a1 + 6);
    if ( v33 == (unsigned __int8 *)-1LL )
    {
      v36 = 0;
      v34 = 0;
      v35 = 0;
      v37 = 0;
    }
    else
    {
      v34 = v33[1];
      v35 = v33[2];
      v36 = v33[3];
      v37 = v33[6];
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: vdev_id: %d cm_id 0x%x :pe-session(%d (vdev %d)) already exists for BSSID: %02x:%02x:%02x:**:**:%02x in lim_sme_state = %X",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "lim_cm_create_session",
      *a1,
      *((unsigned int *)a1 + 1),
      *(unsigned __int16 *)(session_by_bssid + 8),
      *(unsigned __int8 *)(session_by_bssid + 10),
      v34,
      v35,
      v36,
      v37,
      *(_DWORD *)(session_by_bssid + 80));
    _qdf_trigger_self_recovery();
    goto LABEL_11;
  }
  v39 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, _QWORD, _QWORD, _QWORD))pe_create_session)(
          v22,
          *((_QWORD *)a1 + 6) + 1LL,
          v351,
          *(unsigned __int8 *)(v22 + 12272),
          0,
          *a1);
  if ( v39 )
  {
    v48 = v39;
    *(_DWORD *)(v39 + 4) = *((_DWORD *)a1 + 1);
    v49 = *((_QWORD *)a1 + 6);
    v350 = 0;
    v349 = 1;
    v50 = _qdf_mem_malloc((unsigned __int16)(*(_WORD *)(v49 + 1888) + 68) + 4656LL, "lim_fill_session_params", 4756);
    *(_QWORD *)(v48 + 112) = v50;
    if ( !v50 )
    {
LABEL_31:
      pe_delete_session(v22);
      goto LABEL_11;
    }
    v60 = (_WORD *)v50;
    mgmt_txrx_frame_hex_dump(
      *(_QWORD *)(*((_QWORD *)a1 + 6) + 1896LL),
      *(_DWORD *)(*((_QWORD *)a1 + 6) + 1888LL),
      0,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59);
    if ( (unsigned int)wlan_fill_bss_desc_from_scan_entry(v22, v60 + 2274, *((_QWORD *)a1 + 6)) )
      goto LABEL_18;
    v67 = (bool *)(v48 + 7020);
    param = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 7u);
    v77 = *((_QWORD *)a1 + 6);
    v80 = *(unsigned __int8 *)(v77 + 13);
    v79 = v77 + 13;
    v78 = v80;
    if ( !v80 && (param & 0x400000) != 0 )
    {
      if ( a1[233] )
      {
        *(_QWORD *)v79 = *(_QWORD *)(a1 + 233);
        v81 = *(_QWORD *)(a1 + 241);
        v82 = *(_QWORD *)(a1 + 249);
        v83 = *(_QWORD *)(a1 + 257);
        *(_BYTE *)(v79 + 32) = a1[265];
        *(_QWORD *)(v79 + 8) = v81;
        *(_QWORD *)(v79 + 16) = v82;
        *(_QWORD *)(v79 + 24) = v83;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: OWE transition ssid is %.*s",
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          "lim_fill_session_params",
          *(unsigned __int8 *)(*((_QWORD *)a1 + 6) + 13LL),
          *((_QWORD *)a1 + 6) + 14LL);
        v78 = *(unsigned __int8 *)(*((_QWORD *)a1 + 6) + 13LL);
      }
      else
      {
        v78 = 0;
      }
    }
    *(_BYTE *)(v48 + 36) = v78;
    qdf_mem_copy((void *)(v48 + 37), (const void *)(*((_QWORD *)a1 + 6) + 14LL), v78);
    *v67 = (a1[8] & 8) != 0;
    if ( (unsigned int)lim_fill_pe_session(
                         v22,
                         v48,
                         (__int64)(v60 + 2274),
                         *(_DWORD *)(*((_QWORD *)a1 + 6) + 52LL),
                         &v349) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to fill pe session vdev id %d",
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        "lim_fill_session_params",
        *(unsigned __int8 *)(v48 + 10));
      _qdf_mem_free(*(_QWORD *)(v48 + 112));
      v92 = v349;
      *(_QWORD *)(v48 + 112) = 0;
      *((_DWORD *)a1 + 67) = v92;
      goto LABEL_31;
    }
    memcpy((void *)(v48 + 10696), a1 + 56, 0xB0u);
    v93 = a1 + 16;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Assoc IE len: %d",
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      "lim_fill_session_params",
      *((unsigned int *)a1 + 4));
    if ( *((_DWORD *)a1 + 4) )
    {
      ((void (__fastcall *)(__int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 8, *((_QWORD *)a1 + 3));
      v348 = *((_DWORD *)a1 + 4);
    }
    else
    {
      v348 = 0;
    }
    cm_update_session_assoc_ie(*(_QWORD *)(v22 + 21624), *(unsigned __int8 *)(v48 + 10), (const void **)a1 + 2);
    v102 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 1u);
    v103 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 0);
    v104 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 7u);
    v105 = v102 & 0x18001;
    v106 = *(unsigned __int16 *)(*(_QWORD *)(v48 + 112) + 4566LL);
    *(_BYTE *)(*(_QWORD *)(v22 + 8) + 5655LL) = 0;
    if ( (v102 & 0x18001) != 0 && (v103 & 0x10) != 0 )
    {
      v107 = 9;
    }
    else if ( (v103 & 4) != 0 )
    {
      v107 = 1;
    }
    else if ( (v104 & 0x18000C00) != 0 )
    {
      v107 = 3;
    }
    else
    {
      if ( (v104 & 0xC0000) == 0 || *(_DWORD *)(v48 + 7036) != 1 )
      {
LABEL_43:
        v108 = v105 == 0;
        if ( (v102 & 0x669E) == 0 )
          v108 = 0;
        *(_BYTE *)(*(_QWORD *)(v22 + 8) + 5602LL) = v108;
        v109 = (v106 >> 4) & 1;
        if ( (v102 & 0x669E) == 0 )
          LOBYTE(v109) = 0;
        if ( v105 )
          LOBYTE(v109) = 1;
        *(_BYTE *)(*(_QWORD *)(v22 + 8) + 5652LL) = v109;
        *(_BYTE *)(*(_QWORD *)(v22 + 8) + 5656LL) = 0;
        if ( v102 == -1 )
        {
          v110 = 0;
        }
        else if ( (v102 & 0x400) != 0 )
        {
          v110 = 8;
        }
        else if ( (v102 & 0x200) != 0 )
        {
          v110 = 7;
        }
        else if ( (v102 & 0x8C) != 0 )
        {
          v110 = 4;
        }
        else if ( (v102 & 2) != 0 )
        {
          v110 = 3;
        }
        else if ( (v102 & 0x140) != 0 )
        {
          v110 = 6;
        }
        else if ( (v102 & 0x2010) != 0 )
        {
          v110 = 5;
        }
        else if ( (v102 & 0x800) != 0 )
        {
          v110 = 9;
        }
        else if ( (v102 & 0x1000) != 0 )
        {
          v110 = 10;
        }
        else if ( (v102 & 0x8001) != 0 )
        {
          v110 = 1;
        }
        else
        {
          v110 = (v102 >> 15) & 2;
        }
        *(_DWORD *)(v48 + 424) = v110;
        *(_DWORD *)(v48 + 156) = lim_get_connected_akm(v48, v102, v103, v104);
        v111 = *(_QWORD *)(v48 + 16);
        *(_BYTE *)(v48 + 7023) = (a1[8] & 2) != 0;
        *(_BYTE *)(v48 + 7364) = (a1[8] & 4) != 0;
        v112 = wlan_crypto_get_param(v111, 1u);
        v113 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 0);
        if ( v113 == -1 || v112 == -1 || (v113 & 0x6C8) == 0 || (v112 & 0x1868F) == 0 )
        {
          v127 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 1u);
          v128 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 0);
          if ( v128 == -1 || v127 == -1 || (v128 & 0x20) == 0 || (v127 & 0x1808F) == 0 )
          {
            v131 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 1u);
            v132 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 0);
            if ( v132 == -1 )
              goto LABEL_97;
            if ( v131 == -1 )
              goto LABEL_97;
            if ( (v132 & 0x100) == 0 )
              goto LABEL_97;
            if ( (v131 & 0x2010) == 0 )
              goto LABEL_97;
            v133 = _qdf_mem_malloc(0x70u, "lim_fill_wapi_ie", 4581);
            if ( !v133 )
              goto LABEL_97;
            v115 = (unsigned __int8 *)v133;
            lim_strip_ie(v22, *((_QWORD *)a1 + 3), a1 + 16, 68, 1, 0, 0, 0, 0);
            v130 = wlan_crypto_build_wapiie(
                     *(_QWORD *)(v48 + 16),
                     (__int64)v115,
                     v134,
                     v135,
                     v136,
                     v137,
                     v138,
                     v139,
                     v140,
                     v141);
          }
          else
          {
            v129 = _qdf_mem_malloc(0x32u, "lim_fill_wpa_ie", 4549);
            if ( !v129 )
              goto LABEL_97;
            v115 = (unsigned __int8 *)v129;
            lim_strip_ie(v22, *((_QWORD *)a1 + 3), a1 + 16, 221, 1, &unk_B35EBC, 3, 0, 0);
            v130 = wlan_crypto_build_wpaie(*(_QWORD *)(v48 + 16), (__int64)v115);
          }
          v142 = (_BYTE)v130 - (_BYTE)v115;
          if ( !v130 )
            v142 = 0;
          v143 = v142;
          **(_WORD **)(v48 + 112) = v142;
        }
        else
        {
          memset(v354, 0, 32);
          memset(v353, 0, sizeof(v353));
          v352 = 0;
          memset(v351, 0, sizeof(v351));
          v114 = _qdf_mem_malloc(0x101u, "lim_fill_rsn_ie", 4474);
          if ( !v114 )
            goto LABEL_97;
          v115 = (unsigned __int8 *)v114;
          v116 = lim_strip_ie(v22, *((_QWORD *)a1 + 3), a1 + 16, 48, 1, 0, 0, v114, 138);
          if ( (a1[8] & 1) != 0 && !v116 )
          {
            v125 = v115[1];
            v126 = (unsigned __int8)(v125 + 2);
            if ( v125 >= 0x89 )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: RSN length %d not within limits",
                v117,
                v118,
                v119,
                v120,
                v121,
                v122,
                v123,
                v124,
                "lim_fill_rsn_ie",
                v126);
LABEL_96:
              _qdf_mem_free((__int64)v115);
              goto LABEL_97;
            }
            v145 = v115;
            v143 = (unsigned __int8)(v125 + 2);
            **(_WORD **)(v48 + 112) = v126;
            v144 = (void *)(*(_QWORD *)(v48 + 112) + 2LL);
LABEL_95:
            qdf_mem_copy(v144, v145, v143);
            goto LABEL_96;
          }
          v146 = *(_QWORD *)(v48 + 112);
          qdf_mem_set(v351, 0x98u, 0);
          if ( *(_BYTE *)(v146 + 4633) == 1 )
          {
            HIBYTE(v352) = *(_BYTE *)(v48 + 36);
            qdf_mem_copy(v353, (const void *)(v48 + 37), HIBYTE(v352));
            qdf_mem_copy(v354, (const void *)(v146 + 4634), 2u);
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: FILS: vdev %d Cache id =0x%x 0x%x ssid: %.*s",
              v147,
              v148,
              v149,
              v150,
              v151,
              v152,
              v153,
              v154,
              "lim_fill_rsn_ie",
              *(unsigned __int8 *)(v48 + 10),
              LOBYTE(v354[0]),
              BYTE1(v354[0]),
              HIBYTE(v352),
              v353);
          }
          else
          {
            qdf_mem_copy(v351, (const void *)(v48 + 24), 6u);
            v163 = *(_QWORD *)(v48 + 16);
            if ( v163 )
            {
              if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(v48 + 16), v155, v156, v157, v158, v159, v160, v161, v162) & 1) != 0 )
              {
                v164 = *(_QWORD *)(v163 + 184);
                if ( v164 )
                  qdf_mem_copy(v351, (const void *)(v164 + 792), 6u);
              }
            }
          }
          peer_pmksa = wlan_crypto_get_peer_pmksa(
                         *(_QWORD *)(v48 + 16),
                         (__int64)v351,
                         v155,
                         v156,
                         v157,
                         v158,
                         v159,
                         v160,
                         v161,
                         v162);
          v67 = (bool *)(v48 + 7020);
          if ( peer_pmksa )
          {
            v174 = (unsigned __int8 *)peer_pmksa;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: PMKSA found",
              v166,
              v167,
              v168,
              v169,
              v170,
              v171,
              v172,
              v173,
              "lim_fill_rsn_ie");
            v175 = wlan_crypto_build_rsnie_with_pmksa(*(_QWORD *)(v48 + 16), (__int64)v115, (__int64)v174);
            if ( v175 )
            {
              **(_WORD **)(v48 + 112) = (_WORD)v175 - (_WORD)v115;
              qdf_mem_copy((void *)(*(_QWORD *)(v48 + 112) + 2LL), v115, (unsigned __int16)((_WORD)v175 - (_WORD)v115));
            }
            else
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Build RSN IE failed",
                v176,
                v177,
                v178,
                v179,
                v180,
                v181,
                v182,
                v183,
                "lim_update_connect_rsn_ie");
            }
            _qdf_mem_free((__int64)v115);
            wlan_cm_set_psk_pmk(*(_QWORD *)(v22 + 21632), *(_BYTE *)(v48 + 10), v174 + 22, v174[86]);
            ext_hdl = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(v48 + 16), v242, v243, v244, v245, v246, v247, v248, v249);
            if ( ext_hdl )
            {
              v259 = *(_QWORD *)(ext_hdl + 24080);
              if ( v259 )
              {
                v260 = v174[86];
                v261 = ext_hdl;
                *(_BYTE *)(v259 + 726) = v260;
                qdf_mem_copy((void *)(*(_QWORD *)(ext_hdl + 24080) + 662LL), v174 + 22, v260);
                v262 = *(_QWORD *)(v261 + 24080);
                v67 = (bool *)(v48 + 7020);
                qdf_mem_copy((void *)(v262 + 727), v174 + 6, 0x10u);
              }
            }
            else
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: vdev legacy private object is NULL",
                v251,
                v252,
                v253,
                v254,
                v255,
                v256,
                v257,
                v258,
                "lim_update_pmksa_to_profile");
            }
LABEL_97:
            v184 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 7u);
            if ( v184 == -1 )
              goto LABEL_144;
            v185 = v184;
            if ( (v184 & 0x1FFFFFE3) == 0
              || !wlan_get_ie_ptr_from_eid(0xF4u, *((unsigned __int8 **)a1 + 3), *((_DWORD *)a1 + 4)) )
            {
              goto LABEL_144;
            }
            v186 = *((unsigned __int8 **)a1 + 3);
            v187 = *((_DWORD *)a1 + 4);
            LOBYTE(v351[0]) = 0;
            ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0xF4u, v186, v187);
            if ( ie_ptr_from_eid )
            {
              v197 = ie_ptr_from_eid;
              v198 = wlan_crypto_parse_rsnxe_ie(ie_ptr_from_eid, v351, v189, v190, v191, v192, v193, v194, v195, v196);
              if ( v198 && (unsigned int)LOBYTE(v351[0]) + 1 >= v197[1] )
              {
                v216 = 0;
                v217 = -33648;
                while ( ((unsigned __int8)v217 & v198[v216]) == 0 )
                {
                  ++v216;
                  v217 >>= 8;
                  if ( LOBYTE(v351[0]) < (unsigned int)v216 )
                    goto LABEL_113;
                }
              }
              else
              {
                qdf_trace_msg(
                  0x68u,
                  2u,
                  "%s: RSNXE caps not present/unknown caps present. Cap len %d",
                  v199,
                  v200,
                  v201,
                  v202,
                  v203,
                  v204,
                  v205,
                  v206,
                  "lim_is_non_default_rsnxe_cap_set",
                  LOBYTE(v351[0]));
              }
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Do not strip RSNXE, unknown caps are set",
                v199,
                v200,
                v201,
                v202,
                v203,
                v204,
                v205,
                v206,
                "lim_strip_rsnx_ie");
LABEL_144:
              lim_update_fils_config(v22, v48, a1);
              v274 = *(_DWORD *)(v48 + 156);
              if ( v274 != 7 && v274 != 22 )
              {
                wlan_mlme_set_sae_single_pmk_bss_cap(*(_QWORD *)(v22 + 21624), *(unsigned __int8 *)(v48 + 10), 0);
                wlan_mlme_clear_sae_single_pmk_info(
                  *(_QWORD *)(v48 + 16),
                  nullptr,
                  v275,
                  v276,
                  v277,
                  v278,
                  v279,
                  v280,
                  v281,
                  v282);
              }
              v283 = v348;
              if ( v348 != *v93 )
              {
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: After stripping Assoc IE len: %d",
                  v266,
                  v267,
                  v268,
                  v269,
                  v270,
                  v271,
                  v272,
                  v273,
                  "lim_fill_session_params");
                if ( *v93 )
                {
                  ((void (__fastcall *)(__int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 8, *((_QWORD *)a1 + 3));
                  v283 = *((unsigned int *)a1 + 4);
                }
                else
                {
                  v283 = 0;
                }
              }
              qdf_mem_copy(v60 + 1157, *((const void **)a1 + 3), v283);
              v60[1156] = *((_DWORD *)a1 + 4);
              qdf_mem_copy(v60 + 131, *((const void **)a1 + 5), *((unsigned int *)a1 + 8));
              v60[130] = *((_DWORD *)a1 + 8);
              v292 = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(v48 + 16), v284, v285, v286, v287, v288, v289, v290, v291);
              if ( v292 )
              {
                v293 = v292;
                qdf_mem_set((void *)(v292 + 24227), 0x11u, 0);
                v294 = *(_QWORD *)(v48 + 112);
                v295 = *(unsigned __int16 *)(v294 + 2312);
                if ( *(_WORD *)(v294 + 2312) )
                {
                  v296 = v67;
                  LOWORD(v351[0]) = *(_WORD *)(v294 + 2312);
                  v297 = (void *)_qdf_mem_malloc(LOWORD(v351[0]), "lim_fill_session_params", 4863);
                  v61 = *(_QWORD *)(v48 + 112);
                  if ( !v297 )
                    goto LABEL_19;
                  qdf_mem_copy(v297, (const void *)(v61 + 2314), v295);
                  v298 = lim_strip_ie(v22, v297, v351, 127, 1, 0, 0, v293 + 24227, 15);
                  LOBYTE(v299) = *(_BYTE *)(*(_QWORD *)(v48 + 16) + 160LL);
                  if ( (_BYTE)v299 )
                  {
                    v300 = *((_QWORD *)a1 + 6);
                    if ( *(_QWORD *)(v300 + 1864) || (v299 = *(_QWORD *)(v300 + 1880)) != 0 )
                      LOBYTE(v299) = a1[272];
                  }
                  *(_BYTE *)(v48 + 13285) = v299;
                  _qdf_mem_free((__int64)v297);
                  if ( v298 )
                  {
                    qdf_trace_msg(
                      0x35u,
                      2u,
                      "%s: Parsing of ext cap failed with status : %d",
                      v301,
                      v302,
                      v303,
                      v304,
                      v305,
                      v306,
                      v307,
                      v308,
                      "lim_fill_session_params",
                      v298);
                    qdf_mem_set((void *)(v293 + 24227), 0x11u, 0);
LABEL_18:
                    v61 = *(_QWORD *)(v48 + 112);
LABEL_19:
                    _qdf_mem_free(v61);
                    *(_QWORD *)(v48 + 112) = 0;
                    goto LABEL_31;
                  }
                  v67 = v296;
                }
                if ( !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v48 + 284)) || v67[1656] )
                {
                  wlan_psoc_mlme_get_11be_capab(*(_QWORD *)(v22 + 21624), &v350);
                  if ( v350
                    && (wlan_vdev_mlme_is_mlo_vdev(
                          *(_QWORD *)(v48 + 16),
                          v310,
                          v311,
                          v312,
                          v313,
                          v314,
                          v315,
                          v316,
                          v317)
                      & 1) != 0 )
                  {
                    lim_fill_ml_info(a1, v60);
                  }
                  lim_set_emlsr_caps(v22, v48);
                  lim_dump_session_info(v22, v48);
                  lim_dump_he_info(v22, v48);
                  lim_dump_eht_info(v48);
                  v318 = *(_QWORD *)(v48 + 16);
                  if ( (*(_BYTE *)(v318 + 67) & 2) != 0 )
                  {
                    v319 = (void *)_qdf_mem_malloc(
                                     *(unsigned int *)(*((_QWORD *)a1 + 6) + 1888LL),
                                     "lim_cm_handle_join_req",
                                     4960);
                    *(_QWORD *)(v48 + 320) = v319;
                    if ( !v319 )
                      goto LABEL_31;
                    v320 = *(unsigned int *)(*((_QWORD *)a1 + 6) + 1888LL);
                    *(_DWORD *)(v48 + 312) = v320;
                    qdf_mem_copy(v319, *(const void **)(*((_QWORD *)a1 + 6) + 1896LL), v320);
                    v318 = *(_QWORD *)(v48 + 16);
                  }
                  if ( (*(_BYTE *)(v318 + 60) & 2) == 0 )
                    lim_send_mlo_caps_ie(v22, v318, 0, *(unsigned __int8 *)(v48 + 10));
                  v321 = _qdf_mem_malloc(
                           *(unsigned __int16 *)(*(_QWORD *)(v48 + 112) + 4548LL) + 114LL,
                           "lim_send_connect_req_to_mlm",
                           3859);
                  if ( v321 )
                  {
                    v330 = v321;
                    *(_BYTE *)v321 = *(_BYTE *)(v48 + 8);
                    *(_WORD *)(v321 + 4) = *(_WORD *)(*(_QWORD *)(v48 + 112) + 4548LL);
                    qdf_mem_copy(
                      (void *)(v321 + 6),
                      (const void *)(*(_QWORD *)(v48 + 112) + 4550LL),
                      (unsigned int)*(unsigned __int16 *)(*(_QWORD *)(v48 + 112) + 4548LL) + 2);
                    if ( (unsigned int)wlan_vdev_mlme_is_init_state(*(_QWORD *)(v48 + 16)) )
                    {
                      qdf_trace_msg(
                        0x35u,
                        2u,
                        "%s: Vdev %d not in int state cur state %d substate %d",
                        v331,
                        v332,
                        v333,
                        v334,
                        v335,
                        v336,
                        v337,
                        v338,
                        "lim_send_join_req",
                        *(unsigned __int8 *)(v48 + 10),
                        *(unsigned int *)(*(_QWORD *)(v48 + 16) + 20LL),
                        *(unsigned int *)(*(_QWORD *)(v48 + 16) + 24LL));
                      _qdf_trigger_self_recovery();
                    }
                    else if ( !(unsigned int)mlme_set_assoc_type(
                                               *(_QWORD *)(v48 + 16),
                                               0,
                                               v331,
                                               v332,
                                               v333,
                                               v334,
                                               v335,
                                               v336,
                                               v337,
                                               v338)
                           && !(unsigned int)wlan_vdev_mlme_sm_deliver_evt(
                                               *(_QWORD *)(v48 + 16),
                                               0,
                                               0x70u,
                                               v330,
                                               v339,
                                               v340,
                                               v341,
                                               v342,
                                               v343,
                                               v344,
                                               v345,
                                               v346) )
                    {
                      v19 = 0;
                      goto LABEL_13;
                    }
                    _qdf_mem_free(v330);
                  }
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "%s: Failed to send mlm req vdev id %d",
                    v322,
                    v323,
                    v324,
                    v325,
                    v326,
                    v327,
                    v328,
                    v329,
                    "lim_cm_handle_join_req",
                    *(unsigned __int8 *)(v48 + 10));
                  goto LABEL_31;
                }
                v309 = "%s: JOIN_REQ with invalid 6G security";
              }
              else
              {
                v309 = "%s: Invalid mlme priv object";
              }
LABEL_161:
              qdf_trace_msg(0x35u, 2u, v309, v223, v224, v225, v226, v227, v228, v229, v230, "lim_fill_session_params");
              goto LABEL_18;
            }
LABEL_113:
            v218 = *((_QWORD *)a1 + 6);
            v219 = *(_BYTE *)(v218 + 1286);
            v220 = util_scan_entry_rsnxe_by_gen(v218, v219);
            rsnxe_len_by_gen = (unsigned __int8)util_get_rsnxe_len_by_gen(*((_QWORD *)a1 + 6), v219);
            if ( rsnxe_len_by_gen > 1 || v220 && !rsnxe_len_by_gen )
              goto LABEL_144;
            v347 = rsnxe_len_by_gen;
            v222 = _qdf_mem_malloc(0x101u, "lim_strip_rsnx_ie", 4369);
            if ( v222 )
            {
              v231 = (_BYTE *)v222;
              lim_strip_ie(v22, *((_QWORD *)a1 + 3), a1 + 16, 244, 1, 0, 0, v222, 255);
              if ( !*v231 || !v231[1] )
                goto LABEL_143;
              if ( (unsigned __int8)v231[2] <= 0xFu )
              {
                v240 = "%s: None of the caps are set in 1st octet, strip RSNXE";
                v241 = 53;
LABEL_142:
                qdf_trace_msg(v241, 8u, v240, v232, v233, v234, v235, v236, v237, v238, v239, "lim_strip_rsnx_ie");
LABEL_143:
                _qdf_mem_free((__int64)v231);
                goto LABEL_144;
              }
              if ( (v347 & 1) == 0 )
              {
                if ( (v185 & 0x63DF3E3) != 0 )
                {
                  v240 = "%s: Strip RSNXE as it is not supported by AP";
                  v241 = 104;
                  goto LABEL_142;
                }
                if ( (v185 & 0x19C20C00) == 0 )
                {
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "%s: Error in handling RSNXE. Length AP: %d SELF: %d",
                    v232,
                    v233,
                    v234,
                    v235,
                    v236,
                    v237,
                    v238,
                    v239,
                    "lim_strip_rsnx_ie",
                    v347);
                  goto LABEL_186;
                }
              }
              v263 = lim_rebuild_rsnxe_cap(v231);
              if ( !v263 )
              {
LABEL_186:
                _qdf_mem_free((__int64)v231);
                goto LABEL_187;
              }
              v264 = v263;
              if ( !*(_BYTE *)(v263 + 1) )
              {
                _qdf_mem_free(v263);
                goto LABEL_186;
              }
              appended = lim_append_rsnxe_to_assoc_ie(a1, v263);
              _qdf_mem_free(v264);
              _qdf_mem_free((__int64)v231);
              if ( !appended )
                goto LABEL_144;
            }
LABEL_187:
            v309 = "%s: Error in handling RSNXE";
            goto LABEL_161;
          }
          v207 = wlan_crypto_build_rsnie_with_pmksa(*(_QWORD *)(v48 + 16), (__int64)v115, 0);
          if ( !v207 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Build RSN IE failed",
              v208,
              v209,
              v210,
              v211,
              v212,
              v213,
              v214,
              v215,
              "lim_update_connect_rsn_ie");
            goto LABEL_96;
          }
          v143 = (unsigned __int16)((_WORD)v207 - (_WORD)v115);
          **(_WORD **)(v48 + 112) = (_WORD)v207 - (_WORD)v115;
        }
        v144 = (void *)(*(_QWORD *)(v48 + 112) + 2LL);
        v145 = v115;
        goto LABEL_95;
      }
      v107 = 4;
    }
    *(_BYTE *)(*(_QWORD *)(v22 + 8) + 5655LL) = v107;
    goto LABEL_43;
  }
  v62 = *((unsigned __int8 **)a1 + 6);
  if ( v62 == (unsigned __int8 *)-1LL )
  {
    v65 = 0;
    v63 = 0;
    v64 = 0;
    v66 = 0;
  }
  else
  {
    v63 = v62[1];
    v64 = v62[2];
    v65 = v62[3];
    v66 = v62[6];
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: vdev_id: %d cm_id 0x%x : pe_session create failed BSSID%02x:%02x:%02x:**:**:%02x",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "lim_cm_create_session",
    *a1,
    *((unsigned int *)a1 + 1),
    v63,
    v64,
    v65,
    v66);
LABEL_11:
  v19 = wma_remove_bss_peer_before_join(v20, *a1, a1);
  if ( v19 != 24 )
  {
    lim_cm_send_connect_rsp(v22, 0, a1, 14, 16, 0, 0);
    goto LABEL_13;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v19;
}
