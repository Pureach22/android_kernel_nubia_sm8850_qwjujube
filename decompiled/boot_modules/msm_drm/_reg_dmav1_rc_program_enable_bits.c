__int64 __fastcall reg_dmav1_rc_program_enable_bits(
        __int64 a1,
        __int64 *a2,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7,
        __int64 a8,
        unsigned int a9)
{
  __int64 v13; // x8
  __int64 *v14; // x21
  char *v15; // x10
  int v16; // w23
  __int64 v17; // x25
  __int64 v18; // x26
  __int64 v19; // x24
  __int64 v20; // x8
  __int64 v21; // x9
  _BOOL4 v22; // w12
  _BOOL4 v23; // w13
  bool v24; // zf
  int v25; // w15
  int v26; // w16
  bool v27; // w14
  unsigned int v28; // w7
  unsigned int v29; // w12
  size_t v30; // x0
  int v31; // w2
  int v32; // w4
  int v33; // w5
  _BOOL4 v34; // w27
  __int64 v35; // x9
  int v36; // w10
  __int64 v37; // x9
  __int64 v38; // x8
  int v39; // w11
  __int64 v40; // x9
  __int64 v41; // x23
  __int64 (__fastcall *v42)(_QWORD); // x10
  unsigned int v43; // w0
  __int64 v44; // x8
  int v45; // w10
  __int64 v46; // x9
  __int64 v47; // x8
  int v48; // w11
  __int64 v49; // x9
  __int64 (__fastcall *v50)(_QWORD); // x10
  unsigned int v51; // w0
  __int64 v52; // x8
  int v53; // w10
  __int64 v54; // x9
  __int64 v55; // x8
  int v56; // w11
  __int64 v57; // x9
  __int64 (__fastcall *v58)(_QWORD); // x10
  __int64 result; // x0
  unsigned int v60; // w19
  int v61; // [xsp+3Ch] [xbp-64h]
  int v62; // [xsp+40h] [xbp-60h]
  int v63; // [xsp+44h] [xbp-5Ch]
  int v65; // [xsp+50h] [xbp-50h] BYREF
  unsigned int v66; // [xsp+54h] [xbp-4Ch]
  unsigned int v67; // [xsp+58h] [xbp-48h]
  __int64 v68; // [xsp+5Ch] [xbp-44h]
  int v69; // [xsp+64h] [xbp-3Ch]
  unsigned __int64 v70; // [xsp+68h] [xbp-38h]
  int *v71; // [xsp+70h] [xbp-30h]
  __int64 v72; // [xsp+78h] [xbp-28h]
  __int64 v73; // [xsp+80h] [xbp-20h]
  __int64 v74; // [xsp+88h] [xbp-18h]
  int v75; // [xsp+94h] [xbp-Ch] BYREF
  __int64 v76; // [xsp+98h] [xbp-8h]

  v76 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a7 )
  {
    printk(&unk_227DF6, a2);
    goto LABEL_55;
  }
  v13 = 0;
  v14 = a2 + 2560;
  while ( 1 )
  {
    if ( *(_DWORD *)((char *)&config_table + v13 + 12) == a6 && *(_DWORD *)((char *)&config_table + v13) == a3 )
    {
      v15 = (char *)&config_table + v13;
      if ( *(_DWORD *)((char *)&config_table + v13 + 4) == a4 )
        break;
    }
    v13 += 20;
    if ( v13 == 480 )
    {
      _drm_err("configuration not supported");
      printk(&unk_26D447, 4294967274LL);
      goto LABEL_55;
    }
  }
  v16 = *((_DWORD *)v15 + 2);
  v63 = *((_DWORD *)v15 + 4);
  _drm_dev_dbg(0, 0, 0, "found param_c:0x%08X, merge_mode_en:%d\n", v16, v63);
  v17 = *a2;
  v18 = *((unsigned int *)v14 + 343);
  v19 = *((unsigned int *)v14 + 342);
  v20 = *a2 & 0x1E0;
  v21 = *a2 & 0x1E;
  v22 = v20 != 480;
  v23 = (a5 & 0xFFFFFFFE) == 2;
  v24 = (a5 & 0xFFFFFFFD) != 1 || v21 == 30;
  v25 = !v24;
  if ( v24 )
    v26 = 16;
  else
    v26 = 17;
  v27 = v23 && v22;
  if ( !v23 || !v22 )
    v26 = v25;
  if ( v25 )
  {
    v28 = *(unsigned __int16 *)(a7 + 2);
    v29 = *(unsigned __int16 *)(a7 + 6);
    if ( *(_WORD *)(a7 + 2) || *((_DWORD *)a2 + 2) > v29 )
    {
      v30 = sde_dbg_base_evtlog;
      v31 = 384;
      v32 = 4369;
      v33 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 536LL);
LABEL_54:
      sde_evtlog_log(v30, "_reg_dmav1_rc_program_enable_bits", v31, -1, v32, v33, 1, v28, v29);
LABEL_55:
      result = 4294967274LL;
      goto LABEL_56;
    }
  }
  v28 = *(unsigned __int16 *)(a7 + 2);
  if ( v27 )
  {
    v29 = *(unsigned __int16 *)(a7 + 6);
    if ( v29 + v28 != (_DWORD)v19 || *((_DWORD *)a2 + 3) < v28 )
    {
      v30 = sde_dbg_base_evtlog;
      v31 = 392;
      v32 = 8738;
      v33 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 536LL);
      goto LABEL_54;
    }
  }
  v61 = v26;
  v62 = *(unsigned __int16 *)(a7 + 2);
  if ( (_drm_debug & 4) != 0 )
  {
    v34 = v21 != 30;
    _drm_dev_dbg(
      0,
      0,
      0,
      "idx:%d w:%lld h:%lld flags:%llx, R1:%d, R2:%d, PU R1:%d, PU R2:%d, Y_START:%d\n",
      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 536LL),
      v18,
      v19,
      v17,
      v34,
      v20 != 480,
      (a5 & 0xFFFFFFFD) == 1,
      (a5 & 0xFFFFFFFE) == 2,
      v28);
  }
  else
  {
    LOBYTE(v34) = v21 != 30;
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "_reg_dmav1_rc_program_enable_bits",
    402,
    -1,
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 536LL),
    v18,
    v19,
    v17,
    v34);
  v35 = *(_QWORD *)(a1 + 72);
  v36 = *(_DWORD *)(a1 + 8);
  v66 = 0x80000000;
  v67 = a9;
  v37 = *(_QWORD *)(v35 + 48);
  v73 = 0;
  v74 = 0;
  v75 = v61 | v16;
  v38 = *(unsigned int *)(a1 + 64);
  v39 = *(_DWORD *)(v37 + 524);
  if ( (unsigned int)v38 >= 5 )
    goto LABEL_58;
  v40 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v40 > 1 )
    goto LABEL_58;
  v41 = 80LL * a9;
  if ( ((v41 + 16 * v38) | (unsigned __int64)(8 * v40)) > 0x7CF )
    goto LABEL_59;
  v68 = 0;
  v69 = v36 + v39 + 4;
  v42 = *(__int64 (__fastcall **)(_QWORD))(a8 + 8);
  v65 = 1;
  v70 = dspp_buf[10 * a9 + 2 * v38 + v40];
  v71 = &v75;
  v72 = 0x400000000LL;
  if ( *((_DWORD *)v42 - 1) != -1839634494 )
    __break(0x822Au);
  v43 = v42(&v65);
  if ( v43 )
    printk(&unk_27AAB6, v43);
  v44 = *(_QWORD *)(a1 + 72);
  v45 = *(_DWORD *)(a1 + 8);
  v66 = 0x80000000;
  v67 = a9;
  v75 = v62;
  v46 = *(_QWORD *)(v44 + 48);
  v47 = *(unsigned int *)(a1 + 64);
  v73 = 0;
  v74 = 0;
  v48 = *(_DWORD *)(v46 + 524);
  if ( (unsigned int)v47 >= 5 )
    goto LABEL_58;
  v49 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v49 > 1 )
    goto LABEL_58;
  if ( ((v41 + 16 * v47) | (unsigned __int64)(8 * v49)) > 0x7CF
    || ((16 * v47 + 80LL * a9) | (unsigned __int64)(8 * v49)) > 0x7CF )
  {
LABEL_59:
    __break(1u);
  }
  v69 = v45 + v48 + 52;
  v50 = *(__int64 (__fastcall **)(_QWORD))(a8 + 8);
  v68 = 0;
  v65 = 1;
  v70 = dspp_buf[10 * a9 + 2 * v47 + v49];
  v71 = &v75;
  v72 = 0x400000000LL;
  if ( *((_DWORD *)v50 - 1) != -1839634494 )
    __break(0x822Au);
  v51 = v50(&v65);
  if ( v51 )
    printk(&unk_27AAB6, v51);
  v52 = *(_QWORD *)(a1 + 72);
  v53 = *(_DWORD *)(a1 + 8);
  v66 = 0x80000000;
  v67 = a9;
  v75 = v63;
  v54 = *(_QWORD *)(v52 + 48);
  v55 = *(unsigned int *)(a1 + 64);
  v73 = 0;
  v74 = 0;
  v56 = *(_DWORD *)(v54 + 524);
  if ( (unsigned int)v55 >= 5 || (v57 = *(unsigned int *)(a1 + 1496), (unsigned int)v57 > 1) )
  {
LABEL_58:
    __break(0x5512u);
    goto LABEL_59;
  }
  if ( ((v41 + 16 * v55) | (unsigned __int64)(8 * v57)) > 0x7CF
    || ((16 * v55 + 80LL * a9) | (unsigned __int64)(8 * v57)) > 0x7CF )
  {
    goto LABEL_59;
  }
  v69 = v53 + v56 + 36;
  v58 = *(__int64 (__fastcall **)(_QWORD))(a8 + 8);
  v68 = 0;
  v65 = 1;
  v70 = dspp_buf[10 * a9 + 2 * v55 + v57];
  v71 = &v75;
  v72 = 0x400000000LL;
  if ( *((_DWORD *)v58 - 1) != -1839634494 )
    __break(0x822Au);
  result = v58(&v65);
  if ( (_DWORD)result )
  {
    v60 = result;
    printk(&unk_27AAB6, (unsigned int)result);
    result = v60;
  }
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return result;
}
