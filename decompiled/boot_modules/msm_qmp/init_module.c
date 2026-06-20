__int64 init_module()
{
  return _platform_driver_register(qmp_mbox_driver, &_this_module);
}
