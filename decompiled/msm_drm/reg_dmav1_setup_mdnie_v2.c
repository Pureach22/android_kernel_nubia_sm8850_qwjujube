size_t __fastcall reg_dmav1_setup_mdnie_v2(__int64 a1, _QWORD *a2, const void *a3)
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
  __int64 *v19; // x22
  __int64 v20; // x8
  int v21; // w25
  __int64 (__fastcall *v22)(_QWORD); // x9
  unsigned int v23; // w0
  __int64 (__fastcall *v24)(_QWORD); // x9
  unsigned int v25; // w0
  __int64 v26; // x4
  __int64 v27; // x8
  __int64 v28; // x5
  __int64 v29; // x10
  int v30; // w8
  __int64 v31; // x10
  unsigned __int64 v32; // x8
  int v33; // w9
  _DWORD *v34; // x8
  int v35; // w0
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
  __int128 v49; // [xsp+60h] [xbp-40h]
  unsigned __int64 v50; // [xsp+70h] [xbp-30h]
  __int64 *v51; // [xsp+78h] [xbp-28h]
  __int64 v52; // [xsp+80h] [xbp-20h]
  __int64 v53; // [xsp+88h] [xbp-18h]
  __int64 v54; // [xsp+90h] [xbp-10h]
  __int64 v55; // [xsp+98h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v53 = 0;
  v54 = 0;
  v51 = nullptr;
  v52 = 0;
  v50 = 0;
  v48 = 0;
  v49 = 0u;
  if ( !a1 || !a2 || !a3 )
  {
    result = _drm_err("invalid parameters ctx %pK cfg %pK aiqe top %pK\n", (const void *)a1, a2, a3);
    goto LABEL_15;
  }
  v6 = *(unsigned int *)(a1 + 28);
  ops = sde_reg_dma_get_ops(*(_DWORD *)(a1 + 1496));
  v8 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v8 >= 5 )
    goto LABEL_41;
  v9 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v9 > 1 )
    goto LABEL_41;
  v10 = ops;
  v11 = &dspp_buf[2 * v8 + v9];
  v12 = *((void (__fastcall **)(_QWORD))ops + 8);
  v13 = v11[220];
  if ( *((_DWORD *)v12 - 1) != -870478129 )
    __break(0x8229u);
  v12(v13);
  v14 = *(unsigned int *)(a1 + 64);
  v48 = 0x8000000000000000LL;
  v49 = 0x16u;
  v50 = 0;
  v51 = nullptr;
  v52 = 0;
  v53 = 0;
  v54 = 0;
  if ( (unsigned int)v14 > 4 || (v15 = *(unsigned int *)(a1 + 1496), (unsigned int)v15 > 1) )
LABEL_41:
    __break(0x5512u);
  HIDWORD(v49) = 0;
  DWORD1(v49) = 0;
  v52 = 0;
  v50 = dspp_buf[2 * v14 + 220 + v15];
  v51 = nullptr;
  v16 = *((__int64 (__fastcall **)(_QWORD))v10 + 1);
  if ( *((_DWORD *)v16 - 1) != -1839634494 )
    __break(0x8228u);
  v17 = v16(&v48);
  if ( v17 )
  {
    result = _drm_err("write decode select failed ret %d\n", v17);
    goto LABEL_15;
  }
  result = ((__int64 (__fastcall *)(__int64, _QWORD *, const void *, char *, unsigned __int64 *))reg_dmav1_setup_mdnie_common)(
             a1,
             a2,
             a3,
             v10,
             &v48);
  if ( (_DWORD)result )
  {
    result = _drm_err("Setup of common mdnie feature failed");
    goto LABEL_15;
  }
  v19 = (__int64 *)*a2;
  if ( *a2 && (v19[1] & 1) != 0 )
  {
    v20 = *v19;
    v21 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 604LL) + *(_DWORD *)(a1 + 8);
    if ( (*v19 & 1) != 0 )
    {
      *(_QWORD *)((char *)&v49 + 4) = 0;
      HIDWORD(v49) = v21 + 1056;
      v51 = v19 + 60;
      v52 = 0x800000000LL;
      v22 = *((__int64 (__fastcall **)(_QWORD))v10 + 1);
      LODWORD(v48) = 2;
      if ( *((_DWORD *)v22 - 1) != -1839634494 )
        __break(0x8229u);
      v23 = v22(&v48);
      if ( v23 )
      {
        result = printk(&unk_2253CF, v23);
        goto LABEL_15;
      }
      v20 = *v19;
    }
    if ( (v20 & 2) != 0 )
    {
      *(_QWORD *)((char *)&v49 + 4) = 0;
      HIDWORD(v49) = v21 + 1064;
      v51 = v19 + 61;
      v52 = 0x4C00000000LL;
      v24 = *((__int64 (__fastcall **)(_QWORD))v10 + 1);
      LODWORD(v48) = 2;
      if ( *((_DWORD *)v24 - 1) != -1839634494 )
        __break(0x8229u);
      v25 = v24(&v48);
      if ( v25 )
      {
        result = printk(&unk_25BFDA, v25);
        goto LABEL_15;
      }
    }
    v26 = *(unsigned int *)(a1 + 64);
    v27 = a2[2];
    v40 = 0;
    v41 = 0;
    v38 = 0;
    v39 = 0;
    v36 = v27;
    v37 = 0;
    if ( (unsigned int)v26 <= 4 )
    {
      v28 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v28 <= 1 )
      {
        v29 = a2[19];
        LODWORD(v37) = 1;
        LODWORD(v41) = 22;
        v30 = *((_DWORD *)a2 + 40);
        v42 = v29;
        v31 = *(_QWORD *)((char *)a2 + 164);
        v43 = v30;
        v32 = dspp_buf[2 * v26 + 220 + v28];
        v44 = v31;
        LODWORD(v31) = *((_DWORD *)a2 + 43);
        v33 = *((_DWORD *)a2 + 44);
        v38 = v32;
        LODWORD(v32) = *((_DWORD *)a2 + 7);
        LODWORD(v40) = 0;
        v46 = v31;
        v47 = v33;
        v45 = v32;
        if ( (unsigned int)v6 <= 2 )
        {
          v34 = *(_DWORD **)&v10[8 * v6 + 16];
          if ( v34 )
          {
            if ( *(v34 - 1) != 1772228465 )
              __break(0x8228u);
            v35 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v34)(&v36, (unsigned int)v28);
            if ( v35 )
            {
              result = _drm_err("failed to kick off ret %d\n", v35);
              goto LABEL_15;
            }
            LODWORD(v26) = *(_DWORD *)(a1 + 64);
            LODWORD(v28) = *(_DWORD *)(a1 + 1496);
          }
          result = sde_evtlog_log(
                     sde_dbg_base_evtlog,
                     "reg_dmav1_setup_mdnie_v2",
                     418,
                     -1,
                     v26,
                     v28,
                     *(_DWORD *)(a1 + 28),
                     1,
                     239);
          goto LABEL_15;
        }
      }
    }
    goto LABEL_41;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
