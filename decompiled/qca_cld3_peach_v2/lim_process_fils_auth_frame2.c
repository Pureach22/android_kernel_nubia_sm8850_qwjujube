__int64 __fastcall lim_process_fils_auth_frame2(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x4
  const char *v16; // x2
  const char *v17; // x3
  __int64 result; // x0
  __int64 v19; // x24
  int v20; // w0
  __int64 v21; // x4
  int v22; // w0
  int v23; // w0
  int v24; // w0
  int v25; // w0
  unsigned int v26; // w22
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w5
  unsigned int v36; // w4
  __int64 v37; // x26
  unsigned int param; // w0
  unsigned int encrypt_ed_type; // w0
  const char *v40; // x2
  const char *v41; // x3
  int v42; // w8
  unsigned __int8 v43; // w27
  unsigned int v44; // w23
  unsigned __int8 v45; // w28
  int v46; // w10
  int v47; // w8
  unsigned int v48; // w22
  void *v49; // x0
  __int64 v50; // x21
  const void *v51; // x1
  __int64 v52; // x10
  __int64 v53; // x20
  const char *v54; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  char *v63; // x24
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned __int8 *v72; // x22
  unsigned int v73; // w27
  __int64 v74; // x26
  int v75; // w9
  __int64 v76; // x23
  unsigned int v77; // w25
  int v78; // w8
  unsigned int v79; // w24
  unsigned int v80; // w20
  _BYTE *v81; // x0
  void *v82; // x21
  _BYTE *v83; // x28
  _BYTE *v84; // x27
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  const char *v93; // x0
  unsigned __int8 *v94; // x25
  __int64 v95; // x28
  unsigned int v96; // w21
  unsigned __int8 *v97; // x27
  unsigned int v98; // w4
  __int64 v99; // x8
  unsigned int v100; // w8
  void *v101; // x0
  void *v102; // x0
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  const char *v111; // x0
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  int fils_pmkr1_name; // w8
  _BYTE *v121; // x20
  int v122; // w8
  const void *v123; // x1
  const char *v124; // x0
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  const char *v133; // x9
  __int64 v134; // x8
  __int64 v135; // x9
  bool v138; // w8
  char v139; // w8
  unsigned __int8 *v140; // x23
  unsigned int v141; // w22
  const void *v142; // x23
  unsigned int v143; // t1
  char v144; // w8
  unsigned __int8 v145; // w26
  __int64 v146; // x21
  size_t v147; // x0
  __int64 v148; // x0
  int v149; // w5
  __int64 v150; // x0
  unsigned int v151; // w6
  unsigned int v152; // w8
  __int64 v153; // x21
  __int64 v154; // x0
  unsigned int v155; // w8
  __int64 v156; // x0
  unsigned int v157; // w9
  char v158; // w10
  char *v159; // x0
  __int64 v160; // x21
  char v161; // w8
  const char *v162; // x0
  _BYTE *v163; // [xsp+8h] [xbp-1B8h]
  unsigned int v165; // [xsp+20h] [xbp-1A0h] BYREF
  unsigned int v166; // [xsp+24h] [xbp-19Ch] BYREF
  _QWORD v167[9]; // [xsp+28h] [xbp-198h] BYREF
  _QWORD v168[2]; // [xsp+70h] [xbp-150h] BYREF
  _QWORD v169[2]; // [xsp+80h] [xbp-140h] BYREF
  _QWORD v170[2]; // [xsp+90h] [xbp-130h] BYREF
  _QWORD v171[2]; // [xsp+A0h] [xbp-120h] BYREF
  __int64 v172; // [xsp+B0h] [xbp-110h] BYREF
  __int16 v173; // [xsp+B8h] [xbp-108h]
  __int64 v174; // [xsp+C0h] [xbp-100h] BYREF
  unsigned int v175[8]; // [xsp+C8h] [xbp-F8h] BYREF
  __int64 v176; // [xsp+E8h] [xbp-D8h] BYREF
  char s[48]; // [xsp+F0h] [xbp-D0h] BYREF
  __int64 v178; // [xsp+120h] [xbp-A0h]
  __int64 v179; // [xsp+128h] [xbp-98h]
  __int64 v180; // [xsp+130h] [xbp-90h]
  __int64 v181; // [xsp+138h] [xbp-88h]
  __int64 v182; // [xsp+140h] [xbp-80h]
  __int64 v183; // [xsp+148h] [xbp-78h]
  __int64 v184; // [xsp+150h] [xbp-70h]
  __int64 v185; // [xsp+158h] [xbp-68h]
  __int64 v186; // [xsp+160h] [xbp-60h]
  __int64 v187; // [xsp+168h] [xbp-58h]
  __int64 v188; // [xsp+170h] [xbp-50h]
  __int64 v189; // [xsp+178h] [xbp-48h]
  __int64 v190; // [xsp+180h] [xbp-40h]
  __int64 v191; // [xsp+188h] [xbp-38h]
  __int64 v192; // [xsp+190h] [xbp-30h]
  __int64 v193; // [xsp+198h] [xbp-28h]
  __int64 v194; // [xsp+1A0h] [xbp-20h]
  __int64 v195; // [xsp+1A8h] [xbp-18h]
  __int64 v196; // [xsp+1B0h] [xbp-10h]

  v196 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 9976);
  v173 = 0;
  v171[1] = 0;
  v172 = 0;
  v170[1] = 0;
  v171[0] = 0;
  v169[1] = 0;
  v170[0] = 0;
  v168[1] = 0;
  v169[0] = 0;
  v168[0] = 0;
  memset(v167, 0, sizeof(v167));
  if ( !v3 || *(_WORD *)a3 != 4 )
    goto LABEL_6;
  v6 = dot11f_unpack_ie_rsn(a1, (char *)(a3 + 262), *(_BYTE *)(a3 + 261), v167);
  if ( v6 )
  {
    v15 = v6;
    v16 = "%s: unpack failed, ret: %d";
    v17 = "lim_process_fils_auth_frame2";
    goto LABEL_5;
  }
  v19 = *(_QWORD *)(a2 + 9976);
  if ( *(_BYTE *)(a2 + 7041) == 1 )
  {
    if ( v19 )
    {
      memcpy((void *)(v19 + 354), (const void *)(a3 + 517), 0xDAu);
      v19 = *(_QWORD *)(a2 + 9976);
      if ( (*(_BYTE *)(v19 + 354) & 1) == 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: FT-FILS: NO FTIE in auth response",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "lim_process_fils_auth_frame2");
        v19 = *(_QWORD *)(a2 + 9976);
      }
    }
  }
  if ( WORD1(v168[0]) )
  {
    v20 = qdf_mem_cmp((char *)v168 + 4, (const void *)(v19 + 697), 0x10u);
    v21 = WORD1(v168[0]);
    if ( !v20 )
      goto LABEL_28;
    v19 = *(_QWORD *)(a2 + 9976);
    if ( WORD1(v168[0]) < 2u )
      goto LABEL_24;
    v22 = qdf_mem_cmp((char *)v169 + 4, (const void *)(v19 + 697), 0x10u);
    v21 = WORD1(v168[0]);
    if ( !v22 )
      goto LABEL_28;
    v19 = *(_QWORD *)(a2 + 9976);
    if ( WORD1(v168[0]) < 3u )
      goto LABEL_24;
    v23 = qdf_mem_cmp((char *)v170 + 4, (const void *)(v19 + 697), 0x10u);
    v21 = WORD1(v168[0]);
    if ( !v23 )
      goto LABEL_28;
    v19 = *(_QWORD *)(a2 + 9976);
    if ( WORD1(v168[0]) < 4u )
      goto LABEL_24;
    v24 = qdf_mem_cmp((char *)v171 + 4, (const void *)(v19 + 697), 0x10u);
    v21 = WORD1(v168[0]);
    if ( !v24 )
      goto LABEL_28;
    v19 = *(_QWORD *)(a2 + 9976);
    if ( WORD1(v168[0]) < 5u )
      goto LABEL_24;
    v25 = qdf_mem_cmp((char *)&v172 + 4, (const void *)(v19 + 697), 0x10u);
    v21 = WORD1(v168[0]);
    if ( !v25 )
    {
LABEL_28:
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: pmkid match in rsn ie total_count %d",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "lim_process_fils_auth_frame2",
        v21);
LABEL_29:
      v37 = *(_QWORD *)(a2 + 9976);
      v194 = 0;
      v195 = 0;
      v192 = 0;
      v193 = 0;
      v190 = 0;
      v191 = 0;
      strcpy((char *)v175, "FILS PTK Derivation");
      v188 = 0;
      v189 = 0;
      v186 = 0;
      v187 = 0;
      v184 = 0;
      v185 = 0;
      v182 = 0;
      v183 = 0;
      v180 = 0;
      v181 = 0;
      v178 = 0;
      v179 = 0;
      memset(s, 0, sizeof(s));
      if ( v37 )
      {
        if ( *(_DWORD *)(a2 + 88) == 1 )
        {
          param = wlan_crypto_get_param(*(_QWORD *)(a2 + 16), 1u);
          encrypt_ed_type = lim_get_encrypt_ed_type(param);
        }
        else
        {
          encrypt_ed_type = *(_DWORD *)(a2 + 424);
        }
        v42 = *(unsigned __int8 *)(v37 + 17);
        if ( encrypt_ed_type >= 7 )
          v43 = 0;
        else
          v43 = 0x20001020000000uLL >> (8 * (unsigned __int8)encrypt_ed_type);
        if ( (((_BYTE)v42 - 19) & 0xFD) != 0 )
          v44 = 32;
        else
          v44 = 48;
        if ( (((_BYTE)v42 - 18) & 0xFC) != 0 )
          v45 = 32;
        else
          v45 = 0x40204020u >> (8 * (v42 - 18));
        if ( v42 == 21 )
          v46 = 48;
        else
          v46 = 0;
        if ( v42 == 20 )
          v47 = 32;
        else
          v47 = v46;
        if ( *(_BYTE *)(a2 + 7041) )
          v48 = v47;
        else
          v48 = 0;
        v49 = (void *)_qdf_mem_malloc(0x2Cu, "lim_get_keys", 633);
        if ( v49 )
        {
          v50 = (__int64)v49;
          if ( *(_DWORD *)(a2 + 88) == 1 )
            v51 = nullptr;
          else
            v51 = (const void *)(a2 + 30);
          qdf_mem_copy(v49, v51, 6u);
          qdf_mem_copy((void *)(v50 + 6), (const void *)(a2 + 24), 6u);
          if ( *(_DWORD *)(a2 + 88) == 1 )
            v52 = 758;
          else
            v52 = 78;
          if ( *(_DWORD *)(a2 + 88) == 1 )
            v53 = 78;
          else
            v53 = 758;
          qdf_mem_copy((void *)(v50 + 12), (const void *)(v37 + v52), 0x10u);
          qdf_mem_copy((void *)(v50 + 28), (const void *)(v37 + v53), 0x10u);
          if ( ((*(_BYTE *)(v37 + 17) - 19) & 0xFD) != 0 )
            v54 = "hmac(sha256)";
          else
            v54 = "hmac(sha384)";
          if ( (unsigned int)lim_get_key_from_prf(
                               v54,
                               *(_QWORD *)(v37 + 688),
                               *(unsigned __int8 *)(v37 + 696),
                               v175,
                               v50,
                               44,
                               s,
                               (unsigned __int8)(v43 + v44 + v48 + v45)) )
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: failed to generate keydata",
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              "lim_generate_key_data");
          qdf_mem_copy((void *)(v37 + 776), s, v44);
          v63 = &s[v44];
          *(_BYTE *)(v37 + 824) = v44;
          qdf_mem_copy((void *)(v37 + 825), v63, v45 & 0x60);
          *(_BYTE *)(v37 + 889) = v45;
          qdf_mem_copy((void *)(v37 + 890), &v63[v45], v43 & 0x30);
          *(_BYTE *)(v37 + 922) = v43;
          if ( *(_BYTE *)(a2 + 7041) == 1 )
          {
            if ( v48 )
            {
              qdf_mem_copy((void *)(v37 + 923), &v63[v45 + v43], v48);
              *(_BYTE *)(v37 + 971) = v48;
              if ( (unsigned int)wlan_cm_update_fils_ft(
                                   *(_QWORD *)(a1 + 21624),
                                   *(unsigned __int8 *)(a2 + 10),
                                   (const void *)(v37 + 923),
                                   v48) )
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: Failed to update FILS FT to mlme",
                  v64,
                  v65,
                  v66,
                  v67,
                  v68,
                  v69,
                  v70,
                  v71,
                  "lim_get_keys");
            }
          }
          qdf_mem_set((void *)v50, 0x2Cu, 0);
          _qdf_mem_free(v50);
        }
      }
      else
      {
        qdf_trace_msg(0x35u, 2u, "%s: Failed to get fils_info", v7, v8, v9, v10, v11, v12, v13, v14, "lim_get_keys");
      }
      if ( *(_BYTE *)(a2 + 7041) == 1 )
      {
        v72 = *(unsigned __int8 **)(a2 + 9976);
        strcpy((char *)&v176, "FT-R0");
        if ( !v72 )
          goto LABEL_6;
        v73 = *(unsigned __int8 *)(a2 + 36);
        v74 = v72[442];
        v75 = v72[17];
        v76 = *(_QWORD *)(a2 + 112);
        v77 = (unsigned __int8)(v73 + v74 + 10);
        v78 = v75 == 21 ? 48 : 0;
        *(_QWORD *)s = 0;
        *(_QWORD *)&s[8] = 0;
        v79 = v75 == 20 ? 32 : v78;
        *(_QWORD *)v175 = 0;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: FT-FILS: ssid_length:%d MDID len:%d R0KH len:%d key_data len:%d",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "lim_generate_fils_pmkr0",
          v73,
          2,
          (unsigned int)v74,
          (unsigned __int8)(v73 + v74 + 10));
        v80 = v77 + 112;
        v81 = (_BYTE *)_qdf_mem_malloc(v77 + 112, "lim_generate_fils_pmkr0", 1503);
        if ( !v81 )
          goto LABEL_6;
        v82 = v81;
        *v81 = *(_BYTE *)(a2 + 36);
        v83 = v81 + 1;
        v163 = &v81[(unsigned __int8)(v73 + v74 + 10)];
        qdf_mem_copy(v81 + 1, (const void *)(a2 + 37), v73);
        v84 = &v83[v73];
        qdf_mem_copy(v84, (const void *)(v76 + 4593), 2u);
        v84[2] = v74;
        v84 += 3;
        qdf_mem_copy(v84, v72 + 443, (unsigned int)v74);
        qdf_mem_copy(&v84[v74], (const void *)(a2 + 30), 6u);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: FT-FILS: Derive R0-Key-Data",
          v85,
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          "lim_generate_fils_pmkr0");
        if ( ((v72[17] - 19) & 0xFD) != 0 )
          v93 = "hmac(sha256)";
        else
          v93 = "hmac(sha384)";
        if ( (unsigned int)lim_get_key_from_prf(v93, v72 + 923, v72[971], &v176, v82, v77, v163, v79 + 16) )
        {
LABEL_86:
          qdf_mem_set(v82, v80, 0);
          _qdf_mem_free((__int64)v82);
          goto LABEL_6;
        }
        qdf_mem_copy(v72 + 572, v163, v79);
        *(_QWORD *)v175 = 0x1000000006LL;
        v72[620] = v79;
        *(_QWORD *)s = "FT-R0N";
        *(_QWORD *)&s[8] = &v163[v79];
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: FT-FILS: Derive PMK-R0 Name",
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          v109,
          v110,
          "lim_generate_fils_pmkr0");
        if ( ((v72[17] - 19) & 0xFD) != 0 )
          v111 = "sha256";
        else
          v111 = "sha384";
        if ( (qdf_get_hash((__int64)v111, 2u, (__int64)s, v175) & 0x80000000) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: FT-FILS: PMK-R0Name derivation failed",
            v112,
            v113,
            v114,
            v115,
            v116,
            v117,
            v118,
            v119,
            "lim_generate_fils_pmkr0");
          goto LABEL_86;
        }
        qdf_mem_copy(v72 + 621, v163 + 64, 0x10u);
        qdf_mem_set(v82, v80, 0);
        _qdf_mem_free((__int64)v82);
        fils_pmkr1_name = lim_generate_fils_pmkr1_name(a1, a2);
        result = 0;
        if ( fils_pmkr1_name )
          goto LABEL_7;
      }
      v121 = *(_BYTE **)(a2 + 9976);
      memset(s, 0, 44);
      if ( v121 )
      {
        v122 = *(_DWORD *)(a2 + 88);
        LODWORD(v176) = 44;
        *(_QWORD *)v175 = s;
        if ( v122 == 1 )
        {
          qdf_mem_copy(s, v121 + 758, 0x10u);
          qdf_mem_copy(&s[16], v121 + 78, 0x10u);
          v123 = nullptr;
        }
        else
        {
          qdf_mem_copy(s, v121 + 78, 0x10u);
          qdf_mem_copy(&s[16], v121 + 758, 0x10u);
          v123 = (const void *)(a2 + 30);
        }
        qdf_mem_copy(&s[32], v123, 6u);
        qdf_mem_copy(&s[38], (const void *)(a2 + 24), 6u);
        if ( ((v121[17] - 19) & 0xFD) != 0 )
          v124 = "hmac(sha256)";
        else
          v124 = "hmac(sha384)";
        if ( (qdf_get_hmac_hash(
                (__int64)v124,
                (__int64)(v121 + 776),
                (unsigned __int8)v121[824],
                1u,
                (__int64)v175,
                (unsigned int *)&v176)
            & 0x80000000) != 0 )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: failed to generate key auth",
            v125,
            v126,
            v127,
            v128,
            v129,
            v130,
            v131,
            v132,
            "lim_generate_key_auth");
        if ( ((v121[17] - 19) & 0xFD) != 0 )
          v133 = "hmac(sha256)";
        else
          v133 = "hmac(sha384)";
        v134 = *(_QWORD *)v133;
        v135 = *(_QWORD *)(v133 + 5);
        if ( v134 == 0x6168732863616D68LL && v135 == 0x29343833616873LL )
        {
          v139 = 48;
        }
        else
        {
          v138 = v134 == 0x6168732863616D68LL && v135 == 0x29363532616873LL;
          v139 = 32 * v138;
        }
        v121[1020] = v139;
        result = (unsigned int)lim_generate_ap_key_auth(a2) == 0;
        goto LABEL_7;
      }
      v40 = "%s: Failed to get fils_info";
      v41 = "lim_generate_key_auth";
