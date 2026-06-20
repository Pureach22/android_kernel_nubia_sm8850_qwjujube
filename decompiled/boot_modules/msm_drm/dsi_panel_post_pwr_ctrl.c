__int64 __fastcall dsi_panel_post_pwr_ctrl(const char **a1, char a2)
{
  __int64 v4; // x21
  __int64 v5; // x0
  __int64 raw_value; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x0
  __int64 v11; // x0

  if ( (*((_DWORD *)a1 + 401) & 0x80000000) == 0 )
  {
    v4 = ktime_get(a1) + 150000000;
    v5 = gpio_to_desc(*((unsigned int *)a1 + 401));
    raw_value = gpiod_get_raw_value(v5);
    if ( (a2 & 1) != 0 )
    {
      for ( ; (_DWORD)raw_value != 1; raw_value = gpiod_get_raw_value(v7) )
      {
        if ( ktime_get(raw_value) > v4 )
          break;
        usleep_range_state(1251, 5000, 2);
        __yield();
        v7 = gpio_to_desc(*((unsigned int *)a1 + 401));
      }
      v8 = gpio_to_desc(*((unsigned int *)a1 + 401));
      if ( (unsigned int)gpiod_get_raw_value(v8) != 1 )
      {
LABEL_7:
        printk(&unk_21F4B9, *a1);
        return 4294967186LL;
      }
    }
    else
    {
      for ( ; (_DWORD)raw_value; raw_value = gpiod_get_raw_value(v10) )
      {
        if ( ktime_get(raw_value) > v4 )
          break;
        usleep_range_state(1251, 5000, 2);
        __yield();
        v10 = gpio_to_desc(*((unsigned int *)a1 + 401));
      }
      v11 = gpio_to_desc(*((unsigned int *)a1 + 401));
      if ( (unsigned int)gpiod_get_raw_value(v11) )
        goto LABEL_7;
    }
  }
  result = dsi_pwr_enable_regulator((_DWORD *)a1 + 364, a2 & 1);
  if ( (_DWORD)result )
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] failed to set post power vregs status, enable=%d rc=%d\n",
      *a1,
      a2 & 1,
      result);
    return 0;
  }
  return result;
}
