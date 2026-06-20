__int64 __fastcall sde_encoder_helper_phys_disable(__int64 *a1, __int64 a2)
{
  __int64 *v4; // x8
  __int64 v5; // x19
  __int64 v6; // x8
  __int64 v7; // x8
  unsigned int disp_op; // w23
  void *v9; // x0
  __int64 (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x21
  __int64 v12; // x24
  _QWORD *v13; // x23
  void (__fastcall *v14)(_QWORD); // x8
  void (*v15)(void); // x8
  _DWORD *v16; // x8
  __int64 v17; // x2
  __int64 v18; // x22
  __int64 v19; // x25
  __int64 v20; // x9
  _DWORD *v21; // x8
  __int64 v22; // x0
  __int64 v23; // x2
  void (__fastcall *v24)(__int64, __int64, __int64, __int64); // x8
  __int64 v25; // x2
  __int64 v26; // x0
  void (*v27)(void); // x8
  void (__fastcall *v28)(__int64, __int64, __int64, __int64); // x8
  __int64 v29; // x9
  __int64 v30; // x2
  __int64 v31; // x0
  void (*v32)(void); // x8
  void (__fastcall *v33)(__int64, __int64, __int64, __int64); // x8
  __int64 v34; // x2
  __int64 v35; // x0
  void (*v36)(void); // x8
  void (__fastcall *v37)(__int64, __int64, __int64); // x8
  __int64 v38; // x1
  __int64 v39; // x22
  __int64 v40; // x25
  _DWORD *v41; // x8
  __int64 v42; // x0
  void (__fastcall *v43)(__int64, __int64, __int64, __int64); // x8
  __int64 v44; // x2
  __int64 v45; // x22
  _DWORD *v46; // x8
  __int64 v47; // x0
  void (__fastcall *v48)(__int64, __int64, __int64, __int64); // x8
  __int64 v49; // x2
  __int64 v50; // x22
  _DWORD *v51; // x8
  __int64 v52; // x0
  void (__fastcall *v53)(__int64, __int64, __int64, __int64); // x8
  __int64 v54; // x2
  __int64 v55; // x22
  _DWORD *v56; // x8
  __int64 v57; // x0
  void (__fastcall *v58)(__int64, __int64, __int64, __int64); // x8
  __int64 v59; // x2
  __int64 v60; // x8
  __int64 v61; // x8
  __int64 v62; // x8
  void (__fastcall *v63)(_QWORD); // x8
  int v64; // w7
  void (__fastcall *v65)(__int64, int *); // x8
  int v66; // w4
  __int64 v67; // x9
  void (__fastcall *v68)(__int64, __int64 *, __int64); // x8
  __int64 v69; // x9
  __int64 v70; // x2
  __int64 result; // x0
  __int64 (__fastcall *v72)(_QWORD); // x8
  __int64 (__fastcall *v73)(_QWORD); // x8
  __int64 (__fastcall *v74)(_QWORD); // x8
  char v75; // [xsp+0h] [xbp-50h]
  int v76[2]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v77; // [xsp+10h] [xbp-40h]
  __int64 v78; // [xsp+18h] [xbp-38h]
  __int64 v79; // [xsp+20h] [xbp-30h]
  __int64 v80; // [xsp+28h] [xbp-28h]
  __int64 v81; // [xsp+30h] [xbp-20h]
  __int64 v82; // [xsp+38h] [xbp-18h]
  __int64 v83; // [xsp+40h] [xbp-10h]
  __int64 v84; // [xsp+48h] [xbp-8h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (__int64 *)*a1;
  v5 = a1[52];
  v82 = 0;
  v83 = 0;
  v80 = 0;
  v81 = 0;
  v78 = 0;
  v79 = 0;
  *(_QWORD *)v76 = 0;
  v77 = 0;
  if ( v4 )
  {
    v6 = *v4;
    if ( v6 )
    {
      v7 = *(_QWORD *)(v6 + 56);
      if ( v7 && *(_QWORD *)(v7 + 8) )
      {
        disp_op = sde_kms_get_disp_op();
        goto LABEL_10;
      }
      v9 = &unk_234896;
    }
    else
    {
      v9 = &unk_26FCAB;
    }
    printk(v9, "sde_encoder_get_kms");
  }
  disp_op = 0;
LABEL_10:
  v10 = (__int64 (__fastcall *)(_QWORD))a1[4];
  v11 = *a1;
  if ( v10 )
  {
    if ( *((_DWORD *)v10 - 1) != -1375811177 )
      __break(0x8228u);
    if ( (v10(a1) & 1) != 0 )
      sde_encoder_cesta_update(v11, 4u);
  }
  if ( disp_op >= 3 )
    goto LABEL_136;
  v12 = disp_op;
  v13 = (_QWORD *)(v5 + 8LL * disp_op);
  v14 = (void (__fastcall *)(_QWORD))v13[116];
  if ( v14 )
  {
    if ( *((_DWORD *)v14 - 1) != 1800103338 )
      __break(0x8228u);
    v14(v5);
  }
  ((void (__fastcall *)(__int64 *, _QWORD))sde_encoder_helper_reset_mixers)(a1, 0);
  if ( a2 )
  {
    v15 = *(void (**)(void))(*(_QWORD *)(a2 + 2680) + 8 * v12 + 328);
    if ( v15 )
    {
      if ( *((_DWORD *)v15 - 1) != 1726930563 )
        __break(0x8228u);
      v15();
      v16 = (_DWORD *)v13[149];
      if ( v16 )
      {
        v17 = *(unsigned int *)(*(_QWORD *)(a2 + 2680) + 48LL);
        if ( *(v16 - 1) != 949740941 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))v16)(v5, 0, v17, 1);
      }
    }
  }
  else if ( *(_DWORD *)(v11 + 196) )
  {
    v18 = 0;
    v19 = v11 + 200;
    while ( v18 != 4 )
    {
      v20 = *(_QWORD *)(v19 + 8 * v18);
      if ( v20 )
      {
        v21 = *(_DWORD **)(a1[53] + 8 * v12 + 416);
        if ( v21 )
        {
          v22 = *(_QWORD *)(v20 + 424);
          v23 = *(unsigned int *)(*(_QWORD *)(v20 + 496) + 32LL);
          if ( *(v21 - 1) != 530145669 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64))v21)(v22, 0, v23);
          v24 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v5 + 1192 + 8 * v12);
          if ( v24 )
          {
            v25 = *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(v19 + 8 * v18) + 424LL) + 32LL);
            if ( *((_DWORD *)v24 - 1) != 949740941 )
              __break(0x8228u);
            v24(v5, 7, v25, 1);
          }
        }
      }
      if ( ++v18 >= (unsigned __int64)*(unsigned int *)(v11 + 196) )
        goto LABEL_40;
    }
    goto LABEL_136;
  }
