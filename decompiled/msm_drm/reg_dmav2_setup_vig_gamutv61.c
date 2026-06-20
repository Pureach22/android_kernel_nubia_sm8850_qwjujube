unsigned __int64 __fastcall reg_dmav2_setup_vig_gamutv61(__int64 a1, char **a2)
{
  unsigned __int64 v2; // x20
  _QWORD *v3; // x22
  char **v4; // x24
  char *v5; // x25
  int v6; // w26
  _BOOL4 v7; // w27
  __int64 v9; // x8
  __int64 v10; // x8
  int v11; // w23
  __int64 v12; // x2
  __int64 v13; // x8
  unsigned int v14; // w8
  int v15; // w8
  unsigned int v16; // w8
  __int64 v17; // x0
  unsigned __int64 result; // x0
  __int64 v19; // x8
  __int64 v20; // x9
  _QWORD *v21; // x8
  void (__fastcall *v22)(_QWORD); // x9
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x9
  __int64 (__fastcall *v26)(_QWORD); // x8
  unsigned int v27; // w0
  char *v29; // x21
  _WORD *v30; // x8
  __int64 v31; // x9
  char *v32; // x13
  unsigned int v33; // w14
  unsigned int v34; // w14
  unsigned int v35; // w15
  char *v36; // x14
  unsigned int v37; // w15
  __int64 (__fastcall *v38)(_QWORD); // x9
  unsigned int v39; // w0
  __int64 (__fastcall *v40)(_QWORD); // x9
  unsigned int v41; // w0
  __int64 (__fastcall *v42)(_QWORD); // x8
  unsigned int v43; // w0
  __int64 v44; // x1
  _DWORD *v45; // x8
  unsigned int v46; // w0
  _DWORD *v47; // x9
  unsigned int v48; // w0
  __int64 v49; // x4
  char *v50; // x8
  __int64 v51; // x5
  char *v52; // x10
  int v53; // w6
  int v54; // w8
  __int64 v55; // x10
  __int64 v56; // x8
  unsigned int v57; // w9
  __int64 v58; // x8
  __int64 (__fastcall *v59)(char **, __int64); // x8
  __int64 v60; // x1
  unsigned int v61; // w0
  unsigned __int64 StatusReg; // x28
  __int64 v63; // [xsp+10h] [xbp-B0h]
  __int64 v64; // [xsp+18h] [xbp-A8h] BYREF
  char *v65; // [xsp+20h] [xbp-A0h] BYREF
  __int64 v66; // [xsp+28h] [xbp-98h]
  __int64 v67; // [xsp+30h] [xbp-90h]
  __int64 v68; // [xsp+38h] [xbp-88h]
  __int64 v69; // [xsp+40h] [xbp-80h]
  __int64 v70; // [xsp+48h] [xbp-78h]
  char *v71; // [xsp+50h] [xbp-70h]
  __int128 v72; // [xsp+58h] [xbp-68h]
  unsigned __int64 v73; // [xsp+68h] [xbp-58h]
  __int64 v74; // [xsp+70h] [xbp-50h] BYREF
  __int128 v75; // [xsp+78h] [xbp-48h]
  __int64 v76; // [xsp+88h] [xbp-38h]
  char *v77; // [xsp+90h] [xbp-30h]
  __int64 v78; // [xsp+98h] [xbp-28h]
  __int128 v79; // [xsp+A0h] [xbp-20h]
  __int64 v80; // [xsp+B0h] [xbp-10h]

  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 56);
  v79 = 0u;
  v73 = 0;
  v71 = nullptr;
  v72 = 0u;
  v10 = *(_QWORD *)(v9 + 48);
  v77 = nullptr;
  v78 = 0;
  v76 = 0;
  v11 = *(_DWORD *)(v10 + 296);
  v74 = 0;
  v75 = 0u;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = nullptr;
  v66 = 0;
  v64 = 0;
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid cfg %pK ctx %pK\n", a2, (const void *)a1);
    goto LABEL_34;
  }
  v12 = *(unsigned int *)(a1 + 48);
  if ( !a2[2] || (unsigned int)(v12 - 15) <= 0xFFFFFFF1 )
  {
    result = _drm_err("invalid ctl %pK sspp idx %d feature %d\n", a2[2], v12, 1);
    goto LABEL_34;
  }
  v13 = *(unsigned int *)(a1 + 1392);
  if ( (unsigned int)v13 > 1 )
    goto LABEL_67;
  if ( (unsigned __int64)(16 * v12 + 8 * v13 + 6240) > 0x4650 )
    goto LABEL_68;
  v3 = sspp_buf;
  if ( !sspp_buf[2 * v12 + 780 + v13] )
  {
    result = _drm_err("invalid dma_buf for rect idx %d sspp idx %d\n", 1, v12);
    goto LABEL_34;
  }
  v5 = *a2;
  v14 = (_DWORD)a2[20] & 0xFF0F0FFF | 0x106000;
  *((_DWORD *)a2 + 42) = 1;
  *((_DWORD *)a2 + 40) = v14;
  if ( !v5 )
  {
    _drm_dev_dbg(0, 0, 1, "disable gamut feature\n");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "reg_dmav2_setup_vig_gamutv61",
      6455,
      -1,
      *(_DWORD *)(a1 + 48),
      *(_DWORD *)(a1 + 1392),
      *(_DWORD *)(a1 + 28),
      0,
      239);
    result = vig_gamutv5_off(a1, (__int64)a2);
    goto LABEL_34;
  }
  v15 = *((_DWORD *)a2 + 2);
  if ( v15 != 39536 )
  {
    result = _drm_err("invalid size of payload len %d exp %zd\n", v15, 0x9A70u);
    goto LABEL_34;
  }
  v16 = *((_DWORD *)v5 + 2);
  if ( v16 != 1 )
  {
    result = _drm_err("invalid mode %d", v16);
    goto LABEL_34;
  }
  v4 = a2;
  cp_feature_get_curr_mode(0, a2[24], &v64);
  v17 = *(unsigned int *)(a1 + 1392);
  v7 = v64 != 0;
  if ( (_DWORD)v64 )
    v6 = 224;
  else
    v6 = 16;
  HIDWORD(v64) = (2 * (*(_DWORD *)v5 & 1)) | (16 * v7) | 1;
  result = sde_reg_dma_get_ops(v17);
  if ( result )
  {
    v2 = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      v19 = *(unsigned int *)(a1 + 48);
      if ( (unsigned int)v19 >= 0xF )
        goto LABEL_67;
      v20 = *(unsigned int *)(a1 + 1392);
      if ( (unsigned int)v20 > 1 )
        goto LABEL_67;
      if ( (unsigned __int64)(16 * v19 + 8 * v20 + 6240) > 0x4650 )
        goto LABEL_68;
      v21 = &sspp_buf[2 * v19 + v20];
      v22 = *(void (__fastcall **)(_QWORD))(result + 64);
      v23 = v21[780];
      if ( *((_DWORD *)v22 - 1) != -870478129 )
        __break(0x8229u);
      v22(v23);
      v24 = *(unsigned int *)(a1 + 48);
      v74 = 0;
      v75 = 0u;
      v76 = 0;
      v77 = nullptr;
      v78 = 0;
      v79 = 0u;
      if ( (unsigned int)v24 > 0xE )
        goto LABEL_67;
      v25 = *(unsigned int *)(a1 + 1392);
      HIDWORD(v74) = sspp_mapping[v24];
      LODWORD(v75) = 1;
      if ( (unsigned int)v25 > 1 )
        goto LABEL_67;
      if ( (unsigned __int64)(16 * v24 + 8 * v25 + 6240) > 0x4650 )
        goto LABEL_68;
      HIDWORD(v75) = 0;
      DWORD1(v75) = 0;
      v78 = 0;
      v76 = sspp_buf[2 * v24 + 780 + v25];
      v77 = nullptr;
      v26 = *(__int64 (__fastcall **)(_QWORD))(v2 + 8);
      if ( *((_DWORD *)v26 - 1) != -1839634494 )
        __break(0x8228u);
      v27 = v26(&v74);
      if ( v27 )
      {
        result = _drm_err("write decode select failed ret %d\n", v27);
        goto LABEL_34;
      }
      result = _kvmalloc_node_noprof(29496, 0, 3520, 0xFFFFFFFFLL);
      v29 = (char *)result;
      if ( !result )
        goto LABEL_34;
      while ( 1 )
      {
        v30 = v29 + 12;
        v31 = 1229;
        v32 = v5;
        do
        {
          --v31;
          *(v30 - 6) = *((_WORD *)v32 + 104) << 6;
          v33 = *((_DWORD *)v32 + 51);
          *(v30 - 4) = (_WORD)v33 << 6;
          *(v30 - 5) = (v33 >> 10) & 0xFFC0;
          *(v30 - 3) = *((_WORD *)v32 + 5020) << 6;
          v34 = *((_DWORD *)v32 + 2509);
          v35 = v34 >> 10;
          *(v30 - 1) = (_WORD)v34 << 6;
          v36 = v32 + 19872;
          *(v30 - 2) = v35 & 0xFFC0;
          *v30 = *((_WORD *)v32 + 9936) << 6;
          v37 = *((_DWORD *)v32 + 4967);
          v30[2] = (_WORD)v37 << 6;
          v30[1] = (v37 >> 10) & 0xFFC0;
          LOWORD(v37) = *((_WORD *)v32 + 14852);
          v32 += 8;
          v30[3] = (_WORD)v37 << 6;
          LODWORD(v36) = *((_DWORD *)v36 + 2457);
          v30[5] = (_WORD)v36 << 6;
          v30[4] = ((unsigned int)v36 >> 10) & 0xFFC0;
          v30 += 12;
        }
        while ( v31 );
        HIDWORD(v75) = 0;
        v77 = v29;
        v78 = 0x733800000000LL;
        *(_QWORD *)((char *)&v75 + 4) = 0;
        *(_QWORD *)((char *)&v79 + 4) = 0x600000001LL;
        LODWORD(v79) = v7;
        HIDWORD(v79) = 1229;
        v38 = *(__int64 (__fastcall **)(_QWORD))(v2 + 8);
        LODWORD(v74) = 6;
        if ( *((_DWORD *)v38 - 1) != -1839634494 )
          __break(0x8229u);
        v39 = v38(&v74);
        if ( v39 )
        {
          _drm_err("lut write failed ret %d\n", v39);
          goto LABEL_57;
        }
        if ( (v64 & 0x200000000LL) != 0 )
        {
          v6 += v11;
          v7 = 0;
          *(_QWORD *)((char *)&v75 + 4) = 0;
          HIDWORD(v75) = v6;
          v77 = v5 + 12;
          v78 = 0x4000000000LL;
          v42 = *(__int64 (__fastcall **)(_QWORD))(v2 + 8);
          LODWORD(v74) = 2;
          if ( *((_DWORD *)v42 - 1) != -1839634494 )
            __break(0x8228u);
          v43 = v42(&v74);
          v44 = v43;
          if ( v43 )
            goto LABEL_56;
          *(_QWORD *)((char *)&v75 + 4) = 0;
          HIDWORD(v75) = v6 + 64;
          v77 = v5 + 76;
          v78 = 0x4000000000LL;
          v45 = *(_DWORD **)(v2 + 8);
          LODWORD(v74) = 2;
          if ( *(v45 - 1) != -1839634494 )
            __break(0x8228u);
          v46 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v45)(&v74, v43);
          v44 = v46;
          if ( v46 )
            goto LABEL_56;
          *(_QWORD *)((char *)&v75 + 4) = 0;
          HIDWORD(v75) = v6 + 128;
          v77 = v5 + 140;
          v78 = 0x4000000000LL;
          v47 = *(_DWORD **)(v2 + 8);
          LODWORD(v74) = 2;
          if ( *(v47 - 1) != -1839634494 )
            __break(0x8229u);
          v48 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v47)(&v74, v46);
          v44 = v48;
          if ( v48 )
          {
LABEL_56:
            _drm_err("write scale/off reg failed ret %d\n", v44);
            goto LABEL_57;
          }
        }
        HIDWORD(v75) = v11;
        *(_QWORD *)((char *)&v75 + 4) = 0;
        v77 = (char *)&v64 + 4;
        v78 = 0x400000000LL;
        v40 = *(__int64 (__fastcall **)(_QWORD))(v2 + 8);
        LODWORD(v74) = 1;
        if ( *((_DWORD *)v40 - 1) != -1839634494 )
          __break(0x8229u);
        v41 = v40(&v74);
        if ( v41 )
        {
          _drm_err("opmode write single reg failed ret %d\n", v41);
          goto LABEL_57;
        }
        v49 = *(unsigned int *)(a1 + 48);
        v50 = v4[2];
        v69 = 0;
        v70 = 0;
        v67 = 0;
        v68 = 0;
        v65 = v50;
        v66 = 0;
        if ( (unsigned int)v49 > 0xE )
          goto LABEL_67;
        v51 = *(unsigned int *)(a1 + 1392);
        if ( (unsigned int)v51 > 1 )
          goto LABEL_67;
        if ( (unsigned __int64)(16 * v49 + 8 * v51 + 6240) <= 0x4650 )
          break;
