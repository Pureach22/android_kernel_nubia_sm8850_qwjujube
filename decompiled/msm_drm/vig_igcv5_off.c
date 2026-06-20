unsigned __int64 __fastcall vig_igcv5_off(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x8
  int v7; // w23
  unsigned __int64 result; // x0
  unsigned __int64 v9; // x21
  __int64 v10; // x8
  __int64 v11; // x9
  _QWORD *v12; // x8
  void (__fastcall *v13)(_QWORD); // x9
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x9
  __int64 (__fastcall *v17)(_QWORD); // x8
  unsigned int v18; // w0
  __int64 (__fastcall *v19)(_QWORD); // x9
  __int64 v20; // x9
  __int64 v21; // x8
  __int64 v22; // x1
  __int64 v23; // x10
  int v24; // w9
  __int64 v25; // x8
  int v26; // w9
  __int64 v27; // x8
  int v28; // w9
  __int64 (__fastcall *v29)(_QWORD); // x8
  __int64 v30; // [xsp+0h] [xbp-A0h] BYREF
  __int64 v31; // [xsp+8h] [xbp-98h]
  __int64 v32; // [xsp+10h] [xbp-90h]
  __int64 v33; // [xsp+18h] [xbp-88h]
  __int64 v34; // [xsp+20h] [xbp-80h]
  __int64 v35; // [xsp+28h] [xbp-78h]
  __int64 v36; // [xsp+30h] [xbp-70h]
  int v37; // [xsp+38h] [xbp-68h]
  int v38; // [xsp+3Ch] [xbp-64h]
  int v39; // [xsp+40h] [xbp-60h]
  int v40; // [xsp+44h] [xbp-5Ch]
  int v41; // [xsp+48h] [xbp-58h]
  int v42; // [xsp+4Ch] [xbp-54h]
  __int64 v43; // [xsp+50h] [xbp-50h] BYREF
  __int128 v44; // [xsp+58h] [xbp-48h]
  __int64 v45; // [xsp+68h] [xbp-38h]
  int *v46; // [xsp+70h] [xbp-30h]
  __int64 v47; // [xsp+78h] [xbp-28h]
  __int64 v48; // [xsp+80h] [xbp-20h]
  __int64 v49; // [xsp+88h] [xbp-18h]
  int v50; // [xsp+94h] [xbp-Ch] BYREF
  __int64 v51; // [xsp+98h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 56);
  v48 = 0;
  v49 = 0;
  v5 = *(unsigned int *)(a1 + 1392);
  v50 = 0;
  v6 = *(_QWORD *)(v4 + 48);
  v46 = nullptr;
  v47 = 0;
  v45 = 0;
  v7 = *(_DWORD *)(v6 + 336);
  v43 = 0;
  v44 = 0u;
  result = sde_reg_dma_get_ops(v5);
  if ( !result )
    goto LABEL_19;
  v9 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_19;
  v10 = *(unsigned int *)(a1 + 48);
  if ( (unsigned int)v10 > 0xE )
    goto LABEL_29;
  v11 = *(unsigned int *)(a1 + 1392);
  if ( (unsigned int)v11 > 1 )
    goto LABEL_29;
  if ( (unsigned __int64)(16 * v10 + 8 * v11 + 6480) > 0x4650 )
    goto LABEL_30;
  v12 = &sspp_buf[2 * v10 + v11];
  v13 = *(void (__fastcall **)(_QWORD))(result + 64);
  v14 = v12[810];
  if ( *((_DWORD *)v13 - 1) != -870478129 )
    __break(0x8229u);
  v13(v14);
  v15 = *(unsigned int *)(a1 + 48);
  v43 = 0;
  v44 = 0u;
  v45 = 0;
  v46 = nullptr;
  v47 = 0;
  v48 = 0;
  v49 = 0;
  if ( (unsigned int)v15 > 0xE )
    goto LABEL_29;
  v16 = *(unsigned int *)(a1 + 1392);
  HIDWORD(v43) = sspp_mapping[v15];
  LODWORD(v44) = 2;
  if ( (unsigned int)v16 > 1 )
    goto LABEL_29;
  if ( (unsigned __int64)(16 * v15 + 8 * v16 + 6480) > 0x4650 )
    goto LABEL_30;
  HIDWORD(v44) = 0;
  DWORD1(v44) = 0;
  v47 = 0;
  v45 = sspp_buf[2 * v15 + 810 + v16];
  v46 = nullptr;
  v17 = *(__int64 (__fastcall **)(_QWORD))(v9 + 8);
  if ( *((_DWORD *)v17 - 1) != -1839634494 )
    __break(0x8228u);
  v18 = v17(&v43);
  if ( v18 )
  {
    result = _drm_err("write decode select failed ret %d\n", v18);
    goto LABEL_19;
  }
  HIDWORD(v44) = v7;
  *(_QWORD *)((char *)&v44 + 4) = 0;
  v46 = &v50;
  v47 = 0x40001001FLL;
  v19 = *(__int64 (__fastcall **)(_QWORD))(v9 + 8);
  LODWORD(v43) = 5;
  if ( *((_DWORD *)v19 - 1) != -1839634494 )
    __break(0x8229u);
  result = v19(&v43);
  if ( (_DWORD)result )
  {
    result = _drm_err("opmode modify single reg failed ret %d\n", (unsigned int)result);
    goto LABEL_19;
  }
  *(_DWORD *)(a2 + 168) = 0;
  v20 = *(_QWORD *)(a2 + 16);
  v21 = *(unsigned int *)(a1 + 48);
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v30 = v20;
  v31 = 0;
  if ( (unsigned int)v21 > 0xE )
    goto LABEL_29;
  v22 = *(unsigned int *)(a1 + 1392);
  if ( (unsigned int)v22 > 1 )
    goto LABEL_29;
  if ( (unsigned __int64)(16 * v21 + 8 * v22 + 6480) > 0x4650 )
    goto LABEL_30;
  v23 = *(_QWORD *)(a2 + 152);
  LODWORD(v31) = 1;
  LODWORD(v35) = 2;
  v36 = v23;
  v24 = *(_DWORD *)(a2 + 160);
  LODWORD(v23) = *(_DWORD *)(a2 + 164);
  v25 = sspp_buf[2 * v21 + 810 + v22];
  LODWORD(v34) = 0;
  v37 = v24;
  v38 = v23;
  v26 = *(_DWORD *)(a2 + 172);
  LODWORD(v23) = *(_DWORD *)(a2 + 176);
  v32 = v25;
  v27 = *(unsigned int *)(a1 + 28);
  v41 = v26;
  v42 = v23;
  v28 = *(_DWORD *)(a2 + 28);
  v39 = 0;
  v40 = v28;
  if ( (unsigned int)v27 > 2 )
  {
LABEL_29:
    __break(0x5512u);
LABEL_30:
    __break(1u);
  }
  v29 = *(__int64 (__fastcall **)(_QWORD))(v9 + 8 * v27 + 16);
  if ( v29 )
  {
    if ( *((_DWORD *)v29 - 1) != 1772228465 )
      __break(0x8228u);
    result = v29(&v30);
    if ( (_DWORD)result )
      result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
