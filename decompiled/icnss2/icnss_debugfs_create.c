__int64 __fastcall icnss_debugfs_create(__int64 a1)
{
  unsigned __int64 dir; // x19

  dir = debugfs_create_dir("icnss", 0);
  if ( dir >= 0xFFFFFFFFFFFFF001LL )
  {
    printk("%sUnable to create debugfs %d\n", byte_130B32, dir);
    ipc_log_string(icnss_ipc_log_context, "%sUnable to create debugfs %d\n", (const char *)&unk_12DBF3, dir);
  }
  else
  {
    *(_QWORD *)(a1 + 2144) = dir;
    debugfs_create_file("stats", 384, dir, a1, &icnss_stats_fops);
    LODWORD(dir) = 0;
  }
  return (unsigned int)dir;
}
