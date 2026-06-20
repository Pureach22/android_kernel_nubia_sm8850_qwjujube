__int64 init_module()
{
  return _amba_driver_register(&tpda_driver, &_this_module);
}
