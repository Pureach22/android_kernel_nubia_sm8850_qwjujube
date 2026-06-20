__int64 __fastcall gpio_drv_show_pm(int *a1, __int64 a2)
{
  __int64 data; // x0
  __int64 v4; // x19

  data = gpiochip_get_data(a2);
  v4 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112LL * *a1;
  return ((unsigned int)readl(*(_QWORD *)(data + 8 * ((*(_QWORD *)(v4 + 84) >> 5) & 3LL) + 976) + *(unsigned int *)(v4 + 60)) >> (*(_DWORD *)(v4 + 84) >> 17))
       & 7;
}
