__int64 msm_cdc_get_gpio_state()
{
  __int64 gpiodata; // x0
  __int64 v1; // x0

  gpiodata = msm_cdc_pinctrl_get_gpiodata();
  if ( !gpiodata || (*(_DWORD *)(gpiodata + 32) & 0x80000000) != 0 )
    return 4294967274LL;
  v1 = gpio_to_desc();
  return gpiod_get_raw_value_cansleep(v1);
}
