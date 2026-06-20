__int64 __fastcall rtc6226_parse_dt(__int64 a1, unsigned int *a2)
{
  unsigned int named_gpio; // w0
  unsigned int v4; // w0
  __int64 v5; // x0
  unsigned int v7; // w20
  void *v8; // x8

  named_gpio = of_get_named_gpio(*(_QWORD *)(a1 + 744), "fmint-gpio", 0);
  *a2 = named_gpio;
  if ( (named_gpio & 0x80000000) != 0 )
  {
    printk(&unk_D58F, "rtc6226_parse_dt");
    v7 = *a2;
LABEL_10:
    gpio_free(*a2);
    return v7;
  }
  v4 = gpio_request();
  if ( v4 )
  {
    v8 = &unk_DA36;
LABEL_9:
    v7 = v4;
    printk(v8, "rtc6226_parse_dt");
    goto LABEL_10;
  }
  v5 = gpio_to_desc(*a2);
  v4 = gpiod_direction_output_raw(v5, 0);
  if ( v4 )
  {
    v8 = &unk_D857;
    goto LABEL_9;
  }
  msleep(100);
  return 0;
}
