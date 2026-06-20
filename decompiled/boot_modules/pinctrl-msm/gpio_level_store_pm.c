__int64 __fastcall gpio_level_store_pm(int *a1, __int64 a2, int a3)
{
  __int64 data; // x21
  __int64 v6; // x22
  __int64 v7; // x20
  int v8; // w0
  unsigned __int64 v9; // x8
  int v10; // w9
  unsigned int v11; // w10
  unsigned int v12; // w9
  __int64 v13; // x0

  data = gpiochip_get_data(a2);
  v6 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112LL * *a1;
  v7 = raw_spin_lock_irqsave(data + 764);
  v8 = readl(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v6 + 84) >> 5) & 3LL)) + *(unsigned int *)(v6 + 64));
  v9 = *(_QWORD *)(v6 + 84);
  v10 = 1 << (v9 >> 52);
  v11 = v8 | v10;
  v12 = v8 & ~v10;
  if ( a3 )
    v13 = v11;
  else
    v13 = v12;
  writel(v13, *(_QWORD *)(data + 976 + 8 * ((v9 >> 5) & 3)) + *(unsigned int *)(v6 + 64));
  raw_spin_unlock_irqrestore(data + 764, v7);
  return 0;
}
