__int64 __fastcall icnss_get_pinctrl(__int64 a1)
{
  __int64 v2; // x28
  int named_gpio; // w2
  __int64 v4; // x0
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  int v7; // w0
  int v8; // w21
  int v9; // w2
  __int64 v10; // x0
  unsigned __int64 v11; // x0
  unsigned __int64 v12; // x0
  int v13; // w19
  unsigned int i; // w20
  int v15; // w0
  int v16; // w27
  unsigned int v17; // w19
  int v19; // w21
  int v20; // w20
  unsigned int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 8);
  v21 = 0;
  if ( of_find_property(*(_QWORD *)(v2 + 760), "pin-ctrl-support", 0) )
  {
    named_gpio = of_get_named_gpio(*(_QWORD *)(v2 + 760), "pin_sw-ctrl-gpio", 0);
    v4 = icnss_ipc_log_context;
    v21 = named_gpio;
    *(_DWORD *)(a1 + 284) = named_gpio;
    ipc_log_string(v4, "Switch control GPIO: %d\n", named_gpio);
    v5 = devm_pinctrl_get(v2 + 16);
    *(_QWORD *)(a1 + 248) = v5;
    if ( !v5 || v5 >= 0xFFFFFFFFFFFFF001LL )
    {
      v17 = v5;
      printk("%sFailed to get pinctrl, err = %d\n", byte_130B32, v5);
      ipc_log_string(icnss_ipc_log_context, "%sFailed to get pinctrl, err = %d\n", (const char *)&unk_12DBF3, v17);
      goto LABEL_24;
    }
    v6 = ((__int64 (*)(void))pinctrl_lookup_state)();
    *(_QWORD *)(a1 + 256) = v6;
    if ( v6 && v6 < 0xFFFFFFFFFFFFF001LL )
    {
      v7 = pinctrl_select_state(*(_QWORD *)(a1 + 248), v6);
      if ( v7 )
      {
        v8 = v7;
        printk("%sFailed to select sw_ctrl state, err = %d\n", byte_130B32, v7);
        ipc_log_string(
          icnss_ipc_log_context,
          "%sFailed to select sw_ctrl state, err = %d\n",
          (const char *)&unk_12DBF3,
          v8);
      }
    }
    else
    {
      ipc_log_string(icnss_ipc_log_context, "Failed to get sw_ctrl state, err = %d\n", v6);
    }
    v9 = of_get_named_gpio(*(_QWORD *)(v2 + 760), "pin_wlan-en-gpio", 0);
    v10 = icnss_ipc_log_context;
    *(_DWORD *)(a1 + 280) = v9;
    ipc_log_string(v10, "WLAN_EN GPIO: %d\n", v9);
    v11 = pinctrl_lookup_state(*(_QWORD *)(a1 + 248), "wlan_en_active");
    *(_QWORD *)(a1 + 264) = v11;
    if ( !v11 || v11 >= 0xFFFFFFFFFFFFF001LL )
    {
      v19 = v11;
      printk("%sFailed to get wlan_en active state, err = %d\n", byte_130B32, v11);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sFailed to get wlan_en active state, err = %d\n",
        (const char *)&unk_12DBF3,
        v19);
    }
    v12 = pinctrl_lookup_state(*(_QWORD *)(a1 + 248), "wlan_en_sleep");
    *(_QWORD *)(a1 + 272) = v12;
    if ( !v12 || v12 >= 0xFFFFFFFFFFFFF001LL )
    {
      v20 = v12;
      printk("%sFailed to get wlan_en sleep state, err = %d\n", byte_130B32, v12);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sFailed to get wlan_en sleep state, err = %d\n",
        (const char *)&unk_12DBF3,
        v20);
    }
  }
  else
  {
    *(_QWORD *)(a1 + 280) = 0xFFFFFFEAFFFFFFEALL;
  }
  v13 = of_property_count_elems_of_size(*(_QWORD *)(v2 + 760), "mpm_wake_set_gpios", 4);
  if ( v13 < 1 )
  {
    ipc_log_string(icnss_ipc_log_context, "No GPIOs to be setup for interrupt wakeup capable\n");
  }
  else
  {
    ipc_log_string(icnss_ipc_log_context, "Num of GPIOs to be setup for interrupt wakeup capable: %d\n", v13);
    for ( i = 0; i != v13; ++i )
    {
      if ( (unsigned int)of_property_read_u32_index(*(_QWORD *)(v2 + 760), "mpm_wake_set_gpios", i, &v21) )
      {
        printk("%sFailed to read gpio_id at index: %d\n", byte_130B32, i);
        ipc_log_string(icnss_ipc_log_context, "%sFailed to read gpio_id at index: %d\n", (const char *)&unk_12DBF3, i);
      }
      else
      {
        v15 = msm_gpio_mpm_wake_set(v21, 1);
        if ( v15 < 0 )
        {
          v16 = v15;
          printk("%sFailed to setup gpio_id: %d as interrupt wakeup capable, ret: %d\n", byte_130B32, v21, v15);
          ipc_log_string(
            icnss_ipc_log_context,
            "%sFailed to setup gpio_id: %d as interrupt wakeup capable, ret: %d\n",
            (const char *)&unk_12DBF3,
            v21,
            v16);
        }
        else
        {
          ipc_log_string(icnss_ipc_log_context, "gpio_id: %d successfully setup for interrupt wakeup capable\n", v21);
        }
      }
    }
  }
  v17 = 0;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return v17;
}
