unsigned __int64 __fastcall reg_dmav1_setup_dma_igcv5(__int64 a1, __int64 a2, unsigned int a3)
{
  _QWORD *v3; // x24
  _QWORD *v4; // x25
  unsigned int v5; // w21
  unsigned __int64 result; // x0
  int *v9; // x26
  int v10; // w1
  unsigned __int64 v11; // x22
  __int64 v12; // x8
  __int64 v13; // x9
  _QWORD *v14; // x8
  void (__fastcall *v15)(_QWORD); // x9
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 (__fastcall *v19)(_QWORD); // x8
  int v20; // w0
  __int64 v21; // x23
  __int64 v22; // x8
  int *v23; // x9
  int v24; // w10
  int v25; // w11
  __int64 v26; // x9
  int v27; // w27
  __int64 (__fastcall *v28)(_QWORD); // x11
  unsigned int v29; // w0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x9
  _QWORD *v33; // x8
  void (__fastcall *v34)(_QWORD); // x9
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x9
  __int64 (__fastcall *v38)(_QWORD); // x8
  int v39; // w8
  __int64 (__fastcall *v40)(_QWORD); // x9
  __int64 v41; // x9
  __int64 v42; // x8
  __int64 v43; // x1
  int v44; // w11
  __int64 v45; // x11
  __int64 v46; // x8
  int v47; // w9
  int v48; // w10
  int v49; // w9
  __int64 (__fastcall *v50)(_QWORD); // x8
  int v51; // w8
  __int64 (__fastcall *v52)(_QWORD); // x9
  unsigned int v53; // w0
  __int64 (__fastcall *v54)(_QWORD); // x9
  unsigned int v55; // w0
  __int64 v56; // x8
  __int64 v57; // x4
  __int64 v58; // x5
  __int64 v59; // x10
  int v60; // w6
  unsigned int v61; // w9
  unsigned int v62; // w11
  unsigned int v63; // w9
  unsigned int v64; // w11
  __int64 v65; // x8
  int v66; // w9
  __int64 v67; // x8
  __int64 (__fastcall *v68)(__int64 *, __int64); // x8
  __int64 v69; // x1
  unsigned int v70; // w0
  unsigned __int64 StatusReg; // x27
  __int64 v72; // x28
  __int64 v73; // [xsp+10h] [xbp-140h] BYREF
  __int64 v74; // [xsp+18h] [xbp-138h]
  __int64 v75; // [xsp+20h] [xbp-130h]
  __int64 v76; // [xsp+28h] [xbp-128h]
  __int64 v77; // [xsp+30h] [xbp-120h]
  __int64 v78; // [xsp+38h] [xbp-118h]
  __int64 v79; // [xsp+40h] [xbp-110h]
  unsigned __int64 v80; // [xsp+48h] [xbp-108h]
  __int64 v81; // [xsp+50h] [xbp-100h]
  unsigned __int64 v82; // [xsp+58h] [xbp-F8h]
  __int64 v83; // [xsp+60h] [xbp-F0h] BYREF
  __int128 v84; // [xsp+68h] [xbp-E8h]
  __int64 v85; // [xsp+78h] [xbp-D8h]
  int *v86; // [xsp+80h] [xbp-D0h]
  __int64 v87; // [xsp+88h] [xbp-C8h]
  __int64 v88; // [xsp+90h] [xbp-C0h]
  __int64 v89; // [xsp+98h] [xbp-B8h]
  int v90; // [xsp+A4h] [xbp-ACh] BYREF
  __int64 v91; // [xsp+A8h] [xbp-A8h] BYREF
  __int64 v92; // [xsp+B0h] [xbp-A0h]
  __int64 v93; // [xsp+B8h] [xbp-98h]
  __int64 v94; // [xsp+C0h] [xbp-90h]
  __int64 v95; // [xsp+C8h] [xbp-88h]
  __int64 v96; // [xsp+D0h] [xbp-80h]
  __int64 v97; // [xsp+D8h] [xbp-78h]
  int v98; // [xsp+E0h] [xbp-70h]
  int v99; // [xsp+E4h] [xbp-6Ch]
  int v100; // [xsp+E8h] [xbp-68h]
  int v101; // [xsp+ECh] [xbp-64h]
  int v102; // [xsp+F0h] [xbp-60h]
  int v103; // [xsp+F4h] [xbp-5Ch]
  __int64 v104; // [xsp+F8h] [xbp-58h] BYREF
  __int128 v105; // [xsp+100h] [xbp-50h]
  __int64 v106; // [xsp+110h] [xbp-40h]
  int *v107; // [xsp+118h] [xbp-38h]
  __int64 v108; // [xsp+120h] [xbp-30h]
  __int64 v109; // [xsp+128h] [xbp-28h]
  __int64 v110; // [xsp+130h] [xbp-20h]
  int v111; // [xsp+13Ch] [xbp-14h] BYREF
  __int64 v112; // [xsp+140h] [xbp-10h]

  v5 = a3;
  v112 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v90 = 0;
  v88 = 0;
  v89 = 0;
  v86 = nullptr;
  v87 = 0;
  v85 = 0;
  v83 = 0;
  v84 = 0u;
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  v77 = 0;
  v78 = 0;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  result = reg_dma_sspp_check((unsigned int *)a1, (_QWORD *)a2, 2u, a3);
  if ( (_DWORD)result )
    goto LABEL_2;
  v9 = *(int **)a2;
  if ( !*(_QWORD *)a2 )
  {
    _drm_dev_dbg(0, 0, 1, "disable igc feature\n");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "reg_dmav1_setup_dma_igcv5",
      3893,
      -1,
      *(_DWORD *)(a1 + 48),
      *(_DWORD *)(a1 + 1392),
      *(_DWORD *)(a1 + 28),
      0,
      239);
    v30 = *(unsigned int *)(a1 + 1392);
    v111 = 0;
    v109 = 0;
    v110 = 0;
    v107 = nullptr;
    v108 = 0;
    v106 = 0;
    v104 = 0;
    v105 = 0u;
    result = sde_reg_dma_get_ops(v30);
    if ( !result )
      goto LABEL_2;
    v11 = result;
    if ( result > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_2;
    if ( v5 >= 3 )
      goto LABEL_84;
    v31 = *(unsigned int *)(a1 + 48);
    if ( (unsigned int)v31 > 0xE )
      goto LABEL_84;
    v32 = *(unsigned int *)(a1 + 1392);
    if ( (unsigned int)v32 > 1 )
      goto LABEL_84;
    if ( (16 * v31 + 6000 * (unsigned __int64)v5 + 8 * v32 + 480) >> 4 > 0x464 )
      goto LABEL_85;
    v3 = sspp_buf;
    v33 = &sspp_buf[750 * v5 + 2 * v31 + v32];
    v34 = *(void (__fastcall **)(_QWORD))(result + 64);
    v35 = v33[60];
    if ( *((_DWORD *)v34 - 1) != -870478129 )
      __break(0x8229u);
    v34(v35);
    v36 = *(unsigned int *)(a1 + 48);
    v104 = 0;
    v105 = 0u;
    v106 = 0;
    v107 = nullptr;
    v108 = 0;
    v109 = 0;
    v110 = 0;
    if ( (unsigned int)v36 > 0xE )
      goto LABEL_84;
    v37 = *(unsigned int *)(a1 + 1392);
    HIDWORD(v104) = sspp_mapping[v36];
    LODWORD(v105) = 2;
    if ( (unsigned int)v37 > 1 )
      goto LABEL_84;
    if ( (16 * v36 + 6000 * (unsigned __int64)v5 + 8 * v37 + 480) >> 4 > 0x464 )
      goto LABEL_85;
    DWORD1(v105) = 0;
    v108 = 0;
    v106 = sspp_buf[750 * v5 + 60 + 2 * v36 + v37];
    v107 = nullptr;
    v38 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
    if ( *((_DWORD *)v38 - 1) != -1839634494 )
      __break(0x8228u);
    v20 = v38(&v104);
    if ( !v20 )
    {
      if ( v5 == 2 )
        v39 = 5636;
      else
        v39 = 1540;
      *(_QWORD *)((char *)&v105 + 4) = 0;
      HIDWORD(v105) = v39;
      v107 = &v111;
      v108 = 0x400010005LL;
      v40 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
      LODWORD(v104) = 5;
      if ( *((_DWORD *)v40 - 1) != -1839634494 )
        __break(0x8229u);
      result = v40(&v104);
      if ( (_DWORD)result )
      {
        result = _drm_err("opmode modify single reg failed ret %d\n", result);
      }
      else
      {
        *(_DWORD *)(a2 + 168) = 0;
        v41 = *(_QWORD *)(a2 + 16);
        v42 = *(unsigned int *)(a1 + 48);
        v93 = 0;
        v94 = 0;
        v95 = 0;
        v96 = 0;
        v91 = v41;
        v92 = 0;
        if ( (unsigned int)v42 > 0xE )
          goto LABEL_84;
        v43 = *(unsigned int *)(a1 + 1392);
        if ( (unsigned int)v43 > 1 )
          goto LABEL_84;
        if ( (16 * v42 + 6000 * (unsigned __int64)v5 + 8 * v43 + 480) >> 4 > 0x464 )
          goto LABEL_85;
        LODWORD(v96) = 2;
        LODWORD(v92) = 1;
        v97 = *(_QWORD *)(a2 + 152);
        v44 = *(_DWORD *)(a2 + 164);
        v98 = *(_DWORD *)(a2 + 160);
        v99 = v44;
        v45 = sspp_buf[750 * v5 + 60 + 2 * v42 + v43];
        v46 = *(unsigned int *)(a1 + 28);
        v47 = *(_DWORD *)(a2 + 172);
        v48 = *(_DWORD *)(a2 + 176);
        v93 = v45;
        v102 = v47;
        v103 = v48;
        v49 = *(_DWORD *)(a2 + 28);
        v100 = 0;
        v101 = v49;
        if ( (unsigned int)v46 > 2 )
          goto LABEL_84;
        v50 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8 * v46 + 16);
        if ( v50 )
        {
          if ( *((_DWORD *)v50 - 1) != 1772228465 )
            __break(0x8228u);
          result = v50(&v91);
          if ( (_DWORD)result )
            result = _drm_err("failed to kick off ret %d\n", result);
        }
      }
      goto LABEL_2;
    }
    goto LABEL_45;
  }
  v10 = *(_DWORD *)(a2 + 8);
  if ( v10 != 4632 )
  {
    result = _drm_err("invalid size of payload len %d exp %zd\n", v10, 0x1218u);
    goto LABEL_2;
  }
  result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1392));
  if ( result )
  {
    v11 = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      if ( v5 >= 3 )
        goto LABEL_84;
      v12 = *(unsigned int *)(a1 + 48);
      if ( (unsigned int)v12 > 0xE )
        goto LABEL_84;
      v13 = *(unsigned int *)(a1 + 1392);
      if ( (unsigned int)v13 > 1 )
        goto LABEL_84;
      LODWORD(v3) = v5;
      if ( (16 * v12 + 6000 * (unsigned __int64)v5 + 8 * v13 + 480) >> 4 > 0x464 )
        goto LABEL_85;
      v4 = sspp_buf;
      v14 = &sspp_buf[750 * v5 + 2 * v12 + v13];
      v15 = *(void (__fastcall **)(_QWORD))(result + 64);
      v16 = v14[60];
      if ( *((_DWORD *)v15 - 1) != -870478129 )
        __break(0x8229u);
      v15(v16);
      v17 = *(unsigned int *)(a1 + 48);
      v83 = 0;
      v84 = 0u;
      v85 = 0;
      v86 = nullptr;
      v87 = 0;
      v88 = 0;
      v89 = 0;
      if ( (unsigned int)v17 > 0xE )
        goto LABEL_84;
      v18 = *(unsigned int *)(a1 + 1392);
      HIDWORD(v83) = sspp_mapping[v17];
      LODWORD(v84) = 2;
      if ( (unsigned int)v18 > 1 )
        goto LABEL_84;
      if ( (16 * v17 + 6000 * (unsigned __int64)v5 + 8 * v18 + 480) >> 4 > 0x464 )
        goto LABEL_85;
      HIDWORD(v84) = 0;
      DWORD1(v84) = 0;
      v87 = 0;
      v85 = sspp_buf[750 * v5 + 60 + 2 * v17 + v18];
      v86 = nullptr;
      v19 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
      if ( *((_DWORD *)v19 - 1) != -1839634494 )
        __break(0x8228u);
      v20 = v19(&v83);
      if ( !v20 )
      {
        v21 = _kvmalloc_node_noprof(512, 0, 3520, 0xFFFFFFFFLL);
        if ( !v21 )
        {
LABEL_86:
          result = _drm_err("failed to allocate memory for igc\n");
          goto LABEL_2;
        }
        while ( 1 )
        {
          v22 = 0;
          v23 = v9 + 515;
          do
          {
            v24 = *(v23 - 1);
            v25 = *v23;
            v23 += 2;
            *(_DWORD *)(v21 + v22) = v24 & 0xFFF | ((v25 & 0xFFF) << 16);
            v22 += 4;
          }
          while ( v22 != 512 );
          v26 = 336;
          if ( v5 == 2 )
            v26 = 372;
          v27 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 56) + 48LL) + v26);
          *(_QWORD *)((char *)&v84 + 4) = 0;
          v86 = (int *)v21;
          v87 = 0x20000000000LL;
          HIDWORD(v84) = v27;
          if ( v5 == 2 )
            v5 = 5636;
          else
            v5 = 1540;
          v28 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
          LODWORD(v83) = 2;
          if ( *((_DWORD *)v28 - 1) != -1839634494 )
            __break(0x822Bu);
          v29 = v28(&v83);
          if ( v29 )
          {
            _drm_err("lut write failed ret %d\n", v29);
            goto LABEL_74;
          }
          if ( (*(_BYTE *)v9 & 1) != 0 )
            v51 = v9[770] & 0xF | 0x10;
          else
            v51 = 0;
          HIDWORD(v84) = v27 + 1032;
          v9 = &v90;
          *(_QWORD *)((char *)&v84 + 4) = 0;
          v86 = &v90;
          v87 = 0x400000000LL;
          v52 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
          v90 = v51;
          LODWORD(v83) = 1;
          if ( *((_DWORD *)v52 - 1) != -1839634494 )
            __break(0x8229u);
          v53 = v52(&v83);
          if ( v53 )
          {
            _drm_err("failed to set dither strength %d\n", v53);
            goto LABEL_74;
          }
          HIDWORD(v84) = v5;
          *(_QWORD *)((char *)&v84 + 4) = 0;
          v90 = 2;
          v86 = &v90;
          v87 = 0x400010005LL;
          v54 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
          LODWORD(v83) = 5;
          if ( *((_DWORD *)v54 - 1) != -1839634494 )
            __break(0x8229u);
          v55 = v54(&v83);
          if ( v55 )
          {
            _drm_err("setting opcode failed ret %d\n", v55);
            goto LABEL_74;
          }
          v75 = 0;
          v76 = 0;
          *(_DWORD *)(a2 + 168) = 1;
          v56 = *(_QWORD *)(a2 + 16);
          v57 = *(unsigned int *)(a1 + 48);
          v77 = 0;
          v78 = 0;
          v73 = v56;
          v74 = 0;
          if ( (unsigned int)v57 > 0xE )
            goto LABEL_84;
          v58 = *(unsigned int *)(a1 + 1392);
          if ( (unsigned int)v58 > 1 )
            goto LABEL_84;
          if ( (16 * v57 + 6000 * (unsigned __int64)(unsigned int)v3 + 8 * v58 + 480) >> 4 <= 0x464 )
            break;
