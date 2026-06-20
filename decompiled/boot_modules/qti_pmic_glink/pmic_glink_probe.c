__int64 __fastcall pmic_glink_probe(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x0
  __int64 v4; // x19
  unsigned int string; // w0
  const char *v6; // x22
  unsigned int string_helper; // w0
  unsigned int v8; // w0
  __int64 v9; // x0
  __int64 v10; // x2
  void *v11; // x23
  __int64 v12; // x0
  __int64 v13; // x2
  __int64 v14; // x0
  unsigned __int64 v15; // x0
  unsigned __int64 v16; // x0
  unsigned int v17; // w24
  unsigned __int64 v18; // x0
  void *v19; // x2
  __int64 *v20; // x8
  __int64 v21; // x0
  unsigned __int64 dir; // x20
  __int64 v23; // x20
  void *v24; // x0
  void *v25; // x0

  v1 = a1 + 16;
  v3 = devm_kmalloc(a1 + 16, 400, 3520);
  if ( !v3 )
    return (unsigned int)-12;
  v4 = v3;
  string = of_property_read_string(*(_QWORD *)(a1 + 760), "qcom,pmic-glink-channel", v3 + 24);
  if ( (string & 0x80000000) != 0 )
  {
    v17 = string;
    v24 = &unk_7C5A;
LABEL_39:
    printk(v24, "pmic_glink_probe", v17);
    return v17;
  }
  v6 = *(const char **)(v4 + 24);
  if ( strlen(v6) >= 0x21 )
  {
    v25 = &unk_7899;
LABEL_42:
    printk(v25, "pmic_glink_probe", v6);
    return (unsigned int)-22;
  }
  of_property_read_string(*(_QWORD *)(a1 + 760), "qcom,subsys-name", v4 + 352);
  if ( !of_find_property(*(_QWORD *)(a1 + 760), "qcom,protection-domain", 0) )
    goto LABEL_9;
  string_helper = of_property_read_string_helper(*(_QWORD *)(a1 + 760), "qcom,protection-domain", v4 + 376, 1, 0);
  if ( (string_helper & 0x80000000) != 0 )
  {
    v17 = string_helper;
    v24 = &unk_7C9C;
    goto LABEL_39;
  }
  v6 = *(const char **)(v4 + 376);
  if ( strlen(v6) >= 0x41 )
  {
    v25 = &unk_7BDB;
    goto LABEL_42;
  }
  v8 = of_property_read_string_helper(*(_QWORD *)(a1 + 760), "qcom,protection-domain", v4 + 384, 1, 1);
  if ( (v8 & 0x80000000) != 0 )
  {
    v17 = v8;
    v24 = &unk_797F;
    goto LABEL_39;
  }
  v6 = *(const char **)(v4 + 384);
  if ( strlen(v6) >= 0x41 )
  {
    v25 = &unk_7625;
    goto LABEL_42;
  }
LABEL_9:
  v9 = alloc_workqueue("%s", (const char *)0x6000A);
  *(_QWORD *)(v4 + 248) = v9;
  if ( !v9 )
  {
    printk(&unk_7B70, "pmic_glink_probe", v10);
    return (unsigned int)-12;
  }
  _init_rwsem(v4 + 112, "&pgdev->rpdev_sem", &pmic_glink_probe___key);
  v11 = (void *)(v4 + 272);
  *(_QWORD *)(v4 + 184) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v4 + 192) = v4 + 192;
  *(_QWORD *)(v4 + 200) = v4 + 192;
  *(_QWORD *)(v4 + 208) = pmic_glink_rx_work;
  *(_QWORD *)(v4 + 216) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v4 + 224) = v4 + 224;
  *(_QWORD *)(v4 + 232) = v4 + 224;
  *(_QWORD *)(v4 + 240) = pmic_glink_init_work;
  *(_QWORD *)(v4 + 312) = v4 + 312;
  *(_QWORD *)(v4 + 320) = v4 + 312;
  *(_QWORD *)(v4 + 256) = v4 + 256;
  *(_QWORD *)(v4 + 264) = v4 + 256;
  *(_QWORD *)(v4 + 272) = v4 + 272;
  *(_QWORD *)(v4 + 280) = v4 + 272;
  *(_DWORD *)(v4 + 176) = 0;
  _mutex_init(v4 + 64, "&pgdev->client_lock", &pmic_glink_probe___key_29);
  *(_QWORD *)(v4 + 40) = 0x1000000400000000LL;
  *(_QWORD *)(v4 + 48) = 0;
  *(_QWORD *)(v4 + 56) = 0;
  *(_DWORD *)(v4 + 292) = 0;
  *(_DWORD *)(v4 + 392) = 0x7FFFFFFF;
  v12 = ipc_log_context_create(10, *(_QWORD *)(v4 + 24), 0);
  *(_QWORD *)(v4 + 32) = v12;
  if ( v12 )
  {
    v14 = *(_QWORD *)(v4 + 352);
    if ( !v14 )
      goto LABEL_13;
  }
  else
  {
    printk(&unk_79C8, "pmic_glink_probe", v13);
    v14 = *(_QWORD *)(v4 + 352);
    if ( !v14 )
      goto LABEL_13;
  }
  *(_QWORD *)(v4 + 328) = pmic_glink_ssr_notifier_cb;
  v15 = qcom_register_ssr_notifier(v14, v4 + 328);
  *(_QWORD *)(v4 + 360) = v15;
  if ( v15 >= 0xFFFFFFFFFFFFF001LL )
  {
    v17 = v15;
    printk(&unk_76C0, "pmic_glink_probe", (unsigned int)v15);
    goto LABEL_18;
  }
