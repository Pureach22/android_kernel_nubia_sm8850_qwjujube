__int64 __fastcall reg_dma_validate_sixzone_config(
        __int64 a1,
        _QWORD *a2,
        _DWORD *a3,
        _DWORD *a4,
        _QWORD *a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // d14
  __int64 v11; // x8
  unsigned int v12; // w10
  int v13; // w9
  __int64 result; // x0
  double v19; // d0
  unsigned int v20; // w1
  _QWORD *v21; // x22
  double v22; // d1
  double v23; // d2
  double v24; // d3
  int dspp_blk; // w0
  __int64 v26; // x26
  __int64 v27; // x8
  unsigned __int64 ops; // x0
  __int64 v29; // x15
  __int64 v30; // d3
  unsigned __int64 v31; // x20
  __int64 v32; // x8
  __int64 v33; // x9
  unsigned __int64 *v34; // x8
  void (__fastcall *v35)(_QWORD); // x9
  unsigned __int64 v36; // x0
  unsigned int v37; // w23
  unsigned __int64 v38; // x24
  __int64 v39; // x26
  __int64 v40; // x8
  unsigned int v41; // w9
  __int64 v42; // x8
  __int64 v43; // x9
  __int64 (__fastcall *v44)(_QWORD); // x8
  unsigned int v45; // w0
  __int64 v46; // x8
  __int64 v47; // x8
  __int64 (__fastcall *v48)(_QWORD); // x8
  unsigned int v49; // w0
  __int64 v50; // x8
  __int64 v51; // x9
  __int64 v52; // x1
  __int64 v53; // x9
  int v54; // w10
  __int64 v55; // x9
  unsigned __int64 v56; // x9
  __int64 v57; // x8
  int v58; // w10
  int v59; // w11
  __int64 (__fastcall *v60)(_QWORD); // x8
  unsigned int v61; // w0
  __int64 v62; // [xsp+8h] [xbp-D8h] BYREF
  __int64 v63; // [xsp+10h] [xbp-D0h] BYREF
  __int64 v64; // [xsp+18h] [xbp-C8h] BYREF
  __int64 v65; // [xsp+20h] [xbp-C0h]
  unsigned __int64 v66; // [xsp+28h] [xbp-B8h]
  __int64 v67; // [xsp+30h] [xbp-B0h]
  __int64 v68; // [xsp+38h] [xbp-A8h]
  __int64 v69; // [xsp+40h] [xbp-A0h]
  __int64 v70; // [xsp+48h] [xbp-98h]
  int v71; // [xsp+50h] [xbp-90h]
  __int64 v72; // [xsp+54h] [xbp-8Ch]
  int v73; // [xsp+5Ch] [xbp-84h]
  int v74; // [xsp+60h] [xbp-80h]
  int v75; // [xsp+64h] [xbp-7Ch]
  __int64 v76; // [xsp+68h] [xbp-78h] BYREF
  __int128 v77; // [xsp+70h] [xbp-70h]
  unsigned __int64 v78; // [xsp+80h] [xbp-60h]
  char *v79; // [xsp+88h] [xbp-58h]
  __int64 v80; // [xsp+90h] [xbp-50h]
  __int64 v81; // [xsp+98h] [xbp-48h]
  __int64 v82; // [xsp+A0h] [xbp-40h]
  _QWORD dest[7]; // [xsp+A8h] [xbp-38h] BYREF

  dest[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    _drm_err("invalid cfg %pK ctx %pK\n", a2, (const void *)a1);
    result = 4294967274LL;
    goto LABEL_23;
  }
  v11 = *(unsigned int *)(a1 + 64);
  v12 = *(_DWORD *)(a1 + 1496);
  if ( !a2[2] || (unsigned int)v11 > 4 || v12 >= 2 )
  {
    _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", (const void *)a2[2], v11, 9, v12);
    result = 4294967274LL;
    goto LABEL_23;
  }
  if ( &dspp_buf[2 * v11] == (unsigned __int64 *)-720LL )
  {
    _drm_err("invalid dma_buf\n");
LABEL_15:
    result = 4294967274LL;
    goto LABEL_23;
  }
  if ( *a2 )
  {
    v13 = *((_DWORD *)a2 + 2);
    if ( v13 != 4648 )
    {
      _drm_err("invalid size of payload len %d exp %zd\n", v13, 0x1228u);
      result = 4294967274LL;
      goto LABEL_23;
    }
    result = reg_dmav1_get_dspp_blk((__int64)a2, v11, a4, a3, a6, a7, a8, a9);
    if ( (_DWORD)result != -114 )
    {
      if ( (_DWORD)result != -22 )
      {
        v27 = (unsigned int)*a3;
        if ( (unsigned int)v27 < 6 )
        {
          if ( (unsigned int)v27 < 2 )
          {
            result = 0;
            *a5 = a1;
          }
          else
          {
            memcpy(a5, a2 + 6, 8 * v27);
            result = 0;
          }
        }
        else
        {
          _drm_err("unable to process more than %d DSPP blocks\n", 5);
          result = 4294967274LL;
        }
        goto LABEL_23;
      }
      _drm_err("unable to determine LUTDMA DSPP blocks\n");
      goto LABEL_15;
    }
LABEL_23:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v19 = _drm_dev_dbg(0, 0, 1, "disable sixzone feature\n");
  v20 = *(_DWORD *)(a1 + 64);
  v81 = 0;
  v82 = 0;
  v21 = a2;
  v79 = nullptr;
  v80 = 0;
  v78 = 0;
  v76 = 0;
  v77 = 0u;
  v62 = 0;
  v63 = 0;
  dspp_blk = reg_dmav1_get_dspp_blk((__int64)a2, v20, (_DWORD *)&v62 + 1, &v63, v19, v22, v23, v24);
  if ( dspp_blk == -114 )
  {
LABEL_22:
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "reg_dma_validate_sixzone_config",
      2484,
      -1,
      *(_DWORD *)(a1 + 64),
      *(_DWORD *)(a1 + 1496),
      *(_DWORD *)(a1 + 28),
      0,
      239);
    result = 4294967182LL;
    goto LABEL_23;
  }
  if ( dspp_blk == -22 )
  {
    _drm_err("unable to determine LUTDMA DSPP blocks\n");
    goto LABEL_22;
  }
  v26 = (unsigned int)v63;
  if ( (unsigned int)v63 >= 6 )
  {
    _drm_err("unable to process more than %d DSPP blocks\n", 5);
    goto LABEL_22;
  }
  memset(dest, 0, 40);
  if ( (unsigned int)v63 < 2 )
    dest[0] = a1;
  else
    memcpy(dest, a2 + 6, 8LL * (unsigned int)v63);
  ops = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
  if ( !ops )
    goto LABEL_22;
  v31 = ops;
  if ( ops > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_22;
  v32 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v32 > 4 )
    goto LABEL_67;
  v33 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v33 > 1 )
    goto LABEL_67;
  if ( (unsigned __int64)(16 * v32 + 8 * v33 + 720) <= 0x7D0 )
  {
    v34 = &dspp_buf[2 * v32 + v33];
    v35 = *(void (__fastcall **)(_QWORD))(ops + 64);
    v36 = v34[90];
    if ( *((_DWORD *)v35 - 1) != -870478129 )
      __break(0x8229u);
    v35(v36);
    cp_feature_get_curr_mode(2, v21[25], &v62);
    if ( (v62 & 0x3F) != 0 )
      v37 = 0x1FFFFFFF;
    else
      v37 = 535822335;
    if ( (_DWORD)v26 )
    {
      v38 = 0;
      v39 = 8 * v26;
      while ( v38 != 40 )
      {
        v40 = *(unsigned int *)(dest[v38 / 8] + 64LL);
        if ( (unsigned int)v40 > 4 )
          goto LABEL_67;
        v76 = 0;
        v77 = 0u;
        v41 = dspp_mapping[v40];
        v42 = *(unsigned int *)(a1 + 64);
        v78 = 0;
        v79 = nullptr;
        v80 = 0;
        HIDWORD(v62) = v41;
        v81 = 0;
        v82 = 0;
        HIDWORD(v76) = v41;
        LODWORD(v77) = 9;
        if ( (unsigned int)v42 > 4 )
          goto LABEL_67;
        v43 = *(unsigned int *)(a1 + 1496);
        if ( (unsigned int)v43 > 1 )
          goto LABEL_67;
        if ( (unsigned __int64)(16 * v42 + 8 * v43 + 720) > 0x7D0 )
          goto LABEL_68;
        DWORD1(v77) = 0;
        v79 = nullptr;
        v80 = 0;
        v78 = dspp_buf[2 * v42 + 90 + v43];
        v44 = *(__int64 (__fastcall **)(_QWORD))(v31 + 8);
        if ( *((_DWORD *)v44 - 1) != -1839634494 )
          __break(0x8228u);
        v45 = v44(&v76);
        if ( v45 )
        {
          _drm_err("write decode select failed ret %d\n", v45);
          goto LABEL_22;
        }
        v46 = *(_QWORD *)(a1 + 72);
        v79 = (char *)&v63 + 4;
        *(_QWORD *)((char *)&v77 + 4) = 0;
        v47 = *(_QWORD *)(v46 + 48);
        LODWORD(v76) = 5;
        HIDWORD(v77) = *(_DWORD *)(v47 + 128);
        v80 = v37 | 0x400000000LL;
        v48 = *(__int64 (__fastcall **)(_QWORD))(v31 + 8);
        if ( *((_DWORD *)v48 - 1) != -1839634494 )
          __break(0x8228u);
        v49 = v48(&v76);
        if ( v49 )
        {
          _drm_err("setting reg failed ret %d\n", v49);
          goto LABEL_22;
        }
        v38 += 8LL;
        if ( v39 == v38 )
          goto LABEL_55;
      }
      goto LABEL_68;
    }
LABEL_55:
    v50 = *(unsigned int *)(a1 + 64);
    v51 = v21[2];
    v68 = 0;
    v69 = 0;
    v66 = 0;
    v67 = 0;
    v64 = v51;
    v65 = 0;
    if ( (unsigned int)v50 > 4 )
      goto LABEL_67;
    v52 = *(unsigned int *)(a1 + 1496);
    if ( (unsigned int)v52 > 1 )
      goto LABEL_67;
    if ( (unsigned __int64)(16 * v50 + 8 * v52 + 720) <= 0x7D0 )
    {
      LODWORD(v65) = 1;
      v53 = v21[19];
      LODWORD(v69) = 9;
      v54 = *((_DWORD *)v21 + 40);
      v70 = v53;
      v55 = *(_QWORD *)((char *)v21 + 164);
      v71 = v54;
      v72 = v55;
      v56 = dspp_buf[2 * v50 + 90 + v52];
      v57 = *(unsigned int *)(a1 + 28);
      v59 = *((_DWORD *)v21 + 43);
      v58 = *((_DWORD *)v21 + 44);
      v66 = v56;
      LODWORD(v56) = *((_DWORD *)v21 + 7);
      v74 = v59;
      v75 = v58;
      v73 = v56;
      if ( (unsigned int)v57 <= 2 )
      {
        v60 = *(__int64 (__fastcall **)(_QWORD))(v31 + 8 * v57 + 16);
        if ( v60 )
        {
          if ( *((_DWORD *)v60 - 1) != 1772228465 )
            __break(0x8228u);
          v61 = v60(&v64);
          if ( v61 )
            _drm_err("failed to kick off ret %d\n", v61);
        }
        goto LABEL_22;
      }
LABEL_67:
      __break(0x5512u);
    }
  }
LABEL_68:
  __break(1u);
  *(_QWORD *)(v29 - 24) = v9;
  *(_QWORD *)(v29 - 16) = v30;
  return reg_dmav2_setup_dspp_sixzonev2();
}
