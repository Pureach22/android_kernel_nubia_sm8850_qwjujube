__int64 __fastcall init_module(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned __int64 v6; // x0
  __int64 v7; // x4
  __int64 v8; // x5
  unsigned int v9; // w0
  __int64 v10; // x4
  __int64 v11; // x5
  __int64 v12; // x4
  __int64 v13; // x5
  unsigned int v14; // w19
  unsigned __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x9
  unsigned __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  unsigned int v24; // w0
  __int64 v25; // x5
  __int64 v27; // x8
  __int64 v28; // x1
  __int64 v29; // x0
  __int64 v30; // x1
  __int64 v31; // x2
  __int64 v32; // x3
  __int64 v33; // x4
  __int64 v34; // x5
  unsigned int inited; // w0
  void *v36; // x0
  __int64 v37; // x3
  unsigned int v38; // w0
  __int64 v39; // x5
  unsigned int v40; // w0
  __int64 v41; // x5
  unsigned int v42; // w0
  __int64 v43; // x4

  if ( (synx_debug & 4) != 0 )
    printk(&unk_29C44, "info", "synx_init", 4230, a5, a6);
  v6 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 440);
  synx_dev = v6;
  if ( v6 && v6 < 0xFFFFFFFFFFFFF001LL )
  {
    v9 = alloc_chrdev_region(v6 + 136, 0, 1, "synx_device");
    if ( (v9 & 0x80000000) != 0 )
    {
      v14 = v9;
      if ( (synx_debug & 1) != 0 )
        printk(&unk_258B2, &unk_29207, "synx_init", 4240, v10, v11);
      goto LABEL_29;
    }
    cdev_init(synx_dev, &synx_fops);
    *(_QWORD *)(synx_dev + 96) = &_this_module;
    v14 = cdev_add();
    if ( (v14 & 0x80000000) != 0 )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_2B90F, &unk_29207, "synx_init", 4248, v12, v13);
      goto LABEL_28;
    }
    v15 = class_create("SYNX_DEVICE_NAME");
    v16 = synx_dev;
    *(_QWORD *)(synx_dev + 144) = v15;
    if ( v15 >= 0xFFFFFFFFFFFFF001LL )
    {
      v14 = v15;
LABEL_27:
      cdev_del();
LABEL_28:
      unregister_chrdev_region(*(unsigned int *)(synx_dev + 136), 1);
LABEL_29:
      kfree(synx_dev);
      synx_dev = 0;
      return v14;
    }
    device_create(v15, 0, *(unsigned int *)(v16 + 136), 0, "synx_device");
    *(_QWORD *)(synx_dev + 160) = alloc_workqueue("hiprio_synx_cb_queue", 18, 4);
    v17 = alloc_workqueue("hiprio_synx_cleanup_queue", 18, 2);
    v20 = *(_QWORD *)(synx_dev + 160);
    *(_QWORD *)(synx_dev + 168) = v17;
    if ( !v20 || !v17 )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_29279, &unk_29207, "synx_init", 4271, v18, v19);
      v14 = -22;
      goto LABEL_26;
    }
    v21 = vzalloc_noprof(23080);
    v22 = synx_dev;
    *(_QWORD *)(synx_dev + 152) = v21;
    if ( !v21 || v21 > 0xFFFFFFFFFFFFF000LL )
    {
LABEL_26:
      device_destroy(*(_QWORD *)(synx_dev + 144), *(unsigned int *)(synx_dev + 136));
      class_destroy(*(_QWORD *)(synx_dev + 144));
      goto LABEL_27;
    }
    _mutex_init(v22 + 176, "&synx_dev->vtbl_lock", &synx_init___key);
    _mutex_init(synx_dev + 352, "&synx_dev->error_lock", &synx_init___key_199);
    v23 = synx_dev;
    *(_QWORD *)(synx_dev + 336) = synx_dev + 336;
    *(_QWORD *)(v23 + 344) = v23 + 336;
    *(_QWORD *)(synx_dev + 328) = synx_init_debugfs_dir(v23);
    v24 = synx_global_mem_init();
    if ( v24 )
    {
      v14 = v24;
      if ( (synx_debug & 1) == 0 )
      {
LABEL_22:
        vfree(*(_QWORD *)(synx_dev + 152));
        goto LABEL_26;
      }
      v36 = &unk_281B8;
      v37 = 4288;
LABEL_48:
      printk(v36, &unk_29207, "synx_init", v37, v14, v25);
      goto LABEL_22;
    }
    v27 = synx_dev;
    v28 = synx_dev + 416;
    *(_QWORD *)(synx_dev + 400) = 0;
    *(_QWORD *)(v27 + 416) = synx_cdsp_restart_notifier;
    v29 = qcom_register_ssr_notifier("cdsp", v28);
    *(_QWORD *)(synx_dev + 408) = v29;
    if ( !v29 )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_2537F, &unk_29207, "synx_init", 4297, v33, v34);
      v14 = 0;
      goto LABEL_22;
    }
    inited = synx_internal_init_ops(v29, v30, v31, v32, v33, v34);
    if ( inited )
    {
      v14 = inited;
      if ( (synx_debug & 1) == 0 )
        goto LABEL_22;
      v36 = &unk_27803;
      v37 = 4303;
      goto LABEL_48;
    }
    v38 = synx_hwfence_init_ops(&synx_hwfence_ops);
    if ( v38 && (synx_debug & 8) != 0 )
      printk(&unk_2AD5B, &unk_2A972, "synx_init", 4309, v38, v39);
    synx_shared_ops = (__int64)synx_internal_share_handle_status;
    qword_25068 = (__int64)synx_internal_get_dma_fence;
    qword_25070 = (__int64)synx_internal_notify_recover;
    qword_25078 = (__int64)synx_internal_signal_fence;
    qword_25080 = (__int64)synx_dma_add_cb_no_enable_sig;
    v40 = synx_hwfence_init_interops();
    if ( v40 && (synx_debug & 1) != 0 )
      printk(&unk_269D1, &unk_29207, "synx_init", 4318, v40, v41);
    ipclite_register_client(synx_ipc_callback, 0);
    synx_local_mem_init();
    v42 = register_pm_notifier(&qcom_synx_notif_block);
    if ( v42 )
    {
      v14 = v42;
      if ( (synx_debug & 1) == 0 )
        goto LABEL_22;
      v36 = &unk_2A27B;
      v37 = 4326;
      goto LABEL_48;
    }
    if ( (synx_debug & 4) != 0 )
      printk(&unk_29FC7, "info", "synx_init", 4330, v43, v25);
    return 0;
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2B162, &unk_29207, "synx_init", 4234, v7, v8);
    return (unsigned int)-12;
  }
}
