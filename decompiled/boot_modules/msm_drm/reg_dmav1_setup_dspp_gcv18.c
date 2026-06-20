size_t __fastcall reg_dmav1_setup_dspp_gcv18(__int64 a1, int **a2)
{
  __int64 v3; // x2
  unsigned int v4; // w4
  unsigned __int64 ops; // x0
  unsigned __int64 v7; // x20
  size_t result; // x0
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 (__fastcall *v11)(_QWORD); // x8
  unsigned int v12; // w0
  __int64 v13; // x8
  int v14; // w9
  __int64 (__fastcall *v15)(_QWORD); // x8
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x4
  int *v20; // x8
  __int64 v21; // x5
  int *v22; // x10
  int v23; // w6
  int v24; // w8
  __int64 v25; // x10
  unsigned __int64 v26; // x8
  unsigned int v27; // w9
  __int64 v28; // x8
  __int64 (__fastcall *v29)(int **, __int64); // x8
  __int64 v30; // x1
  int v31; // [xsp+14h] [xbp-9Ch] BYREF
  int *v32; // [xsp+18h] [xbp-98h] BYREF
  __int64 v33; // [xsp+20h] [xbp-90h]
  unsigned __int64 v34; // [xsp+28h] [xbp-88h]
  __int64 v35; // [xsp+30h] [xbp-80h]
  __int64 v36; // [xsp+38h] [xbp-78h]
  __int64 v37; // [xsp+40h] [xbp-70h]
  int *v38; // [xsp+48h] [xbp-68h]
  __int128 v39; // [xsp+50h] [xbp-60h]
  unsigned __int64 v40; // [xsp+60h] [xbp-50h]
  __int64 v41; // [xsp+68h] [xbp-48h] BYREF
  __int128 v42; // [xsp+70h] [xbp-40h]
  __int64 v43; // [xsp+80h] [xbp-30h]
  int *v44; // [xsp+88h] [xbp-28h]
  __int64 v45; // [xsp+90h] [xbp-20h]
  __int64 v46; // [xsp+98h] [xbp-18h]
  __int64 v47; // [xsp+A0h] [xbp-10h]
  __int64 v48; // [xsp+A8h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  v47 = 0;
  v44 = nullptr;
  v45 = 0;
  v43 = 0;
  v41 = 0;
  v42 = 0u;
  v40 = 0;
  v38 = nullptr;
  v39 = 0u;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = nullptr;
  v33 = 0;
  v31 = 0;
  if ( !a1 || !a2 )
  {
    _drm_err("invalid cfg %pK ctx %pK\n", a2, (const void *)a1);
LABEL_18:
    result = _drm_err("reg dma dspp check failed ret %d\n", 4294967274LL);
    goto LABEL_19;
  }
  v3 = *(unsigned int *)(a1 + 64);
  v4 = *(_DWORD *)(a1 + 1496);
  if ( !a2[2] || (unsigned int)v3 > 4 || v4 >= 2 )
  {
    _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", a2[2], v3, 11, v4);
    goto LABEL_18;
  }
  if ( &dspp_buf[2 * v3] == (unsigned __int64 *)-880LL )
  {
    _drm_err("invalid dma_buf\n");
    goto LABEL_18;
  }
  if ( !*a2 )
  {
    _drm_dev_dbg(0, 0, 1, "disable pgc feature\n");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "reg_dmav1_setup_dspp_gcv18",
      1299,
      -1,
      *(_DWORD *)(a1 + 64),
      *(_DWORD *)(a1 + 1496),
      *(_DWORD *)(a1 + 28),
      0,
      239);
    if ( *(_DWORD *)(a1 + 28) )
      result = printk(&unk_25F249, "ctx->cap->sblk->gc.base");
    else
      result = sde_reg_write(
                 a1,
                 *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 92LL),
                 0,
                 "ctx->cap->sblk->gc.base");
    goto LABEL_19;
  }
  ops = sde_reg_dma_get_ops(v4);
  if ( !ops || (v7 = ops, ops >= 0xFFFFFFFFFFFFF001LL) )
  {
    result = _drm_err("invalid dma ops\n");
    goto LABEL_19;
  }
  result = reg_dmav1_setup_dspp_gc_common(a1, a2, ops, &v41);
  if ( (_DWORD)result )
  {
LABEL_19:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v9 = *(_QWORD *)(a1 + 72);
  *(_QWORD *)((char *)&v42 + 4) = 0;
  v10 = *(_QWORD *)(v9 + 48);
  v44 = &v31;
  v45 = 0x400000000LL;
  v31 = 1;
  LODWORD(v10) = *(_DWORD *)(v10 + 92);
  LODWORD(v41) = 1;
  HIDWORD(v42) = v10 + 28;
  v11 = *(__int64 (__fastcall **)(_QWORD))(v7 + 8);
  if ( *((_DWORD *)v11 - 1) != -1839634494 )
    __break(0x8228u);
  v12 = v11(&v41);
  if ( v12 )
  {
    result = _drm_err("setting swap offset failed ret %d\n", v12);
    goto LABEL_19;
  }
  v13 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL);
  v14 = **a2;
  *(_QWORD *)((char *)&v42 + 4) = 0;
  v44 = &v31;
  v45 = 0x400000000LL;
  LODWORD(v13) = *(_DWORD *)(v13 + 92);
  LODWORD(v41) = 1;
  HIDWORD(v42) = v13;
  v15 = *(__int64 (__fastcall **)(_QWORD))(v7 + 8);
  v31 = (2 * (v14 & 1)) | 1;
  if ( *((_DWORD *)v15 - 1) != -1839634494 )
    __break(0x8228u);
  result = v15(&v41);
  if ( (_DWORD)result )
  {
    result = _drm_err("enabling gamma correction failed ret %d\n", (unsigned int)result);
    goto LABEL_19;
  }
  v19 = *(unsigned int *)(a1 + 64);
  v20 = a2[2];
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = v20;
  v33 = 0;
  if ( (unsigned int)v19 >= 5 )
    goto LABEL_37;
  v21 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v21 > 1 )
    goto LABEL_37;
  if ( (unsigned __int64)(16 * v19 + 8 * v21 + 880) <= 0x7D0 )
  {
    v22 = a2[19];
    LODWORD(v33) = 1;
    v23 = *(_DWORD *)(a1 + 28);
    LODWORD(v37) = 11;
    v24 = *((_DWORD *)a2 + 40);
    v38 = v22;
    v25 = *(__int64 *)((char *)a2 + 164);
    LODWORD(v39) = v24;
    v26 = dspp_buf[2 * v19 + 110 + v21];
    *(_QWORD *)((char *)&v39 + 4) = v25;
    LODWORD(v25) = *((_DWORD *)a2 + 43);
    v27 = *((_DWORD *)a2 + 44);
    v34 = v26;
    LODWORD(v26) = *((_DWORD *)a2 + 7);
    LODWORD(v36) = 0;
    v40 = __PAIR64__(v27, v25);
    HIDWORD(v39) = v26;
    result = sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_dspp_gcv18", 1335, -1, v19, v21, v23, 1, 239);
    v28 = *(unsigned int *)(a1 + 28);
    if ( (unsigned int)v28 <= 2 )
    {
      v29 = *(__int64 (__fastcall **)(int **, __int64))(v7 + 8 * v28 + 16);
      if ( v29 )
      {
        v30 = *(unsigned int *)(a1 + 1496);
        if ( *((_DWORD *)v29 - 1) != 1772228465 )
          __break(0x8228u);
        result = v29(&v32, v30);
        if ( (_DWORD)result )
          result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
      }
      goto LABEL_19;
    }
LABEL_37:
    __break(0x5512u);
  }
  __break(1u);
  return reg_dmav1_setup_dspp_gc_common(result, v16, v17, v18);
}
