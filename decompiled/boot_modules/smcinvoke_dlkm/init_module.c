__int64 init_module()
{
  return _platform_driver_register(&smcinvoke_plat_driver, &_this_module);
}
