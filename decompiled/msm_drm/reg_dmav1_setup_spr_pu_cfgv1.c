unsigned __int64 __fastcall reg_dmav1_setup_spr_pu_cfgv1(
        unsigned int *a1,
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
  __int64 v20; // x2
  int v21; // w6
  int v22; // w7
  __int64 v23; // x8
  int v24; // w11
  __int64 v25; // x8
  __int64 v26; // x8
  int v27; // w9
  int v28; // w9
  __int64 (__fastcall *v29)(__int64 *, __int64); // x8
  __int64 v30; // x1
  int v31; // w0
  char v32; // [xsp+0h] [xbp-60h]
  char v33; // [xsp+0h] [xbp-60h]
  __int64 v34; // [xsp+8h] [xbp-58h] BYREF
  int v35; // [xsp+10h] [xbp-50h]
  int v36; // [xsp+14h] [xbp-4Ch]
  __int64 v37; // [xsp+18h] [xbp-48h]
  __int64 v38; // [xsp+20h] [xbp-40h]
  __int64 v39; // [xsp+28h] [xbp-38h]
  __int64 v40; // [xsp+30h] [xbp-30h]
  __int64 v41; // [xsp+38h] [xbp-28h]
  __int64 v42; // [xsp+40h] [xbp-20h]
  int v43; // [xsp+48h] [xbp-18h]
  int v44; // [xsp+4Ch] [xbp-14h]
  int v45; // [xsp+50h] [xbp-10h]
  int v46; // [xsp+54h] [xbp-Ch]
  __int64 v47; // [xsp+58h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid cfg %pK ctx %pK\n", a2, a1);
LABEL_28:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v9 = a1[16];
  v10 = a1[374];
  if ( !a2[2] || (unsigned int)v9 > 4 || (unsigned int)v10 >= 2 )
  {
    result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", (const void *)a2[2], v9, 14, v10);
    goto LABEL_28;
  }
  v11 = &dspp_buf[2 * v9];
  if ( v11 == (unsigned __int64 *)-1120LL )
  {
    result = _drm_err("invalid dma_buf\n");
    goto LABEL_28;
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
      goto LABEL_28;
    v17 = result;
    if ( result > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_28;
    sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_spr_pu_cfgv1", 7341, -1, 4369, -1059143953, v15, v16, v32);
    v18 = *(void (__fastcall **)(_QWORD))(v17 + 64);
    if ( *((_DWORD *)v18 - 1) != -870478129 )
      __break(0x8228u);
    v18(v13);
    if ( *a2 )
      v20 = *((_DWORD *)a2 + 2) == 72 ? *a2 : 0LL;
    else
      v20 = 0;
    result = reg_dmav1_setup_spr_pu_common((__int64)a1, (__int64)a2, v20, v17, v13, v19);
    if ( (_DWORD)result )
      goto LABEL_28;
    v23 = a2[2];
    v39 = 0;
    v40 = 0;
    v24 = *((_DWORD *)a2 + 42);
    v37 = v13;
    v38 = 0;
    v34 = v23;
    v36 = 0;
    v35 = 1;
    LODWORD(v40) = 14;
    v25 = a2[20];
    v41 = a2[19];
    v42 = v25;
    v26 = a1[7];
    v27 = *((_DWORD *)a2 + 44);
    v45 = *((_DWORD *)a2 + 43);
    v46 = v27;
    v28 = *((_DWORD *)a2 + 7);
    v43 = v24;
    v44 = v28;
    if ( (unsigned int)v26 <= 2 )
    {
      v29 = *(__int64 (__fastcall **)(__int64 *, __int64))(v17 + 8 * v26 + 16);
      if ( !v29 )
        goto LABEL_27;
      v30 = a1[374];
      if ( *((_DWORD *)v29 - 1) != 1772228465 )
        __break(0x8228u);
      v31 = v29(&v34, v30);
      if ( v31 )
        result = _drm_err("failed to kick off ret %d\n", v31);
      else
LABEL_27:
        result = sde_evtlog_log(
                   sde_dbg_base_evtlog,
                   "reg_dmav1_setup_spr_pu_cfgv1",
                   7361,
                   -1,
                   8738,
                   -1059143953,
                   v21,
                   v22,
                   v33);
      goto LABEL_28;
    }
  }
  __break(0x5512u);
  *(_QWORD *)(v6 - 24) = v7;
  *(double *)(v6 - 16) = a6;
  return reg_dmav1_setup_spr_pu_cfgv2();
}
