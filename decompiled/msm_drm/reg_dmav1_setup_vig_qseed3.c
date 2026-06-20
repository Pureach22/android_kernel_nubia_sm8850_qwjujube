size_t __fastcall reg_dmav1_setup_vig_qseed3(__int64 a1, __int64 *a2, const void *a3, _DWORD *a4, __int64 a5)
{
  unsigned __int64 v7; // x1
  __int64 v8; // x8
  size_t result; // x0
  __int64 v10; // x22
  int v12; // w26
  unsigned int v13; // w24
  size_t v14; // x21
  __int64 v15; // x8
  __int64 v16; // x9
  _QWORD *v17; // x8
  __int64 (__fastcall *v18)(_QWORD); // x9
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 (__fastcall *v22)(_QWORD); // x8
  unsigned int v23; // w0
  int v24; // w1
  int v25; // w4
  int v26; // w5
  int v27; // w6
  __int64 v28; // x23
  int v29; // w22
  int v30; // w9
  unsigned int v31; // w26
  int v32; // w10
  int v33; // w9
  int v34; // w10
  __int64 v35; // x9
  int v36; // w23
  int v37; // w11
  int v38; // w12
  int v39; // w13
  __int64 v40; // x9
  __int64 v41; // x8
  _DWORD *v42; // x8
  __int64 v43; // x3
  int v44; // w8
  int v45; // w11
  int v46; // w9
  int v47; // w9
  __int64 (__fastcall *v48)(_QWORD); // x9
  unsigned int v49; // w0
  int v50; // w23
  __int64 v51; // x8
  __int64 v52; // x4
  int v53; // w8
  __int64 (__fastcall *v54)(_QWORD); // x9
  unsigned int v55; // w0
  unsigned int v56; // w0
  __int64 (__fastcall *v57)(_QWORD); // x9
  unsigned int v58; // w0
  __int64 v59; // x8
  __int64 v60; // x9
  __int64 v61; // x8
  __int64 (__fastcall *v62)(_QWORD); // x8
  int v63; // w8
  __int64 (__fastcall *v64)(_QWORD); // x8
  unsigned int v65; // w0
  int v66; // [xsp+14h] [xbp-ECh]
  int v67; // [xsp+18h] [xbp-E8h]
  int v68; // [xsp+1Ch] [xbp-E4h]
  int v69; // [xsp+20h] [xbp-E0h]
  int v70; // [xsp+24h] [xbp-DCh]
  __int64 v71; // [xsp+28h] [xbp-D8h]
  int v74; // [xsp+44h] [xbp-BCh] BYREF
  __int64 v75; // [xsp+48h] [xbp-B8h] BYREF
  __int64 v76; // [xsp+50h] [xbp-B0h] BYREF
  __int64 v77; // [xsp+58h] [xbp-A8h]
  __int64 v78; // [xsp+60h] [xbp-A0h]
  _DWORD v79[6]; // [xsp+68h] [xbp-98h] BYREF
  __int64 v80; // [xsp+80h] [xbp-80h]
  __int64 v81; // [xsp+88h] [xbp-78h]
  __int128 v82; // [xsp+90h] [xbp-70h]
  __int64 v83; // [xsp+A0h] [xbp-60h] BYREF
  __int128 v84; // [xsp+A8h] [xbp-58h]
  __int64 v85; // [xsp+B8h] [xbp-48h]
  __int64 *v86; // [xsp+C0h] [xbp-40h]
  __int64 v87; // [xsp+C8h] [xbp-38h]
  __int64 v88; // [xsp+D0h] [xbp-30h]
  __int64 v89; // [xsp+D8h] [xbp-28h]
  __int64 v90; // [xsp+E0h] [xbp-20h] BYREF
  __int64 v91; // [xsp+E8h] [xbp-18h]
  __int64 v92; // [xsp+F0h] [xbp-10h]

  v92 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v87 = 0;
  v88 = 0;
  v85 = 0;
  v86 = nullptr;
  v84 = 0u;
  v83 = 0;
  v82 = 0u;
  v80 = 0;
  v81 = 0;
  v78 = 0;
  memset(v79, 0, sizeof(v79));
  v76 = 0;
  v77 = 0;
  v75 = 0;
  v74 = 0;
  v90 = 0;
  v91 = 0;
  v89 = 0;
  if ( !a1 || !a3 || !a4 )
  {
    result = _drm_err("invalid params ctx %pK pe %pK scaler_cfg %pK", (const void *)a1, a3, a4);
LABEL_30:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v7 = *(_QWORD *)(a1 + 1384);
  v8 = *(unsigned int *)(a1 + 48);
  if ( !v7 || (unsigned int)(v8 - 15) <= 0xFFFFFFF1 )
  {
    _drm_err("invalid ctl %pK sspp idx %d feature %d\n", (const void *)v7, v8, 0);
    v24 = -22;
LABEL_29:
    result = _drm_err("invalid params rc %d sspp %pK\n", v24, a2);
    goto LABEL_30;
  }
  result = *(unsigned int *)(a1 + 1392);
  if ( (unsigned int)result > 1 )
    goto LABEL_85;
  if ( 16 * v8 + 8 * result + 6000 > 0x4650 )
    goto LABEL_86;
  if ( !sspp_buf[2 * v8 + 750 + result] )
  {
    _drm_err("invalid dma_buf for rect idx %d sspp idx %d\n", 1, v8);
    v24 = -22;
    goto LABEL_29;
  }
  if ( !a2 )
  {
    v24 = 0;
    goto LABEL_29;
  }
  v10 = *(_QWORD *)(a1 + 1400);
  v12 = *(_DWORD *)(a1 + 1408);
  v71 = *(_QWORD *)(a1 + 1384);
  v13 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 56) + 48LL) + 108LL);
  result = sde_reg_dma_get_ops(result);
  if ( !result )
    goto LABEL_30;
  v14 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_30;
  v15 = *(unsigned int *)(a1 + 48);
  if ( (unsigned int)v15 >= 0xF )
    goto LABEL_85;
  v16 = *(unsigned int *)(a1 + 1392);
  if ( (unsigned int)v16 > 1 )
    goto LABEL_85;
  if ( ((16 * v15) | (unsigned __int64)(8 * v16)) > 0x2EE0 )
    goto LABEL_86;
  v17 = &sspp_buf[2 * v15 + v16];
  v18 = *(__int64 (__fastcall **)(_QWORD))(result + 64);
  v19 = v17[750];
  if ( *((_DWORD *)v18 - 1) != -870478129 )
    __break(0x8229u);
  result = v18(v19);
  v20 = *(unsigned int *)(a1 + 48);
  v83 = 0;
  v84 = 0u;
  v85 = 0;
  v86 = nullptr;
  v87 = 0;
  v88 = 0;
  v89 = 0;
  if ( (unsigned int)v20 > 0xE )
    goto LABEL_85;
  v21 = *(unsigned int *)(a1 + 1392);
  HIDWORD(v83) = sspp_mapping[v20];
  if ( (unsigned int)v21 > 1 )
    goto LABEL_85;
  if ( ((16 * v20) | (unsigned __int64)(8 * v21)) > 0x2EE0 )
    goto LABEL_86;
  HIDWORD(v84) = 0;
  DWORD1(v84) = 0;
  v87 = 0;
  v85 = sspp_buf[2 * v20 + 750 + v21];
  v86 = nullptr;
  v22 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
  if ( *((_DWORD *)v22 - 1) != -1839634494 )
    __break(0x8228u);
  v23 = v22(&v83);
  if ( v23 )
  {
    result = _drm_err("write decode select failed ret %d\n", v23);
    goto LABEL_30;
  }
  v25 = *(_DWORD *)(a1 + 48);
  v26 = *(_DWORD *)(a1 + 1392);
  v27 = *(_DWORD *)(a1 + 28);
  if ( !*a4 )
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_vig_qseed3", 4786, -1, v25, v26, v27, 0, 239);
    v50 = 0;
    goto LABEL_53;
  }
  v28 = v10;
  v29 = v12;
  result = sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_vig_qseed3", 4792, -1, v25, v26, v27, 1, 239);
  v30 = a4[38];
  v31 = ((v30 & 3) << 16) | 1;
  if ( *a2 && (*(_QWORD *)(*a2 + 32) & 1) != 0 )
    v31 = ((v30 & 3) << 16) & 0xFCFFFFFF | ((a4[39] & 3) << 24) | 0x1001;
  v32 = a4[1];
  v33 = v31 | (a4[41] << 31) | (16 * (v32 != 0));
  if ( v32 )
  {
    v33 |= 32 * (a4[3] != 0);
    v32 = (a4[2] != 0) << 6;
  }
  v12 = v29;
  v10 = v28;
  v34 = v32 | v33 | ((a4[72] != 0) << 13);
  v35 = *(_QWORD *)(a1 + 56);
  HIDWORD(v75) = v34;
  if ( (*(_QWORD *)(v35 + 32) & 0x80000000000LL) != 0 )
    HIDWORD(v75) = v34 | ((a4[133] != 0) << 7);
  v36 = *((unsigned __int16 *)a4 + 58);
  v70 = *((unsigned __int16 *)a4 + 56);
  v37 = a4[60];
  v39 = a4[32];
  v38 = a4[33];
  LODWORD(v75) = a4[20] & 0x7F | ((a4[24] & 0x7F) << 8) | ((a4[21] & 0x7F) << 16) & 0x80FFFFFF | ((a4[25] & 0x7F) << 24);
  v68 = v39;
  v69 = v38;
  v66 = a4[37];
  v67 = *((unsigned __int16 *)a4 + 72);
  if ( v37 )
  {
    result = reg_dmav1_setup_scaler3_de(
               &v83,
               a4,
               v13,
               (*(_QWORD *)(v35 + 32) >> 33) & 1LL,
               *(unsigned int *)(a1 + 1392));
    if ( !(_DWORD)result )
    {
      v40 = *(_QWORD *)(a1 + 56);
      HIDWORD(v75) |= 0x100u;
      if ( (*(_QWORD *)(v40 + 32) & 0x100000000000LL) != 0 )
        result = reg_dmav1_setup_scaler3_adaptive_de(&v83, a4, v13, (char *)&v75 + 4, *(unsigned int *)(a1 + 1392));
    }
  }
  v41 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v41 > 2 )
  {
LABEL_85:
    __break(0x5512u);
    goto LABEL_86;
  }
  v42 = *(_DWORD **)(a1 + 8 * v41 + 640);
  if ( v42 )
  {
    v43 = *(unsigned int *)(a1 + 1392);
    if ( *(v42 - 1) != -521284157 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64 *, _DWORD *, _QWORD, __int64))v42)(&v83, a4, v13, v43);
  }
  v44 = a4[12];
  v45 = a4[13];
  v46 = a4[5];
  *(_QWORD *)((char *)&v84 + 4) = 0;
  HIDWORD(v84) = v13 + 144;
  v86 = &v90;
  LODWORD(v91) = v46 & 0x1FFFFF;
  HIDWORD(v91) = v45 & 0x1FFFFF;
  v47 = a4[4];
  v87 = 0x1000000000LL;
  LODWORD(v90) = v47 & 0x1FFFFF;
  HIDWORD(v90) = v44 & 0x1FFFFF;
  v48 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
  LODWORD(v83) = 2;
  if ( *((_DWORD *)v48 - 1) != -1839634494 )
    __break(0x8229u);
  v49 = v48(&v83);
  if ( v49 )
  {
    result = _drm_err("setting phase failed ret %d\n", v49);
    goto LABEL_30;
  }
  *(_QWORD *)((char *)&v84 + 4) = 0;
  HIDWORD(v84) = v13 + 32;
  v86 = &v75;
  v87 = 0x400000000LL;
  v54 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
  LODWORD(v83) = 1;
  if ( *((_DWORD *)v54 - 1) != -1839634494 )
    __break(0x8229u);
  v55 = v54(&v83);
  if ( v55 )
  {
    result = _drm_err("setting preload failed ret %d\n", v55);
    goto LABEL_30;
  }
  *(_QWORD *)((char *)&v84 + 4) = 0;
  HIDWORD(v84) = v13 + 64;
  v86 = &v90;
  v87 = 0xC00000000LL;
  HIDWORD(v90) = v36 | (v69 << 16);
  LODWORD(v91) = v67 | (v66 << 16);
  v57 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
  LODWORD(v90) = v70 | (v68 << 16);
  LODWORD(v83) = 2;
  if ( *((_DWORD *)v57 - 1) != -1839634494 )
    __break(0x8229u);
  v58 = v57(&v83);
  if ( v58 )
  {
    result = _drm_err("setting sizes failed ret %d\n", v58);
    goto LABEL_30;
  }
  v50 = 1;
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 32) + 16LL) == 22 )
  {
    *(_QWORD *)((char *)&v84 + 4) = 0;
    HIDWORD(v84) = v13 + 96;
    v63 = *((unsigned __int8 *)a4 + 284);
    v86 = (__int64 *)&v74;
    v87 = 0x400000000LL;
    v74 = v63;
    v64 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
    LODWORD(v83) = 1;
    if ( *((_DWORD *)v64 - 1) != -1839634494 )
      __break(0x8228u);
    v65 = v64(&v83);
    if ( v65 )
    {
      result = _drm_err("lut write failed ret %d\n", v65);
      goto LABEL_30;
    }
  }
