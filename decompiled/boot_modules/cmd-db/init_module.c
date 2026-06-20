__int64 init_module()
{
  return _platform_driver_register(&cmd_db_dev_driver, &_this_module);
}
