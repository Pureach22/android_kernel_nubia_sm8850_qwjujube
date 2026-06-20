__int64 __fastcall qdf_mc_timer_stop_sync(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w8
  __int64 v5; // x20
  __int64 v6; // x20

  if ( !a1 )
  {
    v5 = jiffies;
    if ( qdf_mc_timer_stop_sync___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(56, 8, "%s: %s Null timer pointer", "qdf_mc_timer_stop_sync", "qdf_mc_timer_stop_sync");
      qdf_mc_timer_stop_sync___last_ticks = v5;
      return 4;
    }
    return 4;
  }
  if ( *(_DWORD *)(a1 + 44) != 305402420 )
  {
    v6 = jiffies;
    if ( qdf_mc_timer_stop_sync___last_ticks_12 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(56, 8, "%s: %s: Cannot stop uninit timer", "qdf_mc_timer_stop_sync", "qdf_mc_timer_stop_sync");
      qdf_mc_timer_stop_sync___last_ticks_12 = v6;
      return 4;
    }
    return 4;
  }
  v2 = raw_spin_lock_irqsave(a1 + 48);
  v3 = *(_DWORD *)(a1 + 148);
  *(_QWORD *)(a1 + 56) = v2;
  if ( v3 == 21 )
  {
    *(_DWORD *)(a1 + 148) = 19;
    raw_spin_unlock_irqrestore(a1 + 48, v2);
    timer_delete_sync(a1);
    if ( *(_DWORD *)(a1 + 144) == 1 )
    {
      --persistent_timer_count;
      return 0;
    }
  }
  else
  {
    raw_spin_unlock_irqrestore(a1 + 48, v2);
  }
  return 0;
}
