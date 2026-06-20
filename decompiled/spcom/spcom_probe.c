__int64 __fastcall spcom_probe(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 property; // x0
  __int64 v6; // x2
  __int64 v7; // x21
  __int64 v8; // x0
  __int64 v10; // x23
  __int64 v11; // x19
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x2
  __int64 v16; // x8
  void *v17; // x0
  unsigned int v18; // w21
  unsigned __int64 v19; // x0
  unsigned __int64 v20; // x0
  __int64 v21; // x8
  int v22; // w9
  __int64 v23; // x0
  unsigned int v24; // w0
  int v25; // w21
  __int64 v26; // x2
  unsigned int predefined_channels_chardev; // w0
  __int64 v28; // x0
  __int64 v29; // x2

  if ( !a1 )
  {
    printk(&unk_11FA5, "spcom_probe", a3);
    return 4294967277LL;
  }
  v3 = *(_QWORD *)(a1 + 760);
  if ( !v3 )
  {
    printk(&unk_EE85, "spcom_probe", a3);
    return 4294967274LL;
  }
  property = of_find_property(*(_QWORD *)(a1 + 760), "qcom,rproc-handle", 0);
  if ( !property )
  {
    printk(&unk_102DA, "spcom_probe", v6);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: can't find qcom,rproc-hable property",
      "spcom_probe",
      (const char *)&unk_F80E);
    return 4294967274LL;
  }
  v7 = property;
  v8 = _kmalloc_large_noprof(58736, 3520);
  if ( !v8 )
    return 4294967284LL;
  *(_QWORD *)(v8 + 1184) = a1;
  v10 = v8 + 57344;
  spcom_dev = v8;
  v11 = v8;
  *(_QWORD *)(v8 + 58472) = v7;
  *(_DWORD *)(v8 + 58288) = 1;
  _mutex_init(v8 + 58296, "&spcom_dev->chdev_count_lock", &spcom_probe___key);
  v12 = spcom_dev;
  *(_DWORD *)(spcom_dev + 58392) = 0;
  _init_swait_queue_head(v12 + 58400, "&x->wait", &init_completion___key);
  v13 = spcom_dev;
  *(_DWORD *)(spcom_dev + 58424) = 0;
  *(_DWORD *)(v13 + 58428) = 0;
  *(_QWORD *)(v13 + 58432) = v13 + 58432;
  *(_QWORD *)(v13 + 58440) = v13 + 58432;
  *(_QWORD *)(v13 + 58448) = 0xFFFFFFFF00000000LL;
  *(_DWORD *)(v13 + 58456) = 0;
  _mutex_init(v13 + 58344, "&spcom_dev->ch_list_lock", &spcom_probe___key_14);
  v14 = wakeup_source_register(*(_QWORD *)(spcom_dev + 1184) + 16LL, "spcom_wakeup");
  v16 = spcom_dev;
  *(_QWORD *)(spcom_dev + 1192) = v14;
  if ( !v14 )
  {
    v17 = &unk_FCE2;
LABEL_23:
    printk(v17, "spcom_probe", v15);
LABEL_24:
    kfree(v11);
    spcom_dev = 0;
    return 4294967277LL;
  }
  v18 = alloc_chrdev_region(v16 + 1160, 0, 1, "spcom");
  if ( (v18 & 0x80000000) != 0 )
  {
    printk(&unk_FB3F, "spcom_register_chardev", v18);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: alloc_chrdev_region failed %d\n",
      "spcom_register_chardev",
      (const char *)&unk_F80E,
      v18);
LABEL_22:
    v17 = &unk_116C5;
    goto LABEL_23;
  }
  v19 = class_create("spcom");
  *(_QWORD *)(spcom_dev + 1168) = v19;
  if ( v19 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_10C9A, "spcom_register_chardev", 4294967284LL);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: class_create failed %d\n",
      "spcom_register_chardev",
      (const char *)&unk_F80E,
      -12);
LABEL_21:
    unregister_chrdev_region(*(unsigned int *)(spcom_dev + 1160), 1);
    goto LABEL_22;
  }
  v20 = device_create();
  v21 = spcom_dev;
  *(_QWORD *)(spcom_dev + 1176) = v20;
  if ( v20 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_EC20, "spcom_register_chardev", v18);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: class_device_create failed %d\n",
      "spcom_register_chardev",
      (const char *)&unk_F80E,
      v18);
LABEL_20:
    class_destroy(*(_QWORD *)(spcom_dev + 1168));
    goto LABEL_21;
  }
  cdev_init(v21 + 1024, &fops);
  v22 = *(_DWORD *)(spcom_dev + 1160);
  v23 = spcom_dev + 1024;
  *(_QWORD *)(spcom_dev + 1120) = &_this_module;
  v24 = cdev_add(v23, v22 & 0xFFF00000, 32);
  if ( (v24 & 0x80000000) != 0 )
  {
    v25 = v24;
    printk(&unk_1144C, "spcom_register_chardev", v24);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: cdev_add failed %d\n",
      "spcom_register_chardev",
      (const char *)&unk_F80E,
      v25);
    device_destroy(*(_QWORD *)(spcom_dev + 1168), *(unsigned int *)(spcom_dev + 1160));
    goto LABEL_20;
  }
  ipc_log_string(
    spcom_ipc_log_context,
    "%sspcom:%s: char device created\n",
    "spcom_register_chardev",
    (const char *)&unk_F80E);
  if ( (spcom_parse_dt(v3) & 0x80000000) != 0 )
  {
LABEL_30:
    v28 = printk(&unk_10AD9, "spcom_probe", v26);
    spcom_unregister_chrdev(v28);
    goto LABEL_24;
  }
  if ( of_find_property(v3, "qcom,boot-enabled", 0) )
    *(_DWORD *)(v10 + 1116) = 1;
  predefined_channels_chardev = spcom_create_predefined_channels_chardev();
  if ( (predefined_channels_chardev & 0x80000000) != 0 )
  {
    printk(&unk_F0F7, "spcom_probe", predefined_channels_chardev);
    goto LABEL_30;
  }
  spcom_ipc_log_context = ipc_log_context_create(10, "spcom", 0);
  if ( !spcom_ipc_log_context )
    printk(&unk_116F1, "spcom_probe", v29);
  printk(&unk_F6A3, "spcom_probe", v29);
  ipc_log_string(
    spcom_ipc_log_context,
    "%sspcom:%s: Driver Initialization completed ok\n",
    "spcom_probe",
    (const char *)&unk_F80E);
  return 0;
}
