__int64 __fastcall gpio_func_get(int *a1, _QWORD *a2)
{
  __int64 data; // x0
  __int64 v5; // x20

  data = gpiochip_get_data(chip_debug);
  v5 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112LL * *a1;
  *a2 = ((unsigned int)readl((unsigned int *)(*(_QWORD *)(data + 8 * ((*(_QWORD *)(v5 + 84) >> 5) & 3LL) + 976)
                                            + *(unsigned int *)(v5 + 60))) >> (*(_DWORD *)(v5 + 84) >> 7))
      & 7;
  return 0;
}
