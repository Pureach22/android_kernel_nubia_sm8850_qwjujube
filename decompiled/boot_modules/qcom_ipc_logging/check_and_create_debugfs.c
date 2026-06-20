__int64 check_and_create_debugfs()
{
  mutex_lock(&ipc_log_debugfs_init_lock);
  if ( !root_dent )
  {
    root_dent = debugfs_create_dir("ipc_logging", 0);
    if ( (unsigned __int64)root_dent >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_826D, "check_and_create_debugfs");
      root_dent = 0;
    }
  }
  return mutex_unlock(&ipc_log_debugfs_init_lock);
}
