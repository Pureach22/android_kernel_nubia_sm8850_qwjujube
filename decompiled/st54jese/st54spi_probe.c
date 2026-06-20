__int64 __fastcall st54spi_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  void *v4; // x21
  __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned int v7; // w22
  int v8; // w23
  void *v9; // x2
  __int64 v10; // x9
  __int64 compatible_node; // x0
  __int64 v12; // x21
  int named_gpio; // w3
  int v14; // w3
  const char *property; // x0
  int v16; // w21
  const char *v17; // x21
  int v18; // w3
  __int64 v19; // x0
  int v20; // w0
  __int64 v21; // x0
  __int64 v22; // x0
  int v23; // w0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  unsigned __int64 v34; // x9

  printk(&unk_8C5C, "st54spi_probe");
  v2 = _kmalloc_cache_noprof(strcmp, 3520, 200);
  v3 = v2;
  if ( !v2 )
    return (unsigned int)-12;
  *(_QWORD *)(v2 + 8) = a1;
  *(_DWORD *)(v2 + 4) = 0;
  _mutex_init(v2 + 40, "&st54spi->buf_lock", &st54spi_probe___key);
  v4 = (void *)(v3 + 24);
  *(_QWORD *)(v3 + 24) = v3 + 24;
  *(_QWORD *)(v3 + 32) = v3 + 24;
  mutex_lock(&device_list_lock);
  if ( (minors & 1) != 0 )
  {
    v8 = 0;
    v7 = -19;
  }
  else
  {
    v5 = st54spi_class;
    *(_DWORD *)v3 = spidev_major << 20;
    v6 = device_create(v5, a1);
    if ( v6 < 0xFFFFFFFFFFFFF001LL )
    {
      _X8 = &minors;
      __asm { PRFM            #0x11, [X8] }
      do
        v34 = __ldxr((unsigned __int64 *)&minors);
      while ( __stxr(v34 | 1, (unsigned __int64 *)&minors) );
      v9 = device_list;
      if ( device_list == v4 || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)device_list) != &device_list )
      {
        _list_add_valid_or_report(v3 + 24, &device_list);
        v7 = 0;
        v8 = 1;
      }
      else
      {
        v7 = 0;
        v8 = 1;
        *(_QWORD *)((char *)&unk_8 + (_QWORD)device_list) = v4;
        *(_QWORD *)(v3 + 24) = v9;
        *(_QWORD *)(v3 + 32) = &device_list;
        device_list = (_UNKNOWN *)(v3 + 24);
      }
    }
    else
    {
      v7 = v6;
      v8 = 0;
    }
  }
  mutex_unlock(&device_list_lock);
  v10 = *(_QWORD *)(v3 + 8);
  *(_DWORD *)(v3 + 120) = *(_DWORD *)(a1 + 920);
  *(_BYTE *)(v10 + 1142) = 0;
  *(_WORD *)(*(_QWORD *)(v3 + 8) + 1140LL) = 20;
  if ( !v8 )
  {
    kfree(v3);
    return v7;
  }
  *(_QWORD *)(a1 + 152) = v3;
  compatible_node = of_find_compatible_node(0, 0, "st,st54spi");
  if ( compatible_node )
  {
    v12 = compatible_node;
    named_gpio = of_get_named_gpio(compatible_node, "gpio-chip_en-std", 0);
    if ( named_gpio < 0 )
      dev_info(a1, "%s: ST54 chip_en not used (%d)", "../soc-repo/drivers/nfc/st54j/st54spi.c", named_gpio);
    else
      *(_DWORD *)(v3 + 132) = named_gpio;
    v14 = of_get_named_gpio(v12, "gpio-power_nreset-std", 0);
    if ( v14 < 0 )
      dev_info(a1, "%s: get ST54 failed (%d)", "../soc-repo/drivers/nfc/st54j/st54spi.c", v14);
    else
      *(_DWORD *)(v3 + 128) = v14;
    property = (const char *)of_get_property(v12, "power_mode", 0);
    if ( property )
    {
      v17 = property;
      if ( !strcmp(property, "ST54J") || !strcmp(v17, "ST54L") )
      {
        v16 = 1;
        dev_info(a1, "%s: Power mode: ST54J (and newer)\n", "../soc-repo/drivers/nfc/st54j/st54spi.c");
      }
      else
      {
        if ( !strcmp(v17, "ST54H") )
        {
          dev_err(a1, "%s : ST54H is not supported\n", "st54spi_parse_dt");
          goto LABEL_27;
        }
        if ( strcmp(v17, "none") )
        {
          dev_err(a1, "%s: Power mode unknown: %s\n", "../soc-repo/drivers/nfc/st54j/st54spi.c", v17);
          goto LABEL_27;
        }
        v16 = -1;
        dev_info(a1, "%s: Power mode: none\n", "../soc-repo/drivers/nfc/st54j/st54spi.c");
      }
    }
    else
    {
      v16 = 1;
      dev_info(a1, "%s: Default power mode: ST54J (and newer)\n", "../soc-repo/drivers/nfc/st54j/st54spi.c");
    }
    v18 = *(_DWORD *)(v3 + 128);
    *(_DWORD *)(v3 + 124) = v16;
    dev_info(a1, "[dsc]%s : get power_or_nreset_gpio[%d]\n", "st54spi_parse_dt", v18);
  }
  else
  {
    dev_info(a1, "%s : get num err.\n", "st54spi_parse_dt");
  }
LABEL_27:
  v19 = *(unsigned int *)(v3 + 132);
  if ( (_DWORD)v19 )
  {
    v20 = gpio_request(v19, "gpio-chip_en-std");
    if ( v20 )
      dev_info(a1, "%s : chip_en request failed (%d)\n", "../soc-repo/drivers/nfc/st54j/st54spi.c", v20);
    dev_info(a1, "%s : chip_en GPIO = %d\n", "st54spi_probe", *(_DWORD *)(v3 + 132));
    v21 = gpio_to_desc(*(unsigned int *)(v3 + 132));
    if ( (unsigned int)gpiod_direction_input(v21) )
      dev_info(a1, "%s : chip_en direction_input failed\n", "../soc-repo/drivers/nfc/st54j/st54spi.c");
  }
  v22 = *(unsigned int *)(v3 + 128);
  if ( (_DWORD)v22 )
  {
    v23 = gpio_request(v22, "gpio-power_nreset-std");
    if ( v23 )
      dev_info(a1, "%s : power request failed (%d)\n", "../soc-repo/drivers/nfc/st54j/st54spi.c", v23);
    dev_info(a1, "%s : power/nreset GPIO = %d\n", "st54spi_probe", *(_DWORD *)(v3 + 128));
    v24 = gpio_to_desc(*(unsigned int *)(v3 + 128));
    if ( (unsigned int)gpiod_direction_output_raw(v24, 0) )
      dev_info(a1, "%s : reset direction_output failed\n", "../soc-repo/drivers/nfc/st54j/st54spi.c");
    v25 = gpio_to_desc(*(unsigned int *)(v3 + 128));
    v26 = gpiod_set_raw_value(v25, 0);
    *(_QWORD *)(v3 + 176) = ktime_get(v26);
  }
  if ( !*(_DWORD *)(v3 + 124) )
    dev_err(a1, "%s : st54spi as module cannot use ST54H fully\n", "st54spi_probe");
  printk(&unk_8C2E, "st54spi_probe");
  return 0;
}
