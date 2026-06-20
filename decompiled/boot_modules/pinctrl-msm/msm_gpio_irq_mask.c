__int64 __fastcall msm_gpio_irq_mask(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x19
  unsigned __int64 v4; // x8
  __int64 v5; // x22
  __int64 v6; // x21
  int v7; // w0
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x8
  unsigned __int64 v17; // x10

  result = gpiochip_get_data(*(_QWORD *)(a1 + 48));
  v3 = result;
  if ( *(_QWORD *)(a1 + 40) )
    result = irq_chip_mask_parent(a1);
  v4 = *(_QWORD *)(a1 + 8);
  if ( ((*(_QWORD *)(v3 + 8 * (v4 >> 6) + 848) >> v4) & 1) == 0 )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(v3 + 968) + 32LL) + 112 * v4;
    v6 = raw_spin_lock_irqsave(v3 + 764);
    v7 = readl((unsigned int *)(*(_QWORD *)(v3 + 976 + 8 * ((*(_QWORD *)(v5 + 84) >> 5) & 3LL))
                              + *(unsigned int *)(v5 + 68)));
    if ( (**(_BYTE **)(a1 + 16) & 0xC) != 0 )
      v7 &= ~(1 << *(_DWORD *)(v5 + 96));
    writel(
      v7 & ~(1 << (*(_QWORD *)(v5 + 84) >> 57)),
      (unsigned int *)(*(_QWORD *)(v3 + 976 + 8 * ((*(_QWORD *)(v5 + 84) >> 5) & 3LL)) + *(unsigned int *)(v5 + 68)));
    v8 = *(_QWORD *)(a1 + 8);
    v9 = (unsigned int)v8 >> 6;
    v10 = 1LL << v8;
    _X9 = (unsigned __int64 *)(v3 + 808 + 8 * v9);
    __asm { PRFM            #0x11, [X9] }
    do
      v17 = __ldxr(_X9);
    while ( __stxr(v17 & ~v10, _X9) );
    return raw_spin_unlock_irqrestore(v3 + 764, v6);
  }
  return result;
}
