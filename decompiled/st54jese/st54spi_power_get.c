__int64 __fastcall st54spi_power_get(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x0

  result = *(unsigned int *)(a1 + 128);
  if ( (_DWORD)result )
  {
    v2 = gpio_to_desc(result);
    return gpiod_get_raw_value(v2);
  }
  return result;
}
