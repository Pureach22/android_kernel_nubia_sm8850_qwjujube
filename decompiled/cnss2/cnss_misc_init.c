__int64 __fastcall cnss_misc_init(__int64 *a1)
{
  unsigned int named_gpio; // w0
  __int64 v3; // x7
  unsigned __int64 StatusReg; // x21
  const char *v5; // x1
  unsigned int v6; // w0
  __int64 v7; // x7
  unsigned int v8; // w20
  const char *v9; // x1
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned int v12; // w0
  const char *v13; // x1
  unsigned __int64 v14; // x8
  const char *v15; // x1
  unsigned int v16; // w0
  __int64 v17; // x7
  unsigned __int64 v18; // x21
  const char *v19; // x1
  __int16 v20; // w9
  const char *v21; // x8
  __int64 v22; // x20
  unsigned int v23; // w0
  __int64 v24; // x7
  unsigned __int64 v25; // x8
  const char *v26; // x1
  __int16 v27; // w9
  const char *v28; // x8
  unsigned int v29; // w0
  __int64 v30; // x7
  unsigned __int64 v31; // x8
  const char *v32; // x1
  __int16 v33; // w9
  const char *v34; // x8
  __int64 v35; // x0
  __int64 v36; // x6
  __int64 v37; // x7
  unsigned __int64 v38; // x8
  const char *v39; // x1
  unsigned int v40; // w0
  __int64 v41; // x7
  const char *v42; // x1
  __int64 v43; // x0
  __int16 v44; // w9
  const char *v45; // x8
  unsigned int v46; // w0
  __int64 v47; // x7
  unsigned __int64 v48; // x8
  const char *v49; // x1
  __int16 v50; // w9
  const char *v51; // x8
  __int64 v52; // x9
  int v53; // w8
  __int64 property; // x0
  unsigned __int64 v55; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  named_gpio = of_get_named_gpio(*(_QWORD *)(*a1 + 760), "wlan-dev-sol-gpio", 0);
  *((_DWORD *)a1 + 34) = named_gpio;
  if ( (named_gpio & 0x80000000) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v5 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v5 = "soft_irq";
    }
    else
    {
      v5 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v5,
      "cnss_init_dev_sol_gpio",
      7u,
      7u,
      "Get device SOL GPIO (%d) from device node\n",
      named_gpio,
      v3,
      vars0);
    v6 = gpio_request(*((unsigned int *)a1 + 34), "wlan_dev_sol_gpio");
    if ( v6 )
    {
      v8 = v6;
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v9 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v9 = "soft_irq";
      }
      else
      {
        v9 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v9,
        "cnss_init_dev_sol_gpio",
        3u,
        3u,
        "Failed to request device SOL GPIO, err = %d\n",
        v6,
        v7,
        vars0);
      return v8;
    }
    v10 = gpio_to_desc(*((unsigned int *)a1 + 34));
    gpiod_direction_input(v10);
    v11 = gpio_to_desc(*((unsigned int *)a1 + 34));
    *((_DWORD *)a1 + 35) = gpiod_to_irq(v11);
    v12 = request_threaded_irq();
    if ( v12 )
    {
      v8 = v12;
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v13 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v13 = "soft_irq";
      }
      else
      {
        v13 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v13,
        "cnss_init_dev_sol_gpio",
        3u,
        3u,
        "Failed to request device SOL IRQ, err = %d\n",
        v12,
        v3,
        vars0);
      goto LABEL_83;
    }
  }
  if ( a1[66] == 4369 )
  {
    v14 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v14 + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v20 = *(_DWORD *)(v14 + 16);
      v21 = (const char *)(v14 + 2320);
      if ( (v20 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v21;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v15,
      "cnss_init_host_sol_gpio",
      6u,
      6u,
      "Reject normal host sol for: 0x%lx\n",
      4369,
      v3,
      vars0);
LABEL_27:
    init_timer_key(a1 + 784, cnss_bus_fw_boot_timeout_hdlr, 0, 0, 0);
    v22 = *a1;
    device_set_wakeup_capable(*a1 + 16, 1);
    v23 = device_wakeup_enable(v22 + 16);
    if ( v23 )
    {
      v25 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v25 + 16) & 0xF0000) != 0 )
      {
        v26 = "irq";
      }
      else
      {
        v27 = *(_DWORD *)(v25 + 16);
        v28 = (const char *)(v25 + 2320);
        if ( (v27 & 0xFF00) != 0 )
          v26 = "soft_irq";
        else
          v26 = v28;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v26,
        "cnss_misc_init",
        3u,
        3u,
        "Failed to init platform device wakeup source, err = %d\n",
        v23,
        v24,
        vars0);
    }
    a1[86] = 0xFFFFFFFE00000LL;
    a1[87] = (__int64)(a1 + 87);
    a1[88] = (__int64)(a1 + 87);
    a1[89] = (__int64)cnss_recovery_work_handler;
    *((_DWORD *)a1 + 1578) = 0;
    _init_swait_queue_head(a1 + 790, "&x->wait", &init_completion___key);
    *((_DWORD *)a1 + 1586) = 0;
    _init_swait_queue_head(a1 + 794, "&x->wait", &init_completion___key);
    *((_DWORD *)a1 + 1654) = 0;
    _init_swait_queue_head(a1 + 828, "&x->wait", &init_completion___key);
    *((_DWORD *)a1 + 1662) = 0;
    _init_swait_queue_head(a1 + 832, "&x->wait", &init_completion___key);
    *((_DWORD *)a1 + 1028) = 0;
    _init_swait_queue_head(a1 + 515, "&x->wait", &init_completion___key);
    _mutex_init(a1 + 797, "&plat_priv->dev_lock", &cnss_misc_init___key_508);
    _mutex_init(a1 + 803, "&plat_priv->driver_ops_lock", &cnss_misc_init___key_510);
    a1[50] = (__int64)cnss_reboot_notifier;
    v29 = register_reboot_notifier(a1 + 50);
    if ( v29 )
    {
      v31 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v31 + 16) & 0xF0000) != 0 )
      {
        v32 = "irq";
      }
      else
      {
        v33 = *(_DWORD *)(v31 + 16);
        v34 = (const char *)(v31 + 2320);
        if ( (v33 & 0xFF00) != 0 )
          v32 = "soft_irq";
        else
          v32 = v34;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v32,
        "cnss_misc_init",
        3u,
        3u,
        "Failed to register reboot notifier, err = %d\n",
        v29,
        v30,
        vars0);
    }
    v35 = wakeup_source_register(*a1 + 16, "CNSS_FW_RECOVERY");
    a1[930] = v35;
    if ( !v35 )
    {
      v38 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v38 + 16) & 0xF0000) != 0 )
      {
        v39 = "irq";
      }
      else
      {
        v44 = *(_DWORD *)(v38 + 16);
        v45 = (const char *)(v38 + 2320);
        if ( (v44 & 0xFF00) != 0 )
          v39 = "soft_irq";
        else
          v39 = v45;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v39,
        "cnss_misc_init",
        3u,
        3u,
        "Failed to setup FW recovery wake source\n",
        v36,
        v37,
        vars0);
    }
    v46 = cnss_plat_ipc_register(1, cnss_daemon_connection_update_cb, a1);
    if ( v46 )
    {
      v48 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v48 + 16) & 0xF0000) != 0 )
      {
        v49 = "irq";
      }
      else
      {
        v50 = *(_DWORD *)(v48 + 16);
        v51 = (const char *)(v48 + 2320);
        if ( (v50 & 0xFF00) != 0 )
          v49 = "soft_irq";
        else
          v49 = v51;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v49,
        "cnss_misc_init",
        3u,
        3u,
        "QMI IPC connection call back register failed, err = %d\n",
        v46,
        v47,
        vars0);
    }
    cnss_utils_register_status_notifier(0, cnss_fmd_status_update_cb, a1);
    v52 = a1[66];
    v53 = 4620288;
    if ( v52 != 4366 && v52 != 4369 )
    {
      if ( v52 != 4370 )
        goto LABEL_71;
      v53 = 5242880;
    }
    *((_DWORD *)a1 + 1650) = v53;
    *((_DWORD *)a1 + 1649) = 20971520;
