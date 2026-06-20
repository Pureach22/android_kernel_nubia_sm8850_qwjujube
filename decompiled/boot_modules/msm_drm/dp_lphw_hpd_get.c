__int64 __fastcall dp_lphw_hpd_get(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 named_gpio; // x0
  unsigned int v9; // w25
  __int64 v10; // x0
  __int64 v11; // x19
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned __int64 v16; // x0
  int v17; // w23
  __int64 v18; // x22
  __int64 v19; // x25
  int v20; // w24
  __int64 v21; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v24; // x0
  unsigned __int64 v25; // x0
  unsigned __int64 v26; // x19
  unsigned __int64 v27; // x0
  __int64 v28; // x0
  __int64 ipc_log_context; // x0
  int v30; // w24
  __int64 v31; // x0
  __int64 v32; // x21
  __int64 v33; // x0
  unsigned __int64 v34; // x21
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0

  if ( !a1 || !a2 || !a4 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid device\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_237845, "dp_lphw_hpd_get");
    return -22;
  }
  named_gpio = of_get_named_gpio(*(_QWORD *)(a1 + 744), "qcom,dp-hpd-gpio", 0);
  if ( (named_gpio & 0x80000000) != 0 )
  {
    v21 = get_ipc_log_context(named_gpio);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(v21, "[d][%-4d]%s gpio not specified\n", *(_DWORD *)(StatusReg + 1800), "qcom,dp-hpd-gpio");
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
  v9 = named_gpio;
  v10 = devm_kmalloc(a1, 360, 3520);
  if ( !v10 )
    return -12;
  v11 = v10;
  strcpy((char *)(v10 + 104), "qcom,dp-hpd-gpio");
  *(_DWORD *)(v10 + 96) = v9;
  *(_DWORD *)(v10 + 100) = 0;
  v12 = gpio_request(v9);
  if ( (_DWORD)v12 )
  {
    v30 = v12;
    v31 = get_ipc_log_context(v12);
    ipc_log_string(
      v31,
      "[e][%-4d]%s: failed to request gpio\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      "qcom,dp-hpd-gpio");
    printk(&unk_264C19, "dp_lphw_hpd_get");
    v32 = v30;
LABEL_30:
    devm_kfree(a1);
    return v32;
  }
  v13 = gpio_to_desc(*(unsigned int *)(v11 + 96));
  gpiod_direction_input(v13);
  v14 = *(unsigned int *)(v11 + 96);
  *(_QWORD *)v11 = a1;
  *(_QWORD *)(v11 + 344) = a4;
  v15 = gpio_to_desc(v14);
  *(_DWORD *)(v11 + 352) = gpiod_to_irq(v15);
  v16 = alloc_workqueue("%s", (_BYTE *)&loc_60008 + 2);
  *(_QWORD *)(v11 + 136) = v16;
  if ( !v16 || v16 >= 0xFFFFFFFFFFFFF001LL )
  {
    v33 = get_ipc_log_context(v16);
    v34 = _ReadStatusReg(SP_EL0);
    ipc_log_string(v33, "[e][%-4d]Error creating connect_wq\n", *(_DWORD *)(v34 + 1800));
    v35 = printk(&unk_22373B, "dp_lphw_hpd_create_workqueue");
    v36 = get_ipc_log_context(v35);
    ipc_log_string(v36, "[e][%-4d]Failed to create a dp_hpd workqueue\n", *(_DWORD *)(v34 + 1800));
    printk(&unk_259D3A, "dp_lphw_hpd_get");
    v32 = -1;
    goto LABEL_30;
  }
  *(_QWORD *)(v11 + 248) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v11 + 256) = v11 + 256;
  *(_QWORD *)(v11 + 264) = v11 + 256;
  *(_QWORD *)(v11 + 272) = dp_lphw_hpd_connect;
  *(_QWORD *)(v11 + 280) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v11 + 288) = v11 + 288;
  *(_QWORD *)(v11 + 296) = v11 + 288;
  *(_QWORD *)(v11 + 304) = dp_lphw_hpd_disconnect;
  *(_QWORD *)(v11 + 312) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v11 + 320) = v11 + 320;
  *(_QWORD *)(v11 + 328) = v11 + 320;
  *(_QWORD *)(v11 + 40) = dp_lphw_hpd_host_init;
  *(_QWORD *)(v11 + 48) = dp_lphw_hpd_host_deinit;
  v17 = *(_DWORD *)(a2 + 112);
  *(_QWORD *)(v11 + 336) = dp_lphw_hpd_attention;
  *(_QWORD *)(v11 + 80) = a2;
  *(_QWORD *)(v11 + 88) = a3;
  v18 = v11 + 8;
  *(_QWORD *)(v11 + 56) = dp_lphw_hpd_simulate_connect;
  *(_QWORD *)(v11 + 64) = dp_lphw_hpd_simulate_attention;
  *(_QWORD *)(v11 + 24) = dp_lphw_hpd_isr;
  *(_QWORD *)(v11 + 32) = dp_lphw_hpd_register;
  if ( v17 )
  {
    v19 = *(_QWORD *)(a2 + 120);
    v20 = 0;
    while ( strcmp((const char *)(v19 + 72LL * v20 + 8), "hpd-pwr") )
    {
      if ( v17 == ++v20 )
        goto LABEL_20;
    }
    v24 = msm_dss_enable_vreg(v19 + 72LL * v20, 1, 1);
    if ( (_DWORD)v24 )
    {
      v37 = get_ipc_log_context(v24);
      ipc_log_string(v37, "[e][%-4d]hpd-pwr vreg not enabled\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_27966B, "dp_lphw_hpd_init");
    }
  }
LABEL_20:
  v25 = devm_pinctrl_get(*(_QWORD *)v11);
  if ( v25 )
  {
    if ( v25 <= 0xFFFFFFFFFFFFF000LL )
    {
      v26 = v25;
      v27 = pinctrl_lookup_state(v25, "mdss_dp_hpd_active");
      if ( v27 )
      {
        if ( v27 <= 0xFFFFFFFFFFFFF000LL )
        {
          v28 = pinctrl_select_state(v26, v27);
          if ( (_DWORD)v28 )
          {
            v38 = get_ipc_log_context(v28);
            ipc_log_string(v38, "[e][%-4d]failed to set hpd_active state\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
            printk(&unk_24F03F, "dp_lphw_hpd_init");
          }
        }
      }
    }
  }
  return v18;
}
