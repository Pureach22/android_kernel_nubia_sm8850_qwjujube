__int64 __fastcall st54spi_power_off(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0

  v2 = *(_QWORD *)(a1 + 8);
  if ( !v2 )
    v2 = *(_QWORD *)(a1 + 16);
  dev_info(v2, "%s\n", "st54spi_power_off");
  if ( *(_DWORD *)(a1 + 144) )
  {
    result = *(unsigned int *)(a1 + 128);
    if ( (_DWORD)result )
    {
      v4 = gpio_to_desc(result);
      v5 = gpiod_set_raw_value(v4, 1);
      result = ktime_get(v5);
      *(_QWORD *)(a1 + 176) = result;
    }
    if ( !*(_DWORD *)(a1 + 124) )
    {
      v7 = *(_QWORD *)(a1 + 8);
      if ( !v7 )
        v7 = *(_QWORD *)(a1 + 16);
      result = dev_err(v7, "%s : ST54H is not supported\n", "st54spi_power_off");
    }
    *(_DWORD *)(a1 + 144) = 0;
  }
  else
  {
    v6 = *(_QWORD *)(a1 + 8);
    if ( !v6 )
      v6 = *(_QWORD *)(a1 + 16);
    return dev_info(v6, "%s - nothing to do\n", "st54spi_power_off");
  }
  return result;
}
