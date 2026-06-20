_QWORD *__fastcall sde_encoder_phys_vid_vblank_irq(_QWORD *result)
{
  __int64 v1; // x20
  _QWORD *v2; // x19
  __int64 v3; // x26
  __int64 v4; // x23
  unsigned int v5; // w24
  unsigned __int64 StatusReg; // x20
  __int64 v7; // x0
  __int64 v8; // x25
  _QWORD *v9; // x27
  unsigned int (__fastcall *v10)(_QWORD); // x8
  char v11; // w21
  bool v12; // w22
  unsigned int v13; // w9
  unsigned int v20; // w11
  unsigned int (__fastcall *v21)(_QWORD); // x8
  char v22; // w20
  _DWORD *v23; // x8
  __int64 v24; // x0
  _DWORD *v25; // x8
  __int64 v26; // x0
  void (*v27)(void); // x8
  void (__fastcall *v28)(_QWORD); // x8
  int v29; // w4
  unsigned int disp_op; // w0
  __int64 v31; // x2
  __int64 v32; // x3
  __int64 v33; // x4
  __int64 v34; // x5
  int v35; // w6
  int v36; // w7
  int v37; // w8
  unsigned int v38; // w22
  unsigned int v39; // w25
  __int64 v40; // x8
  unsigned int *v41; // x9
  unsigned int v42; // w8
  unsigned int v45; // w9
  __int64 v46; // x11
  _DWORD *v47; // x8
  __int64 v48; // x0
  void (*v49)(void); // x8
  void (*v50)(void); // x8
  _DWORD *v51; // x8
  __int64 v52; // x0
  __int64 v53; // x8
  char v54; // [xsp+0h] [xbp-90h]
  __int64 v55; // [xsp+58h] [xbp-38h]
  int v56; // [xsp+64h] [xbp-2Ch]
  _QWORD v57[3]; // [xsp+68h] [xbp-28h] BYREF
  int v58; // [xsp+80h] [xbp-10h]
  unsigned int v59; // [xsp+84h] [xbp-Ch] BYREF
  __int64 v60; // [xsp+88h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58 = 0;
  memset(v57, 0, sizeof(v57));
  if ( !result )
    goto LABEL_96;
  v1 = *result;
  v2 = result;
  if ( !*result )
    goto LABEL_96;
  v3 = (((__int64 (__fastcall *)(_QWORD))sde_encoder_in_clone_mode)(*result) & 1) != 0 ? 0LL : *(_QWORD *)(v1 + 4960);
  result = (_QWORD *)sde_encoder_get_disp_op(*v2);
  v4 = v2[52];
  if ( !v4 )
    goto LABEL_96;
  v5 = (unsigned int)result;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v7 = raw_spin_lock_irqsave(v2[103]);
    if ( v5 >= 3 )
      goto LABEL_98;
    v8 = v7;
    v56 = *((_DWORD *)v2 + 219);
    v9 = (_QWORD *)(v4 + 8LL * v5);
    v55 = v3;
    v10 = (unsigned int (__fastcall *)(_QWORD))v9[98];
    if ( !v10 )
    {
      v11 = 0;
      v3 = 0;
      v12 = 1;
      goto LABEL_27;
    }
    if ( *((_DWORD *)v10 - 1) != 1814623283 )
      __break(0x8228u);
    if ( v10(v4) )
    {
      v11 = 0;
      v3 = 0;
LABEL_26:
      v12 = 1;
      goto LABEL_27;
    }
    v13 = *((_DWORD *)v2 + 219);
    _X8 = (unsigned int *)v2 + 219;
    do
    {
      if ( !v13 )
        break;
      __asm { PRFM            #0x11, [X8] }
      while ( 1 )
      {
        v20 = __ldxr(_X8);
        if ( v20 != v13 )
          break;
        if ( !__stlxr(v13 - 1, _X8) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v20 == v13;
      v13 = v20;
    }
    while ( !_ZF );
    if ( *((_DWORD *)v2 + 166) == 3 )
    {
      v3 = 0;
      v11 = 1;
      goto LABEL_26;
    }
    v42 = *((_DWORD *)v2 + 220);
    v3 = 25;
    v11 = 1;
    while ( 1 )
    {
      v12 = v42 == 0;
      if ( !v42 )
        break;
      _X12 = (unsigned int *)(v2 + 110);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v45 = __ldxr(_X12);
        if ( v45 != v42 )
          break;
        if ( !__stlxr(v42 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v45 == v42;
      v42 = v45;
      if ( _ZF )
        goto LABEL_27;
    }
    v3 = 0;
    v11 = 1;
LABEL_27:
    v21 = (unsigned int (__fastcall *)(_QWORD))v9[119];
    if ( v21 )
    {
      if ( *((_DWORD *)v21 - 1) != 1814623283 )
        __break(0x8228u);
      if ( v21(v4) )
        v22 = -83;
      else
        v22 = 0;
    }
    else
    {
      v22 = 0;
    }
    raw_spin_unlock_irqrestore(v2[103], v8);
    if ( !v12 )
    {
      v23 = (_DWORD *)v2[49];
      if ( v23 )
      {
        v24 = *v2;
        if ( *(v23 - 1) != -570463643 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD *, _QWORD))v23)(v24, v2, (unsigned int)v3);
      }
    }
    v25 = (_DWORD *)v2[46];
    if ( v25 )
    {
      v26 = *v2;
      if ( *(v25 - 1) != 468003652 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *))v25)(v26, v2);
    }
    v27 = *(void (**)(void))(v2[53] + 8LL * v5 + 200);
    if ( v27 )
    {
      if ( *((_DWORD *)v27 - 1) != -2009615442 )
        __break(0x8228u);
      v27();
    }
    if ( (v11 & 1) == 0 )
    {
      v28 = (void (__fastcall *)(_QWORD))v9[56];
      if ( v28 )
      {
        if ( *((_DWORD *)v28 - 1) != 1800103338 )
          __break(0x8228u);
        v28(v4);
      }
    }
    if ( *v2 )
      v29 = *(_DWORD *)(*v2 + 24LL);
    else
      v29 = -1;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_phys_vid_vblank_irq",
      1258,
      2,
      v29,
      *(_DWORD *)(v2[53] + 32LL) - 1,
      v56,
      *((_DWORD *)v2 + 219),
      v22);
    if ( v55 )
      sde_cesta_get_status(v55, v57);
    v4 = *v2;
    v59 = 0;
    disp_op = sde_encoder_get_disp_op(v4);
    if ( *(_BYTE *)(v4 + 751) != 1 )
      goto LABEL_95;
    v37 = *(_DWORD *)(v4 + 4884);
    StatusReg = *(unsigned int *)(v4 + 3944);
    v38 = disp_op;
    v39 = *(_DWORD *)(v4 + 4808);
    if ( v37 )
    {
      v5 = 1;
      if ( v37 != 1 )
        goto LABEL_61;
LABEL_60:
      get_random_bytes(&v59, 4);
      v37 = *(_DWORD *)(v4 + 4884);
      v5 = v59 % ((unsigned int)StatusReg - v39 + 1) + v39;
      goto LABEL_61;
    }
    v5 = 0xF4240u / (1000 * *(_DWORD *)(v4 + 4888));
    sde_evtlog_log(sde_dbg_base_evtlog, "sde_encoder_phys_wd_config", 1077, 2, v5, v39, -1059143953, v36, v54);
    v37 = *(_DWORD *)(v4 + 4884);
    if ( v5 <= v39 )
      v5 = 1;
    if ( v37 == 1 )
      goto LABEL_60;
LABEL_61:
    if ( v37 == 2 )
    {
      if ( !*(_DWORD *)(*(_QWORD *)(v4 + 4904) + 8LL) )
        goto LABEL_95;
      v40 = *(_QWORD *)(*v2 + 4904LL);
      v41 = *(unsigned int **)v40;
      if ( v56 )
      {
        *(_DWORD *)(v40 + 20) = 0;
        v5 = *v41;
        *(_DWORD *)(v40 + 20) = 1;
      }
      else
      {
        v46 = *(unsigned int *)(v40 + 20);
        if ( (unsigned int)v46 >= *(_DWORD *)(v40 + 8) )
        {
          v5 = *(_DWORD *)(*v2 + 4808LL);
        }
        else
        {
          v5 = v41[v46];
          *(_DWORD *)(v40 + 20) = v46 + 1;
        }
      }
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_phys_wd_config",
      1092,
      2,
      *(_DWORD *)(v4 + 4884),
      v5,
      *(_DWORD *)(v4 + 4888),
      -1059143953,
      v54);
    v47 = (_DWORD *)v2[31];
    if ( *(v47 - 1) != 1595431362 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, _QWORD))v47)(v2, 0);
    if ( v38 < 3 )
      break;
LABEL_98:
    __break(0x5512u);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v52 = _traceiter_tracing_mark_write(0, 66, StatusReg, "vblank_irq", 0);
      v53 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v53;
      if ( !v53 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v52);
    }
  }
  v48 = v2[53];
  v49 = *(void (**)(void))(v48 + 8LL * v38 + 320);
  if ( v49 )
  {
    if ( *((_DWORD *)v49 - 1) != -1913620264 )
      __break(0x8228u);
    v49();
    v48 = v2[53];
  }
  v50 = *(void (**)(void))(v48 + 8LL * v38 + 656);
  if ( v50 )
  {
    if ( *((_DWORD *)v50 - 1) != -1913620264 )
      __break(0x8228u);
    v50();
  }
  v51 = (_DWORD *)v2[31];
  if ( *(v51 - 1) != 1595431362 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD *, __int64))v51)(v2, 1);
LABEL_95:
  sde_encoder_handle_frequency_stepping(v2, v56, v31, v32, v33, v34, v35, v36);
  result = (_QWORD *)_wake_up(v2 + 112, 3, 0, 0);
LABEL_96:
  _ReadStatusReg(SP_EL0);
  return result;
}
