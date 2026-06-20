__int64 init_module()
{
  pdentry = debugfs_create_dir("gpi_dma", 0);
  return _platform_driver_register(gpi_driver, &_this_module);
}
