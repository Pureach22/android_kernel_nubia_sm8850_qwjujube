__int64 __fastcall gpio_direction_get(int *a1, __int64 *a2)
{
  __int64 data; // x0
  __int64 v5; // x20
  unsigned __int64 v6; // x9

  data = gpiochip_get_data(chip_debug);
  v5 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112LL * *a1;
  v6 = (unsigned int)readl((unsigned int *)(*(_QWORD *)(data + 8 * ((*(_QWORD *)(v5 + 84) >> 5) & 3LL) + 976)
                                          + *(unsigned int *)(v5 + 60)));
  *a2 = (v6 >> ((*(_QWORD *)(v5 + 84) >> 42) & 0x1F)) & 1;
  return 0;
}
