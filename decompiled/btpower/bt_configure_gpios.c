__int64 __fastcall bt_configure_gpios(int a1)
{
  unsigned int v1; // w19
  unsigned int v2; // w21
  __int64 v3; // x0
  __int64 v4; // x0
  unsigned int v5; // w24
  __int64 v6; // x0
  void *v7; // x0
  unsigned int v8; // w25
  unsigned int v9; // w22
  unsigned int v10; // w23
  unsigned int v11; // w0
  __int64 v12; // x1
  unsigned int v13; // w0
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int v16; // w0
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x1
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x1
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x1
  __int64 v31; // x1
  __int64 v32; // x1
  __int64 v33; // x1
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x1
  __int64 v37; // x1
  __int64 v38; // x1
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x1
  __int64 v43; // x1
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  unsigned int v48; // w0
  __int64 v49; // x1
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0

  v1 = *(_DWORD *)(pwr_data + 8);
  v2 = *(_DWORD *)(pwr_data + 16);
  if ( !a1 )
  {
    v3 = gpio_to_desc(v1);
    gpiod_set_raw_value(v3, 0);
    msleep(100);
    v4 = gpio_to_desc(v1);
    gpiod_get_raw_value(v4);
    printk(&unk_11BD9, v1);
    v5 = 0;
    if ( (v2 & 0x80000000) == 0 )
    {
      v6 = gpio_to_desc(v2);
      gpiod_get_raw_value(v6);
      printk(&unk_13473, v2);
      v5 = 0;
    }
LABEL_4:
    v7 = &unk_10F38;
LABEL_14:
    printk(v7, "bt_configure_gpios");
    return v5;
  }
  v8 = *(_DWORD *)(pwr_data + 12);
  v9 = *(_DWORD *)(pwr_data + 24);
  v10 = *(_DWORD *)(pwr_data + 32);
  v11 = gpio_request(v1, "bt_sys_rst_n");
  if ( v11 )
  {
    v5 = v11;
    v7 = &unk_135AE;
    goto LABEL_14;
  }
  if ( (v10 & 0x80000000) == 0 )
  {
    v13 = gpio_request(v10, "bt_resetb_gpio_n");
    if ( v13 )
    {
      v5 = v13;
      v7 = &unk_135AE;
      goto LABEL_14;
    }
  }
  printk(&unk_12429, v12);
  v14 = gpio_to_desc(v1);
  gpiod_get_raw_value(v14);
  printk(&unk_12C2B, v1);
  v15 = gpio_to_desc(v1);
  v16 = gpiod_direction_output_raw(v15, 0);
  if ( v16 )
    goto LABEL_32;
  v17 = gpio_to_desc(v1);
  power_src[0] = gpiod_get_raw_value(v17);
  msleep(50);
  printk(&unk_1124E, v18);
  v19 = gpio_to_desc(v1);
  gpiod_get_raw_value(v19);
  printk(&unk_12C2B, v1);
  if ( (v2 & 0x80000000) != 0 )
  {
    v5 = 0;
    if ( (v8 & 0x80000000) != 0 )
      goto LABEL_23;
    goto LABEL_22;
  }
  v20 = gpio_to_desc(v2);
  dword_139E0 = gpiod_get_raw_value(v20);
  if ( *(int *)(pwr_data + 36) < 1 )
  {
    v5 = 0;
    goto LABEL_21;
  }
  v5 = msm_gpio_mpm_wake_set();
  if ( (v5 & 0x80000000) == 0 )
  {
    printk(&unk_128EE, v21);
LABEL_21:
    printk(&unk_12134, v2);
    if ( (v8 & 0x80000000) != 0 )
      goto LABEL_23;
LABEL_22:
    v23 = gpio_to_desc(v8);
    gpiod_get_raw_value(v23);
    printk(&unk_117A7, v8);
    v24 = gpio_to_desc(v8);
    if ( !(unsigned int)gpiod_get_raw_value(v24) )
    {
LABEL_25:
      v28 = gpio_to_desc(v8);
      if ( !(unsigned int)gpiod_get_raw_value(v28) )
      {
        v29 = gpio_to_desc(v1);
        if ( !(unsigned int)gpiod_get_raw_value(v29) )
          goto LABEL_27;
        printk(&unk_12928, v30);
        printk(&unk_11480, v33);
        v34 = gpio_to_desc(v1);
        v16 = gpiod_direction_output_raw(v34, 0);
        if ( !v16 )
        {
          v35 = gpio_to_desc(v1);
          power_src[0] = gpiod_get_raw_value(v35);
          if ( (v10 & 0x80000000) != 0 )
          {
            printk(&unk_12952, v36);
            printk(&unk_12EF6, v37);
            msleep(100);
            printk(&unk_11BAF, v38);
            btpower_set_xo_clk_gpio_state(1);
LABEL_35:
            v39 = gpio_to_desc(v1);
            v5 = gpiod_direction_output_raw(v39, 1);
            if ( v5 )
              goto LABEL_33;
            v40 = gpio_to_desc(v1);
            power_src[0] = gpiod_get_raw_value(v40);
            btpower_set_xo_clk_gpio_state(0);
            goto LABEL_37;
          }
          printk(&unk_110C1, v36);
          bt_pull_resetb(v10, 1);
LABEL_27:
          printk(&unk_12952, v30);
          printk(&unk_12EF6, v31);
          msleep(100);
          printk(&unk_11BAF, v32);
          btpower_set_xo_clk_gpio_state(1);
          if ( (v10 & 0x80000000) == 0 )
            bt_resetb_operation(v10);
          goto LABEL_35;
        }
LABEL_32:
        v5 = v16;
        goto LABEL_33;
      }
LABEL_37:
      v41 = gpio_to_desc(v1);
      if ( (unsigned int)gpiod_get_raw_value(v41) )
      {
LABEL_40:
        msleep(50);
        if ( (v2 & 0x80000000) == 0 )
        {
          v46 = gpio_to_desc(v2);
          v5 = gpiod_direction_input(v46);
          if ( v5 )
          {
            printk(&unk_12454, "bt_configure_gpios");
          }
          else
          {
            v47 = gpio_to_desc(v2);
            if ( !(unsigned int)gpiod_get_raw_value(v47) && (v9 & 0x80000000) == 0 )
            {
              v48 = gpio_request(v9, "bt_debug_n");
              if ( v48 )
              {
                v5 = v48;
                printk(&unk_12ACD, v49);
              }
              else
              {
                v50 = gpio_to_desc(v9);
                v5 = gpiod_direction_output_raw(v50, 1);
                if ( v5 )
                  printk(&unk_1127E, "bt_configure_gpios");
              }
            }
          }
        }
        v51 = gpio_to_desc(v1);
        gpiod_get_raw_value(v51);
        printk(&unk_13699, v1);
        if ( (v2 & 0x80000000) == 0 )
        {
          v52 = gpio_to_desc(v2);
          dword_139E0 = gpiod_get_raw_value(v52);
          printk(&unk_12286, v2);
        }
        goto LABEL_4;
      }
      btpower_set_xo_clk_gpio_state(1);
      printk(&unk_12AA4, v42);
      printk(&unk_10F1D, v43);
      v44 = gpio_to_desc(v1);
      v5 = gpiod_direction_output_raw(v44, 1);
      if ( !v5 )
      {
        v45 = gpio_to_desc(v1);
        power_src[0] = gpiod_get_raw_value(v45);
        btpower_set_xo_clk_gpio_state(0);
        goto LABEL_40;
      }
LABEL_33:
      printk(&unk_11A15, "bt_configure_gpios");
      return v5;
    }
LABEL_23:
    btpower_set_xo_clk_gpio_state(1);
    printk(&unk_117D6, v25);
    v26 = gpio_to_desc(v1);
    v5 = gpiod_direction_output_raw(v26, 1);
    if ( v5 )
      goto LABEL_33;
    v27 = gpio_to_desc(v1);
    power_src[0] = gpiod_get_raw_value(v27);
    btpower_set_xo_clk_gpio_state(0);
    if ( (v8 & 0x80000000) != 0 )
      goto LABEL_37;
    goto LABEL_25;
  }
  printk(&unk_10E24, v5);
  return v5;
}
