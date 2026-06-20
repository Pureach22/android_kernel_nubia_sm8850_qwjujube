__int64 __fastcall nb_fan_gpio_proc(_QWORD *a1)
{
  __int64 v3; // x19
  unsigned int v4; // w0
  __int64 v5; // x0
  unsigned int v6; // w0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  unsigned int v10; // w19
  __int64 v11; // x0
  __int64 v12; // x0

  if ( !a1[1] )
    return 4294967277LL;
  v3 = *(_QWORD *)(*a1 + 744LL);
  *(_DWORD *)(a1[1] + 20LL) = of_get_named_gpio(v3, "fan,speed-gpio", 0);
  if ( (*(_DWORD *)(a1[1] + 20LL) & 0x80000000) != 0 )
  {
    printk(&unk_79E9, "NB_FAN", "nb_fan_gpio_proc", 835);
    return *(unsigned int *)(a1[1] + 20LL);
  }
  v4 = gpio_request();
  if ( v4 )
  {
    v10 = v4;
    printk(&unk_82A9, "NB_FAN", "nb_fan_gpio_proc", 840);
    return v10;
  }
  v5 = gpio_to_desc(*(unsigned int *)(a1[1] + 20LL));
  *(_DWORD *)(a1[1] + 28LL) = gpiod_to_irq(v5);
  v6 = request_threaded_irq(*(unsigned int *)(a1[1] + 28LL), fan_speed_irq_proc, 0, 2097154, "fan_speed_int", a1);
  if ( (v6 & 0x80000000) != 0 )
  {
    v10 = v6;
    printk(&unk_7FED, v7, v8, v9);
    return v10;
  }
  disable_irq(*(unsigned int *)(a1[1] + 28LL));
  *(_DWORD *)(a1[1] + 16LL) = of_get_named_gpio(v3, "fan,pwm-gpio", 0);
  v11 = *(unsigned int *)(a1[1] + 16LL);
  if ( (v11 & 0x80000000) != 0 )
  {
    printk(&unk_80FE, "NB_FAN", "nb_fan_gpio_proc", 853);
    return *(unsigned int *)(a1[1] + 16LL);
  }
  else
  {
    v12 = gpio_to_desc(v11);
    gpiod_get_raw_value(v12);
    printk(&unk_832B, "NB_FAN", "nb_fan_gpio_proc", 856);
    return 0;
  }
}
