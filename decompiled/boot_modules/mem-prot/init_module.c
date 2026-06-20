__int64 init_module()
{
  unsigned __int64 dir; // x0

  dir = debugfs_create_dir("mem-prot", 0);
  if ( dir >= 0xFFFFFFFFFFFFF001LL )
    printk(&unk_6D3A, "mem_prot_init");
  else
    debugfs_create_file("pools_info", 384, dir, 0, &mem_prot_debugfs_fops);
  return _platform_driver_register(mem_prot_driver, &_this_module);
}