LABEL_71:
    property = of_find_property(*(_QWORD *)(*a1 + 760), "qcom,rc-ep-short-channel", 0);
    if ( a1 && property )
      a1[966] |= 0x20uLL;
    v8 = 0;
    v55 = a1[66] - 4366;
    if ( v55 <= 4 && ((1LL << v55) & 0x19) != 0 )
    {
      v8 = 0;
      if ( a1 )
        a1[966] |= 0x40uLL;
    }
    return v8;
  }
  v16 = of_get_named_gpio(*(_QWORD *)(*a1 + 760), "wlan-host-sol-gpio", 0);
  *((_DWORD *)a1 + 37) = v16;
  if ( (v16 & 0x80000000) != 0 )
    goto LABEL_27;
  v18 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v18 + 16) & 0xF0000) != 0 )
  {
    v19 = "irq";
  }
  else if ( (*(_DWORD *)(v18 + 16) & 0xFF00) != 0 )
  {
    v19 = "soft_irq";
  }
  else
  {
    v19 = (const char *)(v18 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v19,
    "cnss_init_host_sol_gpio",
    7u,
    7u,
    "Get host SOL GPIO (%d) from device node\n",
    v16,
    v17,
    vars0);
  v40 = gpio_request(*((unsigned int *)a1 + 37), "wlan_host_sol_gpio");
  if ( !v40 )
  {
    v43 = gpio_to_desc(*((unsigned int *)a1 + 37));
    gpiod_direction_output_raw(v43, 0);
    goto LABEL_27;
  }
  v8 = v40;
  if ( (*(_DWORD *)(v18 + 16) & 0xF0000) != 0 )
  {
    v42 = "irq";
  }
  else if ( (*(_DWORD *)(v18 + 16) & 0xFF00) != 0 )
  {
    v42 = "soft_irq";
  }
  else
  {
    v42 = (const char *)(v18 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v42,
    "cnss_init_host_sol_gpio",
    3u,
    3u,
    "Failed to request host SOL GPIO, err = %d\n",
    v40,
    v41,
    vars0);
  if ( (a1[17] & 0x80000000) == 0 )
  {
    free_irq(*((unsigned int *)a1 + 35), a1);
LABEL_83:
    gpio_free(*((unsigned int *)a1 + 34));
  }
  return v8;
}
