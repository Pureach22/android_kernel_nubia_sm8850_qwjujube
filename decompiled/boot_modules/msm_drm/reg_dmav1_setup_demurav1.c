size_t __fastcall reg_dmav1_setup_demurav1(int *a1, _QWORD *a2)
{
  __int64 v3; // x4
  unsigned int v4; // w5
  __int64 v5; // x22
  int v7; // w1
  size_t result; // x0
  __int64 v9; // x1
  size_t v10; // x20
  __int64 v11; // x8
  __int64 v12; // x9
  unsigned __int64 *v13; // x8
  __int64 (__fastcall *v14)(_QWORD); // x9
  unsigned __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 (__fastcall *v18)(_QWORD); // x8
  unsigned int v19; // w0
  unsigned int v21; // w0
  unsigned int v22; // w0
  __int64 v23; // x9
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x11
  unsigned __int64 *v27; // x8
  __int64 v28; // x9
  unsigned __int64 v29; // x8
  int v30; // w10
  int v31; // w10
  int v32; // w4
  __int64 v33; // x8
  __int64 (__fastcall *v34)(__int64 *, __int64); // x8
  __int64 v35; // x1
  __int64 v36; // [xsp+8h] [xbp-98h] BYREF
  __int64 v37; // [xsp+10h] [xbp-90h]
  unsigned __int64 v38; // [xsp+18h] [xbp-88h]
  __int64 v39; // [xsp+20h] [xbp-80h]
  __int64 v40; // [xsp+28h] [xbp-78h]
  __int64 v41; // [xsp+30h] [xbp-70h]
  __int64 v42; // [xsp+38h] [xbp-68h]
  int v43; // [xsp+40h] [xbp-60h]
  __int64 v44; // [xsp+44h] [xbp-5Ch]
  int v45; // [xsp+4Ch] [xbp-54h]
  int v46; // [xsp+50h] [xbp-50h]
  int v47; // [xsp+54h] [xbp-4Ch]
  unsigned __int64 v48; // [xsp+58h] [xbp-48h] BYREF
  __int64 v49; // [xsp+60h] [xbp-40h]
  __int64 v50; // [xsp+68h] [xbp-38h]
  unsigned __int64 v51; // [xsp+70h] [xbp-30h]
  __int64 v52; // [xsp+78h] [xbp-28h]
  __int64 v53; // [xsp+80h] [xbp-20h]
  __int64 v54; // [xsp+88h] [xbp-18h]
  __int64 v55; // [xsp+90h] [xbp-10h]
  __int64 v56; // [xsp+98h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
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
  v5 = *a2;
  if ( !*a2 )
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_demurav1", 8198, -1, v3, v4, a1[7], 0, 239);
    result = reg_dma_demura_off(a1, a2);
    goto LABEL_34;
  }
  v7 = *((_DWORD *)a2 + 2);
  if ( v7 != 8568 )
  {
    _drm_err("invalid sz of payload len %d exp %zd\n", v7, 0x2178u);
    v5 = *a2;
    v4 = a1[374];
  }
  result = sde_reg_dma_get_ops(v4);
  if ( !result )
    goto LABEL_34;
  v10 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_34;
  v11 = (unsigned int)a1[16];
  if ( (unsigned int)v11 >= 5 )
    goto LABEL_44;
  v12 = (unsigned int)a1[374];
  if ( (unsigned int)v12 > 1 )
    goto LABEL_44;
  if ( (unsigned __int64)(16 * v11 + 8 * v12 + 1600) <= 0x7D0 )
  {
    v13 = &dspp_buf[2 * v11 + v12];
    v14 = *(__int64 (__fastcall **)(_QWORD))(result + 64);
    v15 = v13[200];
    if ( *((_DWORD *)v14 - 1) != -870478129 )
      __break(0x8229u);
    result = v14(v15);
    v16 = (unsigned int)a1[16];
    v48 = 0x8000000000000000LL;
    v49 = 20;
    v50 = 0;
    v51 = 0;
    v52 = 0;
    v53 = 0;
    v54 = 0;
    v55 = 0;
    if ( (unsigned int)v16 > 4 || (v17 = (unsigned int)a1[374], (unsigned int)v17 > 1) )
    {
LABEL_44:
      __break(0x5512u);
      goto LABEL_45;
    }
    if ( (unsigned __int64)(16 * v16 + 8 * v17 + 1600) <= 0x7D0 )
    {
      HIDWORD(v50) = 0;
      HIDWORD(v49) = 0;
      v53 = 0;
      v51 = dspp_buf[2 * v16 + 200 + v17];
      v52 = 0;
      v18 = *(__int64 (__fastcall **)(_QWORD))(v10 + 8);
      if ( *((_DWORD *)v18 - 1) != -1839634494 )
        __break(0x8228u);
      v19 = v18(&v48);
      if ( v19 )
      {
        result = _drm_err("write decode select failed ret %d\n", v19);
LABEL_34:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      v21 = _reg_dmav1_setup_demura_cfg_common(a1, v5, &v48, v10, a2, 22, 12, 1024);
      if ( v21 )
      {
        result = _drm_err("failed to setup_demurav1_cfg rc %d", v21);
        goto LABEL_34;
      }
      v22 = _reg_dmav1_setup_demura_cfg0_param4_common(a1, v5, &v48, v10, 6);
      if ( v22 )
      {
        result = _drm_err("failed setup demura v1 cfg0_param4 rc %d", v22);
        goto LABEL_34;
      }
      result = _reg_dmav1_setup_demurav1_en(a1, v5, &v48, v10, a2);
      if ( (_DWORD)result )
      {
        result = _drm_err("failed setup_demurav1_en rc %d", (unsigned int)result);
        goto LABEL_34;
      }
      v23 = (unsigned int)a1[16];
      v24 = a2[2];
      v40 = 0;
      v41 = 0;
      v38 = 0;
      v39 = 0;
      v36 = v24;
      v37 = 0;
      if ( (unsigned int)v23 > 4 )
        goto LABEL_44;
      v25 = (unsigned int)a1[374];
      if ( (unsigned int)v25 > 1 )
        goto LABEL_44;
      if ( (unsigned __int64)(16 * v23 + 8 * v25 + 1600) <= 0x7D0 )
      {
        v26 = a2[19];
        LODWORD(v41) = 20;
        v27 = &dspp_buf[2 * v23 + v25];
        v28 = *(_QWORD *)((char *)a2 + 164);
        v43 = *((_DWORD *)a2 + 40);
        v44 = v28;
        v29 = v27[200];
        LODWORD(v28) = *((_DWORD *)a2 + 43);
        v30 = *((_DWORD *)a2 + 44);
        LODWORD(v40) = 0;
        v42 = v26;
        v46 = v28;
        v47 = v30;
        v31 = *((_DWORD *)a2 + 7);
        v38 = v29;
        v45 = v31;
        v32 = *(_DWORD *)(v29 + 20);
        LODWORD(v37) = 1;
        _drm_dev_dbg(0, 0, 1, "enable demura v1 buffer size %d\n", v32);
        result = sde_evtlog_log(
                   sde_dbg_base_evtlog,
                   "reg_dmav1_setup_demurav1",
                   8251,
                   -1,
                   a1[16],
                   a1[374],
                   a1[7],
                   1,
                   239);
        v33 = (unsigned int)a1[7];
        if ( (unsigned int)v33 <= 2 )
        {
          v34 = *(__int64 (__fastcall **)(__int64 *, __int64))(v10 + 8 * v33 + 16);
          if ( v34 )
          {
            v35 = (unsigned int)a1[374];
            if ( *((_DWORD *)v34 - 1) != 1772228465 )
              __break(0x8228u);
            result = v34(&v36, v35);
            if ( (_DWORD)result )
              result = _drm_err("failed to kick off demurav1 ret %d\n", (unsigned int)result);
          }
          goto LABEL_34;
        }
        goto LABEL_44;
      }
    }
  }
LABEL_45:
  __break(1u);
  return reg_dma_demura_off(result, v9);
}
