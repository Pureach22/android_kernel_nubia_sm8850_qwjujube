__int64 __fastcall sde_encoder_trigger_flush(__int64 result, __int64 a2, _DWORD *a3, char a4)
{
  __int64 v7; // x20
  __int64 v8; // x8
  __int64 v9; // x0
  unsigned int v10; // w24
  __int64 v11; // x8
  __int64 v12; // x21
  int v13; // w4
  __int64 v14; // x8
  int v15; // w8
  _BOOL4 v16; // w27
  _BOOL4 v17; // w28
  _QWORD *v18; // x26
  _BOOL8 v19; // x25
  void (__fastcall *v20)(_QWORD); // x9
  void (__fastcall *v21)(__int64, __int64); // x8
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 (__fastcall *v25)(__int64, __int64, __int64); // x9
  __int64 v26; // x2
  __int64 (__fastcall *v27)(__int64, __int64, __int64); // x9
  __int64 v28; // x2
  __int64 v29; // x0
  __int64 (__fastcall *v30)(_QWORD); // x8
  int v32; // w23
  __int64 v33; // x27
  void (__fastcall *v34)(__int64, __int64, __int64, __int64); // x8
  _DWORD *v35; // x9
  __int64 v36; // x0
  __int64 v37; // x2
  __int64 v38; // x2
  _QWORD *v39; // x26
  _DWORD *v40; // x8
  int v41; // w7
  _DWORD *v42; // x8
  __int64 v43; // x0
  void (*v44)(void); // x8
  void (__fastcall *v45)(_QWORD); // x8
  _DWORD *v46; // x8
  void *v47; // x0
  void *v48; // x0
  unsigned int v55; // w9
  unsigned int v57; // w9
  char v58; // [xsp+0h] [xbp-70h]
  _QWORD v59[9]; // [xsp+28h] [xbp-48h] BYREF

  v59[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    result = printk(&unk_234F2E, "_sde_encoder_trigger_flush");
    goto LABEL_104;
  }
  v7 = result;
  if ( !result )
  {
LABEL_101:
    v10 = 0;
    v11 = *(_QWORD *)(a2 + 496);
    if ( v11 )
      goto LABEL_7;
LABEL_102:
    v47 = &unk_2198A7;
    goto LABEL_103;
  }
  if ( !*(_QWORD *)result )
  {
    v48 = &unk_26FCAB;
    goto LABEL_100;
  }
  v8 = *(_QWORD *)(*(_QWORD *)result + 56LL);
  if ( !v8 || (v9 = *(_QWORD *)(v8 + 8)) == 0 )
  {
    v48 = &unk_234896;
LABEL_100:
    result = printk(v48, "sde_encoder_get_kms");
    goto LABEL_101;
  }
  result = sde_kms_get_disp_op(v9, a2);
  v10 = result;
  v11 = *(_QWORD *)(a2 + 496);
  if ( !v11 )
    goto LABEL_102;
LABEL_7:
  v12 = *(_QWORD *)(a2 + 416);
  if ( !v12 || !*(_QWORD *)(a2 + 168) )
  {
    v47 = &unk_2198D5;
LABEL_103:
    result = printk(v47, "_sde_encoder_trigger_flush");
    goto LABEL_104;
  }
  if ( *(_DWORD *)(a2 + 664) == 4 )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      if ( *(_QWORD *)a2 )
        v13 = *(_DWORD *)(*(_QWORD *)a2 + 24LL);
      else
        v13 = -1;
      result = _drm_dev_dbg(
                 0,
                 0,
                 0,
                 "enc%d skip flush pp%d ctl%d\n",
                 v13,
                 *(_DWORD *)(v11 + 32) - 1,
                 *(_DWORD *)(v12 + 64) - 1);
    }
    goto LABEL_104;
  }
  v14 = *(_QWORD *)(a2 + 424);
  if ( !v14 )
  {
    v16 = 0;
    v17 = 0;
    v18 = *(_QWORD **)(a2 + 8);
    if ( v7 )
      goto LABEL_15;
LABEL_92:
    printk(&unk_26FCAB, "sde_encoder_check_curr_mode");
    v19 = 0;
    goto LABEL_16;
  }
  v15 = *(_DWORD *)(*(_QWORD *)(v14 + 40) + 48LL);
  v16 = v15 == 10;
  v17 = v15 == 3;
  v18 = *(_QWORD **)(a2 + 8);
  if ( !v7 )
    goto LABEL_92;
LABEL_15:
  v19 = *(_DWORD *)(v7 + 648) == 1;
LABEL_16:
  if ( *(_BYTE *)(v7 + 749) == 1 && !*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 512) + 152LL) + 52LL)
    || *(_BYTE *)(v7 + 752) == 1 )
  {
    if ( v10 >= 3 )
      goto LABEL_106;
    v20 = *(void (__fastcall **)(_QWORD))(v12 + 8LL * v10 + 352);
    if ( v20 )
    {
      if ( *((_DWORD *)v20 - 1) != 729814110 )
        __break(0x8229u);
      v20(v12);
      if ( (*(_BYTE *)(v7 + 749) & 1) == 0 )
        goto LABEL_32;
      goto LABEL_26;
    }
  }
  if ( *(_BYTE *)(v7 + 749) )
  {
LABEL_26:
    if ( *(_BYTE *)(a2 + 2348) == 1 && !*(_DWORD *)(v7 + 4912) )
    {
      v21 = (void (__fastcall *)(__int64, __int64))v18[406];
      if ( v21 )
      {
        v22 = v18[345];
        if ( *((_DWORD *)v21 - 1) != -1297827279 )
          __break(0x8228u);
        v21(v22, 1);
      }
    }
  }
