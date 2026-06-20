__int64 init_module()
{
  return _amba_driver_register(&tgu_driver, &_this_module);
}
