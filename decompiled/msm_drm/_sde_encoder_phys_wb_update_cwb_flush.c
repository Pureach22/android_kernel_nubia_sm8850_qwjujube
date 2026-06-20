void __fastcall sde_encoder_phys_wb_update_cwb_flush(__int64 a1, char a2)
{
  unsigned int disp_op; // w0
  __int64 v4; // x26
  __int64 v5; // x8
  __int64 v6; // x21
  int v7; // w4
  __int64 v8; // x25
  __int64 v9; // x28
  __int64 v10; // x20
  __int64 v11; // x27
  int v12; // w24
  unsigned int v13; // w22
  __int64 v14; // x8
  int v15; // w5
  unsigned int v16; // w23
  __int64 v17; // x22
  _DWORD *v18; // x8
  __int64 v19; // x2
  void (__fastcall *v20)(__int64, __int64, __int64, __int64); // x8
  __int64 v21; // x2
  void (__fastcall *v22)(__int64, __int64, __int64); // x8
  __int64 v23; // x1
  __int64 v24; // x8
  void (*v25)(void); // x8
  __int64 v26; // x0
  unsigned int v27; // w0
  long double v28; // q0
  __int64 v29; // x25
  __int64 v30; // x23
  unsigned int v31; // w22
  _WORD *v32; // x8
  int v33; // w8
  int v34; // w9
  int v35; // w28
  __int64 v36; // x10
  __int64 v37; // x8
  unsigned int v38; // w24
  const void *blob; // x20
  unsigned int v40; // w25
  int v41; // w26
  unsigned int v42; // w27
  int v43; // w8
  __int64 v44; // x8
  void (__fastcall *v45)(__int64, __int64, __int64, __int64, __int64, long double); // x8
  int v46; // w21
  __int64 v47; // x1
  __int64 v48; // x3
  __int64 v49; // x0
  __int64 v50; // x2
  __int64 v51; // x4
  _DWORD *v52; // x8
  __int64 v53; // x3
  _DWORD *v54; // x8
  void (__fastcall *v55)(__int64, __int64, __int64, __int64, long double); // x8
  __int64 v56; // x9
  __int64 v57; // x2
  int v58; // [xsp+4h] [xbp-4Ch]
  __int64 v59; // [xsp+28h] [xbp-28h]
  __int64 v60; // [xsp+30h] [xbp-20h]
  _QWORD v62[2]; // [xsp+40h] [xbp-10h] BYREF

  v62[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  disp_op = sde_encoder_get_disp_op(*(_QWORD *)a1);
  if ( (*(_BYTE *)(a1 + 2290) & 1) == 0 )
  {
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_126;
    if ( *(_QWORD *)a1 )
    {
      v7 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
      if ( !a1 )
        goto LABEL_20;
    }
    else
    {
      v7 = -1;
      if ( !a1 )
        goto LABEL_20;
    }
    v14 = *(_QWORD *)(a1 + 2864);
    if ( v14 )
    {
      v15 = *(_DWORD *)(v14 + 12) - 1;
LABEL_21:
      _drm_dev_dbg(0, 0, 0, "enc:%d, wb:%d - not in CWB mode. early return\n", v7, v15);
      goto LABEL_126;
    }
LABEL_20:
    v15 = -1;
    goto LABEL_21;
  }
  v4 = *(_QWORD *)(a1 + 2936);
  v5 = *(_QWORD *)(v4 + 2008);
  if ( v5 )
  {
    v6 = *(_QWORD *)(v4 + 2208);
    if ( !v6 )
      goto LABEL_22;
  }
  else
  {
    v6 = *(_QWORD *)(v4 + 2208);
    if ( !v6 )
    {
LABEL_22:
      printk(&unk_232BB4, "_sde_encoder_phys_wb_update_cwb_flush");
      goto LABEL_126;
    }
  }
  v8 = *(_QWORD *)(a1 + 2680);
  if ( !v8 )
    goto LABEL_22;
  v9 = *(_QWORD *)(a1 + 496);
  if ( !v9 )
    goto LABEL_22;
  v10 = *(_QWORD *)(a1 + 432);
  v11 = *(_QWORD *)(a1 + 504);
  v12 = *(_DWORD *)(v9 + 32);
  v13 = *(_DWORD *)(*(_QWORD *)(v4 + 2200) + 32LL);
  if ( !*(_DWORD *)(a1 + 2292) && (!a1 || !v4 || !v5) )
  {
    v16 = disp_op;
    printk(&unk_247128, "_sde_encoder_is_single_lm_partial_update");
    disp_op = v16;
  }
  if ( (*(_QWORD *)(*(_QWORD *)(v8 + 56) + 32LL) & 0x40000) != 0 )
  {
    if ( (unsigned int)(*(_DWORD *)(v4 + 2192) + *(_DWORD *)(v9 + 48)) >= 6 )
    {
      printk(&unk_26DC11, "_sde_encoder_phys_wb_update_cwb_flush");
      goto LABEL_126;
    }
  }
  else if ( v13 > 1 || (unsigned int)(*(_DWORD *)(v4 + 2192) + v12) >= 8 )
  {
    printk(&unk_263455, "_sde_encoder_phys_wb_update_cwb_flush");
    goto LABEL_126;
  }
  if ( disp_op > 2 )
    goto LABEL_127;
  v17 = disp_op;
  v18 = *(_DWORD **)(v6 + 1192 + 8LL * disp_op);
  if ( v18 )
  {
    v19 = *(unsigned int *)(v8 + 48);
    if ( *(v18 - 1) != 949740941 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))v18)(v6, 0, v19, 1);
    v20 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v6 + 1192 + 8 * v17);
    if ( v20 && v10 )
    {
      v21 = *(unsigned int *)(v10 + 40);
      if ( *((_DWORD *)v20 - 1) != 949740941 )
        __break(0x8228u);
      v20(v6, 4, v21, 1);
    }
  }
  v22 = *(void (__fastcall **)(__int64, __int64, __int64))(v6 + 8 * v17 + 1240);
  if ( v22 && v11 )
  {
    v23 = *(unsigned int *)(v11 + 40);
    if ( *((_DWORD *)v22 - 1) != -1720921224 )
      __break(0x8228u);
    v22(v6, v23, 1);
  }
  v24 = *(_QWORD *)(v8 + 56);
  if ( (*(_QWORD *)(v24 + 32) & 0x20000) == 0 && (*(_QWORD *)(v24 + 32) & 0x40000) == 0 )
  {
    v25 = *(void (**)(void))(*(_QWORD *)(a1 + 408) + 8 * v17 + 296);
    if ( v25 )
    {
      if ( *((_DWORD *)v25 - 1) != 1066508607 )
        __break(0x8228u);
      v25();
    }
    goto LABEL_126;
  }
  v26 = *(_QWORD *)a1;
  v62[0] = 0;
  v27 = sde_encoder_get_disp_op(v26);
  v29 = *(_QWORD *)(a1 + 2936);
  v59 = *(_QWORD *)(v29 + 2208);
  if ( !v59 || (v30 = *(_QWORD *)(a1 + 2680)) == 0 || (v60 = *(_QWORD *)(a1 + 496)) == 0 )
  {
    printk(&unk_232BB4, "_sde_encoder_phys_wb_update_cwb_flush_helper");
    goto LABEL_126;
  }
  v31 = v27;
  if ( (a2 & 1) != 0 )
  {
    if ( !a1 || !v29 || (v32 = *(_WORD **)(v29 + 2008)) == nullptr )
    {
      printk(&unk_247128, "_sde_encoder_is_single_lm_partial_update");
      v36 = *(_QWORD *)(a1 + 2936);
      v33 = 0;
      v34 = 1;
      goto LABEL_74;
    }
    if ( *(_DWORD *)(v29 + 2192) != 2 )
      goto LABEL_71;
    if ( v32[280] )
    {
      if ( v32[281] )
      {
        if ( v32 != (_WORD *)-564LL && v32[284] )
        {
          v33 = (unsigned __int16)v32[285];
          if ( !v33 )
          {
            v34 = 1;
LABEL_73:
            v36 = *(_QWORD *)(a1 + 2936);
LABEL_74:
            if ( *(_DWORD *)(a1 + 2292) )
            {
              v33 = 1;
              v35 = 2;
            }
            else
            {
              v35 = v34;
            }
            goto LABEL_77;
          }
LABEL_72:
          v34 = 2;
          v33 = 1;
          goto LABEL_73;
        }
LABEL_71:
        v33 = 0;
        v34 = 1;
        goto LABEL_73;
      }
      if ( v32 == (_WORD *)-564LL )
        goto LABEL_72;
    }
    else if ( v32 == (_WORD *)-564LL )
    {
      goto LABEL_72;
    }
    if ( !v32[284] || !v32[285] )
      goto LABEL_72;
    goto LABEL_71;
  }
  v35 = *(_DWORD *)(v29 + 2192);
  v36 = *(_QWORD *)(a1 + 2936);
  v33 = (unsigned int)v35 > 1;
