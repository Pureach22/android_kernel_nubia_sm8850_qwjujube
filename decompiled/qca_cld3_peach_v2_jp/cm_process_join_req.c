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
  unsigned int v94; // w26
  int v95; // w27
  int v96; // w3
  int v97; // w9
  unsigned int v98; // w8
  char v99; // w10
  bool v100; // w12
  int v101; // w8
  int v102; // w8
  __int64 v103; // x0
  int v104; // w26
  int v105; // w0
  __int64 v106; // x0
  unsigned __int8 *v107; // x26
  int v108; // w0
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  unsigned int v117; // w8
  __int64 v118; // x4
  int v119; // w26
  int v120; // w0
  __int64 v121; // x0
  void *v122; // x0
  int v123; // w26
  int v124; // w0
  __int64 v125; // x0
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  unsigned __int8 v134; // w9
  size_t v135; // x2
  void *v136; // x0
  unsigned __int8 *v137; // x1
  __int64 v138; // x28
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  __int64 peer_pmksa; // x0
  double v156; // d0
  double v157; // d1
  double v158; // d2
  double v159; // d3
  double v160; // d4
  double v161; // d5
  double v162; // d6
  double v163; // d7
  unsigned __int8 *v164; // x27
  char *v165; // x0
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  int v174; // w0
  int v175; // w26
  unsigned __int8 *v176; // x1
  int v177; // w2
  unsigned __int8 *ie_ptr_from_eid; // x0
  double v179; // d0
  double v180; // d1
  double v181; // d2
  double v182; // d3
  double v183; // d4
  double v184; // d5
  double v185; // d6
  double v186; // d7
  unsigned __int8 *v187; // x27
  unsigned __int8 *v188; // x0
  double v189; // d0
  double v190; // d1
  double v191; // d2
  double v192; // d3
  double v193; // d4
  double v194; // d5
  double v195; // d6
  double v196; // d7
  char *v197; // x0
  double v198; // d0
  double v199; // d1
  double v200; // d2
  double v201; // d3
  double v202; // d4
  double v203; // d5
  double v204; // d6
  double v205; // d7
  unsigned __int8 v206; // w8
  unsigned int v207; // w9
  __int64 v208; // x0
  char v209; // w28
  __int64 v210; // x27
  unsigned int rsnxe_len_by_gen; // w8
  __int64 v212; // x0
  double v213; // d0
  double v214; // d1
  double v215; // d2
  double v216; // d3
  double v217; // d4
  double v218; // d5
  double v219; // d6
  double v220; // d7
  _BYTE *v221; // x27
  double v222; // d0
  double v223; // d1
  double v224; // d2
  double v225; // d3
  double v226; // d4
  double v227; // d5
  double v228; // d6
  double v229; // d7
  const char *v230; // x2
  unsigned int v231; // w0
  double v232; // d0
  double v233; // d1
  double v234; // d2
  double v235; // d3
  double v236; // d4
  double v237; // d5
  double v238; // d6
  double v239; // d7
  __int64 ext_hdl; // x0
  double v241; // d0
  double v242; // d1
  double v243; // d2
  double v244; // d3
  double v245; // d4
  double v246; // d5
  double v247; // d6
  double v248; // d7
  __int64 v249; // x8
  size_t v250; // x2
  __int64 v251; // x25
  __int64 v252; // x8
  __int64 v253; // x0
  __int64 v254; // x26
  int appended; // w28
  double v256; // d0
  double v257; // d1
  double v258; // d2
  double v259; // d3
  double v260; // d4
  double v261; // d5
  double v262; // d6
  double v263; // d7
  int v264; // w8
  double v265; // d0
  double v266; // d1
  double v267; // d2
  double v268; // d3
  double v269; // d4
  double v270; // d5
  double v271; // d6
  double v272; // d7
  size_t v273; // x2
  double v274; // d0
  double v275; // d1
  double v276; // d2
  double v277; // d3
  double v278; // d4
  double v279; // d5
  double v280; // d6
  double v281; // d7
  __int64 v282; // x0
  __int64 v283; // x23
  bool *v284; // x27
  __int64 v285; // x8
  unsigned int v286; // w25
  void *v287; // x24
  unsigned int v288; // w25
  __int64 v289; // x8
  __int64 v290; // x8
  double v291; // d0
  double v292; // d1
  double v293; // d2
  double v294; // d3
  double v295; // d4
  double v296; // d5
  double v297; // d6
  double v298; // d7
  const char *v299; // x2
  __int64 v300; // x0
  double v301; // d0
  double v302; // d1
  double v303; // d2
  double v304; // d3
  double v305; // d4
  double v306; // d5
  double v307; // d6
  double v308; // d7
  __int64 v309; // x23
  double v310; // d0
  double v311; // d1
  double v312; // d2
  double v313; // d3
  double v314; // d4
  double v315; // d5
  double v316; // d6
  double v317; // d7
  double v318; // d0
  double v319; // d1
  double v320; // d2
  double v321; // d3
  double v322; // d4
  double v323; // d5
  double v324; // d6
  double v325; // d7
  unsigned int v326; // [xsp+30h] [xbp-C0h]
  unsigned int v327; // [xsp+3Ch] [xbp-B4h]
  int v328; // [xsp+40h] [xbp-B0h] BYREF
  bool v329; // [xsp+44h] [xbp-ACh] BYREF
  _QWORD v330[10]; // [xsp+48h] [xbp-A8h] BYREF
  __int64 v331; // [xsp+98h] [xbp-58h]
  _QWORD v332[4]; // [xsp+A0h] [xbp-50h] BYREF
  _QWORD v333[6]; // [xsp+C0h] [xbp-30h] BYREF

  v333[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  LOBYTE(v330[0]) = 0;
  session_by_bssid = pe_find_session_by_bssid(v22, v23 + 1, v330);
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
          v330,
          *(unsigned __int8 *)(v22 + 12272),
          0,
          *a1);
  if ( v39 )
  {
    v48 = v39;
    *(_DWORD *)(v39 + 4) = *((_DWORD *)a1 + 1);
    v49 = *((_QWORD *)a1 + 6);
    v329 = 0;
    v328 = 1;
    v50 = _qdf_mem_malloc((unsigned __int16)(*(_WORD *)(v49 + 1704) + 68) + 4472LL, "lim_fill_session_params", 4756);
    *(_QWORD *)(v48 + 112) = v50;
    if ( !v50 )
    {
LABEL_31:
      pe_delete_session(v22);
      goto LABEL_11;
    }
    v60 = (_WORD *)v50;
    mgmt_txrx_frame_hex_dump(
      *(_QWORD *)(*((_QWORD *)a1 + 6) + 1712LL),
      *(_DWORD *)(*((_QWORD *)a1 + 6) + 1704LL),
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
    if ( (unsigned int)wlan_fill_bss_desc_from_scan_entry(v22, v60 + 2182, *((_QWORD *)a1 + 6)) )
      goto LABEL_18;
    v67 = (bool *)(v48 + 7020);
    param = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 7u);
    v77 = *((_QWORD *)a1 + 6);
    v80 = *(unsigned __int8 *)(v77 + 13);
    v79 = v77 + 13;
    v78 = v80;
    if ( !v80 && (param & 0x400000) != 0 )
    {
      if ( a1[56] )
      {
        *(_QWORD *)v79 = *((_QWORD *)a1 + 7);
        v81 = *((_QWORD *)a1 + 8);
        v82 = *((_QWORD *)a1 + 9);
        v83 = *((_QWORD *)a1 + 10);
        *(_BYTE *)(v79 + 32) = a1[88];
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
                         (__int64)(v60 + 2182),
                         *(_DWORD *)(*((_QWORD *)a1 + 6) + 52LL),
                         &v328) )
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
      v92 = v328;
      *(_QWORD *)(v48 + 112) = 0;
      *((_DWORD *)a1 + 23) = v92;
      goto LABEL_31;
    }
    v93 = a1 + 16;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Assoc IE len: %d",
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      "lim_fill_session_params",
      *((unsigned int *)a1 + 4));
    if ( *((_DWORD *)a1 + 4) )
    {
      ((void (__fastcall *)(__int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 8, *((_QWORD *)a1 + 3));
      v327 = *((_DWORD *)a1 + 4);
    }
    else
    {
      v327 = 0;
    }
    cm_update_session_assoc_ie(*(_QWORD *)(v22 + 21552), *(unsigned __int8 *)(v48 + 10), (const void **)a1 + 2);
    v94 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 1u);
    v95 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 0);
    v96 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 7u);
    v97 = v94 & 0x18001;
    v98 = *(unsigned __int16 *)(*(_QWORD *)(v48 + 112) + 4382LL);
    *(_BYTE *)(*(_QWORD *)(v22 + 8) + 5439LL) = 0;
    if ( (v94 & 0x18001) != 0 && (v95 & 0x10) != 0 )
    {
      v99 = 9;
    }
    else if ( (v95 & 4) != 0 )
    {
      v99 = 1;
    }
    else if ( (v96 & 0x18000C00) != 0 )
    {
      v99 = 3;
    }
    else
    {
      if ( (v96 & 0xC0000) == 0 || *(_DWORD *)(v48 + 7036) != 1 )
      {
LABEL_43:
        v100 = v97 == 0;
        if ( (v94 & 0x669E) == 0 )
          v100 = 0;
        *(_BYTE *)(*(_QWORD *)(v22 + 8) + 5386LL) = v100;
        v101 = (v98 >> 4) & 1;
        if ( (v94 & 0x669E) == 0 )
          LOBYTE(v101) = 0;
        if ( v97 )
          LOBYTE(v101) = 1;
        *(_BYTE *)(*(_QWORD *)(v22 + 8) + 5436LL) = v101;
        *(_BYTE *)(*(_QWORD *)(v22 + 8) + 5440LL) = 0;
        if ( v94 == -1 )
        {
          v102 = 0;
        }
        else if ( (v94 & 0x400) != 0 )
        {
          v102 = 8;
        }
        else if ( (v94 & 0x200) != 0 )
        {
          v102 = 7;
        }
        else if ( (v94 & 0x8C) != 0 )
        {
          v102 = 4;
        }
        else if ( (v94 & 2) != 0 )
        {
          v102 = 3;
        }
        else if ( (v94 & 0x140) != 0 )
        {
          v102 = 6;
        }
        else if ( (v94 & 0x2010) != 0 )
        {
          v102 = 5;
        }
        else if ( (v94 & 0x800) != 0 )
        {
          v102 = 9;
        }
        else if ( (v94 & 0x1000) != 0 )
        {
          v102 = 10;
        }
        else if ( (v94 & 0x8001) != 0 )
        {
          v102 = 1;
        }
        else
        {
          v102 = (v94 >> 15) & 2;
        }
        *(_DWORD *)(v48 + 424) = v102;
        *(_DWORD *)(v48 + 156) = lim_get_connected_akm(v48, v94, v95, v96);
        v103 = *(_QWORD *)(v48 + 16);
        *(_BYTE *)(v48 + 7023) = (a1[8] & 2) != 0;
        *(_BYTE *)(v48 + 7364) = (a1[8] & 4) != 0;
        v104 = wlan_crypto_get_param(v103, 1u);
        v105 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 0);
        if ( v105 == -1 || v104 == -1 || (v105 & 0x6C8) == 0 || (v104 & 0x1868F) == 0 )
        {
          v119 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 1u);
          v120 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 0);
          if ( v120 == -1 || v119 == -1 || (v120 & 0x20) == 0 || (v119 & 0x1808F) == 0 )
          {
            v123 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 1u);
            v124 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 0);
            if ( v124 == -1 )
              goto LABEL_94;
            if ( v123 == -1 )
              goto LABEL_94;
            if ( (v124 & 0x100) == 0 )
              goto LABEL_94;
            if ( (v123 & 0x2010) == 0 )
              goto LABEL_94;
            v125 = _qdf_mem_malloc(0x70u, "lim_fill_wapi_ie", 4581);
            if ( !v125 )
              goto LABEL_94;
            v107 = (unsigned __int8 *)v125;
            lim_strip_ie(v22, *((_QWORD *)a1 + 3), a1 + 16, 68, 1, 0, 0, 0, 0);
            v122 = wlan_crypto_build_wapiie(
                     *(_QWORD *)(v48 + 16),
                     (__int64)v107,
                     v126,
                     v127,
                     v128,
                     v129,
                     v130,
                     v131,
                     v132,
                     v133);
          }
          else
          {
            v121 = _qdf_mem_malloc(0x32u, "lim_fill_wpa_ie", 4549);
            if ( !v121 )
              goto LABEL_94;
            v107 = (unsigned __int8 *)v121;
            lim_strip_ie(v22, *((_QWORD *)a1 + 3), a1 + 16, 221, 1, &unk_A3039C, 3, 0, 0);
            v122 = wlan_crypto_build_wpaie(*(_QWORD *)(v48 + 16), (__int64)v107);
          }
          v134 = (_BYTE)v122 - (_BYTE)v107;
          if ( !v122 )
            v134 = 0;
          v135 = v134;
          **(_WORD **)(v48 + 112) = v134;
        }
        else
        {
          memset(v333, 0, 32);
          memset(v332, 0, sizeof(v332));
          v331 = 0;
          memset(v330, 0, sizeof(v330));
          v106 = _qdf_mem_malloc(0x101u, "lim_fill_rsn_ie", 4474);
          if ( !v106 )
            goto LABEL_94;
          v107 = (unsigned __int8 *)v106;
          v108 = lim_strip_ie(v22, *((_QWORD *)a1 + 3), a1 + 16, 48, 1, 0, 0, v106, 138);
          if ( (a1[8] & 1) != 0 && !v108 )
          {
            v117 = v107[1];
            v118 = (unsigned __int8)(v117 + 2);
            if ( v117 >= 0x89 )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: RSN length %d not within limits",
                v109,
                v110,
                v111,
                v112,
                v113,
                v114,
                v115,
                v116,
                "lim_fill_rsn_ie",
                v118);
LABEL_93:
              _qdf_mem_free((__int64)v107);
              goto LABEL_94;
            }
            v137 = v107;
            v135 = (unsigned __int8)(v117 + 2);
            **(_WORD **)(v48 + 112) = v118;
            v136 = (void *)(*(_QWORD *)(v48 + 112) + 2LL);
