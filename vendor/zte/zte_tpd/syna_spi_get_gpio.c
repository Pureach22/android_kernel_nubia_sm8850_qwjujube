__int64 __fastcall syna_spi_get_gpio(unsigned int a1, int a2, unsigned int a3, __int64 a4)
{
  unsigned int v8; // w0
  __int64 v9; // x2
  unsigned int v10; // w0
  __int64 v11; // x0
  void *v13; // x8
  unsigned int v14; // w19
  unsigned int v15; // w20

  v8 = scnprintf(a4, 16, "tcm_gpio_%d\n", a1);
  if ( (v8 & 0x80000000) != 0 )
  {
    v14 = v8;
    printk(unk_3B203, "syna_spi_get_gpio", v9);
    return v14;
  }
  v10 = gpio_request(a1, a4);
  if ( (v10 & 0x80000000) != 0 )
  {
    v13 = unk_3C5F2;
    goto LABEL_11;
  }
  v11 = gpio_to_desc(a1);
  if ( !a2 )
  {
    v10 = gpiod_direction_input(v11);
    if ( (v10 & 0x80000000) == 0 )
      return 0;
    goto LABEL_8;
  }
  v10 = gpiod_direction_output_raw(v11, a3);
  if ( (v10 & 0x80000000) != 0 )
  {
LABEL_8:
    v13 = unk_383AC;
LABEL_11:
    v15 = v10;
    printk(v13, "syna_spi_get_gpio", a1);
    return v15;
  }
  return 0;
}
