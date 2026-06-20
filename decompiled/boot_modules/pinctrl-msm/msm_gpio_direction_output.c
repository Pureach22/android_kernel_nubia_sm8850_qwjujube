__int64 __fastcall msm_gpio_direction_output(__int64 a1, unsigned int a2, int a3)
{
  __int64 data; // x19
  __int64 v6; // x22
  __int64 v7; // x23
  __int64 v8; // x21
  int v9; // w0
  unsigned __int64 v10; // x8
  int v11; // w9
  int v12; // w10
  int v13; // w9
  unsigned int v14; // w0
  int v15; // w0

  data = gpiochip_get_data(a1);
  v6 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112LL * a2;
  v7 = data + 976;
  v8 = raw_spin_lock_irqsave(data + 764);
  v9 = readl((unsigned int *)(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v6 + 84) >> 5) & 3LL))
                            + *(unsigned int *)(v6 + 64)));
  v10 = *(_QWORD *)(v6 + 84);
  v11 = 1 << (v10 >> 52);
  v12 = v9 | v11;
  v13 = v9 & ~v11;
  if ( a3 )
    v14 = v12;
  else
    v14 = v13;
  writel(v14, (unsigned int *)(*(_QWORD *)(data + 976 + 8 * ((v10 >> 5) & 3)) + *(unsigned int *)(v6 + 64)));
  v15 = readl((unsigned int *)(*(_QWORD *)(v7 + 8 * ((*(_QWORD *)(v6 + 84) >> 5) & 3LL)) + *(unsigned int *)(v6 + 60)));
  writel(
    v15 | (1 << (*(_QWORD *)(v6 + 84) >> 42)),
    (unsigned int *)(*(_QWORD *)(v7 + 8 * ((*(_QWORD *)(v6 + 84) >> 5) & 3LL)) + *(unsigned int *)(v6 + 60)));
  raw_spin_unlock_irqrestore(data + 764, v8);
  return 0;
}
