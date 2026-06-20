__int64 init_module()
{
  _QWORD *v0; // x0
  __int64 v1; // x0
  __int64 v2; // x2
  unsigned int v3; // w19

  v0 = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 96);
  qiib_info = (__int64)v0;
  if ( v0 )
  {
    *v0 = v0;
    v0[1] = v0;
    _mutex_init(v0 + 2, "&qiib_info->list_lock", &qiib_driver_data_init___key);
    v1 = ipc_log_context_create(4, "qsee_ipc_irq_bridge", 0);
    *(_QWORD *)(qiib_info + 88) = v1;
    if ( !v1 )
    {
      printk(&unk_7194, "qiib_driver_data_init", v2);
      ipc_log_string(*(_QWORD *)(qiib_info + 88), "%s: unable to create logging context\n", "qiib_driver_data_init");
    }
    v3 = _platform_driver_register(qsee_ipc_irq_bridge_driver, &_this_module);
    if ( v3 )
    {
      printk(&unk_7576, "qsee_ipc_irq_bridge_init", v3);
      ipc_log_string(
        *(_QWORD *)(qiib_info + 88),
        "%s: platform driver register failed %d\n",
        "qsee_ipc_irq_bridge_init",
        v3);
    }
  }
  else
  {
    v3 = -12;
    printk(&unk_75BE, "qsee_ipc_irq_bridge_init", 4294967284LL);
    ipc_log_string(
      *(_QWORD *)(qiib_info + 88),
      "%s: driver data init failed %d\n",
      "qsee_ipc_irq_bridge_init",
      4294967284LL);
  }
  return v3;
}
