size_t __fastcall reg_dmav1_setup_demura_cfg0_param2(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x4
  unsigned int v4; // w5
  unsigned int *v5; // x25
  int v6; // w8
  int v7; // w27
  int v9; // w26
  size_t result; // x0
  size_t v11; // x20
  __int64 v12; // x8
  __int64 v13; // x9
  unsigned __int64 *v14; // x8
  void (__fastcall *v15)(_QWORD); // x9
  unsigned __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 (__fastcall *v19)(_QWORD); // x8
  int v20; // w0
  size_t v21; // x21
  unsigned int v22; // w22
  __int64 v23; // x8
  __int64 v24; // x9
  __int64 v25; // x1
  __int64 v26; // x10
  int v27; // w9
  __int64 v28; // x10
  unsigned __int64 v29; // x8
  unsigned int v30; // w9
  __int64 v31; // x8
  __int64 (__fastcall *v32)(_QWORD); // x8
  int v33; // w0
  unsigned __int64 StatusReg; // x22
  __int64 v35; // x28
  __int64 v36; // [xsp+8h] [xbp-98h] BYREF
  __int64 v37; // [xsp+10h] [xbp-90h]
  unsigned __int64 v38; // [xsp+18h] [xbp-88h]
  __int64 v39; // [xsp+20h] [xbp-80h]
  __int64 v40; // [xsp+28h] [xbp-78h]
  __int64 v41; // [xsp+30h] [xbp-70h]
  __int64 v42; // [xsp+38h] [xbp-68h]
  __int128 v43; // [xsp+40h] [xbp-60h]
  unsigned __int64 v44; // [xsp+50h] [xbp-50h]
  unsigned __int64 v45; // [xsp+58h] [xbp-48h] BYREF
  __int64 v46; // [xsp+60h] [xbp-40h]
  __int64 v47; // [xsp+68h] [xbp-38h]
  unsigned __int64 v48; // [xsp+70h] [xbp-30h]
  __int64 v49; // [xsp+78h] [xbp-28h]
  __int64 v50; // [xsp+80h] [xbp-20h]
  __int64 v51; // [xsp+88h] [xbp-18h]
  __int64 v52; // [xsp+90h] [xbp-10h]
  __int64 v53; // [xsp+98h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v44 = 0;
  v42 = 0;
  v43 = 0u;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid cfg %pK ctx %pK\n", a2, (const void *)a1);
    goto LABEL_28;
  }
  v3 = *(unsigned int *)(a1 + 64);
  v4 = *(_DWORD *)(a1 + 1496);
  if ( !a2[2] || (unsigned int)v3 > 4 || v4 >= 2 )
  {
    result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", (const void *)a2[2], v3, 21, v4);
    goto LABEL_28;
  }
  if ( &dspp_buf[2 * v3] == (unsigned __int64 *)-1680LL )
  {
    result = _drm_err("invalid dma_buf\n");
    goto LABEL_28;
  }
  v5 = (unsigned int *)*a2;
  if ( !*a2 )
  {
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "reg_dmav1_setup_demura_cfg0_param2",
               8352,
               -1,
               v3,
               v4,
               *(_DWORD *)(a1 + 28),
               0,
               239);
    goto LABEL_28;
  }
  v6 = *((_DWORD *)a2 + 2);
  if ( v6 != 6152 )
  {
    result = _drm_err("invalid sz of payload len %d exp %zd\n", v6, 0x1808u);
    goto LABEL_28;
  }
  v7 = *(_DWORD *)(a1 + 8);
  v9 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 568LL);
  result = sde_reg_dma_get_ops(v4);
  if ( result )
  {
    v11 = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      v12 = *(unsigned int *)(a1 + 64);
      if ( (unsigned int)v12 >= 5 )
        goto LABEL_40;
      v13 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v13 > 1 )
        goto LABEL_40;
      if ( (unsigned __int64)(16 * v12 + 8 * v13 + 1680) > 0x7CF )
        goto LABEL_41;
      v14 = &dspp_buf[2 * v12 + v13];
      v15 = *(void (__fastcall **)(_QWORD))(result + 64);
      v16 = v14[210];
      if ( *((_DWORD *)v15 - 1) != -870478129 )
        __break(0x8229u);
      v15(v16);
      v17 = *(unsigned int *)(a1 + 64);
      v45 = 0x8000000000000000LL;
      v46 = 21;
      v47 = 0;
      v48 = 0;
      v49 = 0;
      v50 = 0;
      v51 = 0;
      v52 = 0;
      if ( (unsigned int)v17 > 4 )
        goto LABEL_40;
      v18 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v18 > 1 )
        goto LABEL_40;
      if ( (unsigned __int64)(16 * v17 + 8 * v18 + 1680) > 0x7CF )
        goto LABEL_41;
      HIDWORD(v47) = 0;
      HIDWORD(v46) = 0;
      v50 = 0;
      v48 = dspp_buf[2 * v17 + 210 + v18];
      v49 = 0;
      v19 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
      if ( *((_DWORD *)v19 - 1) != -1839634494 )
        __break(0x8228u);
      v20 = v19(&v45);
      if ( v20 )
      {
        result = _drm_err("write decode select failed ret %d\n", v20);
        goto LABEL_28;
      }
      result = _kvmalloc_node_noprof(6152, 0, 3520, 0xFFFFFFFFLL);
      v21 = result;
      if ( !result )
        goto LABEL_28;
      while ( 1 )
      {
        v22 = *v5;
        _reg_dmav1_setup_demurav1_cfg0_c_params_cmn(&v45, v11, v5 + 2, *v5, v21, 0, (unsigned int)(v7 + v9));
        _reg_dmav1_setup_demurav1_cfg0_c_params_cmn(&v45, v11, v5 + 514, v22, v21, 1, (unsigned int)(v7 + v9));
        _reg_dmav1_setup_demurav1_cfg0_c_params_cmn(&v45, v11, v5 + 1026, v22, v21, 2, (unsigned int)(v7 + v9));
        v23 = *(unsigned int *)(a1 + 64);
        v24 = a2[2];
        v38 = 0;
        v39 = 0;
        v40 = 0;
        v41 = 0;
        v36 = v24;
        v37 = 0;
        if ( (unsigned int)v23 > 4 )
          goto LABEL_40;
        v25 = *(unsigned int *)(a1 + 1496);
        if ( (unsigned int)v25 > 1 )
          goto LABEL_40;
        if ( (unsigned __int64)(16 * v23 + 8 * v25 + 1680) <= 0x7CF )
          break;
LABEL_41:
        __break(1u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v35 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &reg_dmav1_setup_demura_cfg0_param2__alloc_tag;
        result = _kvmalloc_node_noprof(6152, 0, 3520, 0xFFFFFFFFLL);
        v21 = result;
        *(_QWORD *)(StatusReg + 80) = v35;
        if ( !result )
          goto LABEL_28;
      }
      v26 = a2[19];
      LODWORD(v37) = 1;
      LODWORD(v41) = 21;
      v27 = *((_DWORD *)a2 + 40);
      v42 = v26;
      v28 = *(_QWORD *)((char *)a2 + 164);
      LODWORD(v43) = v27;
      v29 = dspp_buf[2 * v23 + 210 + v25];
      *(_QWORD *)((char *)&v43 + 4) = v28;
      LODWORD(v28) = *((_DWORD *)a2 + 43);
      v30 = *((_DWORD *)a2 + 44);
      v38 = v29;
      v31 = *(unsigned int *)(a1 + 28);
      LODWORD(v40) = 0;
      v44 = __PAIR64__(v30, v28);
      HIDWORD(v43) = *((_DWORD *)a2 + 7);
      if ( (unsigned int)v31 <= 2 )
      {
        v32 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8 * v31 + 16);
        if ( v32 )
        {
          if ( *((_DWORD *)v32 - 1) != 1772228465 )
            __break(0x8228u);
          v33 = v32(&v36);
          if ( v33 )
            _drm_err("failed to kick off ret %d\n", v33);
        }
        sde_evtlog_log(
          sde_dbg_base_evtlog,
          "reg_dmav1_setup_demura_cfg0_param2",
          8402,
          -1,
          *(_DWORD *)(a1 + 64),
          *(_DWORD *)(a1 + 1496),
          *(_DWORD *)(a1 + 28),
          1,
          239);
        result = kvfree(v21);
        goto LABEL_28;
      }
LABEL_40:
      __break(0x5512u);
      goto LABEL_41;
    }
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
