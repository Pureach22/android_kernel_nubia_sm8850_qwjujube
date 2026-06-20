__int64 __fastcall adspsleepmon_driver_probe(__int64 a1)
{
  unsigned __int64 v2; // x0
  __int64 v3; // x20
  unsigned int v4; // w0
  unsigned int v5; // w0
  unsigned __int64 v6; // x0
  bool v7; // w9
  __int64 v8; // x0
  bool v9; // w9
  __int64 v10; // x0
  bool v11; // w9
  __int64 v12; // x0
  bool v13; // w9
  __int64 v14; // x0
  bool v15; // w9
  __int64 v16; // x0
  int v17; // w0
  unsigned __int64 v18; // x0
  unsigned int v19; // w20

  _mutex_init(&unk_A688, "&g_adspsleepmon.lock", &adspsleepmon_driver_probe___key);
  _mutex_init(&unk_B140, "&g_adspsleepmon.rpmsg_dev_lock", &adspsleepmon_driver_probe___key_30);
  qword_A638 = 0xF00000005LL;
  qword_A640 = 0x50000003CLL;
  word_A630 = 0;
  v2 = kthread_create_on_node(adspsleepmon_worker, 0, 0xFFFFFFFFLL, "adspsleepmon-worker");
  v3 = v2;
  if ( v2 <= 0xFFFFFFFFFFFFF000LL )
    wake_up_process(v2);
  qword_A758 = v3;
  if ( v3 )
  {
    qword_A768 = 0;
    v4 = alloc_chrdev_region(&dword_A748, 0, 1, "msm_adsp_sleepmon");
    if ( v4 )
    {
      v19 = v4;
      dev_err(a1 + 16, "Failed to allocate char device region\n");
      goto LABEL_29;
    }
    cdev_init(&unk_A6B8, &fops);
    qword_A718 = (__int64)&_this_module;
    v5 = cdev_add(&unk_A6B8, dword_A748 & 0xFFF00000, 1);
    if ( v5 )
    {
      v19 = v5;
      dev_err(a1 + 16, "Failed to add cdev\n");
      goto LABEL_33;
    }
    qword_A740 = class_create("adspsleepmon");
    if ( (unsigned __int64)qword_A740 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(a1 + 16, "Failed to create a class\n");
      v19 = 0;
      goto LABEL_32;
    }
    v6 = device_create();
    qword_A750 = v6;
    if ( !v6 || v6 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(a1 + 16, "Failed to create a device\n");
      v19 = 0;
      goto LABEL_31;
    }
    qword_B100 = debugfs_create_dir("adspsleepmon", 0);
    if ( !qword_B100 )
    {
      dev_err(a1 + 16, "Failed to create debugfs directory for adspsleepmon\n");
      v19 = 0;
      goto LABEL_30;
    }
    v7 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,enable_panic_lpm", 0) != 0;
    v8 = *(_QWORD *)(a1 + 760);
    LOBYTE(word_A630) = v7;
    v9 = of_find_property(v8, "qcom,enable_panic_lpi", 0) != 0;
    v10 = *(_QWORD *)(a1 + 760);
    HIBYTE(word_A630) = v9;
    v11 = of_find_property(v10, "qcom,enable_adsp_panic_lpm", 0) != 0;
    v12 = *(_QWORD *)(a1 + 760);
    byte_A632 = v11;
    v13 = of_find_property(v12, "qcom,enable_adsp_panic_lpi", 0) != 0;
    v14 = *(_QWORD *)(a1 + 760);
    byte_A633 = v13;
    v15 = of_find_property(v14, "qcom,enable_adsp_panic_lpm_overall", 0) != 0;
    v16 = *(_QWORD *)(a1 + 760);
    byte_A634 = v15;
    of_property_read_variable_u32_array(v16, "qcom,wait_time_lpm", &qword_A638, 1, 0);
    of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,wait_time_lpi", (char *)&qword_A638 + 4, 1, 0);
    of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,wait_time_lpm_overall", &qword_A640, 1, 0);
    of_property_read_variable_u32_array(
      *(_QWORD *)(a1 + 760),
      "qcom,min_required_resumes",
      (char *)&qword_A640 + 4,
      1,
      0);
    of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,rproc-handle", &dword_B130, 1, 0);
    if ( dword_B130 && ((byte_A632 & 1) != 0 || (byte_A633 & 1) != 0 || byte_A634 == 1) )
    {
      byte_A635 = 1;
      dev_info(a1 + 16, "ADSP SSR config enabled\n");
    }
    word_A62E = word_A630;
    if ( (word_A630 & 1) != 0 || HIBYTE(word_A630) )
    {
      qword_B108 = debugfs_create_file("panic-state", 420, qword_B100, 0, &panic_state_fops);
      if ( !qword_B108 )
        dev_err(a1 + 16, "Unable to create file in debugfs\n");
    }
    qword_B118 = debugfs_create_file("read_panic_state", 292, qword_B100, 0, &read_panic_state_fops);
    if ( !qword_B118 )
      dev_err(a1 + 16, "Unable to create read panic state file in debugfs\n");
    qword_B110 = debugfs_create_file("master_stats", 292, qword_B100, 0, &master_stats_fops);
    if ( !qword_B110 )
      dev_err(a1 + 16, "Failed to create debugfs file for master stats\n");
    qword_B120 = debugfs_create_file("adsp_panic_state", 420, qword_B100, 0, &adsp_panic_state_fops);
    if ( !qword_B120 )
      dev_err(a1 + 16, "Unable to create ADSP panic state file in debugfs\n");
    qword_B128 = debugfs_create_file("read_adsp_panic_state", 292, qword_B100, 0, &read_adsp_panic_state_fops);
    if ( !qword_B128 )
      dev_err(a1 + 16, "Unable to create ADSP panic state read file in debugfs\n");
    v17 = _register_rpmsg_driver(&sleepmon_rpmsg_client, &_this_module);
    if ( v17 )
    {
      v19 = v17;
      dev_err(a1 + 16, "Failed registering rpmsg driver with return %d\n", v17);
      goto LABEL_29;
    }
    byte_A636 = 1;
    dword_A658 = 0;
    _init_swait_queue_head(&unk_A660, "&x->wait", &init_completion___key);
    qword_B170 = (__int64)adsp_sleepmon_ssr_notifier;
    v18 = qcom_register_ssr_notifier("lpass");
    if ( v18 > 0xFFFFFFFFFFFFF000LL )
    {
      unregister_rpmsg_driver(&sleepmon_rpmsg_client);
      v19 = 0;
LABEL_29:
      debugfs_remove(qword_B100);
LABEL_30:
      device_destroy(qword_A740, (unsigned int)dword_A738);
LABEL_31:
      class_destroy(qword_A740);
LABEL_32:
      cdev_del(&unk_A6B8);
LABEL_33:
      unregister_chrdev_region((unsigned int)dword_A748, 1);
      return v19;
    }
    qword_B188 = v18;
    dev_info(a1 + 16, "ADSP sleep monitor probe called\n");
    return 0;
  }
  else
  {
    dev_err(a1 + 16, "Failed to create kernel thread\n");
    return 4294967284LL;
  }
}
