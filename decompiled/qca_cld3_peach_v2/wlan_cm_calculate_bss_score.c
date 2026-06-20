__int64 __fastcall wlan_cm_calculate_bss_score(
        __int64 a1,
        unsigned int *a2,
        _QWORD *a3,
        __int64 a4,
        unsigned __int8 *a5,
        char a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v14; // x0
  _QWORD *v15; // x19
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x27
  unsigned __int8 sta_mlo_conn_max_num; // w26
  _QWORD *v37; // x1
  _QWORD *v38; // x21
  __int64 v39; // x20
  int v40; // w28
  int v41; // w9
  char v42; // w25
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned __int64 v51; // x19
  unsigned __int8 *v52; // x22
  __int64 v53; // x4
  __int64 v54; // x5
  __int64 v55; // x6
  __int64 v56; // x7
  __int64 v57; // x21
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  _QWORD *peer_by_mac; // x0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 entry; // x0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned __int8 *v84; // x21
  _BOOL4 v85; // w24
  __int64 v86; // x0
  _QWORD *v87; // x25
  __int64 v88; // x0
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  __int64 v97; // x21
  _QWORD *v98; // x0
  _QWORD *v99; // x22
  unsigned int v100; // w8
  int v101; // w26
  int v102; // w9
  unsigned int v103; // w9
  int v104; // w10
  unsigned __int64 v105; // x19
  unsigned int v106; // w9
  unsigned int v107; // w11
  _QWORD *v108; // x1
  unsigned int v109; // w23
  __int64 v110; // x0
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  __int64 v119; // x22
  _QWORD *v120; // x0
  _QWORD *v121; // x21
  unsigned int v122; // w8
  __int64 v123; // x0
  __int64 v124; // x0
  unsigned int v125; // w24
  __int64 v126; // x0
  __int64 v127; // x0
  __int64 v128; // x0
  __int64 v129; // x0
  int v130; // w8
  int v131; // w10
  const char *v132; // x2
  _QWORD *v133; // x1
  __int64 v134; // x20
  __int64 v135; // x26
  int v136; // w25
  unsigned int *v137; // x22
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  _QWORD *v154; // x28
  __int64 v155; // x1
  int v156; // w8
  bool v157; // zf
  __int64 v158; // x9
  unsigned int v159; // w10
  unsigned int v160; // w10
  _BYTE *v161; // x9
  __int64 v162; // x11
  unsigned int v163; // w10
  _BOOL4 v164; // w21
  int v165; // w20
  char v166; // w23
  __int64 v167; // x3
  __int64 v168; // x4
  __int64 v169; // x5
  __int64 v170; // x6
  __int64 v171; // x3
  unsigned __int64 v172; // x8
  __int64 v173; // x10
  int v174; // w4
  __int64 v175; // x9
  bool v176; // w10
  int v177; // w8
  double v178; // d0
  double v179; // d1
  double v180; // d2
  double v181; // d3
  double v182; // d4
  double v183; // d5
  double v184; // d6
  double v185; // d7
  __int64 v186; // x19
  __int64 v187; // x9
  unsigned int v188; // w8
  unsigned int v189; // w9
  unsigned __int8 *v190; // x8
  __int64 v191; // x3
  __int64 v192; // x4
  __int64 v193; // x5
  __int64 v194; // x8
  __int64 v195; // x3
  __int64 v196; // x4
  __int64 v197; // x5
  __int64 v198; // x6
  __int64 v199; // x8
  __int64 v200; // x21
  unsigned int v201; // w9
  unsigned int v202; // w10
  __int64 v203; // x0
  __int64 v204; // x0
  __int64 v205; // x0
  double v206; // d0
  double v207; // d1
  double v208; // d2
  double v209; // d3
  double v210; // d4
  double v211; // d5
  double v212; // d6
  double v213; // d7
  __int64 v214; // x8
  __int64 v215; // x3
  __int64 v216; // x4
  __int64 v217; // x5
  __int64 v218; // x6
  bool v219; // zf
  __int64 v220; // x20
  __int64 v221; // x0
  __int64 v222; // x0
  unsigned int v223; // w21
  unsigned __int8 *v224; // x8
  __int64 v225; // x4
  __int64 v226; // x5
  __int64 v227; // x6
  __int64 v228; // x7
  __int64 v229; // x8
  __int64 v230; // x3
  __int64 v231; // x4
  __int64 v232; // x5
  __int64 v233; // x6
  __int64 v234; // x19
  __int64 v235; // x0
  __int64 v236; // x0
  unsigned __int8 v237; // w20
  _QWORD *i; // x1
  _QWORD *v239; // x21
  _QWORD *v240; // x22
  __int64 v241; // x8
  __int64 v242; // x11
  int v243; // w9
  int v244; // w25
  unsigned __int8 v245; // w10
  unsigned int v246; // w11
  __int64 v247; // x8
  __int64 v248; // x9
  int v249; // w10
  int v250; // w11
  int v251; // w8
  int v252; // w9
  unsigned __int8 *v254; // x9
  int v255; // w10
  __int64 v256; // x12
  int v257; // w8
  unsigned __int8 v258; // w11
  unsigned int v259; // w12
  __int64 v260; // x23
  __int64 v261; // x0
  __int64 v262; // x0
  __int64 v263; // [xsp+0h] [xbp-100h]
  __int64 v264; // [xsp+8h] [xbp-F8h]
  char v265; // [xsp+28h] [xbp-D8h]
  int v266; // [xsp+30h] [xbp-D0h]
  _BOOL4 v267; // [xsp+34h] [xbp-CCh]
  __int64 cmpt_obj; // [xsp+38h] [xbp-C8h]
  char v269; // [xsp+44h] [xbp-BCh]
  __int64 v270; // [xsp+48h] [xbp-B8h]
  unsigned __int8 v271; // [xsp+54h] [xbp-ACh]
  __int64 v272; // [xsp+58h] [xbp-A8h]
  unsigned int v274; // [xsp+6Ch] [xbp-94h]
  __int64 v276; // [xsp+78h] [xbp-88h]
  _QWORD *v277; // [xsp+80h] [xbp-80h]
  _QWORD *v280; // [xsp+98h] [xbp-68h]
  _QWORD *v281; // [xsp+A0h] [xbp-60h] BYREF
  _QWORD *v282; // [xsp+A8h] [xbp-58h] BYREF
  __int64 v283; // [xsp+B0h] [xbp-50h] BYREF
  __int64 v284; // [xsp+B8h] [xbp-48h]
  __int64 v285; // [xsp+C0h] [xbp-40h]
  __int64 v286; // [xsp+C8h] [xbp-38h]
  _QWORD *v287; // [xsp+D0h] [xbp-30h] BYREF
  _QWORD *v288[5]; // [xsp+D8h] [xbp-28h] BYREF

  v288[3] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 80);
  v281 = nullptr;
  v282 = nullptr;
  if ( !v14 )
  {
    v132 = "%s: psoc NULL";
LABEL_115:
    result = qdf_trace_msg(0x68u, 2u, v132, a7, a8, a9, a10, a11, a12, a13, a14, "wlan_cm_calculate_bss_score");
    goto LABEL_116;
  }
  v15 = a3;
  if ( !a3 )
  {
    v132 = "%s: Scan list NULL";
    goto LABEL_115;
  }
  v272 = v14;
  result = wlan_psoc_mlme_get_cmpt_obj(v14);
  if ( !result )
    goto LABEL_116;
  v26 = *(unsigned __int16 *)(result + 2070);
  v276 = result;
  qdf_trace_msg(
    0x68u,
    8u,
    "Self caps: HT %d VHT %d HE %d EHT %d VHT_24Ghz %d BF cap %d bw_above_20_24ghz %d bw_above_20_5ghz %d 2.4G NSS %d 5G NSS %d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26 & 1,
    (v26 >> 1) & 1,
    (v26 >> 2) & 1,
    (v26 >> 3) & 1,
    (v26 >> 4) & 1,
    (v26 >> 5) & 1,
    (v26 >> 7) & 1,
    (v26 >> 6) & 1,
    *(unsigned __int8 *)(result + 2068),
    *(unsigned __int8 *)(result + 2069));
  v287 = nullptr;
  v288[0] = nullptr;
  v280 = v15;
  v35 = *(_QWORD *)(a1 + 80);
  if ( v35 )
  {
    cmpt_obj = wlan_psoc_mlme_get_cmpt_obj(*(_QWORD *)(a1 + 80));
    if ( cmpt_obj )
    {
      sta_mlo_conn_max_num = wlan_mlme_get_sta_mlo_conn_max_num(v35);
      qdf_list_peek_front(v15, v288);
      v37 = v288[0];
      if ( v288[0] )
      {
        v269 = a6;
        v271 = sta_mlo_conn_max_num;
        v266 = sta_mlo_conn_max_num - 1;
        do
        {
          qdf_list_peek_next(v15, v37, &v287);
          v38 = v288[0];
          v284 = 0;
          v39 = v288[0][3];
          v285 = 0;
          v286 = 0;
          v40 = *(unsigned __int8 *)(v39 + 1918);
          v41 = *(_DWORD *)(v39 + 1888) + 65500;
          v283 = *(_QWORD *)(v39 + 1896) + 36LL;
          v284 = (unsigned __int16)v41;
          v42 = wlan_action_oui_search(v35, &v283, 16);
          if ( (v42 & 1) != 0 )
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: IoT AP %02x:%02x:%02x:**:**:%02x slo candidate not allowed",
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              "cm_is_slo_candidate_allowed",
              *(unsigned __int8 *)(v39 + 1),
              *(unsigned __int8 *)(v39 + 2),
              *(unsigned __int8 *)(v39 + 3),
              *(unsigned __int8 *)(v39 + 6));
          if ( sta_mlo_conn_max_num == 1 || (wlan_cm_is_eht_allowed_for_current_security(v35, v39, 1) & 1) == 0 )
          {
            if ( !v40 )
              goto LABEL_40;
            if ( (*(_BYTE *)(v39 + 1960) & 1) != 0 )
              *(_BYTE *)(v39 + 1960) = 0;
            if ( v40 == 1 )
              goto LABEL_40;
            if ( *(_BYTE *)(v39 + 2008) == 1 )
              *(_BYTE *)(v39 + 2008) = 0;
            if ( v40 == 2 )
            {
LABEL_40:
              v85 = 0;
              if ( (v42 & 1) != 0 )
                goto LABEL_98;
              goto LABEL_41;
            }
            if ( *(_BYTE *)(v39 + 2056) == 1 )
              *(_BYTE *)(v39 + 2056) = 0;
            if ( v40 == 3 )
            {
LABEL_87:
              v15 = v280;
              a6 = v269;
              v85 = 0;
              sta_mlo_conn_max_num = v271;
              if ( (v42 & 1) == 0 )
                goto LABEL_41;
LABEL_98:
              if ( !v85 )
                goto LABEL_10;
LABEL_99:
              qdf_list_remove_node((__int64)v15, v288[0]);
              if ( v39 )
              {
                v128 = *(_QWORD *)(v39 + 1320);
                if ( v128 )
                  _qdf_mem_free(v128);
                v129 = *(_QWORD *)(v39 + 1896);
                if ( v129 )
                  _qdf_mem_free(v129);
                _qdf_mem_free(v39);
              }
              _qdf_mem_free((__int64)v288[0]);
              goto LABEL_10;
            }
LABEL_310:
            __break(0x5512u);
          }
          v277 = v38;
          if ( *(_BYTE *)(v39 + 1918) )
          {
            v51 = 0;
            v52 = (unsigned __int8 *)(v39 + 1920);
            while ( v51 != 4 )
            {
              if ( v52[40] == 1 )
              {
                peer_by_mac = wlan_objmgr_get_peer_by_mac(v35, v52, 0x4Du);
                if ( peer_by_mac )
                {
                  if ( v52 )
                  {
                    v53 = *v52;
                    v54 = v52[1];
                    v55 = v52[2];
                    v56 = v52[5];
                  }
                  else
                  {
                    v55 = 0;
                    v53 = 0;
                    v54 = 0;
                    v56 = 0;
                  }
                  v57 = (__int64)peer_by_mac;
                  LODWORD(v263) = *((unsigned __int16 *)v52 + 3);
                  LODWORD(v264) = *(unsigned __int8 *)(peer_by_mac[12] + 168LL);
                  qdf_trace_msg(
                    0x68u,
                    8u,
                    "%s: %02x:%02x:%02x:**:**:%02x link (%d) dup peer existed on vdev %d",
                    v67,
                    v68,
                    v69,
                    v70,
                    v71,
                    v72,
                    v73,
                    v74,
                    "cm_validate_partner_links",
                    v53,
                    v54,
                    v55,
                    v56,
                    v263,
                    v264);
                  v52[40] = 0;
                  wlan_objmgr_peer_release_ref(v57, 0x4Du, v58, v59, v60, v61, v62, v63, v64, v65);
                }
                else
                {
                  entry = cm_get_entry(v280, (__int64)v52, v39 + 1912);
                  if ( entry )
                  {
                    v84 = (unsigned __int8 *)entry;
                    if ( !*(_QWORD *)(entry + 1824) || (scm_scan_entries_contain_cmn_akm(v39, entry) & 1) == 0 )
                    {
                      v52[40] = 0;
                      LODWORD(v263) = *((unsigned __int16 *)v52 + 3);
                      qdf_trace_msg(
                        0x68u,
                        8u,
                        "%s: %02x:%02x:%02x:**:**:%02xlink (%d) akm not matching",
                        v76,
                        v77,
                        v78,
                        v79,
                        v80,
                        v81,
                        v82,
                        v83,
                        "cm_validate_partner_links",
                        v84[1],
                        v84[2],
                        v84[3],
                        v84[6],
                        v263);
                    }
                  }
                  else if ( *(_BYTE *)(v39 + 112) && ((a6 & 1) == 0 || !*(_BYTE *)(cmpt_obj + 2057)) )
                  {
                    v52[40] = 0;
                  }
                }
              }
              ++v51;
              v52 += 48;
              if ( v51 >= *(unsigned __int8 *)(v39 + 1918) )
                goto LABEL_46;
            }
            goto LABEL_310;
          }
LABEL_46:
          v15 = v280;
          if ( (v42 & 1) != 0 )
            goto LABEL_10;
          if ( !v40 )
          {
            v38 = v277;
            v85 = 0;
            goto LABEL_41;
          }
          if ( (unsigned int)(v40 - 4) < 0xFFFFFFFD )
            goto LABEL_310;
          v100 = *(unsigned __int8 *)(v39 + 1960);
          v101 = v100;
          if ( v40 != 1 )
          {
            v102 = *(unsigned __int8 *)(v39 + 2008);
            v157 = v102 == 0;
            v103 = v102 + v100;
            if ( v157 )
              v104 = 0;
            else
              v104 = 2;
            v101 = v104 | v100;
            if ( v40 != 2 )
            {
              v130 = *(unsigned __int8 *)(v39 + 2056);
              v157 = v130 == 0;
              v100 = v130 + v103;
              if ( v157 )
                v131 = 0;
              else
                v131 = 4;
              v101 |= v131;
              v38 = v277;
              if ( !v100 )
                goto LABEL_87;
              goto LABEL_56;
            }
            v100 = v103;
          }
          v38 = v277;
          if ( !v100 )
            goto LABEL_87;
LABEL_56:
          LOBYTE(v105) = 0;
          v106 = 0;
          v267 = v271 <= v100;
          if ( v271 > v100 )
            v107 = v100;
          else
            v107 = v266;
          v274 = v107;
          do
          {
            v109 = (unsigned __int8)v106;
            if ( (unsigned __int8)v106 != v101
              && (v106 & v101) == (unsigned __int8)v106
              && ((((((unsigned __int8)v106 - (((unsigned __int8)v106 >> 1) & 0x55555555u)) >> 2) & 0x33)
                 + (((_BYTE)v106 - (((unsigned __int8)v106 >> 1) & 0x55)) & 0x33)
                 + (unsigned __int8)((((((unsigned __int8)v106 - (((unsigned __int8)v106 >> 1) & 0x55555555u)) >> 2)
                                     & 0x33)
                                    + (((unsigned __int8)v106 - (((unsigned __int8)v106 >> 1) & 0x55555555)) & 0x33)) >> 4))
                & 0xF) <= v107 )
            {
              v110 = util_scan_copy_cache_entry(v39);
              if ( v110 )
              {
                v119 = v110;
                v120 = qdf_mem_malloc_atomic_fl(0x20u, (__int64)"cm_mlo_generate_candidate_list", 0xD71u);
                if ( v120 )
                {
                  v121 = v120;
                  qdf_mem_set((void *)(v119 + 1920), 0x90u, 0);
                  v270 = v119 + 1920;
                  if ( (v105 & 1) != 0 )
                  {
                    qdf_mem_copy((void *)(v119 + 1920), (const void *)(v39 + 1920), 0x30u);
                    v122 = 1;
                    if ( v40 != 1 )
                      goto LABEL_78;
                  }
                  else
                  {
                    v122 = 0;
                    if ( v40 != 1 )
                    {
LABEL_78:
                      if ( (v105 & 2) != 0 )
                      {
                        v125 = v122 + 1;
                        qdf_mem_copy((void *)(v270 + 48LL * v122), (const void *)(v39 + 1968), 0x30u);
                        v122 = v125;
                      }
                      if ( v40 != 2 && (v105 & 4) != 0 )
                      {
                        v265 = v122 + 1;
                        qdf_mem_copy((void *)(v270 + 48LL * v122), (const void *)(v39 + 2016), 0x30u);
                        LOBYTE(v122) = v265;
                      }
                    }
                  }
                  *(_BYTE *)(v119 + 1918) = v122;
                  v108 = v121;
                  v121[3] = v119;
                  v38 = v277;
                  qdf_list_insert_after((__int64)v280, v108, v277);
                }
                else
                {
                  v123 = *(_QWORD *)(v119 + 1320);
                  if ( v123 )
                    _qdf_mem_free(v123);
                  v124 = *(_QWORD *)(v119 + 1896);
                  v38 = v277;
                  if ( v124 )
                    _qdf_mem_free(v124);
                  _qdf_mem_free(v119);
                }
              }
              else
              {
                qdf_trace_msg(
                  0x68u,
                  8u,
                  "%s: Copy cache entry failed for 0x%x",
                  v111,
                  v112,
                  v113,
                  v114,
                  v115,
                  v116,
                  v117,
                  v118,
                  "cm_mlo_generate_candidate_list",
                  v109);
              }
              v107 = v274;
            }
            v106 = v109 + 1;
            v105 = (unsigned __int8)(v109 + 1);
          }
          while ( !(v105 >> v40) );
          v15 = v280;
          a6 = v269;
          sta_mlo_conn_max_num = v271;
          v85 = v267;
          if ( (v42 & 1) != 0 )
            goto LABEL_98;
LABEL_41:
          v86 = v38[3];
          if ( !*(_QWORD *)(v86 + 1824) )
            goto LABEL_98;
          v87 = v38;
          v88 = util_scan_copy_cache_entry(v86);
          if ( !v88 )
          {
            qdf_trace_msg(
              0x68u,
              2u,
              "%s: Copy cache entry failed",
              v89,
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              v96,
              "cm_add_11_ax_candidate");
            if ( !v85 )
              goto LABEL_10;
            goto LABEL_99;
          }
          v97 = v88;
          v98 = qdf_mem_malloc_atomic_fl(0x20u, (__int64)"cm_add_11_ax_candidate", 0xC79u);
          if ( !v98 )
          {
            v126 = *(_QWORD *)(v97 + 1320);
            if ( v126 )
              _qdf_mem_free(v126);
            v127 = *(_QWORD *)(v97 + 1896);
            if ( v127 )
              _qdf_mem_free(v127);
            _qdf_mem_free(v97);
            if ( !v85 )
              goto LABEL_10;
            goto LABEL_99;
          }
          v99 = v98;
          *(_BYTE *)(v97 + 1918) = 0;
          *(_BYTE *)(v97 + 2072) = 0;
          *(_QWORD *)(v97 + 1824) = 0;
          *(_WORD *)(v97 + 1204) = 0;
          *(_QWORD *)(v97 + 1800) = 0;
          *(_QWORD *)(v97 + 1808) = 0;
          qdf_mem_set((void *)(v97 + 1912), 0xA0u, 0);
          *(_BYTE *)(v97 + 1919) = -1;
          *(_DWORD *)(v97 + 52) = util_scan_get_phymode(a1, v97);
          v99[3] = v97;
          qdf_list_insert_after((__int64)v15, v99, v87);
          if ( v85 )
            goto LABEL_99;
LABEL_10:
          v37 = v287;
          v287 = nullptr;
          v288[0] = v37;
        }
        while ( v37 );
      }
    }
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: psoc NULL", v27, v28, v29, v30, v31, v32, v33, v34, "cm_mlo_generate_candidate_list");
  }
  if ( (unsigned int)qdf_list_peek_front(v15, &v282) )
  {
    v132 = "%s: failed to peer front of scan list";
    goto LABEL_115;
  }
  v133 = v282;
  if ( !v282 )
  {
LABEL_248:
    v287 = nullptr;
    v288[0] = nullptr;
    v237 = wlan_mlme_get_sta_mlo_conn_max_num(v272);
    qdf_list_peek_front(v15, v288);
    for ( i = v288[0]; i; v288[0] = i )
    {
      qdf_list_peek_next(v15, i, &v287);
      v240 = v287;
      v239 = v288[0];
      v283 = 0;
      v241 = v288[0][3];
      if ( *(_DWORD *)(v241 + 1912) | *(unsigned __int16 *)(v241 + 1916) )
      {
        v242 = 1LL << *(_BYTE *)(v241 + 1919);
        v243 = *(unsigned __int8 *)(v241 + 1918);
        v244 = (unsigned __int16)v242;
        if ( *(_BYTE *)(v241 + 1918) )
        {
          if ( (unsigned int)(v243 - 5) < 0xFFFFFFFC )
            goto LABEL_310;
          if ( *(_BYTE *)(v241 + 1960) )
            v245 = 2;
          else
            v245 = 1;
          if ( (*(_BYTE *)(v241 + 1960) & 1) != 0 && v237 >= 2u )
          {
            v244 = (unsigned __int16)(v242 | (1LL << *(_BYTE *)(v241 + 1930)));
            v245 = 2;
          }
          if ( v243 != 1 )
          {
            if ( *(_BYTE *)(v241 + 2008) == 1 )
            {
              v246 = v245++;
              if ( v246 < v237 )
                v244 |= (unsigned __int16)(1LL << *(_BYTE *)(v241 + 1978));
            }
            if ( v243 != 2 )
            {
              if ( *(_BYTE *)(v241 + 2056) == 1 && ++v245 <= (unsigned int)v237 )
                v244 |= (unsigned __int16)(1LL << *(_BYTE *)(v241 + 2026));
              if ( v243 != 3 && *(_BYTE *)(v241 + 2104) == 1 && (unsigned __int8)(v245 + 1) <= (unsigned int)v237 )
                v244 |= (unsigned __int16)(1LL << *(_BYTE *)(v241 + 2074));
            }
          }
        }
        if ( v287 )
        {
          do
          {
            qdf_list_peek_next(v15, v240, &v283);
            v247 = v240[3];
            v248 = v239[3];
            v249 = *(_DWORD *)(v247 + 1912);
            v250 = *(_DWORD *)(v248 + 1912);
            v251 = *(unsigned __int16 *)(v247 + 1916);
            v252 = *(unsigned __int16 *)(v248 + 1916);
            if ( v249 == v250 && v251 == v252 )
            {
              v254 = (unsigned __int8 *)v240[3];
              v255 = v254[1918];
              v256 = 1LL << v254[1919];
              v257 = (unsigned __int16)v256;
              if ( v254[1918] )
              {
                if ( (unsigned int)(v255 - 5) < 0xFFFFFFFC )
                  goto LABEL_310;
                if ( v254[1960] )
                  v258 = 2;
                else
                  v258 = 1;
                if ( (v254[1960] & 1) != 0 && v237 >= 2u )
                {
                  v258 = 2;
                  v257 = (unsigned __int16)(v256 | (1LL << v254[1930]));
                }
                if ( v255 != 1 )
                {
                  if ( v254[2008] == 1 )
                  {
                    v259 = v258++;
                    if ( v259 < v237 )
                      v257 |= (unsigned __int16)(1LL << v254[1978]);
                  }
                  if ( v255 != 2 )
                  {
                    if ( v254[2056] == 1 && ++v258 <= (unsigned int)v237 )
                      v257 |= (unsigned __int16)(1LL << v254[2026]);
                    if ( v255 != 3 && v254[2104] == 1 && (unsigned __int8)(v258 + 1) <= (unsigned int)v237 )
                      v257 |= (unsigned __int16)(1LL << v254[2074]);
                  }
                }
              }
              if ( v257 == v244 )
              {
                qdf_list_remove_node((__int64)v15, v240);
                v260 = v240[3];
                if ( v260 )
                {
                  v261 = *(_QWORD *)(v260 + 1320);
                  if ( v261 )
                    _qdf_mem_free(v261);
                  v262 = *(_QWORD *)(v260 + 1896);
                  if ( v262 )
                    _qdf_mem_free(v262);
                  _qdf_mem_free(v260);
                }
                _qdf_mem_free((__int64)v240);
              }
            }
            v240 = (_QWORD *)v283;
            v283 = 0;
          }
          while ( v240 );
          v239 = v288[0];
        }
      }
      if ( (unsigned int)qdf_list_peek_next(v15, v239, &v287) )
        break;
      i = v287;
      v287 = nullptr;
    }
    result = cm_print_candidate_list(v15);
    goto LABEL_116;
  }
  v134 = v276;
  v135 = 0;
  v136 = 1;
  v137 = a2 + 103;
  while ( 1 )
  {
    qdf_list_peek_next(v15, v133, &v281);
    v154 = v282;
    v155 = v282[3];
    v156 = *(_DWORD *)a4 | *(unsigned __int16 *)(a4 + 4);
    if ( !v156 )
      goto LABEL_133;
    if ( (*(_BYTE *)(v134 + 2048) & 1) == 0 )
      goto LABEL_130;
    v157 = *(_DWORD *)a4 == *(_DWORD *)(v155 + 1) && *(unsigned __int16 *)(a4 + 4) == *(unsigned __int16 *)(v155 + 5);
    if ( v157 )
    {
      LOBYTE(v156) = 0;
LABEL_133:
      if ( (*(_BYTE *)(v134 + 2048) & 2) == 0 )
        goto LABEL_140;
      goto LABEL_134;
    }
    if ( *(char *)(v155 + 60) >= *(char *)(v134 + 1956) )
    {
LABEL_130:
      LOBYTE(v156) = 0;
      if ( (*(_BYTE *)(v134 + 2048) & 2) == 0 )
        goto LABEL_140;
      goto LABEL_134;
    }
    LODWORD(v264) = *(char *)(v134 + 1956);
    LODWORD(v263) = *(char *)(v155 + 60);
    qdf_trace_msg(
      0x68u,
      8u,
      "Candidate(%02x:%02x:%02x:**:**:%02x  freq %d): remove entry, rssi %d lower than rssi_threshold %d",
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      v152,
      v153,
      *(unsigned __int8 *)(v155 + 1),
      *(unsigned __int8 *)(v155 + 2),
      *(unsigned __int8 *)(v155 + 3),
      *(unsigned __int8 *)(v155 + 6),
      *(unsigned int *)(v155 + 1192),
      v263,
      v264);
    v155 = v154[3];
    LOBYTE(v156) = 1;
    if ( (*(_BYTE *)(v134 + 2048) & 2) == 0 )
      goto LABEL_140;
LABEL_134:
    v158 = *(_QWORD *)(v155 + 1744);
    if ( v158 )
    {
      v159 = *(unsigned __int8 *)(v158 + 1);
      if ( v159 >= 7 )
      {
        v160 = v159 - 4;
        v161 = (_BYTE *)(v158 + 6);
        do
        {
          v162 = (unsigned __int8)v161[1];
          v163 = v160 - 2;
          if ( (unsigned int)v162 > (unsigned __int8)v163 )
            break;
          if ( *v161 == 4 )
          {
            LODWORD(v264) = (unsigned __int8)v161[2];
            LODWORD(v263) = *(char *)(v155 + 60);
            qdf_trace_msg(
              0x68u,
              8u,
              "Candidate(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d, assoc disallowed set in MBO/OCE IE reason %d",
              v146,
              v147,
              v148,
              v149,
              v150,
              v151,
              v152,
              v153,
              *(unsigned __int8 *)(v155 + 1),
              *(unsigned __int8 *)(v155 + 2),
              *(unsigned __int8 *)(v155 + 3),
              *(unsigned __int8 *)(v155 + 6),
              *(unsigned int *)(v155 + 1192),
              v263,
              v264);
            v155 = v154[3];
            goto LABEL_141;
          }
          v160 = v163 - v162;
          v161 += v162 + 2;
        }
        while ( (unsigned __int8)v160 > 2u );
      }
    }
LABEL_140:
    if ( (v156 & 1) != 0 )
    {
LABEL_141:
      v164 = 0;
      v165 = 2;
      v166 = 1;
      if ( v155 != -1 )
      {
LABEL_142:
        v167 = *(unsigned __int8 *)(v155 + 1);
        v168 = *(unsigned __int8 *)(v155 + 2);
        v169 = *(unsigned __int8 *)(v155 + 3);
        v170 = *(unsigned __int8 *)(v155 + 6);
LABEL_172:
        LODWORD(v263) = v165;
        qdf_trace_msg(
          0x68u,
          8u,
          "Candidate(%02x:%02x:%02x:**:**:%02x freq %d): denylist_action %d",
          v146,
          v147,
          v148,
          v149,
          v150,
          v151,
          v152,
          v153,
          v167,
          v168,
          v169,
          v170,
          *(unsigned int *)(v155 + 1192),
          v263);
        goto LABEL_173;
      }
LABEL_171:
      v169 = 0;
      v167 = 0;
      v168 = 0;
      v170 = 0;
      goto LABEL_172;
    }
    v165 = wlan_denylist_action_on_bssid(a1, v155);
    if ( v165 != 3 && v165 )
    {
LABEL_155:
      v171 = 0;
    }
    else
    {
      v136 = 0;
      if ( a2 )
      {
        v171 = 0;
        if ( !v165 )
        {
          v172 = *a2;
          if ( !(_DWORD)v172 || (v173 = v154[3], *(char *)(v173 + 60) < -74) || !*(_BYTE *)(v276 + 1928) )
          {
            v164 = 0;
            v171 = 0;
            v136 = 0;
LABEL_164:
            cm_calculate_bss_score(v272, a1, v154[3], v171, a4, v15, 2);
            if ( (policy_mgr_is_hw_dbs_capable(v272) & 1) != 0 || !*(_BYTE *)(v276 + 1946) )
            {
              v166 = 0;
            }
            else
            {
              v186 = v154[3];
              if ( (policy_mgr_is_sta_sap_mcc_weightage_required(v272, a1, *(unsigned int *)(v186 + 1192)) & 1) != 0 )
              {
                v187 = *(_QWORD *)(v186 + 1824);
                v188 = *(_DWORD *)(v186 + 1260) * (unsigned int)*(unsigned __int8 *)(v276 + 1946) / 0x64;
                *(_DWORD *)(v186 + 1260) = v188;
                if ( v187 )
                  v189 = 2 * *(unsigned __int8 *)(v186 + 1918) + 2;
                else
                  v189 = 1;
                if ( v188 < v189 )
                {
                  v188 = v189;
                  *(_DWORD *)(v186 + 1260) = v189;
                }
                LODWORD(v264) = v188;
                LODWORD(v263) = *(char *)(v186 + 60);
                qdf_trace_msg(
                  0x68u,
                  8u,
                  "Candidate(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d, is causing MCC, update score to %d",
                  v178,
                  v179,
                  v180,
                  v181,
                  v182,
                  v183,
                  v184,
                  v185,
                  *(unsigned __int8 *)(v186 + 1),
                  *(unsigned __int8 *)(v186 + 2),
                  *(unsigned __int8 *)(v186 + 3),
                  *(unsigned __int8 *)(v186 + 6),
                  *(unsigned int *)(v186 + 1192),
                  v263,
                  v264);
              }
              v15 = v280;
              v166 = 0;
            }
            goto LABEL_173;
          }
          v174 = *(_DWORD *)(v173 + 1192);
          v175 = 0;
          v176 = 1;
          while ( 1 )
          {
            if ( v175 == 102 )
              goto LABEL_310;
            if ( v137[v175 - 102] == v174 )
              break;
            v176 = ++v175 < v172;
            if ( v172 == v175 )
            {
              v136 = 0;
              goto LABEL_155;
            }
          }
          v171 = *((unsigned __int8 *)v137 + v175);
          if ( v176 )
          {
            v223 = *((unsigned __int8 *)v137 + v175);
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: pcl freq %d pcl_chan_weight %d",
              v146,
              v147,
              v148,
              v149,
              v150,
              v151,
              v152,
              v153,
              "wlan_cm_calculate_bss_score");
            v171 = v223;
          }
          v136 = 0;
        }
      }
      else
      {
        v171 = 0;
      }
    }
    v164 = v165 == 1;
    if ( !v165 || (v164 & v136) != 0 )
      goto LABEL_164;
    v155 = v154[3];
    if ( v165 != 3 )
    {
      v166 = 0;
      if ( v155 != -1 )
        goto LABEL_142;
      goto LABEL_171;
    }
    v177 = *(_QWORD *)(v155 + 1824) ? 2 * *(unsigned __int8 *)(v155 + 1918) + 2 : 1;
    *(_DWORD *)(v155 + 1260) = v177;
    v194 = v154[3];
    if ( v194 == -1 )
    {
      v197 = 0;
      v195 = 0;
      v196 = 0;
      v198 = 0;
    }
    else
    {
      v195 = *(unsigned __int8 *)(v194 + 1);
      v196 = *(unsigned __int8 *)(v194 + 2);
      v197 = *(unsigned __int8 *)(v194 + 3);
      v198 = *(unsigned __int8 *)(v194 + 6);
    }
    LODWORD(v263) = *(char *)(v194 + 60);
    LODWORD(v264) = *(_DWORD *)(v194 + 1260);
    qdf_trace_msg(
      0x68u,
      8u,
      "Candidate(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d, is in Avoidlist, give min score %d",
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      v152,
      v153,
      v195,
      v196,
      v197,
      v198,
      *(unsigned int *)(v194 + 1192),
      v263,
      v264);
    v164 = 0;
    v166 = 0;
    v165 = 3;
