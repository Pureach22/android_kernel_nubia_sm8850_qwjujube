__int64 syna_dev_module_exit()
{
  __int64 v0; // x0

  v0 = platform_driver_unregister(syna_dev_driver);
  return syna_hw_interface_exit(v0);
}
