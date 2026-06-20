__int64 __fastcall wcd_usbss_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  __int64 result; // x0
  _QWORD *v5; // x21
  __int64 v6; // x22
  unsigned int v7; // w0
  unsigned int v8; // w19
  int v9; // w0
  __int64 v10; // x8
  const char *v11; // x1
  int v12; // w2
  __int64 v13; // x0
  unsigned int v14; // w8
  unsigned __int64 v15; // x0
  _QWORD *v16; // x8
  unsigned __int64 v17; // x0
  __int64 v18; // x0
  unsigned __int64 v19; // x0
  __int64 v20; // x0
  int v21; // w8
  __int64 v22; // x0
  __int64 v23; // x0
  unsigned __int64 v24; // x0
  _QWORD *v25; // x6
  __int64 v26; // x20
  int v27; // w0
  _QWORD *v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  unsigned __int64 v32; // x0
  __int64 v33; // x19
  __int64 v34; // x3
  __int64 v35; // x1
  __int64 v36; // x0
  unsigned int file_ns; // w0
  unsigned int v38; // w0
  unsigned int v39; // w0
  int v40; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v41; // [xsp+8h] [xbp-28h] BYREF
  __int64 (__fastcall *v42)(); // [xsp+10h] [xbp-20h]
  __int64 v43; // [xsp+18h] [xbp-18h]
  _QWORD *v44; // [xsp+20h] [xbp-10h]
  __int64 v45; // [xsp+28h] [xbp-8h]

  v1 = a1 + 32;
  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v43 = 0;
  v44 = nullptr;
  v41 = 0;
  v42 = nullptr;
  v40 = 0;
  v3 = devm_kmalloc(a1 + 32, 544, 3520);
  if ( !v3 )
  {
    result = 4294967284LL;
    goto LABEL_3;
  }
  *(_QWORD *)(v3 + 8) = v1;
  *(_QWORD *)(v3 + 16) = a1;
  *(_DWORD *)(v3 + 512) = 0;
  v5 = (_QWORD *)v3;
  _mutex_init(v3 + 320, "&priv->io_lock", &wcd_usbss_probe___key);
  _mutex_init(v5 + 51, "&priv->switch_update_lock", &wcd_usbss_probe___key_21);
  _mutex_init(v5 + 57, "&priv->runtime_env_counter_lock", &wcd_usbss_probe___key_23);
  *(_QWORD *)(a1 + 184) = v5;
  pm_runtime_enable(v1);
  _pm_runtime_use_autosuspend(v1, 1);
  pm_runtime_set_autosuspend_delay(v1, 600);
  v6 = v5[1];
  device_set_wakeup_capable(v6, 1);
  device_wakeup_enable(v6);
  v7 = acquire_runtime_env((__int64)v5);
  if ( (v7 & 0x80000000) != 0 )
  {
    v8 = v7;
    dev_err(*(_QWORD *)(wcd_usbss_ctxt_ + 8), "%s: acquire_runtime_env failed: %i\n", "wcd_usbss_probe", v7);
LABEL_27:
    v26 = v5[1];
    device_wakeup_disable(v26);
    device_set_wakeup_capable(v26, 0);
    _pm_runtime_use_autosuspend(*(_QWORD *)(wcd_usbss_ctxt_ + 8), 0);
    _pm_runtime_disable(*(_QWORD *)(wcd_usbss_ctxt_ + 8), 1);
    result = v8;
    goto LABEL_3;
  }
  v5[24] = "vdd-usb-cp";
  v9 = devm_regulator_bulk_get(v5[1], 1, v5 + 24);
  if ( v9 < 0 )
  {
    v10 = v5[1];
    v11 = "Failed to get supplies: %d\n";
    v12 = v9;
LABEL_8:
    v13 = v10;
    v8 = v12;
LABEL_26:
    dev_err(v13, v11);
    goto LABEL_27;
  }
  v14 = regulator_bulk_enable(1, v5 + 24);
  v13 = v5[1];
  if ( v14 )
  {
    v11 = "Failed to enable supplies: %d\n";
    v8 = v14;
    goto LABEL_26;
  }
  v15 = devm_pinctrl_get(v13);
  v16 = v5;
  v5[36] = v15;
  if ( v15 )
  {
    if ( v15 <= 0xFFFFFFFFFFFFF000LL )
    {
      v17 = pinctrl_lookup_state();
      v16 = v5;
      v5[37] = v17;
      if ( v17 )
      {
        if ( v17 <= 0xFFFFFFFFFFFFF000LL )
        {
          pinctrl_select_state(v5[36], v17);
          v16 = v5;
        }
      }
    }
  }
  v18 = v16[1];
  qword_F98 = (__int64)&wcd_usbss_readable_register;
  v19 = wcd_usbss_regmap_init(v18, (__int64)&wcd_usbss_regmap_config);
  *v5 = v19;
  if ( !v19 || v19 >= 0xFFFFFFFFFFFFF001LL )
  {
    v10 = v5[1];
    if ( v19 )
      v12 = v19;
    else
      v12 = -22;
    v11 = "Failed to initialize regmap: %d\n";
    goto LABEL_8;
  }
  if ( of_find_property(*(_QWORD *)(a1 + 776), "wcd-usb-sbu-compliance", 0) )
  {
    v20 = *v5;
    *((_BYTE *)v5 + 536) = 1;
    regmap_update_bits_base(v20, 37, 1, 0, 0, 0, 0);
    regmap_update_bits_base(*v5, 41, 1, 0, 0, 0, 0);
  }
  regmap_update_bits_base(*v5, 99, 119, 119, 0, 0, 0);
  regmap_update_bits_base(*v5, 30, 14, 8, 0, 0, 0);
  regmap_update_bits_base(*v5, 33, 14, 8, 0, 0, 0);
  regmap_update_bits_base(*v5, 129, 7, 1, 0, 0, 0);
  regmap_update_bits_base(*v5, 128, 224, 224, 0, 0, 0);
  regmap_update_bits_base(*v5, 130, 224, 224, 0, 0, 0);
  regmap_update_bits_base(*v5, 36, 12, 12, 0, 0, 0);
  regmap_update_bits_base(*v5, 40, 12, 12, 0, 0, 0);
  regmap_read(*v5, 1081, &v40);
  v21 = v40;
  if ( v40 == 1 )
  {
    regmap_update_bits_base(*v5, 36, 2, 0, 0, 0, 0);
    regmap_update_bits_base(*v5, 40, 2, 0, 0, 0, 0);
    v21 = v40;
  }
  v22 = *v5;
  *((_DWORD *)v5 + 126) = v21;
  regmap_write(v22, 67, 0);
  regmap_write(*v5, 1129, 0);
  regmap_write(*v5, 1131, 0);
  regmap_write(*v5, 1043, 5);
  devm_regmap_qti_debugfs_register(v5[1], *v5);
  v23 = v5[1];
  wcd_usbss_ctxt_ = (__int64)v5;
  *(_QWORD *)(a1 + 184) = v5;
  *((_DWORD *)v5 + 127) = 2;
  v24 = devm_nvmem_cell_get(v23, "usb_mode");
  v25 = v5;
  v5[65] = v24;
  if ( v24 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (_DWORD)v24 != -517 )
    {
      dev_err(v5[1], "nvmem cell get failed, rc:%d\n", v24);
      v25 = v5;
    }
    goto LABEL_36;
  }
  v27 = devm_request_threaded_irq(
          v5[1],
          *(unsigned int *)(v5[2] + 948LL),
          0,
          wcd_usbss_sdam_notifier_handler,
          0x2000,
          "wcd-usbss-sdam");
  if ( v27 )
  {
    dev_err(v5[1], "sdam registration failed, standby not supported, rc:%d\n", v27);
    v25 = v5;
LABEL_36:
    dev_info(v25[1], "wcd standby feature not enabled\n");
    v28 = v5;
    goto LABEL_37;
  }
  irq_set_irq_wake(*(unsigned int *)(v5[2] + 948LL), 1);
  dev_info(v5[1], "sdam registration successful\n");
  v28 = v5;
  *((_BYTE *)v5 + 400) = 1;
