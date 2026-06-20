__int64 __fastcall qsee_ipc_irq_bridge_probe(__int64 a1)
{
  __int64 v2; // x20
  __int64 next_available_child; // x0
  __int64 v4; // x1
  int v5; // w21
  __int64 v6; // x8
  unsigned int v7; // w0
  unsigned __int64 v8; // x0
  __int64 v9; // x2
  __int64 v10; // x0
  __int64 v11; // x23
  unsigned int v12; // w20
  const char *v13; // x22
  unsigned __int64 v14; // x0
  unsigned __int64 v15; // x26
  unsigned int v16; // w0
  __int64 v17; // x0
  unsigned int string; // w0
  __int64 v19; // x0
  const char *v20; // x8
  const char *v21; // x9
  __int64 v22; // x8
  unsigned int v23; // w25
  unsigned __int64 v24; // x0
  unsigned __int64 *v25; // x1
  __int64 v26; // x2
  unsigned int v27; // w0
  unsigned int v28; // w4
  __int64 v29; // x0
  __int64 irq_data; // x0
  int v31; // w8
  __int64 v32; // x0
  __int64 v33; // x25
  unsigned __int64 v34; // x0
  __int64 v35; // x2
  unsigned int v36; // w0
  __int64 v37; // x0
  __int64 v38; // x0
  const char *v40; // [xsp+8h] [xbp-18h] BYREF
  const char *v41[2]; // [xsp+10h] [xbp-10h] BYREF

  v41[1] = *(const char **)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  next_available_child = of_get_next_available_child(v2, 0);
  if ( !next_available_child )
  {
    *(_DWORD *)(qiib_info + 64) = 0;
LABEL_42:
    printk(&unk_6FE9, "qsee_ipc_irq_bridge_probe", 0);
    ipc_log_string(
      *(_QWORD *)(qiib_info + 88),
      "%s:Fail nports = %d\n",
      "qsee_ipc_irq_bridge_probe",
      *(_DWORD *)(qiib_info + 64));
    v23 = -22;
    goto LABEL_56;
  }
  v4 = next_available_child;
  v5 = 0;
  do
  {
    v4 = of_get_next_available_child(v2, v4);
    --v5;
  }
  while ( v4 );
  v6 = qiib_info;
  *(_DWORD *)(qiib_info + 64) = -v5;
  if ( !v5 )
    goto LABEL_42;
  v7 = alloc_chrdev_region(v6 + 80, 0);
  if ( v7 >= 0xFFFFF001 )
  {
    v23 = v7;
    printk(&unk_7618, "qiib_alloc_chrdev_region", v7);
    ipc_log_string(
      *(_QWORD *)(qiib_info + 88),
      "%s: alloc_chrdev_region() failed ret:%i\n",
      "qiib_alloc_chrdev_region",
      v23);
    goto LABEL_44;
  }
  v8 = class_create("qsee_ipc_irq_bridge");
  *(_QWORD *)(qiib_info + 72) = v8;
  if ( v8 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_6FB8, "qiib_alloc_chrdev_region", v9);
    ipc_log_string(*(_QWORD *)(qiib_info + 88), "%s: class_create() failed ENOMEM\n", "qiib_alloc_chrdev_region");
    unregister_chrdev_region(*(_DWORD *)(qiib_info + 80) >> 20, *(unsigned int *)(qiib_info + 64));
    v23 = -12;
LABEL_44:
    printk(&unk_7096, "qsee_ipc_irq_bridge_probe", v23);
    ipc_log_string(
      *(_QWORD *)(qiib_info + 88),
      "%s: chrdev_region allocation failed ret:%i\n",
      "qsee_ipc_irq_bridge_probe",
      v23);
    goto LABEL_56;
  }
  v10 = of_get_next_available_child(*(_QWORD *)(a1 + 760), 0);
  if ( !v10 )
  {
LABEL_38:
    v38 = *(_QWORD *)(qiib_info + 88);
    if ( v38 )
      ipc_log_string(v38, "%s: Driver Initialized.\n", "qsee_ipc_irq_bridge_probe");
    v23 = 0;
    goto LABEL_56;
  }
  v11 = v10;
  v12 = 0;
  v13 = "qcom,dev-name";
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v14 = _kmalloc_cache_noprof(kfree, 3520, 264);
    v15 = v14;
    if ( !v14 || v14 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_738F, "qsee_ipc_irq_bridge_probe", v12);
      v37 = ipc_log_string(
              *(_QWORD *)(qiib_info + 88),
              "%s:Allocation failed id:%d\n",
              "qsee_ipc_irq_bridge_probe",
              v12);
      v23 = -12;
      goto LABEL_55;
    }
    v40 = nullptr;
    v41[0] = nullptr;
    v16 = of_property_read_string(v11, "qcom,dev-name", &v40);
    if ( v16 )
    {
      v23 = v16;
LABEL_47:
      printk(&unk_73AD, "qiib_parse_node", v13);
      ipc_log_string(*(_QWORD *)(qiib_info + 88), "%s: missing key: %s\n", "qiib_parse_node", v13);
      printk(&unk_7326, "qsee_ipc_irq_bridge_probe", v12);
      v37 = ipc_log_string(
              *(_QWORD *)(qiib_info + 88),
              "%s:qiib_parse_node failed %d\n",
              "qsee_ipc_irq_bridge_probe",
              v12);
      goto LABEL_55;
    }
    v17 = *(_QWORD *)(qiib_info + 88);
    if ( v17 )
      ipc_log_string(v17, "%s: %s = %s\n", "qiib_parse_node", "qcom,dev-name", v40);
    string = of_property_read_string(v11, "label", v41);
    if ( string )
    {
      v23 = string;
      v13 = "label";
      goto LABEL_47;
    }
    v19 = *(_QWORD *)(qiib_info + 88);
    if ( v19 )
      ipc_log_string(v19, "%s: %s = %s\n", "qiib_parse_node", "label", v41[0]);
    v20 = v40;
    v21 = v41[0];
    *(_DWORD *)(v15 + 16) = v12;
    *(_QWORD *)(v15 + 24) = v20;
    *(_QWORD *)(v15 + 216) = v21;
    _init_waitqueue_head(v15 + 176, "&devp->poll_wait_queue", &qiib_add_device___key);
    *(_DWORD *)(v15 + 208) = 0;
    cdev_init(v15 + 32, &qiib_fops);
    v22 = qiib_info;
    *(_QWORD *)(v15 + 128) = &_this_module;
    v23 = cdev_add(v15 + 32, v12 + *(_DWORD *)(v22 + 80), 1);
    if ( v23 >= 0xFFFFF001 )
    {
      printk(&unk_7643, "qiib_add_device", *(_QWORD *)(v15 + 24));
      ipc_log_string(
        *(_QWORD *)(qiib_info + 88),
        "%s: cdev_add() failed for dev [%s] ret:%i\n",
        "qiib_add_device",
        *(const char **)(v15 + 24),
        v23);
      goto LABEL_49;
    }
    v24 = device_create(*(_QWORD *)(qiib_info + 72), 0, v12 + *(_DWORD *)(qiib_info + 80), 0, *(_QWORD *)(v15 + 24));
    *(_QWORD *)(v15 + 168) = v24;
    if ( !v24 || v24 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_71D5, "qiib_add_device", *(_QWORD *)(v15 + 24));
      ipc_log_string(
        *(_QWORD *)(qiib_info + 88),
        "%s: device_create() failed for dev [%s]\n",
        "qiib_add_device",
        *(const char **)(v15 + 24));
      cdev_del(v15 + 32);
      v23 = -12;
