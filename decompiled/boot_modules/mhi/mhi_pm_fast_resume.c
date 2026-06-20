__int64 __fastcall mhi_pm_fast_resume(__int64 a1, char a2)
{
  __int64 v2; // x22
  __int64 v5; // x23
  __int64 v6; // x21
  const char *v7; // x0
  int v8; // w8
  const char *v9; // x4
  const char *v10; // x5
  unsigned int v11; // w8
  _QWORD *v13; // x25
  __int64 v14; // x8
  __int64 v15; // x8
  _QWORD *v16; // x24
  __int64 v17; // x0
  unsigned int v18; // w0
  void (__fastcall *v19)(__int64, __int64); // x8
  void (__fastcall *v20)(__int64, __int64); // x8
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x20
  void (__fastcall *v24)(__int64, __int64); // x8
  __int64 v25; // x20
  const char *v26; // x0
  __int64 v27; // x20
  const char *v28; // x0
  unsigned int v35; // w10
  unsigned int v38; // w10
  unsigned int v41; // w10

  v2 = *(_QWORD *)(a1 + 16);
  v5 = *(_QWORD *)(v2 + 192);
  if ( !v5 || *(_DWORD *)(v5 + 24) )
    goto LABEL_27;
  v6 = *(_QWORD *)(v5 + 32);
  v7 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
  v8 = *(_DWORD *)(a1 + 348);
  if ( v8 <= 3 )
  {
    if ( v8 <= 1 )
    {
      if ( !v8 )
      {
        v9 = "RESET";
        goto LABEL_23;
      }
      if ( v8 == 1 )
      {
        v9 = "READY";
        goto LABEL_23;
      }
      goto LABEL_22;
    }
    if ( v8 == 2 )
      v9 = "M0";
    else
      v9 = "M1";
  }
  else
  {
    if ( v8 > 5 )
    {
      switch ( v8 )
      {
        case 6:
          v9 = "M3_FAST";
          goto LABEL_23;
        case 7:
          v9 = "BHI";
          goto LABEL_23;
        case 255:
          v9 = "SYS ERROR";
          goto LABEL_23;
      }
LABEL_22:
      v9 = "Unknown state";
      goto LABEL_23;
    }
    if ( v8 == 4 )
      v9 = "M2";
    else
      v9 = "M3";
  }
LABEL_23:
  if ( (a2 & 1) != 0 )
    v10 = "true";
  else
    v10 = "false";
  ipc_log_string(v6, "[D][%s] Entered with PM state: %s, MHI state: %s notify: %s\n", "mhi_pm_fast_resume", v7, v9, v10);
LABEL_27:
  v11 = *(_DWORD *)(a1 + 336);
  if ( v11 == 1 )
    return 0;
  if ( v11 <= 0x7F )
  {
    raw_read_lock_bh(a1 + 320);
    if ( *(_DWORD *)(a1 + 336) != 32 )
      __break(0x800u);
    raw_read_unlock_bh(a1 + 320);
    if ( *(_QWORD *)(a1 + 160)
      && (unsigned int)mhi_get_exec_env(a1) == 3
      && (unsigned int)(*(_DWORD *)(a1 + 348) - 2) <= 4 )
    {
      v22 = *(_QWORD *)(a1 + 16);
      *(_DWORD *)(a1 + 344) = 3;
      v23 = *(_QWORD *)(v22 + 192);
      dev_err(v2 + 40, "[E][%s] RDDM event occurred!\n", "mhi_pm_fast_resume");
      if ( v23 && *(_DWORD *)(v23 + 24) <= 2u )
        ipc_log_string(*(_QWORD *)(v23 + 32), "[E][%s] RDDM event occurred!\n", "mhi_pm_fast_resume");
      mhi_report_error(a1);
      v24 = *(void (__fastcall **)(__int64, __int64))(a1 + 480);
      if ( *((_DWORD *)v24 - 1) != 1183736653 )
        __break(0x8228u);
      v24(a1, 4);
      _wake_up(a1 + 456, 3, 0, 0);
      return 0;
    }
    if ( (a2 & 1) != 0 )
    {
      v13 = *(_QWORD **)(a1 + 184);
      if ( v13 != (_QWORD *)(a1 + 184) )
      {
        do
        {
          v16 = (_QWORD *)*v13;
          mutex_lock(v13 - 11);
          v17 = *(v13 - 13);
          if ( v17 )
            mhi_notify(v17);
          mutex_unlock(v13 - 11);
          v13 = v16;
        }
        while ( v16 != (_QWORD *)(a1 + 184) );
      }
    }
    v14 = *(_QWORD *)(a1 + 248);
    _X9 = (unsigned int *)(v14 + 184);
    __asm { PRFM            #0x11, [X9] }
    do
      v35 = __ldxr(_X9);
    while ( __stxr(v35 + 1, _X9) );
    __dmb(0xBu);
    tasklet_unlock_wait(v14 + 168);
    __dmb(0xBu);
    raw_write_lock_irq(a1 + 320);
    if ( *(_DWORD *)(a1 + 336) < 0x80u )
    {
      *(_DWORD *)(a1 + 336) = *(_DWORD *)(v5 + 40);
      *(_DWORD *)(a1 + 348) = *(_DWORD *)(v5 + 44);
      raw_write_unlock_irq(a1 + 320);
      v18 = *(_DWORD *)(a1 + 336);
      if ( v18 == 8 )
      {
        raw_read_lock_bh(a1 + 320);
        v19 = *(void (__fastcall **)(__int64, __int64))(a1 + 488);
        if ( *((_DWORD *)v19 - 1) != 598874997 )
          __break(0x8228u);
        v19(a1, 1);
        v20 = *(void (__fastcall **)(__int64, __int64))(a1 + 496);
        if ( *((_DWORD *)v20 - 1) != 598874997 )
          __break(0x8228u);
        v20(a1, 1);
        raw_read_unlock_bh(a1 + 320);
      }
      else if ( v18 == 4 )
      {
        mhi_pm_m0_transition(a1);
      }
      else
      {
        v25 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
        v26 = to_mhi_pm_state_str(v18);
        dev_err(v2 + 40, "[E][%s] Unexpected PM state:%s after restore\n", "mhi_pm_fast_resume", v26);
        if ( v25 && *(_DWORD *)(v25 + 24) <= 2u )
        {
          v27 = *(_QWORD *)(v25 + 32);
          v28 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
          ipc_log_string(v27, "[E][%s] Unexpected PM state:%s after restore\n", "mhi_pm_fast_resume", v28);
        }
      }
      v21 = *(_QWORD *)(a1 + 248);
      __dmb(0xBu);
      _X8 = (unsigned int *)(v21 + 184);
      __asm { PRFM            #0x11, [X8] }
      do
        v41 = __ldxr(_X8);
      while ( __stxr(v41 - 1, _X8) );
      mhi_irq_handler(0, *(__int64 **)(a1 + 248));
      return 0;
    }
    raw_write_unlock_irq(a1 + 320);
    v15 = *(_QWORD *)(a1 + 248);
    __dmb(0xBu);
    _X8 = (unsigned int *)(v15 + 184);
    __asm { PRFM            #0x11, [X8] }
    do
      v38 = __ldxr(_X8);
    while ( __stxr(v38 - 1, _X8) );
  }
  return 4294967291LL;
}