LABEL_85:
          __break(1u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v72 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &reg_dmav1_setup_dma_igcv5__alloc_tag;
          v21 = _kvmalloc_node_noprof(512, 0, 3520, 0xFFFFFFFFLL);
          *(_QWORD *)(StatusReg + 80) = v72;
          if ( !v21 )
            goto LABEL_86;
        }
        v59 = *(_QWORD *)(a2 + 152);
        LODWORD(v78) = 2;
        v60 = *(_DWORD *)(a1 + 28);
        v61 = *(_DWORD *)(a2 + 160);
        v62 = *(_DWORD *)(a2 + 164);
        v79 = v59;
        v80 = __PAIR64__(v62, v61);
        LODWORD(v77) = 0;
        v63 = *(_DWORD *)(a2 + 172);
        v64 = *(_DWORD *)(a2 + 176);
        v65 = v4[750 * (unsigned int)v3 + 60 + 2 * v57 + v58];
        LODWORD(v74) = 1;
        v82 = __PAIR64__(v64, v63);
        v66 = *(_DWORD *)(a2 + 28);
        v75 = v65;
        LODWORD(v81) = 1;
        HIDWORD(v81) = v66;
        sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_dma_igcv5", 3978, -1, v57, v58, v60, 1, 239);
        v67 = *(unsigned int *)(a1 + 28);
        if ( (unsigned int)v67 <= 2 )
        {
          v68 = *(__int64 (__fastcall **)(__int64 *, __int64))(v11 + 8 * v67 + 16);
          if ( v68 )
          {
            v69 = *(unsigned int *)(a1 + 1392);
            if ( *((_DWORD *)v68 - 1) != 1772228465 )
              __break(0x8228u);
            v70 = v68(&v73, v69);
            if ( v70 )
              _drm_err("failed to kick off ret %d\n", v70);
          }
LABEL_74:
          result = kvfree(v21);
          goto LABEL_2;
        }
LABEL_84:
        __break(0x5512u);
        goto LABEL_85;
      }
LABEL_45:
      result = _drm_err("write decode select failed ret %d\n", v20);
    }
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
