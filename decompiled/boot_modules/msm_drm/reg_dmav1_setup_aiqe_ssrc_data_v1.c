void __fastcall reg_dmav1_setup_aiqe_ssrc_data_v1(__int64 a1, __int64 a2)
{
  __int64 v4; // x23
  int v5; // w25
  int v6; // w27
  char *ops; // x0
  __int64 v8; // x8
  __int64 v9; // x9
  char *v10; // x21
  unsigned __int64 v11; // x22
  void (__fastcall *v12)(_QWORD); // x8
  __int64 (__fastcall *v13)(_QWORD); // x9
  int v14; // w0
  _DWORD *v15; // x24
  int v16; // w8
  unsigned __int64 v17; // x26
  _DWORD *v18; // x25
  unsigned __int64 v19; // x28
  __int64 v20; // x27
  __int64 (__fastcall *v21)(_QWORD); // x8
  int v22; // w0
  __int64 (__fastcall *v23)(_QWORD); // x8
  int v24; // w0
  __int64 v25; // x8
  __int64 v26; // x8
  unsigned int v27; // w9
  __int64 (__fastcall *v28)(__int64 *, __int64); // x8
  __int64 v29; // x1
  int v30; // w0
  int v31; // w4
  int v32; // w5
  size_t v33; // x0
  int v34; // w6
  int v35; // w2
  int v36; // w7
  int v37; // [xsp+8h] [xbp-A8h]
  int v38; // [xsp+Ch] [xbp-A4h]
  __int64 v39; // [xsp+10h] [xbp-A0h] BYREF
  __int64 v40; // [xsp+18h] [xbp-98h]
  unsigned __int64 v41; // [xsp+20h] [xbp-90h]
  __int64 v42; // [xsp+28h] [xbp-88h]
  __int64 v43; // [xsp+30h] [xbp-80h]
  __int64 v44; // [xsp+38h] [xbp-78h]
  __int64 v45; // [xsp+40h] [xbp-70h]
  __int64 v46; // [xsp+48h] [xbp-68h]
  unsigned __int64 v47; // [xsp+50h] [xbp-60h]
  __int64 v48; // [xsp+58h] [xbp-58h]
  unsigned __int64 v49; // [xsp+60h] [xbp-50h] BYREF
  __int128 v50; // [xsp+68h] [xbp-48h]
  unsigned __int64 v51; // [xsp+78h] [xbp-38h]
  __int64 v52; // [xsp+80h] [xbp-30h]
  __int64 v53; // [xsp+88h] [xbp-28h]
  __int64 v54; // [xsp+90h] [xbp-20h]
  __int64 v55; // [xsp+98h] [xbp-18h]
  __int64 v56; // [xsp+A0h] [xbp-10h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int *)(a1 + 28);
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v51 = 0;
  v49 = 0;
  v50 = 0u;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  if ( (unsigned int)reg_dma_dspp_check((unsigned int *)a1, (_QWORD *)a2, 0x18u) )
    goto LABEL_2;
  v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 604LL);
  if ( !v5 )
  {
    _drm_dev_dbg(0, 0, 1, "MDNIE not present on DSPP idx %d", *(_DWORD *)(a1 + 64));
    goto LABEL_2;
  }
  v6 = *(_DWORD *)(a1 + 8);
  ops = sde_reg_dma_get_ops(*(_DWORD *)(a1 + 1496));
  v8 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v8 >= 5 )
    goto LABEL_36;
  v9 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v9 > 1 )
    goto LABEL_36;
  v10 = ops;
  v11 = dspp_buf[2 * v8 + 240 + v9];
  v12 = *((void (__fastcall **)(_QWORD))ops + 8);
  if ( *((_DWORD *)v12 - 1) != -870478129 )
    __break(0x8228u);
  v12(v11);
  v54 = 0;
  v55 = 0;
  v50 = 0x18u;
  v51 = v11;
  v52 = 0;
  v53 = 0;
  v13 = *((__int64 (__fastcall **)(_QWORD))v10 + 1);
  v49 = 0x8000000000000000LL;
  if ( *((_DWORD *)v13 - 1) != -1839634494 )
    __break(0x8229u);
  v14 = v13(&v49);
  if ( v14 )
  {
    _drm_err("write decode select failed ret %d\n", v14);
    goto LABEL_2;
  }
  v15 = *(_DWORD **)a2;
  if ( !*(_QWORD *)a2 )
  {
    v31 = *(_DWORD *)(a1 + 64);
    v32 = *(_DWORD *)(a1 + 1496);
    v33 = sde_dbg_base_evtlog;
    v34 = *(_DWORD *)(a1 + 28);
    v35 = 611;
    v36 = 0;
    goto LABEL_32;
  }
  if ( !*v15 )
  {
LABEL_25:
    v25 = *(_QWORD *)(a2 + 16);
    v43 = 0;
    v41 = v11;
    v42 = 0;
    v39 = v25;
    v40 = 1;
    v44 = 24;
    v26 = *(_QWORD *)(a2 + 160);
    v45 = *(_QWORD *)(a2 + 152);
    v46 = v26;
    v27 = *(_DWORD *)(a2 + 168);
    LODWORD(v26) = *(_DWORD *)(a2 + 176);
    LODWORD(v48) = *(_DWORD *)(a2 + 172);
    HIDWORD(v48) = v26;
    v47 = __PAIR64__(*(_DWORD *)(a2 + 28), v27);
    if ( (unsigned int)v4 <= 2 )
    {
      v28 = *(__int64 (__fastcall **)(__int64 *, __int64))&v10[8 * v4 + 16];
      if ( !v28 )
        goto LABEL_2;
      v29 = *(unsigned int *)(a1 + 1496);
      if ( *((_DWORD *)v28 - 1) != 1772228465 )
        __break(0x8228u);
      v30 = v28(&v39, v29);
      if ( v30 )
      {
        _drm_err("failed to kick off ret %d\n", v30);
        goto LABEL_2;
      }
      v31 = *(_DWORD *)(a1 + 64);
      v32 = *(_DWORD *)(a1 + 1496);
      v33 = sde_dbg_base_evtlog;
      v34 = *(_DWORD *)(a1 + 28);
      v35 = 645;
      v36 = 1;
LABEL_32:
      sde_evtlog_log(v33, "reg_dmav1_setup_aiqe_ssrc_data_v1", v35, -1, v31, v32, v34, v36, 239);
      goto LABEL_2;
    }
LABEL_36:
    __break(0x5512u);
  }
  v16 = v6 + v5;
  v17 = 0;
  v18 = v15 + 1;
  v37 = v16 + 16;
  v38 = v16 + 12;
  while ( 1 )
  {
    if ( v17 >> 3 > 0x280 )
      goto LABEL_36;
    v19 = v17 + 1;
    v20 = (unsigned int)v18[v17];
    *(_QWORD *)((char *)&v50 + 4) = 0;
    HIDWORD(v50) = v38;
    v52 = (__int64)&v18[v17 + 1];
    v53 = 0x400000000LL;
    v21 = *((__int64 (__fastcall **)(_QWORD))v10 + 1);
    LODWORD(v49) = 1;
    if ( *((_DWORD *)v21 - 1) != -1839634494 )
      __break(0x8228u);
    v22 = v21(&v49);
    if ( v22 )
    {
      _drm_err("write data phase 1 failed ret %d\n", v22);
      goto LABEL_2;
    }
    LODWORD(v49) = 3;
    HIDWORD(v50) = v37;
    HIDWORD(v53) = 4 * v20 - 4;
    if ( v17 == 5127 )
      goto LABEL_36;
    *(_QWORD *)((char *)&v50 + 4) = 0;
    LODWORD(v53) = 0;
    v52 = (__int64)&v18[v17 + 2];
    v23 = *((__int64 (__fastcall **)(_QWORD))v10 + 1);
    if ( *((_DWORD *)v23 - 1) != -1839634494 )
      __break(0x8228u);
    v24 = v23(&v49);
    if ( v24 )
      break;
    v17 = v19 + v20;
    if ( v19 + v20 >= (unsigned int)*v15 )
      goto LABEL_25;
  }
  _drm_err("write data phase 2 failed ret %d\n", v24);
LABEL_2:
  _ReadStatusReg(SP_EL0);
}
