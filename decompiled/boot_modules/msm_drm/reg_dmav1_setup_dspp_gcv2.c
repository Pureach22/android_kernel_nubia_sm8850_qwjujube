unsigned __int64 __fastcall reg_dmav1_setup_dspp_gcv2(__int64 a1, __int64 **a2)
{
  __int64 v2; // d14
  __int64 v4; // x2
  unsigned int v5; // w4
  int v6; // w8
  __int64 *v8; // x9
  unsigned __int64 ops; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  unsigned __int64 v14; // x21
  unsigned __int64 result; // x0
  int *v16; // x24
  __int64 v17; // x23
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 (__fastcall *v20)(_QWORD); // x8
  unsigned int v21; // w0
  unsigned int v22; // w1
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  __int64 v27; // x15
  __int64 v28; // d3
  unsigned __int64 v29; // x21
  __int64 v30; // x8
  __int64 v31; // x9
  unsigned __int64 *v32; // x8
  void (__fastcall *v33)(_QWORD); // x9
  unsigned __int64 v34; // x0
  __int64 v35; // x8
  __int64 v36; // x9
  __int64 (__fastcall *v37)(_QWORD); // x8
  unsigned int v38; // w0
  __int64 v39; // x8
  __int64 v40; // x8
  __int64 (__fastcall *v41)(_QWORD); // x8
  unsigned int v42; // w0
  __int64 v43; // x1
  __int64 v44; // x8
  __int64 v45; // x8
  _DWORD *v46; // x8
  unsigned int v47; // w0
  __int64 v48; // x8
  _DWORD *v49; // x9
  unsigned int v50; // w0
  __int64 v51; // x8
  __int64 (__fastcall *v52)(_QWORD); // x8
  __int64 v53; // x8
  __int64 v54; // x8
  int v55; // w8
  __int64 (__fastcall *v56)(_QWORD); // x8
  unsigned int v57; // w0
  __int64 v58; // x8
  __int64 *v59; // x9
  __int64 v60; // x1
  __int64 v61; // x9
  __int64 *v62; // x11
  int v63; // w10
  unsigned __int64 v64; // x11
  __int64 v65; // x8
  int v66; // w10
  __int64 (__fastcall *v67)(__int64 **, __int64); // x8
  __int64 **v68; // x0
  int v69; // w8
  __int64 *v70; // x9
  int v71; // w8
  __int64 v72; // x4
  __int64 v73; // x5
  __int64 *v74; // x11
  int v75; // w6
  unsigned int v76; // w10
  unsigned __int64 v77; // x9
  __int64 v78; // x8
  int v79; // [xsp+14h] [xbp-13Ch] BYREF
  __int64 *v80; // [xsp+18h] [xbp-138h] BYREF
  __int64 v81; // [xsp+20h] [xbp-130h]
  unsigned __int64 v82; // [xsp+28h] [xbp-128h]
  __int64 v83; // [xsp+30h] [xbp-120h]
  __int64 v84; // [xsp+38h] [xbp-118h]
  __int64 v85; // [xsp+40h] [xbp-110h]
  __int64 *v86; // [xsp+48h] [xbp-108h]
  unsigned __int64 v87; // [xsp+50h] [xbp-100h]
  unsigned __int64 v88; // [xsp+58h] [xbp-F8h]
  __int64 v89; // [xsp+60h] [xbp-F0h]
  __int64 v90; // [xsp+68h] [xbp-E8h] BYREF
  __int128 v91; // [xsp+70h] [xbp-E0h]
  __int64 v92; // [xsp+80h] [xbp-D0h]
  int *v93; // [xsp+88h] [xbp-C8h]
  __int64 v94; // [xsp+90h] [xbp-C0h]
  __int64 v95; // [xsp+98h] [xbp-B8h]
  __int64 v96; // [xsp+A0h] [xbp-B0h]
  int v97; // [xsp+ACh] [xbp-A4h] BYREF
  __int64 v98; // [xsp+B0h] [xbp-A0h] BYREF
  __int64 *v99; // [xsp+B8h] [xbp-98h] BYREF
  __int64 v100; // [xsp+C0h] [xbp-90h]
  unsigned __int64 v101; // [xsp+C8h] [xbp-88h]
  __int64 v102; // [xsp+D0h] [xbp-80h]
  __int64 v103; // [xsp+D8h] [xbp-78h]
  __int64 v104; // [xsp+E0h] [xbp-70h]
  __int64 *v105; // [xsp+E8h] [xbp-68h]
  int v106; // [xsp+F0h] [xbp-60h]
  __int64 v107; // [xsp+F4h] [xbp-5Ch]
  int v108; // [xsp+FCh] [xbp-54h]
  int v109; // [xsp+100h] [xbp-50h]
  int v110; // [xsp+104h] [xbp-4Ch]
  __int64 v111; // [xsp+108h] [xbp-48h] BYREF
  __int128 v112; // [xsp+110h] [xbp-40h]
  unsigned __int64 v113; // [xsp+120h] [xbp-30h]
  char *v114; // [xsp+128h] [xbp-28h]
  __int64 v115; // [xsp+130h] [xbp-20h]
  __int64 v116; // [xsp+138h] [xbp-18h]
  __int64 v117; // [xsp+140h] [xbp-10h]
  __int64 v118; // [xsp+148h] [xbp-8h]

  v118 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v95 = 0;
  v96 = 0;
  v93 = nullptr;
  v94 = 0;
  v92 = 0;
  v90 = 0;
  v91 = 0u;
  v88 = 0;
  v89 = 0;
  v86 = nullptr;
  v87 = 0;
  v84 = 0;
  v85 = 0;
  v82 = 0;
  v83 = 0;
  v80 = nullptr;
  v81 = 0;
  v79 = 0;
  if ( !a1 || !a2 )
  {
    _drm_err("invalid cfg %pK ctx %pK\n", a2, (const void *)a1);
LABEL_19:
    result = _drm_err("reg dma dspp check failed ret %d\n", 4294967274LL);
    goto LABEL_20;
  }
  v4 = *(unsigned int *)(a1 + 64);
  v5 = *(_DWORD *)(a1 + 1496);
  if ( !a2[2] || (unsigned int)v4 > 4 || v5 >= 2 )
  {
    _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", a2[2], v4, 11, v5);
    goto LABEL_19;
  }
  if ( &dspp_buf[2 * v4] == (unsigned __int64 *)-880LL )
  {
    _drm_err("invalid dma_buf\n");
    goto LABEL_19;
  }
  v6 = *((_DWORD *)a2 + 40);
  *((_DWORD *)a2 + 42) = 2;
  v8 = *a2;
  *((_DWORD *)a2 + 40) = v6 & 0xFF0F0FFF | 0x2000;
  if ( !v8 )
  {
    _drm_dev_dbg(0, 0, 1, "disable pgc feature\n");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "reg_dmav1_setup_dspp_gcv2",
      1369,
      -1,
      *(_DWORD *)(a1 + 64),
      *(_DWORD *)(a1 + 1496),
      *(_DWORD *)(a1 + 28),
      0,
      239);
    v22 = *(_DWORD *)(a1 + 64);
    v116 = 0;
    v117 = 0;
    v114 = nullptr;
    v115 = 0;
    v113 = 0;
    v111 = 0;
    v112 = 0u;
    v98 = 0;
    v97 = 0;
    result = reg_dmav1_get_dspp_blk((__int64)a2, v22, &v97, &v98, v23, v24, v25, v26);
    if ( (_DWORD)result == -114 )
      goto LABEL_20;
    if ( (_DWORD)result == -22 )
    {
      result = _drm_err("unable to determine LUTDMA DSPP blocks\n");
      goto LABEL_20;
    }
    result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
    if ( !result )
      goto LABEL_20;
    v29 = result;
    if ( result > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_20;
    v30 = *(unsigned int *)(a1 + 64);
    if ( (unsigned int)v30 < 5 )
    {
      v31 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v31 <= 1 )
      {
        if ( (unsigned __int64)(16 * v30 + 8 * v31 + 880) > 0x7D0 )
          goto LABEL_77;
        v32 = &dspp_buf[2 * v30 + v31];
        v33 = *(void (__fastcall **)(_QWORD))(result + 64);
        v34 = v32[110];
        if ( *((_DWORD *)v33 - 1) != -870478129 )
          __break(0x8229u);
        v33(v34);
        v35 = *(unsigned int *)(a1 + 64);
        LODWORD(v111) = 0;
        v112 = 0xBu;
        v113 = 0;
        v114 = nullptr;
        v115 = 0;
        v116 = 0;
        v117 = 0;
        HIDWORD(v111) = v97;
        if ( (unsigned int)v35 <= 4 )
        {
          v36 = *(unsigned int *)(a1 + 1496);
          if ( (unsigned int)v36 <= 1 )
          {
            if ( (unsigned __int64)(16 * v35 + 8 * v36 + 880) > 0x7D0 )
              goto LABEL_77;
            DWORD1(v112) = 0;
            v115 = 0;
            v113 = dspp_buf[2 * v35 + 110 + v36];
            v114 = nullptr;
            v37 = *(__int64 (__fastcall **)(_QWORD))(v29 + 8);
            if ( *((_DWORD *)v37 - 1) != -1839634494 )
              __break(0x8228u);
            v38 = v37(&v111);
            if ( v38 )
            {
              result = _drm_err("write decode select failed ret %d\n", v38);
              goto LABEL_20;
            }
            v51 = *(_QWORD *)(a1 + 72);
            *(_QWORD *)((char *)&v112 + 4) = 0;
            HIDWORD(v98) = 0;
            HIDWORD(v112) = *(_DWORD *)(*(_QWORD *)(v51 + 48) + 92LL);
            v114 = (char *)&v98 + 4;
            v115 = 0x400000000LL;
            v52 = *(__int64 (__fastcall **)(_QWORD))(v29 + 8);
            LODWORD(v111) = 1;
            if ( *((_DWORD *)v52 - 1) != -1839634494 )
              __break(0x8228u);
            result = v52(&v111);
            if ( (_DWORD)result )
            {
              result = _drm_err("setting reg failed ret %d\n", (unsigned int)result);
              goto LABEL_20;
            }
            v58 = *(unsigned int *)(a1 + 64);
            v59 = a2[2];
            v103 = 0;
            v104 = 0;
            v101 = 0;
            v102 = 0;
            v99 = v59;
            v100 = 0;
            if ( (unsigned int)v58 <= 4 )
            {
              v60 = *(unsigned int *)(a1 + 1496);
              if ( (unsigned int)v60 <= 1 )
              {
                if ( (unsigned __int64)(16 * v58 + 8 * v60 + 880) <= 0x7D0 )
                {
                  LODWORD(v100) = 1;
                  v61 = *(__int64 *)((char *)a2 + 164);
                  v62 = a2[19];
                  LODWORD(v104) = 11;
                  v107 = v61;
                  v63 = *((_DWORD *)a2 + 43);
                  LODWORD(v61) = *((_DWORD *)a2 + 44);
                  v105 = v62;
                  v64 = dspp_buf[2 * v58 + 110 + v60];
                  v65 = *(unsigned int *)(a1 + 28);
                  v109 = v63;
                  v110 = v61;
                  LODWORD(v61) = *((_DWORD *)a2 + 40);
                  v66 = *((_DWORD *)a2 + 7);
                  v101 = v64;
                  v106 = v61;
                  v108 = v66;
                  if ( (unsigned int)v65 <= 2 )
                  {
                    v67 = *(__int64 (__fastcall **)(__int64 **, __int64))(v29 + 8 * v65 + 16);
                    if ( !v67 )
                      goto LABEL_20;
                    v68 = &v99;
LABEL_72:
                    if ( *((_DWORD *)v67 - 1) != 1772228465 )
                      __break(0x8228u);
                    result = v67(v68, v60);
                    if ( (_DWORD)result )
                      result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
                    goto LABEL_20;
                  }
                  goto LABEL_76;
                }
                goto LABEL_77;
              }
            }
          }
        }
      }
    }
LABEL_76:
    __break(0x5512u);
    goto LABEL_77;
  }
  ops = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
  if ( !ops || (v14 = ops, ops >= 0xFFFFFFFFFFFFF001LL) )
  {
    result = _drm_err("invalid dma ops\n");
    goto LABEL_20;
  }
  result = reg_dmav1_setup_dspp_gc_common(a1, (__int64)a2, ops, (__int64)&v90, v10, v11, v12, v13);
  if ( (_DWORD)result )
  {
LABEL_20:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v16 = (int *)*a2;
  v17 = **a2;
  if ( (v17 & 2) != 0 )
  {
    v39 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)((char *)&v91 + 4) = 0;
    v40 = *(_QWORD *)(v39 + 48);
    v93 = v16 + 1538;
    v94 = 0x20000000000LL;
    LODWORD(v90) = 3;
    HIDWORD(v91) = *(_DWORD *)(v40 + 92) + 4;
    v41 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
    if ( *((_DWORD *)v41 - 1) != -1839634494 )
      __break(0x8228u);
    v42 = v41(&v90);
    v43 = v42;
    if ( v42 )
      goto LABEL_48;
    v44 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)((char *)&v91 + 4) = 0;
    LODWORD(v90) = 3;
    v45 = *(_QWORD *)(v44 + 48);
    v93 = v16 + 1666;
    v94 = 0x20000000000LL;
    HIDWORD(v91) = *(_DWORD *)(v45 + 92) + 12;
    v46 = *(_DWORD **)(v14 + 8);
    if ( *(v46 - 1) != -1839634494 )
      __break(0x8228u);
    v47 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v46)(&v90, v42);
    v43 = v47;
    if ( v47 )
      goto LABEL_48;
    v48 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)((char *)&v91 + 4) = 0;
    HIDWORD(v91) = *(_DWORD *)(*(_QWORD *)(v48 + 48) + 92LL) + 20;
    v93 = v16 + 1794;
    v94 = 0x20000000000LL;
    v49 = *(_DWORD **)(v14 + 8);
    LODWORD(v90) = 3;
    if ( *(v49 - 1) != -1839634494 )
      __break(0x8229u);
    v50 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v49)(&v90, v47);
    v43 = v50;
    if ( v50 )
    {
LABEL_48:
      result = _drm_err("extn lut write failed ret %d\n", v43);
      goto LABEL_20;
    }
  }
  v18 = *(_QWORD *)(a1 + 72);
  *(_QWORD *)((char *)&v91 + 4) = 0;
  v19 = *(_QWORD *)(v18 + 48);
  v93 = &v79;
  v94 = 0x400000000LL;
  v79 = 1;
  LODWORD(v19) = *(_DWORD *)(v19 + 92);
  LODWORD(v90) = 1;
  HIDWORD(v91) = v19 + 28;
  v20 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
  if ( *((_DWORD *)v20 - 1) != -1839634494 )
    __break(0x8228u);
  v21 = v20(&v90);
  if ( v21 )
  {
    result = _drm_err("setting swap offset failed ret %d\n", v21);
    goto LABEL_20;
  }
  v53 = *(_QWORD *)(a1 + 72);
  *(_QWORD *)((char *)&v91 + 4) = 0;
  v93 = &v79;
  v94 = 0x400000000LL;
  v54 = *(_QWORD *)(v53 + 48);
  LODWORD(v90) = 1;
  HIDWORD(v91) = *(_DWORD *)(v54 + 92);
  if ( (v17 & 2) != 0 )
    v55 = 5;
  else
    v55 = 1;
  v79 = v55;
  v56 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
  if ( *((_DWORD *)v56 - 1) != -1839634494 )
    __break(0x8228u);
  v57 = v56(&v90);
  if ( v57 )
  {
    result = _drm_err("enabling gamma correction failed ret %d\n", v57);
    goto LABEL_20;
  }
  v69 = *((_DWORD *)a2 + 42);
  v70 = a2[2];
  v82 = 0;
  v83 = 0;
  v84 = 0;
  v85 = 0;
  v71 = v69 | 1;
  v80 = v70;
  v81 = 0;
  *((_DWORD *)a2 + 42) = v71;
  v72 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v72 > 4 )
    goto LABEL_76;
  v73 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v73 > 1 )
    goto LABEL_76;
  if ( (unsigned __int64)(16 * v72 + 8 * v73 + 880) <= 0x7D0 )
  {
    v74 = a2[19];
    LODWORD(v81) = 1;
    v75 = *(_DWORD *)(a1 + 28);
    LODWORD(v85) = 11;
    v86 = v74;
    v76 = *((_DWORD *)a2 + 40);
    LODWORD(v74) = *((_DWORD *)a2 + 41);
    v77 = dspp_buf[2 * v72 + 110 + v73];
    LODWORD(v84) = 0;
    v87 = __PAIR64__((unsigned int)v74, v76);
    v82 = v77;
    LODWORD(v77) = *((_DWORD *)a2 + 44);
    LODWORD(v89) = *((_DWORD *)a2 + 43);
    HIDWORD(v89) = v77;
    v88 = __PAIR64__(*((_DWORD *)a2 + 7), v71);
    result = sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_dspp_gcv2", 1429, -1, v72, v73, v75, 1, 239);
    v78 = *(unsigned int *)(a1 + 28);
    if ( (unsigned int)v78 <= 2 )
    {
      v67 = *(__int64 (__fastcall **)(__int64 **, __int64))(v14 + 8 * v78 + 16);
      if ( !v67 )
        goto LABEL_20;
      v60 = *(unsigned int *)(a1 + 1496);
      v68 = &v80;
      goto LABEL_72;
    }
    goto LABEL_76;
  }
LABEL_77:
  __break(1u);
  *(_QWORD *)(v27 - 24) = v2;
  *(_QWORD *)(v27 - 16) = v28;
  return reg_dmav1_setup_dspp_igcv31();
}