LABEL_32:
  if ( *(_QWORD *)(v7 + 4960) )
  {
    v23 = *(_QWORD *)(a2 + 424);
    if ( v23 && v19 )
    {
      if ( v10 > 2 )
        goto LABEL_106;
      v25 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v12 + 1216 + 8LL * v10);
      if ( v25 )
      {
        if ( v16 )
          goto LABEL_46;
        v26 = *(unsigned int *)(v23 + 32);
        if ( *((_DWORD *)v25 - 1) != 325080504 )
          __break(0x8229u);
        if ( (v25(v12, 6, v26) & 1) != 0 )
          goto LABEL_46;
        v27 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v12 + 1216 + 8LL * v10);
        v28 = *(unsigned int *)(*(_QWORD *)(a2 + 424) + 32LL);
        if ( *((_DWORD *)v27 - 1) != 325080504 )
          __break(0x8229u);
        if ( (v27(v12, 7, v28) & 1) != 0 )
LABEL_46:
          sde_cesta_poll_handshake(*(_QWORD *)(v7 + 4960));
      }
    }
  }
  if ( v7 )
  {
    if ( *(_DWORD *)(v7 + 648) == 1 )
      sde_encoder_check_prog_fetch_region(v7);
  }
  else
  {
    printk(&unk_26FCAB, "sde_encoder_check_curr_mode");
  }
  v29 = raw_spin_lock_irqsave(v7 + 128);
  v30 = *(__int64 (__fastcall **)(_QWORD))(a2 + 32);
  v19 = v29;
  if ( v30 )
  {
    if ( *((_DWORD *)v30 - 1) != -1375811177 )
      __break(0x8228u);
    if ( (v30(a2) & 1) != 0 && (a4 & 1) != 0 )
      goto LABEL_107;
  }
  while ( 1 )
  {
    v32 = *(_DWORD *)(a2 + 880);
    if ( v16 || v17 )
      break;
    if ( v10 <= 2 )
    {
      v33 = v10;
      goto LABEL_69;
    }
LABEL_106:
    __break(0x5512u);
LABEL_107:
    _X8 = (unsigned int *)(a2 + 880);
    __asm { PRFM            #0x11, [X8] }
    do
      v55 = __ldxr(_X8);
    while ( __stxr(v55 + 1, _X8) );
    _X8 = (unsigned int *)(a2 + 884);
    __asm { PRFM            #0x11, [X8] }
    do
      v57 = __ldxr(_X8);
    while ( __stxr(v57 + 1, _X8) );
  }
  if ( v10 > 2 )
    goto LABEL_106;
  v33 = v10;
  v34 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v12 + 1192 + 8LL * v10);
  if ( v34 )
  {
    if ( *(_DWORD *)(a2 + 800) == 1 )
    {
      if ( *(_DWORD *)(a2 + 804) )
      {
        v35 = (_DWORD *)v18[364];
        if ( v35 )
        {
          v36 = *(_QWORD *)(a2 + 8);
          v37 = v18[345];
          if ( *(v35 - 1) != 720177154 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, _QWORD, __int64))v35)(v36, 0, v37);
          v34 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v12 + 1192 + 8LL * v10);
        }
      }
    }
    v38 = *(unsigned int *)(*(_QWORD *)(a2 + 424) + 32LL);
    if ( *((_DWORD *)v34 - 1) != 949740941 )
      __break(0x8228u);
    v34(v12, 6, v38, 1);
  }
LABEL_69:
  v39 = (_QWORD *)(v12 + 8 * v33);
  v40 = (_DWORD *)v39[83];
  if ( v40 && *(_BYTE *)(a2 + 2328) == 1 )
  {
    if ( *(v40 - 1) != 74273587 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v40)(v12, 0);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_encoder_trigger_flush",
      5236,
      -1,
      *(_DWORD *)(v7 + 24),
      13107,
      -1059143953,
      v41,
      v58);
  }
  if ( a3 )
  {
    if ( *a3 )
    {
      v42 = (_DWORD *)v39[92];
      if ( v42 )
      {
        if ( *(v42 - 1) != 1851168652 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _DWORD *))v42)(v12, a3);
      }
    }
  }
  v43 = *(_QWORD *)(a2 + 424);
  if ( v43 )
  {
    v44 = *(void (**)(void))(v43 + 8 * v33 + 272);
    if ( v44 )
    {
      if ( *((_DWORD *)v44 - 1) != 1550245701 )
        __break(0x8228u);
      v44();
    }
  }
  v45 = *(void (__fastcall **)(_QWORD))(a2 + 168);
  if ( *((_DWORD *)v45 - 1) != -511414616 )
    __break(0x8228u);
  v45(a2);
  raw_spin_unlock_irqrestore(v7 + 128, v19);
  v46 = (_DWORD *)v39[89];
  if ( v46 )
  {
    memset(v59, 0, 64);
    if ( *(v46 - 1) != 1851168652 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD *))v46)(v12, v59);
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "_sde_encoder_trigger_flush",
               5255,
               -1,
               *(_DWORD *)(v7 + 24),
               *(_DWORD *)(a2 + 672) - 1,
               *(_DWORD *)(v12 + 64) - 1,
               v59[0],
               v32);
  }
  else
  {
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "_sde_encoder_trigger_flush",
               5258,
               -1,
               *(_DWORD *)(v7 + 24),
               *(_DWORD *)(a2 + 672) - 1,
               *(_DWORD *)(v12 + 64) - 1,
               v32,
               **(_DWORD **)(*(_QWORD *)v7 + 64LL));
  }
LABEL_104:
  _ReadStatusReg(SP_EL0);
  return result;
}
