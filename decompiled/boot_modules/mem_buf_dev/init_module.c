__int64 init_module()
{
  mem_buf_debugfs_root = debugfs_create_dir("mem_buf", 0);
  return _platform_driver_register(mem_buf_driver, &_this_module);
}