LABEL_92:
            qdf_mem_copy(v136, v137, v135);
            goto LABEL_93;
          }
          v138 = *(_QWORD *)(v48 + 112);
          qdf_mem_set(v330, 0x98u, 0);
          if ( *(_BYTE *)(v138 + 4449) == 1 )
          {
            HIBYTE(v331) = *(_BYTE *)(v48 + 36);
            qdf_mem_copy(v332, (const void *)(v48 + 37), HIBYTE(v331));
            qdf_mem_copy(v333, (const void *)(v138 + 4450), 2u);
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: FILS: vdev %d Cache id =0x%x 0x%x ssid: %.*s",
              v139,
              v140,
              v141,
              v142,
              v143,
              v144,
              v145,
              v146,
              "lim_fill_rsn_ie",
              *(unsigned __int8 *)(v48 + 10),
              LOBYTE(v333[0]),
              BYTE1(v333[0]),
              HIBYTE(v331),
              v332);
          }
          else
          {
            qdf_mem_copy(v330, (const void *)(v48 + 24), 6u);
          }
          peer_pmksa = wlan_crypto_get_peer_pmksa(
                         *(_QWORD *)(v48 + 16),
                         (__int64)v330,
                         v147,
                         v148,
                         v149,
                         v150,
                         v151,
                         v152,
                         v153,
                         v154);
          v67 = (bool *)(v48 + 7020);
          if ( peer_pmksa )
          {
            v164 = (unsigned __int8 *)peer_pmksa;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: PMKSA found",
              v156,
              v157,
              v158,
              v159,
              v160,
              v161,
              v162,
              v163,
              "lim_fill_rsn_ie");
            v165 = wlan_crypto_build_rsnie_with_pmksa(*(_QWORD *)(v48 + 16), (__int64)v107, (__int64)v164);
            if ( v165 )
            {
              **(_WORD **)(v48 + 112) = (_WORD)v165 - (_WORD)v107;
              qdf_mem_copy((void *)(*(_QWORD *)(v48 + 112) + 2LL), v107, (unsigned __int16)((_WORD)v165 - (_WORD)v107));
            }
            else
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Build RSN IE failed",
                v166,
                v167,
                v168,
                v169,
                v170,
                v171,
                v172,
                v173,
                "lim_update_connect_rsn_ie");
            }
            _qdf_mem_free((__int64)v107);
            wlan_cm_set_psk_pmk(*(_QWORD *)(v22 + 21560), *(_BYTE *)(v48 + 10), v164 + 22, v164[86]);
            ext_hdl = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(v48 + 16), v232, v233, v234, v235, v236, v237, v238, v239);
            if ( ext_hdl )
            {
              v249 = *(_QWORD *)(ext_hdl + 24080);
              if ( v249 )
              {
                v250 = v164[86];
                v251 = ext_hdl;
                *(_BYTE *)(v249 + 726) = v250;
                qdf_mem_copy((void *)(*(_QWORD *)(ext_hdl + 24080) + 662LL), v164 + 22, v250);
                v252 = *(_QWORD *)(v251 + 24080);
                v67 = (bool *)(v48 + 7020);
                qdf_mem_copy((void *)(v252 + 727), v164 + 6, 0x10u);
              }
            }
            else
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: vdev legacy private object is NULL",
                v241,
                v242,
                v243,
                v244,
                v245,
                v246,
                v247,
                v248,
                "lim_update_pmksa_to_profile");
            }
