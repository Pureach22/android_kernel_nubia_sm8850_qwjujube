__int64 __fastcall syna_spi_hw_reset(__int64 result)
{
  unsigned int v1; // w8
  int v2; // w20
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  _BOOL4 v7; // w19
  __int64 v8; // x0
  __int64 v9; // x2

  v1 = *(_DWORD *)(result + 240);
  if ( v1 )
  {
    v2 = *(_DWORD *)(result + 244);
    v3 = result;
    v4 = gpio_to_desc(v1);
    gpiod_set_raw_value(v4, v2 & 1);
    v5 = *(unsigned int *)(v3 + 252);
    v6 = v3;
    if ( (int)v5 >= 1 )
    {
      msleep(v5);
      v6 = v3;
    }
    v7 = *(_DWORD *)(v6 + 244) == 0;
    v8 = gpio_to_desc(*(unsigned int *)(v6 + 240));
    gpiod_set_raw_value(v8, v7);
    msleep(80);
    return printk(&unk_38DEF, "syna_spi_hw_reset", v9);
  }
  return result;
}
