__int64 __fastcall lim_set_eht_caps(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int16 a3,
        unsigned __int8 a4,
        unsigned int a5)
{
  int v5; // w25
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  const char *v19; // x2
  unsigned int country_max_allowed_bw; // w0
  unsigned int v21; // w24
  unsigned __int64 v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w26
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x24
  char force_20mhz_in_24ghz; // w25
  unsigned int *v43; // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 result; // x0
  __int64 v53; // x21
  __int64 v54; // x22
  unsigned int *v55; // x8
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  int v64; // w9
  unsigned int v65; // w9
  unsigned int v66; // w9
  unsigned int v67; // w9
  unsigned int v68; // w9
  unsigned int v69; // w9
  unsigned int v70; // w9
  unsigned int v71; // w9
  unsigned int v72; // w9
  unsigned int v73; // w9
  unsigned int v74; // w9
  unsigned int v75; // w9
  unsigned int v76; // w9
  unsigned int v77; // w9
  unsigned int v78; // w9
  unsigned int v79; // w9
  unsigned int v80; // w9
  unsigned int v81; // w9
  unsigned int v82; // w9
  unsigned int v83; // w9
  unsigned __int64 v84; // x8
  unsigned __int64 v85; // x8
  unsigned __int64 v86; // x8
  unsigned __int64 v87; // x8
  unsigned __int64 v88; // x8
  unsigned __int64 v89; // x8
  unsigned __int64 v90; // x8
  unsigned __int64 v91; // x8
  unsigned __int64 v92; // x8
  unsigned __int64 v93; // x8
  unsigned __int64 v94; // x8
  unsigned __int64 v95; // x8
  unsigned __int64 v96; // x8
  unsigned __int64 v97; // x8
  unsigned __int64 v98; // x8
  unsigned __int64 v99; // x8
  unsigned __int64 v100; // x8
  unsigned __int64 v101; // x8
  unsigned __int64 v102; // x8
  unsigned __int64 v103; // x8
  unsigned __int64 v104; // x8
  unsigned __int64 v105; // x8
  unsigned __int64 v106; // x8
  unsigned __int64 v107; // x8
  unsigned __int64 v108; // x8
  unsigned __int64 v109; // x8
  unsigned __int64 v110; // x8
  unsigned __int64 v111; // x8
  unsigned __int64 v112; // x8
  unsigned __int64 v113; // x8
  unsigned __int64 v114; // x8
  unsigned __int64 v115; // x8
  unsigned __int64 v116; // x8
  unsigned __int64 v117; // x8
  unsigned __int64 v118; // x8
  __int64 v119; // x8
  unsigned __int8 *v120; // x0
  unsigned __int8 *v121; // x0
  char *v122; // x1
  unsigned int v123; // w20
  __int128 v124; // [xsp+8h] [xbp-B8h] BYREF
  _QWORD v125[7]; // [xsp+18h] [xbp-A8h] BYREF
  int v126; // [xsp+50h] [xbp-70h]
  _QWORD v127[11]; // [xsp+58h] [xbp-68h] BYREF
  int v128; // [xsp+B0h] [xbp-10h]
  __int64 v129; // [xsp+B8h] [xbp-8h]

  v5 = a4;
  v129 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v128 = 0;
  memset(v127, 0, sizeof(v127));
  v126 = 0;
  memset(v125, 0, sizeof(v125));
  v124 = 0u;
  populate_dot11f_eht_caps_by_band(a1, a4 == 1, v127, 0);
  if ( v5 != 1 )
  {
    if ( (v127[0] & 0x2000000LL) == 0 )
    {
      v19 = "%s: 320MHz is not set";
LABEL_8:
      qdf_trace_msg(0x35u, 8u, v19, v11, v12, v13, v14, v15, v16, v17, v18, "lim_revise_eht_caps_per_band");
      goto LABEL_12;
    }
    country_max_allowed_bw = wlan_reg_get_country_max_allowed_bw(
                               *(_QWORD *)(a1 + 21632),
                               v11,
                               v12,
                               v13,
                               v14,
                               v15,
                               v16,
                               v17,
                               v18);
    if ( !country_max_allowed_bw )
    {
      v19 = "%s: Failed to get country_max_allowed_bw";
      goto LABEL_8;
    }
    v21 = country_max_allowed_bw;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: max_allowed_bw %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "lim_revise_eht_caps_per_band",
      country_max_allowed_bw);
    if ( v21 > 0x13F )
    {
      if ( v21 != 320 )
        goto LABEL_12;
      v22 = *(_QWORD *)((char *)v127 + 1) | 0x20000LL;
    }
    else
    {
      v22 = *(_QWORD *)((char *)v127 + 1) & 0xFFFFFFFFFFFDFFFFLL;
    }
    *(_QWORD *)((char *)v127 + 1) = v22;
  }
