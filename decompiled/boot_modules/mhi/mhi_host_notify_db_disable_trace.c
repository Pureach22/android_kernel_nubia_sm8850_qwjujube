__int64 __fastcall mhi_host_notify_db_disable_trace(__int64 a1)
{
  __int64 lock_irqsave; // x0
  unsigned int v3; // w8
  __int64 v4; // x20
  __int64 v6; // x8
  int mhi_state; // w21
  unsigned int exec_env; // w0
  __int64 v9; // x8
  __int64 v10; // x8
  const char *v11; // x3
  unsigned int v12; // w22
  const char *v13; // x4
  __int64 v14; // x8
  __int64 v15; // x8

  if ( !*(_QWORD *)(a1 + 64) )
  {
    v6 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( v6 && *(_DWORD *)(v6 + 24) <= 1u )
      ipc_log_string(
        *(_QWORD *)(v6 + 32),
        "[I][%s] Host notifiction DB feature NOT supported or enabled\n",
        "mhi_host_notify_db_disable_trace");
    return 0xFFFFFFFFLL;
  }
  lock_irqsave = raw_read_lock_irqsave(a1 + 320);
  v3 = *(_DWORD *)(a1 + 336);
  v4 = lock_irqsave;
  if ( v3 == 1 )
  {
    raw_read_unlock_irqrestore(a1 + 320, lock_irqsave);
    return 4294967274LL;
  }
  if ( v3 >= 0x80 )
  {
    raw_read_unlock_irqrestore(a1 + 320, lock_irqsave);
    return 4294967291LL;
  }
  mhi_state = mhi_get_mhi_state(a1);
  exec_env = mhi_get_exec_env(a1);
  v9 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( v9 && !*(_DWORD *)(v9 + 24) )
  {
    v10 = *(_QWORD *)(v9 + 32);
    if ( mhi_state <= 3 )
    {
      if ( mhi_state <= 1 )
      {
        if ( !mhi_state )
        {
          v11 = "RESET";
          goto LABEL_32;
        }
        if ( mhi_state == 1 )
        {
          v11 = "READY";
          goto LABEL_32;
        }
        goto LABEL_31;
      }
      if ( mhi_state == 2 )
        v11 = "M0";
      else
        v11 = "M1";
    }
    else
    {
      if ( mhi_state > 5 )
      {
        switch ( mhi_state )
        {
          case 6:
            v11 = "M3_FAST";
            goto LABEL_32;
          case 7:
            v11 = "BHI";
            goto LABEL_32;
          case 255:
            v11 = "SYS ERROR";
            goto LABEL_32;
        }
LABEL_31:
        v11 = "Unknown state";
        goto LABEL_32;
      }
      if ( mhi_state == 4 )
        v11 = "M2";
      else
        v11 = "M3";
    }
LABEL_32:
    v12 = exec_env;
    if ( exec_env <= 9 )
      v13 = mhi_ee_str[exec_env];
    else
      v13 = "INVALID_EE";
    ipc_log_string(v10, "[D][%s] Entered with MHI state: %s, EE: %s\n", "mhi_host_notify_db_disable_trace", v11, v13);
    exec_env = v12;
  }
  if ( mhi_state != 2 || exec_env != 2 )
  {
    raw_read_unlock_irqrestore(a1 + 320, v4);
    v15 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( v15 && *(_DWORD *)(v15 + 24) <= 1u )
      ipc_log_string(
        *(_QWORD *)(v15 + 32),
        "[I][%s] Cannot invoke DB due to invalid M state and/or EE\n",
        "mhi_host_notify_db_disable_trace");
    return 0xFFFFFFFFLL;
  }
  mhi_write_db(a1, *(_QWORD *)(a1 + 64), 1u);
  raw_read_unlock_irqrestore(a1 + 320, v4);
  v14 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( !v14 || *(_DWORD *)(v14 + 24) > 1u )
    return 0;
  ipc_log_string(
    *(_QWORD *)(v14 + 32),
    "[I][%s] Host notification DB write Success\n",
    "mhi_host_notify_db_disable_trace");
  return 0;
}
