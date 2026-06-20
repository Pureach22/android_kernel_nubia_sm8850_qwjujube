__int64 __fastcall mhi_pm_fast_suspend(__int64 a1, char a2)
{
  unsigned int v2; // w8
  __int64 result; // x0
  __int64 v4; // x21
  _DWORD *v6; // x23
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x20
  int v11; // w8
  __int64 v13; // x0
  __int64 v14; // x20
  int v15; // w8
  bool v16; // zf
  __int64 v17; // x8
  unsigned int v18; // w20
  unsigned int v19; // w8
  __int64 v20; // x8
  __int64 v21; // x9
  const char *v22; // x3
  int v23; // w8
  __int64 v24; // x8
  __int64 v25; // x19
  _QWORD *v26; // x22
  _QWORD *v27; // t1
  _QWORD *v28; // x21
  __int64 v29; // x0
  __int64 v30; // x22
  const char *v31; // x20
  const char *v32; // x0
  unsigned int v33; // w0
  const char *v34; // x20
  const char *v35; // x0
  const char *v36; // x20
  const char *v37; // x0
  __int64 v38; // x20
  const char *v39; // x21
  const char *v40; // x0
  unsigned int v46; // w10
  unsigned int v49; // w10
  unsigned int v52; // w10
  _QWORD v53[6]; // [xsp+0h] [xbp-30h] BYREF

  v53[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 336);
  if ( v2 == 1 )
  {
    result = 4294967274LL;
    goto LABEL_32;
  }
  if ( v2 > 0x7F )
  {
    result = 4294967291LL;
    goto LABEL_32;
  }
  v4 = *(_QWORD *)(a1 + 16);
  v6 = *(_DWORD **)(v4 + 192);
  if ( *(_DWORD *)(a1 + 356) )
  {
    result = 4294967280LL;
    goto LABEL_32;
  }
  v8 = _msecs_to_jiffies((unsigned int)v6[12]);
  if ( *(_DWORD *)(a1 + 348) != 4 && v8 )
  {
    v9 = (unsigned int)v6[12];
    memset(v53, 0, 40);
    v10 = _msecs_to_jiffies(v9);
    init_wait_entry(v53, 0);
    prepare_to_wait_event(a1 + 456, v53, 2);
    v11 = *(_DWORD *)(a1 + 348);
    if ( v10 )
      _ZF = 0;
    else
      _ZF = v11 == 4;
    if ( _ZF )
      v13 = 1;
    else
      v13 = v10;
    if ( v11 != 4 && v13 )
    {
      do
      {
        v14 = schedule_timeout(v13);
        prepare_to_wait_event(a1 + 456, v53, 2);
        v15 = *(_DWORD *)(a1 + 348);
        if ( v14 )
          v16 = 0;
        else
          v16 = v15 == 4;
        if ( v16 )
          v13 = 1;
        else
          v13 = v14;
      }
      while ( v15 != 4 && v13 );
    }
    finish_wait(a1 + 456, v53);
  }
  v17 = *(_QWORD *)(a1 + 248);
  _X9 = (unsigned int *)(v17 + 184);
  __asm { PRFM            #0x11, [X9] }
  do
    v46 = __ldxr(_X9);
  while ( __stxr(v46 + 1, _X9) );
  __dmb(0xBu);
  tasklet_unlock_wait(v17 + 168);
  __dmb(0xBu);
  raw_write_lock_irq(a1 + 320);
  if ( *(_DWORD *)(a1 + 356) )
  {
    v18 = -16;
    goto LABEL_31;
  }
  v19 = *(_DWORD *)(a1 + 336);
  if ( v19 > 0x7F )
  {
LABEL_30:
    v18 = -5;
LABEL_31:
    raw_write_unlock_irq(a1 + 320);
    v20 = *(_QWORD *)(a1 + 248);
    __dmb(0xBu);
    _X8 = (unsigned int *)(v20 + 184);
    __asm { PRFM            #0x11, [X8] }
    do
      v49 = __ldxr(_X8);
    while ( __stxr(v49 - 1, _X8) );
    mhi_irq_handler(0, *(__int64 **)(a1 + 248));
    result = v18;
    goto LABEL_32;
  }
  v21 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( v21 && !*(_DWORD *)(v21 + 24) )
  {
    if ( (a2 & 1) != 0 )
      v22 = "true";
    else
      v22 = "false";
    ipc_log_string(
      *(_QWORD *)(v21 + 32),
      "[D][%s] Allowing Fast M3 transition with notify: %s\n",
      "mhi_pm_fast_suspend",
      v22);
    v19 = *(_DWORD *)(a1 + 336);
  }
  v6[10] = v19;
  v6[11] = *(_DWORD *)(a1 + 348);
  if ( *(_DWORD *)(a1 + 336) == 8 && (unsigned int)mhi_tryset_pm_state(a1, 4u) != 4 )
  {
    v30 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    v36 = to_mhi_pm_state_str(4u);
    v37 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
    dev_err(v4 + 40, "[E][%s] Error setting to PM state: %s from: %s\n", "mhi_pm_fast_suspend", v36, v37);
    if ( !v30 || *(_DWORD *)(v30 + 24) >= 3u )
      goto LABEL_30;
    v33 = 4;
LABEL_61:
    v38 = *(_QWORD *)(v30 + 32);
    v39 = to_mhi_pm_state_str(v33);
    v40 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
    ipc_log_string(v38, "[E][%s] Error setting to PM state: %s from: %s\n", "mhi_pm_fast_suspend", v39, v40);
    goto LABEL_30;
  }
  if ( (unsigned int)mhi_tryset_pm_state(a1, 0x10u) != 16 )
  {
    v30 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    v31 = to_mhi_pm_state_str(0x10u);
    v32 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
    dev_err(v4 + 40, "[E][%s] Error setting to PM state: %s from: %s\n", "mhi_pm_fast_suspend", v31, v32);
    if ( !v30 || *(_DWORD *)(v30 + 24) >= 3u )
      goto LABEL_30;
    v33 = 16;
    goto LABEL_61;
  }
  if ( (unsigned int)mhi_tryset_pm_state(a1, 0x20u) != 32 )
  {
    v30 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    v34 = to_mhi_pm_state_str(0x20u);
    v35 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
    dev_err(v4 + 40, "[E][%s] Error setting to PM state: %s from: %s\n", "mhi_pm_fast_suspend", v34, v35);
    if ( !v30 || *(_DWORD *)(v30 + 24) >= 3u )
      goto LABEL_30;
    v33 = 32;
    goto LABEL_61;
  }
  v23 = *(_DWORD *)(a1 + 372);
  *(_DWORD *)(a1 + 348) = 6;
  *(_DWORD *)(a1 + 372) = v23 + 1;
  raw_write_unlock_irq(a1 + 320);
  if ( (*(_BYTE *)(a1 + 340) & 8) == 0 )
    flush_work(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL) + 120LL);
  v24 = *(_QWORD *)(a1 + 248);
  __dmb(0xBu);
  _X8 = (unsigned int *)(v24 + 184);
  __asm { PRFM            #0x11, [X8] }
  do
    v52 = __ldxr(_X8);
  while ( __stxr(v52 - 1, _X8) );
  mhi_irq_handler(0, *(__int64 **)(a1 + 248));
  result = 0;
  if ( (a2 & 1) != 0 )
  {
    v27 = *(_QWORD **)(a1 + 184);
    v25 = a1 + 184;
    v26 = v27;
    if ( v27 == (_QWORD *)v25 )
    {
      result = 0;
    }
    else
    {
      do
      {
        v28 = (_QWORD *)*v26;
        mutex_lock(v26 - 11);
        v29 = *(v26 - 13);
        if ( v29 )
          mhi_notify(v29);
        mutex_unlock(v26 - 11);
        result = 0;
        v26 = v28;
      }
      while ( v28 != (_QWORD *)v25 );
    }
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
