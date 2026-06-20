__int64 __fastcall gpio_func_store_pm(int *a1, __int64 a2, unsigned int a3)
{
  __int64 data; // x21
  __int64 v6; // x22
  __int64 v7; // x20
  int v8; // w0
  int v9; // w11

  data = gpiochip_get_data(a2);
  v6 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112LL * *a1;
  v7 = raw_spin_lock_irqsave(data + 764);
  v8 = readl(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v6 + 84) >> 5) & 3LL)) + *(unsigned int *)(v6 + 60));
  if ( a3 >= 7 )
    v9 = 7;
  else
    v9 = a3;
  writel(
    v8 & ~(7 << ((unsigned int)*(_QWORD *)(v6 + 84) >> 7))
  | (unsigned int)(v9 << ((unsigned int)*(_QWORD *)(v6 + 84) >> 7)),
    *(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v6 + 84) >> 5) & 3LL)) + *(unsigned int *)(v6 + 60));
  raw_spin_unlock_irqrestore(data + 764, v7);
  return 0;
}
