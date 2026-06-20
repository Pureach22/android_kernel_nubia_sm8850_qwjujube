__int64 __fastcall gpio_func_set(int *a1, unsigned int a2)
{
  __int64 data; // x21
  __int64 v5; // x22
  __int64 v6; // x20
  int v7; // w0
  int v8; // w11

  data = gpiochip_get_data(chip_debug);
  v5 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112LL * *a1;
  v6 = raw_spin_lock_irqsave(data + 764);
  v7 = readl((unsigned int *)(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v5 + 84) >> 5) & 3LL))
                            + *(unsigned int *)(v5 + 60)));
  if ( a2 >= 7 )
    v8 = 7;
  else
    v8 = a2;
  writel(
    v7 & ~(7 << ((unsigned int)*(_QWORD *)(v5 + 84) >> 7)) | (v8 << ((unsigned int)*(_QWORD *)(v5 + 84) >> 7)),
    (unsigned int *)(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v5 + 84) >> 5) & 3LL)) + *(unsigned int *)(v5 + 60)));
  raw_spin_unlock_irqrestore(data + 764, v6);
  return 0;
}
