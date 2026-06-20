__int64 __fastcall rtc6226_enable_irq(unsigned int *a1)
{
  __int64 v2; // x0
  unsigned int v3; // w0
  __int64 v4; // x0
  unsigned int v5; // w20
  unsigned int v6; // w0
  __int64 result; // x0
  __int64 v8; // x1
  unsigned int v9; // w19
  unsigned int v10; // w20
  unsigned int v11; // w21

  v2 = gpio_to_desc(*a1);
  v3 = gpiod_direction_input(v2);
  if ( v3 )
  {
    v9 = v3;
    printk(&unk_D857, "rtc6226_enable_irq");
    return v9;
  }
  v4 = gpio_to_desc(*a1);
  v5 = gpiod_to_irq(v4);
  a1[464] = v5;
  if ( (v5 & 0x80000000) != 0 )
  {
    printk(&unk_D20B, "rtc6226_enable_irq");
    v10 = 0;
LABEL_10:
    rtc6226_disable_irq((__int64)a1);
    return v10;
  }
  v6 = request_any_context_irq(v5, rtc6226_isr, 2, "rtc6226-fmtuner", a1);
  if ( (v6 & 0x80000000) != 0 )
  {
    v10 = v6;
    printk(&unk_CEE0, "rtc6226_enable_irq");
    goto LABEL_10;
  }
  result = irq_set_irq_wake(v5, 1);
  if ( (result & 0x80000000) != 0 )
  {
    v11 = result;
    printk(&unk_D61F, v8);
    free_irq(v5, a1);
    return v11;
  }
  return result;
}
