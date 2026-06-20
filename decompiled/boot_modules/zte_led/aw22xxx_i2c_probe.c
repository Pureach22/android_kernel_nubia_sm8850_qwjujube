__int64 __fastcall aw22xxx_i2c_probe(_QWORD *a1)
{
  __int64 v2; // x22
  _QWORD *v3; // x20
  __int64 (*v4)(void); // x8
  _QWORD *v5; // x0
  _QWORD *v6; // x19
  unsigned __int64 v7; // x8
  void *v8; // x0
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x8
  unsigned int v11; // w0
  unsigned int v12; // w23
  int v14; // w3
  __int64 named_gpio; // x0
  __int64 v16; // x0
  int v17; // w0
  int v18; // w0
  __int64 v19; // x1
  unsigned int v20; // w0
  __int64 v21; // x1
  unsigned int v22; // w0
  __int64 v23; // x0
  int v24; // w9
  const char *v25; // x1
  unsigned int chipid; // w0
  __int64 (__fastcall *v27)(); // x23
  __int64 v28; // x0
  unsigned int v29; // w0
  unsigned int v30; // w0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  int v34; // w0

  v2 = a1[97];
  v3 = a1 + 4;
  printk(&unk_136BF, "aw22xxx_i2c_probe");
  v4 = *(__int64 (**)(void))(*(_QWORD *)(a1[3] + 16LL) + 32LL);
  if ( *((_DWORD *)v4 - 1) != 2093148950 )
    __break(0x8228u);
  if ( (v4() & 1) == 0 )
  {
    dev_err(v3, "check_functionality failed\n");
    return (unsigned int)-5;
  }
  v5 = (_QWORD *)devm_kmalloc(v3, 848, 3520);
  if ( !v5 )
    return (unsigned int)-12;
  v6 = v5;
  *v5 = a1;
  v5[1] = v3;
  a1[23] = v5;
  _mutex_init(v5 + 86, "&aw22xxx->cfg_lock", &aw22xxx_i2c_probe___key);
  *((_BYTE *)v6 + 772) = 1;
  v7 = devm_pinctrl_get(v3);
  v8 = &unk_13796;
  v6[102] = v7;
  if ( !v7
    || v7 > 0xFFFFFFFFFFFFF000LL
    || (v9 = pinctrl_lookup_state(v7, "aw22xxx_led_default"), v8 = &unk_134B2, (v6[103] = v9) == 0)
    || v9 > 0xFFFFFFFFFFFFF000LL
    || (v10 = pinctrl_lookup_state(v6[102], "aw22xxx_led_sleep"), v8 = &unk_130A7, (v6[104] = v10) == 0)
    || v10 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(v8, "aw22xxx_pinctrl_init");
    printk(&unk_12844, "aw22xxx_i2c_probe");
    v12 = -22;
LABEL_23:
    v6[102] = 0;
    goto LABEL_24;
  }
  if ( !v6[102] || !v6[103] )
  {
    printk(&unk_13947, "aw22xxx_pinctrl_set_state");
    v12 = -22;
LABEL_21:
    printk(&unk_12F5C, "aw22xxx_i2c_probe");
LABEL_22:
    devm_pinctrl_put(v6[102]);
    goto LABEL_23;
  }
  v11 = pinctrl_select_state();
  if ( v11 )
  {
    v12 = v11;
    goto LABEL_21;
  }
  if ( !v2 )
  {
    v12 = 0;
    v6[92] = -1;
LABEL_24:
    devm_kfree(v3, v6);
    return v12;
  }
  if ( (of_property_read_variable_u32_array(v2, "aw_drv_ver", &g_ver_var, 1, 0) & 0x80000000) != 0 )
  {
    v14 = 11;
    g_ver_var = 11;
  }
  else
  {
    v14 = g_ver_var;
  }
  dev_info(v3, "%s: aw drv ver=%d\n", "aw22xxx_parse_dt", v14);
  named_gpio = of_get_named_gpio(v2, "reset-gpio", 0);
  *((_DWORD *)v6 + 184) = named_gpio;
  if ( (named_gpio & 0x80000000) != 0 )
  {
    dev_err(v3, "%s: no reset gpio provided, will not HW reset device\n", "aw22xxx_parse_dt");
LABEL_35:
    dev_err(v3, "%s: failed to parse device tree node\n", "aw22xxx_i2c_probe");
    v12 = -22;
    goto LABEL_24;
  }
  v16 = gpio_to_desc(named_gpio);
  if ( !(unsigned int)gpiod_direction_output_raw(v16, 1) )
    dev_info(v3, "%s: not enable gpio, aw22xxx->reset_gpio=%d\n", "aw22xxx_parse_dt", *((_DWORD *)v6 + 184));
  dev_info(v3, "%s: reset gpio provided ok, aw22xxx->reset_gpio=%d\n", "aw22xxx_parse_dt", *((_DWORD *)v6 + 184));
  v17 = of_get_named_gpio(v2, "irq-gpio", 0);
  *((_DWORD *)v6 + 185) = v17;
  if ( v17 < 0 )
  {
    dev_err(v3, "%s: no irq gpio provided, will not suppport intterrupt\n", "aw22xxx_parse_dt");
    goto LABEL_35;
  }
  dev_info(v3, "%s: irq gpio provided ok, aw22xxx->irq_gpio=%d\n", "aw22xxx_parse_dt", v17);
  v18 = of_get_named_gpio(v2, "nubia_ver-gpio", 0);
  *((_DWORD *)v6 + 186) = v18;
  if ( v18 < 0 )
    dev_info(v3, "%s: not suppport nubia_ver_gpio, regard as normal version\n", "aw22xxx_parse_dt");
  else
    dev_info(v3, "%s: nubia_ver_gpio provided ok, aw22xxx->nubia_ver_gpio=%d\n", "aw22xxx_parse_dt", v18);
  if ( (of_property_read_variable_u32_array(v2, "cfg_custom_en", &g_custom_en, 1, 0) & 0x80000000) != 0 )
    g_custom_en = 0;
  v19 = *((unsigned int *)v6 + 184);
  if ( (v19 & 0x80000000) == 0 )
  {
    v20 = devm_gpio_request_one(v3, v19, 0, "aw22xxx_rst");
    if ( v20 )
    {
      v12 = v20;
      v25 = "%s: rst request failed\n";
LABEL_52:
      dev_err(v3, v25);
      goto LABEL_24;
    }
  }
  v21 = *((unsigned int *)v6 + 185);
  if ( (v21 & 0x80000000) == 0 )
  {
    v22 = devm_gpio_request_one(v3, v21, 1, "aw22xxx_int");
    if ( v22 )
    {
      v12 = v22;
      v25 = "%s: int request failed\n";
      goto LABEL_52;
    }
  }
  aw22xxx_hw_reset(v6);
  printk(&unk_14056, "aw22xxx_i2c_probe");
  if ( (unsigned int)(multicolor_led - 1) < 2 )
  {
    v23 = gpio_to_desc(*((unsigned int *)v6 + 184));
    gpiod_set_raw_value_cansleep(v23, 0);
    devm_gpio_request_one(v3, *((unsigned int *)v6 + 185), 0, "aw22xxx_int");
    v12 = 0;
    multicolor_led = 0;
    if ( g_custom_en )
      v24 = 11;
    else
      v24 = 4500;
    g_cfgarray_count = v24;
    return v12;
  }
  chipid = aw22xxx_read_chipid(v6);
  if ( (chipid & 0x80000000) != 0 )
  {
    v12 = chipid;
    dev_err(v3, "%s: aw22xxx_read_chipid failed ret=%d\n", "aw22xxx_i2c_probe", chipid);
    goto LABEL_22;
  }
  if ( (*((_DWORD *)v6 + 185) & 0x80000000) != 0 || (*((_BYTE *)v6 + 748) & 1) != 0 )
  {
    *((_BYTE *)v6 + 748) |= 1u;
  }
  else
  {
    aw22xxx_interrupt_setup(v6);
    if ( (unsigned int)g_ver_var < 0xC )
    {
      v27 = aw22xxx_irq;
    }
    else
    {
      printk(&unk_128F4, (unsigned int)g_ver_var);
      v27 = aw22xxx_irq_v15;
    }
    v28 = gpio_to_desc(*((unsigned int *)v6 + 185));
    v29 = gpiod_to_irq(v28);
    v30 = devm_request_threaded_irq(v3, v29, 0, v27, 8194, "aw22xxx", v6);
    if ( v30 )
    {
      v12 = v30;
      v33 = gpio_to_desc(*((unsigned int *)v6 + 185));
      v34 = gpiod_to_irq(v33);
      dev_err(v3, "%s: failed to request IRQ %d: %d\n", "aw22xxx_i2c_probe", v34, v12);
      goto LABEL_22;
    }
  }
  a1[23] = v6;
  v31 = aw22xxx_parse_led_cdev(v6, v2);
  aw22xxx_alloc_name_array(v31);
  byte_127EF = 0;
  qword_127E7 = 0;
  qword_127DF = 0;
  qword_127D7 = 0;
  qword_127CF = 0;
  qword_127C7 = 0;
  qword_127BF = 0;
  strcpy((char *)&aw22xxx_fw_name, "aw22xxx_fw.bin");
  printk(&unk_12DF9, "aw22xxx_load_nubia_fw_name");
  aw22xxx_fw_init(v6);
  printk(&unk_14085, "aw22xxx_i2c_probe");
  v32 = gpio_to_desc(*((unsigned int *)v6 + 184));
  if ( (unsigned int)gpiod_direction_output_raw(v32, 0) )
    printk(&unk_12CDF, "aw22xxx_i2c_probe");
  aw22xxx_create_proc_entry();
  return 0;
}
