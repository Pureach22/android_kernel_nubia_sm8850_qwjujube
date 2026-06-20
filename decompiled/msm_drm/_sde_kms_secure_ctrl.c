__int64 __fastcall sde_kms_secure_ctrl(__int64 a1, __int64 a2, char a3)
{
  int v4; // w21
  __int64 result; // x0
  int v8; // w8
  int v9; // w0
  int v10; // w4
  int v11; // w0
  int v12; // w0
  int v13; // w8
  unsigned int v15; // w23
  int v16; // w0
  int v17; // w0
  int v18; // w22
  int v19; // w0
  int v20; // w0
  unsigned int v22; // w23
  int v23; // w0
  int v24; // w0
  int v25; // w8
  int v26; // w9
  int v27; // w10
  unsigned int v34; // w8
  signed int v35; // w8
  unsigned int v37; // w8
  unsigned int v38; // w8
  unsigned int v41; // w8
  unsigned int v42; // w8
  unsigned int v44; // w8
  signed int v45; // w8
  unsigned int v48; // w10
  unsigned int v50; // w9
  unsigned int v52; // w8
  unsigned int v55; // w9

  v4 = *(_DWORD *)(a1 + 3656);
  result = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "_sde_kms_secure_ctrl",
             627,
             -1,
             *(_DWORD *)(a2 + 112),
             v4,
             *(_DWORD *)(a1 + 3672),
             a3 & 1,
             *(_DWORD *)(a1 + 3680));
  v8 = *(_DWORD *)(a1 + 3672);
  if ( !v8 || v8 == 2 && (a3 & 1) == 0 )
    return result;
  if ( *(_DWORD *)(a1 + 3680) == 1 )
  {
    v9 = sde_kms_sui_misr_ctrl(a1, a2, 1);
    if ( v9 )
    {
      v18 = v9;
      *(_DWORD *)(a1 + 3680) = 0;
      goto LABEL_51;
    }
  }
  mutex_lock(a1 + 3696);
  v10 = *(_DWORD *)(a1 + 3656);
  if ( v10 <= 4 )
  {
    if ( v10 != 3 )
    {
      if ( v10 == 4 )
      {
        _X9 = (unsigned int *)(a1 + 3688);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v34 = __ldxr(_X9);
          v35 = v34 + 1;
        }
        while ( __stlxr(v35, _X9) );
        __dmb(0xBu);
        if ( v35 > 1 )
          goto LABEL_12;
        v11 = sde_kms_mmu_detach((_QWORD *)a1, 0);
        if ( v11 )
        {
          v18 = v11;
          printk(&unk_246539, "_sde_kms_detach_all_cb");
        }
        else
        {
          v12 = sde_kms_scm_call(a1, 17);
          if ( !v12 )
          {
LABEL_12:
            v13 = 1;
LABEL_31:
            *(_DWORD *)(a1 + 3656) = v13;
            goto LABEL_32;
          }
          v18 = v12;
          printk(&unk_27DCAB, "_sde_kms_detach_all_cb");
          sde_kms_mmu_attach((_QWORD *)a1, 0);
        }
        _X8 = (unsigned int *)(a1 + 3688);
        __asm { PRFM            #0x11, [X8] }
        do
          v48 = __ldxr(_X8);
        while ( __stxr(v48 - 1, _X8) );
        goto LABEL_50;
      }
      goto LABEL_42;
    }
    _X9 = (unsigned int *)(a1 + 3688);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v41 = __ldxr(_X9);
      v42 = v41 - 1;
    }
    while ( __stlxr(v42, _X9) );
    __dmb(0xBu);
    if ( !v42 )
    {
      v19 = sde_kms_scm_call(a1, 10);
      if ( v19 )
      {
        v18 = v19;
        printk(&unk_27DCAB, "_sde_kms_attach_all_cb");
      }
      else
      {
        v20 = sde_kms_mmu_attach((_QWORD *)a1, 0);
        if ( !v20 )
          goto LABEL_24;
        v18 = v20;
        printk(&unk_2245C1, "_sde_kms_attach_all_cb");
        sde_kms_scm_call(a1, 17);
      }
      _X8 = (unsigned int *)(a1 + 3688);
      __asm { PRFM            #0x11, [X8] }
      do
        v55 = __ldxr(_X8);
      while ( __stxr(v55 + 1, _X8) );
      goto LABEL_50;
    }
    goto LABEL_24;
  }
  if ( v10 == 5 )
  {
    _X26 = (unsigned int *)(a1 + 3684);
    if ( *(_DWORD *)(a1 + 3664) == 1 )
      v22 = 17;
    else
      v22 = 29;
    __asm { PRFM            #0x11, [X26] }
    do
    {
      v44 = __ldxr(_X26);
      v45 = v44 + 1;
    }
    while ( __stlxr(v45, _X26) );
    __dmb(0xBu);
    if ( v45 > 1 )
      goto LABEL_30;
    v23 = sde_kms_mmu_detach((_QWORD *)a1, 1);
    if ( v23 )
    {
      v18 = v23;
      printk(&unk_269276, "_sde_kms_detach_sec_cb");
    }
    else
    {
      v24 = sde_kms_scm_call(a1, v22);
      if ( !v24 )
      {
LABEL_30:
        v13 = 2;
        goto LABEL_31;
      }
      v18 = v24;
      printk(&unk_27DCAB, "_sde_kms_detach_sec_cb");
      sde_kms_mmu_attach((_QWORD *)a1, 1);
    }
    __asm { PRFM            #0x11, [X26] }
    do
      v50 = __ldxr(_X26);
    while ( __stxr(v50 - 1, _X26) );
    goto LABEL_50;
  }
  if ( v10 != 6 )
  {
LABEL_42:
    printk(&unk_253D5E, "_sde_kms_secure_ctrl");
    v18 = -22;
LABEL_50:
    mutex_unlock(a1 + 3696);
LABEL_51:
    *(_DWORD *)(a1 + 3676) = 1;
    printk(&unk_257426, "_sde_kms_secure_ctrl");
    v26 = *(_DWORD *)(a1 + 3680);
    v27 = *(_DWORD *)(a1 + 3668);
    *(_DWORD *)(a1 + 3656) = *(_DWORD *)(a1 + 3660);
    *(_DWORD *)(a1 + 3664) = v27;
    if ( v26 == 1 )
      sde_kms_sui_misr_ctrl(a1, a2, 0);
    goto LABEL_37;
  }
  _X26 = (unsigned int *)(a1 + 3684);
  if ( *(_DWORD *)(a1 + 3664) == 1 )
    v15 = 17;
  else
    v15 = 29;
  __asm { PRFM            #0x11, [X26] }
  do
  {
    v37 = __ldxr(_X26);
    v38 = v37 - 1;
  }
  while ( __stlxr(v38, _X26) );
  __dmb(0xBu);
  if ( !v38 )
  {
    v16 = sde_kms_scm_call(a1, 10);
    if ( v16 )
    {
      v18 = v16;
      printk(&unk_27DCAB, "_sde_kms_attach_sec_cb");
    }
    else
    {
      v17 = sde_kms_mmu_attach((_QWORD *)a1, 1);
      if ( !v17 )
        goto LABEL_24;
      v18 = v17;
      printk(&unk_265CA9, "_sde_kms_attach_sec_cb");
      sde_kms_scm_call(a1, v15);
    }
    __asm { PRFM            #0x11, [X26] }
    do
      v52 = __ldxr(_X26);
    while ( __stxr(v52 + 1, _X26) );
    goto LABEL_50;
  }
LABEL_24:
  *(_DWORD *)(a1 + 3656) = 0;
  *(_DWORD *)(a1 + 3664) = 0;
LABEL_32:
  mutex_unlock(a1 + 3696);
  if ( *(_DWORD *)(a1 + 3680) == 2 )
  {
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))sde_vbif_halt_xin_mask)(
                         a1,
                         *(unsigned int *)(*(_QWORD *)(a1 + 152) + 21476LL),
                         0) )
      printk(&unk_257477, "_sde_kms_secure_ctrl_xin_clients");
    sde_crtc_misr_setup(a2, 0, 0);
    _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 8LL), 4);
  }
  v18 = 0;
  *(_DWORD *)(a1 + 3676) = 0;
LABEL_37:
  v25 = *(_DWORD *)(a1 + 3656);
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(
      0,
      0,
      0,
      "crtc %d: req_state %d, new_state %d, sec_lvl %d, ret %d\n",
      *(_DWORD *)(a2 + 112),
      v4,
      v25,
      *(_DWORD *)(a1 + 3664),
      v18);
    v25 = *(_DWORD *)(a1 + 3656);
  }
  result = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "_sde_kms_secure_ctrl",
             719,
             -1,
             *(_DWORD *)(a2 + 112),
             v25,
             *(_DWORD *)(a1 + 3660),
             *(_DWORD *)(a1 + 3672),
             *(_DWORD *)(a1 + 3676));
  *(_DWORD *)(a1 + 3680) = 0;
  *(_DWORD *)(a1 + 3672) = 0;
  return result;
}
