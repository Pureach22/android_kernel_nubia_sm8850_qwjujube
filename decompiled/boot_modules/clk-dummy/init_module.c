__int64 init_module()
{
  return _platform_driver_register(dummy_clk_driver, &_this_module);
}
