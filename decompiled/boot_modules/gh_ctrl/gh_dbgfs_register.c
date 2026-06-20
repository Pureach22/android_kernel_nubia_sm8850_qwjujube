__int64 gh_dbgfs_register()
{
  unsigned __int64 dir; // x0
  unsigned int v1; // w2
  unsigned __int64 file; // x0

  dir = debugfs_create_dir("gunyah", 0);
  v1 = dir;
  gh_dbgfs_dir = dir;
  if ( dir && dir < 0xFFFFFFFFFFFFF001LL )
  {
    if ( (gunyah_api_1 & 0x80) != 0
      && ((file = debugfs_create_file("trace_set", 384, dir, 0, &gh_dbgfs_trace_class_set_fops),
           file >= 0xFFFFFFFFFFFFF001LL)
       || (file = debugfs_create_file("trace_clear", 384, gh_dbgfs_dir, 0, &gh_dbgfs_trace_class_clear_fops),
           file >= 0xFFFFFFFFFFFFF001LL)
       || (file = debugfs_create_file("hyp_uart_ctrl", 384, gh_dbgfs_dir, 0, &gh_dbgfs_hyp_uart_ctrl_fops),
           file >= 0xFFFFFFFFFFFFF001LL)) )
    {
      return (unsigned int)file;
    }
    else
    {
      return 0;
    }
  }
  return v1;
}
