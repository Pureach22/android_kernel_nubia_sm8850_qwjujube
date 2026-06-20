__int64 __fastcall mhi_async_power_up(__int64 a1)
{
  __int64 v1; // x22
  __int64 v2; // x21
  __int64 v4; // x8
  int v5; // w10
  __int64 (__fastcall *v6)(); // x8
  unsigned int exec_env; // w20
  int mhi_state; // w0
  __int64 v9; // x9
  __int64 v10; // x23
  unsigned int v11; // w0
  __int64 v12; // x8
  unsigned int v13; // w20
  int v14; // w22
  const char *v15; // x4
  __int64 v17; // x22
  unsigned int v18; // w8
  unsigned int v19; // w22
  _BYTE *v20; // x21
  _BOOL4 v21; // w1
  __int64 v22; // x8
  __int64 v23; // x21
  const char *v24; // x3
  const char *v25; // x3

  v1 = *(_QWORD *)(a1 + 16);
  v2 = *(_QWORD *)(a1 + 248);
  v4 = *(_QWORD *)(v1 + 192);
  if ( v4 && *(_DWORD *)(v4 + 24) <= 1u )
    ipc_log_string(*(_QWORD *)(v4 + 32), "[I][%s] Requested to power ON\n", "mhi_async_power_up");
  if ( !*(_QWORD *)(a1 + 488) || !*(_QWORD *)(a1 + 496) || !*(_QWORD *)(a1 + 504) )
  {
    v5 = *(_DWORD *)(a1 + 340);
    *(_QWORD *)(a1 + 488) = mhi_assert_dev_wake;
    *(_QWORD *)(a1 + 496) = mhi_deassert_dev_wake;
    v6 = mhi_toggle_dev_wake_nop;
    if ( (v5 & 8) == 0 )
      v6 = mhi_toggle_dev_wake;
    *(_QWORD *)(a1 + 504) = v6;
  }
  mutex_lock(a1 + 272);
  *(_DWORD *)(a1 + 336) = 1;
  raw_write_lock_irq(a1 + 320);
  mhi_write_reg(a1);
  *(_DWORD *)(a1 + 336) = 2;
  *(_DWORD *)(a1 + 344) = 10;
  exec_env = mhi_get_exec_env(a1);
  raw_write_unlock_irq(a1 + 320);
  if ( exec_env > 6 || ((1 << exec_env) & 0x65) == 0 )
  {
    v23 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( exec_env <= 9 )
      v24 = mhi_ee_str[exec_env];
    else
      v24 = "INVALID_EE";
    dev_err(v1 + 40, "[E][%s] %s is not a valid EE for power on\n", "mhi_async_power_up", v24);
    if ( v23 && *(_DWORD *)(v23 + 24) <= 2u )
    {
      if ( exec_env <= 9 )
        v25 = mhi_ee_str[exec_env];
      else
        v25 = "INVALID_EE";
      ipc_log_string(*(_QWORD *)(v23 + 32), "[E][%s] %s is not a valid EE for power on\n", "mhi_async_power_up", v25);
      v13 = -5;
    }
    else
    {
      v13 = -5;
    }
    goto LABEL_28;
  }
  mhi_state = mhi_get_mhi_state(a1);
  v9 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( !v9 || *(_DWORD *)(v9 + 24) )
  {
    if ( mhi_state != 255 )
      goto LABEL_47;
    goto LABEL_15;
  }
  if ( mhi_state <= 3 )
  {
    if ( mhi_state <= 1 )
    {
      if ( !mhi_state )
      {
        v14 = 0;
        v15 = "RESET";
        goto LABEL_46;
      }
      if ( mhi_state == 1 )
      {
        v14 = 1;
        v15 = "READY";
        goto LABEL_46;
      }
LABEL_45:
      v14 = mhi_state;
      v15 = "Unknown state";
      goto LABEL_46;
    }
    if ( mhi_state == 2 )
    {
      v14 = 2;
      v15 = "M0";
    }
    else
    {
      v14 = 3;
      v15 = "M1";
    }
  }
  else
  {
    if ( mhi_state > 5 )
    {
      switch ( mhi_state )
      {
        case 6:
          v14 = 6;
          v15 = "M3_FAST";
          goto LABEL_46;
        case 7:
          v14 = 7;
          v15 = "BHI";
          goto LABEL_46;
        case 255:
          v14 = 255;
          v15 = "SYS ERROR";
          goto LABEL_46;
      }
      goto LABEL_45;
    }
    if ( mhi_state == 4 )
    {
      v14 = 4;
      v15 = "M2";
    }
    else
    {
      v14 = 5;
      v15 = "M3";
    }
  }
LABEL_46:
  ipc_log_string(
    *(_QWORD *)(v9 + 32),
    "[D][%s] Attempting power on with EE: %s, state: %s\n",
    "mhi_async_power_up",
    mhi_ee_str[exec_env],
    v15);
  if ( v14 != 255 )
    goto LABEL_47;
LABEL_15:
  v10 = *(_QWORD *)(a1 + 16);
  if ( (unsigned int)mhi_write_reg_field(a1, *(_QWORD *)(a1 + 32), 0x38u) )
  {
    v17 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v10 + 40, "[E][%s] Failed to set MHI state to: %s\n", "mhi_set_mhi_state", "RESET");
    if ( v17 )
    {
      if ( *(_DWORD *)(v17 + 24) <= 2u )
        ipc_log_string(*(_QWORD *)(v17 + 32), "[E][%s] Failed to set MHI state to: %s\n", "mhi_set_mhi_state", "RESET");
    }
  }
  v11 = mhi_poll_reg_field(a1, *(_QWORD *)(a1 + 32), 0x38u, 2u, 0, 0x61A8u, *(_DWORD *)(a1 + 328));
  if ( v11 )
  {
    v12 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( v12 )
    {
      v13 = v11;
      if ( *(_DWORD *)(v12 + 24) <= 1u )
        ipc_log_string(*(_QWORD *)(v12 + 32), "[I][%s] Failed to reset MHI due to syserr state\n", "mhi_async_power_up");
    }
    else
    {
      v13 = v11;
    }
LABEL_28:
    *(_DWORD *)(a1 + 336) = 1;
    mutex_unlock(a1 + 272);
    return v13;
  }
  mhi_write_reg(a1);
LABEL_47:
  enable_irq(**(unsigned int **)(a1 + 200));
  v18 = *(_DWORD *)(a1 + 212);
  if ( v18 )
  {
    v19 = 0;
    v20 = (_BYTE *)(v2 + 258);
    do
    {
      if ( (*v20 & 1) == 0 )
      {
        enable_irq(*(unsigned int *)(*(_QWORD *)(a1 + 200) + 4LL * *(unsigned int *)(v20 - 234)));
        v18 = *(_DWORD *)(a1 + 212);
      }
      ++v19;
      v20 += 264;
    }
    while ( v19 < v18 );
  }
  v21 = 0;
  if ( exec_env && exec_env != 5 )
    v21 = exec_env != 6;
  mhi_queue_state_transition(a1, v21);
  mutex_unlock(a1 + 272);
  v22 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( v22 && *(_DWORD *)(v22 + 24) <= 1u )
    ipc_log_string(*(_QWORD *)(v22 + 32), "[I][%s] Power on setup success\n", "mhi_async_power_up");
  return 0;
}