LABEL_173:
    if ( a5 )
    {
      v190 = (unsigned __int8 *)v154[3];
      if ( a5[3] == v190[4] && a5[4] == v190[5] && a5[5] == v190[6] )
      {
        if ( v190 == (unsigned __int8 *)-1LL )
        {
          v193 = 0;
          v191 = 0;
          v192 = 0;
        }
        else
        {
          v191 = v190[1];
          v192 = v190[2];
          v193 = v190[3];
        }
        qdf_trace_msg(
          0x68u,
          8u,
          "Candidate(%02x:%02x:%02x:**:**:%02x freq %d): boost bss score due to same last 3 byte match",
          v178,
          v179,
          v180,
          v181,
          v182,
          v183,
          v184,
          v185,
          v191,
          v192,
          v193);
        *(_DWORD *)(v154[3] + 1260LL) = 20000;
      }
    }
    if ( (v164 & v136) == 1 )
    {
      if ( v135 )
      {
        v199 = v154[3];
        v200 = *(_QWORD *)(v135 + 24);
        v201 = *(_DWORD *)(v199 + 1260);
        v202 = *(_DWORD *)(v200 + 1260);
        if ( v201 <= v202 )
        {
          if ( v201 != v202 )
            goto LABEL_198;
          if ( *(char *)(v199 + 60) <= *(char *)(v200 + 60) )
          {
            v219 = *(_DWORD *)(v199 + 1) == *(_DWORD *)(v200 + 1)
                && *(unsigned __int16 *)(v199 + 5) == *(unsigned __int16 *)(v200 + 5);
            if ( !v219 || !*(_QWORD *)(v199 + 1824) || *(_QWORD *)(v200 + 1824) )
              goto LABEL_198;
            v200 = *(_QWORD *)(v135 + 24);
          }
        }
        if ( v200 )
        {
          v203 = *(_QWORD *)(v200 + 1320);
          if ( v203 )
            _qdf_mem_free(v203);
          v204 = *(_QWORD *)(v200 + 1896);
          if ( v204 )
            _qdf_mem_free(v204);
          _qdf_mem_free(v200);
        }
      }
      else
      {
        result = _qdf_mem_malloc(0x20u, "wlan_cm_calculate_bss_score", 3710);
        if ( !result )
          goto LABEL_116;
        v135 = result;
      }
      v205 = util_scan_copy_cache_entry(v154[3]);
      *(_QWORD *)(v135 + 24) = v205;
      if ( !v205 )
        goto LABEL_245;
    }
