__int64 __fastcall scm_is_security_match(
        __int64 a1,
        __int64 a2,
        int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v14; // w26
  int v15; // w8
  __int64 v16; // x24
  _DWORD *v17; // x0
  int v18; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x4
  __int64 v28; // x5
  int v29; // w8
  __int64 v30; // x6
  __int64 v31; // x7
  unsigned int v32; // w1
  const char *v33; // x2
  unsigned int v34; // w24
  __int64 v35; // x0
  _DWORD *v36; // x25
  unsigned __int8 *v37; // x0
  int v38; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x2
  int v48; // w8
  int v49; // w8
  int v50; // w8
  int v51; // w8
  int v52; // w8
  int v53; // w8
  int v54; // w8
  int v55; // w8
  int v56; // w8
  int v57; // w8
  int v58; // w8
  int v59; // w8
  int v60; // w8
  int v61; // w8
  int v62; // w8
  int v63; // w8
  int v64; // w8
  int v65; // w8
  int v66; // w8
  int v67; // w8
  int v68; // w8
  int v69; // w8
  int v70; // w8
  int v71; // w8
  int v72; // w8
  int v73; // w8
  int v74; // w8
  int v75; // w8
  int v76; // w8
  int v77; // w8
  int v78; // w8
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x4
  __int64 v88; // x5
  __int64 v89; // x6
  __int64 v90; // x7
  const char *v91; // x2
  const char *v92; // x3
  int v93; // w8
  __int64 v94; // x4
  __int64 v95; // x5
  __int64 v96; // x6
  __int64 v97; // x7
  const char *v98; // x2
  __int64 v99; // x0
  int v100; // w0
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x0
  int v110; // w8
  int v111; // w9
  int v112; // w12
  int v113; // w10
  int v114; // w14
  int v115; // w15
  int v116; // w14
  _DWORD *v117; // x0
  unsigned __int8 *v118; // x1
  __int64 v119; // x21
  int v120; // w0
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  __int64 v129; // x4
  __int64 v130; // x5
  int v131; // w8
  __int64 v132; // x6
  __int64 v133; // x7
  const char *v134; // x2
  __int64 v135; // x1
  int v136; // w0
  __int16 v137; // w9
  int v138; // w8
  __int64 v139; // x1
  int v140; // w9
  int v142; // w8
  int v143; // w9
  int v144; // w10
  int v145; // w9
  int v146; // w8
  __int64 v147; // [xsp+0h] [xbp-50h]
  __int64 v148; // [xsp+8h] [xbp-48h]

  if ( !*(_DWORD *)(a1 + 40) )
  {
    v117 = (_DWORD *)_qdf_mem_malloc(0x120u, "scm_match_any_security", 481);
    if ( !v117 )
    {
      LOBYTE(v16) = 0;
      return v16 & 1;
    }
    v118 = *(unsigned __int8 **)(a2 + 1288);
    if ( v118 )
    {
      v119 = (__int64)v117;
      v120 = wlan_crypto_rsnie_check(v117, v118, nullptr);
      if ( v120 )
      {
        v129 = *(unsigned __int8 *)(a2 + 1);
        v130 = *(unsigned __int8 *)(a2 + 2);
        v131 = v120;
        v132 = *(unsigned __int8 *)(a2 + 3);
        v133 = *(unsigned __int8 *)(a2 + 6);
        v134 = "%s: %02x:%02x:%02x:**:**:%02x: failed to parse RSN IE, status %d";
LABEL_286:
        qdf_trace_msg(
          0x15u,
          2u,
          v134,
          v121,
          v122,
          v123,
          v124,
          v125,
          v126,
          v127,
          v128,
          "scm_match_any_security",
          v129,
          v130,
          v132,
          v133,
          v131);
        LOBYTE(v16) = 0;
        _qdf_mem_free(v119);
        return v16 & 1;
      }
      v117 = (_DWORD *)v119;
      a3[3] = *(_DWORD *)(v119 + 8);
      a3[2] = *(_DWORD *)(v119 + 4);
      a3[1] = *(_DWORD *)(v119 + 20);
      v137 = *(_WORD *)(v119 + 152);
      v138 = *a3 | 0x40;
      goto LABEL_281;
    }
    v135 = *(_QWORD *)(a2 + 1272);
    if ( v135 )
    {
      v119 = (__int64)v117;
      v136 = wlan_crypto_wpaie_check((__int64)v117, v135, nullptr);
      if ( !v136 )
      {
        v117 = (_DWORD *)v119;
        a3[3] = *(_DWORD *)(v119 + 8);
        a3[2] = *(_DWORD *)(v119 + 4);
        a3[1] = *(_DWORD *)(v119 + 20);
        v137 = *(_WORD *)(v119 + 152);
        v138 = *a3 | 0x20;
LABEL_281:
        *((_WORD *)a3 + 10) = v137;
LABEL_282:
        *a3 = v138;
        LOBYTE(v16) = 1;
        _qdf_mem_free((__int64)v117);
        return v16 & 1;
      }
    }
    else
    {
      v139 = *(_QWORD *)(a2 + 1384);
      if ( !v139 )
      {
        v142 = a3[2];
        v143 = a3[3];
        v144 = *a3;
        if ( (*(_WORD *)(a2 + 70) & 0x10) != 0 )
        {
          a3[2] = v142 | 1;
          v145 = v143 | 1;
          v138 = v144 | 4;
        }
        else
        {
          a3[2] = v142 | 0x20000;
          v145 = v143 | 0x20000;
          v138 = v144 | 2;
        }
        a3[3] = v145;
        goto LABEL_282;
      }
      v119 = (__int64)v117;
      v136 = wlan_crypto_wapiie_check(v117, v139);
      if ( !v136 )
      {
        v117 = (_DWORD *)v119;
        a3[3] = *(_DWORD *)(v119 + 8);
        a3[2] = *(_DWORD *)(v119 + 4);
        a3[1] = *(_DWORD *)(v119 + 20);
        v137 = *(_WORD *)(v119 + 152);
        v138 = *a3 | 0x100;
        goto LABEL_281;
      }
    }
    v129 = *(unsigned __int8 *)(a2 + 1);
    v130 = *(unsigned __int8 *)(a2 + 2);
    v131 = v136;
    v132 = *(unsigned __int8 *)(a2 + 3);
    v133 = *(unsigned __int8 *)(a2 + 6);
    v134 = "%s: %02x:%02x:%02x:**:**:%02x: failed to parse WPA IE, status %d";
    goto LABEL_286;
  }
  v14 = 0;
  do
  {
    v15 = 1 << v14;
    if ( (*(_DWORD *)(a1 + 40) & (1 << v14)) == 0 )
      goto LABEL_249;
    LOBYTE(v16) = 0;
    *a3 = v15;
    if ( (int)v14 <= 3 )
    {
      if ( v14 < 2 )
        goto LABEL_220;
      if ( v14 == 2 )
        goto LABEL_234;
      if ( v14 != 3 )
        goto LABEL_250;
    }
    else
    {
      if ( v14 > 0xA )
        goto LABEL_219;
      if ( (v15 & 0x6C0) == 0 )
      {
        if ( v14 == 5 )
        {
          if ( *(_QWORD *)(a2 + 1272) )
          {
            v99 = _qdf_mem_malloc(0x120u, "scm_check_wpa", 386);
            if ( v99 )
            {
              v36 = (_DWORD *)v99;
              v100 = wlan_crypto_wpaie_check(v99, *(_QWORD *)(a2 + 1272), nullptr);
              if ( !v100 )
              {
                LOBYTE(v16) = scm_chk_crypto_params(a1, v36, 0, a2, a3);
                goto LABEL_218;
              }
              LODWORD(v147) = v100;
              qdf_trace_msg(
                0x15u,
                2u,
                "%s: %02x:%02x:%02x:**:**:%02x: failed to parse WPA IE, status %d",
                v101,
                v102,
                v103,
                v104,
                v105,
                v106,
                v107,
                v108,
                "scm_check_wpa",
                *(unsigned __int8 *)(a2 + 1),
                *(unsigned __int8 *)(a2 + 2),
                *(unsigned __int8 *)(a2 + 3),
                *(unsigned __int8 *)(a2 + 6),
                v147);
              v109 = (__int64)v36;
              goto LABEL_269;
            }
LABEL_249:
            LOBYTE(v16) = 0;
            goto LABEL_250;
          }
          v87 = *(unsigned __int8 *)(a2 + 1);
          v88 = *(unsigned __int8 *)(a2 + 2);
          v89 = *(unsigned __int8 *)(a2 + 3);
          v90 = *(unsigned __int8 *)(a2 + 6);
          v91 = "%s: %02x:%02x:%02x:**:**:%02x : doesn't have WPA IE";
          v92 = "scm_check_wpa";
LABEL_248:
          qdf_trace_msg(0x15u, 8u, v91, a4, a5, a6, a7, a8, a9, a10, a11, v92, v87, v88, v89, v90, v147, v148);
          goto LABEL_249;
        }
        if ( v14 == 8 )
        {
          if ( *(_QWORD *)(a2 + 1384) )
          {
            v17 = (_DWORD *)_qdf_mem_malloc(0x120u, "scm_check_wapi", 428);
            v16 = (__int64)v17;
            if ( !v17 )
              goto LABEL_250;
            v18 = wlan_crypto_wapiie_check(v17, *(_QWORD *)(a2 + 1384));
            if ( v18 )
            {
              v27 = *(unsigned __int8 *)(a2 + 1);
              v28 = *(unsigned __int8 *)(a2 + 2);
              v29 = v18;
              v30 = *(unsigned __int8 *)(a2 + 3);
              v31 = *(unsigned __int8 *)(a2 + 6);
              v32 = 2;
              v33 = "%s: %02x:%02x:%02x:**:**:%02x: failed to parse WAPI IE, status %d";
              goto LABEL_268;
            }
            v112 = *(_DWORD *)(v16 + 8);
            v113 = *(_DWORD *)(a1 + 52);
            if ( (*(_DWORD *)(v16 + 4) & *(_DWORD *)(a1 + 48)) != 0 )
            {
              v29 = *(_DWORD *)(a1 + 44);
              if ( (v112 & v113) != 0 && (*(_DWORD *)(v16 + 20) & v29) != 0 )
              {
                v114 = *(_DWORD *)(a1 + 56);
                if ( !v114 || (v115 = *(_DWORD *)(v16 + 12)) == 0 || (v115 & v114) != 0 )
                {
                  if ( (*(_WORD *)a1 & 4) != 0 )
                    goto LABEL_271;
                  v116 = *(_DWORD *)(a1 + 24);
                  if ( v116 )
                  {
                    if ( v116 != 2 || (*(_WORD *)(v16 + 152) & 0x80) != 0 )
                    {
LABEL_271:
                      a3[3] = v112 & v113;
                      a3[2] = *(_DWORD *)(a1 + 48) & *(_DWORD *)(v16 + 4);
                      a3[1] = *(_DWORD *)(a1 + 44) & *(_DWORD *)(v16 + 20);
                      *((_WORD *)a3 + 10) = *(_WORD *)(v16 + 152);
                      _qdf_mem_free(v16);
LABEL_288:
                      LOBYTE(v16) = 1;
                      return v16 & 1;
                    }
                  }
                  else if ( (*(_WORD *)(v16 + 152) & 0x40) == 0 )
                  {
                    goto LABEL_271;
                  }
                }
              }
            }
            else
            {
              v29 = *(_DWORD *)(a1 + 44);
            }
            v32 = 8;
            v27 = *(unsigned __int8 *)(a2 + 1);
            v33 = "%s: %02x:%02x:%02x:**:**:%02x: fail. Self: AKM %x CIPHER: mc %x uc %x mgmt %x pmf %d AP: AKM %x CIPHER"
                  ": mc %x uc %x mgmt %x, RSN caps %x";
            v28 = *(unsigned __int8 *)(a2 + 2);
            v30 = *(unsigned __int8 *)(a2 + 3);
            v31 = *(unsigned __int8 *)(a2 + 6);
            LODWORD(v148) = *(_DWORD *)(a1 + 52);
LABEL_268:
            LODWORD(v147) = v29;
            qdf_trace_msg(
              0x15u,
              v32,
              v33,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              "scm_check_wapi",
              v27,
              v28,
              v30,
              v31,
              v147);
            v109 = v16;
LABEL_269:
            _qdf_mem_free(v109);
            goto LABEL_249;
          }
          v87 = *(unsigned __int8 *)(a2 + 1);
          v88 = *(unsigned __int8 *)(a2 + 2);
          v89 = *(unsigned __int8 *)(a2 + 3);
          v90 = *(unsigned __int8 *)(a2 + 6);
          v91 = "%s: %02x:%02x:%02x:**:**:%02x : doesn't have WAPI IE";
          v92 = "scm_check_wapi";
          goto LABEL_248;
        }
LABEL_219:
        if ( v14 != 4 )
          goto LABEL_250;
LABEL_220:
        if ( (*(_WORD *)(a2 + 70) & 0x10) != 0 )
        {
          v94 = *(unsigned __int8 *)(a2 + 1);
          v95 = *(unsigned __int8 *)(a2 + 2);
          v96 = *(unsigned __int8 *)(a2 + 3);
          v97 = *(unsigned __int8 *)(a2 + 6);
          v98 = "%s: %02x:%02x:%02x:**:**:%02x : have privacy set";
        }
        else
        {
          v93 = *(_DWORD *)(a1 + 48);
          if ( !v93 || (v93 & 0x20000) != 0 )
          {
            v93 = *(_DWORD *)(a1 + 52);
            if ( !v93 || (v93 & 0x20000) != 0 )
            {
              v140 = a3[3] | 0x20000;
              a3[2] |= 0x20000u;
              a3[3] = v140;
              goto LABEL_288;
            }
            v94 = *(unsigned __int8 *)(a2 + 1);
            v95 = *(unsigned __int8 *)(a2 + 2);
            v96 = *(unsigned __int8 *)(a2 + 3);
            v97 = *(unsigned __int8 *)(a2 + 6);
            v98 = "%s: %02x:%02x:%02x:**:**:%02x : Filter doesn't have CIPHER none in mc %x";
          }
          else
          {
            v94 = *(unsigned __int8 *)(a2 + 1);
            v95 = *(unsigned __int8 *)(a2 + 2);
            v96 = *(unsigned __int8 *)(a2 + 3);
            v97 = *(unsigned __int8 *)(a2 + 6);
            v98 = "%s: %02x:%02x:%02x:**:**:%02x : Filter doesn't have CIPHER none in uc %x";
          }
          LODWORD(v147) = v93;
        }
        qdf_trace_msg(0x15u, 8u, v98, a4, a5, a6, a7, a8, a9, a10, a11, "scm_check_open", v94, v95, v96, v97, v147);
LABEL_234:
        if ( (*(_WORD *)(a2 + 70) & 0x10) == 0 )
        {
          v87 = *(unsigned __int8 *)(a2 + 1);
          v88 = *(unsigned __int8 *)(a2 + 2);
          v89 = *(unsigned __int8 *)(a2 + 3);
          v90 = *(unsigned __int8 *)(a2 + 6);
          v91 = "%s: %02x:%02x:%02x:**:**:%02x : doesn't have privacy set";
LABEL_238:
          v92 = "scm_check_wep";
          goto LABEL_248;
        }
        if ( (*(_BYTE *)(a2 + 47) & 1) == 0 )
        {
          v87 = *(unsigned __int8 *)(a2 + 1);
          v88 = *(unsigned __int8 *)(a2 + 2);
          v89 = *(unsigned __int8 *)(a2 + 3);
          v90 = *(unsigned __int8 *)(a2 + 6);
          v91 = "%s: %02x:%02x:%02x:**:**:%02x : doesn't support WEP";
          goto LABEL_238;
        }
        v110 = *(_DWORD *)(a1 + 48);
        v111 = *(_DWORD *)(a1 + 52);
        if ( v110 && v111 )
        {
          if ( (v110 & 0x18001) != 0 )
          {
            if ( (v111 & 0x18001) == 0 )
            {
              v87 = *(unsigned __int8 *)(a2 + 1);
              v88 = *(unsigned __int8 *)(a2 + 2);
              v89 = *(unsigned __int8 *)(a2 + 3);
              v90 = *(unsigned __int8 *)(a2 + 6);
              v91 = "%s: %02x:%02x:%02x:**:**:%02x : Filter doesn't have WEP cipher in mc %x";
              v92 = "scm_check_wep";
              LODWORD(v147) = *(_DWORD *)(a1 + 52);
              goto LABEL_248;
            }
            if ( (v110 & 1) != 0 )
            {
              a3[2] |= 1u;
              v110 = *(_DWORD *)(a1 + 48);
              if ( (v110 & 0x8000) != 0 )
                goto LABEL_303;
LABEL_294:
              if ( (v110 & 0x10000) == 0 )
                goto LABEL_295;
LABEL_304:
              a3[2] |= 0x10000u;
              v146 = *(_DWORD *)(a1 + 52);
              if ( (v146 & 1) != 0 )
                goto LABEL_305;
LABEL_296:
              if ( (v146 & 0x8000) == 0 )
                goto LABEL_297;
LABEL_306:
              a3[3] |= 0x8000u;
              if ( (*(_DWORD *)(a1 + 52) & 0x10000) == 0 )
                goto LABEL_288;
            }
            else
            {
              if ( (v110 & 0x8000) == 0 )
                goto LABEL_294;
LABEL_303:
              a3[2] |= 0x8000u;
              if ( (*(_DWORD *)(a1 + 48) & 0x10000) != 0 )
                goto LABEL_304;
LABEL_295:
              v146 = *(_DWORD *)(a1 + 52);
              if ( (v146 & 1) == 0 )
                goto LABEL_296;
LABEL_305:
              a3[3] |= 1u;
              v146 = *(_DWORD *)(a1 + 52);
              if ( (v146 & 0x8000) != 0 )
                goto LABEL_306;
LABEL_297:
              if ( (v146 & 0x10000) == 0 )
                goto LABEL_288;
            }
            a3[3] |= 0x10000u;
            goto LABEL_288;
          }
          v87 = *(unsigned __int8 *)(a2 + 1);
          v88 = *(unsigned __int8 *)(a2 + 2);
          v89 = *(unsigned __int8 *)(a2 + 3);
          v90 = *(unsigned __int8 *)(a2 + 6);
          v91 = "%s: %02x:%02x:%02x:**:**:%02x : Filter doesn't have WEP cipher in uc %x";
        }
        else
        {
          v87 = *(unsigned __int8 *)(a2 + 1);
          v88 = *(unsigned __int8 *)(a2 + 2);
          v89 = *(unsigned __int8 *)(a2 + 3);
          v90 = *(unsigned __int8 *)(a2 + 6);
          LODWORD(v148) = *(_DWORD *)(a1 + 52);
          v91 = "%s: %02x:%02x:%02x:**:**:%02x : Filter uc %x or mc %x cipher are 0";
        }
        v92 = "scm_check_wep";
        LODWORD(v147) = *(_DWORD *)(a1 + 48);
        goto LABEL_248;
      }
    }
    v34 = *(unsigned __int8 *)(a1 + 712);
    if ( !util_scan_entry_rsn_by_gen(a2, 1) )
    {
      v87 = *(unsigned __int8 *)(a2 + 1);
      v88 = *(unsigned __int8 *)(a2 + 2);
      v89 = *(unsigned __int8 *)(a2 + 3);
      v90 = *(unsigned __int8 *)(a2 + 6);
      v91 = "%s: %02x:%02x:%02x:**:**:%02x : doesn't have RSN IE";
      v92 = "scm_check_rsn";
      goto LABEL_248;
    }
    v35 = _qdf_mem_malloc(0x120u, "scm_check_rsn", 308);
    if ( !v35 )
      goto LABEL_249;
    v36 = (_DWORD *)v35;
    if ( v34 - 4 <= 0xFFFFFFFC )
    {
      qdf_trace_msg(0x15u, 8u, "%s: Invalid mrsn gen %d", a4, a5, a6, a7, a8, a9, a10, a11, "scm_check_rsn", v34);
      v34 = 1;
    }
    while ( 1 )
    {
      qdf_mem_set(v36, 0x120u, 0);
      v37 = (unsigned __int8 *)util_scan_entry_rsn_by_gen(a2, v34);
      if ( !v37 )
        goto LABEL_21;
      v38 = wlan_crypto_rsnie_check(v36, v37, nullptr);
      if ( !v38 )
        break;
      LODWORD(v148) = v38;
      LODWORD(v147) = v34;
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: %02x:%02x:%02x:**:**:%02x: failed to parse RSN IE gen %d, status %d",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "scm_check_rsn",
        *(unsigned __int8 *)(a2 + 1),
        *(unsigned __int8 *)(a2 + 2),
        *(unsigned __int8 *)(a2 + 3),
        *(unsigned __int8 *)(a2 + 6),
        v147,
        v148);
LABEL_21:
      if ( !(_BYTE)--v34 )
      {
        LOBYTE(v16) = 0;
        goto LABEL_218;
      }
    }
    if ( *(_BYTE *)(a2 + 86) != 1 || (*(_WORD *)a1 & 1) == 0 )
    {
      v47 = 0;
      goto LABEL_212;
    }
    v48 = v36[40];
    if ( v48 > 6 )
    {
      if ( v48 == 7 )
        goto LABEL_209;
      if ( v48 != 8 )
        goto LABEL_34;
LABEL_33:
      v49 = v36[5] | 0x40;
LABEL_210:
      v36[5] = v49;
      goto LABEL_211;
    }
    if ( !v48 )
      goto LABEL_209;
    if ( v48 == 1 )
      goto LABEL_33;
LABEL_34:
    v50 = v36[41];
    if ( v50 > 6 )
    {
      if ( v50 == 7 )
        goto LABEL_209;
      if ( v50 != 8 )
        goto LABEL_40;
      goto LABEL_33;
    }
    if ( !v50 )
      goto LABEL_209;
    if ( v50 == 1 )
      goto LABEL_33;
LABEL_40:
    v51 = v36[42];
    if ( v51 > 6 )
    {
      if ( v51 == 7 )
        goto LABEL_209;
      if ( v51 != 8 )
        goto LABEL_46;
      goto LABEL_33;
    }
    if ( !v51 )
      goto LABEL_209;
    if ( v51 == 1 )
      goto LABEL_33;
LABEL_46:
    v52 = v36[43];
    if ( v52 > 6 )
    {
      if ( v52 == 7 )
        goto LABEL_209;
      if ( v52 != 8 )
        goto LABEL_52;
      goto LABEL_33;
    }
    if ( !v52 )
      goto LABEL_209;
    if ( v52 == 1 )
      goto LABEL_33;
LABEL_52:
    v53 = v36[44];
    if ( v53 > 6 )
    {
      if ( v53 == 7 )
        goto LABEL_209;
      if ( v53 != 8 )
        goto LABEL_58;
      goto LABEL_33;
    }
    if ( !v53 )
      goto LABEL_209;
    if ( v53 == 1 )
      goto LABEL_33;
LABEL_58:
    v54 = v36[45];
    if ( v54 > 6 )
    {
      if ( v54 == 7 )
        goto LABEL_209;
      if ( v54 != 8 )
        goto LABEL_64;
      goto LABEL_33;
    }
    if ( !v54 )
      goto LABEL_209;
    if ( v54 == 1 )
      goto LABEL_33;
LABEL_64:
    v55 = v36[46];
    if ( v55 > 6 )
    {
      if ( v55 == 7 )
        goto LABEL_209;
      if ( v55 != 8 )
        goto LABEL_70;
      goto LABEL_33;
    }
    if ( !v55 )
      goto LABEL_209;
    if ( v55 == 1 )
      goto LABEL_33;
LABEL_70:
    v56 = v36[47];
    if ( v56 > 6 )
    {
      if ( v56 == 7 )
        goto LABEL_209;
      if ( v56 != 8 )
        goto LABEL_76;
      goto LABEL_33;
    }
    if ( !v56 )
      goto LABEL_209;
    if ( v56 == 1 )
      goto LABEL_33;
LABEL_76:
    v57 = v36[48];
    if ( v57 > 6 )
    {
      if ( v57 == 7 )
        goto LABEL_209;
      if ( v57 != 8 )
        goto LABEL_82;
      goto LABEL_33;
    }
    if ( !v57 )
      goto LABEL_209;
    if ( v57 == 1 )
      goto LABEL_33;
LABEL_82:
    v58 = v36[49];
    if ( v58 > 6 )
    {
      if ( v58 == 7 )
        goto LABEL_209;
      if ( v58 != 8 )
        goto LABEL_88;
      goto LABEL_33;
    }
    if ( !v58 )
      goto LABEL_209;
    if ( v58 == 1 )
      goto LABEL_33;
LABEL_88:
    v59 = v36[50];
    if ( v59 > 6 )
    {
      if ( v59 == 7 )
        goto LABEL_209;
      if ( v59 != 8 )
        goto LABEL_94;
      goto LABEL_33;
    }
    if ( !v59 )
      goto LABEL_209;
    if ( v59 == 1 )
      goto LABEL_33;
LABEL_94:
    v60 = v36[51];
    if ( v60 > 6 )
    {
      if ( v60 == 7 )
        goto LABEL_209;
      if ( v60 != 8 )
        goto LABEL_100;
      goto LABEL_33;
    }
    if ( !v60 )
      goto LABEL_209;
    if ( v60 == 1 )
      goto LABEL_33;
LABEL_100:
    v61 = v36[52];
    if ( v61 > 6 )
    {
      if ( v61 == 7 )
        goto LABEL_209;
      if ( v61 != 8 )
        goto LABEL_106;
      goto LABEL_33;
    }
    if ( !v61 )
      goto LABEL_209;
    if ( v61 == 1 )
      goto LABEL_33;
LABEL_106:
    v62 = v36[53];
    if ( v62 > 6 )
    {
      if ( v62 == 7 )
        goto LABEL_209;
      if ( v62 != 8 )
        goto LABEL_112;
      goto LABEL_33;
    }
    if ( !v62 )
      goto LABEL_209;
    if ( v62 == 1 )
      goto LABEL_33;
LABEL_112:
    v63 = v36[54];
    if ( v63 > 6 )
    {
      if ( v63 == 7 )
        goto LABEL_209;
      if ( v63 != 8 )
        goto LABEL_118;
      goto LABEL_33;
    }
    if ( !v63 )
      goto LABEL_209;
    if ( v63 == 1 )
      goto LABEL_33;
LABEL_118:
    v64 = v36[55];
    if ( v64 > 6 )
    {
      if ( v64 == 7 )
        goto LABEL_209;
      if ( v64 != 8 )
        goto LABEL_124;
      goto LABEL_33;
    }
    if ( !v64 )
      goto LABEL_209;
    if ( v64 == 1 )
      goto LABEL_33;
LABEL_124:
    v65 = v36[56];
    if ( v65 > 6 )
    {
      if ( v65 == 7 )
        goto LABEL_209;
      if ( v65 != 8 )
        goto LABEL_130;
      goto LABEL_33;
    }
    if ( !v65 )
      goto LABEL_209;
    if ( v65 == 1 )
      goto LABEL_33;
LABEL_130:
    v66 = v36[57];
    if ( v66 > 6 )
    {
      if ( v66 == 7 )
        goto LABEL_209;
      if ( v66 != 8 )
        goto LABEL_136;
      goto LABEL_33;
    }
    if ( !v66 )
      goto LABEL_209;
    if ( v66 == 1 )
      goto LABEL_33;
LABEL_136:
    v67 = v36[58];
    if ( v67 > 6 )
    {
      if ( v67 == 7 )
        goto LABEL_209;
      if ( v67 != 8 )
        goto LABEL_142;
      goto LABEL_33;
    }
    if ( !v67 )
      goto LABEL_209;
    if ( v67 == 1 )
      goto LABEL_33;
LABEL_142:
    v68 = v36[59];
    if ( v68 > 6 )
    {
      if ( v68 == 7 )
        goto LABEL_209;
      if ( v68 != 8 )
        goto LABEL_148;
      goto LABEL_33;
    }
    if ( !v68 )
      goto LABEL_209;
    if ( v68 == 1 )
      goto LABEL_33;
LABEL_148:
    v69 = v36[60];
    if ( v69 > 6 )
    {
      if ( v69 == 7 )
        goto LABEL_209;
      if ( v69 != 8 )
        goto LABEL_154;
      goto LABEL_33;
    }
    if ( !v69 )
      goto LABEL_209;
    if ( v69 == 1 )
      goto LABEL_33;
LABEL_154:
    v70 = v36[61];
    if ( v70 > 6 )
    {
      if ( v70 == 7 )
        goto LABEL_209;
      if ( v70 != 8 )
        goto LABEL_160;
      goto LABEL_33;
    }
    if ( !v70 )
      goto LABEL_209;
    if ( v70 == 1 )
      goto LABEL_33;
LABEL_160:
    v71 = v36[62];
    if ( v71 > 6 )
    {
      if ( v71 == 7 )
        goto LABEL_209;
      if ( v71 != 8 )
        goto LABEL_166;
      goto LABEL_33;
    }
    if ( !v71 )
      goto LABEL_209;
    if ( v71 == 1 )
      goto LABEL_33;
LABEL_166:
    v72 = v36[63];
    if ( v72 > 6 )
    {
      if ( v72 == 7 )
        goto LABEL_209;
      if ( v72 != 8 )
        goto LABEL_172;
      goto LABEL_33;
    }
    if ( !v72 )
      goto LABEL_209;
    if ( v72 == 1 )
      goto LABEL_33;
LABEL_172:
    v73 = v36[64];
    if ( v73 > 6 )
    {
      if ( v73 == 7 )
        goto LABEL_209;
      if ( v73 != 8 )
        goto LABEL_178;
      goto LABEL_33;
    }
    if ( !v73 )
      goto LABEL_209;
    if ( v73 == 1 )
      goto LABEL_33;
LABEL_178:
    v74 = v36[65];
    if ( v74 > 6 )
    {
      if ( v74 == 7 )
        goto LABEL_209;
      if ( v74 != 8 )
        goto LABEL_184;
      goto LABEL_33;
    }
    if ( !v74 )
      goto LABEL_209;
    if ( v74 == 1 )
      goto LABEL_33;
LABEL_184:
    v75 = v36[66];
    if ( v75 > 6 )
    {
      if ( v75 == 7 )
        goto LABEL_209;
      if ( v75 != 8 )
        goto LABEL_190;
      goto LABEL_33;
    }
    if ( !v75 )
      goto LABEL_209;
    if ( v75 == 1 )
      goto LABEL_33;
LABEL_190:
    v76 = v36[67];
    if ( v76 > 6 )
    {
      if ( v76 == 7 )
        goto LABEL_209;
      if ( v76 != 8 )
        goto LABEL_196;
      goto LABEL_33;
    }
    if ( !v76 )
      goto LABEL_209;
    if ( v76 == 1 )
      goto LABEL_33;
LABEL_196:
    v77 = v36[68];
    if ( v77 > 6 )
    {
      if ( v77 == 7 )
        goto LABEL_209;
      if ( v77 != 8 )
        goto LABEL_202;
      goto LABEL_33;
    }
    if ( !v77 )
      goto LABEL_209;
    if ( v77 == 1 )
      goto LABEL_33;
LABEL_202:
    v78 = v36[69];
    if ( v78 > 6 )
    {
      if ( v78 != 7 )
      {
        if ( v78 != 8 )
          goto LABEL_208;
        goto LABEL_33;
      }
LABEL_209:
      v49 = v36[5] | 0x20;
      goto LABEL_210;
    }
    if ( !v78 )
      goto LABEL_209;
    if ( v78 == 1 )
      goto LABEL_33;
LABEL_208:
    qdf_trace_msg(
      0x15u,
      8u,
      "%s: No adaptive 11r's AKM present in RSN IE",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "scm_check_and_update_adaptive_11r_key_mgmt_support");
LABEL_211:
    v47 = 1;
LABEL_212:
    if ( (scm_chk_crypto_params(a1, v36, v47, a2, a3) & 1) == 0 )
      goto LABEL_21;
    *((_BYTE *)a3 + 22) = v34;
    if ( (unsigned __int8)v34 >= 2u )
    {
      LODWORD(v147) = v34;
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: %02x:%02x:%02x:**:**:%02x RSN gen selected %d",
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        "scm_check_rsn",
        *(unsigned __int8 *)(a2 + 1),
        *(unsigned __int8 *)(a2 + 2),
        *(unsigned __int8 *)(a2 + 3),
        *(unsigned __int8 *)(a2 + 6),
        v147);
    }
    LOBYTE(v16) = 1;
LABEL_218:
    _qdf_mem_free((__int64)v36);
LABEL_250:
    if ( v14 > 9 )
      break;
    ++v14;
  }
  while ( (v16 & 1) == 0 );
  return v16 & 1;
}
