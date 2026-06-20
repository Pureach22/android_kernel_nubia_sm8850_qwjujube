__int64 __fastcall qcom_slim_ngd_ctrl_probe(_QWORD *a1)
{
  const char **v1; // x20
  __int64 v3; // x0
  __int64 v4; // x19
  unsigned __int64 v5; // x0
  unsigned int irq; // w22
  unsigned int v7; // w0
  _QWORD *resource_byname; // x22
  __int64 v9; // x0
  __int64 property; // x0
  const char *v11; // x1
  __int64 v12; // x0
  int v13; // w8
  const char *v14; // x2
  const char *v15; // x2
  const char *v16; // x3
  __int64 v17; // x0
  int v18; // w8
  int file_ns; // w22
  char v20; // w8
  unsigned __int64 v21; // x0
  unsigned __int64 v22; // x0
  unsigned __int64 v23; // x0
  __int64 v24; // x1
  _DWORD *v25; // x24
  __int64 next_available_child; // x0
  __int64 v27; // x23
  __int64 v28; // x21
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  unsigned int v32; // w0
  int v33; // w8
  int v34; // w8
  unsigned int v36; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v37; // [xsp+8h] [xbp-28h] BYREF
  __int64 v38; // [xsp+10h] [xbp-20h]
  _WORD v39[7]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v40; // [xsp+28h] [xbp-8h]

  v1 = (const char **)(a1 + 2);
  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  memset(v39, 0, sizeof(v39));
  v37 = 0;
  v3 = devm_kmalloc(a1 + 2, 5512, 3520);
  if ( !v3 )
  {
    irq = -12;
    goto LABEL_73;
  }
  v4 = v3;
  a1[21] = v3;
  v5 = devm_platform_get_and_ioremap_resource(a1, 0, 0);
  *(_QWORD *)(v4 + 1976) = v5;
  if ( v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    irq = v5;
    goto LABEL_73;
  }
  irq = platform_get_irq(a1, 0);
  if ( (irq & 0x80000000) != 0 )
    goto LABEL_73;
  *(_DWORD *)(v4 + 5504) = irq;
  v7 = devm_request_threaded_irq(v1, irq, qcom_slim_ngd_interrupt, 0, 4, "slim-ngd", v4);
  if ( v7 )
  {
    irq = dev_err_probe(v1, v7, "request IRQ failed\n");
    goto LABEL_73;
  }
  *(_BYTE *)(v4 + 5508) = 0;
  *(_BYTE *)(v4 + 5468) = 0;
  resource_byname = (_QWORD *)platform_get_resource_byname(a1, 512, "slimbus_remote_mem");
  if ( (unsigned int)dma_set_mask(v1, 0xFFFFFFFFLL) )
  {
    dev_err(v1, "could not set 32 bit mask\n");
    irq = -19;
    goto LABEL_73;
  }
  dma_set_coherent_mask(v1, 0xFFFFFFFFLL);
  if ( resource_byname )
  {
    *(_BYTE *)(v4 + 5468) = 1;
    *(_DWORD *)(v4 + 5464) = *resource_byname;
    v9 = devm_ioremap(v1);
    *(_QWORD *)(v4 + 5448) = v9;
    if ( !v9 )
    {
      dev_err(v1, "Remote mem ioremap failed\n");
      irq = -12;
      goto LABEL_73;
    }
    *(_QWORD *)(v4 + 5456) = v9;
    *(_QWORD *)(v4 + 5440) = resource_byname;
  }
  else
  {
    dev_err(v1, "no Remote mem\n");
  }
  property = of_find_property(a1[95], "qcom,wait_for_adsp_up", 0);
  v11 = (const char *)a1[16];
  *(_BYTE *)(v4 + 5481) = property != 0;
  if ( !v11 )
    v11 = *v1;
  v12 = ipc_log_context_create(10, v11, 0);
  *(_QWORD *)(v4 + 5488) = v12;
  if ( v12 )
  {
    *(_QWORD *)(v4 + 5472) = 0x300000003LL;
    _slimbus_dbg();
    v13 = *(_DWORD *)(v4 + 5476);
    if ( v13 >= 3 )
    {
      v14 = (const char *)a1[16];
      if ( !v14 )
        v14 = *v1;
      ipc_log_string(*(_QWORD *)(v4 + 5488), "start logging for slim dev %s\n", v14);
      v13 = *(_DWORD *)(v4 + 5476);
    }
    if ( !v13 )
    {
      v15 = (const char *)a1[16];
      if ( !v15 )
        v15 = *v1;
      ipc_log_string(*(_QWORD *)(v4 + 5496), "start logging for slim dev %s\n", v15);
    }
  }
  else
  {
    dev_err(v1, "error creating ipc_logging context\n");
  }
  v16 = (const char *)a1[16];
  v38 = 0;
  memset(v39, 0, sizeof(v39));
  v37 = 0;
  if ( !v16 )
    v16 = *v1;
  scnprintf(&v37, 30, "%s%s", v16, "_err");
  v17 = ipc_log_context_create(10, &v37, 0);
  *(_QWORD *)(v4 + 5496) = v17;
  if ( v17 )
  {
    _slimbus_dbg();
    v18 = *(_DWORD *)(v4 + 5476);
    if ( v18 >= 3 )
    {
      ipc_log_string(*(_QWORD *)(v4 + 5488), "start error logging for slim dev %s\n", (const char *)&v37);
      v18 = *(_DWORD *)(v4 + 5476);
    }
    if ( !v18 )
      ipc_log_string(*(_QWORD *)(v4 + 5496), "start error logging for slim dev %s\n", (const char *)&v37);
  }
  else
  {
    dev_err(v1, "error creating ipc_error_logging context\n");
  }
  file_ns = sysfs_create_file_ns(v1, &dev_attr_debug_mask, 0);
  if ( file_ns )
  {
    dev_err(v1, "Failed to create sysfs ret:%d\n", file_ns);
    v20 = 0;
  }
  else
  {
    v20 = 1;
  }
  *(_BYTE *)(v4 + 5480) = v20;
  *(_QWORD *)(v4 + 5344) = qcom_slim_ngd_ssr_notify;
  v21 = qcom_register_ssr_notifier("lpass", v4 + 5344);
  *(_QWORD *)(v4 + 5368) = v21;
  if ( v21 >= 0xFFFFFFFFFFFFF001LL )
  {
    irq = v21;
    dev_err(v1, "Failed to register SSR notification: %d\n", v21);
LABEL_69:
    if ( *(_QWORD *)(v4 + 5488) )
      ipc_log_context_destroy();
    if ( *(_BYTE *)(v4 + 5480) == 1 )
      sysfs_remove_file_ns(v1, &dev_attr_debug_mask, 0);
    goto LABEL_73;
  }
  *(_QWORD *)(v4 + 1968) = v1;
  *(_QWORD *)(v4 + 920) = 0xFA0002EE000LL;
  *(_DWORD *)(v4 + 980) = 10;
  *(_QWORD *)(v4 + 1208) = qcom_slim_ngd_get_laddr;
  *(_QWORD *)(v4 + 1216) = qcom_slim_ngd_enable_stream;
  *(_QWORD *)(v4 + 1224) = qcom_slim_ngd_disable_stream;
  *(_QWORD *)(v4 + 1192) = qcom_slim_ngd_xfer_msg;
  *(_DWORD *)(v4 + 5384) = 3;
  *(_QWORD *)(v4 + 1000) = v4;
  *(_QWORD *)(v4 + 1232) = 0;
  _mutex_init(v4 + 5152, "&ctrl->tx_lock", &qcom_slim_ngd_ctrl_probe___key);
  _mutex_init(v4 + 5200, "&ctrl->suspend_resume_lock", &qcom_slim_ngd_ctrl_probe___key_30);
  _mutex_init(v4 + 5248, "&ctrl->ssr_lock", &qcom_slim_ngd_ctrl_probe___key_32);
  _mutex_init(v4 + 5296, "&ctrl->qmi_handle_lock", &qcom_slim_ngd_ctrl_probe___key_34);
  *(_DWORD *)(v4 + 5144) = 0;
  *(_DWORD *)(v4 + 4880) = 0;
  _init_swait_queue_head(v4 + 4888, "&x->wait", &init_completion___key);
  *(_DWORD *)(v4 + 4912) = 0;
  _init_swait_queue_head(v4 + 4920, "&x->wait", &init_completion___key);
  *(_DWORD *)(v4 + 1928) = 0;
  _init_swait_queue_head(v4 + 1936, "&x->wait", &init_completion___key);
  *(_DWORD *)(v4 + 5016) = 0;
  _init_swait_queue_head(v4 + 5024, "&x->wait", &init_completion___key);
  *(_DWORD *)(v4 + 5048) = 0;
  _init_swait_queue_head(v4 + 5056, "&x->wait", &init_completion___key);
  *(_DWORD *)(v4 + 5080) = 0;
  _init_swait_queue_head(v4 + 5088, "&x->wait", &init_completion___key);
  *(_DWORD *)(v4 + 5112) = 0;
  _init_swait_queue_head(v4 + 5120, "&x->wait", &init_completion___key);
  v22 = pdr_handle_alloc(slim_pd_status, v4);
  *(_QWORD *)(v4 + 5376) = v22;
  if ( v22 >= 0xFFFFFFFFFFFFF001LL )
  {
    irq = dev_err_probe(v1, v22, "Failed to init PDR handle ret:%d\n", file_ns);
LABEL_68:
    qcom_unregister_ssr_notifier(*(_QWORD *)(v4 + 5368), v4 + 5344);
    goto LABEL_69;
  }
  v23 = pdr_add_lookup();
  if ( v23 >= 0xFFFFFFFFFFFFF001LL && v23 != -114 )
  {
    irq = dev_err_probe(v1, v23, "pdr add lookup failed ret:%d\n", file_ns);
LABEL_67:
    pdr_handle_release(*(_QWORD *)(v4 + 5376));
    goto LABEL_68;
  }
  v24 = a1[95];
  v36 = 0;
  v25 = *(_DWORD **)(of_match_node(&_mod_of__qcom_slim_ngd_dt_match_device_table, v24) + 192);
  next_available_child = of_get_next_available_child(a1[95], 0);
  if ( !next_available_child )
  {
LABEL_42:
    irq = -19;
    goto LABEL_64;
  }
  v27 = next_available_child;
  while ( (of_property_read_variable_u32_array(v27, "reg", &v36, 1, 0) & 0x80000000) != 0 )
  {
    v27 = of_get_next_available_child(a1[95], v27);
    if ( !v27 )
      goto LABEL_42;
  }
  v28 = _kmalloc_cache_noprof(platform_device_put, 3520, 24);
  if ( !v28 )
  {
    irq = -12;
LABEL_64:
    _slimbus_dbg();
    v34 = *(_DWORD *)(v4 + 5476);
    if ( v34 >= 1 )
    {
      printk(&unk_C60D, irq);
      ipc_log_string(*(_QWORD *)(v4 + 5488), "qcom_slim_ngd_register failed ret:%d\n", irq);
      *(_QWORD *)(v4 + 5472) = *(unsigned int *)(v4 + 5476);
    }
    else if ( v34 )
    {
      goto LABEL_67;
    }
    ipc_log_string(*(_QWORD *)(v4 + 5496), "qcom_slim_ngd_register failed ret:%d\n", irq);
    goto LABEL_67;
  }
  v29 = platform_device_alloc("qcom,slim-ngd", v36);
  *(_QWORD *)v28 = v29;
  if ( !v29 )
  {
    irq = -12;
    goto LABEL_57;
  }
  *(_DWORD *)(v28 + 16) = v36;
  *(_QWORD *)(v29 + 112) = v1;
  irq = driver_set_override(*(_QWORD *)v28 + 16LL, *(_QWORD *)v28 + 976LL, "qcom,slim-ngd", 13);
  v30 = *(_QWORD *)v28;
  if ( irq )
  {
LABEL_48:
    platform_device_put(v30);
LABEL_57:
    kfree(v28);
    goto LABEL_64;
  }
  *(_QWORD *)(v30 + 760) = v27;
  v31 = *(_QWORD *)v28;
  *(_QWORD *)(v4 + 1960) = v28;
  v32 = platform_device_add(v31);
  if ( v32 )
  {
    irq = v32;
    v30 = *(_QWORD *)v28;
    goto LABEL_48;
  }
  *(_QWORD *)(v28 + 8) = *(_QWORD *)(v4 + 1976)
                       + (unsigned int)(*v25 * *(_DWORD *)(v28 + 16))
                       + (unsigned int)(v25[1] * (*(_DWORD *)(v28 + 16) - 1));
  _platform_driver_register(qcom_slim_ngd_driver, &_this_module);
  _slimbus_dbg();
  v33 = *(_DWORD *)(v4 + 5476);
  if ( v33 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(v4 + 5488), "NGD SB controller is up!\n");
    v33 = *(_DWORD *)(v4 + 5476);
  }
  if ( !v33 )
    ipc_log_string(*(_QWORD *)(v4 + 5496), "NGD SB controller is up!\n");
  irq = 0;
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return irq;
}