LABEL_114:
      qdf_trace_msg(0x35u, 2u, v40, v27, v28, v29, v30, v31, v32, v33, v34, v41);
      goto LABEL_6;
    }
    if ( WORD1(v168[0]) > 5u )
    {
      __break(0x5512u);
      return ((__int64 (*)(void))lim_generate_fils_pmkr1_name)();
    }
    v19 = *(_QWORD *)(a2 + 9976);
  }
LABEL_24:
  v26 = *(unsigned __int8 *)(a3 + 744);
  memset(v175, 0, sizeof(v175));
  v174 = a3 + 745;
  v165 = v26;
  if ( !v19 )
    goto LABEL_6;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: trying to process the wrappped data",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "lim_process_auth_wrapped_data");
  if ( (*(_BYTE *)(a3 + 750) & 0x80) != 0 )
  {
    v40 = "%s: R bit is set in flag, error";
    v41 = "lim_process_auth_wrapped_data";
    goto LABEL_114;
  }
  v35 = *(unsigned __int16 *)(v19 + 68);
  v36 = __rev16(*(unsigned __int16 *)(a3 + 751));
  *(_WORD *)(v19 + 756) = v36;
  if ( v36 < v35 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: sequence EAP-finish:%d is less than EAP-init:%d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "lim_process_auth_wrapped_data");
    goto LABEL_6;
  }
  v94 = (unsigned __int8 *)(a3 + 753);
  if ( v26 - 8 < 0x12 )
  {
    v96 = v26 - 8;
    goto LABEL_139;
  }
  v95 = *(_QWORD *)(a2 + 9976);
  v96 = v26 - 8;
  v97 = v94;
  while ( 1 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: tlv type %x len %u total %u",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "lim_process_fils_eap_tlv",
      *v97,
      v97[1],
      v96);
    v98 = v97[1];
    if ( v96 - 2 < v98 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: tlv len %d greater data_len %d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "lim_process_fils_eap_tlv");