LABEL_37:
  v29 = v28[1];
  v44 = v28;
  v30 = _dev_fwnode(v29);
  v31 = v5[1];
  v41 = v30;
  v42 = wcd_usbss_mux_set;
  v32 = typec_mux_register(v31, &v41);
  v5[3] = v32;
  if ( v32 >= 0xFFFFFFFFFFFFF001LL )
  {
    v8 = dev_err_probe(v1, v32, "failed to register typec mux\n");
    goto LABEL_27;
  }
  _mutex_init(v5 + 18, "&priv->notification_lock", &wcd_usbss_probe___key_31);
  v33 = *v5;
  if ( audio_fsm_mode )
    v34 = 2;
  else
    v34 = 1;
  regmap_update_bits_base(*v5, 1043, 3, v34, 0, 0, 0);
  regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 32, 9, 9, 0, 0, 0);
  regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 39, 36, 36, 0, 0, 0);
  regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 43, 36, 36, 0, 0, 0);
  regmap_update_bits_base(v33, 1045, 128, 0, 0, 0, 0);
  regmap_update_bits_base(*(_QWORD *)wcd_usbss_ctxt_, 161, 255, 255, 0, 0, 0);
  v5[5] = 0xFFFFFFFE00000LL;
  v5[6] = v5 + 6;
  v5[7] = v5 + 6;
  v5[8] = wcd_usbss_usbc_analog_work_fn;
  _init_rwsem(v5 + 9, "&(&priv->wcd_usbss_notifier)->rwsem", &wcd_usbss_probe___key_34);
  v35 = kernel_kobj;
  v5[17] = 0;
  v36 = kobject_create_and_add("wcd_usbss", v35);
  v5[47] = v36;
  if ( v36 )
  {
    file_ns = sysfs_create_file_ns(v36, &wcd_usbss_surge_enable_attribute, 0);
    if ( (file_ns & 0x80000000) != 0 )
    {
      dev_err(
        v5[1],
        "%s: sysfs failed, unable to register surge enable attribute. rc: %d\n",
        "wcd_usbss_sysfs_init",
        file_ns);
    }
    else
    {
      v38 = sysfs_create_file_ns(v5[47], &wcd_usbss_surge_period_attribute, 0);
      if ( (v38 & 0x80000000) != 0 )
      {
        dev_err(
          v5[1],
          "%s: sysfs failed, unable to register surge period attribute. rc: %d\n",
          "wcd_usbss_sysfs_init",
          v38);
      }
      else
      {
        v39 = sysfs_create_file_ns(v5[47], &wcd_usbss_standby_enable_attribute, 0);
        if ( (v39 & 0x80000000) != 0 )
        {
          dev_err(
            v5[1],
            "%s: sysfs failed, unable to register standby enable attribute. rc: %d\n",
            "wcd_usbss_sysfs_init",
            v39);
        }
        else
        {
          *((_DWORD *)v5 + 98) = 15000;
          *((_BYTE *)v5 + 372) = 1;
          wcd_usbss_enable_surge_kthread();
        }
      }
    }
  }
  else
  {
    dev_err(v5[1], "%s: sysfs failed, surge kobj not created\n", "wcd_usbss_sysfs_init");
  }
  release_runtime_env(wcd_usbss_ctxt_);
  dev_info(v5[1], "Probe completed!\n");
  result = 0;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
