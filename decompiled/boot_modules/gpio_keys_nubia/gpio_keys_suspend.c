__int64 __fastcall gpio_keys_suspend(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 v2; // x19
  __int64 v3; // x21
  __int64 v4; // x19
  __int64 v5; // x8
  _QWORD *v6; // x23
  int v7; // w0
  int v8; // w0
  unsigned int v9; // w19
  void (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0
  __int64 result; // x0
  int v13; // w3
  _QWORD *v14; // x19
  unsigned int v15; // w22
  int v16; // w0

  v1 = *(_QWORD **)(a1 + 152);
  v2 = v1[1];
  if ( (*(_WORD *)(a1 + 268) & 1) == 0 || !*(_QWORD *)(a1 + 328) )
  {
    mutex_lock(v2 + 504);
    if ( *(_DWORD *)(v2 + 552) )
    {
      v10 = *(void (__fastcall **)(_QWORD))(**(_QWORD **)(v2 + 712) + 32LL);
      if ( v10 )
      {
        v11 = *(_QWORD *)(v2 + 656);
        if ( *((_DWORD *)v10 - 1) != 1820440776 )
          __break(0x8228u);
        v10(v11);
      }
    }
    mutex_unlock(v2 + 504);
    return 0;
  }
  if ( *(int *)(*v1 + 8LL) < 1 )
    return 0;
  v3 = 0;
  v4 = 0;
  while ( 1 )
  {
    v6 = &v1[v3];
    if ( !*(_DWORD *)(v1[v3 + 9] + 28LL) )
      goto LABEL_5;
    v7 = irq_set_irq_wake(*((unsigned int *)v6 + 65), 1);
    if ( v7 )
      break;
    if ( LODWORD(v1[v3 + 41]) )
    {
      v8 = irq_set_irq_type(*((unsigned int *)v6 + 65));
      if ( v8 )
      {
        v9 = v8;
        dev_err(
          *(_QWORD *)(v1[v3 + 10] + 656LL),
          "failed to set wakeup trigger %08x for IRQ %d: %d\n",
          LODWORD(v1[v3 + 41]),
          HIDWORD(v1[v3 + 32]),
          v8);
        irq_set_irq_wake(HIDWORD(v1[v3 + 32]), 0);
        goto LABEL_20;
      }
    }
LABEL_5:
    v5 = *v1;
    *((_BYTE *)v6 + 338) = 1;
    ++v4;
    v3 += 34;
    if ( v4 >= *(int *)(v5 + 8) )
      return 0;
  }
  v9 = v7;
  dev_err(
    *(_QWORD *)(v1[v3 + 10] + 656LL),
    "failed to configure IRQ %d as wakeup source: %d\n",
    HIDWORD(v1[v3 + 32]),
    v7);
LABEL_20:
  for ( result = v9; v3 * 8; *((_BYTE *)v14 + 66) = 0 )
  {
    v14 = &v1[v3];
    if ( *(_DWORD *)(v1[v3 - 25] + 28LL) )
    {
      v15 = result;
      if ( *((_DWORD *)v14 + 14) )
      {
        v16 = irq_set_irq_type(*((unsigned int *)&v1[v3 - 1] - 1));
        if ( v16 )
          dev_warn(
            *(_QWORD *)(v1[v3 - 24] + 656LL),
            "failed to restore interrupt trigger for IRQ %d: %d\n",
            *((_DWORD *)&v1[v3 - 1] - 1),
            v16);
      }
      v13 = irq_set_irq_wake(*((unsigned int *)&v1[v3 - 1] - 1), 0);
      result = v15;
      if ( v13 )
      {
        dev_warn(
          *(_QWORD *)(v1[v3 - 24] + 656LL),
          "failed to disable IRQ %d as wake source: %d\n",
          *((_DWORD *)&v1[v3 - 1] - 1),
          v13);
        result = v15;
      }
    }
    v3 -= 34;
  }
  return result;
}