LABEL_94:
            v174 = wlan_crypto_get_param(*(_QWORD *)(v48 + 16), 7u);
            if ( v174 == -1 )
              goto LABEL_141;
            v175 = v174;
            if ( (v174 & 0x1FFFFFE3) == 0
              || !wlan_get_ie_ptr_from_eid(0xF4u, *((unsigned __int8 **)a1 + 3), *((_DWORD *)a1 + 4)) )
            {
              goto LABEL_141;
            }
            v176 = *((unsigned __int8 **)a1 + 3);
            v177 = *((_DWORD *)a1 + 4);
            LOBYTE(v330[0]) = 0;
            ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0xF4u, v176, v177);
            if ( ie_ptr_from_eid )
            {
              v187 = ie_ptr_from_eid;
              v188 = wlan_crypto_parse_rsnxe_ie(ie_ptr_from_eid, v330, v179, v180, v181, v182, v183, v184, v185, v186);
              if ( v188 && (unsigned int)LOBYTE(v330[0]) + 1 >= v187[1] )
              {
                v206 = 0;
                v207 = -33648;
                while ( ((unsigned __int8)v207 & v188[v206]) == 0 )
                {
                  ++v206;
                  v207 >>= 8;
                  if ( LOBYTE(v330[0]) < (unsigned int)v206 )
                    goto LABEL_110;
                }
              }
              else
              {
                qdf_trace_msg(
                  0x68u,
                  2u,
                  "%s: RSNXE caps not present/unknown caps present. Cap len %d",
                  v189,
                  v190,
                  v191,
                  v192,
                  v193,
                  v194,
                  v195,
                  v196,
                  "lim_is_non_default_rsnxe_cap_set",
                  LOBYTE(v330[0]));
              }
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Do not strip RSNXE, unknown caps are set",
                v189,
                v190,
                v191,
                v192,
                v193,
                v194,
                v195,
                v196,
                "lim_strip_rsnx_ie");
