__int64 init_module()
{
  return _platform_driver_register(cpu_vendor_hooks_driver, &_this_module);
}
