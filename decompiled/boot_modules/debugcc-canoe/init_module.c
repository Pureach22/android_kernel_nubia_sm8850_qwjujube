__int64 init_module()
{
  return _platform_driver_register(&clk_debug_driver, &_this_module);
}
