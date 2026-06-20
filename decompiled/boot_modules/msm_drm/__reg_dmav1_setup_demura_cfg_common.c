__int64 __fastcall _reg_dmav1_setup_demura_cfg_common(
        __int64 a1,
        __int64 *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        char a6,
        char a7,
        int a8)
{
  const char *v8; // x24
  __int64 v9; // x20
  __int64 v14; // x8
  int v15; // w10
  __int64 *v16; // x26
  __int64 v17; // x8
  int v18; // w22
  __int64 v19; // x27
  char *v20; // x25
  __int64 v21; // x21
  unsigned int v22; // w5
  unsigned int v23; // w26
  int v24; // w5
  _QWORD *v25; // x22
  int v26; // w5
  unsigned int v27; // w5
  long double v28; // q0
  __int64 (__fastcall *v29)(_QWORD, long double); // x8
  unsigned int v30; // w0
  unsigned int v31; // w28
  __int64 v32; // x8
  int v33; // w26
  int v34; // w22
  unsigned int *v35; // x25
  unsigned int v36; // w8
  unsigned int v37; // w9
  unsigned int v38; // w11
  unsigned int v39; // w9
  unsigned int v40; // w4
  int v41; // w6
  int v42; // w6
  int v43; // w5
  int v44; // w6
  int v45; // w5
  int v46; // w6
  int v47; // w5
  int v48; // w6
  int v49; // w5
  int v50; // w6
  int v51; // w5
  int v52; // w6
  int v53; // w5
  int v54; // w6
  int v55; // w5
  long double v56; // q0
  __int64 (__fastcall *v57)(_QWORD, long double); // x8
  unsigned int v58; // w0
  long double v59; // q0
  __int64 (__fastcall *v60)(_QWORD, long double); // x8
  unsigned int v61; // w0
  unsigned int v62; // w24
  double v63; // d0
  unsigned int v64; // w8
  unsigned int v65; // w9
  bool v66; // cf
  unsigned int v67; // w8
  unsigned int v68; // w10
  int v69; // w8
  int v70; // w9
  int v71; // w10
  unsigned int v72; // w4
  long double v73; // q0
  __int64 (__fastcall *v74)(_QWORD, long double); // x8
  unsigned int v75; // w0
  int v76; // w5
  int v77; // w5
  int v78; // w5
  int v79; // w5
  int v80; // w5
  int v81; // w5
  int v82; // w5
  int v83; // w5
  long double v84; // q0
  __int64 (__fastcall *v85)(_QWORD, long double); // x8
  unsigned int v86; // w0
  int v87; // w4
  long double v88; // q0
  __int64 (__fastcall *v89)(_QWORD, long double); // x8
  unsigned int v90; // w0
  int v91; // w5
  int v92; // w9
  int v93; // w8
  int v94; // w5
  int v95; // w9
  int v96; // w8
  long double v97; // q0
  __int64 (__fastcall *v98)(_QWORD, long double); // x8
  unsigned int v99; // w0
  __int64 v100; // x28
  unsigned int v101; // w4
  unsigned int v102; // w4
  unsigned int v103; // w5
  long double v104; // q0
  __int64 (__fastcall *v105)(_QWORD, long double); // x8
  unsigned int v106; // w0
  __int64 v107; // x8
  unsigned int v108; // w8
  __int64 v109; // x3
  int v110; // w8
  __int64 v111; // x20
  __int16 v112; // w8
  int v113; // w9
  __int64 v114; // x11
  int v115; // w10
  __int64 v116; // x26
  int v117; // w9
  __int64 v118; // x11
  int v119; // w21
  int v120; // w22
  long double v121; // q0
  __int64 (__fastcall *v122)(_QWORD, long double); // x8
  unsigned int v123; // w0
  int v124; // w8
  __int64 v125; // x25
  int v126; // w11
  int v127; // w12
  int v128; // w10
  int v129; // w21
  int v130; // w22
  long double v131; // q0
  __int64 (__fastcall *v132)(_QWORD, long double); // x8
  unsigned int v133; // w0
  long double v134; // q0
  unsigned int v135; // w8
  unsigned int v136; // w8
  __int64 v137; // x0
  int offset_idx; // w0
  __int64 (__fastcall *v139)(_QWORD); // x8
  unsigned int v140; // w0
  __int64 v141; // x8
  const char *v142; // x0
  long double v143; // q0
  __int64 (__fastcall *v144)(_QWORD, long double); // x8
  unsigned int v145; // w0
  __int64 (__fastcall *v146)(_QWORD); // x8
  unsigned int v147; // w0
  unsigned __int64 StatusReg; // x21
  __int64 v149; // x28
  __int64 v150; // x0
  __int64 v152; // [xsp+18h] [xbp-48h]
  __int64 v153; // [xsp+18h] [xbp-48h]
  __int64 v154; // [xsp+18h] [xbp-48h]
  __int64 v155; // [xsp+28h] [xbp-38h]
  __int64 v156; // [xsp+28h] [xbp-38h]
  int v157; // [xsp+30h] [xbp-30h] BYREF
  unsigned int v158; // [xsp+34h] [xbp-2Ch] BYREF
  __int64 v159; // [xsp+38h] [xbp-28h] BYREF
  unsigned __int64 v160; // [xsp+40h] [xbp-20h] BYREF
  unsigned __int64 v161; // [xsp+48h] [xbp-18h]
  int v162; // [xsp+50h] [xbp-10h]
  __int64 v163; // [xsp+58h] [xbp-8h]

  LOBYTE(v8) = a7;
  v9 = a1;
  v163 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 72);
  v15 = *((_DWORD *)a2 + 3);
  LODWORD(v16) = *(_DWORD *)(a1 + 8);
  LODWORD(v160) = a8;
  v17 = *(_QWORD *)(v14 + 48);
  v159 = 0;
  v158 = 1;
  v18 = *(_DWORD *)(v17 + 568);
  v157 = 1;
  if ( v15 )
  {
    LOBYTE(v19) = a6;
    v20 = (char *)_kvmalloc_node_noprof(8568, 0, 3520, 0xFFFFFFFFLL);
    if ( !v20 )
    {
LABEL_105:
      v31 = -12;
      goto LABEL_106;
    }
LABEL_3:
    v155 = a4;
    v21 = -1LL << (char)v8;
    v152 = a5;
    v22 = a2[799] & ~(unsigned int)(-1LL << (char)v8)
        | ((*((_DWORD *)a2 + 1599) & ~(unsigned int)(-1LL << (char)v8)) << 16);
    v23 = (_DWORD)v16 + v18;
    *(_DWORD *)v20 = v22;
    _drm_dev_dbg(0, 0, 1, "0x1c: index %d value %x\n", 0, v22);
    v24 = a2[800] & ~(_DWORD)v21 | ((*((_DWORD *)a2 + 1601) & ~(_DWORD)v21) << 16);
    *((_DWORD *)v20 + 1) = v24;
    v25 = v20 + 4;
    _drm_dev_dbg(0, 0, 1, "0x1c: index %d value %x\n", 1, v24);
    v26 = a2[801] & ~(_DWORD)v21 | ((*((_DWORD *)a2 + 1603) & ~(_DWORD)v21) << 16);
    *((_DWORD *)v20 + 2) = v26;
    _drm_dev_dbg(0, 0, 1, "0x1c: index %d value %x\n", 2, v26);
    a4 = v155;
    v27 = a2[802] & ~(unsigned int)(-1LL << (char)v8)
        | ((*((_DWORD *)a2 + 1605) & ~(unsigned int)(-1LL << (char)v8)) << 16);
    *((_DWORD *)v20 + 3) = v27;
    *(double *)&v28 = _drm_dev_dbg(0, 0, 1, "0x1c: index %d value %x\n", 3, v27);
    *(_DWORD *)a3 = 2;
    *(_DWORD *)(a3 + 20) = v23 + 28;
    *(_QWORD *)(a3 + 12) = 0;
    *(_QWORD *)(a3 + 32) = v20;
    *(_QWORD *)(a3 + 40) = 0x1000000000LL;
    v29 = *(__int64 (__fastcall **)(_QWORD, long double))(v155 + 8);
    if ( *((_DWORD *)v29 - 1) != -1839634494 )
      __break(0x8228u);
    v30 = v29(a3, v28);
    if ( v30 )
    {
      v31 = v30;
      _drm_err("0x1c: write err %d len %zd buffer index %d\n", v30, 16, *(unsigned int *)(*(_QWORD *)(a3 + 24) + 20LL));
LABEL_101:
      kvfree(v20);
LABEL_106:
      _drm_err("failed setup_demurav1_cfg0 rc %d", v31);
      goto LABEL_109;
    }
    v41 = a2[7] & 0x3F;
    *((_DWORD *)v20 + 7) = 0;
    *(_QWORD *)(v20 + 12) = 0;
    *(_QWORD *)(v20 + 20) = 0;
    *v25 = 0;
    *(_DWORD *)v20 = v41;
    _drm_dev_dbg(0, 0, 1, "0xc: index %d value %x val %x shift %d\n", 0, v41, v41, 0);
    v42 = *((_DWORD *)a2 + 15) & 0x3F;
    v43 = *(_DWORD *)v20 | (v42 << 8);
    *(_DWORD *)v20 = v43;
    _drm_dev_dbg(0, 0, 1, "0xc: index %d value %x val %x shift %d\n", 1, v43, v42, 8);
    v44 = a2[8] & 0x3F;
    v45 = *(_DWORD *)v20 | (v44 << 16);
    *(_DWORD *)v20 = v45;
    _drm_dev_dbg(0, 0, 1, "0xc: index %d value %x val %x shift %d\n", 2, v45, v44, 16);
    v46 = *((_DWORD *)a2 + 17) & 0x3F;
    v47 = *(_DWORD *)v20 | (v46 << 24);
    *(_DWORD *)v20 = v47;
    _drm_dev_dbg(0, 0, 1, "0xc: index %d value %x val %x shift %d\n", 3, v47, v46, 24);
    v48 = a2[9] & 0x3F;
    v49 = v48 | *((_DWORD *)v20 + 1);
    *((_DWORD *)v20 + 1) = v49;
    _drm_dev_dbg(0, 0, 1, "0xc: index %d value %x val %x shift %d\n", 4, v49, v48, 0);
    v50 = *((_DWORD *)a2 + 19) & 0x3F;
    v51 = *((_DWORD *)v20 + 1) | (v50 << 8);
    *((_DWORD *)v20 + 1) = v51;
    _drm_dev_dbg(0, 0, 1, "0xc: index %d value %x val %x shift %d\n", 5, v51, v50, 8);
    v52 = a2[10] & 0x3F;
    v53 = *((_DWORD *)v20 + 1) | (v52 << 16);
    *((_DWORD *)v20 + 1) = v53;
    _drm_dev_dbg(0, 0, 1, "0xc: index %d value %x val %x shift %d\n", 6, v53, v52, 16);
    v54 = *((_DWORD *)a2 + 21) & 0x3F;
    v55 = *((_DWORD *)v20 + 1) | (v54 << 24);
    *((_DWORD *)v20 + 1) = v55;
    *(double *)&v56 = _drm_dev_dbg(0, 0, 1, "0xc: index %d value %x val %x shift %d\n", 7, v55, v54, 24);
    *(_QWORD *)(a3 + 12) = 0;
    *(_DWORD *)a3 = 2;
    *(_DWORD *)(a3 + 20) = v23 + 12;
    *(_QWORD *)(a3 + 32) = v20;
    *(_QWORD *)(a3 + 40) = 0x800000000LL;
    v57 = *(__int64 (__fastcall **)(_QWORD, long double))(v155 + 8);
    if ( *((_DWORD *)v57 - 1) != -1839634494 )
      __break(0x8228u);
    v58 = v57(a3, v56);
    if ( v58 )
    {
      v31 = v58;
      _drm_err("0xc: write err %d len %zd buffer index %d\n", v58, 8, *(unsigned int *)(*(_QWORD *)(a3 + 24) + 20LL));
      goto LABEL_101;
    }
    v76 = *((_DWORD *)a2 + 5);
    *((_DWORD *)v20 + 7) = 0;
    *(_QWORD *)(v20 + 12) = 0;
    *(_QWORD *)(v20 + 20) = 0;
    *v25 = 0;
    *(_DWORD *)v20 = v76 & ~(unsigned int)(-1LL << v19);
    _drm_dev_dbg(0, 0, 1, "0x2c: index %d value %x\n", 0, v76);
    v77 = *((_DWORD *)a2 + 6);
    *((_DWORD *)v20 + 1) = v77 & ~(unsigned int)(-1LL << v19);
    _drm_dev_dbg(0, 0, 1, "0x2c: index %d value %x\n", 1, v77);
    v78 = *((_DWORD *)a2 + 7);
    *((_DWORD *)v20 + 2) = v78 & ~(unsigned int)(-1LL << v19);
    _drm_dev_dbg(0, 0, 1, "0x2c: index %d value %x\n", 2, v78);
    v79 = *((_DWORD *)a2 + 8);
    *((_DWORD *)v20 + 3) = v79 & ~(unsigned int)(-1LL << v19);
    _drm_dev_dbg(0, 0, 1, "0x2c: index %d value %x\n", 3, v79);
    v80 = *((_DWORD *)a2 + 9);
    *((_DWORD *)v20 + 4) = v80 & ~(unsigned int)(-1LL << v19);
    _drm_dev_dbg(0, 0, 1, "0x2c: index %d value %x\n", 4, v80);
    v81 = *((_DWORD *)a2 + 10);
    *((_DWORD *)v20 + 5) = v81 & ~(unsigned int)(-1LL << v19);
    _drm_dev_dbg(0, 0, 1, "0x2c: index %d value %x\n", 5, v81);
    v82 = *((_DWORD *)a2 + 11);
    *((_DWORD *)v20 + 6) = v82 & ~(unsigned int)(-1LL << v19);
    _drm_dev_dbg(0, 0, 1, "0x2c: index %d value %x\n", 6, v82);
    v83 = *((_DWORD *)a2 + 12);
    *((_DWORD *)v20 + 7) = v83 & ~(unsigned int)(-1LL << v19);
    *(double *)&v84 = _drm_dev_dbg(0, 0, 1, "0x2c: index %d value %x\n", 7, v83);
    *(_DWORD *)a3 = 2;
    *(_DWORD *)(a3 + 20) = v23 + 44;
    *(_QWORD *)(a3 + 12) = 0;
    *(_QWORD *)(a3 + 32) = v20;
    *(_QWORD *)(a3 + 40) = 0x2000000000LL;
    v85 = *(__int64 (__fastcall **)(_QWORD, long double))(v155 + 8);
    if ( *((_DWORD *)v85 - 1) != -1839634494 )
      __break(0x8228u);
    v86 = v85(a3, v84);
    if ( v86 )
    {
      v31 = v86;
      _drm_err("0x2c: write err %d len %zd buf idx %d\n", v86, 32, *(unsigned int *)(*(_QWORD *)(a3 + 24) + 20LL));
      goto LABEL_101;
    }
    v91 = *((unsigned __int8 *)a2 + 6244)
        | (*((unsigned __int8 *)a2 + 6254) << 16)
        | (*((unsigned __int8 *)a2 + 6249) << 8)
        | a2[782] & 0x7F800000;
    v92 = *((unsigned __int8 *)a2 + 6276)
        | (*((unsigned __int8 *)a2 + 6286) << 16)
        | (*((unsigned __int8 *)a2 + 6281) << 8)
        | a2[786] & 0x7F800000;
    v93 = *((unsigned __int8 *)a2 + 6308)
        | (*((unsigned __int8 *)a2 + 6318) << 16)
        | (*((unsigned __int8 *)a2 + 6313) << 8)
        | a2[790] & 0x7F800000;
    *((_DWORD *)v20 + 5) = 0;
    *v25 = 0;
    *(_QWORD *)(v20 + 12) = 0;
    *(_DWORD *)v20 = v91;
    *((_DWORD *)v20 + 2) = v92;
    *((_DWORD *)v20 + 4) = v93;
    _drm_dev_dbg(0, 0, 1, "0xb0: index %d value %x\n", 0, v91);
    _drm_dev_dbg(0, 0, 1, "0xb0: index %d value %x\n", 2, *((_DWORD *)v20 + 2));
    _drm_dev_dbg(0, 0, 1, "0xb0: index %d value %x\n", 4, *((_DWORD *)v20 + 4));
    v94 = *((unsigned __int8 *)a2 + 6260)
        | (*((unsigned __int8 *)a2 + 6270) << 16)
        | (*((unsigned __int8 *)a2 + 6265) << 8)
        | a2[784] & 0x7F800000;
    v95 = *((unsigned __int8 *)a2 + 6292)
        | (*((unsigned __int8 *)a2 + 6302) << 16)
        | (*((unsigned __int8 *)a2 + 6297) << 8)
        | a2[788] & 0x7F800000;
    v96 = *((unsigned __int8 *)a2 + 6324)
        | (*((unsigned __int8 *)a2 + 6334) << 16)
        | (*((unsigned __int8 *)a2 + 6329) << 8)
        | a2[792] & 0x7F800000;
    *((_DWORD *)v20 + 1) = v94;
    *((_DWORD *)v20 + 3) = v95;
    *((_DWORD *)v20 + 5) = v96;
    _drm_dev_dbg(0, 0, 1, "0xb0: index %d value %x\n", 1, v94);
    _drm_dev_dbg(0, 0, 1, "0xb0: index %d value %x\n", 3, *((_DWORD *)v20 + 3));
    *(double *)&v97 = _drm_dev_dbg(0, 0, 1, "0xb0: index %d value %x\n", 5, *((_DWORD *)v20 + 5));
    *(_DWORD *)a3 = 2;
    *(_DWORD *)(a3 + 20) = v23 + 176;
    *(_QWORD *)(a3 + 12) = 0;
    *(_QWORD *)(a3 + 32) = v20;
    *(_QWORD *)(a3 + 40) = 0x1800000000LL;
    v98 = *(__int64 (__fastcall **)(_QWORD, long double))(v155 + 8);
    if ( *((_DWORD *)v98 - 1) != -1839634494 )
      __break(0x8228u);
    v99 = v98(a3, v97);
    if ( v99 )
    {
      v31 = v99;
      _drm_err("0xb0: write err %d len %zd buffer index %d\n", v99, 24, *(unsigned int *)(*(_QWORD *)(a3 + 24) + 20LL));
      goto LABEL_101;
    }
    v107 = *a2;
    if ( (*a2 & 0x10) == 0 )
    {
      memset(v20, 0, 0x800u);
      v108 = *((_DWORD *)a2 + 2090);
      v109 = (unsigned int)(1 << v108);
      if ( v108 >= 9 )
      {
LABEL_60:
        _drm_err("invalid len %d Max 256\n", v109);
        v31 = -22;
        goto LABEL_101;
      }
      v31 = _reg_dmav1_setup_demurav1_cfg0_c_params_cmn(a3, v155, a2 + 12, v109, v20, 0, v23);
      if ( v31 )
        goto LABEL_101;
      v107 = *a2;
      if ( (*a2 & 0x10) == 0 )
      {
        memset(v20, 0, 0x800u);
        v135 = *((_DWORD *)a2 + 2091);
        v109 = (unsigned int)(1 << v135);
        if ( v135 > 8 )
          goto LABEL_60;
        v31 = _reg_dmav1_setup_demurav1_cfg0_c_params_cmn(a3, v155, a2 + 268, v109, v20, 1, v23);
        if ( v31 )
          goto LABEL_101;
        v107 = *a2;
        if ( (*a2 & 0x10) == 0 )
        {
          memset(v20, 0, 0x800u);
          v136 = *((_DWORD *)a2 + 2092);
          v109 = (unsigned int)(1 << v136);
          if ( v136 > 8 )
            goto LABEL_60;
          a4 = v155;
          v31 = _reg_dmav1_setup_demurav1_cfg0_c_params_cmn(a3, v155, a2 + 524, v109, v20, 2, v23);
          if ( v31 )
            goto LABEL_101;
          v107 = *a2;
        }
      }
    }
    if ( (v107 & 0x10) != 0 )
    {
      v137 = *((unsigned int *)a2 + 2094);
    }
    else
    {
      v137 = 0;
      *((_DWORD *)a2 + 2094) = 0;
    }
    offset_idx = _get_offset_idx(v137, *((unsigned int *)a2 + 2090));
    *(_QWORD *)(a3 + 12) = 0;
    *(_DWORD *)a3 = 1;
    *(_DWORD *)(a3 + 20) = v23 + 112;
    *(_QWORD *)(a3 + 32) = &v159;
    *(_QWORD *)(a3 + 40) = 0x400000000LL;
    v139 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
    LODWORD(v159) = offset_idx;
    if ( *((_DWORD *)v139 - 1) != -1839634494 )
      __break(0x8228u);
    v140 = v139(a3);
    if ( v140 )
    {
      v141 = *(_QWORD *)(a3 + 24);
      v31 = v140;
      v142 = "0x70: REG_SINGLE_WRITE err %d len %zd buf idx %d\n";
LABEL_100:
      _drm_err(v142, v31, 4, *(unsigned int *)(v141 + 20));
      goto LABEL_101;
    }
    if ( (*(_BYTE *)a2 & 2) != 0 && (_parse_cfg0_param_7(*((unsigned int *)a2 + 2140), &v158, &v157) & 1) == 0 )
    {
      _drm_err("Failed to parse cfg0_param_7 param\n");
    }
    else
    {
      HIDWORD(v159) = ((*(_DWORD *)(v152 + 96) + v158 - 1) / v158) >> 1;
      *(double *)&v143 = _drm_dev_dbg(0, 0, 1, "0x80: value %x\n", HIDWORD(v159));
      *(_DWORD *)a3 = 1;
      *(_DWORD *)(a3 + 20) = v23 + 128;
      *(_QWORD *)(a3 + 12) = 0;
      *(_QWORD *)(a3 + 32) = (char *)&v159 + 4;
      *(_QWORD *)(a3 + 40) = 0x400000000LL;
      v144 = *(__int64 (__fastcall **)(_QWORD, long double))(a4 + 8);
      if ( *((_DWORD *)v144 - 1) != -1839634494 )
        __break(0x8228u);
      v145 = v144(a3, v143);
      if ( v145 )
      {
        v141 = *(_QWORD *)(a3 + 24);
        v31 = v145;
        v142 = "0x80: REG_SINGLE_WRITE err %d len %zd buf idx %d\n";
        goto LABEL_100;
      }
      *(_DWORD *)a3 = 1;
      *(_DWORD *)(a3 + 20) = v23 + 224;
      *(_QWORD *)(a3 + 12) = 0;
      *(_QWORD *)(a3 + 32) = &v160;
      *(_QWORD *)(a3 + 40) = 0x400000000LL;
      v146 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
      if ( *((_DWORD *)v146 - 1) != -1839634494 )
        __break(0x8228u);
      v147 = v146(a3);
      if ( v147 )
      {
        v141 = *(_QWORD *)(a3 + 24);
        v31 = v147;
        v142 = "0xe0: REG_SINGLE_WRITE err %d len %zd buf idx %d\n";
        goto LABEL_100;
      }
    }
    kvfree(v20);
    a5 = v152;
  }
  else
  {
    _drm_dev_dbg(0, 0, 1, "dcfg->cfg0_en is disabled\n");
  }
  v32 = *(_QWORD *)(v9 + 72);
  v33 = *(_DWORD *)(v9 + 8);
  v160 = 0;
  HIDWORD(v159) = 0;
  v34 = *(_DWORD *)(*(_QWORD *)(v32 + 48) + 568LL);
  v35 = (unsigned int *)_kvmalloc_node_noprof(612, 0, 3520, 0xFFFFFFFFLL);
  if ( !v35 )
  {
    v31 = -12;
    goto LABEL_108;
  }
  _drm_dev_dbg(
    0,
    0,
    1,
    "dcfg->cfg1_high_idx %d dcfg->cfg1_low_idx %d\n",
    *((_DWORD *)a2 + 1595),
    *((_DWORD *)a2 + 1596));
  v36 = *((_DWORD *)a2 + 1595);
  if ( v36 >= 8 )
  {
    v36 = 7;
    *((_DWORD *)a2 + 1595) = 7;
  }
  v37 = *((_DWORD *)a2 + 1596);
  v156 = v9;
  if ( v37 >= 8 )
  {
    v37 = 7;
    *((_DWORD *)a2 + 1596) = 7;
  }
  v9 = (unsigned int)(v33 + v34);
  v18 = a5;
  v38 = *((_DWORD *)a2 + v36 + 1598);
  v39 = *((_DWORD *)a2 + v37 + 1598);
  v160 = __PAIR64__(v39, v38);
  if ( v38 <= v39 )
    v40 = 0;
  else
    v40 = (1 << (char)v8) / (v38 - v39);
  HIDWORD(v159) = v40;
  *(double *)&v59 = _drm_dev_dbg(0, 0, 1, "0x14: value %x\n", v40);
  *(_DWORD *)a3 = 1;
  *(_DWORD *)(a3 + 20) = v9 + 20;
  *(_QWORD *)(a3 + 12) = 0;
  *(_QWORD *)(a3 + 32) = (char *)&v159 + 4;
  *(_QWORD *)(a3 + 40) = 0x400000000LL;
  v60 = *(__int64 (__fastcall **)(_QWORD, long double))(a4 + 8);
  if ( *((_DWORD *)v60 - 1) != -1839634494 )
    __break(0x8228u);
  v61 = v60(a3, v59);
  if ( v61 )
  {
    v31 = v61;
    _drm_err("0x14: REG_SINGLE_WRITE failed ret %d\n", v61);
LABEL_45:
    kvfree(v35);
LABEL_108:
    _drm_err("failed setup_demurav1_cfg1 rc %d", v31);
    goto LABEL_109;
  }
  v62 = *(_DWORD *)(a5 + 96);
  v63 = _drm_dev_dbg(0, 0, 1, "width for LFC calculation is %d\n", v62);
  v65 = *(_DWORD *)(a5 + 92);
  v64 = *(_DWORD *)(a5 + 96);
  v66 = v64 >= v65;
  if ( v64 >= v65 )
    v67 = 0x2000000;
  else
    v67 = 0x1000000;
  if ( v66 )
    v68 = 0x1000000;
  else
    v68 = 0x2000000;
  v69 = v67 / v62;
  v70 = v68 / v65;
  v71 = *((_DWORD *)a2 + 2);
  *(_DWORD *)a3 = 1;
  *(_QWORD *)(a3 + 12) = 0;
  if ( v71 )
    v72 = v69 | 0x80000000;
  else
    v72 = v69;
  *(_DWORD *)(a3 + 20) = v9 + 84;
  *(_QWORD *)(a3 + 32) = &v160;
  *(_QWORD *)(a3 + 40) = 0x400000000LL;
  v160 = __PAIR64__(v70, v72);
  *(double *)&v73 = _drm_dev_dbg(0, 0, 1, "0x54 value %x\n", v63);
  v74 = *(__int64 (__fastcall **)(_QWORD, long double))(a4 + 8);
  if ( *((_DWORD *)v74 - 1) != -1839634494 )
    __break(0x8228u);
  v75 = v74(a3, v73);
  if ( v75 )
  {
    v31 = v75;
    _drm_err("0x54: REG_SINGLE_WRITE ret %d\n", v75);
    goto LABEL_45;
  }
  v87 = HIDWORD(v160);
  *(_DWORD *)a3 = 1;
  *(_DWORD *)(a3 + 20) = v9 + 92;
  v153 = a5;
  *(_QWORD *)(a3 + 12) = 0;
  *(_QWORD *)(a3 + 32) = (char *)&v160 + 4;
  *(_QWORD *)(a3 + 40) = 0x400000000LL;
  *(double *)&v88 = _drm_dev_dbg(0, 0, 1, "0x5c value %x\n", v87);
  v89 = *(__int64 (__fastcall **)(_QWORD, long double))(a4 + 8);
  if ( *((_DWORD *)v89 - 1) != -1839634494 )
    __break(0x8228u);
  v90 = v89(a3, v88);
  if ( v90 )
  {
    v31 = v90;
    _drm_err("0x5c: REG_SINGLE_WRITE ret %d\n", v90);
    goto LABEL_45;
  }
  if ( *((_DWORD *)a2 + 1594) )
  {
    v100 = a4;
    v16 = a2 + 880;
    v19 = (__int64)a2 + 7652;
    v101 = *((_DWORD *)a2 + 1607) & 0x3FF
         | ((a2[880] & 0x3FF) << 10) & 0xC00FFFFF
         | ((*((_DWORD *)a2 + 1913) & 0x3FF) << 20)
         | 0x80000000;
    *v35 = v101;
    _drm_dev_dbg(0, 0, 1, "0x64: value %x\n", v101);
    v102 = 1;
    v8 = "0x64 index %d value %x\n";
    HIDWORD(v159) = 1;
    while ( v102 <= 0x98 )
    {
      v103 = *((_DWORD *)a2 + v102 + 1607) & 0x3FF
           | ((*((_DWORD *)v16 + v102) & 0x3FF) << 10) & 0xC00FFFFF
           | ((*(_DWORD *)(v19 + 4LL * v102) & 0x3FF) << 20);
      v35[v102] = v103;
      *(double *)&v104 = _drm_dev_dbg(0, 0, 1, "0x64 index %d value %x\n", v102, v103);
      v102 = ++HIDWORD(v159);
      if ( HIDWORD(v159) >= 0x99 )
      {
        *(_QWORD *)(a3 + 12) = 0;
        *(_DWORD *)a3 = 3;
        *(_DWORD *)(a3 + 20) = v9 + 100;
        *(_QWORD *)(a3 + 32) = v35;
        *(_QWORD *)(a3 + 40) = 0x26400000000LL;
        v105 = *(__int64 (__fastcall **)(_QWORD, long double))(a4 + 8);
        if ( *((_DWORD *)v105 - 1) != -1839634494 )
          __break(0x8228u);
        v106 = v105(a3, v104);
        if ( v106 )
        {
          v31 = v106;
          _drm_err("lut write failed ret %d\n", v106);
          goto LABEL_45;
        }
        goto LABEL_61;
      }
    }
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v154 = v100;
    v149 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &_reg_dmav1_setup_demurav1_cfg0__alloc_tag;
    v150 = _kvmalloc_node_noprof(8568, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v149;
    a5 = v154;
    a4 = (__int64)a2 + 6428;
    v20 = (char *)v150;
    if ( v150 )
      goto LABEL_3;
    goto LABEL_105;
  }
LABEL_61:
  kvfree(v35);
  v110 = *((_DWORD *)a2 + 2067);
  v162 = 0;
  v160 = 0;
  v161 = 0;
  if ( v110 )
  {
    v111 = v156;
    v112 = *((_DWORD *)a2 + 2076);
    v113 = (a2[1036] & 0x3FF) << 16;
    v114 = *(_QWORD *)(v156 + 72);
    v115 = (a2[1037] & 0x7FF) << 16;
    v116 = a4;
    LODWORD(v160) = (a2[1035] & 0x3FF) << 16;
    HIDWORD(v160) = v113;
    v117 = *((_DWORD *)a2 + 2077);
    v118 = *(_QWORD *)(v114 + 48);
    v119 = *(_DWORD *)(v156 + 8);
    LODWORD(v161) = v115;
    HIDWORD(v161) = (v112 & 0x7FF) << 16;
    v120 = *(_DWORD *)(v118 + 568);
    v162 = v117 & 0x7FF;
    _drm_dev_dbg(0, 0, 1, "0xd0: index %i value %x\n", 0, v160);
    _drm_dev_dbg(0, 0, 1, "0xd0: index %i value %x\n", 1, HIDWORD(v160));
    _drm_dev_dbg(0, 0, 1, "0xd0: index %i value %x\n", 2, v161);
    _drm_dev_dbg(0, 0, 1, "0xd0: index %i value %x\n", 3, HIDWORD(v161));
    *(double *)&v121 = _drm_dev_dbg(0, 0, 1, "0xd0: index %i value %x\n", 4, v162);
    *(_DWORD *)a3 = 2;
    *(_QWORD *)(a3 + 12) = 0;
    *(_DWORD *)(a3 + 20) = v119 + v120 + 208;
    a4 = v116;
    *(_QWORD *)(a3 + 32) = &v160;
    *(_QWORD *)(a3 + 40) = 0x1400000000LL;
    v122 = *(__int64 (__fastcall **)(_QWORD, long double))(v116 + 8);
    if ( *((_DWORD *)v122 - 1) != -1839634494 )
      __break(0x8228u);
    v123 = v122(a3, v121);
    if ( v123 )
    {
      v31 = v123;
      _drm_err("0xd0: REG_BLK_WRITE_SINGLE failed ret %d\n", v123);
      _drm_err("failed setup_demurav1_cfg3 rc %d", v31);
      goto LABEL_109;
    }
  }
  else
  {
    _drm_dev_dbg(0, 0, 1, "dcfg->cfg3_en is disabled\n");
    v111 = v156;
  }
  v124 = *((_DWORD *)a2 + 2079);
  v160 = 0;
  v161 = 0;
  if ( v124 )
  {
    v125 = a4;
    v126 = *((_DWORD *)a2 + 2083) & 0x3FF | ((a2[1042] & 0x3FF) << 16);
    v127 = a2[1043] & 0x7FF | ((*((_DWORD *)a2 + 2087) & 0x7FF) << 16);
    v128 = a2[1044] & 0x7FF | ((*((_DWORD *)a2 + 2089) & 0x7FF) << 16);
    v129 = *(_DWORD *)(v111 + 8);
    v130 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v111 + 72) + 48LL) + 568LL);
    LODWORD(v160) = *((_DWORD *)a2 + 2081) & 0x3FF | ((a2[1041] & 0x3FF) << 16);
    HIDWORD(v160) = v126;
    v161 = __PAIR64__(v128, v127);
    _drm_dev_dbg(0, 0, 1, "0xa0: index %i value %x\n", 0, v160);
    _drm_dev_dbg(0, 0, 1, "0xa0: index %i value %x\n", 1, HIDWORD(v160));
    _drm_dev_dbg(0, 0, 1, "0xa0: index %i value %x\n", 2, v161);
    *(double *)&v131 = _drm_dev_dbg(0, 0, 1, "0xa0: index %i value %x\n", 3, HIDWORD(v161));
    *(_DWORD *)a3 = 2;
    *(_QWORD *)(a3 + 12) = 0;
    *(_DWORD *)(a3 + 20) = v129 + v130 + 160;
    a4 = v125;
    *(_QWORD *)(a3 + 32) = &v160;
    *(_QWORD *)(a3 + 40) = 0x1000000000LL;
    v132 = *(__int64 (__fastcall **)(_QWORD, long double))(v125 + 8);
    if ( *((_DWORD *)v132 - 1) != -1839634494 )
      __break(0x8228u);
    v133 = v132(a3, v131);
    if ( v133 )
    {
      v31 = v133;
      _drm_err("0xa0: REG_BLK_WRITE_SINGLE failed ret %d\n", v133);
      _drm_err("failed setup_demurav1_cfg5 rc %d", v31);
      goto LABEL_109;
    }
  }
  else
  {
    *(double *)&v134 = _drm_dev_dbg(0, 0, 1, "dcfg->cfg5_en is disabled\n");
  }
  v31 = _reg_dmav1_setup_demurav1_dual_pipe(v111, v153, a3, a4, v134);
  if ( v31 )
    _drm_err("failed setup_demurav1_dual_pipe rc %d", v31);
LABEL_109:
  _ReadStatusReg(SP_EL0);
  return v31;
}
