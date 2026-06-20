__int64 init_module()
{
  unsigned __int64 dir; // x0
  __int64 v1; // x4
  unsigned int v2; // w19
  unsigned __int64 file; // x0
  __int64 v4; // x4

  dir = debugfs_create_dir("thermal", 0);
  v2 = dir;
  thermal_debugfs_parent = dir;
  if ( dir && dir < 0xFFFFFFFFFFFFF001LL )
  {
    file = debugfs_create_file("config", 384, dir, 0, &thermal_dbgfs_config_fops);
    v2 = file;
    thermal_debugfs_config = file;
    if ( file && file < 0xFFFFFFFFFFFFF001LL )
      return 0;
    else
      printk(&unk_70C5, "thermal_config", "thermal_config_init", (unsigned int)file, v4);
  }
  else
  {
    printk(&unk_6FEB, "thermal_config", "thermal_config_init", (unsigned int)dir, v1);
  }
  return v2;
}
