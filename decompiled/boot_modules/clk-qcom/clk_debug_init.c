__int64 clk_debug_init()
{
  unsigned __int64 v0; // x0
  unsigned int v1; // w19
  unsigned int v2; // w20

  tracepoint_probe_register(&_tracepoint_suspend_resume, clk_debug_suspend_trace_probe, 0);
  v0 = debugfs_lookup(&unk_29688, 0);
  clk_debug_init_rootdir = v0;
  if ( v0 && v0 < 0xFFFFFFFFFFFFF001LL )
  {
    debugfs_create_file("clk_enabled_list", 292, v0, &clk_hw_debug_list, &clk_enabled_list_fops);
    debugfs_create_file("trace_clocks", 292, clk_debug_init_rootdir, &clk_hw_debug_list, &clk_enabled_trace_fops);
    clk_debugfs_suspend = debugfs_create_file_unsafe(
                            "debug_suspend",
                            420,
                            clk_debug_init_rootdir,
                            0,
                            &clk_debug_suspend_enable_fops);
    clk_debugfs_suspend_atomic = debugfs_create_file_unsafe(
                                   "debug_suspend_atomic",
                                   420,
                                   clk_debug_init_rootdir,
                                   0,
                                   &clk_debug_suspend_atomic_enable_fops);
    dput(clk_debug_init_rootdir);
    v1 = clk_debugfs_suspend;
    if ( (unsigned __int64)clk_debugfs_suspend >= 0xFFFFFFFFFFFFF001LL )
      printk(&unk_2916B);
    else
      v1 = 0;
    v2 = clk_debugfs_suspend_atomic;
    if ( (unsigned __int64)clk_debugfs_suspend_atomic >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_29005);
      return v2;
    }
  }
  else
  {
    printk(&unk_28DBF);
    return 0;
  }
  return v1;
}
