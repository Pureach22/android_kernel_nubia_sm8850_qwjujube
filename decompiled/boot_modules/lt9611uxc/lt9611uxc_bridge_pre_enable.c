__int64 __fastcall lt9611uxc_bridge_pre_enable(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0

  v2 = gpio_to_desc(*(unsigned int *)(a1 + 3120));
  gpiod_set_raw_value(v2, 1);
  msleep(20);
  v3 = gpio_to_desc(*(unsigned int *)(a1 + 3120));
  gpiod_set_raw_value(v3, 0);
  msleep(20);
  v4 = gpio_to_desc(*(unsigned int *)(a1 + 3120));
  gpiod_set_raw_value(v4, 1);
  return msleep(300);
}
