__int64 __fastcall vendor_print_gpio_buffer(__int64 a1)
{
  const char *v1; // x1
  __int64 v2; // x2

  if ( gpio_sleep_status_info && *(_BYTE *)gpio_sleep_status_info )
  {
    seq_printf(a1, (const char *)gpio_sleep_status_info);
  }
  else
  {
    if ( gpio_debug_mask )
    {
      v1 = "Not suspended yet!\n";
      v2 = 19;
    }
    else
    {
      v1 = " please echo 1 > /sys/module/pinctrl_msm/parameters/gpio_debug_mask \n";
      v2 = 69;
    }
    seq_write(a1, v1, v2);
  }
  return 0;
}
