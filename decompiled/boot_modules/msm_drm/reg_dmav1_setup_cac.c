__int64 __fastcall reg_dmav1_setup_cac(__int64 a1, __int64 a2, __int64 a3, int a4, unsigned int a5)
{
  __int64 v9; // x0
  __int64 ops; // x0
  __int64 v11; // x21
  int v12; // w14
  int v13; // w11
  int v14; // w12
  int v15; // w13
  __int64 (__fastcall *v16)(_QWORD); // x8
  unsigned int v17; // w0
  unsigned int v18; // w23
  int v19; // w12
  char v20; // w9
  int v21; // w27
  int v22; // w11
  int v23; // w10
  int v24; // w28
  int v25; // w25
  int v26; // w11
  int v27; // w24
  int v28; // w26
  int v29; // w9
  int v30; // w11
  int v31; // w20
  int v32; // w8
  __int64 (__fastcall *v33)(_QWORD); // x10
  unsigned int v34; // w0
  __int64 (__fastcall *v35)(_QWORD); // x8
  int v36; // w9
  unsigned int v37; // w8
  unsigned int v38; // w9
  __int64 (__fastcall *v39)(_QWORD); // x10
  unsigned int v40; // w0
  int v41; // w9
  int v42; // w10
  __int64 (__fastcall *v43)(_QWORD); // x10
  unsigned int v44; // w0
  int v45; // w9
  int v46; // w8
  __int64 (__fastcall *v47)(_QWORD); // x10
  unsigned int v48; // w0
  __int64 (__fastcall *v49)(_QWORD); // x8
  unsigned int v50; // w0
  __int64 (__fastcall *v51)(_QWORD); // x8
  unsigned int v52; // w0
  int v54; // [xsp+8h] [xbp-78h]
  int v55; // [xsp+20h] [xbp-60h]
  int v56; // [xsp+24h] [xbp-5Ch]
  int v57; // [xsp+28h] [xbp-58h]
  int v58; // [xsp+2Ch] [xbp-54h]
  int v59; // [xsp+30h] [xbp-50h]
  int v60; // [xsp+34h] [xbp-4Ch]
  int v61; // [xsp+38h] [xbp-48h]
  int v62; // [xsp+3Ch] [xbp-44h]
  int v63; // [xsp+40h] [xbp-40h]
  int v64; // [xsp+44h] [xbp-3Ch]
  int v65; // [xsp+48h] [xbp-38h]
  int v66; // [xsp+4Ch] [xbp-34h]
  int v67; // [xsp+50h] [xbp-30h]
  int v68; // [xsp+54h] [xbp-2Ch]
  int v69; // [xsp+58h] [xbp-28h]
  int v70; // [xsp+5Ch] [xbp-24h]
  int v71; // [xsp+60h] [xbp-20h]
  unsigned int v72; // [xsp+64h] [xbp-1Ch] BYREF
  unsigned __int64 v73; // [xsp+68h] [xbp-18h] BYREF
  unsigned __int64 v74; // [xsp+70h] [xbp-10h]
  __int64 v75; // [xsp+78h] [xbp-8h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned int *)(a1 + 1392);
  v72 = a5;
  v73 = 0;
  v74 = 0;
  ops = sde_reg_dma_get_ops(v9);
  if ( ops )
  {
    v11 = ops;
    v12 = *(_DWORD *)(a3 + 32) & 0xFFFFFF;
    v13 = *(_DWORD *)(a3 + 36) & 0xFFFFFF;
    v14 = *(_DWORD *)(a3 + 64) & 0xFFFFFF;
    v15 = *(_DWORD *)(a3 + 68) & 0xFFFFFF;
    if ( *(_QWORD *)(a3 + 308) )
    {
      v65 = *(_DWORD *)(a3 + 68) & 0xFFFFFF;
      v66 = *(_DWORD *)(a3 + 36) & 0xFFFFFF;
      v67 = *(_DWORD *)(a3 + 64) & 0xFFFFFF;
      v68 = *(_DWORD *)(a3 + 32) & 0xFFFFFF;
      v63 = *(unsigned __int16 *)(a3 + 500);
      v64 = *(unsigned __int16 *)(a3 + 484);
      v69 = *(unsigned __int16 *)(a3 + 384);
      v55 = *(unsigned __int16 *)(a3 + 508);
      v19 = *(_DWORD *)(a3 + 320);
      v58 = *(unsigned __int16 *)(a3 + 526);
      v20 = *(_DWORD *)(a3 + 436);
      v21 = *(_DWORD *)(a3 + 404);
      v61 = *(unsigned __int16 *)(a3 + 524);
      v62 = *(unsigned __int16 *)(a3 + 492);
      v22 = *(unsigned __int16 *)(a3 + 502);
      v23 = *(unsigned __int16 *)(a3 + 486);
      v71 = a4;
      v72 = ((*(_DWORD *)(a3 + 312) & 3) << 20) & 0xFCFFFFFF
          | ((*(_DWORD *)(a3 + 316) & 3) << 24)
          | a5
          | (2 * *(_DWORD *)(a3 + 308));
      v59 = v22;
      v60 = v23;
      v24 = *(unsigned __int16 *)(a3 + 388);
      v25 = *(_DWORD *)(a3 + 452);
      v56 = *(unsigned __int16 *)(a3 + 510);
      v57 = *(unsigned __int16 *)(a3 + 494);
      v26 = *(_DWORD *)(a3 + 400);
      LOBYTE(v23) = *(_DWORD *)(a3 + 432);
      LODWORD(v74) = *(_DWORD *)(a3 + 372) & 0x1FFFFF;
      HIDWORD(v74) = v19;
      v27 = *(unsigned __int16 *)(a3 + 448);
      v28 = *(_DWORD *)(a3 + 460);
      v29 = ((v20 & 0x7F) << 24) | ((v23 & 0x7F) << 8);
      v70 = v26;
      v30 = a4 + 160;
      v31 = *(unsigned __int16 *)(a3 + 456);
      v32 = *(_DWORD *)(a3 + 368);
      *(_DWORD *)(a2 + 20) = v30;
      *(_DWORD *)a2 = 2;
      *(_QWORD *)(a2 + 12) = 0;
      *(_QWORD *)(a2 + 32) = &v73;
      *(_QWORD *)(a2 + 40) = 0x1000000000LL;
      v33 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
      LODWORD(v73) = v29;
      HIDWORD(v73) = v32 & 0x1FFFFF;
      if ( *((_DWORD *)v33 - 1) != -1839634494 )
        __break(0x822Au);
      v34 = v33(a2);
      if ( v34 )
      {
        v18 = v34;
        _drm_err("setting re phase failed ret %d\n", v34);
        goto LABEL_36;
      }
      v54 = v31;
      v36 = *(_DWORD *)(a3 + 352);
      a4 = v71;
      LODWORD(v74) = *(_DWORD *)(a3 + 340);
      HIDWORD(v74) = v36;
      v37 = *(_DWORD *)(a3 + 336);
      v38 = *(_DWORD *)(a3 + 324);
      *(_DWORD *)a2 = 2;
      *(_DWORD *)(a2 + 20) = v71 + 176;
      *(_QWORD *)(a2 + 32) = &v73;
      *(_QWORD *)(a2 + 12) = 0;
      *(_QWORD *)(a2 + 40) = 0x1000000000LL;
      v39 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
      v73 = __PAIR64__(v38, v37);
      if ( *((_DWORD *)v39 - 1) != -1839634494 )
        __break(0x822Au);
      v40 = v39(a2);
      if ( v40 )
      {
        v18 = v40;
        _drm_err("setting le phase failed ret %d\n", v40);
        goto LABEL_36;
      }
      v41 = *(_DWORD *)(a3 + 356);
      v42 = *(_DWORD *)(a3 + 416);
      *(_DWORD *)(a2 + 20) = v71 + 192;
      *(_QWORD *)(a2 + 12) = 0;
      *(_DWORD *)a2 = 2;
      *(_QWORD *)(a2 + 32) = &v73;
      *(_QWORD *)(a2 + 40) = 0x1000000000LL;
      LODWORD(v74) = v24 | (v21 << 16);
      HIDWORD(v74) = v42 << 16;
      v43 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
      LODWORD(v73) = v41;
      HIDWORD(v73) = v69 | (v70 << 16);
      if ( *((_DWORD *)v43 - 1) != -1839634494 )
        __break(0x822Au);
      v44 = v43(a2);
      if ( v44 )
      {
        v18 = v44;
        _drm_err("setting cac threshold failed ret %d\n", v44);
        goto LABEL_36;
      }
      v45 = *(_DWORD *)(a3 + 464);
      v46 = *(_DWORD *)(a3 + 420);
      *(_DWORD *)(a2 + 20) = v71 + 208;
      *(_DWORD *)a2 = 2;
      *(_QWORD *)(a2 + 12) = 0;
      LODWORD(v74) = v54 | (v28 << 16);
      HIDWORD(v74) = v45 << 16;
      *(_QWORD *)(a2 + 32) = &v73;
      *(_QWORD *)(a2 + 40) = 0x1000000000LL;
      v47 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
      LODWORD(v73) = v46 << 16;
      HIDWORD(v73) = v27 | (v25 << 16);
      if ( *((_DWORD *)v47 - 1) != -1839634494 )
        __break(0x822Au);
      v48 = v47(a2);
      if ( v48 )
      {
        v18 = v48;
        _drm_err("setting dst size failed ret %d\n", v48);
        goto LABEL_36;
      }
      *(_DWORD *)(a2 + 20) = v71 + 104;
      *(_DWORD *)a2 = 1;
      *(_QWORD *)(a2 + 12) = 0;
      *(_QWORD *)(a2 + 32) = a3 + 468;
      *(_QWORD *)(a2 + 40) = 0x400000000LL;
      v49 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
      if ( *((_DWORD *)v49 - 1) != -1839634494 )
        __break(0x8228u);
      v50 = v49(a2);
      if ( v50 )
      {
        v18 = v50;
        _drm_err("setting cac_asym_phase_step_h failed ret %d\n", v50);
        goto LABEL_36;
      }
      *(_DWORD *)a2 = 1;
      *(_DWORD *)(a2 + 20) = v71 + 108;
      *(_QWORD *)(a2 + 12) = 0;
      *(_QWORD *)(a2 + 32) = a3 + 472;
      *(_QWORD *)(a2 + 40) = 0x400000000LL;
      v51 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
      if ( *((_DWORD *)v51 - 1) != -1839634494 )
        __break(0x8228u);
      v52 = v51(a2);
      if ( v52 )
      {
        v18 = v52;
        _drm_err("setting cac_asym_phase_step_v failed ret %d\n", v52);
        goto LABEL_36;
      }
      v15 = (v56 << 29) | (v57 << 28) | (v58 << 30) | v65;
      v14 = (v55 << 29) | (v62 << 28) | (v61 << 30) | v67;
      v12 = (v63 << 29) | (v64 << 28) | v68;
      v13 = (v59 << 29) | (v60 << 28) | v66;
    }
    v74 = __PAIR64__(v15, v13);
    *(_DWORD *)a2 = 2;
    *(_DWORD *)(a2 + 20) = a4 + 16;
    *(_QWORD *)(a2 + 12) = 0;
    *(_QWORD *)(a2 + 32) = &v73;
    *(_QWORD *)(a2 + 40) = 0x1000000000LL;
    v16 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
    v73 = __PAIR64__(v14, v12);
    if ( *((_DWORD *)v16 - 1) != -1839634494 )
      __break(0x8228u);
    v17 = v16(a2);
    if ( v17 )
    {
      v18 = v17;
      _drm_err("setting phase failed ret %d\n", v17);
    }
    else
    {
      *(_QWORD *)(a2 + 12) = 0;
      *(_DWORD *)a2 = 1;
      *(_DWORD *)(a2 + 20) = a4 + 4;
      *(_QWORD *)(a2 + 32) = &v72;
      *(_QWORD *)(a2 + 40) = 0x400000000LL;
      v35 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
      if ( *((_DWORD *)v35 - 1) != -1839634494 )
        __break(0x8228u);
      v18 = v35(a2);
      if ( v18 )
        _drm_err("setting opmode failed ret %d\n", v18);
    }
  }
  else
  {
    _drm_err("invalid dma ops\n");
    v18 = -22;
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return v18;
}
