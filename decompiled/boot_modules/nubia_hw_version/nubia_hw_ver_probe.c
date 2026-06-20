__int64 __fastcall nubia_hw_ver_probe(__int64 a1)
{
  __int64 v1; // x22
  unsigned int named_gpio; // w0
  unsigned int v4; // w20
  int v5; // w0
  unsigned int v6; // w0
  unsigned int v7; // w23
  int v8; // w0
  int v9; // w0
  unsigned int v10; // w0
  unsigned int v11; // w21
  unsigned int v12; // w0
  unsigned int v13; // w22
  int v14; // w0
  int v15; // w0
  __int64 v16; // x0
  __int64 v17; // x0
  unsigned __int8 raw_value; // w0
  __int64 v19; // x0
  __int64 v20; // x0
  unsigned __int8 v21; // w0
  unsigned int v22; // w24
  __int64 v23; // x0
  __int64 v24; // x0
  unsigned __int8 v25; // w0
  __int64 v26; // x0
  __int64 v27; // x0
  unsigned __int8 v28; // w0
  __int64 v29; // x0
  __int64 v30; // x0
  unsigned __int8 v31; // w0
  _QWORD *v32; // x8
  const char *v34; // x1
  unsigned __int8 v35; // w24
  unsigned __int8 v36; // w24
  unsigned __int8 v37; // w24
  unsigned __int8 v38; // w28
  unsigned __int8 v39; // w28
  unsigned __int8 v40; // w8
  _UNKNOWN **v41; // x9
  char *v42; // x8
  unsigned __int8 v43; // w8

  v1 = *(_QWORD *)(a1 + 760);
  if ( debug_value != 1 )
  {
    if ( a1 )
      goto LABEL_3;
LABEL_39:
    printk(byte_72D8);
    return 4294966779LL;
  }
  printk(byte_75D8);
  if ( !a1 )
    goto LABEL_39;
LABEL_3:
  named_gpio = of_get_named_gpio(v1, "qcom,pcb-gpio1", 0);
  if ( (named_gpio & 0x80000000) != 0 )
  {
    if ( debug_value == 1 )
      printk(byte_72FF);
    v34 = "parse pcb_gpio error!!\n";
    goto LABEL_48;
  }
  v4 = named_gpio;
  v5 = ((__int64 (*)(void))gpio_request)();
  if ( v5 < 0 )
    printk("Failed to request GPIO:%d, ERRNO:%d", v4, v5);
  v6 = of_get_named_gpio(v1, "qcom,pcb-gpio2", 0);
  if ( (v6 & 0x80000000) != 0 )
  {
    if ( debug_value == 1 )
      printk(byte_71F3);
    v7 = 0;
  }
  else
  {
    v7 = v6;
    v8 = ((__int64 (*)(void))gpio_request)();
    if ( v8 < 0 )
      printk("Failed to request GPIO:%d, ERRNO:%d\n", v7, v8);
    pcb_gpio3 = of_get_named_gpio(v1, "qcom,pcb-gpio3", 0);
    if ( pcb_gpio3 < 0 )
    {
      if ( debug_value == 1 )
        printk(byte_7187);
    }
    else
    {
      v9 = ((__int64 (*)(void))gpio_request)();
      if ( v9 < 0 )
        printk("Failed to request GPIO:%d, ERRNO:%d\n", pcb_gpio3, v9);
    }
  }
  v10 = of_get_named_gpio(v1, "qcom,rf-gpio1", 0);
  if ( (v10 & 0x80000000) != 0 )
  {
    if ( debug_value == 1 )
      printk(byte_7611);
    goto LABEL_47;
  }
  v11 = v10;
  v12 = of_get_named_gpio(v1, "qcom,rf-gpio2", 0);
  if ( (v12 & 0x80000000) != 0 )
  {
    if ( debug_value == 1 )
      printk(byte_74DD);
LABEL_47:
    v34 = "parse rf_gpio error!!\n";
LABEL_48:
    dev_err(a1 + 16, v34);
    return 4294966779LL;
  }
  v13 = v12;
  v14 = gpio_request(v11, "NUBIA_RF_PCB_GPIO1");
  if ( v14 < 0 )
    printk("Failed to request GPIO:%d, ERRNO:%d", v11, v14);
  v15 = gpio_request(v13, "NUBIA_HW_RF_GPIO2");
  if ( v15 < 0 )
    printk("Failed to request GPIO:%d, ERRNO:%d\n", v13, v15);
  if ( (unsigned int)nubia_gpio_ctrl(a1) )
    return 4294967277LL;
  v16 = gpio_to_desc(v4);
  gpiod_direction_input(v16);
  msleep(1);
  v17 = gpio_to_desc(v4);
  raw_value = gpiod_get_raw_value(v17);
  if ( debug_value == 1 )
  {
    v35 = raw_value;
    printk(byte_7661, raw_value);
    raw_value = v35;
  }
  nubia_pcb_gpio1_v = raw_value;
  v19 = gpio_to_desc(v7);
  gpiod_direction_input(v19);
  msleep(1);
  v20 = gpio_to_desc(v7);
  v21 = gpiod_get_raw_value(v20);
  if ( debug_value == 1 )
  {
    v36 = v21;
    printk(byte_7661, v21);
    v21 = v36;
  }
  v22 = pcb_gpio3;
  nubia_pcb_gpio2_v = v21;
  v23 = gpio_to_desc((unsigned int)pcb_gpio3);
  gpiod_direction_input(v23);
  msleep(1);
  v24 = gpio_to_desc(v22);
  v25 = gpiod_get_raw_value(v24);
  if ( debug_value == 1 )
  {
    v37 = v25;
    printk(byte_7661, v25);
    v25 = v37;
  }
  nubia_pcb_gpio3_v = v25;
  v26 = gpio_to_desc(v11);
  gpiod_direction_input(v26);
  msleep(1);
  v27 = gpio_to_desc(v11);
  v28 = gpiod_get_raw_value(v27);
  if ( debug_value == 1 )
  {
    v38 = v28;
    printk(byte_7661, v28);
    v28 = v38;
  }
  nubia_rf_gpio1_v = v28;
  v29 = gpio_to_desc(v13);
  gpiod_direction_input(v29);
  msleep(1);
  v30 = gpio_to_desc(v13);
  v31 = gpiod_get_raw_value(v30);
  if ( debug_value == 1 )
  {
    v39 = v31;
    printk(byte_7661, v31);
    v31 = v39;
  }
  nubia_rf_gpio2_v = v31;
  msleep(20);
  v32 = *(_QWORD **)(a1 + 168);
  if ( !v32 )
  {
    dev_err(a1 + 16, "Cannot get hw gpio info\n");
    return 4294967277LL;
  }
  if ( !v32[2] )
  {
    printk(byte_72B1);
    return 4294967277LL;
  }
  if ( (unsigned int)pinctrl_select_state(*v32) )
    return 4294967277LL;
  nubia_pcb_gpio1_v += nubia_get_gpio_status(v4);
  nubia_pcb_gpio2_v += nubia_get_gpio_status(v7);
  v40 = nubia_pcb_gpio3_v + nubia_get_gpio_status((unsigned int)pcb_gpio3);
  nubia_pcb_gpio3_v = v40;
  if ( debug_value == 1 )
    printk(byte_73EA, (unsigned __int8)nubia_pcb_gpio1_v, (unsigned __int8)nubia_pcb_gpio2_v, v40);
  if ( (unsigned __int8)nubia_pcb_gpio1_v <= 1u )
  {
    if ( nubia_pcb_gpio1_v )
    {
      if ( nubia_pcb_gpio1_v == 1 && (unsigned int)_UNIQUE_ID_vermagic534[19] < 3 )
      {
        v41 = &off_79D0;
LABEL_67:
        v42 = (char *)v41[_UNIQUE_ID_vermagic534[19]];
        goto LABEL_68;
      }
    }
    else if ( (unsigned int)_UNIQUE_ID_vermagic534[19] < 3 )
    {
      v41 = &off_79A0;
      goto LABEL_67;
    }
LABEL_69:
    printk(byte_72E8);
    goto LABEL_70;
  }
  if ( nubia_pcb_gpio1_v == 2 )
  {
    if ( (unsigned int)_UNIQUE_ID_vermagic534[19] < 3 )
    {
      v41 = &off_79B8;
      goto LABEL_67;
    }
    goto LABEL_69;
  }
  if ( nubia_pcb_gpio1_v != 3 || _UNIQUE_ID_vermagic534[19] != 3 )
    goto LABEL_69;
  v42 = (char *)&unk_7768;
LABEL_68:
  printk(byte_7150, v42 + 12);
LABEL_70:
  nubia_rf_gpio1_v += nubia_get_gpio_status(v11);
  v43 = nubia_rf_gpio2_v + nubia_get_gpio_status(v13);
  nubia_rf_gpio2_v = v43;
  if ( debug_value == 1 )
    printk(byte_7568, (unsigned __int8)nubia_rf_gpio1_v, v43);
  return 0;
}
