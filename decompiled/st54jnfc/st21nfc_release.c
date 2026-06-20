__int64 __fastcall st21nfc_release(__int64 a1, __int64 a2)
{
  _BYTE *v2; // x21
  __int64 v3; // x20

  v2 = *(_BYTE **)(a2 + 32);
  if ( v2[352] == 1 )
  {
    v3 = raw_spin_lock_irqsave(v2 + 356);
    if ( v2[340] == 1 )
    {
      disable_irq_nosync(*(unsigned int *)(*((_QWORD *)v2 - 1) + 948LL));
      v2[340] = 0;
    }
    raw_spin_unlock_irqrestore(v2 + 356, v3);
    devm_free_irq(*((_QWORD *)v2 - 1) + 32LL, *(unsigned int *)(*((_QWORD *)v2 - 1) + 948LL), v2 - 176);
    v2[352] = 0;
  }
  v2[353] = 0;
  return 0;
}
