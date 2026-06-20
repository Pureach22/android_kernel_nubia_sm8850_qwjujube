__int64 __fastcall cnss_set_xo_clk_gpio_state(__int64 result, char a2)
{
  unsigned int v2; // w19
  int v4; // w0
  __int64 v5; // x6
  __int64 v6; // x7
  _BOOL4 v7; // w8
  int v8; // w0
  int v9; // w0
  int v10; // w0
  unsigned __int64 StatusReg; // x8
  const char *v12; // x1
  __int64 v13; // x0
  __int64 v14; // x0
  __int16 v15; // w9
  const char *v16; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v2 = *(_DWORD *)(result + 120);
  if ( (v2 & 0x80000000) == 0 && *(_QWORD *)(result + 528) == 4355 )
  {
    if ( !(unsigned int)gpio_request(v2, "XO_CLK_GPIO") )
      goto LABEL_12;
    usleep_range_state(10000, 20000, 2);
    v4 = gpio_request(v2, "XO_CLK_GPIO");
    v7 = v4 != 0;
    if ( v4 )
    {
      usleep_range_state(10000, 20000, 2);
      v8 = gpio_request(v2, "XO_CLK_GPIO");
      v7 = v8 != 0;
      if ( v8 )
      {
        usleep_range_state(10000, 20000, 2);
        v9 = gpio_request(v2, "XO_CLK_GPIO");
        v7 = v9 != 0;
        if ( v9 )
        {
          usleep_range_state(10000, 20000, 2);
          v10 = gpio_request(v2, "XO_CLK_GPIO");
          v7 = v10 != 0;
          if ( v10 )
          {
            usleep_range_state(10000, 20000, 2);
            v7 = gpio_request(v2, "XO_CLK_GPIO") != 0;
          }
        }
      }
    }
    if ( v7 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v12 = "irq";
      }
      else
      {
        v15 = *(_DWORD *)(StatusReg + 16);
        v16 = (const char *)(StatusReg + 2320);
        if ( (v15 & 0xFF00) != 0 )
          v12 = "soft_irq";
        else
          v12 = v16;
      }
      return cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v12,
               "cnss_set_xo_clk_gpio_state",
               3u,
               3u,
               "QCA6490 XO CLK Gpio request failed\n",
               v5,
               v6,
               vars0);
    }
    else
    {
LABEL_12:
      if ( (a2 & 1) != 0 )
      {
        v13 = gpio_to_desc(v2);
        gpiod_direction_output_raw(v13, 1);
        usleep_range_state(100, 200, 2);
      }
      else
      {
        usleep_range_state(2000, 5000, 2);
        v14 = gpio_to_desc(v2);
        gpiod_direction_output_raw(v14, 0);
      }
      return gpio_free(v2);
    }
  }
  return result;
}
