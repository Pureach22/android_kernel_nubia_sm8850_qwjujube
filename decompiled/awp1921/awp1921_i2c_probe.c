__int64 __fastcall awp1921_i2c_probe(_QWORD *a1)
{
  __int64 (*v2)(void); // x8
  unsigned int v3; // w20
  _QWORD *v4; // x0
  _QWORD *v5; // x19
  __int64 v6; // x21
  unsigned int named_gpio; // w0
  unsigned int v9; // w0
  __int64 v10; // x0
  __int64 v11; // x20
  __int64 v12; // x0
  unsigned int v13; // w0
  unsigned int v14; // w0
  __int64 v15; // x0
  __int64 v16; // x2
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x1
  __int64 v23; // x2
  __int64 v24; // x1
  __int64 v25; // x2
  __int64 v26; // x1
  __int64 v27; // x2
  int v28; // w20
  __int16 v29; // w8
  __int64 v30; // x0
  unsigned __int16 v31; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_8350, "awp1921_i2c_probe", mAWP1921);
  v2 = *(__int64 (**)(void))(*(_QWORD *)(a1[3] + 16LL) + 32LL);
  if ( *((_DWORD *)v2 - 1) != 2093148950 )
    __break(0x8228u);
  if ( (v2() & 1) == 0 )
  {
    printk(&unk_806E, "awp1921_i2c_probe", 636);
    v3 = -5;
    goto LABEL_17;
  }
  v4 = (_QWORD *)devm_kmalloc(a1 + 4, 2200, 3520);
  v5 = v4;
  mAWP1921 = (__int64)v4;
  if ( !v4 )
  {
    printk(&unk_83E5, "awp1921_i2c_probe", 643);
    v3 = -1;
    goto LABEL_13;
  }
  *v4 = a1;
  v4[1] = a1 + 4;
  v6 = a1[97];
  a1[23] = v4;
  named_gpio = of_get_named_gpio(v6, "irq-gpio", 0);
  *((_DWORD *)v5 + 6) = named_gpio;
  if ( (named_gpio & 0x80000000) != 0 )
  {
    printk(&unk_87C8, "awp1921_parse_dt", 581);
    v3 = -517;
    goto LABEL_11;
  }
  v3 = gpio_request(named_gpio, "awp1921_irq_gpio");
  printk(&unk_86AD, "awp1921_parse_dt", 586);
  if ( (v3 & 0x80000000) != 0 )
  {
    printk(&unk_829C, "awp1921_parse_dt", 588);
LABEL_11:
    *((_DWORD *)v5 + 6) = -22;
LABEL_12:
    printk(&unk_84C4, "awp1921_i2c_probe", 655);
    goto LABEL_13;
  }
  v9 = of_get_named_gpio(v6, "power-en", 0);
  *((_DWORD *)v5 + 5) = v9;
  if ( (v9 & 0x80000000) != 0 )
  {
    printk(&unk_80E8, "awp1921_parse_dt", 596);
    v3 = -517;
    *((_DWORD *)v5 + 5) = -22;
    goto LABEL_12;
  }
  v3 = gpio_request(v9, "awp1921_power_en");
  printk(&unk_8891, "awp1921_parse_dt", 601);
  if ( (v3 & 0x80000000) != 0 )
  {
    printk(&unk_8159, "awp1921_parse_dt", 603);
    *((_DWORD *)v5 + 5) = -22;
    goto LABEL_12;
  }
  printk(&unk_7F46, "awp1921_parse_dt", 607);
  v10 = gpio_to_desc(*((unsigned int *)v5 + 5));
  gpiod_direction_output_raw(v10, 1);
  v11 = v5[1];
  v12 = gpio_to_desc(*((unsigned int *)v5 + 6));
  v13 = gpiod_to_irq(v12);
  v14 = devm_request_threaded_irq(v11, v13, 0, awp1921_irq_handle, 8194, "awp1921", v5);
  if ( v14 )
  {
    v3 = v14;
    v17 = gpio_to_desc(*((unsigned int *)v5 + 6));
    gpiod_to_irq(v17);
    printk(&unk_8191, "awp1921_i2c_probe", 664);
  }
  else
  {
    v15 = proc_mkdir("driver/micropump", 0);
    micro_pump_proc_entry = v15;
    if ( v15 )
    {
      if ( !proc_create("icid", 436, v15, &proc_ops_icid) )
        printk(&unk_88DB, v18, v19);
      if ( !proc_create("enable", 436, micro_pump_proc_entry, &proc_ops_micropump) )
        printk(&unk_8599, v20, v21);
      if ( !proc_create("speed", 436, micro_pump_proc_entry, &proc_ops_speed) )
        printk(&unk_8412, v22, v23);
      if ( !proc_create("freq", 436, micro_pump_proc_entry, &proc_ops_freq) )
        printk(&unk_827B, v24, v25);
      if ( !proc_create("reg", 146, micro_pump_proc_entry, &proc_ops_reg) )
        printk(&unk_895A, v26, v27);
    }
    else
    {
      printk(&unk_8043, "create_pump_proc_entry", v16);
    }
    v31 = 0;
    printk(&unk_886D, "read_chipid", 196);
    if ( !(unsigned int)awp1921_i2c_read(v5, 30, &v31) )
    {
      v28 = v31;
      printk(&unk_82D3, "read_chipid", 201);
      if ( v28 == 20609 )
      {
        printk(&unk_8546, "read_chipid", 203);
        g_chip_id = 0x31323931707761LL;
        v29 = 20609;
      }
      else
      {
        printk(&unk_882D, "read_chipid", 208);
        v29 = -1;
      }
      *((_WORD *)v5 + 8) = v29;
      printk(&unk_8210, "awp1921_i2c_probe", 675);
      *((_DWORD *)v5 + 522) = 24;
      v5[262] = 0xFFFFFFFE00000LL;
      *((_WORD *)v5 + 1046) = 4;
      v5[263] = v5 + 263;
      v5[264] = v5 + 263;
      v5[265] = awp1921_check_handle;
      init_timer_key(v5 + 266, &delayed_work_timer_fn, 0x200000, 0, 0);
      enableMicroPump(v5, 0);
      printk(&unk_8249, "awp1921_i2c_probe", 683);
      v3 = 0;
      goto LABEL_17;
    }
    v3 = -1;
    printk(&unk_85BD, "read_chipid", 199);
    printk(&unk_8797, "awp1921_i2c_probe", 672);
    remove_proc_entry("icid", micro_pump_proc_entry);
    remove_proc_entry("enable", micro_pump_proc_entry);
    remove_proc_entry("speed", micro_pump_proc_entry);
    remove_proc_entry("freq", micro_pump_proc_entry);
    remove_proc_entry("reg", micro_pump_proc_entry);
    remove_proc_entry("driver/micropump", 0);
    v30 = gpio_to_desc(*((unsigned int *)v5 + 5));
    gpiod_direction_output_raw(v30, 0);
  }
LABEL_13:
  if ( (v5[3] & 0x80000000) == 0 )
  {
    gpio_free();
    *((_DWORD *)v5 + 6) = -22;
  }
  if ( (*((_DWORD *)v5 + 5) & 0x80000000) == 0 )
  {
    gpio_free();
    *((_DWORD *)v5 + 5) = -22;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v3;
}
