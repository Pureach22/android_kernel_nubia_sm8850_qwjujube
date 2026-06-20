unsigned __int64 __fastcall reg_dmav1_setup_dspp_igcv31(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6)
{
  __int64 v7; // x8
  unsigned int v8; // w4
  __int64 v9; // x9
  int v10; // w9
  unsigned __int64 result; // x0
  unsigned int v13; // w26
  unsigned int v15; // w1
  _QWORD *v16; // x23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  int v21; // w6
  unsigned __int64 v22; // x20
  __int64 v23; // x8
  __int64 v24; // x9
  unsigned __int64 *v25; // x8
  void (__fastcall *v26)(_QWORD); // x9
  unsigned __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x9
  __int64 (__fastcall *v30)(_QWORD); // x8
  unsigned int v31; // w0
  __int64 v32; // x8
  __int64 (__fastcall *v33)(_QWORD); // x8
  __int64 v34; // x24
  unsigned __int64 v35; // x20
  __int64 v36; // x8
  __int64 v37; // x9
  unsigned __int64 *v38; // x8
  void (__fastcall *v39)(_QWORD); // x9
  unsigned __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x9
  __int64 (__fastcall *v43)(_QWORD); // x8
  int v44; // w8
  int v45; // w26
  __int64 v46; // x8
  __int64 v47; // x9
  __int64 v48; // x1
  __int64 v49; // x9
  __int64 v50; // x11
  int v51; // w10
  unsigned __int64 v52; // x11
  __int64 v53; // x8
  int v54; // w10
  __int64 (__fastcall *v55)(_QWORD); // x8
  __int64 *v56; // x0
  __int64 v57; // x9
  __int64 v58; // x10
  int v59; // w12
  __int64 (__fastcall *v60)(_QWORD); // x9
  unsigned int v61; // w0
  __int64 v62; // x1
  __int64 v63; // x8
  __int64 v64; // x9
  int v65; // w11
  _DWORD *v66; // x9
  unsigned int v67; // w0
  __int64 v68; // x8
  __int64 v69; // x9
  int v70; // w11
  _DWORD *v71; // x9
  unsigned int v72; // w0
  __int64 v73; // x8
  __int64 v74; // x9
  _DWORD *v75; // x8
  __int64 v76; // x8
  char v77; // w9
  int v78; // w10
  __int64 (__fastcall *v79)(_QWORD); // x9
  unsigned int v80; // w0
  __int64 v81; // x8
  __int64 (__fastcall *v82)(_QWORD); // x8
  __int64 v83; // x4
  __int64 v84; // x8
  __int64 v85; // x5
  __int64 v86; // x9
  int v87; // w6
  __int64 v88; // x10
  unsigned __int64 v89; // x8
  __int64 v90; // x8
  int v91; // [xsp+Ch] [xbp-174h] BYREF
  unsigned int v92; // [xsp+10h] [xbp-170h] BYREF
  int v93; // [xsp+14h] [xbp-16Ch] BYREF
  __int64 v94; // [xsp+18h] [xbp-168h] BYREF
  __int128 v95; // [xsp+20h] [xbp-160h]
  unsigned __int64 v96; // [xsp+30h] [xbp-150h]
  int *v97; // [xsp+38h] [xbp-148h]
  __int64 v98; // [xsp+40h] [xbp-140h]
  __int64 v99; // [xsp+48h] [xbp-138h]
  __int64 v100; // [xsp+50h] [xbp-130h]
  __int64 v101; // [xsp+58h] [xbp-128h] BYREF
  __int64 v102; // [xsp+60h] [xbp-120h]
  unsigned __int64 v103; // [xsp+68h] [xbp-118h]
  __int64 v104; // [xsp+70h] [xbp-110h]
  __int64 v105; // [xsp+78h] [xbp-108h]
  __int64 v106; // [xsp+80h] [xbp-100h]
  __int64 v107; // [xsp+88h] [xbp-F8h]
  __int128 v108; // [xsp+90h] [xbp-F0h]
  unsigned __int64 v109; // [xsp+A0h] [xbp-E0h]
  int v110; // [xsp+ACh] [xbp-D4h] BYREF
  __int64 v111; // [xsp+B0h] [xbp-D0h] BYREF
  __int64 v112; // [xsp+B8h] [xbp-C8h] BYREF
  __int128 v113; // [xsp+C0h] [xbp-C0h]
  unsigned __int64 v114; // [xsp+D0h] [xbp-B0h]
  char *v115; // [xsp+D8h] [xbp-A8h]
  __int64 v116; // [xsp+E0h] [xbp-A0h]
  __int64 v117; // [xsp+E8h] [xbp-98h]
  __int64 v118; // [xsp+F0h] [xbp-90h]
  __int64 v119; // [xsp+F8h] [xbp-88h] BYREF
  __int64 v120; // [xsp+100h] [xbp-80h]
  unsigned __int64 v121; // [xsp+108h] [xbp-78h]
  __int64 v122; // [xsp+110h] [xbp-70h]
  __int64 v123; // [xsp+118h] [xbp-68h]
  __int64 v124; // [xsp+120h] [xbp-60h]
  __int64 v125; // [xsp+128h] [xbp-58h]
  int v126; // [xsp+130h] [xbp-50h]
  __int64 v127; // [xsp+134h] [xbp-4Ch]
  int v128; // [xsp+13Ch] [xbp-44h]
  int v129; // [xsp+140h] [xbp-40h]
  int v130; // [xsp+144h] [xbp-3Ch]
  __int64 dest; // [xsp+148h] [xbp-38h] BYREF
  __int64 v132; // [xsp+150h] [xbp-30h]
  __int64 v133; // [xsp+158h] [xbp-28h]
  __int64 v134; // [xsp+160h] [xbp-20h]
  __int64 v135; // [xsp+168h] [xbp-18h]
  __int64 v136; // [xsp+170h] [xbp-10h]

  v136 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v109 = 0;
  v108 = 0u;
  v106 = 0;
  v107 = 0;
  v104 = 0;
  v105 = 0;
  v102 = 0;
  v103 = 0;
  v100 = 0;
  v101 = 0;
  v98 = 0;
  v99 = 0;
  v96 = 0;
  v97 = nullptr;
  v95 = 0u;
  v94 = 0;
  v93 = 0;
  v91 = 0;
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid cfg %pK ctx %pK\n", a2, (const void *)a1);
    goto LABEL_54;
  }
  v7 = *(unsigned int *)(a1 + 64);
  v8 = *(_DWORD *)(a1 + 1496);
  if ( !a2[2] || (unsigned int)v7 > 4 || v8 >= 2 )
  {
    result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", (const void *)a2[2], v7, 2, v8);
    goto LABEL_54;
  }
  if ( &dspp_buf[2 * v7] == (unsigned __int64 *)-160LL )
  {
    result = _drm_err("invalid dma_buf\n");
    goto LABEL_54;
  }
  v9 = *a2;
  v134 = 0;
  v135 = 0;
  v132 = 0;
  v133 = 0;
  dest = 0;
  v92 = 0;
  if ( !v9 )
  {
    _drm_dev_dbg(0, 0, 1, "disable igc feature\n");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "reg_dmav1_setup_dspp_igcv31",
      1512,
      -1,
      *(_DWORD *)(a1 + 64),
      *(_DWORD *)(a1 + 1496),
      *(_DWORD *)(a1 + 28),
      0,
      239);
    v15 = *(_DWORD *)(a1 + 64);
    v117 = 0;
    v118 = 0;
    v16 = a2;
    v115 = nullptr;
    v116 = 0;
    v114 = 0;
    v112 = 0;
    v113 = 0u;
    v111 = 0;
    v110 = 0;
    result = reg_dmav1_get_dspp_blk((__int64)a2, v15, &v110, &v111, v17, v18, v19, v20);
    if ( (_DWORD)result == -114 )
      goto LABEL_54;
    if ( (_DWORD)result != -22 )
    {
      result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
      if ( !result )
        goto LABEL_54;
      v22 = result;
      if ( result > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_54;
      v23 = *(unsigned int *)(a1 + 64);
      if ( (unsigned int)v23 < 5 )
      {
        v24 = *(unsigned int *)(a1 + 1496);
        if ( (unsigned int)v24 <= 1 )
        {
          if ( (unsigned __int64)(16 * v23 + 8 * v24 + 160) > 0x7D0 )
            goto LABEL_111;
          v25 = &dspp_buf[2 * v23 + v24];
          v26 = *(void (__fastcall **)(_QWORD))(result + 64);
          v27 = v25[20];
          if ( *((_DWORD *)v26 - 1) != -870478129 )
            __break(0x8229u);
          v26(v27);
          v28 = *(unsigned int *)(a1 + 64);
          LODWORD(v112) = 0;
          v114 = 0;
          v115 = nullptr;
          v116 = 0;
          v117 = 0;
          v118 = 0;
          HIDWORD(v112) = v110;
          v113 = 2u;
          if ( (unsigned int)v28 <= 4 )
          {
            v29 = *(unsigned int *)(a1 + 1496);
            if ( (unsigned int)v29 <= 1 )
            {
              if ( (unsigned __int64)(16 * v28 + 8 * v29 + 160) > 0x7D0 )
                goto LABEL_111;
              DWORD1(v113) = 0;
              v116 = 0;
              v114 = dspp_buf[2 * v28 + 20 + v29];
              v115 = nullptr;
              v30 = *(__int64 (__fastcall **)(_QWORD))(v22 + 8);
              if ( *((_DWORD *)v30 - 1) != -1839634494 )
                __break(0x8228u);
              v31 = v30(&v112);
              if ( v31 )
                goto LABEL_53;
              v32 = *(_QWORD *)(a1 + 72);
              *(_QWORD *)((char *)&v113 + 4) = 0;
              HIDWORD(v113) = *(_DWORD *)(*(_QWORD *)(v32 + 48) + 20LL);
              v115 = (char *)&v111 + 4;
              v116 = 0x400000000LL;
              v33 = *(__int64 (__fastcall **)(_QWORD))(v22 + 8);
              HIDWORD(v111) = 0;
              LODWORD(v112) = 1;
              if ( *((_DWORD *)v33 - 1) != -1839634494 )
                __break(0x8228u);
              result = v33(&v112);
              if ( (_DWORD)result )
              {
LABEL_36:
                result = _drm_err("setting opcode failed ret %d\n", (unsigned int)result);
                goto LABEL_54;
              }
              v46 = *(unsigned int *)(a1 + 64);
              v47 = v16[2];
              v123 = 0;
              v124 = 0;
              v121 = 0;
              v122 = 0;
              v119 = v47;
              v120 = 0;
              if ( (unsigned int)v46 <= 4 )
              {
                v48 = *(unsigned int *)(a1 + 1496);
                if ( (unsigned int)v48 <= 1 )
                {
                  if ( (unsigned __int64)(16 * v46 + 8 * v48 + 160) <= 0x7D0 )
                  {
                    LODWORD(v120) = 1;
                    v49 = *(_QWORD *)((char *)v16 + 164);
                    v50 = v16[19];
                    LODWORD(v124) = 2;
                    v127 = v49;
                    v51 = *((_DWORD *)v16 + 43);
                    LODWORD(v49) = *((_DWORD *)v16 + 44);
                    v125 = v50;
                    v52 = dspp_buf[2 * v46 + 20 + v48];
                    v53 = *(unsigned int *)(a1 + 28);
                    v129 = v51;
                    v130 = v49;
                    LODWORD(v49) = *((_DWORD *)v16 + 40);
                    v54 = *((_DWORD *)v16 + 7);
                    v121 = v52;
                    v126 = v49;
                    v128 = v54;
                    if ( (unsigned int)v53 <= 2 )
                    {
                      v55 = *(__int64 (__fastcall **)(_QWORD))(v22 + 8 * v53 + 16);
                      if ( !v55 )
                        goto LABEL_54;
                      v56 = &v119;
LABEL_69:
                      if ( *((_DWORD *)v55 - 1) != 1772228465 )
                        __break(0x8228u);
                      result = v55(v56);
                      if ( (_DWORD)result )
                        result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
                      goto LABEL_54;
                    }
                    goto LABEL_110;
                  }
                  goto LABEL_111;
                }
              }
            }
          }
        }
      }
LABEL_110:
      __break(0x5512u);
      goto LABEL_111;
    }
LABEL_18:
    result = _drm_err("unable to determine LUTDMA DSPP blocks\n");
    goto LABEL_54;
  }
  v10 = *((_DWORD *)a2 + 2);
  if ( v10 != 4632 )
  {
    result = _drm_err("invalid size of payload len %d exp %zd\n", v10, 0x1218u);
    goto LABEL_54;
  }
  result = reg_dmav1_get_dspp_blk((__int64)a2, v7, &v91, &v92, a3, a4, a5, a6);
  if ( (_DWORD)result == -114 )
  {
LABEL_54:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (_DWORD)result == -22 )
    goto LABEL_18;
  v13 = v92;
  if ( v92 >= 6 )
  {
    result = _drm_err("unable to process more than %d DSPP blocks\n", 5);
    goto LABEL_54;
  }
  if ( v92 < 2 )
    dest = a1;
  else
    memcpy(&dest, a2 + 6, 8LL * v92);
  v34 = *a2;
  result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
  if ( !result )
    goto LABEL_54;
  v35 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_54;
  v36 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v36 > 4 )
    goto LABEL_110;
  v37 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v37 > 1 )
    goto LABEL_110;
  if ( (unsigned __int64)(16 * v36 + 8 * v37 + 160) > 0x7D0 )
    goto LABEL_111;
  v38 = &dspp_buf[2 * v36 + v37];
  v39 = *(void (__fastcall **)(_QWORD))(result + 64);
  v40 = v38[20];
  if ( *((_DWORD *)v39 - 1) != -870478129 )
    __break(0x8229u);
  v39(v40);
  v41 = *(unsigned int *)(a1 + 64);
  v94 = 0x2000000000000LL;
  v96 = 0;
  v97 = nullptr;
  v98 = 0;
  v99 = 0;
  v100 = 0;
  v95 = 2u;
  if ( (unsigned int)v41 > 4 )
    goto LABEL_110;
  v42 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v42 > 1 )
    goto LABEL_110;
  if ( (unsigned __int64)(16 * v41 + 8 * v42 + 160) > 0x7D0 )
    goto LABEL_111;
  HIDWORD(v95) = 0;
  DWORD1(v95) = 0;
  v98 = 0;
  v96 = dspp_buf[2 * v41 + 20 + v42];
  v97 = nullptr;
  v43 = *(__int64 (__fastcall **)(_QWORD))(v35 + 8);
  if ( *((_DWORD *)v43 - 1) != -1839634494 )
    __break(0x8228u);
  v31 = v43(&v94);
  if ( v31 )
    goto LABEL_53;
  if ( v13 )
  {
    v44 = ~(1 << (*(_DWORD *)(dest + 64) - 1));
    if ( v13 != 1 )
    {
      v44 &= ~(1 << (*(_BYTE *)(v132 + 64) - 1));
      if ( v13 != 2 )
      {
        v44 &= ~(1 << (*(_DWORD *)(v133 + 64) - 1));
        if ( v13 != 3 )
        {
          v44 &= ~(1 << (*(_BYTE *)(v134 + 64) - 1));
          if ( v13 != 4 )
          {
            if ( v13 != 5 )
              goto LABEL_111;
            v44 &= ~(1 << (*(_DWORD *)(v135 + 64) - 1));
          }
        }
      }
    }
    v45 = v44 << 28;
  }
  else
  {
    v45 = -1;
  }
  v57 = 0;
  *(_DWORD *)(v34 + 8) = *(_DWORD *)(v34 + 8) & 0xFFF | v45 | 0x2000000;
  do
  {
    v58 = v34 + v57;
    v57 += 8;
    v59 = *(_DWORD *)(v58 + 16) & 0xFFF | v45;
    *(_DWORD *)(v58 + 12) = *(_DWORD *)(v58 + 12) & 0xFFF | v45;
    *(_DWORD *)(v58 + 16) = v59;
  }
  while ( v57 != 1016 );
  *(_DWORD *)(v34 + 1028) = *(_DWORD *)(v34 + 1028) & 0xFFF | v45;
  HIDWORD(v95) = 0;
  *(_QWORD *)((char *)&v95 + 4) = 0;
  v97 = (int *)(v34 + 8);
  v98 = 0x40000000000LL;
  v60 = *(__int64 (__fastcall **)(_QWORD))(v35 + 8);
  LODWORD(v94) = 3;
  if ( *((_DWORD *)v60 - 1) != -1839634494 )
    __break(0x8229u);
  v61 = v60(&v94);
  v62 = v61;
  if ( v61 )
    goto LABEL_89;
  v63 = 0;
  *(_DWORD *)(v34 + 1032) = *(_DWORD *)(v34 + 1032) & 0xFFF | v45 | 0x2000000;
  do
  {
    v64 = v34 + v63;
    v63 += 8;
    v65 = *(_DWORD *)(v64 + 1040) & 0xFFF | v45;
    *(_DWORD *)(v64 + 1036) = *(_DWORD *)(v64 + 1036) & 0xFFF | v45;
    *(_DWORD *)(v64 + 1040) = v65;
  }
  while ( v63 != 1016 );
  *(_DWORD *)(v34 + 2052) = *(_DWORD *)(v34 + 2052) & 0xFFF | v45;
  HIDWORD(v95) = 4;
  *(_QWORD *)((char *)&v95 + 4) = 0;
  v97 = (int *)(v34 + 1032);
  v98 = 0x40000000000LL;
  v66 = *(_DWORD **)(v35 + 8);
  LODWORD(v94) = 3;
  if ( *(v66 - 1) != -1839634494 )
    __break(0x8229u);
  v67 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v66)(&v94, v61);
  v62 = v67;
  if ( v67 )
    goto LABEL_89;
  v68 = 0;
  *(_DWORD *)(v34 + 2056) = *(_DWORD *)(v34 + 2056) & 0xFFF | v45 | 0x2000000;
  do
  {
    v69 = v34 + v68;
    v68 += 8;
    v70 = *(_DWORD *)(v69 + 2064) & 0xFFF | v45;
    *(_DWORD *)(v69 + 2060) = *(_DWORD *)(v69 + 2060) & 0xFFF | v45;
    *(_DWORD *)(v69 + 2064) = v70;
  }
  while ( v68 != 1016 );
  *(_DWORD *)(v34 + 3076) = *(_DWORD *)(v34 + 3076) & 0xFFF | v45;
  HIDWORD(v95) = 8;
  *(_QWORD *)((char *)&v95 + 4) = 0;
  v97 = (int *)(v34 + 2056);
  v98 = 0x40000000000LL;
  v71 = *(_DWORD **)(v35 + 8);
  LODWORD(v94) = 3;
  if ( *(v71 - 1) != -1839634494 )
    __break(0x8229u);
  v72 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v71)(&v94, v67);
  v62 = v72;
  if ( v72 )
  {
LABEL_89:
    result = _drm_err("lut write failed ret %d\n", v62);
    goto LABEL_54;
  }
  v73 = *(unsigned int *)(a1 + 64);
  LODWORD(v94) = 0;
  v99 = 0;
  v100 = 0;
  v97 = nullptr;
  v98 = 0;
  v96 = 0;
  HIDWORD(v94) = v91;
  v95 = 2u;
  if ( (unsigned int)v73 >= 5 )
    goto LABEL_110;
  v74 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v74 > 1 )
    goto LABEL_110;
  if ( (unsigned __int64)(16 * v73 + 8 * v74 + 160) > 0x7D0 )
    goto LABEL_111;
  HIDWORD(v95) = 0;
  DWORD1(v95) = 0;
  v97 = nullptr;
  v98 = 0;
  v96 = dspp_buf[2 * v73 + 20 + v74];
  v75 = *(_DWORD **)(v35 + 8);
  if ( *(v75 - 1) != -1839634494 )
    __break(0x8228u);
  v31 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v75)(&v94, v72);
  if ( v31 )
  {
LABEL_53:
    result = _drm_err("write decode select failed ret %d\n", v31);
    goto LABEL_54;
  }
  if ( (*(_BYTE *)v34 & 1) != 0 )
  {
    v76 = *(_QWORD *)(a1 + 72);
    v77 = *(_DWORD *)(v34 + 3080);
    *(_QWORD *)((char *)&v95 + 4) = 0;
    HIDWORD(v95) = *(_DWORD *)(*(_QWORD *)(v76 + 48) + 20LL) + 2016;
    v97 = &v93;
    v98 = 0x400000000LL;
    v78 = v77 & 0xF;
    v79 = *(__int64 (__fastcall **)(_QWORD))(v35 + 8);
    v93 = v78;
    LODWORD(v94) = 1;
    if ( *((_DWORD *)v79 - 1) != -1839634494 )
      __break(0x8229u);
    v80 = v79(&v94);
    if ( v80 )
    {
      result = _drm_err("dither strength failed ret %d\n", v80);
      goto LABEL_54;
    }
  }
  v81 = *(_QWORD *)(a1 + 72);
  *(_QWORD *)((char *)&v95 + 4) = 0;
  HIDWORD(v95) = *(_DWORD *)(*(_QWORD *)(v81 + 48) + 20LL);
  v97 = &v93;
  v98 = 0x400000000LL;
  v82 = *(__int64 (__fastcall **)(_QWORD))(v35 + 8);
  v93 = 1;
  LODWORD(v94) = 1;
  if ( *((_DWORD *)v82 - 1) != -1839634494 )
    __break(0x8228u);
  LODWORD(result) = v82(&v94);
  if ( (_DWORD)result )
    goto LABEL_36;
  v83 = *(unsigned int *)(a1 + 64);
  v84 = a2[2];
  v105 = 0;
  v106 = 0;
  v103 = 0;
  v104 = 0;
  v101 = v84;
  v102 = 0;
  if ( (unsigned int)v83 > 4 )
    goto LABEL_110;
  v85 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v85 > 1 )
    goto LABEL_110;
  if ( (unsigned __int64)(16 * v83 + 8 * v85 + 160) <= 0x7D0 )
  {
    LODWORD(v102) = 1;
    v86 = a2[19];
    v87 = *(_DWORD *)(a1 + 28);
    LODWORD(v106) = 2;
    v88 = *(_QWORD *)((char *)a2 + 164);
    v107 = v86;
    v89 = dspp_buf[2 * v83 + 20 + v85];
    *(_QWORD *)((char *)&v108 + 4) = v88;
    LODWORD(v86) = *((_DWORD *)a2 + 43);
    LODWORD(v88) = *((_DWORD *)a2 + 44);
    v103 = v89;
    LODWORD(v89) = *((_DWORD *)a2 + 40);
    LODWORD(v105) = 0;
    v109 = __PAIR64__(v88, v86);
    LODWORD(v86) = *((_DWORD *)a2 + 7);
    LODWORD(v108) = v89;
    HIDWORD(v108) = v86;
    result = sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_dspp_igcv31", 1618, -1, v83, v85, v87, 1, 239);
    v90 = *(unsigned int *)(a1 + 28);
    if ( (unsigned int)v90 <= 2 )
    {
      v55 = *(__int64 (__fastcall **)(_QWORD))(v35 + 8 * v90 + 16);
      if ( !v55 )
        goto LABEL_54;
      v56 = &v101;
      goto LABEL_69;
    }
    goto LABEL_110;
  }
LABEL_111:
  __break(1u);
  if ( v21 )
    JUMPOUT(0x14A480);
  return reg_dmav1_setup_rc_pu_configv1();
}
