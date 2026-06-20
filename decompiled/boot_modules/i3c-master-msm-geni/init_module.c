__int64 init_module()
{
  return _platform_driver_register(&geni_i3c_master, &_this_module);
}
