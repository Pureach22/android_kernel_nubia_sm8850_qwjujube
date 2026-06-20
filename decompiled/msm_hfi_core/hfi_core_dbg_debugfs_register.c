__int64 __fastcall hfi_core_dbg_debugfs_register(unsigned __int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x20
  unsigned __int64 *v8; // x21
  unsigned __int64 dir; // x0
  unsigned __int64 v10; // x22
  unsigned __int64 v11; // x0
  __int64 v12; // x4
  unsigned __int64 v13; // x23
  __int64 v14; // x3
  __int64 v15; // x4
  int v16; // w8

  v6 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( a1 )
      goto LABEL_3;
LABEL_11:
    printk(&unk_1905C, "hfi_core_dbg_debugfs_register", 2876, v6, a5);
    LODWORD(v10) = -22;
    return (unsigned int)v10;
  }
  printk(&unk_1E83A, "hfi_core_dbg_debugfs_register", 2873, a4, a5);
  if ( !a1 )
    goto LABEL_11;
LABEL_3:
  v8 = (unsigned __int64 *)_kmalloc_cache_noprof(of_irq_get, 3520, 280);
  if ( !v8 )
  {
    LODWORD(v10) = -12;
    return (unsigned int)v10;
  }
  dir = debugfs_create_dir("hfi_core", 0);
  v10 = dir;
  if ( !dir || dir >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_1F1BC, "hfi_core_dbg_debugfs_register", 2887, v6, dir);
LABEL_14:
    kfree(v8);
    *(_QWORD *)(a1 + 792) = 0;
    return (unsigned int)v10;
  }
  *(_QWORD *)(a1 + 792) = v8;
  v8[1] = a1;
  _mutex_init(v8 + 4, "&debugfs_data->clients_list_lock", &hfi_core_dbg_debugfs_register___key);
  v8[2] = (unsigned __int64)(v8 + 2);
  v8[3] = (unsigned __int64)(v8 + 2);
  v8[15] = (unsigned __int64)(v8 + 15);
  v8[16] = (unsigned __int64)(v8 + 15);
  debugfs_create_file("hfi_core_register_client", 384, v10, a1, &hfi_core_register_clients_fops);
  debugfs_create_file("hfi_core_get_buf", 384, v10, a1, &hfi_core_dbg_get_buf_fops);
  debugfs_create_file("hfi_core_trigger_ipc", 384, v10, a1, &hfi_core_dbg_send_buf_fops);
  debugfs_create_file("hfi_core_put_buf", 384, v10, a1, &hfi_core_dbg_put_buf_fops);
  debugfs_create_file("hfi_core_unregister_client", 384, v10, a1, &hfi_core_unregister_clients_fops);
  debugfs_create_file("hfi_core_print_res_tbl", 384, v10, a1, &hfi_core_print_res_table_fops);
  debugfs_create_file("hfi_core_dbg_test_pkt_send", 384, v10, a1, &hfi_core_dbg_test_pkt_fops);
  debugfs_create_file("hfi_core_dump_events", 384, v10, a1, &hfi_core_dbg_dump_events_fops);
  debugfs_create_bool("hfi_core_fail_client0_reg", 384, v10, &msm_hfi_fail_client_0_reg);
  debugfs_create_u32("hfi_core_pkt_cmd_id", 384, v10, &msm_hfi_packet_cmd_id);
  debugfs_create_file("hfi_core_lb_cmd_data", 384, v10, a1, &hfi_core_dbg_lb_cmd_fops);
  debugfs_create_u32("hfi_core_debug_level", 384, v10, &msm_hfi_core_debug_level);
  *v8 = v10;
  _init_waitqueue_head(v8 + 11, "&debugfs_data->wait_queue", &hfi_core_dbg_debugfs_register___key_35);
  v11 = kthread_create_on_node(hfi_core_dbg_listener, a1, 0xFFFFFFFFLL, "hfi_core_dbg_client_listener");
  v13 = v11;
  if ( v11 > 0xFFFFFFFFFFFFF000LL )
  {
    printk(&unk_19EDF, "hfi_core_dbg_debugfs_register", 2930, v6, v12);
    debugfs_remove(v10);
    LODWORD(v10) = v13;
    goto LABEL_14;
  }
  wake_up_process(v11);
  v16 = msm_hfi_core_debug_level;
  v8[14] = v13;
  if ( (~v16 & 0x10001) == 0 )
    printk(&unk_1C28B, "hfi_core_dbg_debugfs_register", 2936, v14, v15);
  LODWORD(v10) = 0;
  return (unsigned int)v10;
}
