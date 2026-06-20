__int64 __fastcall VI530X_Chip_PowerOFF(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x0
  int v5; // w1
  int v6; // w2
  __int64 v7; // x0
  int v8; // w2
  __int64 result; // x0

  v2 = devm_pinctrl_get(*(_QWORD *)a1);
  v3 = pinctrl_lookup_state(v2, "irq_suspend");
  v4 = gpio_to_desc(*(unsigned int *)(a1 + 212));
  gpiod_direction_output_raw(v4, 0);
  _const_udelay("d: %u rc: %d", v5, v6);
  v7 = gpio_to_desc(*(unsigned int *)(a1 + 216));
  gpiod_direction_output_raw(v7, 0);
  printk(&unk_40FC1F);
  v8 = pinctrl_select_state(v2, v3);
  result = 0;
  if ( v8 )
  {
    printk(&unk_403D6B);
    return 4294967283LL;
  }
  return result;
}