LABEL_40:
  v26 = a1[62];
  if ( v26 )
  {
    v27 = *(void (**)(void))(v26 + 8 * v12 + 400);
    if ( v27 )
    {
      if ( *((_DWORD *)v27 - 1) != 1021724354 )
        __break(0x8228u);
      v27();
      v28 = (void (__fastcall *)(__int64, __int64, __int64, __int64))v13[149];
      if ( v28 )
      {
        v29 = *(_QWORD *)(a1[62] + 56);
        if ( v29 )
        {
          v30 = *(unsigned int *)(v29 + 32);
          if ( *((_DWORD *)v28 - 1) != 949740941 )
            __break(0x8228u);
          v28(v5, 3, v30, 1);
        }
      }
    }
  }
  v31 = a1[54];
  if ( v31 )
  {
    v32 = *(void (**)(void))(v31 + 8 * v12 + 152);
    if ( v32 )
    {
      if ( a1[62] )
      {
        if ( *((_DWORD *)v32 - 1) != 396898043 )
          __break(0x8228u);
        v32();
        v33 = (void (__fastcall *)(__int64, __int64, __int64, __int64))v13[149];
        if ( v33 )
        {
          v34 = *(unsigned int *)(a1[54] + 40);
          if ( *((_DWORD *)v33 - 1) != 949740941 )
            __break(0x8228u);
          v33(v5, 4, v34, 1);
        }
      }
    }
  }
  v35 = a1[63];
  if ( v35 )
  {
    v36 = *(void (**)(void))(v35 + 8 * v12 + 96);
    if ( v36 )
    {
      if ( a1[62] )
      {
        if ( *((_DWORD *)v36 - 1) != 1605504302 )
          __break(0x8228u);
        v36();
        v37 = (void (__fastcall *)(__int64, __int64, __int64))v13[155];
        if ( v37 )
        {
          v38 = *(unsigned int *)(a1[63] + 40);
          if ( *((_DWORD *)v37 - 1) != -1720921224 )
            __break(0x8228u);
          v37(v5, v38, 1);
        }
      }
    }
  }
  if ( *(__int64 **)(v11 + 328) == a1 )
  {
    v67 = a1[62];
    if ( v67 )
    {
      v68 = (void (__fastcall *)(__int64, __int64 *, __int64))v13[104];
      if ( v68 )
      {
        v69 = *(_QWORD *)(v67 + 56);
        if ( v69 )
          v70 = *(unsigned int *)(v69 + 32);
        else
          v70 = 0;
        if ( *((_DWORD *)v68 - 1) != -1549349620 )
          __break(0x8228u);
        v68(v5, a1 + 87, v70);
      }
    }
  }
  v39 = *(_QWORD *)(v11 + 368);
  v40 = v5 + 1192;
  if ( v39 )
  {
    v41 = *(_DWORD **)(v39 + 8 * v12 + 120);
    if ( v41 )
    {
      v42 = *(_QWORD *)(v11 + 368);
      if ( *(v41 - 1) != 46373723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64))v41)(v42, 0, 14);
      v43 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v40 + 8 * v12);
      if ( v43 )
      {
        v44 = *(unsigned int *)(v39 + 32);
        if ( *((_DWORD *)v43 - 1) != 949740941 )
          __break(0x8228u);
        v43(v5, 1, v44, 1);
      }
    }
  }
  v45 = *(_QWORD *)(v11 + 376);
  if ( v45 )
  {
    v46 = *(_DWORD **)(v45 + 8 * v12 + 120);
    if ( v46 )
    {
      v47 = *(_QWORD *)(v11 + 376);
      if ( *(v46 - 1) != 46373723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64))v46)(v47, 0, 14);
      v48 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v40 + 8 * v12);
      if ( v48 )
      {
        v49 = *(unsigned int *)(v45 + 32);
        if ( *((_DWORD *)v48 - 1) != 949740941 )
          __break(0x8228u);
        v48(v5, 1, v49, 1);
      }
    }
  }
  v50 = *(_QWORD *)(v11 + 384);
  if ( v50 )
  {
    v51 = *(_DWORD **)(v50 + 8 * v12 + 120);
    if ( v51 )
    {
      v52 = *(_QWORD *)(v11 + 384);
      if ( *(v51 - 1) != 46373723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64))v51)(v52, 0, 14);
      v53 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v40 + 8 * v12);
      if ( v53 )
      {
        v54 = *(unsigned int *)(v50 + 32);
        if ( *((_DWORD *)v53 - 1) != 949740941 )
          __break(0x8228u);
        v53(v5, 1, v54, 1);
      }
    }
  }
  v55 = *(_QWORD *)(v11 + 392);
  if ( v55 )
  {
    v56 = *(_DWORD **)(v55 + 8 * v12 + 120);
    if ( v56 )
    {
      v57 = *(_QWORD *)(v11 + 392);
      if ( *(v56 - 1) != 46373723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64))v56)(v57, 0, 14);
      v58 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v40 + 8 * v12);
      if ( v58 )
      {
        v59 = *(unsigned int *)(v55 + 32);
        if ( *((_DWORD *)v58 - 1) != 949740941 )
          __break(0x8228u);
        v58(v5, 1, v59, 1);
      }
    }
  }
  v60 = a1[64];
  if ( v60 )
  {
    v61 = *(_QWORD *)(v60 + 152);
    if ( *(_DWORD *)(v61 + 52) || *(_BYTE *)(v61 + 22140) == 1 )
    {
      v62 = *(unsigned int *)(v5 + 28);
      if ( (unsigned int)v62 < 3 )
      {
        v63 = *(void (__fastcall **)(_QWORD))(v5 + 8 * v62 + 352);
        if ( v63 )
        {
          if ( *((_DWORD *)v63 - 1) != 729814110 )
            __break(0x8228u);
          v63(v5);
        }
        goto LABEL_108;
      }
LABEL_136:
      __break(0x5512u);
    }
  }
LABEL_108:
  sde_crtc_disable_cp_features();
  v65 = (void (__fastcall *)(__int64, int *))v13[89];
  if ( v65 )
  {
    if ( *((_DWORD *)v65 - 1) != 1851168652 )
      __break(0x8228u);
    v65(v5, v76);
  }
  if ( *a1 )
    v66 = *(_DWORD *)(*a1 + 24);
  else
    v66 = -1;
  result = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_encoder_helper_phys_disable",
             4588,
             -1,
             v66,
             v76[0],
             -1059143953,
             v64,
             v75);
  v72 = (__int64 (__fastcall *)(_QWORD))v13[95];
  if ( v72 )
  {
    if ( *((_DWORD *)v72 - 1) != 1800103338 )
      __break(0x8228u);
    result = v72(v5);
  }
  v73 = (__int64 (__fastcall *)(_QWORD))v13[71];
  if ( v73 )
  {
    if ( *((_DWORD *)v73 - 1) != 1800103338 )
      __break(0x8228u);
    result = v73(v5);
  }
  v74 = (__int64 (__fastcall *)(_QWORD))v13[86];
  if ( v74 )
  {
    if ( *((_DWORD *)v74 - 1) != 1800103338 )
      __break(0x8228u);
    result = v74(v5);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
