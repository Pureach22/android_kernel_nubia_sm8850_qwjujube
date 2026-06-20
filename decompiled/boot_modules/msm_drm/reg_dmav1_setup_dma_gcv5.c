unsigned __int64 __fastcall reg_dmav1_setup_dma_gcv5(__int64 a1, __int64 *a2, unsigned int a3)
{
  unsigned __int64 result; // x0
  __int64 v7; // x25
  int v8; // w1
  unsigned __int64 v9; // x22
  __int64 v10; // x8
  __int64 v11; // x9
  _QWORD *v12; // x8
  void (__fastcall *v13)(_QWORD); // x9
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x9
  __int64 (__fastcall *v17)(_QWORD); // x8
  unsigned int v18; // w0
  __int64 v19; // x9
  int v20; // w8
  __int64 (__fastcall *v21)(_QWORD); // x9
  unsigned int v22; // w0
  __int64 v23; // x0
  unsigned __int64 v24; // x22
  __int64 v25; // x8
  __int64 v26; // x9
  _QWORD *v27; // x8
  void (__fastcall *v28)(_QWORD); // x9
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x9
  __int64 (__fastcall *v32)(_QWORD); // x8
  int v33; // w8
  __int64 (__fastcall *v34)(_QWORD); // x9
  __int64 v35; // x9
  __int64 v36; // x8
  __int64 v37; // x1
  int v38; // w11
  __int64 v39; // x11
  __int64 v40; // x8
  int v41; // w9
  int v42; // w10
  int v43; // w9
  __int64 (__fastcall *v44)(__int64 *, __int64); // x8
  __int64 *v45; // x0
  int v46; // w8
  __int64 (__fastcall *v47)(_QWORD); // x9
  unsigned int v48; // w0
  __int64 v49; // x8
  __int64 v50; // x4
  __int64 v51; // x5
  __int64 v52; // x10
  int v53; // w6
  unsigned int v54; // w9
  unsigned int v55; // w11
  unsigned int v56; // w9
  unsigned int v57; // w11
  __int64 v58; // x8
  int v59; // w9
  __int64 v60; // x8
  __int64 v61; // [xsp+8h] [xbp-138h] BYREF
  __int64 v62; // [xsp+10h] [xbp-130h]
  __int64 v63; // [xsp+18h] [xbp-128h]
  __int64 v64; // [xsp+20h] [xbp-120h]
  __int64 v65; // [xsp+28h] [xbp-118h]
  __int64 v66; // [xsp+30h] [xbp-110h]
  __int64 v67; // [xsp+38h] [xbp-108h]
  unsigned __int64 v68; // [xsp+40h] [xbp-100h]
  __int64 v69; // [xsp+48h] [xbp-F8h]
  unsigned __int64 v70; // [xsp+50h] [xbp-F0h]
  __int64 v71; // [xsp+58h] [xbp-E8h] BYREF
  __int128 v72; // [xsp+60h] [xbp-E0h]
  __int64 v73; // [xsp+70h] [xbp-D0h]
  int *v74; // [xsp+78h] [xbp-C8h]
  __int64 v75; // [xsp+80h] [xbp-C0h]
  __int64 v76; // [xsp+88h] [xbp-B8h]
  __int64 v77; // [xsp+90h] [xbp-B0h]
  int v78; // [xsp+9Ch] [xbp-A4h] BYREF
  __int64 v79; // [xsp+A0h] [xbp-A0h] BYREF
  __int64 v80; // [xsp+A8h] [xbp-98h]
  __int64 v81; // [xsp+B0h] [xbp-90h]
  __int64 v82; // [xsp+B8h] [xbp-88h]
  __int64 v83; // [xsp+C0h] [xbp-80h]
  __int64 v84; // [xsp+C8h] [xbp-78h]
  __int64 v85; // [xsp+D0h] [xbp-70h]
  int v86; // [xsp+D8h] [xbp-68h]
  int v87; // [xsp+DCh] [xbp-64h]
  int v88; // [xsp+E0h] [xbp-60h]
  int v89; // [xsp+E4h] [xbp-5Ch]
  int v90; // [xsp+E8h] [xbp-58h]
  int v91; // [xsp+ECh] [xbp-54h]
  __int64 v92; // [xsp+F0h] [xbp-50h] BYREF
  __int128 v93; // [xsp+F8h] [xbp-48h]
  __int64 v94; // [xsp+108h] [xbp-38h]
  int *v95; // [xsp+110h] [xbp-30h]
  __int64 v96; // [xsp+118h] [xbp-28h]
  __int64 v97; // [xsp+120h] [xbp-20h]
  __int64 v98; // [xsp+128h] [xbp-18h]
  int v99; // [xsp+134h] [xbp-Ch] BYREF
  __int64 v100; // [xsp+138h] [xbp-8h]

  v100 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v78 = 0;
  v76 = 0;
  v77 = 0;
  v74 = nullptr;
  v75 = 0;
  v73 = 0;
  v71 = 0;
  v72 = 0u;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  result = reg_dma_sspp_check((unsigned int *)a1, a2, 0xBu, a3);
  if ( (_DWORD)result )
    goto LABEL_2;
  v7 = *a2;
  if ( !*a2 )
  {
    _drm_dev_dbg(0, 0, 1, "disable gc feature\n");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "reg_dmav1_setup_dma_gcv5",
      4059,
      -1,
      *(_DWORD *)(a1 + 48),
      *(_DWORD *)(a1 + 1392),
      *(_DWORD *)(a1 + 28),
      0,
      239);
    v23 = *(unsigned int *)(a1 + 1392);
    v99 = 0;
    v97 = 0;
    v98 = 0;
    v95 = nullptr;
    v96 = 0;
    v94 = 0;
    v92 = 0;
    v93 = 0u;
    result = sde_reg_dma_get_ops(v23);
    if ( !result )
      goto LABEL_2;
    v24 = result;
    if ( result > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_2;
    if ( a3 >= 3 )
      goto LABEL_72;
    v25 = *(unsigned int *)(a1 + 48);
    if ( (unsigned int)v25 > 0xE )
      goto LABEL_72;
    v26 = *(unsigned int *)(a1 + 1392);
    if ( (unsigned int)v26 > 1 )
      goto LABEL_72;
    if ( (16 * v25 + 6000 * (unsigned __int64)a3 + 8 * v26 + 2640) >> 4 > 0x464 )
      goto LABEL_73;
    v27 = &sspp_buf[750 * a3 + 2 * v25 + v26];
    v28 = *(void (__fastcall **)(_QWORD))(result + 64);
    v29 = v27[330];
    if ( *((_DWORD *)v28 - 1) != -870478129 )
      __break(0x8229u);
    v28(v29);
    v30 = *(unsigned int *)(a1 + 48);
    v92 = 0;
    v93 = 0u;
    v94 = 0;
    v95 = nullptr;
    v96 = 0;
    v97 = 0;
    v98 = 0;
    if ( (unsigned int)v30 > 0xE )
      goto LABEL_72;
    v31 = *(unsigned int *)(a1 + 1392);
    HIDWORD(v92) = sspp_mapping[v30];
    LODWORD(v93) = 11;
    if ( (unsigned int)v31 > 1 )
      goto LABEL_72;
    if ( (16 * v30 + 6000 * (unsigned __int64)a3 + 8 * v31 + 2640) >> 4 > 0x464 )
      goto LABEL_73;
    DWORD1(v93) = 0;
    v96 = 0;
    v94 = sspp_buf[750 * a3 + 330 + 2 * v30 + v31];
    v95 = nullptr;
    v32 = *(__int64 (__fastcall **)(_QWORD))(v24 + 8);
    if ( *((_DWORD *)v32 - 1) != -1839634494 )
      __break(0x8228u);
    v18 = v32(&v92);
    if ( !v18 )
    {
      if ( a3 == 2 )
        v33 = 5636;
      else
        v33 = 1540;
      *(_QWORD *)((char *)&v93 + 4) = 0;
      HIDWORD(v93) = v33;
      v95 = &v99;
      v96 = 0x400010003LL;
      v34 = *(__int64 (__fastcall **)(_QWORD))(v24 + 8);
      LODWORD(v92) = 5;
      if ( *((_DWORD *)v34 - 1) != -1839634494 )
        __break(0x8229u);
      result = v34(&v92);
      if ( (_DWORD)result )
      {
        result = _drm_err("opmode modify single reg failed ret %d\n", (unsigned int)result);
        goto LABEL_2;
      }
      *((_DWORD *)a2 + 42) = 0;
      v35 = a2[2];
      v36 = *(unsigned int *)(a1 + 48);
      v81 = 0;
      v82 = 0;
      v83 = 0;
      v84 = 0;
      v79 = v35;
      v80 = 0;
      if ( (unsigned int)v36 <= 0xE )
      {
        v37 = *(unsigned int *)(a1 + 1392);
        if ( (unsigned int)v37 <= 1 )
        {
          if ( (16 * v36 + 6000 * (unsigned __int64)a3 + 8 * v37 + 2640) >> 4 <= 0x464 )
          {
            LODWORD(v84) = 11;
            LODWORD(v80) = 1;
            v85 = a2[19];
            v38 = *((_DWORD *)a2 + 41);
            v86 = *((_DWORD *)a2 + 40);
            v87 = v38;
            v39 = sspp_buf[750 * a3 + 330 + 2 * v36 + v37];
            v40 = *(unsigned int *)(a1 + 28);
            v41 = *((_DWORD *)a2 + 43);
            v42 = *((_DWORD *)a2 + 44);
            v81 = v39;
            v90 = v41;
            v91 = v42;
            v43 = *((_DWORD *)a2 + 7);
            v88 = 0;
            v89 = v43;
            if ( (unsigned int)v40 <= 2 )
            {
              v44 = *(__int64 (__fastcall **)(__int64 *, __int64))(v24 + 8 * v40 + 16);
              if ( !v44 )
                goto LABEL_2;
              v45 = &v79;
              goto LABEL_68;
            }
            goto LABEL_72;
          }
          goto LABEL_73;
        }
      }
LABEL_72:
      __break(0x5512u);
      goto LABEL_73;
    }
LABEL_39:
    result = _drm_err("write decode select failed ret %d\n", v18);
    goto LABEL_2;
  }
  v8 = *((_DWORD *)a2 + 2);
  if ( v8 != 7688 )
  {
    result = _drm_err("invalid size of payload len %d exp %zd\n", v8, 0x1E08u);
    goto LABEL_2;
  }
  result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1392));
  if ( result )
  {
    v9 = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      if ( a3 >= 3 )
        goto LABEL_72;
      v10 = *(unsigned int *)(a1 + 48);
      if ( (unsigned int)v10 > 0xE )
        goto LABEL_72;
      v11 = *(unsigned int *)(a1 + 1392);
      if ( (unsigned int)v11 > 1 )
        goto LABEL_72;
      if ( (16 * v10 + 6000 * (unsigned __int64)a3 + 8 * v11 + 2640) >> 4 > 0x464 )
        goto LABEL_73;
      v12 = &sspp_buf[750 * a3 + 2 * v10 + v11];
      v13 = *(void (__fastcall **)(_QWORD))(result + 64);
      v14 = v12[330];
      if ( *((_DWORD *)v13 - 1) != -870478129 )
        __break(0x8229u);
      v13(v14);
      v15 = *(unsigned int *)(a1 + 48);
      v71 = 0;
      v72 = 0u;
      v73 = 0;
      v74 = nullptr;
      v75 = 0;
      v76 = 0;
      v77 = 0;
      if ( (unsigned int)v15 > 0xE )
        goto LABEL_72;
      v16 = *(unsigned int *)(a1 + 1392);
      HIDWORD(v71) = sspp_mapping[v15];
      LODWORD(v72) = 11;
      if ( (unsigned int)v16 > 1 )
        goto LABEL_72;
      if ( (16 * v15 + 6000 * (unsigned __int64)a3 + 8 * v16 + 2640) >> 4 > 0x464 )
        goto LABEL_73;
      HIDWORD(v72) = 0;
      DWORD1(v72) = 0;
      v75 = 0;
      v73 = sspp_buf[750 * a3 + 330 + 2 * v15 + v16];
      v74 = nullptr;
      v17 = *(__int64 (__fastcall **)(_QWORD))(v9 + 8);
      if ( *((_DWORD *)v17 - 1) != -1839634494 )
        __break(0x8228u);
      v18 = v17(&v71);
      if ( !v18 )
      {
        v19 = 412;
        if ( a3 == 2 )
          v19 = 448;
        v20 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 56) + 48LL) + v19);
        *(_QWORD *)((char *)&v72 + 4) = 0;
        HIDWORD(v72) = v20;
        v74 = (int *)(v7 + 4104);
        v75 = 0x20000000000LL;
        v21 = *(__int64 (__fastcall **)(_QWORD))(v9 + 8);
        LODWORD(v71) = 2;
        if ( *((_DWORD *)v21 - 1) != -1839634494 )
          __break(0x8229u);
        v22 = v21(&v71);
        if ( v22 )
        {
          result = _drm_err("lut write failed ret %d\n", v22);
          goto LABEL_2;
        }
        if ( a3 == 2 )
          v46 = 5636;
        else
          v46 = 1540;
        *(_QWORD *)((char *)&v72 + 4) = 0;
        HIDWORD(v72) = v46;
        v74 = &v78;
        v75 = 0x400010003LL;
        v78 = 4;
        v47 = *(__int64 (__fastcall **)(_QWORD))(v9 + 8);
        LODWORD(v71) = 5;
        if ( *((_DWORD *)v47 - 1) != -1839634494 )
          __break(0x8229u);
        v48 = v47(&v71);
        if ( v48 )
        {
          result = _drm_err("setting opcode failed ret %d\n", v48);
          goto LABEL_2;
        }
        v63 = 0;
        v64 = 0;
        *((_DWORD *)a2 + 42) = 1;
        v49 = a2[2];
        v50 = *(unsigned int *)(a1 + 48);
        v65 = 0;
        v66 = 0;
        v61 = v49;
        v62 = 0;
        if ( (unsigned int)v50 <= 0xE )
        {
          v51 = *(unsigned int *)(a1 + 1392);
          if ( (unsigned int)v51 <= 1 )
          {
            if ( (16 * v50 + 6000 * (unsigned __int64)a3 + 8 * v51 + 2640) >> 4 <= 0x464 )
            {
              v52 = a2[19];
              LODWORD(v66) = 11;
              v53 = *(_DWORD *)(a1 + 28);
              v54 = *((_DWORD *)a2 + 40);
              v55 = *((_DWORD *)a2 + 41);
              v67 = v52;
              v68 = __PAIR64__(v55, v54);
              LODWORD(v65) = 0;
              v56 = *((_DWORD *)a2 + 43);
              v57 = *((_DWORD *)a2 + 44);
              v58 = sspp_buf[750 * a3 + 330 + 2 * v50 + v51];
              LODWORD(v62) = 1;
              v70 = __PAIR64__(v57, v56);
              v59 = *((_DWORD *)a2 + 7);
              v63 = v58;
              LODWORD(v69) = 1;
              HIDWORD(v69) = v59;
              result = sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_dma_gcv5", 4121, -1, v50, v51, v53, 1, 239);
              v60 = *(unsigned int *)(a1 + 28);
              if ( (unsigned int)v60 <= 2 )
              {
                v44 = *(__int64 (__fastcall **)(__int64 *, __int64))(v9 + 8 * v60 + 16);
                if ( !v44 )
                  goto LABEL_2;
                v37 = *(unsigned int *)(a1 + 1392);
                v45 = &v61;
LABEL_68:
                if ( *((_DWORD *)v44 - 1) != 1772228465 )
                  __break(0x8228u);
                result = v44(v45, v37);
                if ( (_DWORD)result )
                  result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
                goto LABEL_2;
              }
              goto LABEL_72;
            }
LABEL_73:
            __break(1u);
            JUMPOUT(0x154524);
          }
        }
        goto LABEL_72;
      }
      goto LABEL_39;
    }
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
