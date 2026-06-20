__int64 __fastcall reg_dmav1_setup_rc_pu_configv1(__int64 a1, __int64 a2)
{
  const void *v3; // x1
  __int64 v4; // x2
  unsigned int v6; // w4
  __int64 v7; // x1
  __int64 v8; // x2
  unsigned __int64 ops; // x21
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x9
  unsigned __int64 *v13; // x8
  __int64 (__fastcall *v14)(_QWORD); // x9
  unsigned __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 (__fastcall *v18)(_QWORD); // x8
  unsigned int v19; // w0
  unsigned int *v20; // x22
  __int64 v21; // x23
  int v22; // w6
  int v23; // w7
  int v24; // w4
  unsigned int v25; // w24
  void *v26; // x0
  void *v27; // x0
  __int64 v28; // x4
  __int64 v29; // x8
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x9
  __int64 v33; // x11
  unsigned int v34; // w10
  unsigned int v35; // w8
  _DWORD *v36; // x8
  _QWORD *v37; // x8
  __int64 v38; // x9
  __int64 v39; // x11
  __int64 v40; // x12
  __int64 v41; // x9
  __int64 v42; // x11
  __int64 v43; // x12
  void *v44; // x8
  unsigned int v45; // w19
  char v46; // [xsp+0h] [xbp-100h]
  __int64 v47; // [xsp+8h] [xbp-F8h] BYREF
  __int64 v48; // [xsp+10h] [xbp-F0h] BYREF
  __int64 v49; // [xsp+18h] [xbp-E8h] BYREF
  unsigned __int64 v50; // [xsp+20h] [xbp-E0h] BYREF
  __int64 v51; // [xsp+28h] [xbp-D8h]
  __int64 v52; // [xsp+30h] [xbp-D0h]
  unsigned __int64 v53; // [xsp+38h] [xbp-C8h]
  __int64 v54; // [xsp+40h] [xbp-C0h]
  __int64 v55; // [xsp+48h] [xbp-B8h]
  __int64 v56; // [xsp+50h] [xbp-B0h]
  __int64 v57; // [xsp+58h] [xbp-A8h]
  __int64 v58; // [xsp+60h] [xbp-A0h] BYREF
  __int64 v59; // [xsp+68h] [xbp-98h]
  unsigned __int64 v60; // [xsp+70h] [xbp-90h]
  __int128 v61; // [xsp+78h] [xbp-88h]
  __int64 v62; // [xsp+88h] [xbp-78h]
  __int64 v63; // [xsp+90h] [xbp-70h]
  __int64 v64; // [xsp+98h] [xbp-68h]
  unsigned __int64 v65; // [xsp+A0h] [xbp-60h]
  unsigned __int64 v66; // [xsp+A8h] [xbp-58h]
  __int64 v67; // [xsp+B0h] [xbp-50h] BYREF
  __int64 v68; // [xsp+B8h] [xbp-48h]
  __int64 v69; // [xsp+C0h] [xbp-40h]
  __int64 v70; // [xsp+C8h] [xbp-38h]
  __int64 v71; // [xsp+D0h] [xbp-30h]
  __int64 v72; // [xsp+D8h] [xbp-28h]
  __int64 v73; // [xsp+E0h] [xbp-20h]
  __int64 v74; // [xsp+E8h] [xbp-18h]
  __int64 v75; // [xsp+F0h] [xbp-10h]
  __int64 v76; // [xsp+F8h] [xbp-8h]

  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v62 = 0;
  v60 = 0;
  v61 = 0u;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v67 = 0;
  v48 = 0;
  v49 = 0;
  v47 = 0;
  if ( !a1 || !a2 )
  {
    v26 = &unk_227DF6;
LABEL_37:
    printk(v26, a2);
    result = 4294967274LL;
LABEL_56:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( *(_DWORD *)(a2 + 8) != 72 )
  {
    v26 = &unk_246925;
    goto LABEL_37;
  }
  v3 = *(const void **)(a2 + 16);
  v4 = *(unsigned int *)(a1 + 64);
  v6 = *(_DWORD *)(a1 + 1496);
  if ( !v3 || (unsigned int)v4 > 4 || v6 >= 2 )
  {
    _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", v3, v4, 19, v6);
LABEL_40:
    v27 = &unk_246948;
LABEL_41:
    printk(v27, 4294967274LL);
    result = 4294967274LL;
    goto LABEL_56;
  }
  if ( &dspp_buf[2 * v4] == (unsigned __int64 *)-1520LL )
  {
    _drm_err("invalid dma_buf\n");
    goto LABEL_40;
  }
  ops = sde_reg_dma_get_ops(v6);
  result = 4294967201LL;
  if ( !ops || ops > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_56;
  v11 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v11 >= 5 )
    goto LABEL_64;
  v12 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v12 > 1 )
    goto LABEL_64;
  if ( (unsigned __int64)(16 * v11 + 8 * v12 + 1520) > 0x7CF )
    goto LABEL_65;
  v13 = &dspp_buf[2 * v11 + v12];
  v14 = *(__int64 (__fastcall **)(_QWORD))(ops + 64);
  v15 = v13[190];
  if ( *((_DWORD *)v14 - 1) != -870478129 )
    __break(0x8229u);
  result = v14(v15);
  v16 = *(unsigned int *)(a1 + 64);
  v50 = 0x8000000000000000LL;
  v52 = 0;
  v53 = 0;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  v57 = 0;
  v51 = 19;
  if ( (unsigned int)v16 > 4 )
    goto LABEL_64;
  v17 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v17 > 1 )
    goto LABEL_64;
  if ( (unsigned __int64)(16 * v16 + 8 * v17 + 1520) > 0x7CF )
    goto LABEL_65;
  HIDWORD(v52) = 0;
  HIDWORD(v51) = 0;
  v55 = 0;
  v53 = dspp_buf[2 * v16 + 190 + v17];
  v54 = 0;
  v18 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
  if ( *((_DWORD *)v18 - 1) != -1839634494 )
    __break(0x8228u);
  v19 = v18(&v50);
  if ( v19 )
  {
    printk(&unk_23C6E2, v19);
    result = 4294967284LL;
    goto LABEL_56;
  }
  v20 = *(unsigned int **)a2;
  if ( !*(_QWORD *)a2 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "full frame update\n");
    v20 = (unsigned int *)&v67;
    v74 = 0;
    v75 = 0;
    v72 = 0;
    v73 = 0;
    v70 = 0;
    v71 = 0;
    v68 = 0;
    v69 = 0;
    v67 = 0;
  }
  v21 = *(_QWORD *)(a1 + 1480);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "reg_dmav1_setup_rc_pu_configv1",
    1681,
    -1,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 536LL),
    (int)v20,
    v21,
    *(_DWORD *)(v21 + 16),
    239);
  if ( !v21 || !*(_DWORD *)(v21 + 16) )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "no previous rc mask programmed\n");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "reg_dmav1_setup_rc_pu_configv1",
      1686,
      -1,
      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 536LL),
      -1059143953,
      v22,
      v23,
      v46);
    result = 1;
    goto LABEL_56;
  }
  sde_kms_rect_merge_rectangles(v20, (__int64)&v48);
  LODWORD(result) = sde_hw_rc_get_ajusted_roi(a2, &v48, &v49);
  if ( (_DWORD)result )
  {
    v44 = &unk_21E2E0;
    goto LABEL_62;
  }
  v24 = *(_DWORD *)(a2 + 28);
  if ( v24 == 1 )
  {
    v25 = 0;
    goto LABEL_44;
  }
  if ( v24 == 4 )
  {
    v25 = 3;
    goto LABEL_44;
  }
  if ( v24 != 2 )
  {
    _drm_err("invalid number of mixers:%d\n", v24);
    v27 = &unk_23FBD9;
    goto LABEL_41;
  }
  v25 = 1;
