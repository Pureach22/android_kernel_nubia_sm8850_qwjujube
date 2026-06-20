__int64 __fastcall st21nfc_probe(__int64 a1)
{
  __int64 (*v2)(void); // x8
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 result; // x0
  void *v7; // x0
  __int64 v8; // x20
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x0
  char v12; // w22
  void *v13; // x0
  __int64 v14; // x0
  unsigned __int64 v15; // x0
  unsigned int v16; // w0
  void *v17; // x8
  int v18; // w0
  __int64 v19; // x8
  __int64 v20; // x9
  int v21; // w22
  unsigned __int64 v22; // x0
  int v23; // w8
  void *v24; // x0
  int v25; // w8
  unsigned __int64 v26; // x0
  unsigned __int64 v27; // x0
  unsigned int v28; // w0
  unsigned int group; // w0
  unsigned int v30; // w23
  unsigned __int64 v31; // x8
  unsigned int v32; // w21
  unsigned __int64 v33; // x1
  unsigned __int64 v34; // x1
  unsigned __int64 v35; // x1
  __int64 v36; // x0
  unsigned int v37; // w0
  unsigned int v38; // w0
  void *v39; // x0
  int v40; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v41; // [xsp+8h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40 = 0;
  printk(&unk_8595, "st21nfc_probe");
  v2 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 16LL) + 32LL);
  if ( *((_DWORD *)v2 - 1) != 2093148950 )
    __break(0x8228u);
  if ( (v2() & 1) == 0 )
  {
    v7 = &unk_891D;
LABEL_20:
    printk(v7, "st21nfc_probe");
    result = 4294967277LL;
    goto LABEL_6;
  }
  v3 = a1 + 32;
  v4 = devm_kmalloc(a1 + 32, 984, 3520);
  if ( !v4 )
  {
    result = 4294967284LL;
    goto LABEL_6;
  }
  v8 = v4;
  *(_QWORD *)(v4 + 168) = a1;
  *(_DWORD *)(v4 + 540) = 0;
  printk(&unk_887A, v5);
  v9 = devm_gpiod_get(a1 + 32, &unk_84A3, 1);
  *(_QWORD *)(v8 + 944) = v9;
  if ( !v9 || v9 >= 0xFFFFFFFFFFFFF001LL )
  {
    v7 = &unk_83D0;
    goto LABEL_20;
  }
  v10 = devm_gpiod_get(a1 + 32, "reset", 7);
  *(_QWORD *)(v8 + 952) = v10;
  if ( !v10 || v10 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_8567, "st21nfc_probe");
    goto LABEL_22;
  }
  v11 = devm_gpiod_get(a1 + 32, "pidle", 1);
  *(_QWORD *)(v8 + 968) = v11;
  if ( v11 && v11 < 0xFFFFFFFFFFFFF001LL )
  {
    v12 = device_property_present(a1 + 32, "st,pidle_active_low") & 1;
    if ( v12 )
      v13 = &unk_8ABA;
    else
      v13 = &unk_8718;
    printk(v13, "st21nfc_probe");
    *(_BYTE *)(v8 + 976) = v12;
    v14 = alloc_workqueue(&unk_868B, 262152, 1, "st_pstate_work");
    *(_QWORD *)(v8 + 712) = v14;
    if ( !v14 )
    {
      devm_gpiod_put(a1 + 32, *(_QWORD *)(v8 + 968));
      devm_gpiod_put(a1 + 32, *(_QWORD *)(v8 + 952));
LABEL_22:
      devm_gpiod_put(a1 + 32, *(_QWORD *)(v8 + 944));
      result = 4294967277LL;
      goto LABEL_6;
    }
    _mutex_init(v8 + 72, "&st21nfc_dev->pidle_mutex", &st21nfc_probe___key);
    *(_QWORD *)(v8 + 720) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v8 + 728) = v8 + 728;
    *(_QWORD *)(v8 + 736) = v8 + 728;
    v36 = *(_QWORD *)(v8 + 968);
    *(_QWORD *)(v8 + 744) = st21nfc_pstate_wq;
    *(_DWORD *)(v8 + 544) = gpiod_to_irq(v36);
    v37 = irq_set_irq_type();
    if ( v37 )
    {
      v30 = v37;
      v39 = &unk_8624;
      goto LABEL_78;
    }
    v38 = devm_request_threaded_irq(
            a1 + 32,
            *(unsigned int *)(v8 + 544),
            st21nfc_dev_power_stats_handler,
            0,
            3,
            "st21nfc_pw_stats_idle_handle",
            v8);
    if ( v38 )
    {
      v30 = v38;
      v39 = &unk_87A7;
LABEL_78:
      printk(v39, "st21nfc_probe");
LABEL_61:
      v31 = *(_QWORD *)(v8 + 968);
      result = v30;
      goto LABEL_62;
    }
  }
  else
  {
    printk(&unk_86E9, "st21nfc_probe");
  }
  v15 = devm_gpiod_get(a1 + 32, "clkreq", 1);
  *(_QWORD *)(v8 + 960) = v15;
  if ( v15 && v15 < 0xFFFFFFFFFFFFF001LL )
  {
    v16 = of_property_read_u32_index(*(_QWORD *)(a1 + 776), "clkreq-gpios", 1, &v40);
    if ( (v16 & 0x80000000) != 0 )
    {
      v17 = &unk_8C15;
LABEL_56:
      v30 = v16;
      printk(v17, "st21nfc_probe");
      goto LABEL_61;
    }
    if ( (device_property_present(a1 + 32, "st,clk_pinctrl") & 1) != 0 )
    {
      printk(&unk_8A48, "st21nfc_probe");
      *(_BYTE *)(v8 + 936) = 1;
      *(_BYTE *)(v8 + 920) = 1;
    }
    else
    {
      printk(&unk_868E, "st21nfc_probe");
      *(_BYTE *)(v8 + 936) = 0;
    }
  }
  else
  {
    printk(&unk_87DC, "st21nfc_probe");
  }
  v18 = gpiod_to_irq(*(_QWORD *)(v8 + 944));
  v19 = *(_QWORD *)(a1 + 776);
  v20 = *(_QWORD *)(a1 + 24);
  *(_DWORD *)(a1 + 948) = v18;
  if ( (of_property_read_variable_u32_array(v19, "i2c-retry", v20 + 108, 1, 0) & 0x80000000) != 0 )
    *(_DWORD *)(*(_QWORD *)(a1 + 24) + 108LL) = 0;
  else
    printk(&unk_860D, "st21nfc_probe");
  v21 = 0;
  while ( (unsigned int)st21nfc_ping(v8) )
  {
    printk(&unk_8937, "st21nfc_probe");
    printk(&unk_8CA0, "st21nfc_recovery");
    mutex_lock(v8 + 120);
    v22 = *(_QWORD *)(v8 + 952);
    if ( !v22 || v22 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_40;
    ((void (*)(void))gpiod_set_value)();
    usleep_range_state(10000, 11000, 2);
    v23 = gpiod_direction_output(*(_QWORD *)(v8 + 944), 1);
    v24 = &unk_8B4B;
    if ( !v23 )
    {
      gpiod_set_value(*(_QWORD *)(v8 + 944), 1);
      usleep_range_state(10000, 11000, 2);
      gpiod_set_value(*(_QWORD *)(v8 + 952), 1);
      printk(&unk_8A6E, "st21nfc_recovery");
LABEL_40:
      msleep(20);
      gpiod_set_value(*(_QWORD *)(v8 + 944), 0);
      msleep(20);
      gpiod_set_value(*(_QWORD *)(v8 + 944), 1);
      msleep(20);
      gpiod_set_value(*(_QWORD *)(v8 + 944), 0);
      msleep(20);
      printk(&unk_88FB, "st21nfc_recovery");
      v25 = gpiod_direction_input(*(_QWORD *)(v8 + 944));
      v24 = &unk_8B0A;
      if ( !v25 )
        goto LABEL_34;
    }
    printk(v24, "st21nfc_recovery");
LABEL_34:
    mutex_unlock(v8 + 120);
    printk(&unk_85BC, "st21nfc_probe");
    if ( ++v21 == 3 )
    {
      v16 = st21nfc_ping(v8);
      if ( v16 )
      {
        v17 = &unk_8640;
        goto LABEL_56;
      }
      break;
    }
  }
  _init_waitqueue_head(v8, "&st21nfc_dev->read_wq", &st21nfc_probe___key_36);
  _mutex_init(v8 + 24, "&st21nfc_dev->read_mutex", &st21nfc_probe___key_38);
  _mutex_init(v8 + 120, "&st21nfc_dev->irq_dir_mutex", &st21nfc_probe___key_40);
  v26 = *(_QWORD *)(v8 + 944);
  *(_DWORD *)(v8 + 532) = 0;
  if ( v26 && v26 <= 0xFFFFFFFFFFFFF000LL )
    desc_to_gpio();
  v27 = *(_QWORD *)(v8 + 968);
  if ( v27 && v27 <= 0xFFFFFFFFFFFFF000LL )
    desc_to_gpio();
  printk(&unk_8982, "st21nfc_probe");
  *(_DWORD *)(v8 + 176) = 255;
  *(_QWORD *)(v8 + 184) = "st21nfc";
  *(_QWORD *)(v8 + 192) = &st21nfc_dev_fops;
  *(_QWORD *)(v8 + 216) = v3;
  *(_QWORD *)(a1 + 184) = v8;
  v28 = misc_register(v8 + 176);
  if ( v28 )
  {
    v30 = v28;
    printk(&unk_8C83, "st21nfc_probe");
  }
  else
  {
    group = sysfs_create_group(a1 + 32, &st21nfc_attr_grp);
    if ( !group )
    {
      *(_QWORD *)(v8 + 520) = wakeup_source_register(0, "st21nfc");
      *(_BYTE *)(v8 + 517) = 0;
      printk(&unk_88DD, "st21nfc_probe");
      result = 0;
      goto LABEL_6;
    }
    v30 = group;
    printk(&unk_88BB, "st21nfc_probe");
    misc_deregister(v8 + 176);
  }
  v31 = *(_QWORD *)(v8 + 968);
  result = v30;
  if ( v31 && v31 <= 0xFFFFFFFFFFFFF000LL )
  {
    sysfs_remove_file_ns(a1 + 32, &dev_attr_power_stats, 0);
    goto LABEL_61;
  }
LABEL_62:
  v32 = result;
  if ( v31 <= 0xFFFFFFFFFFFFF000LL )
  {
    destroy_workqueue(*(_QWORD *)(v8 + 712));
    devm_gpiod_put(v3, *(_QWORD *)(v8 + 968));
    result = v32;
  }
  v33 = *(_QWORD *)(v8 + 952);
  if ( v33 && v33 <= 0xFFFFFFFFFFFFF000LL )
  {
    devm_gpiod_put(v3, v33);
    result = v32;
  }
  v34 = *(_QWORD *)(v8 + 944);
  if ( v34 && v34 <= 0xFFFFFFFFFFFFF000LL )
  {
    devm_gpiod_put(v3, v34);
    result = v32;
  }
  v35 = *(_QWORD *)(v8 + 960);
  if ( v35 && v35 <= 0xFFFFFFFFFFFFF000LL )
  {
    devm_gpiod_put(v3, v35);
    result = v32;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
