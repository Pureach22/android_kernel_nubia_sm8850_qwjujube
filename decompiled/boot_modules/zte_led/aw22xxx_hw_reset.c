__int64 __fastcall aw22xxx_hw_reset(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0

  printk(&unk_130E1, "aw22xxx_hw_reset");
  if ( !a1 )
    return dev_err(*(_QWORD *)(a1 + 8), "%s:  failed\n", "aw22xxx_hw_reset");
  v2 = *(unsigned int *)(a1 + 736);
  if ( (v2 & 0x80000000) != 0 )
    return dev_err(*(_QWORD *)(a1 + 8), "%s:  failed\n", "aw22xxx_hw_reset");
  v3 = gpio_to_desc(v2);
  gpiod_set_raw_value_cansleep(v3, 0);
  usleep_range_state(1000, 1500, 2);
  v4 = gpio_to_desc(*(unsigned int *)(a1 + 736));
  gpiod_set_raw_value_cansleep(v4, 1);
  return usleep_range_state(1000, 1500, 2);
}