LABEL_77:
  v58 = v33;
  v37 = *(_QWORD *)(v36 + 2008);
  if ( v37 )
    v38 = *(_DWORD *)(v37 + 1472);
  else
    v38 = 0;
  blob = nullptr;
  v40 = *(_DWORD *)(*(_QWORD *)(v29 + 2200) + 32LL);
  if ( (*(_QWORD *)(*(_QWORD *)(v30 + 56) + 32LL) & 0x80000) != 0 )
  {
    if ( v38 )
    {
      blob = (const void *)msm_property_get_blob(
                             *(_QWORD *)(a1 + 8) + 3312LL,
                             *(_QWORD *)(*(_QWORD *)(a1 + 8) + 2512LL) + 448LL,
                             v62);
      if ( (_drm_debug & 4) != 0 )
        *(double *)&v28 = _drm_dev_dbg(0, 0, 0, "Read cwb dither setting from blob %pK\n", blob);
    }
  }
  if ( v35 >= 1 )
  {
    v41 = 0;
    v42 = 0;
    while ( 1 )
    {
      v43 = *(_DWORD *)(a1 + 2292);
      v40 += v41;
      if ( v43 )
      {
        if ( v43 == 2 )
        {
          v42 = v40 & 1 | 2;
        }
        else if ( v43 == 3 )
        {
          v42 = v40 + 2;
        }
        else
        {
          v42 = v40;
        }
      }
      v44 = *(_QWORD *)(v30 + 56);
      if ( (*(_QWORD *)(v44 + 32) & 0x40000) != 0 )
        break;
      if ( (*(_QWORD *)(v44 + 32) & 0x20000) != 0 )
      {
        if ( v31 > 2 )
          goto LABEL_127;
        v45 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, long double))(v30 + 376 + 8LL * v31);
        v46 = *(_DWORD *)(v60 + 32);
        if ( v45 )
        {
          v47 = (unsigned int)(v41 + v46);
          v48 = v38 == 1;
          v49 = v30;
          v50 = v40;
          v51 = a2 & 1;
          if ( *((_DWORD *)v45 - 1) != 364137501 )
            __break(0x8228u);
          goto LABEL_113;
        }
        goto LABEL_114;
      }
