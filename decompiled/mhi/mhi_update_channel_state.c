__int64 __fastcall mhi_update_channel_state(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x23
  __int64 v7; // x8
  int v8; // w22
  unsigned int v9; // w8
  __int64 result; // x0
  void (__fastcall *v11)(_QWORD); // x8
  unsigned int v12; // w0
  __int64 v13; // x0
  int v14; // w8
  __int64 v15; // x8
  unsigned int v16; // w22
  void (__fastcall *v17)(_QWORD); // x8
  __int64 v18; // x22
  const char *v19; // x21
  __int64 v20; // x24
  const char *v21; // x21

  v3 = *(_QWORD *)(a2 + 272);
  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( v7 && !*(_DWORD *)(v7 + 24) )
    ipc_log_string(
      *(_QWORD *)(v7 + 32),
      "[D][%s] %d: Updating channel state to: %s\n",
      "mhi_update_channel_state",
      *(_DWORD *)(a2 + 200),
      mhi_ch_state_type_str[a3]);
  if ( a3 == 2 )
  {
    if ( (*(_DWORD *)(a2 + 260) | 4) != 4 )
      return 4294967274LL;
    v8 = 18;
  }
  else
  {
    if ( a3 == 1 )
    {
      if ( *(_DWORD *)(a2 + 260) == 1 )
      {
        v8 = 17;
        goto LABEL_13;
      }
      return 4294967274LL;
    }
    raw_write_lock_irq(a2 + 368);
    v9 = *(_DWORD *)(a2 + 260);
    if ( v9 > 4 || ((1 << v9) & 0x1A) == 0 )
    {
      raw_write_unlock_irq(a2 + 368);
      return 4294967274LL;
    }
    *(_DWORD *)(a2 + 260) = 0;
    raw_write_unlock_irq(a2 + 368);
    v8 = 16;
  }
LABEL_13:
  result = mhi_device_get_sync(*(_QWORD *)(a1 + 16));
  if ( !(_DWORD)result )
  {
    v11 = *(void (__fastcall **)(_QWORD))(a1 + 512);
    if ( *((_DWORD *)v11 - 1) != -700558418 )
      __break(0x8228u);
    v11(a1);
    *(_DWORD *)(a2 + 336) = 0;
    v12 = mhi_send_cmd(a1, a2, v8);
    if ( v12 )
    {
      v16 = v12;
      v20 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      v21 = mhi_ch_state_type_str[a3];
      dev_err(
        v3 + 40,
        "[E][%s] %d: Failed to send %s channel command\n",
        "mhi_update_channel_state",
        *(_DWORD *)(a2 + 200),
        v21);
      if ( v20 && *(_DWORD *)(v20 + 24) <= 2u )
        ipc_log_string(
          *(_QWORD *)(v20 + 32),
          "[E][%s] %d: Failed to send %s channel command\n",
          "mhi_update_channel_state",
          *(_DWORD *)(a2 + 200),
          v21);
    }
    else
    {
      v13 = _msecs_to_jiffies(*(unsigned int *)(a1 + 328));
      if ( (unsigned int)wait_for_completion_timeout(a2 + 336, v13) && *(_DWORD *)(a2 + 264) == 1 )
      {
        if ( a3 )
        {
          raw_write_lock_irq(a2 + 368);
          if ( a3 == 2 )
            v14 = 1;
          else
            v14 = 4;
          *(_DWORD *)(a2 + 260) = v14;
          raw_write_unlock_irq(a2 + 368);
        }
        v15 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
        if ( v15 && !*(_DWORD *)(v15 + 24) )
          ipc_log_string(
            *(_QWORD *)(v15 + 32),
            "[D][%s] %d: Channel state change to %s successful\n",
            "mhi_update_channel_state",
            *(_DWORD *)(a2 + 200),
            mhi_ch_state_type_str[a3]);
        v16 = 0;
      }
      else
      {
        v18 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
        v19 = mhi_ch_state_type_str[a3];
        dev_err(
          v3 + 40,
          "[E][%s] %d: Failed to receive %s channel command completion\n",
          "mhi_update_channel_state",
          *(_DWORD *)(a2 + 200),
          v19);
        if ( v18 && *(_DWORD *)(v18 + 24) <= 2u )
        {
          ipc_log_string(
            *(_QWORD *)(v18 + 32),
            "[E][%s] %d: Failed to receive %s channel command completion\n",
            "mhi_update_channel_state",
            *(_DWORD *)(a2 + 200),
            v19);
          v16 = -5;
        }
        else
        {
          v16 = -5;
        }
      }
    }
    v17 = *(void (__fastcall **)(_QWORD))(a1 + 528);
    if ( *((_DWORD *)v17 - 1) != -2145957670 )
      __break(0x8228u);
    v17(a1);
    mhi_device_put(*(_QWORD *)(a1 + 16));
    return v16;
  }
  return result;
}
