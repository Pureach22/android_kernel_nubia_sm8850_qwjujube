__int64 __fastcall gpio_pull_show_pm(int *a1, __int64 a2)
{
  __int64 data; // x20
  __int64 v4; // x19
  unsigned int v5; // w8

  data = gpiochip_get_data(a2);
  v4 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112LL * *a1;
  v5 = ((unsigned int)readl(*(_QWORD *)(data + 8 * ((*(_QWORD *)(v4 + 84) >> 5) & 3LL) + 976) + *(unsigned int *)(v4 + 60)) >> (*(_DWORD *)(v4 + 84) >> 12))
     & 3;
  if ( (*(_BYTE *)(*(_QWORD *)(data + 968) + 48LL) & (v5 == 2)) != 0 )
    return 3;
  else
    return v5;
}
