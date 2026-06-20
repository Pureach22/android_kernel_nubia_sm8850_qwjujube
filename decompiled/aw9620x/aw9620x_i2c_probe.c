__int64 __fastcall aw9620x_i2c_probe(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 (*v5)(void); // x8
  _QWORD *v6; // x20
  unsigned int v7; // w21
  __int64 v8; // x0
  __int64 v9; // x19
  __int64 v10; // x21
  int variable_u32_array; // w0
  __int64 v12; // x1
  int named_gpio; // w0
  __int64 v14; // x1
  int v16; // w0
  __int64 v17; // x1
  __int64 property; // x0
  __int64 v19; // x1
  unsigned __int64 v20; // x0
  int v21; // w8
  unsigned __int64 v22; // x0
  unsigned __int64 v23; // x0
  unsigned __int64 v24; // x0
  unsigned __int64 v25; // x0
  unsigned __int64 v26; // x0
  unsigned __int64 v27; // x0
  __int64 v28; // x0
  unsigned int v29; // w0
  __int64 v30; // x1
  __int64 v31; // x6
  __int64 v32; // x1
  unsigned __int64 v33; // x0
  unsigned int v34; // w0
  int v35; // w0
  int voltage; // w23
  int v37; // w21
  int v38; // w21
  int v39; // w21
  int v40; // w21
  int v41; // w21
  int v42; // w21
  int v43; // w21
  int v44; // w21
  int v45; // w21
  const char *v46; // x8
  __int64 v47; // x0
  unsigned int v48; // w0
  unsigned int group; // w0
  int v50; // w0
  __int64 v51; // x1
  __int64 v52; // x8
  __int64 v53; // x22
  __int64 v54; // x21
  _QWORD *v55; // x8
  int chipid; // w0
  __int64 v57; // x1
  char v58; // w8
  int init_over_irq; // w0
  __int64 v60; // x1
  _BYTE v61[4]; // [xsp+Ch] [xbp-24h] BYREF
  char s[8]; // [xsp+10h] [xbp-20h] BYREF
  __int64 v63; // [xsp+18h] [xbp-18h]
  int v64; // [xsp+20h] [xbp-10h]
  __int64 v65; // [xsp+28h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61[0] = 0;
  printk(&unk_1470C, "aw9620x_i2c_probe", a3, a4);
  v5 = *(__int64 (**)(void))(*(_QWORD *)(a1[3] + 16LL) + 32LL);
  if ( *((_DWORD *)v5 - 1) != 2093148950 )
    __break(0x8228u);
  v6 = a1 + 4;
  if ( (v5() & 1) != 0 )
  {
    v8 = devm_kmalloc(a1 + 4, 832, 3520);
    if ( !v8 )
    {
      dev_printk(&unk_134C0, a1 + 4, "[%s:%d] failed to malloc memory!\n", "aw9620x_i2c_probe", 4289);
      v7 = -1;
      goto LABEL_12;
    }
    v9 = v8;
    *(_QWORD *)(v8 + 40) = a1;
    *(_QWORD *)(v8 + 48) = v6;
    a1[23] = v8;
    _mutex_init(&aw_lock, "&aw_lock", &aw9620x_i2c_probe___key);
    _mutex_init(&aw_update_lock, "&aw_update_lock", &aw9620x_i2c_probe___key_285);
    v10 = a1[97];
    variable_u32_array = of_property_read_variable_u32_array(v10, "sar-num", v9 + 8, 1, 0);
    v12 = *(_QWORD *)(v9 + 48);
    if ( variable_u32_array < 0 )
    {
      dev_printk(&unk_134C0, v12, "[%s:%d] multiple sar failed!\n", "aw9620x_parse_dt", 697);
      goto LABEL_11;
    }
    dev_printk(&unk_13D4F, v12, "[%s:%d] sar num = %d\n", "aw9620x_parse_dt", 700, *(_DWORD *)(v9 + 8));
    named_gpio = of_get_named_gpio(v10, "irq-gpio", 0);
    *(_DWORD *)(v9 + 12) = named_gpio;
    if ( named_gpio < 0 )
    {
      v14 = *(_QWORD *)(v9 + 48);
      *(_DWORD *)(v9 + 12) = -1;
      dev_printk(&unk_134C0, v14, "[%s:%d] no irq gpio provided.\n", "aw9620x_parse_dt", 705);
LABEL_11:
      v7 = -1;
      dev_printk(&unk_134C0, *(_QWORD *)(v9 + 48), "[%s:%d] irq gpio error!, ret = %d\n", "aw9620x_i2c_probe", 4303, -1);
      goto LABEL_12;
    }
    dev_printk(&unk_13D4F, *(_QWORD *)(v9 + 48), "[%s:%d] irq gpio provided ok.\n", "aw9620x_parse_dt", 708);
    v16 = of_property_read_variable_u32_array(v10, "channel_use_flag", v9 + 24, 1, 0);
    v17 = *(_QWORD *)(v9 + 48);
    if ( v16 < 0 )
    {
      dev_printk(&unk_134C0, v17, "[%s:%d] channel_use_flag failed!\n", "aw9620x_parse_dt", 712);
      goto LABEL_11;
    }
    dev_printk(&unk_13D4F, v17, "[%s:%d] channel_use_flag = 0x%x\n", "aw9620x_parse_dt", 715, *(_DWORD *)(v9 + 24));
    property = of_find_property(v10, "aw9620x,using-arr-laod-reg", 0);
    v19 = *(_QWORD *)(v9 + 48);
    *(_BYTE *)v9 = property != 0;
    dev_printk(&unk_13D4F, v19, "[%s:%d] firmware_flag = <%d>\n", "aw9620x_parse_dt", 718);
    dev_printk(
      &unk_142BB,
      *(_QWORD *)(v9 + 48),
      "[%s:%d] %s enter\n",
      "aw9620x_pinctrl_init",
      4200,
      "aw9620x_pinctrl_init");
    v20 = devm_pinctrl_get(*(_QWORD *)(v9 + 48));
    *(_QWORD *)(v9 + 800) = v20;
    if ( !v20 || v20 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_printk(
        &unk_134C0,
        *(_QWORD *)(v9 + 48),
        "[%s:%d] %s Target does not use pinctrl %d\n\n",
        "aw9620x_pinctrl_init",
        4205,
        "aw9620x_pinctrl_init",
        v20);
LABEL_43:
      *(_QWORD *)(v9 + 800) = 0;
      goto LABEL_44;
    }
    v21 = *(_DWORD *)(v9 + 8);
    if ( v21 == 1 )
    {
      v25 = pinctrl_lookup_state(v20, "aw_int_default_sar1");
      *(_QWORD *)(v9 + 824) = v25;
      if ( !v25 || v25 >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_printk(
          &unk_134C0,
          *(_QWORD *)(v9 + 48),
          "[%s:%d] %s Can not lookup aw_int_default_sar%d pinstate %d\n\n",
          "aw9620x_pinctrl_init",
          4239,
          "aw9620x_pinctrl_init",
          *(unsigned int *)(v9 + 8),
          v25);
        goto LABEL_42;
      }
      v26 = pinctrl_lookup_state(*(_QWORD *)(v9 + 800), "aw_int_active_sar1");
      *(_QWORD *)(v9 + 808) = v26;
      if ( !v26 || v26 >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_printk(
          &unk_134C0,
          *(_QWORD *)(v9 + 48),
          "[%s:%d] %s Can not lookup aw_int_active_sar%d pinstate %d\n\n",
          "aw9620x_pinctrl_init",
          4248,
          "aw9620x_pinctrl_init",
          *(unsigned int *)(v9 + 8),
          v26);
        goto LABEL_42;
      }
      v27 = pinctrl_lookup_state(*(_QWORD *)(v9 + 800), "aw_int_suspend_sar1");
      *(_QWORD *)(v9 + 816) = v27;
      if ( !v27 || v27 >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_printk(
          &unk_134C0,
          *(_QWORD *)(v9 + 48),
          "[%s:%d] %s Can not lookup aw_int_suspend_sar%d pinstate %d\n\n",
          "aw9620x_pinctrl_init",
          4256,
          "aw9620x_pinctrl_init",
          *(unsigned int *)(v9 + 8),
          v27);
        goto LABEL_42;
      }
    }
    else if ( !v21 )
    {
      v22 = pinctrl_lookup_state(v20, "aw_int_default_sar0");
      *(_QWORD *)(v9 + 824) = v22;
      if ( !v22 || v22 >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_printk(
          &unk_134C0,
          *(_QWORD *)(v9 + 48),
          "[%s:%d] %s Can not lookup aw_int_default_sar%d pinstate %d\n\n",
          "aw9620x_pinctrl_init",
          4213,
          "aw9620x_pinctrl_init",
          *(unsigned int *)(v9 + 8),
          v22);
        goto LABEL_42;
      }
      v23 = pinctrl_lookup_state(*(_QWORD *)(v9 + 800), "aw_int_active_sar0");
      *(_QWORD *)(v9 + 808) = v23;
      if ( !v23 || v23 >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_printk(
          &unk_134C0,
          *(_QWORD *)(v9 + 48),
          "[%s:%d] %s Can not lookup aw_int_active_sar%d pinstate %d\n\n",
          "aw9620x_pinctrl_init",
          4222,
          "aw9620x_pinctrl_init",
          *(unsigned int *)(v9 + 8),
          v23);
        goto LABEL_42;
      }
      v24 = pinctrl_lookup_state(*(_QWORD *)(v9 + 800), "aw_int_suspend_sar0");
      *(_QWORD *)(v9 + 816) = v24;
      if ( !v24 || v24 >= 0xFFFFFFFFFFFFF001LL )
      {
        dev_printk(
          &unk_134C0,
          *(_QWORD *)(v9 + 48),
          "[%s:%d] %s Can not lookup aw_int_suspend_sar%d pinstate %d\n\n",
          "aw9620x_pinctrl_init",
          4230,
          "aw9620x_pinctrl_init",
          *(unsigned int *)(v9 + 8),
          v24);
LABEL_42:
        devm_pinctrl_put(*(_QWORD *)(v9 + 800));
        goto LABEL_43;
      }
    }
    v28 = *(_QWORD *)(v9 + 800);
    if ( v28 )
    {
      v29 = pinctrl_select_state(v28, *(_QWORD *)(v9 + 808));
      v30 = *(_QWORD *)(v9 + 48);
      v31 = *(unsigned int *)(v9 + 8);
      if ( (v29 & 0x80000000) != 0 )
        dev_printk(
          &unk_134C0,
          v30,
          "[%s:%d] %s: Failed to select aw_int_active_sar%d pinstate %d\n\n",
          "aw9620x_i2c_probe",
          4313,
          "aw9620x_i2c_probe",
          v31,
          v29);
      else
        dev_printk(
          &unk_142BB,
          v30,
          "[%s:%d] %s: Successed to select aw_int_active_sar%d pinstate %d\n\n",
          "aw9620x_i2c_probe",
          4315,
          "aw9620x_i2c_probe",
          v31,
          v29);
    }
LABEL_44:
    v32 = *(_QWORD *)(v9 + 48);
    v64 = 0;
    *(_QWORD *)s = 0;
    v63 = 0;
    dev_printk(&unk_142BB, v32, "[%s:%d] aw9620x power init enter\n", "aw9620x_power_init", 729);
    snprintf(s, 0x14u, "vcc%u", *(_DWORD *)(v9 + 8));
    dev_printk(&unk_142BB, *(_QWORD *)(v9 + 48), "[%s:%d] vcc_name = %s\n", "aw9620x_power_init", 732, s);
    v33 = regulator_get(*(_QWORD *)(v9 + 48), s);
    v7 = v33;
    *(_QWORD *)(v9 + 504) = v33;
    if ( v33 <= 0xFFFFFFFFFFFFF000LL )
    {
      if ( (int)regulator_count_voltages(v33) >= 1 )
      {
        v34 = regulator_set_voltage(*(_QWORD *)(v9 + 504), 1700000, 3600000);
        if ( v34 )
        {
          v7 = v34;
          dev_printk(
            &unk_134C0,
            *(_QWORD *)(v9 + 48),
            "[%s:%d] regulator set vol failed rc = %d\n",
            "aw9620x_power_init",
            746,
            v34);
          regulator_put(*(_QWORD *)(v9 + 504));
          goto LABEL_75;
        }
      }
    }
    else
    {
      dev_printk(
        &unk_134C0,
        *(_QWORD *)(v9 + 48),
        "[%s:%d] regulator get failed vcc rc = %d\n",
        "aw9620x_power_init",
        737,
        v33);
      if ( v7 )
      {
LABEL_75:
        dev_printk(&unk_134C0, v6, "[%s:%d] aw9620x power init failed\n", "aw9620x_i2c_probe", 4323);
        if ( !*(_BYTE *)(v9 + 1) )
          goto LABEL_12;
        goto LABEL_101;
      }
    }
    dev_printk(&unk_142BB, *(_QWORD *)(v9 + 48), "[%s:%d] aw9620x power enable enter\n", "aw9620x_power_enable", 762);
    v35 = regulator_enable(*(_QWORD *)(v9 + 504));
    if ( v35 )
      dev_printk(
        &unk_134C0,
        *(_QWORD *)(v9 + 48),
        "[%s:%d] regulator_enable vol failed rc = %d\n",
        "aw9620x_power_enable",
        768,
        v35);
    else
      *(_BYTE *)(v9 + 1) = 1;
    dev_printk(&unk_142BB, *(_QWORD *)(v9 + 48), "[%s:%d] enter\n", "regulator_is_get_voltage", 787);
    voltage = regulator_get_voltage(*(_QWORD *)(v9 + 504));
    dev_printk(
      &unk_142BB,
      *(_QWORD *)(v9 + 48),
      "[%s:%d] aw9620x voltage is : %d uv\n",
      "regulator_is_get_voltage",
      791,
      voltage);
    if ( voltage <= 1599999 )
    {
      _const_udelay(4295000);
      v37 = regulator_get_voltage(*(_QWORD *)(v9 + 504));
      dev_printk(
        &unk_142BB,
        *(_QWORD *)(v9 + 48),
        "[%s:%d] aw9620x voltage is : %d uv\n",
        "regulator_is_get_voltage",
        791,
        v37);
      if ( v37 <= 1599999 )
      {
        _const_udelay(4295000);
        v38 = regulator_get_voltage(*(_QWORD *)(v9 + 504));
        dev_printk(
          &unk_142BB,
          *(_QWORD *)(v9 + 48),
          "[%s:%d] aw9620x voltage is : %d uv\n",
          "regulator_is_get_voltage",
          791,
          v38);
        if ( v38 <= 1599999 )
        {
          _const_udelay(4295000);
          v39 = regulator_get_voltage(*(_QWORD *)(v9 + 504));
          dev_printk(
            &unk_142BB,
            *(_QWORD *)(v9 + 48),
            "[%s:%d] aw9620x voltage is : %d uv\n",
            "regulator_is_get_voltage",
            791,
            v39);
          if ( v39 <= 1599999 )
          {
            _const_udelay(4295000);
            v40 = regulator_get_voltage(*(_QWORD *)(v9 + 504));
            dev_printk(
              &unk_142BB,
              *(_QWORD *)(v9 + 48),
              "[%s:%d] aw9620x voltage is : %d uv\n",
              "regulator_is_get_voltage",
              791,
              v40);
            if ( v40 <= 1599999 )
            {
              _const_udelay(4295000);
              v41 = regulator_get_voltage(*(_QWORD *)(v9 + 504));
              dev_printk(
                &unk_142BB,
                *(_QWORD *)(v9 + 48),
                "[%s:%d] aw9620x voltage is : %d uv\n",
                "regulator_is_get_voltage",
                791,
                v41);
              if ( v41 <= 1599999 )
              {
                _const_udelay(4295000);
                v42 = regulator_get_voltage(*(_QWORD *)(v9 + 504));
                dev_printk(
                  &unk_142BB,
                  *(_QWORD *)(v9 + 48),
                  "[%s:%d] aw9620x voltage is : %d uv\n",
                  "regulator_is_get_voltage",
                  791,
                  v42);
                if ( v42 <= 1599999 )
                {
                  _const_udelay(4295000);
                  v43 = regulator_get_voltage(*(_QWORD *)(v9 + 504));
                  dev_printk(
                    &unk_142BB,
                    *(_QWORD *)(v9 + 48),
                    "[%s:%d] aw9620x voltage is : %d uv\n",
                    "regulator_is_get_voltage",
                    791,
                    v43);
                  if ( v43 <= 1599999 )
                  {
                    _const_udelay(4295000);
                    v44 = regulator_get_voltage(*(_QWORD *)(v9 + 504));
                    dev_printk(
                      &unk_142BB,
                      *(_QWORD *)(v9 + 48),
                      "[%s:%d] aw9620x voltage is : %d uv\n",
                      "regulator_is_get_voltage",
                      791,
                      v44);
                    if ( v44 <= 1599999 )
                    {
                      _const_udelay(4295000);
                      v45 = regulator_get_voltage(*(_QWORD *)(v9 + 504));
                      dev_printk(
                        &unk_142BB,
                        *(_QWORD *)(v9 + 48),
                        "[%s:%d] aw9620x voltage is : %d uv\n",
                        "regulator_is_get_voltage",
                        791,
                        v45);
                      if ( v45 <= 1599999 )
                      {
                        _const_udelay(4295000);
                        dev_printk(
                          &unk_134C0,
                          *(_QWORD *)(v9 + 48),
                          "[%s:%d] get_voltage failed\n",
                          "aw9620x_i2c_probe",
                          4330);
                        v7 = -1;
                        if ( !*(_BYTE *)(v9 + 1) )
                          goto LABEL_12;
                        goto LABEL_101;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    msleep(25);
    if ( *(_DWORD *)(v9 + 8) )
      v46 = "sar1";
    else
      v46 = "sar0";
    *(_QWORD *)(v9 + 56) = v46;
    v47 = *(_QWORD *)(v9 + 48);
    *(_QWORD *)(v9 + 88) = aw9620x_set_brightness;
    v48 = devm_led_classdev_register_ext(v47);
    if ( (v48 & 0x80000000) != 0 )
    {
      v7 = v48;
      dev_err(*(_QWORD *)(v9 + 48), "unable to register led ret=%d\n", v48);
      goto LABEL_12;
    }
    group = sysfs_create_group(*(_QWORD *)(v9 + 136), &aw9620x_touch_attribute_group);
    if ( (group & 0x80000000) != 0 )
    {
      v7 = group;
      dev_printk(
        &unk_134C0,
        *(_QWORD *)(v9 + 48),
        "[%s:%d] error creating sysfs attr files\n",
        "aw9620x_i2c_probe",
        4356);
      goto LABEL_100;
    }
    if ( (unsigned int)aw9620x_input_init(v9, v61) )
    {
      dev_printk(&unk_134C0, *(_QWORD *)(v9 + 48), "[%s:%d] error inputs init\n", "aw9620x_i2c_probe", 4364);
      goto LABEL_80;
    }
    if ( (unsigned int)aw9620x_irq_init(v9) )
    {
      dev_printk(&unk_134C0, *(_QWORD *)(v9 + 48), "[%s:%d] error irq init\n", "aw9620x_i2c_probe", 4370);
      goto LABEL_80;
    }
    v50 = aw9620x_old_boot_nvr_modify(v9);
    v51 = *(_QWORD *)(v9 + 48);
    if ( v50 == -1 )
    {
      dev_printk(&unk_134C0, v51, "[%s:%d] i2c err!\n", "aw9620x_i2c_probe", 4382);
      goto LABEL_80;
    }
    if ( !v50 )
    {
      dev_printk(&unk_134C0, v51, "[%s:%d] old boot\n", "aw9620x_i2c_probe", 4377);
      *(_BYTE *)(v9 + 6) = 5;
      *(_DWORD *)(v9 + 32) = 1;
LABEL_109:
      aw9620x_update((_QWORD *)v9);
      v7 = 0;
      *(_BYTE *)(v9 + 672) = 2;
      goto LABEL_12;
    }
    dev_printk(&unk_134C0, v51, "[%s:%d] new boot\n", "aw9620x_i2c_probe", 4385);
    chipid = aw9620x_read_chipid(v9);
    v57 = *(_QWORD *)(v9 + 48);
    if ( chipid == -2 )
    {
      dev_printk(&unk_134C0, v57, "[%s:%d] read chipid failed, ret=%d, \n", "aw9620x_i2c_probe", 4394, -2);
      v58 = 2;
    }
    else
    {
      if ( chipid == -1 )
      {
        dev_printk(&unk_134C0, v57, "[%s:%d] read chipid failed, ret=%d, \n", "aw9620x_i2c_probe", 4391, 0xFFFFFFFFLL);
        goto LABEL_105;
      }
      dev_printk(&unk_134C0, v57, "[%s:%d] read chipid ok!\n", "aw9620x_i2c_probe", 4398);
      if ( (unsigned int)aw9620x_recover_fun(v9, 1) )
      {
        dev_printk(&unk_134C0, *(_QWORD *)(v9 + 48), "[%s:%d] recover_fun err\n", "aw9620x_i2c_probe", 4404);
        goto LABEL_80;
      }
      if ( (unsigned int)aw9620x_soft_reset(v9) )
      {
        dev_printk(
          &unk_134C0,
          *(_QWORD *)(v9 + 48),
          "[%s:%d] soft reset failed, ret=%d\n",
          "aw9620x_i2c_probe",
          4411,
          0xFFFFFFFFLL);
LABEL_105:
        v52 = v61[0];
        if ( !v61[0] )
          goto LABEL_83;
        goto LABEL_81;
      }
      init_over_irq = aw9620x_read_init_over_irq(v9);
      v60 = *(_QWORD *)(v9 + 48);
      if ( init_over_irq != -3 )
      {
        if ( init_over_irq != -1 )
        {
          dev_printk(&unk_134C0, v60, "[%s:%d] read_init_over_irq ok!\n", "aw9620x_i2c_probe", 4426);
          *(_BYTE *)(v9 + 6) = 0;
          goto LABEL_109;
        }
        dev_printk(&unk_134C0, v60, "[%s:%d] read chipid failed\n", "aw9620x_i2c_probe", 4418);
LABEL_80:
        v52 = v61[0];
        if ( !v61[0] )
        {
LABEL_83:
          v55 = *(_QWORD **)(v9 + 512);
          if ( v55[1] )
          {
            input_free_device();
            v55 = *(_QWORD **)(v9 + 512);
          }
          if ( v55[7] )
          {
            input_free_device();
            v55 = *(_QWORD **)(v9 + 512);
          }
          if ( v55[13] )
          {
            input_free_device();
            v55 = *(_QWORD **)(v9 + 512);
          }
          if ( v55[19] )
          {
            input_free_device();
            v55 = *(_QWORD **)(v9 + 512);
          }
          if ( v55[25] )
          {
            input_free_device();
            v55 = *(_QWORD **)(v9 + 512);
          }
          if ( v55[31] )
          {
            input_free_device();
            v55 = *(_QWORD **)(v9 + 512);
          }
          if ( v55[37] )
          {
            input_free_device();
            v55 = *(_QWORD **)(v9 + 512);
          }
          if ( v55[43] )
            input_free_device();
          v7 = -1;
LABEL_100:
          sysfs_remove_group(v6, &aw9620x_touch_attribute_group);
          if ( !*(_BYTE *)(v9 + 1) )
            goto LABEL_12;
LABEL_101:
          regulator_disable(*(_QWORD *)(v9 + 504));
          regulator_put(*(_QWORD *)(v9 + 504));
          goto LABEL_12;
        }
LABEL_81:
        v53 = 0;
        v54 = 48 * v52;
        do
        {
          input_unregister_device(*(_QWORD *)(*(_QWORD *)(v9 + 512) + v53 + 8));
          v53 += 48;
        }
        while ( v54 != v53 );
        goto LABEL_83;
      }
      dev_printk(&unk_134C0, v60, "[%s:%d] _read_init_over_irq, ret=%d, \n", "aw9620x_i2c_probe", 4421, -3);
      aw9620x_get_err_info(v9);
      v58 = 3;
    }
    *(_BYTE *)(v9 + 6) = v58;
    goto LABEL_109;
  }
  dev_printk(&unk_134C0, a1 + 4, "[%s:%d] check_functionality failed\n", "aw9620x_i2c_probe", 4283);
  v7 = -5;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v7;
}
