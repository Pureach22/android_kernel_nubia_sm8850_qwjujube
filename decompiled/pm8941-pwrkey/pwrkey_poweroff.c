__int64 __fastcall pwrkey_poweroff(__int64 a1)
{
  __int64 compatible_node; // x0
  __int64 v3; // x20
  __int64 next_available_child; // x0
  __int64 v5; // x0
  __int64 raw_value; // x0
  __int64 result; // x0
  int v8; // w2
  const char **v9; // x21

  if ( (vendor_volume_keys_pressed_key_gpio_initialized & 1) == 0 )
  {
    compatible_node = of_find_compatible_node(0, 0, "gpio-keys");
    if ( compatible_node )
    {
      v3 = compatible_node;
      next_available_child = of_get_next_available_child(compatible_node, 0);
      if ( next_available_child )
      {
        v9 = (const char **)next_available_child;
        do
        {
          if ( !strcmp(*v9, "vol_up") )
            *(_DWORD *)(a1 + 32) = of_get_named_gpio(v9, "gpios", 0);
          v9 = (const char **)of_get_next_available_child(v3, v9);
        }
        while ( v9 );
      }
    }
    else
    {
      dev_err(*(_QWORD *)(a1 - 144), "unable to find DT node: gpio-keys\n");
    }
    vendor_volume_keys_pressed_key_gpio_initialized = 1;
  }
  if ( (*(_DWORD *)(a1 + 32) & 0x80000000) != 0 )
  {
    raw_value = dev_err(*(_QWORD *)(a1 - 144), "%s: invalid gpio\n", "vendor_volume_keys_pressed");
  }
  else
  {
    v5 = gpio_to_desc();
    raw_value = gpiod_get_raw_value(v5);
    if ( !(_DWORD)raw_value )
    {
      dev_err(*(_QWORD *)(a1 - 144), "%s: power key long pressed, trigger s2 warm reset\n", "pwrkey_poweroff");
      result = dev_info(*(_QWORD *)(a1 - 144), "%s: modify pwrkey s2 warm reset\n", "vendor_mod_ponreg");
      v8 = *(_DWORD *)(a1 - 128);
      if ( v8 )
      {
        dev_err(*(_QWORD *)(a1 - 144), "use pon pbs address=0x%04X\n", v8);
        result = regmap_write(*(_QWORD *)(a1 - 120), (unsigned int)(*(_DWORD *)(a1 - 128) + 66), 1);
        if ( (_DWORD)result )
          return dev_err(*(_QWORD *)(a1 - 144), "pwrkey s2 register write failed, rc=%d\n", result);
      }
      return result;
    }
  }
  if ( (unsigned int)is_s2_warm_reset(raw_value) )
    panic("LONGPRESS");
  dev_err(*(_QWORD *)(a1 - 144), "%s: power key long pressed, trigger kernel reboot\n", "pwrkey_poweroff");
  return kernel_restart("LONGPRESS");
}
