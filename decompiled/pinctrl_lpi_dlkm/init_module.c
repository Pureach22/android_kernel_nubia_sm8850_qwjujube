__int64 init_module()
{
  return _platform_driver_register(lpi_pinctrl_driver, &_this_module);
}
