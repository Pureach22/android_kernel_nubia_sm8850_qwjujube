__int64 init_module()
{
  return _platform_driver_register(&qmp_combo_driver, &_this_module);
}