LABEL_138:
      v96 = 0;
      goto LABEL_139;
    }
    v100 = *v97;
    if ( v100 > 3 )
      break;
    if ( v100 == 1 )
    {
      v102 = (void *)_qdf_mem_malloc(v97[1], "lim_process_fils_eap_tlv", 360);
      *(_QWORD *)(v95 + 720) = v102;
      if ( !v102 )
        goto LABEL_138;
      qdf_mem_copy(v102, v97 + 2, v97[1]);
      v98 = v97[1];
      *(_BYTE *)(v95 + 728) = v98;
    }
    else
    {
      if ( v100 == 2 )
      {
        *(_DWORD *)(v95 + 748) = *(_DWORD *)(v97 + 2);
      }
      else
      {
        if ( v100 != 3 )
          goto LABEL_171;
        *(_DWORD *)(v95 + 752) = *(_DWORD *)(v97 + 2);
      }
      v98 = v97[1];
    }
LABEL_91:
    v99 = v98 + 2;
    v96 -= v99;
    v97 += v99;
    if ( v96 <= 0x11 )
      goto LABEL_139;
  }
  if ( v100 - 5 < 2 )
    goto LABEL_91;
  if ( v100 == 4 )
  {
    v101 = (void *)_qdf_mem_malloc(v97[1], "lim_process_fils_eap_tlv", 383);
    *(_QWORD *)(v95 + 736) = v101;
    if ( !v101 )
      goto LABEL_138;
    qdf_mem_copy(v101, v97 + 2, v97[1]);
    v98 = v97[1];
    *(_BYTE *)(v95 + 744) = v98;
    goto LABEL_91;
  }
