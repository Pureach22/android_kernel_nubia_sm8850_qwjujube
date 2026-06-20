__int64 __fastcall mhi_unprepare_channel(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v5; // x8
  unsigned __int64 v6; // x4
  __int64 v7; // x8
  __int64 v9; // x9
  const char *v10; // x3
  __int64 v11; // x22

  v2 = *(_QWORD *)(a2 + 272);
  mutex_lock(a2 + 288);
  v5 = *(unsigned int *)(a1 + 344);
  v6 = *(unsigned int *)(a2 + 256);
  if ( ((v6 >> v5) & 1) != 0 )
  {
    if ( (unsigned int)mhi_update_channel_state(a1, a2, 0) )
    {
      v11 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      dev_err(
        v2 + 40,
        "[E][%s] %d: Failed to reset channel, still resetting\n",
        "mhi_unprepare_channel",
        *(_DWORD *)(a2 + 200));
      if ( v11 )
      {
        if ( *(_DWORD *)(v11 + 24) <= 2u )
          ipc_log_string(
            *(_QWORD *)(v11 + 32),
            "[E][%s] %d: Failed to reset channel, still resetting\n",
            "mhi_unprepare_channel",
            *(_DWORD *)(a2 + 200));
      }
    }
  }
  else
  {
    v9 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( v9 && !*(_DWORD *)(v9 + 24) )
    {
      if ( (unsigned int)v5 <= 9 )
        v10 = mhi_ee_str[v5];
      else
        v10 = "INVALID_EE";
      ipc_log_string(
        *(_QWORD *)(v9 + 32),
        "[D][%s] Current EE: %s Required EE Mask: 0x%x\n",
        "mhi_unprepare_channel",
        v10,
        v6);
    }
  }
  raw_write_lock_irq(a2 + 368);
  *(_DWORD *)(a2 + 260) = 0;
  raw_write_unlock_irq(a2 + 368);
  if ( (*(_BYTE *)(a2 + 394) & 1) == 0 )
  {
    mhi_reset_chan(a1, a2);
    mhi_deinit_chan_ctxt(a1, a2);
  }
  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( v7 && !*(_DWORD *)(v7 + 24) )
    ipc_log_string(
      *(_QWORD *)(v7 + 32),
      "[D][%s] %d: successfully reset\n",
      "mhi_unprepare_channel",
      *(_DWORD *)(a2 + 200));
  return mutex_unlock(a2 + 288);
}
