__int64 __fastcall gf_parse_dts(__int64 a1)
{
  __int64 v1; // x22
  __int64 v3; // x21
  unsigned int v4; // w20
  unsigned __int64 v5; // x1
  unsigned int v6; // w0
  unsigned __int64 v7; // x0
  void *v8; // x0
  void *v9; // x0
  unsigned int v11; // w0
  int named_gpio; // w0
  unsigned int v13; // w0
  int v14; // w0
  __int64 v15; // x0

  v1 = *(_QWORD *)(a1 + 24);
  v3 = *(_QWORD *)(v1 + 760);
  v4 = zte_goodix_pinctrl_init((unsigned int *)a1);
  if ( !v4 && *(_QWORD *)(a1 + 120) )
  {
    printk(&unk_86FE);
    v5 = *(_QWORD *)(a1 + 136);
    if ( v5 && v5 < 0xFFFFFFFFFFFFF001LL )
    {
      v6 = pinctrl_select_state(*(_QWORD *)(a1 + 120), v5);
      if ( !v6
        || (v4 = v6,
            dev_err(*(_QWORD *)(a1 + 24) + 16LL, "can not set %s pins\n", "goodix_suspend"),
            (v4 & 0x80000000) == 0) )
      {
        printk(&unk_8715);
        usleep_range_state(10000, 10100, 2);
        v7 = devm_regulator_get(v1 + 16, &unk_8F90);
        *(_QWORD *)(a1 + 144) = v7;
        if ( v7 >= 0xFFFFFFFFFFFFF001LL )
        {
          printk(&unk_880F);
          v4 = *(_DWORD *)(a1 + 144);
          goto LABEL_13;
        }
        v11 = regulator_enable();
        if ( v11 )
        {
          v4 = v11;
          v8 = &unk_9343;
        }
        else
        {
          named_gpio = of_get_named_gpio(v3, "fp-gpio-reset", 0);
          *(_DWORD *)(a1 + 64) = named_gpio;
          if ( named_gpio < 0 )
          {
            printk(&unk_9741);
            v4 = -1;
          }
          else
          {
            printk(&unk_9006);
            v13 = devm_gpio_request(v1 + 16, *(unsigned int *)(a1 + 64), "goodix_reset");
            if ( v13 )
            {
              v4 = v13;
              printk(&unk_8F11);
            }
            else
            {
              printk(&unk_9006);
              v14 = of_get_named_gpio(v3, "fp-gpio-irq", 0);
              *(_DWORD *)(a1 + 60) = v14;
              if ( v14 < 0 )
              {
                printk(&unk_8C8E);
                v4 = -1;
              }
              else
              {
                printk(&unk_91B4);
                v4 = devm_gpio_request(v1 + 16, *(unsigned int *)(a1 + 60), "goodix_irq");
                if ( !v4 )
                {
                  v15 = gpio_to_desc(*(unsigned int *)(a1 + 60));
                  gpiod_direction_input(v15);
                  v9 = &unk_9027;
                  goto LABEL_14;
                }
                printk(&unk_9952);
              }
              printk(&unk_929B);
            }
          }
          v8 = &unk_950D;
        }
LABEL_12:
        printk(v8);
        goto LABEL_13;
      }
    }
    else
    {
      dev_err(*(_QWORD *)(a1 + 24) + 16LL, "not a valid '%s' pinstate\n", "goodix_suspend");
      v4 = -22;
    }
    v8 = &unk_87E1;
    goto LABEL_12;
  }
  printk(&unk_8F6B);
LABEL_13:
  v9 = &unk_88E4;
LABEL_14:
  printk(v9);
  return v4;
}