LABEL_53:
  v51 = *a2;
  if ( *a2 )
  {
    if ( (*(_QWORD *)(v51 + 32) & 2) == 0 )
      HIDWORD(v75) |= 0x4000u;
    v52 = HIDWORD(v75);
    if ( *(_BYTE *)(v51 + 24) )
    {
      v53 = HIDWORD(v75) | ((a4[40] & 3) << 29);
      v52 = v53 | 0x400u;
      HIDWORD(v75) = v53 | 0x400;
    }
  }
  else
  {
    v52 = HIDWORD(v75);
  }
  v56 = reg_dmav1_setup_cac(a1, &v83, a4, v13, v52);
  if ( v56 )
  {
    result = _drm_err("setting cac params failed ret %d\n", v56);
    goto LABEL_30;
  }
  result = reg_dmav1_setup_pe_pre_downscale(a1, &v83, a3, a5);
  if ( (_DWORD)result )
  {
    result = _drm_err("failed to set up pe and pre_downscale rc %d\n", (unsigned int)result);
    goto LABEL_30;
  }
  v59 = *(unsigned int *)(a1 + 48);
  v78 = 0;
  memset(v79, 0, sizeof(v79));
  v76 = v71;
  v77 = 0;
  if ( (unsigned int)v59 > 0xE )
    goto LABEL_85;
  v7 = *(unsigned int *)(a1 + 1392);
  if ( (unsigned int)v7 > 1 )
    goto LABEL_85;
  if ( ((16 * v59) | (8 * v7)) <= 0x2EE0 )
  {
    LODWORD(v77) = 1;
    *(_OWORD *)&v79[1] = 0u;
    v60 = sspp_buf[2 * v59 + 750 + v7];
    v61 = *(unsigned int *)(a1 + 28);
    v80 = v10;
    LODWORD(v81) = 196872;
    HIDWORD(v81) = v12;
    v78 = v60;
    LODWORD(v82) = v50;
    HIDWORD(v82) = 0;
    *(_QWORD *)((char *)&v82 + 4) = 0;
    if ( (unsigned int)v61 <= 2 )
    {
      v62 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8 * v61 + 16);
      if ( v62 )
      {
        if ( *((_DWORD *)v62 - 1) != 1772228465 )
          __break(0x8228u);
        result = v62(&v76);
        if ( (_DWORD)result )
          result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
      }
      goto LABEL_30;
    }
    goto LABEL_85;
  }
LABEL_86:
  __break(1u);
  return reg_dmav1_setup_scaler3_de(result, v7, a3, a4, a5);
}
