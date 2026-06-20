__int64 __fastcall msm_gpio_irq_relres(__int64 a1)
{
  __int64 v1; // x19
  __int64 data; // x0
  unsigned __int64 v4; // x1
  __int64 v5; // x23
  __int64 v6; // x21
  __int64 v7; // x22
  unsigned int v8; // w0
  unsigned __int64 v9; // x8

  v1 = *(_QWORD *)(a1 + 48);
  data = gpiochip_get_data(v1);
  v4 = *(_QWORD *)(a1 + 8);
  if ( ((*(_QWORD *)(data + 8 * (v4 >> 6) + 848) >> v4) & 1) != 0 )
  {
    v5 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112 * v4;
    if ( (*(_WORD *)(v5 + 92) & 0x7C0) != 0 )
    {
      v6 = data;
      v7 = raw_spin_lock_irqsave(data + 764);
      v8 = readl((unsigned int *)(*(_QWORD *)(v6 + 976 + 8 * ((*(_QWORD *)(v5 + 84) >> 5) & 3LL))
                                + *(unsigned int *)(v5 + 68)));
      v9 = *(_QWORD *)(v5 + 92);
      if ( ((v8 >> ((v9 >> 6) & 0x1F)) & 1) != 0 )
        writel(
          v8 & ~(1 << (v9 >> 11)),
          (unsigned int *)(*(_QWORD *)(v6 + 976 + 8 * ((*(_QWORD *)(v5 + 84) >> 5) & 3LL)) + *(unsigned int *)(v5 + 68)));
      raw_spin_unlock_irqrestore(v6 + 764, v7);
      v4 = *(_QWORD *)(a1 + 8);
    }
  }
  gpiochip_unlock_as_irq(v1, v4);
  return module_put(*(_QWORD *)(v1 + 32));
}