LABEL_198:
    if ( (unsigned int)qdf_list_remove_node((__int64)v15, v282) )
      break;
    if ( (unsigned int)(v165 - 1) > 1 )
    {
      cm_list_insert_sorted(v15, v154);
    }
    else
    {
      if ( (v166 & 1) == 0 )
      {
        v214 = v154[3];
        if ( v214 == -1 )
        {
          v217 = 0;
          v215 = 0;
          v216 = 0;
          v218 = 0;
        }
        else
        {
          v215 = *(unsigned __int8 *)(v214 + 1);
          v216 = *(unsigned __int8 *)(v214 + 2);
          v217 = *(unsigned __int8 *)(v214 + 3);
          v218 = *(unsigned __int8 *)(v214 + 6);
        }
        LODWORD(v264) = v165;
        LODWORD(v263) = *(char *)(v214 + 60);
        qdf_trace_msg(
          0x68u,
          8u,
          "Candidate( %02x:%02x:%02x:**:**:%02x freq %d): rssi %d, dlm action %d is in Denylist, remove entry",
          v206,
          v207,
          v208,
          v209,
          v210,
          v211,
          v212,
          v213,
          v215,
          v216,
          v217,
          v218,
          *(unsigned int *)(v214 + 1192),
          v263,
          v264);
      }
      v220 = v154[3];
      if ( v220 )
      {
        v221 = *(_QWORD *)(v220 + 1320);
        if ( v221 )
          _qdf_mem_free(v221);
        v222 = *(_QWORD *)(v220 + 1896);
        if ( v222 )
          _qdf_mem_free(v222);
        _qdf_mem_free(v220);
      }
      _qdf_mem_free((__int64)v154);
    }
    v133 = v281;
    v134 = v276;
    v281 = nullptr;
    v282 = v133;
    if ( !v133 )
    {
      if ( ((unsigned __int8)v136 & (v135 != 0)) == 1 )
      {
        v229 = *(_QWORD *)(v135 + 24);
        if ( v229 == -1 )
        {
          v232 = 0;
          v230 = 0;
          v231 = 0;
          v233 = 0;
        }
        else
        {
          v230 = *(unsigned __int8 *)(v229 + 1);
          v231 = *(unsigned __int8 *)(v229 + 2);
          v232 = *(unsigned __int8 *)(v229 + 3);
          v233 = *(unsigned __int8 *)(v229 + 6);
        }
        LODWORD(v263) = *(char *)(v229 + 60);
        qdf_trace_msg(
          0x68u,
          8u,
          "All candidates in denylist, Candidate( %02x:%02x:%02x:**:**:%02x freq %d): rssi %d, selected for connection",
          v138,
          v139,
          v140,
          v141,
          v142,
          v143,
          v144,
          v145,
          v230,
          v231,
          v232,
          v233,
          *(unsigned int *)(v229 + 1192),
          v263);
        cm_list_insert_sorted(v15, v135);
      }
      else if ( v135 )
      {
        util_scan_free_cache_entry(*(_QWORD *)(v135 + 24));
        _qdf_mem_free(v135);
      }
      goto LABEL_248;
    }
  }
  v224 = (unsigned __int8 *)v154[3];
  if ( v224 == (unsigned __int8 *)-1LL )
  {
    v227 = 0;
    v225 = 0;
    v226 = 0;
    v228 = 0;
  }
  else
  {
    v225 = v224[1];
    v226 = v224[2];
    v227 = v224[3];
    v228 = v224[6];
  }
  result = qdf_trace_msg(
             0x68u,
             2u,
             "%s: failed to remove node for BSS %02x:%02x:%02x:**:**:%02x from scan list",
             v206,
             v207,
             v208,
             v209,
             v210,
             v211,
             v212,
             v213,
             "wlan_cm_calculate_bss_score",
             v225,
             v226,
             v227,
             v228);
  if ( v135 )
  {
    v234 = *(_QWORD *)(v135 + 24);
    if ( v234 )
    {
      v235 = *(_QWORD *)(v234 + 1320);
      if ( v235 )
        _qdf_mem_free(v235);
      v236 = *(_QWORD *)(v234 + 1896);
      if ( v236 )
        _qdf_mem_free(v236);
      _qdf_mem_free(v234);
    }
LABEL_245:
    result = _qdf_mem_free(v135);
  }
LABEL_116:
  _ReadStatusReg(SP_EL0);
  return result;
}
