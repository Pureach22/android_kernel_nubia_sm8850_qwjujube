__int64 __fastcall st54spi_power_on(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0

  v2 = *(_QWORD *)(a1 + 8);
  if ( !v2 )
    v2 = *(_QWORD *)(a1 + 16);
  result = dev_info(v2, "%s\n", "st54spi_power_on");
  if ( *(_DWORD *)(a1 + 132) && *(_QWORD *)(a1 + 192) )
  {
    result = ktime_get(result);
    v4 = result - *(_QWORD *)(a1 + 192);
    if ( v4 <= 9999999 )
      result = usleep_range_state(1000 * (10 - v4 / 1000000), 1000 * (11 - v4 / 1000000), 2);
    *(_QWORD *)(a1 + 192) = 0;
  }
  if ( *(_DWORD *)(a1 + 128) )
  {
    v5 = ktime_get(result) - *(_QWORD *)(a1 + 176);
    if ( v5 <= 2999999 )
      usleep_range_state(1000 * (3 - v5 / 1000000), 1000 * (4 - v5 / 1000000), 2);
    v6 = gpio_to_desc(*(unsigned int *)(a1 + 128));
    v7 = gpiod_set_raw_value(v6, 1);
    result = ktime_get(v7);
    *(_QWORD *)(a1 + 184) = result;
  }
  if ( !*(_DWORD *)(a1 + 124) )
  {
    v8 = *(_QWORD *)(a1 + 8);
    if ( !v8 )
      v8 = *(_QWORD *)(a1 + 16);
    result = dev_err(v8, "%s : ST54H is not supported\n", "st54spi_power_on");
  }
  *(_DWORD *)(a1 + 144) = 1;
  return result;
}
