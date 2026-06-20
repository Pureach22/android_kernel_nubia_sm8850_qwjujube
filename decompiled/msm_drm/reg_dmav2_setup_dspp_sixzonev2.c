unsigned __int64 __fastcall reg_dmav2_setup_dspp_sixzonev2(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6)
{
  unsigned __int64 *v6; // x23
  __int64 *v7; // x24
  int v10; // w8
  unsigned __int64 result; // x0
  __int64 *v12; // x25
  unsigned __int64 v13; // x21
  __int64 v14; // x8
  __int64 v15; // x9
  unsigned __int64 *v16; // x8
  void (__fastcall *v17)(_QWORD); // x9
  unsigned __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x9
  __int64 (__fastcall *v21)(_QWORD); // x8
  int v22; // w0
  __int64 v23; // x22
  _WORD *v24; // x8
  __int64 v25; // x9
  __int64 v26; // x10
  __int64 v27; // x11
  unsigned int v28; // w12
  __int64 (__fastcall *v29)(_QWORD); // x9
  unsigned int v30; // w0
  __int64 v31; // x8
  __int64 v32; // x8
  __int64 (__fastcall *v33)(_QWORD); // x8
  unsigned int v34; // w0
  __int64 v35; // x8
  __int64 v36; // x8
  __int64 (__fastcall *v37)(_QWORD); // x8
  unsigned int v38; // w0
  __int64 v39; // x8
  __int64 v40; // x8
  __int64 (__fastcall *v41)(_QWORD); // x8
  unsigned int v42; // w0
  __int64 v43; // x8
  __int64 v44; // x8
  __int64 (__fastcall *v45)(_QWORD); // x8
  unsigned int v46; // w0
  __int64 v47; // x8
  __int64 (__fastcall *v48)(_QWORD); // x9
  unsigned int v49; // w0
  __int64 v50; // x8
  __int64 (__fastcall *v51)(_QWORD); // x9
  unsigned int v52; // w0
  __int64 v53; // x8
  int v54; // w9
  __int64 v55; // x26
  __int64 v56; // x8
  unsigned int v57; // w9
  __int64 v58; // x8
  __int64 v59; // x9
  __int64 (__fastcall *v60)(_QWORD); // x8
  unsigned int v61; // w0
  __int64 v62; // x8
  __int64 (__fastcall *v63)(_QWORD); // x8
  unsigned int v64; // w0
  __int64 v65; // x8
  __int64 (__fastcall *v66)(_QWORD); // x8
  unsigned int v67; // w0
  unsigned __int64 StatusReg; // x26
  __int64 v69; // x27
  unsigned int v70; // [xsp+Ch] [xbp-84h] BYREF
  __int64 v71; // [xsp+10h] [xbp-80h] BYREF
  __int64 v72; // [xsp+18h] [xbp-78h] BYREF
  __int64 v73; // [xsp+20h] [xbp-70h] BYREF
  __int128 v74; // [xsp+28h] [xbp-68h]
  unsigned __int64 v75; // [xsp+38h] [xbp-58h]
  char *v76; // [xsp+40h] [xbp-50h]
  __int64 v77; // [xsp+48h] [xbp-48h]
  __int64 v78; // [xsp+50h] [xbp-40h]
  __int64 v79; // [xsp+58h] [xbp-38h]
  _QWORD v80[6]; // [xsp+60h] [xbp-30h] BYREF

  v80[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *((_DWORD *)a2 + 40);
  v78 = 0;
  v79 = 0;
  v76 = nullptr;
  v77 = 0;
  v75 = 0;
  v73 = 0;
  v74 = 0u;
  *((_DWORD *)a2 + 40) = v10 & 0xFF0F0FFF | 0x2000;
  memset(v80, 0, 40);
  v71 = 0;
  v72 = 0;
  v70 = 0;
  *((_DWORD *)a2 + 42) = 2;
  result = reg_dma_validate_sixzone_config(a1, a2, &v71, &v70, v80, a3, a4, a5, a6);
  if ( (_DWORD)result )
    goto LABEL_2;
  v12 = (__int64 *)*a2;
  *((_DWORD *)a2 + 42) |= 1u;
  result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
  if ( !result )
    goto LABEL_2;
  v13 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_2;
  v14 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v14 >= 5 )
    goto LABEL_80;
  v15 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v15 > 1 )
    goto LABEL_80;
  if ( (unsigned __int64)(16 * v14 + 8 * v15 + 720) > 0x7D0 )
    goto LABEL_81;
  v6 = dspp_buf;
  v16 = &dspp_buf[2 * v14 + v15];
  v17 = *(void (__fastcall **)(_QWORD))(result + 64);
  v18 = v16[90];
  if ( *((_DWORD *)v17 - 1) != -870478129 )
    __break(0x8229u);
  v17(v18);
  v19 = *(unsigned int *)(a1 + 64);
  LODWORD(v73) = 0;
  v75 = 0;
  v76 = nullptr;
  v77 = 0;
  v78 = 0;
  v79 = 0;
  HIDWORD(v73) = v70;
  v74 = 9u;
  if ( (unsigned int)v19 > 4 )
    goto LABEL_80;
  v20 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v20 > 1 )
    goto LABEL_80;
  if ( (unsigned __int64)(16 * v19 + 8 * v20 + 720) > 0x7D0 )
    goto LABEL_81;
  HIDWORD(v74) = 0;
  DWORD1(v74) = 0;
  v7 = &v73;
  v77 = 0;
  v75 = dspp_buf[2 * v19 + 90 + v20];
  v76 = nullptr;
  v21 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8);
  if ( *((_DWORD *)v21 - 1) != -1839634494 )
    __break(0x8228u);
  v22 = v21(&v73);
  if ( v22 )
  {
    result = _drm_err("write decode select for sixzone failed ret %d\n", v22);
    goto LABEL_2;
  }
  v23 = _kvmalloc_node_noprof(3840, 0, 3520, 0xFFFFFFFFLL);
  if ( !v23 )
  {
LABEL_82:
    result = _drm_err("Allocating memory for sixzone data failed!");
    goto LABEL_2;
  }
  while ( 1 )
  {
    v24 = (_WORD *)(v23 + 4);
    v25 = 28;
    v26 = 777;
    do
    {
      v27 = (__int64)v12 + v25;
      v25 += 8;
      *(v24 - 2) = 16 * *(_WORD *)(v27 + 4);
      *(v24 - 1) = (*(_DWORD *)v27 >> 12) & 0xFFF0;
      *v24 = 16 * *((_WORD *)v12 + 2 * v26);
      v28 = *((_DWORD *)v12 + v26++);
      v24[1] = (v28 >> 12) & 0xFFF0;
      v24[2] = 16 * *(_WORD *)v27;
      v24 += 5;
    }
    while ( v26 != 1161 );
    HIDWORD(v74) = 0;
    v76 = (char *)v23;
    v77 = 0xF0000000000LL;
    *(_QWORD *)((char *)&v74 + 4) = 0;
    v78 = 0x300000000LL;
    v79 = 0xC000000005LL;
    v29 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8);
    LODWORD(v73) = 6;
    if ( *((_DWORD *)v29 - 1) != -1839634494 )
      __break(0x8229u);
    v30 = v29(&v73);
    if ( v30 )
    {
      _drm_err("lut write for sixzone failed ret %d\n", v30);
      goto LABEL_50;
    }
    v31 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)((char *)&v74 + 4) = 0;
    v32 = *(_QWORD *)(v31 + 48);
    v76 = (char *)(v12 + 1);
    v77 = 0x400000000LL;
    LODWORD(v73) = 1;
    HIDWORD(v74) = *(_DWORD *)(v32 + 200) + 8;
    v33 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8);
    if ( *((_DWORD *)v33 - 1) != -1839634494 )
      __break(0x8228u);
    v34 = v33(&v73);
    if ( v34 )
    {
      _drm_err("write sixzone threshold failed ret %d\n", v34);
      goto LABEL_50;
    }
    v35 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)((char *)&v74 + 4) = 0;
    v76 = (char *)v12 + 12;
    v77 = 0x400000000LL;
    v36 = *(_QWORD *)(v35 + 48);
    LODWORD(v73) = 1;
    HIDWORD(v74) = *(_DWORD *)(v36 + 200) + 12;
    v37 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8);
    if ( *((_DWORD *)v37 - 1) != -1839634494 )
      __break(0x8228u);
    v38 = v37(&v73);
    if ( v38 )
    {
      _drm_err("write sixzone adjust p0 failed ret %d\n", v38);
      goto LABEL_50;
    }
    v39 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)((char *)&v74 + 4) = 0;
    v76 = (char *)(v12 + 2);
    v77 = 0x400000000LL;
    v40 = *(_QWORD *)(v39 + 48);
    LODWORD(v73) = 1;
    HIDWORD(v74) = *(_DWORD *)(v40 + 200) + 16;
    v41 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8);
    if ( *((_DWORD *)v41 - 1) != -1839634494 )
      __break(0x8228u);
    v42 = v41(&v73);
    if ( v42 )
    {
      _drm_err("write sixzone adjust p1 failed ret %d\n", v42);
      goto LABEL_50;
    }
    v43 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)((char *)&v74 + 4) = 0;
    v76 = (char *)v12 + 3100;
    v77 = 0x400000000LL;
    v44 = *(_QWORD *)(v43 + 48);
    LODWORD(v73) = 1;
    HIDWORD(v74) = *(_DWORD *)(v44 + 200) + 20;
    v45 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8);
    if ( *((_DWORD *)v45 - 1) != -1839634494 )
      __break(0x8228u);
    v46 = v45(&v73);
    if ( v46 )
    {
      _drm_err("write sixzone saturation adjust p0 failed ret %d\n", v46);
      goto LABEL_50;
    }
    v47 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)((char *)&v74 + 4) = 0;
    HIDWORD(v74) = *(_DWORD *)(*(_QWORD *)(v47 + 48) + 200LL) + 24;
    v76 = (char *)(v12 + 388);
    v77 = 0x400000000LL;
    v48 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8);
    LODWORD(v73) = 1;
    if ( *((_DWORD *)v48 - 1) != -1839634494 )
      __break(0x8229u);
    v49 = v48(&v73);
    if ( v49 )
    {
      _drm_err("write sixzone saturation adjust p1 failed ret %d\n", v49);
      goto LABEL_50;
    }
    if ( (*(_BYTE *)v12 & 8) != 0 )
      HIDWORD(v71) |= 1u;
    v50 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)((char *)&v74 + 4) = 0;
    HIDWORD(v74) = *(_DWORD *)(*(_QWORD *)(v50 + 48) + 200LL) + 32;
    v76 = (char *)&v71 + 4;
    v77 = 0x400000000LL;
    v51 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8);
    LODWORD(v73) = 1;
    if ( *((_DWORD *)v51 - 1) != -1839634494 )
      __break(0x8229u);
    v52 = v51(&v73);
    if ( v52 )
    {
      _drm_err("sv enable write failed for sixzone ret %d\n", v52);
      goto LABEL_50;
    }
    v53 = *v12;
    LODWORD(v72) = ((*((_WORD *)v12 + 10) & 3) << 12) & 0x3FFF | ((v12[3] & 3) << 14);
    if ( (v53 & 1) != 0 )
    {
      HIDWORD(v72) |= 0x20000000u;
      if ( (v53 & 2) == 0 )
      {
LABEL_53:
        v54 = HIDWORD(v72);
        if ( (v53 & 4) != 0 )
          goto LABEL_58;
        goto LABEL_54;
      }
    }
    else if ( (v53 & 2) == 0 )
    {
      goto LABEL_53;
    }
    HIDWORD(v72) |= 0x40000000u;
    v54 = HIDWORD(v72);
    if ( (v53 & 4) != 0 )
    {
LABEL_58:
      v54 |= 0x80000000;
      goto LABEL_59;
    }
