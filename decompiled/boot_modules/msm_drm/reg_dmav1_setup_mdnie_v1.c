size_t __fastcall reg_dmav1_setup_mdnie_v1(__int64 a1, __int64 a2, const void *a3)
{
  __int64 v6; // x23
  char *ops; // x0
  __int64 v8; // x8
  __int64 v9; // x9
  char *v10; // x21
  unsigned __int64 *v11; // x8
  void (__fastcall *v12)(_QWORD); // x9
  unsigned __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 (__fastcall *v16)(_QWORD); // x8
  int v17; // w0
  size_t result; // x0
  __int64 v19; // x4
  __int64 v20; // x8
  __int64 v21; // x5
  __int64 v22; // x10
  int v23; // w8
  __int64 v24; // x10
  unsigned __int64 v25; // x8
  int v26; // w9
  _DWORD *v27; // x8
  int v28; // w0
  __int64 v29; // [xsp+8h] [xbp-98h] BYREF
  __int64 v30; // [xsp+10h] [xbp-90h]
  unsigned __int64 v31; // [xsp+18h] [xbp-88h]
  __int64 v32; // [xsp+20h] [xbp-80h]
  __int64 v33; // [xsp+28h] [xbp-78h]
  __int64 v34; // [xsp+30h] [xbp-70h]
  __int64 v35; // [xsp+38h] [xbp-68h]
  int v36; // [xsp+40h] [xbp-60h]
  __int64 v37; // [xsp+44h] [xbp-5Ch]
  int v38; // [xsp+4Ch] [xbp-54h]
  int v39; // [xsp+50h] [xbp-50h]
  int v40; // [xsp+54h] [xbp-4Ch]
  unsigned __int64 v41; // [xsp+58h] [xbp-48h] BYREF
  __int64 v42; // [xsp+60h] [xbp-40h]
  __int64 v43; // [xsp+68h] [xbp-38h]
  unsigned __int64 v44; // [xsp+70h] [xbp-30h]
  __int64 v45; // [xsp+78h] [xbp-28h]
  __int64 v46; // [xsp+80h] [xbp-20h]
  __int64 v47; // [xsp+88h] [xbp-18h]
  __int64 v48; // [xsp+90h] [xbp-10h]
  __int64 v49; // [xsp+98h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  if ( !a1 || !a2 || !a3 )
  {
    result = _drm_err("invalid parameters ctx %pK cfg %pK aiqe top %pK\n", (const void *)a1, (const void *)a2, a3);
    goto LABEL_15;
  }
  v6 = *(unsigned int *)(a1 + 28);
  ops = sde_reg_dma_get_ops(*(_DWORD *)(a1 + 1496));
  v8 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v8 >= 5 )
    goto LABEL_30;
  v9 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v9 > 1 )
    goto LABEL_30;
  v10 = ops;
  v11 = &dspp_buf[2 * v8 + v9];
  v12 = *((void (__fastcall **)(_QWORD))ops + 8);
  v13 = v11[220];
  if ( *((_DWORD *)v12 - 1) != -870478129 )
    __break(0x8229u);
  v12(v13);
  v14 = *(unsigned int *)(a1 + 64);
  v41 = 0x8000000000000000LL;
  v42 = 22;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v47 = 0;
  v48 = 0;
  if ( (unsigned int)v14 > 4 || (v15 = *(unsigned int *)(a1 + 1496), (unsigned int)v15 > 1) )
LABEL_30:
    __break(0x5512u);
  HIDWORD(v43) = 0;
  HIDWORD(v42) = 0;
  v46 = 0;
  v44 = dspp_buf[2 * v14 + 220 + v15];
  v45 = 0;
  v16 = *((__int64 (__fastcall **)(_QWORD))v10 + 1);
  if ( *((_DWORD *)v16 - 1) != -1839634494 )
    __break(0x8228u);
  v17 = v16(&v41);
  if ( v17 )
  {
    result = _drm_err("write decode select failed ret %d\n", v17);
    goto LABEL_15;
  }
  result = ((__int64 (__fastcall *)(__int64, __int64, const void *, char *, unsigned __int64 *))reg_dmav1_setup_mdnie_common)(
             a1,
             a2,
             a3,
             v10,
             &v41);
  if ( (_DWORD)result )
  {
    result = _drm_err("Setup of common mdnie feature failed");
    goto LABEL_15;
  }
  if ( *(_QWORD *)a2 && (*(_BYTE *)(*(_QWORD *)a2 + 8LL) & 1) != 0 )
  {
    v19 = *(unsigned int *)(a1 + 64);
    v20 = *(_QWORD *)(a2 + 16);
    v33 = 0;
    v34 = 0;
    v31 = 0;
    v32 = 0;
    v29 = v20;
    v30 = 0;
    if ( (unsigned int)v19 <= 4 )
    {
      v21 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v21 <= 1 )
      {
        v22 = *(_QWORD *)(a2 + 152);
        LODWORD(v30) = 1;
        LODWORD(v34) = 22;
        v23 = *(_DWORD *)(a2 + 160);
        v35 = v22;
        v24 = *(_QWORD *)(a2 + 164);
        v36 = v23;
        v25 = dspp_buf[2 * v19 + 220 + v21];
        v37 = v24;
        LODWORD(v24) = *(_DWORD *)(a2 + 172);
        v26 = *(_DWORD *)(a2 + 176);
        v31 = v25;
        LODWORD(v25) = *(_DWORD *)(a2 + 28);
        LODWORD(v33) = 0;
        v39 = v24;
        v40 = v26;
        v38 = v25;
        if ( (unsigned int)v6 <= 2 )
        {
          v27 = *(_DWORD **)&v10[8 * v6 + 16];
          if ( v27 )
          {
            if ( *(v27 - 1) != 1772228465 )
              __break(0x8228u);
            v28 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v27)(&v29, (unsigned int)v21);
            if ( v28 )
            {
              result = _drm_err("failed to kick off ret %d\n", v28);
              goto LABEL_15;
            }
            LODWORD(v19) = *(_DWORD *)(a1 + 64);
            LODWORD(v21) = *(_DWORD *)(a1 + 1496);
          }
          result = sde_evtlog_log(
                     sde_dbg_base_evtlog,
                     "reg_dmav1_setup_mdnie_v1",
                     341,
                     -1,
                     v19,
                     v21,
                     *(_DWORD *)(a1 + 28),
                     1,
                     239);
          goto LABEL_15;
        }
      }
    }
    goto LABEL_30;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
