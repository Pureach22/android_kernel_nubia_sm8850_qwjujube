__int64 __fastcall gpio_pull_get(int *a1, __int64 *a2)
{
  __int64 data; // x21
  __int64 v5; // x20
  unsigned int v6; // w8
  __int64 result; // x0
  __int64 v8; // x8

  data = gpiochip_get_data(chip_debug);
  v5 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112LL * *a1;
  v6 = (unsigned int)readl((unsigned int *)(*(_QWORD *)(data + 8 * ((*(_QWORD *)(v5 + 84) >> 5) & 3LL) + 976)
                                          + *(unsigned int *)(v5 + 60))) >> (*(_DWORD *)(v5 + 84) >> 12);
  result = 0;
  v8 = v6 & 3;
  if ( (*(_BYTE *)(*(_QWORD *)(data + 968) + 48LL) & ((_DWORD)v8 == 2)) != 0 )
    v8 = 3;
  *a2 = v8;
  return result;
}
