unsigned __int64 __fastcall reg_dmav1_setup_dspp_3d_gamutv4_common(__int64 a1, _QWORD *a2, int a3)
{
  __int64 v3; // d14
  __int64 v5; // x8
  unsigned int v6; // w4
  int v9; // w0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  int *v14; // x24
  int v15; // w1
  unsigned int v16; // w1
  unsigned __int64 result; // x0
  unsigned int v18; // w1
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  __int64 v23; // x15
  __int64 v24; // d3
  unsigned __int64 v25; // x20
  __int64 v26; // x8
  __int64 v27; // x9
  unsigned __int64 *v28; // x8
  void (__fastcall *v29)(_QWORD); // x9
  unsigned __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x9
  __int64 (__fastcall *v33)(_QWORD); // x8
  unsigned int v34; // w0
  __int64 v35; // x8
  __int64 (__fastcall *v36)(_QWORD); // x9
  int v37; // w9
  int v38; // w23
  int v39; // w27
  int v40; // w28
  unsigned int v41; // w1
  int v42; // w26
  unsigned __int64 v43; // x20
  __int64 v44; // x8
  __int64 v45; // x9
  unsigned __int64 *v46; // x8
  void (__fastcall *v47)(_QWORD); // x9
  unsigned __int64 v48; // x0
  __int64 v49; // x8
  __int64 v50; // x9
  __int64 (__fastcall *v51)(_QWORD); // x8
  __int64 v52; // x8
  __int64 v53; // x9
  __int64 v54; // x1
  __int64 v55; // x10
  unsigned __int64 v56; // x11
  __int64 v57; // x8
  int v58; // w9
  __int64 (__fastcall *v59)(_QWORD); // x8
  __int64 *v60; // x0
  int *v61; // x27
  __int64 i; // x23
  __int64 v63; // x8
  __int64 (__fastcall *v64)(_QWORD); // x8
  unsigned int v65; // w0
  __int64 v66; // x8
  __int64 v67; // x8
  __int64 (__fastcall *v68)(_QWORD); // x8
  unsigned int v69; // w0
  __int64 v70; // x8
  __int64 (__fastcall *v71)(_QWORD); // x9
  __int64 v72; // x4
  __int64 v73; // x8
  __int64 v74; // x5
  __int64 v75; // x10
  int v76; // w6
  __int64 v77; // x9
  unsigned __int64 v78; // x8
  __int64 v79; // x8
  __int64 v80; // x8
  int v81; // w23
  __int64 v82; // x8
  __int64 (__fastcall *v83)(_QWORD); // x8
  unsigned int v84; // w0
  __int64 v85; // x1
  __int64 v86; // x8
  __int64 v87; // x8
  _DWORD *v88; // x8
  unsigned int v89; // w0
  __int64 v90; // x8
  __int64 v91; // x8
  _DWORD *v92; // x9
  unsigned int v93; // w0
  int v94; // [xsp+14h] [xbp-15Ch]
  int v95; // [xsp+1Ch] [xbp-154h]
  int v96; // [xsp+20h] [xbp-150h] BYREF
  int v97; // [xsp+24h] [xbp-14Ch] BYREF
  __int64 v98; // [xsp+28h] [xbp-148h] BYREF
  __int128 v99; // [xsp+30h] [xbp-140h]
  unsigned __int64 v100; // [xsp+40h] [xbp-130h]
  int *v101; // [xsp+48h] [xbp-128h]
  __int64 v102; // [xsp+50h] [xbp-120h]
  __int64 v103; // [xsp+58h] [xbp-118h]
  __int64 v104; // [xsp+60h] [xbp-110h]
  int v105; // [xsp+68h] [xbp-108h] BYREF
  int v106; // [xsp+6Ch] [xbp-104h] BYREF
  __int64 v107; // [xsp+70h] [xbp-100h] BYREF
  __int64 v108; // [xsp+78h] [xbp-F8h]
  unsigned __int64 v109; // [xsp+80h] [xbp-F0h]
  __int64 v110; // [xsp+88h] [xbp-E8h]
  __int64 v111; // [xsp+90h] [xbp-E0h]
  __int64 v112; // [xsp+98h] [xbp-D8h]
  __int64 v113; // [xsp+A0h] [xbp-D0h]
  __int128 v114; // [xsp+A8h] [xbp-C8h]
  unsigned __int64 v115; // [xsp+B8h] [xbp-B8h]
  __int64 v116; // [xsp+C0h] [xbp-B0h] BYREF
  __int64 v117; // [xsp+C8h] [xbp-A8h] BYREF
  __int128 v118; // [xsp+D0h] [xbp-A0h]
  unsigned __int64 v119; // [xsp+E0h] [xbp-90h]
  int *v120; // [xsp+E8h] [xbp-88h]
  __int64 v121; // [xsp+F0h] [xbp-80h]
  __int64 v122; // [xsp+F8h] [xbp-78h]
  __int64 v123; // [xsp+100h] [xbp-70h]
  int v124; // [xsp+10Ch] [xbp-64h] BYREF
  __int64 v125; // [xsp+110h] [xbp-60h] BYREF
  __int64 v126; // [xsp+118h] [xbp-58h]
  unsigned __int64 v127; // [xsp+120h] [xbp-50h]
  __int64 v128; // [xsp+128h] [xbp-48h]
  __int64 v129; // [xsp+130h] [xbp-40h]
  __int64 v130; // [xsp+138h] [xbp-38h]
  __int64 v131; // [xsp+140h] [xbp-30h]
  int v132; // [xsp+148h] [xbp-28h]
  __int64 v133; // [xsp+14Ch] [xbp-24h]
  int v134; // [xsp+154h] [xbp-1Ch]
  int v135; // [xsp+158h] [xbp-18h]
  int v136; // [xsp+15Ch] [xbp-14h]
  __int64 v137; // [xsp+160h] [xbp-10h]

  v137 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v115 = 0;
  v113 = 0;
  v114 = 0u;
  v111 = 0;
  v112 = 0;
  v109 = 0;
  v110 = 0;
  v107 = 0;
  v108 = 0;
  v105 = 0;
  v103 = 0;
  v104 = 0;
  v101 = nullptr;
  v102 = 0;
  v100 = 0;
  v98 = 0;
  v99 = 0u;
  v96 = 0;
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid cfg %pK ctx %pK\n", a2, (const void *)a1);
    goto LABEL_70;
  }
  v5 = *(unsigned int *)(a1 + 64);
  v6 = *(_DWORD *)(a1 + 1496);
  if ( !a2[2] || (unsigned int)v5 > 4 || v6 >= 2 )
  {
    result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", (const void *)a2[2], v5, 1, v6);
    goto LABEL_70;
  }
  if ( &dspp_buf[2 * v5] == (unsigned __int64 *)-80LL )
  {
    result = _drm_err("invalid dma_buf\n");
    goto LABEL_70;
  }
  if ( *(_DWORD *)(a1 + 28) )
  {
    printk(&unk_243701, "ctx->cap->sblk->gamut.base");
    v9 = 0;
  }
  else
  {
    v9 = sde_reg_read(a1, *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 236LL));
  }
  v14 = (int *)*a2;
  v97 = 0;
  v106 = v9;
  if ( !v14 )
  {
    _drm_dev_dbg(0, 0, 1, "disable gamut feature\n");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "reg_dmav1_setup_dspp_3d_gamutv4_common",
      1010,
      -1,
      *(_DWORD *)(a1 + 64),
      *(_DWORD *)(a1 + 1496),
      *(_DWORD *)(a1 + 28),
      0,
      239);
    v18 = *(_DWORD *)(a1 + 64);
    v124 = 0;
    v122 = 0;
    v123 = 0;
    v120 = nullptr;
    v121 = 0;
    v119 = 0;
    v117 = 0;
    v118 = 0u;
    v116 = 0;
    result = reg_dmav1_get_dspp_blk((__int64)a2, v18, &v116, (_DWORD *)&v116 + 1, v19, v20, v21, v22);
    if ( (_DWORD)result == -114 )
      goto LABEL_70;
    if ( (_DWORD)result == -22 )
      goto LABEL_55;
    result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
    if ( !result )
      goto LABEL_70;
    v25 = result;
    if ( result > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_70;
    v26 = *(unsigned int *)(a1 + 64);
    if ( (unsigned int)v26 < 5 )
    {
      v27 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v27 <= 1 )
      {
        if ( (unsigned __int64)(16 * v26 + 8 * v27 + 80) > 0x7D0 )
          goto LABEL_115;
        v28 = &dspp_buf[2 * v26 + v27];
        v29 = *(void (__fastcall **)(_QWORD))(result + 64);
        v30 = v28[10];
        if ( *((_DWORD *)v29 - 1) != -870478129 )
          __break(0x8229u);
        v29(v30);
        v31 = *(unsigned int *)(a1 + 64);
        LODWORD(v117) = 0;
        v118 = 1u;
        v119 = 0;
        v120 = nullptr;
        v121 = 0;
        v122 = 0;
        v123 = 0;
        HIDWORD(v117) = v116;
        if ( (unsigned int)v31 <= 4 )
        {
          v32 = *(unsigned int *)(a1 + 1496);
          if ( (unsigned int)v32 <= 1 )
          {
            if ( (unsigned __int64)(16 * v31 + 8 * v32 + 80) > 0x7D0 )
              goto LABEL_115;
            DWORD1(v118) = 0;
            v121 = 0;
            v119 = dspp_buf[2 * v31 + 10 + v32];
            v120 = nullptr;
            v33 = *(__int64 (__fastcall **)(_QWORD))(v25 + 8);
            if ( *((_DWORD *)v33 - 1) != -1839634494 )
              __break(0x8228u);
            v34 = v33(&v117);
            if ( v34 )
              goto LABEL_69;
            v35 = *(_QWORD *)(a1 + 72);
            *(_QWORD *)((char *)&v118 + 4) = 0;
            HIDWORD(v118) = *(_DWORD *)(*(_QWORD *)(v35 + 48) + 236LL);
            v120 = &v124;
            v121 = 0x400000000LL;
            v36 = *(__int64 (__fastcall **)(_QWORD))(v25 + 8);
            LODWORD(v117) = 1;
            if ( *((_DWORD *)v36 - 1) != -1839634494 )
              __break(0x8229u);
            result = v36(&v117);
            if ( (_DWORD)result )
              goto LABEL_35;
            v52 = *(unsigned int *)(a1 + 64);
            v53 = a2[2];
            v129 = 0;
            v130 = 0;
            v127 = 0;
            v128 = 0;
            v125 = v53;
            v126 = 0;
            if ( (unsigned int)v52 <= 4 )
            {
              v54 = *(unsigned int *)(a1 + 1496);
              if ( (unsigned int)v54 <= 1 )
              {
                if ( (unsigned __int64)(16 * v52 + 8 * v54 + 80) <= 0x7D0 )
                {
                  v55 = a2[19];
                  v133 = *(_QWORD *)((char *)a2 + 164);
                  LODWORD(v126) = 1;
                  LODWORD(v130) = 1;
                  v56 = dspp_buf[2 * v52 + 10 + v54];
                  v57 = *(unsigned int *)(a1 + 28);
                  v131 = v55;
                  v58 = *((_DWORD *)a2 + 43);
                  LODWORD(v55) = *((_DWORD *)a2 + 44);
                  v127 = v56;
                  v135 = v58;
                  v136 = v55;
                  LODWORD(v55) = *((_DWORD *)a2 + 7);
                  v132 = *((_DWORD *)a2 + 40);
                  v134 = v55;
                  if ( (unsigned int)v57 <= 2 )
                  {
                    v59 = *(__int64 (__fastcall **)(_QWORD))(v25 + 8 * v57 + 16);
                    if ( !v59 )
                      goto LABEL_70;
                    v60 = &v125;
LABEL_77:
                    if ( *((_DWORD *)v59 - 1) != 1772228465 )
                      __break(0x8228u);
                    result = v59(v60);
                    if ( (_DWORD)result )
                      result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
                    goto LABEL_70;
                  }
                  goto LABEL_114;
                }
                goto LABEL_115;
              }
            }
          }
        }
      }
    }