LABEL_54:
    if ( !v54 )
    {
      _drm_err("Invalid six zone config 0x%x\n", 0);
      goto LABEL_50;
    }
LABEL_59:
    HIDWORD(v72) = v54 | 0x100000;
    if ( !(_DWORD)v71 )
      break;
    v12 = nullptr;
    v55 = 8LL * (unsigned int)v71;
    while ( v12 != &qword_28 )
    {
      v56 = *(unsigned int *)(*(_QWORD *)((char *)v80 + (_QWORD)v12) + 64LL);
      if ( (unsigned int)v56 > 4 )
        break;
      v73 = 0;
      v74 = 0u;
      v57 = dspp_mapping[v56];
      v58 = *(unsigned int *)(a1 + 64);
      v75 = 0;
      v76 = nullptr;
      v77 = 0;
      v78 = 0;
      v79 = 0;
      HIDWORD(v73) = v57;
      LODWORD(v74) = 9;
      if ( (unsigned int)v58 > 4 )
        break;
      v59 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v59 > 1 )
        break;
      if ( (unsigned __int64)(16 * v58 + 8 * v59 + 720) > 0x7D0 )
        goto LABEL_81;
      HIDWORD(v74) = 0;
      DWORD1(v74) = 0;
      v7[4] = 0;
      v7[5] = 0;
      v75 = v6[2 * v58 + 90 + v59];
      v60 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8);
      if ( *((_DWORD *)v60 - 1) != -1839634494 )
        __break(0x8228u);
      v61 = v60(&v73);
      if ( v61 )
      {
        _drm_err("write decode select failed for sixzone ret %d\n", v61);
        goto LABEL_50;
      }
      v62 = *(_QWORD *)(a1 + 72);
      *(_QWORD *)((char *)&v74 + 4) = 0;
      LODWORD(v73) = 5;
      HIDWORD(v74) = *(_DWORD *)(*(_QWORD *)(v62 + 48) + 128LL) + 64;
      v76 = (char *)&v72;
      v77 = 0x400000FFFLL;
      v63 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8);
      if ( *((_DWORD *)v63 - 1) != -1839634494 )
        __break(0x8228u);
      v64 = v63(&v73);
      if ( v64 )
      {
        _drm_err("setting local_hold failed for sixzone ret %d\n", v64);
        goto LABEL_50;
      }
      v65 = *(_QWORD *)(a1 + 72);
      *(_QWORD *)((char *)&v74 + 4) = 0;
      LODWORD(v73) = 5;
      HIDWORD(v74) = *(_DWORD *)(*(_QWORD *)(v65 + 48) + 128LL);
      v76 = (char *)&v72 + 4;
      v77 = 0x41FEFFFFFLL;
      v66 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8);
      if ( *((_DWORD *)v66 - 1) != -1839634494 )
        __break(0x8228u);
      v67 = v66(&v73);
      if ( v67 )
      {
        _drm_err("setting local_opcode failed for sixzone ret %d\n", v67);
        goto LABEL_50;
      }
      if ( (__int64 *)v55 == ++v12 )
        goto LABEL_76;
    }
LABEL_80:
    __break(0x5512u);
LABEL_81:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v69 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &reg_dmav2_setup_dspp_sixzonev2__alloc_tag;
    v23 = _kvmalloc_node_noprof(3840, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v69;
    if ( !v23 )
      goto LABEL_82;
  }
LABEL_76:
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "reg_dmav2_setup_dspp_sixzonev2",
    2837,
    -1,
    *(_DWORD *)(a1 + 64),
    *(_DWORD *)(a1 + 1496),
    *(_DWORD *)(a1 + 28),
    1,
    239);
  ((void (__fastcall *)(__int64, __int64 *, unsigned __int64, _QWORD, __int64))perform_sbdma_kickoff)(
    a1,
    a2,
    v13,
    v70,
    9);
LABEL_50:
  result = kvfree(v23);
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
