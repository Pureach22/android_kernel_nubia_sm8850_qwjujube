__int64 __fastcall dp_power_init(__int64 a1, char a2)
{
  __int64 *v2; // x19
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x24
  _DWORD *v8; // x8
  const char *v9; // x22
  __int64 v10; // x0
  __int64 v11; // x26
  __int64 v12; // x28
  unsigned __int64 v13; // x19
  __int64 v14; // x0
  unsigned int v15; // w25
  __int64 v16; // x0
  const char *v17; // x25
  __int64 gpio; // x0
  __int64 v19; // x0
  __int64 v20; // x24
  __int64 v21; // x0
  unsigned int v22; // w25
  __int64 v23; // x0
  __int64 v24; // x21
  __int64 v25; // x0
  unsigned int v26; // w8
  __int64 result; // x0
  unsigned int v28; // w23
  __int64 v29; // x0
  __int64 v30; // x0
  unsigned __int64 StatusReg; // x21
  _DWORD *v32; // x8
  __int64 v33; // x0
  __int64 ipc_log_context; // x0
  unsigned int v35; // w19
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  unsigned int v42; // w8
  unsigned int v49; // w10
  __int64 v50; // x0
  __int64 v51; // x19
  unsigned int v52; // w8
  __int64 v53; // x21
  unsigned int i; // w20
  unsigned int *v55; // x24
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 *v58; // [xsp+0h] [xbp-10h]

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid power data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_22992C, "dp_power_init");
    return 4294967274LL;
  }
  v2 = (__int64 *)(a1 - 72);
  v5 = dp_power_regulator_ctrl(a1 - 72, 1);
  if ( (_DWORD)v5 )
  {
    v35 = v5;
    v36 = get_ipc_log_context(v5);
    ipc_log_string(v36, "[e][%-4d]failed to enable regulators\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_278F48, "dp_power_init");
    return v35;
  }
  v6 = dp_power_pinctrl_set(v2, 1);
  if ( !(_DWORD)v6 )
  {
    if ( !v2 )
    {
      v38 = get_ipc_log_context(v6);
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(v38, "[e][%-4d]invalid power data\n", *(_DWORD *)(StatusReg + 1800));
      v33 = printk(&unk_22992C, "dp_power_request_gpios");
      v28 = -22;
      goto LABEL_58;
    }
    v7 = *v2;
    v8 = *(_DWORD **)(*v2 + 40);
    if ( (*v8 & 0x80000000) == 0 )
    {
      v9 = "aux_enable";
      v10 = gpio_request();
      if ( (_DWORD)v10 )
        goto LABEL_39;
      v8 = *(_DWORD **)(v7 + 40);
    }
    if ( (v8[10] & 0x80000000) == 0 )
    {
      v9 = "aux_sel";
      v10 = gpio_request();
      if ( (_DWORD)v10 )
        goto LABEL_39;
      v8 = *(_DWORD **)(v7 + 40);
    }
    if ( (v8[20] & 0x80000000) == 0 )
    {
      v9 = "usbplug_cc";
      v10 = gpio_request();
      if ( (_DWORD)v10 )
        goto LABEL_39;
      v8 = *(_DWORD **)(v7 + 40);
    }
    if ( (v8[30] & 0x80000000) == 0 )
    {
      v9 = "edp_vcc_enable";
      v10 = gpio_request();
      if ( (_DWORD)v10 )
        goto LABEL_39;
      v8 = *(_DWORD **)(v7 + 40);
    }
    if ( (v8[40] & 0x80000000) == 0 )
    {
      v9 = "edp_backlight_pwr";
      v10 = gpio_request();
      if ( (_DWORD)v10 )
        goto LABEL_39;
      v8 = *(_DWORD **)(v7 + 40);
    }
    if ( (v8[50] & 0x80000000) == 0 )
    {
      v9 = "edp_pwm_en";
      v10 = gpio_request();
      if ( (_DWORD)v10 )
        goto LABEL_39;
      v8 = *(_DWORD **)(v7 + 40);
    }
    if ( (v8[60] & 0x80000000) != 0 || (v9 = "edp_backlight_en", v10 = gpio_request(), !(_DWORD)v10) )
    {
      v58 = v2;
      v11 = 0;
      v12 = *(_QWORD *)(*v2 + 40);
      v13 = _ReadStatusReg(SP_EL0);
      do
      {
        v17 = (const char *)(v12 + v11);
        gpio = dp_power_find_gpio(v12 + v11 + 8, "aux-sel");
        if ( (gpio & 1) != 0 )
          *((_DWORD *)v17 + 1) = a2 & 1;
        if ( (*(_DWORD *)v17 & 0x80000000) == 0 )
        {
          v19 = get_ipc_log_context(gpio);
          v20 = v12 + v11;
          ipc_log_string(
            v19,
            "[d][%-4d]gpio %s, value %d\n",
            *(_DWORD *)(v13 + 1800),
            v17 + 8,
            *(_DWORD *)(v12 + v11 + 4));
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]gpio %s, value %d\n",
              *(_DWORD *)(v13 + 1800),
              v17 + 8,
              *(_DWORD *)(v20 + 4));
          if ( (dp_power_find_gpio(v17 + 8, "aux-en") & 1) != 0 || (dp_power_find_gpio(v17 + 8, "aux-sel") & 1) != 0 )
          {
            v14 = *(unsigned int *)v17;
            v15 = *(_DWORD *)(v20 + 4);
            v16 = gpio_to_desc(v14);
            gpiod_direction_output_raw(v16, v15);
          }
          else
          {
            v21 = *(unsigned int *)v17;
            v22 = *(_DWORD *)(v20 + 4);
            v23 = gpio_to_desc(v21);
            gpiod_set_raw_value(v23, v22);
          }
        }
        v11 += 40;
      }
      while ( (_DWORD)v11 != 120 );
      v24 = *(_QWORD *)(*(_QWORD *)a1 + 8LL);
      v25 = _pm_runtime_resume(v24, 4);
      if ( (v25 & 0x80000000) != 0 )
      {
        v42 = *(_DWORD *)(v24 + 480);
        v28 = v25;
        do
        {
          if ( !v42 )
            break;
          _X12 = (unsigned int *)(v24 + 480);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v49 = __ldxr(_X12);
            if ( v49 != v42 )
              break;
            if ( !__stlxr(v42 - 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v49 == v42;
          v42 = v49;
        }
        while ( !_ZF );
        v50 = get_ipc_log_context(v25);
        ipc_log_string(
          v50,
          "[e][%-4d]failed to enable power resource %d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          v28);
        printk(&unk_21BDC6, "dp_power_init");
      }
      else
      {
        v26 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))dp_power_clk_enable)(a1, 0, 1);
        result = 0;
        if ( !v26 )
          return result;
        v28 = v26;
        v29 = get_ipc_log_context(0);
        ipc_log_string(v29, "[e][%-4d]failed to enable DP core clocks\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        printk(&unk_260F38, "dp_power_init");
        _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)a1 + 8LL), 4);
      }
      v51 = *v58;
      v52 = *(_DWORD *)(*v58 + 32);
      if ( v52 )
      {
        v53 = *(_QWORD *)(v51 + 40);
        for ( i = 0; i < v52; ++i )
        {
          v55 = (unsigned int *)(v53 + 40LL * (int)i);
          v56 = *v55;
          if ( (v56 & 0x80000000) == 0 )
          {
            v57 = gpio_to_desc(v56);
            gpiod_set_raw_value(v57, 0);
            gpio_free(*v55);
            v52 = *(_DWORD *)(v51 + 32);
          }
        }
      }
      v2 = v58;
      goto LABEL_75;
    }
