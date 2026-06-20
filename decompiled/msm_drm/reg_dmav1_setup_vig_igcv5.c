size_t __fastcall reg_dmav1_setup_vig_igcv5(int *a1, _QWORD *a2)
{
  __int64 v3; // x2
  size_t result; // x0
  __int64 v5; // x22
  size_t v7; // x20
  __int64 v8; // x8
  __int64 v9; // x9
  _QWORD *v10; // x8
  __int64 (__fastcall *v11)(_QWORD); // x9
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 (__fastcall *v15)(_QWORD); // x8
  unsigned int v16; // w0
  __int64 v17; // x4
  __int64 v18; // x8
  __int64 v19; // x5
  __int64 v20; // x10
  int v21; // w6
  int v22; // w8
  __int64 v23; // x10
  __int64 v24; // x8
  unsigned int v25; // w9
  __int64 v26; // x8
  __int64 (__fastcall *v27)(__int64 *, __int64); // x8
  __int64 v28; // x1
  __int64 v29; // [xsp+8h] [xbp-98h] BYREF
  __int64 v30; // [xsp+10h] [xbp-90h]
  __int64 v31; // [xsp+18h] [xbp-88h]
  __int64 v32; // [xsp+20h] [xbp-80h]
  __int64 v33; // [xsp+28h] [xbp-78h]
  __int64 v34; // [xsp+30h] [xbp-70h]
  __int64 v35; // [xsp+38h] [xbp-68h]
  __int64 v36; // [xsp+40h] [xbp-60h]
  __int64 v37; // [xsp+48h] [xbp-58h] BYREF
  __int64 v38; // [xsp+50h] [xbp-50h]
  __int64 v39; // [xsp+58h] [xbp-48h]
  __int64 v40; // [xsp+60h] [xbp-40h]
  __int64 v41; // [xsp+68h] [xbp-38h]
  __int64 v42; // [xsp+70h] [xbp-30h]
  __int64 v43; // [xsp+78h] [xbp-28h]
  __int128 v44; // [xsp+80h] [xbp-20h]
  unsigned __int64 v45; // [xsp+90h] [xbp-10h]
  __int64 v46; // [xsp+98h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  v43 = 0;
  v44 = 0u;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid cfg %pK ctx %pK\n", a2, a1);
LABEL_28:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v3 = (unsigned int)a1[12];
  if ( !a2[2] || (unsigned int)(v3 - 15) <= 0xFFFFFFF1 )
  {
    result = _drm_err("invalid ctl %pK sspp idx %d feature %d\n", (const void *)a2[2], v3, 2);
    goto LABEL_28;
  }
  result = (unsigned int)a1[348];
  if ( (unsigned int)result > 1 )
    goto LABEL_40;
  if ( 16 * v3 + 8 * result + 6480 > 0x4650 )
    goto LABEL_41;
  if ( !sspp_buf[2 * v3 + 810 + result] )
  {
    result = _drm_err("invalid dma_buf for rect idx %d sspp idx %d\n", 1, v3);
    goto LABEL_28;
  }
  v5 = *a2;
  if ( !*a2 )
  {
    _drm_dev_dbg(0, 0, 1, "disable igc feature\n");
    sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_vig_igcv5", 3712, -1, a1[12], a1[348], a1[7], 0, 239);
    result = vig_igcv5_off(a1, a2);
    goto LABEL_28;
  }
  result = sde_reg_dma_get_ops(result);
  if ( !result )
    goto LABEL_28;
  v7 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_28;
  v8 = (unsigned int)a1[12];
  if ( (unsigned int)v8 >= 0xF )
    goto LABEL_40;
  v9 = (unsigned int)a1[348];
  if ( (unsigned int)v9 > 1 )
    goto LABEL_40;
  if ( (unsigned __int64)(16 * v8 + 8 * v9 + 6480) > 0x4650 )
    goto LABEL_41;
  v10 = &sspp_buf[2 * v8 + v9];
  v11 = *(__int64 (__fastcall **)(_QWORD))(result + 64);
  v12 = v10[810];
  if ( *((_DWORD *)v11 - 1) != -870478129 )
    __break(0x8229u);
  result = v11(v12);
  v13 = (unsigned int)a1[12];
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  if ( (unsigned int)v13 > 0xE
    || (v14 = (unsigned int)a1[348], HIDWORD(v29) = sspp_mapping[v13], LODWORD(v30) = 2, (unsigned int)v14 > 1) )
  {
LABEL_40:
    __break(0x5512u);
    goto LABEL_41;
  }
  if ( (unsigned __int64)(16 * v13 + 8 * v14 + 6480) <= 0x4650 )
  {
    HIDWORD(v31) = 0;
    HIDWORD(v30) = 0;
    v34 = 0;
    v32 = sspp_buf[2 * v13 + 810 + v14];
    v33 = 0;
    v15 = *(__int64 (__fastcall **)(_QWORD))(v7 + 8);
    if ( *((_DWORD *)v15 - 1) != -1839634494 )
      __break(0x8228u);
    v16 = v15(&v29);
    if ( v16 )
    {
      result = _drm_err("write decode select failed ret %d\n", v16);
      goto LABEL_28;
    }
    result = reg_dmav1_setup_vig_igc_common(v7, &v29, a1, a2, 1023, v5);
    if ( (_DWORD)result )
    {
      result = _drm_err("setup_vig_igc_common failed\n");
      goto LABEL_28;
    }
    v17 = (unsigned int)a1[12];
    v18 = a2[2];
    v41 = 0;
    v42 = 0;
    v39 = 0;
    v40 = 0;
    v37 = v18;
    v38 = 0;
    if ( (unsigned int)v17 > 0xE )
      goto LABEL_40;
    v19 = (unsigned int)a1[348];
    if ( (unsigned int)v19 > 1 )
      goto LABEL_40;
    if ( (unsigned __int64)(16 * v17 + 8 * v19 + 6480) <= 0x4650 )
    {
      v20 = a2[19];
      LODWORD(v38) = 1;
      v21 = a1[7];
      LODWORD(v42) = 2;
      v22 = *((_DWORD *)a2 + 40);
      v43 = v20;
      v23 = *(_QWORD *)((char *)a2 + 164);
      LODWORD(v44) = v22;
      v24 = sspp_buf[2 * v17 + 810 + v19];
      *(_QWORD *)((char *)&v44 + 4) = v23;
      LODWORD(v23) = *((_DWORD *)a2 + 43);
      v25 = *((_DWORD *)a2 + 44);
      v39 = v24;
      LODWORD(v24) = *((_DWORD *)a2 + 7);
      LODWORD(v41) = 0;
      v45 = __PAIR64__(v25, v23);
      HIDWORD(v44) = v24;
      result = sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_vig_igcv5", 3743, -1, v17, v19, v21, 1, 239);
      v26 = (unsigned int)a1[7];
      if ( (unsigned int)v26 <= 2 )
      {
        v27 = *(__int64 (__fastcall **)(__int64 *, __int64))(v7 + 8 * v26 + 16);
        if ( v27 )
        {
          v28 = (unsigned int)a1[348];
          if ( *((_DWORD *)v27 - 1) != 1772228465 )
            __break(0x8228u);
          result = v27(&v37, v28);
          if ( (_DWORD)result )
            result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
        }
        goto LABEL_28;
      }
      goto LABEL_40;
    }
  }
LABEL_41:
  __break(1u);
  return vig_igcv5_off(result, a2);
}
