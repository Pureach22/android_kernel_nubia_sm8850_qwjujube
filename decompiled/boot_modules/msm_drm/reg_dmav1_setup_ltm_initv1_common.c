size_t __fastcall reg_dmav1_setup_ltm_initv1_common(
        int *a1,
        _QWORD *a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7)
{
  __int64 v7; // x15
  __int64 v8; // d14
  const void *v11; // x1
  __int64 v12; // x8
  __int64 v13; // x4
  __int64 v14; // x25
  char *v15; // x22
  size_t result; // x0
  _DWORD *v18; // x26
  __int64 v19; // x24
  int v20; // w1
  unsigned int v21; // w8
  unsigned int v22; // w9
  unsigned int v23; // w13
  unsigned int v24; // w11
  unsigned int v25; // w10
  unsigned int v26; // w11
  __int64 v27; // x0
  size_t v28; // x21
  __int64 v29; // x8
  void (__fastcall *v30)(_QWORD); // x9
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x8
  __int64 (__fastcall *v34)(_QWORD); // x8
  unsigned int v35; // w0
  __int64 v36; // x22
  size_t v37; // x21
  __int64 v38; // x8
  __int64 (__fastcall *v39)(_QWORD); // x9
  __int64 v40; // x0
  __int64 v41; // x1
  int v42; // w8
  int v43; // w8
  int v44; // w26
  __int64 v45; // x27
  int v46; // w8
  __int64 (__fastcall *v47)(_QWORD); // x9
  __int64 v48; // x8
  char *v49; // x9
  int v50; // w10
  __int64 (__fastcall *v51)(_QWORD); // x8
  __int64 v52; // x8
  __int64 (__fastcall *v53)(_QWORD); // x9
  unsigned int v54; // w0
  __int64 v55; // x8
  __int64 v56; // x10
  __int64 v57; // x8
  int v58; // w9
  int v59; // w11
  __int64 v60; // x8
  int v61; // w9
  __int64 (__fastcall *v62)(_QWORD); // x8
  __int64 *v63; // x0
  __int64 v64; // x28
  __int64 v65; // x24
  int v66; // w8
  __int64 (__fastcall *v67)(_QWORD); // x9
  __int64 (__fastcall *v68)(_QWORD); // x8
  __int64 v69; // x8
  __int64 v70; // x10
  char *v71; // x9
  int v72; // w13
  unsigned int v73; // w11
  unsigned int v74; // w11
  __int64 (__fastcall *v75)(_QWORD); // x8
  __int64 v76; // x5
  __int64 v77; // x8
  __int64 v78; // x8
  __int64 v79; // x9
  int v80; // w10
  __int64 v81; // x8
  int v82; // w4
  int v83; // w6
  unsigned int v84; // w10
  __int64 v85; // x8
  __int64 v86; // [xsp+8h] [xbp-1A8h]
  char *v87; // [xsp+10h] [xbp-1A0h]
  __int64 v88; // [xsp+18h] [xbp-198h]
  __int64 v89; // [xsp+18h] [xbp-198h]
  __int64 v90; // [xsp+20h] [xbp-190h] BYREF
  __int64 v91; // [xsp+28h] [xbp-188h] BYREF
  __int64 v92; // [xsp+30h] [xbp-180h]
  __int64 v93; // [xsp+38h] [xbp-178h]
  __int64 v94; // [xsp+40h] [xbp-170h]
  __int64 v95; // [xsp+48h] [xbp-168h]
  __int64 v96; // [xsp+50h] [xbp-160h]
  __int64 v97; // [xsp+58h] [xbp-158h]
  __int128 v98; // [xsp+60h] [xbp-150h]
  unsigned __int64 v99; // [xsp+70h] [xbp-140h]
  __int64 v100; // [xsp+78h] [xbp-138h] BYREF
  __int128 v101; // [xsp+80h] [xbp-130h]
  __int64 v102; // [xsp+90h] [xbp-120h]
  __int64 *v103; // [xsp+98h] [xbp-118h]
  __int64 v104; // [xsp+A0h] [xbp-110h]
  __int64 v105; // [xsp+A8h] [xbp-108h]
  __int64 v106; // [xsp+B0h] [xbp-100h]
  int v107; // [xsp+BCh] [xbp-F4h] BYREF
  __int64 v108; // [xsp+C0h] [xbp-F0h] BYREF
  __int64 v109; // [xsp+C8h] [xbp-E8h]
  __int64 v110; // [xsp+D0h] [xbp-E0h]
  _QWORD v111[5]; // [xsp+D8h] [xbp-D8h] BYREF
  int v112; // [xsp+100h] [xbp-B0h]
  int v113; // [xsp+104h] [xbp-ACh]
  int v114; // [xsp+108h] [xbp-A8h]
  int v115; // [xsp+10Ch] [xbp-A4h]
  __int64 v116; // [xsp+110h] [xbp-A0h] BYREF
  __int128 v117; // [xsp+118h] [xbp-98h]
  __int64 v118; // [xsp+128h] [xbp-88h]
  int *v119; // [xsp+130h] [xbp-80h]
  __int64 v120; // [xsp+138h] [xbp-78h]
  __int64 v121; // [xsp+140h] [xbp-70h]
  __int64 v122; // [xsp+148h] [xbp-68h]
  __int64 v123; // [xsp+150h] [xbp-60h] BYREF
  unsigned int v124; // [xsp+158h] [xbp-58h]
  _QWORD v125[2]; // [xsp+160h] [xbp-50h] BYREF
  int v126; // [xsp+170h] [xbp-40h]
  __int64 v127; // [xsp+178h] [xbp-38h] BYREF
  __int64 v128; // [xsp+180h] [xbp-30h]
  __int64 v129; // [xsp+188h] [xbp-28h]
  unsigned __int64 v130; // [xsp+190h] [xbp-20h]
  int v131; // [xsp+198h] [xbp-18h]
  __int64 v132; // [xsp+1A0h] [xbp-10h]

  v132 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v105 = 0;
  v106 = 0;
  v103 = nullptr;
  v104 = 0;
  v102 = 0;
  v100 = 0;
  v101 = 0u;
  v99 = 0;
  v97 = 0;
  v98 = 0u;
  v95 = 0;
  v96 = 0;
  v93 = 0;
  v94 = 0;
  v91 = 0;
  v92 = 0;
  v131 = 0;
  v129 = 0;
  v130 = 0;
  v127 = 0;
  v128 = 0;
  v126 = 0;
  v125[0] = 0;
  v125[1] = 0;
  v90 = 0;
  v124 = 0;
  v123 = 0;
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid ctx %pK cfg %pK\n", a1, a2);
    goto LABEL_39;
  }
  v11 = (const void *)a2[2];
  v12 = (unsigned int)a1[16];
  v13 = (unsigned int)a1[374];
  if ( !v11 || (unsigned int)v12 > 4 || (unsigned int)v13 >= 2 )
  {
    result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", v11, v12, 15, v13);
    goto LABEL_39;
  }
  v14 = 16 * v12;
  if ( (unsigned __int64)(16 * v12 + 8 * v13 + 1200) > 0x7CF )
    goto LABEL_109;
  v15 = (char *)&ltm_buf + 16 * v12;
  if ( !*(_QWORD *)&v15[8 * v13 + 1200] )
  {
    result = _drm_err("invalid dma_buf\n");
    goto LABEL_39;
  }
  result = reg_dmav1_get_ltm_blk(a2, (unsigned int)v12, v125, (char *)&v90 + 4);
  if ( (_DWORD)result == -114 )
  {
LABEL_39:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (_DWORD)result )
  {
    result = _drm_err("failed to get the blk info\n");
    goto LABEL_39;
  }
  v18 = (_DWORD *)*a2;
  v19 = *((unsigned int *)a2 + 7);
  if ( *a2 )
  {
    v20 = *((_DWORD *)a2 + 2);
    if ( v20 != 16 )
    {
      result = _drm_err("invalid size of payload len %d exp %zd\n", v20, 0x10u);
      goto LABEL_39;
    }
    v22 = *((_DWORD *)a2 + 10);
    v21 = *((_DWORD *)a2 + 11);
    v131 = 0;
    if ( v21 >= v22 )
      v23 = 117440512;
    else
      v23 = 50331648;
    if ( v21 >= v22 )
      v24 = 50331648;
    else
      v24 = 117440512;
    v25 = v23 / (v21 - 1);
    LOBYTE(v131) = v21 < v22;
    BYTE1(v131) = (_DWORD)v19 != 1;
    v127 = 0x80000000000000LL;
    v128 = 0x80000000800000LL;
    v129 = 0x80000000800000LL;
    v26 = v24 / (v22 - 1);
    v130 = __PAIR64__(v26, v25);
    if ( (_DWORD)v19 != 1 )
    {
      LODWORD(v128) = v25 * (v21 >> 1) + 0x800000;
      LODWORD(v129) = v128;
    }
    v27 = (unsigned int)a1[374];
    LODWORD(v123) = 0x800000;
    HIDWORD(v123) = v23 / (v21 - 1);
    v124 = v26;
    LODWORD(v90) = 4 * (v21 < v22);
    result = sde_reg_dma_get_ops(v27);
    if ( !result )
      goto LABEL_39;
    v28 = result;
    if ( result > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_39;
    v29 = (unsigned int)a1[374];
    if ( (unsigned int)v29 > 1 )
      goto LABEL_110;
    if ( (unsigned __int64)(v14 + 8 * v29 + 1200) <= 0x7CF )
    {
      v30 = *(void (__fastcall **)(_QWORD))(result + 64);
      v31 = *(_QWORD *)&v15[8 * v29 + 1200];
      if ( *((_DWORD *)v30 - 1) != -870478129 )
        __break(0x8229u);
      v30(v31);
      v32 = (unsigned int)a1[374];
      LODWORD(v100) = 0;
      v102 = 0;
      v103 = nullptr;
      v104 = 0;
      v105 = 0;
      v106 = 0;
      HIDWORD(v100) = HIDWORD(v90);
      v101 = 0xFu;
      if ( (unsigned int)v32 > 1 )
        goto LABEL_110;
      if ( (unsigned __int64)(v14 + 8 * v32 + 1200) <= 0x7CF )
      {
        HIDWORD(v101) = 0;
        DWORD1(v101) = 0;
        v33 = *(_QWORD *)&v15[8 * v32 + 1200];
        v104 = 0;
        v102 = v33;
        v103 = nullptr;
        v34 = *(__int64 (__fastcall **)(_QWORD))(v28 + 8);
        if ( *((_DWORD *)v34 - 1) != -1839634494 )
          __break(0x8228u);
        v35 = v34(&v100);
        if ( v35 )
        {
LABEL_31:
          result = _drm_err("write decode select failed ret %d\n", v35);
          goto LABEL_39;
        }
        *(_QWORD *)((char *)&v101 + 4) = 0;
        HIDWORD(v101) = 12;
        v103 = &v123;
        v104 = 0xC00000000LL;
        v53 = *(__int64 (__fastcall **)(_QWORD))(v28 + 8);
        LODWORD(v100) = 2;
        if ( *((_DWORD *)v53 - 1) != -1839634494 )
          __break(0x8229u);
        v54 = v53(&v100);
        if ( v54 )
        {
          result = _drm_err("write phase data failed ret %d\n", v54);
          goto LABEL_39;
        }
        if ( (_DWORD)v19 )
        {
          v64 = 0;
          v89 = 4 * v19;
          while ( v64 != 20 )
          {
            v65 = *(unsigned int *)((char *)v125 + v64);
            if ( (unsigned int)v65 > 4 )
              break;
            HIDWORD(v101) = 0;
            *(_QWORD *)((char *)&v101 + 4) = 0;
            v66 = ltm_mapping[v65];
            v103 = nullptr;
            v104 = 0;
            v67 = *(__int64 (__fastcall **)(_QWORD))(v28 + 8);
            LODWORD(v100) = 0;
            HIDWORD(v100) = v66;
            if ( *((_DWORD *)v67 - 1) != -1839634494 )
              __break(0x8229u);
            v35 = v67(&v100);
            if ( v35 )
              goto LABEL_31;
            *(_QWORD *)((char *)&v101 + 4) = 0;
            HIDWORD(v101) = 8;
            v103 = (__int64 *)((char *)&v127 + 4 * v65);
            v104 = 0x400000000LL;
            v68 = *(__int64 (__fastcall **)(_QWORD))(v28 + 8);
            LODWORD(v100) = 1;
            if ( *((_DWORD *)v68 - 1) != -1839634494 )
              __break(0x8228u);
            LODWORD(result) = v68(&v100);
            if ( (_DWORD)result )
              goto LABEL_108;
            v69 = (unsigned int)a1[374];
            v70 = 8 * v65;
            v71 = (char *)&ltm_vlut_ops_mask + 8 * v65;
            if ( *v18 )
            {
              if ( (unsigned int)v69 > 1 )
                goto LABEL_110;
              if ( (v70 | (unsigned __int64)(4 * v69)) > 0x27 )
                goto LABEL_109;
              v72 = v90;
              v73 = *(_DWORD *)&v71[4 * v69] | 2;
              *(_DWORD *)&v71[4 * v69] = v73;
              LODWORD(v90) = v72 | a3 | ((v18[1] & 7) << 12);
            }
            else
            {
              if ( (unsigned int)v69 > 1 )
                goto LABEL_110;
              if ( (v70 | (unsigned __int64)(4 * v69)) > 0x27 )
                goto LABEL_109;
              v73 = *(_DWORD *)&v71[4 * v69] & 0xFFFFFFFD;
              *(_DWORD *)&v71[4 * v69] = v73;
            }
            if ( v18[2] )
            {
              v74 = v73 | 1;
              LODWORD(v90) = ((v18[3] & 3) << 8) | v90;
            }
            else
            {
              v74 = v73 & 0xFFFFFFFE;
            }
            if ( (unsigned __int64)(v70 + 4 * v69) > 0x27 )
              goto LABEL_109;
            *(_DWORD *)&v71[4 * v69] = v74 | 0x10;
            HIDWORD(v101) = 4;
            v103 = &v90;
            *(_QWORD *)((char *)&v101 + 4) = 0;
            LODWORD(v100) = 5;
            v104 = 0x401100053LL;
            v75 = *(__int64 (__fastcall **)(_QWORD))(v28 + 8);
            if ( *((_DWORD *)v75 - 1) != -1839634494 )
              __break(0x8228u);
            LODWORD(result) = v75(&v100);
            if ( (_DWORD)result )
              goto LABEL_108;
            v64 += 4;
            if ( v89 == v64 )
              goto LABEL_103;
          }
          goto LABEL_110;
        }
LABEL_103:
        v76 = (unsigned int)a1[374];
        v77 = a2[2];
        v95 = 0;
        v96 = 0;
        v93 = 0;
        v94 = 0;
        v91 = v77;
        v92 = 0;
        if ( (unsigned int)v76 > 1 )
          goto LABEL_110;
        if ( (unsigned __int64)(v14 + 8 * v76 + 1200) <= 0x7CF )
        {
          LODWORD(v92) = 1;
          v78 = a2[19];
          LODWORD(v96) = 15;
          v79 = *(_QWORD *)&v15[8 * v76 + 1200];
          v80 = *((_DWORD *)a2 + 40);
          v97 = v78;
          v81 = *(_QWORD *)((char *)a2 + 164);
          v93 = v79;
          v82 = a1[16];
          *(_QWORD *)((char *)&v98 + 4) = v81;
          LODWORD(v81) = *((_DWORD *)a2 + 7);
          LODWORD(v98) = v80;
          v83 = a1[7];
          v84 = *((_DWORD *)a2 + 43);
          LODWORD(v79) = *((_DWORD *)a2 + 44);
          HIDWORD(v98) = v81;
          LODWORD(v95) = 0;
          v99 = __PAIR64__(v79, v84);
          result = sde_evtlog_log(
                     sde_dbg_base_evtlog,
                     "reg_dmav1_setup_ltm_initv1_common",
                     5243,
                     -1,
                     v82,
                     v76,
                     v83,
                     1,
                     239);
          v85 = (unsigned int)a1[7];
          if ( (unsigned int)v85 <= 2 )
          {
            v62 = *(__int64 (__fastcall **)(_QWORD))(v28 + 8 * v85 + 16);
            if ( !v62 )
              goto LABEL_39;
            v63 = &v91;
            goto LABEL_74;
          }
          goto LABEL_110;
        }
      }
    }
    goto LABEL_109;
  }
  _drm_dev_dbg(0, 0, 1, "Disable LTM init feature\n");
  sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_ltm_initv1_common", 5144, -1, a1[16], a1[374], a1[7], 0, 239);
  v36 = (unsigned int)a1[16];
  v121 = 0;
  v122 = 0;
  v119 = nullptr;
  v120 = 0;
  v118 = 0;
  v116 = 0;
  v117 = 0u;
  v107 = 0;
  if ( (unsigned int)v36 >= 5 )
  {
    result = _drm_err("invalid ltm idx %d\n", (unsigned int)v36);
    goto LABEL_39;
  }
  result = sde_reg_dma_get_ops((unsigned int)a1[374]);
  if ( !result )
    goto LABEL_39;
  v37 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_39;
  v38 = (unsigned int)a1[374];
  if ( (unsigned int)v38 >= 2 )
    goto LABEL_110;
  v88 = 16 * v36;
  v86 = 16 * v36 + 1200;
  if ( (v86 | (unsigned __int64)(8 * v38)) > 0x7D0 )
    goto LABEL_109;
  v87 = (char *)&ltm_buf + 16 * v36;
  v39 = *(__int64 (__fastcall **)(_QWORD))(result + 64);
  v40 = *(_QWORD *)&v87[8 * v38 + 1200];
  if ( *((_DWORD *)v39 - 1) != -870478129 )
    __break(0x8229u);
  result = v39(v40);
  v41 = (unsigned int)a1[374];
  v42 = ltm_mapping[v36];
  LODWORD(v116) = 0;
  v117 = 0xFu;
  v118 = 0;
  HIDWORD(v116) = v42;
  v119 = nullptr;
  v120 = 0;
  v121 = 0;
  v122 = 0;
  if ( (unsigned int)v41 > 1 )
    goto LABEL_110;
  if ( (unsigned __int64)(v88 + 8 * v41 + 1200) > 0x7D0 )
    goto LABEL_109;
  v118 = *(_QWORD *)&v87[8 * v41 + 1200];
  if ( (_DWORD)v19 )
  {
    v43 = 0;
    while ( (unsigned __int64)(4LL * v43) <= 0x14 && v43 != 5 )
    {
      v44 = v43;
      v45 = *((unsigned int *)v125 + v43);
      if ( (unsigned int)v45 > 4 )
        goto LABEL_110;
      HIDWORD(v117) = 0;
      *(_QWORD *)((char *)&v117 + 4) = 0;
      v46 = ltm_mapping[v45];
      v119 = nullptr;
      v120 = 0;
      v47 = *(__int64 (__fastcall **)(_QWORD))(v37 + 8);
      LODWORD(v116) = 0;
      HIDWORD(v116) = v46;
      if ( *((_DWORD *)v47 - 1) != -1839634494 )
        __break(0x8229u);
      v35 = v47(&v116);
      if ( v35 )
        goto LABEL_31;
      v48 = (unsigned int)a1[374];
      if ( (unsigned int)v48 > 1 )
        goto LABEL_110;
      if ( ((4 * v48) | (unsigned __int64)(8 * v45)) > 0x27 )
        break;
      v49 = (char *)&ltm_vlut_ops_mask + 8 * v45;
      v119 = &v107;
      HIDWORD(v117) = 4;
      v50 = *(_DWORD *)&v49[4 * v48];
      *(_QWORD *)((char *)&v117 + 4) = 0;
      LODWORD(v120) = ~a3 & 0xFFFF8CAF;
      HIDWORD(v120) = 4;
      *(_DWORD *)&v49[4 * v48] = v50 & 0xFFFFFFEC;
      v51 = *(__int64 (__fastcall **)(_QWORD))(v37 + 8);
      LODWORD(v116) = 5;
      if ( *((_DWORD *)v51 - 1) != -1839634494 )
        __break(0x8228u);
      result = v51(&v116);
      if ( (_DWORD)result )
      {
LABEL_108:
        result = _drm_err("opmode write failed ret %d\n", (unsigned int)result);
        goto LABEL_39;
      }
      v43 = v44 + 1;
      if ( (_DWORD)v19 == v44 + 1 )
      {
        v41 = (unsigned int)a1[374];
        v52 = a2[2];
        v110 = 0;
        memset(v111, 0, 24);
        v108 = v52;
        v109 = 0;
        if ( (unsigned int)v41 <= 1 )
          goto LABEL_69;
        goto LABEL_110;
      }
    }
    goto LABEL_109;
  }
  v55 = a2[2];
  v110 = 0;
  memset(v111, 0, 24);
  v108 = v55;
  v109 = 0;
LABEL_69:
  if ( (v86 | (unsigned __int64)(8 * v41)) > 0x7D0 || (unsigned __int64)(v88 + 8 * v41 + 1200) > 0x7CF )
  {
LABEL_109:
    __break(1u);
    goto LABEL_110;
  }
  *(_QWORD *)((char *)v111 + 4) = 0;
  LODWORD(v109) = 1;
  *(_QWORD *)((char *)&v111[1] + 4) = 0xF00000000LL;
  v56 = a2[20];
  v57 = *(_QWORD *)&v87[8 * v41 + 1200];
  v111[3] = a2[19];
  v111[4] = v56;
  LODWORD(v56) = *((_DWORD *)a2 + 42);
  v59 = *((_DWORD *)a2 + 43);
  v58 = *((_DWORD *)a2 + 44);
  v110 = v57;
  v60 = (unsigned int)a1[7];
  v112 = v56;
  v115 = v58;
  v61 = *((_DWORD *)a2 + 7);
  v114 = v59;
  v113 = v61;
  if ( (unsigned int)v60 <= 2 )
  {
    v62 = *(__int64 (__fastcall **)(_QWORD))(v37 + 8 * v60 + 16);
    if ( !v62 )
      goto LABEL_39;
    v63 = &v108;
LABEL_74:
    if ( *((_DWORD *)v62 - 1) != 1772228465 )
      __break(0x8228u);
    result = v62(v63);
    if ( (_DWORD)result )
      result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
    goto LABEL_39;
  }
LABEL_110:
  __break(0x5512u);
  *(_QWORD *)(v7 - 24) = v8;
  *(double *)(v7 - 16) = a7;
  return reg_dmav1_setup_ltm_initv1_4();
}
