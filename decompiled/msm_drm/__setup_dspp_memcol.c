unsigned __int64 __fastcall _setup_dspp_memcol(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7)
{
  __int64 v7; // d14
  int v11; // w26
  int v12; // w25
  unsigned int v13; // w1
  unsigned __int64 result; // x0
  __int64 v15; // x27
  __int64 v16; // x15
  __int64 v17; // d3
  unsigned __int64 v18; // x22
  __int64 v19; // x8
  __int64 v20; // x9
  void (__fastcall *v21)(_QWORD); // x10
  unsigned __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x9
  __int64 (__fastcall *v25)(_QWORD); // x8
  unsigned int v26; // w0
  __int64 v27; // x8
  int v28; // w24
  int *v29; // x28
  __int64 v30; // x8
  __int64 (__fastcall *v31)(_QWORD); // x8
  __int64 (__fastcall *v32)(_QWORD); // x8
  __int64 v33; // x8
  __int64 v34; // x8
  __int64 (__fastcall *v35)(_QWORD); // x8
  char v36; // w8
  int v37; // w10
  int v38; // w9
  unsigned __int64 v39; // x26
  unsigned int v40; // w25
  __int64 v41; // x8
  unsigned int v42; // w9
  __int64 v43; // x8
  __int64 v44; // x9
  __int64 (__fastcall *v45)(_QWORD); // x8
  __int64 (__fastcall *v46)(_QWORD); // x8
  __int64 v47; // x8
  __int64 v48; // x8
  __int64 (__fastcall *v49)(_QWORD); // x8
  __int64 v50; // x9
  __int64 v51; // x8
  __int64 v52; // x1
  unsigned int v53; // w10
  unsigned int v54; // w12
  __int64 v55; // x11
  unsigned int v56; // w9
  unsigned int v57; // w10
  unsigned __int64 v58; // x11
  __int64 v59; // x8
  int v60; // w10
  __int64 (__fastcall *v61)(_QWORD); // x8
  unsigned int v62; // [xsp+10h] [xbp-E0h]
  int v63; // [xsp+14h] [xbp-DCh]
  unsigned int v64; // [xsp+18h] [xbp-D8h] BYREF
  unsigned int v65; // [xsp+1Ch] [xbp-D4h] BYREF
  int v66; // [xsp+20h] [xbp-D0h] BYREF
  int v67; // [xsp+24h] [xbp-CCh] BYREF
  __int64 v68; // [xsp+28h] [xbp-C8h] BYREF
  __int64 v69; // [xsp+30h] [xbp-C0h]
  unsigned __int64 v70; // [xsp+38h] [xbp-B8h]
  __int64 v71; // [xsp+40h] [xbp-B0h]
  __int64 v72; // [xsp+48h] [xbp-A8h]
  __int64 v73; // [xsp+50h] [xbp-A0h]
  __int64 v74; // [xsp+58h] [xbp-98h]
  unsigned __int64 v75; // [xsp+60h] [xbp-90h]
  __int64 v76; // [xsp+68h] [xbp-88h]
  unsigned __int64 v77; // [xsp+70h] [xbp-80h]
  __int64 v78; // [xsp+78h] [xbp-78h] BYREF
  __int128 v79; // [xsp+80h] [xbp-70h]
  unsigned __int64 v80; // [xsp+90h] [xbp-60h]
  int *v81; // [xsp+98h] [xbp-58h]
  __int64 v82; // [xsp+A0h] [xbp-50h]
  __int64 v83; // [xsp+A8h] [xbp-48h]
  __int64 v84; // [xsp+B0h] [xbp-40h]
  _QWORD dest[7]; // [xsp+B8h] [xbp-38h] BYREF

  dest[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v67 = 0;
  v64 = 0;
  if ( a2 == 7 )
  {
    v11 = 2;
    v66 = 64;
    v12 = 1048640;
  }
  else if ( a2 == 6 )
  {
    v11 = 1;
    v66 = 128;
    v12 = 1048704;
  }
  else
  {
    v11 = 0;
    v12 = 1048608;
    v66 = 32;
  }
  v13 = *(_DWORD *)(a1 + 64);
  v83 = 0;
  v84 = 0;
  v81 = nullptr;
  v82 = 0;
  v80 = 0;
  v78 = 0;
  v79 = 0u;
  v68 = 0;
  v69 = 0;
  v70 = 0;
  v71 = 0;
  v72 = 0;
  v73 = 0;
  v74 = 0;
  v75 = 0;
  v76 = 0;
  v77 = 0;
  v65 = 0;
  result = reg_dmav1_get_dspp_blk(a3, v13, &v64, &v65, a4, a5, a6, a7);
  if ( (_DWORD)result == -114 )
    goto LABEL_38;
  if ( (_DWORD)result == -22 )
  {
    result = _drm_err("unable to determine LUTDMA DSPP blocks\n");
LABEL_38:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v15 = v65;
  if ( v65 >= 6 )
  {
    result = _drm_err("unable to process more than %d DSPP blocks\n", 5);
    goto LABEL_38;
  }
  memset(dest, 0, 40);
  if ( v65 < 2 )
    dest[0] = a1;
  else
    memcpy(dest, (const void *)(a3 + 48), 8LL * v65);
  result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
  if ( !result )
    goto LABEL_38;
  v18 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_38;
  v19 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v19 > 4 )
    goto LABEL_66;
  v20 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v20 > 1 )
    goto LABEL_66;
  if ( ((16 * v19 + 80LL * a2) | (unsigned __int64)(8 * v20)) <= 0x7CF )
  {
    v21 = *(void (__fastcall **)(_QWORD))(result + 64);
    v22 = dspp_buf[10 * a2 + 2 * v19 + v20];
    if ( *((_DWORD *)v21 - 1) != -870478129 )
      __break(0x822Au);
    v21(v22);
    v23 = *(unsigned int *)(a1 + 64);
    LODWORD(v78) = 0;
    v80 = 0;
    v81 = nullptr;
    v82 = 0;
    v83 = 0;
    v84 = 0;
    HIDWORD(v78) = v64;
    v79 = a2;
    if ( (unsigned int)v23 > 4 || (v24 = *(unsigned int *)(a1 + 1496), (unsigned int)v24 > 1) )
    {
LABEL_66:
      __break(0x5512u);
      goto LABEL_67;
    }
    if ( ((16 * v23 + 80LL * a2) | (unsigned __int64)(8 * v24)) <= 0x7CF )
    {
      HIDWORD(v79) = 0;
      DWORD1(v79) = 0;
      v82 = 0;
      v80 = dspp_buf[10 * a2 + 2 * v23 + v24];
      v81 = nullptr;
      v25 = *(__int64 (__fastcall **)(_QWORD))(v18 + 8);
      if ( *((_DWORD *)v25 - 1) != -1839634494 )
        __break(0x8228u);
      v26 = v25(&v78);
      if ( v26 )
      {
LABEL_27:
        result = _drm_err("write decode select failed ret %d\n", v26);
        goto LABEL_38;
      }
      v27 = *(_QWORD *)(a1 + 72);
      *(_QWORD *)((char *)&v79 + 4) = 0;
      v28 = *(_DWORD *)(*(_QWORD *)(v27 + 48) + 164LL) + 20 * v11;
      v29 = *(int **)a3;
      v30 = *(_QWORD *)a3 + 8LL;
      HIDWORD(v79) = v28;
      v81 = (int *)v30;
      v82 = 0x800000000LL;
      v31 = *(__int64 (__fastcall **)(_QWORD))(v18 + 8);
      LODWORD(v78) = 2;
      if ( *((_DWORD *)v31 - 1) != -1839634494 )
        __break(0x8228u);
      LODWORD(result) = v31(&v78);
      if ( (_DWORD)result )
        goto LABEL_37;
      *(_QWORD *)((char *)&v79 + 4) = 0;
      HIDWORD(v79) = v28 + 8;
      v81 = v29 + 8;
      v82 = 0xC00000000LL;
      v32 = *(__int64 (__fastcall **)(_QWORD))(v18 + 8);
      LODWORD(v78) = 2;
      if ( *((_DWORD *)v32 - 1) != -1839634494 )
        __break(0x8228u);
      LODWORD(result) = v32(&v78);
      if ( (_DWORD)result )
        goto LABEL_37;
      v33 = *(_QWORD *)(a1 + 72);
      *(_QWORD *)((char *)&v79 + 4) = 0;
      v34 = *(_QWORD *)(v33 + 48);
      LODWORD(v78) = 2;
      HIDWORD(v79) = *(_DWORD *)(v34 + 164) + 8 * v11 + 60;
      v81 = v29 + 4;
      v82 = 0x800000000LL;
      v35 = *(__int64 (__fastcall **)(_QWORD))(v18 + 8);
      if ( *((_DWORD *)v35 - 1) != -1839634494 )
        __break(0x8228u);
      result = v35(&v78);
      if ( (_DWORD)result )
      {
LABEL_37:
        result = _drm_err("setting color_adjust_p0 failed ret %d\n", (unsigned int)result);
        goto LABEL_38;
      }
      v36 = 4 * v11;
      v37 = ((v29[7] & 3) << ((4 * (v11 & 3)) | 2)) | ((v29[6] & 3) << (4 * v11));
      v38 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 128LL);
      v66 = v12;
      v67 = v37;
      if ( (_DWORD)v15 )
      {
        v62 = ~v12;
        v63 = v38 + 64;
        v39 = 0;
        v40 = (15 << v36) ^ 0xFFFF;
        while ( v39 <= 0x27 )
        {
          v41 = *(unsigned int *)(dest[v39 / 8] + 64LL);
          if ( (unsigned int)v41 > 4 )
            goto LABEL_66;
          v78 = 0;
          v79 = 0u;
          v42 = dspp_mapping[v41];
          v43 = *(unsigned int *)(a1 + 64);
          v80 = 0;
          v81 = nullptr;
          v82 = 0;
          v64 = v42;
          v83 = 0;
          v84 = 0;
          HIDWORD(v78) = v42;
          LODWORD(v79) = a2;
          if ( (unsigned int)v43 > 4 )
            goto LABEL_66;
          v44 = *(unsigned int *)(a1 + 1496);
          if ( (unsigned int)v44 > 1 )
            goto LABEL_66;
          if ( ((80LL * a2 + 16 * v43) | (unsigned __int64)(8 * v44)) > 0x7CF )
            goto LABEL_67;
          HIDWORD(v79) = 0;
          DWORD1(v79) = 0;
          v80 = dspp_buf[10 * a2 + 2 * v43 + v44];
          v81 = nullptr;
          v82 = 0;
          v45 = *(__int64 (__fastcall **)(_QWORD))(v18 + 8);
          if ( *((_DWORD *)v45 - 1) != -1839634494 )
            __break(0x8228u);
          v26 = v45(&v78);
          if ( v26 )
            goto LABEL_27;
          *(_QWORD *)((char *)&v79 + 4) = 0;
          v82 = v40 | 0x400000000LL;
          HIDWORD(v79) = v63;
          v81 = &v67;
          v46 = *(__int64 (__fastcall **)(_QWORD))(v18 + 8);
          LODWORD(v78) = 5;
          if ( *((_DWORD *)v46 - 1) != -1839634494 )
            __break(0x8228u);
          LODWORD(result) = v46(&v78);
          if ( (_DWORD)result )
            goto LABEL_37;
          v47 = *(_QWORD *)(a1 + 72);
          *(_QWORD *)((char *)&v79 + 4) = 0;
          v81 = &v66;
          v48 = *(_QWORD *)(v47 + 48);
          LODWORD(v78) = 5;
          HIDWORD(v79) = *(_DWORD *)(v48 + 128);
          v82 = v62 | 0x400000000LL;
          v49 = *(__int64 (__fastcall **)(_QWORD))(v18 + 8);
          if ( *((_DWORD *)v49 - 1) != -1839634494 )
            __break(0x8228u);
          result = v49(&v78);
          if ( (_DWORD)result )
          {
            result = _drm_err("setting opcode failed ret %d\n", (unsigned int)result);
            goto LABEL_38;
          }
          v39 += 8LL;
          if ( 8 * v15 == v39 )
            goto LABEL_56;
        }
        goto LABEL_67;
      }
LABEL_56:
      v50 = *(_QWORD *)(a3 + 16);
      v70 = 0;
      v71 = 0;
      *(_DWORD *)(a3 + 168) = 3;
      v51 = *(unsigned int *)(a1 + 64);
      v72 = 0;
      v73 = 0;
      v68 = v50;
      v69 = 0;
      if ( (unsigned int)v51 > 4 )
        goto LABEL_66;
      v52 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v52 > 1 )
        goto LABEL_66;
      if ( ((16 * v51 + 80LL * a2) | (unsigned __int64)(8 * v52)) <= 0x7CF )
      {
        LODWORD(v69) = 1;
        v53 = *(_DWORD *)(a3 + 160);
        v54 = *(_DWORD *)(a3 + 164);
        v55 = *(_QWORD *)(a3 + 152);
        LODWORD(v72) = 0;
        LODWORD(v73) = a2;
        v75 = __PAIR64__(v54, v53);
        v56 = *(_DWORD *)(a3 + 172);
        v57 = *(_DWORD *)(a3 + 176);
        v74 = v55;
        v58 = dspp_buf[10 * a2 + 2 * v51 + v52];
        v59 = *(unsigned int *)(a1 + 28);
        v77 = __PAIR64__(v57, v56);
        v60 = *(_DWORD *)(a3 + 28);
        v70 = v58;
        LODWORD(v76) = 3;
        HIDWORD(v76) = v60;
        if ( (unsigned int)v59 <= 2 )
        {
          v61 = *(__int64 (__fastcall **)(_QWORD))(v18 + 8 * v59 + 16);
          if ( v61 )
          {
            if ( *((_DWORD *)v61 - 1) != 1772228465 )
              __break(0x8228u);
            result = v61(&v68);
            if ( (_DWORD)result )
              result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
          }
          goto LABEL_38;
        }
        goto LABEL_66;
      }
    }
  }
LABEL_67:
  __break(1u);
  *(_QWORD *)(v16 - 24) = v7;
  *(_QWORD *)(v16 - 16) = v17;
  return reg_dmav1_setup_dspp_memcol_skyv17();
}
