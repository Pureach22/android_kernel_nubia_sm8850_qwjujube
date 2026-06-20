__int64 cleanup_module()
{
  mem_buf_vm_exit();
  platform_driver_unregister(mem_buf_driver);
  return debugfs_remove(mem_buf_debugfs_root);
}
