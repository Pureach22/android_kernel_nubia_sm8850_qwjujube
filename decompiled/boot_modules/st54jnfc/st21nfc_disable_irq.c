__int64 __fastcall st21nfc_disable_irq(__int64 a1)
{
  __int64 v2; // x20

  v2 = raw_spin_lock_irqsave(a1 + 532);
  if ( *(_BYTE *)(a1 + 516) == 1 )
  {
    disable_irq_nosync(*(unsigned int *)(*(_QWORD *)(a1 + 168) + 948LL));
    *(_BYTE *)(a1 + 516) = 0;
  }
  return raw_spin_unlock_irqrestore(a1 + 532, v2);
}
