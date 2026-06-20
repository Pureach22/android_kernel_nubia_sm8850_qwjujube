__int64 __fastcall msm_gpio_direction_input(__int64 a1, unsigned int a2)
{
  __int64 data; // x20
  __int64 v4; // x21
  __int64 v5; // x19
  int v6; // w0

  data = gpiochip_get_data(a1);
  v4 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112LL * a2;
  v5 = raw_spin_lock_irqsave(data + 764);
  v6 = readl((unsigned int *)(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v4 + 84) >> 5) & 3LL))
                            + *(unsigned int *)(v4 + 60)));
  writel(
    v6 & ~(1 << (*(_QWORD *)(v4 + 84) >> 42)),
    (unsigned int *)(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v4 + 84) >> 5) & 3LL)) + *(unsigned int *)(v4 + 60)));
  raw_spin_unlock_irqrestore(data + 764, v5);
  return 0;
}
