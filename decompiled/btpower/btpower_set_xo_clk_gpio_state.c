__int64 __fastcall btpower_set_xo_clk_gpio_state(__int64 result)
{
  unsigned int v1; // w19
  char v2; // w20
  int v3; // w0
  _BOOL4 v4; // w8
  int v5; // w0
  int v6; // w0
  int v7; // w0
  __int64 v8; // x0
  __int64 v9; // x0

  v1 = *(_DWORD *)(pwr_data + 40);
  if ( (v1 & 0x80000000) == 0 )
  {
    v2 = result;
    if ( !(unsigned int)gpio_request(v1, "bt_xo_clk_gpio") )
      goto LABEL_10;
    usleep_range_state(10000, 20000, 2);
    v3 = gpio_request(v1, "bt_xo_clk_gpio");
    v4 = v3 != 0;
    if ( v3 )
    {
      usleep_range_state(10000, 20000, 2);
      v5 = gpio_request(v1, "bt_xo_clk_gpio");
      v4 = v5 != 0;
      if ( v5 )
      {
        usleep_range_state(10000, 20000, 2);
        v6 = gpio_request(v1, "bt_xo_clk_gpio");
        v4 = v6 != 0;
        if ( v6 )
        {
          usleep_range_state(10000, 20000, 2);
          v7 = gpio_request(v1, "bt_xo_clk_gpio");
          v4 = v7 != 0;
          if ( v7 )
          {
            usleep_range_state(10000, 20000, 2);
            v4 = gpio_request(v1, "bt_xo_clk_gpio") != 0;
          }
        }
      }
    }
    if ( v4 )
    {
      return printk(&unk_127EA, "btpower_set_xo_clk_gpio_state");
    }
    else
    {
LABEL_10:
      if ( (v2 & 1) != 0 )
      {
        v8 = gpio_to_desc(v1);
        gpiod_direction_output_raw(v8, 1);
        usleep_range_state(100, 200, 2);
      }
      else
      {
        usleep_range_state(4000, 6000, 2);
        v9 = gpio_to_desc(v1);
        gpiod_direction_output_raw(v9, 0);
      }
      printk(&unk_130EA, "btpower_set_xo_clk_gpio_state");
      return gpio_free(v1);
    }
  }
  return result;
}
