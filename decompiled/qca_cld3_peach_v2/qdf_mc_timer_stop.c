__int64 __fastcall qdf_mc_timer_stop(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w20
  __int64 v4; // x0
  __int64 v6; // x20
  __int64 v7; // x20

  if ( !a1 )
  {
    v6 = jiffies;
    if ( qdf_mc_timer_stop___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(56, 8, "%s: %s Null timer pointer", "qdf_mc_timer_stop", "qdf_mc_timer_stop");
      qdf_mc_timer_stop___last_ticks = v6;
      return 4;
    }
    return 4;
  }
  if ( *(_DWORD *)(a1 + 44) != 305402420 )
  {
    v7 = jiffies;
    if ( qdf_mc_timer_stop___last_ticks_10 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(56, 8, "%s: %s: Cannot stop uninit timer", "qdf_mc_timer_stop", "qdf_mc_timer_stop");
      qdf_mc_timer_stop___last_ticks_10 = v7;
      return 4;
    }
    return 4;
  }
  v2 = raw_spin_lock_irqsave(a1 + 48);
  v3 = *(_DWORD *)(a1 + 148);
  *(_QWORD *)(a1 + 56) = v2;
  raw_spin_unlock_irqrestore(a1 + 48, v2);
  if ( v3 != 21 )
    return 0;
  timer_delete((timer_t)a1);
  v4 = raw_spin_lock_irqsave(a1 + 48);
  *(_QWORD *)(a1 + 56) = v4;
  *(_DWORD *)(a1 + 148) = 19;
  raw_spin_unlock_irqrestore(a1 + 48, v4);
  if ( *(_DWORD *)(a1 + 144) != 1 )
    return 0;
  --persistent_timer_count;
  return 0;
}
