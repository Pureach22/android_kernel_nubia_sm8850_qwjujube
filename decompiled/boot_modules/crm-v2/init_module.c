__int64 init_module()
{
  return _platform_driver_register(&crm_driver, &_this_module);
}