LABEL_114:
    __break(0x5512u);
    goto LABEL_115;
  }
  v15 = *((_DWORD *)a2 + 2);
  if ( v15 != 39536 )
  {
    result = _drm_err("invalid size of payload len %d exp %zd\n", v15, 0x9A70u);
    goto LABEL_70;
  }
  v16 = v14[2];
  if ( v16 >= 4 )
  {
    _drm_err("invalid mode %d", v16);
LABEL_13:
    result = _drm_err("invalid mode info rc %d\n", 4294967274LL);
LABEL_70:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  switch ( v16 )
  {
    case 1u:
      v39 = 0;
      v37 = 0;
      v38 = 16;
      v40 = 9832;
      break;
    case 3u:
      if ( (v9 & 0xC) == 8 )
        v39 = 640;
      else
        v39 = 0;
      if ( (v9 & 0xC) == 8 )
        v37 = 12;
      else
        v37 = 8;
      if ( (v9 & 0xC) == 8 )
        v38 = 224;
      else
        v38 = 16;
      v40 = 4400;
      break;
    case 2u:
      v37 = 4;
      v38 = 224;
      v39 = 1248;
      v40 = 256;
      break;
    default:
      goto LABEL_13;
  }
  v41 = *(_DWORD *)(a1 + 64);
  v42 = 2 * (*v14 & 1);
  v106 = v37 | v42 | 1;
  result = reg_dmav1_get_dspp_blk((__int64)a2, v41, &v96, &v97, v10, v11, v12, v13);
  if ( (_DWORD)result == -114 )
    goto LABEL_70;
  if ( (_DWORD)result == -22 )
  {
LABEL_55:
    result = _drm_err("unable to determine LUTDMA DSPP blocks\n");
    goto LABEL_70;
  }
  result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
  if ( !result )
    goto LABEL_70;
  v43 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_70;
  v44 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v44 >= 5 )
    goto LABEL_114;
  v45 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v45 > 1 )
    goto LABEL_114;
  if ( (unsigned __int64)(16 * v44 + 8 * v45 + 80) > 0x7D0 )
    goto LABEL_115;
  v46 = &dspp_buf[2 * v44 + v45];
  v47 = *(void (__fastcall **)(_QWORD))(result + 64);
  v48 = v46[10];
  if ( *((_DWORD *)v47 - 1) != -870478129 )
    __break(0x8229u);
  v47(v48);
  v49 = *(unsigned int *)(a1 + 64);
  LODWORD(v98) = 0;
  v100 = 0;
  v101 = nullptr;
  v102 = 0;
  v103 = 0;
  v104 = 0;
  HIDWORD(v98) = v96;
  v99 = 1u;
  if ( (unsigned int)v49 > 4 )
    goto LABEL_114;
  v50 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v50 > 1 )
    goto LABEL_114;
  if ( (unsigned __int64)(16 * v49 + 8 * v50 + 80) <= 0x7D0 )
  {
    HIDWORD(v99) = 0;
    DWORD1(v99) = 0;
    v102 = 0;
    v100 = dspp_buf[2 * v49 + 10 + v50];
    v101 = nullptr;
    v51 = *(__int64 (__fastcall **)(_QWORD))(v43 + 8);
    if ( *((_DWORD *)v51 - 1) != -1839634494 )
      __break(0x8228u);
    v34 = v51(&v98);
    if ( v34 )
    {
LABEL_69:
      result = _drm_err("write decode select failed ret %d\n", v34);
      goto LABEL_70;
    }
    v95 = v39;
    v61 = v14 + 51;
    v94 = v38;
    for ( i = 0; i != 4; ++i )
    {
      v63 = *(_QWORD *)(a1 + 72);
      *(_QWORD *)((char *)&v99 + 4) = 0;
      HIDWORD(v99) = *(_DWORD *)(*(_QWORD *)(v63 + 48) + 236LL) + 4;
      v101 = &v105;
      v102 = 0x400000000LL;
      v105 = (4096 << i) | v95;
      v64 = *(__int64 (__fastcall **)(_QWORD))(v43 + 8);
      LODWORD(v98) = 1;
      if ( *((_DWORD *)v64 - 1) != -1839634494 )
        __break(0x8228u);
      v65 = v64(&v98);
      if ( v65 )
      {
        result = _drm_err("write tbl sel reg failed ret %d\n", v65);
        goto LABEL_70;
      }
      v66 = *(_QWORD *)(a1 + 72);
      v101 = v61;
      *(_QWORD *)((char *)&v99 + 4) = 2;
      v67 = *(_QWORD *)(v66 + 48);
      LODWORD(v98) = 4;
      HIDWORD(v99) = *(_DWORD *)(v67 + 236) + 12;
      LODWORD(v102) = 0;
      HIDWORD(v102) = v40;
      v68 = *(__int64 (__fastcall **)(_QWORD))(v43 + 8);
      if ( *((_DWORD *)v68 - 1) != -1839634494 )
        __break(0x8228u);
      v69 = v68(&v98);
      if ( v69 )
      {
        result = _drm_err("write color reg failed ret %d\n", v69);
        goto LABEL_70;
      }
      v61 += 2458;
    }
    if ( v42 )
    {
      v80 = *(_QWORD *)(a1 + 72);
      if ( v94 == 16 )
        v81 = 64;
      else
        v81 = a3;
      *(_QWORD *)((char *)&v99 + 4) = 0;
      v82 = *(_QWORD *)(v80 + 48);
      v101 = v14 + 3;
      LODWORD(v102) = 0;
      HIDWORD(v102) = v81;
      LODWORD(v82) = *(_DWORD *)(v82 + 236);
      LODWORD(v98) = 2;
      HIDWORD(v99) = v94 + v82;
      v83 = *(__int64 (__fastcall **)(_QWORD))(v43 + 8);
      if ( *((_DWORD *)v83 - 1) != -1839634494 )
        __break(0x8228u);
      v84 = v83(&v98);
      v85 = v84;
      if ( v84 )
        goto LABEL_113;
      v86 = *(_QWORD *)(a1 + 72);
      *(_QWORD *)((char *)&v99 + 4) = 0;
      v87 = *(_QWORD *)(v86 + 48);
      v101 = v14 + 19;
      LODWORD(v102) = 0;
      HIDWORD(v102) = v81;
      LODWORD(v87) = *(_DWORD *)(v87 + 236);
      LODWORD(v98) = 2;
      HIDWORD(v99) = v81 + v94 + v87;
      v88 = *(_DWORD **)(v43 + 8);
      if ( *(v88 - 1) != -1839634494 )
        __break(0x8228u);
      v89 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v88)(&v98, v84);
      v85 = v89;
      if ( v89 )
        goto LABEL_113;
      v90 = *(_QWORD *)(a1 + 72);
      *(_QWORD *)((char *)&v99 + 4) = 0;
      v91 = *(_QWORD *)(v90 + 48);
      v101 = v14 + 35;
      LODWORD(v102) = 0;
      HIDWORD(v102) = v81;
      HIDWORD(v99) = v94 + 2 * v81 + *(_DWORD *)(v91 + 236);
      v92 = *(_DWORD **)(v43 + 8);
      LODWORD(v98) = 2;
      if ( *(v92 - 1) != -1839634494 )
        __break(0x8229u);
      v93 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v92)(&v98, v89);
      v85 = v93;
      if ( v93 )
      {
LABEL_113:
        result = _drm_err("write scale/off reg failed ret %d\n", v85);
        goto LABEL_70;
      }
    }
    v70 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)((char *)&v99 + 4) = 0;
    HIDWORD(v99) = *(_DWORD *)(*(_QWORD *)(v70 + 48) + 236LL);
    v101 = &v106;
    v102 = 0x400000000LL;
    v71 = *(__int64 (__fastcall **)(_QWORD))(v43 + 8);
    LODWORD(v98) = 1;
    if ( *((_DWORD *)v71 - 1) != -1839634494 )
      __break(0x8229u);
    LODWORD(result) = v71(&v98);
    if ( !(_DWORD)result )
    {
      v72 = *(unsigned int *)(a1 + 64);
      v73 = a2[2];
      v111 = 0;
      v112 = 0;
      v109 = 0;
      v110 = 0;
      v107 = v73;
      v108 = 0;
      if ( (unsigned int)v72 <= 4 )
      {
        v74 = *(unsigned int *)(a1 + 1496);
        if ( (unsigned int)v74 <= 1 )
        {
          if ( (unsigned __int64)(16 * v72 + 8 * v74 + 80) > 0x7D0 )
            goto LABEL_115;
          v75 = a2[19];
          LODWORD(v108) = 1;
          v76 = *(_DWORD *)(a1 + 28);
          LODWORD(v112) = 1;
          v77 = *(_QWORD *)((char *)a2 + 164);
          v113 = v75;
          v78 = dspp_buf[2 * v72 + 10 + v74];
          *(_QWORD *)((char *)&v114 + 4) = v77;
          LODWORD(v77) = *((_DWORD *)a2 + 43);
          LODWORD(v75) = *((_DWORD *)a2 + 44);
          v109 = v78;
          LODWORD(v78) = *((_DWORD *)a2 + 40);
          LODWORD(v111) = 0;
          v115 = __PAIR64__(v75, v77);
          LODWORD(v77) = *((_DWORD *)a2 + 7);
          LODWORD(v114) = v78;
          HIDWORD(v114) = v77;
          result = sde_evtlog_log(
                     sde_dbg_base_evtlog,
                     "reg_dmav1_setup_dspp_3d_gamutv4_common",
                     1106,
                     -1,
                     v72,
                     v74,
                     v76,
                     1,
                     239);
          v79 = *(unsigned int *)(a1 + 28);
          if ( (unsigned int)v79 <= 2 )
          {
            v59 = *(__int64 (__fastcall **)(_QWORD))(v43 + 8 * v79 + 16);
            if ( !v59 )
              goto LABEL_70;
            v60 = &v107;
            goto LABEL_77;
          }
        }
      }
      goto LABEL_114;
    }
LABEL_35:
    result = _drm_err("opmode write single reg failed ret %d\n", (unsigned int)result);
    goto LABEL_70;
  }
LABEL_115:
  __break(1u);
  *(_QWORD *)(v23 - 24) = v3;
  *(_QWORD *)(v23 - 16) = v24;
  return reg_dmav1_setup_dspp_3d_gamutv41();
}
