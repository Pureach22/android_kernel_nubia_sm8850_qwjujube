__int64 __fastcall mhi_pm_suspend(__int64 a1)
{
  unsigned int v1; // w8
  __int64 result; // x0
  __int64 v3; // x22
  unsigned int v5; // w21
  __int64 v6; // x20
  _DWORD *v7; // x8
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x20
  unsigned int v10; // w8
  bool v11; // cc
  __int64 v12; // x0
  unsigned int v13; // w8
  bool v14; // cc
  unsigned int v15; // w23
  __int64 v16; // x21
  _DWORD *v17; // x8
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x8
  unsigned __int64 v21; // x0
  unsigned __int64 v22; // x20
  __int64 v23; // x19
  unsigned int v24; // w8
  bool v25; // cc
  __int64 v26; // x0
  unsigned int v27; // w8
  bool v28; // cc
  __int64 v29; // x0
  unsigned int v30; // w20
  __int64 v31; // x19
  _QWORD *v32; // x22
  _QWORD *v33; // t1
  _QWORD *v34; // x21
  __int64 v35; // x0
  __int64 v36; // x21
  const char *v37; // x20
  const char *v38; // x0
  __int64 v39; // x20
  const char *v40; // x0
  unsigned int v41; // w8
  const char *v42; // x19
  const char *v43; // x4
  __int64 v44; // x23
  const char *v45; // x21
  const char *v46; // x0
  __int64 v47; // x20
  const char *v48; // x0
  unsigned int v49; // w8
  const char *v50; // x19
  const char *v51; // x4
  __int64 v52; // [xsp+0h] [xbp-30h] BYREF
  __int64 v53; // [xsp+8h] [xbp-28h]
  __int64 v54; // [xsp+10h] [xbp-20h]
  __int64 v55; // [xsp+18h] [xbp-18h]
  __int64 v56; // [xsp+20h] [xbp-10h]
  __int64 v57; // [xsp+28h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(a1 + 336);
  if ( v1 == 1 )
  {
    result = 4294967274LL;
    goto LABEL_56;
  }
  if ( v1 > 0x7F )
  {
LABEL_4:
    result = 4294967291LL;
    goto LABEL_56;
  }
  v3 = *(_QWORD *)(a1 + 16);
  if ( *(_DWORD *)(a1 + 352) || *(_DWORD *)(a1 + 356) )
  {
LABEL_55:
    result = 4294967280LL;
    goto LABEL_56;
  }
  if ( *(_DWORD *)(a1 + 212) )
  {
    v5 = 0;
    v6 = *(_QWORD *)(a1 + 248) + 168LL;
    do
    {
      if ( (*(_BYTE *)(v6 + 90) & 1) == 0 )
      {
        if ( *(_DWORD *)(v6 - 136) == 2 )
          flush_work(v6 + 40);
        else
          tasklet_unlock_wait(v6);
      }
      ++v5;
      v6 += 264;
    }
    while ( v5 < *(_DWORD *)(a1 + 212) );
  }
  raw_read_lock_bh(a1 + 320);
  v7 = *(_DWORD **)(a1 + 488);
  if ( *(v7 - 1) != 598874997 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD))v7)(a1, 0);
  raw_read_unlock_bh(a1 + 320);
  v8 = _msecs_to_jiffies(*(unsigned int *)(a1 + 328));
  if ( (*(_DWORD *)(a1 + 348) & 0xFFFFFFFE) == 2 )
  {
    if ( v8 <= 1 )
      LODWORD(v9) = 1;
    else
      LODWORD(v9) = v8;
  }
  else
  {
    v10 = *(_DWORD *)(a1 + 336);
    if ( v8 )
      v11 = 0;
    else
      v11 = v10 > 0x7F;
    if ( v11 )
      v9 = 1;
    else
      v9 = v8;
    if ( v10 <= 0x7F && v9 )
    {
      v12 = *(unsigned int *)(a1 + 328);
      v55 = 0;
      v56 = 0;
      v53 = 0;
      v54 = 0;
      v52 = 0;
      v9 = _msecs_to_jiffies(v12);
      init_wait_entry(&v52, 0);
      prepare_to_wait_event(a1 + 456, &v52, 2);
      if ( (*(_DWORD *)(a1 + 348) & 0xFFFFFFFE) == 2 )
      {
LABEL_38:
        if ( v9 <= 1 )
          LODWORD(v9) = 1;
      }
      else
      {
        while ( 1 )
        {
          v13 = *(_DWORD *)(a1 + 336);
          if ( v9 )
            v14 = 0;
          else
            v14 = v13 > 0x7F;
          if ( v14 )
            v9 = 1;
          if ( v13 > 0x7F || !v9 )
            break;
          v9 = schedule_timeout(v9);
          prepare_to_wait_event(a1 + 456, &v52, 2);
          if ( (*(_DWORD *)(a1 + 348) & 0xFFFFFFFE) == 2 )
            goto LABEL_38;
        }
      }
      finish_wait(a1 + 456, &v52);
    }
  }
  if ( *(_DWORD *)(a1 + 212) )
  {
    v15 = 0;
    v16 = *(_QWORD *)(a1 + 248) + 168LL;
    do
    {
      if ( (*(_BYTE *)(v16 + 90) & 1) == 0 )
      {
        if ( *(_DWORD *)(v16 - 136) == 2 )
          flush_work(v16 + 40);
        else
          tasklet_unlock_wait(v16);
      }
      ++v15;
      v16 += 264;
    }
    while ( v15 < *(_DWORD *)(a1 + 212) );
  }
  raw_read_lock_bh(a1 + 320);
  v17 = *(_DWORD **)(a1 + 496);
  if ( *(v17 - 1) != 598874997 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD))v17)(a1, 0);
  raw_read_unlock_bh(a1 + 320);
  if ( !(_DWORD)v9 || *(_DWORD *)(a1 + 336) >= 0x80u )
  {
    v23 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v3 + 40, "[E][%s] Could not enter M0/M1 state", "mhi_pm_suspend");
    if ( v23 && *(_DWORD *)(v23 + 24) <= 2u )
    {
      ipc_log_string(*(_QWORD *)(v23 + 32), "[E][%s] Could not enter M0/M1 state", "mhi_pm_suspend");
      result = 4294967291LL;
      goto LABEL_56;
    }
    goto LABEL_4;
  }
  raw_write_lock_irq(a1 + 320);
  if ( *(_DWORD *)(a1 + 352) || *(_DWORD *)(a1 + 356) )
  {
    raw_write_unlock_irq(a1 + 320);
    goto LABEL_55;
  }
  raw_write_unlock_irq(a1 + 320);
  mhi_force_reg_write(a1);
  v18 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( v18 && !*(_DWORD *)(v18 + 24) )
    ipc_log_string(*(_QWORD *)(v18 + 32), "[D][%s] Reg writes are done\n", "mhi_pm_suspend");
  raw_write_lock_irq(a1 + 320);
  v19 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( v19 && !*(_DWORD *)(v19 + 24) )
    ipc_log_string(*(_QWORD *)(v19 + 32), "[D][%s] Allowing M3 transition\n", "mhi_pm_suspend");
  if ( (unsigned int)mhi_tryset_pm_state(a1, 0x10u) != 16 )
  {
    raw_write_unlock_irq(a1 + 320);
    v36 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    v37 = to_mhi_pm_state_str(0x10u);
    v38 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
    dev_err(v3 + 40, "[E][%s] Error setting to PM state: %s from: %s\n", "mhi_pm_suspend", v37, v38);
    if ( !v36 || *(_DWORD *)(v36 + 24) > 2u )
      goto LABEL_4;
    v39 = *(_QWORD *)(v36 + 32);
    v40 = to_mhi_pm_state_str(0x10u);
    v41 = *(_DWORD *)(a1 + 336);
    v42 = v40;
    v43 = to_mhi_pm_state_str(v41);
    ipc_log_string(v39, "[E][%s] Error setting to PM state: %s from: %s\n", "mhi_pm_suspend", v42, v43);
    goto LABEL_110;
  }
  mhi_set_mhi_state(a1, 5);
  raw_write_unlock_irq(a1 + 320);
  v20 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( v20 && !*(_DWORD *)(v20 + 24) )
    ipc_log_string(*(_QWORD *)(v20 + 32), "[D][%s] Waiting for M3 completion\n", "mhi_pm_suspend");
  v21 = _msecs_to_jiffies(*(unsigned int *)(a1 + 328));
  if ( *(_DWORD *)(a1 + 348) == 5 )
  {
    if ( v21 <= 1 )
      LODWORD(v22) = 1;
    else
      LODWORD(v22) = v21;
  }
  else
  {
    v24 = *(_DWORD *)(a1 + 336);
    if ( v21 )
      v25 = 0;
    else
      v25 = v24 > 0x7F;
    if ( v25 )
      v22 = 1;
    else
      v22 = v21;
    if ( v24 <= 0x7F && v22 )
    {
      v26 = *(unsigned int *)(a1 + 328);
      v55 = 0;
      v56 = 0;
      v53 = 0;
      v54 = 0;
      v52 = 0;
      v22 = _msecs_to_jiffies(v26);
      init_wait_entry(&v52, 0);
      prepare_to_wait_event(a1 + 456, &v52, 2);
      if ( *(_DWORD *)(a1 + 348) == 5 )
      {
LABEL_92:
        if ( v22 <= 1 )
          LODWORD(v22) = 1;
      }
      else
      {
        while ( 1 )
        {
          v27 = *(_DWORD *)(a1 + 336);
          v28 = !v22 && v27 > 0x7F;
          v29 = v28 ? 1LL : v22;
          if ( v27 > 0x7F || !v29 )
            break;
          v22 = schedule_timeout(v29);
          prepare_to_wait_event(a1 + 456, &v52, 2);
          if ( *(_DWORD *)(a1 + 348) == 5 )
            goto LABEL_92;
        }
        LODWORD(v22) = v29;
      }
      finish_wait(a1 + 456, &v52);
    }
  }
  if ( !(_DWORD)v22 )
  {
    mhi_debug_reg_dump(a1);
    panic("Timedout waiting for M3 ACK");
  }
  v30 = *(_DWORD *)(a1 + 336);
  if ( v30 >= 0x80 )
  {
    v44 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    v45 = mhi_state_str_0(*(_DWORD *)(a1 + 348));
    v46 = to_mhi_pm_state_str(v30);
    dev_err(v3 + 40, "[E][%s] Did not enter M3 state, MHI state: %s, PM state: %s\n", "mhi_pm_suspend", v45, v46);
    if ( !v44 || *(_DWORD *)(v44 + 24) > 2u )
      goto LABEL_4;
    v47 = *(_QWORD *)(v44 + 32);
    v48 = mhi_state_str_0(*(_DWORD *)(a1 + 348));
    v49 = *(_DWORD *)(a1 + 336);
    v50 = v48;
    v51 = to_mhi_pm_state_str(v49);
    ipc_log_string(v47, "[E][%s] Did not enter M3 state, MHI state: %s, PM state: %s\n", "mhi_pm_suspend", v50, v51);
LABEL_110:
    result = 4294967291LL;
    goto LABEL_56;
  }
  v33 = *(_QWORD **)(a1 + 184);
  v31 = a1 + 184;
  v32 = v33;
  if ( v33 == (_QWORD *)v31 )
  {
    result = 0;
  }
  else
  {
    do
    {
      v34 = (_QWORD *)*v32;
      mutex_lock(v32 - 11);
      v35 = *(v32 - 13);
      if ( v35 )
        mhi_notify(v35);
      mutex_unlock(v32 - 11);
      result = 0;
      v32 = v34;
    }
    while ( v34 != (_QWORD *)v31 );
  }
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return result;
}
