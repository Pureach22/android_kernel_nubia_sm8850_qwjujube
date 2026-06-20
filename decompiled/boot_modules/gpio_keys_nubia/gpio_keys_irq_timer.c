__int64 __fastcall gpio_keys_irq_timer(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x20

  v2 = *(_QWORD *)(a1 - 24);
  v3 = raw_spin_lock_irqsave(a1 + 228);
  if ( *(_BYTE *)(a1 + 233) == 1 )
  {
    input_event(v2, 1, **(unsigned __int16 **)(a1 - 8), 0);
    input_event(v2, 0, 0, 0);
    *(_BYTE *)(a1 + 233) = 0;
  }
  return raw_spin_unlock_irqrestore(a1 + 228, v3);
}
