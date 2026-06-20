__int64 __fastcall st21nfc_poll(__int64 a1, void (**a2)(void))
{
  __int64 v2; // x22
  void (*v3)(void); // x8
  int value; // w21
  __int64 v5; // x20
  unsigned int v6; // w21
  __int64 v7; // x9

  v2 = *(_QWORD *)(a1 + 32);
  if ( a2 )
  {
    if ( v2 != 176 )
    {
      v3 = *a2;
      if ( *a2 )
      {
        if ( *((_DWORD *)v3 - 1) != -442429149 )
          __break(0x8228u);
        v3();
        __dmb(0xBu);
      }
    }
  }
  value = gpiod_get_value(*(_QWORD *)(v2 + 768));
  mutex_lock(v2 - 56);
  v5 = raw_spin_lock_irqsave(v2 + 356);
  if ( value )
  {
    if ( *(_BYTE *)(v2 + 340) )
    {
      disable_irq_nosync(*(unsigned int *)(*(_QWORD *)(v2 - 8) + 948LL));
      *(_BYTE *)(v2 + 340) = 0;
    }
    v6 = 65;
  }
  else
  {
    if ( (*(_BYTE *)(v2 + 340) & 1) == 0 )
    {
      v7 = *(_QWORD *)(v2 - 8);
      *(_BYTE *)(v2 + 340) = 1;
      enable_irq(*(unsigned int *)(v7 + 948));
    }
    v6 = 0;
  }
  raw_spin_unlock_irqrestore(v2 + 356, v5);
  mutex_unlock(v2 - 56);
  return v6;
}