LABEL_44:
  _drm_dev_dbg(0, 0, 0, "number mixers:%u, merge mode:%u\n", v24, v25);
  LODWORD(result) = sde_hw_rc_get_param_rb(v21, &v49, (char *)&v47 + 4, &v47);
  if ( (_DWORD)result )
  {
    v44 = &unk_27E2C0;
    goto LABEL_62;
  }
  result = reg_dmav1_rc_program_enable_bits(
             a1,
             v21,
             *(unsigned int *)(v21 + 16),
             (unsigned int)v47,
             HIDWORD(v47),
             v25,
             &v49,
             ops,
             19);
  if ( (_DWORD)result )
  {
    v44 = &unk_274459;
    goto LABEL_62;
  }
  v28 = *(unsigned int *)(a1 + 64);
  v29 = *(_QWORD *)(a2 + 16);
  v62 = 0;
  v60 = 0;
  v61 = 0u;
  v58 = v29;
  v59 = 0;
  if ( (unsigned int)v28 > 4 )
    goto LABEL_64;
  v30 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v30 > 1 )
    goto LABEL_64;
  if ( (unsigned __int64)(16 * v28 + 8 * v30 + 1520) <= 0x7CF )
  {
    LODWORD(v59) = 1;
    v31 = *(unsigned int *)(a1 + 28);
    *(_QWORD *)((char *)&v61 + 4) = 1;
    v32 = *(_QWORD *)(a2 + 152);
    v33 = *(_QWORD *)(a2 + 160);
    LODWORD(v62) = 19;
    v63 = v32;
    v64 = v33;
    LODWORD(v32) = *(_DWORD *)(a2 + 172);
    v34 = *(_DWORD *)(a2 + 176);
    v60 = dspp_buf[2 * v28 + 190 + v30];
    v35 = *(_DWORD *)(a2 + 168);
    v66 = __PAIR64__(v34, v32);
    v65 = __PAIR64__(*(_DWORD *)(a2 + 28), v35);
    if ( (unsigned int)v31 <= 2 )
    {
      v36 = *(_DWORD **)(ops + 8 * v31 + 16);
      if ( !v36 )
      {
LABEL_55:
        sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_rc_pu_configv1", 1730, -1, v28, v30, v31, 1, 239);
        v37 = *(_QWORD **)(a1 + 1488);
        result = 0;
        *v37 = *(_QWORD *)v20;
        v38 = *((_QWORD *)v20 + 4);
        v39 = *((_QWORD *)v20 + 1);
        v40 = *((_QWORD *)v20 + 2);
        v37[3] = *((_QWORD *)v20 + 3);
        v37[4] = v38;
        v37[1] = v39;
        v37[2] = v40;
        v41 = *((_QWORD *)v20 + 8);
        v42 = *((_QWORD *)v20 + 5);
        v43 = *((_QWORD *)v20 + 6);
        v37[7] = *((_QWORD *)v20 + 7);
        v37[8] = v41;
        v37[5] = v42;
        v37[6] = v43;
        goto LABEL_56;
      }
      if ( *(v36 - 1) != 1772228465 )
        __break(0x8228u);
      LODWORD(result) = ((__int64 (__fastcall *)(__int64 *, _QWORD))v36)(&v58, (unsigned int)v30);
      if ( !(_DWORD)result )
      {
        LODWORD(v28) = *(_DWORD *)(a1 + 64);
        LODWORD(v30) = *(_DWORD *)(a1 + 1496);
        LODWORD(v31) = *(_DWORD *)(a1 + 28);
        goto LABEL_55;
      }
      v44 = &unk_277957;
LABEL_62:
      v45 = result;
      printk(v44, (unsigned int)result);
      result = v45;
      goto LABEL_56;
    }
LABEL_64:
    __break(0x5512u);
  }
LABEL_65:
  __break(1u);
  return sde_hw_rc_get_ajusted_roi(result, v7, v8);
}
