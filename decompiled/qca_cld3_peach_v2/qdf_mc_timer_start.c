__int64 __fastcall qdf_mc_timer_start(__int64 a1, unsigned int a2)
{
  __int64 v5; // x0
  int v6; // w9
  __int64 v7; // x22
  __int64 v8; // x23
  __int64 v9; // x0
  int v10; // w9

  if ( !a1 )
  {
    qdf_trace_msg(56, 2, "%s Null timer pointer being passed", "qdf_mc_timer_start");
    return 4;
  }
  if ( *(_DWORD *)(a1 + 44) != 305402420 )
  {
    qdf_trace_msg(56, 2, "%s: Cannot start uninitialized timer", "qdf_mc_timer_start");
    return 4;
  }
  if ( a2 <= 9 )
  {
    qdf_trace_msg(56, 2, "%s: Cannot start a timer with expiration less than 10 ms", "qdf_mc_timer_start");
    return 4;
  }
  v5 = raw_spin_lock_irqsave(a1 + 48);
  v6 = *(_DWORD *)(a1 + 148);
  *(_QWORD *)(a1 + 56) = v5;
  if ( v6 == 19 )
  {
    v7 = jiffies;
    v8 = (unsigned int)g_qdf_timer_multiplier;
    v9 = _msecs_to_jiffies(a2);
    mod_timer(a1, v7 + v9 * v8);
    *(_DWORD *)(a1 + 148) = 21;
    v10 = *(_DWORD *)(a1 + 144);
    *(_QWORD *)(a1 + 152) = jiffies;
    *(_DWORD *)(a1 + 40) = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
    if ( v10 == 1 )
      ++persistent_timer_count;
    raw_spin_unlock_irqrestore(a1 + 48, *(_QWORD *)(a1 + 56));
    return 0;
  }
  else
  {
    raw_spin_unlock_irqrestore(a1 + 48, v5);
    qdf_trace_msg(
      56,
      2,
      "%s: Cannot start timer in state = %d %ps",
      "qdf_mc_timer_start",
      *(_DWORD *)(a1 + 148),
      *(const void **)(a1 + 64));
    return 6;
  }
}
