size_t __fastcall reg_dmav1_setup_demura_cfg0_param2_v4(__int64 a1, unsigned int **a2)
{
  int v2; // w27
  __int64 v4; // x8
  int v5; // w22
  __int64 v6; // x8
  int v7; // w21
  __int64 v8; // x4
  unsigned int v9; // w5
  unsigned int *v10; // x26
  int v11; // w8
  size_t result; // x0
  __int64 v14; // x20
  __int64 v15; // x8
  __int64 v16; // x9
  unsigned __int64 *v17; // x8
  void (__fastcall *v18)(_QWORD); // x9
  unsigned __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 (__fastcall *v22)(_QWORD); // x8
  int v23; // w0
  __int64 (__fastcall *v24)(_QWORD); // x9
  int v25; // w0
  __int64 v26; // x21
  unsigned int v27; // w23
  __int64 (__fastcall *v28)(_QWORD); // x9
  int v29; // w0
  __int64 v30; // x4
  unsigned int *v31; // x8
  __int64 v32; // x5
  unsigned int *v33; // x10
  __int64 v34; // x6
  int v35; // w8
  __int64 v36; // x10
  unsigned __int64 v37; // x8
  unsigned int v38; // w9
  _DWORD *v39; // x8
  int v40; // w0
  unsigned __int64 StatusReg; // x23
  __int64 v42; // x28
  int v43; // [xsp+Ch] [xbp-A4h] BYREF
  unsigned int *v44; // [xsp+10h] [xbp-A0h] BYREF
  __int64 v45; // [xsp+18h] [xbp-98h]
  unsigned __int64 v46; // [xsp+20h] [xbp-90h]
  __int64 v47; // [xsp+28h] [xbp-88h]
  __int64 v48; // [xsp+30h] [xbp-80h]
  __int64 v49; // [xsp+38h] [xbp-78h]
  unsigned int *v50; // [xsp+40h] [xbp-70h]
  __int128 v51; // [xsp+48h] [xbp-68h]
  unsigned __int64 v52; // [xsp+58h] [xbp-58h]
  unsigned __int64 v53; // [xsp+60h] [xbp-50h] BYREF
  __int128 v54; // [xsp+68h] [xbp-48h]
  unsigned __int64 v55; // [xsp+78h] [xbp-38h]
  int *v56; // [xsp+80h] [xbp-30h]
  __int64 v57; // [xsp+88h] [xbp-28h]
  __int64 v58; // [xsp+90h] [xbp-20h]
  __int64 v59; // [xsp+98h] [xbp-18h]
  __int64 v60; // [xsp+A0h] [xbp-10h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 72);
  v58 = 0;
  v59 = 0;
  v5 = *(_DWORD *)(a1 + 8);
  v52 = 0;
  v50 = nullptr;
  v51 = 0u;
  v6 = *(_QWORD *)(v4 + 48);
  v56 = nullptr;
  v57 = 0;
  v55 = 0;
  v7 = *(_DWORD *)(v6 + 568);
  v53 = 0;
  v54 = 0u;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = nullptr;
  v45 = 0;
  v43 = 3;
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid cfg %pK ctx %pK\n", a2, (const void *)a1);
    goto LABEL_28;
  }
  v8 = *(unsigned int *)(a1 + 64);
  v9 = *(_DWORD *)(a1 + 1496);
  if ( !a2[2] || (unsigned int)v8 > 4 || v9 >= 2 )
  {
    result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", a2[2], v8, 21, v9);
    goto LABEL_28;
  }
  if ( &dspp_buf[2 * v8] == (unsigned __int64 *)-1680LL )
  {
    result = _drm_err("invalid dma_buf\n");
    goto LABEL_28;
  }
  v10 = *a2;
  if ( !*a2 )
  {
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "reg_dmav1_setup_demura_cfg0_param2_v4",
               8424,
               -1,
               v8,
               v9,
               *(_DWORD *)(a1 + 28),
               0,
               239);
    goto LABEL_28;
  }
  v11 = *((_DWORD *)a2 + 2);
  if ( v11 != 6152 )
  {
    result = _drm_err("invalid sz of payload len %d exp %zd\n", v11, 0x1808u);
    goto LABEL_28;
  }
  result = sde_reg_dma_get_ops(v9);
  if ( result )
  {
    v14 = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      v15 = *(unsigned int *)(a1 + 64);
      if ( (unsigned int)v15 >= 5 )
        goto LABEL_50;
      v16 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v16 > 1 )
        goto LABEL_50;
      if ( (unsigned __int64)(16 * v15 + 8 * v16 + 1680) > 0x7CF )
        goto LABEL_51;
      v17 = &dspp_buf[2 * v15 + v16];
      v18 = *(void (__fastcall **)(_QWORD))(result + 64);
      v19 = v17[210];
      if ( *((_DWORD *)v18 - 1) != -870478129 )
        __break(0x8229u);
      v18(v19);
      v20 = *(unsigned int *)(a1 + 64);
      v53 = 0x8000000000000000LL;
      v54 = 0x15u;
      v55 = 0;
      v56 = nullptr;
      v57 = 0;
      v58 = 0;
      v59 = 0;
      if ( (unsigned int)v20 > 4 )
        goto LABEL_50;
      v21 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v21 > 1 )
        goto LABEL_50;
      if ( (unsigned __int64)(16 * v20 + 8 * v21 + 1680) > 0x7CF )
        goto LABEL_51;
      HIDWORD(v54) = 0;
      DWORD1(v54) = 0;
      v57 = 0;
      v55 = dspp_buf[2 * v20 + 210 + v21];
      v56 = nullptr;
      v22 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
      if ( *((_DWORD *)v22 - 1) != -1839634494 )
        __break(0x8228u);
      v23 = v22(&v53);
      if ( v23 )
      {
        result = _drm_err("write decode select failed ret %d\n", v23);
        goto LABEL_28;
      }
      v5 += v7;
      v2 = v5 + 116;
      *(_QWORD *)((char *)&v54 + 4) = 0;
      HIDWORD(v54) = v5 + 116;
      v56 = &v43;
      v57 = 0x4FFFFFFFDLL;
      v24 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
      LODWORD(v53) = 5;
      if ( *((_DWORD *)v24 - 1) != -1839634494 )
        __break(0x8229u);
      v25 = v24(&v53);
      if ( v25 )
      {
        result = _drm_err("0x74: REG_SINGLE_MODIFY err %d len %zd buf idx %d\n", v25, 4u, *(_DWORD *)(v55 + 20));
        goto LABEL_28;
      }
      result = _kvmalloc_node_noprof(6152, 0, 3520, 0xFFFFFFFFLL);
      v26 = result;
      if ( !result )
        goto LABEL_28;
      while ( 1 )
      {
        v27 = *v10;
        _reg_dmav1_setup_demurav1_cfg0_c_params_cmn((__int64)&v53, v14, (__int64)(v10 + 2), *v10, v26, 0, v5);
        _reg_dmav1_setup_demurav1_cfg0_c_params_cmn((__int64)&v53, v14, (__int64)(v10 + 514), v27, v26, 1, v5);
        _reg_dmav1_setup_demurav1_cfg0_c_params_cmn((__int64)&v53, v14, (__int64)(v10 + 1026), v27, v26, 2, v5);
        HIDWORD(v54) = v2;
        *(_QWORD *)((char *)&v54 + 4) = 0;
        v56 = &v43;
        v57 = 0x4FFFFFFFELL;
        v28 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
        LODWORD(v53) = 5;
        if ( *((_DWORD *)v28 - 1) != -1839634494 )
          __break(0x8229u);
        v29 = v28(&v53);
        if ( v29 )
        {
          _drm_err("0x74: REG_SINGLE_MODIFY err %d len %zd buf idx %d\n", v29, 4u, *(_DWORD *)(v55 + 20));
          goto LABEL_49;
        }
        v30 = *(unsigned int *)(a1 + 64);
        v31 = a2[2];
        v48 = 0;
        v49 = 0;
        v46 = 0;
        v47 = 0;
        v44 = v31;
        v45 = 0;
        if ( (unsigned int)v30 > 4 )
          goto LABEL_50;
        v32 = *(unsigned int *)(a1 + 1496);
        if ( (unsigned int)v32 > 1 )
          goto LABEL_50;
        if ( (unsigned __int64)(16 * v30 + 8 * v32 + 1680) <= 0x7CF )
          break;
LABEL_51:
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v42 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &reg_dmav1_setup_demura_cfg0_param2_v4__alloc_tag;
        result = _kvmalloc_node_noprof(6152, 0, 3520, 0xFFFFFFFFLL);
        v26 = result;
        *(_QWORD *)(StatusReg + 80) = v42;
        if ( !result )
          goto LABEL_28;
      }
      v33 = a2[19];
      LODWORD(v45) = 1;
      v34 = *(unsigned int *)(a1 + 28);
      LODWORD(v49) = 21;
      v35 = *((_DWORD *)a2 + 40);
      v50 = v33;
      v36 = *(__int64 *)((char *)a2 + 164);
      LODWORD(v51) = v35;
      v37 = dspp_buf[2 * v30 + 210 + v32];
      *(_QWORD *)((char *)&v51 + 4) = v36;
      LODWORD(v36) = *((_DWORD *)a2 + 43);
      v38 = *((_DWORD *)a2 + 44);
      v46 = v37;
      LODWORD(v37) = *((_DWORD *)a2 + 7);
      LODWORD(v48) = 0;
      v52 = __PAIR64__(v38, v36);
      HIDWORD(v51) = v37;
      if ( (unsigned int)v34 <= 2 )
      {
        v39 = *(_DWORD **)(v14 + 8 * v34 + 16);
        if ( v39 )
        {
          if ( *(v39 - 1) != 1772228465 )
            __break(0x8228u);
          v40 = ((__int64 (__fastcall *)(unsigned int **, _QWORD))v39)(&v44, (unsigned int)v32);
          if ( v40 )
          {
            _drm_err("failed to kick off ret %d\n", v40);
            goto LABEL_49;
          }
          LODWORD(v30) = *(_DWORD *)(a1 + 64);
          LODWORD(v32) = *(_DWORD *)(a1 + 1496);
          LODWORD(v34) = *(_DWORD *)(a1 + 28);
        }
        sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_demura_cfg0_param2_v4", 8498, -1, v30, v32, v34, 1, 239);
LABEL_49:
        result = kvfree(v26);
        goto LABEL_28;
      }
LABEL_50:
      __break(0x5512u);
      goto LABEL_51;
    }
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
