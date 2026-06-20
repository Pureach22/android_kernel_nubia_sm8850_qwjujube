__int64 __fastcall hw_fence_debug_debugfs_register(__int64 a1)
{
  __int64 v1; // x30
  __int64 v3; // x21
  unsigned __int64 dir; // x0
  unsigned __int64 v5; // x20

  v3 = v1;
  dir = debugfs_create_dir("hw_fence", 0);
  v5 = dir;
  if ( dir && dir < 0xFFFFFFFFFFFFF001LL )
  {
    _mutex_init(a1 + 544, "&drv_data->debugfs_data.clients_list_lock", &hw_fence_debug_debugfs_register___key);
    *(_QWORD *)(a1 + 528) = a1 + 528;
    *(_QWORD *)(a1 + 536) = a1 + 528;
    *(_BYTE *)(a1 + 520) = 1;
    *(_QWORD *)(a1 + 480) = v5;
    *(_DWORD *)(a1 + 516) = 8333;
    debugfs_create_file("ipc_trigger", 384, v5, a1, &hw_fence_dbg_ipcc_fops);
    debugfs_create_file("dpu_trigger", 384, v5, a1, &hw_fence_dbg_ipcc_dpu_fops);
    debugfs_create_file("hw_fence_reset_client", 384, v5, a1, &hw_fence_reset_client_fops);
    debugfs_create_file("hw_fence_register_clients", 384, v5, a1, &hw_fence_register_clients_fops);
    debugfs_create_file("hw_fence_tx_and_signal", 384, v5, a1, &hw_fence_tx_and_signal_clients_fops);
    debugfs_create_file("hw_fence_create_join_fence", 384, v5, a1, &hw_fence_create_join_fence_fops);
    debugfs_create_bool("create_hw_fences", 384, v5, a1 + 520);
    debugfs_create_u32("sleep_range_us", 384, v5, a1 + 516);
    debugfs_create_file("hw_fence_create", 384, v5, a1, &hw_fence_create_fops);
    debugfs_create_u32("hw_fence_debug_level", 384, v5, &msm_hw_fence_debug_level);
    debugfs_create_file("hw_fence_dump_table", 384, v5, a1, &hw_fence_dump_table_fops);
    debugfs_create_file("hw_fence_dump_queues", 384, v5, a1, &hw_fence_dump_queues_fops);
    debugfs_create_file("hw_sync", 384, v5, 0, &hw_sync_debugfs_fops);
    debugfs_create_u64("hw_fence_lock_wake_cnt", 384, v5, a1 + 592);
    debugfs_create_file("hw_fence_dump_events", 384, v5, a1, &hw_fence_dump_events_fops);
    debugfs_create_file("hw_fence_soccp_props", 384, v5, a1, &hw_fence_get_soccp_props_fops);
    return 0;
  }
  else
  {
    printk(&unk_29B4F, "hw_fence_debug_debugfs_register", 1532, v3, dir);
    *(_QWORD *)(a1 + 480) = 0;
    return 4294967274LL;
  }
}
