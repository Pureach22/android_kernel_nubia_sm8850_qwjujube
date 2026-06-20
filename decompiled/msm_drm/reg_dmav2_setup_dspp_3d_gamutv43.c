unsigned __int64 __fastcall reg_dmav2_setup_dspp_3d_gamutv43(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6)
{
  int v6; // w24
  _DWORD *v8; // x21
  __int64 v9; // x2
  unsigned int v10; // w4
  int v11; // w8
  __int64 v12; // x9
  int v13; // w8
  int **v14; // x20
  unsigned __int64 result; // x0
  unsigned int v17; // w1
  int *v18; // x23
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  __int64 v23; // x8
  __int64 v24; // x9
  unsigned __int64 *v25; // x8
  void (__fastcall *v26)(_QWORD); // x9
  unsigned __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x9
  int *v30; // x8
  int v31; // w0
  int v32; // w1
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x9
  unsigned __int64 *v36; // x8
  void (__fastcall *v37)(_QWORD); // x9
  unsigned __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x9
  __int64 (__fastcall *v41)(_QWORD); // x8
  unsigned __int64 v42; // x22
  int v43; // w24
  _WORD *v44; // x8
  __int64 v45; // x9
  __int64 v46; // x10
  __int64 v47; // x11
  int *v48; // x14
  unsigned int v49; // w15
  int *v50; // x14
  int v51; // w16
  unsigned int v52; // w15
  int *v53; // x14
  __int64 (__fastcall *v54)(_QWORD); // x9
  int v55; // w0
  __int64 v56; // x1
  __int64 v57; // x8
  __int64 v58; // x8
  int *v59; // x9
  int v60; // w0
  __int64 v61; // x3
  __int64 v62; // x8
  _DWORD *v63; // x11
  _DWORD *v64; // x12
  unsigned int v65; // w13
  unsigned int v66; // w14
  __int16 v67; // w15
  int *v68; // x13
  __int64 v69; // x8
  __int64 v70; // x8
  __int64 (__fastcall *v71)(_QWORD); // x8
  unsigned int v72; // w0
  __int64 v73; // x8
  __int64 v74; // x8
  _DWORD *v75; // x8
  unsigned int v76; // w0
  __int64 v77; // x8
  _DWORD *v78; // x9
  unsigned int v79; // w0
  __int64 v80; // x8
  __int64 (__fastcall *v81)(__int64 *, __int64); // x9
  int v82; // w0
  unsigned __int64 StatusReg; // x25
  __int64 v84; // x26
  int v85; // [xsp+Ch] [xbp-164h] BYREF
  unsigned int v86; // [xsp+10h] [xbp-160h] BYREF
  unsigned int v87; // [xsp+14h] [xbp-15Ch] BYREF
  __int64 v88; // [xsp+18h] [xbp-158h] BYREF
  __int128 v89; // [xsp+20h] [xbp-150h]
  unsigned __int64 v90; // [xsp+30h] [xbp-140h]
  int *v91; // [xsp+38h] [xbp-138h]
  __int64 v92; // [xsp+40h] [xbp-130h]
  __int64 v93; // [xsp+48h] [xbp-128h]
  __int64 v94; // [xsp+50h] [xbp-120h]
  unsigned int v95; // [xsp+5Ch] [xbp-114h] BYREF
  __int64 v96; // [xsp+60h] [xbp-110h] BYREF
  _DWORD v97[3]; // [xsp+68h] [xbp-108h] BYREF
  __int64 v98; // [xsp+74h] [xbp-FCh]
  int v99; // [xsp+7Ch] [xbp-F4h]
  unsigned __int64 v100; // [xsp+80h] [xbp-F0h]
  char *v101; // [xsp+88h] [xbp-E8h]
  __int64 v102; // [xsp+90h] [xbp-E0h]
  __int64 v103; // [xsp+98h] [xbp-D8h]
  __int64 v104; // [xsp+A0h] [xbp-D0h]
  _BYTE v105[32]; // [xsp+A8h] [xbp-C8h] BYREF
  _BYTE v106[32]; // [xsp+C8h] [xbp-A8h] BYREF
  _BYTE v107[64]; // [xsp+E8h] [xbp-88h] BYREF
  _BYTE v108[64]; // [xsp+128h] [xbp-48h] BYREF
  __int64 v109; // [xsp+168h] [xbp-8h]

  v8 = v97;
  v109 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v93 = 0;
  v94 = 0;
  v91 = nullptr;
  v92 = 0;
  v90 = 0;
  v88 = 0;
  v89 = 0u;
  v85 = 0;
  v86 = 0;
  memset(v108, 0, sizeof(v108));
  memset(v107, 0, sizeof(v107));
  memset(v106, 0, sizeof(v106));
  memset(v105, 0, sizeof(v105));
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid cfg %pK ctx %pK\n", a2, (const void *)a1);
    goto LABEL_20;
  }
  v9 = *(unsigned int *)(a1 + 64);
  v10 = *(_DWORD *)(a1 + 1496);
  if ( !a2[2] || (unsigned int)v9 > 4 || v10 >= 2 )
  {
    result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", (const void *)a2[2], v9, 1, v10);
    goto LABEL_20;
  }
  if ( &dspp_buf[2 * v9] == (unsigned __int64 *)-80LL )
  {
    result = _drm_err("invalid dma_buf\n");
    goto LABEL_20;
  }
  v11 = *((_DWORD *)a2 + 40);
  v87 = 0;
  v12 = *a2;
  *((_DWORD *)a2 + 40) = v11 & 0xFF0F0FFF | 0x304000;
  *((_DWORD *)a2 + 42) = 3;
  if ( !v12 )
  {
    _drm_dev_dbg(0, 0, 1, "disable gamut feature\n");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "reg_dmav2_setup_dspp_3d_gamutv43",
      6288,
      -1,
      *(_DWORD *)(a1 + 64),
      *(_DWORD *)(a1 + 1496),
      *(_DWORD *)(a1 + 28),
      0,
      239);
    v17 = *(_DWORD *)(a1 + 64);
    v96 = 0;
    v18 = (int *)a2;
    v95 = 0;
    result = reg_dmav1_get_dspp_blk((__int64)a2, v17, &v95, &v96, v19, v20, v21, v22);
    if ( (_DWORD)result == -114 )
      goto LABEL_20;
    if ( (_DWORD)result != -22 )
    {
      result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
      if ( !result )
        goto LABEL_20;
      v14 = (int **)result;
      if ( result > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_20;
      v23 = *(unsigned int *)(a1 + 64);
      if ( (unsigned int)v23 >= 5 )
        goto LABEL_84;
      v24 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v24 > 1 )
        goto LABEL_84;
      if ( (unsigned __int64)(16 * v23 + 8 * v24 + 80) > 0x7D0 )
        goto LABEL_85;
      v25 = &dspp_buf[2 * v23 + v24];
      v26 = *(void (__fastcall **)(_QWORD))(result + 64);
      v27 = v25[10];
      if ( *((_DWORD *)v26 - 1) != -870478129 )
        __break(0x8229u);
      v26(v27);
      v28 = *(unsigned int *)(a1 + 64);
      v103 = 0;
      v104 = 0;
      v97[1] = v95;
      v97[2] = 1;
      if ( (unsigned int)v28 > 4 )
        goto LABEL_84;
      v29 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v29 > 1 )
        goto LABEL_84;
      if ( (unsigned __int64)(16 * v28 + 8 * v29 + 80) > 0x7D0 )
        goto LABEL_85;
      v99 = 0;
      v98 = 0;
      v102 = 0;
      v97[0] = 0;
      v100 = dspp_buf[2 * v28 + 10 + v29];
      v101 = nullptr;
      v30 = v14[1];
      if ( *(v30 - 1) != -1839634494 )
        __break(0x8228u);
      v31 = ((__int64 (__fastcall *)(_DWORD *))v30)(v97);
      if ( v31 )
        goto LABEL_34;
      v57 = *(_QWORD *)(a1 + 72);
      v98 = 0;
      v101 = (char *)&v96 + 4;
      v58 = *(_QWORD *)(v57 + 48);
      v102 = 0x400000000LL;
      v99 = *(_DWORD *)(v58 + 236);
      v59 = v14[1];
      v97[0] = 1;
      if ( *(v59 - 1) != -1839634494 )
        __break(0x8229u);
      v60 = ((__int64 (__fastcall *)(_DWORD *))v59)(v97);
      if ( v60 )
      {
        result = _drm_err("opmode modify single reg failed ret %d\n", v60);
      }
      else
      {
        v61 = v95;
        v18[42] = 2;
        result = ((__int64 (__fastcall *)(__int64, int *, int **, __int64, __int64))perform_sbdma_kickoff)(
                   a1,
                   v18,
                   v14,
                   v61,
                   1);
      }
      goto LABEL_20;
    }
