__int64 __fastcall qdf_mc_timer_destroy(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w8
  __int64 v4; // x1
  unsigned int v6; // w20

  if ( !a1 )
  {
    qdf_trace_msg(56, 2, "%s: Null timer pointer being passed", "qdf_mc_timer_destroy");
    return 5;
  }
  if ( *(_DWORD *)(a1 + 44) != 305402420 )
  {
    qdf_trace_msg(56, 2, "%s: Cannot destroy uninitialized timer", "qdf_mc_timer_destroy");
    return 4;
  }
  v2 = raw_spin_lock_irqsave(a1 + 48);
  v3 = *(_DWORD *)(a1 + 148);
  v4 = v2;
  *(_QWORD *)(a1 + 56) = v2;
  if ( v3 > 19 )
  {
    if ( v3 == 20 )
    {
      v6 = 8;
      goto LABEL_16;
    }
    if ( v3 != 21 )
      goto LABEL_13;
    timer_delete((timer_t)a1);
    v4 = *(_QWORD *)(a1 + 56);
LABEL_12:
    *(_DWORD *)(a1 + 148) = 18;
    *(_DWORD *)(a1 + 44) = -17958194;
    raw_spin_unlock_irqrestore(a1 + 48, v4);
    return 0;
  }
  if ( v3 == 18 )
  {
    v6 = 6;
    goto LABEL_16;
  }
  if ( v3 == 19 )
    goto LABEL_12;
LABEL_13:
  v6 = 5;
LABEL_16:
  raw_spin_unlock_irqrestore(a1 + 48, v2);
  qdf_trace_msg(56, 5, "%s: Cannot destroy timer in state = %d", "qdf_mc_timer_destroy", *(_DWORD *)(a1 + 148));
  return v6;
}
