unsigned __int64 __fastcall reg_dmav1_setup_dspp_pa_hsicv17(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6)
{
  __int64 v6; // d14
  __int64 v8; // x2
  unsigned int v9; // w4
  int v10; // w8
  __int64 *v11; // x9
  int v12; // w8
  unsigned __int64 result; // x0
  double v16; // d0
  unsigned int v17; // w1
  _QWORD *v18; // x22
  double v19; // d1
  double v20; // d2
  double v21; // d3
  int dspp_blk; // w0
  __int64 v23; // x23
  __int64 v24; // x23
  unsigned int v25; // w24
  unsigned __int64 ops; // x0
  __int64 v27; // x15
  __int64 v28; // d3
  unsigned __int64 v29; // x20
  __int64 v30; // x8
  __int64 v31; // x9
  unsigned __int64 *v32; // x8
  void (__fastcall *v33)(_QWORD); // x9
  unsigned __int64 v34; // x0
  __int64 v35; // x25
  __int64 v36; // x8
  unsigned int v37; // w9
  __int64 v38; // x8
  __int64 v39; // x9
  __int64 (__fastcall *v40)(_QWORD); // x8
  unsigned int v41; // w0
  __int64 v42; // x8
  __int64 v43; // x8
  __int64 (__fastcall *v44)(_QWORD); // x8
  unsigned int v45; // w0
  __int64 v46; // x8
  __int64 v47; // x9
  __int64 v48; // x1
  __int64 v49; // x9
  unsigned __int64 v50; // x11
  __int64 v51; // x8
  int v52; // w10
  int v53; // w10
  __int64 (__fastcall *v54)(_QWORD); // x8
  unsigned int v55; // w0
  __int64 *v56; // x25
  unsigned __int64 v57; // x20
  __int64 v58; // x8
  __int64 v59; // x9
  unsigned __int64 *v60; // x8
  void (__fastcall *v61)(_QWORD); // x9
  unsigned __int64 v62; // x0
  __int64 v63; // x8
  __int64 v64; // x9
  __int64 (__fastcall *v65)(_QWORD); // x8
  unsigned int v66; // w0
  __int64 v67; // x8
  int v68; // w26
  __int64 v69; // x8
  __int16 v70; // w9
  int v71; // w10
  __int64 (__fastcall *v72)(_QWORD); // x9
  unsigned int v73; // w0
  __int64 v74; // x8
  int v75; // w11
  __int64 (__fastcall *v76)(_QWORD); // x9
  unsigned int v77; // w0
  _QWORD *v78; // x9
  __int64 v79; // x8
  int v80; // w11
  __int64 (__fastcall *v81)(_QWORD); // x9
  unsigned int v82; // w0
  __int64 v83; // x8
  int v84; // w11
  __int64 (__fastcall *v85)(_QWORD); // x9
  unsigned int v86; // w0
  unsigned __int64 v87; // x25
  __int64 v88; // x23
  __int64 v89; // x8
  unsigned int v90; // w9
  __int64 v91; // x8
  __int64 v92; // x9
  __int64 (__fastcall *v93)(_QWORD); // x8
  __int64 v94; // x8
  __int64 v95; // x8
  __int64 (__fastcall *v96)(_QWORD); // x8
  unsigned int v97; // w0
  int v98; // w8
  int v99; // w8
  __int64 v100; // x4
  __int64 v101; // x5
  __int64 v102; // x11
  int v103; // w6
  unsigned int v104; // w10
  unsigned __int64 v105; // x9
  __int64 v106; // x8
  __int64 (__fastcall *v107)(__int64 *, __int64); // x8
  __int64 v108; // x1
  unsigned int v109; // [xsp+10h] [xbp-1A0h] BYREF
  unsigned int v110; // [xsp+14h] [xbp-19Ch] BYREF
  __int64 v111; // [xsp+18h] [xbp-198h] BYREF
  __int64 v112; // [xsp+20h] [xbp-190h] BYREF
  __int128 v113; // [xsp+28h] [xbp-188h]
  unsigned __int64 v114; // [xsp+38h] [xbp-178h]
  char *v115; // [xsp+40h] [xbp-170h]
  __int64 v116; // [xsp+48h] [xbp-168h]
  __int64 v117; // [xsp+50h] [xbp-160h]
  __int64 v118; // [xsp+58h] [xbp-158h]
  __int64 v119; // [xsp+60h] [xbp-150h] BYREF
  __int64 v120; // [xsp+68h] [xbp-148h]
  unsigned __int64 v121; // [xsp+70h] [xbp-140h]
  __int64 v122; // [xsp+78h] [xbp-138h]
  __int64 v123; // [xsp+80h] [xbp-130h]
  __int64 v124; // [xsp+88h] [xbp-128h]
  __int64 v125; // [xsp+90h] [xbp-120h]
  unsigned __int64 v126; // [xsp+98h] [xbp-118h]
  unsigned __int64 v127; // [xsp+A0h] [xbp-110h]
  __int64 v128; // [xsp+A8h] [xbp-108h]
  __int64 v129; // [xsp+B0h] [xbp-100h] BYREF
  __int64 v130; // [xsp+B8h] [xbp-F8h] BYREF
  __int64 v131; // [xsp+C0h] [xbp-F0h] BYREF
  __int64 v132; // [xsp+C8h] [xbp-E8h]
  unsigned __int64 v133; // [xsp+D0h] [xbp-E0h]
  __int64 v134; // [xsp+D8h] [xbp-D8h]
  __int64 v135; // [xsp+E0h] [xbp-D0h]
  __int64 v136; // [xsp+E8h] [xbp-C8h]
  __int64 v137; // [xsp+F0h] [xbp-C0h]
  int v138; // [xsp+F8h] [xbp-B8h]
  __int64 v139; // [xsp+FCh] [xbp-B4h]
  int v140; // [xsp+104h] [xbp-ACh]
  int v141; // [xsp+108h] [xbp-A8h]
  int v142; // [xsp+10Ch] [xbp-A4h]
  __int64 v143; // [xsp+110h] [xbp-A0h] BYREF
  __int128 v144; // [xsp+118h] [xbp-98h]
  unsigned __int64 v145; // [xsp+128h] [xbp-88h]
  char *v146; // [xsp+130h] [xbp-80h]
  __int64 v147; // [xsp+138h] [xbp-78h]
  __int64 v148; // [xsp+140h] [xbp-70h]
  __int64 v149; // [xsp+148h] [xbp-68h]
  _QWORD v150[5]; // [xsp+150h] [xbp-60h] BYREF
  _QWORD dest[7]; // [xsp+178h] [xbp-38h] BYREF

  dest[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v127 = 0;
  v128 = 0;
  v125 = 0;
  v126 = 0;
  v123 = 0;
  v124 = 0;
  v121 = 0;
  v122 = 0;
  v119 = 0;
  v120 = 0;
  v117 = 0;
  v118 = 0;
  v115 = nullptr;
  v116 = 0;
  v114 = 0;
  v112 = 0;
  v113 = 0u;
  v111 = 0;
  v109 = 0;
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid cfg %pK ctx %pK\n", a2, (const void *)a1);
    goto LABEL_22;
  }
  v8 = *(unsigned int *)(a1 + 64);
  v9 = *(_DWORD *)(a1 + 1496);
  if ( !a2[2] || (unsigned int)v8 > 4 || v9 >= 2 )
  {
    result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", (const void *)a2[2], v8, 10, v9);
    goto LABEL_22;
  }
  if ( &dspp_buf[2 * v8] == (unsigned __int64 *)-800LL )
  {
    result = _drm_err("invalid dma_buf\n");
    goto LABEL_22;
  }
  v10 = *((_DWORD *)a2 + 40);
  memset(v150, 0, sizeof(v150));
  v110 = 0;
  v11 = (__int64 *)*a2;
  *((_DWORD *)a2 + 40) = v10 & 0xFF0F0FFF | 0x701000;
  *((_DWORD *)a2 + 42) = 2;
  if ( !v11 )
  {
    v16 = _drm_dev_dbg(0, 0, 1, "disable pa hsic feature\n");
    v17 = *(_DWORD *)(a1 + 64);
    v148 = 0;
    v149 = 0;
    v18 = a2;
    v146 = nullptr;
    v147 = 0;
    v145 = 0;
    v143 = 0;
    v144 = 0u;
    v129 = 0;
    v130 = 0;
    dspp_blk = reg_dmav1_get_dspp_blk((__int64)a2, v17, (_DWORD *)&v129 + 1, &v130, v16, v19, v20, v21);
    if ( dspp_blk != -114 )
    {
      if ( dspp_blk == -22 )
      {
        _drm_err("unable to determine LUTDMA DSPP blocks\n");
      }
      else
      {
        v23 = (unsigned int)v130;
        if ( (unsigned int)v130 < 6 )
        {
          memset(dest, 0, 40);
          if ( (unsigned int)v130 < 2 )
            dest[0] = a1;
          else
            memcpy(dest, a2 + 6, 8LL * (unsigned int)v130);
          cp_feature_get_curr_mode(1, a2[25], &v129);
          if ( (v129 & 0x3F) != 0 )
            v25 = -503316481;
          else
            v25 = -504365057;
          ops = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
          if ( ops )
          {
            v29 = ops;
            if ( ops <= 0xFFFFFFFFFFFFF000LL )
            {
              v30 = *(unsigned int *)(a1 + 64);
              if ( (unsigned int)v30 > 4 )
                goto LABEL_132;
              v31 = *(unsigned int *)(a1 + 1496);
              if ( (unsigned int)v31 > 1 )
                goto LABEL_132;
              if ( (unsigned __int64)(16 * v30 + 8 * v31 + 800) > 0x7D0 )
                goto LABEL_133;
              v32 = &dspp_buf[2 * v30 + v31];
              v33 = *(void (__fastcall **)(_QWORD))(ops + 64);
              v34 = v32[100];
              if ( *((_DWORD *)v33 - 1) != -870478129 )
                __break(0x8229u);
              v33(v34);
              if ( (_DWORD)v23 )
              {
                v35 = 0;
                while ( v35 != 5 )
                {
                  v36 = *(unsigned int *)(dest[v35] + 64LL);
                  if ( (unsigned int)v36 > 4 )
                    goto LABEL_132;
                  v143 = 0;
                  v144 = 0u;
                  v37 = dspp_mapping[v36];
                  v38 = *(unsigned int *)(a1 + 64);
                  v145 = 0;
                  v146 = nullptr;
                  v147 = 0;
                  HIDWORD(v129) = v37;
                  v148 = 0;
                  v149 = 0;
                  HIDWORD(v143) = v37;
                  LODWORD(v144) = 10;
                  if ( (unsigned int)v38 > 4 )
                    goto LABEL_132;
                  v39 = *(unsigned int *)(a1 + 1496);
                  if ( (unsigned int)v39 > 1 )
                    goto LABEL_132;
                  if ( (unsigned __int64)(16 * v38 + 8 * v39 + 800) > 0x7D0 )
                    goto LABEL_133;
                  DWORD1(v144) = 0;
                  v146 = nullptr;
                  v147 = 0;
                  v145 = dspp_buf[2 * v38 + 100 + v39];
                  v40 = *(__int64 (__fastcall **)(_QWORD))(v29 + 8);
                  if ( *((_DWORD *)v40 - 1) != -1839634494 )
                    __break(0x8228u);
                  v41 = v40(&v143);
                  if ( v41 )
                  {
                    _drm_err("write decode select failed ret %d\n", v41);
                    goto LABEL_21;
                  }
                  v42 = *(_QWORD *)(a1 + 72);
                  v146 = (char *)&v130 + 4;
                  *(_QWORD *)((char *)&v144 + 4) = 0;
                  v43 = *(_QWORD *)(v42 + 48);
                  LODWORD(v143) = 5;
                  HIDWORD(v144) = *(_DWORD *)(v43 + 128);
                  v147 = v25 | 0x400000000LL;
                  v44 = *(__int64 (__fastcall **)(_QWORD))(v29 + 8);
                  if ( *((_DWORD *)v44 - 1) != -1839634494 )
                    __break(0x8228u);
                  v45 = v44(&v143);
                  if ( v45 )
                  {
                    _drm_err("setting reg failed ret %d\n", v45);
                    goto LABEL_21;
                  }
                  if ( v23 == ++v35 )
                    goto LABEL_54;
                }
                goto LABEL_133;
              }
LABEL_54:
              v46 = *(unsigned int *)(a1 + 64);
              v47 = v18[2];
              v135 = 0;
              v136 = 0;
              v133 = 0;
              v134 = 0;
              v131 = v47;
              v132 = 0;
              if ( (unsigned int)v46 > 4 )
                goto LABEL_132;
              v48 = *(unsigned int *)(a1 + 1496);
              if ( (unsigned int)v48 > 1 )
                goto LABEL_132;
              if ( (unsigned __int64)(16 * v46 + 8 * v48 + 800) > 0x7D0 )
                goto LABEL_133;
              v139 = *(_QWORD *)((char *)v18 + 164);
              LODWORD(v132) = 1;
              v49 = v18[19];
              LODWORD(v136) = 10;
              v137 = v49;
              v50 = dspp_buf[2 * v46 + 100 + v48];
              v51 = *(unsigned int *)(a1 + 28);
              v52 = *((_DWORD *)v18 + 43);
              LODWORD(v49) = *((_DWORD *)v18 + 44);
              v133 = v50;
              v141 = v52;
              v53 = *((_DWORD *)v18 + 40);
              v142 = v49;
              LODWORD(v49) = *((_DWORD *)v18 + 7);
              v138 = v53;
              v140 = v49;
              if ( (unsigned int)v51 > 2 )
                goto LABEL_132;
              v54 = *(__int64 (__fastcall **)(_QWORD))(v29 + 8 * v51 + 16);
              if ( v54 )
              {
                if ( *((_DWORD *)v54 - 1) != 1772228465 )
                  __break(0x8228u);
                v55 = v54(&v131);
                if ( v55 )
                  _drm_err("failed to kick off ret %d\n", v55);
              }
            }
          }
        }
        else
        {
          _drm_err("unable to process more than %d DSPP blocks\n", 5);
        }
      }
    }
LABEL_21:
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "reg_dmav1_setup_dspp_pa_hsicv17",
               2259,
               -1,
               *(_DWORD *)(a1 + 64),
               *(_DWORD *)(a1 + 1496),
               *(_DWORD *)(a1 + 28),
               0,
               239);
    goto LABEL_22;
  }
  v12 = *((_DWORD *)a2 + 2);
  if ( v12 != 24 )
  {
    result = _drm_err("invalid size of payload len %d exp %zd\n", v12, 0x18u);
    goto LABEL_22;
  }
  result = reg_dmav1_get_dspp_blk((__int64)a2, *(_DWORD *)(a1 + 64), &v109, &v110, a3, a4, a5, a6);
  if ( (_DWORD)result == -114 )
  {
LABEL_22:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (_DWORD)result == -22 )
  {
    result = _drm_err("unable to determine LUTDMA DSPP blocks\n");
    goto LABEL_22;
  }
  v24 = v110;
  if ( v110 >= 6 )
  {
    result = _drm_err("unable to process more than %d DSPP blocks\n", 5);
    goto LABEL_22;
  }
  if ( v110 < 2 )
    v150[0] = a1;
  else
    memcpy(v150, a2 + 6, 8LL * v110);
  v56 = (__int64 *)*a2;
  result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
  if ( !result )
    goto LABEL_22;
  v57 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_22;
  v58 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v58 > 4 )
    goto LABEL_132;
  v59 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v59 > 1 )
    goto LABEL_132;
  if ( (unsigned __int64)(16 * v58 + 8 * v59 + 800) > 0x7D0 )
    goto LABEL_133;
  v60 = &dspp_buf[2 * v58 + v59];
  v61 = *(void (__fastcall **)(_QWORD))(result + 64);
  v62 = v60[100];
  if ( *((_DWORD *)v61 - 1) != -870478129 )
    __break(0x8229u);
  v61(v62);
  v63 = *(unsigned int *)(a1 + 64);
  LODWORD(v112) = 0;
  v114 = 0;
  v115 = nullptr;
  v116 = 0;
  v117 = 0;
  v118 = 0;
  HIDWORD(v112) = v109;
  v113 = 0xAu;
  if ( (unsigned int)v63 > 4 || (v64 = *(unsigned int *)(a1 + 1496), (unsigned int)v64 > 1) )
  {
LABEL_132:
    __break(0x5512u);
    goto LABEL_133;
  }
  if ( (unsigned __int64)(16 * v63 + 8 * v64 + 800) <= 0x7D0 )
  {
    HIDWORD(v113) = 0;
    DWORD1(v113) = 0;
    v116 = 0;
    v114 = dspp_buf[2 * v63 + 100 + v64];
    v115 = nullptr;
    v65 = *(__int64 (__fastcall **)(_QWORD))(v57 + 8);
    if ( *((_DWORD *)v65 - 1) != -1839634494 )
      __break(0x8228u);
    v66 = v65(&v112);
    if ( v66 )
    {
LABEL_77:
      result = _drm_err("write decode select failed ret %d\n", v66);
      goto LABEL_22;
    }
    v67 = *v56;
    if ( (*v56 & 1) != 0 )
    {
      v69 = *(_QWORD *)(a1 + 72);
      v70 = *((_DWORD *)v56 + 2);
      *(_QWORD *)((char *)&v113 + 4) = 0;
      HIDWORD(v113) = *(_DWORD *)(*(_QWORD *)(v69 + 48) + 128LL) + 28;
      v115 = (char *)&v111 + 4;
      v116 = 0x400000000LL;
      v71 = v70 & 0xFFF;
      v72 = *(__int64 (__fastcall **)(_QWORD))(v57 + 8);
      HIDWORD(v111) = v71;
      LODWORD(v112) = 1;
      if ( *((_DWORD *)v72 - 1) != -1839634494 )
        __break(0x8229u);
      v73 = v72(&v112);
      if ( v73 )
      {
        result = _drm_err("hsic hue write failed ret %d\n", v73);
        goto LABEL_22;
      }
      v67 = *v56;
      v68 = 0x2000000;
      LODWORD(v111) = 0x2000000;
    }
    else
    {
      v68 = 0;
    }
    if ( (v67 & 2) != 0 )
    {
      v74 = *(_QWORD *)(a1 + 72);
      v75 = *((unsigned __int16 *)v56 + 6);
      *(_QWORD *)((char *)&v113 + 4) = 0;
      HIDWORD(v113) = *(_DWORD *)(*(_QWORD *)(v74 + 48) + 128LL) + 32;
      v115 = (char *)&v111 + 4;
      v116 = 0x400000000LL;
      v76 = *(__int64 (__fastcall **)(_QWORD))(v57 + 8);
      HIDWORD(v111) = v75;
      LODWORD(v112) = 1;
      if ( *((_DWORD *)v76 - 1) != -1839634494 )
        __break(0x8229u);
      v77 = v76(&v112);
      if ( v77 )
      {
        result = _drm_err("hsic saturation write failed ret %d\n", v77);
        goto LABEL_22;
      }
      v67 = *v56;
      v68 |= 0x4000000u;
    }
    v78 = a2;
    if ( (v67 & 4) != 0 )
    {
      v79 = *(_QWORD *)(a1 + 72);
      v80 = *((unsigned __int8 *)v56 + 16);
      *(_QWORD *)((char *)&v113 + 4) = 0;
      HIDWORD(v113) = *(_DWORD *)(*(_QWORD *)(v79 + 48) + 128LL) + 36;
      v115 = (char *)&v111 + 4;
      v116 = 0x400000000LL;
      v81 = *(__int64 (__fastcall **)(_QWORD))(v57 + 8);
      HIDWORD(v111) = v80;
      LODWORD(v112) = 1;
      if ( *((_DWORD *)v81 - 1) != -1839634494 )
        __break(0x8229u);
      v82 = v81(&v112);
      if ( v82 )
      {
        result = _drm_err("hsic value write failed ret %d\n", v82);
        goto LABEL_22;
      }
      v67 = *v56;
      v68 |= 0x8000000u;
      v78 = a2;
    }
    if ( (v67 & 8) != 0 )
    {
      v83 = *(_QWORD *)(a1 + 72);
      v84 = *((unsigned __int8 *)v56 + 20);
      *(_QWORD *)((char *)&v113 + 4) = 0;
      HIDWORD(v113) = *(_DWORD *)(*(_QWORD *)(v83 + 48) + 128LL) + 40;
      v115 = (char *)&v111 + 4;
      v116 = 0x400000000LL;
      v85 = *(__int64 (__fastcall **)(_QWORD))(v57 + 8);
      HIDWORD(v111) = v84;
      LODWORD(v112) = 1;
      if ( *((_DWORD *)v85 - 1) != -1839634494 )
        __break(0x8229u);
      v86 = v85(&v112);
      if ( v86 )
      {
        result = _drm_err("hsic contrast write failed ret %d\n", v86);
        goto LABEL_22;
      }
      v68 |= 0x10000000u;
      v78 = a2;
    }
    else if ( !v68 )
    {
      result = _drm_err("Invalid hsic config 0x%x\n", 0);
      goto LABEL_22;
    }
    LODWORD(v111) = v68 | 0x100000;
    if ( (_DWORD)v24 )
    {
      v87 = 0;
      v88 = 8 * v24;
      while ( v87 <= 0x27 )
      {
        v89 = *(unsigned int *)(v150[v87 / 8] + 64LL);
        if ( (unsigned int)v89 > 4 )
          goto LABEL_132;
        v112 = 0;
        v113 = 0u;
        v90 = dspp_mapping[v89];
        v91 = *(unsigned int *)(a1 + 64);
        v114 = 0;
        v115 = nullptr;
        v116 = 0;
        v109 = v90;
        v117 = 0;
        v118 = 0;
        HIDWORD(v112) = v90;
        LODWORD(v113) = 10;
        if ( (unsigned int)v91 > 4 )
          goto LABEL_132;
        v92 = *(unsigned int *)(a1 + 1496);
        if ( (unsigned int)v92 > 1 )
          goto LABEL_132;
        if ( (unsigned __int64)(16 * v91 + 8 * v92 + 800) > 0x7D0 )
          goto LABEL_133;
        HIDWORD(v113) = 0;
        DWORD1(v113) = 0;
        v115 = nullptr;
        v116 = 0;
        v114 = dspp_buf[2 * v91 + 100 + v92];
        v93 = *(__int64 (__fastcall **)(_QWORD))(v57 + 8);
        if ( *((_DWORD *)v93 - 1) != -1839634494 )
          __break(0x8228u);
        v66 = v93(&v112);
        if ( v66 )
          goto LABEL_77;
        v94 = *(_QWORD *)(a1 + 72);
        *(_QWORD *)((char *)&v113 + 4) = 0;
        v115 = (char *)&v111;
        v116 = 0x4E1EFFFFFLL;
        v95 = *(_QWORD *)(v94 + 48);
        LODWORD(v112) = 5;
        HIDWORD(v113) = *(_DWORD *)(v95 + 128);
        v96 = *(__int64 (__fastcall **)(_QWORD))(v57 + 8);
        if ( *((_DWORD *)v96 - 1) != -1839634494 )
          __break(0x8228u);
        v97 = v96(&v112);
        if ( v97 )
        {
          result = _drm_err("setting opcode failed ret %d\n", v97);
          goto LABEL_22;
        }
        v87 += 8LL;
        v78 = a2;
        if ( v88 == v87 )
          goto LABEL_122;
      }
      goto LABEL_133;
    }
LABEL_122:
    v98 = *((_DWORD *)v78 + 42);
    v121 = 0;
    v122 = 0;
    v123 = 0;
    v124 = 0;
    v99 = v98 | 1;
    *((_DWORD *)v78 + 42) = v99;
    v100 = *(unsigned int *)(a1 + 64);
    v119 = v78[2];
    v120 = 0;
    if ( (unsigned int)v100 > 4 )
      goto LABEL_132;
    v101 = *(unsigned int *)(a1 + 1496);
    if ( (unsigned int)v101 > 1 )
      goto LABEL_132;
    if ( (unsigned __int64)(16 * v100 + 8 * v101 + 800) <= 0x7D0 )
    {
      v102 = a2[19];
      LODWORD(v120) = 1;
      v103 = *(_DWORD *)(a1 + 28);
      LODWORD(v124) = 10;
      v125 = v102;
      v104 = *((_DWORD *)a2 + 40);
      LODWORD(v102) = *((_DWORD *)a2 + 41);
      v105 = dspp_buf[2 * v100 + 100 + v101];
      LODWORD(v123) = 0;
      v126 = __PAIR64__(v102, v104);
      v121 = v105;
      LODWORD(v105) = *((_DWORD *)a2 + 44);
      LODWORD(v128) = *((_DWORD *)a2 + 43);
      HIDWORD(v128) = v105;
      v127 = __PAIR64__(*((_DWORD *)a2 + 7), v99);
      result = sde_evtlog_log(
                 sde_dbg_base_evtlog,
                 "reg_dmav1_setup_dspp_pa_hsicv17",
                 2392,
                 -1,
                 v100,
                 v101,
                 v103,
                 1,
                 239);
      v106 = *(unsigned int *)(a1 + 28);
      if ( (unsigned int)v106 <= 2 )
      {
        v107 = *(__int64 (__fastcall **)(__int64 *, __int64))(v57 + 8 * v106 + 16);
        if ( v107 )
        {
          v108 = *(unsigned int *)(a1 + 1496);
          if ( *((_DWORD *)v107 - 1) != 1772228465 )
            __break(0x8228u);
          result = v107(&v119, v108);
          if ( (_DWORD)result )
            result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
        }
        goto LABEL_22;
      }
      goto LABEL_132;
    }
  }
LABEL_133:
  __break(1u);
  *(_QWORD *)(v27 - 24) = v6;
  *(_QWORD *)(v27 - 16) = v28;
  return reg_dmav1_setup_dspp_sixzonev17();
}
