size_t __fastcall reg_dmav1_setup_dspp_sixzonev17(__int64 a1, __int64 **a2)
{
  size_t result; // x0
  __int64 *v5; // x25
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x4
  size_t v10; // x21
  __int64 v11; // x8
  __int64 v12; // x9
  unsigned __int64 *v13; // x8
  __int64 (__fastcall *v14)(_QWORD); // x9
  unsigned __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 (__fastcall *v18)(_QWORD); // x8
  unsigned int v19; // w0
  __int64 v20; // x8
  __int64 (__fastcall *v21)(_QWORD); // x9
  unsigned int v22; // w0
  __int64 v23; // x8
  __int64 (__fastcall *v24)(_QWORD); // x9
  unsigned int v25; // w0
  __int64 v26; // x8
  __int64 (__fastcall *v27)(_QWORD); // x8
  __int64 v28; // x9
  int v29; // w8
  unsigned int v30; // w8
  __int64 v31; // x25
  __int64 v32; // x26
  __int64 v33; // x8
  unsigned int v34; // w9
  __int64 v35; // x8
  __int64 v36; // x9
  __int64 (__fastcall *v37)(_QWORD); // x8
  __int64 v38; // x8
  __int64 (__fastcall *v39)(_QWORD); // x8
  unsigned int v40; // w0
  __int64 v41; // x8
  __int64 (__fastcall *v42)(_QWORD); // x8
  __int64 *v43; // x8
  __int64 v44; // x5
  __int64 *v45; // x9
  int v46; // w6
  __int64 v47; // x10
  unsigned __int64 v48; // x8
  __int64 v49; // x8
  __int64 (__fastcall *v50)(__int64 **, __int64); // x8
  __int64 v51; // x1
  unsigned int v52; // [xsp+14h] [xbp-DCh] BYREF
  __int64 v53; // [xsp+18h] [xbp-D8h] BYREF
  __int64 v54; // [xsp+20h] [xbp-D0h] BYREF
  __int64 v55; // [xsp+28h] [xbp-C8h] BYREF
  __int128 v56; // [xsp+30h] [xbp-C0h]
  unsigned __int64 v57; // [xsp+40h] [xbp-B0h]
  char *v58; // [xsp+48h] [xbp-A8h]
  __int64 v59; // [xsp+50h] [xbp-A0h]
  __int64 v60; // [xsp+58h] [xbp-98h]
  __int64 v61; // [xsp+60h] [xbp-90h]
  __int64 *v62; // [xsp+68h] [xbp-88h] BYREF
  __int64 v63; // [xsp+70h] [xbp-80h]
  unsigned __int64 v64; // [xsp+78h] [xbp-78h]
  __int64 v65; // [xsp+80h] [xbp-70h]
  __int64 v66; // [xsp+88h] [xbp-68h]
  __int64 v67; // [xsp+90h] [xbp-60h]
  __int64 *v68; // [xsp+98h] [xbp-58h]
  __int128 v69; // [xsp+A0h] [xbp-50h]
  unsigned __int64 v70; // [xsp+B0h] [xbp-40h]
  _BYTE v71[40]; // [xsp+B8h] [xbp-38h] BYREF
  __int64 v72; // [xsp+E0h] [xbp-10h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v70 = 0;
  v68 = nullptr;
  v69 = 0u;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = nullptr;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v58 = nullptr;
  v59 = 0;
  v57 = 0;
  v55 = 0;
  v56 = 0u;
  memset(v71, 0, sizeof(v71));
  v53 = 0;
  v54 = 0;
  v52 = 0;
  result = reg_dma_validate_sixzone_config(a1, a2, &v53, &v52, v71);
  if ( (_DWORD)result )
    goto LABEL_28;
  v5 = *a2;
  result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
  if ( !result )
    goto LABEL_28;
  v10 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_28;
  v11 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v11 >= 5 )
    goto LABEL_64;
  v12 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v12 > 1 )
    goto LABEL_64;
  if ( (unsigned __int64)(16 * v11 + 8 * v12 + 720) <= 0x7D0 )
  {
    v13 = &dspp_buf[2 * v11 + v12];
    v14 = *(__int64 (__fastcall **)(_QWORD))(result + 64);
    v15 = v13[90];
    if ( *((_DWORD *)v14 - 1) != -870478129 )
      __break(0x8229u);
    result = v14(v15);
    v16 = *(unsigned int *)(a1 + 64);
    LODWORD(v55) = 0;
    v57 = 0;
    v58 = nullptr;
    v59 = 0;
    v60 = 0;
    v61 = 0;
    HIDWORD(v55) = v52;
    v56 = 9u;
    if ( (unsigned int)v16 > 4 )
      goto LABEL_64;
    v17 = *(unsigned int *)(a1 + 1496);
    if ( (unsigned int)v17 > 1 )
      goto LABEL_64;
    if ( (unsigned __int64)(16 * v16 + 8 * v17 + 720) > 0x7D0 )
      goto LABEL_65;
    HIDWORD(v56) = 0;
    DWORD1(v56) = 0;
    v59 = 0;
    v57 = dspp_buf[2 * v16 + 90 + v17];
    v58 = nullptr;
    v18 = *(__int64 (__fastcall **)(_QWORD))(v10 + 8);
    if ( *((_DWORD *)v18 - 1) != -1839634494 )
      __break(0x8228u);
    v19 = v18(&v55);
    if ( v19 )
    {
LABEL_15:
      result = _drm_err("write decode select failed ret %d\n", v19);
LABEL_28:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v20 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)((char *)&v56 + 4) = 0;
    HIDWORD(v56) = *(_DWORD *)(*(_QWORD *)(v20 + 48) + 200LL);
    v58 = (char *)&v54 + 4;
    v59 = 0x400000000LL;
    v21 = *(__int64 (__fastcall **)(_QWORD))(v10 + 8);
    HIDWORD(v54) = 0x4000000;
    LODWORD(v55) = 1;
    if ( *((_DWORD *)v21 - 1) != -1839634494 )
      __break(0x8229u);
    v22 = v21(&v55);
    if ( v22 )
    {
      result = _drm_err("setting lut index failed ret %d\n", v22);
      goto LABEL_28;
    }
    v23 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)((char *)&v56 + 4) = 2;
    HIDWORD(v56) = *(_DWORD *)(*(_QWORD *)(v23 + 48) + 200LL) + 4;
    v58 = (char *)v5 + 28;
    v59 = 0xC0000000000LL;
    v24 = *(__int64 (__fastcall **)(_QWORD))(v10 + 8);
    LODWORD(v55) = 4;
    if ( *((_DWORD *)v24 - 1) != -1839634494 )
      __break(0x8229u);
    v25 = v24(&v55);
    if ( v25 )
    {
      result = _drm_err("write sixzone lut failed ret %d\n", v25);
      goto LABEL_28;
    }
    v26 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)((char *)&v56 + 4) = 0;
    LODWORD(v55) = 2;
    HIDWORD(v56) = *(_DWORD *)(*(_QWORD *)(v26 + 48) + 200LL) + 8;
    v58 = (char *)(v5 + 1);
    v59 = 0xC00000000LL;
    v27 = *(__int64 (__fastcall **)(_QWORD))(v10 + 8);
    if ( *((_DWORD *)v27 - 1) != -1839634494 )
      __break(0x8228u);
    result = v27(&v55);
    if ( (_DWORD)result )
    {
      result = _drm_err("write sixzone threshold failed ret %d\n", (unsigned int)result);
      goto LABEL_28;
    }
    v28 = *v5;
    HIDWORD(v53) = ((*((_WORD *)v5 + 10) & 3) << 12) & 0x3FFF | ((v5[3] & 3) << 14);
    if ( (v28 & 1) != 0 )
    {
      v29 = 0x20000000;
      LODWORD(v54) = 0x20000000;
    }
    else
    {
      v29 = 0;
    }
    v30 = v29 & 0xBFFFFFFF | ((((unsigned int)v28 >> 1) & 1) << 30);
    if ( (v28 & 4) != 0 )
    {
      v30 |= 0x80000000;
    }
    else if ( !v30 )
    {
      result = _drm_err("Invalid six zone config 0x%x\n", 0);
      goto LABEL_28;
    }
    LODWORD(v54) = v30 | 0x100000;
    if ( (_DWORD)v53 )
    {
      v31 = 0;
      v32 = 8LL * (unsigned int)v53;
      while ( v31 != 40 )
      {
        v33 = *(unsigned int *)(*(_QWORD *)&v71[v31] + 64LL);
        if ( (unsigned int)v33 > 4 )
          break;
        v55 = 0;
        v56 = 0u;
        v34 = dspp_mapping[v33];
        v35 = *(unsigned int *)(a1 + 64);
        v57 = 0;
        v58 = nullptr;
        v59 = 0;
        v52 = v34;
        v60 = 0;
        v61 = 0;
        HIDWORD(v55) = v34;
        LODWORD(v56) = 9;
        if ( (unsigned int)v35 > 4 )
          break;
        v36 = *(unsigned int *)(a1 + 1496);
        if ( (unsigned int)v36 > 1 )
          break;
        if ( (unsigned __int64)(16 * v35 + 8 * v36 + 720) > 0x7D0 )
          goto LABEL_65;
        HIDWORD(v56) = 0;
        DWORD1(v56) = 0;
        v58 = nullptr;
        v59 = 0;
        v57 = dspp_buf[2 * v35 + 90 + v36];
        v37 = *(__int64 (__fastcall **)(_QWORD))(v10 + 8);
        if ( *((_DWORD *)v37 - 1) != -1839634494 )
          __break(0x8228u);
        v19 = v37(&v55);
        if ( v19 )
          goto LABEL_15;
        v38 = *(_QWORD *)(a1 + 72);
        *(_QWORD *)((char *)&v56 + 4) = 0;
        LODWORD(v55) = 5;
        HIDWORD(v56) = *(_DWORD *)(*(_QWORD *)(v38 + 48) + 128LL) + 64;
        v58 = (char *)&v53 + 4;
        v59 = 0x400000FFFLL;
        v39 = *(__int64 (__fastcall **)(_QWORD))(v10 + 8);
        if ( *((_DWORD *)v39 - 1) != -1839634494 )
          __break(0x8228u);
        v40 = v39(&v55);
        if ( v40 )
        {
          result = _drm_err("setting local_hold failed ret %d\n", v40);
          goto LABEL_28;
        }
        v41 = *(_QWORD *)(a1 + 72);
        *(_QWORD *)((char *)&v56 + 4) = 0;
        LODWORD(v55) = 5;
        HIDWORD(v56) = *(_DWORD *)(*(_QWORD *)(v41 + 48) + 128LL);
        v58 = (char *)&v54;
        v59 = 0x41FEFFFFFLL;
        v42 = *(__int64 (__fastcall **)(_QWORD))(v10 + 8);
        if ( *((_DWORD *)v42 - 1) != -1839634494 )
          __break(0x8228u);
        result = v42(&v55);
        if ( (_DWORD)result )
        {
          result = _drm_err("setting local_opcode failed ret %d\n", (unsigned int)result);
          goto LABEL_28;
        }
        v31 += 8;
        if ( v32 == v31 )
          goto LABEL_53;
      }
      goto LABEL_64;
    }
