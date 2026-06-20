unsigned __int64 __fastcall reg_dmav1_setup_spr_pu_cfgv2(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6)
{
  __int64 v6; // x15
  __int64 v7; // d14
  __int64 v9; // x2
  __int64 v10; // x4
  unsigned __int64 *v11; // x8
  __int64 v13; // x21
  unsigned __int64 result; // x0
  int v15; // w6
  int v16; // w7
  __int64 v17; // x20
  void (__fastcall *v18)(_QWORD); // x8
  long double v19; // q0
  __int64 v20; // x22
  int v21; // w6
  int v22; // w7
  __int64 v23; // x2
  unsigned int v24; // w10
  __int64 v25; // x8
  unsigned int v26; // w11
  __int64 v27; // x8
  __int64 v28; // x8
  int v29; // w9
  __int64 (__fastcall *v30)(__int64 *, __int64); // x8
  __int64 v31; // x1
  int v32; // w0
  char v33; // [xsp+0h] [xbp-60h]
  char v34; // [xsp+0h] [xbp-60h]
  __int64 v35; // [xsp+8h] [xbp-58h] BYREF
  __int64 v36; // [xsp+10h] [xbp-50h]
  __int64 v37; // [xsp+18h] [xbp-48h]
  __int64 v38; // [xsp+20h] [xbp-40h]
  __int128 v39; // [xsp+28h] [xbp-38h]
  __int64 v40; // [xsp+38h] [xbp-28h]
  __int64 v41; // [xsp+40h] [xbp-20h]
  unsigned __int64 v42; // [xsp+48h] [xbp-18h]
  __int64 v43; // [xsp+50h] [xbp-10h]
  __int64 v44; // [xsp+58h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v39 = 0u;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid cfg %pK ctx %pK\n", a2, (const void *)a1);
LABEL_38:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v9 = *(unsigned int *)(a1 + 64);
  v10 = *(unsigned int *)(a1 + 1496);
  if ( !a2[2] || (unsigned int)v9 > 4 || (unsigned int)v10 >= 2 )
  {
    result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", (const void *)a2[2], v9, 14, v10);
    goto LABEL_38;
  }
  v11 = &dspp_buf[2 * v9];
  if ( v11 == (unsigned __int64 *)-1120LL )
  {
    result = _drm_err("invalid dma_buf\n");
    goto LABEL_38;
  }
  if ( (unsigned __int64)(16 * v9 + 8 * v10 + 1120) > 0x7CF )
  {
    __break(1u);
  }
  else
  {
    v13 = v11[v10 + 140];
    result = sde_reg_dma_get_ops((unsigned int)v10);
    if ( !result )
      goto LABEL_38;
    v17 = result;
    if ( result > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_38;
    sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_spr_pu_cfgv2", 7382, -1, 4369, -1059143953, v15, v16, v33);
    v18 = *(void (__fastcall **)(_QWORD))(v17 + 64);
    if ( *((_DWORD *)v18 - 1) != -870478129 )
      __break(0x8228u);
    v18(v13);
    if ( *a2 )
      v20 = *((_DWORD *)a2 + 2) == 72 ? *a2 : 0LL;
    else
      v20 = 0;
    result = reg_dmav1_setup_spr_pu_common(a1, (__int64)a2, v20, v17, v13, v19);
    if ( (_DWORD)result )
      goto LABEL_38;
    result = reg_dmav1_setup_spr_pu_config(a1, v20, v17, v13);
    if ( (_DWORD)result )
      goto LABEL_38;
    v23 = *(unsigned int *)(a1 + 84);
    if ( (_DWORD)v23 )
    {
      if ( v20 )
      {
        v24 = v23 & 0xFFFFFFFC;
        if ( !*(_WORD *)(v20 + 42) )
          v24 = *(_DWORD *)(a1 + 84);
        if ( *((_DWORD *)a2 + 23) == *(unsigned __int16 *)(v20 + 46) )
          v23 = v24;
        else
          v23 = v24 & 0xFFFFFFCF;
      }
      if ( *(_DWORD *)(a1 + 28) )
        printk(&unk_25F249, "ctx->cap->sblk->spr.base + 0x7C");
      else
        sde_reg_write(
          a1,
          (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 416LL) + 124),
          v23,
          "ctx->cap->sblk->spr.base + 0x7C");
    }
    v25 = a2[2];
    v39 = 0u;
    v26 = *((_DWORD *)a2 + 42);
    v37 = v13;
    v38 = 0;
    v35 = v25;
    v36 = 1;
    DWORD2(v39) = 14;
    v27 = a2[20];
    v40 = a2[19];
    v41 = v27;
    v28 = *(unsigned int *)(a1 + 28);
    v29 = *((_DWORD *)a2 + 44);
    LODWORD(v43) = *((_DWORD *)a2 + 43);
    HIDWORD(v43) = v29;
    v42 = __PAIR64__(*((_DWORD *)a2 + 7), v26);
    if ( (unsigned int)v28 <= 2 )
    {
      v30 = *(__int64 (__fastcall **)(__int64 *, __int64))(v17 + 8 * v28 + 16);
      if ( !v30 )
        goto LABEL_37;
      v31 = *(unsigned int *)(a1 + 1496);
      if ( *((_DWORD *)v30 - 1) != 1772228465 )
        __break(0x8228u);
      v32 = v30(&v35, v31);
      if ( v32 )
        result = _drm_err("failed to kick off ret %d\n", v32);
      else
LABEL_37:
        result = sde_evtlog_log(
                   sde_dbg_base_evtlog,
                   "reg_dmav1_setup_spr_pu_cfgv2",
                   7419,
                   -1,
                   8738,
                   -1059143953,
                   v21,
                   v22,
                   v34);
      goto LABEL_38;
    }
  }
  __break(0x5512u);
  *(_QWORD *)(v6 - 24) = v7;
  *(double *)(v6 - 16) = a6;
  return reg_dmav1_setup_demurav1();
}
