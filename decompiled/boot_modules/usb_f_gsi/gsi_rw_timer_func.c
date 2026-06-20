__int64 __fastcall gsi_rw_timer_func(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x20
  __int64 v4; // x0

  v1 = result;
  v2 = result - 1360;
  if ( *(_DWORD *)(result - 1088) )
  {
    if ( result == 1360 )
    {
      result = gsi_wakeup_host(0);
      if ( !*(_BYTE *)(v1 + 40) )
        return result;
    }
    else
    {
      ipc_log_string(*(_QWORD *)(result - 16), "%s: calling gsi_wakeup_host\n", "gsi_rw_timer_func");
      result = gsi_wakeup_host(v2);
      if ( !*(_BYTE *)(v1 + 40) )
        return result;
      ipc_log_string(*(_QWORD *)(v1 - 16), "%s: re-arm the timer\n", "gsi_rw_timer_func");
    }
    v3 = jiffies;
    v4 = _msecs_to_jiffies(*(unsigned __int16 *)(v1 + 42));
    return mod_timer(v1, v4 + v3);
  }
  else
  {
    if ( result != 1360 )
      result = ipc_log_string(*(_QWORD *)(result - 16), "%s: gsi not connected.. bail-out\n", "gsi_rw_timer_func");
    *(_BYTE *)(v1 + 40) = 0;
  }
  return result;
}