LABEL_68:
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v63 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &reg_dmav2_setup_vig_gamutv61__alloc_tag;
        result = _kvmalloc_node_noprof(29496, 0, 3520, 0xFFFFFFFFLL);
        v29 = (char *)result;
        *(_QWORD *)(StatusReg + 80) = v63;
        if ( !result )
          goto LABEL_34;
      }
      v52 = v4[19];
      LODWORD(v66) = 1;
      v53 = *(_DWORD *)(a1 + 28);
      LODWORD(v70) = 1;
      v54 = *((_DWORD *)v4 + 40);
      v71 = v52;
      v55 = *(__int64 *)((char *)v4 + 164);
      LODWORD(v72) = v54;
      v56 = v3[2 * v49 + 780 + v51];
      *(_QWORD *)((char *)&v72 + 4) = v55;
      LODWORD(v55) = *((_DWORD *)v4 + 43);
      v57 = *((_DWORD *)v4 + 44);
      v67 = v56;
      LODWORD(v56) = *((_DWORD *)v4 + 7);
      LODWORD(v69) = 0;
      v73 = __PAIR64__(v57, v55);
      HIDWORD(v72) = v56;
      sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav2_setup_vig_gamutv61", 6570, -1, v49, v51, v53, 1, 239);
      v58 = *(unsigned int *)(a1 + 28);
      if ( (unsigned int)v58 <= 2 )
      {
        v59 = *(__int64 (__fastcall **)(char **, __int64))(v2 + 8 * v58 + 16);
        if ( v59 )
        {
          v60 = *(unsigned int *)(a1 + 1392);
          if ( *((_DWORD *)v59 - 1) != 1772228465 )
            __break(0x8228u);
          v61 = v59(&v65, v60);
          if ( v61 )
            _drm_err("failed to kick off ret %d\n", v61);
        }
LABEL_57:
        result = kvfree(v29);
        goto LABEL_34;
      }
LABEL_67:
      __break(0x5512u);
      goto LABEL_68;
    }
  }
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