LABEL_13:
  if ( *(_QWORD *)(v4 + 376) )
  {
    v16 = pdr_handle_alloc(pmic_glink_pdr_notifier_cb, v4);
    v17 = v16;
    *(_QWORD *)(v4 + 368) = v16;
    if ( v16 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (_DWORD)v16 == -517 )
        v17 = -517;
      else
        printk(&unk_79F5, "pmic_glink_probe", (unsigned int)v16);
      goto LABEL_17;
    }
    v18 = pdr_add_lookup(v16, *(_QWORD *)(v4 + 376), *(_QWORD *)(v4 + 384));
    if ( v18 >= 0xFFFFFFFFFFFFF001LL )
    {
      v17 = v18;
      if ( v18 != -114 )
      {
        printk(&unk_78F9, "pmic_glink_probe", (unsigned int)v18);
        pdr_handle_release(*(_QWORD *)(v4 + 368));
LABEL_17:
        qcom_unregister_ssr_notifier(*(_QWORD *)(v4 + 360), v4 + 328);
LABEL_18:
        ipc_log_context_destroy(*(_QWORD *)(v4 + 32));
        idr_destroy(v4 + 40);
        destroy_workqueue(*(_QWORD *)(v4 + 248));
        return v17;
      }
    }
    ipc_log_string(
      *(_QWORD *)(v4 + 32),
      "Registering PDR for path_name: %s service_name: %s\n",
      *(const char **)(v4 + 384),
      *(const char **)(v4 + 376));
  }
  *(_QWORD *)(a1 + 168) = v4;
  *(_QWORD *)(v4 + 8) = v1;
  mutex_lock(&pmic_glink_dev_lock);
  v19 = pmic_glink_dev_list;
  if ( pmic_glink_dev_list == v11
    || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)pmic_glink_dev_list) != &pmic_glink_dev_list )
  {
    _list_add_valid_or_report(v4 + 272, &pmic_glink_dev_list);
  }
  else
  {
    *(_QWORD *)((char *)&unk_8 + (_QWORD)pmic_glink_dev_list) = v11;
    *(_QWORD *)(v4 + 272) = v19;
    *(_QWORD *)(v4 + 280) = &pmic_glink_dev_list;
    pmic_glink_dev_list = (_UNKNOWN *)(v4 + 272);
  }
  mutex_unlock(&pmic_glink_dev_lock);
  v20 = *(__int64 **)(v4 + 8);
  v21 = v20[14];
  if ( !v21 )
    v21 = *v20;
  dir = debugfs_create_dir(v21, 0);
  if ( dir >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_7AEA, "pmic_glink_add_debugfs", dir);
  }
  else
  {
    *(_QWORD *)(v4 + 16) = dir;
    debugfs_create_u32("filter", 384, dir, v4 + 300);
    debugfs_create_bool("enable", 384, dir, v4 + 304);
    debugfs_create_bool("crash_on_error", 384, dir, v4 + 305);
  }
  v23 = *(_QWORD *)(v4 + 8);
  device_set_wakeup_capable(v23, 1);
  device_wakeup_enable(v23);
  ipc_log_string(*(_QWORD *)(v4 + 32), "%s probed successfully\n", *(const char **)(v4 + 24));
  return 0;
}