LABEL_49:
      printk(&unk_70C4, "qsee_ipc_irq_bridge_probe", *(_QWORD *)(v15 + 24));
      v37 = ipc_log_string(
              *(_QWORD *)(qiib_info + 88),
              "%s: add [%s] device failed ret=%d\n",
              "qsee_ipc_irq_bridge_probe",
              *(const char **)(v15 + 24),
              v23);
      goto LABEL_55;
    }
    mutex_lock(qiib_info + 16);
    v25 = (unsigned __int64 *)qiib_info;
    v26 = *(_QWORD *)qiib_info;
    if ( *(_QWORD *)(*(_QWORD *)qiib_info + 8LL) != qiib_info || qiib_info == v15 || v26 == v15 )
    {
      _list_add_valid_or_report(v15);
      v25 = (unsigned __int64 *)qiib_info;
    }
    else
    {
      *(_QWORD *)(v26 + 8) = v15;
      *(_QWORD *)v15 = v26;
      *(_QWORD *)(v15 + 8) = v25;
      *v25 = v15;
    }
    mutex_unlock(v25 + 2);
    if ( (v23 & 0x80000000) != 0 )
      goto LABEL_49;
    v27 = irq_of_parse_and_map(v11, 0);
    *(_DWORD *)(v15 + 200) = v27;
    if ( !v27 )
    {
      printk(&unk_73AD, "qiib_init_notifs", "interrupts");
      ipc_log_string(*(_QWORD *)(qiib_info + 88), "%s: missing key: %s\n", "qiib_init_notifs", "interrupts");
      v23 = -19;
      goto LABEL_54;
    }
    v28 = v27;
    v29 = *(_QWORD *)(qiib_info + 88);
    if ( v29 )
    {
      ipc_log_string(v29, "%s: %s = %d\n", "qiib_init_notifs", "interrupts", v28);
      v28 = *(_DWORD *)(v15 + 200);
    }
    irq_data = irq_get_irq_data(v28);
    if ( !irq_data )
    {
      printk(&unk_7374, "qiib_init_notifs", *(unsigned int *)(v15 + 200));
      ipc_log_string(
        *(_QWORD *)(qiib_info + 88),
        "%s: get irqdata fail:%d\n",
        "qiib_init_notifs",
        *(_DWORD *)(v15 + 200));
      v23 = -19;
      goto LABEL_54;
    }
    v31 = **(_DWORD **)(irq_data + 16);
    v32 = *(_QWORD *)(qiib_info + 88);
    v33 = v31 & 0xF;
    if ( v32 )
      ipc_log_string(v32, "%s: irqtype = %d\n", "qiib_init_notifs", v33);
    *(_QWORD *)(v15 + 224) = qiib_restart_notifier_cb;
    v34 = qcom_register_ssr_notifier(*(_QWORD *)(v15 + 216), v15 + 224);
    *(_QWORD *)(v15 + 248) = v34;
    if ( !v34 || v34 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_76AD, "qiib_init_notifs", v35);
      ipc_log_string(*(_QWORD *)(qiib_info + 88), "%s: Could not register SSR notifier cb\n", "qiib_init_notifs");
      v23 = -22;
      goto LABEL_54;
    }
    v36 = request_threaded_irq(
            *(unsigned int *)(v15 + 200),
            qiib_irq_handler,
            0,
            v33 | 0x200000,
            *(_QWORD *)(v15 + 24),
            v15);
    if ( (v36 & 0x80000000) != 0 )
      break;
    ++v12;
    v11 = of_get_next_available_child(*(_QWORD *)(a1 + 760), v11);
    if ( !v11 )
      goto LABEL_38;
  }
  v23 = v36;
  printk(&unk_75E0, "qiib_init_notifs", *(unsigned int *)(v15 + 200));
  ipc_log_string(
    *(_QWORD *)(qiib_info + 88),
    "%s: request_irq() failed on %d\n",
    "qiib_init_notifs",
    *(_DWORD *)(v15 + 200));
  qcom_unregister_ssr_notifier(*(_QWORD *)(v15 + 248), v15 + 224);
LABEL_54:
  printk(&unk_72C5, "qsee_ipc_irq_bridge_probe", v23);
  v37 = ipc_log_string(
          *(_QWORD *)(qiib_info + 88),
          "%s: qiib_init_notifs failed ret=%d\n",
          "qsee_ipc_irq_bridge_probe",
          v23);
LABEL_55:
  qiib_cleanup(v37);
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return v23;
}
