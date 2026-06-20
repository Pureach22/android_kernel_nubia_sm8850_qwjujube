__int64 rmnet_shs_wq_mem_deinit()
{
  remove_proc_entry("rmnet_shs_global", shs_proc_dir);
  remove_proc_entry("shs", 0);
  rmnet_shs_ep_lock_bh();
  global_shared = 0;
  return rmnet_shs_ep_unlock_bh();
}
