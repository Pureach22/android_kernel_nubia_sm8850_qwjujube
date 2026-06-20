size_t __fastcall reg_dmav1_setup_demurav2(int *a1, _QWORD *a2)
{
  __int64 v3; // x4
  unsigned int v4; // w5
  __int64 *v5; // x22
  int v7; // w1
  size_t result; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x20
  __int64 v14; // x8
  __int64 v15; // x9
  unsigned __int64 *v16; // x8
  __int64 (__fastcall *v17)(_QWORD); // x9
  unsigned __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x9
  __int64 (__fastcall *v21)(_QWORD); // x8
  unsigned int v22; // w0
  unsigned int v24; // w0
  unsigned int v25; // w0
  __int64 v26; // x9
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x11
  unsigned __int64 *v30; // x8
  __int64 v31; // x9
  unsigned __int64 v32; // x8
  int v33; // w10
  int v34; // w10
  int v35; // w4
  __int64 v36; // x8
  __int64 (__fastcall *v37)(__int64 *, __int64); // x8
  __int64 v38; // x1
  __int64 v39; // [xsp+8h] [xbp-98h] BYREF
  __int64 v40; // [xsp+10h] [xbp-90h]
  unsigned __int64 v41; // [xsp+18h] [xbp-88h]
  __int64 v42; // [xsp+20h] [xbp-80h]
  __int64 v43; // [xsp+28h] [xbp-78h]
  __int64 v44; // [xsp+30h] [xbp-70h]
  __int64 v45; // [xsp+38h] [xbp-68h]
  int v46; // [xsp+40h] [xbp-60h]
  __int64 v47; // [xsp+44h] [xbp-5Ch]
  int v48; // [xsp+4Ch] [xbp-54h]
  int v49; // [xsp+50h] [xbp-50h]
  int v50; // [xsp+54h] [xbp-4Ch]
  unsigned __int64 v51; // [xsp+58h] [xbp-48h] BYREF
  __int64 v52; // [xsp+60h] [xbp-40h]
  __int64 v53; // [xsp+68h] [xbp-38h]
  unsigned __int64 v54; // [xsp+70h] [xbp-30h]
  __int64 v55; // [xsp+78h] [xbp-28h]
  __int64 v56; // [xsp+80h] [xbp-20h]
  __int64 v57; // [xsp+88h] [xbp-18h]
  __int64 v58; // [xsp+90h] [xbp-10h]
  __int64 v59; // [xsp+98h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid cfg %pK ctx %pK\n", a2, a1);
    goto LABEL_34;
  }
  v3 = (unsigned int)a1[16];
  v4 = a1[374];
  if ( !a2[2] || (unsigned int)v3 > 4 || v4 >= 2 )
  {
    result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", (const void *)a2[2], v3, 20, v4);
    goto LABEL_34;
  }
  if ( &dspp_buf[2 * v3] == (unsigned __int64 *)-1600LL )
  {
    result = _drm_err("invalid dma_buf\n");
    goto LABEL_34;
  }
  v5 = (__int64 *)*a2;
  if ( !*a2 )
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_demurav2", 8274, -1, v3, v4, a1[7], 0, 239);
    result = reg_dma_demura_off((__int64)a1, (__int64)a2);
    goto LABEL_34;
  }
  v7 = *((_DWORD *)a2 + 2);
  if ( v7 != 8568 )
  {
    _drm_err("invalid sz of payload len %d exp %zd\n", v7, 0x2178u);
    v5 = (__int64 *)*a2;
    v4 = a1[374];
  }
  result = sde_reg_dma_get_ops(v4);
  if ( !result )
    goto LABEL_34;
  v13 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_34;
  v14 = (unsigned int)a1[16];
  if ( (unsigned int)v14 >= 5 )
    goto LABEL_44;
  v15 = (unsigned int)a1[374];
  if ( (unsigned int)v15 > 1 )
    goto LABEL_44;
  if ( (unsigned __int64)(16 * v14 + 8 * v15 + 1600) <= 0x7D0 )
  {
    v16 = &dspp_buf[2 * v14 + v15];
    v17 = *(__int64 (__fastcall **)(_QWORD))(result + 64);
    v18 = v16[200];
    if ( *((_DWORD *)v17 - 1) != -870478129 )
      __break(0x8229u);
    result = v17(v18);
    v19 = (unsigned int)a1[16];
    v51 = 0x8000000000000000LL;
    v52 = 20;
    v53 = 0;
    v54 = 0;
    v55 = 0;
    v56 = 0;
    v57 = 0;
    v58 = 0;
    if ( (unsigned int)v19 > 4 || (v20 = (unsigned int)a1[374], (unsigned int)v20 > 1) )
    {
LABEL_44:
      __break(0x5512u);
      goto LABEL_45;
    }
    if ( (unsigned __int64)(16 * v19 + 8 * v20 + 1600) <= 0x7D0 )
    {
      HIDWORD(v53) = 0;
      HIDWORD(v52) = 0;
      v56 = 0;
      v54 = dspp_buf[2 * v19 + 200 + v20];
      v55 = 0;
      v21 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8);
      if ( *((_DWORD *)v21 - 1) != -1839634494 )
        __break(0x8228u);
      v22 = v21(&v51);
      if ( v22 )
      {
        result = _drm_err("write decode select failed ret %d\n", v22);
LABEL_34:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      v24 = _reg_dmav1_setup_demura_cfg_common((__int64)a1, v5, (__int64)&v51, v13, (__int64)a2, 22, 12, 1024);
      if ( v24 )
      {
        result = _drm_err("failed to setup_demurav2_cfg rc %d", v24);
        goto LABEL_34;
      }
      v25 = _reg_dmav1_setup_demura_cfg0_param4_common((__int64)a1, v5, (__int64)&v51, v13, 8);
      if ( v25 )
      {
        result = _drm_err("failed setup demura v2 cfg0_param4 rc %d", v25);
        goto LABEL_34;
      }
      result = _reg_dmav1_setup_demurav2_en(a1, v5, &v51, v13, a2);
      if ( (_DWORD)result )
      {
        result = _drm_err("failed setup_demurav2_en rc %d", (unsigned int)result);
        goto LABEL_34;
      }
      v26 = (unsigned int)a1[16];
      v27 = a2[2];
      v43 = 0;
      v44 = 0;
      v41 = 0;
      v42 = 0;
      v39 = v27;
      v40 = 0;
      if ( (unsigned int)v26 > 4 )
        goto LABEL_44;
      v28 = (unsigned int)a1[374];
      if ( (unsigned int)v28 > 1 )
        goto LABEL_44;
      if ( (unsigned __int64)(16 * v26 + 8 * v28 + 1600) <= 0x7D0 )
      {
        v29 = a2[19];
        LODWORD(v44) = 20;
        v30 = &dspp_buf[2 * v26 + v28];
        v31 = *(_QWORD *)((char *)a2 + 164);
        v46 = *((_DWORD *)a2 + 40);
        v47 = v31;
        v32 = v30[200];
        LODWORD(v31) = *((_DWORD *)a2 + 43);
        v33 = *((_DWORD *)a2 + 44);
        LODWORD(v43) = 0;
        v45 = v29;
        v49 = v31;
        v50 = v33;
        v34 = *((_DWORD *)a2 + 7);
        v41 = v32;
        v48 = v34;
        v35 = *(_DWORD *)(v32 + 20);
        LODWORD(v40) = 1;
        _drm_dev_dbg(0, 0, 1, "enable demura buffer size %d\n", v35);
        result = sde_evtlog_log(
                   sde_dbg_base_evtlog,
                   "reg_dmav1_setup_demurav2",
                   8327,
                   -1,
                   a1[16],
                   a1[374],
                   a1[7],
                   1,
                   239);
        v36 = (unsigned int)a1[7];
        if ( (unsigned int)v36 <= 2 )
        {
          v37 = *(__int64 (__fastcall **)(__int64 *, __int64))(v13 + 8 * v36 + 16);
          if ( v37 )
          {
            v38 = (unsigned int)a1[374];
            if ( *((_DWORD *)v37 - 1) != 1772228465 )
              __break(0x8228u);
            result = v37(&v39, v38);
            if ( (_DWORD)result )
              result = _drm_err("failed to kick off demurav2 ret %d\n", (unsigned int)result);
          }
          goto LABEL_34;
        }
        goto LABEL_44;
      }
    }
  }
LABEL_45:
  __break(1u);
  return _reg_dmav1_setup_demurav2_en(result, v9, v10, v11, v12);
}
