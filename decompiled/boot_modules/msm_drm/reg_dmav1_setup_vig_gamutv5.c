size_t __fastcall reg_dmav1_setup_vig_gamutv5(__int64 a1, __int64 a2)
{
  __int64 v3; // x2
  __int64 v4; // x8
  int v5; // w8
  __int64 v7; // x8
  int v8; // w23
  char v9; // w0
  char *v10; // x24
  unsigned int v11; // w1
  size_t result; // x0
  int v14; // w25
  int v15; // w28
  int v16; // w8
  int v17; // w26
  __int64 v18; // x0
  int v19; // w27
  size_t v20; // x20
  __int64 v21; // x8
  __int64 v22; // x9
  char *v23; // x8
  void (__fastcall *v24)(_QWORD); // x9
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x9
  __int64 (__fastcall *v28)(_QWORD); // x8
  unsigned int v29; // w0
  int v30; // w8
  __int64 (__fastcall *v31)(_QWORD); // x9
  unsigned int v32; // w0
  __int64 v33; // x1
  _DWORD *v34; // x9
  unsigned int v35; // w0
  __int64 v36; // x1
  int v37; // w8
  _DWORD *v38; // x9
  unsigned int v39; // w0
  _DWORD *v40; // x9
  unsigned int v41; // w0
  int v42; // w8
  _DWORD *v43; // x9
  unsigned int v44; // w0
  _DWORD *v45; // x9
  unsigned int v46; // w0
  int v47; // w8
  _DWORD *v48; // x9
  unsigned int v49; // w0
  _DWORD *v50; // x9
  unsigned int v51; // w0
  __int64 (__fastcall *v52)(__int64 *, __int64); // x9
  unsigned int v53; // w0
  int v54; // w25
  _DWORD *v55; // x8
  unsigned int v56; // w0
  _DWORD *v57; // x8
  unsigned int v58; // w0
  _DWORD *v59; // x9
  unsigned int v60; // w0
  __int64 v61; // x4
  __int64 v62; // x8
  __int64 v63; // x5
  __int64 v64; // x10
  int v65; // w6
  int v66; // w8
  __int64 v67; // x10
  __int64 v68; // x8
  unsigned int v69; // w9
  __int64 v70; // x8
  __int64 (__fastcall *v71)(__int64 *, __int64); // x8
  __int64 v72; // x1
  int v73; // [xsp+14h] [xbp-ACh]
  __int64 v74; // [xsp+18h] [xbp-A8h] BYREF
  __int64 v75; // [xsp+20h] [xbp-A0h]
  __int64 v76; // [xsp+28h] [xbp-98h]
  __int64 v77; // [xsp+30h] [xbp-90h]
  __int64 v78; // [xsp+38h] [xbp-88h]
  __int64 v79; // [xsp+40h] [xbp-80h]
  __int64 v80; // [xsp+48h] [xbp-78h]
  __int128 v81; // [xsp+50h] [xbp-70h]
  unsigned __int64 v82; // [xsp+60h] [xbp-60h]
  __int64 v83; // [xsp+68h] [xbp-58h] BYREF
  __int128 v84; // [xsp+70h] [xbp-50h]
  __int64 v85; // [xsp+80h] [xbp-40h]
  char *v86; // [xsp+88h] [xbp-38h]
  __int64 v87; // [xsp+90h] [xbp-30h]
  __int64 v88; // [xsp+98h] [xbp-28h]
  __int64 v89; // [xsp+A0h] [xbp-20h]
  _QWORD v90[3]; // [xsp+A8h] [xbp-18h] BYREF

  v90[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v89 = 0;
  v90[0] = 0;
  v87 = 0;
  v88 = 0;
  v85 = 0;
  v86 = nullptr;
  v84 = 0u;
  v83 = 0;
  v82 = 0;
  v80 = 0;
  v81 = 0u;
  v78 = 0;
  v79 = 0;
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid cfg %pK ctx %pK\n", (const void *)a2, (const void *)a1);
LABEL_21:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v3 = *(unsigned int *)(a1 + 48);
  if ( !*(_QWORD *)(a2 + 16) || (unsigned int)(v3 - 15) <= 0xFFFFFFF1 )
  {
    result = _drm_err("invalid ctl %pK sspp idx %d feature %d\n", *(const void **)(a2 + 16), v3, 1);
    goto LABEL_21;
  }
  v4 = *(unsigned int *)(a1 + 1392);
  if ( (unsigned int)v4 > 1 )
    goto LABEL_117;
  if ( (unsigned __int64)(16 * v3 + 8 * v4 + 6240) > 0x4650 )
    goto LABEL_118;
  if ( !sspp_buf[2 * v3 + 780 + v4] )
  {
    result = _drm_err("invalid dma_buf for rect idx %d sspp idx %d\n", 1, v3);
    goto LABEL_21;
  }
  if ( !*(_QWORD *)a2 )
  {
    _drm_dev_dbg(0, 0, 1, "disable gamut feature\n");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "reg_dmav1_setup_vig_gamutv5",
      3461,
      -1,
      *(_DWORD *)(a1 + 48),
      *(_DWORD *)(a1 + 1392),
      *(_DWORD *)(a1 + 28),
      0,
      239);
    result = vig_gamutv5_off(a1, a2);
    goto LABEL_21;
  }
  v5 = *(_DWORD *)(a2 + 8);
  if ( v5 != 39536 )
  {
    result = _drm_err("invalid size of payload len %d exp %zd\n", v5, 0x9A70u);
    goto LABEL_21;
  }
  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 56) + 48LL);
  v8 = *(_DWORD *)(v7 + 296);
  if ( *(_DWORD *)(a1 + 28) )
  {
    printk(&unk_243701, "ctx->cap->sblk->gamut_blk.base");
    v9 = 0;
  }
  else
  {
    v9 = sde_reg_read(a1, *(unsigned int *)(v7 + 288));
  }
  v10 = *(char **)a2;
  v11 = *(_DWORD *)(*(_QWORD *)a2 + 8LL);
  if ( v11 >= 4 )
  {
    _drm_err("invalid mode %d", v11);
LABEL_14:
    result = _drm_err("invalid mode info rc %d\n", 4294967274LL);
    goto LABEL_21;
  }
  v14 = 224;
  switch ( v11 )
  {
    case 3u:
      if ( (v9 & 0xC) == 8 )
        v15 = 640;
      else
        v15 = 0;
      if ( (v9 & 0xC) == 8 )
        v17 = 12;
      else
        v17 = 8;
      if ( (v9 & 0xC) == 8 )
        v14 = 224;
      else
        v14 = 16;
      v16 = 4400;
      break;
    case 2u:
      v17 = 4;
      v15 = 1248;
      v16 = 256;
      break;
    case 1u:
      v15 = 0;
      if ( (v9 & 0x1C) == 0x10 )
        v14 = 16;
      else
        v14 = 224;
      v16 = 9832;
      v17 = 16 * ((v9 & 0x1C) != 16);
      break;
    default:
      goto LABEL_14;
  }
  v73 = v16;
  v18 = *(unsigned int *)(a1 + 1392);
  v19 = 2 * (*(_DWORD *)v10 & 1);
  HIDWORD(v90[0]) = v17 | v19 | 1;
  result = sde_reg_dma_get_ops(v18);
  if ( !result )
    goto LABEL_21;
  v20 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_21;
  v21 = *(unsigned int *)(a1 + 48);
  if ( (unsigned int)v21 >= 0xF )
    goto LABEL_117;
  v22 = *(unsigned int *)(a1 + 1392);
  if ( (unsigned int)v22 > 1 )
    goto LABEL_117;
  if ( (unsigned __int64)(16 * v21 + 8 * v22 + 6240) > 0x4650 )
    goto LABEL_118;
  v23 = (char *)&sspp_buf[2 * v21 + v22];
  v24 = *(void (__fastcall **)(_QWORD))(result + 64);
  v25 = *((_QWORD *)v23 + 780);
  if ( *((_DWORD *)v24 - 1) != -870478129 )
    __break(0x8229u);
  v24(v25);
  v26 = *(unsigned int *)(a1 + 48);
  v83 = 0;
  v84 = 0u;
  v85 = 0;
  v86 = nullptr;
  v87 = 0;
  v88 = 0;
  v89 = 0;
  if ( (unsigned int)v26 > 0xE
    || (v27 = *(unsigned int *)(a1 + 1392), HIDWORD(v83) = sspp_mapping[v26], LODWORD(v84) = 1, (unsigned int)v27 > 1) )
  {
LABEL_117:
    __break(0x5512u);
    goto LABEL_118;
  }
  if ( (unsigned __int64)(16 * v26 + 8 * v27 + 6240) <= 0x4650 )
  {
    HIDWORD(v84) = 0;
    DWORD1(v84) = 0;
    v87 = 0;
    v85 = sspp_buf[2 * v26 + 780 + v27];
    v86 = nullptr;
    v28 = *(__int64 (__fastcall **)(_QWORD))(v20 + 8);
    if ( *((_DWORD *)v28 - 1) != -1839634494 )
      __break(0x8228u);
    v29 = v28(&v83);
    if ( v29 )
    {
      result = _drm_err("write decode select failed ret %d\n", v29);
      goto LABEL_21;
    }
    if ( v17 == 16 )
      v30 = 6144;
    else
      v30 = 4096;
    HIDWORD(v84) = v8 + 4;
    *(_QWORD *)((char *)&v84 + 4) = 0;
    v86 = (char *)v90;
    v87 = 0x400000000LL;
    v31 = *(__int64 (__fastcall **)(_QWORD))(v20 + 8);
    LODWORD(v90[0]) = v15 | v30;
    LODWORD(v83) = 1;
    if ( *((_DWORD *)v31 - 1) != -1839634494 )
      __break(0x8229u);
    v32 = v31(&v83);
    v33 = v32;
    if ( v32 )
    {
LABEL_60:
      result = _drm_err("write tbl sel reg failed ret %d\n", v33);
      goto LABEL_21;
    }
    v86 = v10 + 204;
    HIDWORD(v84) = v8 + 12;
    *(_QWORD *)((char *)&v84 + 4) = 2;
    LODWORD(v87) = 0;
    HIDWORD(v87) = v73;
    v34 = *(_DWORD **)(v20 + 8);
    LODWORD(v83) = 4;
    if ( *(v34 - 1) != -1839634494 )
      __break(0x8229u);
    v35 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v34)(&v83, v32);
    v36 = v35;
    if ( v35 )
      goto LABEL_65;
    *(_QWORD *)((char *)&v84 + 4) = 0;
    HIDWORD(v84) = v8 + 4;
    if ( v17 == 16 )
      v37 = 10240;
    else
      v37 = 0x2000;
    v86 = (char *)v90;
    v87 = 0x400000000LL;
    v38 = *(_DWORD **)(v20 + 8);
    LODWORD(v90[0]) = v15 | v37;
    LODWORD(v83) = 1;
    if ( *(v38 - 1) != -1839634494 )
      __break(0x8229u);
    v39 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v38)(&v83, v35);
    v33 = v39;
    if ( v39 )
      goto LABEL_60;
    HIDWORD(v84) = v8 + 12;
    *(_QWORD *)((char *)&v84 + 4) = 2;
    v86 = v10 + 10036;
    LODWORD(v87) = 0;
    HIDWORD(v87) = v73;
    v40 = *(_DWORD **)(v20 + 8);
    LODWORD(v83) = 4;
    if ( *(v40 - 1) != -1839634494 )
      __break(0x8229u);
    v41 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v40)(&v83, v39);
    v36 = v41;
    if ( v41 )
      goto LABEL_65;
    *(_QWORD *)((char *)&v84 + 4) = 0;
    HIDWORD(v84) = v8 + 4;
    if ( v17 == 16 )
      v42 = 18432;
    else
      v42 = 0x4000;
    v86 = (char *)v90;
    v87 = 0x400000000LL;
    v43 = *(_DWORD **)(v20 + 8);
    LODWORD(v90[0]) = v15 | v42;
    LODWORD(v83) = 1;
    if ( *(v43 - 1) != -1839634494 )
      __break(0x8229u);
    v44 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v43)(&v83, v41);
    v33 = v44;
    if ( v44 )
      goto LABEL_60;
    HIDWORD(v84) = v8 + 12;
    *(_QWORD *)((char *)&v84 + 4) = 2;
    v86 = v10 + 19868;
    LODWORD(v87) = 0;
    HIDWORD(v87) = v73;
    v45 = *(_DWORD **)(v20 + 8);
    LODWORD(v83) = 4;
    if ( *(v45 - 1) != -1839634494 )
      __break(0x8229u);
    v46 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v45)(&v83, v44);
    v36 = v46;
    if ( v46 )
      goto LABEL_65;
    *(_QWORD *)((char *)&v84 + 4) = 0;
    HIDWORD(v84) = v8 + 4;
    if ( v17 == 16 )
      v47 = 34816;
    else
      v47 = 0x8000;
    v86 = (char *)v90;
    v87 = 0x400000000LL;
    v48 = *(_DWORD **)(v20 + 8);
    LODWORD(v90[0]) = v15 | v47;
    LODWORD(v83) = 1;
    if ( *(v48 - 1) != -1839634494 )
      __break(0x8229u);
    v49 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v48)(&v83, v46);
    v33 = v49;
    if ( v49 )
      goto LABEL_60;
    HIDWORD(v84) = v8 + 12;
    *(_QWORD *)((char *)&v84 + 4) = 2;
    v86 = v10 + 29700;
    LODWORD(v87) = 0;
    HIDWORD(v87) = v73;
    v50 = *(_DWORD **)(v20 + 8);
    LODWORD(v83) = 4;
    if ( *(v50 - 1) != -1839634494 )
      __break(0x8229u);
    v51 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v50)(&v83, v49);
    v36 = v51;
    if ( v51 )
    {
LABEL_65:
      result = _drm_err("write color reg failed ret %d\n", v36);
      goto LABEL_21;
    }
    if ( v19 )
    {
      v54 = v14 + v8;
      *(_QWORD *)((char *)&v84 + 4) = 0;
      HIDWORD(v84) = v54;
      v86 = v10 + 12;
      v87 = 0x4000000000LL;
      v55 = *(_DWORD **)(v20 + 8);
      LODWORD(v83) = 2;
      if ( *(v55 - 1) != -1839634494 )
        __break(0x8228u);
      v56 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v55)(&v83, v51);
      v36 = v56;
      if ( v56 )
        goto LABEL_107;
      *(_QWORD *)((char *)&v84 + 4) = 0;
      HIDWORD(v84) = v54 + 64;
      v86 = v10 + 76;
      v87 = 0x4000000000LL;
      v57 = *(_DWORD **)(v20 + 8);
      LODWORD(v83) = 2;
      if ( *(v57 - 1) != -1839634494 )
        __break(0x8228u);
      v58 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v57)(&v83, v56);
      v36 = v58;
      if ( v58 )
        goto LABEL_107;
      *(_QWORD *)((char *)&v84 + 4) = 0;
      HIDWORD(v84) = v54 + 128;
      v86 = v10 + 140;
      v87 = 0x4000000000LL;
      v59 = *(_DWORD **)(v20 + 8);
      LODWORD(v83) = 2;
      if ( *(v59 - 1) != -1839634494 )
        __break(0x8229u);
      v60 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v59)(&v83, v58);
      v36 = v60;
      if ( v60 )
      {
LABEL_107:
        result = _drm_err("write scale/off reg failed ret %d\n", v36);
        goto LABEL_21;
      }
    }
    HIDWORD(v84) = v8;
    *(_QWORD *)((char *)&v84 + 4) = 0;
    v86 = (char *)v90 + 4;
    v87 = 0x400000300LL;
    v52 = *(__int64 (__fastcall **)(__int64 *, __int64))(v20 + 8);
    LODWORD(v83) = 5;
    if ( *((_DWORD *)v52 - 1) != -1839634494 )
      __break(0x8229u);
    v53 = v52(&v83, v36);
    if ( v53 )
    {
      result = _drm_err("opmode write single reg failed ret %d\n", v53);
      goto LABEL_21;
    }
    v61 = *(unsigned int *)(a1 + 48);
    v62 = *(_QWORD *)(a2 + 16);
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    v74 = v62;
    v75 = 0;
    if ( (unsigned int)v61 > 0xE )
      goto LABEL_117;
    v63 = *(unsigned int *)(a1 + 1392);
    if ( (unsigned int)v63 > 1 )
      goto LABEL_117;
    if ( (unsigned __int64)(16 * v61 + 8 * v63 + 6240) <= 0x4650 )
    {
      v64 = *(_QWORD *)(a2 + 152);
      LODWORD(v75) = 1;
      v65 = *(_DWORD *)(a1 + 28);
      LODWORD(v79) = 1;
      v66 = *(_DWORD *)(a2 + 160);
      v80 = v64;
      v67 = *(_QWORD *)(a2 + 164);
      LODWORD(v81) = v66;
      v68 = sspp_buf[2 * v61 + 780 + v63];
      *(_QWORD *)((char *)&v81 + 4) = v67;
      LODWORD(v67) = *(_DWORD *)(a2 + 172);
      v69 = *(_DWORD *)(a2 + 176);
      v76 = v68;
      LODWORD(v68) = *(_DWORD *)(a2 + 28);
      LODWORD(v78) = 0;
      v82 = __PAIR64__(v69, v67);
      HIDWORD(v81) = v68;
      result = sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_vig_gamutv5", 3551, -1, v61, v63, v65, 1, 239);
      v70 = *(unsigned int *)(a1 + 28);
      if ( (unsigned int)v70 <= 2 )
      {
        v71 = *(__int64 (__fastcall **)(__int64 *, __int64))(v20 + 8 * v70 + 16);
        if ( v71 )
        {
          v72 = *(unsigned int *)(a1 + 1392);
          if ( *((_DWORD *)v71 - 1) != 1772228465 )
            __break(0x8228u);
          result = v71(&v74, v72);
          if ( (_DWORD)result )
            result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
        }
        goto LABEL_21;
      }
      goto LABEL_117;
    }
  }
LABEL_118:
  __break(1u);
  return reg_dma_sspp_check();
}
