__int64 __fastcall qmp_probe(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x0
  _QWORD *v4; // x19
  unsigned __int64 v5; // x0
  unsigned int v6; // w22
  unsigned __int64 v7; // x0
  unsigned int irq; // w23
  unsigned int v9; // w0
  unsigned int v10; // w0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v14; // x0
  __int64 v15; // x22
  __int64 v16; // x0
  __int64 next_available_child; // x0
  const char **v18; // x23
  unsigned int v19; // w27
  unsigned int v20; // w26
  const char *v21; // x28
  __int64 v22; // x27
  unsigned __int64 v23; // x0
  __int64 v24; // x23
  __int64 dir; // x0
  __int64 file; // x0
  __int64 v27; // x2
  __int64 v28; // x0
  __int64 v29; // x2
  __int64 v30; // x0
  __int64 v31; // x2

  v1 = a1 + 16;
  v3 = devm_kmalloc(a1 + 16, 256, 3520);
  if ( !v3 )
    return (unsigned int)-12;
  v4 = (_QWORD *)v3;
  *(_QWORD *)(v3 + 8) = v1;
  _init_waitqueue_head(v3 + 96, "&qmp->event", &qmp_probe___key);
  _mutex_init(v4 + 15, "&qmp->tx_lock", &qmp_probe___key_26);
  ilc = ipc_log_context_create(2, "aoss", 0);
  v5 = devm_platform_ioremap_resource(a1, 0);
  *v4 = v5;
  if ( v5 >= 0xFFFFFFFFFFFFF001LL )
    return (unsigned int)v5;
  v4[2] = v1;
  *((_BYTE *)v4 + 40) = 1;
  v7 = mbox_request_channel(v4 + 2, 0);
  v4[9] = v7;
  if ( v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(v1, "failed to acquire ipc mailbox\n");
    return *((unsigned int *)v4 + 18);
  }
  irq = platform_get_irq(a1, 0);
  v9 = devm_request_threaded_irq(v1, irq, qmp_intr, 0, 0, "aoss-qmp", v4);
  if ( (v9 & 0x80000000) != 0 )
  {
    v6 = v9;
    dev_err(v1, "failed to request interrupt\n");
    goto LABEL_13;
  }
  irq_set_irq_wake(irq, 1);
  v10 = qmp_open(v4);
  if ( (v10 & 0x80000000) != 0 )
  {
    v6 = v10;
    goto LABEL_13;
  }
  v11 = v4[1];
  v4[23] = &qmp_qdss_clk_add_qdss_init;
  v6 = clk_hw_register(v11, v4 + 21);
  v12 = v4[1];
  if ( (v6 & 0x80000000) != 0 )
  {
    dev_err(v12, "failed to register qdss clock\n");
    goto LABEL_11;
  }
  v6 = of_clk_add_hw_provider(*(_QWORD *)(v12 + 744), &of_clk_hw_simple_get, v4 + 21);
  if ( (v6 & 0x80000000) != 0 )
  {
    dev_err(v4[1], "unable to register of clk hw provider\n");
    clk_hw_unregister(v4 + 21);
    goto LABEL_11;
  }
  if ( v6 )
  {
LABEL_11:
    writel(0xFFFF0000, (unsigned int *)(*v4 + 44LL));
    writel(0xFFFF0000, (unsigned int *)(*v4 + 36LL));
    mbox_send_message(v4[9], 0);
    mbox_client_txdone(v4[9], 0);
LABEL_13:
    mbox_free_channel(v4[9]);
    return v6;
  }
  v14 = v4[1];
  v15 = *(_QWORD *)(v14 + 744);
  v16 = devm_kmalloc(v14, 64, 3520);
  v4[24] = v16;
  if ( v16 )
  {
    next_available_child = of_get_next_available_child(v15, 0);
    if ( next_available_child )
    {
      v18 = (const char **)next_available_child;
      v19 = 0;
      do
      {
        v20 = v19;
        if ( of_find_property(v18, "#cooling-cells", 0) )
        {
          v21 = *v18;
          v22 = v4[24] + 32LL * (int)v19;
          *(_BYTE *)(v22 + 24) = 0;
          *(_QWORD *)(v22 + 8) = v4;
          *(_QWORD *)(v22 + 16) = v21;
          v23 = devm_thermal_of_cooling_device_register(v4[1], v18, v21, v22, qmp_cooling_device_ops);
          *(_QWORD *)v22 = v23;
          if ( v23 >= 0xFFFFFFFFFFFFF001LL )
          {
            dev_err(v4[1], "unable to register %s cooling device\n", v21);
            v23 = *(_QWORD *)v22;
          }
          v19 = v20 + 1;
          if ( v23 >= 0xFFFFFFFFFFFFF001LL )
          {
            if ( (v20 & 0x80000000) == 0 )
            {
              v24 = 32LL * v20;
              do
              {
                thermal_cooling_device_unregister(*(_QWORD *)(v4[24] + v24));
                v24 -= 32;
              }
              while ( v24 != -32 );
            }
            devm_kfree(v4[1], v4[24]);
            goto LABEL_35;
          }
        }
        v18 = (const char **)of_get_next_available_child(v15, v18);
      }
      while ( v18 );
      if ( v19 )
        goto LABEL_36;
    }
    devm_kfree(v4[1], v4[24]);
  }
  else
  {
LABEL_35:
    dev_err(v1, "failed to register aoss cooling devices\n");
  }
LABEL_36:
  *(_QWORD *)(a1 + 168) = v4;
  dir = debugfs_create_dir("qcom_aoss", 0);
  v4[25] = dir;
  file = debugfs_create_file("ddr_frequency_mhz", 128, dir, v4, &qmp_debugfs_fops);
  v27 = v4[25];
  v4[26] = file;
  v28 = debugfs_create_file("prevent_aoss_sleep", 128, v27, v4, &qmp_debugfs_fops);
  v29 = v4[25];
  v4[27] = v28;
  v30 = debugfs_create_file("prevent_cx_collapse", 128, v29, v4, &qmp_debugfs_fops);
  v31 = v4[25];
  v4[28] = v30;
  v4[29] = debugfs_create_file("prevent_ddr_collapse", 128, v31, v4, &qmp_debugfs_fops);
  v6 = 0;
  v4[30] = debugfs_create_file("aoss_send_message", 144, 0, v4, &aoss_dbg_fops);
  return v6;
}