LABEL_53:
    v9 = *(unsigned int *)(a1 + 64);
    v43 = a2[2];
    v66 = 0;
    v67 = 0;
    v64 = 0;
    v65 = 0;
    v62 = v43;
    v63 = 0;
    if ( (unsigned int)v9 > 4 || (v44 = *(unsigned int *)(a1 + 1496), (unsigned int)v44 > 1) )
    {
LABEL_64:
      __break(0x5512u);
      goto LABEL_65;
    }
    if ( (unsigned __int64)(16 * v9 + 8 * v44 + 720) <= 0x7D0 )
    {
      LODWORD(v63) = 1;
      v45 = a2[19];
      v46 = *(_DWORD *)(a1 + 28);
      LODWORD(v67) = 9;
      v47 = *(__int64 *)((char *)a2 + 164);
      v68 = v45;
      v48 = dspp_buf[2 * v9 + 90 + v44];
      *(_QWORD *)((char *)&v69 + 4) = v47;
      LODWORD(v45) = *((_DWORD *)a2 + 43);
      LODWORD(v47) = *((_DWORD *)a2 + 44);
      v64 = v48;
      LODWORD(v48) = *((_DWORD *)a2 + 40);
      LODWORD(v66) = 0;
      v70 = __PAIR64__(v47, (unsigned int)v45);
      LODWORD(v45) = *((_DWORD *)a2 + 7);
      LODWORD(v69) = v48;
      HIDWORD(v69) = (_DWORD)v45;
      result = sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_dspp_sixzonev17", 2633, -1, v9, v44, v46, 1, 239);
      v49 = *(unsigned int *)(a1 + 28);
      if ( (unsigned int)v49 <= 2 )
      {
        v50 = *(__int64 (__fastcall **)(__int64 **, __int64))(v10 + 8 * v49 + 16);
        if ( v50 )
        {
          v51 = *(unsigned int *)(a1 + 1496);
          if ( *((_DWORD *)v50 - 1) != 1772228465 )
            __break(0x8228u);
          result = v50(&v62, v51);
          if ( (_DWORD)result )
            result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
        }
        goto LABEL_28;
      }
      goto LABEL_64;
    }
  }
LABEL_65:
  __break(1u);
  return reg_dma_validate_sixzone_config(result, v6, v7, v8, v9);
}
