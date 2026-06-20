__int64 __fastcall qti_ptd_device_probe(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x0
  _QWORD *v4; // x19
  __int64 v5; // x0
  __int64 v6; // x0
  int inited; // w0
  __int64 v8; // x8
  unsigned int v10; // w21

  v1 = a1 + 16;
  v3 = (_QWORD *)devm_kmalloc(a1 + 16, 96, 3520);
  if ( !v3 )
    return 4294967284LL;
  v4 = v3;
  *v3 = v1;
  v5 = ipc_log_context_create(10, "pdt_data", 0);
  v4[1] = v5;
  if ( !v5 )
    dev_err(v1, "%s: unable to create IPC Logging for %s\n", "qti_ptd_device_probe", "pdt_data");
  v6 = ipc_log_context_create(10, "pdt_event", 0);
  v4[2] = v6;
  if ( !v6 )
    dev_err(v1, "%s: unable to create IPC Logging for %s\n", "qti_ptd_device_probe", "pdt_event");
  _mutex_init(v4 + 6, "&pdt->hw_read_lock", &qti_pdt_hw_init___key);
  inited = qti_pdt_init_data_sharing((__int64)v4);
  if ( inited < 0 )
  {
    v10 = inited;
    dev_err(*v4, "Failed to initialize data sharing for pdt, rc=%d\n", inited);
    dev_err(v1, "%s: init failed\n", "qti_ptd_device_probe");
    ipc_log_context_destroy(v4[1]);
    ipc_log_context_destroy(v4[2]);
    return v10;
  }
  else
  {
    v4[3] = qti_pdt_share_updated_data_cb;
    qptm_data_update_notifier_register(v4 + 3);
    v8 = *v4;
    *(_QWORD *)(a1 + 168) = v4;
    *(_QWORD *)(v8 + 152) = v4;
    return 0;
  }
}
