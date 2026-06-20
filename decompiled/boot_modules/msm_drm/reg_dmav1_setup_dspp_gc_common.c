__int64 __fastcall reg_dmav1_setup_dspp_gc_common(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // d14
  int v9; // w8
  unsigned int v10; // w8
  __int64 result; // x0
  __int64 v16; // x15
  __int64 v17; // d3
  __int64 v18; // x8
  __int64 v19; // x9
  unsigned __int64 *v20; // x8
  void (__fastcall *v21)(_QWORD); // x9
  unsigned __int64 v22; // x0
  int v23; // w8
  __int64 v24; // x8
  __int64 v25; // x9
  unsigned __int64 v26; // x8
  __int64 (__fastcall *v27)(_QWORD); // x8
  const char *v28; // x8
  __int64 v29; // x22
  __int64 v30; // x8
  __int64 (__fastcall *v31)(_QWORD); // x8
  int v32; // w8
  __int64 (__fastcall *v33)(_QWORD); // x8
  unsigned int v34; // w19
  __int64 v35; // x8
  __int64 (__fastcall *v36)(_QWORD); // x8
  int v37; // w8
  __int64 (__fastcall *v38)(_QWORD); // x8
  __int64 v39; // x8
  __int64 (__fastcall *v40)(_QWORD); // x8
  int v41; // w8
  __int64 (__fastcall *v42)(_QWORD); // x8
  int v43; // [xsp+Ch] [xbp-14h] BYREF
  int v44; // [xsp+10h] [xbp-10h] BYREF
  int v45; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+18h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_DWORD *)(a2 + 8);
  v43 = 0;
  if ( v9 != 7688 )
  {
    _drm_err("invalid size of payload len %d exp %zd\n", v9, 0x1E08u);
    result = 4294967274LL;
    goto LABEL_27;
  }
  v10 = *(_DWORD *)(a1 + 64);
  v44 = 0;
  result = reg_dmav1_get_dspp_blk(a2, v10, &v43, &v44, a5, a6, a7, a8);
  if ( (_DWORD)result == -114 )
  {
LABEL_27:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (_DWORD)result == -22 )
  {
    _drm_err("unable to determine LUTDMA DSPP blocks\n");
    result = 4294967274LL;
    goto LABEL_27;
  }
  v18 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v18 >= 5 )
    goto LABEL_41;
  v19 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v19 > 1 )
    goto LABEL_41;
  if ( (unsigned __int64)(16 * v18 + 8 * v19 + 880) > 0x7D0 )
    goto LABEL_42;
  v20 = &dspp_buf[2 * v18 + v19];
  v21 = *(void (__fastcall **)(_QWORD))(a3 + 64);
  v22 = v20[110];
  if ( *((_DWORD *)v21 - 1) != -870478129 )
    __break(0x8229u);
  v21(v22);
  v23 = v43;
  *(_QWORD *)a4 = 0;
  *(_QWORD *)(a4 + 8) = 0;
  *(_QWORD *)(a4 + 48) = 0;
  *(_QWORD *)(a4 + 56) = 0;
  *(_QWORD *)(a4 + 32) = 0;
  *(_QWORD *)(a4 + 40) = 0;
  *(_QWORD *)(a4 + 16) = 0;
  *(_QWORD *)(a4 + 24) = 0;
  *(_DWORD *)(a4 + 4) = v23;
  *(_DWORD *)(a4 + 8) = 11;
  v24 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v24 > 4 || (v25 = *(unsigned int *)(a1 + 1496), (unsigned int)v25 > 1) )
  {
LABEL_41:
    __break(0x5512u);
    goto LABEL_42;
  }
  if ( (unsigned __int64)(16 * v24 + 8 * v25 + 880) <= 0x7D0 )
  {
    v26 = dspp_buf[2 * v24 + 110 + v25];
    *(_DWORD *)a4 = 0;
    *(_DWORD *)(a4 + 20) = 0;
    *(_QWORD *)(a4 + 12) = 0;
    *(_QWORD *)(a4 + 24) = v26;
    *(_QWORD *)(a4 + 32) = 0;
    *(_QWORD *)(a4 + 40) = 0;
    v27 = *(__int64 (__fastcall **)(_QWORD))(a3 + 8);
    if ( *((_DWORD *)v27 - 1) != -1839634494 )
      __break(0x8228u);
    LODWORD(result) = v27(a4);
    if ( (_DWORD)result )
    {
      v28 = "write decode select failed ret %d\n";
LABEL_26:
      v34 = result;
      _drm_err(v28, (unsigned int)result);
      result = v34;
      goto LABEL_27;
    }
    v29 = *(_QWORD *)a2;
    *(_DWORD *)a4 = 1;
    v30 = *(_QWORD *)(a1 + 72);
    v45 = 0;
    LODWORD(v30) = *(_DWORD *)(*(_QWORD *)(v30 + 48) + 92LL);
    *(_QWORD *)(a4 + 12) = 0;
    *(_DWORD *)(a4 + 20) = v30 + 8;
    *(_QWORD *)(a4 + 32) = &v45;
    *(_QWORD *)(a4 + 40) = 0x400000000LL;
    v31 = *(__int64 (__fastcall **)(_QWORD))(a3 + 8);
    if ( *((_DWORD *)v31 - 1) != -1839634494 )
      __break(0x8228u);
    LODWORD(result) = v31(a4);
    if ( (_DWORD)result )
    {
LABEL_21:
      v28 = "index init failed ret %d\n";
      goto LABEL_26;
    }
    *(_DWORD *)a4 = 3;
    v32 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 92LL);
    *(_QWORD *)(a4 + 12) = 0;
    *(_DWORD *)(a4 + 20) = v32 + 4;
    *(_QWORD *)(a4 + 32) = v29 + 8;
    *(_QWORD *)(a4 + 40) = 0x80000000000LL;
    v33 = *(__int64 (__fastcall **)(_QWORD))(a3 + 8);
    if ( *((_DWORD *)v33 - 1) != -1839634494 )
      __break(0x8228u);
    LODWORD(result) = v33(a4);
    if ( !(_DWORD)result )
    {
      *(_DWORD *)a4 = 1;
      v35 = *(_QWORD *)(a1 + 72);
      v45 = 0;
      LODWORD(v35) = *(_DWORD *)(*(_QWORD *)(v35 + 48) + 92LL);
      *(_QWORD *)(a4 + 12) = 0;
      *(_DWORD *)(a4 + 20) = v35 + 16;
      *(_QWORD *)(a4 + 32) = &v45;
      *(_QWORD *)(a4 + 40) = 0x400000000LL;
      v36 = *(__int64 (__fastcall **)(_QWORD))(a3 + 8);
      if ( *((_DWORD *)v36 - 1) != -1839634494 )
        __break(0x8228u);
      LODWORD(result) = v36(a4);
      if ( (_DWORD)result )
        goto LABEL_21;
      *(_DWORD *)a4 = 3;
      v37 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 92LL);
      *(_QWORD *)(a4 + 12) = 0;
      *(_DWORD *)(a4 + 20) = v37 + 12;
      *(_QWORD *)(a4 + 32) = v29 + 2056;
      *(_QWORD *)(a4 + 40) = 0x80000000000LL;
      v38 = *(__int64 (__fastcall **)(_QWORD))(a3 + 8);
      if ( *((_DWORD *)v38 - 1) != -1839634494 )
        __break(0x8228u);
      LODWORD(result) = v38(a4);
      if ( !(_DWORD)result )
      {
        *(_DWORD *)a4 = 1;
        v39 = *(_QWORD *)(a1 + 72);
        v45 = 0;
        LODWORD(v39) = *(_DWORD *)(*(_QWORD *)(v39 + 48) + 92LL);
        *(_QWORD *)(a4 + 12) = 0;
        *(_DWORD *)(a4 + 20) = v39 + 24;
        *(_QWORD *)(a4 + 32) = &v45;
        *(_QWORD *)(a4 + 40) = 0x400000000LL;
        v40 = *(__int64 (__fastcall **)(_QWORD))(a3 + 8);
        if ( *((_DWORD *)v40 - 1) != -1839634494 )
          __break(0x8228u);
        LODWORD(result) = v40(a4);
        if ( (_DWORD)result )
          goto LABEL_21;
        *(_DWORD *)a4 = 3;
        v41 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 92LL);
        *(_QWORD *)(a4 + 12) = 0;
        *(_DWORD *)(a4 + 20) = v41 + 20;
        *(_QWORD *)(a4 + 32) = v29 + 4104;
        *(_QWORD *)(a4 + 40) = 0x80000000000LL;
        v42 = *(__int64 (__fastcall **)(_QWORD))(a3 + 8);
        if ( *((_DWORD *)v42 - 1) != -1839634494 )
          __break(0x8228u);
        result = v42(a4);
        if ( !(_DWORD)result )
          goto LABEL_27;
      }
    }
    v28 = "lut write failed ret %d\n";
    goto LABEL_26;
  }
LABEL_42:
  __break(1u);
  *(_QWORD *)(v16 - 24) = v8;
  *(_QWORD *)(v16 - 16) = v17;
  return reg_dmav1_setup_dspp_gcv2();
}
