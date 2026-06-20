__int64 __fastcall dp_gpio_hpd_get(__int64 a1, __int64 a2)
{
  __int64 named_gpio; // x0
  unsigned int v5; // w24
  __int64 v6; // x0
  __int64 v7; // x19
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x22
  unsigned __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v19; // x0
  int v20; // w22
  __int64 v21; // x0
  __int64 v22; // x0

  if ( a1 && a2 )
  {
    named_gpio = of_get_named_gpio(*(_QWORD *)(a1 + 744), "qcom,dp-hpd-gpio", 0);
    if ( (named_gpio & 0x80000000) != 0 )
    {
      ipc_log_context = get_ipc_log_context(named_gpio);
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(
        ipc_log_context,
        "[d][%-4d]%s gpio not specified\n",
        *(_DWORD *)(StatusReg + 1800),
        "qcom,dp-hpd-gpio");
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]%s gpio not specified\n",
          *(_DWORD *)(StatusReg + 1800),
          "qcom,dp-hpd-gpio");
      return -22;
    }
    else
    {
      v5 = named_gpio;
      v6 = devm_kmalloc(a1, 240, 3520);
      if ( v6 )
      {
        v7 = v6;
        v8 = devm_pinctrl_get(a1);
        if ( v8
          && (v9 = v8, v8 <= 0xFFFFFFFFFFFFF000LL)
          && (v10 = pinctrl_lookup_state(v8, "mdss_dp_hpd_active")) != 0
          && v10 <= 0xFFFFFFFFFFFFF000LL
          && (v11 = pinctrl_select_state(v9, v10), (_DWORD)v11) )
        {
          v20 = v11;
          v22 = get_ipc_log_context(v11);
          ipc_log_string(v22, "[e][%-4d]failed to set hpd active state\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
          printk(&unk_24EFF2, "dp_gpio_hpd_get");
        }
        else
        {
          strcpy((char *)(v7 + 88), "qcom,dp-hpd-gpio");
          *(_DWORD *)(v7 + 80) = v5;
          *(_DWORD *)(v7 + 84) = 0;
          v12 = gpio_request(v5);
          if ( !(_DWORD)v12 )
          {
            v13 = gpio_to_desc(*(unsigned int *)(v7 + 80));
            gpiod_direction_input(v13);
            v14 = *(unsigned int *)(v7 + 80);
            *(_QWORD *)v7 = a1;
            *(_QWORD *)(v7 + 224) = a2;
            v15 = gpio_to_desc(v14);
            *(_DWORD *)(v7 + 232) = gpiod_to_irq(v15);
            *(_QWORD *)(v7 + 120) = 0xFFFFFFFE00000LL;
            *(_QWORD *)(v7 + 128) = v7 + 128;
            *(_QWORD *)(v7 + 136) = v7 + 128;
            *(_QWORD *)(v7 + 144) = dp_gpio_hpd_work;
            init_timer_key(v7 + 152, &delayed_work_timer_fn, 0x200000, 0, 0);
            *(_QWORD *)(v7 + 56) = dp_gpio_hpd_simulate_connect;
            *(_QWORD *)(v7 + 64) = dp_gpio_hpd_simulate_attention;
            *(_QWORD *)(v7 + 32) = dp_gpio_hpd_register;
            return v7 + 8;
          }
          v20 = v12;
          v21 = get_ipc_log_context(v12);
          ipc_log_string(
            v21,
            "[e][%-4d]%s: failed to request gpio\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            "qcom,dp-hpd-gpio");
          printk(&unk_264C19, "dp_gpio_hpd_get");
        }
        devm_kfree(a1);
        return v20;
      }
      else
      {
        return -12;
      }
    }
  }
  else
  {
    v19 = get_ipc_log_context(a1);
    ipc_log_string(v19, "[e][%-4d]invalid device\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_237845, "dp_gpio_hpd_get");
    return -22;
  }
}
