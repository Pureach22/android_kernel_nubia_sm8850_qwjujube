__int64 __fastcall create_ctx_debugfs(__int64 a1, __int64 a2)
{
  __int64 v4; // x1
  unsigned __int64 dir; // x0

  v4 = root_dent;
  if ( root_dent )
    goto LABEL_6;
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
  mutex_unlock(&ipc_log_debugfs_init_lock);
  v4 = root_dent;
  if ( root_dent )
  {
LABEL_6:
    dir = debugfs_create_dir(a2, v4);
    *(_QWORD *)(a1 + 136) = dir;
    if ( dir <= 0xFFFFFFFFFFFFF000LL )
    {
      debugfs_create_file_unsafe("log", 292, dir, a1, &debug_ops);
      debugfs_create_file_unsafe("log_cont", 292, *(_QWORD *)(a1 + 136), a1, &debug_ops_cont);
    }
  }
  return add_deserialization_func(a1, 2, (__int64)dfunc_string);
}
