__int64 __fastcall VI530X_Chip_PowerON(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  int v8; // w2
  __int64 result; // x0

  v2 = devm_pinctrl_get(*(_QWORD *)a1);
  v3 = pinctrl_lookup_state(v2, "irq_active");
  v4 = gpio_to_desc(*(unsigned int *)(a1 + 216));
  gpiod_direction_output_raw(v4, 0);
  v5 = gpio_to_desc(*(unsigned int *)(a1 + 212));
  gpiod_direction_output_raw(v5, 0);
  v6 = gpio_to_desc(*(unsigned int *)(a1 + 216));
  gpiod_direction_output_raw(v6, 1);
  _const_udelay((const char *)0x147AEB8);
  v7 = gpio_to_desc(*(unsigned int *)(a1 + 212));
  gpiod_direction_output_raw(v7, 1);
  _const_udelay((const char *)0x147AEB8);
  printk(&unk_41F7F2);
  v8 = pinctrl_select_state(v2, v3);
  result = 0;
  if ( v8 )
  {
    printk(&unk_3D7F45);
    return 4294967284LL;
  }
  return result;
}
