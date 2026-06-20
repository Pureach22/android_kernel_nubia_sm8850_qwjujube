__int64 __fastcall msm_gpio_irq_reqres(__int64 a1)
{
  __int64 v1; // x20
  __int64 data; // x19
  __int64 v4; // x24
  __int64 v5; // x25
  __int64 v6; // x23
  unsigned int v7; // w22
  __int64 v8; // x8
  __int64 v9; // x9
  int v10; // w0
  unsigned int v11; // w19
  unsigned int v13; // w23
  __int64 v14; // x22
  __int64 v15; // x26
  __int64 v16; // x23
  int v17; // w0
  __int64 v18; // x21
  __int64 v19; // x20
  unsigned int v20; // w0
  unsigned __int64 v21; // x8

  v1 = *(_QWORD *)(a1 + 48);
  data = gpiochip_get_data(v1);
  v4 = *(_QWORD *)(a1 + 8);
  v5 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL);
  if ( (try_module_get(*(_QWORD *)(v1 + 32)) & 1) == 0 )
    return 4294967277LL;
  v6 = *(_QWORD *)(data + 8);
  v7 = *(_DWORD *)(a1 + 8);
  v8 = *(_QWORD *)(pinctrl_dev_get_drvdata(v6) + 968);
  v9 = *(_QWORD *)(v8 + 32) + 112LL * v7;
  if ( *(_DWORD *)(v9 + 56) )
  {
    v10 = msm_pinmux_set_mux(v6, *(_DWORD *)(*(_QWORD *)(v9 + 48) + 4LL * *(unsigned int *)(v8 + 108)), v7);
    if ( v10 )
      goto LABEL_4;
  }
  v13 = *(_DWORD *)(a1 + 8);
  v14 = gpiochip_get_data(v1);
  v15 = *(_QWORD *)(*(_QWORD *)(v14 + 968) + 32LL) + 112LL * v13;
  v16 = raw_spin_lock_irqsave(v14 + 764);
  v17 = readl((unsigned int *)(*(_QWORD *)(v14 + 976 + 8 * ((*(_QWORD *)(v15 + 84) >> 5) & 3LL))
                             + *(unsigned int *)(v15 + 60)));
  writel(
    v17 & ~(1 << (*(_QWORD *)(v15 + 84) >> 42)),
    (unsigned int *)(*(_QWORD *)(v14 + 976 + 8 * ((*(_QWORD *)(v15 + 84) >> 5) & 3LL)) + *(unsigned int *)(v15 + 60)));
  raw_spin_unlock_irqrestore(v14 + 764, v16);
  if ( (unsigned int)gpiochip_lock_as_irq(v1, *(unsigned int *)(a1 + 8)) )
  {
    dev_err(*(_QWORD *)(v1 + 16), "unable to lock HW IRQ %lu for IRQ\n", *(_QWORD *)(a1 + 8));
    v10 = -22;
LABEL_4:
    v11 = v10;
    module_put(*(_QWORD *)(v1 + 32));
    return v11;
  }
  irq_modify_status(*(unsigned int *)(a1 + 4), 0, 0x80000);
  if ( ((*(_QWORD *)(data + 8LL * (*(_QWORD *)(a1 + 8) >> 6) + 848) >> *(_QWORD *)(a1 + 8)) & 1) != 0 )
  {
    v18 = v5 + 112 * v4;
    if ( (*(_WORD *)(v18 + 92) & 0x7C0) != 0 )
    {
      v19 = raw_spin_lock_irqsave(data + 764);
      v20 = readl((unsigned int *)(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v18 + 84) >> 5) & 3LL))
                                 + *(unsigned int *)(v18 + 68)));
      v21 = *(_QWORD *)(v18 + 92);
      if ( ((v20 >> ((v21 >> 6) & 0x1F)) & 1) != 0 )
        writel(
          v20 | (1 << (v21 >> 11)),
          (unsigned int *)(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v18 + 84) >> 5) & 3LL))
                         + *(unsigned int *)(v18 + 68)));
      raw_spin_unlock_irqrestore(data + 764, v19);
    }
  }
  return 0;
}
