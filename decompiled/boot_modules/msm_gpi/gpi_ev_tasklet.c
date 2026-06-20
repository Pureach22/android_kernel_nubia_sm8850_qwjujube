__int64 __fastcall gpi_ev_tasklet(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x5
  __int64 v4; // x6
  __int64 v5; // x8
  const char *v6; // x4
  __int64 v7; // x8
  const char *v8; // x4

  raw_read_lock_bh(a1 + 948);
  if ( *(_DWORD *)(a1 + 944) > 1u )
  {
    gpi_process_events(a1);
    gpi_config_interrupts(a1, 1, 1);
    return raw_read_unlock_bh(a1 + 948);
  }
  raw_read_unlock_bh(a1 + 948);
  if ( *(_DWORD *)(a1 + 1068) >= 2u )
  {
    v7 = *(unsigned int *)(a1 + 944);
    if ( (unsigned int)v7 <= 5 )
      v8 = gpi_pm_state_str[v7];
    else
      v8 = "INVALID";
    printk(&unk_14AB4, a1 + 1076, 99, "gpi_ev_tasklet", v8, v3, v4);
    result = *(_QWORD *)(a1 + 1056);
    if ( !result )
      return result;
  }
  else
  {
    result = *(_QWORD *)(a1 + 1056);
    if ( !result )
      return result;
  }
  if ( *(_DWORD *)(a1 + 1064) >= 2u )
  {
    v5 = *(unsigned int *)(a1 + 944);
    if ( (unsigned int)v5 <= 5 )
      v6 = gpi_pm_state_str[v5];
    else
      v6 = "INVALID";
    return ipc_log_string(result, "ch:%u %s: not processing any events, pm_state:%s\n", 99, "gpi_ev_tasklet", v6);
  }
  return result;
}