LABEL_18:
    result = _drm_err("unable to determine LUTDMA DSPP blocks\n");
    goto LABEL_20;
  }
  v13 = *((_DWORD *)a2 + 2);
  if ( v13 != 39536 )
  {
    result = _drm_err("invalid size of payload len %d exp %zd\n", v13, 0x9A70u);
    goto LABEL_20;
  }
  v14 = (int **)a2;
  result = reg_dmav1_get_dspp_blk((__int64)a2, *(_DWORD *)(a1 + 64), &v86, &v87, a3, a4, a5, a6);
  if ( (_DWORD)result == -114 )
    goto LABEL_20;
  if ( (_DWORD)result == -22 )
    goto LABEL_18;
  if ( v87 >= 6 )
  {
    result = _drm_err("unable to process more than %d DSPP blocks\n", 5);
    goto LABEL_20;
  }
  v18 = *v14;
  v32 = (*v14)[2];
  if ( v32 != 1 )
  {
    result = _drm_err("invalid mode %d", v32);
    goto LABEL_20;
  }
  v6 = *v18;
  v33 = *(unsigned int *)(a1 + 1496);
  v85 = (2 * (*v18 & 1)) | 1;
  result = sde_reg_dma_get_ops(v33);
  if ( result )
  {
    v8 = (_DWORD *)result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      v34 = *(unsigned int *)(a1 + 64);
      if ( (unsigned int)v34 < 5 )
      {
        v35 = *(unsigned int *)(a1 + 1496);
        if ( (unsigned int)v35 <= 1 )
        {
          if ( (unsigned __int64)(16 * v34 + 8 * v35 + 80) > 0x7D0 )
            goto LABEL_85;
          v36 = &dspp_buf[2 * v34 + v35];
          v37 = *(void (__fastcall **)(_QWORD))(result + 64);
          v38 = v36[10];
          if ( *((_DWORD *)v37 - 1) != -870478129 )
            __break(0x8229u);
          v37(v38);
          v39 = *(unsigned int *)(a1 + 64);
          v93 = 0;
          v94 = 0;
          HIDWORD(v88) = v86;
          LODWORD(v89) = 1;
          if ( (unsigned int)v39 <= 4 )
          {
            v40 = *(unsigned int *)(a1 + 1496);
            if ( (unsigned int)v40 <= 1 )
            {
              if ( (unsigned __int64)(16 * v39 + 8 * v40 + 80) <= 0x7D0 )
              {
                HIDWORD(v89) = 0;
                *(_QWORD *)((char *)&v89 + 4) = 0;
                v92 = 0;
                LODWORD(v88) = 0;
                v90 = dspp_buf[2 * v39 + 10 + v40];
                v91 = nullptr;
                v41 = *((__int64 (__fastcall **)(_QWORD))v8 + 1);
                if ( *((_DWORD *)v41 - 1) != -1839634494 )
                  __break(0x8228u);
                v31 = v41(&v88);
                if ( !v31 )
                {
                  result = vzalloc_noprof(29496);
                  v42 = result;
                  if ( !result )
                    goto LABEL_20;
                  goto LABEL_50;
                }
LABEL_34:
                result = _drm_err("write decode select failed ret %d\n", v31);
                goto LABEL_20;
              }
LABEL_85:
              __break(1u);
              StatusReg = _ReadStatusReg(SP_EL0);
              v84 = *(_QWORD *)(StatusReg + 80);
              *(_QWORD *)(StatusReg + 80) = &reg_dmav2_setup_dspp_3d_gamutv43__alloc_tag;
              result = vzalloc_noprof(29496);
              v42 = result;
              *(_QWORD *)(StatusReg + 80) = v84;
              if ( !result )
                goto LABEL_20;
LABEL_50:
              v43 = 2 * (v6 & 1);
              v44 = (_WORD *)(v42 + 12);
              v45 = 0x3FFFFFFFFFFFF666LL;
              v46 = 2509;
              v47 = 7426;
              do
              {
                v48 = &v18[v45];
                v45 += 2;
                *(v44 - 6) = 16 * *((_WORD *)v48 + 5020);
                LODWORD(v48) = v48[2509];
                v49 = (unsigned int)v48 >> 12;
                *(v44 - 4) = 16 * (_WORD)v48;
                v50 = &v18[v46];
                *(v44 - 5) = v49 & 0xFFF0;
                v46 += 2;
                *(v44 - 3) = 16 * *((_WORD *)v50 + 2);
                v51 = ((unsigned int)*v50 >> 12) & 0xFFF0;
                *(v44 - 1) = 16 * *(_WORD *)v50;
                *(v44 - 2) = v51;
                *v44 = 16 * *((_WORD *)v50 + 4918);
                LODWORD(v50) = v50[2458];
                v52 = (unsigned int)v50 >> 12;
                v44[2] = 16 * (_WORD)v50;
                v53 = &v18[v47];
                v44[1] = v52 & 0xFFF0;
                v47 += 2;
                v44[3] = 16 * *(_WORD *)v53;
                LODWORD(v53) = *(v53 - 1);
                v44[5] = 16 * (_WORD)v53;
                v44[4] = ((unsigned int)v53 >> 12) & 0xFFF0;
                v44 += 12;
              }
              while ( v45 * 4 );
              HIDWORD(v89) = 0;
              v91 = (int *)v42;
              v92 = 0x733800000000LL;
              *(_QWORD *)((char *)&v89 + 4) = 0;
              v93 = 0x100000000LL;
              v94 = 0x4CD00000006LL;
              v54 = *((__int64 (__fastcall **)(_QWORD))v8 + 1);
              LODWORD(v88) = 6;
              if ( *((_DWORD *)v54 - 1) != -1839634494 )
                __break(0x8229u);
              v55 = v54(&v88);
              if ( v55 )
              {
                _drm_err("lut write failed ret %d\n", v55);
              }
              else
              {
                if ( v18 && (*(_BYTE *)v18 & 1) != 0 )
                {
                  v62 = 0;
                  v63 = v18 + 9;
                  do
                  {
                    v64 = &v63[v62];
                    *(_DWORD *)&v105[v62 * 4] = v63[v62 - 6] & 0xFFF | (v63[v62 - 6] >> 12 << 15);
                    v65 = v63[v62 - 5];
                    v66 = v65 >> 12;
                    v67 = v65 & 0xFFF;
                    v68 = (int *)&v106[v62 * 4];
                    v62 += 16;
                    *(v68 - 7) = v67 & 0x7FFF | (v66 << 15);
                    *(v68 - 6) = *(v64 - 4) & 0xFFF | (*(v64 - 4) >> 12 << 15);
                    *(v68 - 5) = *(v64 - 3) & 0xFFF | (*(v64 - 3) >> 12 << 15);
                    *(v68 - 4) = *(v64 - 2) & 0xFFF | (*(v64 - 2) >> 12 << 15);
                    *(v68 - 3) = *(v64 - 1) & 0xFFF | (*(v64 - 1) >> 12 << 15);
                    *(v68 - 2) = *v64 & 0xFFF | (*v64 >> 12 << 15);
                    *(v68 - 1) = v64[1] & 0xFFF | (v64[1] >> 12 << 15);
                    *v68 = v64[2] & 0xFFF | (v64[2] >> 12 << 15);
                    v68[1] = v64[3] & 0xFFF | (v64[3] >> 12 << 15);
                    v68[2] = v64[4] & 0xFFF | (v64[4] >> 12 << 15);
                    v68[3] = v64[5] & 0xFFF | (v64[5] >> 12 << 15);
                    v68[4] = v64[6] & 0xFFF | (v64[6] >> 12 << 15);
                    v68[5] = v64[7] & 0xFFF | (v64[7] >> 12 << 15);
                    v68[6] = v64[8] & 0xFFF | (v64[8] >> 12 << 15);
                    v68[7] = v64[9] & 0xFFF | (v64[9] >> 12 << 15);
                  }
                  while ( v62 != 48 );
                  v43 = v85 & 2;
                }
                if ( !v43 )
                  goto LABEL_78;
                v69 = *(_QWORD *)(a1 + 72);
                *(_QWORD *)((char *)&v89 + 4) = 0;
                v70 = *(_QWORD *)(v69 + 48);
                v91 = (int *)v105;
                v92 = 0x4000000000LL;
                LODWORD(v88) = 2;
                HIDWORD(v89) = *(_DWORD *)(v70 + 236) + 16;
                v71 = *((__int64 (__fastcall **)(_QWORD))v8 + 1);
                if ( *((_DWORD *)v71 - 1) != -1839634494 )
                  __break(0x8228u);
                v72 = v71(&v88);
                LODWORD(v56) = v72;
                if ( v72 )
                  goto LABEL_77;
                v73 = *(_QWORD *)(a1 + 72);
                *(_QWORD *)((char *)&v89 + 4) = 0;
                v91 = (int *)v107;
                v92 = 0x4000000000LL;
                v74 = *(_QWORD *)(v73 + 48);
                LODWORD(v88) = 2;
                HIDWORD(v89) = *(_DWORD *)(v74 + 236) + 80;
                v75 = *((_DWORD **)v8 + 1);
                if ( *(v75 - 1) != -1839634494 )
                  __break(0x8228u);
                v76 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v75)(&v88, v72);
                LODWORD(v56) = v76;
                if ( v76 )
                  goto LABEL_77;
                v77 = *(_QWORD *)(a1 + 72);
                *(_QWORD *)((char *)&v89 + 4) = 0;
                HIDWORD(v89) = *(_DWORD *)(*(_QWORD *)(v77 + 48) + 236LL) + 144;
                v91 = (int *)v108;
                v92 = 0x4000000000LL;
                v78 = *((_DWORD **)v8 + 1);
                LODWORD(v88) = 2;
                if ( *(v78 - 1) != -1839634494 )
                  __break(0x8229u);
                v79 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v78)(&v88, v76);
                v56 = v79;
                if ( v79 )
                {
LABEL_77:
                  _drm_err("write scale/off reg failed ret %d\n", v56);
                }
                else
                {
LABEL_78:
                  v80 = *(_QWORD *)(a1 + 72);
                  *(_QWORD *)((char *)&v89 + 4) = 0;
                  HIDWORD(v89) = *(_DWORD *)(*(_QWORD *)(v80 + 48) + 236LL);
                  v91 = &v85;
                  v92 = 0x400000000LL;
                  v81 = *((__int64 (__fastcall **)(__int64 *, __int64))v8 + 1);
                  LODWORD(v88) = 1;
                  if ( *((_DWORD *)v81 - 1) != -1839634494 )
                    __break(0x8229u);
                  v82 = v81(&v88, v56);
                  if ( v82 )
                  {
                    _drm_err("opmode write single reg failed ret %d\n", v82);
                  }
                  else
                  {
                    sde_evtlog_log(
                      sde_dbg_base_evtlog,
                      "reg_dmav2_setup_dspp_3d_gamutv43",
                      6420,
                      -1,
                      *(_DWORD *)(a1 + 64),
                      *(_DWORD *)(a1 + 1496),
                      *(_DWORD *)(a1 + 28),
                      1,
                      239);
                    ((void (__fastcall *)(__int64, int **, _DWORD *, _QWORD, __int64))perform_sbdma_kickoff)(
                      a1,
                      v14,
                      v8,
                      v86,
                      1);
                  }
                }
              }
              result = vfree(v42);
              goto LABEL_20;
            }
          }
        }
      }
LABEL_84:
      __break(0x5512u);
      goto LABEL_85;
    }
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