LABEL_86:
      if ( v35 == ++v41 )
        goto LABEL_118;
    }
    v46 = *(_DWORD *)(v60 + 48);
    if ( (*(_QWORD *)(v44 + 32) & 0x80000) != 0 )
    {
      if ( v31 > 2 )
        goto LABEL_127;
      v52 = *(_DWORD **)(v30 + 448 + 8LL * v31);
      if ( v52 )
      {
        v53 = v62[0];
        if ( *(v52 - 1) != -212505971 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, const void *, __int64, _QWORD, long double))v52)(
          v30,
          (unsigned int)(v41 + v46),
          blob,
          v53,
          a2 & 1,
          v28);
      }
    }
    else if ( v31 > 2 )
    {
      goto LABEL_127;
    }
    v45 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64, long double))(v30 + 400 + 8LL * v31);
    if ( !v45 || (v50 = v42, !*(_DWORD *)(a1 + 2292)) )
      v50 = v40;
    v47 = (unsigned int)(v41 + v46);
    v49 = v30;
    v48 = v38;
    v51 = a2 & 1;
    if ( *((_DWORD *)v45 - 1) != -380744289 )
      __break(0x8228u);
LABEL_113:
    v45(v49, v47, v50, v48, v51, v28);
LABEL_114:
    v54 = *(_DWORD **)(v59 + 1192 + 8LL * v31);
    if ( v54 )
    {
      if ( *(v54 - 1) != 949740941 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, __int64, long double))v54)(
        v59,
        5,
        (unsigned int)(v41 + v46),
        1,
        v28);
    }
    goto LABEL_86;
  }
LABEL_118:
  if ( !v58 )
    goto LABEL_126;
  if ( v31 > 2 )
LABEL_127:
    __break(0x5512u);
  v55 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, long double))(v59 + 8LL * v31 + 1192);
  if ( v55 )
  {
    v56 = *(_QWORD *)(v60 + 56);
    if ( v56 )
    {
      v57 = *(unsigned int *)(v56 + 32);
      if ( *((_DWORD *)v55 - 1) != 949740941 )
        __break(0x8228u);
      v55(v59, 3, v57, 1, v28);
    }
  }
LABEL_126:
  _ReadStatusReg(SP_EL0);
}