LABEL_39:
    v28 = v10;
    v30 = get_ipc_log_context(v10);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(v30, "[e][%-4d]request %s gpio failed, rc=%d\n", *(_DWORD *)(StatusReg + 1800), v9, v28);
    printk(&unk_214A84, "dp_power_request_gpios");
    v32 = *(_DWORD **)(v7 + 40);
    if ( (*v32 & 0x80000000) != 0 )
    {
      if ( (v32[10] & 0x80000000) != 0 )
        goto LABEL_41;
    }
    else
    {
      ((void (*)(void))gpio_free)();
      v32 = *(_DWORD **)(v7 + 40);
      if ( (v32[10] & 0x80000000) != 0 )
      {
LABEL_41:
        if ( (v32[20] & 0x80000000) != 0 )
          goto LABEL_42;
        goto LABEL_49;
      }
    }
    ((void (*)(void))gpio_free)();
    v32 = *(_DWORD **)(v7 + 40);
    if ( (v32[20] & 0x80000000) != 0 )
    {
LABEL_42:
      if ( (v32[30] & 0x80000000) != 0 )
        goto LABEL_43;
      goto LABEL_50;
    }
LABEL_49:
    ((void (*)(void))gpio_free)();
    v32 = *(_DWORD **)(v7 + 40);
    if ( (v32[30] & 0x80000000) != 0 )
    {
LABEL_43:
      if ( (v32[40] & 0x80000000) != 0 )
        goto LABEL_44;
      goto LABEL_51;
    }
LABEL_50:
    ((void (*)(void))gpio_free)();
    v32 = *(_DWORD **)(v7 + 40);
    if ( (v32[40] & 0x80000000) != 0 )
    {
LABEL_44:
      if ( (v32[50] & 0x80000000) != 0 )
        goto LABEL_45;
      goto LABEL_52;
    }
LABEL_51:
    ((void (*)(void))gpio_free)();
    v32 = *(_DWORD **)(v7 + 40);
    if ( (v32[50] & 0x80000000) != 0 )
    {
LABEL_45:
      v33 = (unsigned int)v32[60];
      if ( (v33 & 0x80000000) != 0 )
        goto LABEL_58;
      goto LABEL_53;
    }
LABEL_52:
    ((void (*)(void))gpio_free)();
    v33 = *(unsigned int *)(*(_QWORD *)(v7 + 40) + 240LL);
    if ( (v33 & 0x80000000) != 0 )
    {
LABEL_58:
      v39 = get_ipc_log_context(v33);
      ipc_log_string(v39, "[e][%-4d]gpio request failed\n", *(_DWORD *)(StatusReg + 1800));
      v40 = printk(&unk_275CF6, "dp_power_config_gpios");
      v41 = get_ipc_log_context(v40);
      ipc_log_string(v41, "[e][%-4d]failed to enable gpios\n", *(_DWORD *)(StatusReg + 1800));
      printk(&unk_26467C, "dp_power_init");
LABEL_75:
      dp_power_pinctrl_set(v2, 0);
      goto LABEL_76;
    }
LABEL_53:
    v33 = ((__int64 (*)(void))gpio_free)();
    goto LABEL_58;
  }
  v28 = v6;
  v37 = get_ipc_log_context(v6);
  ipc_log_string(v37, "[e][%-4d]failed to set pinctrl state\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  printk(&unk_244C91, "dp_power_init");
LABEL_76:
  dp_power_regulator_ctrl(v2, 0);
  return v28;
}
