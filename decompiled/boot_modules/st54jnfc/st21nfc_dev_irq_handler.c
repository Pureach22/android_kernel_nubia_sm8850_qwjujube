__int64 __fastcall st21nfc_dev_irq_handler(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v4; // x20

  v2 = *(_QWORD *)(a2 + 520);
  if ( v2 )
    pm_wakeup_ws_event(v2, 500, 0);
  v4 = raw_spin_lock_irqsave(a2 + 532);
  if ( *(_BYTE *)(a2 + 516) == 1 )
  {
    disable_irq_nosync(*(unsigned int *)(*(_QWORD *)(a2 + 168) + 948LL));
    *(_BYTE *)(a2 + 516) = 0;
  }
  raw_spin_unlock_irqrestore(a2 + 532, v4);
  _wake_up(a2, 3, 1, 0);
  return 1;
}
