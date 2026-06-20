unsigned __int64 __fastcall gpio_level_show_pm(int *a1, __int64 a2)
{
  __int64 data; // x0
  int v4; // w8
  __int64 v5; // x19
  __int64 v6; // x20
  int v7; // w0
  __int64 v8; // x8
  unsigned int v9; // w0
  unsigned __int64 v10; // x8
  char v11; // w9

  data = gpiochip_get_data(a2);
  v4 = *a1;
  v5 = data + 976;
  v6 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112LL * v4;
  v7 = readl(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v6 + 84) >> 5) & 3LL)) + *(unsigned int *)(v6 + 60));
  v8 = *(_QWORD *)(v5 + 8 * ((*(_QWORD *)(v6 + 84) >> 5) & 3LL));
  LODWORD(v5) = v7;
  v9 = readl(v8 + *(unsigned int *)(v6 + 64));
  v10 = *(_QWORD *)(v6 + 84);
  v11 = 52;
  if ( (((unsigned int)v5 >> ((v10 >> 42) & 0x1F)) & 1LL) == 0 )
    v11 = 47;
  return (v9 >> ((v10 >> v11) & 0x1F)) & 1LL;
}