LABEL_141:
              lim_update_fils_config(v22, v48, a1);
              v264 = *(_DWORD *)(v48 + 156);
              if ( v264 != 7 && v264 != 22 )
              {
                wlan_mlme_set_sae_single_pmk_bss_cap(*(_QWORD *)(v22 + 21552), *(unsigned __int8 *)(v48 + 10), 0);
                wlan_mlme_clear_sae_single_pmk_info(
                  *(_QWORD *)(v48 + 16),
                  nullptr,
                  v265,
                  v266,
                  v267,
                  v268,
                  v269,
                  v270,
                  v271,
                  v272);
              }
              v273 = v327;
              if ( v327 != *v93 )
              {
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: After stripping Assoc IE len: %d",
                  v256,
                  v257,
                  v258,
                  v259,
                  v260,
                  v261,
                  v262,
                  v263,
                  "lim_fill_session_params");
                if ( *v93 )
                {
                  ((void (__fastcall *)(__int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 8, *((_QWORD *)a1 + 3));
                  v273 = *((unsigned int *)a1 + 4);
                }
                else
                {
                  v273 = 0;
                }
              }
              qdf_mem_copy(v60 + 1157, *((const void **)a1 + 3), v273);
              v60[1156] = *((_DWORD *)a1 + 4);
              qdf_mem_copy(v60 + 131, *((const void **)a1 + 5), *((unsigned int *)a1 + 8));
              v60[130] = *((_DWORD *)a1 + 8);
              v282 = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(v48 + 16), v274, v275, v276, v277, v278, v279, v280, v281);
              if ( v282 )
              {
                v283 = v282;
                v284 = v67;
                qdf_mem_set((void *)(v282 + 24227), 0x11u, 0);
                v285 = *(_QWORD *)(v48 + 112);
                v286 = *(unsigned __int16 *)(v285 + 2312);
                if ( *(_WORD *)(v285 + 2312) )
                {
                  LOWORD(v330[0]) = *(_WORD *)(v285 + 2312);
                  v287 = (void *)_qdf_mem_malloc(LOWORD(v330[0]), "lim_fill_session_params", 4863);
                  v61 = *(_QWORD *)(v48 + 112);
                  if ( !v287 )
                    goto LABEL_19;
                  qdf_mem_copy(v287, (const void *)(v61 + 2314), v286);
                  v288 = lim_strip_ie(v22, v287, v330, 127, 1, 0, 0, v283 + 24227, 15);
                  LOBYTE(v289) = *(_BYTE *)(*(_QWORD *)(v48 + 16) + 92LL);
                  if ( (_BYTE)v289 )
                  {
                    v290 = *((_QWORD *)a1 + 6);
                    if ( *(_QWORD *)(v290 + 1680) || (v289 = *(_QWORD *)(v290 + 1696)) != 0 )
                      LOBYTE(v289) = a1[96];
                  }
                  v284[3056] = v289;
                  _qdf_mem_free((__int64)v287);
                  if ( v288 )
                  {
                    qdf_trace_msg(
                      0x35u,
                      2u,
                      "%s: Parsing of ext cap failed with status : %d",
                      v291,
                      v292,
                      v293,
                      v294,
                      v295,
                      v296,
                      v297,
                      v298,
                      "lim_fill_session_params",
                      v288);
                    qdf_mem_set((void *)(v283 + 24227), 0x11u, 0);
LABEL_18:
                    v61 = *(_QWORD *)(v48 + 112);
LABEL_19:
                    _qdf_mem_free(v61);
                    *(_QWORD *)(v48 + 112) = 0;
                    goto LABEL_31;
                  }
                }
                if ( !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v48 + 284)) || v284[1656] )
                {
                  wlan_psoc_mlme_get_11be_capab(*(_QWORD *)(v22 + 21552), &v329);
                  lim_dump_session_info(v22, v48);
                  lim_dump_he_info(v22, v48);
                  v300 = _qdf_mem_malloc(
                           *(unsigned __int16 *)(*(_QWORD *)(v48 + 112) + 4364LL) + 114LL,
                           "lim_send_connect_req_to_mlm",
                           3859);
                  if ( v300 )
                  {
                    v309 = v300;
                    *(_BYTE *)v300 = *(_BYTE *)(v48 + 8);
                    *(_WORD *)(v300 + 4) = *(_WORD *)(*(_QWORD *)(v48 + 112) + 4364LL);
                    qdf_mem_copy(
                      (void *)(v300 + 6),
                      (const void *)(*(_QWORD *)(v48 + 112) + 4366LL),
                      (unsigned int)*(unsigned __int16 *)(*(_QWORD *)(v48 + 112) + 4364LL) + 2);
                    if ( (unsigned int)wlan_vdev_mlme_is_init_state(*(_QWORD *)(v48 + 16)) )
                    {
                      qdf_trace_msg(
                        0x35u,
                        2u,
                        "%s: Vdev %d not in int state cur state %d substate %d",
                        v310,
                        v311,
                        v312,
                        v313,
                        v314,
                        v315,
                        v316,
                        v317,
                        "lim_send_join_req",
                        *(unsigned __int8 *)(v48 + 10),
                        *(unsigned int *)(*(_QWORD *)(v48 + 16) + 20LL),
                        *(unsigned int *)(*(_QWORD *)(v48 + 16) + 24LL));
                      _qdf_trigger_self_recovery();
                    }
                    else if ( !(unsigned int)mlme_set_assoc_type(
                                               *(_QWORD *)(v48 + 16),
                                               0,
                                               v310,
                                               v311,
                                               v312,
                                               v313,
                                               v314,
                                               v315,
                                               v316,
                                               v317)
                           && !(unsigned int)wlan_vdev_mlme_sm_deliver_evt(
                                               *(_QWORD *)(v48 + 16),
                                               0,
                                               0x70u,
                                               v309,
                                               v318,
                                               v319,
                                               v320,
                                               v321,
                                               v322,
                                               v323,
                                               v324,
                                               v325) )
                    {
                      v19 = 0;
                      goto LABEL_13;
                    }
                    _qdf_mem_free(v309);
                  }
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "%s: Failed to send mlm req vdev id %d",
                    v301,
                    v302,
                    v303,
                    v304,
                    v305,
                    v306,
                    v307,
                    v308,
                    "lim_cm_handle_join_req",
                    *(unsigned __int8 *)(v48 + 10));
                  goto LABEL_31;
                }
                v299 = "%s: JOIN_REQ with invalid 6G security";
              }
              else
              {
                v299 = "%s: Invalid mlme priv object";
              }
