__int64 rmnet_shs_wq_mem_init()
{
  __int64 result; // x0

  result = proc_mkdir("shs", 0);
  shs_proc_dir = result;
  if ( result )
  {
    proc_set_user(result, 1001, 1001);
    proc_create("rmnet_shs_global", 420, shs_proc_dir, &rmnet_shs_global_fops);
    rmnet_shs_ep_lock_bh();
    global_shared = 0;
    return rmnet_shs_ep_unlock_bh();
  }
  return result;
}