LABEL_12:
  populate_dot11f_he_caps_by_band(a1, v5 == 1, (int)v125);
  if ( LOBYTE(v127[0]) )
  {
    qdf_trace_msg(0x35u, 8u, "EHT Capabilities:", v23, v24, v25, v26, v27, v28, v29, v30);
    ((void (__fastcall *)(__int64, __int64, _QWORD *, __int64))qdf_trace_hex_dump)(53, 8, v127, 92);
  }
  if ( a4 == 1 )
  {
    if ( (v31 = *(unsigned __int8 *)(a1 + 17192),
          (v32 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                   *(_QWORD *)(a1 + 21624),
                   a5,
                   1)) != 0)
      && (v41 = v32,
          force_20mhz_in_24ghz = wlan_cm_get_force_20mhz_in_24ghz(v32, v33, v34, v35, v36, v37, v38, v39, v40),
          wlan_objmgr_vdev_release_ref(v41, 1u, v43, v44, v45, v46, v47, v48, v49, v50, v51),
          (force_20mhz_in_24ghz & 1) != 0)
      || !v31 )
    {
      *(_QWORD *)((char *)v125 + 1) &= ~0x4000000000000uLL;
      *(_QWORD *)((char *)&v125[1] + 1) &= ~0x10000000000000uLL;
    }
  }
  result = (__int64)wlan_get_ext_ie_ptr_from_ext_id("l", 1u, a2, a3);
  if ( !result )
    goto LABEL_35;
  v53 = result;
  v54 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(a1 + 21624),
          a5,
          77);
  result = wlan_epcs_get_config(v54);
  v64 = *(_DWORD *)(v53 + 3) & 0xFFFFFFFE | result & 1;
  *(_DWORD *)(v53 + 3) = v64;
  if ( v54 )
  {
    result = wlan_objmgr_vdev_release_ref(v54, 0x4Du, v55, v56, v57, v58, v59, v60, v61, v62, v63);
    v64 = *(_DWORD *)(v53 + 3);
  }
  v65 = v64 & 0xFFFFFFFD | (2 * ((*(_DWORD *)((char *)v127 + 1) >> 1) & 1));
  *(_DWORD *)(v53 + 3) = v65;
  v66 = v65 & 0xFFFFFFFB | (4 * ((*(_DWORD *)((char *)v127 + 1) >> 2) & 1));
  *(_DWORD *)(v53 + 3) = v66;
  v67 = v66 & 0xFFFFFFF7 | (8 * ((*(_DWORD *)((char *)v127 + 1) >> 3) & 1));
  *(_DWORD *)(v53 + 3) = v67;
  v68 = v67 & 0xFFFFFFEF | (16 * ((*(_DWORD *)((char *)v127 + 1) >> 4) & 1));
  *(_DWORD *)(v53 + 3) = v68;
  v69 = v68 & 0xFFFFFFDF | (32 * ((*(_DWORD *)((char *)v127 + 1) >> 5) & 1));
  *(_DWORD *)(v53 + 3) = v69;
  v70 = v69 & 0xFFFFFF3F | (BYTE1(v127[0]) >> 6 << 6);
  *(_DWORD *)(v53 + 3) = v70;
  v71 = v70 & 0xFFFFFEFF | (((*(_DWORD *)((char *)v127 + 1) >> 8) & 1) << 8);
  *(_DWORD *)(v53 + 3) = v71;
  v72 = v71 & 0xFFFFFDFF | (((*(_DWORD *)((char *)v127 + 1) >> 9) & 1) << 9);
  *(_DWORD *)(v53 + 3) = v72;
  v73 = v72 & 0xFFFFFBFF | (((*(_DWORD *)((char *)v127 + 1) >> 10) & 1) << 10);
  *(_DWORD *)(v53 + 3) = v73;
  v74 = v73 & 0xFFFFF7FF | (((*(_DWORD *)((char *)v127 + 1) >> 11) & 1) << 11);
  *(_DWORD *)(v53 + 3) = v74;
  v75 = v74 & 0xFFFFCFFF | (((*(_DWORD *)((char *)v127 + 1) >> 12) & 3) << 12);
  *(_DWORD *)(v53 + 3) = v75;
  v76 = v75 & 0xFFFDFFFF | (((*(_DWORD *)((char *)v127 + 1) >> 17) & 1) << 17);
  *(_DWORD *)(v53 + 3) = v76;
  v77 = v76 & 0xFFFBFFFF | (((*(_DWORD *)((char *)v127 + 1) >> 18) & 1) << 18);
  *(_DWORD *)(v53 + 3) = v77;
  v78 = v77 & 0xFFF7FFFF | (((*(_DWORD *)((char *)v127 + 1) >> 19) & 1) << 19);
  *(_DWORD *)(v53 + 3) = v78;
  v79 = v78 & 0xFFEFFFFF | (((*(_DWORD *)((char *)v127 + 1) >> 20) & 1) << 20);
  *(_DWORD *)(v53 + 3) = v79;
  v80 = v79 & 0xFFDFFFFF | (((*(_DWORD *)((char *)v127 + 1) >> 21) & 1) << 21);
  *(_DWORD *)(v53 + 3) = v80;
  v81 = v80 & 0xFFBFFFFF | (((*(_DWORD *)((char *)v127 + 1) >> 22) & 1) << 22);
  *(_DWORD *)(v53 + 3) = v81;
  v82 = v81 & 0xFC7FFFFF | ((HIBYTE(*(_DWORD *)((char *)v127 + 1)) & 7) << 23);
  *(_DWORD *)(v53 + 3) = v82;
  v83 = v82 & 0xE3FFFFFF | (((*(_DWORD *)((char *)v127 + 1) >> 27) & 7) << 26);
  *(_DWORD *)(v53 + 3) = v83;
  *(_DWORD *)(v53 + 3) = (*(_QWORD *)((char *)v127 + 1) >> 1) & 0xE0000000 | v83 & 0x1FFFFFFF;
  v84 = *(_QWORD *)(v53 + 7) & 0xFFFFFFFFFFFFFFF8LL | (*(_QWORD *)((char *)v127 + 1) >> 33) & 7LL;
  *(_QWORD *)(v53 + 7) = v84;
  v85 = v84 & 0xFFFFFFFFFFFFFFC7LL | (8 * ((*(_QWORD *)((char *)v127 + 1) >> 36) & 7LL));
  *(_QWORD *)(v53 + 7) = v85;
  v86 = v85 & 0xFFFFFFFFFFFFFE3FLL | (((*(_QWORD *)((char *)v127 + 1) >> 39) & 7LL) << 6);
  *(_QWORD *)(v53 + 7) = v86;
  v87 = v86 & 0xFFFFFFFFFFFFFDFFLL | (((*(_QWORD *)((char *)v127 + 1) >> 42) & 1LL) << 9);
  *(_QWORD *)(v53 + 7) = v87;
  v88 = v87 & 0xFFFFFFFFFFFFFBFFLL | (((*(_QWORD *)((char *)v127 + 1) >> 43) & 1LL) << 10);
  *(_QWORD *)(v53 + 7) = v88;
  v89 = v88 & 0xFFFFFFFFFFFFF7FFLL | (((*(_QWORD *)((char *)v127 + 1) >> 44) & 1LL) << 11);
  *(_QWORD *)(v53 + 7) = v89;
  v90 = v89 & 0xFFFFFFFFFFFFEFFFLL | (((*(_QWORD *)((char *)v127 + 1) >> 45) & 1LL) << 12);
  *(_QWORD *)(v53 + 7) = v90;
  v91 = v90 & 0xFFFFFFFFFFFFDFFFLL | (((*(_QWORD *)((char *)v127 + 1) >> 46) & 1LL) << 13);
  *(_QWORD *)(v53 + 7) = v91;
  v92 = v91 & 0xFFFFFFFFFFFFBFFFLL | (((*(_QWORD *)((char *)v127 + 1) >> 47) & 1LL) << 14);
  *(_QWORD *)(v53 + 7) = v92;
  v93 = v92 & 0xFFFFFFFFFFFF7FFFLL | ((HIWORD(*(_QWORD *)((char *)v127 + 1)) & 1LL) << 15);
  *(_QWORD *)(v53 + 7) = v93;
  v94 = v93 & 0xFFFFFFFFFFFEFFFFLL | (((*(_QWORD *)((char *)v127 + 1) >> 49) & 1LL) << 16);
  *(_QWORD *)(v53 + 7) = v94;
  v95 = v94 & 0xFFFFFFFFFFFDFFFFLL | (((*(_QWORD *)((char *)v127 + 1) >> 50) & 1LL) << 17);
  *(_QWORD *)(v53 + 7) = v95;
  v96 = v95 & 0xFFFFFFFFFFFBFFFFLL | (((*(_QWORD *)((char *)v127 + 1) >> 51) & 1LL) << 18);
  *(_QWORD *)(v53 + 7) = v96;
  v97 = v96 & 0xFFFFFFFFFFF7FFFFLL | (((*(_QWORD *)((char *)v127 + 1) >> 52) & 1LL) << 19);
  *(_QWORD *)(v53 + 7) = v97;
  v98 = v97 & 0xFFFFFFFFFF0FFFFFLL | ((HIBYTE(*(_QWORD *)((char *)v127 + 1)) & 0xFLL) << 20);
  *(_QWORD *)(v53 + 7) = v98;
  v99 = v98 & 0xFFFFFFFFFEFFFFFFLL | (((*(_QWORD *)((char *)v127 + 1) >> 60) & 1LL) << 24);
  *(_QWORD *)(v53 + 7) = v99;
  v100 = v99 & 0xFFFFFFFFFDFFFFFFLL | (((*(_QWORD *)((char *)v127 + 1) >> 61) & 1LL) << 25);
  *(_QWORD *)(v53 + 7) = v100;
  v101 = v100 & 0xFFFFFFFFFBFFFFFFLL | (((*(_QWORD *)((char *)v127 + 1) >> 62) & 1LL) << 26);
  *(_QWORD *)(v53 + 7) = v101;
  v102 = v101 & 0xFFFFFFFFF7FFFFFFLL | (*(_QWORD *)((char *)v127 + 1) >> 63 << 27);
  *(_QWORD *)(v53 + 7) = v102;
  v103 = v102 & 0xFFFFFFFFCFFFFFFFLL | ((unsigned __int64)(BYTE1(v127[1]) & 3) << 28);
  *(_QWORD *)(v53 + 7) = v103;
  v104 = v103 & 0xFFFFFFF83FFFFFFFLL | (((*(_QWORD *)((char *)&v127[1] + 1) >> 2) & 0x1FLL) << 30);
  *(_QWORD *)(v53 + 7) = v104;
  v105 = v104 & 0xFFFFFF87FFFFFFFFLL | (((*(_QWORD *)((char *)&v127[1] + 1) >> 7) & 0xFLL) << 35);
  *(_QWORD *)(v53 + 7) = v105;
  v106 = v105 & 0xFFFFFF7FFFFFFFFFLL | (((*(_QWORD *)((char *)&v127[1] + 1) >> 11) & 1LL) << 39);
  *(_QWORD *)(v53 + 7) = v106;
  v107 = v106 & 0xFFFFFEFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v127[1] + 1) >> 12) & 1LL) << 40);
  *(_QWORD *)(v53 + 7) = v107;
  v108 = v107 & 0xFFFFFDFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v127[1] + 1) >> 13) & 1LL) << 41);
  *(_QWORD *)(v53 + 7) = v108;
  v109 = v108 & 0xFFFFFBFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v127[1] + 1) >> 14) & 1LL) << 42);
  *(_QWORD *)(v53 + 7) = v109;
  v110 = v109 & 0xFFFFF7FFFFFFFFFFLL | (((*(_QWORD *)((char *)&v127[1] + 1) >> 15) & 1LL) << 43);
  *(_QWORD *)(v53 + 7) = v110;
  v111 = v110 & 0xFFFFEFFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v127[1] + 1) >> 16) & 1LL) << 44);
  *(_QWORD *)(v53 + 7) = v111;
  v112 = v111 & 0xFFFFDFFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v127[1] + 1) >> 17) & 1LL) << 45);
  *(_QWORD *)(v53 + 7) = v112;
  v113 = v112 & 0xFFFFBFFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v127[1] + 1) >> 18) & 1LL) << 46);
  *(_QWORD *)(v53 + 7) = v113;
  v114 = v113 & 0xFFFF7FFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v127[1] + 1) >> 19) & 1LL) << 47);
  *(_QWORD *)(v53 + 7) = v114;
  v115 = v114 & 0xFFF7FFFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v127[1] + 1) >> 20) & 1LL) << 51);
  *(_QWORD *)(v53 + 7) = v115;
  v116 = v115 & 0xFFEFFFFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v127[1] + 1) >> 21) & 1LL) << 52);
  *(_QWORD *)(v53 + 7) = v116;
  v117 = v116 & 0xFFFEFFFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v127[1] + 1) >> 22) & 1LL) << 48);
  *(_QWORD *)(v53 + 7) = v117;
  v118 = v117 & 0xFFFDFFFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v127[1] + 1) >> 23) & 1LL) << 49);
  *(_QWORD *)(v53 + 7) = v118;
  *(_QWORD *)(v53 + 7) = v118 & 0xFFFBFFFFFFFFFFFFLL | (((*(_QWORD *)((char *)&v127[1] + 1) >> 24) & 1LL) << 50);
  v119 = *(_QWORD *)((char *)v125 + 1);
  if ( a4 == 1 )
  {
    if ( (*(_QWORD *)((char *)v125 + 1) & 0x4000000000000LL) == 0 )
      goto LABEL_33;
LABEL_27:
    v120 = &a2[(unsigned __int8)(a2[1] + 3)];
    *(_QWORD *)((char *)&v124 + 4) = *(_QWORD *)((_BYTE *)&v124 + 4) & 0xFFFF000000FFFFFFLL
                                   | (*(_QWORD *)((char *)&v127[1] + 1) >> 60 << 24) & 0xFFFF00000FFFFFFFLL
                                   | ((unsigned __int64)(*(_DWORD *)((_BYTE *)&v127[2] + 1) & 0xFFFFF) << 28);
    result = (__int64)qdf_mem_copy(v120, (char *)&v124 + 7, 3u);
    a2[1] += 3;
    if ( a4 == 1 )
      goto LABEL_35;
    v119 = *(_QWORD *)((char *)v125 + 1);
    goto LABEL_29;
  }
  if ( (*(_QWORD *)((char *)v125 + 1) & 0x38000000000000LL) == 0 )
  {
LABEL_33:
    v122 = (char *)&v124 + 3;
    v123 = 4;
    BYTE3(v124) = *(_QWORD *)((char *)&v127[1] + 1) >> 28;
    *(_QWORD *)((char *)&v124 + 4) = *(_QWORD *)((_BYTE *)&v124 + 4) & 0xFFFFFFFFFF000000LL
                                   | (*(_QWORD *)((char *)&v127[1] + 1) >> 36) & 0xFFFFFFLL;
    goto LABEL_34;
  }
  if ( (*(_QWORD *)((char *)v125 + 1) & 0x8000000000000LL) != 0 )
    goto LABEL_27;
LABEL_29:
  if ( (v119 & 0x10000000000000LL) != 0 )
  {
    v121 = &a2[(unsigned __int8)(a2[1] + 3)];
    BYTE12(v124) = *(_QWORD *)((char *)&v127[2] + 1) >> 36;
    WORD5(v124) = *(_QWORD *)((char *)&v127[2] + 1) >> 20;
    result = (__int64)qdf_mem_copy(v121, (char *)&v124 + 10, 3u);
    a2[1] += 3;
  }
  if ( (*(_BYTE *)(v53 + 5) & 2) != 0 )
  {
    v122 = (char *)&v124 + 13;
    v123 = 3;
    HIDWORD(v124) = (*(_QWORD *)((char *)&v127[2] + 1) >> 36) & 0xFFFFF00 | BYTE12(v124) | (BYTE1(v127[3]) << 28);
LABEL_34:
    result = (__int64)qdf_mem_copy(&a2[(unsigned __int8)(a2[1] + 3)], v122, v123);
    a2[1] += v123;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
