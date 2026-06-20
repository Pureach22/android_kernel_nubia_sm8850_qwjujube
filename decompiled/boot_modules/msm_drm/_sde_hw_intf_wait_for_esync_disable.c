size_t __fastcall sde_hw_intf_wait_for_esync_disable(__int64 a1, char a2)
{
  int v3; // w21
  __int64 v4; // x22
  __int64 v5; // x20
  size_t result; // x0
  __int64 v7; // x20
  int v8; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  if ( (a2 & 1) != 0 )
    v3 = 16;
  else
    v3 = 8;
  v4 = *(_QWORD *)a1 + *(unsigned int *)(a1 + 8);
  v5 = ktime_get(a1);
  result = readl_relaxed_9(v4 + 620);
  if ( ((unsigned int)result & v3) != 0 )
  {
    v7 = v5 + 10000000;
    while ( ktime_get(result) <= v7 )
    {
      usleep_range_state(26, 100, 2);
      __yield();
      result = readl_relaxed_9(v4 + 620);
      if ( ((unsigned int)result & v3) == 0 )
        return result;
    }
    result = readl_relaxed_9(v4 + 620);
    if ( ((unsigned int)result & v3) != 0 )
      return sde_evtlog_log(
               sde_dbg_base_evtlog,
               "_sde_hw_intf_wait_for_esync_disable",
               336,
               -1,
               a2 & 1,
               60333,
               -1059143953,
               v8,
               vars0);
  }
  return result;
}
