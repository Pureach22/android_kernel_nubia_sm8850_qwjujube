__int64 __fastcall mhi_pm_disable_transition(__int64 a1, char a2)
{
  __int64 v2; // x22
  __int64 v5; // x8
  __int64 v6; // x21
  const char *v7; // x0
  __int64 v8; // x21
  __int64 v9; // x8
  __int64 v10; // x8
  unsigned int v11; // w23
  __int64 v12; // x21
  __int64 v13; // x8
  __int64 v14; // x8
  _QWORD *v15; // x8
  __int64 v16; // x10
  __int64 v17; // x9
  __int64 v18; // x8
  unsigned int v19; // w9
  unsigned int v20; // w8
  _BYTE *v21; // x10
  _QWORD *v22; // x11
  __int64 v23; // x9
  __int64 v24; // x9
  unsigned int v25; // w20
  __int64 v26; // x8
  __int64 v27; // x20
  const char *v28; // x0
  int v29; // w8
  const char *v30; // x4
  __int64 v32; // x23
  __int64 v33; // x21
  __int64 v34; // x21
  __int64 v35; // x23
  const char *v36; // x21
  const char *v37; // x0
  __int64 v38; // x21
  const char *v39; // x20
  const char *v40; // x0

  v2 = *(_QWORD *)(a1 + 16);
  v5 = *(_QWORD *)(v2 + 192);
  if ( v5 && !*(_DWORD *)(v5 + 24) )
  {
    v6 = *(_QWORD *)(v5 + 32);
    v7 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
    ipc_log_string(v6, "[D][%s] Processing disable transition with PM state: %s\n", "mhi_pm_disable_transition", v7);
  }
  mhi_reset_reg_write_q(a1);
  mutex_lock(a1 + 272);
  if ( *(_DWORD *)(a1 + 336) != 4096 && (!*(_QWORD *)(a1 + 160) || (unsigned int)mhi_get_exec_env(a1) != 3) )
  {
    v8 = *(_QWORD *)(a1 + 16);
    v9 = *(_QWORD *)(v8 + 192);
    if ( v9 && !*(_DWORD *)(v9 + 24) )
    {
      ipc_log_string(*(_QWORD *)(v9 + 32), "[D][%s] Triggering MHI Reset in device\n", "mhi_pm_disable_transition");
      v8 = *(_QWORD *)(a1 + 16);
    }
    if ( (unsigned int)mhi_write_reg_field(a1, *(_QWORD *)(a1 + 32), 0x38u) )
    {
      v32 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      dev_err(v8 + 40, "[E][%s] Failed to set MHI state to: %s\n", "mhi_set_mhi_state", "RESET");
      if ( v32 )
      {
        if ( *(_DWORD *)(v32 + 24) <= 2u )
          ipc_log_string(
            *(_QWORD *)(v32 + 32),
            "[E][%s] Failed to set MHI state to: %s\n",
            "mhi_set_mhi_state",
            "RESET");
      }
    }
    if ( (unsigned int)mhi_poll_reg_field(a1, *(_QWORD *)(a1 + 32), 0x38u, 2u, 0, 0x61A8u, *(_DWORD *)(a1 + 328)) )
    {
      v33 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      dev_err(v2 + 40, "[E][%s] Device failed to clear MHI Reset\n", "mhi_pm_disable_transition");
      if ( v33 )
      {
        if ( *(_DWORD *)(v33 + 24) <= 2u )
          ipc_log_string(
            *(_QWORD *)(v33 + 32),
            "[E][%s] Device failed to clear MHI Reset\n",
            "mhi_pm_disable_transition");
      }
    }
    mhi_write_reg(a1);
    if ( (unsigned int)mhi_get_exec_env(a1) )
    {
      if ( (unsigned int)mhi_get_exec_env(a1) != 5 && (unsigned int)mhi_get_exec_env(a1) != 6 )
      {
        if ( (unsigned int)mhi_poll_reg_field(a1, *(_QWORD *)(a1 + 32), 0x48u, 1u, 1, 0x61A8u, *(_DWORD *)(a1 + 328)) )
        {
          v34 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
          dev_err(v2 + 40, "[E][%s] Device failed to enter READY state\n", "mhi_pm_disable_transition");
          if ( v34 )
          {
            if ( *(_DWORD *)(v34 + 24) <= 2u )
              ipc_log_string(
                *(_QWORD *)(v34 + 32),
                "[E][%s] Device failed to enter READY state\n",
                "mhi_pm_disable_transition");
          }
        }
      }
    }
  }
  v10 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( v10 && !*(_DWORD *)(v10 + 24) )
    ipc_log_string(
      *(_QWORD *)(v10 + 32),
      "[D][%s] Waiting for all pending event ring processing to complete\n",
      "mhi_pm_disable_transition");
  if ( *(_DWORD *)(a1 + 212) )
  {
    v11 = 0;
    v12 = *(_QWORD *)(a1 + 248) + 168LL;
    do
    {
      if ( (*(_BYTE *)(v12 + 90) & 1) == 0 )
      {
        disable_irq(*(unsigned int *)(*(_QWORD *)(a1 + 200) + 4LL * *(unsigned int *)(v12 - 144)));
        if ( *(_DWORD *)(v12 - 136) == 2 )
          cancel_work_sync(v12 + 40);
        else
          tasklet_kill(v12);
      }
      ++v11;
      v12 += 264;
    }
    while ( v11 < *(_DWORD *)(a1 + 212) );
  }
  mutex_unlock(a1 + 272);
  mhi_misc_disable(a1);
  v13 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( v13 && !*(_DWORD *)(v13 + 24) )
    ipc_log_string(
      *(_QWORD *)(v13 + 32),
      "[D][%s] Waiting for all pending threads to complete\n",
      "mhi_pm_disable_transition");
  _wake_up(a1 + 456, 3, 0, 0);
  if ( (a2 & 1) != 0 )
    device_for_each_child(*(_QWORD *)(a1 + 16) + 40LL, 0, mhi_destroy_device);
  mutex_lock(a1 + 272);
  if ( *(_DWORD *)(a1 + 352) )
  {
    __break(0x800u);
    if ( !*(_DWORD *)(a1 + 356) )
      goto LABEL_33;
LABEL_76:
    __break(0x800u);
    goto LABEL_33;
  }
  if ( *(_DWORD *)(a1 + 356) )
    goto LABEL_76;
LABEL_33:
  v14 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( v14 && !*(_DWORD *)(v14 + 24) )
    ipc_log_string(*(_QWORD *)(v14 + 32), "[D][%s] Resetting EV CTXT and CMD CTXT\n", "mhi_pm_disable_transition");
  v15 = *(_QWORD **)(a1 + 256);
  v16 = v15[4];
  v17 = *(_QWORD *)(*(_QWORD *)(a1 + 264) + 16LL);
  v15[5] = v16;
  v15[6] = v16;
  v18 = *(_QWORD *)(v17 + 12);
  *(_QWORD *)(v17 + 28) = v18;
  *(_QWORD *)(v17 + 36) = v18;
  v19 = *(_DWORD *)(a1 + 212);
  if ( v19 )
  {
    v20 = 0;
    v21 = (_BYTE *)(*(_QWORD *)(a1 + 248) + 258LL);
    v22 = (_QWORD *)(**(_QWORD **)(a1 + 264) + 28LL);
    do
    {
      if ( (*v21 & 1) == 0 )
      {
        v23 = *(_QWORD *)(v21 - 186);
        *(_QWORD *)(v21 - 178) = v23;
        *(_QWORD *)(v21 - 170) = v23;
        v24 = *(v22 - 2);
        *v22 = v24;
        v22[1] = v24;
        v19 = *(_DWORD *)(a1 + 212);
      }
      ++v20;
      v21 += 264;
      v22 = (_QWORD *)((char *)v22 + 44);
    }
    while ( v20 < v19 );
  }
  raw_write_lock_irq(a1 + 320);
  v25 = mhi_tryset_pm_state(a1, 1u);
  raw_write_unlock_irq(a1 + 320);
  if ( v25 != 1 )
  {
    v35 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    v36 = to_mhi_pm_state_str(v25);
    v37 = to_mhi_pm_state_str(1u);
    dev_err(v2 + 40, "[E][%s] Error moving from PM state: %s to: %s\n", "mhi_pm_disable_transition", v36, v37);
    if ( v35 )
    {
      if ( *(_DWORD *)(v35 + 24) <= 2u )
      {
        v38 = *(_QWORD *)(v35 + 32);
        v39 = to_mhi_pm_state_str(v25);
        v40 = to_mhi_pm_state_str(1u);
        ipc_log_string(v38, "[E][%s] Error moving from PM state: %s to: %s\n", "mhi_pm_disable_transition", v39, v40);
      }
    }
  }
  v26 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( v26 && !*(_DWORD *)(v26 + 24) )
  {
    v27 = *(_QWORD *)(v26 + 32);
    v28 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
    v29 = *(_DWORD *)(a1 + 348);
    if ( v29 <= 3 )
    {
      if ( v29 > 1 )
      {
        if ( v29 == 2 )
          v30 = "M0";
        else
          v30 = "M1";
        goto LABEL_64;
      }
      if ( !v29 )
      {
        v30 = "RESET";
        goto LABEL_64;
      }
      if ( v29 == 1 )
      {
        v30 = "READY";
        goto LABEL_64;
      }
    }
    else
    {
      if ( v29 <= 5 )
      {
        if ( v29 == 4 )
          v30 = "M2";
        else
          v30 = "M3";
        goto LABEL_64;
      }
      switch ( v29 )
      {
        case 6:
          v30 = "M3_FAST";
          goto LABEL_64;
        case 7:
          v30 = "BHI";
          goto LABEL_64;
        case 255:
          v30 = "SYS ERROR";
LABEL_64:
          ipc_log_string(
            v27,
            "[D][%s] Exiting with PM state: %s, MHI state: %s\n",
            "mhi_pm_disable_transition",
            v28,
            v30);
          return mutex_unlock(a1 + 272);
      }
    }
    v30 = "Unknown state";
    goto LABEL_64;
  }
  return mutex_unlock(a1 + 272);
}
