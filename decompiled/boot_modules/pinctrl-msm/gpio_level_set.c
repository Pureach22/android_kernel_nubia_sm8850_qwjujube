__int64 __fastcall gpio_level_set(int *a1, int a2)
{
  __int64 data; // x21
  __int64 v5; // x22
  __int64 v6; // x20
  int v7; // w0
  unsigned __int64 v8; // x8
  int v9; // w9
  int v10; // w10
  int v11; // w9
  unsigned int v12; // w0

  data = gpiochip_get_data(chip_debug);
  v5 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112LL * *a1;
  v6 = raw_spin_lock_irqsave(data + 764);
  v7 = readl((unsigned int *)(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v5 + 84) >> 5) & 3LL))
                            + *(unsigned int *)(v5 + 64)));
  v8 = *(_QWORD *)(v5 + 84);
  v9 = 1 << (v8 >> 52);
  v10 = v7 | v9;
  v11 = v7 & ~v9;
  if ( a2 )
    v12 = v10;
  else
    v12 = v11;
  writel(v12, (unsigned int *)(*(_QWORD *)(data + 976 + 8 * ((v8 >> 5) & 3)) + *(unsigned int *)(v5 + 64)));
  raw_spin_unlock_irqrestore(data + 764, v6);
  return 0;
}
