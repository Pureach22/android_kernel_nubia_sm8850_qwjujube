__int64 __fastcall qdf_mc_timer_get_current_state(__int64 a1)
{
  unsigned int v1; // w19
  __int64 v3; // x0
  unsigned int v4; // w8

  v1 = 18;
  if ( a1 )
  {
    v3 = raw_spin_lock_irqsave(a1 + 48);
    v4 = *(_DWORD *)(a1 + 148);
    *(_QWORD *)(a1 + 56) = v3;
    if ( v4 - 18 >= 4 )
      v1 = 18;
    else
      v1 = v4;
    raw_spin_unlock_irqrestore(a1 + 48, v3);
  }
  return v1;
}