LABEL_171:
  qdf_trace_msg(0x35u, 8u, "%s: Unknown type", v27, v28, v29, v30, v31, v32, v33, v34, "lim_process_fils_eap_tlv");
LABEL_139:
  v140 = &v94[v26 - 8 - v96];
  v143 = *v140;
  v142 = v140 + 1;
  v141 = v143;
  if ( v143 == 2 )
    v144 = 16;
  else
    v144 = -22;
  if ( v141 == 3 )
    v145 = 32;
  else
    v145 = v144;
  v165 -= v145 & 0xFE;
  if ( v96 - 1 == (v145 & 0xFE) )
    qdf_get_hmac_hash(
      (__int64)"hmac(sha256)",
      *(_QWORD *)(v19 + 56),
      *(unsigned int *)(v19 + 64),
      1u,
      (__int64)&v174,
      &v165);
  else
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: invalid remaining len %d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "lim_process_auth_wrapped_data");
  if ( !(unsigned int)qdf_mem_cmp(v142, v175, v145) )
  {
    v146 = *(_QWORD *)(a2 + 9976);
    LODWORD(v176) = 0;
    strcpy(s, "Re-authentication Master Session Key@ietf.org");
    if ( v146 )
    {
      v147 = *(unsigned __int8 *)(v146 + 48);
      *(_BYTE *)(v146 + 680) = v147;
      v148 = _qdf_mem_malloc(v147, "lim_generate_rmsk_data", 988);
      *(_QWORD *)(v146 + 672) = v148;
      if ( v148 )
      {
        v149 = v148;
        v150 = *(_QWORD *)(v146 + 40);
        v151 = *(unsigned __int8 *)(v146 + 680);
        v152 = bswap32(*(unsigned __int16 *)(v146 + 68)) >> 16;
        BYTE3(v176) = *(_BYTE *)(v146 + 48);
        LOWORD(v176) = v152;
        qdf_default_hmac_sha256_kdf(v150, BYTE3(v176), s, (__int64)&v176, 4u, v149, v151);
      }
      v153 = *(_QWORD *)(a2 + 9976);
      memset(s, 0, 32);
      if ( v153 )
      {
        qdf_mem_copy(s, (const void *)(v153 + 78), 0x10u);
        qdf_mem_copy(&s[16], (const void *)(*(_QWORD *)(a2 + 9976) + 758LL), 0x10u);
        v154 = *(_QWORD *)(v153 + 688);
        if ( ((*(unsigned __int8 *)(v153 + 17) - 19) & 0xFFFFFFFD) != 0 )
          v155 = 32;
        else
          v155 = 48;
        *(_BYTE *)(v153 + 696) = v155;
        if ( v154 )
        {
          _qdf_mem_free(v154);
          v155 = *(unsigned __int8 *)(v153 + 696);
        }
        v156 = _qdf_mem_malloc(v155, "lim_generate_pmk", 956);
        *(_QWORD *)(v153 + 688) = v156;
        if ( v156 )
        {
          v157 = *(unsigned __int8 *)(v153 + 680);
          v158 = *(_BYTE *)(v153 + 17);
          v176 = *(_QWORD *)(v153 + 672);
          v166 = v157;
          v159 = ((v158 - 19) & 0xFD) != 0 ? "hmac(sha256)" : "hmac(sha384)";
          if ( (qdf_get_hmac_hash((__int64)v159, (__int64)s, 32, 1u, (__int64)&v176, &v166) & 0x80000000) != 0 )
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: failed to generate PMK",
              v7,
              v8,
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              "lim_generate_pmk");
        }
      }
    }
    v160 = *(_QWORD *)(a2 + 9976);
    if ( v160 )
    {
      v161 = *(_BYTE *)(v160 + 17);
      memset(s, 0, sizeof(s));
      if ( ((v161 - 19) & 0xFD) != 0 )
        v162 = "sha256";
      else
        v162 = "sha384";
      qdf_get_hash((__int64)v162, 1u, v160 + 24, (unsigned int *)(v160 + 32));
      qdf_mem_copy((void *)(v160 + 697), s, 0x10u);
    }
    goto LABEL_29;
  }
  v16 = "%s: integratity check failed for auth, crypto %d";
  v17 = "lim_process_auth_wrapped_data";
  v15 = v141;
LABEL_5:
  qdf_trace_msg(0x35u, 2u, v16, v7, v8, v9, v10, v11, v12, v13, v14, v17, v15);
LABEL_6:
  result = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
