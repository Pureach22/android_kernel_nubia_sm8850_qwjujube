__int64 __fastcall st21nfc_loc_set_polaritymode(__int64 a1, int a2)
{
  int v2; // w8
  __int64 v3; // x21
  unsigned int v5; // w20
  __int64 v6; // x4
  __int64 v7; // x20
  void *v9; // x0

  v2 = *(unsigned __int8 *)(a1 + 528);
  v3 = *(_QWORD *)(a1 + 168);
  if ( a2 == 4 )
    v5 = 4;
  else
    v5 = 1;
  *(_DWORD *)(a1 + 980) = a2;
  if ( v2 == 1 )
  {
    devm_free_irq(v3 + 32, *(unsigned int *)(v3 + 948), a1);
    *(_BYTE *)(a1 + 528) = 0;
  }
  if ( (unsigned int)irq_set_irq_type(*(unsigned int *)(v3 + 948), v5) )
  {
    v9 = &unk_8624;
    return printk(v9, "st21nfc_loc_set_polaritymode");
  }
  v6 = *(unsigned int *)(a1 + 980);
  *(_BYTE *)(a1 + 516) = 1;
  if ( (unsigned int)devm_request_threaded_irq(
                       v3 + 32,
                       *(unsigned int *)(v3 + 948),
                       st21nfc_dev_irq_handler,
                       0,
                       v6,
                       v3 + 4,
                       a1) )
  {
    v9 = &unk_84B9;
    return printk(v9, "st21nfc_loc_set_polaritymode");
  }
  *(_BYTE *)(a1 + 528) = 1;
  v7 = raw_spin_lock_irqsave(a1 + 532);
  if ( *(_BYTE *)(a1 + 516) == 1 )
  {
    disable_irq_nosync(*(unsigned int *)(*(_QWORD *)(a1 + 168) + 948LL));
    *(_BYTE *)(a1 + 516) = 0;
  }
  return raw_spin_unlock_irqrestore(a1 + 532, v7);
}
