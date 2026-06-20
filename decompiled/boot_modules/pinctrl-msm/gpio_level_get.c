__int64 __fastcall gpio_level_get(int *a1, __int64 *a2)
{
  __int64 data; // x0
  int v5; // w8
  __int64 v6; // x20
  __int64 v7; // x21
  int v8; // w0
  __int64 v9; // x8
  unsigned int v10; // w0
  unsigned __int64 v11; // x8
  char v12; // w9
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x9

  data = gpiochip_get_data(chip_debug);
  v5 = *a1;
  v6 = data + 976;
  v7 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112LL * v5;
  v8 = readl((unsigned int *)(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v7 + 84) >> 5) & 3LL))
                            + *(unsigned int *)(v7 + 60)));
  v9 = *(_QWORD *)(v6 + 8 * ((*(_QWORD *)(v7 + 84) >> 5) & 3LL));
  LODWORD(v6) = v8;
  v10 = readl((unsigned int *)(v9 + *(unsigned int *)(v7 + 64)));
  v11 = *(_QWORD *)(v7 + 84);
  v12 = 52;
  if ( (((unsigned int)v6 >> ((v11 >> 42) & 0x1F)) & 1LL) == 0 )
    v12 = 47;
  v13 = v11 >> v12;
  v14 = v10;
  *a2 = (v14 >> (v13 & 0x1F)) & 1;
  return 0;
}