LABEL_158:
              qdf_trace_msg(0x35u, 2u, v299, v213, v214, v215, v216, v217, v218, v219, v220, "lim_fill_session_params");
              goto LABEL_18;
            }
LABEL_110:
            v208 = *((_QWORD *)a1 + 6);
            v209 = *(_BYTE *)(v208 + 1158);
            v210 = util_scan_entry_rsnxe_by_gen(v208, v209);
            rsnxe_len_by_gen = (unsigned __int8)util_get_rsnxe_len_by_gen(*((_QWORD *)a1 + 6), v209);
            if ( rsnxe_len_by_gen > 1 || v210 && !rsnxe_len_by_gen )
              goto LABEL_141;
            v326 = rsnxe_len_by_gen;
            v212 = _qdf_mem_malloc(0x101u, "lim_strip_rsnx_ie", 4369);
            if ( v212 )
            {
              v221 = (_BYTE *)v212;
              lim_strip_ie(v22, *((_QWORD *)a1 + 3), a1 + 16, 244, 1, 0, 0, v212, 255);
              if ( !*v221 || !v221[1] )
                goto LABEL_140;
              if ( (unsigned __int8)v221[2] <= 0xFu )
              {
                v230 = "%s: None of the caps are set in 1st octet, strip RSNXE";
                v231 = 53;
LABEL_139:
                qdf_trace_msg(v231, 8u, v230, v222, v223, v224, v225, v226, v227, v228, v229, "lim_strip_rsnx_ie");
LABEL_140:
                _qdf_mem_free((__int64)v221);
                goto LABEL_141;
              }
              if ( (v326 & 1) == 0 )
              {
                if ( (v175 & 0x63DF3E3) != 0 )
                {
                  v230 = "%s: Strip RSNXE as it is not supported by AP";
                  v231 = 104;
                  goto LABEL_139;
                }
                if ( (v175 & 0x19C20C00) == 0 )
                {
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "%s: Error in handling RSNXE. Length AP: %d SELF: %d",
                    v222,
                    v223,
                    v224,
                    v225,
                    v226,
                    v227,
                    v228,
                    v229,
                    "lim_strip_rsnx_ie",
                    v326);
                  goto LABEL_174;
                }
              }
              v253 = lim_rebuild_rsnxe_cap(v221);
              if ( !v253 )
              {
LABEL_174:
                _qdf_mem_free((__int64)v221);
                goto LABEL_175;
              }
              v254 = v253;
              if ( !*(_BYTE *)(v253 + 1) )
              {
                _qdf_mem_free(v253);
                goto LABEL_174;
              }
              appended = lim_append_rsnxe_to_assoc_ie(a1, v253);
              _qdf_mem_free(v254);
              _qdf_mem_free((__int64)v221);
              if ( !appended )
                goto LABEL_141;
            }
LABEL_175:
            v299 = "%s: Error in handling RSNXE";
            goto LABEL_158;
          }
          v197 = wlan_crypto_build_rsnie_with_pmksa(*(_QWORD *)(v48 + 16), (__int64)v107, 0);
          if ( !v197 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Build RSN IE failed",
              v198,
              v199,
              v200,
              v201,
              v202,
              v203,
              v204,
              v205,
              "lim_update_connect_rsn_ie");
            goto LABEL_93;
          }
          v135 = (unsigned __int16)((_WORD)v197 - (_WORD)v107);
          **(_WORD **)(v48 + 112) = (_WORD)v197 - (_WORD)v107;
        }
        v136 = (void *)(*(_QWORD *)(v48 + 112) + 2LL);
        v137 = v107;
        goto LABEL_92;
      }
      v99 = 4;
    }
    *(_BYTE *)(*(_QWORD *)(v22 + 8) + 5439LL) = v99;
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
