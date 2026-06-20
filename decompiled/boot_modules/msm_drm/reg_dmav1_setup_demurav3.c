size_t __fastcall reg_dmav1_setup_demurav3(int *a1, _QWORD *a2)
{
  __int64 v3; // x4
  unsigned int v4; // w5
  __int64 *v5; // x22
  int v6; // w8
  size_t result; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x20
  __int64 v13; // x8
  __int64 v14; // x9
  unsigned __int64 *v15; // x8
  __int64 (__fastcall *v16)(_QWORD); // x9
  unsigned __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 (__fastcall *v20)(_QWORD); // x8
  unsigned int v21; // w0
  unsigned int v23; // w0
  unsigned int v24; // w0
  __int64 v25; // x9
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x11
  unsigned __int64 *v29; // x8
  __int64 v30; // x9
  unsigned __int64 v31; // x8
  int v32; // w10
  int v33; // w10
  int v34; // w4
  __int64 v35; // x8
  __int64 (__fastcall *v36)(__int64 *, __int64); // x8
  __int64 v37; // x1
  __int64 v38; // [xsp+8h] [xbp-98h] BYREF
  __int64 v39; // [xsp+10h] [xbp-90h]
  unsigned __int64 v40; // [xsp+18h] [xbp-88h]
  __int64 v41; // [xsp+20h] [xbp-80h]
  __int64 v42; // [xsp+28h] [xbp-78h]
  __int64 v43; // [xsp+30h] [xbp-70h]
  __int64 v44; // [xsp+38h] [xbp-68h]
  int v45; // [xsp+40h] [xbp-60h]
  __int64 v46; // [xsp+44h] [xbp-5Ch]
  int v47; // [xsp+4Ch] [xbp-54h]
  int v48; // [xsp+50h] [xbp-50h]
  int v49; // [xsp+54h] [xbp-4Ch]
  unsigned __int64 v50; // [xsp+58h] [xbp-48h] BYREF
  __int64 v51; // [xsp+60h] [xbp-40h]
  __int64 v52; // [xsp+68h] [xbp-38h]
  unsigned __int64 v53; // [xsp+70h] [xbp-30h]
  __int64 v54; // [xsp+78h] [xbp-28h]
  __int64 v55; // [xsp+80h] [xbp-20h]
  __int64 v56; // [xsp+88h] [xbp-18h]
  __int64 v57; // [xsp+90h] [xbp-10h]
  __int64 v58; // [xsp+98h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
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
    sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_demurav3", 8639, -1, v3, v4, a1[7], 0, 239);
    result = reg_dma_demura_off((__int64)a1, (__int64)a2);
    goto LABEL_34;
  }
  v6 = *((_DWORD *)a2 + 2);
  if ( v6 != 8568 )
  {
    result = _drm_err("invalid sz of payload len %d exp %zd\n", v6, 0x2178u);
    goto LABEL_34;
  }
  result = sde_reg_dma_get_ops(v4);
  if ( !result )
    goto LABEL_34;
  v12 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_34;
  v13 = (unsigned int)a1[16];
  if ( (unsigned int)v13 >= 5 )
    goto LABEL_44;
  v14 = (unsigned int)a1[374];
  if ( (unsigned int)v14 > 1 )
    goto LABEL_44;
  if ( (unsigned __int64)(16 * v13 + 8 * v14 + 1600) <= 0x7D0 )
  {
    v15 = &dspp_buf[2 * v13 + v14];
    v16 = *(__int64 (__fastcall **)(_QWORD))(result + 64);
    v17 = v15[200];
    if ( *((_DWORD *)v16 - 1) != -870478129 )
      __break(0x8229u);
    result = v16(v17);
    v18 = (unsigned int)a1[16];
    v50 = 0x8000000000000000LL;
    v51 = 20;
    v52 = 0;
    v53 = 0;
    v54 = 0;
    v55 = 0;
    v56 = 0;
    v57 = 0;
    if ( (unsigned int)v18 > 4 || (v19 = (unsigned int)a1[374], (unsigned int)v19 > 1) )
    {
LABEL_44:
      __break(0x5512u);
      goto LABEL_45;
    }
    if ( (unsigned __int64)(16 * v18 + 8 * v19 + 1600) <= 0x7D0 )
    {
      HIDWORD(v52) = 0;
      HIDWORD(v51) = 0;
      v55 = 0;
      v53 = dspp_buf[2 * v18 + 200 + v19];
      v54 = 0;
      v20 = *(__int64 (__fastcall **)(_QWORD))(v12 + 8);
      if ( *((_DWORD *)v20 - 1) != -1839634494 )
        __break(0x8228u);
      v21 = v20(&v50);
      if ( v21 )
      {
        result = _drm_err("write decode select failed ret %d\n", v21);
LABEL_34:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      v23 = _reg_dmav1_setup_demura_cfg_common((__int64)a1, v5, (__int64)&v50, v12, (__int64)a2, 26, 16, 1024);
      if ( v23 )
      {
        result = _drm_err("failed to setup_demura_cfg_common rc %d", v23);
        goto LABEL_34;
      }
      v24 = _reg_dmav1_setup_demura_cfg0_param4_5_6_v3(a1, v5, &v50, v12);
      if ( v24 )
      {
        result = _drm_err("failed setup_demura_cfg0_param4_5_6_v3 rc %d", v24);
        goto LABEL_34;
      }
      result = _reg_dmav1_setup_demura_en_v3_common(a1, v5, &v50, v12, a2, 0);
      if ( (_DWORD)result )
      {
        result = _drm_err("failed setup_demura_en_v3 rc %d", (unsigned int)result);
        goto LABEL_34;
      }
      v25 = (unsigned int)a1[16];
      v26 = a2[2];
      v42 = 0;
      v43 = 0;
      v40 = 0;
      v41 = 0;
      v38 = v26;
      v39 = 0;
      if ( (unsigned int)v25 > 4 )
        goto LABEL_44;
      v27 = (unsigned int)a1[374];
      if ( (unsigned int)v27 > 1 )
        goto LABEL_44;
      if ( (unsigned __int64)(16 * v25 + 8 * v27 + 1600) <= 0x7D0 )
      {
        v28 = a2[19];
        LODWORD(v43) = 20;
        v29 = &dspp_buf[2 * v25 + v27];
        v30 = *(_QWORD *)((char *)a2 + 164);
        v45 = *((_DWORD *)a2 + 40);
        v46 = v30;
        v31 = v29[200];
        LODWORD(v30) = *((_DWORD *)a2 + 43);
        v32 = *((_DWORD *)a2 + 44);
        LODWORD(v42) = 0;
        v44 = v28;
        v48 = v30;
        v49 = v32;
        v33 = *((_DWORD *)a2 + 7);
        v40 = v31;
        v47 = v33;
        v34 = *(_DWORD *)(v31 + 20);
        LODWORD(v39) = 1;
        _drm_dev_dbg(0, 0, 1, "enable demura buffer size %d\n", v34);
        result = sde_evtlog_log(
                   sde_dbg_base_evtlog,
                   "reg_dmav1_setup_demurav3",
                   8692,
                   -1,
                   a1[16],
                   a1[374],
                   a1[7],
                   1,
                   239);
        v35 = (unsigned int)a1[7];
        if ( (unsigned int)v35 <= 2 )
        {
          v36 = *(__int64 (__fastcall **)(__int64 *, __int64))(v12 + 8 * v35 + 16);
          if ( v36 )
          {
            v37 = (unsigned int)a1[374];
            if ( *((_DWORD *)v36 - 1) != 1772228465 )
              __break(0x8228u);
            result = v36(&v38, v37);
            if ( (_DWORD)result )
              result = _drm_err("failed to kick off demurav3 ret %d\n", (unsigned int)result);
          }
          goto LABEL_34;
        }
        goto LABEL_44;
      }
    }
  }
LABEL_45:
  __break(1u);
  return _reg_dmav1_setup_demura_cfg0_param4_5_6_v3(result, v9, v10, v11);
}
